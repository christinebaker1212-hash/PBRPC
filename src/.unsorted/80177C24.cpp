#include ".unsorted/80177C24.hpp"

#include "ds/pokemon.hpp"
#include "gs/GScache.hpp"
#include "types/pokemonDeck.hpp"
#include "types/trainerDeck.hpp"

#include "common.hpp"

struct UnkStruct2 {
    /* 0x00 */ u8 _00[0x88];
    /* 0x88 */ u8 _88;
    /* 0x89 */ u8 _89;
    /* 0x8A */ s8 _8A;
};

struct UnkStruct1 {
    /* 0x00 */ u8 _00[0x30];
    /* 0x30 */ UnkStruct2 *_30[6];
    /* 0x48 */ UnkStruct2 *_48[6];
};

bool Battle::fn_8017A754(u32 coloId, TrainerDeckEntry *trainer, UnkStruct1 *_r6) {
    PokemonDeck *pokeDeck = (PokemonDeck *)GScache::getCachedFile(0xc8, fn_8017831C(coloId));

    if (!pokeDeck) {
        return false;
    }

    PokemonDeckEntry *deckEntries = pokeDeck->mEntries;

    if (!deckEntries) {
        return false;
    }

    PokemonDeckEntry *entries[6];

    for (s32 i = 0; i < trainer->mTeamSize; i++) {
        UnkStruct2 *unk = _r6->_48[i];

        entries[i] = deckEntries + trainer->mPokeDeckStart + i;
        fn_80178E10(unk, entries[i], _r6, 0xff);
    }

    for (s32 i = trainer->mTeamSize; i < 6; i++) {
        UnkStruct2 *unk = _r6->_48[i];
        u32 species = 0;
        BoxPokemon_SetValue((BoxPokemon *)unk, MON_DATA_SPECIES, &species);
        unk->_88 = 0;
        unk->_89 = 0;
        unk->_8A &= ~(0x80);
    }

    if (_71) {
        PokemonDeckEntry *result[6];
        fn_8017A028(pokeDeck, entries, result, 6, 0x54, 0x18C);

        for (s32 i = 0; i < 6; i++) {
            fn_80178E10(_r6->_30[i], result[i], _r6, 0xff);
        }
    }

    return true;
}

extern "C" {

void fn_80177EA4(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 __dla__FPv(s32);
s32 fn_80177EB8(s32, s32);

s32 fn_80177EB8(s32 arg0, s32 arg1) {
    s32 temp_r3;

    if (arg0 != 0) {
        temp_r3 = (*(s32 *)((u8 *)(arg0) + (8)));
        if (temp_r3 != 0) {
            __dla__FPv(temp_r3);
        }
        (*(s32 *)((u8 *)(arg0) + (8))) = 0;
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}
