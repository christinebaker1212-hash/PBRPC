// AXFX declarations from koopthekoopa/wii-ipl (CC0), libs/RVL_SDK/include/revolution/axfx/*.h
// and private/axfx.h, for the AXFX sources imported from wii-ipl. They are a later
// revision than revolution/axfx.h, which the nw4r sound code uses.
#ifndef PRIVATE_AXFX_IPL_H
#define PRIVATE_AXFX_IPL_H

#include <revolution/types.h>

// revolution/axfx/AXFXCommon.h
#ifndef REVOLUTION_AXFX_COMMON_H
#define REVOLUTION_AXFX_COMMON_H


#ifdef __cplusplus
extern "C" {
#endif

#define AXFX_STEREO_CHANNEL_MAX 3
#define AXFX_DPL2_CHANNEL_MAX 4

typedef struct AXFX_BUS {
    s32* left;      // 0x00
    s32* right;     // 0x04
    s32* surround;  // 0x08
} AXFX_BUS;

typedef struct AXFX_BUS_DPL2 {
    s32* L;   // 0x00
    s32* R;   // 0x04
    s32* Ls;  // 0x08
    s32* Rs;  // 0x0C
} AXFX_BUS_DPL2;

#ifdef __cplusplus
}
#endif

#endif  // REVOLUTION_AXFX_COMMON_H

// revolution/axfx/AXFXHooks.h
#ifndef REVOLUTION_AXFX_HOOKS_H
#define REVOLUTION_AXFX_HOOKS_H


#ifdef __cplusplus
extern "C" {
#endif

typedef void* (*AXFXAllocHook)(u32);
typedef void (*AXFXFreeHook)(void*);

void AXFXSetHooks(AXFXAllocHook alloc, AXFXFreeHook free);
void AXFXGetHooks(AXFXAllocHook* alloc, AXFXFreeHook* free);

#ifdef __cplusplus
}
#endif

#endif  // REVOLUTION_AXFX_HOOKS_H

// revolution/axfx/AXFXChorus.h
#ifndef REVOLUTION_AXFX_CHORUS_H
#define REVOLUTION_AXFX_CHORUS_H


#ifdef __cplusplus
extern "C" {
#endif

typedef struct AXFX_CHORUS_EXP_LFO {
    s32* table;      // 0x00
    s32 phaseAdd;    // 0x04
    s32 stepSamp;    // 0x08
    s32 depthSamp;   // 0x0C
    u32 phase;       // 0x10
    u32 sign;        // 0x14
    u32 lastNum;     // 0x18
    s32 lastValue;   // 0x1C
    s32 grad;        // 0x20
    s32 gradFactor;  // 0x24
} AXFX_CHORUS_EXP_LFO;

typedef struct AXFX_CHORUS_EXP_DELAY {
    f32* line[AXFX_STEREO_CHANNEL_MAX];  // 0x00
    u32 inPos;                           // 0x0C
    u32 outPos;                          // 0x10
    u32 lastPos;                         // 0x14
    u32 sizeFP;                          // 0x18
    u32 size;                            // 0x1C
} AXFX_CHORUS_EXP_DELAY;

typedef struct AXFX_CHORUS_EXP {
    AXFX_CHORUS_EXP_DELAY delay;              // 0x00
    AXFX_CHORUS_EXP_LFO lfo;                  // 0x20
    f32 history[AXFX_STEREO_CHANNEL_MAX][4];  // 0x48
    u32 histIndex;                            // 0x78
    u32 active;                               // 0x7C
    f32 delayTime;                            // 0x80
    f32 depth;                                // 0x84
    f32 rate;                                 // 0x88
    f32 feedback;                             // 0x8C
    AXFX_BUS* busIn;                          // 0x90
    AXFX_BUS* busOut;                         // 0x94
    f32 outGain;                              // 0x98
    f32 sendGain;                             // 0x9C
} AXFX_CHORUS_EXP;

typedef struct AXFX_CHORUS {
    AXFX_CHORUS_EXP chorusInner;  // 0x00
    u32 baseDelay;                // 0xA0
    u32 variation;                // 0xA4
    u32 period;                   // 0xA8
} AXFX_CHORUS;

u32 AXFXChorusGetMemSize(AXFX_CHORUS* chorus);
BOOL AXFXChorusInit(AXFX_CHORUS* chorus);
BOOL AXFXChorusSettings(AXFX_CHORUS* chorus);
BOOL AXFXChorusShutdown(AXFX_CHORUS* chorus);
void AXFXChorusCallback(AXFX_BUS* bus, AXFX_CHORUS* chorus);

u32 AXFXChorusExpGetMemSize(AXFX_CHORUS_EXP* chorus);
BOOL AXFXChorusExpInit(AXFX_CHORUS_EXP* chorus);
BOOL AXFXChorusExpSettings(AXFX_CHORUS_EXP* chorus);
BOOL AXFXChorusExpSettingsUpdate(AXFX_CHORUS_EXP* chorus);
void AXFXChorusExpShutdown(AXFX_CHORUS_EXP* chorus);
void AXFXChorusExpCallback(AXFX_BUS* bus, AXFX_CHORUS_EXP* chorus);

#ifdef __cplusplus
}
#endif

