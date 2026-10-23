#include "common.hpp"

extern "C" {

void fn_8023EC6C(u8 *arg0, f32 farg0) {
    s32 (**temp_r3)(f32);
    s32 (*temp_r12)(f32);
    u8 *var_r31;

    var_r31 = (*(u8 **)((u8 *)(arg0) + (0x10)));
    while (var_r31 != NULL) {
        temp_r3 = (*(s32 (***)(f32))((u8 *)(var_r31) + (0)));
        if (temp_r3 != NULL) {
            temp_r12 = *temp_r3;
            if (temp_r12 != NULL) {
                temp_r12(farg0);
            }
        }
        var_r31 = (*(u8 **)((u8 *)(var_r31) + (4)));
    }
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 __dt__14GSrenderModuleFv(s32, s32);
s32 freeNode__12GSlinkedListFP10GSlistNode(s32);
__declspec(section ".data") extern s32 lbl_80424808;
extern s32 lbl_8063F778;

u8 *fn_8023EA90(u8 *arg0, s32 arg1) {
    s32 temp_r3;
    u8 *temp_r31;
    u8 *var_r31;
    u8 *var_r3;

    if (arg0 != NULL) {
        var_r31 = (*(u8 **)((u8 *)(arg0) + (0x10)));
        (*(s32 **)((u8 *)(arg0) + (0xC))) = &lbl_80424808;
        while (var_r31 != NULL) {
            temp_r3 = (*(s32 *)((u8 *)(var_r31) + (0)));
            if (temp_r3 != 0) {
                __dl__FPv(temp_r3);
            }
            var_r31 = (*(u8 **)((u8 *)(var_r31) + (4)));
        }
        lbl_8063F778 = 0;
        if ((arg0 + 0x10) != NULL) {
            var_r3 = (*(u8 **)((u8 *)(arg0) + (0x10)));
            while (var_r3 != NULL) {
                temp_r31 = (*(u8 **)((u8 *)(var_r3) + (4)));
                freeNode__12GSlinkedListFP10GSlistNode((s32) var_r3);
                var_r3 = temp_r31;
            }
            (*(u8 **)((u8 *)(arg0) + (0x10))) = NULL;
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

struct S_lbl_8063F770 { s8 f_0; u8 pad_1[1]; s16 f_2; s8 f_4; };
extern struct S_lbl_8063F770 lbl_8063F770;

void fn_8023EE4C() {
    lbl_8063F770.f_0 = 1;
    lbl_8063F770.f_2 = 4;
    lbl_8063F770.f_4 = 0;
}
}
