#include ".unsorted/80167820.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80164C2C(s32);
s32 fn_80166C3C(s32, s32);
s32 fn_80167874(s32, s32, s32);

s32 fn_80167874(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;

    temp_r3 = fn_80164C2C(arg0);
    if (temp_r3 != 0) {
        fn_80166C3C(temp_r3, arg2);
    }
    return 0;
}
}

extern "C" {

s32 fn_80166CAC(s32, s32);
s32 fn_801678B4(s32, s32, s32);

s32 fn_801678B4(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;

    temp_r3 = fn_80164C2C((s32)(arg0));
    if (temp_r3 != 0) {
        fn_80166CAC(temp_r3, arg2);
    }
    return 0;
}
}

extern "C" {

s32 fn_80166D14(s32, s32);
s32 fn_801678F4(s32, s32, s32);

s32 fn_801678F4(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;

    temp_r3 = fn_80164C2C((s32)(arg0));
    if (temp_r3 != 0) {
        fn_80166D14(temp_r3, arg2);
    }
    return 0;
}
}
