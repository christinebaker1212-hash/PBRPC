#include ".unsorted/8009598C.hpp"

#include "common.hpp"

extern "C" {

void fn_80098F3C(void) {}
}

extern "C" {

s32 fn_80099AE0(s32 *, s32, f32);
extern f32 lbl_8063ED50;
extern s32 lbl_8063EE28;

void fn_80099C48(void) {
    fn_80099AE0(&lbl_8063EE28, 0x18, lbl_8063ED50);
}
}

extern "C" {

s32 fn_8009868C(s32, s32);
s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_8009868C(s32 arg0, s32 arg1) {
    u32 sp8;
    s32 var_r3;

    var_r3 = fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    if (sp8 == 2U) {
        var_r3 = fn_80253EB4(arg0, arg1, 2, 0x2ADC);
    }
    return var_r3;
}
}

extern "C" {

s32 fn_80059A3C(s32, s32);
s32 fn_80253EDC(s32, s32, s32, s32);

void fn_80098FD8(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC(arg0, arg1, 3, (s32) &sp8);
    if (sp8 == 0) {
        fn_80253EDC(arg0, arg1, 6, (s32) sp10);
        fn_80059A3C(1, (s32) sp10);
    }
}
}

extern "C" {

void fn_80099044(s32 arg0, s32 arg1) {
    s32 sp10[10];
    u32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    if (sp8 == 3U) {
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(1), (s32)((s32) sp10));
    }
    if (sp8 == 2U) {
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(2), (s32)((s32) sp10));
    }
}
}
