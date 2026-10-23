#include ".unsorted/80162784.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80162934(s32);
s32 fn_80162940(s32, s32, s32);

s32 fn_80162934(s32 arg0) {
    return fn_80162940(arg0, 1, 1);
}
}

extern "C" {

s32 fn_80162784(s32 arg0) {
    return 0x20 - __cntlzw(arg0);
}
}
