#include ".unsorted/801682D0.hpp"

#include "common.hpp"

extern "C" {

s32 fn_801682D0(s32, s32, s32);
s32 fn_80176EB4(s32, s32, s32);

void fn_80168418(s32 arg0, s32 arg1, s32 arg2) {
    fn_80176EB4(arg2, arg0, arg1);
    fn_801682D0(arg2, arg1, arg2);
}
}

extern "C" {

s32 fn_80168470(s32);
s32 fn_8016849C(s32, s32, s32);

s32 fn_8016849C(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r0;
    u32 temp_r31;

    var_r0 = (fn_80168470(arg0) + 1) * 2;
    if (var_r0 > arg2) {
        var_r0 = arg2;
    }
    temp_r31 = (u32) var_r0 >> 1U;
    fn_80168418((s32)(arg0), (s32)((s32) temp_r31), (s32)(arg1));
    return temp_r31 * 2;
}
}
