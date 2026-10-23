

#include "common.hpp"

extern "C" {

s32 PSMTXCopy(s32, u8 *);

void fn_802367D4(u8 *arg0, s32 arg1) {
    u8 *temp_r3;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r5;

    temp_r5 = (*(u8 **)((u8 *)(arg0) + (4))) + 0x94;
    (*(u8 **)((u8 *)(arg0) + (4))) = temp_r5;
    if (arg1 == 0) {
        PSMTXCopy((s32)(temp_r5 - 0x90), (u8 *)(temp_r5 + 4));
        temp_r3 = (*(u8 **)((u8 *)(arg0) + (4)));
        if ((*(s32 *)((u8 *)(temp_r3) + (-0x94))) & 8) {
            (*(s32 *)((u8 *)(temp_r3) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3) + (0))) | 8);
        } else {
            (*(s32 *)((u8 *)(temp_r3) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3) + (0))) & 0xFFFFFFF7);
        }
    } else {
        PSMTXCopy((s32)(arg1), (u8 *)(temp_r5 + 4));
        temp_r3_2 = (*(u8 **)((u8 *)(arg0) + (4)));
        (*(s32 *)((u8 *)(temp_r3_2) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3_2) + (0))) & 0xFFFFFFF7);
    }
    temp_r3_3 = (*(u8 **)((u8 *)(arg0) + (4)));
    (*(s32 *)((u8 *)(temp_r3_3) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3_3) + (0))) | 7);
}
}

extern "C" {

s32 PSMTXIdentity(s32);
s32 allocAndClear__5GSmemFUl(s32);

u8 *__ct__17_UnkClass80236704FUl(u8 *arg0, s32 arg1) {
    s32 temp_r3;
    s32 *temp_r4;

    temp_r3 = allocAndClear__5GSmemFUl(arg1 * 0x94);
    (*(s32 *)((u8 *)(arg0) + (0))) = temp_r3;
    (*(s32 *)((u8 *)(arg0) + (4))) = temp_r3;
    (*(s32 *)((u8 *)(arg0) + (8))) = (s32) (temp_r3 + ((arg1 - 1) * 0x94));
    PSMTXIdentity(temp_r3 + 4);
    temp_r4 = (long *)((*(s32 *)((u8 *)(arg0) + (4))));
    *temp_r4 = (s32) (*temp_r4 | 7);
    return arg0;
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 free__5GSmemFPv(s32);

s32 *__dt__17_UnkClass80236704Fv(s32 *arg0, s32 arg1) {
    s32 temp_r3;

    if (arg0 != NULL) {
        temp_r3 = *arg0;
        if (temp_r3 != 0) {
            free__5GSmemFPv(temp_r3);
        }
        if (arg1 > 0) {
            __dl__FPv((s32) arg0);
        }
    }
    return arg0;
}
}

extern "C" {

struct S_lbl_8063F6B0 { s8 f_0; u8 pad_1[1]; s16 f_2; s8 f_4; };
extern struct S_lbl_8063F6B0 lbl_8063F6B0;

void fn_8023692C() {
    lbl_8063F6B0.f_0 = 1;
    lbl_8063F6B0.f_2 = 4;
    lbl_8063F6B0.f_4 = 0;
}
}
