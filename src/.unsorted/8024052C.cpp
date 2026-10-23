#include ".unsorted/8024052C.hpp"

#include "common.hpp"

extern "C" {

s32 __dl__FPv(s32);
s32 __dt__14GSrenderTargetFv(s32, s32);
s32 fn_8023645C__FPv(s32);
__declspec(section ".data") extern s32 lbl_80424928;

u8 *fn_802406A8(u8 *arg0, s32 arg1) {
    s32 temp_r0;

    if (arg0 != NULL) {
        temp_r0 = (*(s32 *)((u8 *)(arg0) + (0xA4)));
        (*(s32 **)((u8 *)(arg0) + (0x1C))) = &lbl_80424928;
        if (temp_r0 != 0) {
            fn_8023645C__FPv(temp_r0);
        }
        __dt__14GSrenderTargetFv((s32) arg0, 0);
        if (arg1 > 0) {
            __dl__FPv((s32) arg0);
        }
    }
    return arg0;
}
}
