#include ".unsorted/80204058.hpp"

#include "gs/GShierarchyModule.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063F494;

void fn_802054E0(u32 v) {
    lbl_8063F494 = v;
}

GSrenderLight **fn_802054E8(u8 *count) {
    *count = GShierarchyModule::lbl_8063F46D;
    return GShierarchyModule::lbl_804920B0;
}

void fn_80205914(u8 *p, u32 v) {
    p[0] = v >> 24;
    p[1] = v >> 16;
    p[2] = v >> 8;
    p[3] = v;
}
}

extern "C" {

void fn_8020561C(u8 *arg0, s8 arg1) {
    u8 *temp_r3;
    u8 *temp_r4;

    (*(s8 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x1638)))) + (0x68))) = arg1;
    temp_r4 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
    (*(s32 *)((u8 *)(temp_r4) + (4))) = (s32) ((*(s32 *)((u8 *)(temp_r4) + (4))) | 1);
    temp_r3 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
    (*(s32 *)((u8 *)(temp_r3) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3) + (0))) | 1);
}
}

extern "C" {

void fn_80205648(u8 *arg0, s8 arg1) {
    u8 *temp_r3;
    u8 *temp_r4;

    (*(s8 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x1638)))) + (0x890))) = arg1;
    temp_r4 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
    (*(s32 *)((u8 *)(temp_r4) + (0x44))) = (s32) ((*(s32 *)((u8 *)(temp_r4) + (0x44))) | 1);
    temp_r3 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
    (*(s32 *)((u8 *)(temp_r3) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3) + (0))) | 0x80);
}
}

extern "C" {

void fn_80205674(u8 *arg0, s8 arg1) {
    u8 *temp_r3;
    u8 *temp_r4;

    (*(s8 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x1638)))) + (0x18C))) = arg1;
    temp_r4 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
    (*(s32 *)((u8 *)(temp_r4) + (0x14))) = (s32) ((*(s32 *)((u8 *)(temp_r4) + (0x14))) | 1);
    temp_r3 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
    (*(s32 *)((u8 *)(temp_r3) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3) + (0))) | 4);
}
}

extern "C" {

void fn_80205700(u8 *arg0, s8 arg1) {
    u8 *temp_r3;
    u8 *temp_r4;

    (*(s8 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x1638)))) + (0x280))) = arg1;
    temp_r4 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
    (*(s32 *)((u8 *)(temp_r4) + (0x24))) = (s32) ((*(s32 *)((u8 *)(temp_r4) + (0x24))) | 1);
    temp_r3 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
    (*(s32 *)((u8 *)(temp_r3) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3) + (0))) | 8);
}
}

extern "C" {

void fn_8020572C(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_r6;
    s32 temp_r6_2;
    s32 temp_r6_3;
    s32 temp_r6_4;
    s32 temp_r8;
    s32 temp_r8_2;
    s32 temp_r8_3;
    s32 temp_r8_4;
    u8 *temp_r3;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    u8 *temp_r4;
    u8 *temp_r4_10;
    u8 *temp_r4_11;
    u8 *temp_r4_12;
    u8 *temp_r4_2;
    u8 *temp_r4_3;
    u8 *temp_r4_4;
    u8 *temp_r4_5;
    u8 *temp_r4_6;
    u8 *temp_r4_7;
    u8 *temp_r4_8;
    u8 *temp_r4_9;

    switch (arg2) {                                 /* irregular */
    case 0:
        temp_r8 = (arg1 * 4) & 0x3FC;
        (*(s32 *)((u8 *)(((*(u8 **)((u8 *)(arg0) + (0x1638))) + temp_r8)) + (0x8E4))) = 0xC;
        temp_r6 = 1 << arg1;
        temp_r4 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r4) + (0x54))) = (s32) ((*(s32 *)((u8 *)(temp_r4) + (0x54))) | temp_r6);
        temp_r4_2 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r4_2) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r4_2) + (0))) | 0x10);
        (*(s32 *)((u8 *)(((*(u8 **)((u8 *)(arg0) + (0x1638))) + temp_r8)) + (0x924))) = 0x1C;
        temp_r4_3 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r4_3) + (0x58))) = (s32) ((*(s32 *)((u8 *)(temp_r4_3) + (0x58))) | temp_r6);
        temp_r3 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r3) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3) + (0))) | 0x10);
        return;
    case 1:
        temp_r8_2 = (arg1 * 4) & 0x3FC;
        (*(s32 *)((u8 *)(((*(u8 **)((u8 *)(arg0) + (0x1638))) + temp_r8_2)) + (0x8E4))) = 0xD;
        temp_r6_2 = 1 << arg1;
        temp_r4_4 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r4_4) + (0x54))) = (s32) ((*(s32 *)((u8 *)(temp_r4_4) + (0x54))) | temp_r6_2);
        temp_r4_5 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r4_5) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r4_5) + (0))) | 0x10);
        (*(s32 *)((u8 *)(((*(u8 **)((u8 *)(arg0) + (0x1638))) + temp_r8_2)) + (0x924))) = 0x1D;
        temp_r4_6 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r4_6) + (0x58))) = (s32) ((*(s32 *)((u8 *)(temp_r4_6) + (0x58))) | temp_r6_2);
        temp_r3_2 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r3_2) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3_2) + (0))) | 0x10);
        return;
    case 2:
        temp_r8_3 = (arg1 * 4) & 0x3FC;
        (*(s32 *)((u8 *)(((*(u8 **)((u8 *)(arg0) + (0x1638))) + temp_r8_3)) + (0x8E4))) = 0xE;
        temp_r6_3 = 1 << arg1;
        temp_r4_7 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r4_7) + (0x54))) = (s32) ((*(s32 *)((u8 *)(temp_r4_7) + (0x54))) | temp_r6_3);
        temp_r4_8 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r4_8) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r4_8) + (0))) | 0x10);
        (*(s32 *)((u8 *)(((*(u8 **)((u8 *)(arg0) + (0x1638))) + temp_r8_3)) + (0x924))) = 0x1E;
        temp_r4_9 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r4_9) + (0x58))) = (s32) ((*(s32 *)((u8 *)(temp_r4_9) + (0x58))) | temp_r6_3);
        temp_r3_3 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r3_3) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3_3) + (0))) | 0x10);
        return;
    case 3:
        temp_r8_4 = (arg1 * 4) & 0x3FC;
        (*(s32 *)((u8 *)(((*(u8 **)((u8 *)(arg0) + (0x1638))) + temp_r8_4)) + (0x8E4))) = 0xF;
        temp_r6_4 = 1 << arg1;
        temp_r4_10 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r4_10) + (0x54))) = (s32) ((*(s32 *)((u8 *)(temp_r4_10) + (0x54))) | temp_r6_4);
        temp_r4_11 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r4_11) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r4_11) + (0))) | 0x10);
        (*(s32 *)((u8 *)(((*(u8 **)((u8 *)(arg0) + (0x1638))) + temp_r8_4)) + (0x924))) = 0x1F;
        temp_r4_12 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r4_12) + (0x58))) = (s32) ((*(s32 *)((u8 *)(temp_r4_12) + (0x58))) | temp_r6_4);
        temp_r3_4 = (*(u8 **)((u8 *)(arg0) + (0x1638)));
        (*(s32 *)((u8 *)(temp_r3_4) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3_4) + (0))) | 0x10);
        return;
    }
}
}

