// Imported from doldecomp/ogws (CC0), src/revolution/OS/OSExec.c; PackArgs, Run, Callback, callback and
// __OSBootDol from zeldaret/tp (CC0), libs/revolution/src/os/OSExec.c.
#include <private/ios.h>
#include <private/ipc.h>
#include <private/os.h>
#include <private/os/OSExec.h>
#include <revolution/os.h>
#include <revolution/dvd.h>
#include <stdio.h>
#include <string.h>

#ifndef __REGISTER
#define __REGISTER register
#endif
#define __GEKKO__

static int Prepared;
static u32 DVDLowIntType;

void ICFlashInvalidate(void);
void __OSBootDolSimple(u32 doloffset, u32 restartCode, void* regionStart, void* regionEnd, BOOL argsUseDefault,
                       s32 argc, char** argv);

// From doldecomp/ogws (CC0), include/revolution/ESP/esp.h
enum {
    ES_IOCTLV_LAUNCH_TITLE         = 8,
    ES_IOCTLV_GET_NUM_TICKET_VIEWS = 18,
    ES_IOCTLV_GET_TICKET_VIEWS     = 19,
};

#define MENU_TITLE_ID 0x0000000100000002
#define TICKET_VIEW_SIZE 0xD8

// Force CW to align the file boundary to 64
u8 FORCE_BSS_ALIGN[0xABCD] ALIGN64;

static u8 views[0xBD00] ALIGN32;

BOOL __OSInReboot;

static s32 _ES_InitLib(s32 *fd);
static s32 _ES_GetTicketViews(s32 *fd, u64 tid, void *pViews, u32 *count);
static s32 _ES_LaunchTitle(s32 *fd, u64 tid, void *pViews) NO_INLINE;

// TODO: the functions after __OSGetExecParams in this unit (callback, fn_8026BD34,
// fn_8026C328, fn_8026C474 and __OSBootDol) are not in the imported source and
// are still unwritten.
void __OSGetExecParams(OSExecParams *out) {
    if ((void *)__OSExecParamsAddr >= (void *)0x80000000) {
        memcpy(out, __OSExecParamsAddr, sizeof(OSExecParams));
    } else {
        out->valid = 0;
    }
}

void __OSLaunchMenu(void) {
    // This makes me feel sick
    s32 result;
    void *pviews = &views;
    u32 count = 1;
    s32 fd = -1;
    struct {
        u8 tmp[4];
    } unused = {0xFF, 0xFF, 0xFF, 0};

    if (_ES_InitLib(&fd) != IPC_RESULT_OK) {
        return;
    }

    // Get num ticket views
    result = _ES_GetTicketViews(&fd, MENU_TITLE_ID, NULL, &count);
    if (count != 1 || result != IPC_RESULT_OK) {
        return;
    }

    // Get ticket views
    if (_ES_GetTicketViews(&fd, MENU_TITLE_ID, pviews, &count) != IPC_RESULT_OK) {
        return;
    }

    // Launch title
    if (_ES_LaunchTitle(&fd, MENU_TITLE_ID, pviews) != IPC_RESULT_OK) {
        return;
    }

    while (TRUE) {
        ;
    }
}

/**
 * These were actually re(?)implemented in NANDCore/OSExec according to BBA
 */

static s32 _ES_InitLib(s32 *fd) {
    s32 result;

    // Had to remove fd initialization to match __OSLaunchMenu
    // *fd = -1;

    result = IPC_RESULT_OK;

    *fd = IOS_Open("/dev/es", IPC_OPEN_NONE);
    if (*fd < 0) {
        result = *fd;
    }

    return result;
}

