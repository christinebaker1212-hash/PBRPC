#include ".unsorted/8016E2B8.hpp"

#include "common.hpp"

extern "C" {

/* lbl_8048CDD8 */ extern s32 lbl_8048CDD8[4];
extern s32 lbl_8063F1CC;

void fn_8016E2DC(void) {
    fn_8016E2E4(1);
}

// TODO name: appends a value to a small list unless it is already there
void fn_8016E2E4(u32 value) {
    s32 i;
    for (i = 0; i < lbl_8063F1CC; i++) {
        if (lbl_8048CDD8[i] == (s32)value) {
            return;
        }
    }
    lbl_8048CDD8[lbl_8063F1CC++] = value;
}

s32 fn_8016E430(u8 i) {
    return lbl_8063F1C8->_10[i];
}
void fn_8016E444(s32 i) {
    lbl_8063F1C8->_78[i] = 1;
}

void fn_8016E458(s32 i) {
    lbl_8063F1C8->_7C[i] = 1;
    lbl_8063F1C8->_80[i] = 1;
}

u32 fn_8016E478(u8 i) {
    return lbl_8063F1C8->_00[i];
}
}

extern "C" {

s32 __dl__FPv(u8 *);
s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;

u8 *fn_8016E5C0(u8 *arg0, s32 arg1) {
    if (arg0 != NULL) {
        freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, (*(s32 *)((u8 *)(arg0) + (0x60))));
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8016E674(void);
s32 fn_803D9E08__Fv(void);

s32 fn_8016E674(void) {
    if (fn_803D9E08__Fv() != 0) {
        fn_8016E2E4((u32)(6));
        return 6;
    }
    return lbl_8063F1CC;
}
}
