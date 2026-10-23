#include ".unsorted/8026FC14.hpp"

#include "common.hpp"

extern "C" {

s32 OSDisableInterrupts(void);
s32 OSSetArenaHi(s32);
s32 OSSetArenaLo(s32);
s32 __OSBootDol(s32, s32, s32);
s32 __OSReboot(s32, s32);

s32 __OSReboot(s32 arg0, s32 arg1) {
    s32 sp8;

    OSDisableInterrupts();
    OSSetArenaLo(0x81280000);
    OSSetArenaHi(0x812F0000);
    sp8 = 0;
    return __OSBootDol(arg1, arg0 | 0x80000000, (s32) &sp8);
}
}

extern "C" {

s32 OSInitThreadQueue(s32);
s32 fn_8026FC14(s32);

s32 fn_8026FC14(s32 arg0) {
    return OSInitThreadQueue(arg0);
}
}

extern "C" {

s32 OSWakeupThread(s32);
s32 fn_8026FC18(s32);

s32 fn_8026FC18(s32 arg0) {
    return OSWakeupThread(arg0);
}
}

extern "C" {

extern s32 lbl_8063FAD0;
extern s32 lbl_8063FAD4;

void OSGetSaveRegion(s32 *arg0, s32 *arg1) {
    *arg0 = lbl_8063FAD0;
    *arg1 = lbl_8063FAD4;
}
}
