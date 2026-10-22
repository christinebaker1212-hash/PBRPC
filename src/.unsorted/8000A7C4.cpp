#include ".unsorted/8000A7C4.hpp"

#include "common.hpp"

extern "C" {

extern u8 lbl_80405F20[];

void fn_8000A810(void) {}
void fn_8000A9B4(void) {}
s32 fn_8000AA80(void) {
    return 0;
}
s32 fn_8000AA88(void) {
    return 0;
}
void fn_8000AA90(void) {}
void fn_8000AA94(void) {}
u8 *fn_8000AA98(void) {
    return lbl_80405F20;
}
}

extern "C" {

s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;

void fn_8000A7C4(s32 arg0) {
    freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, arg0);
}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_8000A7D0(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 __nw__FUl(s32);
s32 fn_8000AA04(void);
extern s32 lbl_8063E940;
extern s32 lbl_8063F640;

void fn_8000A9B8(void) {
    s32 var_r3;

    if (((s32) lbl_8063F640 != 0) && ((s32) lbl_8063E940 == 0)) {
        var_r3 = __nw__FUl(4);
        if (var_r3 != 0) {
            var_r3 = fn_8000AA04();
        }
        lbl_8063E940 = var_r3;
    }
}
}
