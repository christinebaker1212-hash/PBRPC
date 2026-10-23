#include ".unsorted/80151474.hpp"

#include "common.hpp"

extern "C" {

BOOL fn_801531D4(void) {
    return lbl_8063D590->_C4 == 0x14;
}
}

extern "C" {

s32 fn_80154FB8(s32);
u16 fn_80253DD0(s32);
u16 fn_80253DE0(s32);
s32 fn_80253DF0(s32, s32, s32);

void fn_80154CD8(s32 arg0) {
    if ((fn_80154FB8(0x1E) != 0) && (fn_80253DE0(arg0) == 1) && (fn_80253DD0(arg0) == 3)) {
        fn_80253DF0(arg0, 8, 0);
    }
}
}

extern "C" {

s32 fn_80154D48(s32, s32);
s32 fn_80253E8C(s32, s32, s32, s32);

s32 fn_80154D48(s32 arg0, s32 arg1) {
    s32 sp8;

    return fn_80253E8C((s32) (s16) arg0, arg1, 3, (s32) &sp8);
}
}

extern "C" {

s32 fn_80253DB0(s32, s32, s32);
s32 fn_80253E4C(s32, s32, s32);

void fn_80153398(s32 arg0) {
    s32 sp8;
    u16 temp_r3;

    fn_80253E4C(arg0, 8, (s32) &sp8);
    if ((sp8 != 0) && (fn_80253DD0((s32)(arg0)) == 3)) {
        temp_r3 = fn_80253DE0((s32)(arg0));
        switch ((s32) temp_r3) {                    /* irregular */
        case 6:
            fn_80253DB0(arg0, 0, 0);
            return;
        case 7:
            fn_80253DB0(arg0, 1, 0);
            return;
        case 8:
            fn_80253DB0(arg0, 2, 0);
            return;
        case 9:
            fn_80253DB0(arg0, 3, 0);
            return;
        case 10:
            fn_80253DB0(arg0, 4, 0);
            return;
        case 11:
            fn_80253DB0(arg0, 5, 0);
            break;
        }
    }
}
}

extern "C" {

s32 fn_80059A3C(s32, s32);
s32 fn_80253EDC(s32, s32, s32, s32);

void fn_8015330C(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC(arg0, arg1, 3, (s32) &sp8);
    fn_80253EDC(arg0, arg1, 6, (s32) sp10);
    switch (sp8) {                                  /* irregular */
    case 1:
        fn_80059A3C(0x3D, (s32) sp10);
        return;
    case 2:
        fn_80059A3C(0x3E, (s32) sp10);
        return;
    }
}
}
