#include ".unsorted/800D7C90.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

void fn_800E1504(s32 arg0, s32 arg1) {
    s32 sp8;

    fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    switch (sp8) {                                  /* irregular */
    case 5:
        fn_80253EB4(arg0, arg1, 2, 0x2D27);
        return;
    case 7:
        fn_80253EB4(arg0, arg1, 2, 0x2D28);
        /* fallthrough */
    case 6:
        return;
    }
}
}

extern "C" {

void fn_800E0D78(s32 arg0, s32 arg1) {
    s32 sp8;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {
    case 9:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2D77));
        return;
    case 12:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2D78));
        return;
    case 15:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2D79));
        return;
    case 18:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2D7A));
        return;
    case 21:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2D7B));
        return;
    case 24:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2D7C));
        return;
    case 29:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(1), (s32)(0));
        /* fallthrough */
    default:
        return;
    }
}
}

extern "C" {

void fn_800E12B4(s32 arg0, s32 arg1) {
    s32 sp8;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {
    case 3:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(1), (s32)(0));
        return;
    case 9:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x5160));
        return;
    case 12:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x5161));
        return;
    case 6:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x5164));
        /* fallthrough */
    default:
        return;
    }
}
}
