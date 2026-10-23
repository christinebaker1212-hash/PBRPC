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

extern "C" {

struct S_lbl_80627648 { s8 f_0; u8 pad_1[1]; s16 f_2; s8 f_4; };
extern struct S_lbl_80627648 lbl_80627648;

void fn_801DF020() {
    lbl_80627648.f_0 = 1;
    lbl_80627648.f_2 = 4;
    lbl_80627648.f_4 = 0;
}
}
