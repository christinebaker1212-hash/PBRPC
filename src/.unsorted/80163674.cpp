#include ".unsorted/80163674.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063D5EC;

u32 fn_80163E70(void) {
    return lbl_8063D5EC;
}
}

#include "common.hpp"

extern "C" {

extern u32 lbl_8063D5F0;

void fn_8016450C(void) {
    lbl_8063D5F0 = 0x0;
}
}

extern "C" {

s32 fn_80163AFC(void);
s32 fn_801643C4(u16);
s32 fn_8016482C(s32, s32, s32, s32, s32);

s32 fn_80164794(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    temp_r3 = fn_80163AFC();
    if (temp_r3 < 0) {
        return -2;
    }
    if (fn_801643C4((u16) temp_r3) != 0) {
        return -5;
    }
    return fn_8016482C(arg0, arg1, arg2, arg3, 1);
}
}

extern "C" {

s32 fn_80163C74(s32);
s32 fn_80163DC4(s32 arg0);
s32 fn_8025DFC0(s32, s32);
s32 fn_8025DFD0(void);
extern s32 lbl_8063F080;

s32 fn_80163C74(s32 arg0) {
    if ((s32) lbl_8063F080 == 0) {
        lbl_8063F080 = fn_8025DFC0(fn_8025DFD0(), 0x588);
    }
    return fn_80163DC4((s32)(0));
}
}

extern "C" {

s32 fn_80164824(s32, s32, s32, s32);

s32 fn_80164824(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return fn_8016482C(arg0, arg1, arg2, arg3, 0);
}
}

extern "C" {

s32 fn_80164970(s32, s32, s32, s32);
s32 fn_80164978(s32, s32, s32, s32, s32);

s32 fn_80164970(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return fn_80164978(arg0, arg1, arg2, arg3, 0);
}
}

extern "C" {

s32 fn_80164B14(s32, s32, s32);
s32 fn_8025E2B8(s32);
s32 fn_8025EB78(s32, s32, s32, s32);

s32 fn_80164B14(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3 = fn_8025E2B8(fn_8025DFD0());
    if (temp_r3 == 0) {
        return -1;
    }
    temp_r3_2 = ((s32 (*)(s32))fn_80163AFC)(arg0);
    if (temp_r3_2 < 0) {
        return -2;
    }
    return fn_8025EB78(temp_r3, (s32) (u16) temp_r3_2, arg1, arg2);
}
}

extern "C" {

s32 fn_80164C04() {
    return (((u32)fn_80163AFC()) >> 0x1FU) ^ 1;
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8041F1A8;

void fn_80163674() {
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (2))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (3))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (4))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (5))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (6))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (7))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (8))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0xC))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0xD))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0xE))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0xF))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x10))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x11))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x12))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x16))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x17))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x18))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x19))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x1A))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x1B))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x1C))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x20))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x21))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x22))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x23))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x24))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x25))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x26))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x2A))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x2B))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x2C))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x2D))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x2E))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x2F))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x30))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x34))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x35))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x36))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x37))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x38))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x39))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x3A))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x3E))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x3F))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x40))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x41))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x42))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x43))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x44))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x48))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x49))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x4A))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x4B))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x4C))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x4D))) = 0;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x4E))) = 0;
}
}

extern "C" {

void fn_80163764() {
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (8))) = 1;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x12))) = 1;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x1C))) = 1;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x26))) = 1;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x30))) = 1;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x3A))) = 1;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x44))) = 1;
    (*(s8 *)((u8 *)(&lbl_8041F1A8) + (0x4E))) = 1;
}
}

extern "C" {

s32 fn_8025E31C(s32);
s32 fn_8026745C__Q25gsapi11WiFiNetworkFPl(s32, s32);
__declspec(section ".data") extern s32 lbl_8041F1F8;
extern s32 lbl_8063D5E8;
extern s32 lbl_8063F084;

s32 fn_80163DC4(s32 arg0) {
    s32 sp8;
    s32 temp_r3;

    if ((s32) lbl_8063D5E8 != 0) {
        return lbl_8063F084;
    }
    if (arg0 != 0) {
        return -1;
    }
    temp_r3 = fn_8026745C__Q25gsapi11WiFiNetworkFPl(fn_8025E31C(fn_8025DFD0()), (s32) &sp8);
    if (temp_r3 == 0) {
        return -1;
    }
    if (temp_r3 < 0) {
        sp8 = 0;
    }
    if (((s32)fn_80163E70()) == 0) {
        sp8 = 0;
    }
    lbl_8063D5E8 = 1;
    lbl_8063F084 = sp8;
    fn_80164824((s32)(0), (s32)((s32) &lbl_8041F1F8), (s32)((s32) &lbl_8063F084), (s32)(4));
    return sp8;
}
}

extern "C" {

s32 fn_80164518(void);

void fn_801644EC() {
    s32 temp_r0;

    temp_r0 = (*(s32 (*))&lbl_8063D5F0) - 1;
    (*(s32 (*))&lbl_8063D5F0) = temp_r0;
    if (temp_r0 <= 0) {
        (*(s32 (*))&lbl_8063D5F0) = 4;
        fn_80164518();
    }
}
}
