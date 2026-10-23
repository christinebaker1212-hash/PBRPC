#include "common.hpp"

extern "C" {

void fn_8020331C(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0x11C))) = 0;
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 __dt__14GSrenderModuleFv(s32, s32);
s32 __dt__7GSsceneFv(s32, s32);
s32 freeNode__12GSlinkedListFP10GSlistNode(s32);
__declspec(section ".data") extern s32 lbl_80423810;
extern s32 sInstance__12GSmenuModule;

u8 *fn_80203080(u8 *arg0, s32 arg1) {
    s32 temp_r0;
    u8 *temp_r31;
    u8 *var_r3;

    if (arg0 != NULL) {
        temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x114)));
        (*(s32 **)((u8 *)(arg0) + (0xC))) = &lbl_80423810;
        if (temp_r0 != 0) {
            __dt__7GSsceneFv(temp_r0, 1);
            (*(s32 *)((u8 *)(arg0) + (0x114))) = 0;
        }
        sInstance__12GSmenuModule = 0;
        if ((arg0 + 0x10) != NULL) {
            var_r3 = (*(u8 **)((u8 *)(arg0) + (0x10)));
            while (var_r3 != NULL) {
                temp_r31 = (*(u8 **)((u8 *)(var_r3) + (8)));
                freeNode__12GSlinkedListFP10GSlistNode((s32) var_r3);
                var_r3 = temp_r31;
            }
        }
        __dt__14GSrenderModuleFv((s32) arg0, 0);
        if (arg1 > 0) {
            __dl__FPv((s32) arg0);
        }
    }
    return arg0;
}
}
