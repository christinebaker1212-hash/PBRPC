#include "common.hpp"

extern "C" {

s32 fn_8023C908(s32);
s32 fn_8023CAD8(s32, s32, s32, s32, s32);
s32 fn_8023CC30(s32, s32, s32, s32, s32, s32);

void fn_801FB83C(s32 arg0) {
    fn_8023C908(arg0 + 0x18);
    fn_8023CAD8(arg0 + 0x18, 9, 0, 2, 0);
    fn_8023CAD8(arg0 + 0x18, 0xB, 1, 5, 0);
    fn_8023CAD8(arg0 + 0x18, 0xD, 1, 0, 0);
    fn_8023CC30(arg0 + 0x18, 9, 2, arg0 + 0x3F4, 4, 0x10);
    fn_8023CC30(arg0 + 0x18, 0xD, 2, arg0 + 0x404, 2, 8);
}
}

extern "C" {

s32 fn_8023352C(u8 *, s32);
s32 fn_80233580(u8 *);
extern f32 lbl_80641E5C;
extern f32 lbl_80641E60;
extern f32 lbl_80641E64;
extern f32 lbl_80641E68;
extern u8 *sInstance__8GSrender;

void fn_801FB8EC(void) {
    (*(s32 *)((u8 *)(sInstance__8GSrender) + (0x1738))) = 0x98;
    fn_8023352C(sInstance__8GSrender, 4);
    *(f32 *)0xCC008000 = lbl_80641E60;
    *(f32 *)0xCC008000 = lbl_80641E64;
    *(f32 *)0xCC008000 = lbl_80641E60;
    *(f32 *)0xCC008000 = lbl_80641E5C;
    *(f32 *)0xCC008000 = lbl_80641E60;
    *(f32 *)0xCC008000 = lbl_80641E60;
    *(f32 *)0xCC008000 = lbl_80641E60;
    *(f32 *)0xCC008000 = lbl_80641E60;
    *(f32 *)0xCC008000 = lbl_80641E68;
    *(f32 *)0xCC008000 = lbl_80641E64;
    *(f32 *)0xCC008000 = lbl_80641E5C;
    *(f32 *)0xCC008000 = lbl_80641E5C;
    *(f32 *)0xCC008000 = lbl_80641E68;
    *(f32 *)0xCC008000 = lbl_80641E60;
    *(f32 *)0xCC008000 = lbl_80641E5C;
    *(f32 *)0xCC008000 = lbl_80641E60;
    fn_80233580(sInstance__8GSrender);
}
}

extern "C" {

u8 *findTarget__14GSrenderTargetFl(s32);
s32 fn_801FB9AC(void);
s32 fn_801FC920(u8 *);
s32 fn_801FCEE4(u8 *);
s32 fn_8023F5E8(u8 *, s32, s32, s32, s32);

void fn_801FE14C(u8 *arg0) {
    s32 var_r31;
    u8 temp_r30;
    u8 *temp_r3;

    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x418))) != 0) {
        if (((s32) (*(u8 *)((u8 *)(arg0) + (0x40E))) != 0) && ((s32) (*(u8 *)((u8 *)(arg0) + (0x454))) != 0)) {
            fn_801FB9AC();
        }
        (*(u8 *)((u8 *)(arg0) + (0x454))) = 0U;
        var_r31 = 0;
        temp_r30 = (*(u8 *)((u8 *)(arg0) + (0x40D)));
        if (((s32) (*(s32 *)((u8 *)(arg0) + (0x414))) != 0) && ((s32) (*(u8 *)((u8 *)(arg0) + (0x40F))) != 0)) {
            temp_r3 = findTarget__14GSrenderTargetFl(2);
            if (temp_r3 != NULL) {
                var_r31 = (*(s32 *)((u8 *)(temp_r3) + (0x20))) == 0;
            }
        }
        if (((s32) temp_r30 != 0) || (var_r31 != 0)) {
            if (var_r31 != 0) {
                fn_8023F5E8(sInstance__8GSrender, (*(s32 *)((u8 *)(arg0) + (0x414))), 0xA6, 0, 0);
            }
            fn_8023F5E8(sInstance__8GSrender, (*(s32 *)((u8 *)(arg0) + (0x418))), 0x45, 0, 0);
            (*(u8 *)((u8 *)(arg0) + (0x454))) = 1U;
            (*(u16 *)((u8 *)(sInstance__8GSrender) + (0x16FE))) = (u16) ((*(u16 *)((u8 *)(sInstance__8GSrender) + (0x16FE))) | 6);
            if ((s32) temp_r30 != 0) {
                fn_801FC920(arg0);
            }
            if (var_r31 != 0) {
                fn_801FCEE4(arg0);
            }
        } else if ((s32) (*(u8 *)((u8 *)(arg0) + (0x40E))) != 0) {
            fn_8023F5E8(sInstance__8GSrender, (*(s32 *)((u8 *)(arg0) + (0x418))), 0x45, 0, 0);
            (*(u8 *)((u8 *)(arg0) + (0x454))) = 1U;
            (*(u16 *)((u8 *)(sInstance__8GSrender) + (0x16FE))) = (u16) ((*(u16 *)((u8 *)(sInstance__8GSrender) + (0x16FE))) | 6);
        }
    } else {
        (*(u8 *)((u8 *)(arg0) + (0x454))) = 0U;
    }
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 __dt__14GSrenderModuleFv(s32, s32);
s32 fn_8023645C__FPv(s32);
s32 fn_8023CA6C(s32);
s32 free__5GSmemFPv(s32);
__declspec(section ".data") extern s32 lbl_80423768;
extern s32 lbl_8063F410;

