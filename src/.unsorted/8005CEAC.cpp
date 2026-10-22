#include ".unsorted/8005CEAC.hpp"

#include "common.hpp"

extern "C" {

void fn_80062FF8(void) {}
void fn_80063510(void) {}
void fn_80064558(void) {}
void fn_80069668(void) {}
void fn_8006A74C(void) {}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_8005CEAC(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_8006A750(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0x3126;
    case 1:
        return 0x3127;
    default:
        return 0;
    }
}
}
