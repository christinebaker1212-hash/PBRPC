#include ".unsorted/801581B8.hpp"

#include "common.hpp"

extern "C" {

BOOL fn_80158438(void) {
    return lbl_8063D5A0->_1C == 0xFF;
}
}

extern "C" {

s32 fn_8008A27C(void);
u32 fn_80162A90(s32);

void fn_80158644(void) {
    if (fn_80162A90(0x261) == 2U) {
        fn_8008A27C();
    }
}
}
