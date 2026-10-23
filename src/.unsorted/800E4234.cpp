#include ".unsorted/800E4234.hpp"

#include "common.hpp"

extern "C" {

void fn_800E46A0(void) {}
void fn_800E5670(void) {}
}

extern "C" {

void fn_800E695C(u8 *arg0, s32 arg1) {
    if (arg1 != 0) {
        (*(u8 *)((u8 *)(arg0) + (7))) = (u8) ((*(u8 *)((u8 *)(arg0) + (7))) | 1);
        return;
    }
    (*(u8 *)((u8 *)(arg0) + (7))) = (u8) ((*(u8 *)((u8 *)(arg0) + (7))) & 0xFE);
}
}

extern "C" {

void fn_800E6984(u8 *arg0, s32 arg1) {
    u16 temp_r0;

    temp_r0 = (*(u16 *)((u8 *)(arg0) + (0x16FE))) | 2;
    (*(u16 *)((u8 *)(arg0) + (0x16FE))) = temp_r0;
    if (arg1 != 0) {
        (*(u16 *)((u8 *)(arg0) + (0x16FE))) = (u16) (temp_r0 | 4);
    }
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8047D604;

void fn_800E512C(u32 arg0, s32 arg1) {
    u8 *temp_r4;
    u8 *temp_r4_2;

    if (arg0 <= 7U) {
        if (arg1 != 0) {
            temp_r4 = (unsigned char *)((*(s32 *)((u8 *)(&lbl_8047D604) + (0))) + ((*(u8 *)((u8 *)(&lbl_8047D604) + (0xC))) * 0x6EC));
            (*(u8 *)((u8 *)(temp_r4) + (0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_r4) + (0x1E))) | (1 << arg0));
            return;
        }
        temp_r4_2 = (unsigned char *)((*(s32 *)((u8 *)(&lbl_8047D604) + (0))) + ((*(u8 *)((u8 *)(&lbl_8047D604) + (0xC))) * 0x6EC));
        (*(u8 *)((u8 *)(temp_r4_2) + (0x1E))) = (u8) ((*(u8 *)((u8 *)(temp_r4_2) + (0x1E))) & ~(1 << arg0));
    }
}
}

extern "C" {

void fn_800E520C(u8 arg0) {
    if (arg0 < 0x9FU) {
        (*(u8 *)((u8 *)(&lbl_8047D604) + (0xC))) = arg0;
    }
}
}

extern "C" {

void fn_800E59FC(s8 arg0) {
    (*(s8 *)((u8 *)(((*(s32 *)((u8 *)(&lbl_8047D604) + (0))) + ((*(u8 *)((u8 *)(&lbl_8047D604) + (0xC))) * 0x6EC))) + (0x1EE))) = arg0;
}
}

extern "C" {

void fn_800E5A1C(s32 *arg0, u8 *arg1) {
    u8 *temp_r5;

    temp_r5 = (unsigned char *)((*(s32 *)((u8 *)(&lbl_8047D604) + (0))) + ((*(u8 *)((u8 *)(&lbl_8047D604) + (0xC))) * 0x6EC));
    *arg0 = (s32) (*(s16 *)((u8 *)(temp_r5) + (0x20)));
    *arg1 = (*(u8 *)((u8 *)(temp_r5) + (0x1EE)));
}
}

extern "C" {

s32 fn_800E5AD0(s32 arg0) {
    if (arg0 < 0) {
        return (*(s32 *)((u8 *)(&lbl_8047D604) + (0))) + ((*(u8 *)((u8 *)(&lbl_8047D604) + (0xC))) * 0x6EC);
    }
    if (arg0 < 0x9F) {
        return (*(s32 *)((u8 *)(&lbl_8047D604) + (0))) + (arg0 * 0x6EC);
    }
    return 0;
}
}

extern "C" {

s32 fn_800E63D0() {
    return ((u8) (*(u8 *)((u8 *)(&lbl_8047D604) + (0xFC))) >> 6U) & 3;
}
}

extern "C" {

s32 fn_800E63E4(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return ((u8) (*(u8 *)((u8 *)(&lbl_8047D604) + (0xFC))) >> 3U) & 1;
    case 1:
        return ((u8) (*(u8 *)((u8 *)(&lbl_8047D604) + (0xFC))) >> 2U) & 1;
    case 2:
        return ((u8) (*(u8 *)((u8 *)(&lbl_8047D604) + (0xFD))) >> 7U) & 1;
    default:
        return 0xFF;
    }
}
}

extern "C" {

s32 fn_800E644C() {
    return ((u8) (*(u8 *)((u8 *)(&lbl_8047D604) + (0xFC))) >> 4U) & 3;
}
}

extern "C" {

void fn_800E6478() {
    (*(u8 *)((u8 *)(&lbl_8047D604) + (0x38))) = 0xFF;
    (*(u8 *)((u8 *)(&lbl_8047D604) + (0x39))) = 0xFF;
    (*(u8 *)((u8 *)(&lbl_8047D604) + (0x3A))) = 0xFF;
    (*(u8 *)((u8 *)(&lbl_8047D604) + (0x3B))) = 0xFF;
}
}

extern "C" {

s32 __register_global_object(s32 *, s32 *, s32 *);
s32 fn_800DA8F4(s32 *, s32, s32, s32);
s32 fn_800E96C4(s32 *);
void fn_800E96C8(void);
__declspec(section ".data") extern s32 lbl_8047D5F8;
extern u8 lbl_8063EF08;

void fn_800E9668() {
    fn_800DA8F4((s32 *)(&lbl_8063EF08), (s32)(1), (s32)(4), (s32)(0));
    fn_800E96C4(&lbl_8047D604);
    __register_global_object((s32 *)(&lbl_8047D604), (s32 *)(&fn_800E96C8), (s32 *)(&lbl_8047D5F8));
}
}

extern "C" {

s32 fn_800E5674(s32, s32, s32);

void fn_800E59B8(s32 arg0, s32 arg1) {
    fn_800E5674(arg0, arg1, (*(s32 *)((u8 *)(&lbl_8047D604) + (0))) + ((*(u8 *)((u8 *)(&lbl_8047D604) + (0xC))) * 0x6EC));
}
}
