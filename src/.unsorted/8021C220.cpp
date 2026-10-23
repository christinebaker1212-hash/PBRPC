#include ".unsorted/8021C220.hpp"

#include "common.hpp"

extern "C" {

void fn_8021C58C();

void fn_8021C220(void) {
    fn_8021C58C();
}
s32 fn_8021CA78(void) {
    return 2;
}
}

extern "C" {

s32 fn_8021C75C(void);
s32 fn_8021CA78(void);
extern u8 lbl_8063F52E;

void fn_8021C224(void) {
    if ((s32) lbl_8063F52E != 0) {
        fn_8021CA78();
        fn_8021C75C();
    }
}
}

extern "C" {

s32 allocAndClear__5GSmemFUl(s32);
s32 fn_8021C254(void);
s32 fn_8021C274(s32);
s32 fn_8021C388(void);
extern u8 lbl_8063F52F;
extern s16 lbl_8063F536;
extern s32 lbl_8063F538;

s32 fn_8021C274(s32 arg0) {
    s32 temp_r3;

    lbl_8063F52E = 0;
    fn_8021C388();
    if ((s32) lbl_8063F52F == 0) {
        fn_8021C254();
        lbl_8063F52F = 1;
    }
    temp_r3 = allocAndClear__5GSmemFUl((arg0 * 4) & 0x3FFFC);
    lbl_8063F538 = temp_r3;
    if (temp_r3 == 0) {
        lbl_8063F536 = 0;
        return 0;
    }
    lbl_8063F536 = (s16) arg0;
    return 1;
}
}
