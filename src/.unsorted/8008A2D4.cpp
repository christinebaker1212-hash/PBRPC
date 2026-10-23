#include ".unsorted/8008A2D4.hpp"

#include "common.hpp"

extern "C" {

BOOL fn_8008AA14(void) {
    return lbl_8063ED90->_14 == 8;
}
}

extern "C" {

s32 fn_8008A5D4(void);

s32 fn_8008A9D8(void) {
    s32 temp_r3;

    temp_r3 = fn_8008A5D4();
    if ((temp_r3 >= 0xE) && (temp_r3 <= 0x10)) {
        return 1;
    }
    return 0;
}
}

extern "C" {

s32 fn_8008B678(u32 arg0, u32 arg1, f32 *arg2) {
    f32 temp_f1;

    if (arg0 != arg1) {
        temp_f1 = (f32) arg1 / (f32) arg0;
        if (*arg2 > temp_f1) {
            *arg2 = temp_f1;
            return 1;
        }
    }
    return 0;
}
}

extern "C" {

s32 fn_8008B754(s32);
s32 fn_8008B970(s32);
s32 fn_8008BAA8(s32);
s32 fn_8008BBA0(s32);
s32 fn_8008BE4C(s32);
s32 fn_80150FA8(s32, s32);
s32 fn_80253DB0(s32, s32, s32);
__declspec(section ".data") extern s32 lbl_8047AA88;
extern s8 lbl_8063ECFC;
extern s16 lbl_8063EE30;
extern s16 lbl_8063EE32;

void fn_8008B3FC(u32 arg0) {
    s32 sp8;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;

    sp8 = -1;
    switch (arg0) {
    case 0:
    case 1:
    case 14:
    case 15:
    case 24:
        fn_80150FA8(0, 0);
        lbl_8063EE32 = 0x2AEE;
        break;
    case 2:
    case 3:
    case 4:
        temp_r3 = fn_8008BAA8((s32) &sp8);
        if (temp_r3 != 0) {
            fn_80150FA8(temp_r3, 0);
            lbl_8063EE32 = 0x2AE7;
        } else {
            lbl_8063EE32 = 0x525A;
        }
        break;
    case 5:
    case 6:
        temp_r3_2 = fn_8008BE4C((s32) &sp8);
        if (temp_r3_2 != 0) {
            fn_80150FA8(temp_r3_2, 0);
            lbl_8063EE32 = 0x2AED;
        } else {
            lbl_8063EE32 = 0x525D;
        }
        break;
    case 7:
    case 8:
        fn_80150FA8(0x43F, 0);
        lbl_8063EE32 = 0x2AEA;
        lbl_8063EE30 = 0xA;
        break;
    case 9:
        fn_80150FA8(0xF3F, 0);
        lbl_8063EE32 = 0x2AE4;
        lbl_8063EE30 = 0xA;
        break;
    case 10:
    case 11:
        fn_80150FA8(0x13F, 0);
        lbl_8063EE32 = 0x2AE6;
        lbl_8063EE30 = 0xA;
        break;
    case 12:
    case 13:
        fn_80150FA8(0x23F, 0);
        lbl_8063EE32 = 0x2AE8;
        lbl_8063EE30 = 0xA;
        break;
    case 16:
    case 17:
        temp_r3_3 = fn_8008B970((s32) &sp8);
        if (temp_r3_3 != 0) {
            fn_80150FA8(temp_r3_3, 0);
            lbl_8063EE32 = 0x2AEB;
        } else {
            lbl_8063EE32 = 0x525C;
        }
        break;
    case 18:
    case 19:
    case 20:
        temp_r3_4 = fn_8008BBA0((s32) &sp8);
        if (temp_r3_4 != 0) {
            fn_80150FA8(temp_r3_4, 0);
            lbl_8063EE32 = 0x2AE9;
        } else {
            lbl_8063EE32 = 0x525B;
        }
        break;
    case 21:
    case 22:
        fn_80150FA8(0x83F, 0);
        lbl_8063EE32 = 0x2AEC;
        lbl_8063EE30 = 0xA;
        break;
    case 23:
        temp_r3_5 = fn_8008B754((s32) &sp8);
        if (temp_r3_5 != 0) {
            fn_80150FA8(temp_r3_5, 0);
            lbl_8063EE32 = 0x2AE5;
        } else {
            lbl_8063EE32 = 0x5259;
        }
        break;
    }
    if (sp8 > 0) {
        lbl_8063EE30 = (s16) sp8;
    }
    if ((s16) lbl_8063EE30 > 0) {
        fn_80253DB0((s32) (*(s16 *)((u8 *)(&lbl_8047AA88) + (0x26))), 0, 0);
    }
    lbl_8063ECFC = 1;
}
}

extern "C" {

s32 fn_80162A90(u16);
u16 fn_80397F34(u8 *, s32, s32);
__declspec(section ".data") extern s32 lbl_8063CE34;

s32 fn_8008AF50(s32 arg0) {
    u16 temp_r3;

    temp_r3 = fn_80397F34((u8 *)(u8 *)&lbl_8063CE34 + 0x60, fn_8008A5D4(), (arg0 - 2) == 0);
    if (temp_r3 != 0) {
        return fn_80162A90(temp_r3) + 1;
    }
    return 0;
}
}

extern "C" {

s32 fn_8008AEC0(void);
u16 fn_80398068(u8 *, s32, s32 *);

s32 fn_8008B344() {
    u16 temp_r3;

    if (fn_8008AEC0() == 0) {
        return 0;
    }
    temp_r3 = fn_80398068((u8 *)(u8 *)&lbl_8063CE34 + 0x60, fn_8008A5D4(), &lbl_8063CE34);
    if (temp_r3 == 0) {
        return 0;
    }
    return fn_80162A90((u16)(temp_r3)) == 0;
}
}