#endif  // REVOLUTION_AXFX_CHORUS_H

// revolution/axfx/AXFXChorusDpl2.h
#ifndef REVOLUTION_AXFX_CHORUS_DPL2_H
#define REVOLUTION_AXFX_CHORUS_DPL2_H


#ifdef __cplusplus
extern "C" {
#endif

typedef struct AXFX_CHORUS_EXP_LFO_DPL2 {
    s32* table;      // 0x00
    s32 phaseAdd;    // 0x04
    s32 stepSamp;    // 0x08
    s32 depthSamp;   // 0x0C
    u32 phase;       // 0x10
    u32 sign;        // 0x14
    u32 lastNum;     // 0x18
    s32 lastValue;   // 0x1C
    s32 grad;        // 0x20
    s32 gradFactor;  // 0x24
} AXFX_CHORUS_EXP_LFO_DPL2;

typedef struct AXFX_CHORUS_EXP_DELAY_DPL2 {
    f32* line[AXFX_DPL2_CHANNEL_MAX];  // 0x00
    u32 inPos;                         // 0x10
    u32 outPos;                        // 0x14
    u32 lastPos;                       // 0x18
    u32 sizeFP;                        // 0x1C
    u32 size;                          // 0x20
} AXFX_CHORUS_EXP_DELAY_DPL2;

typedef struct AXFX_CHORUS_EXP_DPL2 {
    AXFX_CHORUS_EXP_DELAY_DPL2 delay;       // 0x00
    AXFX_CHORUS_EXP_LFO_DPL2 lfo;           // 0x24
    f32 history[AXFX_DPL2_CHANNEL_MAX][4];  // 0x4C
    u32 histIndex;                          // 0x8C
    u32 active;                             // 0x90
    f32 delayTime;                          // 0x94
    f32 depth;                              // 0x98
    f32 rate;                               // 0x9C
    f32 feedback;                           // 0xA0
    AXFX_BUS_DPL2* busIn;                   // 0xA4
    AXFX_BUS_DPL2* busOut;                  // 0xA8
    f32 outGain;                            // 0xAC
    f32 sendGain;                           // 0xB0
} AXFX_CHORUS_EXP_DPL2;

typedef struct AXFX_CHORUS_DPL2 {
    AXFX_CHORUS_EXP_DPL2 chorusInner;  // 0x00
    u32 baseDelay;                     // 0xB0
    u32 variation;                     // 0xB4
    u32 period;                        // 0xB8
} AXFX_CHORUS_DPL2;

u32 AXFXChorusGetMemSizeDpl2(AXFX_CHORUS_DPL2* chorus);
BOOL AXFXChorusInitDpl2(AXFX_CHORUS_DPL2* chorus);
BOOL AXFXChorusSettingsDpl2(AXFX_CHORUS_DPL2* chorus);
BOOL AXFXChorusShutdownDpl2(AXFX_CHORUS_DPL2* chorus);
void AXFXChorusCallbackDpl2(AXFX_BUS_DPL2* bus, AXFX_CHORUS_DPL2* chorus);

u32 AXFXChorusExpGetMemSizeDpl2(AXFX_CHORUS_EXP_DPL2* chorus);
BOOL AXFXChorusExpInitDpl2(AXFX_CHORUS_EXP_DPL2* chorus);
BOOL AXFXChorusExpSettingsDpl2(AXFX_CHORUS_EXP_DPL2* chorus);
BOOL AXFXChorusExpSettingsUpdateDpl2(AXFX_CHORUS_EXP_DPL2* chorus);
void AXFXChorusExpShutdownDpl2(AXFX_CHORUS_EXP_DPL2* chorus);
void AXFXChorusExpCallbackDpl2(AXFX_BUS_DPL2* bus, AXFX_CHORUS_EXP_DPL2* chorus);

#ifdef __cplusplus
}
#endif

