#include ".unsorted/80205954.hpp"

#include "common.hpp"

extern "C" {

s32 __dl__FPv(void);

s32 fn_802072DC(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_80207864(void);
s32 fn_802093CC(s32);

void fn_802077D8(s32 arg0) {
    if (fn_80207864() != 0) {
        fn_802093CC(arg0 + 8);
    }
}
}

extern "C" {

extern f32 lbl_80641F68;

f32 fn_80207814(u8 *arg0) {
    if (arg0 == NULL) {
        return lbl_80641F68;
    }
    if ((*(u16 *)((u8 *)(arg0) + (0x148))) & 1) {
        return (*(f32 *)((u8 *)(arg0) + (0xC)));
    }
    return lbl_80641F68;
}
}

extern "C" {

f32 fn_80207840(u8 *arg0) {
    u8 *temp_r3;

    if ((arg0 == NULL) || (temp_r3 = (*(u8 **)((u8 *)(arg0) + (0x104))), ((temp_r3 == NULL) != 0))) {
        return lbl_80641F68;
    }
    return (*(f32 *)((u8 *)(temp_r3) + (0x2C)));
}
}
