#include ".unsorted/800F8AC4.hpp"

#include "common.hpp"

extern "C" {

void fn_800F959C(void) {
    lbl_8063D530->_CC = 45;
}

void fn_800FD4D8(void) {}
void fn_800FE8E4(void) {}
void fn_800FEC90(void) {}
void fn_8010190C(void) {}
void fn_80101B30(void) {}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_800F8AC4(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_80101E58(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0xE8D;
    case 1:
        return 0xE90;
    default:
        return 0;
    }
}
}

extern "C" {

s32 fn_8005A9F8(s32);
s32 fn_800FE1E4(s32, s32);
s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_800FE1E4(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    if (sp8 != 1) {
        return temp_r3;
    }
    return fn_80253EB4(arg0, arg1, 1, fn_8005A9F8(0x1A));
}
}

extern "C" {

s32 fn_800FEC94(s32, s32);

s32 fn_800FEC94(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    if (sp8 != 8) {
        return temp_r3;
    }
    return fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0xE99));
}
}
