#include ".unsorted/80176EB4.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80167B30(s32, s32);
s32 fn_80177BD4(s32, s32);

s32 fn_80177BD4(s32 arg0, s32 arg1) {
    return fn_80167B30((s32) (u8) arg0, arg1);
}
}

extern "C" {

u8 *fn_801772F0(s32 *, s32, s32);
__declspec(section ".data") extern s32 lbl_80420430;

u16 fn_80177334(s32 arg0) {
    u8 *temp_r3;

    temp_r3 = fn_801772F0(&lbl_80420430, 0x1E1, arg0);
    if (temp_r3 != NULL) {
        return (*(u16 *)((u8 *)(temp_r3) + (2)));
    }
    return 0x3000U;
}
}

extern "C" {

u16 fn_80177378(s32 arg0) {
    u8 *temp_r3;

    temp_r3 = fn_801772F0((s32 *)(&lbl_80420430), (s32)(0x1E1), (s32)(arg0));
    if (temp_r3 != NULL) {
        return (*(u16 *)((u8 *)(temp_r3) + (4)));
    }
    return 0x81ACU;
}
}
