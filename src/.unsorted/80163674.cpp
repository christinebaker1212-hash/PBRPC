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

extern "C" {

s32 fn_80163C74(s32);
s32 fn_80163DC4(s32);
s32 fn_8025DFC0(s32, s32);
s32 fn_8025DFD0(void);
extern s32 lbl_8063F080;

s32 fn_80163C74(s32 arg0) {
    if ((s32) lbl_8063F080 == 0) {
        lbl_8063F080 = fn_8025DFC0(fn_8025DFD0(), 0x588);
    }
    return fn_80163DC4(0);
}
}

extern "C" {

s32 fn_80164824(s32, s32, s32, s32);

s32 fn_80164824(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return fn_8016482C(arg0, arg1, arg2, arg3, 0);
}
}

extern "C" {

s32 fn_80164970(s32, s32, s32, s32);
s32 fn_80164978(s32, s32, s32, s32, s32);

s32 fn_80164970(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return fn_80164978(arg0, arg1, arg2, arg3, 0);
}
}

extern "C" {

s32 fn_80164B14(s32, s32, s32);
s32 fn_8025E2B8(s32);
s32 fn_8025EB78(s32, s32, s32, s32);

s32 fn_80164B14(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3 = fn_8025E2B8(fn_8025DFD0());
    if (temp_r3 == 0) {
        return -1;
    }
    temp_r3_2 = ((s32 (*)(s32))fn_80163AFC)(arg0);
    if (temp_r3_2 < 0) {
        return -2;
    }
    return fn_8025EB78(temp_r3, (s32) (u16) temp_r3_2, arg1, arg2);
}
}
