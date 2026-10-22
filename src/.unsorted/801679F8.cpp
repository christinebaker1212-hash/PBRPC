#include ".unsorted/801679F8.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80164C6C(void);
s32 fn_80166C1C(void);
s32 fn_80167A30(void);

s32 fn_80167C4C(void) {
    if (fn_80167A30() < 0) {
        return 7;
    }
    if (fn_80164C6C() == 0) {
        return 7;
    }
    return fn_80166C1C();
}
}

extern "C" {

s32 fn_801679F8(s32, s32);
extern u8 lbl_8063F0E8;

s32 fn_801679F8(s32 arg0, s32 arg1) {
    if ((u32) arg0 >= 4U) {
        return -1;
    }
    if ((arg1 < 0) || (arg1 >= 8)) {
        return -1;
    }
    *(&lbl_8063F0E8 + arg0) = (s8) arg1;
    return 0;
}
}

extern "C" {

s32 Party_ToDS__FP5PartyP7DSPartyi(s32, s32, s32);
s32 fn_80164970(s32, s32, s32, s32);
s32 fn_80167D60(s32, s32, s32);
s32 fn_8025DFC0(s32, s32);
s32 fn_8025DFC8(s32, s32);
s32 fn_8025DFD0(void);

s32 fn_80167D60(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3 = ((s32 (*)(s32))fn_80167A30)(arg0);
    if (temp_r3 < 0) {
        return 7;
    }
    temp_r3_2 = fn_8025DFC0(fn_8025DFD0(), 0x590);
    if (temp_r3_2 == 0) {
        return 7;
    }
    Party_ToDS__FP5PartyP7DSPartyi(arg1, temp_r3_2, 0);
    temp_r31 = fn_80164970(temp_r3, arg2, temp_r3_2, 0x590);
    fn_8025DFC8(fn_8025DFD0(), temp_r3_2);
    return ((s32) (-temp_r31 | temp_r31) >> 0x1F) & 7;
}
}

extern "C" {

s32 fn_80164824(s32, s32, s32, s32);
s32 fn_80167EEC(s32, s32, s32);
s32 fn_8016849C(s32, s32, s32);
s32 fn_8017714C(s32, s32, s32);

s32 fn_80167EEC(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3 = ((s32 (*)(s32))fn_80167A30)(arg0);
    if (temp_r3 < 0) {
        return 7;
    }
    temp_r3_2 = fn_8025DFC0((s32)(fn_8025DFD0()), (s32)(0x200));
    if (temp_r3_2 == 0) {
        return 7;
    }
    fn_8017714C(temp_r3_2, arg1, 0x200);
    temp_r31 = fn_80164824(temp_r3, arg2, temp_r3_2, fn_8016849C(arg1, temp_r3_2, 0x200));
    fn_8025DFC8((s32)(fn_8025DFD0()), (s32)(temp_r3_2));
    return ((s32) (-temp_r31 | temp_r31) >> 0x1F) & 7;
}
}

extern "C" {

s32 fn_80167FDC(s32, s32, s32);

s32 fn_80167FDC(s32 arg0, s32 arg1, s32 arg2) {
    s16 sp8;
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3_2 = ((s32 (*)(s32))fn_80167A30)(arg0);
    if (temp_r3_2 < 0) {
        return 7;
    }
    sp8 = ((arg1 << 8) & 0xFF00) + (u8) ((u32) arg1 >> 8U);
    temp_r3 = fn_80164824((s32)(temp_r3_2), (s32)(arg2), (s32)((s32) &sp8), (s32)(2));
    return ((s32) (-temp_r3 | temp_r3) >> 0x1F) & 7;
}
}

extern "C" {

s32 fn_80164B14(s32, s32, s32);
s32 fn_80168100(s32, s32);

s32 fn_80168100(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(s32))fn_80167A30)(arg0);
    if (temp_r3 < 0) {
        return -1;
    }
    return fn_80164B14(temp_r3, arg1, 0xC);
}
}

extern "C" {

s32 fn_80166C24(s32);
s32 fn_80166C78(s32);
s32 fn_80168148(s32, s32);
s32 memcpy(s32, s32, s32);

s32 fn_80168148(s32 arg0, s32 arg1) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;

    temp_r3 = ((s32 (*)(s32))fn_80167A30)(arg0);
    if (temp_r3 < 0) {
        return 0;
    }
    temp_r3_2 = ((s32 (*)(s32))fn_80164C6C)(temp_r3);
    if (temp_r3_2 == 0) {
        return 0;
    }
    temp_r3_3 = fn_80166C78(temp_r3_2);
    if (temp_r3_3 == 0) {
        return 0;
    }
    memcpy(arg1, temp_r3_3, 0xC);
    fn_80166C24(temp_r3_2);
    return arg1;
}
}

extern "C" {

s32 fn_80166C94(s32);
s32 fn_80166CE8(s32);
s32 fn_80168224(s32, s32);

s32 fn_80168224(s32 arg0, s32 arg1) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;

    temp_r3 = ((s32 (*)(s32))fn_80167A30)(arg0);
    if (temp_r3 < 0) {
        return 0;
    }
    temp_r3_2 = ((s32 (*)(s32))fn_80164C6C)(temp_r3);
    if (temp_r3_2 == 0) {
        return 0;
    }
    temp_r3_3 = fn_80166CE8(temp_r3_2);
    if (temp_r3_3 == 0) {
        return 0;
    }
    memcpy(arg1, temp_r3_3, 0x80);
    fn_80166C94(temp_r3_2);
    return arg1;
}
}
