#include ".unsorted/8025D7CC.hpp"

#include "common.hpp"

extern "C" {

u32 fn_8025D7F8(u8 *p) {
    return *(u32 *)(p + 0x1c);
}
u32 fn_8025D800(u8 *p) {
    return *(u32 *)(p + 0x18);
}
}

extern "C" {

void fn_8025D7CC(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_r5;

    temp_r5 = arg1 + arg2;
    (*(s32 *)((u8 *)(arg0) + (0))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (4))) = temp_r5;
    (*(s32 *)((u8 *)(arg0) + (8))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (0x14))) = temp_r5;
    (*(s32 *)((u8 *)(arg0) + (0x18))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = 0;
}
}
