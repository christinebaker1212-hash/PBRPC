#include ".unsorted/8017C588.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063F238;

u32 fn_8017C588(void) {
    return lbl_8063F238;
}
u8 fn_8017C648(u8 *p) {
    return *(u8 *)(p + 0x0);
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 fn_8017C5D0(void);

s32 fn_8017C5D0(void) {
    s32 var_r3;

    var_r3 = lbl_8063F238;
    if (var_r3 != 0) {
        var_r3 = __dl__FPv(var_r3);
        lbl_8063F238 = 0;
    }
    return var_r3;
}
}

extern "C" {

s32 __nw__FUl(s32);
s32 fn_8017C604(void);

void fn_8017C590(void) {
    s32 var_r3;

    if ((s32) lbl_8063F238 == 0) {
        var_r3 = __nw__FUl(0xBC);
        if (var_r3 != 0) {
            var_r3 = fn_8017C604();
        }
        lbl_8063F238 = var_r3;
    }
}
}

extern "C" {

s32 fn_8017C8FC(s32, s32);
s32 memcpy(s32, s32, s32);

void fn_8017C650(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *var_r31;
    s32 var_r30;

    if ((s32) *arg0 != 0) {
        var_r31 = arg1;
        var_r30 = 0;
        while (var_r30 < arg2) {
            memcpy((s32)(var_r31 + 0x1C), (s32)(fn_8017C8FC((s32) arg0, (s32) (*(u16 *)((u8 *)(var_r31) + (4))))), (s32)(0x20U));
            var_r30 += 1;
            var_r31 += 0x3C;
        }
    }
}
}

extern "C" {

s32 Party_GetPokemonBySlotIndex__FPC5Partyl(s32, s32);
s32 Pokemon_GetValue__FP7PokemonUlPv(s32, s32, s32);
s32 Pokemon_SetValue__FP7PokemonUlPCv(s32, s32, s32);

void fn_8017C7F0(u8 *arg0, s32 arg1, s32 arg2) {
    s32 var_r31;
    s32 temp_r3_2;
    s32 temp_r3;

    if ((s32) *arg0 != 0) {
        var_r31 = 0;
        (*(s32 *)((u8 *)((arg0 + (arg1 * 4))) + (0xB4))) = arg2;
        do {
            temp_r3 = Party_GetPokemonBySlotIndex__FPC5Partyl(arg2, var_r31);
            temp_r3_2 = fn_8017C8FC((s32)((s32) arg0), (s32)(Pokemon_GetValue__FP7PokemonUlPv(temp_r3, 5, 0)));
            if (temp_r3_2 != 0) {
                Pokemon_SetValue__FP7PokemonUlPCv(temp_r3, 0x74, temp_r3_2);
            }
            var_r31 += 1;
        } while (var_r31 < 6);
    }
}
}
