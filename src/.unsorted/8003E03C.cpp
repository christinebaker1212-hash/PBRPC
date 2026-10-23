#include ".unsorted/8003E03C.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063EA80;

void fn_8003E158(void) {}
u32 fn_8003E15C(void) {
    return lbl_8063EA80;
}
u32 fn_8003E42C(u8 *p) {
    return *(u32 *)(p + 0xc);
}
}

extern "C" {

s32 fn_8003E544(s32, s32, s32, s32);
s32 fn_8003E610(s32, s32);
s32 fn_80391200(s32, s32);

s32 fn_8003E610(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_8003E544(arg0, arg1, 0, 0xFF);
    if (temp_r3 >= 0) {
        return fn_80391200((*(s32 *)((u8 *)(arg0) + (4))), temp_r3);
    }
    return -1;
}
}

extern "C" {

s32 fn_8003E698(s32, s32, s32, s32);
s32 fn_80391318(s32, s32);

s32 fn_8003E698(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    temp_r3 = fn_8003E544((s32)(arg0), (s32)(arg1), (s32)(arg2), (s32)(arg3));
    if (temp_r3 >= 0) {
        return fn_80391318((*(s32 *)((u8 *)(arg0) + (4))), temp_r3);
    }
    return 0;
}
}

extern "C" {

s32 fn_8003E6E0(s32, s32, s32, s32, s32);
s32 fn_8039134C(s32, s32);
s32 fn_80391380(s32, s32);

s32 fn_8003E6E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r3;

    temp_r3 = fn_8003E544((s32)(arg0), (s32)(arg1), (s32)(arg3), (s32)(arg4));
    if (temp_r3 >= 0) {
        if (arg2 != 0) {
            return fn_80391380((*(s32 *)((u8 *)(arg0) + (4))), temp_r3);
        }
        return fn_8039134C((*(s32 *)((u8 *)(arg0) + (4))), temp_r3);
    }
    return 0;
}
}

extern "C" {

s32 fn_8000739C__Fv(void);
void fn_8003E4B8(u8 *arg0, f32 farg0);

void fn_8003E124(void) {
    if ((s32) lbl_8063EA80 != 0) {
        fn_8000739C__Fv();
        ((s32 (*)(s32))fn_8003E4B8)(lbl_8063EA80);
    }
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 __nw__FUl(s32);
u8 *fn_8003E164(u8 *arg0);
s32 fn_8023EB58(s32, s32, s32, s32, s32);
extern s32 lbl_8063F778;

void fn_8003E03C() {
    s32 var_r3;

    if ((s32) lbl_8063EA80 != 0) {
        __dl__FPv(lbl_8063EA80);
    }
    var_r3 = __nw__FUl(0x90);
    if (var_r3 != 0) {
        var_r3 = ((s32)fn_8003E164((u8 *)(var_r3)));
    }
    lbl_8063EA80 = var_r3;
    fn_8023EB58(lbl_8063F778, (s32) &fn_8003E124, (s32) &fn_8003E158, 3, 0xC);
}
}

extern "C" {

s32 fn_8003753C(s32, s32);

void fn_8003E0A0() {
    s32 var_r30;
    s32 var_r29;
    s32 temp_r3;

    if ((s32) lbl_8063EA80 != 0) {
        var_r29 = 0;
        var_r30 = 0;
        do {
            temp_r3 = (*(s32 *)((u8 *)((lbl_8063EA80 + var_r30)) + (0x10)));
            if (temp_r3 != 0) {
                fn_8003753C(temp_r3, 1);
                (*(s32 *)((u8 *)((lbl_8063EA80 + var_r30)) + (0x10))) = 0;
            }
            var_r29 += 1;
            var_r30 += 4;
        } while (var_r29 < 0x20);
    }
}
}

extern "C" {

s32 fn_803912C4(s32, s32, s32);

u8 fn_8003E7C4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r3;
    s32 var_r31;
    s32 var_r4;

    var_r31 = arg2;
    if (arg2 < 0) {
        var_r31 = 0;
    }
    temp_r3 = fn_8003E544((s32)(arg0), (s32)(arg1), (s32)(arg3), (s32)(arg4));
    var_r4 = temp_r3;
    if (temp_r3 < 0) {
        var_r4 = 0;
    }
    return fn_803912C4((*(s32 *)((u8 *)(arg0) + (4))), var_r4, var_r31);
}
}

extern "C" {

s32 fn_8003B8D4(s32, f32);
s32 fn_8003E238(s32, s32);

void fn_8003E4B8(u8 *arg0, f32 farg0) {
    u8 *var_r31;
    s32 var_r30;
    s32 *temp_r4;

    var_r30 = 0;
    var_r31 = arg0;
    do {
        temp_r4 = (*(s32 **)((u8 *)(var_r31) + (0x10)));
        if (temp_r4 != NULL) {
            if (*temp_r4 & 0x100) {
                fn_8003E238((s32) arg0, (s32) temp_r4);
            } else {
                fn_8003B8D4((s32) temp_r4, farg0);
            }
        }
        var_r30 += 1;
        var_r31 += 4;
    } while (var_r30 < 0x20);
}
}

extern "C" {

s32 memset(s32, s32, s32);
__declspec(section ".data") extern s32 lbl_8063CE34;

u8 *fn_8003E164(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    memset((s32)(arg0 + 0x10), (s32)(0), (s32)(0x80U));
    (*(s32 **)((u8 *)(arg0) + (4))) = &lbl_8063CE34;
    (*(u8 **)((u8 *)(arg0) + (8))) = (u8 *) ((u8 *)(u8 *)&lbl_8063CE34 + 0x10);
    return arg0;
}
}
