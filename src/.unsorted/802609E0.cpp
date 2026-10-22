#include ".unsorted/802609E0.hpp"

#include "common.hpp"

extern "C" {

void fn_802609F0(u8 *p, u8 v) {
    *(u8 *)(p + 0x6) = v;
}
u8 fn_802609F8(u8 *p) {
    return *(u8 *)(p + 0x6);
}
}

#include "common.hpp"

extern "C" {

u32 fn_80260A10(u8 *p) {
    return *(u8 *)(p + 0x7) & 0x1;
}
}

extern "C" {

s32 fn_802609E0(u8 *arg0) {
    return *arg0 == 0;
}
}

extern "C" {

void fn_80260A00(u8 *arg0) {
    (*(u8 *)((u8 *)(arg0) + (7))) = (u8) ((*(u8 *)((u8 *)(arg0) + (7))) | 1);
}
}

extern "C" {

void fn_80260A1C(u8 *arg0) {
    (*(u8 *)((u8 *)(arg0) + (7))) = (u8) ((*(u8 *)((u8 *)(arg0) + (7))) | 2);
}
}

extern "C" {

s32 fn_80260A2C(u8 *arg0) {
    return (*(u8 *)((u8 *)(arg0) + (7))) & 2;
}
}

extern "C" {

s32 fn_80260A38(u8 *arg0) {
    return (*arg0 - 2) == 0;
}
}

extern "C" {

s32 fn_80260A4C(u8 *arg0) {
    return (*arg0 - 1) == 0;
}
}

extern "C" {

s32 fn_80260A60(u8 *arg0, u32 arg1, u32 arg2) {
    if ((arg1 == (u8) (*(u8 *)((u8 *)(arg0) + (0)))) && (arg2 == (u16) (*(u16 *)((u8 *)(arg0) + (2))))) {
        return 1;
    }
    return 0;
}
}

extern "C" {

s32 fn_80260A88(u8 *arg0, u32 arg1) {
    if ((arg1 > (u32) (*(u32 *)((u8 *)(arg0) + (0x14)))) || (arg1 > (u32) (*(u32 *)((u8 *)(arg0) + (0xC)))) || (arg1 > (u32) (*(u32 *)((u8 *)(arg0) + (0x10))))) {
        return -1;
    }
    (*(u32 *)((u8 *)(arg0) + (0x10))) = arg1;
    if ((s32) (*(u8 *)((u8 *)(arg0) + (1))) == 0) {
        (*(u8 *)((u8 *)(arg0) + (1))) = 1U;
    }
    return 0;
}
}

extern "C" {

void fn_80260AD4(u8 *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0))) = 0;
    (*(s8 *)((u8 *)(arg0) + (1))) = 0;
    (*(s16 *)((u8 *)(arg0) + (2))) = 0;
    (*(s16 *)((u8 *)(arg0) + (4))) = 0;
    (*(s8 *)((u8 *)(arg0) + (6))) = 0;
    (*(s8 *)((u8 *)(arg0) + (7))) = 0;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x14))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x18))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x34))) = 0;
}
}

extern "C" {

s32 fn_8025E370(void);

s32 fn_802612B8(u8 *arg0, u8 *arg1) {
    s32 temp_r3;
    u32 temp_r3_2;

    if (((u8) (*(u8 *)((u8 *)(arg0) + (0))) != 2) || ((s32) (*(u8 *)((u8 *)(arg0) + (1))) == 0)) {
        return -1;
    }
    if ((u16) (*(u16 *)((u8 *)(arg1) + (4))) != (u16) (*(u16 *)((u8 *)(arg0) + (2)))) {
        return -1;
    }
    temp_r3 = fn_8025E370();
    (*(s32 *)((u8 *)(arg0) + (0x18))) = temp_r3;
    if (temp_r3 == 0) {
        (*(s32 *)((u8 *)(arg0) + (0x18))) = -1;
    }
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = (s32) (*(s32 *)((u8 *)(arg0) + (0x18)));
    temp_r3_2 = (*(u32 *)((u8 *)(arg0) + (0x10))) + (*(u16 *)((u8 *)(arg1) + (6)));
    (*(u32 *)((u8 *)(arg0) + (0x10))) = temp_r3_2;
    if (temp_r3_2 >= (u32) (*(u32 *)((u8 *)(arg0) + (0x14)))) {
        (*(u8 *)((u8 *)(arg0) + (1))) = 0U;
    }
    return 0;
}
}
