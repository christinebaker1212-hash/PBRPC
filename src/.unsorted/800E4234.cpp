#include ".unsorted/800E4234.hpp"

#include "common.hpp"

extern "C" {

void fn_800E46A0(void) {}
void fn_800E5670(void) {}
}

extern "C" {

void fn_800E695C(u8 *arg0, s32 arg1) {
    if (arg1 != 0) {
        (*(u8 *)((u8 *)(arg0) + (7))) = (u8) ((*(u8 *)((u8 *)(arg0) + (7))) | 1);
        return;
    }
    (*(u8 *)((u8 *)(arg0) + (7))) = (u8) ((*(u8 *)((u8 *)(arg0) + (7))) & 0xFE);
}
}

extern "C" {

void fn_800E6984(u8 *arg0, s32 arg1) {
    u16 temp_r0;

    temp_r0 = (*(u16 *)((u8 *)(arg0) + (0x16FE))) | 2;
    (*(u16 *)((u8 *)(arg0) + (0x16FE))) = temp_r0;
    if (arg1 != 0) {
        (*(u16 *)((u8 *)(arg0) + (0x16FE))) = (u16) (temp_r0 | 4);
    }
}
}
