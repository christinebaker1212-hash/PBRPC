#include ".unsorted/80163674.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063D5EC;

u32 fn_80163E70(void) {
    return lbl_8063D5EC;
}
}

#include "common.hpp"

extern "C" {

extern u32 lbl_8063D5F0;

void fn_8016450C(void) {
    lbl_8063D5F0 = 0x0;
}
}

extern "C" {

s32 fn_80163AFC(void);
s32 fn_801643C4(u16);
s32 fn_8016482C(s32, s32, s32, s32, s32);

s32 fn_80164794(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    temp_r3 = fn_80163AFC();
    if (temp_r3 < 0) {
        return -2;
    }
    if (fn_801643C4((u16) temp_r3) != 0) {
        return -5;
    }
    return fn_8016482C(arg0, arg1, arg2, arg3, 1);
}
}
