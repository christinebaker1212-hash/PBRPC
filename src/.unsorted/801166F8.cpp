#include ".unsorted/801166F8.hpp"

#include "common.hpp"

extern "C" {

void fn_80116708(void) {}
void fn_80116DC4(void) {}
void fn_8011838C(void) {}
}

#include "common.hpp"

extern "C" {

extern u8 lbl_8041B894[];

void fn_801166F8(u8 *p) {
    *(u8 **)(p + 0x0) = lbl_8041B894;
}
}

extern "C" {

extern u8 *lbl_8063D544;

void fn_80116344(void) {
    (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) = (u16) ((*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) & 0xFFFFFDFF);
}
}

extern "C" {

void fn_80116358(void) {
    (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) = (u16) ((*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) | 0x200);
}
}

extern "C" {

s32 fn_80117FDC(u8 *, s32);
s32 fn_80118070(u8 *, s32);
s32 fn_80118CDC(u8 *, s32);

void fn_801163C8(void) {
    fn_80118070(lbl_8063D544, 0);
    fn_80117FDC(lbl_8063D544, 4);
    fn_80118CDC(lbl_8063D544, 0);
    (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) = (u16) ((*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) | 0x1000);
    (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) = (u16) ((*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) | 0x800);
    (*(s16 *)((u8 *)(lbl_8063D544) + (0x20E))) = 0;
}
}

extern "C" {

void fn_801164A0(void) {
    fn_80118070(lbl_8063D544, 0);
    fn_80117FDC(lbl_8063D544, 7);
    fn_80118CDC(lbl_8063D544, 0);
    (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) = (u16) ((*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) | 0x1000);
    (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) = (u16) ((*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) | 0x800);
    (*(s16 *)((u8 *)(lbl_8063D544) + (0x20E))) = 0;
    (*(s32 *)((u8 *)(lbl_8063D544) + (0xDC))) = 0x281;
}
}

extern "C" {

void fn_80116684(void) {

}
}
