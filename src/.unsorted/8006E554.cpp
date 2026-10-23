#include ".unsorted/8006E554.hpp"

#include "common.hpp"

extern "C" {

void fn_80058E34();
void fn_8007C3E0();
void fn_801577C4();

BOOL fn_800728C4(void) {
    return lbl_8063D4D0->_00 == 3;
}
BOOL fn_80072908(void) {
    return lbl_8063D4D0->_04 == 2;
}
BOOL fn_80072944(void) {
    return lbl_8063D4D0->_14 == 2;
}
BOOL fn_80072CD8(void) {
    return lbl_8063D4D0->_08 == 2;
}
void fn_80073EA0(u32 i) {
    lbl_8063D4D0->_420[i] = -1;
}

void fn_800745D8(void) {}
void fn_800753F4(void) {}
void fn_8007B9F4(void) {}
void fn_8007BA80(void) {}
void fn_8007C290(void) {}
void fn_8007C3DC(void) {
    fn_8007C3E0();
}
void fn_8007C6D0(void) {
    fn_801577C4();
}
void fn_8007C80C(void) {
    fn_80058E34();
}
}

extern "C" {

s32 fn_80253CBC(u16);
extern u16 lbl_8063D4D4;

void fn_8006F134(void) {
    fn_80253CBC(lbl_8063D4D4);
}
}

extern "C" {

s32 fn_8007247C(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0x2ECF;
    case 1:
        return 0x2ED0;
    default:
        return 0;
    }
}
}

extern "C" {

s32 fn_800724AC(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0xE8D;
    case 1:
        return 0xE90;
    default:
        return 0;
    }
}
}

extern "C" {

s32 fn_80162A90(s32);

s32 fn_8007C6D4(void) {
    if ((fn_80162A90(9) == 0) && (fn_80162A90(0x19B) == 0)) {
        return 0;
    }
    if (fn_80162A90(0x19B) == 1U) {
        return 1;
    }
    return 2;
}
}

extern "C" {

s32 fn_8006F0EC(void);
s32 fn_80253E4C(s32, s32, s32);

s32 fn_8006F0EC(void) {
    s32 sp8;

    if ((s16) lbl_8063D4D4 == -1) {
        return 1;
    }
    fn_80253E4C((s32) lbl_8063D4D4, 8, (s32) &sp8);
    return sp8 == 0;
}
}

extern "C" {

s32 fn_8006F6DC(void);
s32 fn_80155C18(s32, s32);
extern s32 lbl_8063EC70;

s32 fn_8006F6DC(void) {
    s32 var_r3;

    var_r3 = lbl_8063EC70;
    if (var_r3 != 0) {
        var_r3 = fn_80155C18(var_r3, 1);
        lbl_8063EC70 = 0;
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8007C22C(s32, s32);
s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_8007C22C(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    if (sp8 != 1) {
        return temp_r3;
    }
    return fn_80253EB4(arg0, arg1, 2, 0x5243);
}
}

extern "C" {

s32 fn_8007C734(s32, s32, s32, s32);
s32 fn_80162940(s32, s32, s32);

s32 fn_8007C734(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r3;

    if (arg3 != 0) {
        fn_80162940(arg0, 1, 1);
        return fn_80162940(arg1, 0, 1);
    }
    fn_80162940(arg0, 2, 1);
    fn_80162940(arg1, fn_80162A90((s32)(arg1)) + 1, 1);
    var_r3 = fn_80162A90((s32)(arg1));
    if ((u32) var_r3 == 2U) {
        var_r3 = fn_80162940(arg1, 0, 1);
        if (arg2 != 0) {
            var_r3 = fn_80162A90((s32)(arg2));
            if (var_r3 != 0) {
                var_r3 = fn_80162940(arg2, fn_80162A90((s32)(arg2)) - 1, 1);
            }
        }
    }
    return var_r3;
}
}
