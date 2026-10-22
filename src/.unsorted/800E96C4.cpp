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
