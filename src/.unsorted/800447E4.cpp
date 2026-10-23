#include ".unsorted/800447E4.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063EAA8;

u32 fn_80044848(void) {
    return lbl_8063EAA8;
}
void fn_80044A98(void) {}
void fn_80044AA8(void) {}
}

#include "common.hpp"

extern "C" {

void fn_80044A8C(u8 *p, u32 x, u8 y) {
    *(u32 *)(p + 0x4) = x;
    *(u8 *)(p + 0x1) = y;
}
}

extern "C" {

s32 fn_80044A04(u32);
s32 fn_80044B64(u32);

u32 fn_80044898(u32 arg0) {
    u32 var_r30;
    u32 var_r31;

    var_r30 = arg0 + 0x780;
    var_r31 = arg0;
    do {
        fn_80044B64(var_r31);
        var_r31 += 0xF0;
    } while (var_r31 < var_r30);
    do {
        fn_80044A04(var_r30);
        var_r30 += 0xE8;
    } while (var_r30 < (u32) (arg0 + 0xEC0));
    return arg0;
}
}

extern "C" {

s32 fn_8025009C(s32, s32, s32, s16, s16, s32, s32, s32);
s32 fn_80250134(s32, s32, s32, s16, s16, s32);

void fn_80044AAC(u8 *arg0) {
    s32 temp_r4;

    if (((s32) (*(u8 *)((u8 *)(arg0) + (0))) != 0) && (temp_r4 = (*(s32 *)((u8 *)(arg0) + (4))), ((temp_r4 == 0) == 0))) {
        if ((s32) (*(u8 *)((u8 *)(arg0) + (1))) != 0) {
            fn_8025009C(temp_r4, (s32) (*(f32 *)((u8 *)(arg0) + (8))), (s32) (*(f32 *)((u8 *)(arg0) + (0xC))), (*(s16 *)((u8 *)(arg0) + (0x14))), (*(s16 *)((u8 *)(arg0) + (0x16))), (*(s32 *)((u8 *)(arg0) + (0x10))), 0, 1);
            return;
        }
        fn_80250134(temp_r4, (s32) (*(f32 *)((u8 *)(arg0) + (8))), (s32) (*(f32 *)((u8 *)(arg0) + (0xC))), (*(s16 *)((u8 *)(arg0) + (0x14))), (*(s16 *)((u8 *)(arg0) + (0x16))), (*(s32 *)((u8 *)(arg0) + (0x10))));
    }
}
}

extern "C" {

s32 fn_80250560(u8 *, s32, f32);

void fn_80044CD0(u8 *arg0) {
    s32 temp_r4;

    temp_r4 = (*(s32 *)((u8 *)(arg0) + (0x1C)));
    fn_80250560(arg0 + 0x90, temp_r4, (f32) (u8) temp_r4);
}
}

extern "C" {

s32 fn_80044A9C(s32, s32, s32);
s32 fn_8015C308(s32, s32);

s32 fn_80044A9C(s32 arg0, s32 arg1, s32 arg2) {
    return fn_8015C308(arg1, arg2);
}
}

extern "C" {

s32 fn_80044C8C(s32, s32, s32);

s32 fn_80044C8C(s32 arg0, s32 arg1, s32 arg2) {
    return fn_8015C308(arg1, arg2);
}
}

extern "C" {

s32 fn_8000739C__Fv(void);
void fn_80044908(u32 arg0, f32 farg0);

void fn_80044850(void) {
    if ((s32) lbl_8063EAA8 != 0) {
        fn_8000739C__Fv();
        ((s32 (*)(s32))fn_80044908)(lbl_8063EAA8);
    }
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 __nw__FUl(s32);
s32 fn_8023EB58(s32, s32, s32, s32, s32);
void fn_80044884();
extern s32 lbl_8063F778;

void fn_800447E4() {
    s32 var_r3;

    if ((s32) lbl_8063EAA8 != 0) {
        __dl__FPv(lbl_8063EAA8);
    }
    var_r3 = __nw__FUl(0xEC0);
    if (var_r3 != 0) {
        var_r3 = ((s32)fn_80044898((u32)(var_r3)));
    }
    lbl_8063EAA8 = var_r3;
    fn_8023EB58(lbl_8063F778, (s32) &fn_80044850, (s32) &fn_80044884, 3, 0xC);
}
}

extern "C" {

s32 fn_80044DF4(s32);

void fn_80044990(u32 arg0) {
    u32 temp_r31;
    u32 var_r29;
    u32 var_r30;

    var_r30 = arg0 + 0x780;
    var_r29 = arg0;
    while (var_r30 != (u32) (arg0 + 0xEC0)) {
        ((s32 (*)(s32))fn_80044AAC)((s32) var_r30);
        var_r30 += 0xE8;
    }
    temp_r31 = var_r29 + 0x780;
    while (var_r29 != temp_r31) {
        fn_80044DF4((s32) var_r29);
        var_r29 += 0xF0;
    }
}
}

extern "C" {

void fn_80044884() {
    if ((s32) (*(s32 (*))&lbl_8063EAA8) != 0) {
        ((s32 (*)(s32))fn_80044990)((*(s32 (*))&lbl_8063EAA8));
    }
}
}

extern "C" {

s32 fn_80044D94(s32, f32);

void fn_80044908(u32 arg0, f32 farg0) {
    u32 temp_r31;
    u32 var_r29;
    u32 var_r30;

    var_r30 = arg0 + 0x780;
    var_r29 = arg0;
    while (var_r30 != (u32) (arg0 + 0xEC0)) {
        ((s32 (*)(s32, f32))fn_80044AA8)((s32) var_r30, farg0);
        var_r30 += 0xE8;
    }
    temp_r31 = var_r29 + 0x780;
    while (var_r29 != temp_r31) {
        fn_80044D94((s32) var_r29, farg0);
        var_r29 += 0xF0;
    }
}
}
