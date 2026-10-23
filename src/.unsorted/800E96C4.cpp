#include ".unsorted/800E96C4.hpp"

#include "common.hpp"

extern "C" {

void fn_8005A44C();

void fn_800E96C4(void) {}
void fn_800ED1FC(void) {
    fn_8005A44C();
}
}

extern "C" {

s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap1;

void fn_800F8114(s32 arg0) {
    freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap1, arg0);
}
}

extern "C" {

s32 fn_800EEFE0(s32, s32);
s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_800EEFE0(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    if (sp8 != 4) {
        return temp_r3;
    }
    return fn_80253EB4(arg0, arg1, 2, 0x2DD0);
}
}

extern "C" {

s32 __dl__FPv(u8 *);
s32 fn_8023E2D0__9GStextureFv(s32);

u8 *fn_800E96C8(u8 *arg0, s32 arg1, s32 arg_sp0) {
    u8 *var_r30;
    s32 var_r29;

    if (arg0 != NULL) {
        var_r30 = arg0;
        var_r29 = 0;
        do {
            fn_8023E2D0__9GStextureFv((*(s32 *)((u8 *)(var_r30) + (0x18))));
            var_r29 += 1;
            (*(s32 *)((u8 *)(var_r30) + (0x18))) = 0;
            var_r30 += 4;
        } while (var_r29 < 4);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 allocFromHeap__5GSmemFP12MEMiHeapHeadUl(s32, s32);
s32 getCachedFileSize__7GScacheFUlUl(void);
s32 getCachedFile__7GScacheFUlUl(s32, s32);
s32 memcpy(s32, s32, s32);

s32 fn_800F8094(s32 arg0, s32 arg1) {
    s32 temp_r3;
    s32 temp_r30;

    temp_r3 = getCachedFileSize__7GScacheFUlUl();
    temp_r30 = allocFromHeap__5GSmemFP12MEMiHeapHeadUl(gUnkHeap1, (temp_r3 + 0x1F) & 0xFFFFFFE0);
    memcpy(temp_r30, getCachedFile__7GScacheFUlUl(arg0, arg1), temp_r3);
    return temp_r30;
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8047DAE0;

void fn_800ED9E8(s32 arg0, s32 arg1) {
    s32 sp8;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {
    case 1:
        if (((u16) (*(u16 *)((u8 *)(&lbl_8047DAE0) + (0xCE))) >> 1U) & 3) {
            fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2DBF));
            return;
        }
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x512E));
    }
    return;
}
}

extern "C" {

void fn_800EDA78(s32 arg0, s32 arg1) {
    s32 sp8;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 0x4:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2DC0));
        return;
    case 0x50:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2DC1));
        return;
    }
}
}
