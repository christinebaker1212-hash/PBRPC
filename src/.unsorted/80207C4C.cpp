#include ".unsorted/80207C4C.hpp"

#include "common.hpp"

extern "C" {

s32 fn_8020AF84(void) {
    return 0;
}
}

extern "C" {

s32 fn_8020AA4C(s32, s32);
u8 *fn_8020AB20(u8 *arg0, s32 arg1);
s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;

s32 fn_8020AA4C(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        ((s32)fn_8020AB20((u8 *)(arg0), (s32)(0)));
        if (arg1 > 0) {
            freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_802079B4(s32, s32);
s32 fn_8020A994(s32);
__declspec(section ".data") extern s32 lbl_80423900;

u8 *fn_8020AB20(u8 *arg0, s32 arg1) {
    u8 *temp_r31;
    u8 *var_r5;

    if (arg0 != NULL) {
        var_r5 = (*(u8 **)((u8 *)(arg0) + (0xC)));
        (*(s32 **)((u8 *)(arg0) + (0x1C))) = &lbl_80423900;
        while (var_r5 != NULL) {
            temp_r31 = (*(u8 **)((u8 *)(var_r5) + (0x28)));
            fn_8020A994((s32) var_r5);
            var_r5 = temp_r31;
        }
        fn_802079B4((s32) arg0, 0);
        if (arg1 > 0) {
            freeToHeap__5GSmemFP12MEMiHeapHeadPv((s32)(gUnkHeap2), (s32)((s32) arg0));
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_80207B34(s32, s32);
s32 fn_802099CC(s32, s32, s32, f32);
s32 fn_8020A640(s32, s32);

void fn_8020AC3C(u8 *arg0, f32 farg0) {
    u8 *var_r31;
    u8 *temp_r30;

    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x18))) != 0) {
        var_r31 = (*(u8 **)((u8 *)(arg0) + (0x10)));
        while (var_r31 != NULL) {
            temp_r30 = (*(u8 **)((u8 *)(var_r31) + (0x28)));
            if (fn_802099CC((s32) var_r31, (*(s32 *)((u8 *)(arg0) + (0))), (*(s32 *)((u8 *)(arg0) + (0x20))), farg0) == 0) {
                fn_8020A640((s32) var_r31, (*(s32 *)((u8 *)(arg0) + (0x20))));
                fn_80207B34((s32) arg0, (s32) var_r31);
            }
            var_r31 = temp_r30;
        }
    }
}
}

extern "C" {

s32 fn_8020A4E0(s32, s32, s32);
s32 fn_8020ACD8(s32);
s32 fn_8020AE80(s32);

void fn_8020AD9C(s32 arg0, s32 arg1) {
    s32 var_r31;

    if (fn_8020ACD8(arg0) != 0) {
        fn_8020AE80(arg0);
        var_r31 = (*(s32 *)((u8 *)(arg0) + (0x10)));
        while (var_r31 != 0) {
            fn_8020A4E0(var_r31, arg1, (*(s32 *)((u8 *)(arg0) + (0x20))));
            var_r31 = (*(s32 *)((u8 *)(var_r31) + (0x28)));
        }
    }
}
}

extern "C" {

s32 fn_80207B8C(s32);

void fn_8020AE10(u8 *arg0) {
    u8 *temp_r31;
    u8 *var_r4;

    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x18))) != 0) {
        var_r4 = (*(u8 **)((u8 *)(arg0) + (0x10)));
        (*(u8 *)((u8 *)(arg0) + (0x18))) = 0U;
        while (var_r4 != NULL) {
            temp_r31 = (*(u8 **)((u8 *)(var_r4) + (0x28)));
            fn_8020A640((s32)((s32) var_r4), (s32)((*(s32 *)((u8 *)(arg0) + (0x20)))));
            var_r4 = temp_r31;
        }
        fn_80207B8C((s32) arg0);
    }
}
}

extern "C" {

void fn_8020AF8C(u8 *arg0, f32 farg0) {
    u8 *var_r31;
    u8 *temp_r30;

    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x18))) != 0) {
        var_r31 = (*(u8 **)((u8 *)(arg0) + (0x10)));
        while (var_r31 != NULL) {
            temp_r30 = (*(u8 **)((u8 *)(var_r31) + (0x28)));
            if (fn_802099CC((s32)((s32) var_r31), (s32)(0), (s32)((*(s32 *)((u8 *)(arg0) + (0x20)))), (f32)(farg0)) == 0) {
                fn_8020A640((s32)((s32) var_r31), (s32)((*(s32 *)((u8 *)(arg0) + (0x20)))));
                fn_80207B34((s32)((s32) arg0), (s32)((s32) var_r31));
            }
            var_r31 = temp_r30;
        }
    }
}
}
