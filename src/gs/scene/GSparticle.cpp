#include "common.hpp"

extern "C" {

s32 __dt__6GSnullFv(s32, s32);
s32 fn_80207018(s32);
s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gGameHeap;
__declspec(section ".data") extern s32 lbl_80423720;

u8 *fn_801F9ABC(u8 *arg0, s32 arg1) {
    s32 temp_r0;

    if (arg0 != NULL) {
        temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x138)));
        (*(s32 **)((u8 *)(arg0) + (0x100))) = &lbl_80423720;
        if (temp_r0 != 0) {
            fn_80207018(temp_r0);
        }
        __dt__6GSnullFv((s32) arg0, 0);
        if (arg1 > 0) {
            freeToHeap__5GSmemFP12MEMiHeapHeadPv(gGameHeap, (s32) arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_801FA044(u8 *arg0) {
    s32 temp_r0;
    u8 *temp_r3;

    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x12C)));
    if (temp_r0 != 0) {
        return temp_r0;
    }
    temp_r3 = (*(u8 **)((u8 *)(arg0) + (0xB8)));
    if (temp_r3 != NULL) {
        return (*(s32 *)((u8 *)(temp_r3) + (0x3C)));
    }
    return 0;
}
}

extern "C" {

struct S_version_806276D8 { s8 f_0; u8 pad_1[1]; s16 f_2; s8 f_4; };
extern struct S_version_806276D8 version_806276D8;

void fn_801FA074() {
    version_806276D8.f_0 = 1;
    version_806276D8.f_2 = 4;
    version_806276D8.f_4 = 0;
}
}
