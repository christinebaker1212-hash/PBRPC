

#include "common.hpp"

extern "C" {

s32 fn_8023BA34(s32, s32);
s32 fn_8023CAA8__FP14GSvertexFormatUl(s32, s32);

s32 fn_8023CAA8__FP14GSvertexFormatUl(s32 arg0, s32 arg1) {
    return fn_8023BA34(arg0 + 0x1B8, arg1) != 0;
}
}

extern "C" {

s32 fn_8023B9F4(void);
extern s32 lbl_8063F758;

s32 fn_8023B9F4(void) {
    s32 temp_r3;
    u32 var_r0;

    temp_r3 = lbl_8063F758;
    var_r0 = temp_r3 + 1;
    if (var_r0 >= 8U) {
        var_r0 = 0U;
    }
    lbl_8063F758 = (s32) var_r0;
    return temp_r3;
}
}

extern "C" {

s32 fn_8023BA58(s32, s32);
s32 fn_8023C290(s32, s32, s32);

s32 fn_8023C290(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;

    temp_r3 = fn_8023BA58(arg0 + 4, arg1);
    if (temp_r3 != 0) {
        (*(s32 *)((u8 *)(temp_r3) + (4))) = arg2;
        (*(s8 *)((u8 *)(temp_r3) + (0))) = (s8) ((arg2 & 0xC0000000) != 0xC0000000);
    }
    return temp_r3;
}
}
