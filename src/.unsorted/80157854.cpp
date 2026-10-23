#include ".unsorted/80157854.hpp"

#include "common.hpp"

extern "C" {

void fn_80157854(void) {}
}

#include "common.hpp"

extern "C" {

void fn_80158124(u8 *p) {
    *(u32 *)(p + 0x4) = 0x0;
}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_8015788C(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_800097F0(void);

void fn_801578CC(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    fn_800097F0();
    (*(s8 *)((u8 *)(arg0) + (0x1D))) = 1;
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8041E8E4;

void fn_80157858(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s32 **)((u8 *)(arg0) + (0))) = &lbl_8041E8E4;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x14))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x18))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x1C))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x1D))) = 0;
}
}