#endif  // REVOLUTION_AXFX_CHORUS_DPL2_H

// revolution/axfx/AXFXDelay.h
#ifndef REVOLUTION_AXFX_DELAY_H
#define REVOLUTION_AXFX_DELAY_H


#ifdef __cplusplus
extern "C" {
#endif

typedef struct AXFX_DELAY_EXP {
    s32* lineL;                               // 0x00
    s32* lineR;                               // 0x04
    s32* lineS;                               // 0x08
    u32 curPos;                               // 0x0C
    u32 length;                               // 0x10
    u32 maxLength;                            // 0x14
    s32 feedbackGain;                         // 0x18
    s32 lastLpfOut[AXFX_STEREO_CHANNEL_MAX];  // 0x1C
    s32 lpfCoef;                              // 0x28
    s32 outGainCalc;                          // 0x2C
    s32 sendGainCalc;                         // 0x30
    u32 active;                               // 0x34
    f32 maxDelay;                             // 0x38
    f32 delay;                                // 0x3C
    f32 feedback;                             // 0x40
    f32 lpf;                                  // 0x44
    AXFX_BUS* busIn;                          // 0x48
    AXFX_BUS* busOut;                         // 0x4C
    f32 outGain;                              // 0x50
    f32 sendGain;                             // 0x54
} AXFX_DELAY_EXP;

typedef struct AXFX_DELAY {
    s32* line[AXFX_STEREO_CHANNEL_MAX];         // 0x00
    u32 curPos[AXFX_STEREO_CHANNEL_MAX];        // 0x0C
    u32 length[AXFX_STEREO_CHANNEL_MAX];        // 0x18
    s32 feedbackGain[AXFX_STEREO_CHANNEL_MAX];  // 0x24
    s32 outGain[AXFX_STEREO_CHANNEL_MAX];       // 0x30
    u32 active;                                 // 0x3C
    u32 delay[AXFX_STEREO_CHANNEL_MAX];         // 0x48
    u32 feedback[AXFX_STEREO_CHANNEL_MAX];      // 0x54
    u32 output[AXFX_STEREO_CHANNEL_MAX];        // 0x60
} AXFX_DELAY;

u32 AXFXDelayGetMemSize(AXFX_DELAY* delay);
BOOL AXFXDelayInit(AXFX_DELAY* delay);
BOOL AXFXDelaySettings(AXFX_DELAY* delay);
void AXFXDelayShutdown(AXFX_DELAY* delay);
void AXFXDelayCallback(AXFX_BUS* bus, AXFX_DELAY* delay);

u32 AXFXDelayExpGetMemSize(AXFX_DELAY_EXP* delay);
BOOL AXFXDelayExpInit(AXFX_DELAY_EXP* delay);
BOOL AXFXDelayExpSettings(AXFX_DELAY_EXP* delay);
BOOL AXFXDelayExpSettingsUpdate(AXFX_DELAY_EXP* delay);
void AXFXDelayExpShutdown(AXFX_DELAY_EXP* delay);
void AXFXDelayExpCallback(AXFX_BUS* bus, AXFX_DELAY_EXP* delay);

#ifdef __cplusplus
}
#endif

#endif  // REVOLUTION_AXFX_DELAY_H

// revolution/axfx/AXFXDelayDpl2.h
#ifndef REVOLUTION_AXFX_DELAY_DPL2_H
#define REVOLUTION_AXFX_DELAY_DPL2_H


