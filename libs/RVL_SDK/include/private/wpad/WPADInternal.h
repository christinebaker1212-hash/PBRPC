#ifndef RVL_SDK_WPAD_INTERNAL_H
#define RVL_SDK_WPAD_INTERNAL_H

#include <revolution.h>

#include <revolution/wpad.h>

#include <private/wpad/WPADHIDParser.h>
#include <private/wpad/WPADMem.h>

#ifdef __cplusplus
extern "C" {
#endif

void DEBUGPrint(const char* format, ...);

#define RX_BUFFER_SIZE OSRoundUp32B(sizeof(WPADStatusEx))

#define WPAD_CONFIG_BLOCK_CHECKSUM_BIAS 0x55
#define WPAD_MAX_CONFIG_BLOCKS 2

#define WPAD_DPD_CONFIG_BLOCK_CHECKSUM 10
#define WPAD_DPD_CONFIG_BLOCK_SIZE 11

#define WPAD_DEV_CONFIG_BLOCK_CHECKSUM 9
#define WPAD_DEV_CONFIG_BLOCK_SIZE 10

#define DPD_CFG_OBJ_BL 0
#define DPD_CFG_OBJ_BR 1
#define DPD_CFG_OBJ_TR 2
#define DPD_CFG_OBJ_TL 3

/*
 * Wiimote memory addresses
 */
#define WM_ADDR_MEM_DEV_CONFIG_0 WM_MEM_ADDR(0x0000)
#define WM_ADDR_MEM_GAME_INFO_0 WM_MEM_ADDR(0x002A)
#define WM_ADDR_MEM_GAME_INFO_1 WM_MEM_ADDR(0x0062)
#define WM_ADDR_MEM_176C WM_MEM_ADDR(0x176C)
#define WM_ADDR_MEM_1770 WM_MEM_ADDR(0x1770)

/*
 * Wiimote extension register addresses
 */
// Speaker register addresses
#define WM_REG_SPEAKER_01 WM_EXT_REG_ADDR(SPEAKER, 0x01)
#define WM_REG_SPEAKER_08 WM_EXT_REG_ADDR(SPEAKER, 0x08)
#define WM_REG_SPEAKER_09 WM_EXT_REG_ADDR(SPEAKER, 0x09)

// Extension register addresses
#define WM_REG_EXTENSION_CONFIG WM_EXT_REG_ADDR(EXTENSION, 0x20)
#define WM_REG_EXTENSION_40 WM_EXT_REG_ADDR(EXTENSION, 0x40)
#define WM_REG_EXTENSION_CERT_PARAM WM_EXT_REG_ADDR(EXTENSION, 0x50)
#define WM_REG_EXTENSION_F0 WM_EXT_REG_ADDR(EXTENSION, 0xF0)
#define WM_REG_EXTENSION_CERT_CHALLENGE WM_EXT_REG_ADDR(EXTENSION, 0xF1)
#define WM_REG_EXTENSION_F2 WM_EXT_REG_ADDR(EXTENSION, 0xF2)
#define WM_REG_EXTENSION_F3 WM_EXT_REG_ADDR(EXTENSION, 0xF3)
#define WM_REG_EXTENSION_EXT_TYPE_2 WM_EXT_REG_ADDR(EXTENSION, 0xF6)
#define WM_REG_EXTENSION_CERT_PROBE WM_EXT_REG_ADDR(EXTENSION, 0xF7)
#define WM_REG_EXTENSION_FA WM_EXT_REG_ADDR(EXTENSION, 0xFA)
#define WM_REG_EXTENSION_FB WM_EXT_REG_ADDR(EXTENSION, 0xFB)
#define WM_REG_EXTENSION_DEV_MODE WM_EXT_REG_ADDR(EXTENSION, 0xFE)
#define WM_REG_EXTENSION_ID_BYTE WM_EXT_REG_ADDR(EXTENSION, 0xFF)

// IR camera register addresses
#define WM_REG_DPD_CONFIG_BLOCK_1 WM_EXT_REG_ADDR(DPD, 0x00)
#define WM_REG_DPD_CONFIG_BLOCK_2 WM_EXT_REG_ADDR(DPD, 0x1A)
#define WM_REG_DPD_30 WM_EXT_REG_ADDR(DPD, 0x30)
#define WM_REG_DPD_DATA_FORMAT WM_EXT_REG_ADDR(DPD, 0x33)

#define WM_EXTENSION_CONFIG_SIZE 0x20  // 0xA40020 - 0xA4003F

typedef enum {
    WPAD_STATE_EXT_UNINITIALIZED,
    WPAD_STATE_EXT_INITIALIZED,
    WPAD_STATE_EXT_ENCRYPTED,
    WPAD_STATE_EXT_ENCRYPTED_3RD,
} WPADExtensionState;

typedef enum {
    WPAD_RADIO_QUALITY_GOOD,  // 80+
    WPAD_RADIO_QUALITY_BAD    // 80-
    // if radioQuality calculation == 80, state stays the same
} WPADRadioQuality;

typedef enum {
    WPAD_ILBUF_NONE = 0,

    WPAD_ILBUF_BUF3E = (1 << 0),
    WPAD_ILBUF_BUF3F = (1 << 1),

    WPAD_ILBUF_ALL = WPAD_ILBUF_BUF3E | WPAD_ILBUF_BUF3F,
} WPADInterleaveBufferFlags;

typedef struct WPADCommand {
    u32 reportID;  // 0x00

    u8 dataBuf[RPT_MAX_SIZE];  // 0x04
    u16 dataLength;            // 0x1A

    void* dstBuf;  // 0x1C

    u16 readLength;   // 0x20
    u32 readAddress;  // 0x24

    WPADInfo* statusReportOut;  // 0x28
    WPADCallback cmdCB;         // 0x2C
} WPADCommand;

typedef struct WPADCommandQueue {
    s8 front;             // 0x00
    s8 back;              // 0x01
    WPADCommand* buffer;  // 0x04
    u32 capacity;         // 0x08
} WPADCommandQueue;

typedef struct WPADDevConfig {
    DPDObject dpd[WPAD_MAX_DPD_OBJECTS];  // 0x00

    s16 accX0g;  // 0x20
    s16 accY0g;  // 0x22
    s16 accZ0g;  // 0x24

    s16 accX1g;  // 0x26
    s16 accY1g;  // 0x28
    s16 accZ1g;  // 0x2A

    u8 motor;   // 0x2C
    u8 volume;  // 0x2D
} WPADDevConfig;

typedef struct WPADExtConfig {
    union {
        struct WPADFSConfig {
            s16 stickXCenter;  // 0x00
            s16 unk_0x02;      // 0x02
            s16 unk_0x04;      // 0x04
            s16 stickYCenter;  // 0x06
            s16 unk_0x08;      // 0x08
            s16 unk_0x0A;      // 0x0A

            s16 accX0g;  // 0x0C
            s16 accY0g;  // 0x0E
            s16 accZ0g;  // 0x10

            s16 accX1g;  // 0x12
            s16 accY1g;  // 0x14
            s16 accZ1g;  // 0x16
        } fs;

        struct WPADCLConfig {
            s16 lStickXCenter;  // 0x00
            s16 unk_0x02;       // 0x02
            s16 unk_0x04;       // 0x04
            s16 lStickYCenter;  // 0x06
            s16 unk_0x08;       // 0x08
            s16 unk_0x0A;       // 0x0A

            s16 rStickXCenter;  // 0x0C
            s16 unk_0x0E;       // 0x0E
            s16 unk_0x10;       // 0x10
            s16 rStickYCenter;  // 0x12
            s16 unk_0x14;       // 0x14
            s16 unk_0x16;       // 0x16

            u8 triggerLZero;  // 0x18
            u8 triggerRZero;  // 0x19
        } cl;
    } u;
} WPADExtConfig;

typedef struct WPADCB {
    WPADGameInfo gameInfo;  // 0x00
    s32 unk_0x38[2];
    u8 rxBufMain[RX_BUFFER_SIZE];       // 0x40
    u8 rxBufs[2][RX_BUFFER_SIZE];       // 0xA0
    WPADCommandQueue stdCmdQueue;       // 0x160
    WPADCommand stdCmdQueueList[24];    // 0x16C
    WPADCommandQueue extCmdQueue;       // 0x5EC
    WPADCommand extCmdQueueList[8];     // 0x5F8
    WPADInfo wpInfo;                    // 0x778
    WPADInfo* wpInfoOut;                // 0x790
    WPADDevConfig devConfig;            // 0x794
    WPADExtConfig extConfig;            // 0x7C2
    WPADCallback cmdBlkCB;              // 0x7DC
    WPADExtensionCallback extensionCB;  // 0x7E0
    WPADConnectCallback connectCB;      // 0x7E4
    WPADSamplingCallback samplingCB;    // 0x7E8
    union {
        WPADStatus* samplingBuf;
        WPADStatusEx* samplingBufEx;
        WPADFSStatus* samplingBufFS;
        WPADCLStatus* samplingBufCL;
    };  // 0x7EC
    u32 samplingBufIndex;  // 0x7F0
    u32 samplingBufSize;   // 0x7F4
    u32 dataFormat;        // 0x7F8
    s32 status;            // 0x7FC
    u8 statusReqBusy;      // 0x800
    u8 devType;            // 0x801
    u8 devMode;            // 0x802
    s8 devHandle;          // 0x803
    s32 unk_0x804;
    u8 rxBufIndex;  // 0x808
    s8 unk_0x809;
    u8 defaultDpdSize;             // 0x80A
    u8 currentDpdCommand;          // 0x80B
    u8 pendingDpdCommand;          // 0x80C
    u8 radioQuality;               // 0x80D
    u8 radioQualityOkMs;           // 0x80E
    u8 audioFrames;                // 0x80F
    u32 motorBusy;                 // 0x810
    BOOL motorRunning;             // 0x814
    BOOL used;                     // 0x818
    BOOL handshakeFinished;        // 0x81C
    s32 configIndex;               // 0x820
    OSThreadQueue threadQueue;     // 0x824
    s64 lastControllerDataUpdate;  // 0x830
    u16 filterDiffDpd;             // 0x838
    u16 filterSameDpd;             // 0x83A
    u16 filterDiffAcc;             // 0x83C
    u16 filterSameAcc;             // 0x83E
    u16 filterDiffExt;             // 0x840
    u16 filterSameExt;             // 0x842
    s64 lastReportSendTime;        // 0x848
    u8 unk_0x850;
    u8 calibrated;          // 0x851
    u16 comboHeld;          // 0x852
    u8 encryptionKey[16];   // 0x854
    u8 decryptAddTable[8];  // 0x864
    u8 decryptXorTable[8];  // 0x86C
    u8 wmReadDataBuf[64];   // 0x874
    u8* wmReadDataPtr;      // 0x8B4
    u32 wmReadAddress;      // 0x8B8
    int wmReadHadError;     // 0x8BC
    u16 wmReadLength;       // 0x8C0
    s8 unk_0x8C2;
    u8 radioSensitivity;     // 0x8C3
    u16 copyOutCount;        // 0x8C4
    u8 sleeping;             // 0x8C6
    u8 lastReportID;         // 0x8C7
    WPADCallback getInfoCB;  // 0x8C8
    u8 getInfoBusy;          // 0x8CC

    u8 unk_0x8CD;  // 0x8CD
    u8 unk_0x8CE;  // 0x8CE
    u8 unk_0x8CF[0x8E0 - 0x8CF];
} WPADCB;

extern WPADCB _wpd[WPAD_MAX_CONTROLLERS];
extern WPADCB* _wpdcb[WPAD_MAX_CONTROLLERS];

void WPADiInitSub();

void WPADiExcludeButton(s32 chan);
void WPADiCopyOut(s32 chan);

BOOL WPADiSendSetPort(WPADCommandQueue* pQueue, u8 port, WPADCallback pCallback);
BOOL WPADiSendSetReportType(WPADCommandQueue* pQueue, s32 format, WPADCallback pCallback);
BOOL WPADiSendEnableDPD(WPADCommandQueue* pQueue, BOOL enable, WPADCallback pCallback);
BOOL WPADiSendEnableSpeaker(WPADCommandQueue* pQueue, BOOL enable, WPADCallback pCallback);
BOOL WPADiSendGetContStat(WPADCommandQueue* pQueue, WPADInfo* pInfo, WPADCallback pCallback);
BOOL WPADiSendWriteDataCmd(WPADCommandQueue* pQueue, u8 cmd, u32 addr, WPADCallback pCallback);
BOOL WPADiSendWriteData(WPADCommandQueue* pQueue, const void* pSrc, u16 len, u32 addr, WPADCallback pCallback);
BOOL WPADiSendReadData(WPADCommandQueue* pQueue, void* pDst, u16 len, u32 addr, WPADCallback pCallback);
BOOL WPADiSendStreamData(WPADCommandQueue* pQueue, const void* pData, u16 len);
BOOL WPADiSendMuteSpeaker(WPADCommandQueue* pQueue, BOOL mute, WPADCallback pCallback);
BOOL WPADiSendDPDCSB(WPADCommandQueue* pQueue, BOOL enable, WPADCallback pCallback);

void WPADiClearQueue(WPADCommandQueue* pQueue);
BOOL WPADiPushCommand(WPADCommandQueue* pQueue, WPADCommand command);
BOOL WPADiGetCommand(const WPADCommandQueue* pQueue, WPADCommand* pCommand);
BOOL WPADiPopCommand(WPADCommandQueue* pQueue);

u16 _WPADGetStackBufferStatus(s32 chan);
u16 _WPADGetModuleBufferStatus(s32 chan);

inline void __WPADShutdown();

#ifdef __cplusplus
}
#endif
#endif
