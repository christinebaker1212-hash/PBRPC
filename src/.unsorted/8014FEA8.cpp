#include ".unsorted/8014FEA8.hpp"

#include "common.hpp"

extern "C" {

u32 Pokemon_GetValue__FP7PokemonUlPv(s32, s32, s32);
s32 Pokemon_SetValue__FP7PokemonUlPCv(s32, s32, u32 *);
s32 fn_8011C974(void);

void fn_80150D24(s32 arg0, s32 arg_sp0) {
    u32 sp20;
    u32 sp1C;
    u32 sp18;
    u32 sp14;
    u32 sp10;
    u32 spC;
    u32 sp8;
    s32 temp_r24;
    s32 var_r24;
    u32 temp_r25;
    u32 temp_r26;
    u32 temp_r27;
    u32 temp_r28;
    u32 temp_r29;
    u32 temp_r30;
    u32 temp_r31;
    u32 var_r23;

    temp_r24 = fn_8011C974();
    temp_r25 = Pokemon_GetValue__FP7PokemonUlPv(arg0, 5, 0);
    temp_r26 = Pokemon_GetValue__FP7PokemonUlPv(arg0, 0, 0);
    temp_r27 = Pokemon_GetValue__FP7PokemonUlPv(arg0, 0xA4, 0);
    temp_r28 = Pokemon_GetValue__FP7PokemonUlPv(arg0, 0xA5, 0);
    temp_r29 = Pokemon_GetValue__FP7PokemonUlPv(arg0, 0xA6, 0);
    temp_r30 = Pokemon_GetValue__FP7PokemonUlPv(arg0, 0xA7, 0);
    temp_r31 = Pokemon_GetValue__FP7PokemonUlPv(arg0, 0xA8, 0);
    var_r24 = temp_r24 + 0x5760;
    var_r23 = 0U;
loop_1:
    if ((temp_r25 == Pokemon_GetValue__FP7PokemonUlPv(var_r24, 5, 0)) && (temp_r26 == Pokemon_GetValue__FP7PokemonUlPv(var_r24, 0, 0)) && (temp_r27 == Pokemon_GetValue__FP7PokemonUlPv(var_r24, 0xA4, 0)) && (temp_r28 == Pokemon_GetValue__FP7PokemonUlPv(var_r24, 0xA5, 0)) && (temp_r29 == Pokemon_GetValue__FP7PokemonUlPv(var_r24, 0xA6, 0)) && (temp_r30 == Pokemon_GetValue__FP7PokemonUlPv(var_r24, 0xA7, 0)) && (temp_r31 == Pokemon_GetValue__FP7PokemonUlPv(var_r24, 0xA8, 0))) {
        sp20 = Pokemon_GetValue__FP7PokemonUlPv(var_r24, 0xA2, 0);
        sp1C = Pokemon_GetValue__FP7PokemonUlPv(var_r24, 0x3A, 0);
        sp18 = Pokemon_GetValue__FP7PokemonUlPv(var_r24, 0x3B, 0);
        sp14 = Pokemon_GetValue__FP7PokemonUlPv(var_r24, 0x3C, 0);
        sp10 = Pokemon_GetValue__FP7PokemonUlPv(var_r24, 0x3D, 0);
        spC = Pokemon_GetValue__FP7PokemonUlPv(var_r24, 0x9F, 0);
        sp8 = Pokemon_GetValue__FP7PokemonUlPv(var_r24, 6, 0);
        Pokemon_SetValue__FP7PokemonUlPCv(arg0, 0xA2, &sp20);
        Pokemon_SetValue__FP7PokemonUlPCv(arg0, 0x3A, &sp1C);
        Pokemon_SetValue__FP7PokemonUlPCv(arg0, 0x3B, &sp18);
        Pokemon_SetValue__FP7PokemonUlPCv(arg0, 0x3C, &sp14);
        Pokemon_SetValue__FP7PokemonUlPCv(arg0, 0x3D, &sp10);
        Pokemon_SetValue__FP7PokemonUlPCv(arg0, 0x9F, &spC);
        Pokemon_SetValue__FP7PokemonUlPCv(arg0, 6, &sp8);
        return;
    }
    var_r23 += 1;
    var_r24 += 0xDC;
    if (var_r23 >= 6U) {
        return;
    }
    goto loop_1;
}
}

extern "C" {

s32 Party_GetPokemonBySlotIndex__FPC5Partyl(s32, s32);
s32 fn_80056C4C__FP7Pokemon(void);

void fn_80150910(s32 arg0) {
    s32 var_r31;
    s32 temp_r30;

    var_r31 = 0;
    do {
        temp_r30 = Party_GetPokemonBySlotIndex__FPC5Partyl(arg0, var_r31);
        if (fn_80056C4C__FP7Pokemon() != 0) {
            ((s32 (*)(s32))fn_80150D24)(temp_r30);
        }
        var_r31 += 1;
    } while (var_r31 < 6);
}
}