#ifdef __cplusplus
extern "C" {
#endif

typedef struct AXFX_DELAY_EXP_DPL2 {
    s32* line[AXFX_DPL2_CHANNEL_MAX];       // 0x00
    u32 curPos;                             // 0x10
    u32 length;                             // 0x14
    u32 maxLength;                          // 0x18
    s32 feedbackGain;                       // 0x1C
    s32 lastLpfOut[AXFX_DPL2_CHANNEL_MAX];  // 0x20
    s32 lpfCoef;                            // 0x30
    s32 outGainCalc;                        // 0x34
    s32 sendGainCalc;                       // 0x38
    u32 active;                             // 0x3C
    f32 maxDelay;                           // 0x40
    f32 delay;                              // 0x44
    f32 feedback;                           // 0x48
    f32 lpf;                                // 0x4C
    AXFX_BUS_DPL2* busIn;                   // 0x50
    AXFX_BUS_DPL2* busOut;                  // 0x54
    f32 outGain;                            // 0x58
    f32 sendGain;                           // 0x5C
} AXFX_DELAY_EXP_DPL2;

typedef struct AXFX_DELAY_DPL2 {
    s32* line[AXFX_DPL2_CHANNEL_MAX];         // 0x00
    u32 curPos[AXFX_DPL2_CHANNEL_MAX];        // 0x10
    u32 length[AXFX_DPL2_CHANNEL_MAX];        // 0x20
    s32 feedbackGain[AXFX_DPL2_CHANNEL_MAX];  // 0x30
    s32 outGain[AXFX_DPL2_CHANNEL_MAX];       // 0x40
    u32 active;                               // 0x50
    u32 delay[AXFX_DPL2_CHANNEL_MAX];         // 0x60
    u32 feedback[AXFX_DPL2_CHANNEL_MAX];      // 0x70
    u32 output[AXFX_DPL2_CHANNEL_MAX];        // 0x80
} AXFX_DELAY_DPL2;

u32 AXFXDelayGetMemSizeDpl2(AXFX_DELAY_DPL2* delay);
BOOL AXFXDelayInitDpl2(AXFX_DELAY_DPL2* delay);
BOOL AXFXDelaySettingsDpl2(AXFX_DELAY_DPL2* delay);
BOOL AXFXDelaySettingsUpdateDpl2(AXFX_DELAY_DPL2* delay);
void AXFXDelayShutdownDpl2(AXFX_DELAY_DPL2* delay);
void AXFXDelayCallbackDpl2(AXFX_BUS_DPL2* bus, AXFX_DELAY_DPL2* delay);

u32 AXFXDelayExpGetMemSizeDpl2(AXFX_DELAY_EXP_DPL2* delay);
BOOL AXFXDelayExpInitDpl2(AXFX_DELAY_EXP_DPL2* delay);
BOOL AXFXDelayExpSettingsDpl2(AXFX_DELAY_EXP_DPL2* delay);
BOOL AXFXDelayExpSettingsUpdateDpl2(AXFX_DELAY_EXP_DPL2* delay);
void AXFXDelayExpShutdownDpl2(AXFX_DELAY_EXP_DPL2* delay);
void AXFXDelayExpCallbackDpl2(AXFX_BUS_DPL2* bus, AXFX_DELAY_EXP_DPL2* delay);

#ifdef __cplusplus
}
#endif

#endif  // REVOLUTION_AXFX_DELAY_DPL2_H

// revolution/axfx/AXFXReverbHi.h
#ifndef REVOLUTION_AXFX_REVERB_HIGH_H
#define REVOLUTION_AXFX_REVERB_HIGH_H


