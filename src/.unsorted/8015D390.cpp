#include ".unsorted/8015D390.hpp"

#include "common.hpp"

extern "C" {

extern u8 lbl_8063F018;

u8 fn_8015E62C(void) {
    return lbl_8063F018;
}
}

#include "common.hpp"

extern "C" {

extern u8 lbl_80488300[];

u32 fn_8015F660(void) {
    return *(u32 *)(lbl_80488300 + 0x18);
}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_8015D390(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_80161208(s32);

void fn_801611CC(void) {
    fn_80161208(0);
    fn_80161208(1);
    fn_80161208(2);
    fn_80161208(3);
}
}

extern "C" {

u8 SCGetSoundMode(void);
u8 *fn_8015F690(void);
s32 fn_802544D8(s32);
s32 fn_80259408(s32);
extern s8 lbl_8063F01A;

void fn_80161308(void) {
    u8 temp_r3;
    u8 *temp_r30;

    temp_r30 = fn_8015F690();
    temp_r3 = SCGetSoundMode();
    switch ((s32) temp_r3) {                        /* irregular */
    case 0:
        (*(s8 *)((u8 *)(temp_r30) + (0x43))) = 0;
        fn_802544D8(3);
        fn_80259408(0);
        return;
    case 1:
        (*(s8 *)((u8 *)(temp_r30) + (0x43))) = 1;
        fn_802544D8(0);
        fn_80259408(1);
        return;
    case 2:
        (*(s8 *)((u8 *)(temp_r30) + (0x43))) = 1;
        fn_802544D8(0);
        fn_80259408(1);
        lbl_8063F01A = 1;
        return;
    }
}
}

extern "C" {

s32 fn_801610A4(s32, s32);
extern s32 lbl_8063F014;

s32 fn_801610A4(s32 arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 0:
        lbl_8063F014 = 4;
        return arg0;
    case -1:
        lbl_8063F014 = 0xB;
        return arg0;
    case -3:
        lbl_8063F014 = 0xB;
        return arg0;
    default:
        lbl_8063F014 = 0xD;
        return arg0;
    }
}
}

extern "C" {

s32 fn_801610F4(s32, s32);

s32 fn_801610F4(s32 arg0, s32 arg1) {
    switch (arg1) {                                 /* irregular */
    case 0:
        lbl_8063F014 = 8;
        return arg0;
    case -1:
        lbl_8063F014 = 0xB;
        return arg0;
    case -3:
        lbl_8063F014 = 0xB;
        return arg0;
    case -5:
        lbl_8063F014 = 0xD;
        return arg0;
    default:
        lbl_8063F014 = 0xD;
        return arg0;
    }
}
}

extern "C" {

s32 fn_8015F6A0(void);
s32 fn_801612DC(void);
s32 memset(s32, s32, s32);

s32 fn_801612DC(void) {
    return memset(fn_8015F6A0(), 0, 0x100);
}
}

extern "C" {

s32 fn_8015D4EC() {
    return ((u32) (*(u32 *)((u8 *)(&lbl_80488300) + (0x28))) >> 0x1EU) & 1;
}
}

extern "C" {

u8 * fn_8015F690() {
    return (u8 *)(lbl_80488300 + 0x100);
}
}

extern "C" {

void fn_8015F72C(u8 arg0) {
    u8 var_r3;

    var_r3 = arg0;
    if (var_r3 >= 4U) {
        var_r3 = 0;
    }
    (*(u8 *)((u8 *)(lbl_80488300) + (0x50))) = var_r3;
}
}

extern "C" {

u8 fn_8015F748() {
    return (*(u8 *)((u8 *)(lbl_80488300) + (0x50)));
}
}

extern "C" {

s32 fn_8007D224(void);

void fn_80161294() {
    u8 *temp_r3;

    temp_r3 = (unsigned char *)(((s32)fn_8015F690()));
    memset((s32)((s32)(temp_r3)), (s32)((s32)(0)), (s32)((s32)(0x50U)));
    fn_8007D224();
    (*(s8 *)((u8 *)(temp_r3) + (0x45))) = 1;
    ((s32 (*)(void))fn_80161308)();
}
}

extern "C" {

s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;

void fn_80162724() {
    freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, (*(s32 *)((u8 *)(&lbl_80488300) + (0x10))));
    (*(s32 *)((u8 *)(&lbl_80488300) + (0x10))) = 0;
}
}
