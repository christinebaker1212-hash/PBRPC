#include ".unsorted/8020B4F8.hpp"

#include "common.hpp"

extern "C" {

extern s32 lbl_8063F498;

s32 fn_8020C750(u8 *arg0) {
    s32 temp_r3;

    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x18))) == 0) {
        return 0;
    }
    if ((s32) (*(u16 *)((u8 *)(arg0) + (0x14))) == 0) {
        return 0;
    }
    temp_r3 = *(*(s32 **)((u8 *)(arg0) + (0x20)));
    if (temp_r3 & 0x20000) {
        return (lbl_8063F498 - 0xA) == 0;
    }
    if (temp_r3 & 0x40000) {
        return (lbl_8063F498 - 5) == 0;
    }
    return (lbl_8063F498 - 8) == 0;
}
}

extern "C" {

s32 fn_802079B4(s32, s32);
s32 fn_8020C9BC(s32, s32);
s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;

s32 fn_8020C9BC(s32 arg0, s32 arg1) {
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
s32 fn_8020B9A4(u8 *, s32, s32, f32);
void fn_8020C600(u8 *arg0, u8 *arg1);
s32 fn_8020C8B8(u8 *);

void fn_8020C6AC(u8 *arg0, f32 farg0) {
    u8 *var_r31;
    u8 *temp_r30;

    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x18))) != 0) {
        var_r31 = (*(u8 **)((u8 *)(arg0) + (0x10)));
        while (var_r31 != NULL) {
            temp_r30 = (*(u8 **)((u8 *)(var_r31) + (0x28)));
            if (fn_8020B9A4(var_r31, (*(s32 *)((u8 *)(arg0) + (0))), (*(s32 *)((u8 *)(arg0) + (0x20))), farg0) == 0) {
                fn_8020C600((u8 *)(var_r31), (u8 *)((*(s32 *)((u8 *)(arg0) + (0x20)))));
                fn_80207B34(arg0, var_r31);
            }
            var_r31 = temp_r30;
        }
        fn_8020C8B8(arg0);
    }
}
}

extern "C" {

s32 fn_80205278(s32);
s32 fn_8020C0B4(u8 *, s32, s32);
extern s8 lbl_8063F4B4;

void fn_8020C7CC(u8 *arg0, s32 arg1) {
    u8 *var_r31;

    if (((s32 (*)(void))fn_8020C750)() != 0) {
        var_r31 = (*(u8 **)((u8 *)(arg0) + (0x10)));
        while (var_r31 != NULL) {
            fn_8020C0B4(var_r31, arg1, (*(s32 *)((u8 *)(arg0) + (0x20))));
            var_r31 = (*(u8 **)((u8 *)(var_r31) + (0x28)));
        }
        fn_80205278(1);
        lbl_8063F4B4 = 1;
    }
}
}

extern "C" {

s32 fn_80207B8C(u8 *);

void fn_8020C848(u8 *arg0) {
    u8 *temp_r31;
    u8 *var_r4;

    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x18))) != 0) {
        var_r4 = (*(u8 **)((u8 *)(arg0) + (0x10)));
        (*(u8 *)((u8 *)(arg0) + (0x18))) = 0U;
        while (var_r4 != NULL) {
            temp_r31 = (*(u8 **)((u8 *)(var_r4) + (0x28)));
            fn_8020C600((u8 *)((u8 *)(var_r4)), (u8 *)((s32)((*(s32 *)((u8 *)(arg0) + (0x20))))));
            var_r4 = temp_r31;
        }
        fn_80207B8C(arg0);
    }
}
}

extern "C" {

s32 fn_8021C564(s32, s32);

void fn_8020C600(u8 *arg0, u8 *arg1) {
    if ((*(s32 *)((u8 *)(arg1) + (0))) & 1) {
        fn_8021C564((s32) (u16) ((*(s32 *)((u8 *)(arg1) + (0x58))) - 1), (s32) (*(s16 *)((u8 *)(arg0) + (0x58))));
    }
}
}
