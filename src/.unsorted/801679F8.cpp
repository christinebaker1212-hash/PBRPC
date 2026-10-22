#include ".unsorted/801679F8.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80164C6C(void);
s32 fn_80166C1C(void);
s32 fn_80167A30(void);

s32 fn_80167C4C(void) {
    if (fn_80167A30() < 0) {
        return 7;
    }
    if (fn_80164C6C() == 0) {
        return 7;
    }
    return fn_80166C1C();
}
}

extern "C" {

s32 fn_801679F8(s32, s32);
extern u8 lbl_8063F0E8;

s32 fn_801679F8(s32 arg0, s32 arg1) {
    if ((u32) arg0 >= 4U) {
        return -1;
    }
    if ((arg1 < 0) || (arg1 >= 8)) {
        return -1;
    }
    *(&lbl_8063F0E8 + arg0) = (s8) arg1;
    return 0;
}
}
