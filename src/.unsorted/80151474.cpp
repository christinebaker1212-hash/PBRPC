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
