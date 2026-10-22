#include ".unsorted/80050324.hpp"

#include "common.hpp"

extern "C" {

void fn_800520B0(void) {}
void fn_8005376C(void) {}
void fn_80054154(void) {}
void fn_80054490(void) {}
void fn_80054494(void) {}
u32 fn_800547F4(u8 *p) {
    return *(u32 *)(p + 0x38);
}
u32 fn_8005498C(u8 *p) {
    return *(u32 *)(p + 0x40);
}
u32 fn_80055278(u8 *p) {
    return *(u32 *)(p + 0x3c);
}
s32 fn_80055474(void) {
    return 0;
}
}

#include "common.hpp"

extern "C" {

extern u8 lbl_8040AEA4[];

void fn_80050388(u8 *p) {
    *(u32 *)(p + 0x0) = 0x0;
}
void fn_800505C0(u8 *p) {
    *(u32 *)(p + 0x0) = 0x0;
}
void fn_80050BE0(u8 *p) {
    *(u32 *)(p + 0x0) = 0x0;
}
void fn_80052060(u8 *p) {
    *(u8 **)(p + 0x0) = lbl_8040AEA4;
}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_80051468(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_80051FB4(s32 arg0, u32 arg1) {
    if (arg1 >= 0x64U) {
        return 0;
    }
    return arg0 + (arg1 * 0x28) + 0x248;
}
}

extern "C" {

s32 fn_80052070(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_80253E10(s16, s32, f32);
extern f32 lbl_80640B10;

void fn_80054200(s16 arg0) {
    fn_80253E10(arg0, 4, lbl_80640B10);
}
}

extern "C" {

void fn_800574B0(void) {

}
}

extern "C" {

s32 fn_80053FE8(s32, s32);
s32 fn_8005A9F8(s32);
s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_80053FE8(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    if (sp8 != 2) {
        return temp_r3;
    }
    return fn_80253EB4(arg0, arg1, 1, fn_8005A9F8(0x1A));
}
}

extern "C" {

s32 fn_800540C4(s32, s32);
extern u32 lbl_8063EB2C;

s32 fn_800540C4(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 var_r3;

    var_r3 = fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    if (sp8 != 1) {
        return var_r3;
    }
    if (((u32) lbl_8063EB2C != 0x32U) && ((u32) lbl_8063EB2C != 0x33U) && ((u32) lbl_8063EB2C != 0x34U)) {
        (*(u8 *)((u8 *)(arg1) + (2))) = 0xFF;
        (*(u8 *)((u8 *)(arg1) + (3))) = 0xFF;
        (*(u8 *)((u8 *)(arg1) + (4))) = 0xFF;
        var_r3 = fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2E51));
    }
    return var_r3;
}
}

extern "C" {

s32 __ct__7GSsceneFP11GSsceneData(s32, s32);
s32 allocFromHeap__5GSmemFP12MEMiHeapHeadUl(s32, s32);
s32 fn_800547FC(s32);
s32 fn_80054914(s32);
s32 fn_801E34DC__FP11GSsceneDataUl(s32, s32);
s32 fn_80200858__17GShierarchyModuleFP8GSobject(s32);
s32 fn_80203810(s32);
s32 getCachedFile__7GScacheFUlUl(s32, s32);
s32 isInitialized__5GSmemFv(void);
s32 startAnimation__8GSobjectFUsUlffbbb(s32, s32, s32, s32, s32, s32, f32, f32);
extern s32 gGameHeap;
extern f32 lbl_80640AE8;
extern f32 lbl_80640AEC;

s32 fn_800547FC(s32 arg0) {
    s32 *temp_r4;
    s32 var_r3;

    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x2C))) != 0) {
        fn_80054914(arg0);
    }
    var_r3 = getCachedFile__7GScacheFUlUl(0x403, 0x273F0400);
    (*(s32 *)((u8 *)(arg0) + (0x58))) = var_r3;
    if (var_r3 != 0) {
        fn_801E34DC__FP11GSsceneDataUl(var_r3, var_r3);
        if (isInitialized__5GSmemFv() != 0) {
            var_r3 = allocFromHeap__5GSmemFP12MEMiHeapHeadUl(gGameHeap, 0x14);
        } else {
            var_r3 = 0;
        }
        if (var_r3 != 0) {
            var_r3 = __ct__7GSsceneFP11GSsceneData(var_r3, (*(s32 *)((u8 *)(arg0) + (0x58))));
        }
        (*(s32 *)((u8 *)(arg0) + (0x2C))) = var_r3;
        if (var_r3 != 0) {
            temp_r4 = (*(s32 **)((u8 *)(var_r3) + (4)));
            if (temp_r4 == NULL) {
                var_r3 = 0;
            } else if ((s32) (*(u16 *)((u8 *)((*(u8 **)((u8 *)(var_r3) + (0)))) + (0x18))) == 0) {
                var_r3 = 0;
            } else {
                var_r3 = *temp_r4;
            }
            (*(s32 *)((u8 *)(arg0) + (0x40))) = var_r3;
            if (var_r3 != 0) {
                fn_80203810(var_r3);
                fn_80200858__17GShierarchyModuleFP8GSobject((*(s32 *)((u8 *)(arg0) + (0x40))));
                var_r3 = startAnimation__8GSobjectFUsUlffbbb((*(s32 *)((u8 *)(arg0) + (0x40))), 0, 0, 0, 0, 0, lbl_80640AE8, lbl_80640AEC);
            }
        }
    }
    return var_r3;
}
}

extern "C" {

s32 __dt__7GSsceneFv(s32, s32);
s32 fn_801E37F0(s32);
s32 fn_80203950__FP8GSobject(s32);

s32 fn_80054914(s32 arg0) {
    s32 temp_r3;
    s32 var_r3;

    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x2C))) != 0) {
        temp_r3 = (*(s32 *)((u8 *)(arg0) + (0x40)));
        if (temp_r3 != 0) {
            fn_80203950__FP8GSobject(temp_r3);
            (*(s32 *)((u8 *)(arg0) + (0x40))) = 0;
        }
        __dt__7GSsceneFv((*(s32 *)((u8 *)(arg0) + (0x2C))), 1);
        (*(s32 *)((u8 *)(arg0) + (0x2C))) = 0;
    }
    var_r3 = (*(s32 *)((u8 *)(arg0) + (0x58)));
    if (var_r3 != 0) {
        var_r3 = fn_801E37F0(var_r3);
        (*(s32 *)((u8 *)(arg0) + (0x58))) = 0;
    }
    return var_r3;
}
}
