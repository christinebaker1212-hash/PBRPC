#include "common.hpp"

extern "C" {

s32 initTransform__6GSnullFb(s32, s32);

void fn_801E62B8(s32 arg0, s32 arg1) {
    u8 *temp_r3;
    u8 *temp_r3_2;

    initTransform__6GSnullFb(arg0, arg1);
    temp_r3 = (*(u8 **)((u8 *)(arg0) + (0x10C)));
    if (temp_r3 != NULL) {
        if ((*(s32 *)((u8 *)(temp_r3) + (0x30))) & 0x10) {
            (*(s32 *)((u8 *)(arg0) + (0x104))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0x104))) | 1);
        } else {
            (*(s32 *)((u8 *)(arg0) + (0x104))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0x104))) & 0xFFFFFFFE);
        }
        temp_r3_2 = (*(u8 **)((u8 *)(arg0) + (0x10C)));
        (*(u8 *)((u8 *)(arg0) + (0x110))) = (u8) (*(u8 *)((u8 *)(temp_r3_2) + (0x34)));
        (*(u8 *)((u8 *)(arg0) + (0x111))) = (u8) (*(u8 *)((u8 *)(temp_r3_2) + (0x35)));
        (*(u8 *)((u8 *)(arg0) + (0x112))) = (u8) (*(u8 *)((u8 *)(temp_r3_2) + (0x36)));
        (*(u8 *)((u8 *)(arg0) + (0x113))) = (u8) (*(u8 *)((u8 *)(temp_r3_2) + (0x37)));
        (*(u8 *)((u8 *)(arg0) + (0x114))) = (u8) (*(u8 *)((u8 *)(temp_r3_2) + (0x38)));
        (*(u8 *)((u8 *)(arg0) + (0x115))) = (u8) (*(u8 *)((u8 *)(temp_r3_2) + (0x39)));
        (*(u8 *)((u8 *)(arg0) + (0x116))) = (u8) (*(u8 *)((u8 *)(temp_r3_2) + (0x3A)));
        (*(u8 *)((u8 *)(arg0) + (0x117))) = (u8) (*(u8 *)((u8 *)(temp_r3_2) + (0x3B)));
        (*(f32 *)((u8 *)(arg0) + (0x118))) = (f32) (*(f32 *)((u8 *)(temp_r3_2) + (0x3C)));
        (*(s32 *)((u8 *)(arg0) + (0x11C))) = (s32) (*(s32 *)((u8 *)(temp_r3_2) + (0x40)));
        (*(f32 *)((u8 *)(arg0) + (0x120))) = (f32) (*(f32 *)((u8 *)(temp_r3_2) + (0x44)));
        (*(f32 *)((u8 *)(arg0) + (0x124))) = (f32) (*(f32 *)((u8 *)(temp_r3_2) + (0x48)));
        (*(s32 *)((u8 *)(arg0) + (0x128))) = (s32) (*(s32 *)((u8 *)(temp_r3_2) + (0x4C)));
        (*(f32 *)((u8 *)(arg0) + (0x12C))) = (f32) (*(f32 *)((u8 *)(temp_r3_2) + (0x50)));
    }
}
}

extern "C" {

s32 fn_801E1440__FP13GSchannelDatafP7GScolor(s32, s32, f32);

void fn_801E6BB0__7GSlightFP17GSanimationObjectP13GSchannelDatafb(s32 arg0, u8 *arg1, s32 arg2, f32 farg0) {
    if ((arg2 == 0) && ((s32) (*(u8 *)((u8 *)(arg1) + (1))) == 0x13)) {
        fn_801E1440__FP13GSchannelDatafP7GScolor((s32) arg1, arg0 + 0x110, farg0);
    }
}
}

extern "C" {

struct S_lbl_8063F398 { s8 f_0; u8 pad_1[1]; s16 f_2; s8 f_4; };
extern struct S_lbl_8063F398 lbl_8063F398;

void fn_801E6BD8() {
    lbl_8063F398.f_0 = 1;
    lbl_8063F398.f_2 = 4;
    lbl_8063F398.f_4 = 0;
}
}
