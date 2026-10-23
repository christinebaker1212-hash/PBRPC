#include ".unsorted/8004D724.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063EAF0;

u32 fn_8004D80C(void) {
    return lbl_8063EAF0;
}
void fn_8004DA84(void) {}
}

extern "C" {

s32 fn_8004879C(void);
s32 fn_8004DBE8(void);

void fn_8004DBBC(void) {
    if (fn_8004DBE8() != 0) {
        fn_8004879C();
    }
}
}

extern "C" {

s32 fn_80048908(s32, s32, s32);
s32 fn_8004DB54(s32, s32, s32);
s32 fn_8004DC28(s32);

s32 fn_8004DB54(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    var_r3 = ((s32 (*)(s32, s32, s32))fn_8004DBE8)(arg0, arg1, arg2);
    if (var_r3 == 0) {
        var_r3 = fn_8004DC28(arg0);
        if (var_r3 != 0) {
            var_r3 = fn_80048908(var_r3, arg1, arg2);
        }
    }
    return var_r3;
}
}

extern "C" {

s32 fn_80047AA8(s32);
s32 fn_8004DDCC(s32, s32);

s32 fn_8004DDCC(s32 arg0, s32 arg1) {
    s32 temp_r0;
    s32 var_r3;
    u8 *temp_r31;

    var_r3 = arg0;
    if ((arg1 != 0) && ((*(s32 *)((u8 *)(arg1) + (0))) & 1)) {
        temp_r31 = (*(u8 **)((u8 *)(arg1) + (0x24)));
        var_r3 = fn_80047AA8(arg1);
        temp_r0 = (*(s32 *)((u8 *)(temp_r31) + (0x88))) - 1;
        (*(s32 *)((u8 *)(temp_r31) + (0x88))) = temp_r0;
        if (temp_r0 == 0) {
            var_r3 = ((s32 (*)(s32))fn_8004879C)((s32) temp_r31);
        }
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8000739C__Fv(void);
s32 fn_8004D9D8(s32);

void fn_8004D814(void) {
    if ((s32) lbl_8063EAF0 != 0) {
        fn_8000739C__Fv();
        fn_8004D9D8(lbl_8063EAF0);
    }
}
}

extern "C" {

s32 __construct_array(s32, s32, s32, s32, s32);
void fn_8004D904(u32 arg0);
s32 fn_8004E9F0(s32);
s32 fn_8004F0BC(s32);
s32 fn_8004F12C(s32);
void fn_800478E4(void);
void fn_80047908(void);
void fn_80048728(void);
void fn_80048748(void);
void fn_8004DE88(void);
void fn_8004DEF8(void);

s32 fn_8004D85C(s32 arg0) {
    __construct_array(arg0, (s32) &fn_80048728, (s32) &fn_80048748, 0x9C, 0x30);
    __construct_array(arg0 + 0x1D40, (s32) &fn_800478E4, (s32) &fn_80047908, 0x38, 0x30);
    __construct_array(arg0 + 0x27C0, (s32) &fn_8004DE88, (s32) &fn_8004DEF8, 0x68, 0x20);
    fn_8004E9F0(arg0 + 0x34C0);
    fn_8004F0BC(arg0 + 0x3510);
    fn_8004F12C(arg0 + 0x3510);
    fn_8004D904((u32)(arg0));
    return arg0;
}
}

extern "C" {

s32 __destroy_arr(s32, s32 *, s32, s32);
s32 __dl__FPv(s32);
s32 __nw__FUl(s32);
s32 fn_8004E920(void);
s32 fn_8004EA40(s32, s32);
s32 fn_8023EB58(s32, s32 *, s32 *, s32, s32);
void fn_8004D848(void);
void fn_8004ED5C(void);
extern s32 lbl_8063F778;

void fn_8004D724() {
    s32 temp_r31;
    s32 temp_r3;
    s32 var_r3;

    temp_r31 = lbl_8063EAF0;
    if ((!(temp_r31 == 0)) && (!(temp_r31 == 0))) {
        temp_r3 = temp_r31 + 0x3510;
        if (temp_r3 != 0) {
            __destroy_arr((s32)(temp_r3), (s32 *)(&fn_8004ED5C), (s32)(8), (s32)(0x20));
        }
        fn_8004EA40(temp_r31 + 0x34C0, -1);
        __destroy_arr((s32)(temp_r31 + 0x27C0), (s32 *)(&fn_8004DEF8), (s32)(0x68), (s32)(0x20));
        __destroy_arr((s32)(temp_r31 + 0x1D40), (s32 *)(&fn_80047908), (s32)(0x38), (s32)(0x30));
        __destroy_arr((s32)(temp_r31), (s32 *)(&fn_80048748), (s32)(0x9C), (s32)(0x30));
        __dl__FPv(temp_r31);
    }
    var_r3 = __nw__FUl(0x3694);
    if (var_r3 != 0) {
        var_r3 = ((s32 (*)(void))fn_8004D85C)();
    }
    lbl_8063EAF0 = var_r3;
    fn_8023EB58((s32)(lbl_8063F778), (s32 *)(&fn_8004D814), (s32 *)(&fn_8004D848), (s32)(3), (s32)(0xC));
    fn_8004E920();
}
}

extern "C" {

void fn_8004DCCC(s32 arg0);
s32 fn_8004F300(s32);

void fn_8004D904(u32 arg0) {
    u32 var_r30;

    var_r30 = arg0;
    while (var_r30 != (u32) (arg0 + 0x1D40)) {
        ((s32 (*)(u32))fn_8004879C)(var_r30);
        var_r30 += 0x9C;
    }
    fn_8004DCCC((s32)(arg0));
    fn_8004F300(arg0 + 0x3510);
}
}

extern "C" {

void fn_8004DD24(s32 arg0);

void fn_8004D96C(u8 *arg0) {
    u8 *var_r30;

    var_r30 = arg0;
    while ((u32) var_r30 != (u32) (arg0 + 0x1D40)) {
        if ((u32) (*(u32 *)((u8 *)(var_r30) + (0x8C))) != 0xCU) {
            ((s32 (*)(u8 *))fn_8004879C)(var_r30);
        }
        var_r30 += 0x9C;
    }
    fn_8004DD24((s32)(arg0));
}
}

extern "C" {

s32 fn_8004DF78(u8 *);

void fn_8004DCCC(s32 arg0) {
    u8 *var_r30;

    var_r30 = (unsigned char *)(arg0 + 0x27C0);
    while ((u32) var_r30 != (u32) (arg0 + 0x34C0)) {
        if ((*(s32 *)((u8 *)(var_r30) + (0x34))) & 1) {
            fn_8004DF78(var_r30);
        }
        var_r30 += 0x68;
    }
}
}

extern "C" {

void fn_8004DD24(s32 arg0) {
    u32 temp_r0;
    u8 *var_r30;

    var_r30 = (unsigned char *)(arg0 + 0x27C0);
    while ((u32) var_r30 != (u32) (arg0 + 0x34C0)) {
        if ((*(s32 *)((u8 *)(var_r30) + (0x34))) & 1) {
            temp_r0 = (*(u32 *)((u8 *)(var_r30) + (0x44)));
            if ((temp_r0 != 0xCU) && ((temp_r0 < 0x64U) || (temp_r0 > 0x73U))) {
                fn_8004DF78((u8 *)(var_r30));
            }
        }
        var_r30 += 0x68;
    }
}
}
