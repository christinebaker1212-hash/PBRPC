#include ".unsorted/8016340C.hpp"

#include "common.hpp"

extern "C" {

extern u8 **lbl_8063F070;

void fn_801634C0(u8 *arg0) {
    u8 **temp_r4_2;
    u8 *temp_r4;

    temp_r4 = (*(u8 **)((u8 *)(arg0) + (0)));
    if (temp_r4 != NULL) {
        (*(u8 **)((u8 *)(temp_r4) + (4))) = arg0;
    } else {
        lbl_8063F070 = (*(u8 ***)((u8 *)(arg0) + (4)));
    }
    temp_r4_2 = (*(u8 ***)((u8 *)(arg0) + (4)));
    if (temp_r4_2 != NULL) {
        *temp_r4_2 = (*(u8 **)((u8 *)(arg0) + (0)));
    }
}
}
