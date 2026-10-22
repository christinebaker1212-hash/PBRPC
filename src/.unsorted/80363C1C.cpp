#include ".unsorted/80363C1C.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_80640470;
extern u32 lbl_80640478;

u32 *fn_80363C1C(void) {
    return &lbl_80640470;
}
s32 fn_80363E58(void) {
    return 0;
}
s32 fn_80363E60(void) {
    return 0;
}
s32 fn_80363E68(void) {
    return 0;
}
u32 *fn_80363E70(void) {
    return &lbl_80640478;
}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_80363F2C(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}
