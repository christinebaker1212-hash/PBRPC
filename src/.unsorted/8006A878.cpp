#include ".unsorted/8006A878.hpp"

#include "common.hpp"

extern "C" {

s32 fn_8006E310(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0xE8D;
    case 1:
        return 0xE90;
    default:
        return 0;
    }
}
}

extern "C" {

s32 fn_80253E10(s16, s32, f32);
extern f32 lbl_80640C78;

void fn_8006E340(s16 arg0) {
    fn_80253E10(arg0, 4, lbl_80640C78);
}
}

extern "C" {

s32 fn_8005A9F8(s32);
s32 fn_8006E234(s32, s32);
s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_8006E234(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    if (sp8 != 2) {
        return temp_r3;
    }
    return fn_80253EB4(arg0, arg1, 1, fn_8005A9F8(0x1A));
}
}

extern "C" {

s32 fn_800569EC__FP7Pokemon(s32);
s32 fn_8015C308(s32, s32);
s32 fn_802502F4(s32);
__declspec(section ".data") extern s32 lbl_80478408;

void fn_8006BCBC(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 var_r31;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {
    case 1:
        (*(u8 *)((u8 *)(arg1) + (2))) = 0xFF;
        var_r31 = 0;
        (*(u8 *)((u8 *)(arg1) + (3))) = 0xFF;
        (*(u8 *)((u8 *)(arg1) + (4))) = 0xFF;
        switch ((s32) (*(u16 *)((u8 *)(&lbl_80478408) + (0x6A)))) { /* irregular */
        case 0x0:
            var_r31 = 0x2ECB;
            fn_8015C308(0x15, fn_800569EC__FP7Pokemon((*(s32 *)((u8 *)(&lbl_80478408) + (4)))));
            break;
        case 0x1:
            var_r31 = 0x2ECC;
            fn_8015C308(0x16, fn_802502F4((s32) (*(u16 *)((u8 *)(&lbl_80478408) + (0x6C)))));
            break;
        case 0x2:
            var_r31 = 0x2ECB;
            fn_8015C308(0x15, fn_800569EC__FP7Pokemon((*(s32 *)((u8 *)(&lbl_80478408) + (8)))));
            break;
        case 0x3:
            var_r31 = 0x2ECC;
            fn_8015C308(0x16, fn_802502F4((s32) (*(u16 *)((u8 *)(&lbl_80478408) + (0x6C)))));
            break;
        case 0x4:
            var_r31 = 0xE9E;
            break;
        case 0x5:
            var_r31 = 0xEA2;
            break;
        case 0x6:
            var_r31 = 0xEAB;
            break;
        case 0x7:
            var_r31 = 0xEAC;
            break;
        case 0x8:
            var_r31 = 0x2ED8;
            break;
        case 0x800:
            var_r31 = 0x46BB;
            break;
        }
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(var_r31));
    }
    return;
}
}