extern "C" {

s32 fn_8023C8B4(s32);
s32 fn_8023CAD8(s32, s32, s32, s32, s32);
__declspec(section ".data") extern s32 lbl_80492260;
__declspec(section ".data") extern s32 lbl_804922DC;
__declspec(section ".data") extern s32 lbl_804926BC;
__declspec(section ".data") extern s32 lbl_80492A9C;
__declspec(section ".data") extern s32 lbl_80492E7C;
extern f32 lbl_80641F30;
extern u8 *sInstance__7GSvideo;

void fn_80204058__Fv() {
    f32 temp_f0;

    fn_8023C8B4((s32) &lbl_804926BC);
    fn_8023CAD8((s32) &lbl_804926BC, 9, 1, 4, 0);
    fn_8023CAD8((s32) &lbl_804926BC, 0xA, 0, 4, 0);
    fn_8023CAD8((s32) &lbl_804926BC, 0xB, 1, 5, 0);
    fn_8023CAD8((s32) &lbl_804926BC, 0xC, 1, 5, 0);
    fn_8023CAD8((s32) &lbl_804926BC, 0xD, 1, 3, 0xA);
    fn_8023C8B4((s32) &lbl_804922DC);
    fn_8023CAD8((s32) &lbl_804922DC, 9, 1, 4, 0);
    fn_8023CAD8((s32) &lbl_804922DC, 0xA, 0, 4, 0);
    fn_8023CAD8((s32) &lbl_804922DC, 0xB, 1, 5, 0);
    fn_8023CAD8((s32) &lbl_804922DC, 0xD, 1, 3, 0xA);
    fn_8023C8B4((s32) &lbl_80492E7C);
    fn_8023CAD8((s32) &lbl_80492E7C, 9, 1, 4, 0);
    fn_8023CAD8((s32) &lbl_80492E7C, 0xB, 1, 5, 0);
    fn_8023CAD8((s32) &lbl_80492E7C, 0xC, 1, 5, 0);
    fn_8023CAD8((s32) &lbl_80492E7C, 0xD, 1, 4, 0);
    fn_8023C8B4((s32) &lbl_80492A9C);
    fn_8023CAD8((s32) &lbl_80492A9C, 9, 1, 4, 0);
    fn_8023CAD8((s32) &lbl_80492A9C, 0xB, 1, 5, 0);
    fn_8023CAD8((s32) &lbl_80492A9C, 0xD, 1, 4, 0);
    temp_f0 = lbl_80641F30 / (f32) (*(u8 *)((u8 *)(sInstance__7GSvideo) + (0x59)));
    (*(f32 *)((u8 *)(&lbl_80492260) + (0))) = temp_f0;
    (*(f32 *)((u8 *)(&lbl_80492260) + (4))) = temp_f0;
    (*(f32 *)((u8 *)(&lbl_80492260) + (8))) = temp_f0;
    (*(f32 *)((u8 *)(&lbl_80492260) + (0xC))) = temp_f0;
    (*(f32 *)((u8 *)(&lbl_80492260) + (0x10))) = temp_f0;
}
}

extern "C" {

s32 fn_80207018(s32);
s32 fn_8023CA6C(s32);
extern u8 *lbl_8063F488;

void fn_80204270__Fv() {
    u8 *temp_r31;
    u8 *var_r3;

    var_r3 = lbl_8063F488;
    while (var_r3 != NULL) {
        temp_r31 = (*(u8 **)((u8 *)(var_r3) + (0x150)));
        fn_80207018((s32) var_r3);
        var_r3 = temp_r31;
    }
    fn_8023CA6C((s32) &lbl_804926BC);
    fn_8023CA6C((s32) &lbl_804922DC);
    fn_8023CA6C((s32) &lbl_80492E7C);
    fn_8023CA6C((s32) &lbl_80492A9C);
}
}
