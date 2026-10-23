#include ".unsorted/801697AC.hpp"

#include "common.hpp"

extern "C" {

void fn_80169884(void) {}
void fn_80169E88(void) {}
void fn_8016A088(void) {}
}

#include "common.hpp"

extern "C" {

extern u8 lbl_8041F7A0[];
extern u8 lbl_8063F156;

void fn_80169834(u8 *p) {
    *(u8 **)(p + 0x0) = lbl_8041F7A0;
}
void fn_801698B4(void) {
    lbl_8063F156 = 0x1;
}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_80169844(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_80009808(s32);
s32 fn_80035D9C(void);
s32 fn_80035DA4(void);

void fn_80169888(void) {
    fn_80009808(1);
    fn_80035D9C();
    fn_80035DA4();
}
}

extern "C" {

s32 fn_801697AC(void);
s32 fn_8016CE24(void);
extern u8 lbl_8063F15C;

s32 fn_801697AC(void) {
    ((s32 (*)(s32))fn_80169884)((s32) &lbl_8063F15C);
    return fn_8016CE24();
}
}
