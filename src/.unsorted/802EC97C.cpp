#include ".unsorted/802EC97C.hpp"

#include "common.hpp"

extern "C" {

s32 __SCF1(s32, s32, s32);
s32 sscanf(s32, ...);
extern u8 lbl_8063DE90;
extern u8 lbl_8063DE98;

s32 fn_802EC9B8(s32 arg0) {
    s32 sp8;

    if ((__SCF1((s32) &lbl_8063DE90, (s32) &sp8, 0xB) != 0) && (sscanf((s32) &sp8, &lbl_8063DE98, arg0) == 1)) {
        return 1;
    }
    return 0;
}
}
