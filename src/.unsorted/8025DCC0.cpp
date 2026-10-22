#include ".unsorted/8025DCC0.hpp"

#include "common.hpp"

extern "C" {

void fn_8025DD0C(u8 *p, u32 v) {
    *(u32 *)(p + 0x0) = v;
}
void fn_8025DD34(u8 *p, u16 v) {
    *(u16 *)(p + 0xa) = v;
}
void fn_8025DD3C(u8 *p, u16 v) {
    *(u16 *)(p + 0x8) = v;
}
}

extern "C" {

u16 fn_8025DD14(s32 *arg0) {
    s32 temp_r0;

    temp_r0 = (*arg0 * 0x41C64E6D) + 0x3039;
    *arg0 = temp_r0;
    return (u16) temp_r0;
}
}