#ifdef __cplusplus
extern "C" {
#endif

typedef struct AXFX_REVERBHI_EXP {
    f32* earlyLine[AXFX_STEREO_CHANNEL_MAX];            // 0x00
    u32 earlyPos[3];                                    // 0x0C
    u32 earlyLength;                                    // 0x18
    u32 earlyMaxLength;                                 // 0x1C
    f32 earlyCoef[3];                                   // 0x20
    f32* preDelayLine[AXFX_STEREO_CHANNEL_MAX];         // 0x2C
    u32 preDelayPos;                                    // 0x38
    u32 preDelayLength;                                 // 0x3C
    u32 preDelayMaxLength;                              // 0x40
    f32* combLine[AXFX_STEREO_CHANNEL_MAX][3];          // 0x44
    u32 combPos[3];                                     // 0x68
    u32 combLength[3];                                  // 0x74
    u32 combMaxLength[3];                               // 0x80
    f32 combCoef[3];                                    // 0x8C
    f32* allpassLine[AXFX_STEREO_CHANNEL_MAX][2];       // 0x98
    u32 allpassPos[2];                                  // 0xB0
    u32 allpassLength[2];                               // 0xB8
    u32 allpassMaxLength[2];                            // 0xC0
    f32* lastAllpassLine[AXFX_STEREO_CHANNEL_MAX];      // 0xC8
    u32 lastAllpassPos[AXFX_STEREO_CHANNEL_MAX];        // 0xD4
    u32 lastAllpassLength[AXFX_STEREO_CHANNEL_MAX];     // 0xE0
    u32 lastAllpassMaxLength[AXFX_STEREO_CHANNEL_MAX];  // 0xEC
    f32 allpassCoef;                                    // 0xF8
    f32 lastLpfOut[AXFX_STEREO_CHANNEL_MAX];            // 0xFC
    f32 lpfCoef;                                        // 0x108
    u32 active;                                         // 0x10C
    u32 earlyMode;                                      // 0x110
    f32 preDelayTimeMax;                                // 0x114
    f32 preDelayTime;                                   // 0x118
    u32 fusedMode;                                      // 0x11C
    f32 fusedTime;                                      // 0x120
    f32 coloration;                                     // 0x124
    f32 damping;                                        // 0x128
    f32 crosstalk;                                      // 0x12C
    f32 earlyGain;                                      // 0x130
    f32 fusedGain;                                      // 0x134
    AXFX_BUS* busIn;                                    // 0x138
    AXFX_BUS* busOut;                                   // 0x13C
    f32 outGain;                                        // 0x140
    f32 sendGain;                                       // 0x144
} AXFX_REVERBHI_EXP;

typedef struct AXFX_REVERBHI {
    AXFX_REVERBHI_EXP reverbInner;  // 0x00
    f32 coloration;                 // 0x148
    f32 mix;                        // 0x14C
    f32 time;                       // 0x150
    f32 damping;                    // 0x154
    f32 preDelay;                   // 0x158
    f32 crosstalk;                  // 0x15C
} AXFX_REVERBHI;

u32 AXFXReverbHiGetMemSize(AXFX_REVERBHI* reverb);
BOOL AXFXReverbHiInit(AXFX_REVERBHI* reverb);
BOOL AXFXReverbHiSettings(AXFX_REVERBHI* reverb);
BOOL AXFXReverbHiShutdown(AXFX_REVERBHI* reverb);
void AXFXReverbHiCallback(AXFX_BUS* bus, AXFX_REVERBHI* reverb);

u32 AXFXReverbHiExpGetMemSize(AXFX_REVERBHI_EXP* reverb);
BOOL AXFXReverbHiExpInit(AXFX_REVERBHI_EXP* reverb);
BOOL AXFXReverbHiExpSettings(AXFX_REVERBHI_EXP* reverb);
BOOL AXFXReverbHiExpSettingsUpdate(AXFX_REVERBHI_EXP* reverb);
void AXFXReverbHiExpShutdown(AXFX_REVERBHI_EXP* reverb);
void AXFXReverbHiExpCallback(AXFX_BUS* bus, AXFX_REVERBHI_EXP* reverb);

#ifdef __cplusplus
}
#endif

#endif  // REVOLUTION_AXFX_REVERB_HIGH_H

// revolution/axfx/AXFXReverbHiDpl2.h
#ifndef REVOLUTION_AXFX_REVERB_HIGH_DPL2_H
#define REVOLUTION_AXFX_REVERB_HIGH_DPL2_H