u8 *fn_801FB734(u8 *arg0, s32 arg1) {
    s32 temp_r0;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    u8 *temp_r3_5;

    if (arg0 != NULL) {
        temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x420)));
        (*(s32 **)((u8 *)(arg0) + (0xC))) = &lbl_80423768;
        if (temp_r0 != 0) {
            fn_8023645C__FPv(temp_r0);
        }
        temp_r3 = (*(s32 *)((u8 *)(arg0) + (0x41C)));
        if (temp_r3 != 0) {
            fn_8023645C__FPv(temp_r3);
        }
        temp_r3_2 = (*(s32 *)((u8 *)(arg0) + (0x414)));
        if (temp_r3_2 != 0) {
            fn_8023645C__FPv(temp_r3_2);
        }
        temp_r3_3 = (*(s32 *)((u8 *)(arg0) + (0x418)));
        if (temp_r3_3 != 0) {
            fn_8023645C__FPv(temp_r3_3);
        }
        temp_r3_4 = (*(s32 *)((u8 *)(arg0) + (0x3EC)));
        if (temp_r3_4 != 0) {
            free__5GSmemFPv(temp_r3_4);
        }
        fn_8023CA6C((s32) (arg0 + 0x18));
        temp_r3_5 = arg0 + 0x18;
        lbl_8063F410 = 0;
        if (temp_r3_5 != NULL) {
            fn_8023CA6C((s32) temp_r3_5);
        }
        __dt__14GSrenderModuleFv((s32) arg0, 0);
        if (arg1 > 0) {
            __dl__FPv((s32) arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8023B420__14GSrenderTargetFUl(s32, s32);

void fn_801FEF68(u8 *arg0) {
    s32 temp_r3;
    s32 temp_r3_2;
    u32 var_r31;

    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x468))) != 0) {
        if ((s32) (*(u8 *)((u8 *)(arg0) + (0x467))) != 0) {
            var_r31 = (*(u32 *)((u8 *)(arg0) + (0x10)));
        } else {
            var_r31 = (*(u32 *)((u8 *)(arg0) + (0x14)));
        }
        temp_r3 = ((s32)findTarget__14GSrenderTargetFl((s32)((s32) (u8) (var_r31 >> 0x10U))));
        if (temp_r3 != 0) {
            fn_8023B420__14GSrenderTargetFUl(temp_r3, (s32) var_r31);
        }
        temp_r3_2 = (*(s32 *)((u8 *)(arg0) + (0x498)));
        (*(u8 *)((u8 *)(arg0) + (0x468))) = 0U;
        (*(s8 *)((u8 *)(arg0) + (0x484))) = 0;
        (*(s8 *)((u8 *)(arg0) + (0x485))) = 0;
        (*(s16 *)((u8 *)(arg0) + (0x464))) = 0;
        if (temp_r3_2 != 0) {
            fn_8023645C__FPv((s32)(temp_r3_2));
            (*(s32 *)((u8 *)(arg0) + (0x498))) = 0;
        }
    }
}
}
