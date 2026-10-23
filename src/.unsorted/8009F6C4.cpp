#include ".unsorted/8009F6C4.hpp"

#include "common.hpp"

extern "C" {

void fn_800A6F38(void) {}
}

extern "C" {

extern u8 *lbl_8063D4F8;
extern f64 lbl_80640ED8;

void fn_8009F6C4(void) {
    (*(f64 *)((u8 *)(lbl_8063D4F8) + (0x100))) = (f64) lbl_80640ED8;
    (*(s32 *)((u8 *)(lbl_8063D4F8) + (0x108))) = (s32) ((*(s32 *)((u8 *)(lbl_8063D4F8) + (0x108))) & 0x1FFFFFFF);
    (*(s32 *)((u8 *)(lbl_8063D4F8) + (0x108))) = (s32) ((*(s32 *)((u8 *)(lbl_8063D4F8) + (0x108))) & 0xE7FFFFFF);
    (*(s32 *)((u8 *)(lbl_8063D4F8) + (0x108))) = (s32) ((*(s32 *)((u8 *)(lbl_8063D4F8) + (0x108))) & 0xF9FFFFFF);
}
}

extern "C" {

u32 fn_800A04B0(void) {
    u32 temp_r0;

    if ((u16) (*(u16 *)((u8 *)(lbl_8063D4F8) + (0xFC))) == 0x41) {
        temp_r0 = (u32) (*(u32 *)((u8 *)(lbl_8063D4F8) + (0x108))) >> 0x1DU;
        if (temp_r0 != 7) {
            return temp_r0;
        }
        return 0x8000U;
    }
    return 0xFFFFU;
}
}

extern "C" {

s32 fn_800A7A80(s32, s32);
s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_800A7A80(s32 arg0, s32 arg1) {
    u32 sp8;
    s32 var_r3;

    var_r3 = fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    if (sp8 == 1U) {
        var_r3 = fn_80253EB4(arg0, arg1, 2, (s32) (*(u16 *)((u8 *)(lbl_8063D4F8) + (0x114))));
    }
    return var_r3;
}
}

extern "C" {

s32 fn_80056528__Fv(void);
s32 fn_800A9F5C(s32, s32);
extern f32 lbl_80640F28;

s32 fn_800A9F5C(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;
    u16 temp_r0;

    temp_r3 = fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    if (sp8 != 1) {
        return temp_r3;
    }
    (*(u8 *)((u8 *)(arg1) + (2))) = 0xEF;
    (*(u8 *)((u8 *)(arg1) + (3))) = 0xEF;
    (*(u8 *)((u8 *)(arg1) + (4))) = 0xEF;
    (*(u8 *)((u8 *)(arg1) + (5))) = 0xFF;
    temp_r0 = (*(u16 *)((u8 *)(lbl_8063D4F8) + (0xFC)));
    if ((temp_r0 >= 0x30U) && (temp_r0 <= 0x38U)) {
        (*(f32 *)((u8 *)((*(u8 **)((u8 *)(arg1) + (0x24)))) + (4))) = (f32) lbl_80640F28;
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F04));
    } else {
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x3077));
    }
    return fn_80056528__Fv();
}
}

extern "C" {

s32 fn_80253E10(s32, s32, f32);
f64 sin(f32);
extern f32 lbl_80640EF8;
extern f32 lbl_80640EFC;
extern f32 lbl_80640F00;
extern f32 lbl_80640F04;
extern f32 lbl_80640F08;
extern u8 *sInstance__8GSrender;

void fn_800A7C8C(s32 arg0) {
    f32 temp_f3;
    f32 var_f31;
    u32 *var_r3;
    u32 temp_r0;

    temp_f3 = (f32) (((*(f64 *)((u8 *)(sInstance__8GSrender) + (0xA0))) / (f64) (*(u8 *)((u8 *)(sInstance__8GSrender) + (0x59)))) - (*(f64 *)((u8 *)(lbl_8063D4F8) + (0x100)))) / lbl_80640EF8;
    if (arg0 == (s16) (*(s16 *)((u8 *)(lbl_8063D4F8) + (0x44)))) {
        var_r3 = (unsigned long *)(lbl_8063D4F8 + 0x108);
        var_f31 = lbl_80640EFC * (f32) (((u32) (*(u32 *)((u8 *)(lbl_8063D4F8) + (0x108))) >> 0x1BU) & 3);
    } else if (arg0 == (s16) (*(s16 *)((u8 *)(lbl_8063D4F8) + (0x46)))) {
        var_r3 = (unsigned long *)(lbl_8063D4F8 + 0x108);
        var_f31 = (lbl_80640EFC * (f32) (((u32) (*(u32 *)((u8 *)(lbl_8063D4F8) + (0x108))) >> 0x1BU) & 3)) - lbl_80640EFC;
    } else {
        var_r3 = (unsigned long *)(lbl_8063D4F8 + 0x108);
        var_f31 = (lbl_80640EFC * (f32) (((u32) (*(u32 *)((u8 *)(lbl_8063D4F8) + (0x108))) >> 0x1BU) & 3)) - lbl_80640F00;
    }
    temp_r0 = ((u32) *var_r3 >> 0x19U) & 3;
    if (temp_r0 == 1) {
        var_f31 -= lbl_80640EFC * (f32) sin(lbl_80640F04 * (lbl_80640F08 * temp_f3));
    } else if (temp_r0 == 2) {
        var_f31 += lbl_80640EFC * (f32) sin(lbl_80640F04 * (lbl_80640F08 * temp_f3));
    }
    fn_80253E10(arg0, 4, var_f31);
}
}