#ifdef __cplusplus
extern "C" {
#endif

typedef struct AXFX_REVERBHI_EXP_DPL2 {
    f32* earlyLine[AXFX_DPL2_CHANNEL_MAX];            // 0x00
    u32 earlyPos[3];                                  // 0x10
    u32 earlyLength;                                  // 0x1C
    u32 earlyMaxLength;                               // 0x20
    f32 earlyCoef[3];                                 // 0x24
    f32* preDelayLine[AXFX_DPL2_CHANNEL_MAX];         // 0x30
    u32 preDelayPos;                                  // 0x40
    u32 preDelayLength;                               // 0x44
    u32 preDelayMaxLength;                            // 0x48
    f32* combLine[AXFX_DPL2_CHANNEL_MAX][3];          // 0x4C
    u32 combPos[3];                                   // 0x7C
    u32 combLength[3];                                // 0x88
    u32 combMaxLength[3];                             // 0x94
    f32 combCoef[3];                                  // 0xA0
    f32* allpassLine[AXFX_DPL2_CHANNEL_MAX][2];       // 0xAC
    u32 allpassPos[2];                                // 0xCC
    u32 allpassLength[2];                             // 0xD4
    u32 allpassMaxLength[2];                          // 0xE4
    f32* lastAllpassLine[AXFX_DPL2_CHANNEL_MAX];      // 0xF4
    u32 lastAllpassPos[AXFX_DPL2_CHANNEL_MAX];        // 0x104
    u32 lastAllpassLength[AXFX_DPL2_CHANNEL_MAX];     // 0x114
    u32 lastAllpassMaxLength[AXFX_DPL2_CHANNEL_MAX];  // 0x124
    f32 allpassCoef;                                  // 0x128
    f32 lastLpfOut[AXFX_DPL2_CHANNEL_MAX];            // 0x138
    f32 lpfCoef;                                      // 0x130
    u32 active;                                       // 0x13C
    u32 earlyMode;                                    // 0x140
    f32 preDelayTimeMax;                              // 0x144
    f32 preDelayTime;                                 // 0x148
    u32 fusedMode;                                    // 0x14C
    f32 fusedTime;                                    // 0x150
    f32 coloration;                                   // 0x154
    f32 damping;                                      // 0x158
    f32 crosstalk;                                    // 0x15C
    f32 earlyGain;                                    // 0x160
    f32 fusedGain;                                    // 0x164
    AXFX_BUS_DPL2* busIn;                             // 0x168
    AXFX_BUS_DPL2* busOut;                            // 0x16C
    f32 outGain;                                      // 0x170
    f32 sendGain;                                     // 0x174
} AXFX_REVERBHI_EXP_DPL2;

typedef struct AXFX_REVERBHI_DPL2 {
    AXFX_REVERBHI_EXP_DPL2 reverbInner;  // 0x00
    f32 coloration;                      // 0x178
    f32 mix;                             // 0x17C
    f32 time;                            // 0x180
    f32 damping;                         // 0x184
    f32 preDelay;                        // 0x188
    f32 crosstalk;                       // 0x118C
} AXFX_REVERBHI_DPL2;

u32 AXFXReverbHiGetMemSizeDpl2(AXFX_REVERBHI_DPL2* reverb);
BOOL AXFXReverbHiInitDpl2(AXFX_REVERBHI_DPL2* reverb);
BOOL AXFXReverbHiSettingsDpl2(AXFX_REVERBHI_DPL2* reverb);
BOOL AXFXReverbHiShutdownDpl2(AXFX_REVERBHI_DPL2* reverb);
void AXFXReverbHiCallbackDpl2(AXFX_BUS_DPL2* bus, AXFX_REVERBHI_DPL2* reverb);

u32 AXFXReverbHiExpGetMemSizeDpl2(AXFX_REVERBHI_EXP_DPL2* reverb);
BOOL AXFXReverbHiExpInitDpl2(AXFX_REVERBHI_EXP_DPL2* reverb);
BOOL AXFXReverbHiExpSettingsDpl2(AXFX_REVERBHI_EXP_DPL2* reverb);
BOOL AXFXReverbHiExpSettingsUpdateDpl2(AXFX_REVERBHI_EXP_DPL2* reverb);
void AXFXReverbHiExpShutdownDpl2(AXFX_REVERBHI_EXP_DPL2* reverb);
void AXFXReverbHiExpCallbackDpl2(AXFX_BUS_DPL2* bus, AXFX_REVERBHI_EXP_DPL2* reverb);

#ifdef __cplusplus
}
#endif

#endif  // REVOLUTION_AXFX_REVERB_HIGH_DPL2_H

// revolution/axfx/AXFXReverbStd.h
#ifndef REVOLUTION_AXFX_REVERB_STANDARD_H
#define REVOLUTION_AXFX_REVERB_STANDARD_H


