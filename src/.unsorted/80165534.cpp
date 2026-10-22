#include ".unsorted/80165534.hpp"

#include "common.hpp"

extern "C" {

u8 *fn_80166AAC(u8 *p) {
    return p + 0x2;
}
u32 fn_80166AB4(u8 *p) {
    return *(u32 *)(p + 0x854);
}
u32 fn_80166ABC(u8 *p) {
    return *(u32 *)(p + 0x84c);
}
u32 fn_80166AC4(u8 *p) {
    return *(u32 *)(p + 0x858);
}
u32 fn_80166ACC(u8 *p) {
    return *(u32 *)(p + 0x85c);
}
void fn_80166C14(u8 *p, u32 v) {
    *(u32 *)(p + 0x1968) = v;
}
u32 fn_80166C1C(u8 *p) {
    return *(u32 *)(p + 0x1968);
}
void fn_80166D3C(u8 *p, u32 v) {
    *(u32 *)(p + 0x860) = v;
}
u32 fn_80166D44(u8 *p) {
    return *(u32 *)(p + 0x860);
}
}

#include "common.hpp"

extern "C" {

void fn_80166AA0(u8 *p) {
    *(u32 *)(p + 0x864) = 0x1;
}
BOOL fn_80166AF0(u8 *p) {
    return *(u32 *)(p + 0x1884) != 0;
}
}

extern "C" {

s32 fn_8016592C(u8 *arg0) {
    if (((s32) (*(s32 *)((u8 *)(arg0) + (0x1888))) != 0) && ((s32) (*(s32 *)((u8 *)(arg0) + (0x1890))) != 0) && ((s32) (*(s32 *)((u8 *)(arg0) + (0x1898))) != 0)) {
        return 1;
    }
    return 0;
}
}

extern "C" {

s32 fn_8016615C(s32);
s32 fn_80166210(s32);
s32 fn_80166630(s32);
s32 fn_8025DFD0(void);
s32 fn_8025E0A8(void);
s32 fn_8025E2B8(void);

void fn_801660D8(s32 arg0) {
    s32 temp_r3;

    fn_8025DFD0();
    if (fn_8025E2B8() != 0) {
        fn_8025DFD0();
        temp_r3 = fn_8025E0A8();
        switch (temp_r3) {                          /* irregular */
        case 1:
            fn_80166210(arg0);
            return;
        case 2:
            fn_8016615C(arg0);
            return;
        case 3:
            fn_80166630(arg0);
            break;
        }
    }
}
}

extern "C" {

s32 fn_80166AD4(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x1888))) != 0) {
        return (*(s32 *)((u8 *)(arg0) + (0x188C)));
    }
    return 0;
}
}

extern "C" {

s32 fn_80166B04(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x1898))) != 0) {
        return (*(s32 *)((u8 *)(arg0) + (0x189C)));
    }
    return 0;
}
}

extern "C" {

s32 fn_80166B20(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x18A0))) != 0) {
        return (*(s32 *)((u8 *)(arg0) + (0x18A4)));
    }
    return 0;
}
}

extern "C" {

s32 memset(u8 *, s32, s32);

void fn_80166C24(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0x18C4))) = 0;
    memset(arg0 + 0x18C8, 0, 0xC);
}
}

extern "C" {

u8 *fn_80166C78(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x18C4))) != 0) {
        return arg0 + 0x18C8;
    }
    return NULL;
}
}

extern "C" {

void fn_80166C94(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0x18D4))) = 0;
    memset(arg0 + 0x18D8, 0, 0x80);
}
}

extern "C" {

u8 *fn_80166CE8(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x18D4))) != 0) {
        return arg0 + 0x18D8;
    }
    return NULL;
}
}

extern "C" {

s32 fn_80166D20(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x187C))) != 0) {
        return (*(s32 *)((u8 *)(arg0) + (0x1880)));
    }
    return 0;
}
}
