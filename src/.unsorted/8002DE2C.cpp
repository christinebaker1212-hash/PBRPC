#include ".unsorted/8002DE2C.hpp"

#include "common.hpp"

extern "C" {

s32 fn_8002DE2C(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 1:
        return 0x27E6;
    case 2:
        return 0x27E0;
    case 3:
        return 0x27E5;
    case 4:
        return 0x27E1;
    default:
        return 0;
    }
}
}

extern "C" {

s32 fn_8015C308(s32, s32);
s32 fn_8025009C(s32, s32, s32, s32, s32, s32, s32, s32);
s32 fn_802502D4(s32);
s32 fn_802502E4(s32);
__declspec(section ".data") extern s32 lbl_80474F38;
extern u8 lbl_8063E9F6;
extern f32 lbl_8063E9F8;
extern s32 lbl_8063E9FC;
extern s32 lbl_8063EA00;
extern s16 lbl_8063EA04;
extern s16 lbl_8063EA06;

void fn_80030070(f32 farg0) {
    if ((s32) lbl_8063E9F6 != 0) {
        lbl_8063E9F8 -= farg0;
        if ((fn_802502E4(0x508A) == 0) && (fn_802502E4(0x508B) == 0)) {
            lbl_8063E9F6 = 0;
            fn_802502D4(0x508B);
            fn_802502D4(0x508A);
            fn_8015C308(0x10, (s32) ((u8 *)(u8 *)&lbl_80474F38 + 0x100));
            fn_8025009C(0x508A, lbl_8063E9FC, lbl_8063EA00, (s32) lbl_8063EA04, (s32) lbl_8063EA06, -1, 0, 1);
        }
    }
}
}