#ifdef __cplusplus
extern "C" {
#endif

typedef struct AXFX_REVERBSTD_EXP {
    f32* earlyLine[AXFX_STEREO_CHANNEL_MAX];       // 0x00
    u32 earlyPos;                                  // 0x0C
    u32 earlyLength;                               // 0x10
    u32 earlyMaxLength;                            // 0x14
    f32 earlyCoef;                                 // 0x18
    f32* preDelayLine[AXFX_STEREO_CHANNEL_MAX];    // 0x1C
    u32 preDelayPos;                               // 0x28
    u32 preDelayLength;                            // 0x2C
    u32 preDelayMaxLength;                         // 0x30
    f32* combLine[AXFX_STEREO_CHANNEL_MAX][2];     // 0x34
    u32 combPos[2];                                // 0x4C
    u32 combLength[2];                             // 0x54
    u32 combMaxLength[2];                          // 0x5C
    f32 combCoef[2];                               // 0x64
    f32* allpassLine[AXFX_STEREO_CHANNEL_MAX][2];  // 0x6C
    u32 allpassPos[2];                             // 0x84
    u32 allpassLength[2];                          // 0x8C
    u32 allpassMaxLength[2];                       // 0x94
    f32 allpassCoef;                               // 0x9C
    f32 lastLpfOut[AXFX_STEREO_CHANNEL_MAX];       // 0xA0
    f32 lpfCoef;                                   // 0xAC
    u32 active;                                    // 0xB0
    u32 earlyMode;                                 // 0xB4
    f32 preDelayTimeMax;                           // 0xB8
    f32 preDelayTime;                              // 0xBC
    u32 fusedMode;                                 // 0xC0
    f32 fusedTime;                                 // 0xC4
    f32 coloration;                                // 0xC8
    f32 damping;                                   // 0xCC
    f32 earlyGain;                                 // 0xD0
    f32 fusedGain;                                 // 0xD4
    AXFX_BUS* busIn;                               // 0xD8
    AXFX_BUS* busOut;                              // 0xDC
    f32 outGain;                                   // 0xE0
    f32 sendGain;                                  // 0xE4
} AXFX_REVERBSTD_EXP;

typedef struct AXFX_REVERBSTD {
    AXFX_REVERBSTD_EXP reverbInner;  // 0x00
    f32 coloration;                  // 0xE8
    f32 mix;                         // 0xEC
    f32 time;                        // 0xF0
    f32 damping;                     // 0xF4
    f32 preDelay;                    // 0xF8
} AXFX_REVERBSTD;

u32 AXFXReverbStdGetMemSize(AXFX_REVERBSTD* reverb);
BOOL AXFXReverbStdInit(AXFX_REVERBSTD* reverb);
BOOL AXFXReverbStdSettings(AXFX_REVERBSTD* reverb);
BOOL AXFXReverbStdShutdown(AXFX_REVERBSTD* reverb);
void AXFXReverbStdCallback(AXFX_BUS* bus, AXFX_REVERBSTD* reverb);

u32 AXFXReverbStdExpGetMemSize(AXFX_REVERBSTD_EXP* reverb);
BOOL AXFXReverbStdExpInit(AXFX_REVERBSTD_EXP* reverb);
BOOL AXFXReverbStdExpSettings(AXFX_REVERBSTD_EXP* reverb);
BOOL AXFXReverbStdExpSettingsUpdate(AXFX_REVERBSTD_EXP* reverb);
void AXFXReverbStdExpShutdown(AXFX_REVERBSTD_EXP* reverb);
void AXFXReverbStdExpCallback(AXFX_BUS* bus, AXFX_REVERBSTD_EXP* reverb);

#ifdef __cplusplus
}
#endif

#endif  // REVOLUTION_AXFX_REVERB_STANDARD_H

// revolution/axfx/AXFXReverbStdDpl2.h
#ifndef REVOLUTION_AXFX_REVERB_STANDARD_DPL2_H
#define REVOLUTION_AXFX_REVERB_STANDARD_DPL2_H


