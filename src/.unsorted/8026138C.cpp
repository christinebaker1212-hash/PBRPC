#include ".unsorted/8026138C.hpp"

#include "common.hpp"

extern "C" {

void fn_802F1CD4();

s32 fn_8026138C(void) {
    return 200;
}
s32 fn_80261394(void) {
    return 5;
}
s32 fn_8026139C(void) {
    return 1;
}
void fn_802615A0(u8 *p, u32 v) {
    *(u32 *)(p + 0x1000) = v;
}
u32 fn_802615A8(u8 *p) {
    return *(u32 *)(p + 0xfc4);
}
s32 fn_802624C4(void) {
    return 0;
}
void fn_80262548(u8 *p, u32 v) {
    *(u32 *)(p + 0x1004) = v;
}
u32 fn_802625C8(u8 *p) {
    return *(u32 *)(p + 0xfac);
}
void fn_802625E0(void) {
    fn_802F1CD4();
}
u32 fn_80262790(u8 *p) {
    return *(u32 *)(p + 0xfe4);
}
u32 fn_8026283C(u8 *p) {
    return *(u32 *)(p + 0xf04);
}
s32 fn_80262844(void) {
    return 0;
}
}

#include "common.hpp"

extern "C" {

void fn_8025E6C0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

BOOL fn_802615B0(u8 *p) {
    return *(u32 *)(p + 0xfac) != 0;
}
void fn_80262734(u8 *p, u32 x, u32 y) {
    *(u32 *)(p + 0xff0) = x;
    *(u32 *)(p + 0xfec) = y;
}
void fn_80262740(u8 *p) {
    *(u32 *)(p + 0xfe4) = 0x1;
}
void fn_80262798(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_8025E6C0(*(u32 *)(a0 + 0xfec), a1, a2, a3, a4, a5, a6, a7);
}
}

extern "C" {

s32 memset(u8 *, s32, s32);

void fn_802613A4(u8 *arg0) {
    (*(s16 *)((u8 *)(arg0) + (0xF08))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0xF0A))) = 0;
    memset(arg0 + 0xF0C, 0, 0x60);
    (*(s32 *)((u8 *)(arg0) + (0xF04))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0xF04))) + 1);
}
}

extern "C" {

void fn_802625D0(u8 *arg0, s32 arg1);
s32 fn_802627A0(void);
s32 fn_80262B00(void);
s32 fn_80262B04(void);

void fn_802615DC(u8 *arg0) {
    s32 temp_r4;

    temp_r4 = (*(s32 *)((u8 *)(arg0) + (0xFB4)));
    switch (temp_r4) {                              /* irregular */
    case 0:
        fn_80262B00();
        (*(s32 *)((u8 *)(arg0) + (0xFB4))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0xFB4))) + 1);
        return;
    case 1:
        (*(s32 *)((u8 *)(arg0) + (0xFB4))) = (s32) (temp_r4 + 1);
        return;
    case 2:
        fn_80262B04();
        (*(s32 *)((u8 *)(arg0) + (0xFB4))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0xFB4))) + 1);
        return;
    case 3:
        (*(s32 *)((u8 *)(arg0) + (0xFB4))) = (s32) (temp_r4 + 1);
        return;
    case 4:
        fn_802627A0();
        fn_802625D0((u8 *)(arg0), (s32)(3));
        return;
    }
}
}

extern "C" {

s32 fn_8026182C(u8 *arg0, u32 arg1);

void fn_80261754(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xFC4))) == 0) {
        (*(s32 *)((u8 *)(arg0) + (0xFDC))) = 1;
    }
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xFDC))) != 0) {
        (*(s32 *)((u8 *)(arg0) + (0xFDC))) = 0;
        fn_802625D0((u8 *)(arg0), (s32)(2));
        return;
    }
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xFE0))) != 0) {
        (*(s32 *)((u8 *)(arg0) + (0xFE0))) = 0;
    }
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xFCC))) != 0) {
        fn_8026182C((u8 *)(arg0), (u32)((*(u8 *)((u8 *)(arg0) + (0xF02)))));
    }
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xFD0))) != 0) {
        (*(s32 *)((u8 *)(arg0) + (0xFD0))) = 0;
        fn_802625D0((u8 *)(arg0), (s32)(5));
    }
}
}

extern "C" {

void fn_80261ADC(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xFD8))) == 0) {
        (*(s32 *)((u8 *)(arg0) + (0xFD4))) = 1;
    }
}
}

extern "C" {

s32 fn_80262398(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xFC4))) != 0) {
        return -1;
    }
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xFE4))) != 0) {
        return -1;
    }
    (*(s32 *)((u8 *)(arg0) + (0xFC4))) = 1;
    return 0;
}
}

