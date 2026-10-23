#include ".unsorted/8005A588.hpp"

#include "common.hpp"

extern "C" {

s32 getCachedFile__7GScacheFUlUl(void);

void fn_8005AC60(void) {
    getCachedFile__7GScacheFUlUl();
}
}

extern "C" {

s32 BoxPokemon_GetValue__FP10BoxPokemonUlPv(s32, s32, s32);
s32 fn_80056BD4__FP10BoxPokemon(s32);
s32 fn_80056E2C__FP10BoxPokemon(s32);
s32 fn_8005A9F8(s32);
s32 fn_80253EB4(s32, s32, s32, s32);

void fn_8005B294(s32 arg0, s32 arg1, s32 arg2) {
    if ((fn_80056BD4__FP10BoxPokemon(arg2) != 0) && (BoxPokemon_GetValue__FP10BoxPokemonUlPv(arg2, 6, 0) != 0) && (fn_80056E2C__FP10BoxPokemon(arg2) == 0)) {
        fn_80253EB4(arg0, arg1, 1, fn_8005A9F8(0x18));
    }
}
}

extern "C" {

s32 Pokemon_GetValue__FP7PokemonUlPv(s32, s32, s32);
s32 fn_80056C4C__FP7Pokemon(s32);
s32 fn_8005ADC4(s32 arg0);

void fn_8005B3BC(s32 arg0, s32 arg1, s32 arg2) {
    if (fn_80056C4C__FP7Pokemon(arg2) != 0) {
        if (Pokemon_GetValue__FP7PokemonUlPv(arg2, 0xA2, 0) == 0) {
            fn_80253EB4(arg0, arg1, 1, fn_8005A9F8(1));
            return;
        }
        if (Pokemon_GetValue__FP7PokemonUlPv(arg2, 0x9F, 0) != 0) {
            Pokemon_GetValue__FP7PokemonUlPv(arg2, 0x9F, 0);
            fn_80253EB4(arg0, arg1, 1, ((s32 (*)(void))fn_8005ADC4)());
        }
    }
}
}

extern "C" {

s32 fn_8005ADC4(s32 arg0) {
    if (arg0 & 0xF88) {
        return fn_8005A9F8((s32)(4));
    }
    if (arg0 & 0x40) {
        return fn_8005A9F8((s32)(3));
    }
    if (arg0 & 0x20) {
        return fn_8005A9F8((s32)(2));
    }
    if (arg0 & 0x10) {
        return fn_8005A9F8((s32)(0));
    }
    if (arg0 & 7) {
        return fn_8005A9F8((s32)(5));
    }
    return 0;
}
}

extern "C" {

s32 *fn_8005CB24(s32, s32, s32 *);
s32 fn_80253F04(s32, s32, s32, s32 *);

void fn_8005B328(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp8[10];

    if (fn_80056BD4__FP10BoxPokemon((s32)(arg2)) != 0) {
        fn_80253F04(arg0, arg1, 2, fn_8005CB24(arg2, arg3, sp8));
        fn_80253F04(arg0, arg1, 1, sp8);
    }
}
}
