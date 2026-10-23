#include ".unsorted/80131CF0.hpp"

#include "common.hpp"

extern "C" {

BOOL fn_80131FC4(void) {
    return lbl_8063D568->_70 == 0;
}
}

extern "C" {

u8 *fn_8011C974(void);
s32 fn_80162940(s32, s32, s32);

void fn_801332E8(s32 arg0) {
    if ((s32) (*(s32 *)((u8 *)(fn_8011C974()) + (0xC))) == 0) {
        fn_80162940(0x199, arg0, 1);
        return;
    }
    fn_80162940(0x199, 0, 1);
}
}

extern "C" {

s32 fn_8015C308(s32, s32);
u32 fn_80162A90(s32);
s32 fn_802502F4(s32);

s32 fn_8013A51C(void) {
    if (fn_80162A90(0x24B) == 1U) {
        fn_80162940(0x24B, 2, 1);
        fn_8015C308(0xE, fn_802502F4(0x29C8));
        return 0x4607;
    }
    if (fn_80162A90(0x24C) == 1U) {
        fn_80162940(0x24C, 2, 1);
        fn_8015C308(0xE, fn_802502F4(0x29C9));
        fn_8015C308(0xF, fn_802502F4(0x29CA));
        return 0x4608;
    }
    if (fn_80162A90(0x24D) == 1U) {
        fn_80162940(0x24D, 2, 1);
        fn_8015C308(0xE, fn_802502F4(0x29CB));
        return 0x4607;
    }
    if (fn_80162A90(0x24E) == 1U) {
        fn_80162940(0x24E, 2, 1);
        fn_8015C308(0xE, fn_802502F4(0x29CC));
        fn_8015C308(0xF, fn_802502F4(0x29CD));
        return 0x4608;
    }
    if (fn_80162A90(0x24F) == 1U) {
        fn_80162940(0x24F, 2, 1);
        fn_8015C308(0xE, fn_802502F4(0x29CE));
        return 0x4607;
    }
    if (fn_80162A90(0x250) == 1U) {
        fn_80162940(0x250, 2, 1);
        fn_8015C308(0xE, fn_802502F4(0x29CF));
        return 0x4607;
    }
    return 0;
}
}

extern "C" {

s32 fn_8005A9F8(s32);
s32 fn_80132B28(s32, s32);
s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_80132B28(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    if (sp8 != 1) {
        return temp_r3;
    }
    return fn_80253EB4(arg0, arg1, 1, fn_8005A9F8(0x1A));
}
}

extern "C" {

s32 fn_800E5F98(s32);

s32 fn_801371A8(u32 arg0) {
    s32 var_r5;

    var_r5 = 0;
    switch (arg0) {
    case 0x1:
        fn_800E5F98(4);
        var_r5 = 1;
        break;
    case 0x2:
        fn_800E5F98(5);
        var_r5 = 1;
        break;
    case 0x3:
        fn_800E5F98(6);
        var_r5 = 1;
        break;
    case 0x4:
        fn_800E5F98(7);
        var_r5 = 1;
        break;
    case 0x5:
        fn_800E5F98(8);
        var_r5 = 1;
        break;
    case 0x6:
        fn_800E5F98(9);
        var_r5 = 1;
        break;
    case 0x7:
        fn_800E5F98(0xA);
        var_r5 = 1;
        break;
    case 0x8:
        fn_800E5F98(0xB);
        var_r5 = 1;
        break;
    case 0x9:
        fn_800E5F98(0xC);
        var_r5 = 1;
        break;
    case 0xA:
        fn_800E5F98(0xD);
        fn_800E5F98(0x16);
        fn_800E5F98(0x17);
        fn_800E5F98(0x18);
        fn_800E5F98(0x19);
        var_r5 = 1;
        break;
    case 0x11:
        fn_800E5F98(3);
        var_r5 = 1;
        break;
    case 0x12:
        fn_800E5F98(0xE);
        var_r5 = 1;
        break;
    case 0x13:
        fn_800E5F98(0xF);
        var_r5 = 1;
        break;
    case 0x14:
        fn_800E5F98(0x10);
        var_r5 = 1;
        break;
    case 0x15:
        fn_800E5F98(0x11);
        var_r5 = 1;
        break;
    case 0x16:
        fn_800E5F98(0x12);
        var_r5 = 1;
        break;
    case 0x17:
        fn_800E5F98(0x13);
        var_r5 = 1;
        break;
    case 0x18:
        fn_800E5F98(0x14);
        var_r5 = 1;
        break;
    case 0x19:
        fn_800E5F98(0x15);
        var_r5 = 1;
        break;
    case 0x1A:
        fn_800E5F98(0x1A);
        var_r5 = 1;
        break;
    case 0x1B:
        fn_800E5F98(0x1B);
        var_r5 = 1;
        break;
    case 0x1C:
        fn_800E5F98(0x1C);
        var_r5 = 1;
        break;
    case 0x1D:
        fn_800E5F98(0x1D);
        var_r5 = 1;
        break;
    case 0x1E:
        fn_800E5F98(0x1E);
        var_r5 = 1;
        break;
    case 0x1F:
        fn_800E5F98(0x1F);
        var_r5 = 1;
        break;
    case 0x20:
        fn_800E5F98(0x20);
        var_r5 = 1;
        break;
    case 0x21:
        fn_800E5F98(0x21);
        var_r5 = 1;
        break;
    case 0x22:
        fn_800E5F98(0x22);
        var_r5 = 1;
        break;
    case 0x23:
        fn_800E5F98(0x23);
        var_r5 = 1;
        break;
    case 0x24:
        fn_800E5F98(0x24);
        var_r5 = 1;
        break;
    case 0x25:
        fn_800E5F98(0x25);
        var_r5 = 1;
        break;
    case 0x32:
        fn_800E5F98(0x26);
        var_r5 = 1;
        break;
    case 0x33:
        fn_800E5F98(0x27);
        var_r5 = 1;
        break;
    case 0x34:
        fn_800E5F98(0x28);
        var_r5 = 1;
        break;
    case 0x35:
        fn_800E5F98(0x29);
        var_r5 = 1;
        break;
    case 0x36:
        fn_800E5F98(0x2A);
        var_r5 = 1;
        break;
    }
    return var_r5;
}
}

extern "C" {

s32 fn_80059A3C(s32, s32);
s32 fn_80253EDC(s32, s32, s32, s32);

void fn_80132B94(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC(arg0, arg1, 3, (s32) &sp8);
    switch (sp8) {
    case 0:
        fn_80253EDC(arg0, arg1, 6, (s32) sp10);
        fn_80059A3C(0x63, (s32) sp10);
    }
    return;
}
}

extern "C" {

void fn_80132CCC(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 0:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(7), (s32)((s32) sp10));
        return;
    case 1:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(8), (s32)((s32) sp10));
        return;
    }
}
}
