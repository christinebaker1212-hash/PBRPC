#include ".unsorted/8005CEAC.hpp"

#include "common.hpp"

extern "C" {

void fn_80062FF8(void) {}
void fn_80063510(void) {}
void fn_80064558(void) {}
void fn_80069668(void) {}
void fn_8006A74C(void) {}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_8005CEAC(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_8006A750(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0x3126;
    case 1:
        return 0x3127;
    default:
        return 0;
    }
}
}

extern "C" {

s32 fn_80058480__Fv(void);
s32 fn_80058490__Fv(void);
s32 fn_80068F34(s32, s32);
s32 fn_8006F0EC(void);
s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_80068F34(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    if ((fn_80058480__Fv() == 0) || (fn_80058490__Fv() == 0)) {
        return fn_80253EB4(arg0, arg1, 1, 0);
    }
    temp_r3 = fn_8006F0EC();
    if (temp_r3 != 0) {
        return fn_80253EB4(arg0, arg1, 1, 0);
    }
    if (sp8 != 1) {
        return temp_r3;
    }
    return fn_80253EB4(arg0, arg1, 2, 0x51CF);
}
}

extern "C" {

s32 fn_80069600(s32, s32);
s32 fn_8006A7B0(s32);

s32 fn_80069600(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 var_r3;

    var_r3 = fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    if (sp8 == 0) {
        var_r3 = fn_80253EB4(arg0, arg1, 1, fn_8006A7B0(7));
    }
    return var_r3;
}
}