#ifdef __cplusplus
extern "C" {
#endif

typedef struct AXFX_REVERBSTD_EXP_DPL2 {
    f32* earlyLine[AXFX_DPL2_CHANNEL_MAX];       // 0x00
    u32 earlyPos;                                // 0x10
    u32 earlyLength;                             // 0x14
    u32 earlyMaxLength;                          // 0x18
    f32 earlyCoef;                               // 0x1C
    f32* preDelayLine[AXFX_DPL2_CHANNEL_MAX];    // 0x20
    u32 preDelayPos;                             // 0x30
    u32 preDelayLength;                          // 0x34
    u32 preDelayMaxLength;                       // 0x38
    f32* combLine[AXFX_DPL2_CHANNEL_MAX][2];     // 0x3C
    u32 combPos[2];                              // 0x5C
    u32 combLength[2];                           // 0x64
    u32 combMaxLength[2];                        // 0x6C
    f32 combCoef[2];                             // 0x74
    f32* allpassLine[AXFX_DPL2_CHANNEL_MAX][2];  // 0x7C
    u32 allpassPos[2];                           // 0x9C
    u32 allpassLength[2];                        // 0xA4
    u32 allpassMaxLength[2];                     // 0xAC
    f32 allpassCoef;                             // 0xB4
    f32 lastLpfOut[AXFX_DPL2_CHANNEL_MAX];       // 0xB8
    f32 lpfCoef;                                 // 0xC8
    u32 active;                                  // 0xCC
    u32 earlyMode;                               // 0xD0
    f32 preDelayTimeMax;                         // 0xD4
    f32 preDelayTime;                            // 0xD8
    u32 fusedMode;                               // 0xDC
    f32 fusedTime;                               // 0xE0
    f32 coloration;                              // 0xE4
    f32 damping;                                 // 0xE8
    f32 earlyGain;                               // 0xEC
    f32 fusedGain;                               // 0xF0
    AXFX_BUS_DPL2* busIn;                        // 0xF4
    AXFX_BUS_DPL2* busOut;                       // 0xF8
    f32 outGain;                                 // 0xFC
    f32 sendGain;                                // 0x100
} AXFX_REVERBSTD_EXP_DPL2;

typedef struct AXFX_REVERBSTD_DPL2 {
    AXFX_REVERBSTD_EXP_DPL2 reverbInner;  // 0x00
    f32 coloration;                       // 0x104
    f32 mix;                              // 0x108
    f32 time;                             // 0x10C
    f32 damping;                          // 0x110
    f32 preDelay;                         // 0x114
} AXFX_REVERBSTD_DPL2;

u32 AXFXReverbStdGetMemSizeDpl2(AXFX_REVERBSTD_DPL2* reverb);
BOOL AXFXReverbStdInitDpl2(AXFX_REVERBSTD_DPL2* reverb);
BOOL AXFXReverbStdSettingsDpl2(AXFX_REVERBSTD_DPL2* reverb);
BOOL AXFXReverbStdShutdownDpl2(AXFX_REVERBSTD_DPL2* reverb);
void AXFXReverbStdCallbackDpl2(AXFX_BUS_DPL2* bus, AXFX_REVERBSTD_DPL2* reverb);

u32 AXFXReverbStdExpGetMemSizeDpl2(AXFX_REVERBSTD_EXP_DPL2* reverb);
BOOL AXFXReverbStdExpInitDpl2(AXFX_REVERBSTD_EXP_DPL2* reverb);
BOOL AXFXReverbStdExpSettingsDpl2(AXFX_REVERBSTD_EXP_DPL2* reverb);
BOOL AXFXReverbStdExpSettingsUpdateDpl2(AXFX_REVERBSTD_EXP_DPL2* reverb);
void AXFXReverbStdExpShutdownDpl2(AXFX_REVERBSTD_EXP_DPL2* reverb);
void AXFXReverbStdExpCallbackDpl2(AXFX_BUS_DPL2* bus, AXFX_REVERBSTD_EXP_DPL2* reverb);

#ifdef __cplusplus
}
#endif

#endif  // REVOLUTION_AXFX_REVERB_STANDARD_DPL2_H

// private/axfx.h
#ifndef PRIVATE_AXFX_H
#define PRIVATE_AXFX_H


#ifdef __cplusplus
extern "C" {
#endif

extern AXFXAllocHook __AXFXAlloc;
extern AXFXFreeHook __AXFXFree;

s32* __AXFXGetLfoSinTable();
f32* __AXFXGetSrcCoef(u32 i);

#ifdef __cplusplus
}
#endif

#endif  // PRIVATE_AXFX_H

#endif  // PRIVATE_AXFX_IPL_H
