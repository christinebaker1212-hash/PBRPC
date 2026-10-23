#include ".unsorted/8011E1FC.hpp"

#include "common.hpp"
#include "gs/GSmem.hpp"

extern "C" {

void fn_8012A414(void) {}
void fn_8012B0D0(void) {}
}

extern "C" {

s32 fn_80253E4C(s16, s32, s32 *);
extern u8 *lbl_8063D558;

void fn_80126BF8(s16 arg0) {
    s32 sp8;

    fn_80253E4C(arg0, 8, &sp8);
    if (sp8 != 0) {
        (*(s32 *)((u8 *)(lbl_8063D558) + (0x240))) = 0;
        if ((*(s32 *)((u8 *)(lbl_8063D558) + (0x23C))) & 1) {
            (*(s32 *)((u8 *)(lbl_8063D558) + (0x240))) = (s32) ((*(s32 *)((u8 *)(lbl_8063D558) + (0x240))) + 1);
        }
        if ((*(s32 *)((u8 *)(lbl_8063D558) + (0x23C))) & 2) {
            (*(s32 *)((u8 *)(lbl_8063D558) + (0x240))) = (s32) ((*(s32 *)((u8 *)(lbl_8063D558) + (0x240))) + 1);
        }
        if ((*(s32 *)((u8 *)(lbl_8063D558) + (0x23C))) & 4) {
            (*(s32 *)((u8 *)(lbl_8063D558) + (0x240))) = (s32) ((*(s32 *)((u8 *)(lbl_8063D558) + (0x240))) + 1);
        }
        if ((*(s32 *)((u8 *)(lbl_8063D558) + (0x23C))) & 8) {
            (*(s32 *)((u8 *)(lbl_8063D558) + (0x240))) = (s32) ((*(s32 *)((u8 *)(lbl_8063D558) + (0x240))) + 1);
        }
    }
}
}

extern "C" {

s32 fn_80253E10(s16, s32, f32);
extern f32 lbl_80641380;

void fn_80129CB8(s16 arg0) {
    fn_80253E10(arg0, 4, lbl_80641380);
}
}

extern "C" {

s32 fn_801679F8(u8, s32);

void fn_8012D118(void) {
    s32 var_r31;
    u8 temp_r0;

    var_r31 = 0;
    do {
        temp_r0 = (*(u8 *)((u8 *)((lbl_8063D558 + var_r31)) + (0x250)));
        switch ((s32) temp_r0) {                    /* irregular */
        case 1:
            fn_801679F8((u8) ((*(u8 *)((u8 *)(lbl_8063D558) + (0x258))) - 1), var_r31);
            break;
        case 2:
            fn_801679F8((u8) ((*(u8 *)((u8 *)(lbl_8063D558) + (0x259))) - 1), var_r31);
            break;
        case 3:
            fn_801679F8((u8) ((*(u8 *)((u8 *)(lbl_8063D558) + (0x25A))) - 1), var_r31);
            break;
        case 4:
            fn_801679F8((u8) ((*(u8 *)((u8 *)(lbl_8063D558) + (0x25B))) - 1), var_r31);
            break;
        }
        var_r31 += 1;
    } while (var_r31 < 8);
}
}

extern "C" {

s32 fn_8012D500(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0xE8D;
    case 1:
        return 0xE90;
    default:
        return 0;
    }
}
}

extern "C" {

u32 fn_80162A90(s32);

s32 fn_8012EFC8(void) {
    if ((fn_80162A90(0x261) == 3U) && (((u32) (*(u32 *)((u8 *)(lbl_8063D558) + (0x974))) >> 0xDU) & 1)) {
        return 1;
    }
    return 0;
}
}

extern "C" {

s32 fn_801266B4(s32, s32);
s32 fn_80253E8C(s32, s32, s32, s32);

s32 fn_801266B4(s32 arg0, s32 arg1) {
    s32 sp8;

    return fn_80253E8C((s32) (s16) arg0, arg1, 3, (s32) &sp8);
}
}

