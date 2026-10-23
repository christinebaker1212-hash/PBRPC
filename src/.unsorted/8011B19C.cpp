#include ".unsorted/8011B19C.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

void fn_8011C788(s32 arg0, s32 arg1) {
    s32 sp8;

    fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    switch (sp8) {
    case 4:
        fn_80253EB4(arg0, arg1, 1, 0);
        return;
    case 9:
        fn_80253EB4(arg0, arg1, 2, 0x515E);
        return;
    case 12:
        fn_80253EB4(arg0, arg1, 2, 0x515F);
        return;
    case 6:
        fn_80253EB4(arg0, arg1, 2, 0x5163);
        /* fallthrough */
    default:
        return;
    }
}
}

extern "C" {

s32 fn_80059A3C(s32, s32);
s32 fn_80253EDC(s32, s32, s32, s32);

void fn_8011C87C(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC(arg0, arg1, 3, (s32) &sp8);
    switch (sp8) {                                  /* irregular */
    case 1:
        fn_80253EDC(arg0, arg1, 6, (s32) sp10);
        fn_80059A3C(0xA, (s32) sp10);
        return;
    case 2:
        fn_80253EDC(arg0, arg1, 6, (s32) sp10);
        fn_80059A3C(0xB, (s32) sp10);
        /* fallthrough */
    case 8:
    case 11:
        return;
    }
}
}
