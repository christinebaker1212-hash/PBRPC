#include ".unsorted/8020B4F8.hpp"

#include "common.hpp"

extern "C" {

extern s32 lbl_8063F498;

s32 fn_8020C750(u8 *arg0) {
    s32 temp_r3;

    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x18))) == 0) {
        return 0;
    }
    if ((s32) (*(u16 *)((u8 *)(arg0) + (0x14))) == 0) {
        return 0;
    }
    temp_r3 = *(*(s32 **)((u8 *)(arg0) + (0x20)));
    if (temp_r3 & 0x20000) {
        return (lbl_8063F498 - 0xA) == 0;
    }
    if (temp_r3 & 0x40000) {
        return (lbl_8063F498 - 5) == 0;
    }
    return (lbl_8063F498 - 8) == 0;
}
}

extern "C" {

s32 fn_802079B4(s32, s32);
s32 fn_8020C9BC(s32, s32);
s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;

s32 fn_8020C9BC(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_802079B4(arg0, 0);
        if (arg1 > 0) {
            freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, arg0);
        }
    }
    return arg0;
}
}
