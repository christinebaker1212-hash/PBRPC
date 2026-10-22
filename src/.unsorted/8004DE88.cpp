#include ".unsorted/8004DE88.hpp"

#include "common.hpp"

extern "C" {

s32 __dl__FPv(s32);
s32 fn_8004DF78(void);

s32 fn_8004DEF8(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8004DF78();
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

extern u32 lbl_8063D448;

void fn_8004DF4C(u8 *arg0) {
    u32 temp_r5;

    temp_r5 = lbl_8063D448 + 1;
    (*(s32 *)((u8 *)(arg0) + (0x50))) = (s32) (lbl_8063D448 | 0x82900000);
    lbl_8063D448 = temp_r5;
    if (temp_r5 > 0x10000U) {
        lbl_8063D448 = 1;
    }
}
}

extern "C" {

void fn_8004E780(u8 *arg0, s32 arg1) {
    (*(s32 *)((u8 *)(arg0) + (0x54))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (0x34))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0x34))) | 0x10);
}
}
