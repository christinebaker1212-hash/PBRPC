// Imported from doldecomp/ogws (CC0), src/revolution/OS/OSFatal.c
#include <private/exi.h>
#include <private/hollywood.h>
#include <private/os.h>
#include <private/os/OSAudioSystem.h>
#include <private/os/OSReset.h>
#include <revolution/base/PPCArch.h>
#include <revolution/gx.h>
#include <revolution/os.h>
#include <revolution/os/OSBootInfo.h>
#include <revolution/vi.h>
#include <string.h>

#define CLAMP(low, high, x) ((x) < (low) ? (low) : ((x) > (high) ? (high) : (x)))

/**
 * Framebuffer formatted as 32-bits per two pixels
 * Pixels are written as brightness/chroma pairs
 */
#define FATAL_FB_W 640
#define FATAL_FB_H 480
#define FATAL_FB_SIZE (FATAL_FB_W * FATAL_FB_H * 2)

typedef struct OSFatalParam {
    GXColor textColor; // at 0x0
    GXColor bgColor;   // at 0x4
    const char *msg;   // at 0x8
} OSFatalParam;

static OSContext FatalContext;
static OSFatalParam FatalParam;

static void Halt(void);

static void ScreenClear(u8 *fb, u16 width, u16 height, GXColor yuv) {
    int x, y;

    for (y = 0; y < height; y += 1) {
        for (x = 0; x < width; x += 2) {
            fb[0] = yuv.r;
            fb[1] = yuv.g;

            fb[2] = yuv.r;
            fb[3] = yuv.b;

            fb += sizeof(u32);
        }
    }
}

static void ScreenReport(void *fb, u16 width, u16 height, GXColor msgYUV, s32 x, s32 y, u32 lf, const char *msg) {
    u32 texel[70];
    s32 charWidth;
    u8 *tmp;
    u8 bright;
    s32 xPos;
    u32 idx;
    u32 idx2;
    u32 idx3;
    u32 i;
    u32 j;

new_line:
    if (height - 24 < y) {
        return;
    }

    tmp = (u8 *)fb + ((x + (y * width)) * 2);
    xPos = x;

    while (*msg != '\0') {
        if (*msg == '\n') {
            msg++;
            y += lf;
            goto new_line;
        } else if (width - 48 < xPos) {
            y += lf;
            goto new_line;
        }

        for (i = 0; i < 24; i++) {
            idx = (i & 7) + ((i / 8) * 24);
            texel[idx] = 0;
            texel[idx + 8] = 0;
            texel[idx + 16] = 0;
        }

        msg = OSGetFontTexel(msg, texel, 0, 6, &charWidth);

        for (i = 0; i < 24; i++) {
            idx = (i & 7) + ((i / 8) * 24);

            for (j = 0; j < 24; j++) {
                idx2 = idx + ((j / 8) * 8);
                bright = (texel[idx2] >> ((7 - (j & 7)) * 4)) & 0x0F;

                if (bright != 0) {
                    // Y component/brightness
                    bright = (((msgYUV.r * (bright * 0xEF)) / 255) / 15) + 16;
                    idx3 = (j + (width * i));
                    tmp[idx3 * 2] = bright;

                    // Order chroma depending on pixel pair
                    if ((xPos + j) % 2 != 0) {
                        tmp[(idx3 * 2) - 1] = msgYUV.g;
                        tmp[(idx3 * 2) + 1] = msgYUV.b;
                    } else {
                        tmp[(idx3 * 2) - 1] = msgYUV.b;
                        tmp[(idx3 * 2) + 1] = msgYUV.g;
                    }
                }
            }
        }

        tmp += charWidth * 2;
        xPos += charWidth;
    }
}

static void ConfigureVideo(u16 width, u16 height) {
    GXRenderModeObj rmode;

    rmode.fbWidth = width;
    rmode.efbHeight = FATAL_FB_H;
    rmode.xfbHeight = height;

    rmode.viXOrigin = 40;
    rmode.viWidth = FATAL_FB_W;
    rmode.viHeight = height;

    switch (VIGetTvFormat()) {
        case VI_NTSC:
        case VI_MPAL: {
            if ((*(vu16 *)0xCC00206C) & 1 /* == VI_VICLK_54MHZ */) {
                // Progressive mode
                rmode.viTVmode = VI_TVMODE(VI_NTSC, VI_PROGRESSIVE);
                rmode.viYOrigin = 0;
                rmode.xFBmode = VI_XFBMODE_SF;
            } else {
                // Non-progressive mode
                rmode.viTVmode = VI_TVMODE(VI_NTSC, VI_INTERLACE);
                rmode.viYOrigin = 0;
                rmode.xFBmode = VI_XFBMODE_DF;
            }
            break;
        }

        case VI_EURGB60: {
            rmode.viTVmode = VI_TVMODE(VI_EURGB60, VI_INTERLACE);
            rmode.viYOrigin = 0;
            rmode.xFBmode = VI_XFBMODE_DF;
            break;
        }

        case VI_PAL: {
            rmode.viTVmode = VI_TVMODE(VI_PAL, VI_INTERLACE);
            rmode.viYOrigin = 47;
            rmode.xFBmode = VI_XFBMODE_DF;
            break;
        }

        default: {
            break;
        }
    }

    VIConfigure(&rmode);
    VIConfigurePan(0, 0, FATAL_FB_W, FATAL_FB_H);
}

