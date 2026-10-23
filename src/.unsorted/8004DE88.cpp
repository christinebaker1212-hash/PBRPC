#include ".unsorted/8004DE88.hpp"

#include "common.hpp"

extern "C" {

s32 __dl__FPv(s32);
void fn_8004DF78(u8 *arg0);

s32 fn_8004DEF8(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        ((s32 (*)(void))fn_8004DF78)();
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

extern "C" {

s32 decrementRefCount__7GScacheFUlUl(s32, s32);
s32 fn_80206DF4(s32);
s32 free__5GSmemFPv(s32);
struct VT_fn_8004DF78_0 { u8 pad[256];  virtual s32 v0(s32); };

void fn_8004DF78(u8 *arg0) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r4;
    u8 *temp_r0;

    temp_r0 = (*(u8 **)((u8 *)(arg0) + (0x40)));
    if (!(temp_r0 == NULL)) {
        if (!(temp_r0 == NULL)) {
            ((VT_fn_8004DF78_0 *)(temp_r0))->v0((s32)(1));
        }
        (*(u8 **)((u8 *)(arg0) + (0x40))) = NULL;
    }
    temp_r3 = (*(s32 *)((u8 *)(arg0) + (0x3C)));
    if (temp_r3 != 0) {
        temp_r4 = (*(s32 *)((u8 *)(arg0) + (0x34)));
        if (temp_r4 & 2) {
            (*(s32 *)((u8 *)(arg0) + (0x34))) = (s32) (temp_r4 & 0xFFFFFFFD);
            fn_80206DF4(temp_r3);
        }
    }
    temp_r3_2 = (*(s32 *)((u8 *)(arg0) + (0x38)));
    (*(s32 *)((u8 *)(arg0) + (0x3C))) = 0;
    if (temp_r3_2 != 0) {
        free__5GSmemFPv(temp_r3_2);
        (*(s32 *)((u8 *)(arg0) + (0x38))) = 0;
    }
    if ((*(s32 *)((u8 *)(arg0) + (0x34))) & 0x40) {
        decrementRefCount__7GScacheFUlUl((*(s32 *)((u8 *)(arg0) + (0x44))), (*(s32 *)((u8 *)(arg0) + (0x48))));
        (*(s32 *)((u8 *)(arg0) + (0x44))) = 0;
        (*(s32 *)((u8 *)(arg0) + (0x48))) = 0;
    }
    (*(s32 *)((u8 *)(arg0) + (0x34))) = 0;
}
}

extern "C" {

void fn_8004E504(u8 *arg0, u8 *arg1) {
    u8 *temp_r4;

    temp_r4 = (*(u8 **)((u8 *)(arg1) + (0x40)));
    if (temp_r4 != NULL) {
        (*(f32 *)((u8 *)(arg0) + (0))) = (f32) (*(f32 *)((u8 *)(temp_r4) + (0x20)));
        (*(f32 *)((u8 *)(arg0) + (4))) = (f32) (*(f32 *)((u8 *)(temp_r4) + (0x24)));
        (*(f32 *)((u8 *)(arg0) + (8))) = (f32) (*(f32 *)((u8 *)(temp_r4) + (0x28)));
        return;
    }
    (*(f32 *)((u8 *)(arg0) + (0))) = (f32) (0.0f);
    (*(f32 *)((u8 *)(arg0) + (4))) = (f32) (0.0f);
    (*(f32 *)((u8 *)(arg0) + (8))) = (f32) (0.0f);
}
}

extern "C" {

s32 markNeedsUpdate__6GSnullFb(s32, s32);
struct VT_fn_8004E5D4_0 { u8 pad[48];  virtual s32 v0(void); };

void fn_8004E5D4(u8 *arg0, f32 farg0) {
    s32 temp_r3_2;
    u8 *temp_r3;

    (*(f32 *)((u8 *)(arg0) + (0x4C))) = (f32) ((*(f32 *)((u8 *)(arg0) + (0x4C))) - farg0);
    if (((VT_fn_8004E5D4_0 *)(arg0))->v0() != 0) {
        temp_r3 = (*(u8 **)((u8 *)(arg0) + (0x40)));
        if (temp_r3 != NULL) {
            (*(f32 *)((u8 *)(temp_r3) + (0x20))) = (f32) (*(f32 *)((u8 *)(arg0) + (0x5C)));
            (*(f32 *)((u8 *)(temp_r3) + (0x24))) = (f32) (*(f32 *)((u8 *)(arg0) + (0x60)));
            (*(f32 *)((u8 *)(temp_r3) + (0x28))) = (f32) (*(f32 *)((u8 *)(arg0) + (0x64)));
            markNeedsUpdate__6GSnullFb((s32) temp_r3, 1);
        }
    }
    temp_r3_2 = (*(s32 *)((u8 *)(arg0) + (0x34)));
    if ((temp_r3_2 & 4) && (temp_r3_2 & 8) && ((*(f32 *)((u8 *)(arg0) + (0x4C))) < (0.0f))) {
        ((s32 (*)(s32))fn_8004DF78)((s32) arg0);
    }
}
}
