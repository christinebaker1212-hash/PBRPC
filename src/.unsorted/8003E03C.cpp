#include ".unsorted/8003E03C.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063EA80;

void fn_8003E158(void) {}
u32 fn_8003E15C(void) {
    return lbl_8063EA80;
}
u32 fn_8003E42C(u8 *p) {
    return *(u32 *)(p + 0xc);
}
}

extern "C" {

s32 fn_8003E544(s32, s32, s32, s32);
s32 fn_8003E610(s32, s32);
s32 fn_80391200(s32, s32);

s32 fn_8003E610(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_8003E544(arg0, arg1, 0, 0xFF);
    if (temp_r3 >= 0) {
        return fn_80391200((*(s32 *)((u8 *)(arg0) + (4))), temp_r3);
    }
    return -1;
}
}

extern "C" {

s32 fn_8003E698(s32, s32, s32, s32);
s32 fn_80391318(s32, s32);

s32 fn_8003E698(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    temp_r3 = fn_8003E544((s32)(arg0), (s32)(arg1), (s32)(arg2), (s32)(arg3));
    if (temp_r3 >= 0) {
        return fn_80391318((*(s32 *)((u8 *)(arg0) + (4))), temp_r3);
    }
    return 0;
}
}

extern "C" {

s32 fn_8003E6E0(s32, s32, s32, s32, s32);
s32 fn_8039134C(s32, s32);
s32 fn_80391380(s32, s32);

s32 fn_8003E6E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r3;

    temp_r3 = fn_8003E544((s32)(arg0), (s32)(arg1), (s32)(arg3), (s32)(arg4));
    if (temp_r3 >= 0) {
        if (arg2 != 0) {
            return fn_80391380((*(s32 *)((u8 *)(arg0) + (4))), temp_r3);
        }
        return fn_8039134C((*(s32 *)((u8 *)(arg0) + (4))), temp_r3);
    }
    return 0;
}
}
