#include ".unsorted/8005CEAC.hpp"

#include "common.hpp"

extern "C" {

void fn_80062FF8(void) {}
void fn_80063510(void) {}
void fn_80064558(void) {}
void fn_80069668(void) {}
void fn_8006A74C(void) {}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_8005CEAC(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_8006A750(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0x3126;
    case 1:
        return 0x3127;
    default:
        return 0;
    }
}
}

extern "C" {

s32 fn_80058480__Fv(void);
s32 fn_80058490__Fv(void);
s32 fn_80068F34(s32, s32);
s32 fn_8006F0EC(void);
s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_80068F34(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    if ((fn_80058480__Fv() == 0) || (fn_80058490__Fv() == 0)) {
        return fn_80253EB4(arg0, arg1, 1, 0);
    }
    temp_r3 = fn_8006F0EC();
    if (temp_r3 != 0) {
        return fn_80253EB4(arg0, arg1, 1, 0);
    }
    if (sp8 != 1) {
        return temp_r3;
    }
    return fn_80253EB4(arg0, arg1, 2, 0x51CF);
}
}

extern "C" {

s32 fn_80069600(s32, s32);
s32 fn_8006A7B0(s32);

s32 fn_80069600(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 var_r3;

    var_r3 = fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    if (sp8 == 0) {
        var_r3 = fn_80253EB4(arg0, arg1, 1, fn_8006A7B0(7));
    }
    return var_r3;
}
}

extern "C" {

s32 fn_80064158(s32);
s32 fn_80253DB0(s16, s32, s32);
u16 fn_80253DD0(s16);
s32 fn_80253DF0(s16, s32, s32);
__declspec(section ".data") extern s32 lbl_8040B768;
__declspec(section ".data") extern s32 lbl_80478408;

void fn_80062F08() {
    switch ((s32) (*(u16 *)((u8 *)(&lbl_80478408) + (0xA0)))) { /* irregular */
    case 37:
        fn_80253DF0((*(s16 *)((u8 *)(&lbl_8040B768) + (0xC))), 8, 1);
        fn_80253DB0((*(s16 *)((u8 *)(&lbl_8040B768) + (0xC))), 2, 0);
        (*(u16 *)((u8 *)(&lbl_80478408) + (0xA0))) = 0x26U;
        return;
    case 38:
        if (fn_80253DD0((*(s16 *)((u8 *)(&lbl_8040B768) + (0xC)))) == 3) {
            fn_80253DB0((*(s16 *)((u8 *)(&lbl_8040B768) + (0xC))), 0, 0);
        }
        fn_80064158(1);
        return;
    case 39:
        fn_80253DF0((*(s16 *)((u8 *)(&lbl_8040B768) + (6))), 8, 0);
        fn_80253DF0((*(s16 *)((u8 *)(&lbl_8040B768) + (0xC))), 8, 0);
        return;
    }
}
}

extern "C" {

s32 fn_800F95DC(void);
s32 fn_80253E10(s32, s32, f32);
s32 fn_80253E4C(s16, s32, s32 *);
extern f32 lbl_80640C18;
extern f32 lbl_80640C54;
extern f32 lbl_80640C58;
extern f32 lbl_80640C5C;
extern f32 lbl_80640C60;

void fn_80069510(s32 arg0) {
    s32 sp8;
    s32 var_r31;

    var_r31 = 1;
    fn_80253E4C((*(s16 *)((u8 *)(&lbl_8040B768) + (0x14))), 8, &sp8);
    if (sp8 != 0) {
        var_r31 = 0;
    }
    if (fn_800F95DC() != 0) {
        var_r31 = 0;
    }
    if (var_r31 == 0) {
        fn_80253E10(arg0, 3, lbl_80640C54);
        fn_80253E10(arg0, 4, lbl_80640C58);
    } else {
        fn_80253E10(arg0, 3, lbl_80640C18);
        fn_80253E10(arg0, 4, lbl_80640C18);
    }
    if ((u32) (((u16) (*(u16 *)((u8 *)(&lbl_80478408) + (0xB2))) >> 9U) & 0xF) == 0xF) {
        fn_80253E10(arg0, 3, lbl_80640C5C);
        fn_80253E10(arg0, 4, lbl_80640C60);
    }
}
}

