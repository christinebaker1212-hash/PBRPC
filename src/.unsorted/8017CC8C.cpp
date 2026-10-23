#include ".unsorted/8017CC8C.hpp"

#include "common.hpp"

extern "C" {

s32 fn_8017CDD8(s32, s32);

s32 fn_8017CDD8(s32 arg0, s32 arg1) {
    if (arg0 == 0) {
        return 0;
    }
    return arg0 + (arg1 * 0x9544) + 0xC;
}
}

extern "C" {

s32 fn_8017CE00(s32, s32);

s32 fn_8017CE00(s32 arg0, s32 arg1) {
    if (arg0 == 0) {
        return 0;
    }
    return arg0 + (arg1 * 0x774) + 0x28C;
}
}

extern "C" {

s32 fn_8017CE20(s32, s32);

s32 fn_8017CE20(s32 arg0, s32 arg1) {
    if (arg1 & 1) {
        return arg0 + ((((u32) arg1 >> 1U) & 1) * 0x6EC) + 0x1224;
    }
    return arg0 + ((((u32) arg1 >> 1U) & 1) * 0x6EC) + 0x44C;
}
}

extern "C" {

s32 fn_8017D100(s32);

s32 fn_8017D100(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return (*(s32 *)((u8 *)(arg0) + (8)));
}
}

extern "C" {

s32 fn_8017D170(s32, s32);
s32 fn_8017D1B0(s32, s32, s32);

s32 fn_8017D1B0(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    var_r3 = arg0;
    if (var_r3 != 0) {
        var_r3 = fn_8017D170(var_r3, arg1);
        if (var_r3 != 0) {
            (*(s8 *)((u8 *)(var_r3) + (2))) = (s8) arg2;
        }
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8017D1F0(s32, s32, s32);

s32 fn_8017D1F0(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    var_r3 = arg0;
    if (var_r3 != 0) {
        var_r3 = fn_8017D170((s32)(var_r3), (s32)(arg1));
        if (var_r3 != 0) {
            (*(s8 *)((u8 *)(var_r3) + (3))) = (s8) arg2;
        }
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8017D510(s32, s32);

s32 fn_8017D510(s32 arg0, s32 arg1) {
    if (arg0 == 0) {
        return 0;
    }
    return arg0 + (arg1 * 0x8CC) + 0x2F44;
}
}

extern "C" {

s32 fn_8017D190(s32, s32);
s32 fn_8017DA60(s32, s32, s32);

s32 fn_8017DA60(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    var_r3 = arg0;
    if (var_r3 != 0) {
        var_r3 = fn_8017D190(var_r3, arg1);
        if (var_r3 != 0) {
            (*(s8 *)((u8 *)(var_r3) + (2))) = (s8) arg2;
        }
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8017DAA0(s32, s32, s32);

s32 fn_8017DAA0(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    var_r3 = arg0;
    if (var_r3 != 0) {
        var_r3 = fn_8017D190((s32)(var_r3), (s32)(arg1));
        if (var_r3 != 0) {
            (*(s8 *)((u8 *)(var_r3) + (3))) = (s8) arg2;
        }
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8017DB9C(s32, s32);

s32 fn_8017DB9C(s32 arg0, s32 arg1) {
    if (arg0 == 0) {
        return 0;
    }
    return arg0 + (arg1 * 0x6C) + 4;
}
}

extern "C" {

void fn_8017D130(s32 arg0, s32 arg1, s16 arg2) {
    s16 *temp_r3;

    if (arg0 != 0) {
        temp_r3 = ((s16 * (*)(void))fn_8017D170)();
        if (temp_r3 != NULL) {
            *temp_r3 = arg2;
        }
    }
}
}

extern "C" {

void fn_8017DA20(s32 arg0, s32 arg1, s16 arg2) {
    s16 *temp_r3;

    if (arg0 != 0) {
        temp_r3 = ((s16 * (*)(void))fn_8017D190)();
        if (temp_r3 != NULL) {
            *temp_r3 = arg2;
        }
    }
}
}
