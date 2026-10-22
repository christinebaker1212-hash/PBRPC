#include ".unsorted/80207C4C.hpp"

#include "common.hpp"

extern "C" {

s32 fn_8020AF84(void) {
    return 0;
}
}

extern "C" {

s32 fn_8020AA4C(s32, s32);
s32 fn_8020AB20(s32, s32);
s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;

s32 fn_8020AA4C(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8020AB20(arg0, 0);
        if (arg1 > 0) {
            freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, arg0);
        }
    }
    return arg0;
}
}