static s32 _ES_GetTicketViews(s32 *fd, u64 tid, void *pViews, u32 *count) {
    s32 result;
    // TODO(kiwi) Hacky solution
    u8 work[0x120] ALIGN32;
    IOSIoVector *pVectors = (IOSIoVector *)(work + 0x0);
    u64 *pTid = (u64 *)(work + 0x20);
    u32 *pCount = (u32 *)(work + 0x40);

    // Cast is necessary
    if (*fd < 0 || count == ((void *)NULL)) {
        return -0x3F9;
    }

    if ((u32)pViews % 32 != 0) {
        return -0x3F9;
    }

    *pTid = tid;

    // NULL views ptr = get num views
    if (pViews == (void *)NULL) {
        pVectors[0].base = (u8 *)pTid;
        pVectors[0].length = sizeof(u64);
        pVectors[1].base = (u8 *)pCount;
        pVectors[1].length = sizeof(u32);

        result = IOS_Ioctlv(*fd, ES_IOCTLV_GET_NUM_TICKET_VIEWS, 1, 1, pVectors);
        if (result == IPC_RESULT_OK) {
            *count = *pCount;
        }

        return result;
    }

    if (*count == 0) {
        return -0x3F9;
    }

    *pCount = *count;

    pVectors[0].base = (u8 *)pTid;
    pVectors[0].length = sizeof(u64);
    pVectors[1].base = (u8 *)pCount;
    pVectors[1].length = sizeof(u32);
    pVectors[2].base = (u8 *)pViews;
    pVectors[2].length = *count * TICKET_VIEW_SIZE;
    return IOS_Ioctlv(*fd, ES_IOCTLV_GET_TICKET_VIEWS, 2, 1, pVectors);
}

static s32 _ES_LaunchTitle(s32 *fd, u64 tid, void *pViews) {
    // TODO(kiwi) Hacky solution
    u8 tidWork[256] ALIGN32;
    u8 vectorWork[32] ALIGN32;
    IOSIoVector *pVectors = (IOSIoVector *)vectorWork;
    u64 *pTid = (u64 *)tidWork;

    if (*fd < 0) {
        return -0x3F9;
    }

    if ((u32)pViews % 32 != 0) {
        return -0x3F9;
    }

    *pTid = tid;

    pVectors[0].base = (u8 *)pTid;
    pVectors[0].length = sizeof(u64);
    pVectors[1].base = (u8 *)pViews;
    pVectors[1].length = TICKET_VIEW_SIZE;

    return IOS_IoctlvReboot(*fd, ES_IOCTLV_LAUNCH_TITLE, 2, 0, pVectors);
}

int PackArgs(void* addr, s32 argc, char** argv) {
    s32 numArgs;
    char* bootInfo2;
    char* ptr;
    char** list;
    u32 i;

    bootInfo2 = (char*)addr;
    memset(bootInfo2, 0, 0x2000);

    if (argc == 0) {
        *(u32*)(bootInfo2 + 8) = 0;
    } else {
        numArgs = argc;
        ptr = bootInfo2 + 0x2000;
        while (--argc >= 0) {
            ptr -= strlen(argv[argc]) + 1;
            strcpy(ptr, argv[argc]);
            argv[argc] = (char*)(ptr - bootInfo2);
        }

        ptr = bootInfo2 + ((ptr - bootInfo2) & ~0x3);
        ptr -= ((numArgs + 1) * 4);
        list = (char**)ptr;

        for (i = 0; i < numArgs + 1; i++) {
            list[i] = argv[i];
        }

        ptr -= 4;
        *(u32*)ptr = numArgs;

        ASSERTMSGLINE(401, ptr - bootInfo2 >= 0x1000U, "OSExec: Argument list is too long");

        *(u32*)(bootInfo2 + 8) = (ptr - bootInfo2);
    }

    return 1;
}

asm void Run(__REGISTER void* entryPoint) {
    fralloc

    bl ICFlashInvalidate
    sync
    isync
    mtctr entryPoint
    bctr

    frfree
    blr
}

void Callback(s32 result, DVDCommandBlock* block) {
    Prepared = TRUE;
}

void callback(u32 param_0) {
    DVDLowIntType = param_0;
}

void __OSBootDol(u32 doloffset, u32 restartCode, const char** argv) {
    char doloffInString[20];
    s32 argvlen;
    char** argvToPass;
    s32 i;
    void* saveStart;
    void* saveEnd;

    OSGetSaveRegion(&saveStart, &saveEnd);
    sprintf(doloffInString, "%d", doloffset);
    argvlen = 0;

    if (argv != 0) {
        while (argv[argvlen] != 0) {
            argvlen++;
        }
    }

    argvlen++;
    argvToPass = OSAllocFromMEM1ArenaLo((argvlen + 1) * 4, 1);
    *argvToPass = doloffInString;

    for (i = 1; i < argvlen; i++) {
        argvToPass[i] = (char*)argv[i - 1];
    }

    __OSBootDolSimple(-1, restartCode, saveStart, saveEnd, FALSE, argvlen, argvToPass);
}
