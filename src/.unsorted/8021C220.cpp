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
