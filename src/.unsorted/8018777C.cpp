#include ".unsorted/8018777C.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80187868(void) {
    return 0;
}
s32 fn_80187F54(void) {
    return 0;
}
}

extern "C" {

u16 fn_8018A8D8(u8 *arg0) {
    if (arg0 == NULL) {
        return 0U;
    }
    return (*(u16 *)((u8 *)(arg0) + (0x854)));
}
}

extern "C" {

u8 fn_8018BF18(u8 *arg0) {
    if (arg0 == NULL) {
        return 0U;
    }
    return (*(u8 *)((u8 *)(arg0) + (0x70)));
}
}

extern "C" {

s32 fn_8018E388(s32 *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    return *arg0;
}
}

extern "C" {

s32 fn_80180B04(s32, s32);
s32 fn_8019A8B0(s32, s32);

s32 fn_8019A8B0(s32 arg0, s32 arg1) {
    s32 var_r0;
    s32 var_r0_10;
    s32 var_r0_11;
    s32 var_r0_12;
    s32 var_r0_13;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r0_4;
    s32 var_r0_5;
    s32 var_r0_6;
    s32 var_r0_7;
    s32 var_r0_8;
    s32 var_r0_9;
    u32 var_r0_14;
    u8 var_r0_15;
    u8 var_r0_16;
    u8 var_r30;

    if (arg1 == 0) {
        var_r0 = 0;
    } else {
        var_r0 = (*(s32 *)((u8 *)(arg1) + (0x790)));
    }
    if (var_r0 & 7) {
        return 9;
    }
    if (arg1 == 0) {
        var_r0_2 = 0;
    } else {
        var_r0_2 = (*(s32 *)((u8 *)(arg1) + (0x790)));
    }
    if (var_r0_2 & 0xF0000) {
        return 0xA;
    }
    if (arg1 == 0) {
        var_r30 = 0;
    } else {
        var_r30 = ((u32) *(*(u32 **)((u8 *)(arg1) + (0x798))) >> 0x11U) & 3;
    }
    if (arg1 == 0) {
        var_r0_3 = 0;
    } else {
        var_r0_3 = (*(s32 *)((u8 *)(arg1) + (0x794)));
    }
    if ((var_r0_3 & 0x20) && (fn_80180B04(arg0, arg1) == 0) && ((var_r30 - 1) == 0)) {
        return 0xB;
    }
    if (arg1 == 0) {
        var_r0_4 = 0;
    } else {
        var_r0_4 = (*(s32 *)((u8 *)(arg1) + (0x790)));
    }
    if (var_r0_4 & 0xE000) {
        return 0xC;
    }
    if (arg1 == 0) {
        var_r0_5 = 0;
    } else {
        var_r0_5 = (*(s32 *)((u8 *)(arg1) + (0x790)));
    }
    if (var_r0_5 & 0x08000000) {
        return 0xD;
    }
    if (arg1 == 0) {
        var_r0_6 = 0;
    } else {
        var_r0_6 = (*(s32 *)((u8 *)(arg1) + (0x790)));
    }
    if (var_r0_6 & 0x10000000) {
        return 0xE;
    }
    if (arg1 == 0) {
        var_r0_7 = 0;
    } else {
        var_r0_7 = (*(s32 *)((u8 *)(arg1) + (0x790)));
    }
    if (var_r0_7 & 0x20000000) {
        return 0xF;
    }
    if (arg1 == 0) {
        var_r0_8 = 0;
    } else {
        var_r0_8 = (*(s32 *)((u8 *)(arg1) + (0x790)));
    }
    if (var_r0_8 & 0x80000000) {
        return 0x10;
    }
    if (arg1 == 0) {
        var_r0_9 = 0;
    } else {
        var_r0_9 = (*(s32 *)((u8 *)(arg1) + (0x794)));
    }
    if (var_r0_9 & 4) {
        return 0x11;
    }
    if (arg1 == 0) {
        var_r0_10 = 0;
    } else {
        var_r0_10 = (*(s32 *)((u8 *)(arg1) + (0x794)));
    }
    if (var_r0_10 & 0x18) {
        return 0x12;
    }
    if (arg1 == 0) {
        var_r0_11 = 0;
    } else {
        var_r0_11 = (*(s32 *)((u8 *)(arg1) + (0x794)));
    }
    if (var_r0_11 & 0x1800) {
        return 0x13;
    }
    if (arg1 == 0) {
        var_r0_12 = 0;
    } else {
        var_r0_12 = (*(s32 *)((u8 *)(arg1) + (0x794)));
    }
    if (var_r0_12 & 0x2000) {
        return 0x14;
    }
    if (arg1 == 0) {
        var_r0_13 = 0;
    } else {
        var_r0_13 = (*(s32 *)((u8 *)(arg1) + (0x794)));
    }
    if (var_r0_13 & 0x4000) {
        return 0x15;
    }
    if (arg1 == 0) {
        var_r0_14 = 0;
    } else {
        var_r0_14 = (u32) *(*(u32 **)((u8 *)(arg1) + (0x798))) >> 0x1DU;
    }
    if ((u8) var_r0_14 != 0) {
        return 0x16;
    }
    if (arg1 == 0) {
        var_r0_15 = 0;
    } else {
        var_r0_15 = ((u32) *(*(u32 **)((u8 *)(arg1) + (0x798))) >> 0x1AU) & 7;
    }
    if (var_r0_15 != 0) {
        return 0x17;
    }
    if (arg1 == 0) {
        var_r0_16 = 0;
    } else {
        var_r0_16 = ((u32) *(*(u32 **)((u8 *)(arg1) + (0x798))) >> 0x15U) & 7;
    }
    if (var_r0_16 != 0) {
        return 0x18;
    }
    return 0;
}
}

extern "C" {

s32 fn_8019AD6C(s32, s32, s32);
s32 fn_8019B130(s32, s32, s32, s32);
s32 fn_8019BE08(s32, s32, s32);
s32 fn_801BF694(s32, s32);
s32 fn_801C3B64(s32, s32);

s32 fn_8019BE08(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;

    fn_801BF694(0, arg1);
    if (fn_8019AD6C(arg0, arg1, arg2) <= 0) {
        return 0;
    }
    temp_r3 = fn_8019B130(arg0, arg2, 1, arg1);
    if (temp_r3 == 0) {
        return 0;
    }
    fn_801C3B64(arg1, temp_r3);
    return 1;
}
}
