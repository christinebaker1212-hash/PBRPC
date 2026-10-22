#include ".unsorted/8008A2D4.hpp"

#include "common.hpp"

extern "C" {

BOOL fn_8008AA14(void) {
    return lbl_8063ED90->_14 == 8;
}
}

extern "C" {

s32 fn_8008A5D4(void);

s32 fn_8008A9D8(void) {
    s32 temp_r3;

    temp_r3 = fn_8008A5D4();
    if ((temp_r3 >= 0xE) && (temp_r3 <= 0x10)) {
        return 1;
    }
    return 0;
}
}

extern "C" {

s32 fn_8008B678(u32 arg0, u32 arg1, f32 *arg2) {
    f32 temp_f1;

    if (arg0 != arg1) {
        temp_f1 = (f32) arg1 / (f32) arg0;
        if (*arg2 > temp_f1) {
            *arg2 = temp_f1;
            return 1;
        }
    }
    return 0;
}
}
