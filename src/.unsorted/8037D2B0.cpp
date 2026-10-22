#include ".unsorted/8037D2B0.hpp"

#include "common.hpp"

extern "C" {

s32 __dl__FPv(s32);
s32 fn_8037D3B4(s32, s32);
s32 fn_8037F940(s32, s32);

s32 fn_8037D3B4(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8037F940(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8037D40C(s32, s32);

s32 fn_8037D40C(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8037F940(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}
