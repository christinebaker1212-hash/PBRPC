#include ".unsorted/800478C0.hpp"

#include "common.hpp"

extern "C" {

void fn_8004819C(void) {}
}

extern "C" {

s32 __dl__FPv(s32);
s32 fn_80047AA8(void);

s32 fn_80047908(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_80047AA8();
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}
