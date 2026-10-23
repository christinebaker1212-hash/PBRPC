#include ".unsorted/80169268.hpp"

#include "common.hpp"

extern "C" {

s32 OSInitMutex(s32);
s32 fn_80163580(s32);
s32 fn_8025DFC0(s32, s32);
s32 fn_8025DFD0(void);
__declspec(section ".data") extern s32 lbl_8048CB90;
__declspec(section ".data") extern s32 lbl_8048CBA8;
extern s32 lbl_8063F140;
extern s32 lbl_8063F144;
extern s32 lbl_8063F148;

void fn_801694A0() {
    if ((s32) lbl_8063F144 == 0) {
        lbl_8063F144 = fn_8025DFC0(fn_8025DFD0(), 0x8000);
        lbl_8063F148 = 0x8000;
        OSInitMutex((s32) &lbl_8048CB90);
    }
    lbl_8063F140 = 0;
    fn_80163580((s32) &lbl_8048CBA8);
}
}

extern "C" {

s32 fn_80164C04(s32);
s32 fn_80167A30(s32);
s32 fn_80169268(s32, s32);
s32 fn_801693B0(s32, s32);
s32 fn_8016950C(s32);
s32 fn_80169560(s32, s32);
s32 fn_8025DFC8(s32, s32);

s32 fn_801696B8(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;
    s32 temp_r31_2;
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3 = fn_80167A30(arg0);
    if (temp_r3 < 0) {
        return -1;
    }
    if (fn_80164C04(temp_r3) == 0) {
        return -2;
    }
    temp_r31 = fn_8016950C(arg1);
    temp_r3_2 = fn_8025DFC0((s32)(fn_8025DFD0()), (s32)(temp_r31));
    if (temp_r3_2 == 0) {
        return -1;
    }
    fn_80169560(arg1, temp_r3_2);
    temp_r31_2 = fn_80169268(temp_r3_2, temp_r31);
    fn_8025DFC8(fn_8025DFD0(), temp_r3_2);
    if (temp_r31_2 != 0) {
        return -1;
    }
    fn_801693B0(temp_r3, arg2);
    return 0;
}
}
