#include ".unsorted/800AA038.hpp"

#include "common.hpp"

extern "C" {

void fn_800F92D8();

void fn_800AA080(void) {
    fn_800F92D8();
}
}

extern "C" {

s32 fn_800579FC__Fi(s32);
s32 fn_800F8BF4(s32);
extern s8 lbl_8063EEA6;
extern s32 lbl_8063EEA8;
extern s8 lbl_8063EEB4;

void fn_800AA038(void) {
    lbl_8063EEB4 = 1;
    fn_800F8BF4(1);
    lbl_8063EEA6 = 1;
    lbl_8063EEA8 = 0;
    fn_800579FC__Fi(1);
}
}
