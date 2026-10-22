#include ".unsorted/800F8AC4.hpp"

#include "common.hpp"

extern "C" {

void fn_800F959C(void) {
    lbl_8063D530->_CC = 45;
}

void fn_800FD4D8(void) {}
void fn_800FE8E4(void) {}
void fn_800FEC90(void) {}
void fn_8010190C(void) {}
void fn_80101B30(void) {}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_800F8AC4(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_80101E58(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0xE8D;
    case 1:
        return 0xE90;
    default:
        return 0;
    }
}
}