// Intel IPP RGBToYCbCr algorithm (+0.5f?)
static GXColor RGB2YUV(GXColor rgb) {
    f32 Y;
    f32 Cb;
    f32 Cr;
    GXColor yuv;

    Y  = 0.5f + (16.0f + ((0.098f * (f32) rgb.b) + ((0.257f * (f32) rgb.r) + (0.504f * (f32) rgb.g))));
    Cb = 0.5f + (128.0f + ((0.439f * (f32) rgb.b) + ((-0.148f * (f32) rgb.r) - (0.291f * (f32) rgb.g))));
    Cr = 0.5f + (128.0f + (((0.439f * (f32) rgb.r) - (0.368f * (f32) rgb.g)) - (0.071f * (f32) rgb.b)));

    yuv.r = (Y > 235.0f) ? 235.0f : (Y < 16.0f) ? 16.0f : Y;
    yuv.g = (Cb > 240.0f) ? 240.0f : (Cb < 16.0f) ? 16.0f : Cb;
    yuv.b = (Cr > 240.0f) ? 240.0f : (Cr < 16.0f) ? 16.0f : Cr;
    yuv.a = 0;

    return yuv;
}

void OSFatal(GXColor textColor, GXColor bgColor, const char *msg) {
    s32 retraceCount;
    s64 start;
    OSBootInfo *bootInfo;

    bootInfo = (OSBootInfo *)OSPhysicalToCached(OS_ADDR_BOOT_INFO);

    OSDisableInterrupts();

    OSDisableScheduler();
    OSClearContext(&FatalContext);
    OSSetCurrentContext(&FatalContext);
    __OSStopAudioSystem();

    VIInit();
    __OSUnmaskInterrupts(OS_INTERRUPTMASK(__OS_INTERRUPT_PI_VI));
    VISetBlack(TRUE);
    VIFlush();
    VISetPreRetraceCallback(NULL);
    VISetPostRetraceCallback(NULL);

    OSEnableInterrupts();

    retraceCount = VIGetRetraceCount();
    while ((s32)(VIGetRetraceCount() - retraceCount) < 1) {
        ;
    }

    start = OSGetTime();
    do {
        if (__OSCallShutdownFunctions(FALSE, OS_SD_EVENT_FATAL)) {
            break;
        }
    } while (OSGetTime() - start < OSMillisecondsToTicks(1000));

    OSDisableInterrupts();
    __OSCallShutdownFunctions(TRUE, OS_SD_EVENT_FATAL);

    EXISetExiCallback(EXI_CHAN_0, NULL);
    EXISetExiCallback(EXI_CHAN_2, NULL);
    while (!EXILock(EXI_CHAN_0, EXI_DEV_INT, NULL)) {
        EXISync(EXI_CHAN_0);
        EXIDeselect(EXI_CHAN_0);
        EXIUnlock(EXI_CHAN_0);
    }
    EXIUnlock(EXI_CHAN_0);

    while ((EXI_READ_REG(EXI_0_CONTROL) & 1) == 1) {
        ;
    }

    __OSSetExceptionHandler(OS_EXCEPTION_DECREMENTER, OSDefaultExceptionHandler);

    GXAbortFrame();

    OSSetArenaLo((void *)0x81400000);
    OSSetArenaHi(bootInfo->FSTLocation);

    FatalParam.textColor = textColor;
    FatalParam.bgColor = bgColor;
    FatalParam.msg = msg;
    OSSwitchFiber((u32)Halt, (u32)OSGetArenaHi());
}

static void Halt(void) {
    u32 count;
    OSFontHeader* fontData;
    void* xfb;
    u32 len;
    OSFatalParam* fp;

    OSEnableInterrupts();
    fp = &FatalParam;
    len = strlen(fp->msg) + 1;
    fp->msg = memmove(OSAllocFromMEM1ArenaLo(len, 32), fp->msg, len);

    fontData = OSAllocFromMEM1ArenaLo(0xA1004, 32);
    OSLoadFont(fontData, OSGetArenaLo());

    xfb = OSAllocFromMEM1ArenaLo(FATAL_FB_SIZE, 32);
    ScreenClear(xfb, FATAL_FB_W, FATAL_FB_H, RGB2YUV(fp->bgColor));
    VISetNextFrameBuffer(xfb);
    ConfigureVideo(FATAL_FB_W, FATAL_FB_H);
    VIFlush();

    count = VIGetRetraceCount();
    do {
    } while ((s32)(VIGetRetraceCount() - count) < 2);

    ScreenReport(xfb, FATAL_FB_W, FATAL_FB_H, RGB2YUV(fp->textColor), 48, 100, fontData->leading, fp->msg);
    DCFlushRange(xfb, FATAL_FB_SIZE);
    VISetBlack(FALSE);
    VIFlush();

    count = VIGetRetraceCount();
    do {
    } while ((s32)(VIGetRetraceCount() - count) < 1);

    OSDisableInterrupts();
    OSReport("%s\n", fp->msg);
    PPCHalt();
}
