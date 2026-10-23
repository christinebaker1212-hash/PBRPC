#include "common.hpp"

extern "C" {

s32 __dl__FPv(s32);
s32 __dt__14GSrenderModuleFv(s32, s32);
s32 fn_801E4910(s32, s32);
extern s32 lbl_8063F390;

s32 fn_801E4910(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        lbl_8063F390 = 0;
        __dt__14GSrenderModuleFv(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}
