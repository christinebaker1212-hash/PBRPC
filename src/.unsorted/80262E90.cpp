#include ".unsorted/80262E90.hpp"

#include "common.hpp"

extern "C" {

void fn_802F1CD4();

s32 fn_80262E90(void) {
    return 200;
}
s32 fn_80262E98(void) {
    return 5;
}
s32 fn_80262EA0(void) {
    return 1;
}
s32 fn_80262EB0(void) {
    return 0;
}
void fn_80262F50(void) {
    fn_802F1CD4();
}
u32 fn_80262F54(u8 *p) {
    return *(u32 *)(p + 0xf0c);
}
s32 fn_80262F84(void) {
    return 0;
}
s32 fn_80262F8C(void) {
    return 0;
}
u32 fn_80263048(u8 *p) {
    return *(u32 *)(p + 0xf00);
}
u32 fn_802631FC(u8 *p) {
    return *(u32 *)(p + 0xf30);
}
s32 fn_802638FC(void) {
    return 0;
}
s32 fn_80263904(void) {
    return 0;
}
s32 fn_8026390C(void) {
    return -1;
}
s32 fn_80263914(void) {
    return -1;
}
}

#include "common.hpp"

extern "C" {

void fn_8025E518(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

void fn_80262EA8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_8025E518(*(u32 *)(a0 + 0xf40), a1, a2, a3, a4, a5, a6, a7);
}
BOOL fn_80262F5C(u8 *p) {
    return *(u32 *)(p + 0xf00) != 0;
}
void fn_802631AC(u8 *p, u32 x, u32 y) {
    *(u32 *)(p + 0xf3c) = x;
    *(u32 *)(p + 0xf40) = y;
}
void fn_802631B8(u8 *p) {
    *(u32 *)(p + 0xf30) = 0x1;
}
}

extern "C" {

s32 fn_80262EB8(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xF0C))) != 0) {
        return -1;
    }
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xF30))) != 0) {
        return -1;
    }
    (*(s32 *)((u8 *)(arg0) + (0xF0C))) = 1;
    return 0;
}
}

extern "C" {

s32 fn_80262F70(u8 *arg0) {
    return ((*(s32 *)((u8 *)(arg0) + (0xF00))) - 2) == 0;
}
}

extern "C" {

void fn_80263050(u8 *arg0, s32 arg1) {
    (*(s32 *)((u8 *)(arg0) + (0xF00))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (0xF08))) = 0;
}
}

extern "C" {

s32 fn_80263188(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xF18))) == 0) {
        return -1;
    }
    (*(s32 *)((u8 *)(arg0) + (0xF18))) = 0;
    return 0;
}
}

extern "C" {

void fn_802631C4(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0xF40))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xF3C))) = 0;
}
}

extern "C" {

s32 fn_802631D4(u8 *arg0) {
    s32 var_r4;

    var_r4 = 0;
    if (((s32) (*(s32 *)((u8 *)(arg0) + (0xF40))) != 0) || ((s32) (*(s32 *)((u8 *)(arg0) + (0xF30))) != 0)) {
        var_r4 = 1;
    }
    return var_r4;
}
}

extern "C" {

s32 fn_8025E3D4(void);

s32 fn_80263674(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xF2C))) == 0) {
        return -1;
    }
    return fn_8025E3D4() - (*(s32 *)((u8 *)(arg0) + (0xF2C)));
}
}

extern "C" {

s32 fn_8026391C(void);

s32 fn_80263A44(void) {
    return fn_8026391C() != 0;
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_80425B80;

void fn_8026321C(u8 *arg0, s32 arg1) {
    (*(s32 *)((u8 *)(arg0) + (0xF44))) = arg1;
    (*(s32 *)((u8 *)(&lbl_80425B80) + (0xC))) = arg1;
}
}

extern "C" {

void fn_80263204(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xF0C))) != 0) {
        ((s32 (*)(s32, s32))fn_80263050)((s32) arg0, 1);
    }
}
}

extern "C" {

void fn_802637D4(u8 *arg0) {
    s32 temp_r0;

    if ((s32) (*(s32 *)((u8 *)(arg0) + (0xF18))) == 0) {
        temp_r0 = (*(s32 *)((u8 *)(arg0) + (0xF34)));
        switch (temp_r0) {                          /* irregular */
        case 3:
        case 5:
            break;
        case 1:
            (*(s32 *)((u8 *)(arg0) + (0xF0C))) = 0;
            ((s32 (*)(s32, s32))fn_80263050)((s32) arg0, 4);
            break;
        case 4:
            ((s32 (*)(s32, s32))fn_80263050)((s32) arg0, 0);
            break;
        case 2:
            (*(s32 *)((u8 *)(arg0) + (0xF0C))) = 0;
            ((s32 (*)(s32, s32))fn_80263050)((s32) arg0, 4);
            break;
        }
        ((s32 (*)(s32))fn_802631C4)((s32) arg0);
    }
}
}

extern "C" {

s32 fn_802F4B30(s32, s32);
s32 fn_802F4C20(void);
s32 fn_802F4CF8(void);

s32 fn_80263870(u8 *arg0) {
    s32 sp8[8];
    s32 temp_r30;
    s32 temp_r3;

    temp_r30 = fn_802F4CF8();
    temp_r3 = fn_802F4C20();
    if (((u32) (*(u32 *)((u8 *)(arg0) + (0xF20))) != (u32) temp_r30) || ((u32) (*(u32 *)((u8 *)(arg0) + (0xF24))) != (u32) temp_r3)) {
        fn_802F4C20();
        fn_802F4CF8();
        fn_802F4B30(1, (s32) sp8);
        (*(s32 *)((u8 *)(arg0) + (0xF28))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0xF28))) + 1);
    }
    (*(u32 *)((u8 *)(arg0) + (0xF20))) = (u32) temp_r30;
    (*(u32 *)((u8 *)(arg0) + (0xF24))) = (u32) temp_r3;
    return (*(s32 *)((u8 *)(arg0) + (0xF28)));
}
}
