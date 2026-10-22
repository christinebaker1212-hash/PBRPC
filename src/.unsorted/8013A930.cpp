#include ".unsorted/8013A930.hpp"

#include "common.hpp"

extern "C" {

u32 fn_8013B030(void) {
    return lbl_8063EFA8->_00;
}
u32 fn_8013B03C(void) {
    return lbl_8063EFA8->_684;
}

void fn_8013B2D8(u32 a, u32 b) {
    lbl_8063EFA8->_6DC = a;
    lbl_8063EFA8->_6D8 = b;
}

void fn_8013BF80(void) {}
void fn_8013CAF0(void) {}
}

extern "C" {

s32 fn_800599C8(s32, s32, s32, s32, s32, s32);

void fn_8013D004(s32 arg0) {
    if (arg0 != 0) {
        fn_800599C8(0xA, 0, 0, 1, 0, 0);
        fn_800599C8(1, 0, 0xA, 0, 2, 0);
        fn_800599C8(2, 1, 0xA, 0, 0x63, 0);
        fn_800599C8(0x63, 2, 0xA, 0, 0, 0);
        return;
    }
    fn_800599C8(1, 0, 0, 0, 2, 0);
    fn_800599C8(2, 1, 0, 0, 0x63, 0);
    fn_800599C8(0x63, 2, 0, 0, 0, 0);
}
}
