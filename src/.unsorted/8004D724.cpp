#include ".unsorted/8004D724.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063EAF0;

u32 fn_8004D80C(void) {
    return lbl_8063EAF0;
}
void fn_8004DA84(void) {}
}

extern "C" {

s32 fn_8004879C(void);
s32 fn_8004DBE8(void);

void fn_8004DBBC(void) {
    if (fn_8004DBE8() != 0) {
        fn_8004879C();
    }
}
}
