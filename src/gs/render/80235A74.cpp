#include "common.hpp"

extern "C" {

void fn_80235A74(u8 *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
}
}

extern "C" {

s32 findModule__14GSrenderModuleFUc(s32);
s32 findTarget__14GSrenderTargetFl(s32);
s32 fn_80236BC0(s32);
s32 fn_8023B120(s32, s32, s32, s32);

s32 fn_80236530(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;

    temp_r3 = findTarget__14GSrenderTargetFl(arg0);
    if (temp_r3 == 0) {
        return 0;
    }
    temp_r3_2 = fn_80236BC0(arg1);
    if (temp_r3_2 == 0) {
        return 0;
    }
    temp_r3_3 = findModule__14GSrenderModuleFUc(arg2);
    if (temp_r3_3 != 0) {
        return fn_8023B120(temp_r3, temp_r3_2, temp_r3_3, 1);
    }
    return 0;
}
}
