#include ".unsorted/8004DE88.hpp"

#include "common.hpp"

extern "C" {

s32 __dl__FPv(s32);
s32 fn_8004DF78(void);

s32 fn_8004DEF8(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8004DF78();
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

extern u32 lbl_8063D448;

void fn_8004DF4C(u8 *arg0) {
    u32 temp_r5;

    temp_r5 = lbl_8063D448 + 1;
    (*(s32 *)((u8 *)(arg0) + (0x50))) = (s32) (lbl_8063D448 | 0x82900000);
    lbl_8063D448 = temp_r5;
    if (temp_r5 > 0x10000U) {
        lbl_8063D448 = 1;
    }
}
}

extern "C" {

void fn_8004E780(u8 *arg0, s32 arg1) {
    (*(s32 *)((u8 *)(arg0) + (0x54))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (0x34))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0x34))) | 0x10);
}
}

extern "C" {

s32 fn_8004D80C(void);
s32 fn_8004DE28(s32, s32);
s32 fn_8004E85C(s32, s32, s32, s32, f32);
s32 fn_8004E92C(s32, s32, s32, s32, f32);

s32 fn_8004E92C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0) {
    s32 temp_r3;
    s32 temp_r3_2;

    if (arg0 == 0) {
        return 0;
    }
    temp_r3 = fn_8004D80C();
    if ((temp_r3 != 0) && (arg0 != 0)) {
        temp_r3_2 = fn_8004DE28(temp_r3, (*(s32 *)((u8 *)(arg0) + (0x13C))));
        if (temp_r3_2 != 0) {
            fn_8004E85C(temp_r3_2, arg1, arg2, arg3, farg0);
        }
    }
    return 0;
}
}

extern "C" {

s32 fn_80033088__Fv(void);
s32 fn_80033B7C__FP11Unk80033090Ul(s32, s32);
s32 fn_80035970__FP11Unk80035380(s32);

void fn_8004E678(u8 *arg0, s32 arg1, s32 arg2) {
    s32 var_r3;
    u8 *temp_r3;
    u8 *temp_r4;

    if ((u8 *) (*(u8 **)((u8 *)(arg0) + (0x40))) != NULL) {
        var_r3 = fn_80033088__Fv();
        temp_r4 = (*(u8 **)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x40)))) + (0x138)));
        if (temp_r4 != NULL) {
            (*(u16 *)((u8 *)(temp_r4) + (0x148))) = (u16) ((*(u16 *)((u8 *)(temp_r4) + (0x148))) | 8);
        }
        if ((arg1 != 0) && (arg2 != 0)) {
            (*(s32 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x40)))) + (0x12C))) = 0;
            return;
        }
        if (arg1 != 0) {
            if (var_r3 != 0) {
                var_r3 = fn_80033B7C__FP11Unk80033090Ul(var_r3, 0);
            }
            if (var_r3 != 0) {
                (*(s32 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x40)))) + (0x12C))) = fn_80035970__FP11Unk80035380(var_r3);
            }
        } else if (arg2 != 0) {
            if (var_r3 != 0) {
                var_r3 = fn_80033B7C__FP11Unk80033090Ul(var_r3, 1);
            }
            if (var_r3 != 0) {
                (*(s32 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x40)))) + (0x12C))) = fn_80035970__FP11Unk80035380(var_r3);
            }
        } else {
            temp_r3 = (*(u8 **)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x40)))) + (0x138)));
            if (temp_r3 != NULL) {
                (*(u16 *)((u8 *)(temp_r3) + (0x148))) = (u16) ((*(u16 *)((u8 *)(temp_r3) + (0x148))) & 0xFFFFFFF7);
            }
        }
    }
}
}

extern "C" {

s32 fn_802054E0(s32);

void fn_8004E920() {
    fn_802054E0((s32) &fn_8004E92C);
}
}