extern "C" {

void fn_800A6AFC(s32 arg0, s32 arg1) {
    s32 sp8;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 4:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x3087));
        return;
    case 6:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x3089));
        return;
    case 8:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x308A));
        return;
    }
}
}

extern "C" {

void fn_800A6BA8(s32 arg0, s32 arg1) {
    s32 sp8;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {
    case 8:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x3069));
        return;
    case 10:
    case 14:
    case 16:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x306F));
        return;
    case 12:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x306A));
        /* fallthrough */
    default:
        return;
    }
}
}

extern "C" {

s32 fn_80059A3C(s32, u32 *);
s32 fn_8015C308(s32, s32);
s32 fn_8015F6E0(void);
s32 fn_80253EDC(s32, s32, s32, u32 *);

void fn_800A7F84(s32 arg0, s32 arg1) {
    u32 sp10[8];
    u32 sp8;
    s32 var_r31;

    var_r31 = 0xA;
    fn_8015F6E0();
    fn_80253EDC(arg0, arg1, 3, &sp8);
    switch (sp8) {
    case 6:
        var_r31 = 0xB;
        /* fallthrough */
    case 5:
        var_r31 += 1;
        /* fallthrough */
    case 4:
        var_r31 += 1;
        /* fallthrough */
    case 3:
        var_r31 += 1;
        /* fallthrough */
    case 2:
        fn_80253EDC(arg0, arg1, 6, sp10);
        fn_80059A3C(var_r31, sp10);
        return;
    case 10:
        fn_8015C308(0xE, (*(s32 (*))&lbl_8063D4F8) + 0xB4);
        return;
    case 14:
        fn_8015C308(0xE, (*(s32 (*))&lbl_8063D4F8) + 0xCC);
        return;
    case 16:
        fn_8015C308(0xE, (*(s32 (*))&lbl_8063D4F8) + 0xE4);
        /* fallthrough */
    default:
        return;
    }
}
}

extern "C" {

u8 *fn_8011C974(void);

void fn_800A9B70(s32 arg0, u8 *arg1) {
    s32 sp10[8];
    s32 sp8;
    u8 temp_r0;
    u8 *temp_r29;

    temp_r29 = fn_8011C974();
    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (u32 *)(&sp8));
    switch (sp8) {                                  /* irregular */
    case 1:
        temp_r0 = (*(u16 *)((u8 *)(temp_r29) + (0x90))) % 10;
        if ((temp_r0 == 6) || ((s32) temp_r0 == 0)) {
            (*(u8 *)((u8 *)(arg1) + (0x10))) = 0x80;
            (*(u8 *)((u8 *)(arg1) + (0xF))) = 0x80;
            (*(u8 *)((u8 *)(arg1) + (0xE))) = 0x80;
        }
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (u32 *)(sp10));
        fn_80059A3C((s32)(0xA), (u32 *)(sp10));
        return;
    case 2:
        if ((u8) ((*(u16 *)((u8 *)(temp_r29) + (0x90))) % 10) <= 1U) {
            (*(u8 *)((u8 *)(arg1) + (0x10))) = 0x80;
            (*(u8 *)((u8 *)(arg1) + (0xF))) = 0x80;
            (*(u8 *)((u8 *)(arg1) + (0xE))) = 0x80;
        }
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (u32 *)(sp10));
        fn_80059A3C((s32)(0xB), (u32 *)(sp10));
        return;
    }
}
}
