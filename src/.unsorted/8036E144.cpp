#include ".unsorted/8036E144.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_806404B0;

u32 *fn_8036E184(void) {
    return &lbl_806404B0;
}
void fn_8036E18C(void) {
    lbl_806404B0 = 0x0;
}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_8036E144(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}
