#include "common.hpp"

void fn_8005BCA0(void *);
void fn_8005C5DC(void *);

u8 lbl_80478178[0x10]; // dummy

void fn_8005C9C8() {
    fn_8005BCA0(lbl_80478178);
    fn_8005C5DC(lbl_80478178);
}

extern "C" {

void fn_8005BC54(u8 *arg0) {
    u8 *var_r6;
    u32 var_r7;
    u16 temp_r0;

    var_r6 = arg0;
    var_r7 = 0U;
    while (var_r7 < (u16) (*(u16 *)((u8 *)(arg0) + (0x96)))) {
        temp_r0 = (*(u16 *)((u8 *)(var_r6) + (0x74)));
        var_r6 += 2;
        var_r7 += 1;
        (*(s8 *)((u8 *)(((*(s32 *)((u8 *)(arg0) + (0x24))) + (temp_r0 * 0x28))) + (0xC))) = 1;
    }
}
}

extern "C" {

void fn_8005C590(u8 *arg0) {
    u8 *var_r6;
    u32 var_r7;
    u16 temp_r0;

    var_r6 = arg0;
    var_r7 = 0U;
    while (var_r7 < (u16) (*(u16 *)((u8 *)(arg0) + (0x11E)))) {
        temp_r0 = (*(u16 *)((u8 *)(var_r6) + (0xFC)));
        var_r6 += 2;
        var_r7 += 1;
        (*(s8 *)((u8 *)(((*(s32 *)((u8 *)(arg0) + (0xAC))) + (temp_r0 * 0x28))) + (0xC))) = 1;
    }
}
}

extern "C" {

s32 fn_8005B4A4(s32, s32);

void fn_8005C9A8(s32 arg0) {
    fn_8005B4A4((s32) &lbl_80478178, arg0);
}
}

extern "C" {

s32 fn_8005B5BC(s32, s32);

void fn_8005C9B8(s32 arg0) {
    fn_8005B5BC((s32) &lbl_80478178, arg0);
}
}