extern "C" {

s32 fn_8005A9F8(s32);
s32 fn_80126934(s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_80126934(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    if (sp8 != 1) {
        return temp_r3;
    }
    return fn_80253EB4(arg0, arg1, 1, fn_8005A9F8(0x1A));
}
}

extern "C" {

s32 fn_8012B19C(s32);

s32 fn_8012B19C(s32 arg0) {
    fn_80253E10(arg0, 3, (*(f32 *)((u8 *)(lbl_8063D558) + (0x274))));
    return fn_80253E10(arg0, 4, (*(f32 *)((u8 *)(lbl_8063D558) + (0x27C))));
}
}

extern "C" {

s32 fn_8012B1E8(s32, s32);

s32 fn_8012B1E8(s32 arg0, s32 arg1) {
    s32 sp8;

    return fn_80253E8C((s32)((s32) (s16) arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
}
}

extern "C" {

s32 fn_8012B214(s32, s32);
s32 fn_80253EDC(s32, s32, s32, s32);

s32 fn_8012B214(s32 arg0, s32 arg1) {
    s32 sp8;

    return fn_80253EDC((s32) (s16) arg0, arg1, 3, (s32) &sp8);
}
}

extern "C" {

s32 fn_8012B240(s32);

s32 fn_8012B240(s32 arg0) {
    fn_80253E10(arg0, 3, (*(f32 *)((u8 *)(lbl_8063D558) + (0x278))));
    return fn_80253E10(arg0, 4, (*(f32 *)((u8 *)(lbl_8063D558) + (0x280))));
}
}

extern "C" {

s32 fn_8012B28C(s32, s32);

s32 fn_8012B28C(s32 arg0, s32 arg1) {
    s32 sp8;

    return fn_80253E8C((s32)((s32) (s16) arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
}
}

extern "C" {

s32 fn_8012B2B8(s32, s32);

s32 fn_8012B2B8(s32 arg0, s32 arg1) {
    s32 sp8;

    return fn_80253EDC((s32)((s32) (s16) arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
}
}

extern "C" {

s32 fn_8012B2E4(s32, s32);

s32 fn_8012B2E4(s32 arg0, s32 arg1) {
    s32 sp8;

    return fn_80253E8C((s32)((s32) (s16) arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
}
}

extern "C" {

s32 fn_8012D4CC(s32, s32);
s32 fn_80253DB0(s32, s32, s32);

s32 fn_8012D4CC(s32 arg0, s32 arg1) {
    return fn_80253DB0((s32) (*(s16 *)((u8 *)((lbl_8063D558 + ((arg0 * 2) & 0x1FFFE))) + (0xC0))), arg1, 0);
}
}

extern "C" {

s32 fn_8012D4E4(s32, s32);
s32 fn_80253DF0(s32, s32, s32);

s32 fn_8012D4E4(s32 arg0, s32 arg1) {
    return fn_80253DF0((s32) (*(s16 *)((u8 *)((lbl_8063D558 + ((arg0 * 2) & 0x1FFFE))) + (0xC0))), 8, arg1);
}
}

extern "C" {

// TODO Identify the event codes and scene type values.
void fn_80126A10(s32 arg0, Unk80126A10 *arg1) {
    s32 sp8;
    u16 temp_r0;
    u16 temp_r0_2;

    fn_80253E8C(arg0, (s32) arg1, 3, (s32) &sp8);
    switch (sp8) {
    case 3:
        arg1->_02 = 0xFF;
        arg1->_03 = 0xFF;
        arg1->_04 = 0xFF;
        temp_r0 = ((Unk8011E1FC *) lbl_8063D558)->_12C;
        switch ((s32) temp_r0) {
        case 1:
            fn_80253EB4(arg0, (s32) arg1, 2, 0x2F4E);
            return;
        case 16:
            fn_80253EB4(arg0, (s32) arg1, 2, 0x2F3C);
            return;
        }
        break;
    case 7:
        arg1->_02 = 0xFF;
        arg1->_03 = 0xFF;
        arg1->_04 = 0xFF;
        temp_r0_2 = ((Unk8011E1FC *) lbl_8063D558)->_12C;
        switch ((s32) temp_r0_2) {
        case 1:
            fn_80253EB4(arg0, (s32) arg1, 2, 0x2F53);
            return;
        case 16:
            fn_80253EB4(arg0, (s32) arg1, 2, 0x2F47);
            return;
        }
        break;
    case 4:
        if (((Unk8011E1FC *) lbl_8063D558)->_12C != 0x10) {
            fn_80253EB4(arg0, (s32) arg1, 1, 0);
            return;
        }
        break;
    case 5:
        if (((Unk8011E1FC *) lbl_8063D558)->_12C != 1) {
            fn_80253EB4(arg0, (s32) arg1, 1, 0);
        }
        break;
    }
}

// TODO Identify the three event-specific command values.
void fn_8012A22C(s32 arg0, s32 arg1) {
    s32 sp8;
    fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    switch (sp8) {
    case 5:
        fn_80253EB4(arg0, arg1, 2, 0x46E1);
        return;
    case 7:
        fn_80253EB4(arg0, arg1, 2, 0x46E2);
        return;
    case 9:
        fn_80253EB4(arg0, arg1, 2, 0x46E3);
        return;
    }
}

// TODO Identify the scene-owned allocation released here.
void fn_8012EE00(void) {
    void *temp_r4;
    temp_r4 = ((Unk8011E1FC *) lbl_8063D558)->_1AC4;
    if (temp_r4 != 0) {
        GSmem::freeToHeap(gUnkHeap2, temp_r4);
        ((Unk8011E1FC *) lbl_8063D558)->_1AC4 = 0;
    }
}
}
