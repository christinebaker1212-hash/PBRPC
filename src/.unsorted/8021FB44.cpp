#include ".unsorted/8021FB44.hpp"

#include "common.hpp"

extern "C" {

extern f32 lbl_806421D0;

void fn_8021FD38(u8 *arg0) {
    (*(f32 *)((u8 *)(arg0) + (0x70))) = (f32) lbl_806421D0;
}
}

extern "C" {

s32 fn_8021FD08(u8 *arg0) {
    f32 temp_f1;

    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x10))) == 0) {
        return 0;
    }
    temp_f1 = (*(f32 *)((u8 *)(arg0) + (0x74)));
    (*(f32 *)((u8 *)(arg0) + (0x70))) = temp_f1;
    return temp_f1 > (0.00001f);
}
}

extern "C" {

s32 fn_8021FD44(u8 *arg0, f32 farg0) {
    f32 temp_f1;

    temp_f1 = (*(f32 *)((u8 *)(arg0) + (0x70))) - farg0;
    (*(f32 *)((u8 *)(arg0) + (0x70))) = temp_f1;
    return temp_f1 > (0.00001f);
}
}
