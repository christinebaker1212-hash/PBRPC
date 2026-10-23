#include "common.hpp"

extern "C" {

s32 eulerToQuat__6GSmathFP6GSquatP6GSvec3(u8 *, u8 *);
s32 initTransform__6GSnullFb(void);

void fn_801E466C(u8 *arg0) {
    u8 *temp_r5;

    initTransform__6GSnullFb();
    temp_r5 = (*(u8 **)((u8 *)(arg0) + (0x108)));
    if (temp_r5 != NULL) {
        (*(s32 *)((u8 *)(arg0) + (0x104))) = 0;
        (*(f32 *)((u8 *)(arg0) + (0x17C))) = (f32) (*(f32 *)((u8 *)(temp_r5) + (0x34)));
        (*(f32 *)((u8 *)(arg0) + (0x180))) = (f32) (*(f32 *)((u8 *)(temp_r5) + (0x38)));
        (*(f32 *)((u8 *)(arg0) + (0x184))) = (f32) (*(f32 *)((u8 *)(temp_r5) + (0x3C)));
        eulerToQuat__6GSmathFP6GSquatP6GSvec3(arg0 + 0x16C, arg0 + 0x17C);
    }
}
}

extern "C" {

struct S_lbl_8063F380 { s8 f_0; u8 pad_1[1]; s16 f_2; s8 f_4; };
extern struct S_lbl_8063F380 lbl_8063F380;

void fn_801E472C() {
    lbl_8063F380.f_0 = 1;
    lbl_8063F380.f_2 = 4;
    lbl_8063F380.f_4 = 0;
}
}
