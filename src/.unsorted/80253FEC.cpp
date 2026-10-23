#include ".unsorted/80253FEC.hpp"

#include "common.hpp"

extern "C" {

s32 __dl__FPv(void);

s32 fn_80253FEC(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

void fn_80254080(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4) {
    s32 temp_r8;
    s32 temp_r8_2;

    switch (arg3) {                                 /* irregular */
    case 1:
        temp_r8 = arg1 * 0xC0;
        (*(s32 *)((u8 *)(((*(s32 *)((u8 *)(arg0) + (8))) + temp_r8)) + (0x94))) = arg4;
        (*(s16 *)((u8 *)(arg2) + (8))) = -1;
        (*(s32 *)((u8 *)(((*(s32 *)((u8 *)(arg0) + (8))) + temp_r8)) + (0x98))) = -1;
        (*(u8 *)((u8 *)(arg2) + (4))) = 0xFF;
        (*(u8 *)((u8 *)(arg2) + (3))) = 0xFF;
        (*(u8 *)((u8 *)(arg2) + (2))) = 0xFF;
        return;
    case 2:
        temp_r8_2 = arg1 * 0xC0;
        (*(s32 *)((u8 *)(((*(s32 *)((u8 *)(arg0) + (8))) + temp_r8_2)) + (0x98))) = arg4;
        (*(s32 *)((u8 *)(((*(s32 *)((u8 *)(arg0) + (8))) + temp_r8_2)) + (0x94))) = 0;
        (*(s16 *)((u8 *)(arg2) + (8))) = -1;
        return;
    }
}
}

extern "C" {

void fn_80254188(s32 arg0, s32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    switch (arg3) {                                 /* irregular */
    case 1:
        (*(f32 *)((u8 *)(arg2) + (0x58))) = (f32) (*(f32 *)((u8 *)(arg4) + (0)));
        (*(f32 *)((u8 *)(arg2) + (0x5C))) = (f32) (*(f32 *)((u8 *)(arg4) + (4)));
        (*(f32 *)((u8 *)(arg2) + (0x60))) = (f32) (*(f32 *)((u8 *)(arg4) + (8)));
        (*(f32 *)((u8 *)(arg2) + (0x64))) = (f32) (*(f32 *)((u8 *)(arg4) + (0xC)));
        (*(f32 *)((u8 *)(arg2) + (0x68))) = (f32) (*(f32 *)((u8 *)(arg4) + (0x10)));
        (*(f32 *)((u8 *)(arg2) + (0x6C))) = (f32) (*(f32 *)((u8 *)(arg4) + (0x14)));
        (*(f32 *)((u8 *)(arg2) + (0x70))) = (f32) (*(f32 *)((u8 *)(arg4) + (0x18)));
        (*(f32 *)((u8 *)(arg2) + (0x74))) = (f32) (*(f32 *)((u8 *)(arg4) + (0x1C)));
        return;
    case 2:
        ((s32 (*)(s32, s32, s32, s32, s32))fn_80254080)(arg0, arg1, (s32) (arg2 + 0xC), 1, (s32) arg4);
        (*(u8 **)((u8 *)(arg2) + (0x84))) = arg4;
        (*(s32 *)((u8 *)(arg2) + (8))) = -1;
        (*(u8 *)((u8 *)(arg2) + (0x10))) = 0xFF;
        (*(u8 *)((u8 *)(arg2) + (0xF))) = 0xFF;
        (*(u8 *)((u8 *)(arg2) + (0xE))) = 0xFF;
        return;
    }
}
}
