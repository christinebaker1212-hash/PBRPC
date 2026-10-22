#include ".unsorted/80225E44.hpp"

#include "common.hpp"

extern "C" {

extern u8 lbl_80423D80[];

u8 *fn_80226320(void) {
    return lbl_80423D80;
}
s32 fn_8022632C(void) {
    return 0;
}
s32 fn_80226334(void) {
    return 0;
}
void fn_8022633C(void) {}
void fn_80226340(void) {}
}

extern "C" {

s32 fn_80225F70(void);

u8 *fn_80225E94(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    (*(s32 *)((u8 *)(arg0) + (4))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (8))) = arg2;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = arg3;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = arg4;
    (*(s32 *)((u8 *)(arg0) + (0x18))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    fn_80225F70();
    return arg0;
}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_80226150(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_80225FE0(s32);
s32 fn_80226020(s32, s32, s32);
s32 fn_80226190(s32, s32, s32);

s32 fn_80226190(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    var_r3 = fn_80225FE0(arg1);
    if (var_r3 != 0) {
        var_r3 = fn_80226020(var_r3, arg1, arg2);
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8022604C(s32, s32, s32);
s32 fn_802261E0(s32, s32, s32);

s32 fn_802261E0(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    var_r3 = fn_80225FE0((s32)(arg1));
    if (var_r3 != 0) {
        var_r3 = fn_8022604C(var_r3, arg1, arg2);
    }
    return var_r3;
}
}

extern "C" {

s32 fn_80226094(s32, s32, s32);
s32 fn_80226230(s32, s32, s32);

s32 fn_80226230(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    var_r3 = fn_80225FE0((s32)(arg1));
    if (var_r3 != 0) {
        var_r3 = fn_80226094(var_r3, arg1, arg2);
    }
    return var_r3;
}
}

extern "C" {

s32 fn_802260DC(s32, s32, s32);
s32 fn_80226280(s32, s32, s32);

s32 fn_80226280(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    var_r3 = fn_80225FE0((s32)(arg1));
    if (var_r3 != 0) {
        var_r3 = fn_802260DC(var_r3, arg1, arg2);
    }
    return var_r3;
}
}

extern "C" {

s32 fn_80226124(s32, s32, s32);
s32 fn_802262D0(s32, s32, s32);

s32 fn_802262D0(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    var_r3 = fn_80225FE0((s32)(arg1));
    if (var_r3 != 0) {
        var_r3 = fn_80226124(var_r3, arg1, arg2);
    }
    return var_r3;
}
}
