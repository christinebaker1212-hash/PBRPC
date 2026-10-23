#include ".unsorted/8020EB1C.hpp"

#include "common.hpp"

extern "C" {

s32 fn_8020CB28(s32, s32, f32);
s32 fn_8020EB1C(s32, s32, s32, f32, f32);
s32 fn_8020EF5C(s32, s32, s32, f32);
extern f32 lbl_80642044;

s32 fn_8020EF5C(s32 arg0, s32 arg1, s32 arg2, f32 farg0) {
    f32 temp_f2;

    if (fn_8020CB28(arg0, arg1, farg0) <= 0) {
        return 0;
    }
    temp_f2 = (*(f32 *)((u8 *)(arg0) + (4)));
    fn_8020EB1C(arg0, arg1, arg2, lbl_80642044 - (temp_f2 / (*(f32 *)((u8 *)(arg0) + (0)))), temp_f2);
    return 1;
}
}

extern "C" {

s32 fn_802079B4(s32, s32);
s32 fn_8020F878(s32, s32);
s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;

s32 fn_8020F878(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_802079B4(arg0, 0);
        if (arg1 > 0) {
            freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, arg0);
        }
    }
    return arg0;
}
}
