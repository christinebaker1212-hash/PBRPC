

#include "common.hpp"

extern "C" {

s32 PSMTXCopy(s32, u8 *);

void fn_802367D4(u8 *arg0, s32 arg1) {
    u8 *temp_r3;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r5;

    temp_r5 = (*(u8 **)((u8 *)(arg0) + (4))) + 0x94;
    (*(u8 **)((u8 *)(arg0) + (4))) = temp_r5;
    if (arg1 == 0) {
        PSMTXCopy((s32)(temp_r5 - 0x90), (u8 *)(temp_r5 + 4));
        temp_r3 = (*(u8 **)((u8 *)(arg0) + (4)));
        if ((*(s32 *)((u8 *)(temp_r3) + (-0x94))) & 8) {
            (*(s32 *)((u8 *)(temp_r3) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3) + (0))) | 8);
        } else {
            (*(s32 *)((u8 *)(temp_r3) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3) + (0))) & 0xFFFFFFF7);
        }
    } else {
        PSMTXCopy((s32)(arg1), (u8 *)(temp_r5 + 4));
        temp_r3_2 = (*(u8 **)((u8 *)(arg0) + (4)));
        (*(s32 *)((u8 *)(temp_r3_2) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3_2) + (0))) & 0xFFFFFFF7);
    }
    temp_r3_3 = (*(u8 **)((u8 *)(arg0) + (4)));
    (*(s32 *)((u8 *)(temp_r3_3) + (0))) = (s32) ((*(s32 *)((u8 *)(temp_r3_3) + (0))) | 7);
}
}
