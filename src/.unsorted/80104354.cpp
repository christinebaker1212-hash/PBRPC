#include ".unsorted/80104354.hpp"

#include "common.hpp"

extern "C" {

void fn_80116344(void) {
    lbl_8063D540->mFlags &= ~0x200;
}
void fn_80116358(void) {
    lbl_8063D540->mFlags |= 0x200;
}
void fn_80116684(void) {}
}

extern "C" {

s32 __dt__7GSsceneFv(s32, s32);
s32 findTarget__14GSrenderTargetFl(s32);
s32 fn_80114CDC(s32);
s32 fn_801E37F0(s32);
s32 getCachedFile__7GScacheFUlUl(s32, s32);
extern u8 *lbl_8063D544;

s32 fn_80114CDC(s32 arg0) {
    s32 temp_r0;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 var_r3;

    temp_r3 = findTarget__14GSrenderTargetFl(2);
    temp_r0 = (*(s32 *)((u8 *)(lbl_8063D544) + (0xFC)));
    if (temp_r0 != 0) {
        (*(s32 *)((u8 *)(temp_r3) + (0xC))) = temp_r0;
    }
    temp_r3_2 = (*(s32 *)((u8 *)(arg0) + (0xF4)));
    if (temp_r3_2 != 0) {
        __dt__7GSsceneFv(temp_r3_2, 1);
        (*(s32 *)((u8 *)(arg0) + (0xF4))) = 0;
        (*(s32 *)((u8 *)(arg0) + (0xF8))) = 0;
    }
    temp_r3_3 = (*(s32 *)((u8 *)(arg0) + (0xF0)));
    if (temp_r3_3 != 0) {
        __dt__7GSsceneFv(temp_r3_3, 1);
        (*(s32 *)((u8 *)(arg0) + (0xF0))) = 0;
    }
    temp_r3_4 = getCachedFile__7GScacheFUlUl(0x70, 0x16B60400);
    if (temp_r3_4 != 0) {
        fn_801E37F0(temp_r3_4);
    }
    var_r3 = getCachedFile__7GScacheFUlUl(0x70, 0x20E20400);
    if (var_r3 != 0) {
        var_r3 = fn_801E37F0(var_r3);
    }
    return var_r3;
}
}

extern "C" {

s32 fn_80114F50(s32);

s32 fn_80114F50(s32 arg0) {
    s32 temp_r0;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r3;

    temp_r3 = findTarget__14GSrenderTargetFl((s32)(2));
    temp_r0 = (*(s32 *)((u8 *)(lbl_8063D544) + (0xFC)));
    if (temp_r0 != 0) {
        (*(s32 *)((u8 *)(temp_r3) + (0xC))) = temp_r0;
    }
    temp_r3_2 = (*(s32 *)((u8 *)(arg0) + (0xF0)));
    if (temp_r3_2 != 0) {
        __dt__7GSsceneFv(temp_r3_2, 1);
        (*(s32 *)((u8 *)(arg0) + (0xF0))) = 0;
    }
    var_r3 = getCachedFile__7GScacheFUlUl((s32)(0x6F), (s32)(0x0B510400));
    if (var_r3 != 0) {
        var_r3 = fn_801E37F0(var_r3);
    }
    return var_r3;
}
}
