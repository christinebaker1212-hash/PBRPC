#include ".unsorted/80044F28.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063EAB8;

u8 fn_80044FB0(u8 *p) {
    return *(u8 *)(p + 0x3f);
}
u32 fn_80045590(void) {
    return lbl_8063EAB8;
}
}

#include "common.hpp"

extern "C" {

void fn_800470B4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

void fn_8004746C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_800470B4(a0, 0x0, a2, a3, a4, a5, a6, a7);
}
}

extern "C" {

s32 fn_80044F74(void);

u8 *fn_80044F28(u8 *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0x40))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x41))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x42))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x10))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x11))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x12))) = 0;
    fn_80044F74();
    return arg0;
}
}

extern "C" {

s32 fn_80044FB8(u8 *arg0) {
    s32 var_r4;

    var_r4 = 0;
    if ((s32) (*(s32 *)((u8 *)(arg0) + (8))) != 0) {
        var_r4 = 1;
    }
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xC))) != 0) {
        var_r4 += 1;
    }
    return var_r4;
}
}

extern "C" {

void fn_80044FE4(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    (*(s8 *)((u8 *)(arg0) + (0x3F))) = 1;
    (*(s32 *)((u8 *)(arg0) + (0))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (4))) = arg2;
    (*(s32 *)((u8 *)(arg0) + (8))) = arg3;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = arg4;
    (*(s8 *)((u8 *)(arg0) + (0x40))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x41))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x42))) = 0;
}
}

extern "C" {

s32 fn_8003CF0C(s32);
s32 fn_8004506C(u8 *);

void fn_80045010(u8 *arg0) {
    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x3F))) != 0) {
        if ((s32) (*(u8 *)((u8 *)(arg0) + (0x40))) != 0) {
            fn_8003CF0C((*(s32 *)((u8 *)(arg0) + (4))));
            (*(s32 *)((u8 *)(arg0) + (4))) = 0;
            (*(u8 *)((u8 *)(arg0) + (0x40))) = 0U;
        }
        fn_8004506C(arg0);
    }
}
}

extern "C" {

void fn_8004539C(u8 *arg0, u8 *arg1) {
    if (arg1 != NULL) {
        (*(f32 *)((u8 *)(arg0) + (0x14))) = (f32) (*(f32 *)((u8 *)(arg1) + (0)));
        (*(f32 *)((u8 *)(arg0) + (0x18))) = (f32) (*(f32 *)((u8 *)(arg1) + (4)));
        (*(f32 *)((u8 *)(arg0) + (0x1C))) = (f32) (*(f32 *)((u8 *)(arg1) + (8)));
    }
}
}

extern "C" {

void fn_800453C0(u8 *arg0, u8 *arg1, u8 *arg2) {
    if (arg1 != NULL) {
        (*(f32 *)((u8 *)(arg0) + (0x20))) = (f32) (*(f32 *)((u8 *)(arg1) + (0)));
        (*(f32 *)((u8 *)(arg0) + (0x24))) = (f32) (*(f32 *)((u8 *)(arg1) + (4)));
        (*(f32 *)((u8 *)(arg0) + (0x28))) = (f32) (*(f32 *)((u8 *)(arg1) + (8)));
    }
    if (arg2 != NULL) {
        (*(f32 *)((u8 *)(arg0) + (0x2C))) = (f32) (*(f32 *)((u8 *)(arg2) + (0)));
        (*(f32 *)((u8 *)(arg0) + (0x30))) = (f32) (*(f32 *)((u8 *)(arg2) + (4)));
        (*(f32 *)((u8 *)(arg0) + (0x34))) = (f32) (*(f32 *)((u8 *)(arg2) + (8)));
    }
}
}

extern "C" {

void fn_80045404(u8 *arg0, u8 *arg1) {
    if (arg1 != NULL) {
        (*(f32 *)((u8 *)(arg1) + (0))) = (f32) (*(f32 *)((u8 *)(arg0) + (0x14)));
        (*(f32 *)((u8 *)(arg1) + (4))) = (f32) (*(f32 *)((u8 *)(arg0) + (0x18)));
        (*(f32 *)((u8 *)(arg1) + (8))) = (f32) (*(f32 *)((u8 *)(arg0) + (0x1C)));
    }
}
}

extern "C" {

void fn_80045428(u8 *arg0, u8 *arg1, u8 *arg2) {
    if (arg1 != NULL) {
        (*(f32 *)((u8 *)(arg1) + (0))) = (f32) (*(f32 *)((u8 *)(arg0) + (0x20)));
        (*(f32 *)((u8 *)(arg1) + (4))) = (f32) (*(f32 *)((u8 *)(arg0) + (0x24)));
        (*(f32 *)((u8 *)(arg1) + (8))) = (f32) (*(f32 *)((u8 *)(arg0) + (0x28)));
    }
    if (arg2 != NULL) {
        (*(f32 *)((u8 *)(arg2) + (0))) = (f32) (*(f32 *)((u8 *)(arg0) + (0x2C)));
        (*(f32 *)((u8 *)(arg2) + (4))) = (f32) (*(f32 *)((u8 *)(arg0) + (0x30)));
        (*(f32 *)((u8 *)(arg2) + (8))) = (f32) (*(f32 *)((u8 *)(arg0) + (0x34)));
    }
}
}

extern "C" {

u8 fn_80045838(s32 arg0, s32 arg1) {
    if ((arg1 < 0) || (arg1 > 3)) {
        return 0U;
    }
    return (*(u8 *)((u8 *)((arg0 + ((arg1 & 3) * 0x44))) + (0x1C)));
}
}

extern "C" {

s32 fn_80045598(s32);
s32 fn_800455F8(s32);

s32 fn_80045598(s32 arg0) {
    s32 var_r30;

    var_r30 = arg0 + 0xC;
    do {
        fn_80044F28((u8 *)(var_r30));
        var_r30 += 0x44;
    } while ((u32) var_r30 < (u32) (arg0 + 0x11C));
    fn_800455F8(arg0);
    return arg0;
}
}

extern "C" {

s32 fn_80047474(s32, s32, s32, s32);
s32 fn_801E4B8C(s32, s32);
s32 fn_801E4BCC(s32, s32);
s32 getCachedFile__7GScacheFUlUl(s32, s32);

s32 fn_80047474(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    temp_r3 = getCachedFile__7GScacheFUlUl(arg1, (arg2 & 0x7FFF0000) | 0x2C00);
    if (temp_r3 != 0) {
        fn_801E4B8C(temp_r3, arg3);
        fn_801E4BCC(temp_r3, 1);
        (*(s32 *)((u8 *)(arg0) + (0x168))) = temp_r3;
        return 1;
    }
    return 0;
}
}
