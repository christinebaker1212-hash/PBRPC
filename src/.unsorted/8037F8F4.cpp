#include ".unsorted/8037F8F4.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_80640548;

u32 *fn_8037F8F4(void) {
    return &lbl_80640548;
}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_8037F940(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}
