#include ".unsorted/80185AE0.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80185D20(void) {
    return 0;
}
}

extern "C" {

u8 fn_80187570(u8 *arg0) {
    if (arg0 == NULL) {
        return 0U;
    }
    return (*(u8 *)((u8 *)(arg0) + (0xC)));
}
}

extern "C" {

s32 fn_801864F8(s32, s32, s32, s32, s32, s32);
s32 fn_801868AC(s32, s32, s32, s32, s32);

s32 fn_801864F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    return fn_801868AC(arg2, arg4, arg0, arg1, (s32) (s8) arg5);
}
}

extern "C" {

s32 fn_801C6728(s32);

s32 fn_8018610C(s32 arg0, u32 arg1, s32 arg2) {
    s32 temp_r3;

    temp_r3 = fn_801C6728(arg2);
    if ((arg1 == 0x40U) && (((u16) temp_r3 == 0x92) || ((u16) temp_r3 == 0x95) || ((u16) temp_r3 == 0x98) || ((u16) temp_r3 == 0xCF))) {
        return 1;
    }
    if ((arg1 == 0x80U) && ((u16) temp_r3 == 0x93)) {
        return 1;
    }
    if (((u32) (arg1) == 0x40000U) && (((u32) arg2 == 0x39U) || ((u32) arg2 == 0xFAU))) {
        return 1;
    }
    if ((u32) (arg1) == 0x20000000U) {
        return 1;
    }
    return ((u16) temp_r3 - 0x5E) == 0;
}
}

extern "C" {

s32 fn_801C03A0(s32, s32, s32, s32, s32);
__declspec(section ".data") extern s32 lbl_804211E0;
__declspec(section ".data") extern s32 lbl_80463B28;

s32 fn_801861E0(s32 arg0, u8 *arg1, s32 arg2) {
    s32 sp8[8];
    s32 (*temp_r12)(s32, u8 *, s32 *, u16);
    s32 temp_r6;
    u8 var_r4;

    temp_r6 = fn_801C03A0((s32) &lbl_80463B28, arg0, (s32) sp8, 0, 1);
    if (arg1 == NULL) {
        var_r4 = 0;
    } else {
        var_r4 = (*(u8 *)((u8 *)(arg1) + (0x84C)));
    }
    temp_r12 = (*(s32 (**)(s32, u8 *, s32 *, u16))((u8 *)(((u8 *)(u8 *)&lbl_804211E0 + (var_r4 * 0xC))) + (8)));
    if ((s32) var_r4 == 0) {
        return 0;
    }
    if (temp_r12 == NULL) {
        if (arg1 != NULL) {
            (*(u8 *)((u8 *)(arg1) + (0x84C))) = 0U;
        }
        return 0;
    }
    if (temp_r12(arg0, arg1, sp8, (u16) temp_r6) == 0) {
        if (arg1 != NULL) {
            (*(u8 *)((u8 *)(arg1) + (0x84C))) = 0U;
        }
        return 0;
    }
    return 1;
}
}
