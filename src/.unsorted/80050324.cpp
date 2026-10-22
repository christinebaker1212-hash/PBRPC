#include ".unsorted/80050324.hpp"

#include "common.hpp"

extern "C" {

void fn_800520B0(void) {}
void fn_8005376C(void) {}
void fn_80054154(void) {}
void fn_80054490(void) {}
void fn_80054494(void) {}
u32 fn_800547F4(u8 *p) {
    return *(u32 *)(p + 0x38);
}
u32 fn_8005498C(u8 *p) {
    return *(u32 *)(p + 0x40);
}
u32 fn_80055278(u8 *p) {
    return *(u32 *)(p + 0x3c);
}
s32 fn_80055474(void) {
    return 0;
}
}

#include "common.hpp"

extern "C" {

extern u8 lbl_8040AEA4[];

void fn_80050388(u8 *p) {
    *(u32 *)(p + 0x0) = 0x0;
}
void fn_800505C0(u8 *p) {
    *(u32 *)(p + 0x0) = 0x0;
}
void fn_80050BE0(u8 *p) {
    *(u32 *)(p + 0x0) = 0x0;
}
void fn_80052060(u8 *p) {
    *(u8 **)(p + 0x0) = lbl_8040AEA4;
}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_80051468(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_80051FB4(s32 arg0, u32 arg1) {
    if (arg1 >= 0x64U) {
        return 0;
    }
    return arg0 + (arg1 * 0x28) + 0x248;
}
}

extern "C" {

s32 fn_80052070(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_80253E10(s16, s32, f32);
extern f32 lbl_80640B10;

void fn_80054200(s16 arg0) {
    fn_80253E10(arg0, 4, lbl_80640B10);
}
}

extern "C" {

void fn_800574B0(void) {

}
}
