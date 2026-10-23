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

void fn_8016615C(u8 *arg0);
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
            fn_8016615C((u8 *)(arg0));
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

extern "C" {

s32 fn_80165894(s32, s32);
s32 fn_80165960(s32);
s32 fn_8025DFC0(s32, s32);
extern s32 lbl_8063F0C0;

s32 fn_80165894(s32 arg0, s32 arg1) {
    (*(s32 *)((u8 *)(arg0) + (0x188C))) = fn_8025DFC0(fn_8025DFD0(), 0x3E0);
    (*(s32 *)((u8 *)(arg0) + (0x1894))) = fn_8025DFC0(fn_8025DFD0(), 0x774);
    (*(s32 *)((u8 *)(arg0) + (0x189C))) = fn_8025DFC0(fn_8025DFD0(), 0x20);
    (*(s32 *)((u8 *)(arg0) + (0x1880))) = fn_8025DFC0(fn_8025DFD0(), 0x6EC);
    if ((s32) lbl_8063F0C0 == 0) {
        lbl_8063F0C0 = fn_8025DFC0(fn_8025DFD0(), 0x121B0);
    }
    (*(s32 *)((u8 *)(arg0) + (0x18A4))) = (s32) lbl_8063F0C0;
    return fn_80165960(arg0);
}
}

extern "C" {

s32 fn_80165B24(s32);
s32 fn_8025DFC8(s32, s32);
s32 fn_802604F8(s32, s32);

s32 fn_80165B24(s32 arg0) {
    s32 temp_r30;
    s32 temp_r31;
    s32 var_r3;

    var_r3 = arg0;
    temp_r30 = var_r3;
    if ((s32) (*(s32 *)((u8 *)(var_r3) + (0x874))) != 0) {
        var_r3 = ((s32 (*)(s32))fn_8025E2B8)(fn_8025DFD0());
        if (var_r3 != 0) {
            var_r3 = fn_802604F8(var_r3, (s32) (u16) (*(s32 *)((u8 *)(temp_r30) + (0x874))));
        }
        (*(s32 *)((u8 *)(temp_r30) + (0x874))) = 0;
    }
    temp_r31 = (*(s32 *)((u8 *)(temp_r30) + (0x878)));
    if (temp_r31 != 0) {
        var_r3 = fn_8025DFC8(fn_8025DFD0(), temp_r31);
    }
    (*(s32 *)((u8 *)(temp_r30) + (0x878))) = 0;
    return var_r3;
}
}

extern "C" {

s32 fn_80166C3C(s32, s32);
s32 memcpy(s32, s32, s32);

s32 fn_80166C3C(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = memcpy(arg0 + 0x18C8, arg1, 0xC);
    (*(s32 *)((u8 *)(arg0) + (0x18C4))) = 1;
    return temp_r3;
}
}

extern "C" {

s32 fn_80166CAC(s32, s32);

s32 fn_80166CAC(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = memcpy((s32)(arg0 + 0x18D8), (s32)(arg1), (s32)(0x80));
    (*(s32 *)((u8 *)(arg0) + (0x18D4))) = 1;
    return temp_r3;
}
}

extern "C" {

s32 fn_80166D14(s32, s32);

s32 fn_80166D14(s32 arg0, s32 arg1) {
    return memcpy((s32)(arg0 + 0x1958), (s32)(arg1), (s32)(0x10));
}
}

extern "C" {

void fn_80166D04(s32 arg0) {
    memset((u8 *)(arg0 + 0x1958), (s32)(0), (s32)(0x10));
}
}

extern "C" {

s32 fn_80162B70(void);
s32 fn_80164D04(void);
s32 fn_80165534(s32);
s32 fn_801657F0(s32);
s32 fn_8025E314(s32);
s32 fn_80262FEC(s32, s32);

void fn_8016615C(u8 *arg0) {
    u16 temp_r0;

    temp_r0 = (*(u16 *)((u8 *)(arg0) + (0x86C)));
    switch ((s32) temp_r0) {                        /* irregular */
    case 0:
        if (fn_80162B70() == 1) {
            if (fn_80262FEC(fn_8025E314(fn_8025DFD0()), (s32) (*(u16 *)((u8 *)(arg0) + (0)))) != 0) {
                memcpy((s32)((s32)((*(u8 **)((u8 *)(arg0) + (0x189C))))), (s32)((s32)(fn_80165534((s32) (arg0 + 2)) + 0xC)), (s32)((s32)(0x20U)));
            } else {
                fn_801657F0((s32) (arg0 + 2));
            }
            (*(s32 *)((u8 *)(arg0) + (0x1898))) = 1;
        }
        if (fn_80162B70() == 2) {
            fn_80164D04();
        }
        (*(u16 *)((u8 *)(arg0) + (0x86C))) = (u16) ((*(u16 *)((u8 *)(arg0) + (0x86C))) + 1);
        /* fallthrough */
    case 1:
        return;
    }
}
}

extern "C" {

s32 fn_80163B30(s32);
s32 fn_80164824(s32, s32, s32, s32);
__declspec(section ".data") extern s32 lbl_8041F364;

void fn_80166B3C(u16 *arg0) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80163B30((s32) *arg0);
    sp8 = 0;
    if (!(temp_r3 < 0)) {
        fn_80164824(temp_r3, (s32) &lbl_8041F364, (s32) &sp8, 4);
    }
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8041F370;

void fn_80166B84(u16 *arg0) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80163B30((s32)((s32) *arg0));
    sp8 = 0;
    if (!(temp_r3 < 0)) {
        fn_80164824((s32)(temp_r3), (s32)((s32) &lbl_8041F370), (s32)((s32) &sp8), (s32)(4));
    }
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8041F37C;

void fn_80166BCC(u16 *arg0) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80163B30((s32)((s32) *arg0));
    sp8 = 0;
    if (!(temp_r3 < 0)) {
        fn_80164824((s32)(temp_r3), (s32)((s32) &lbl_8041F37C), (s32)((s32) &sp8), (s32)(4));
    }
}
}
