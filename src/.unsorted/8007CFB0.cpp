#include ".unsorted/8007CFB0.hpp"

#include "common.hpp"

extern "C" {

s32 fn_8007CFB0(void) {
    return 1;
}
void fn_8007F0A8(void) {}
}

extern "C" {

u8 *fn_8015F690(void);

void fn_8007D224(void) {
    u8 *temp_r3;

    temp_r3 = fn_8015F690();
    (*(s8 *)((u8 *)(temp_r3) + (0x43))) = 1;
    (*(s8 *)((u8 *)(temp_r3) + (0x44))) = 1;
    (*(s8 *)((u8 *)(temp_r3) + (0x45))) = 1;
    (*(s8 *)((u8 *)(temp_r3) + (0x41))) = 0;
    (*(s32 *)((u8 *)(temp_r3) + (0x48))) = 0;
    (*(s32 *)((u8 *)(temp_r3) + (0x4C))) = 0;
}
}

extern "C" {

void fn_8007D27C(void) {
    u8 *temp_r3;

    temp_r3 = fn_8015F690();
    (*(s8 *)((u8 *)(temp_r3) + (0x41))) = 0;
    (*(s32 *)((u8 *)(temp_r3) + (0x48))) = 0;
}
}

extern "C" {

s32 fn_80253F6C(s32, s32, s32);
void fn_8007D3F8(void);
void fn_8007EA80(void);
extern s16 lbl_8063ECB6;
extern s32 lbl_8063ECC4;

void fn_8007D3CC(s32 arg0, s32 arg1) {
    lbl_8063ECB6 = 1;
    fn_80253F6C((s32) &fn_8007D3F8, (s32) &fn_8007EA80, lbl_8063ECC4);
}
}

extern "C" {

__declspec(section ".data") extern u8 lbl_8047A968;

u8 fn_8007D3EC() {
    return lbl_8047A968;
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8047A978;

s32 fn_8007F81C() {
    if ((u8) (*(u8 *)((u8 *)(&lbl_8047A968) + (5))) != (u8) (*(u8 *)((u8 *)(&lbl_8047A978) + (5)))) {
        return 1;
    }
    if ((s32) (*(s32 *)((u8 *)(&lbl_8047A968) + (8))) != (s32) (*(s32 *)((u8 *)(&lbl_8047A978) + (8)))) {
        return 1;
    }
    return (*(s32 *)((u8 *)(&lbl_8047A968) + (0xC))) != (*(s32 *)((u8 *)(&lbl_8047A978) + (0xC)));
}
}
