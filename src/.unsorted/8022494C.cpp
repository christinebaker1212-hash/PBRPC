#include ".unsorted/8022494C.hpp"

#include "common.hpp"

extern "C" {

s32 __dl__FPv(void);

s32 fn_80224AB0(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_80423C38;

void fn_8022494C(u8 *arg0, s32 arg1) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 **)((u8 *)(arg0) + (0xC))) = &lbl_80423C38;
}
}
