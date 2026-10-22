#include ".unsorted/8009F6C4.hpp"

#include "common.hpp"

extern "C" {

void fn_800A6F38(void) {}
}

extern "C" {

extern u8 *lbl_8063D4F8;
extern f64 lbl_80640ED8;

void fn_8009F6C4(void) {
    (*(f64 *)((u8 *)(lbl_8063D4F8) + (0x100))) = (f64) lbl_80640ED8;
    (*(s32 *)((u8 *)(lbl_8063D4F8) + (0x108))) = (s32) ((*(s32 *)((u8 *)(lbl_8063D4F8) + (0x108))) & 0x1FFFFFFF);
    (*(s32 *)((u8 *)(lbl_8063D4F8) + (0x108))) = (s32) ((*(s32 *)((u8 *)(lbl_8063D4F8) + (0x108))) & 0xE7FFFFFF);
    (*(s32 *)((u8 *)(lbl_8063D4F8) + (0x108))) = (s32) ((*(s32 *)((u8 *)(lbl_8063D4F8) + (0x108))) & 0xF9FFFFFF);
}
}

extern "C" {

u32 fn_800A04B0(void) {
    u32 temp_r0;

    if ((u16) (*(u16 *)((u8 *)(lbl_8063D4F8) + (0xFC))) == 0x41) {
        temp_r0 = (u32) (*(u32 *)((u8 *)(lbl_8063D4F8) + (0x108))) >> 0x1DU;
        if (temp_r0 != 7) {
            return temp_r0;
        }
        return 0x8000U;
    }
    return 0xFFFFU;
}
}
