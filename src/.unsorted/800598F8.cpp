#include ".unsorted/800598F8.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063EB98;
extern u8 lbl_8063EBAC;

void fn_800599C0(u8 v) {
    lbl_8063EBAC = v;
}
void fn_8005A438(u32 v) {
    lbl_8063EB98 = v;
}
void fn_8005A44C(void) {}
}

#include "common.hpp"

extern "C" {

extern u8 lbl_8063EBA4;

void fn_8005A440(void) {
    lbl_8063EBA4 = 0x1;
}
}

extern "C" {

s32 fn_80051AC0(s32, s32, s32);
__declspec(section ".data") extern s32 lbl_804766D8;

void fn_80059A3C(s32 arg0, s32 arg1) {
    fn_80051AC0((s32) &lbl_804766D8, arg0, arg1);
}
}

extern "C" {

s32 fn_80051B14(s32, s32, s32);

void fn_80059A54(s32 arg0, s32 arg1) {
    fn_80051B14((s32) &lbl_804766D8, arg0, arg1);
}
}

extern "C" {

s32 fn_80253DA0(s32);
void fn_8005A45C();

void fn_8005A450() {
    fn_80253DA0((s32) &fn_8005A45C);
}
}

extern "C" {

s32 fn_800514A8(s32);
s32 fn_8015F690(void);
extern s32 lbl_8063EBA8;

void fn_8005A45C() {
    if ((s32) lbl_8063EBA4 != 0) {
        if ((s32) lbl_8063EBA8 == 0) {
            lbl_8063EBA8 = fn_8015F690();
        }
        if ((s32) lbl_8063EBA8 != 0) {
            if ((s32) (*(s32 *)((u8 *)(lbl_8063EBA8) + (0x4C))) != 2) {
                fn_800514A8((s32) &lbl_804766D8);
            }
        } else {
            fn_800514A8((s32) &lbl_804766D8);
        }
    }
}
}
