#include ".unsorted/802078B8.hpp"

#include "common.hpp"

extern "C" {

void fn_80207A30(u8 *p) {
    *(u8 *)(p + 0x18) = 0x1;
}
}

extern "C" {

u8 *fn_80207A58(u8 *arg0) {
    u8 *temp_r4;
    u8 *temp_r5;

    temp_r5 = (*(u8 **)((u8 *)(arg0) + (0xC)));
    if (temp_r5 == NULL) {
        return NULL;
    }
    temp_r4 = (*(u8 **)((u8 *)(arg0) + (0x10)));
    (*(u8 **)((u8 *)(arg0) + (0xC))) = (u8 *) (*(u8 **)((u8 *)(temp_r5) + (0x28)));
    (*(u8 **)((u8 *)(temp_r5) + (0x28))) = temp_r4;
    if (temp_r4 != NULL) {
        (*(u8 **)((u8 *)(temp_r4) + (0x2C))) = temp_r5;
    }
    (*(s32 *)((u8 *)(temp_r5) + (0x2C))) = 0;
    (*(u8 **)((u8 *)(arg0) + (0x10))) = temp_r5;
    (*(u16 *)((u8 *)(arg0) + (0x14))) = (u16) ((*(u16 *)((u8 *)(arg0) + (0x14))) + 1);
    return temp_r5;
}
}

extern "C" {

void fn_80207B34(u8 *arg0, u8 *arg1) {
    u8 *temp_r5;
    u8 *temp_r5_2;
    u8 *temp_r6;

    temp_r5 = (*(u8 **)((u8 *)(arg1) + (0x28)));
    temp_r6 = (*(u8 **)((u8 *)(arg1) + (0x2C)));
    if (temp_r5 != NULL) {
        (*(u8 **)((u8 *)(temp_r5) + (0x2C))) = temp_r6;
    }
    if (temp_r6 != NULL) {
        (*(u8 **)((u8 *)(temp_r6) + (0x28))) = temp_r5;
    } else {
        (*(u8 **)((u8 *)(arg0) + (0x10))) = temp_r5;
    }
    (*(u8 **)((u8 *)(arg1) + (0x2C))) = NULL;
    temp_r5_2 = (*(u8 **)((u8 *)(arg0) + (0xC)));
    (*(u8 **)((u8 *)(arg1) + (0x28))) = temp_r5_2;
    if (temp_r5_2 != NULL) {
        (*(u8 **)((u8 *)(temp_r5_2) + (0x2C))) = arg1;
    }
    (*(u8 **)((u8 *)(arg0) + (0xC))) = arg1;
    (*(u16 *)((u8 *)(arg0) + (0x14))) = (u16) ((*(u16 *)((u8 *)(arg0) + (0x14))) - 1);
}
}

extern "C" {

void fn_80207BDC(u8 *arg0, u8 *arg1, u8 *arg2) {
    u8 *temp_r6;
    u8 *temp_r6_2;
    u8 *temp_r7;

    temp_r6 = (*(u8 **)((u8 *)(arg1) + (0x28)));
    temp_r7 = (*(u8 **)((u8 *)(arg1) + (0x2C)));
    if (temp_r6 != NULL) {
        (*(u8 **)((u8 *)(temp_r6) + (0x2C))) = temp_r7;
    }
    if (temp_r7 != NULL) {
        (*(u8 **)((u8 *)(temp_r7) + (0x28))) = temp_r6;
    } else {
        (*(u8 **)((u8 *)(arg0) + (0x10))) = temp_r6;
    }
    temp_r6_2 = (*(u8 **)((u8 *)(arg2) + (0x2C)));
    (*(u8 **)((u8 *)(arg2) + (0x2C))) = arg1;
    (*(u8 **)((u8 *)(arg1) + (0x28))) = arg2;
    (*(u8 **)((u8 *)(arg1) + (0x2C))) = temp_r6_2;
    if (temp_r6_2 != NULL) {
        (*(u8 **)((u8 *)(temp_r6_2) + (0x28))) = arg1;
        return;
    }
    (*(u8 **)((u8 *)(arg0) + (0x10))) = arg1;
}
}

extern "C" {

s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;
__declspec(section ".data") extern s32 lbl_80423868;

u8 *fn_802079B4(u8 *arg0, s32 arg1) {
    s32 temp_r4;

    if (arg0 != NULL) {
        temp_r4 = (*(s32 *)((u8 *)(arg0) + (8)));
        (*(s32 **)((u8 *)(arg0) + (0x1C))) = &lbl_80423868;
        if (temp_r4 != 0) {
            freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, temp_r4);
            (*(s32 *)((u8 *)(arg0) + (8))) = 0;
        }
        if (arg1 > 0) {
            freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, (s32) arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_80207B8C(s32);

void fn_80207A3C(u8 *arg0) {
    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x18))) != 0) {
        (*(u8 *)((u8 *)(arg0) + (0x18))) = 0U;
        fn_80207B8C((s32) arg0);
    }
}
}
