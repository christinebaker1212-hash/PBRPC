#include ".unsorted/8022910C.hpp"

#include "common.hpp"

extern "C" {

void fn_8022910C(void) {}
s32 fn_80229E94(void) {
    return 1;
}
s32 fn_80229E9C(void) {
    return 1;
}
s32 fn_80229EA4(void) {
    return 0;
}
s32 fn_80229EAC(void) {
    return 0;
}
void fn_8022CF7C(void) {}
void fn_8022D6C0(void) {}
void fn_8022D704(void) {}
void fn_8022D708(void) {}
}

extern "C" {

void fn_80229238(u8 *arg0);

s32 fn_802291C8(s32 arg0) {
    ((s32 (*)(void))fn_80229238)();
    return arg0;
}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_802291F8(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_80229514(u8 *, s32, s32);
s32 memset(u8 *, s32, s32);

u8 *fn_802293BC(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x154))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x15C))) = 0;
    memset(arg0 + 0xC, 0, 0x144);
    (*(s32 *)((u8 *)(arg0) + (0x180))) = 0;
    fn_80229514(arg0, 0x100, 0x80);
    return arg0;
}
}

extern "C" {

s32 fn_80229B08(void);
s32 fn_8022A85C(void);
extern u8 *lbl_80627960;

void fn_8022A8A8(u8 *arg0) {
    u8 *temp_r31;

    temp_r31 = lbl_80627960;
    lbl_80627960 = arg0;
    if (fn_8022A85C() != 0) {
        fn_80229B08();
        (*(s32 *)((u8 *)(arg0) + (0x8DC))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0x8DC))) - 1);
    }
    lbl_80627960 = temp_r31;
}
}

extern "C" {

s32 fn_8022D6C4(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_8022A2B4(s32, s32, s32, s32, s32);
s32 fn_8022A35C(s32, s32, s32, s32, s32);
s32 fn_8022CF90(s32, s32);

s32 fn_8022A2B4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r8;

    temp_r8 = (*(s32 *)((u8 *)(arg0) + (0x940)));
    if (temp_r8 == 0) {
        return 0;
    }
    if ((arg1 >> 0x10) == 0) {
        return 0;
    }
    if (((s32) (u16) arg1 >= temp_r8) || ((s32) (u16) arg1 < 0)) {
        return 0;
    }
    return fn_8022A35C(arg0, fn_8022CF90(arg0, (s32) (u16) arg1), arg2, arg3, arg4);
}
}

extern "C" {

s32 fn_80229478(void);

s32 fn_80229424(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_80229478();
        if (arg1 > 0) {
            ((s32 (*)(s32))__dl__FPv)(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8022A900() {
    s32 *temp_r3;

    temp_r3 = ((s32 *)fn_8022A85C());
    if (temp_r3 != NULL) {
        return *temp_r3 != 0;
    }
    return 0;
}
}

extern "C" {

void fn_8022AB38() {
    s32 *temp_r3;
    s32 temp_r0;

    temp_r3 = ((s32 *)fn_8022A85C());
    if (temp_r3 != NULL) {
        temp_r0 = *temp_r3;
        if (temp_r0 != 0) {
            *temp_r3 = temp_r0 | 2;
        }
    }
}
}

extern "C" {

void fn_8022AB74() {
    s32 *temp_r3;

    temp_r3 = ((s32 *)fn_8022A85C());
    if (temp_r3 != NULL) {
        *temp_r3 &= 0xFFFFFFFD;
    }
}
}

extern "C" {

void fn_80229238(u8 *arg0) {
    memset((u8 *)((s32)(arg0)), (s32)((s32)(0)), (s32)((s32)(0x80U)));
    memset((u8 *)((s32)(arg0 + 0x80)), (s32)((s32)(0)), (s32)((s32)(0x40U)));
}
}

extern "C" {

s32 fn_80224A00(u8 *, s32, s32);
s32 fn_8022A940(void);
s32 fn_8022DB40(void);
struct VT_fn_80229F44_0 { u8 pad[2440]; virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual s32 v5(void); };

void fn_80229F44(u8 *arg0) {
    s32 var_r31;
    s32 var_r30;

    fn_8022A940();
    (*(s32 *)((u8 *)(arg0) + (0x940))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x944))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x948))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x94C))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x950))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x954))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x958))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x95C))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x960))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x964))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x968))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x974))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x978))) = 0;
    fn_80224A00(arg0, 0, 0);
    (*(s32 *)((u8 *)(arg0) + (0x938))) = 0;
    ((VT_fn_80229F44_0 *)(arg0))->v5();
    ((s32 (*)(u8 *))fn_80229238)(arg0 + 0x18);
    var_r30 = 0;
    var_r31 = 0;
    while (var_r30 < (s32) (*(s32 *)((u8 *)(arg0) + (0x96C)))) {
        if ((s32) (*(u8 *)((u8 *)(*(s32 *)((u8 *)0 + ((*(s32 *)((u8 *)(arg0) + (0x970))) + var_r31))) + (8))) == 0) {
            fn_8022DB40();
        }
        var_r31 += 4;
        var_r30 += 1;
    }
    (*(s32 *)((u8 *)(arg0) + (0x96C))) = 0;
}
}
