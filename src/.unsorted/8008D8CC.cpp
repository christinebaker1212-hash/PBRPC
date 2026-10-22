#include ".unsorted/8008D8CC.hpp"

#include "common.hpp"

extern "C" {

void fn_8008E4F0(void) {}
void fn_80090BC0(void) {}
}

extern "C" {

s32 fn_80090B94(s32, s32);
s32 fn_80253EDC(s32, s32, s32, s32);

s32 fn_80090B94(s32 arg0, s32 arg1) {
    s32 sp8;

    return fn_80253EDC((s32) (s16) arg0, arg1, 3, (s32) &sp8);
}
}
