#include ".unsorted/8004E9F0.hpp"

#include ".unsorted/80050324.hpp"

#include "common.hpp"

extern "C" {

// Thunk adjusting the object pointer to the sub-object at 0x14
void fn_8004ECD8(u8 *p) {
    fn_80050BE0(p + 0x14);
}

u8 fn_8004EE68(const u8 *p) {
    return *p;
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 fn_8004EA94(void);

s32 fn_8004EA40(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8004EA94();
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

void fn_8004ED4C(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0))) = 0;
}
}

extern "C" {

s32 fn_8004EDB0(void);

s32 fn_8004ED5C(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8004EDB0();
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8004F190(u8 *, s32, s32);
s32 memset(u8 *, s32, s32);
extern f32 lbl_80640A60;

void fn_8004F12C(u8 *arg0) {
    memset(arg0 + 0x100, 0, 0x80);
    memset(arg0, 0, 0x100);
    (*(f32 *)((u8 *)(arg0) + (0x180))) = (f32) lbl_80640A60;
    fn_8004F190(arg0, 0xC, 0x119C0C00);
}
}

extern "C" {

s32 fn_8004EFE4(s32, f32);

void fn_8004F2A4(s32 arg0, f32 farg0) {
    s32 var_r31;
    u32 var_r30;

    var_r31 = arg0;
    var_r30 = 0U;
    do {
        fn_8004EFE4(var_r31, farg0);
        var_r30 += 1;
        var_r31 += 8;
    } while (var_r30 < 0x20U);
}
}
