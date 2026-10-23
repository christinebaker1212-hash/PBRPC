#include ".unsorted/8009A2BC.hpp"

#include "common.hpp"

extern "C" {

s32 BoxPokemon_GetValue__FP10BoxPokemonUlPv(u8 *, s32, s32);
__declspec(section ".data") extern s32 lbl_8047B100;

u8 *fn_8009C0F0(s32 arg0, s32 *arg1, s32 arg2) {
    u8 *temp_r30;
    s32 var_r29;

    var_r29 = *arg1;
    do {
        if (arg2 != 0) {
            if (var_r29 == 0) {
                var_r29 = 0xB;
            } else {
                var_r29 -= 1;
            }
        } else {
            var_r29 += 1;
            if ((u32) var_r29 == 0xCU) {
                var_r29 = 0;
            }
        }
        temp_r30 = (u8 *)(u8 *)&lbl_8047B100 + (var_r29 * 0x8C);
    } while (BoxPokemon_GetValue__FP10BoxPokemonUlPv(temp_r30, 5, 0) == 0);
    *arg1 = var_r29;
    return temp_r30;
}
}
