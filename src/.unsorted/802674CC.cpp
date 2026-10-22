#include ".unsorted/802674CC.hpp"

#include "common.hpp"

extern "C" {

u8 *fn_802674CC(u8 *p) {
    return p + 0xf00;
}
s32 fn_802674D4(u8 *) {
    return 3368;
}
u8 *fn_802674DC(u8 *p) {
    return p + 0xf00;
}
s32 fn_80267504(void) {
    return 30;
}
s32 fn_8026750C(void) {
    return 360;
}
u32 fn_80267688(u8 *p) {
    return *(u32 *)(p + 0x1c2c);
}
}

#include "common.hpp"

extern "C" {

void fn_802676A8(u8 *p) {
    *(u32 *)(p + 0x1c2c) = 0x0;
}
}

extern "C" {

s32 fn_802674E4(s32 arg0, s32 arg1) {
    if (arg1 > 0x1E) {
        return 0;
    }
    return arg0 + (arg1 * 0xC) + 0xF40;
}
}

extern "C" {

s32 fn_80267514(s32 arg0, s32 arg1) {
    return arg0 + (arg1 * 0xB8) + 0x1D08;
}
}

extern "C" {

s32 fn_80267524(s32 arg0, s32 arg1) {
    return arg0 + (arg1 * 8) + 0x3298;
}
}

extern "C" {

void fn_80267690(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0x1C2C))) = 1;
    (*(s32 *)((u8 *)(arg0) + (0x3388))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0x3388))) + 1);
}
}

extern "C" {

s32 fn_80267600(void);
s32 fn_8026765C(s32);
s32 fn_80267710(s32, s32);

void fn_802676B4(s32 arg0, s32 arg1) {
    if ((fn_80267600() == 0) || (fn_8026765C(arg0) != 0)) {
        fn_80267710(arg0, arg1);
    }
}
}

extern "C" {

s32 fn_8031F37C(void);

s32 fn_80267854(void) {
    return fn_8031F37C() == 0;
}
}

extern "C" {

s32 fn_80267BDC(s32, s32);
s32 fn_80267F6C(s32, s32);
s32 fn_8031F3AC(s32);
s32 fn_803331D0(s32);
s32 memmove(s32, s32, s32);
s32 memset(s32, s32, s32);

s32 fn_80267BDC(s32 arg0, s32 arg1) {
    s32 temp_r31;
    s32 temp_r3;

    if (arg1 >= 0x1E) {
        return -1;
    }
    if (fn_803331D0(fn_802674E4((s32)(arg0), (s32)(arg1))) == 0) {
        return -1;
    }
    if (((s32 (*)(s32))fn_80267854)(arg0) != 0) {
        return -1;
    }
    temp_r3 = fn_80267F6C(arg0, arg1);
    if (temp_r3 != 0) {
        memset(temp_r3, 0, 0x40);
    }
    fn_8031F3AC(fn_802674E4((s32)(arg0), (s32)(arg1)));
    if (arg1 < 0x1D) {
        temp_r31 = fn_802674E4((s32)(arg0), (s32)(arg1 + 1));
        memmove(fn_802674E4((s32)(arg0), (s32)(arg1)), temp_r31, (0x1D - arg1) * 0xC);
        memset(fn_802674E4((s32)(arg0), (s32)(0x1D)), 0, 0xC);
    }
    fn_80267690((u8 *)(arg0));
    (*(s32 *)((u8 *)(arg0) + (0x3398))) = 1;
    return 0;
}
}

extern "C" {

s32 fn_802680F4(s32, s32, s32);
s32 memcpy(s32, s32, s32);

s32 fn_802680F4(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;

    temp_r3 = fn_80267F6C((s32)(arg0), (s32)(arg1));
    if (temp_r3 == 0) {
        return -1;
    }
    memcpy(temp_r3 + 0x10, arg2, 0x20);
    fn_80267690((u8 *)(arg0));
    return 0;
}
}

extern "C" {

s32 fn_80268158(s32, s32, s32);

s32 fn_80268158(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;

    temp_r3 = fn_80267F6C((s32)(arg0), (s32)(arg1));
    if (temp_r3 == 0) {
        return -1;
    }
    (*(s32 *)((u8 *)(temp_r3) + (0x38))) = arg2;
    fn_80267690((u8 *)(arg0));
    return 0;
}
}

extern "C" {

s32 fn_802681B0(s32, s32, s32);

s32 fn_802681B0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;

    temp_r3 = fn_80267F6C((s32)(arg0), (s32)(arg1));
    if (temp_r3 == 0) {
        return -1;
    }
    (*(s32 *)((u8 *)(temp_r3) + (0x3C))) = arg2;
    fn_80267690((u8 *)(arg0));
    return 0;
}
}
