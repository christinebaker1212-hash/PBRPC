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

extern "C" {

s32 fn_80207B34(u8 *, u8 *);

void fn_8020F230(u8 *arg0, f32 farg0) {
    u8 *var_r31;
    u8 *temp_r30;

    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x18))) != 0) {
        var_r31 = (*(u8 **)((u8 *)(arg0) + (0x10)));
        while (var_r31 != NULL) {
            temp_r30 = (*(u8 **)((u8 *)(var_r31) + (0x28)));
            if (fn_8020EF5C((s32)(var_r31), (s32)((*(s32 *)((u8 *)(arg0) + (0)))), (s32)((*(s32 *)((u8 *)(arg0) + (0x20)))), (f32)(farg0)) == 0) {
                fn_80207B34(arg0, var_r31);
            }
            var_r31 = temp_r30;
        }
        (*(f32 *)((u8 *)(arg0) + (0x24))) = (f32) ((*(f32 *)((u8 *)(arg0) + (0x24))) - farg0);
    }
}
}
