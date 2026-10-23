#include ".unsorted/80297890.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063FF1C;

void fn_80297BAC(u32 v) {
    lbl_8063FF1C = v;
}
}

extern "C" {

extern s32 lbl_8063FF10;
extern s32 lbl_8063FF14;
extern s32 lbl_8063FF20;

void fn_80297B98(void) {
    lbl_8063FF10 = 0;
    lbl_8063FF20 = 0;
    lbl_8063FF14 = 0;
}
}

extern "C" {

void fn_8029928C(u8 *arg0, s32 arg1) {
    u8 *temp_r3;

    temp_r3 = (unsigned char *)(lbl_8063FF10 + ((*(s32 *)((u8 *)(arg0) + (0x18))) * 0x70));
    (*(s32 *)((u8 *)(temp_r3) + (8))) = arg1;
    (*(s32 *)((u8 *)(temp_r3) + (4))) = (s32) ((*(s32 *)((u8 *)(temp_r3) + (4))) | 0x10000000);
}
}

extern "C" {

void fn_802992B0(u8 *arg0, s32 arg1) {
    u8 *temp_r3;

    temp_r3 = (unsigned char *)(lbl_8063FF10 + ((*(s32 *)((u8 *)(arg0) + (0x18))) * 0x70));
    (*(s32 *)((u8 *)(temp_r3) + (0x20))) = arg1;
    (*(s32 *)((u8 *)(temp_r3) + (4))) = (s32) ((*(s32 *)((u8 *)(temp_r3) + (4))) | 0x40000000);
}
}

extern "C" {

void fn_80299274(u8 *arg0) {
    *(s32 *)((u8 *)0 + (lbl_8063FF10 + ((*(s32 *)((u8 *)(arg0) + (0x18))) * 0x70))) = 0;
}
}
