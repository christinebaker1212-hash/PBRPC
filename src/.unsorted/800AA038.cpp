#include ".unsorted/800AA038.hpp"

#include "common.hpp"

extern "C" {

void fn_800F92D8();

void fn_800AA080(void) {
    fn_800F92D8();
}
}

extern "C" {

s32 fn_800579FC__Fi(s32);
s32 fn_800F8BF4(s32);
extern s8 lbl_8063EEA6;
extern s32 lbl_8063EEA8;
extern s8 lbl_8063EEB4;

void fn_800AA038(void) {
    lbl_8063EEB4 = 1;
    fn_800F8BF4(1);
    lbl_8063EEA6 = 1;
    lbl_8063EEA8 = 0;
    fn_800579FC__Fi(1);
}
}

extern "C" {

s32 BoxPokemon_GetValue__FP10BoxPokemonUlPv(s32, s32, s32);
s32 fn_8015F6E0(void);
extern s32 lbl_8063EEAC;

s32 fn_800AA354(s32 arg0, s32 *arg1, s32 arg2) {
    s32 temp_r30;
    s32 temp_r30_2;
    s32 temp_r31;
    s32 var_r29;

    var_r29 = *arg1;
    temp_r31 = fn_8015F6E0();
    if (arg2 != 0) {
        do {
            if (var_r29 == 0) {
                var_r29 = 0x21C;
            }
            var_r29 -= 1;
            temp_r30_2 = temp_r31 + (var_r29 * 0x88) + 0x5F8;
        } while (BoxPokemon_GetValue__FP10BoxPokemonUlPv(temp_r30_2, 5, 0) == 0);
        *arg1 = var_r29;
        lbl_8063EEAC = BoxPokemon_GetValue__FP10BoxPokemonUlPv(temp_r30_2, 5, 0);
        return temp_r30_2;
    }
    do {
        var_r29 += 1;
        if ((u32) var_r29 == 0x21CU) {
            var_r29 = 0;
        }
        temp_r30 = temp_r31 + (var_r29 * 0x88) + 0x5F8;
    } while (BoxPokemon_GetValue__FP10BoxPokemonUlPv(temp_r30, 5, 0) == 0);
    *arg1 = var_r29;
    lbl_8063EEAC = BoxPokemon_GetValue__FP10BoxPokemonUlPv(temp_r30, 5, 0);
    return temp_r30;
}
}

extern "C" {

s32 fn_8015CC78(s32, s32, s32, s32);
s32 fn_80250134(s32, s32, s32, s32, s32, s32);
__declspec(section ".data") extern s32 lbl_80418508;

void fn_800AA2E8() {
    fn_8015CC78((s32) (u32) ((100.0f) * (*(f32 *)((u8 *)(((u8 *)(u8 *)&lbl_80418508 + (lbl_8063EEAC * 0x10))) + (0xC)))), 5, 0xE, 1);
    fn_80250134(0x2D73, 0x190, 0x14A, 0, 0, -1);
}
}
