#include ".unsorted/80213694.hpp"

#include "common.hpp"

extern "C" {

s32 fn_802328AC__13GSdisplayListFv(s32);
s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;

void fn_80218134(u8 *arg0) {
    s32 temp_r0;

    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x434)));
    if (temp_r0 != 0) {
        fn_802328AC__13GSdisplayListFv(temp_r0);
        freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, (*(s32 *)((u8 *)(arg0) + (0x434))));
        (*(s32 *)((u8 *)(arg0) + (0x434))) = 0;
    }
}
}

extern "C" {

s32 fn_80219DFC(u8 **arg0) {
    u8 *temp_r4;

    temp_r4 = *arg0;
    return (*(u16 *)((u8 *)(temp_r4) + (0xA))) * (*(u16 *)((u8 *)(temp_r4) + (0xC))) * 2;
}
}

extern "C" {

s32 fn_80219E14(s32 *arg0, s32 arg1) {
    return (*(s32 *)((u8 *)((*arg0 + (arg1 * 4))) + (0x28)));
}
}