extern "C" {

s32 fn_8005D7D0(s32, s32, s32, s32);

void fn_8005D78C(s32 arg0, u32 arg1, s16 arg2, s16 arg3) {
    if (arg1 == 9U) {
        (*(s16 *)((u8 *)(&lbl_80478408) + (0x84))) = arg2;
        (*(s16 *)((u8 *)(&lbl_80478408) + (0x86))) = arg3;
        (*(s32 *)((u8 *)(&lbl_80478408) + (0xB8))) = 0;
    }
    fn_8005D7D0(arg0, (s32) arg1, (s32) arg2, 1);
}
}

extern "C" {

s32 fn_800599C8(s32, s32, s32, s32, s32, s32);

u32 fn_80061B9C(u32 arg0) {
    u32 var_r3;

    var_r3 = arg0;
    switch (var_r3) {
    case 1:
        fn_800599C8(1, 0, 0, 5, 0, 0);
        fn_800599C8(5, 0, 1, 0, 0, 0);
        return 1U;
    case 3:
        fn_800599C8(1, 0, 0, 2, 0, 0);
        fn_800599C8(2, 0, 1, 5, 0, 0);
        fn_800599C8(5, 0, 2, 0, 0, 0);
        return 1U;
    case 7:
        fn_800599C8(1, 0, 0, 2, 3, 0);
        fn_800599C8(2, 0, 1, 5, 0, 0);
        fn_800599C8(3, 1, 0, 5, 0, 0);
        fn_800599C8(5, 0, 2, 0, 0, 0);
        return 1U;
    case 15:
        fn_800599C8(1, 0, 0, 2, 3, 0);
        fn_800599C8(2, 0, 1, 5, 4, 0);
        fn_800599C8(3, 1, 0, 4, 0, 0);
        fn_800599C8(4, 2, 3, 5, 0, 0);
        fn_800599C8(5, 0, 4, 0, 0, 0);
        var_r3 = 1;
        /* fallthrough */
    default:
        return var_r3;
    }
}
}

extern "C" {

s32 fn_800569EC__FP7Pokemon(s32);
s32 fn_8015C308(s32, s32);
s32 fn_80253EDC(s32, s32, s32, s32);

void fn_80064900(s32 arg0, s32 arg1) {
    s32 var_r31;
    s32 var_r30;
    s32 sp8;

    if ((s32) (*(u16 *)((u8 *)(&lbl_80478408) + (0x6E))) == 0) {
        var_r31 = (*(s32 *)((u8 *)(&lbl_80478408) + (4)));
        var_r30 = (*(s32 *)((u8 *)(&lbl_80478408) + (8)));
    } else {
        var_r31 = (*(s32 *)((u8 *)(&lbl_80478408) + (0x1C)));
        var_r30 = (*(s32 *)((u8 *)(&lbl_80478408) + (0x20)));
    }
    fn_80253EDC(arg0, arg1, 3, (s32) &sp8);
    switch (sp8) {
    case 1:
        switch ((s32) (*(u16 *)((u8 *)(&lbl_80478408) + (0x6A)))) { /* irregular */
        case 0:
            fn_8015C308(0x15, fn_800569EC__FP7Pokemon(var_r31));
            return;
        case 2:
            fn_8015C308(0x15, fn_800569EC__FP7Pokemon(var_r30));
            /* fallthrough */
        case 1:
            return;
        }
    }
    return;
}
}

extern "C" {

s32 fn_800584A0__Fv(void);
s32 fn_800584B0__Fv(void);

void fn_80069230(s32 arg0, s32 arg1) {
    s32 sp8;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    if ((fn_800584A0__Fv() == 0) || (fn_800584B0__Fv() == 0)) {
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(1), (s32)(0));
        return;
    }
    switch (sp8) {
    case 1:
        if (((u16) (*(u16 *)((u8 *)(&lbl_80478408) + (0xB2))) >> 0xDU) & 1) {
            fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(1), (s32)(0));
        }
    }
    return;
}
}
