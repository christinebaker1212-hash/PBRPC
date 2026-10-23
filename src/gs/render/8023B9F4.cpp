

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

extern "C" {

s32 __dl__FPv(s32);

u8 **__dt__17_UnkClass8023C09CFv(u8 **arg0, s32 arg1) {
    u8 *temp_r3;
    u8 *temp_r5;
    u8 *temp_r6;

    if (arg0 != NULL) {
        temp_r6 = *arg0;
        (*(u8 *)((u8 *)(temp_r6) + (1))) = (u8) ((*(u8 *)((u8 *)(temp_r6) + (1))) - 1);
        temp_r5 = *arg0;
        if ((s32) (*(u8 *)((u8 *)(temp_r5) + (1))) == 0) {
            (*(u8 *)((u8 *)(temp_r5) + (0))) = (u8) ((*(u8 *)((u8 *)(temp_r5) + (0))) & 0xFFFFFFDF);
            temp_r3 = *arg0;
            (*(u8 *)((u8 *)(temp_r3) + (0))) = (u8) ((*(u8 *)((u8 *)(temp_r3) + (0))) & 0xFFFFFFEF);
        }
        if (arg1 > 0) {
            __dl__FPv((s32) arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8023C908(s32);
s32 fn_8023CA6C(s32);

void fn_8023C8B4(u8 *arg0) {
    if ((*(u8 *)((u8 *)(arg0) + (0))) & 1) {
        fn_8023CA6C((s32) arg0);
    }
    (*(s32 *)((u8 *)(arg0) + (4))) = fn_8023B9F4();
    (*(u8 *)((u8 *)(arg0) + (0))) = (u8) ((*(u8 *)((u8 *)(arg0) + (0))) | 1);
    fn_8023C908((s32) arg0);
}
}

extern "C" {

u8 *fn_8023BC44(s32, s32);
u8 *fn_8023BD70(s32, s32);
s32 fn_8023C47C(u8 *);
s32 fn_8023CB74(void);

void fn_8023CAD8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4) {
    u8 *temp_r3;
    u8 *temp_r3_2;

    fn_8023CB74();
    temp_r3 = fn_8023BD70((s32)(arg0 + 0x1B8), (s32)(arg1));
    (*(s32 *)((u8 *)(temp_r3) + (0))) = arg1;
    (*(s32 *)((u8 *)(temp_r3) + (4))) = 1;
    if ((arg1 >= 9) || (arg1 < 0)) {
        temp_r3_2 = fn_8023BC44((s32)(arg0 + 8), (s32)(arg1));
        (*(s32 *)((u8 *)(temp_r3_2) + (0))) = arg1;
        (*(s32 *)((u8 *)(temp_r3_2) + (4))) = arg2;
        (*(s32 *)((u8 *)(temp_r3_2) + (8))) = arg3;
        (*(s8 *)((u8 *)(temp_r3_2) + (0xC))) = arg4;
    }
    fn_8023C47C(arg0);
    *arg0 |= 6;
}
}

extern "C" {

void fn_8023BFE4(u8 *arg0) {
    u8 temp_r0;
    u8 *var_r3;
    u8 *var_r4;

    var_r3 = arg0;
    var_r4 = var_r3 + 0x10;
    while ((s32) (*(s32 *)((u8 *)(var_r3) + (0))) != 0xFF) {
        (*(s32 *)((u8 *)(var_r3) + (0))) = (s32) (*(s32 *)((u8 *)(var_r4) + (0)));
        (*(s32 *)((u8 *)(var_r3) + (4))) = (s32) (*(s32 *)((u8 *)(var_r4) + (4)));
        (*(s32 *)((u8 *)(var_r3) + (8))) = (s32) (*(s32 *)((u8 *)(var_r4) + (8)));
        temp_r0 = (*(u8 *)((u8 *)(var_r4) + (0xC)));
        var_r4 += 0x10;
        (*(u8 *)((u8 *)(var_r3) + (0xC))) = temp_r0;
        var_r3 += 0x10;
    }
}
}

extern "C" {

void fn_8023C024(u8 *arg0) {
    s32 temp_r0;
    u8 *var_r3;
    u8 *var_r4;

    var_r3 = arg0;
    var_r4 = var_r3 + 8;
    while ((s32) (*(s32 *)((u8 *)(var_r3) + (0))) != 0xFF) {
        (*(s32 *)((u8 *)(var_r3) + (0))) = (s32) (*(s32 *)((u8 *)(var_r4) + (0)));
        temp_r0 = (*(s32 *)((u8 *)(var_r4) + (4)));
        var_r4 += 8;
        (*(s32 *)((u8 *)(var_r3) + (4))) = temp_r0;
        var_r3 += 8;
    }
}
}

extern "C" {

void fn_8023C054(u8 *arg0) {
    s32 temp_r0;
    u8 *var_r3;
    u8 *var_r4;

    var_r3 = arg0;
    var_r4 = var_r3 + 0xC;
    while ((u8) (*(u8 *)((u8 *)(var_r3) + (3))) != 0xFF) {
        (*(u8 *)((u8 *)(var_r3) + (0))) = (u8) (*(u8 *)((u8 *)(var_r4) + (0)));
        (*(u8 *)((u8 *)(var_r3) + (2))) = (u8) (*(u8 *)((u8 *)(var_r4) + (2)));
        (*(u8 *)((u8 *)(var_r3) + (3))) = (u8) (*(u8 *)((u8 *)(var_r4) + (3)));
        (*(s32 *)((u8 *)(var_r3) + (4))) = (s32) (*(s32 *)((u8 *)(var_r4) + (4)));
        temp_r0 = (*(s32 *)((u8 *)(var_r4) + (8)));
        var_r4 += 0xC;
        (*(s32 *)((u8 *)(var_r3) + (8))) = temp_r0;
        var_r3 += 0xC;
    }
}
}
