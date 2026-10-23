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

extern "C" {

void fn_801166A4(s32 arg0, s32 arg1, s32 arg2);      /* extern */
s32 fn_801172A4(u8 *, s32);               /* extern */
s32 fn_80253DB0(s16, s32, s32);         /* extern */
s32 fn_80253E4C(s16, s32, s32 *);           /* extern */

s32 fn_80118070(u8 *arg0, s32 arg1) {
    s32 sp8;

    if (arg1 != 0) {
        fn_80253E4C((*(s16 *)((u8 *)(lbl_8063D544) + (0x92))), 8, &sp8);
        if (sp8 == 0) {
            fn_801166A4((s32)(lbl_8063D544), (s32)(7), (s32)(1));
            fn_80253DB0((*(s16 *)((u8 *)(lbl_8063D544) + (0x92))), 4, 0);
        }
        fn_80253E4C((*(s16 *)((u8 *)(lbl_8063D544) + (0x96))), 8, &sp8);
        if (sp8 == 0) {
            fn_801166A4((s32)(lbl_8063D544), (s32)(9), (s32)(1));
            fn_80253DB0((*(s16 *)((u8 *)(lbl_8063D544) + (0x96))), 2, 0);
        }
    }
    (*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) = (u16) ((*(u16 *)((u8 *)(lbl_8063D544) + (0x220))) | 0x8000);
    return fn_801172A4(lbl_8063D544, 1);
}
}

extern "C" {

s32 fn_8000A72C(s32, s32);
s32 fn_8000A734(void);
s32 fn_8011636C(s32);

s32 fn_8011636C(s32 arg0) {
    return fn_8000A72C(fn_8000A734(), arg0);
}
}

extern "C" {

s32 fn_801163A0(s32);

s32 fn_801163A0(s32 arg0) {
    return fn_8000A72C((s32)(fn_8000A734()), (s32)(0));
}
}

extern "C" {

s32 fn_80116688(s32, s32, s32);

s32 fn_80116688(s32 arg0, s32 arg1, s32 arg2) {
    return fn_80253DB0((s16)((s32) (*(s16 *)((u8 *)((lbl_8063D544 + (arg1 * 2))) + (0x84)))), (s32)(arg2), (s32)(0));
}
}

extern "C" {

s32 fn_80117630(s32, s32);
s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_80117630(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    if (sp8 != 0xE) {
        if (sp8 < 0xE) {
            if (sp8 != 0xB) {
                return temp_r3;
            }
            goto block_6;
        }
        if (sp8 != 0x11) {
            return temp_r3;
        }
        goto block_6;
    }
block_6:
    return fn_80253EB4(arg0, arg1, 1, 0);
}
}

extern "C" {

s32 fn_80118790(s32, s32);

s32 fn_80118790(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    if (sp8 != 0xE) {
        if (sp8 < 0xE) {
            if (sp8 != 0xB) {
                return temp_r3;
            }
            goto block_6;
        }
        if (sp8 != 0x11) {
            return temp_r3;
        }
        goto block_6;
    }
block_6:
    return fn_80253EB4(arg0, arg1, 1, 0);
}
}

extern "C" {

s32 fn_80253DF0(s32, s32, s32);

void fn_801166A4(s32 arg0, s32 arg1, s32 arg2) {
    fn_80253DF0((s32) (*(s16 *)((u8 *)((lbl_8063D544 + ((arg1 * 2) & 0x1FFFE))) + (0x84))), 8, arg2);
}
}
