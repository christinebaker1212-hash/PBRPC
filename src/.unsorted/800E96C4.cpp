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
