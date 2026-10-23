#include "common.hpp"

extern "C" {

s32 fn_801FA6BC(s32, s32, s32);
s32 fn_801FA750(s32, s32, s32, s32);

s32 fn_801FA750(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    temp_r3 = fn_801FA6BC(arg0, arg1, arg2);
    if (temp_r3 != 0) {
        if ((s32) (*(u8 *)((u8 *)(temp_r3) + (8))) == 0) {
            (*(s32 *)((u8 *)(temp_r3) + (4))) = (s32) (*(s32 *)((u8 *)(arg0) + (0x18)));
            (*(s32 *)((u8 *)(arg0) + (0x18))) = temp_r3;
            (*(u8 *)((u8 *)(temp_r3) + (8))) = 1U;
        }
        (*(u8 *)((u8 *)(temp_r3) + (9))) = (u8) ((*(u8 *)((u8 *)(temp_r3) + (9))) | (1 << arg3));
    }
    return temp_r3;
}
}

extern "C" {

void fn_801FA7C4(u8 *arg0);
s32 fn_801FA9F8(s32);
s32 fn_801FAB0C(s32);
s32 fn_801FAEB8(s32, s32);

void fn_801FAFE0__17_UnkClass801FA38CFf(s32 arg0, s32 arg1) {
    u8 *var_r31;

    fn_801FA9F8(arg0);
    if (((s32) (*(s32 *)((u8 *)(arg0) + (8))) != 0) || ((s32) (*(s32 *)((u8 *)(arg0) + (4))) != 0)) {
        fn_801FAB0C(arg0);
        var_r31 = (*(u8 **)((u8 *)(arg0) + (0x18)));
        while (var_r31 != NULL) {
            if ((u8) (*(u8 *)((u8 *)(var_r31) + (9))) == 7) {
                fn_801FAEB8(arg0, (s32) var_r31);
            }
            var_r31 = (*(u8 **)((u8 *)(var_r31) + (4)));
        }
        fn_801FA7C4((u8 *)(arg0));
    }
}
}

extern "C" {

void fn_801FA7C4(u8 *arg0) {
    u8 *var_r4;
    u8 *temp_r5;

    var_r4 = (*(u8 **)((u8 *)(arg0) + (0x18)));
    while (var_r4 != NULL) {
        temp_r5 = (*(u8 **)((u8 *)(var_r4) + (4)));
        (*(s8 *)((u8 *)(var_r4) + (8))) = 0;
        (*(u8 **)((u8 *)(var_r4) + (4))) = NULL;
        (*(s8 *)((u8 *)(var_r4) + (9))) = 0;
        var_r4 = temp_r5;
    }
    (*(u8 **)((u8 *)(arg0) + (0x18))) = NULL;
}
}

extern "C" {

s32 fn_801FA46C(u8 *arg0, u32 arg1) {
    if (arg1 == 0xFFFF) {
        return 0;
    }
    if (arg1 >= (u16) (*(u16 *)((u8 *)(arg0) + (0x14)))) {
        return 0;
    }
    return *(s32 *)((u8 *)0 + ((*(s32 *)((u8 *)(arg0) + (0x10))) + (arg1 * 0x44)));
}
}
