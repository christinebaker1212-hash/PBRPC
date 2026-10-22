#include ".unsorted/8017C588.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063F238;

u32 fn_8017C588(void) {
    return lbl_8063F238;
}
u8 fn_8017C648(u8 *p) {
    return *(u8 *)(p + 0x0);
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 fn_8017C5D0(void);

s32 fn_8017C5D0(void) {
    s32 var_r3;

    var_r3 = lbl_8063F238;
    if (var_r3 != 0) {
        var_r3 = __dl__FPv(var_r3);
        lbl_8063F238 = 0;
    }
    return var_r3;
}
}
