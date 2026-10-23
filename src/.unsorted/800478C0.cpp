#include ".unsorted/800478C0.hpp"

#include "common.hpp"

extern "C" {

void fn_8004819C(void) {}
}

extern "C" {

s32 __dl__FPv(s32);
s32 fn_80047AA8(void);

s32 fn_80047908(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_80047AA8();
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8004795C(s32, s32);
s32 fn_80047B7C(s32, s32);
s32 fn_8004D80C(void);
s32 fn_8004DA88(s32, s32);

s32 fn_80047B7C(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_8004DA88(fn_8004D80C(), arg1);
    if (temp_r3 != 0) {
        fn_8004795C(arg0, temp_r3);
        return 1;
    }
    return 0;
}
}

extern "C" {

s32 fn_80047BDC(s32, s32, s32);
s32 fn_8004DBE8(s32, s32, s32);

s32 fn_80047BDC(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;

    temp_r3 = fn_8004DBE8(fn_8004D80C(), arg1, arg2);
    if (temp_r3 != 0) {
        fn_8004795C(arg0, temp_r3);
        return 1;
    }
    return 0;
}
}

extern "C" {

s32 fn_80033088__Fv(void);
s32 fn_80033B7C__FP11Unk80033090Ul(s32, s32);
s32 fn_80035970__FP11Unk80035380(s32);
s32 fn_800481A0(s32);

s32 fn_800481A0(s32 arg0) {
    s32 temp_r3;

    temp_r3 = fn_80033B7C__FP11Unk80033090Ul(fn_80033088__Fv(), (s32) (u16) (*(s32 *)((u8 *)(arg0) + (0x20))));
    if (temp_r3 == 0) {
        return 0;
    }
    return fn_80035970__FP11Unk80035380(temp_r3);
}
}

extern "C" {

s32 fn_8004828C(u32 *arg0, s32 arg1) {
    switch (arg1) {
    case 0:
        return ((u32) *arg0 >> 1U) & 1;
    }
    return 0;
}
}

extern "C" {

void fn_800478C0(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = 0;
    (*(f32 *)((u8 *)(arg0) + (0x14))) = (f32) (0.0f);
}
}

extern "C" {

void fn_800478E4(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x2C))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x30))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x20))) = 0;
    (*(f32 *)((u8 *)(arg0) + (0x1C))) = (f32) (0.0f);
    (*(f32 *)((u8 *)(arg0) + (0xC))) = (f32) (0.0f);
}
}

extern "C" {

f32 fn_80049058(s32);

void fn_80048208(u8 *arg0, f32 farg0) {
    u8 *temp_r4;
    u8 *temp_r4_2;

    temp_r4 = (*(u8 **)((u8 *)(arg0) + (0x2C)));
    (*(f32 *)((u8 *)(arg0) + (0xC))) = farg0;
    (*(s32 *)((u8 *)(arg0) + (0))) = (s32) (((*(s32 *)((u8 *)(arg0) + (0))) | 2) & 0xFFFFFFF3);
    (*(u8 **)((u8 *)(arg0) + (0x28))) = temp_r4;
    if (farg0 > (0.0f)) {
        (*(f32 *)((u8 *)(temp_r4) + (0x20))) = farg0;
    }
    temp_r4_2 = (*(u8 **)((u8 *)(arg0) + (0x34)));
    if (temp_r4_2 != NULL) {
        (*(f32 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x28)))) + (0x1C))) = (f32) (*(f32 *)((u8 *)(temp_r4_2) + (0xD80)));
    }
    (*(f32 *)((u8 *)(arg0) + (0x14))) = (f32) (0.0f);
    (*(f32 *)((u8 *)(arg0) + (0x18))) = (f32) (0.0f);
    (*(f32 *)((u8 *)(arg0) + (0x1C))) = fn_80049058((*(s32 *)((u8 *)(arg0) + (0x24))));
}
}
