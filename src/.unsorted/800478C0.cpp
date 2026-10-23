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
