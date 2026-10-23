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
