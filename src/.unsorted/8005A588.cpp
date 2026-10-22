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
s32 fn_8005ADC4(void);

void fn_8005B3BC(s32 arg0, s32 arg1, s32 arg2) {
    if (fn_80056C4C__FP7Pokemon(arg2) != 0) {
        if (Pokemon_GetValue__FP7PokemonUlPv(arg2, 0xA2, 0) == 0) {
            fn_80253EB4(arg0, arg1, 1, fn_8005A9F8(1));
            return;
        }
        if (Pokemon_GetValue__FP7PokemonUlPv(arg2, 0x9F, 0) != 0) {
            Pokemon_GetValue__FP7PokemonUlPv(arg2, 0x9F, 0);
            fn_80253EB4(arg0, arg1, 1, fn_8005ADC4());
        }
    }
}
}
