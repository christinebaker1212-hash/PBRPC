#include ".unsorted/80168C1C.hpp"

#include "common.hpp"

extern "C" {

s32 fn_8025D7CC(s32, s32, s32);
s32 fn_8025DFC0(s32, s32);
s32 fn_8025DFD0(void);
__declspec(section ".data") extern s32 lbl_8048CB48;
extern s32 lbl_8063F130;
extern s32 lbl_8063F134;

void fn_80168C48() {
    if ((s32) lbl_8063F130 == 0) {
        lbl_8063F130 = fn_8025DFC0(fn_8025DFD0(), 0x8000);
    }
    if ((s32) lbl_8063F134 == 0) {
        lbl_8063F134 = fn_8025DFC0(fn_8025DFD0(), 0xC000);
    }
    fn_8025D7CC((s32) &lbl_8048CB48, lbl_8063F134, 0xC000);
}
}
