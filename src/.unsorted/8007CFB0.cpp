#include ".unsorted/8007CFB0.hpp"

#include "common.hpp"

extern "C" {

s32 fn_8007CFB0(void) {
    return 1;
}
void fn_8007F0A8(void) {}
}

extern "C" {

u8 *fn_8015F690(void);

void fn_8007D224(void) {
    u8 *temp_r3;

    temp_r3 = fn_8015F690();
    (*(s8 *)((u8 *)(temp_r3) + (0x43))) = 1;
    (*(s8 *)((u8 *)(temp_r3) + (0x44))) = 1;
    (*(s8 *)((u8 *)(temp_r3) + (0x45))) = 1;
    (*(s8 *)((u8 *)(temp_r3) + (0x41))) = 0;
    (*(s32 *)((u8 *)(temp_r3) + (0x48))) = 0;
    (*(s32 *)((u8 *)(temp_r3) + (0x4C))) = 0;
}
}

extern "C" {

void fn_8007D27C(void) {
    u8 *temp_r3;

    temp_r3 = fn_8015F690();
    (*(s8 *)((u8 *)(temp_r3) + (0x41))) = 0;
    (*(s32 *)((u8 *)(temp_r3) + (0x48))) = 0;
}
}
