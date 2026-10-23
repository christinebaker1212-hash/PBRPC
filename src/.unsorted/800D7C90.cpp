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
