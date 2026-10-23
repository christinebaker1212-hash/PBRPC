#include ".unsorted/8016340C.hpp"

#include "common.hpp"

extern "C" {

extern u8 **lbl_8063F070;

void fn_801634C0(u8 *arg0) {
    u8 **temp_r4_2;
    u8 *temp_r4;

    temp_r4 = (*(u8 **)((u8 *)(arg0) + (0)));
    if (temp_r4 != NULL) {
        (*(u8 **)((u8 *)(temp_r4) + (4))) = arg0;
    } else {
        lbl_8063F070 = (*(u8 ***)((u8 *)(arg0) + (4)));
    }
    temp_r4_2 = (*(u8 ***)((u8 *)(arg0) + (4)));
    if (temp_r4_2 != NULL) {
        *temp_r4_2 = (*(u8 **)((u8 *)(arg0) + (0)));
    }
}
}

extern "C" {

s32 fn_80163580(s32);
s32 memset(s32, s32, s32);

s32 fn_80163580(s32 arg0) {
    return memset(arg0, 0, 4);
}
}

extern "C" {

s32 fn_8016358C(s32, s32, s32, s32, s32);
s32 fn_8016359C(s32, s32);

s32 fn_8016358C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    (*(s32 *)((u8 *)(arg0) + (8))) = arg2;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = arg3;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = arg4;
    return fn_8016359C(arg0, arg1);
}
}

extern "C" {

void fn_80163614(u8 *arg0) {
    if ((u32) (*(u32 *)((u8 *)(arg0) + (0x18))) == 1U) {
        ((s32 (*)(void))fn_801634C0)();
    }
    (*(u32 *)((u8 *)(arg0) + (0x18))) = 0U;
}
}
