
#include "common.hpp"

extern "C" {

void fn_802000B0(void) {}
void fn_802000B4(void) {}
void fn_802000B8(void) {}
}

extern "C" {

void fn_801FFBC0(u8 *arg0) {
    (*(f32 *)((u8 *)(arg0) + (0x30))) = (f32) (0.05f);
    (*(f32 *)((u8 *)(arg0) + (0x38))) = (f32) (8.0f);
    (*(f32 *)((u8 *)(arg0) + (0x34))) = (f32) (0.0f);
    (*(s8 *)((u8 *)(arg0) + (0x11))) = 0;
}
}
