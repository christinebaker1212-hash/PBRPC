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
