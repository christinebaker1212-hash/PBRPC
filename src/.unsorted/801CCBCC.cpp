#include "common.hpp"

extern "C" {

extern u32 lbl_8063D6A8;

s32 rand() {
    u32 temp_r0;

    temp_r0 = (lbl_8063D6A8 * 0x41C64E6D) + 0x3039;
    lbl_8063D6A8 = temp_r0;
    return (temp_r0 >> 0x10U) & 0x7FFF;
}
}

extern "C" {

void srand(s32 arg0) {
    lbl_8063D6A8 = arg0;
}
}