extern "C" {

s32 fn_802624B0(u8 *arg0) {
    return ((*(s32 *)((u8 *)(arg0) + (0xFAC))) - 6) == 0;
}
}

extern "C" {

s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(void);

s32 fn_80262550(u8 *arg0, s32 arg1, s32 arg2) {
    OSDisableInterrupts();
    (*(s32 *)((u8 *)(arg0) + (0x1008))) = 0;
    if (arg1 == 0) {
        (*(s32 *)((u8 *)(arg0) + (0x1008))) = 0;
        (*(s32 *)((u8 *)(arg0) + (0x100C))) = 0;
        (*(s32 *)((u8 *)(arg0) + (0x1010))) = 0;
    } else {
        (*(s32 *)((u8 *)(arg0) + (0x1008))) = 0;
        (*(s32 *)((u8 *)(arg0) + (0x100C))) = arg1;
        (*(s32 *)((u8 *)(arg0) + (0x1010))) = arg2;
    }
    OSRestoreInterrupts();
    return 0;
}
}

extern "C" {

s32 fn_80262710(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xFC8))) == 0) {
        return -1;
    }
    (*(s32 *)((u8 *)(arg0) + (0xFC8))) = 0;
    return 0;
}
}

extern "C" {

void fn_8026274C(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0xFFC))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xFF8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xFEC))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xFF0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xFF4))) = 0;
}
}

extern "C" {

s32 fn_80262768(u8 *arg0) {
    s32 var_r4;

    var_r4 = 0;
    if (((s32) (*(s32 *)((u8 *)(arg0) + (0xFEC))) != 0) || ((s32) (*(s32 *)((u8 *)(arg0) + (0xFE4))) != 0)) {
        var_r4 = 1;
    }
    return var_r4;
}
}

extern "C" {

s32 fn_8025EE18(s32);
s32 fn_8025F07C(void);

void fn_802627D4(s32 arg0) {
    fn_8025F07C();
    fn_8025EE18(arg0);
}
}

extern "C" {

s32 fn_802624CC(s32, s32);

s32 fn_802624CC(s32 arg0, s32 arg1) {
    if (fn_802624B0((u8 *)(arg0)) != 0) {
        if (arg1 == 0) {
            if ((s32) (*(u16 *)((u8 *)(arg0) + (0xF0A))) != 0) {
                return 1;
            }
            goto block_6;
        }
        if ((*(u16 *)((u8 *)(arg0) + (0xF0A))) & (1 << arg1)) {
            return 1;
        }
        goto block_6;
    }
block_6:
    return 0;
}
}

extern "C" {

s32 fn_8026284C(s32);

s32 fn_8026284C(s32 arg0) {
    s32 temp_r3;

    if (fn_802624B0((u8 *)(arg0)) != 0) {
        return 0x90;
    }
    temp_r3 = ((s32 (*)(s32))fn_802624C4)(arg0);
    return ((s32) (-temp_r3 | temp_r3) >> 0x1F) & 0x50;
}
}

extern "C" {

void fn_80262808(s32 arg0);

void fn_802616E4(u8 *arg0) {
    if (((s32) (*(s32 *)((u8 *)(arg0) + (0xFC4))) != 0) && ((s32) (*(s32 *)((u8 *)(arg0) + (0xFDC))) != 0)) {
        (*(s32 *)((u8 *)(arg0) + (0xFDC))) = 0;
    }
    (*(s32 *)((u8 *)(arg0) + (0xFE0))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0xF00))) = 0;
    ((s32 (*)(u8 *))fn_802613A4)(arg0);
    fn_80262808((s32)(arg0));
    fn_802625D0((u8 *)((u8 *)(arg0)), (s32)((s32)(4)));
}
}

extern "C" {

s32 fn_8026182C(u8 *arg0, u32 arg1) {
    s32 temp_r0;

    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xFD0))) != 0) {
        return -1;
    }
    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0xFAC)));
    if ((temp_r0 >= 5) || (temp_r0 < 3)) {
        return -1;
    }
    if ((arg1 < 1U) || (arg1 > 0x10U)) {
        return -1;
    }
    (*(s32 *)((u8 *)(arg0) + (0xFD0))) = 1;
    (*(s8 *)((u8 *)(arg0) + (0xF03))) = (s8) (arg1 - 1);
    return 0;
}
}

extern "C" {

void fn_802625D0(u8 *arg0, s32 arg1) {
    (*(s32 *)((u8 *)(arg0) + (0xFAC))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (0xFB4))) = 0;
}
}

extern "C" {

void fn_80262808(s32 arg0) {
    ((s32 (*)(void))fn_8025EE18)();
    ((s32 (*)(s32))fn_8025F07C)(arg0);
}
}
