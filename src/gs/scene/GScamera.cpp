#include "common.hpp"

extern "C" {

s32 __dt__6GSnullFv(s32, s32);
s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gGameHeap;

s32 fn_801DE19C(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        __dt__6GSnullFv(arg0, 0);
        if (arg1 > 0) {
            freeToHeap__5GSmemFP12MEMiHeapHeadPv(gGameHeap, arg0);
        }
    }
    return arg0;
}
}
