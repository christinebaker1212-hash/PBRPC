#include ".unsorted/8025D3B8.hpp"

#include "common.hpp"

extern "C" {

void fn_8025D3B8(u8 *arg0, u8 *arg1, s32 arg2) {
    (*(u8 **)((u8 *)(arg0) + (0))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (4))) = (s32) (arg1 + arg2);
    (*(s32 *)((u8 *)(arg0) + (8))) = 1;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
    (*(s32 *)((u8 *)(arg1) + (0))) = 0;
    (*(s32 *)((u8 *)(arg1) + (4))) = 0xD185;
    (*(s32 *)((u8 *)(arg1) + (8))) = arg2;
    (*(s32 *)((u8 *)(arg1) + (0xC))) = (s32) (arg2 - 0x20);
    (*(s32 *)((u8 *)(arg1) + (0x10))) = 0;
    (*(s32 *)((u8 *)(arg1) + (0x14))) = 0;
    (*(s16 *)((u8 *)(arg1) + (0x1A))) = 0;
    (*(s32 *)((u8 *)(arg1) + (0x1C))) = 0;
}
}

extern "C" {

s32 OSReport(s32, ...);
__declspec(section ".data") extern s8 lbl_80425430;


}

extern "C" {

__declspec(section ".data") extern s8 lbl_80425464;


}

extern "C" {

s32 fn_8025D55C(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        return 0;
    }
    if (arg1 & 0x1F) {
        OSReport((s32)((const s8 *)(&lbl_80425430)), 0x20);
    }
    return (*(s32 *)((u8 *)(arg1) + (-0x14)));
}
}

extern "C" {

u16 fn_8025D5B4(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        return 0U;
    }
    if (arg1 & 0x1F) {
        OSReport((s32)((const s8 *)(&lbl_80425464)), 0x20);
    }
    return (*(u16 *)((u8 *)(arg1) + (-8)));
}
}
