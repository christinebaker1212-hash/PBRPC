#include ".unsorted/80167298.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80167298(s32, s32, s32);

s32 fn_80167298(s32 arg0, s32 arg1, s32 arg2) {
    return arg2;
}
}

extern "C" {

s32 fn_801673C4(s32, s32);

s32 fn_801673C4(s32 arg0, s32 arg1) {
    if ((u32) arg1 < 4U) {
        return arg1;
    }
    return 4;
}
}

extern "C" {

s32 fn_8016741C(s32, s32);

s32 fn_8016741C(s32 arg0, s32 arg1) {
    if ((u32) arg1 < 8U) {
        return arg1;
    }
    return 8;
}
}

extern "C" {

s32 fn_8016747C(s32, s32);

s32 fn_8016747C(s32 arg0, s32 arg1) {
    if ((u32) arg1 < 0x6ECU) {
        return arg1;
    }
    return 0x6EC;
}
}
