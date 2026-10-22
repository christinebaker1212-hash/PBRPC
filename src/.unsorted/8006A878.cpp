#include ".unsorted/8006A878.hpp"

#include "common.hpp"

extern "C" {

s32 fn_8006E310(s32 arg0) {
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

s32 fn_80253E10(s16, s32, f32);
extern f32 lbl_80640C78;

void fn_8006E340(s16 arg0) {
    fn_80253E10(arg0, 4, lbl_80640C78);
}
}
