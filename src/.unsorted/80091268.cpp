#include ".unsorted/80091268.hpp"

#include "common.hpp"

extern "C" {

void fn_80091440(void) {}
void fn_8009187C(void) {}
void fn_800947FC(void) {}
void fn_80094800(void) {}
}

extern "C" {

s32 fn_8005AC60(s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

void fn_80093FD4(s32 arg0, s32 arg1, s32 arg2) {
    fn_80253EB4(arg0, arg1, 1, fn_8005AC60(0x3EF, arg2));
}
}

extern "C" {

s32 fn_80253E8C(s32, s32, s32, s32 *);                /* extern */
extern u8 lbl_8063ED0C;

void fn_80091294(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 var_r31;

    var_r31 = 0;
    fn_80253E8C(arg0, arg1, 3, &sp8);
    switch (sp8) {                                  /* irregular */
    case 1:
        if ((u8) lbl_8063ED0C == 1) {
            var_r31 = 0x29C6;
        }
        if ((u8) lbl_8063ED0C == 2) {
            var_r31 = 0x29C7;
        }
        if ((u8) lbl_8063ED0C == 3) {
            var_r31 = 0x29C8;
        }
        if ((u8) lbl_8063ED0C == 4) {
            var_r31 = 0x29C9;
        }
        if ((u8) lbl_8063ED0C == 5) {
            var_r31 = 0x29CA;
        }
        if ((u8) lbl_8063ED0C == 6) {
            var_r31 = 0x29CB;
        }
        if ((u8) lbl_8063ED0C == 7) {
            var_r31 = 0x29CC;
        }
        if ((u8) lbl_8063ED0C == 8) {
            var_r31 = 0x29CD;
        }
        if ((u8) lbl_8063ED0C == 9) {
            var_r31 = 0x29CE;
        }
        if ((u8) lbl_8063ED0C == 0xA) {
            var_r31 = 0x29CF;
        }
        break;
    case 2:
        if ((u8) lbl_8063ED0C == 1) {
            var_r31 = 0x29D1;
        }
        if ((u8) lbl_8063ED0C == 2) {
            var_r31 = 0x29D2;
        }
        if ((u8) lbl_8063ED0C == 3) {
            var_r31 = 0x29D3;
        }
        if ((u8) lbl_8063ED0C == 4) {
            var_r31 = 0x29D4;
        }
        if ((u8) lbl_8063ED0C == 5) {
            var_r31 = 0x29D5;
        }
        if ((u8) lbl_8063ED0C == 6) {
            var_r31 = 0x29D6;
        }
        if ((u8) lbl_8063ED0C == 7) {
            var_r31 = 0x29D7;
        }
        if ((u8) lbl_8063ED0C == 8) {
            var_r31 = 0x29D8;
        }
        if ((u8) lbl_8063ED0C == 9) {
            var_r31 = 0x29D9;
        }
        if ((u8) lbl_8063ED0C == 0xA) {
            var_r31 = 0x29DA;
        }
        break;
    }
    if (var_r31 != 0) {
        fn_80253EB4(arg0, arg1, 2, var_r31);
    }
    if (((u32) sp8 == 4U) && ((u8) lbl_8063ED0C == 0xB)) {
        fn_80253EB4(arg0, arg1, 1, 0);
    }
}
}
