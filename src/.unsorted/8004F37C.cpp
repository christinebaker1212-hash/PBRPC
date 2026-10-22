#include ".unsorted/8004F37C.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063EB10;

void fn_8004F418(void) {}
u32 fn_8004F41C(void) {
    return lbl_8063EB10;
}
u32 fn_8004F4C4(u8 *p) {
    return *(u32 *)(p + 0x4);
}
}

#include "common.hpp"

extern "C" {

void fn_8004F900(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

void fn_8004F4CC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_8004F900(*(u32 *)(a0 + 0x4), a1, a2, a3, a4, a5, a6, a7);
}
}

extern "C" {

s32 __nw__FUl(s32);
s32 fn_8004F4D4(void);

u8 *fn_8004F424(u8 *arg0) {
    s32 var_r3;

    var_r3 = __nw__FUl(0x174);
    if (var_r3 != 0) {
        var_r3 = fn_8004F4D4();
    }
    (*(s32 *)((u8 *)(arg0) + (4))) = var_r3;
    return arg0;
}
}

extern "C" {

s32 __dl__FPv(u8 *);
s32 fn_8004F5BC(s32, s32);

u8 *fn_8004F468(u8 *arg0, s32 arg1) {
    if (arg0 != NULL) {
        fn_8004F5BC((*(s32 *)((u8 *)(arg0) + (4))), 1);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 markNeedsUpdate__6GSnullFb(u8 *, s32);

void fn_8004FCE0(u8 *arg0, u8 *arg1) {
    u8 *temp_r5;

    temp_r5 = (*(u8 **)((u8 *)(arg0) + (0)));
    if (temp_r5 != NULL) {
        (*(f32 *)((u8 *)(temp_r5) + (0x20))) = (f32) (*(f32 *)((u8 *)(arg1) + (0)));
        (*(f32 *)((u8 *)(temp_r5) + (0x24))) = (f32) (*(f32 *)((u8 *)(arg1) + (4)));
        (*(f32 *)((u8 *)(temp_r5) + (0x28))) = (f32) (*(f32 *)((u8 *)(arg1) + (8)));
        markNeedsUpdate__6GSnullFb(temp_r5, 1);
    }
    (*(f32 *)((u8 *)(arg0) + (0x14))) = (f32) (*(f32 *)((u8 *)(arg1) + (0)));
    (*(f32 *)((u8 *)(arg0) + (0x18))) = (f32) (*(f32 *)((u8 *)(arg1) + (4)));
    (*(f32 *)((u8 *)(arg0) + (0x1C))) = (f32) (*(f32 *)((u8 *)(arg1) + (8)));
}
}

extern "C" {

s32 fn_801E64DC(s32);

void fn_8004FDF8(u8 *arg0, u8 *arg1) {
    s32 temp_r0;

    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0)));
    if (temp_r0 != 0) {
        fn_801E64DC(temp_r0);
    }
    (*(f32 *)((u8 *)(arg0) + (0x20))) = (f32) (*(f32 *)((u8 *)(arg1) + (0)));
    (*(f32 *)((u8 *)(arg0) + (0x24))) = (f32) (*(f32 *)((u8 *)(arg1) + (4)));
    (*(f32 *)((u8 *)(arg0) + (0x28))) = (f32) (*(f32 *)((u8 *)(arg1) + (8)));
}
}

extern "C" {

void fn_8004FEF4(u8 *arg0, u8 *arg1) {
    u8 *temp_r5;

    temp_r5 = (*(u8 **)((u8 *)(arg0) + (0)));
    if (temp_r5 != NULL) {
        (*(u8 *)((u8 *)(temp_r5) + (0x110))) = (u8) (*(u8 *)((u8 *)(arg1) + (0)));
        (*(u8 *)((u8 *)(temp_r5) + (0x111))) = (u8) (*(u8 *)((u8 *)(arg1) + (1)));
        (*(u8 *)((u8 *)(temp_r5) + (0x112))) = (u8) (*(u8 *)((u8 *)(arg1) + (2)));
        (*(u8 *)((u8 *)(temp_r5) + (0x113))) = (u8) (*(u8 *)((u8 *)(arg1) + (3)));
    }
    (*(f32 *)((u8 *)(arg0) + (4))) = (f32) (*(u8 *)((u8 *)(arg1) + (0)));
    (*(f32 *)((u8 *)(arg0) + (8))) = (f32) (*(u8 *)((u8 *)(arg1) + (1)));
    (*(f32 *)((u8 *)(arg0) + (0xC))) = (f32) (*(u8 *)((u8 *)(arg1) + (2)));
    (*(f32 *)((u8 *)(arg0) + (0x10))) = (f32) (*(u8 *)((u8 *)(arg1) + (3)));
}
}

extern "C" {

s32 fn_8004FA38(s32, s32);

s32 fn_8004FA38(s32 arg0, s32 arg1) {
    u8 *temp_r3;
    u8 *temp_r4;

    (*(s8 *)((u8 *)(arg0) + (0x170))) = (s8) arg1;
    if (arg1 != 0) {
        temp_r4 = (*(u8 **)((u8 *)(arg0) + (0)));
        if (temp_r4 != NULL) {
            (*(s32 *)((u8 *)(temp_r4) + (0x104))) = (s32) ((*(s32 *)((u8 *)(temp_r4) + (0x104))) | 1);
            return arg0;
        }
    }
    temp_r3 = (*(u8 **)((u8 *)(arg0) + (0)));
    if (temp_r3 != NULL) {
        (*(s32 *)((u8 *)(temp_r3) + (0x104))) = (s32) ((*(s32 *)((u8 *)(temp_r3) + (0x104))) & 0xFFFFFFFE);
        return (s32) temp_r3;
    }
    return (s32) temp_r3;
}
}
