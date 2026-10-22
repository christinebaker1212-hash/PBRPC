#include ".unsorted/80254460.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063F908;

u32 fn_802544D0(void) {
    return lbl_8063F908;
}
s32 fn_80256520(void) {
    return 1;
}
}

#include "common.hpp"

extern "C" {

void fn_80377024(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

void fn_802558FC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_80377024(*(u32 *)(a0 + 0x0), a1, a2, a3, a4, a5, a6, a7);
}
void fn_80256E34(u8 *p) {
    *(u32 *)(p + 0x0) = 0x0;
}
void fn_80256E80(u8 *p) {
    *(u32 *)(p + 0x0) = 0x0;
}
}

extern "C" {

s32 LoadGroup__Q34nw4r3snd18SoundArchivePlayerFUlPQ34nw4r3snd22SoundMemoryAllocatableUl(s32, u32, s32, s32);
u32 fn_80255904(void);

s32 fn_80254A30(u8 *arg0, u32 arg1, s32 arg2, s32 arg3) {
    s32 var_r31;

    var_r31 = arg3;
    if (arg1 >= fn_80255904()) {
        return 0;
    }
    if ((var_r31 != 0) && (var_r31 & 0x3F)) {
        var_r31 = (var_r31 + 0x1F) & 0xFFFFFFE0;
    }
    return LoadGroup__Q34nw4r3snd18SoundArchivePlayerFUlPQ34nw4r3snd22SoundMemoryAllocatableUl((*(s32 *)((u8 *)(arg0) + (4))), arg1, (*(s32 *)((u8 *)(arg0) + (8))) + (arg2 * 0x2C), var_r31) != 0;
}
}

extern "C" {

s32 GetSoundPlayer__Q34nw4r3snd18SoundArchivePlayerFUl(s32);
s32 SetVolume__Q34nw4r3snd11SoundPlayerFf(f32);

void fn_80255520(u8 *arg0, f32 farg0) {
    GetSoundPlayer__Q34nw4r3snd18SoundArchivePlayerFUl((*(s32 *)((u8 *)(arg0) + (4))));
    SetVolume__Q34nw4r3snd11SoundPlayerFf(farg0);
}
}

extern "C" {

u32 fn_80255968(void);

s32 fn_80255710(void) {
    return (fn_80255968() >> 0x1FU) ^ 1;
}
}

extern "C" {

void fn_80256880(u8 *arg0, s8 arg1, s32 arg2, f32 farg0) {
    (*(s8 *)((u8 *)(arg0) + (0xF4))) = arg1;
    (*(f32 *)((u8 *)(arg0) + (0xF8))) = farg0;
    (*(s32 *)((u8 *)(arg0) + (0xFC))) = arg2;
}
}

extern "C" {

s32 fn_80256E24(u8 *arg0) {
    return ((u32) (*(u32 *)((u8 *)(arg0) + (0x58))) >> 0x1FU) ^ 1;
}
}

extern "C" {

void fn_80259104(s32 *arg0) {
    *arg0 = 0;
}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_80259110(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

void fn_80259480(s32 *arg0) {
    *arg0 = 0;
}
}

extern "C" {

s32 Update__Q34nw4r3snd18SoundArchivePlayerFv(s32);
s32 fn_80254C74(void);

void fn_802594E0(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x48))) > 0) {
        fn_80254C74();
    }
    Update__Q34nw4r3snd18SoundArchivePlayerFv((*(s32 *)((u8 *)(arg0) + (4))));
}
}
