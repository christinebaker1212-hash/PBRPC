#include ".unsorted/8020D250.hpp"

#include "common.hpp"

extern "C" {

s32 fn_802079B4(s32, s32);
s32 fn_8020E9FC(s32, s32);
s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;

s32 fn_8020E9FC(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_802079B4(arg0, 0);
        if (arg1 > 0) {
            freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_802078B8(s32, s32, s32, s32);
__declspec(section ".data") extern s32 lbl_80423990;

s32 fn_8020E3EC(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    fn_802078B8(arg0, arg1, 0x68, arg3);
    (*(s32 *)((u8 *)(arg0) + (0x20))) = arg2;
    (*(s32 **)((u8 *)(arg0) + (0x1C))) = &lbl_80423990;
    return arg0;
}
}
