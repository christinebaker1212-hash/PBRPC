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

extern "C" {

s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);
extern u16 lbl_8063ECB8;

void fn_8007ED44(s32 arg0, s32 arg1) {
    s32 sp8;

    fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    switch (sp8) {
    case 1:
        (*(u8 *)((u8 *)(arg1) + (2))) = 0xEF;
        (*(u8 *)((u8 *)(arg1) + (3))) = 0xEF;
        (*(u8 *)((u8 *)(arg1) + (4))) = 0xEF;
        (*(u8 *)((u8 *)(arg1) + (5))) = 0xFF;
        switch ((s32) lbl_8063ECB8) {                   /* irregular */
        case 0:
            fn_80253EB4(arg0, arg1, 2, 0x2E59);
            return;
        case 3:
            fn_80253EB4(arg0, arg1, 2, 0x2E6A);
            return;
        case 4:
            fn_80253EB4(arg0, arg1, 2, 0x2E76);
            return;
        case 5:
            fn_80253EB4(arg0, arg1, 2, 0x2E6F);
            return;
        }
    }
    return;
}
}

extern "C" {

s32 fn_80059A3C(s32, s32);
s32 fn_80253EDC(s32, s32, s32, s32);

void fn_8007F328(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC(arg0, arg1, 3, (s32) &sp8);
    switch (sp8) {                                  /* irregular */
    case 2:
        fn_80253EDC(arg0, arg1, 6, (s32) sp10);
        fn_80059A3C(2, (s32) sp10);
        return;
    case 3:
        fn_80253EDC(arg0, arg1, 6, (s32) sp10);
        fn_80059A3C(3, (s32) sp10);
        return;
    case 4:
        if ((s32) (*(u8 *)((u8 *)(&(*(s32 (*))&lbl_8047A968)) + (1))) != 0) {
            fn_80253EDC(arg0, arg1, 6, (s32) sp10);
            fn_80059A3C(4, (s32) sp10);
        }
        /* fallthrough */
    case 0:
        return;
    }
}
}

extern "C" {

void fn_8007F3D8(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 1:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(1), (s32)((s32) sp10));
        return;
    case 0:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(2), (s32)((s32) sp10));
        return;
    }
}
}

extern "C" {

void fn_8007F478(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {
    case 5:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(1), (s32)((s32) sp10));
        return;
    case 8:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(2), (s32)((s32) sp10));
        return;
    case 11:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(3), (s32)((s32) sp10));
        return;
    case 14:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(4), (s32)((s32) sp10));
        return;
    case 17:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(5), (s32)((s32) sp10));
        /* fallthrough */
    default:
        return;
    }
}
}

extern "C" {

s32 WPADProbe(s32, s32);

void fn_8007F590(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 spC;
    s32 sp8;

    WPADProbe(0, (s32) &sp8);
    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &spC));
    switch (spC) {                                  /* irregular */
    case 3:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(1), (s32)((s32) sp10));
        return;
    case 6:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(2), (s32)((s32) sp10));
        return;
    case 9:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(3), (s32)((s32) sp10));
        return;
    }
}
}

extern "C" {

void fn_8007F674(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 1:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(1), (s32)((s32) sp10));
        return;
    case 2:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(2), (s32)((s32) sp10));
        return;
    }
}
}
