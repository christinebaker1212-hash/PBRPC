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
