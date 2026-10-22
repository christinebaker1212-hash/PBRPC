#include ".unsorted/8038F424.hpp"

#include "common.hpp"
#include "ds/battle/battle_common.hpp"
#include "ds/battle/battle_strings.hpp"
#include "ds/trainer_data.hpp"
#include "ds/constants/abilities.hpp"
#include "ds/constants/items.hpp"
#include "ds/constants/moves.hpp"
#include "ds/constants/types.hpp"

// "Invalid definition\n" and "VAL_GET can't be specified" (Shift JIS)
#define BTLSCR_ERR_INVALID "\x95\x73\x90\xb3\x82\xc8\x92\xe8\x8b\x60\x82\xc5\x82\xb7\n"
#define BTLSCR_ERR_VAL_GET "VAL_GET\x82\xcd\x8e\x77\x92\xe8\x82\xc5\x82\xab\x82\xdc\x82\xb9\x82\xf1"

#define XtOffset(pointer_type, field) ((unsigned int)&(((pointer_type)NULL)->field))

// Operands of a message command as read from the script.
// size: 0x20
struct BattleMessageParams {
    /* 0x0 */ int id;
    /* 0x4 */ int tags;
    /* 0x8 */ int params[6];
};

extern "C" int fn_803D90C4(BattleContext *battleCtx, int battlerIn);

static inline int BattleMessage_PokeTag(BattleSystem *battleSys, BattleContext *battleCtx, int battlerIn) {
    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, battlerIn);
    int tag = battler;
    tag |= battleCtx->selectedPartySlot[battler] << 8;

    return tag;
}

static inline int BattleMessage_PoffinTag(BattleContext *battleCtx, int battlerIn) {
    int poffin;
    switch (battlerIn) {
        case BTLSCR_MSG_TEMP:
            poffin = battleCtx->msgTemp;
    }

    return poffin;
}

static inline int BattleMessage_FlavorTag(BattleContext *battleCtx, int battlerIn) {
    int flavor;
    switch (battlerIn) {
        case BTLSCR_MSG_TEMP:
            flavor = battleCtx->msgTemp;
    }

    return flavor;
}

static inline int BattleMessage_TrainerClassTag(BattleSystem *battleSys, BattleContext *battleCtx, int battlerIn) {
    return fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, battlerIn);
}

static inline int BattleMessage_TrainerNameTag(BattleSystem *battleSys, BattleContext *battleCtx, int battlerIn) {
    return fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, battlerIn);
}

// pokeplatinum sProtectSuccessRate
extern const u16 lbl_80642FF8[4];
// pokeplatinum sTrainerClassPrizeMul
extern const u8 lbl_80474040[];
// pokeplatinum sWeightToPower
extern const u16 lbl_80405A5C[][2];

#define BattleAI_SetAbility(battleCtx, battler, ability) \
    ((battleCtx)->aiContext.battlerAbilities[(u8)(battler)] = (u8)(ability))
#define BattleAI_SetHeldItem(battleCtx, battler, item) \
    ((battleCtx)->aiContext.battlerHeldItems[(u8)(battler)] = (u16)(item))

#define AbilityBlocksSpecificStatReduction(battleCtx, statOffset, ability, stat) (Battler_IgnorableAbility(battleCtx, battleCtx->attacker, battleCtx->sideEffectMon, ability) == TRUE && BATTLE_STAT_ATTACK + statOffset == stat)

#define SetupNicknameStatMsg(battleCtx, msgID, statOffset) do { battleCtx->msgBuffer.id = msgID; battleCtx->msgBuffer.tags = TAG_NICKNAME_STAT; battleCtx->msgBuffer.params[0] = BattleSystem_NicknameTag(battleCtx, battleCtx->sideEffectMon); battleCtx->msgBuffer.params[1] = BATTLE_STAT_ATTACK + statOffset; } while (0)

#define SetupNicknameAbilityStatMsg(battleCtx, msgID, statOffset) do { battleCtx->msgBuffer.id = msgID; battleCtx->msgBuffer.tags = TAG_NICKNAME_ABILITY_STAT; battleCtx->msgBuffer.params[0] = BattleSystem_NicknameTag(battleCtx, battleCtx->sideEffectMon); battleCtx->msgBuffer.params[1] = battleCtx->battleMons[battleCtx->sideEffectMon].ability; battleCtx->msgBuffer.params[2] = BATTLE_STAT_ATTACK + statOffset; } while (0)

#define SetupNicknameAbilityNicknameAbilityMsg(battleCtx, msgID) do { battleCtx->msgBuffer.id = msgID; battleCtx->msgBuffer.tags = TAG_NICKNAME_ABILITY_NICKNAME_ABILITY; battleCtx->msgBuffer.params[0] = BattleSystem_NicknameTag(battleCtx, battleCtx->sideEffectMon); battleCtx->msgBuffer.params[1] = battleCtx->battleMons[battleCtx->sideEffectMon].ability; battleCtx->msgBuffer.params[2] = BattleSystem_NicknameTag(battleCtx, battleCtx->attacker); battleCtx->msgBuffer.params[3] = battleCtx->battleMons[battleCtx->attacker].ability; } while (0)

#define BeatUpEligibleMon(battleCtx, mon)                                                  \
    ((battleCtx)->beatUpCounter == (battleCtx)->selectedPartySlot[(battleCtx)->attacker]    \
     || (Pokemon_GetValue(mon, MON_DATA_HP, NULL) != 0                                      \
         && Pokemon_GetValue(mon, MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_NONE            \
         && Pokemon_GetValue(mon, MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_EGG             \
         && Pokemon_GetValue(mon, MON_DATA_STATUS, NULL) == MON_CONDITION_NONE))

extern "C" {

s32 fn_803C94CC(u8 *a, u8 *b) {
    return lbl_804056D8[*(u32 *)(b + *(u32 *)(b + 0xb4) * 4 + 0x2700)](a, b);
}

s32 fn_803C94F4(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitSetupBattleUI((BattleSystem *)a, 0);
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803C9528(u8 *a, u8 *b) {
    s32 n = BattleSystem_GetMaxBattlers((BattleSystem *)a);
    (*(u32 *)(b + 0xb4))++;
    s32 i;
    switch (fn_803D6E6C(b)) {
        case 0:
        default:
            for (i = 0; i < n; i++) {
                BattleController_EmitSetEncounter((BattleSystem *)a, i);
                fn_803ADE5C(a, i);
            }
            break;
        case 3: break;
        case 4:
            for (i = 0; i < n; i++) {
                if (((u8 *)BattleSystem_GetBattlerData((BattleSystem *)a, i))[0x185] & 1) {
                    BattleController_EmitSetEncounter((BattleSystem *)a, i);
                    fn_803ADE5C(a, i);
                }
            }
            break;
    }
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_PokemonSlideIn
s32 fn_803C9614(BattleSystem *battleSys, BattleContext *battleCtx) {
    s32 i;
    s32 maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
    BattlerData *battlerData;

    battleCtx->scriptCursor++;

    switch (fn_803D6E6C((u8 *)battleCtx)) {
        default:
        case BTLSCR_ALL_BATTLERS:
            for (i = 0; i < maxBattlers; i++) {
                BattleController_EmitShowEncounter(battleSys, i);
                fn_803ADE5C((u8 *)battleSys, i);
            }
            break;

        case BTLSCR_PLAYER:
            for (i = 0; i < maxBattlers; i++) {
                battlerData = BattleSystem_GetBattlerData(battleSys, i);

                if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
                    BattleController_EmitShowEncounter(battleSys, i);
                    fn_803ADE5C((u8 *)battleSys, i);
                }
            }

            BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_1);
            BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_2);
            break;

        case BTLSCR_ENEMY:
            for (i = 0; i < maxBattlers; i++) {
                battlerData = BattleSystem_GetBattlerData(battleSys, i);

                if (battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) {
                    BattleSystem_ClearSideExpGain(battleCtx, i);
                    BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, i);
                    BattleController_EmitShowEncounter(battleSys, i);
                    fn_803ADE5C((u8 *)battleSys, i);
                }
            }
            break;

        case BTLSCR_ATTACKER:
            battlerData = BattleSystem_GetBattlerData(battleSys, battleCtx->attacker);

            if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
                BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_1);
                BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_2);
            } else {
                BattleSystem_ClearSideExpGain(battleCtx, battleCtx->attacker);
                BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, battleCtx->attacker);
            }

            fn_803ADE5C((u8 *)battleSys, battleCtx->attacker);
            BattleController_EmitShowEncounter(battleSys, battleCtx->attacker);
            break;

        case BTLSCR_DEFENDER:
            battlerData = BattleSystem_GetBattlerData(battleSys, battleCtx->defender);

            if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
                BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_1);
                BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_2);
            } else {
                BattleSystem_ClearSideExpGain(battleCtx, battleCtx->defender);
                BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, battleCtx->defender);
            }

            fn_803ADE5C((u8 *)battleSys, battleCtx->defender);
            BattleController_EmitShowEncounter(battleSys, battleCtx->defender);
            break;

        case BTLSCR_SWITCHED_MON:
            battlerData = BattleSystem_GetBattlerData(battleSys, battleCtx->switchedMon);

            if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
                BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_1);
                BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_2);
            } else {
                BattleSystem_ClearSideExpGain(battleCtx, battleCtx->switchedMon);
                BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, battleCtx->switchedMon);
            }

            fn_803ADE5C((u8 *)battleSys, battleCtx->switchedMon);
            BattleController_EmitShowEncounter(battleSys, battleCtx->switchedMon);
            break;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// Sends a sent-out Pokemon's data to the presentation layer (PBR addition).
void fn_803C98DC(u8 battler, BattleSystem *battleSys, BattleContext *battleCtx) {
    u16 nickname[12];
    s32 slot = BattleContext_Get(battleSys, battleCtx, BATTLECTX_SELECTED_PARTY_SLOT, battler);
    Pokemon *mon = BattleSystem_GetPartyPokemon(battleSys, battler, slot);

    lbl_8048CDE8.args[0] = battler;
    lbl_8048CDE8.args[1] = Pokemon_GetValue(mon, MON_DATA_SPECIES, NULL);
    Pokemon_GetValue(mon, MON_DATA_NICKNAME, nickname);
    lbl_8048CDE8.args[2] = (u32)nickname;
    lbl_8048CDE8.args[3] = Pokemon_GetValue(mon, MON_DATA_FORM, NULL);
    lbl_8048CDE8.args[4] = BoxPokemon_IsShiny((BoxPokemon *)mon) != FALSE;
    lbl_8048CDE8.args[5] = Pokemon_GetValue(mon, MON_DATA_GENDER, NULL) != 0;
    lbl_8048CDE8.args[6] = Pokemon_GetValue(mon, MON_DATA_PERSONALITY, NULL);
    lbl_8048CDE8.args[7] = Pokemon_GetValue(mon, MON_DATA_FRIENDSHIP, NULL);
    lbl_8048CDE8.args[8] = Pokemon_GetValue(mon, MON_DATA_HP, NULL);
    lbl_8048CDE8.args[9] = Pokemon_GetValue(mon, MON_DATA_POKEBALL, NULL);
    lbl_8048CDE8.args[10] = Pokemon_GetValue(mon, MON_DATA_STATUS, NULL);
    lbl_8048CDE8.args[11] = slot;
    lbl_8048CDE8.args[12] = Pokemon_GetValue(mon, MON_DATA_ABILITY, NULL);

    if ((s32)battleCtx->scriptFile == 9 || (s32)battleCtx->scriptFile == 0x5B || (battleCtx->battleStatusMask & SYSCTL_BATON_PASS)) {
        lbl_8048CDE8.args[13] = TRUE;
    } else {
        lbl_8048CDE8.args[13] = FALSE;
    }

    fn_8016FA4C(0x18, &lbl_8048CDE8);
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_PokemonSendOut
s32 fn_803C9A84(BattleSystem *battleSys, BattleContext *battleCtx) {
    int i;
    int maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
    BattlerData *battlerData;

    battleCtx->scriptCursor++;

    int battlerIn = fn_803D6E6C((u8 *)battleCtx);
    switch (battlerIn) {
    default:
    case BTLSCR_ALL_BATTLERS:
        for (i = 0; i < maxBattlers; i++) {
            BattleController_EmitShowPokemon(battleSys, i, NULL, 0);
            fn_803ADE5C((u8 *)battleSys, i);
            fn_803C98DC(i, battleSys, battleCtx);
        }
        break;

    case BTLSCR_PLAYER:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
                BattleController_EmitShowPokemon(battleSys, i, NULL, 0);
                fn_803ADE5C((u8 *)battleSys, i);
                fn_803C98DC(i, battleSys, battleCtx);
            }
        }

        BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_1);
        BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_2);
        break;

    case BTLSCR_ENEMY:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if (battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) {
                BattleSystem_ClearSideExpGain(battleCtx, i);
                BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, i);
                BattleController_EmitShowPokemon(battleSys, i, NULL, 0);
                fn_803ADE5C((u8 *)battleSys, i);
                fn_803C98DC(i, battleSys, battleCtx);
            }
        }
        break;

    case BTLSCR_ATTACKER:
        battlerData = BattleSystem_GetBattlerData(battleSys, battleCtx->attacker);

        if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
            BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_1);
            BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_2);
        } else {
            BattleSystem_ClearSideExpGain(battleCtx, battleCtx->attacker);
            BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, battleCtx->attacker);
        }

        fn_803ADE5C((u8 *)battleSys, battleCtx->attacker);
        BattleController_EmitShowPokemon(battleSys, battleCtx->attacker, NULL, 0);
        fn_803C98DC(battleCtx->attacker, battleSys, battleCtx);
        break;

    case BTLSCR_DEFENDER:
        battlerData = BattleSystem_GetBattlerData(battleSys, battleCtx->defender);

        if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
            BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_1);
            BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_2);
        } else {
            BattleSystem_ClearSideExpGain(battleCtx, battleCtx->defender);
            BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, battleCtx->defender);
        }

        fn_803ADE5C((u8 *)battleSys, battleCtx->defender);
        BattleController_EmitShowPokemon(battleSys, battleCtx->defender, NULL, 0);
        fn_803C98DC(battleCtx->defender, battleSys, battleCtx);
        break;

    case BTLSCR_SWITCHED_MON:
        battlerData = BattleSystem_GetBattlerData(battleSys, battleCtx->switchedMon);

        if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
            BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_1);
            BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, BATTLER_ENEMY_2);
        } else {
            BattleSystem_ClearSideExpGain(battleCtx, battleCtx->switchedMon);
            BattleSystem_FlagBattlerExpGain(battleSys, battleCtx, battleCtx->switchedMon);
        }

        fn_803ADE5C((u8 *)battleSys, battleCtx->switchedMon);
        BattleController_EmitShowPokemon(battleSys, battleCtx->switchedMon, NULL, 0);
        fn_803C98DC(battleCtx->switchedMon, battleSys, battleCtx);
        break;
    }

    fn_8016E2E4(2);
    return 0;
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_RecallPokemon
s32 fn_803C9DF0(BattleSystem *battleSys, BattleContext *battleCtx) {
    s32 i;
    s32 maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
    BattlerData *battlerData;

    battleCtx->scriptCursor++;
    s32 battlerIn = fn_803D6E6C((u8 *)battleCtx);

    switch (battlerIn) {
        case BTLSCR_ALL_BATTLERS:
            for (i = 0; i < maxBattlers; i++) {
                BattleController_EmitReturnPokemon(battleSys, battleCtx, i);
            }
            break;

        case BTLSCR_PLAYER:
            for (i = 0; i < maxBattlers; i++) {
                battlerData = BattleSystem_GetBattlerData(battleSys, i);

                if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
                    BattleController_EmitReturnPokemon(battleSys, battleCtx, i);
                }
            }
            break;

        case BTLSCR_ENEMY:
            for (i = 0; i < maxBattlers; i++) {
                battlerData = BattleSystem_GetBattlerData(battleSys, i);

                if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) &&
                    (battleCtx->battlersSwitchingMask & FlagIndex(i)) == FALSE) {
                    BattleController_EmitReturnPokemon(battleSys, battleCtx, i);
                }
            }
            break;

        default:
            i = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, battlerIn);
            BattleController_EmitReturnPokemon(battleSys, battleCtx, i);
            break;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803C9F44(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitDeletePokemon((BattleSystem *)a, fn_803D803C(a, b, fn_803D6E6C(b)));
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_SetTrainerEncounter
s32 fn_803C9FAC(BattleSystem *battleSys, BattleContext *battleCtx) {
    s32 i;
    s32 maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
    BattlerData *battlerData;

    battleCtx->scriptCursor++;

    s32 battlerIn = fn_803D6E6C((u8 *)battleCtx);

    switch (battlerIn) {
        default:
        case BTLSCR_ALL_BATTLERS:
            if (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_TAG) {
                for (i = 0; i < maxBattlers; i++) {
                    battlerData = BattleSystem_GetBattlerData(battleSys, i);
                    if (battlerData->battlerType != BATTLER_TYPE_PLAYER_SIDE_SLOT_2) {
                        BattleController_EmitSetTrainerEncounter(battleSys, i);
                    }
                }
            } else {
                for (i = 0; i < maxBattlers; i++) {
                    if ((BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_2vs2) == FALSE &&
                        (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_DOUBLES) && i > 1) {
                        break;
                    }

                    BattleController_EmitSetTrainerEncounter(battleSys, i);
                }
            }
            break;

        case BTLSCR_PLAYER:
            for (i = 0; i < maxBattlers; i++) {
                battlerData = BattleSystem_GetBattlerData(battleSys, i);

                if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
                    BattleController_EmitSetTrainerEncounter(battleSys, i);

                    if ((BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_2vs2) == FALSE &&
                        (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_DOUBLES)) {
                        break;
                    }
                }
            }
            break;

        case BTLSCR_ENEMY:
            for (i = 0; i < maxBattlers; i++) {
                battlerData = BattleSystem_GetBattlerData(battleSys, i);

                if (battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) {
                    BattleController_EmitSetTrainerEncounter(battleSys, i);

                    if ((BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_2vs2) == FALSE &&
                        (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_TAG) == FALSE &&
                        (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_DOUBLES)) {
                        break;
                    }
                }
            }
            break;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_ThrowPokeball
s32 fn_803CA180(BattleSystem *battleSys, BattleContext *battleCtx) {
    s32 i;
    s32 maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
    BattlerData *battlerData;

    battleCtx->scriptCursor++;

    s32 battlerIn = fn_803D6E6C((u8 *)battleCtx);
    s32 ballTypeIn = fn_803D6E6C((u8 *)battleCtx);

    switch (battlerIn) {
        default:
        case BTLSCR_ALL_BATTLERS:
            for (i = 0; i < maxBattlers; i++) {
                if ((BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_2vs2) == FALSE &&
                    (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_DOUBLES) && i > 1) {
                    break;
                }

                BattleController_EmitThrowTrainerBall(battleSys, i, ballTypeIn);
            }
            break;

        case BTLSCR_PLAYER:
            for (i = 0; i < maxBattlers; i++) {
                battlerData = BattleSystem_GetBattlerData(battleSys, i);

                if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
                    BattleController_EmitThrowTrainerBall(battleSys, i, ballTypeIn);

                    if ((BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_2vs2) == FALSE &&
                        (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_DOUBLES)) {
                        break;
                    }
                }
            }
            break;

        case BTLSCR_ENEMY:
            for (i = 0; i < maxBattlers; i++) {
                battlerData = BattleSystem_GetBattlerData(battleSys, i);

                if (battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) {
                    BattleController_EmitThrowTrainerBall(battleSys, i, ballTypeIn);

                    if ((BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_2vs2) == FALSE &&
                        (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_TAG) == FALSE &&
                        (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_DOUBLES)) {
                        break;
                    }
                }
            }
            break;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TrainerSlideOut
s32 fn_803CA324(BattleSystem *battleSys, BattleContext *battleCtx) {
    int i;
    int maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
    BattlerData *battlerData;

    battleCtx->scriptCursor++;

    int battlerIn = fn_803D6E6C((u8 *)battleCtx);

    switch (battlerIn) {
    default:
    case BTLSCR_ALL_BATTLERS:
        for (i = 0; i < maxBattlers; i++) {
            if ((BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_2vs2) == FALSE
                && (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_DOUBLES)
                && i > 1) {
                break;
            }

            BattleController_EmitSlideTrainerOut(battleSys, i);
        }
        break;

    case BTLSCR_PLAYER:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
                BattleController_EmitSlideTrainerOut(battleSys, i);

                if ((BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_2vs2) == FALSE
                    && (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_DOUBLES)) {
                    break;
                }
            }
        }
        break;

    case BTLSCR_ENEMY:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if (battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) {
                BattleController_EmitSlideTrainerOut(battleSys, i);

                if ((BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_2vs2) == FALSE
                    && (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_TAG) == FALSE
                    && (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_DOUBLES)) {
                    break;
                }
            }
        }
        break;

    case BTLSCR_PLAYER_SLOT_1:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if (battlerData->battlerType == BATTLER_TYPE_SOLO_PLAYER
                || battlerData->battlerType == BATTLER_TYPE_PLAYER_SIDE_SLOT_1) {
                BattleController_EmitSlideTrainerOut(battleSys, i);
                break;
            }
        }
        break;

    case BTLSCR_ENEMY_SLOT_1:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if (battlerData->battlerType == BATTLER_TYPE_SOLO_ENEMY
                || battlerData->battlerType == BATTLER_TYPE_ENEMY_SIDE_SLOT_1) {
                BattleController_EmitSlideTrainerOut(battleSys, i);
                break;
            }
        }
        break;

    case BTLSCR_PLAYER_SLOT_2:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if (battlerData->battlerType == BATTLER_TYPE_PLAYER_SIDE_SLOT_2) {
                BattleController_EmitSlideTrainerOut(battleSys, i);
                break;
            }
        }
        break;

    case BTLSCR_ENEMY_SLOT_2:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if (battlerData->battlerType == BATTLER_TYPE_ENEMY_SIDE_SLOT_2) {
                BattleController_EmitSlideTrainerOut(battleSys, i);
                break;
            }
        }
        break;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TrainerSlideIn
s32 fn_803CA5B8(BattleSystem *battleSys, BattleContext *battleCtx) {
    int i;
    int maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
    BattlerData *battlerData;

    battleCtx->scriptCursor++;

    int battlerIn = fn_803D6E6C((u8 *)battleCtx);
    int posIn = fn_803D6E6C((u8 *)battleCtx);

    switch (battlerIn) {
    default:
    case BTLSCR_ALL_BATTLERS:
        for (i = 0; i < maxBattlers; i++) {
            if ((BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_DOUBLES)
                && i > 1) {
                break;
            }

            BattleController_EmitSlideTrainerIn(battleSys, i, posIn);
        }
        break;

    case BTLSCR_PLAYER:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
                BattleController_EmitSlideTrainerIn(battleSys, i, posIn);

                if (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_DOUBLES) {
                    break;
                }
            }
        }
        break;

    case BTLSCR_ENEMY:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if (battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) {
                BattleController_EmitSlideTrainerIn(battleSys, i, posIn);

                if (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_DOUBLES) {
                    break;
                }
            }
        }
        break;

    case BTLSCR_PLAYER_SLOT_1:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if (battlerData->battlerType == BATTLER_TYPE_SOLO_PLAYER
                || battlerData->battlerType == BATTLER_TYPE_PLAYER_SIDE_SLOT_1) {
                BattleController_EmitSlideTrainerIn(battleSys, i, posIn);
                break;
            }
        }
        break;

    case BTLSCR_ENEMY_SLOT_1:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if (battlerData->battlerType == BATTLER_TYPE_SOLO_ENEMY
                || battlerData->battlerType == BATTLER_TYPE_ENEMY_SIDE_SLOT_1) {
                BattleController_EmitSlideTrainerIn(battleSys, i, posIn);
                break;
            }
        }
        break;

    case BTLSCR_PLAYER_SLOT_2:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if (battlerData->battlerType == BATTLER_TYPE_PLAYER_SIDE_SLOT_2) {
                BattleController_EmitSlideTrainerIn(battleSys, i, posIn);
                break;
            }
        }
        break;

    case BTLSCR_ENEMY_SLOT_2:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if (battlerData->battlerType == BATTLER_TYPE_ENEMY_SIDE_SLOT_2) {
                BattleController_EmitSlideTrainerIn(battleSys, i, posIn);
                break;
            }
        }
        break;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CA838(u8 *a, u8 *b) {
    s32 n = BattleSystem_GetMaxBattlers((BattleSystem *)a);
    (*(u32 *)(b + 0xb4))++;
    for (s32 i = 0; i < n; i++) {
        BattleController_EmitSlideInPanel((BattleSystem *)a, i);
    }
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_HealthBoxSlideIn
s32 fn_803CA8A4(BattleSystem *battleSys, BattleContext *battleCtx) {
    int i;
    int maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
    BattlerData *battlerData;

    battleCtx->scriptCursor++;

    int battlerIn = fn_803D6E6C((u8 *)battleCtx);

    switch (battlerIn) {
    case BTLSCR_ALL_BATTLERS:
        for (i = 0; i < maxBattlers; i++) {
            BattleController_EmitSlideHealthBoxIn(battleSys, battleCtx, i, 0);
        }
        break;

    case BTLSCR_PLAYER:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
                BattleController_EmitSlideHealthBoxIn(battleSys, battleCtx, i, 0);
            }
        }
        break;

    case BTLSCR_ENEMY:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if (battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) {
                BattleController_EmitSlideHealthBoxIn(battleSys, battleCtx, i, 0);
            }
        }
        break;

    default:
        i = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, battlerIn);
        BattleController_EmitSlideHealthBoxIn(battleSys, battleCtx, i, 0);
        break;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_HealthBoxSlideInDelay
s32 fn_803CA9F4(BattleSystem *battleSys, BattleContext *battleCtx) {
    int i;
    int maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
    BattlerData *battlerData;

    battleCtx->scriptCursor++;

    int battlerIn = fn_803D6E6C((u8 *)battleCtx);
    u8 wait = 0;

    switch (battlerIn) {
    case BTLSCR_ALL_BATTLERS:
        for (i = 0; i < maxBattlers; i++) {
            BattleController_EmitSlideHealthBoxIn(battleSys, battleCtx, i, 0);
        }
        break;

    case BTLSCR_PLAYER:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
                BattleController_EmitSlideHealthBoxIn(battleSys, battleCtx, i, wait);
                wait += 4;
            }
        }
        break;

    case BTLSCR_ENEMY:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if (battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) {
                BattleController_EmitSlideHealthBoxIn(battleSys, battleCtx, i, wait);
                wait += 4;
            }
        }
        break;

    default:
        i = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, battlerIn);
        BattleController_EmitSlideHealthBoxIn(battleSys, battleCtx, i, wait);
        break;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_HealthBoxSlideOut
s32 fn_803CAB58(BattleSystem *battleSys, BattleContext *battleCtx) {
    int i;
    int maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
    BattlerData *battlerData;

    battleCtx->scriptCursor++;

    int battlerIn = fn_803D6E6C((u8 *)battleCtx);

    switch (battlerIn) {
    case BTLSCR_ALL_BATTLERS:
        for (i = 0; i < maxBattlers; i++) {
            BattleController_EmitSlideHealthBoxOut(battleSys, i);
        }
        break;

    case BTLSCR_PLAYER:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE
                && (battleCtx->battlersSwitchingMask & FlagIndex(i)) == FALSE) {
                BattleController_EmitSlideHealthBoxOut(battleSys, i);
            }
        }
        break;

    case BTLSCR_ENEMY:
        for (i = 0; i < maxBattlers; i++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, i);

            if (battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) {
                BattleController_EmitSlideHealthBoxOut(battleSys, i);
            }
        }
        break;

    default:
        i = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, battlerIn);
        BattleController_EmitSlideHealthBoxOut(battleSys, i);
        break;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CAC9C(u8 *a, u8 *b) {
    if (BattleIO_QueueIsEmpty((BattleContext *)b)) {
        (*(u32 *)(b + 0xb4))++;
    } else {
        BattleIO_UpdateTimeout((BattleContext *)b);
    }
    return 0;
}
}

#pragma push
#pragma optimize_for_size on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BattleScript_CalcMoveDamage
void fn_803CACF0(u8 *a, u8 *b) {
    int moveType;
    BattleSystem *battleSys = (BattleSystem *)a;
    BattleContext *battleCtx = (BattleContext *)b;
    if (Battler_Ability(battleCtx, battleCtx->attacker) == ABILITY_NORMALIZE) {
        moveType = TYPE_NORMAL;
    } else if (battleCtx->moveType) {
        moveType = battleCtx->moveType;
    } else {
        moveType = CURRENT_MOVE_DATA.type;
    }

    battleCtx->damage = BattleSystem_CalcMoveDamage(battleSys,
        battleCtx,
        battleCtx->moveCur,
        battleCtx->sideConditionsMask[BattleSystem_GetBattlerSide(battleSys, battleCtx->defender)],
        battleCtx->fieldConditionsMask,
        battleCtx->movePower,
        moveType,
        battleCtx->attacker,
        battleCtx->defender,
        battleCtx->criticalMul);
    battleCtx->damage *= battleCtx->criticalMul;

    if (Battler_HeldItemEffect(battleCtx, battleCtx->attacker) == HOLD_EFFECT_HP_DRAIN_ON_ATK) {
        battleCtx->damage = battleCtx->damage * (100 + Battler_HeldItemPower(battleCtx, battleCtx->attacker, (enum HeldItemPowerOp)0)) / 100;
    }

    if (Battler_HeldItemEffect(battleCtx, battleCtx->attacker) == HOLD_EFFECT_BOOST_REPEATED) {
        battleCtx->damage = battleCtx->damage * (10 + ATTACKING_MON.moveEffectsData.metronomeTurns) / 10;
    }

    if (ATTACKING_MON.moveEffectsData.meFirst) {
        // TODO: Document how this works after documenting the Me First behavior.
        if (battleCtx->meFirstTurnOrder == ATTACKING_MON.moveEffectsData.meFirstTurnNumber) {
            ATTACKING_MON.moveEffectsData.meFirstTurnNumber--;
        }

        if (battleCtx->meFirstTurnOrder - ATTACKING_MON.moveEffectsData.meFirstTurnNumber < 2) {
            battleCtx->damage = battleCtx->damage * 15 / 10;
        } else {
            ATTACKING_MON.moveEffectsData.meFirst = 0;
        }
    }
}
}

#pragma pop

extern "C" {

s32 fn_803CAEB8(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    if (*(s32 *)(b + 0x6c) == 0xff) {
        *(u32 *)(b + 0x2144) = 1;
    } else {
        fn_803CACF0(a, b);
        *(s32 *)(b + 0x2144) = BattleSystem_CalcDamageVariance((BattleContext *)b, *(s32 *)(b + 0x2144)) * -1;
    }
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803CAF20(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    fn_803CACF0(a, b);
    *(s32 *)(b + 0x2144) *= -1;
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CAF68(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    if (!(*(u32 *)(b + 0x213c) & 1)) {
        BattleController_EmitPrintAttackMessage((BattleSystem *)a, (BattleContext *)b);
        lbl_8048CE28.pendingCommand = 7;
        lbl_8048CE28._0C = *(u32 *)(b + 0x64);
    }
    *(u32 *)(b + 0x213c) |= 1;
    *(u32 *)(b + 0x2140) |= 4;
    return 0;
}

s32 fn_803CAFE0(u8 *a, u8 *b) {
    u8 buf[0x20];
    u8 out[0x30];
    (*(u32 *)(b + 0xb4))++;
    fn_803D8444(b, buf);
    fn_803D8520(a, b, buf, out);
    BattleController_EmitPrintMessage((BattleSystem *)a, (BattleContext *)b, (BattleMessage *)out);
    if (lbl_8048CE28.pendingCommand == 0) {
        lbl_8048CE28.pendingCommand = 10;
    }
    return 0;
}

s32 fn_803CB070(u8 *a, u8 *b) {
    u8 buf[0x20];
    u8 out[0x30];
    (*(u32 *)(b + 0xb4))++;
    fn_803D8444(b, buf);
    fn_803D8520(a, b, buf, out);
    out[1] |= 0x80;
    BattleController_EmitPrintMessage((BattleSystem *)a, (BattleContext *)b, (BattleMessage *)out);
    lbl_8048CE28.pendingCommand = 10;
    return 0;
}

s32 fn_803CB100(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitPrintMessage((BattleSystem *)a, (BattleContext *)b, (BattleMessage *)(b + 0xf4));
    lbl_8048CE28.pendingCommand = 10;
    return 0;
}

s32 fn_803CB144(u8 *a, u8 *b) {
    u8 buf[0x20];
    (*(u32 *)(b + 0xb4))++;
    fn_803D8444(b, buf);
    fn_803D8520(a, b, buf, b + 0xf4);
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803CB1A8(u8 *a, u8 *b) {
    u8 buf[0x20];
    u8 out[0x24];
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    fn_803D8444(b, buf);
    fn_803D8520(a, b, buf, out);
    out[1] |= 0x40;
    *(u32 *)(out + 0x20) = fn_803D803C(a, b, n);
    BattleController_EmitPrintMessage((BattleSystem *)a, (BattleContext *)b, (BattleMessage *)out);
    lbl_8048CE28.pendingCommand = 10;
    return 0;
}

s32 fn_803CB438(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    s32 w = fn_803D6E6C(b);
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    u16 m;
    if (w == 0xff) {
        m = *(u32 *)(b + 0x124);
    } else {
        m = *(u32 *)(b + 0x3044);
    }
    u32 rx = fn_803D803C(a, b, x);
    u32 ry = fn_803D803C(a, b, y);
    if ((!(*(u32 *)(b + 0x213c) & 0x4000) && fn_803ADBB4(a) == 1) || m == 0x90) {
        *(u32 *)(b + 0x213c) |= 0x4000;
        BattleController_EmitPlayMoveAnimationA2D((BattleSystem *)a, (BattleContext *)b, m, rx, ry);
        *(u32 *)&lbl_8048CDE8 = ry;
        *(u32 *)((u8 *)&lbl_8048CDE8 + 4) = rx;
        *(u32 *)((u8 *)&lbl_8048CDE8 + 8) = m;
        fn_8016FA4C(0x10, &lbl_8048CDE8);
    }
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_FlickerMon
s32 fn_803CB548(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);

    BattleController_EmitFlickerBattlerSprite(battleSys, battler, battleCtx->moveStatusFlags);

    return 0;
}
}

#pragma pop

extern "C" {


}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_UpdateHealthBarValue
s32 fn_803CB5B4(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int inBattler = fn_803D6E6C((u8 *)battleCtx);

    // Cap the hit damage to the battler's current HP
    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);
    if (battleCtx->battleMons[battler].curHP + battleCtx->hpCalcTemp <= 0) {
        battleCtx->hitDamage = battleCtx->battleMons[battler].curHP * -1;
    } else {
        battleCtx->hitDamage = battleCtx->hpCalcTemp;
    }

    // Accumulate the hit damage into this battler's total taken damage
    if (battleCtx->hitDamage < 0) {
        battleCtx->totalDamage[battler] += (battleCtx->hitDamage * -1);
    }

    // Cap the battler's new HP value to their max HP (in case the temp value is positive).
    battleCtx->battleMons[battler].curHP += battleCtx->hpCalcTemp;
    if (battleCtx->battleMons[battler].curHP < 0) {
        battleCtx->battleMons[battler].curHP = 0;
    } else if (battleCtx->battleMons[battler].curHP > battleCtx->battleMons[battler].maxHP) {
        battleCtx->battleMons[battler].curHP = battleCtx->battleMons[battler].maxHP;
    }

    BattleMon_CopyToParty(battleSys, battleCtx, battler);

    return 0;
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_UpdateHealthBar
s32 fn_803CB69C(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);

    BattleController_EmitUpdateHPGauge(battleSys, battleCtx, battler);

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryFaintMon
s32 fn_803CB854(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int inBattler = fn_803D6E6C((u8 *)battleCtx);

    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);
    if (battleCtx->battleMons[battler].curHP == 0) {
        battleCtx->faintedMon = battler;
        battleCtx->battleStatusMask |= (FlagIndex(battler) << SYSCTL_MON_FAINTED_SHIFT);
        battleCtx->totalFainted[battler]++;

    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CBA04(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitPlayFaintingSequence((BattleSystem *)a, (BattleContext *)b, *(u32 *)(b + 0x74));
    *(u32 *)(b + 0x213c) &= (FlagIndex(*(u32 *)(b + 0x74)) << 24) ^ 0xffffffff;
    *(u32 *)(b + 0x2140) |= FlagIndex(*(u32 *)(b + 0x74)) << 28;
    *(u32 *)(b + *(u32 *)(b + 0x74) * 16 + 0x21a8) = 0x27;
    BattleSystem_CleanupFaintedMon((BattleSystem *)a, (BattleContext *)b, *(u32 *)(b + 0x74));
    fn_8016E2E4(2);
    *(u32 *)&lbl_8048CDE8 = *(u32 *)(b + 0x74);
    fn_8016FA4C(0xf, &lbl_8048CDE8);
    return 0;
}

s32 fn_803CBACC(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    fn_803D6E6C(b);
    *(u32 *)(b + 0xf0) = 0;
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803CBB14(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    BattleController_EmitPlaySound((BattleSystem *)a, (BattleContext *)b, y, fn_803D803C(a, b, x));
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CompareVarToValue
s32 fn_803CBB94(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int op = fn_803D6E6C((u8 *)battleCtx);
    int srcVar = fn_803D6E6C((u8 *)battleCtx);
    int compareTo = fn_803D6E6C((u8 *)battleCtx);
    int jump = fn_803D6E6C((u8 *)battleCtx);

    int *data = (int *)fn_803D6E8C((u8 *)battleSys, (u8 *)battleCtx, srcVar);

    switch (op) {
    case OPCODE_EQU:
        if (*data != compareTo) {
            jump = 0;
        }
        break;

    case OPCODE_NEQ:
        if (*data == compareTo) {
            jump = 0;
        }
        break;

    case OPCODE_GT:
        if (*data <= compareTo) {
            jump = 0;
        }
        break;

    case OPCODE_LTE:
        if (*data > compareTo) {
            jump = 0;
        }
        break;

    case OPCODE_FLAG_SET:
        if ((*data & compareTo) == FALSE) {
            jump = 0;
        }
        break;

    case OPCODE_FLAG_NOT:
        if (*data & compareTo) {
            jump = 0;
        }
        break;

    case OPCODE_AND:
        if ((*data & compareTo) != compareTo) {
            jump = 0;
        }
        break;

    default:
        fn_803D989C(TRUE, BTLSCR_ERR_INVALID);
        break;
    }

    if (jump) {
        battleCtx->scriptCursor += jump;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CompareMonDataToValue
s32 fn_803CBCF0(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int op = fn_803D6E6C((u8 *)battleCtx);
    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int srcParam = fn_803D6E6C((u8 *)battleCtx);
    int compareTo = fn_803D6E6C((u8 *)battleCtx);
    int jump = fn_803D6E6C((u8 *)battleCtx);

    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);
    int data = BattleMon_Get(battleCtx, battler, (enum BattleMonParam)srcParam, NULL);

    switch (op) {
    case OPCODE_EQU:
        if (data != compareTo) {
            jump = 0;
        }
        break;

    case OPCODE_NEQ:
        if (data == compareTo) {
            jump = 0;
        }
        break;

    case OPCODE_GT:
        if (data <= compareTo) {
            jump = 0;
        }
        break;

    case OPCODE_LTE:
        if (data > compareTo) {
            jump = 0;
        }
        break;

    case OPCODE_FLAG_SET:
        if ((data & compareTo) == FALSE) {
            jump = 0;
        }
        break;

    case OPCODE_FLAG_NOT:
        if (data & compareTo) {
            jump = 0;
        }
        break;

    case OPCODE_AND:
        if ((data & compareTo) != compareTo) {
            jump = 0;
        }
        break;

    default:
        fn_803D989C(TRUE, BTLSCR_ERR_INVALID);
        break;
    }

    if (jump) {
        battleCtx->scriptCursor += jump;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CBE50(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitFadeOut((BattleSystem *)a);
    return 0;
}

s32 fn_803CBE80(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleSystem_LoadScript((BattleContext *)b, 2, fn_803D6E6C(b));
    return 0;
}

s32 fn_803CBED0(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleSystem_LoadScript((BattleContext *)b, 0x1f, *(u16 *)(b + *(u32 *)(b + 0x3044) * 16 + 0x3de));
    return 0;
}

s32 fn_803CBF18(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    s32 n = fn_803D6E6C(b);
    *(u32 *)(b + 0x3044) = *(u32 *)(b + 0x124);
    struct BF_213C {
        u32 hi : 17;
        u32 f14 : 1;
        u32 mid : 13;
        u32 f0 : 1;
    };
    ((BF_213C *)(b + 0x213c))->f0 = 0;
    ((BF_213C *)(b + 0x213c))->f14 = 0;
    if (n == 0) {
        *(u32 *)(b + 0x6c) = BattleSystem_Defender((BattleSystem *)a,
                                                   (BattleContext *)b,
                                                   *(u32 *)(b + 0x64),
                                                   (u16) * (u32 *)(b + 0x3044),
                                                   1,
                                                   0);
        BattleSystem_CheckRedirectionAbilities((BattleSystem *)a,
                                               (BattleContext *)b,
                                               *(u32 *)(b + 0x64),
                                               (u16) * (u32 *)(b + 0x124));
        *(u32 *)(b + *(u32 *)(b + 0x64) * 16 + 0x21ac) = *(u32 *)(b + 0x6c);
    }
    if (*(s32 *)(b + 0x6c) == 0xff) {
        *(u32 *)(b + 0xc) = 0x26;
        BattleSystem_LoadScript((BattleContext *)b, 2, 0x119);
    } else {
        BattleSystem_LoadScript((BattleContext *)b, 1, *(u32 *)(b + 0x3044));
    }
    *(u32 *)&lbl_8048CDE8 = *(u32 *)(b + 0x64);
    *(u32 *)((u8 *)&lbl_8048CDE8 + 4) = *(u32 *)(b + 0x3044);
    fn_8016FA4C(0x19, &lbl_8048CDE8);
    return 0;
}

s32 fn_803CC028(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    if ((BattleSystem_GetBattleType((BattleSystem *)a) & 0x400) ||
        (BattleSystem_GetBattleStatusMask((BattleSystem *)a) & 1)) {
        *(u32 *)(b + 0x2150) = 1;
    } else if (*(s32 *)(b + 0x6c) == 0xff) {
        *(u32 *)(b + 0x2150) = 1;
    } else {
        *(u32 *)(b + 0x2150) = BattleSystem_CalcCriticalMulti((BattleContext *)b,
                                                              *(u32 *)(b + 0x64),
                                                              *(u32 *)(b + 0x6c),
                                                              *(u32 *)(b + 0x214c),
                                                              BattleContext_Get((BattleSystem *)a,
                                                                                (BattleContext *)((u32)b),
                                                                                (enum BattleContextParam)0,
                                                                                *(u32 *)(b + 0x6c)));
    }
    return 0;
}

s32 fn_803CC0D8(u8 *a, u8 *b) {
    BattleSystem_GetBattleType((BattleSystem *)a);
    BattleSystem_GetBattlerData((BattleSystem *)a, *(u32 *)(b + 0x74));
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    *(u32 *)(b + 0xb4) += n;
    return 0;
}

s32 fn_803CC140(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    *(u8 **)(b + 0x178) = (u8 *)fn_8016DF70(5, 0x50);
    **(u8 ***)(b + 0x178) = a;
    *(u8 **)(*(u8 **)(b + 0x178) + 4) = b;
    *(u32 *)(*(u8 **)(b + 0x178) + 0x20) = 0;
    *(u32 *)(*(u8 **)(b + 0x178) + 0x40) = 0;
    fn_803DEF00((Unk8063D230Func)((void *)fn_803D71CC), (void *)(*(u8 **)(b + 0x178)), 0);
    return 0;
}

s32 fn_803CC1C8(u8 *a, u8 *b) {
    if (*(u32 *)(b + 0x178) == 0) {
        (*(u32 *)(b + 0xb4))++;
    }
    return 0;
}

s32 fn_803CC1E8(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    fn_803D6E6C(b);
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_ShowParty
s32 fn_803CC21C(BattleSystem *battleSys, BattleContext *battleCtx) {
    int maxBattlers = BattleSystem_GetMaxBattlers(battleSys);

    battleCtx->scriptCursor++;

    int battler;
    int switchingMask = 0;

    for (battler = 0; battler < maxBattlers; battler++) {
        if (battleCtx->battlerStatusFlags[battler] & BATTLER_STATUS_SWITCHING) {
            switchingMask |= FlagIndex(battler);
            BattleController_EmitShowPartyMenu(battleSys, battleCtx, battler, 1, 0, 6);
        }
    }

    for (battler = 0; battler < maxBattlers; battler++) {
        if (BattleSystem_GetBattleType(battleSys) == BATTLE_TYPE_LINK_DOUBLES) {
            // CompareVarToValue both battlers are done selecting replacements, wait for all other battlers
            int partner = BattleSystem_GetPartner(battleSys, battler);
            if ((switchingMask & FlagIndex(battler)) == FALSE
                && (switchingMask & FlagIndex(partner)) == FALSE) {
                switchingMask |= FlagIndex(battler);
                BattleController_EmitPrintLinkWaitMessage(battleSys, battler);
            }
        } else if ((switchingMask & FlagIndex(battler)) == FALSE) {
            BattleController_EmitPrintLinkWaitMessage(battleSys, battler);
        }
    }

    for (battler = 0; battler < maxBattlers; battler++) {
        if (battleCtx->battlerStatusFlags[battler] & BATTLER_STATUS_SWITCHING) {
            battleCtx->switchedMon = battler;
            break;
        }
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_WaitMonSelection
s32 fn_803CC384(BattleSystem *battleSys, BattleContext *battleCtx) {
    int maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
    int totalSwitching = 0;

    int battler;
    for (battler = 0; battler < maxBattlers; battler++) {
        if (battleCtx->battlerStatusFlags[battler] & BATTLER_STATUS_SWITCHING) {
            totalSwitching++;
        }
    }

    for (battler = 0; battler < maxBattlers; battler++) {
        if ((battleCtx->battlerStatusFlags[battler] & BATTLER_STATUS_SWITCHING)
            && BattleContext_IOBufferVal(battleCtx, battler)) {
            battleCtx->switchedPartySlot[battler] = battleCtx->ioBuffer[battler][0] - 1;
            totalSwitching--;

            if ((battleCtx->battleStatusMask2 & (FlagIndex(battler) << SYSCTL_LINK_WAITING_SHIFT)) == FALSE) {
                battleCtx->battleStatusMask2 |= (FlagIndex(battler) << SYSCTL_LINK_WAITING_SHIFT);
                BattleController_EmitPrintLinkWaitMessage(battleSys, battler);
            }
        }
    }

    if (totalSwitching == 0) {
        battleCtx->battleStatusMask2 &= ~(0xF << SYSCTL_LINK_WAITING_SHIFT);
        battleCtx->scriptCursor++;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CC4B0(u8 *a, u8 *b) {
    u8 *q;
    s32 i;
    (*(u32 *)(b + 0xb4))++;
    switch (fn_803D6E6C(b)) {
        case 1:    i = *(u32 *)(b + 0x64); break;
        case 6:    i = *(u32 *)(b + 0x78); break;
        case 0x12: i = *(u32 *)(b + 0x6c); break;
    }
    *(u32 *)(b + i * 4 + 0x13c) &= ~1;
    b[0x3108] &= FlagIndex(i) ^ 0xffffffff;
    q = b + i;
    u8 v = q[0x21a0];
    q[0x219c] = v;
    q[0x21a0] = 6;
    BattleSystem_InitBattleMon((BattleSystem *)a, (BattleContext *)b, i, v);
    BattleSystem_SwitchSlots((BattleSystem *)a, (BattleContext *)b, i, q[0x219c]);
    *(u16 *)(b + 0x3122) = *(u32 *)(b + 0x2e4c);
    BattleSystem_UpdateAfterSwitch((BattleSystem *)a, (BattleContext *)b, i);
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on

extern "C" {

s32 fn_803CC5B4(u8 *a, u8 *b) {
    s32 n = BattleSystem_GetMaxBattlers((BattleSystem *)a);
    (*(u32 *)(b + 0xb4))++;
    u32 m = fn_803D6E6C(b);
    for (s32 i = 0; i < n; i++) {
        if (*(u32 *)(b + i * 4 + 0x13c) & 1) {
            *(u32 *)(b + 0x78) = i;
            *(u32 *)(b + 0xb4) += m;
            break;
        }
    }
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803CC648(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    *(u8 **)(b + 0x178) = (u8 *)fn_8016DF70(5, 0x50);
    **(u8 ***)(b + 0x178) = a;
    *(u8 **)(*(u8 **)(b + 0x178) + 4) = b;
    *(u32 *)(*(u8 **)(b + 0x178) + 0x20) = 0;
    *(u32 *)(*(u8 **)(b + 0x178) + 0x1c) = n;
    *(u32 *)(*(u8 **)(b + 0x178) + 0x24) = *(u32 *)(b + 0x128);
    fn_803DEF00((Unk8063D230Func)((void *)fn_803D8004), (void *)(*(u8 **)(b + 0x178)), 0);
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CC6E8(u8 *a, u8 *b) {
    if (*(u32 *)(b + 0x178) == 0) {
        (*(u32 *)(b + 0xb4))++;
    }
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803CC708(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    s32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    if (b[0x217d] == 0) {
        if (x == 0) {
            if ((u8)Battler_Ability((BattleContext *)b, *(u32 *)(b + 0x64)) == 0x5c) {
                x = 5;
            } else {
                x = LCRNG_Next() & 3;
                if (x < 2) {
                    x += 2;
                } else {
                    x = (LCRNG_Next() & 3) + 2;
                }
            }
        }
        b[0x217c] = x;
        b[0x217d] = x;
        *(u32 *)(b + 0x2188) = y;
    }
    return 0;
}

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_UpdateVar
s32 fn_803CC7C4(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int op = fn_803D6E6C((u8 *)battleCtx);
    int dstVar = fn_803D6E6C((u8 *)battleCtx);
    int srcVal = fn_803D6E6C((u8 *)battleCtx);

    int *var = (int *)fn_803D6E8C((u8 *)battleSys, (u8 *)battleCtx, dstVar);

    switch (op) {
    case OPCODE_SET:
        *var = srcVal;
        break;

    case OPCODE_ADD:
        *var += srcVal;
        break;

    case OPCODE_SUB:
        *var -= srcVal;
        break;

    case OPCODE_FLAG_ON:
        *var |= srcVal;
        break;

    case OPCODE_FLAG_OFF:
        *var &= FLAG_NEGATE(srcVal);
        break;

    case OPCODE_MUL:
        *var *= srcVal;
        break;

    case OPCODE_DIV:
        *var /= srcVal;
        break;

    case OPCODE_LEFT_SHIFT:
        *var = *var << srcVal;
        break;

    case OPCODE_RIGHT_SHIFT:
        *var = *var >> srcVal;
        break;

    case OPCODE_FLAG_INDEX:
        *var = FlagIndex(srcVal);
        break;

    case OPCODE_GET:
        fn_803D989C(FALSE, BTLSCR_ERR_INVALID);
        break;

    case OPCODE_SUB_TO_ZERO:
        *var -= srcVal;
        if (*var < 0) {
            *var = 0;
        }
        break;

    case OPCODE_BITWISE_XOR:
        *var ^= srcVal;
        break;

    case OPCODE_BITWISE_AND:
        *var &= srcVal;
        break;

    default:
        fn_803D989C(FALSE, BTLSCR_ERR_INVALID);
        break;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on

extern "C" {

// pokeplatinum BtlCmd_ChangeStatStage
s32 fn_803CC96C(BattleSystem *battleSys, BattleContext *battleCtx) {
    int jumpNoChange;
    int jumpBlocked;
    int jumpBlockedBySubstitute;
    int statOffset;
    int stageChange;
    int result;
    BattleMon *mon = &battleCtx->battleMons[battleCtx->sideEffectMon];

    battleCtx->scriptCursor++;

    jumpNoChange = fn_803D6E6C((u8 *)battleCtx);
    jumpBlocked = fn_803D6E6C((u8 *)battleCtx);
    jumpBlockedBySubstitute = fn_803D6E6C((u8 *)battleCtx);
    result = 0;

    battleCtx->battleStatusMask &= ~SYSCTL_FAIL_STAT_STAGE_CHANGE;

    if (battleCtx->sideEffectParam >= MOVE_SUBSCRIPT_PTR_ATTACK_DOWN_2_STAGES) {
        statOffset = battleCtx->sideEffectParam - MOVE_SUBSCRIPT_PTR_ATTACK_DOWN_2_STAGES;
        stageChange = -2;
        battleCtx->scriptTemp = BATTLE_ANIMATION_STAT_DROP;
    } else if (battleCtx->sideEffectParam >= MOVE_SUBSCRIPT_PTR_ATTACK_UP_2_STAGES) {
        statOffset = battleCtx->sideEffectParam - MOVE_SUBSCRIPT_PTR_ATTACK_UP_2_STAGES;
        stageChange = 2;
        battleCtx->scriptTemp = BATTLE_ANIMATION_STAT_BOOST;
    } else if (battleCtx->sideEffectParam >= MOVE_SUBSCRIPT_PTR_ATTACK_DOWN_1_STAGE) {
        statOffset = battleCtx->sideEffectParam - MOVE_SUBSCRIPT_PTR_ATTACK_DOWN_1_STAGE;
        stageChange = -1;
        battleCtx->scriptTemp = BATTLE_ANIMATION_STAT_DROP;
    } else {
        statOffset = battleCtx->sideEffectParam - MOVE_SUBSCRIPT_PTR_ATTACK_UP_1_STAGE;
        stageChange = 1;
        battleCtx->scriptTemp = BATTLE_ANIMATION_STAT_BOOST;
    }

    lbl_8048CE28._10 = statOffset + 1;

    if (stageChange > 0) {
        if (mon->statBoosts[BATTLE_STAT_ATTACK + statOffset] == MAX_STAT_STAGE) {
            battleCtx->battleStatusMask |= SYSCTL_FAIL_STAT_STAGE_CHANGE;
            lbl_8048CE28._0C = battleCtx->sideEffectMon;

            if (battleCtx->sideEffectType == SIDE_EFFECT_TYPE_INDIRECT
                || battleCtx->sideEffectType == SIDE_EFFECT_TYPE_ABILITY) {
                battleCtx->scriptCursor += jumpBlocked;
            } else {
                SetupNicknameStatMsg(battleCtx, BattleStrings_Text_PokemonsStatWontGoHigher_Ally, statOffset); // "{0}'s {1} won't go higher!"
                battleCtx->scriptCursor += jumpNoChange;
            }
        } else {
            if (battleCtx->sideEffectType == SIDE_EFFECT_TYPE_ABILITY) {
                SetupNicknameAbilityStatMsg(battleCtx, BattleStrings_Text_PokemonsAbilityRaisedItsStat_Ally, statOffset); // "{0}'s {1} raised its {2}!"
                lbl_8048CE28._18 = battleCtx->sideEffectMon;
            } else if (battleCtx->sideEffectType == SIDE_EFFECT_TYPE_HELD_ITEM) {
                battleCtx->msgBuffer.id = BattleStrings_Text_TheItemRaisedPokemonsStat_Ally; // "The {0} raised {1}'s {2}!"
                battleCtx->msgBuffer.tags = TAG_NICKNAME_ITEM_STAT;
                battleCtx->msgBuffer.params[0] = BattleSystem_NicknameTag(battleCtx, battleCtx->sideEffectMon);
                battleCtx->msgBuffer.params[1] = battleCtx->msgItemTemp;
                battleCtx->msgBuffer.params[2] = BATTLE_STAT_ATTACK + statOffset;
            } else {
                SetupNicknameStatMsg(battleCtx,
                    stageChange == 1 ? BattleStrings_Text_PokemonsStatRose_Ally : // "{0}'s {1} rose!"
                        BattleStrings_Text_PokemonsStatSharplyRose_Ally, // "{0}'s {1} sharply rose!"
                    statOffset);
            }

            mon->statBoosts[BATTLE_STAT_ATTACK + statOffset] += stageChange;

            if (mon->statBoosts[BATTLE_STAT_ATTACK + statOffset] > MAX_STAT_STAGE) {
                mon->statBoosts[BATTLE_STAT_ATTACK + statOffset] = MAX_STAT_STAGE;
            }
        }
    } else {
        if ((battleCtx->sideEffectFlags & MOVE_SIDE_EFFECT_CANNOT_PREVENT) == FALSE) {
            if (battleCtx->attacker != battleCtx->sideEffectMon) {
                if (battleCtx->sideConditions[BattleSystem_GetBattlerSide(battleSys, battleCtx->sideEffectMon)].mistTurns) {
                    battleCtx->msgBuffer.id = BattleStrings_Text_PokemonIsProtectedByMist_Ally; // "{0} is protected by Mist!"
                    battleCtx->msgBuffer.tags = TAG_NICKNAME;
                    battleCtx->msgBuffer.params[0] = BattleSystem_NicknameTag(battleCtx, battleCtx->sideEffectMon);

                    result = 1;
                } else if (Battler_IgnorableAbility(battleCtx, battleCtx->attacker, battleCtx->sideEffectMon, ABILITY_CLEAR_BODY) == TRUE
                    || Battler_IgnorableAbility(battleCtx, battleCtx->attacker, battleCtx->sideEffectMon, ABILITY_WHITE_SMOKE) == TRUE) {
                    if (battleCtx->sideEffectType == SIDE_EFFECT_TYPE_ABILITY) {
                        SetupNicknameAbilityNicknameAbilityMsg(battleCtx, BattleStrings_Text_PokemonsAbilitySuppressedPokemonsAbility_AllyAlly); // "{0}'s {1} suppressed {2}'s {3}!"
                    } else {
                        battleCtx->msgBuffer.id = BattleStrings_Text_PokemonsAbilityPreventsStatLoss_Ally; // "{0}'s {1} prevents stat loss!"
                        battleCtx->msgBuffer.tags = TAG_NICKNAME_ABILITY;
                        battleCtx->msgBuffer.params[0] = BattleSystem_NicknameTag(battleCtx, battleCtx->sideEffectMon);
                        battleCtx->msgBuffer.params[1] = battleCtx->battleMons[battleCtx->sideEffectMon].ability;
                    }

                    result = 1;
                } else if (AbilityBlocksSpecificStatReduction(battleCtx, statOffset, ABILITY_KEEN_EYE, BATTLE_STAT_ACCURACY)
                    || AbilityBlocksSpecificStatReduction(battleCtx, statOffset, ABILITY_HYPER_CUTTER, BATTLE_STAT_ATTACK)) {
                    if (battleCtx->sideEffectType == SIDE_EFFECT_TYPE_ABILITY) {
                        SetupNicknameAbilityNicknameAbilityMsg(battleCtx, BattleStrings_Text_PokemonsAbilitySuppressedPokemonsAbility_AllyAlly); // "{0}'s {1} suppressed {2}'s {3}!"
                    } else {
                        SetupNicknameAbilityStatMsg(battleCtx, BattleStrings_Text_PokemonsAbilityPreventsBufferStatLoss, statOffset); // "{0}'s {1} prevents {2} loss!"
                        lbl_8048CE28._18 = battleCtx->sideEffectMon;
                    }

                    result = 1;
                } else if (mon->statBoosts[BATTLE_STAT_ATTACK + statOffset] == MIN_STAT_STAGE) {
                    battleCtx->battleStatusMask |= SYSCTL_FAIL_STAT_STAGE_CHANGE;
                    lbl_8048CE28._0C = battleCtx->sideEffectMon;

                    if (battleCtx->sideEffectType == SIDE_EFFECT_TYPE_INDIRECT
                        || battleCtx->sideEffectType == SIDE_EFFECT_TYPE_ABILITY) {
                        battleCtx->scriptCursor += jumpBlocked;

                        return 0;
                    } else {
                        SetupNicknameStatMsg(battleCtx, BattleStrings_Text_PokemonsStatWontGoLower_Ally, statOffset); // "{0}'s {1} won't go lower!"
                        battleCtx->scriptCursor += jumpNoChange;

                        return 0;
                    }
                } else if (Battler_IgnorableAbility(battleCtx, battleCtx->attacker, battleCtx->sideEffectMon, ABILITY_SHIELD_DUST) == TRUE
                    && battleCtx->sideEffectType == SIDE_EFFECT_TYPE_INDIRECT) {
                    result = 1;
                } else if (battleCtx->battleMons[battleCtx->sideEffectMon].statusVolatile & VOLATILE_CONDITION_SUBSTITUTE) {
                    result = 2;
                }
            } else if (mon->statBoosts[BATTLE_STAT_ATTACK + statOffset] == MIN_STAT_STAGE) {
                battleCtx->battleStatusMask |= SYSCTL_FAIL_STAT_STAGE_CHANGE;
                lbl_8048CE28._0C = battleCtx->sideEffectMon;

                if (battleCtx->sideEffectType == SIDE_EFFECT_TYPE_INDIRECT
                    || battleCtx->sideEffectType == SIDE_EFFECT_TYPE_ABILITY) {
                    battleCtx->scriptCursor += jumpBlocked;

                    return 0;
                } else {
                    SetupNicknameStatMsg(battleCtx, BattleStrings_Text_PokemonsStatWontGoLower_Ally, statOffset); // "{0}'s {1} won't go lower!"
                    battleCtx->scriptCursor += jumpNoChange;

                    return 0;
                }
            }

            if (result == 2 && battleCtx->sideEffectType == SIDE_EFFECT_TYPE_DIRECT) {
                battleCtx->scriptCursor += jumpBlockedBySubstitute;

                return 0;
            } else if (result && battleCtx->sideEffectType == SIDE_EFFECT_TYPE_INDIRECT) {
                battleCtx->scriptCursor += jumpBlocked;

                return 0;
            } else if (result) {
                battleCtx->scriptCursor += jumpNoChange;

                return 0;
            }
        }

        if (battleCtx->sideEffectType == SIDE_EFFECT_TYPE_ABILITY) {
            battleCtx->msgBuffer.id = BattleStrings_Text_PokemonsAbilityCutsPokemonsStat_AllyAlly; // "{0}'s {1} cuts {2}'s {3}!"
            battleCtx->msgBuffer.tags = TAG_NICKNAME_ABILITY_NICKNAME_STAT;
            battleCtx->msgBuffer.params[0] = BattleSystem_NicknameTag(battleCtx, battleCtx->attacker);
            battleCtx->msgBuffer.params[1] = battleCtx->battleMons[battleCtx->attacker].ability;
            battleCtx->msgBuffer.params[2] = BattleSystem_NicknameTag(battleCtx, battleCtx->sideEffectMon);
            battleCtx->msgBuffer.params[3] = BATTLE_STAT_ATTACK + statOffset;
        } else {
            SetupNicknameStatMsg(battleCtx,
                stageChange == -1 ? BattleStrings_Text_PokemonsStatFell_Ally : // "{0}'s {1} fell!"
                    BattleStrings_Text_PokemonsStatHarshlyFell_Ally, // "{0}'s {1} harshly fell!"
                statOffset);
        }

        mon->statBoosts[BATTLE_STAT_ATTACK + statOffset] += stageChange;

        if (mon->statBoosts[BATTLE_STAT_ATTACK + statOffset] < MIN_STAT_STAGE) {
            mon->statBoosts[BATTLE_STAT_ATTACK + statOffset] = MIN_STAT_STAGE;
        }
    }

    return 0;
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_UpdateMonData
s32 fn_803CD094(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int op = fn_803D6E6C((u8 *)battleCtx);
    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int paramID = fn_803D6E6C((u8 *)battleCtx);
    int srcVal = fn_803D6E6C((u8 *)battleCtx);

    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);
    int monData = BattleMon_Get(battleCtx, battler, (enum BattleMonParam)paramID, NULL);

    switch (op) {
    case OPCODE_SET:
        monData = srcVal;
        break;

    case OPCODE_ADD:
        monData += srcVal;
        break;

    case OPCODE_SUB:
        monData -= srcVal;
        break;

    case OPCODE_FLAG_ON:
        monData |= srcVal;
        break;

    case OPCODE_FLAG_OFF:
        monData &= FLAG_NEGATE(srcVal);
        break;

    case OPCODE_MUL:
        monData *= srcVal;
        break;

    case OPCODE_DIV:
        monData /= srcVal;
        break;

    case OPCODE_LEFT_SHIFT:
        monData = monData << srcVal;
        break;

    case OPCODE_RIGHT_SHIFT:
        monData = monData >> srcVal;
        break;

    case OPCODE_FLAG_INDEX:
        monData = FlagIndex(srcVal);
        break;

    case OPCODE_GET:
        fn_803D989C(FALSE, BTLSCR_ERR_INVALID);
        break;

    case OPCODE_SUB_TO_ZERO:
        monData -= srcVal;

        if (monData < 0) {
            monData = 0;
        }
        break;

    case OPCODE_BITWISE_XOR:
        monData ^= srcVal;
        break;

    case OPCODE_BITWISE_AND:
        monData &= srcVal;
        break;

    default:
        fn_803D989C(FALSE, BTLSCR_ERR_INVALID);
        break;
    }

    if (paramID == BATTLEMON_ABILITY) {
        BattleAI_SetAbility(battleCtx, battler, monData);
    }

    BattleMon_Set(battleCtx, battler, (enum BattleMonParam)paramID, &monData);
    BattleMon_CopyToParty(battleSys, battleCtx, battler);

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CD270(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    *(u32 *)(b + fn_803D803C(a, b, x) * 4 + 0x218c) |= y;
    return 0;
}

s32 fn_803CD2F0(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    BattleController_EmitToggleVanish((BattleSystem *)a, fn_803D803C(a, b, x), y);
    return 0;
}

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CheckAbility
s32 fn_803CD36C(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int op = fn_803D6E6C((u8 *)battleCtx);
    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int ability = fn_803D6E6C((u8 *)battleCtx);
    int jump = fn_803D6E6C((u8 *)battleCtx);

    int battler;
    if (inBattler == BTLSCR_ALL_BATTLERS) {
        int maxBattlers = BattleSystem_GetMaxBattlers(battleSys);

        for (battler = 0; battler < maxBattlers; battler++) {
            if (op == CHECK_HAVE) {
                if (Battler_Ability(battleCtx, battler) == ability) {
                    battleCtx->scriptCursor += jump;
                    battleCtx->abilityMon = battler;
                    lbl_8048CE28._18 = battler;
                    break;
                }
            } else if (Battler_Ability(battleCtx, battler) == ability) {
                break;
            }
        }
    } else {
        battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);

        if (op == CHECK_HAVE) {
            if (Battler_Ability(battleCtx, battler) == ability) {
                battleCtx->scriptCursor += jump;
                battleCtx->abilityMon = battler;
                lbl_8048CE28._18 = battler;
            }
        } else if (Battler_Ability(battleCtx, battler) != ability) {
            battleCtx->scriptCursor += jump;
            battleCtx->abilityMon = battler;
        }
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CD4E0(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    s32 y;
    s32 x;
    x = fn_803D6E6C(b);
    y = fn_803D6E6C(b);
    *(u32 *)(b + 0x134) = y + (s32)LCRNG_Next() % (x + 1);
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_UpdateVarFromVar
s32 fn_803CD558(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int op = fn_803D6E6C((u8 *)battleCtx);
    int dstVar = fn_803D6E6C((u8 *)battleCtx);
    int srcVar = fn_803D6E6C((u8 *)battleCtx);

    int *dstData = (int *)fn_803D6E8C((u8 *)battleSys, (u8 *)battleCtx, dstVar);
    int *srcData = (int *)fn_803D6E8C((u8 *)battleSys, (u8 *)battleCtx, srcVar);

    switch (op) {
    case OPCODE_SET:
        *dstData = *srcData;
        break;

    case OPCODE_ADD:
        *dstData += *srcData;
        break;

    case OPCODE_SUB:
        *dstData -= *srcData;
        break;

    case OPCODE_FLAG_ON:
        *dstData |= *srcData;
        break;

    case OPCODE_FLAG_OFF:
        *dstData &= FLAG_NEGATE(*srcData);
        break;

    case OPCODE_MUL:
        *dstData *= *srcData;
        break;

    case OPCODE_DIV:
        *dstData /= *srcData;
        break;

    case OPCODE_LEFT_SHIFT:
        *dstData = *dstData << *srcData;
        break;

    case OPCODE_RIGHT_SHIFT:
        *dstData = *dstData >> *srcData;
        break;

    case OPCODE_FLAG_INDEX:
        *dstData = FlagIndex(*srcData);
        break;

    case OPCODE_GET:
        *srcData = *dstData;
        break;

    case OPCODE_SUB_TO_ZERO:
        *dstData -= *srcData;

        if (*dstData < 0) {
            *dstData = 0;
        }
        break;

    case OPCODE_BITWISE_XOR:
        *dstData ^= *srcData;
        break;

    case OPCODE_BITWISE_AND:
        *dstData &= *srcData;
        break;

    default:
        fn_803D989C(FALSE, BTLSCR_ERR_INVALID);
        break;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_UpdateMonDataFromVar
s32 fn_803CD734(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int op = fn_803D6E6C((u8 *)battleCtx);
    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int paramID = fn_803D6E6C((u8 *)battleCtx);
    int var = fn_803D6E6C((u8 *)battleCtx);

    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);
    int monData = BattleMon_Get(battleCtx, battler, (enum BattleMonParam)paramID, NULL);
    int *varData = (int *)fn_803D6E8C((u8 *)battleSys, (u8 *)battleCtx, var);

    switch (op) {
    case OPCODE_SET:
        monData = *varData;
        break;

    case OPCODE_ADD:
        monData += *varData;
        break;

    case OPCODE_SUB:
        monData -= *varData;
        break;

    case OPCODE_FLAG_ON:
        monData |= *varData;
        break;

    case OPCODE_FLAG_OFF:
        monData &= FLAG_NEGATE(*varData);
        break;

    case OPCODE_MUL:
        monData *= *varData;
        break;

    case OPCODE_DIV:
        monData /= *varData;
        break;

    case OPCODE_LEFT_SHIFT:
        monData = monData << *varData;
        break;

    case OPCODE_RIGHT_SHIFT:
        monData = monData >> *varData;
        break;

    case OPCODE_FLAG_INDEX:
        monData = FlagIndex(*varData);
        break;

    case OPCODE_GET:
        *varData = monData;
        break;

    case OPCODE_SUB_TO_ZERO:
        monData -= *varData;

        if (monData < 0) {
            monData = 0;
        }
        break;

    case OPCODE_BITWISE_XOR:
        monData ^= *varData;
        break;

    case OPCODE_BITWISE_AND:
        monData &= *varData;
        break;

    default:
        fn_803D989C(FALSE, BTLSCR_ERR_INVALID);
        break;
    }

    if (op != OPCODE_GET) {
        if (paramID == BATTLEMON_ABILITY) {
            BattleAI_SetAbility(battleCtx, battler, monData);
        }

        BattleMon_Set(battleCtx, battler, (enum BattleMonParam)paramID, &monData);
        BattleMon_CopyToParty(battleSys, battleCtx, battler);
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CD978(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    *(u32 *)(b + 0xb4) += n;
    return 0;
}

s32 fn_803CD9C4(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleSystem_CallScript((BattleContext *)b, 2, fn_803D6E6C(b));
    return 0;
}

s32 fn_803CDA14(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 *r = fn_803D6E8C(a, b, fn_803D6E6C(b));
    BattleSystem_CallScript((BattleContext *)b, 2, *r);
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_SetMirrorMove
s32 fn_803CDA84(BattleSystem *battleSys, BattleContext *battleCtx) {
    int move = MOVE_NONE;
    int battleType = BattleSystem_GetBattleType(battleSys);

    battleCtx->scriptCursor++;

    if (battleCtx->moveCopied[battleCtx->attacker]) {
        move = battleCtx->moveCopied[battleCtx->attacker];
    } else if (battleType & BATTLE_TYPE_DOUBLES) {
        // In double battles, choose randomly.
        move = battleCtx->moveCopiedHit[battleCtx->attacker][0]
            + battleCtx->moveCopiedHit[battleCtx->attacker][1]
            + battleCtx->moveCopiedHit[battleCtx->attacker][2]
            + battleCtx->moveCopiedHit[battleCtx->attacker][3];

        if (move) {
            do {
                move = battleCtx->moveCopiedHit[battleCtx->attacker][LCRNG_Next() % 4];
            } while (move == MOVE_NONE);
        }
    }

    // Mirror Move shares a legality table with Encore
    if (move && Move_CanBeEncored(battleCtx, move) == TRUE) {
        battleCtx->battleStatusMask &= ~SYSCTL_SKIP_ATTACK_MESSAGE;
        battleCtx->battleStatusMask &= ~SYSCTL_PLAYED_MOVE_ANIMATION;
        battleCtx->moveCur = move;
        battleCtx->defender = BattleSystem_Defender(battleSys, battleCtx, battleCtx->attacker, move, TRUE, RANGE_SINGLE_TARGET);

        if (battleCtx->defender == BATTLER_NONE) {
            battleCtx->commandNext = BATTLE_CONTROL_UPDATE_MOVE_BUFFERS;
            BattleSystem_LoadScript(battleCtx, NARC_BATTLE_SUB_SEQ, BATTLE_SUBSCRIPT_NO_TARGET);
        } else {
            ATTACKER_ACTION[BATTLE_ACTION_CHOOSE_TARGET] = battleCtx->defender;
            BattleSystem_LoadScript(battleCtx, NARC_BATTLE_MOVE_SEQ, move);
            lbl_8048CDE8.args[0] = battleCtx->attacker;
            lbl_8048CDE8.args[1] = battleCtx->moveCur;
            fn_8016FA4C(0x19, &lbl_8048CDE8);
        }
    } else {
        battleCtx->selfTurnFlags[battleCtx->attacker].skipPressureCheck = TRUE;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CDC28(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    s32 n = BattleSystem_GetMaxBattlers((BattleSystem *)a);
    s32 j;
    s32 i;
    for (i = 0; i < n; i++) {
        for (j = 0; j < 8; j++) {
            b[i * 0xc0 + j + 0x2d58] = 6;
        }
        *(u32 *)(b + i * 0xc0 + 0x2db0) &= ~0x100000;
    }
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CDCB0(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    Battler_LockMoveChoice((BattleSystem *)a, (BattleContext *)b, fn_803D803C(a, b, fn_803D6E6C(b)));
    return 0;
}

s32 fn_803CDD1C(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    Battler_UnlockMoveChoice((BattleSystem *)a, (BattleContext *)b, fn_803D803C(a, b, fn_803D6E6C(b)));
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803CDD88(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    BattleController_EmitSetStatusIcon((BattleSystem *)a, fn_803D803C(a, b, x), y);
    return 0;
}

s32 fn_803CDE04(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    BattleController_EmitTrainerMessage((BattleSystem *)a, fn_803D803C(a, b, x), y);
    return 0;
}

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BattleScript_CalcPrizeMoney (sTrainerClassPrizeMul is lbl_80474040)
s32 fn_803CDE80(u8 *a, u8 *b, u32 battler) {
    BattleSystem *battleSys = (BattleSystem *)a;
    BattleContext *battleCtx = (BattleContext *)b;
    u8 lastLevel = 0;
    void *rawParty = fn_8016DF70(5, sizeof(TrainerMonWithMovesAndItem) * MAX_PARTY_SIZE);

    Trainer trainer;
    Trainer_Load(battleSys->trainerIDs[battler], &trainer);
    Trainer_LoadParty(battleSys->trainerIDs[battler], rawParty);

    switch (trainer.monDataType) {
        default:
        case TRDATATYPE_BASE: {
            TrainerMonBase *party = (TrainerMonBase *)rawParty;
            lastLevel = party[trainer.partySize - 1].level;
            break;
        }

        case TRDATATYPE_WITH_MOVES: {
            TrainerMonWithMoves *party = (TrainerMonWithMoves *)rawParty;
            lastLevel = party[trainer.partySize - 1].level;
            break;
        }

        case TRDATATYPE_WITH_ITEM: {
            TrainerMonWithItem *party = (TrainerMonWithItem *)rawParty;
            lastLevel = party[trainer.partySize - 1].level;
            break;
        }

        case TRDATATYPE_WITH_MOVES_AND_ITEM: {
            TrainerMonWithMovesAndItem *party = (TrainerMonWithMovesAndItem *)rawParty;
            lastLevel = party[trainer.partySize - 1].level;
            break;
        }
    }

    u32 prize;
    if ((battleSys->battleType & BATTLE_TYPE_TAG) || battleSys->battleType == BATTLE_TYPE_TRAINER_WITH_AI_PARTNER) {
        prize = lastLevel * 4 * battleCtx->prizeMoneyMul * lbl_80474040[trainer.trainerType];
    } else if (battleSys->battleType & BATTLE_TYPE_DOUBLES) {
        prize = lastLevel * 4 * battleCtx->prizeMoneyMul * 2 * lbl_80474040[trainer.trainerType];
    } else {
        prize = lastLevel * 4 * battleCtx->prizeMoneyMul * lbl_80474040[trainer.trainerType];
    }

    fn_8016E0A0(rawParty);
    return prize;
}
}

#pragma pop

extern "C" {

s32 fn_803CE014(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    s32 v;
    if (a[0x23e4] == 1) {
        v = fn_803CDE80(a, b, 1);
        if ((*(u32 *)(a + 0x2c) & 0x10) || *(u32 *)(a + 0x2c) == 0x4b) {
            v += fn_803CDE80(a, b, 3);
        }
        TrainerInfo_GiveMoney((TrainerInfo *)((u8 *)BattleSystem_GetTrainerInfo((BattleSystem *)a, 0)), v);
    } else {
        v = BattleSystem_CalcMoneyPenalty((Party *)(*(u8 **)(a + 0x68)), (TrainerInfo *)(*(u8 **)(a + 0x48)));
        TrainerInfo_TakeMoney((TrainerInfo *)((u8 *)BattleSystem_GetTrainerInfo((BattleSystem *)a, 0)), v);
    }
    if (v) {
        *(s32 *)(b + 0x130) = v;
    } else {
        *(s32 *)(b + 0x130) = 0;
    }
    return 0;
}

s32 fn_803CE560(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 r = fn_803D803C(a, b, fn_803D6E6C(b));
    BattleController_EmitRecallMessage((BattleSystem *)a, (BattleContext *)b, r, b[r + 0x219c]);
    return 0;
}

s32 fn_803CE5D4(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 r = fn_803D803C(a, b, fn_803D6E6C(b));
    BattleController_EmitSendOutMessage((BattleSystem *)a, (BattleContext *)b, r, b[r + 0x219c]);
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CE648(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitBattleStartMessage((BattleSystem *)a, (BattleContext *)b, fn_803D803C(a, b, fn_803D6E6C(b)));
    return 0;
}

s32 fn_803CE6B4(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitLeadMonMessage((BattleSystem *)a, (BattleContext *)b, fn_803D803C(a, b, fn_803D6E6C(b)));
    return 0;
}

s32 fn_803CE720(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitTrainerMessage((BattleSystem *)a, fn_803D803C(a, b, fn_803D6E6C(b)), *(u32 *)(b + 0x130));
    return 0;
}

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryConversion
s32 fn_803CE78C(BattleSystem *battleSys, BattleContext *battleCtx) {
    int numMoves, i, moveType; // must declare these here to match

    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);

    if (Battler_Ability(battleCtx, battleCtx->attacker) == ABILITY_MULTITYPE) {
        battleCtx->scriptCursor += jumpOnFail;
        return 0;
    }

    for (numMoves = 0; numMoves < LEARNED_MOVES_MAX; numMoves++) {
        if (ATTACKING_MON.moves[numMoves] == MOVE_NONE) {
            break;
        }
    }

    // First, check if there are any non-Conversion moves which have a type different from the
    // source Pokemon's types.
    for (i = 0; i < numMoves; i++) {
        if (ATTACKING_MON.moves[i] == MOVE_CONVERSION) {
            continue;
        }

        moveType = MOVE_DATA(ATTACKING_MON.moves[i]).type;
        if (moveType == TYPE_MYSTERY) {
            if (MON_HAS_TYPE(battleCtx->attacker, TYPE_GHOST)) {
                moveType = TYPE_GHOST;
            } else {
                moveType = TYPE_NORMAL;
            }
        }

        if (MON_IS_NOT_TYPE(battleCtx->attacker, moveType)) {
            break;
        }
    }

    if (i == numMoves) { // no such moves
        battleCtx->scriptCursor += jumpOnFail;
    } else {
        do {
            // Get a random non-Conversion move
            do {
                i = LCRNG_Next() % numMoves;
            } while (ATTACKING_MON.moves[i] == MOVE_CONVERSION);

            moveType = MOVE_DATA(ATTACKING_MON.moves[i]).type;

            // Handle Curse as a Ghost-type move for Ghost-type Pokemon
            if (moveType == TYPE_MYSTERY) {
                if (MON_HAS_TYPE(battleCtx->attacker, TYPE_GHOST)) {
                    moveType = TYPE_GHOST;
                } else {
                    moveType = TYPE_NORMAL;
                }
            }
        } while (MON_HAS_TYPE(battleCtx->attacker, moveType));

        ATTACKING_MON.type1 = moveType;
        ATTACKING_MON.type2 = moveType;
        battleCtx->msgTemp = moveType;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CompareVarToVar
s32 fn_803CE9FC(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int op = fn_803D6E6C((u8 *)battleCtx);
    int lhsVar = fn_803D6E6C((u8 *)battleCtx);
    int rhsVar = fn_803D6E6C((u8 *)battleCtx);
    int jump = fn_803D6E6C((u8 *)battleCtx);

    u32 *lhs = fn_803D6E8C((u8 *)battleSys, (u8 *)battleCtx, lhsVar);
    u32 *rhs = fn_803D6E8C((u8 *)battleSys, (u8 *)battleCtx, rhsVar);

    switch (op) {
    case OPCODE_EQU:
        if (*lhs != *rhs) {
            jump = 0;
        }
        break;

    case OPCODE_NEQ:
        if (*lhs == *rhs) {
            jump = 0;
        }
        break;

    case OPCODE_GT:
        if (*lhs <= *rhs) {
            jump = 0;
        }
        break;

    case OPCODE_LTE:
        if (*lhs > *rhs) {
            jump = 0;
        }
        break;

    case OPCODE_FLAG_SET:
        if ((*lhs & *rhs) == FALSE) {
            jump = 0;
        }
        break;

    case OPCODE_FLAG_NOT:
        if (*lhs & *rhs) {
            jump = 0;
        }
        break;

    case OPCODE_AND:
        if ((*lhs & *rhs) != *rhs) {
            jump = 0;
        }
        break;

    default:
        fn_803D989C(TRUE, BTLSCR_ERR_INVALID);
        break;
    }

    if (jump) {
        battleCtx->scriptCursor += jump;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CompareMonDataToVar
s32 fn_803CEB88(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int op = fn_803D6E6C((u8 *)battleCtx);
    int battler = fn_803D6E6C((u8 *)battleCtx);
    int paramID = fn_803D6E6C((u8 *)battleCtx);
    int rhsVar = fn_803D6E6C((u8 *)battleCtx);
    int jump = fn_803D6E6C((u8 *)battleCtx);

    u32 lhs = BattleMon_Get(battleCtx, fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, battler), (enum BattleMonParam)paramID, NULL);
    u32 *rhs = fn_803D6E8C((u8 *)battleSys, (u8 *)battleCtx, rhsVar);

    switch (op) {
    case OPCODE_EQU:
        if (lhs != *rhs) {
            jump = 0;
        }
        break;

    case OPCODE_NEQ:
        if (lhs == *rhs) {
            jump = 0;
        }
        break;

    case OPCODE_GT:
        if (lhs <= *rhs) {
            jump = 0;
        }
        break;

    case OPCODE_LTE:
        if (lhs > *rhs) {
            jump = 0;
        }
        break;

    case OPCODE_FLAG_SET:
        if ((lhs & *rhs) == FALSE) {
            jump = 0;
        }
        break;

    case OPCODE_FLAG_NOT:
        if (lhs & *rhs) {
            jump = 0;
        }
        break;

    case OPCODE_AND:
        if ((lhs & *rhs) != *rhs) {
            jump = 0;
        }
        break;

    default:
        fn_803D989C(TRUE, BTLSCR_ERR_INVALID);
        break;
    }

    if (jump) {
        battleCtx->scriptCursor += jump;
    }

    return 0;
}
}

#pragma pop

extern "C" {

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_AddPayDayMoney
s32 fn_803CED18(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    battleCtx->msgTemp = battleCtx->payDayCount * battleCtx->prizeMoneyMul;
    if (battleCtx->msgTemp > PAYDAY_MAX) {
        battleCtx->msgTemp = PAYDAY_MAX;
    }

    TrainerInfo_GiveMoney(BattleSystem_GetTrainerInfo(battleSys, BATTLER_US), battleCtx->msgTemp);

    return 0;
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_TryLightScreen
s32 fn_803CED84(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jump = fn_803D6E6C((u8 *)battleCtx);

    int side = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker);

    if (battleCtx->sideConditionsMask[side] & SIDE_CONDITION_LIGHT_SCREEN) {
        battleCtx->scriptCursor += jump;
        battleCtx->moveStatusFlags |= MOVE_STATUS_FAILED;
    } else {
        battleCtx->sideConditionsMask[side] |= SIDE_CONDITION_LIGHT_SCREEN;
        battleCtx->sideConditions[side].lightScreenTurns = NUM_SCREEN_TURNS;
        battleCtx->sideConditions[side].lightScreenUser = battleCtx->attacker;

        if (Battler_HeldItemEffect(battleCtx, battleCtx->attacker) == HOLD_EFFECT_EXTEND_SCREENS) {
            battleCtx->sideConditions[side].lightScreenTurns += Battler_HeldItemPower(battleCtx, battleCtx->attacker, (enum HeldItemPowerOp)0);
        }

        battleCtx->msgBuffer.tags = TAG_MOVE_SIDE;
        battleCtx->msgBuffer.params[0] = battleCtx->moveCur;
        battleCtx->msgBuffer.params[1] = battleCtx->attacker;

        if (BattleSystem_CountAliveBattlers(battleSys, battleCtx, TRUE, battleCtx->attacker) == 2) {
            battleCtx->msgBuffer.id = BattleStrings_Text_MoveRaisedYourTeamsSpecialDefenseSlightly; // "{0} raised [your/its] team's Special Defense slightly!"
        } else {
            battleCtx->msgBuffer.id = BattleStrings_Text_MoveRaisedYourTeamsSpecialDefense; // "{0} raised [your/its] team's Special Defense!"
        }
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryReflect
s32 fn_803CEEC0(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jump = fn_803D6E6C((u8 *)battleCtx);

    int side = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker);

    if (battleCtx->sideConditionsMask[side] & SIDE_CONDITION_REFLECT) {
        battleCtx->scriptCursor += jump;
        battleCtx->moveStatusFlags |= MOVE_STATUS_FAILED;
    } else {
        battleCtx->sideConditionsMask[side] |= SIDE_CONDITION_REFLECT;
        battleCtx->sideConditions[side].reflectTurns = NUM_SCREEN_TURNS;
        battleCtx->sideConditions[side].reflectUser = battleCtx->attacker;

        if (Battler_HeldItemEffect(battleCtx, battleCtx->attacker) == HOLD_EFFECT_EXTEND_SCREENS) {
            battleCtx->sideConditions[side].reflectTurns += Battler_HeldItemPower(battleCtx, battleCtx->attacker, (enum HeldItemPowerOp)0);
        }

        battleCtx->msgBuffer.tags = TAG_MOVE_SIDE;
        battleCtx->msgBuffer.params[0] = battleCtx->moveCur;
        battleCtx->msgBuffer.params[1] = battleCtx->attacker;

        if (BattleSystem_CountAliveBattlers(battleSys, battleCtx, TRUE, battleCtx->attacker) == 2) {
            battleCtx->msgBuffer.id = BattleStrings_Text_MoveRaisedYourTeamsDefenseSlightly; // "{0} raised [your/its] team's Defense slightly!"
        } else {
            battleCtx->msgBuffer.id = BattleStrings_Text_MoveRaisedYourTeamsDefense; // "{0} raised [your/its] team's Defense!"
        }
    }

    return 0;
}
}

#pragma pop

extern "C" {


}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryMist
s32 fn_803CEFFC(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jump = fn_803D6E6C((u8 *)battleCtx);

    int side = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker);

    if (battleCtx->sideConditionsMask[side] & SIDE_CONDITION_MIST) {
        battleCtx->scriptCursor += jump;
        battleCtx->moveStatusFlags |= MOVE_STATUS_FAILED;
    } else {
        battleCtx->sideConditionsMask[side] |= SIDE_CONDITION_MIST;
        battleCtx->sideConditions[side].mistTurns = NUM_SCREEN_TURNS;
        battleCtx->sideConditions[side].mistUser = battleCtx->attacker;
    }

    return 0;
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_TryOHKOMove
s32 fn_803CF0B8(BattleSystem *battleSys, BattleContext *battleCtx) {
    u16 hit;
    battleCtx->scriptCursor++;
    battleCtx->battleStatusMask |= SYSCTL_NONSTANDARD_ACC_CHECK;

    if (Battler_IgnorableAbility(battleCtx, battleCtx->attacker, battleCtx->defender, ABILITY_STURDY) == TRUE) {
        battleCtx->moveStatusFlags |= MOVE_STATUS_STURDY;
        lbl_8048CE28._18 = battleCtx->sideEffectMon;
    } else {
        if ((DEFENDING_MON.moveEffectsMask & MOVE_EFFECT_LOCK_ON) == FALSE
            && Battler_Ability(battleCtx, battleCtx->attacker) != ABILITY_NO_GUARD
            && Battler_Ability(battleCtx, battleCtx->defender) != ABILITY_NO_GUARD) {
            // Use the usual OHKO accuracy check: scale upwards with the difference between the attacker and
            // defender's levels.
            hit = CURRENT_MOVE_DATA.accuracy + (ATTACKING_MON.level - DEFENDING_MON.level);

            if ((LCRNG_Next() % 100) < hit && ATTACKING_MON.level >= DEFENDING_MON.level) {
                hit = TRUE;
            } else {
                hit = FALSE;
            }
        } else {
            if (((DEFENDING_MON.moveEffectsData.lockOnTarget == battleCtx->attacker
                     && (DEFENDING_MON.moveEffectsMask & MOVE_EFFECT_LOCK_ON))
                    || Battler_Ability(battleCtx, battleCtx->attacker) == ABILITY_NO_GUARD
                    || Battler_Ability(battleCtx, battleCtx->defender) == ABILITY_NO_GUARD)
                && ATTACKING_MON.level >= DEFENDING_MON.level) {
                // Bypass the accuracy check: always hit.
                hit = TRUE;
            } else {
                // Fallback to the usual OHKO accuracy check, for some reason.
                hit = CURRENT_MOVE_DATA.accuracy + (ATTACKING_MON.level - DEFENDING_MON.level);

                if ((LCRNG_Next() % 100) < hit && ATTACKING_MON.level >= DEFENDING_MON.level) {
                    hit = TRUE;
                } else {
                    hit = FALSE;
                }
            }

            battleCtx->moveStatusFlags |= MOVE_STATUS_BYPASSED_ACCURACY;
        }

        if (hit) {
            battleCtx->damage = DEFENDING_MON.curHP * -1;
            battleCtx->moveStatusFlags |= MOVE_STATUS_ONE_HIT_KO;
        } else if (ATTACKING_MON.level >= DEFENDING_MON.level) {
            battleCtx->moveStatusFlags |= MOVE_STATUS_MISSED;
        } else {
            battleCtx->moveStatusFlags |= MOVE_STATUS_ONE_HIT_KO_FAILED;
        }
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CF3B4(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    u32 *r = fn_803D6E8C(a, b, x);
    *r = BattleSystem_Divide(*r, y);
    return 0;
}

s32 fn_803CF434(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    s32 *r1 = (s32 *)fn_803D6E8C(a, b, x);
    s32 *r2 = (s32 *)fn_803D6E8C(a, b, y);
    s32 s = 1;
    if (*r1 < 0) {
        s = -1;
    }
    if ((*r1 = *r1 / *r2) == 0) {
        *r1 = s;
    }
    return 0;
}

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryMimic
s32 fn_803CF4E0(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);

    if (Move_CanBeMimicked(DEFENDER_LAST_MOVE) == FALSE
        || (ATTACKING_MON.statusVolatile & VOLATILE_CONDITION_TRANSFORM)
        || (DEFENDING_MON.statusVolatile & VOLATILE_CONDITION_SUBSTITUTE)
        || DEFENDER_LAST_MOVE == MOVE_NONE) {
        battleCtx->scriptCursor += jumpOnFail;
    } else {
        int i, j = -1;
        for (i = 0; i < LEARNED_MOVES_MAX; i++) {
            // Don't try to copy a move that we already know
            if (ATTACKING_MON.moves[i] == DEFENDER_LAST_MOVE) {
                break;
            }

            // Only replace the first instance of Mimic
            if (ATTACKING_MON.moves[i] == MOVE_MIMIC && j == -1) {
                j = i;
            }
        }

        if (i == LEARNED_MOVES_MAX) {
            // Copying a move we do not already know
            battleCtx->msgMoveTemp = DEFENDER_LAST_MOVE;
            ATTACKING_MON.moves[j] = battleCtx->msgMoveTemp;

            // Max out the current PP at 5
            if (MOVE_DATA(battleCtx->msgMoveTemp).pp < 5) {
                ATTACKING_MON.ppCur[j] = MOVE_DATA(battleCtx->msgMoveTemp).pp;
            } else {
                ATTACKING_MON.ppCur[j] = 5;
            }

            ATTACKING_MON.moveEffectsData.mimickedMoveSlot |= FlagIndex(j);

            if (battleCtx->msgMoveTemp == MOVE_LAST_RESORT) {
                ATTACKING_MON.moveEffectsData.lastResortCount = 0;
            }
        } else {
            // We tried to copy a move that we already know
            battleCtx->scriptCursor += jumpOnFail;
        }
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803CF6A4(u8 *a, u8 *b) {
    u16 v;
    s32 i;
    (*(u32 *)(b + 0xb4))++;
    do {
        do {
            v = (s32)LCRNG_Next() % 0x1d3 + 1;
            for (i = 0; i < 4; i++) {
                if (v == *(u16 *)(b + *(u32 *)(b + 0x64) * 0xc0 + i * 2 + 0x2d4c)) {
                    break;
                }
            }
        } while (i != 4);
    } while (Move_CanBeMetronomed(v) == 0);
    *(u32 *)(b + 0x124) = v;
    return 0;
}
}

#pragma pop

extern "C" {

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryDisable
s32 fn_803CF758(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);

    int moveSlot = Battler_SlotForMove(&DEFENDING_MON, DEFENDER_LAST_MOVE);

    if (DEFENDING_MON.moveEffectsData.disabledMove == MOVE_NONE
        && moveSlot != LEARNED_MOVES_MAX
        && DEFENDING_MON.ppCur[moveSlot]
        && DEFENDER_LAST_MOVE) {
        battleCtx->msgMoveTemp = DEFENDER_LAST_MOVE;
        DEFENDING_MON.moveEffectsData.disabledMove = battleCtx->msgMoveTemp;
        DEFENDING_MON.moveEffectsData.disabledTurns = LCRNG_Next() % 4 + 3; // range: [3-6]
    } else {
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_Counter
s32 fn_803CF854(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    int lastAttacker = ATTACKER_TURN_FLAGS.physicalDamageLastAttacker;
    int attackingSide = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker);
    int defendingSide = BattleSystem_GetBattlerSide(battleSys, lastAttacker);

    if (ATTACKER_TURN_FLAGS.physicalDamageTakenFrom[lastAttacker]
        && attackingSide != defendingSide
        && battleCtx->battleMons[lastAttacker].curHP) {
        battleCtx->damage = ATTACKER_TURN_FLAGS.physicalDamageTakenFrom[lastAttacker] * 2;

        if (battleCtx->sideConditions[defendingSide].followMe && FOLLOW_ME_MON(defendingSide).curHP) {
            battleCtx->defender = FOLLOW_ME_USER(defendingSide);
        } else {
            battleCtx->defender = lastAttacker;
        }

        // CompareVarToValue the target is no longer active, pick a random opponent
        // This should always give us an active opponent, unless both have fainted
        if (DEFENDING_MON.curHP == 0) {
            battleCtx->defender = BattleSystem_RandomOpponent(battleSys, battleCtx, battleCtx->attacker);

            // CompareVarToValue there are no possible targets, fail
            if (DEFENDING_MON.curHP == 0) {
                battleCtx->commandNext = BATTLE_CONTROL_UPDATE_MOVE_BUFFERS;
                BattleSystem_LoadScript(battleCtx, NARC_BATTLE_SUB_SEQ, BATTLE_SUBSCRIPT_NO_TARGET);
            }
        }

        BattleSystem_DecPPForPressure(battleCtx, battleCtx->attacker, battleCtx->defender);
    } else {
        ATTACKER_SELF_TURN_FLAGS.skipPressureCheck = TRUE;
        battleCtx->moveStatusFlags |= MOVE_STATUS_FAILED;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_MirrorCoat
s32 fn_803CF9CC(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    int lastAttacker = ATTACKER_TURN_FLAGS.specialDamageLastAttacker;
    int attackingSide = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker);
    int defendingSide = BattleSystem_GetBattlerSide(battleSys, lastAttacker);

    if (ATTACKER_TURN_FLAGS.specialDamageTakenFrom[lastAttacker]
        && attackingSide != defendingSide
        && battleCtx->battleMons[lastAttacker].curHP) {
        battleCtx->damage = ATTACKER_TURN_FLAGS.specialDamageTakenFrom[lastAttacker] * 2;

        if (battleCtx->sideConditions[defendingSide].followMe && FOLLOW_ME_MON(defendingSide).curHP) {
            battleCtx->defender = FOLLOW_ME_USER(defendingSide);
        } else {
            battleCtx->defender = lastAttacker;
        }

        // CompareVarToValue the target is no longer active, pick a random opponent
        // This should always give us an active opponent, unless both have fainted
        if (DEFENDING_MON.curHP == 0) {
            battleCtx->defender = BattleSystem_RandomOpponent(battleSys, battleCtx, battleCtx->attacker);

            // CompareVarToValue there are no possible targets, fail
            if (DEFENDING_MON.curHP == 0) {
                battleCtx->commandNext = BATTLE_CONTROL_UPDATE_MOVE_BUFFERS;
                BattleSystem_LoadScript(battleCtx, NARC_BATTLE_SUB_SEQ, BATTLE_SUBSCRIPT_NO_TARGET);
            }
        }

        BattleSystem_DecPPForPressure(battleCtx, battleCtx->attacker, battleCtx->defender);
    } else {
        ATTACKER_SELF_TURN_FLAGS.skipPressureCheck = TRUE;
        battleCtx->moveStatusFlags |= MOVE_STATUS_FAILED;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryEncore
s32 fn_803CFB44(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);

    int moveSlot = Battler_SlotForMove(&DEFENDING_MON, DEFENDER_LAST_MOVE);
    if (Move_CanBeEncored(battleCtx, DEFENDER_LAST_MOVE) == FALSE) {
        moveSlot = LEARNED_MOVES_MAX;
    }

    if (DEFENDING_MON.moveEffectsData.encoredMove == MOVE_NONE
        && moveSlot != LEARNED_MOVES_MAX
        && DEFENDING_MON.ppCur[moveSlot]
        && DEFENDER_LAST_MOVE) {
        battleCtx->msgMoveTemp = DEFENDER_LAST_MOVE;
        DEFENDING_MON.moveEffectsData.encoredMove = battleCtx->msgMoveTemp;
        DEFENDING_MON.moveEffectsData.encoredMoveSlot = moveSlot;
        DEFENDING_MON.moveEffectsData.encoredTurns = LCRNG_Next() % 5 + 3; // range: [3-7]
    } else {
        battleCtx->moveStatusFlags |= MOVE_STATUS_FAILED;
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryConversion2
s32 fn_803CFC84(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);

    if (Battler_Ability(battleCtx, battleCtx->attacker) == ABILITY_MULTITYPE) {
        battleCtx->scriptCursor += jumpOnFail;
        return 0;
    }

    if (battleCtx->conversion2Move[battleCtx->attacker]
        && battleCtx->conversion2Battler[battleCtx->attacker] != BATTLER_NONE) {
        // Fail to execute if the source move's owner is locked into the first turn of a multi-turn move
        if (Move_IsMultiTurn(battleCtx, battleCtx->conversion2Move[battleCtx->attacker])
            && (battleCtx->battleMons[battleCtx->conversion2Battler[battleCtx->attacker]].statusVolatile & VOLATILE_CONDITION_MOVE_LOCKED)) {
            battleCtx->scriptCursor += jumpOnFail;
            return 0;
        }

        u8 atkType, defType, typeMulti;
        int i, moveType = battleCtx->conversion2Type[battleCtx->attacker];
        for (i = 0; i < 1000; i++) {
            // Get a random entry from the type matchup table
            BattleSystem_TypeMatchup(0xFFFF, &atkType, &defType, &typeMulti);

            // Check if the accessed entry has an attacking type which matches the source move
            // and a defending type which results in a favorable matchup
            if (atkType == moveType
                && typeMulti <= TYPE_MULTI_NOT_VERY_EFF
                && MON_IS_NOT_TYPE(battleCtx->attacker, defType)) {
                ATTACKING_MON.type1 = defType;
                ATTACKING_MON.type2 = defType;
                battleCtx->msgTemp = defType;
                return 0;
            }
        }

        // Fallback to a linear search through the table for the first entry which matches the criteria
        i = 0;
        while (BattleSystem_TypeMatchup(i, &atkType, &defType, &typeMulti) == TRUE) {
            if (atkType == moveType
                && typeMulti <= TYPE_MULTI_NOT_VERY_EFF
                && MON_IS_NOT_TYPE(battleCtx->attacker, defType)) {
                ATTACKING_MON.type1 = defType;
                ATTACKING_MON.type2 = defType;
                battleCtx->msgTemp = defType;
                return 0;
            }

            i++;
        }
    }

    battleCtx->scriptCursor += jumpOnFail;
    return 0;
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_TrySketch
s32 fn_803CFEE4(BattleSystem *battleSys, BattleContext *battleCtx) {
    int moveSlot = -1;

    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);

    // Don't allow Sketch while Transformed or against any of Struggle, Chatter, or Sketch itself
    if ((ATTACKING_MON.statusVolatile & VOLATILE_CONDITION_TRANSFORM)
        || battleCtx->moveSketched[battleCtx->defender] == MOVE_STRUGGLE
        || battleCtx->moveSketched[battleCtx->defender] == MOVE_SKETCH
        || battleCtx->moveSketched[battleCtx->defender] == MOVE_CHATTER
        || battleCtx->moveSketched[battleCtx->defender] == MOVE_NONE) {
        battleCtx->scriptCursor += jumpOnFail;
    } else {
        int i;
        for (i = 0; i < LEARNED_MOVES_MAX; i++) {
            // Don't allow Sketching a move that we already know
            if (ATTACKING_MON.moves[i] != MOVE_SKETCH
                && ATTACKING_MON.moves[i] == battleCtx->moveSketched[battleCtx->defender]) {
                break;
            }

            // Replace the first instance of Sketch only (there should only be one)
            if (ATTACKING_MON.moves[i] == MOVE_SKETCH && moveSlot == -1) {
                moveSlot = i;
            }
        }

        if (i == LEARNED_MOVES_MAX) {
            // Teach the attacker the Sketched move with default PP
            ATTACKING_MON.moves[moveSlot] = battleCtx->moveSketched[battleCtx->defender];
            ATTACKING_MON.ppCur[moveSlot] = MOVE_DATA(battleCtx->moveSketched[battleCtx->defender]).pp;

            BattleController_EmitUpdatePartyMon(battleSys, battleCtx, battleCtx->attacker);
            battleCtx->msgMoveTemp = battleCtx->moveSketched[battleCtx->defender];

            if (battleCtx->msgMoveTemp == MOVE_LAST_RESORT) {
                ATTACKING_MON.moveEffectsData.lastResortCount = 0;
            }
        } else {
            battleCtx->scriptCursor += jumpOnFail;
        }
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TrySleepTalk
s32 fn_803D0070(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);
    int i;
    int invalidMovesMask = 0;

    // Check for invalid moves for the random selection
    for (i = 0; i < LEARNED_MOVES_MAX; i++) {
        if (Move_IsInvoker(ATTACKING_MON.moves[i])
            || ATTACKING_MON.moves[i] == MOVE_FOCUS_PUNCH
            || ATTACKING_MON.moves[i] == MOVE_UPROAR
            || ATTACKING_MON.moves[i] == MOVE_CHATTER
            || Move_IsMultiTurn(battleCtx, ATTACKING_MON.moves[i])) {
            invalidMovesMask |= FlagIndex(i);
        }
    }

    // Check for other invalid moves (only skip the PP check)
    invalidMovesMask = BattleSystem_CheckInvalidMoves(battleSys, battleCtx, battleCtx->attacker, invalidMovesMask, ~CHECK_INVALID_NO_PP);
    if (invalidMovesMask == STRUGGLING_ALL) {
        battleCtx->scriptCursor += jumpOnFail;
    } else {
        do {
            i = LCRNG_Next() % LEARNED_MOVES_MAX;
        } while (invalidMovesMask & FlagIndex(i));

        battleCtx->msgMoveTemp = ATTACKING_MON.moves[i];
    }

    return 0;
}
}

#pragma pop

extern "C" {

u8 fn_803D01BC(s32 a, s32 b) {
    s32 i;
    s32 v = App_PixelCount(a, b, 0x40);
    for (i = 0; i < 6; i++) {
        if (v <= lbl_80405A50[i].a) {
            break;
        }
    }
    return lbl_80405A50[i].b;
}

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CalcFlailPower
s32 fn_803D0230(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    int i, curHPPixels = App_PixelCount(ATTACKING_MON.curHP, ATTACKING_MON.maxHP, 64);
    for (i = 0; i < 6; i++) {
        if (curHPPixels <= lbl_80405A50[i].a) {
            break;
        }
    }

    battleCtx->movePower = lbl_80405A50[i].b;

    return 0;
}
}

#pragma pop

extern "C" {

}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TrySpite
s32 fn_803D02D8(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);

    if (DEFENDER_LAST_MOVE) {
        int moveSlot = Battler_SlotForMove(&DEFENDING_MON, DEFENDER_LAST_MOVE);
        if (moveSlot == LEARNED_MOVES_MAX || DEFENDING_MON.ppCur[moveSlot] == 0) {
            battleCtx->scriptCursor += jumpOnFail;
        } else {
            int dec = 4;
            if (DEFENDING_MON.ppCur[moveSlot] < dec) {
                dec = DEFENDING_MON.ppCur[moveSlot];
            }

            battleCtx->msgMoveTemp = DEFENDER_LAST_MOVE;
            battleCtx->msgTemp = dec;
            DEFENDING_MON.ppCur[moveSlot] -= dec;

            BattleMon_CopyToParty(battleSys, battleCtx, battleCtx->defender);
        }
    } else {
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_TryPartyStatusRefresh
s32 fn_803D03E4(BattleSystem *battleSys, BattleContext *battleCtx) {
    u32 battleType = BattleSystem_GetBattleType(battleSys);
    battleCtx->scriptCursor++;

    battleCtx->calcTemp = 0;
    if (battleCtx->moveCur == MOVE_HEAL_BELL) {
        battleCtx->msgMoveTemp = battleCtx->moveCur;

        if (Battler_Ability(battleCtx, battleCtx->attacker) != ABILITY_SOUNDPROOF) {
            ATTACKING_MON.status = MON_CONDITION_NONE;
            ATTACKING_MON.statusVolatile &= ~VOLATILE_CONDITION_NIGHTMARE;
        } else {
            battleCtx->calcTemp |= (SOUNDPROOF_SLOT_1 | NO_PARTNER_SLOT_1);
        }

        if (battleType & BATTLE_TYPE_DOUBLES) {
            int partner = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, BTLSCR_ATTACKER_PARTNER);

            if ((battleCtx->battlersSwitchingMask & FlagIndex(partner)) == FALSE) {
                if (Battler_IgnorableAbility(battleCtx, battleCtx->attacker, partner, ABILITY_SOUNDPROOF) == FALSE) {
                    battleCtx->battleMons[partner].status = MON_CONDITION_NONE;
                    battleCtx->battleMons[partner].statusVolatile &= ~VOLATILE_CONDITION_NIGHTMARE;
                } else {
                    battleCtx->msgBattlerTemp = partner;
                    battleCtx->calcTemp |= (SOUNDPROOF_SLOT_2 | NO_PARTNER_SLOT_2);
                }
            }
        } else {
            battleCtx->calcTemp |= NO_PARTNER_SLOT_2;
        }
    } else {
        ATTACKING_MON.status = MON_CONDITION_NONE;
        ATTACKING_MON.statusVolatile &= ~VOLATILE_CONDITION_NIGHTMARE;

        if (battleType & BATTLE_TYPE_DOUBLES) {
            int partner = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, BTLSCR_ATTACKER_PARTNER);

            if ((battleCtx->battlersSwitchingMask & FlagIndex(partner)) == FALSE) {
                battleCtx->battleMons[partner].status = MON_CONDITION_NONE;
                battleCtx->battleMons[partner].statusVolatile &= ~VOLATILE_CONDITION_NIGHTMARE;
            }
        } else {
            battleCtx->calcTemp |= NO_PARTNER_SLOT_2;
        }
    }

    BattleController_EmitRefreshPartyStatus(battleSys, battleCtx, battleCtx->attacker, battleCtx->moveCur);
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryStealItem
s32 fn_803D05B4(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);
    int jumpStickyHold = fn_803D6E6C((u8 *)battleCtx);

    u32 battleType = BattleSystem_GetBattleType(battleSys);
    int attackingSide = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker);

    if (BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker) && (battleType & BATTLE_TYPE_FRONTIER_LINK) == FALSE) {
        // AI trainers are unable to steal items outside of the Battle Frontier. PvP trainers can steal items.
        battleCtx->scriptCursor += jumpOnFail;
    } else if (battleCtx->sideConditions[attackingSide].knockedOffItemsMask & FlagIndex(battleCtx->selectedPartySlot[battleCtx->attacker])) {
        // The attacker has an item which has been suppressed.
        battleCtx->scriptCursor += jumpOnFail;
    } else if (Battler_Ability(battleCtx, battleCtx->attacker) == ABILITY_MULTITYPE || Battler_Ability(battleCtx, battleCtx->defender) == ABILITY_MULTITYPE) {
        // Either battler has Multitype.
        battleCtx->scriptCursor += jumpOnFail;
    } else if (DEFENDING_MON.heldItem == ITEM_GRISEOUS_ORB) {
        // The defender is holding a Griseous Orb.
        battleCtx->scriptCursor += jumpOnFail;
    } else if (DEFENDING_MON.moveEffectsData.custapBerry || DEFENDING_MON.moveEffectsData.quickClaw) {
        // The defender activated a Custap Berry or a Quick Claw this turn.
        battleCtx->scriptCursor += jumpOnFail;
    } else if (DEFENDING_MON.heldItem && Battler_IgnorableAbility(battleCtx, battleCtx->attacker, battleCtx->defender, ABILITY_STICKY_HOLD) == TRUE) {
        // The defender has a held item, but has the ability Sticky Hold.
        battleCtx->scriptCursor += jumpStickyHold;
    } else if (ATTACKING_MON.heldItem || BattleSystem_CanStealItem(battleSys, battleCtx, battleCtx->defender) == FALSE) {
        // The attacker has an item, or the defender's item cannot be stolen.
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryProtection
s32 fn_803D074C(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);

    if (battleCtx->moveProtect[battleCtx->attacker] != MOVE_PROTECT
        && battleCtx->moveProtect[battleCtx->attacker] != MOVE_DETECT
        && battleCtx->moveProtect[battleCtx->attacker] != MOVE_ENDURE) {
        battleCtx->battleMons[battleCtx->attacker].moveEffectsData.protectSuccessTurns = 0;
    }

    int waitingBattlers = 0;
    for (int i = 0; i < BattleSystem_GetMaxBattlers(battleSys); i++) {
        if (battleCtx->battlerActions[i][BATTLE_ACTION_PICK_COMMAND] != BATTLE_CONTROL_MOVE_END) {
            waitingBattlers++;
        }
    }

    BOOL moreBattlersThisTurn;
    if (waitingBattlers == 1) {
        moreBattlersThisTurn = FALSE;
    } else {
        moreBattlersThisTurn = TRUE;
    }

    if (lbl_80642FF8[ATTACKING_MON.moveEffectsData.protectSuccessTurns] >= LCRNG_Next()
        && moreBattlersThisTurn) {
        if (CURRENT_MOVE_DATA.effect == BATTLE_EFFECT_PROTECT) {
            ATTACKER_TURN_FLAGS.protecting = TRUE;
            battleCtx->msgBuffer.id = BattleStrings_Text_PokemonProtectedItself2_Ally; // "{0} protected itself!"
        }

        if (CURRENT_MOVE_DATA.effect == BATTLE_EFFECT_SURVIVE_WITH_1_HP) {
            ATTACKER_TURN_FLAGS.enduring = TRUE;
            battleCtx->msgBuffer.id = BattleStrings_Text_PokemonBracedItself_Ally; // "{0} braced itself!"
        }

        battleCtx->msgBuffer.tags = TAG_NICKNAME;
        battleCtx->msgBuffer.params[0] = BattleSystem_NicknameTag(battleCtx, battleCtx->attacker);

        if (ATTACKING_MON.moveEffectsData.protectSuccessTurns < 4 - 1) {
            ATTACKING_MON.moveEffectsData.protectSuccessTurns++;
        }
    } else {
        ATTACKING_MON.moveEffectsData.protectSuccessTurns = 0;
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D091C(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    s32 q = BattleSystem_Divide(*(s32 *)(b + *(u32 *)(b + 0x64) * 0xc0 + 0x2d90), 4);
    u8 *p = b + *(u32 *)(b + 0x64) * 0xc0;
    if (*(s32 *)(p + 0x2d8c) <= q) {
        *(u32 *)(b + 0xb4) += n;
    } else {
        *(s32 *)(b + 0x215c) = -q;
        *(s32 *)(p + 0x2de0) = q;
        *(u32 *)(b + *(u32 *)(b + 0x64) * 0xc0 + 0x2db0) &= ~0xe000;
    }
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryWhirlwind
s32 fn_803D09CC(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);
    u32 battleType = BattleSystem_GetBattleType(battleSys);

    if (battleType & BATTLE_TYPE_TRAINER) {
        Party *defenderParty;
        Pokemon *mon;
        int defenderPartyCount;
        int eligibleMons = 0, maxActiveMons, i, partyStart, partyEnd, max;
        int selectedSlot1, selectedSlot2;

        defenderParty = BattleSystem_GetParty(battleSys, battleCtx->defender);
        defenderPartyCount = BattleSystem_GetPartyCount(battleSys, battleCtx->defender);

        if ((battleType & BATTLE_TYPE_2vs2)
            || ((battleType & BATTLE_TYPE_TAG) && BattleSystem_GetBattlerSide(battleSys, battleCtx->defender))) {
            // There are two battlers out at one time, but only one of these belongs to each trainer.
            partyStart = 0;
            partyEnd = defenderPartyCount;
            max = defenderPartyCount;
            maxActiveMons = 1;
            selectedSlot1 = battleCtx->selectedPartySlot[battleCtx->defender];
            selectedSlot2 = battleCtx->selectedPartySlot[battleCtx->defender];
        } else if (battleType & BATTLE_TYPE_DOUBLES) {
            // There are two battlers out at one time, and both belong to the same trainer.
            partyStart = 0;
            partyEnd = defenderPartyCount;
            max = defenderPartyCount;
            maxActiveMons = 2;
            selectedSlot1 = battleCtx->selectedPartySlot[battleCtx->defender];
            selectedSlot2 = battleCtx->selectedPartySlot[BattleSystem_GetPartner(battleSys, battleCtx->defender)];
        } else {
            // There is only one active battler (singles).
            partyStart = 0;
            partyEnd = defenderPartyCount;
            max = defenderPartyCount;
            maxActiveMons = 1;
            selectedSlot1 = battleCtx->selectedPartySlot[battleCtx->defender];
            selectedSlot2 = battleCtx->selectedPartySlot[battleCtx->defender];
        }

        // Count the number of eligible mons in the party.
        for (i = partyStart; i < partyEnd; i++) {
            mon = Party_GetPokemonBySlotIndex(defenderParty, i);

            if (Pokemon_GetValue(mon, MON_DATA_SPECIES, NULL)
                && Pokemon_GetValue(mon, MON_DATA_IS_EGG, NULL) == FALSE
                && Pokemon_GetValue(mon, MON_DATA_HP, NULL)) {
                eligibleMons++;
            }
        }

        // Check if there are more eligible mons in the back of the party.
        if (eligibleMons <= maxActiveMons) {
            battleCtx->scriptCursor += jumpOnFail;
        } else if (BattleSystem_CanWhirlwind(battleCtx)) {
            // Pick a random eligible mon from the back of the party.
            do {
                do {
                    i = LCRNG_Next() % max;
                    i += partyStart;
                } while (i == selectedSlot1 || i == selectedSlot2);

                mon = Party_GetPokemonBySlotIndex(defenderParty, i);
            } while (Pokemon_GetValue(mon, MON_DATA_SPECIES, NULL) == SPECIES_NONE
                || Pokemon_GetValue(mon, MON_DATA_IS_EGG, NULL) == TRUE
                || Pokemon_GetValue(mon, MON_DATA_HP, NULL) == 0);

            battleCtx->switchedPartySlot[battleCtx->defender] = i;
        } else {
            // We failed the random Whirlwind check.
            battleCtx->scriptCursor += jumpOnFail;
        }
    } else if (BattleSystem_CanWhirlwind(battleCtx) == FALSE) {
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_Transform
s32 fn_803D0C28(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    ATTACKING_MON.statusVolatile |= VOLATILE_CONDITION_TRANSFORM;
    ATTACKING_MON.moveEffectsData.disabledMove = MOVE_NONE;
    ATTACKING_MON.moveEffectsData.disabledTurns = 0;
    ATTACKING_MON.moveEffectsData.transformedPID = DEFENDING_MON.personality;
    ATTACKING_MON.moveEffectsData.transformedGender = DEFENDING_MON.gender;
    ATTACKING_MON.moveEffectsData.mimickedMoveSlot = 0;
    ATTACKING_MON.moveEffectsData.lastResortCount = 0;

    u8 *attackerData = (u8 *)&ATTACKING_MON;
    u8 *defenderData = (u8 *)&DEFENDING_MON;

    int i; // does not match if this is declared outside the individual loops' scopes
    for (i = 0; i < XtOffset(BattleMon *, ability) + 1; i++) {
        attackerData[i] = defenderData[i];
    }

    ATTACKING_MON.weatherAbilityAnnounced = FALSE;
    ATTACKING_MON.intimidateAnnounced = FALSE;
    ATTACKING_MON.traceAnnounced = FALSE;
    ATTACKING_MON.downloadAnnounced = FALSE;
    ATTACKING_MON.anticipationAnnounced = FALSE;
    ATTACKING_MON.forewarnAnnounced = FALSE;
    ATTACKING_MON.friskAnnounced = FALSE;
    ATTACKING_MON.moldBreakerAnnounced = FALSE;
    ATTACKING_MON.pressureAnnounced = FALSE;
    ATTACKING_MON.moveEffectsData.truant = battleCtx->totalTurns & 1;
    ATTACKING_MON.moveEffectsData.slowStartTurnNumber = battleCtx->totalTurns + 1;
    ATTACKING_MON.slowStartAnnounced = FALSE;
    ATTACKING_MON.slowStartFinished = FALSE;

    for (i = 0; i < LEARNED_MOVES_MAX; i++) {
        if (MOVE_DATA(ATTACKING_MON.moves[i]).pp < 5) {
            ATTACKING_MON.ppCur[i] = MOVE_DATA(ATTACKING_MON.moves[i]).pp;
        } else {
            ATTACKING_MON.ppCur[i] = 5;
        }
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TrySpikes
s32 fn_803D0EC8(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);
    int defendingSide = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker) ^ 1;

    if (battleCtx->sideConditions[defendingSide].spikesLayers == 3) {
        battleCtx->selfTurnFlags[battleCtx->attacker].skipPressureCheck = TRUE;
        battleCtx->scriptCursor += jumpOnFail;
    } else {
        battleCtx->sideConditionsMask[defendingSide] |= SIDE_CONDITION_SPIKES;
        battleCtx->sideConditions[defendingSide].spikesLayers++;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CheckSpikes
s32 fn_803D0F94(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);

    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);
    int side = BattleSystem_GetBattlerSide(battleSys, battler);

    if (battleCtx->sideConditions[side].spikesLayers && battleCtx->battleMons[battler].curHP) {
        battleCtx->hpCalcTemp = (5 - battleCtx->sideConditions[side].spikesLayers) * 2;
        battleCtx->hpCalcTemp = BattleSystem_Divide(battleCtx->battleMons[battler].maxHP * -1, battleCtx->hpCalcTemp);
    } else {
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

extern "C" {



}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryPerishSong
s32 fn_803D1064(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);
    int maxBattlers = BattleSystem_GetMaxBattlers(battleSys);

    battleCtx->calcTemp = maxBattlers;

    int ineligibleBattlers = 0;
    for (int i = 0; i < maxBattlers; i++) {
        if ((battleCtx->battleMons[i].moveEffectsMask & MOVE_EFFECT_PERISH_SONG)
            || battleCtx->battleMons[i].curHP == 0
            || Battler_IgnorableAbility(battleCtx, battleCtx->attacker, i, ABILITY_SOUNDPROOF) == TRUE) {
            ineligibleBattlers++;
        } else {
            battleCtx->battleMons[i].moveEffectsMask |= MOVE_EFFECT_PERISH_SONG;
            battleCtx->battleMons[i].moveEffectsData.perishSongTurns = 3;
        }
    }

    if (ineligibleBattlers == maxBattlers) {
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D1150(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 *r = fn_803D6E8C(a, b, fn_803D6E6C(b));
    *r = b[*(u32 *)(b + 0x3104) + 0x21ec];
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D11BC(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    u32 *r = fn_803D6E8C(a, b, x);
    if (*r < (u32)BattleSystem_GetMaxBattlers((BattleSystem *)a)) {
        *(u32 *)(b + 0xb4) += y;
    }
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_EndOfTurnWeatherEffect
s32 fn_803D124C(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);

    battleCtx->scriptTemp = 0;
    battleCtx->hpCalcTemp = 0;

    int type1 = BattleMon_Get(battleCtx, battler, BATTLEMON_TYPE_1, NULL);
    int type2 = BattleMon_Get(battleCtx, battler, BATTLEMON_TYPE_2, NULL);

    if (NO_CLOUD_NINE) {
        if (WEATHER_IS_SAND
            && type1 != TYPE_ROCK && type2 != TYPE_ROCK
            && type1 != TYPE_STEEL && type2 != TYPE_STEEL
            && type1 != TYPE_GROUND && type2 != TYPE_GROUND
            && battleCtx->battleMons[battler].curHP
            && Battler_Ability(battleCtx, battler) != ABILITY_SAND_VEIL
            && (battleCtx->battleMons[battler].moveEffectsMask & MOVE_EFFECT_NO_WEATHER_DAMAGE) == FALSE) {
            battleCtx->msgMoveTemp = MOVE_SANDSTORM;
            battleCtx->hpCalcTemp = BattleSystem_Divide(battleCtx->battleMons[battler].maxHP * -1, 16);
        }

        if (WEATHER_IS_SUN
            && battleCtx->battleMons[battler].curHP
            && (battleCtx->battleMons[battler].moveEffectsMask & MOVE_EFFECT_NO_WEATHER_DAMAGE) == FALSE) {
            if (Battler_Ability(battleCtx, battler) == ABILITY_DRY_SKIN
                || Battler_Ability(battleCtx, battler) == ABILITY_SOLAR_POWER) {
                battleCtx->hpCalcTemp = BattleSystem_Divide(battleCtx->battleMons[battler].maxHP * -1, 8);
            }

            if (Battler_Ability(battleCtx, battler) == ABILITY_SOLAR_POWER) {
                battleCtx->scriptTemp = WEATHER_EFFECT_SOLAR_POWER;
            }
        }

        if (WEATHER_IS_HAIL
            && battleCtx->battleMons[battler].curHP
            && (battleCtx->battleMons[battler].moveEffectsMask & MOVE_EFFECT_NO_WEATHER_DAMAGE) == FALSE) {
            if (Battler_Ability(battleCtx, battler) == ABILITY_ICE_BODY) {
                if (battleCtx->battleMons[battler].curHP < battleCtx->battleMons[battler].maxHP) {
                    battleCtx->hpCalcTemp = BattleSystem_Divide(battleCtx->battleMons[battler].maxHP, 16);
                }
            } else if (type1 != TYPE_ICE
                && type2 != TYPE_ICE
                && Battler_Ability(battleCtx, battler) != ABILITY_SNOW_CLOAK) {
                battleCtx->msgMoveTemp = MOVE_HAIL;
                battleCtx->hpCalcTemp = BattleSystem_Divide(battleCtx->battleMons[battler].maxHP * -1, 16);
            }
        }

        if (WEATHER_IS_RAIN) {
            if (battleCtx->battleMons[battler].curHP
                && battleCtx->battleMons[battler].curHP < battleCtx->battleMons[battler].maxHP
                && Battler_Ability(battleCtx, battler) == ABILITY_RAIN_DISH) {
                battleCtx->hpCalcTemp = BattleSystem_Divide(battleCtx->battleMons[battler].maxHP, 16);
            }

            if (battleCtx->battleMons[battler].curHP
                && battleCtx->battleMons[battler].curHP < battleCtx->battleMons[battler].maxHP
                && Battler_Ability(battleCtx, battler) == ABILITY_DRY_SKIN) {
                battleCtx->hpCalcTemp = BattleSystem_Divide(battleCtx->battleMons[battler].maxHP, 8);
            }

            if (battleCtx->battleMons[battler].curHP
                && (battleCtx->battleMons[battler].status & MON_CONDITION_ANY)
                && Battler_Ability(battleCtx, battler) == ABILITY_HYDRATION) {
                if (battleCtx->battleMons[battler].status & MON_CONDITION_SLEEP) {
                    battleCtx->msgTemp = MSGCOND_SLEEP;
                } else if (battleCtx->battleMons[battler].status & MON_CONDITION_ANY_POISON) {
                    battleCtx->msgTemp = MSGCOND_POISON;
                } else if (battleCtx->battleMons[battler].status & MON_CONDITION_BURN) {
                    battleCtx->msgTemp = MSGCOND_BURN;
                } else if (battleCtx->battleMons[battler].status & MON_CONDITION_PARALYSIS) {
                    battleCtx->msgTemp = MSGCOND_PARALYSIS;
                } else {
                    battleCtx->msgTemp = MSGCOND_FREEZE;
                }

                battleCtx->scriptTemp = WEATHER_EFFECT_HYDRATION;
                lbl_8048CE28._0C = battler;
            }
        }
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CalcRolloutPower
s32 fn_803D1640(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    ATTACKER_SELF_TURN_FLAGS.repeatedMoveCount = ATTACKING_MON.moveEffectsData.rolloutCount;

    if ((ATTACKING_MON.statusVolatile & VOLATILE_CONDITION_MOVE_LOCKED) == FALSE) {
        Battler_LockMoveChoice(battleSys, battleCtx, battleCtx->attacker);
        ATTACKING_MON.moveEffectsData.rolloutCount = 5;
    }

    if (--ATTACKING_MON.moveEffectsData.rolloutCount == 0) {
        Battler_UnlockMoveChoice(battleSys, battleCtx, battleCtx->attacker);
    }

    battleCtx->movePower = CURRENT_MOVE_DATA.power;

    // must declare i first to match (regswap)
    int i, exponent = 5 - ATTACKING_MON.moveEffectsData.rolloutCount;
    for (i = 1; i < exponent; i++) {
        battleCtx->movePower *= 2;
    }

    if (ATTACKING_MON.statusVolatile & VOLATILE_CONDITION_DEFENSE_CURL) {
        battleCtx->movePower *= 2;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CalcFuryCutterPower
s32 fn_803D1788(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    if (ATTACKING_MON.moveEffectsData.furyCutterCount < 5) {
        ATTACKING_MON.moveEffectsData.furyCutterCount++;
    }

    battleCtx->movePower = CURRENT_MOVE_DATA.power;

    for (int i = 1; i < ATTACKING_MON.moveEffectsData.furyCutterCount; i++) {
        battleCtx->movePower *= 2;
    }

    return 0;
}
}

#pragma pop

extern "C" {


}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryAttract
s32 fn_803D180C(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);

    if (battleCtx->battleMons[battleCtx->msgBattlerTemp].gender == battleCtx->battleMons[battleCtx->sideEffectMon].gender
        || battleCtx->battleMons[battleCtx->sideEffectMon].statusVolatile & VOLATILE_CONDITION_ATTRACT
        || battleCtx->battleMons[battleCtx->msgBattlerTemp].gender == GENDER_NONE
        || battleCtx->battleMons[battleCtx->sideEffectMon].gender == GENDER_NONE) {
        battleCtx->scriptCursor += jumpOnFail;
    } else {
        battleCtx->battleMons[battleCtx->sideEffectMon].statusVolatile |= FlagIndex(battleCtx->msgBattlerTemp) << VOLATILE_CONDITION_ATTRACT_SHIFT;
    }

    return 0;
}
}

#pragma pop

extern "C" {

}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TrySafeguard
s32 fn_803D18CC(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);
    int side = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker);

    if (battleCtx->sideConditionsMask[side] & SIDE_CONDITION_SAFEGUARD) {
        battleCtx->scriptCursor += jumpOnFail;
        battleCtx->moveStatusFlags |= MOVE_STATUS_FAILED;
    } else {
        battleCtx->sideConditionsMask[side] |= SIDE_CONDITION_SAFEGUARD;
        battleCtx->sideConditions[side].safeguardTurns = 5;
        battleCtx->sideConditions[side].safeguardUser = battleCtx->attacker;
        battleCtx->msgBuffer.tags = TAG_NONE_SIDE_CONSCIOUS;
        battleCtx->msgBuffer.params[0] = battleCtx->attacker;
        battleCtx->msgBuffer.id = BattleStrings_Text_YourTeamBecameCloakedInAMysticalVeil; // "[Your/The foe's] team became cloaked in a mystical veil!"
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D19A0(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    s32 r = (u8)LCRNG_Next();
    if (r < 0x66) {
        *(u32 *)(b + 0x2154) = 40;
    } else if (r < 0xb2) {
        *(u32 *)(b + 0x2154) = 80;
    } else if (r < 0xcc) {
        *(u32 *)(b + 0x2154) = 120;
    } else {
        *(s32 *)(b + 0x215c) = BattleSystem_Divide(*(s32 *)(b + *(u32 *)(b + 0x6c) * 0xc0 + 0x2d90), 4);
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D1A58(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    if (b[0x3120] == 0) {
        u8 v = (s32)LCRNG_Next() % 100;
        b[0x3120] = v;
        if (v < 5) {
            *(u32 *)(b + 0x2154) = 10;
            b[0x3120] = 4;
        } else if (v < 15) {
            *(u32 *)(b + 0x2154) = 30;
            b[0x3120] = 5;
        } else if (v < 35) {
            *(u32 *)(b + 0x2154) = 50;
            b[0x3120] = 6;
        } else if (v < 65) {
            *(u32 *)(b + 0x2154) = 70;
            b[0x3120] = 7;
        } else if (v < 85) {
            *(u32 *)(b + 0x2154) = 90;
            b[0x3120] = 8;
        } else if (v < 95) {
            *(u32 *)(b + 0x2154) = 110;
            b[0x3120] = 9;
        } else {
            *(u32 *)(b + 0x2154) = 150;
            b[0x3120] = 10;
        }
    }
    *(u32 *)(b + 0x130) = b[0x3120];
    return 0;
}

s32 fn_803D1B7C(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    s32 y = fn_803D6E6C(b);
    u32 z = fn_803D6E6C(b);
    x = fn_803D803C(a, b, x);
    if (BattleSystem_AnyReplacementMons((BattleSystem *)a, (BattleContext *)b, x) == 0) {
        *(u32 *)(b + 0xb4) += z;
    } else if (y == 1) {
        *(u32 *)(b + x * 4 + 0x13c) |= 1;
    }
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_RapidSpin
s32 fn_803D1C3C(BattleSystem *battleSys, BattleContext *battleCtx) {
    int side = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker);

    if (ATTACKING_MON.statusVolatile & VOLATILE_CONDITION_BIND) {
        ATTACKING_MON.statusVolatile &= ~VOLATILE_CONDITION_BIND;
        battleCtx->msgBattlerTemp = ATTACKING_MON.moveEffectsData.bindTarget;
        battleCtx->msgMoveTemp = ATTACKING_MON.moveEffectsData.bindingMove;
        BattleSystem_CallScript(battleCtx, NARC_BATTLE_SUB_SEQ, BATTLE_SUBSCRIPT_BREAK_BIND_EFFECT);

        return 0;
    }

    if (ATTACKING_MON.moveEffectsMask & MOVE_EFFECT_LEECH_SEED) {
        ATTACKING_MON.moveEffectsMask &= ~MOVE_EFFECT_LEECH_SEED;
        ATTACKING_MON.moveEffectsMask &= ~MOVE_EFFECT_LEECH_SEED_RECIPIENT;
        battleCtx->msgMoveTemp = MOVE_LEECH_SEED;
        BattleSystem_CallScript(battleCtx, NARC_BATTLE_SUB_SEQ, BATTLE_SUBSCRIPT_BLOW_AWAY_HAZARDS);

        return 0;
    }

    if (battleCtx->sideConditions[side].spikesLayers) {
        battleCtx->sideConditionsMask[side] &= ~SIDE_CONDITION_SPIKES;
        battleCtx->sideConditions[side].spikesLayers = 0;
        battleCtx->msgMoveTemp = MOVE_SPIKES;
        BattleSystem_CallScript(battleCtx, NARC_BATTLE_SUB_SEQ, BATTLE_SUBSCRIPT_BLOW_AWAY_HAZARDS);

        return 0;
    }

    if (battleCtx->sideConditions[side].toxicSpikesLayers) {
        battleCtx->sideConditionsMask[side] &= ~SIDE_CONDITION_TOXIC_SPIKES;
        battleCtx->sideConditions[side].toxicSpikesLayers = 0;
        battleCtx->msgMoveTemp = MOVE_TOXIC_SPIKES;

        BattleSystem_CallScript(battleCtx, NARC_BATTLE_SUB_SEQ, BATTLE_SUBSCRIPT_BLOW_AWAY_HAZARDS);

        return 0;
    }

    if (battleCtx->sideConditionsMask[side] & SIDE_CONDITION_STEALTH_ROCK) {
        battleCtx->sideConditionsMask[side] &= ~SIDE_CONDITION_STEALTH_ROCK;
        battleCtx->msgMoveTemp = MOVE_STEALTH_ROCK;
        BattleSystem_CallScript(battleCtx, NARC_BATTLE_SUB_SEQ, BATTLE_SUBSCRIPT_BLOW_AWAY_HAZARDS);

        return 0;
    }

    battleCtx->scriptCursor++;

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D1DFC(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    if ((*(u32 *)(b + 0x180) & 0x80ff) == 0 ||
        BattleSystem_CountAbility((BattleSystem *)a, (BattleContext *)b, (enum CountAbilityMode)8, 0, 0xd) ||
        BattleSystem_CountAbility((BattleSystem *)a, (BattleContext *)b, (enum CountAbilityMode)8, 0, 0x4c)) {
        *(u32 *)(b + 0x215c) = *(u32 *)(b + *(u32 *)(b + 0x64) * 0xc0 + 0x2d90) >> 1;
    } else if (*(u32 *)(b + 0x180) & 0x30) {
        *(s32 *)(b + 0x215c) = BattleSystem_Divide(*(s32 *)(b + *(u32 *)(b + 0x64) * 0xc0 + 0x2d90) * 20, 30);
    } else {
        *(s32 *)(b + 0x215c) = BattleSystem_Divide(*(s32 *)(b + *(u32 *)(b + 0x64) * 0xc0 + 0x2d90), 4);
    }
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CalcHiddenPowerParams
s32 fn_803D1EEC(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    battleCtx->movePower = ((ATTACKING_MON.hpIV & 2) >> 1)
        | (ATTACKING_MON.attackIV & 2)
        | ((ATTACKING_MON.defenseIV & 2) << 1)
        | ((ATTACKING_MON.speedIV & 2) << 2)
        | ((ATTACKING_MON.spAttackIV & 2) << 3)
        | ((ATTACKING_MON.spDefenseIV & 2) << 4);

    battleCtx->moveType = (ATTACKING_MON.hpIV & 1)
        | ((ATTACKING_MON.attackIV & 1) << 1)
        | ((ATTACKING_MON.defenseIV & 1) << 2)
        | ((ATTACKING_MON.speedIV & 1) << 3)
        | ((ATTACKING_MON.spAttackIV & 1) << 4)
        | ((ATTACKING_MON.spDefenseIV & 1) << 5);

    battleCtx->movePower = battleCtx->movePower * 40 / 63 + 30;
    battleCtx->moveType = battleCtx->moveType * 15 / 63 + 1;

    if (battleCtx->moveType >= TYPE_MYSTERY) {
        battleCtx->moveType++;
    }

    return 0;
}
}

#pragma pop

extern "C" {


}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CopyStatStages
s32 fn_803D1F84(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    for (int i = BATTLE_STAT_HP; i < BATTLE_STAT_MAX; i++) {
        ATTACKING_MON.statBoosts[i] = DEFENDING_MON.statBoosts[i];
    }

    ATTACKING_MON.statusVolatile |= (DEFENDING_MON.statusVolatile & VOLATILE_CONDITION_FOCUS_ENERGY);

    return 0;
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_TryFutureSight
s32 fn_803D1FFC(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);

    if (battleCtx->fieldConditions.futureSightTurns[battleCtx->defender] == 0) {
        int side = BattleSystem_GetBattlerSide(battleSys, battleCtx->defender);
        battleCtx->sideConditionsMask[side] |= SIDE_CONDITION_FUTURE_SIGHT;
        battleCtx->fieldConditions.futureSightTurns[battleCtx->defender] = 3;
        battleCtx->fieldConditions.futureSightMove[battleCtx->defender] = battleCtx->moveCur;
        battleCtx->fieldConditions.futureSightAttacker[battleCtx->defender] = battleCtx->attacker;

        // Calculate the damage at the time of Future Sight setup.
        // Do not check for type effectiveness nor crits.
        int damage = BattleSystem_CalcMoveDamage(battleSys,
                         battleCtx,
                         battleCtx->moveCur,
                         battleCtx->sideConditionsMask[side],
                         battleCtx->fieldConditionsMask,
                         0,
                         0,
                         battleCtx->attacker,
                         battleCtx->defender,
                         1)
            * -1;
        battleCtx->fieldConditions.futureSightDamage[battleCtx->defender] = BattleSystem_CalcDamageVariance(battleCtx, damage);

        if (ATTACKER_TURN_FLAGS.helpingHand) {
            battleCtx->fieldConditions.futureSightDamage[battleCtx->defender] = battleCtx->fieldConditions.futureSightDamage[battleCtx->defender] * 15 / 10;
        }
    } else {
        lbl_8048CDE8.args[0] = battleCtx->defender;
        fn_8016FA4C(0x14, &lbl_8048CDE8);
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D2168(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 w0 = fn_803D6E6C(b);
    u32 x0 = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    u32 z = fn_803D6E6C(b);
    u32 w = fn_803D803C(a, b, w0);
    u32 x = fn_803D803C(a, b, x0);
    BattleControllerPlayer_CheckMoveHit((BattleSystem *)a, (BattleContext *)b, w, x, (u32)fn_803D90A0(b, y));
    if (*(u32 *)(b + 0x216c) & 0x1fd849) {
        *(u32 *)(b + 0xb4) += z;
        *(u32 *)&lbl_8048CDE8 = x;
        fn_8016FA4C(0xb, &lbl_8048CDE8);
    }
    return 0;
}

s32 fn_803D225C(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    if (Battler_IsTrappedMsg((BattleSystem *)a, (BattleContext *)b, *(u32 *)(b + 0x64), (BattleMessage *)0)) {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on

extern "C" {

// pokeplatinum BtlCmd_BeatUp
s32 fn_803D22D4(BattleSystem *battleSys, BattleContext *battleCtx) {
    int partyCount;
    int species;
    int form;
    int level;
    Pokemon *mon;

    battleCtx->scriptCursor++;

    partyCount = BattleSystem_GetPartyCount(battleSys, battleCtx->attacker);

    if (battleCtx->multiHitNumHits == 0) {
        battleCtx->multiHitNumHits = 2; // not actually used, just set to make multi-hit stuff work
        battleCtx->multiHitAccuracyCheck = SYSCTL_MULTI_HIT_MOVE;
        battleCtx->beatUpCounter = 0;

        while (TRUE) {
            // Find the next mon to deal Beat Up damage
            mon = BattleSystem_GetPartyPokemon(battleSys, battleCtx->attacker, battleCtx->beatUpCounter);
            if (BeatUpEligibleMon(battleCtx, mon)) {
                break;
            }

            battleCtx->beatUpCounter++;
        }
    }

    mon = BattleSystem_GetPartyPokemon(battleSys, battleCtx->attacker, battleCtx->beatUpCounter);
    species = Pokemon_GetValue(mon, MON_DATA_SPECIES, NULL);
    form = Pokemon_GetValue(mon, MON_DATA_FORM, NULL);
    level = Pokemon_GetValue(mon, MON_DATA_LEVEL, NULL);

    battleCtx->damage = SpeciesData_GetFormValue(species, form, SPECIES_DATA_BASE_ATK);
    battleCtx->damage *= CURRENT_MOVE_DATA.power;
    battleCtx->damage *= (level * 2 / 5) + 2;
    battleCtx->damage /= SpeciesData_GetFormValue(DEFENDING_MON.species, DEFENDING_MON.formNum, SPECIES_DATA_BASE_DEF);
    battleCtx->damage /= 50;
    battleCtx->damage += 2;
    battleCtx->damage *= battleCtx->criticalMul;

    if (battleCtx->turnFlags[battleCtx->attacker].helpingHand) {
        battleCtx->damage = battleCtx->damage * 15 / 10;
    }

    battleCtx->damage = BattleSystem_CalcDamageVariance(battleCtx, battleCtx->damage);
    battleCtx->damage *= -1;

    battleCtx->msgBuffer.id = BattleStrings_Text_PokemonsBeatUpAttack_Ally; // "{0}'s attack!"
    battleCtx->msgBuffer.tags = TAG_NICKNAME;
    battleCtx->msgBuffer.params[0] = (battleCtx->attacker | (battleCtx->beatUpCounter << 8));

    battleCtx->beatUpCounter++;
    battleCtx->multiHitCounter = 2;

    // Check if there are more eligible mons in the back to attack
    if (battleCtx->beatUpCounter < partyCount) {
        while (TRUE) {
            mon = BattleSystem_GetPartyPokemon(battleSys, battleCtx->attacker, battleCtx->beatUpCounter);
            if (BeatUpEligibleMon(battleCtx, mon)) {
                break;
            }

            battleCtx->beatUpCounter++;

            if (battleCtx->beatUpCounter >= partyCount) {
                battleCtx->multiHitCounter = 1;
                break;
            }
        }
    } else {
        battleCtx->multiHitCounter = 1;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D25D4(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u8 *q = b + (u8)BattleSystem_GetBattlerSide((BattleSystem *)a, *(u32 *)(b + 0x64)) * 8;
    ((BF_2700 *)(q + 0x1c4))->sel = 1;
    ((BF_2700 *)(q + 0x1c4))->who = *(u32 *)(b + 0x64);
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryHelpingHand
s32 fn_803D2634(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);
    int battleType = BattleSystem_GetBattleType(battleSys);

    if (battleType & BATTLE_TYPE_DOUBLES) {
        int partner = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, BTLSCR_ATTACKER_PARTNER);
        if ((battleCtx->battlersSwitchingMask & FlagIndex(partner)) == FALSE
            && battleCtx->battlerActions[partner][BATTLE_ACTION_PICK_COMMAND] != BATTLE_CONTROL_MOVE_END
            && battleCtx->battleMons[partner].curHP
            && ATTACKER_TURN_FLAGS.helpingHand == FALSE
            && battleCtx->turnFlags[partner].helpingHand == FALSE) {
            battleCtx->msgBattlerTemp = partner;
            battleCtx->turnFlags[partner].helpingHand = TRUE;
        } else {
            battleCtx->scriptCursor += jumpOnFail;
        }
    } else {
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_TrySwapItems
s32 fn_803D273C(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);
    int jumpStickyHold = fn_803D6E6C((u8 *)battleCtx);

    u32 battleType = BattleSystem_GetBattleType(battleSys);
    int attacking = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker);
    int defending = BattleSystem_GetBattlerSide(battleSys, battleCtx->defender);

    if (BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker) && battleType == BATTLE_TYPE_SINGLES) {
        battleCtx->scriptCursor += jumpOnFail;
    } else if ((battleCtx->sideConditions[attacking].knockedOffItemsMask & FlagIndex(battleCtx->selectedPartySlot[battleCtx->attacker]))
        || (battleCtx->sideConditions[defending].knockedOffItemsMask & FlagIndex(battleCtx->selectedPartySlot[battleCtx->defender]))) {
        battleCtx->scriptCursor += jumpOnFail;
    } else if ((ATTACKING_MON.heldItem == ITEM_NONE && DEFENDING_MON.heldItem == ITEM_NONE)
        || BattleSystem_NotHoldingMail(battleCtx, battleCtx->attacker) == FALSE
        || BattleSystem_NotHoldingMail(battleCtx, battleCtx->defender) == FALSE) {
        battleCtx->scriptCursor += jumpOnFail;
    } else if (Battler_IgnorableAbility(battleCtx, battleCtx->attacker, battleCtx->defender, ABILITY_STICKY_HOLD) == TRUE) {
        battleCtx->scriptCursor += jumpStickyHold;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D28DC(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    u8 *q = b + *(u32 *)(b + 0x64);
    if (q[0x18c]) {
        *(u32 *)(b + 0xb4) += n;
    } else {
        q[0x18c] = 2;
        u8 *r = b + *(u32 *)(b + 0x64);
        r[0x1b8] = r[0x219c];
    }
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D2AB4(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    s32 i;
    s32 c = 0;
    for (i = 0; i < (s32)BattleSystem_GetMaxBattlers((BattleSystem *)a); i++) {
        if (*(u32 *)(b + i * 0xc0 + 0x2d8c)) {
            c++;
        }
    }
    if (*(u32 *)(b + 0xec) == c - 1) {
        *(u32 *)(b + 0xb4) += n;
    } else {
        *(u32 *)(b + *(u32 *)(b + 0x64) * 64 + 0x1d4) |= 0x8000000;
    }
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_MagicCoat
s32 fn_803D2B78(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    int target = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker);
    int attacker = battleCtx->attacker;

    battleCtx->magicCoatMon = attacker;
    battleCtx->attacker = battleCtx->defender;

    if (battleCtx->sideConditions[target].followMe && FOLLOW_ME_MON(target).curHP) {
        battleCtx->defender = FOLLOW_ME_USER(target);
    } else if (CURRENT_MOVE_DATA.range == RANGE_ADJACENT_OPPONENTS || CURRENT_MOVE_DATA.range == RANGE_ALL_ADJACENT) {
        battleCtx->defender = attacker;
    } else {
        target = BattleSystem_Defender(battleSys, battleCtx, battleCtx->attacker, battleCtx->moveCur, TRUE, RANGE_SINGLE_TARGET);
        if (battleCtx->selfTurnFlags[target].lightningRodActivated || battleCtx->selfTurnFlags[target].stormDrainActivated) {
            battleCtx->defender = target;
        } else {
            battleCtx->defender = attacker;
        }
    }

    battleCtx->battleStatusMask2 |= SYSCTL_MAGIC_COAT_REFLECTED;

    return 0;
}
}

#pragma pop

extern "C" {

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CalcRevengePowerMul
s32 fn_803D2C80(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    if ((ATTACKER_TURN_FLAGS.physicalDamageTakenFrom[battleCtx->defender] && (ATTACKER_TURN_FLAGS.physicalDamageAttackerMask & FlagIndex(battleCtx->defender)))
        || (ATTACKER_TURN_FLAGS.specialDamageTakenFrom[battleCtx->defender]) && (ATTACKER_TURN_FLAGS.specialDamageAttackerMask & FlagIndex(battleCtx->defender))) {
        battleCtx->powerMul = 20;
    } else {
        battleCtx->powerMul = 10;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D2D44(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    u32 k = (u8)BattleSystem_GetBattlerSide((BattleSystem *)a, *(u32 *)(b + 0x6c));
    lbl_8048CE28._20 = 0;
    u32 *q = (u32 *)(b + k * 4 + 0x1bc);
    if (*q & 1) {
        lbl_8048CE28._20 |= 1;
    }
    if (*q & 2) {
        lbl_8048CE28._20 |= 2;
    }
    if ((*q & 1) || (*q & 2)) {
        *q &= ~3;
        BF_1C4c *f = (BF_1C4c *)(b + k * 8 + 0x1c4);
        f->x = 0;
        f->y = 0;
    } else {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D2E38(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    u8 *q = b + *(u32 *)(b + 0x6c) * 0xc0;
    if (*(u32 *)(q + 0x2dc0) & 0x1800) {
        *(u32 *)(b + 0xb4) += n;
    } else {
        *(u32 *)(q + 0x2dc0) |= 0x1000;
    }
    return 0;
}

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryKnockOff
s32 fn_803D2EA8(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);
    int defending = BattleSystem_GetBattlerSide(battleSys, battleCtx->defender);

    if (DEFENDING_MON.heldItem && Battler_IgnorableAbility(battleCtx, battleCtx->attacker, battleCtx->defender, ABILITY_STICKY_HOLD) == TRUE) {
        battleCtx->msgBuffer.id = BattleStrings_Text_PokemonsAbilityMadeMoveIneffective_Ally; // "{0}'s {1} made {2} ineffective!"
        battleCtx->msgBuffer.tags = TAG_NICKNAME_ABILITY_MOVE;
        battleCtx->msgBuffer.params[0] = BattleSystem_NicknameTag(battleCtx, battleCtx->defender);
        battleCtx->msgBuffer.params[1] = DEFENDING_MON.ability;
        battleCtx->msgBuffer.params[2] = battleCtx->moveCur;
    } else if (DEFENDING_MON.heldItem) {
        battleCtx->msgBuffer.id = BattleStrings_Text_PokemonKnockedOffPokemonsItem_AllyAlly; // "{0} knocked off {1}'s {2}!"
        battleCtx->msgBuffer.tags = TAG_NICKNAME_NICKNAME_ITEM;
        battleCtx->msgBuffer.params[0] = BattleSystem_NicknameTag(battleCtx, battleCtx->attacker);
        battleCtx->msgBuffer.params[1] = BattleSystem_NicknameTag(battleCtx, battleCtx->defender);
        battleCtx->msgBuffer.params[2] = DEFENDING_MON.heldItem;

        DEFENDING_MON.heldItem = ITEM_NONE;
        battleCtx->sideConditions[defending].knockedOffItemsMask |= FlagIndex(battleCtx->selectedPartySlot[battleCtx->defender]);
    } else {
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

extern "C" {

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CalcHPFalloffPower
s32 fn_803D3018(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    if (battleCtx->movePower == 0) {
        battleCtx->movePower = CURRENT_MOVE_DATA.power * ATTACKING_MON.curHP / ATTACKING_MON.maxHP;

        if (battleCtx->movePower == 0) {
            battleCtx->movePower = 1;
        }
    }

    return 0;
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_TryImprison
s32 fn_803D3074(BattleSystem *battleSys, BattleContext *battleCtx) {
    // must declare C89-style to match
    int jumpOnFail;
    int attackingSide;
    int i, j;
    int battler, maxBattlers;
    int defender1, defender2;

    battleCtx->scriptCursor++;
    jumpOnFail = fn_803D6E6C((u8 *)battleCtx);

    defender1 = BattleSystem_GetEnemyInSlot(battleSys, battleCtx->attacker, ENEMY_IN_SLOT_RIGHT);
    defender2 = BattleSystem_GetEnemyInSlot(battleSys, battleCtx->attacker, ENEMY_IN_SLOT_LEFT);

    battleCtx->battleMons[defender1].moveEffectsMask |= MOVE_EFFECT_IMPRISONED;
    battleCtx->battleMons[defender2].moveEffectsMask |= MOVE_EFFECT_IMPRISONED;

    if (ATTACKING_MON.moveEffectsMask & MOVE_EFFECT_IMPRISON) {
        battleCtx->scriptCursor += jumpOnFail;
    } else {
        attackingSide = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker);
        maxBattlers = BattleSystem_GetMaxBattlers(battleSys);

        // Check that the Imprisoning mon knows at least 1 move that the active defenders know
        for (battler = 0; battler < maxBattlers; battler++) {
            if (attackingSide != BattleSystem_GetBattlerSide(battleSys, battler)) {
                for (i = 0; i < LEARNED_MOVES_MAX; i++) {
                    for (j = 0; j < LEARNED_MOVES_MAX; j++) {
                        if (ATTACKING_MON.moves[i] == battleCtx->battleMons[battler].moves[j]
                            && ATTACKING_MON.moves[i]
                            && battleCtx->battleMons[battler].moves[j]) {
                            break;
                        }
                    }

                    if (j != LEARNED_MOVES_MAX) {
                        break;
                    }
                }

                if (j != LEARNED_MOVES_MAX) {
                    break;
                }
            }
        }

        if (battler == maxBattlers) {
            battleCtx->scriptCursor += jumpOnFail;
        } else {
            ATTACKING_MON.moveEffectsMask |= MOVE_EFFECT_IMPRISON;
        }
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryGrudge
s32 fn_803D3230(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);
    int defending = BattleSystem_GetBattlerSide(battleSys, battleCtx->defender);

    if ((FAINTED_MON.moveEffectsMask & MOVE_EFFECT_GRUDGE)
        && BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker) != BattleSystem_GetBattlerSide(battleSys, battleCtx->faintedMon)
        && ATTACKING_MON.curHP
        && battleCtx->moveTemp != MOVE_STRUGGLE) {
        battleCtx->msgMoveTemp = battleCtx->moveTemp;
        int moveSlot = Battler_SlotForMove(&ATTACKING_MON, battleCtx->msgMoveTemp);
        ATTACKING_MON.ppCur[moveSlot] = 0;

        BattleMon_CopyToParty(battleSys, battleCtx, battleCtx->attacker);
    } else {
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D333C(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    s32 i;
    s32 c = 0;
    for (i = 0; i < (s32)BattleSystem_GetMaxBattlers((BattleSystem *)a); i++) {
        if (*(u32 *)(b + i * 0xc0 + 0x2d8c)) {
            c++;
        }
    }
    if (*(u32 *)(b + 0xec) == c - 1) {
        *(u32 *)(b + 0xb4) += n;
    } else {
        *(u32 *)(b + *(u32 *)(b + 0x64) * 64 + 0x1d4) |= 0x4000000;
    }
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// Power of Low Kick and Grass Knot for a weight (pokeplatinum sWeightToPower lookup)
u16 fn_803D3400(u32 weight) {
    int i = 0;

    for (; lbl_80405A5C[i][0] != 0xFFFF; i++) {
        if (lbl_80405A5C[i][0] >= weight) {
            break;
        }
    }

    if (lbl_80405A5C[i][0] != 0xFFFF) {
        return lbl_80405A5C[i][1];
    }

    return 120;
}
}

extern "C" {

// pokeplatinum BtlCmd_CalcWeightBasedPower
s32 fn_803D3450(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    int i = 0;
    int monWeight = DEFENDING_MON.weight;

    for (; lbl_80405A5C[i][0] != 0xFFFF; i++) {
        if (lbl_80405A5C[i][0] >= monWeight) {
            break;
        }
    }

    if (lbl_80405A5C[i][0] != 0xFFFF) {
        battleCtx->movePower = lbl_80405A5C[i][1];
    } else {
        battleCtx->movePower = 120;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D34C8(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    if (BattleSystem_CountAbility((BattleSystem *)a, (BattleContext *)b, (enum CountAbilityMode)8, 0, 0xd) == 0 &&
        BattleSystem_CountAbility((BattleSystem *)a, (BattleContext *)b, (enum CountAbilityMode)8, 0, 0x4c) == 0) {
        u32 fl = *(u32 *)(b + 0x180);
        if (fl & 0x80ff) {
            *(u32 *)(b + 0x2154) = b[*(u32 *)(b + 0x3044) * 16 + 0x3e1] * 2;
            if (fl & 3) {
                *(u32 *)(b + 0x2160) = 11;
            }
            if (*(u32 *)(b + 0x180) & 0xc) {
                *(u32 *)(b + 0x2160) = 5;
            }
            if (*(u32 *)(b + 0x180) & 0x30) {
                *(u32 *)(b + 0x2160) = 10;
            }
            if (*(u32 *)(b + 0x180) & 0xc0) {
                *(u32 *)(b + 0x2160) = 15;
            }
        } else {
            *(u32 *)(b + 0x2154) = b[*(u32 *)(b + 0x3044) * 16 + 0x3e1];
        }
    }
    return 0;
}

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryPursuit
s32 fn_803D35CC(BattleSystem *battleSys, BattleContext *battleCtx) {
    int jumpIfNoTrigger;
    int i;
    int maxBattlers;
    int move;
    int moveSlot;

    battleCtx->scriptCursor++;

    jumpIfNoTrigger = fn_803D6E6C((u8 *)battleCtx);
    maxBattlers = BattleSystem_GetMaxBattlers(battleSys);

    // Go through all of the battlers while trying to switch and check for any of them using Pursuit.
    // Only consider battlers which would move after us and are not currently asleep, frozen, or Truant.
    for (i = 0; i < maxBattlers; i++) {
        if (battleCtx->battlerActions[i][BATTLE_ACTION_PICK_COMMAND] != BATTLE_CONTROL_MOVE_END
            && battleCtx->battleMons[i].curHP
            && (battleCtx->battleMons[i].status & (MON_CONDITION_SLEEP | MON_CONDITION_FREEZE)) == FALSE
            && Battler_CheckTruant(battleCtx, i) == FALSE
            && BattleSystem_GetBattlerSide(battleSys, i) != BattleSystem_GetBattlerSide(battleSys, battleCtx->switchedMon)) {
            if (battleCtx->battleMons[i].moveEffectsData.encoredMove
                && battleCtx->battleMons[i].moveEffectsData.encoredMove == battleCtx->battleMons[i].moves[battleCtx->battleMons[i].moveEffectsData.encoredMoveSlot]) {
                move = battleCtx->battleMons[i].moveEffectsData.encoredMove;
            } else {
                move = Battler_SelectedMove(battleCtx, i);
            }

            if (move) {
                moveSlot = Battler_SlotForMove(&battleCtx->battleMons[i], move);

                if (MOVE_DATA(move).effect == BATTLE_EFFECT_HIT_BEFORE_SWITCH
                    && battleCtx->battleMons[i].ppCur[moveSlot]) {
                    battleCtx->battleMons[i].ppCur[moveSlot]--;

                    // CompareVarToValue the switching battler has Pressure, apply it to the battler using Pursuit.
                    if (Battler_Ability(battleCtx, battleCtx->switchedMon) == ABILITY_PRESSURE
                        && battleCtx->battleMons[i].ppCur[moveSlot]) {
                        battleCtx->battleMons[i].ppCur[moveSlot]--;
                    }

                    BattleSystem_SetupLoop(battleSys, battleCtx);
                    battleCtx->attacker = i;
                    battleCtx->defender = battleCtx->switchedMon;
                    battleCtx->powerMul = 20;
                    battleCtx->moveCur = move;
                    battleCtx->movePrevByBattler[i] = move;
                    battleCtx->battlerActions[i][BATTLE_ACTION_PICK_COMMAND] = BATTLE_CONTROL_MOVE_END;

                    break;
                }
            }
        }
    }

    if (i == maxBattlers) {
        battleCtx->scriptCursor += jumpIfNoTrigger;
    } else {
        int effect = Battler_HeldItemEffect(battleCtx, battleCtx->attacker);
        int power = Battler_HeldItemPower(battleCtx, battleCtx->attacker, (enum HeldItemPowerOp)0);

        if (effect == HOLD_EFFECT_CHOICE_ATK
            || effect == HOLD_EFFECT_CHOICE_SPEED
            || effect == HOLD_EFFECT_CHOICE_SPATK) {
            ATTACKING_MON.moveEffectsData.choiceLockedMove = move;
        }
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D37FC(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    *(u32 *)(b + 0x2144) = BattleSystem_ApplyTypeChart((BattleSystem *)a,
                                                       (BattleContext *)b,
                                                       *(u32 *)(b + 0x3044),
                                                       *(u32 *)(b + 0x2160),
                                                       *(u32 *)(b + 0x64),
                                                       *(u32 *)(b + 0x6c),
                                                       *(u32 *)(b + 0x2144),
                                                       (u32 *)(b + 0x216c));
    return 0;
}

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_IfTurnFlag
s32 fn_803D3854(BattleSystem *battleSys, BattleContext *battleCtx) {
    BOOL result = FALSE;

    battleCtx->scriptCursor++;
    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int flagID = fn_803D6E6C((u8 *)battleCtx);
    int compareTo = fn_803D6E6C((u8 *)battleCtx);
    int jumpIfTrue = fn_803D6E6C((u8 *)battleCtx);

    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);

    switch (flagID) {
    case TURN_FLAG_STRUGGLING:
        if (battleCtx->turnFlags[battler].struggling == compareTo) {
            result = TRUE;
        }
        break;

    case TURN_FLAG_PP_DECREMENTED:
        if (battleCtx->turnFlags[battler].ppDecremented == compareTo) {
            result = TRUE;
        }
        break;

    case TURN_FLAG_PROTECTING:
        if (battleCtx->turnFlags[battler].protecting == compareTo) {
            result = TRUE;
        }
        break;

    case TURN_FLAG_HELPING_HAND:
        if (battleCtx->turnFlags[battler].helpingHand == compareTo) {
            result = TRUE;
        }
        break;

    case TURN_FLAG_MAGIC_COAT:
        if (battleCtx->turnFlags[battler].magicCoat == compareTo) {
            result = TRUE;
        }
        break;

    case TURN_FLAG_SNATCHING:
        if (battleCtx->turnFlags[battler].snatching == compareTo) {
            result = TRUE;
        }
        break;

    case TURN_FLAG_ROOSTING:
        if (battleCtx->turnFlags[battler].roosting == compareTo) {
            result = TRUE;
        }
        break;
    }

    if (result) {
        battleCtx->scriptCursor += jumpIfTrue;
    }

    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_SetTurnFlag
s32 fn_803D39EC(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int flagID = fn_803D6E6C((u8 *)battleCtx);
    int val = fn_803D6E6C((u8 *)battleCtx);

    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);

    switch (flagID) {
    case TURN_FLAG_STRUGGLING:
        battleCtx->turnFlags[battler].struggling = val;
        break;

    case TURN_FLAG_PP_DECREMENTED:
        battleCtx->turnFlags[battler].ppDecremented = val;
        break;

    case TURN_FLAG_PROTECTING:
        battleCtx->turnFlags[battler].protecting = val;
        break;

    case TURN_FLAG_HELPING_HAND:
        battleCtx->turnFlags[battler].helpingHand = val;
        break;

    case TURN_FLAG_MAGIC_COAT:
        battleCtx->turnFlags[battler].magicCoat = val;
        break;

    case TURN_FLAG_SNATCHING:
        battleCtx->turnFlags[battler].snatching = val;
        break;

    case TURN_FLAG_ROOSTING:
        battleCtx->turnFlags[battler].roosting = val;
        break;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D3B28(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    *(s32 *)(b + 0x2154) =
        *(u32 *)(b + *(u32 *)(b + 0x6c) * 4 + 0x21f0) * 25 / *(u32 *)(b + *(u32 *)(b + 0x64) * 4 + 0x21f0) + 1;
    if (*(s32 *)(b + 0x2154) > 150) {
        *(s32 *)(b + 0x2154) = 150;
    }
    return 0;
}

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryMetalBurst
s32 fn_803D3B7C(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);
    int attacking = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker);
    int defending = BattleSystem_GetBattlerSide(battleSys, ATTACKER_TURN_FLAGS.lastAttacker);

    if (ATTACKER_TURN_FLAGS.lastDamageTaken
        && attacking != defending
        && battleCtx->battleMons[ATTACKER_TURN_FLAGS.lastAttacker].curHP) {
        battleCtx->damage = ATTACKER_TURN_FLAGS.lastDamageTaken * 15 / 10;

        if (battleCtx->sideConditions[defending].followMe && FOLLOW_ME_MON(defending).curHP) {
            battleCtx->defender = FOLLOW_ME_USER(defending);
        } else {
            battleCtx->defender = ATTACKER_TURN_FLAGS.lastAttacker;
        }

        if (DEFENDING_MON.curHP == 0) {
            battleCtx->defender = BattleSystem_RandomOpponent(battleSys, battleCtx, battleCtx->attacker);

            if (DEFENDING_MON.curHP == 0) {
                battleCtx->commandNext = BATTLE_CONTROL_UPDATE_MOVE_BUFFERS;
                BattleSystem_LoadScript(battleCtx, NARC_BATTLE_SUB_SEQ, BATTLE_SUBSCRIPT_NO_TARGET);
            }
        }

        BattleSystem_DecPPForPressure(battleCtx, battleCtx->attacker, battleCtx->defender);
    } else {
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D3D00(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    if (*(u32 *)(b + *(u32 *)(b + 0x6c) * 16 + 0x21a8) == 0x27) {
        *(u32 *)(b + 0x2154) = b[*(u32 *)(b + 0x3044) * 16 + 0x3e1] * 2;
    } else {
        *(u32 *)(b + 0x2154) = b[*(u32 *)(b + 0x3044) * 16 + 0x3e1];
    }
    return 0;
}

s32 fn_803D3D5C(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 k = *(u32 *)(b + 0x64);
    u8 v = b[k * 0xc0 + *(u16 *)(b + k * 2 + 0x30bc) + 0x2d6c];
    if (v > 4) {
        v = 4;
    }
    *(u32 *)(b + 0x2154) = lbl_80643000[v];
    return 0;
}


}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CalcWringOutPower
s32 fn_803D3DA8(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;

    battleCtx->movePower = 1 + (120 * DEFENDING_MON.curHP) / DEFENDING_MON.maxHP;

    return 0;
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_TryMeFirst
s32 fn_803D3DE0(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);

    u16 move;
    if (DEFENDING_MON.moveEffectsData.encoredMove
        && DEFENDING_MON.moveEffectsData.encoredMove == DEFENDING_MON.moves[DEFENDING_MON.moveEffectsData.encoredMoveSlot]) {
        move = DEFENDING_MON.moveEffectsData.encoredMove;
    } else {
        move = Battler_SelectedMove(battleCtx, battleCtx->defender);
    }

    if (DEFENDER_ACTION[BATTLE_ACTION_PICK_COMMAND] != BATTLE_CONTROL_MOVE_END
        && DEFENDER_TURN_FLAGS.struggling == FALSE
        && Move_MeFirstCanCopy(battleCtx, move) == TRUE
        && MOVE_DATA(move).power) {
        ATTACKING_MON.moveEffectsData.meFirst = TRUE;
        ATTACKING_MON.moveEffectsData.meFirstTurnNumber = battleCtx->meFirstTurnOrder;
        battleCtx->msgMoveTemp = move;
    } else {
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D3F04(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    if (Move_IsInvoker((u16) * (u32 *)(b + 0x3048)) == 0 && *(u32 *)(b + 0x3048) != 0 &&
        Move_CanBeMetronomed((u16) * (u32 *)(b + 0x3048)) == 1) {
        *(u32 *)(b + 0x124) = *(u32 *)(b + 0x3048);
    } else {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D3F98(u8 *a, u8 *b) {
    s32 i;
    s32 s = 0;
    (*(u32 *)(b + 0xb4))++;
    u8 *q = b + *(u32 *)(b + 0x6c) * 0xc0;
    for (i = 0; i < 8; i++) {
        s8 v = q[i + 0x2d58];
        if (v > 6) {
            s = s + v - 6;
        }
    }
    *(s32 *)(b + 0x2154) = s * 20 + 60;
    if (*(s32 *)(b + 0x2154) > 200) {
        *(s32 *)(b + 0x2154) = 200;
    }
    return 0;
}
}

#pragma pop

extern "C" {


}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TrySuckerPunch
s32 fn_803D4008(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);

    int move;
    if (DEFENDING_MON.moveEffectsData.encoredMove
        && DEFENDING_MON.moveEffectsData.encoredMove == DEFENDING_MON.moves[DEFENDING_MON.moveEffectsData.encoredMoveSlot]) {
        move = DEFENDING_MON.moveEffectsData.encoredMove;
    } else {
        move = Battler_SelectedMove(battleCtx, battleCtx->defender);
    }

    if (DEFENDER_ACTION[BATTLE_ACTION_PICK_COMMAND] == BATTLE_CONTROL_MOVE_END
        || (MOVE_DATA(move).power == 0 && DEFENDER_TURN_FLAGS.struggling == FALSE)) {
        battleCtx->scriptCursor += jumpOnFail;
    }

    return 0;
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_CheckSideCondition
s32 fn_803D40E0(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int op = fn_803D6E6C((u8 *)battleCtx);
    int sidecond = fn_803D6E6C((u8 *)battleCtx);
    int jump = fn_803D6E6C((u8 *)battleCtx);

    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);
    int side = BattleSystem_GetBattlerSide(battleSys, battler);
    int val;

    switch (op) {
    case CHECK_SIDE_COND_VAL_ZERO:
    case CHECK_SIDE_COND_VAL_NOT_ZERO:
        switch (sidecond) {
        case SIDE_COND_REFLECT_TURNS:
            val = battleCtx->sideConditions[side].reflectTurns;
            break;

        case SIDE_COND_LIGHT_SCREEN_TURNS:
            val = battleCtx->sideConditions[side].lightScreenTurns;
            break;

        case SIDE_COND_MIST_TURNS:
            val = battleCtx->sideConditions[side].mistTurns;
            break;

        case SIDE_COND_SAFEGUARD_TURNS:
            val = battleCtx->sideConditions[side].safeguardTurns;
            break;

        case SIDE_COND_SPIKES_LAYERS:
            val = battleCtx->sideConditions[side].spikesLayers;
            break;

        case SIDE_COND_TOXIC_SPIKES_LAYERS:
            val = battleCtx->sideConditions[side].toxicSpikesLayers;
            break;
        }
        break;

    case CHECK_SIDE_COND_CLEAR:
        switch (sidecond) {
        case SIDE_COND_REFLECT_TURNS:
            battleCtx->sideConditions[side].reflectTurns = 0;
            battleCtx->sideConditionsMask[side] &= ~SIDE_CONDITION_REFLECT;
            break;

        case SIDE_COND_LIGHT_SCREEN_TURNS:
            battleCtx->sideConditions[side].lightScreenTurns = 0;
            battleCtx->sideConditionsMask[side] &= ~SIDE_CONDITION_LIGHT_SCREEN;
            break;

        case SIDE_COND_MIST_TURNS:
            battleCtx->sideConditions[side].mistTurns = 0;
            battleCtx->sideConditionsMask[side] &= ~SIDE_CONDITION_MIST;
            break;

        case SIDE_COND_SAFEGUARD_TURNS:
            battleCtx->sideConditions[side].safeguardTurns = 0;
            battleCtx->sideConditionsMask[side] &= ~SIDE_CONDITION_SAFEGUARD;
            break;

        case SIDE_COND_SPIKES_LAYERS:
            battleCtx->sideConditions[side].spikesLayers = 0;
            battleCtx->sideConditionsMask[side] &= ~SIDE_CONDITION_SPIKES;
            break;

        case SIDE_COND_TOXIC_SPIKES_LAYERS:
            battleCtx->sideConditions[side].toxicSpikesLayers = 0;
            battleCtx->sideConditionsMask[side] &= ~SIDE_CONDITION_TOXIC_SPIKES;
            break;
        }
        break;
    }

    if (op == CHECK_SIDE_COND_VAL_ZERO && val == 0) {
        battleCtx->scriptCursor += jump;
    }

    if (op == CHECK_SIDE_COND_VAL_NOT_ZERO && val) {
        battleCtx->scriptCursor += jump;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D43A8(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    if (((*(u32 *)(b + *(u32 *)(b + 0x6c) * 64 + 0x1d4) >> 29) & 1) == 0) {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}

s32 fn_803D440C(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    u8 *q = b + *(u32 *)(b + 0x6c) * 0xc0;
    if (*(u32 *)(q + 0x2dac) != 0 || (*(u32 *)(q + 0x2db0) & 0x1000000) ||
        *(u32 *)(b + *(u32 *)(b + 0x64) * 0xc0 + 0x2dac) == 0) {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D4494(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    s32 k = Battler_CountMoves((BattleSystem *)a, (BattleContext *)b, *(u32 *)(b + 0x64));
    if (((*(u32 *)(b + *(u32 *)(b + 0x64) * 0xc0 + 0x2dcc) >> 19) & 7) < (u32)(k - 1) || k < 2) {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}


}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_TryToxicSpikes
s32 fn_803D4528(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int jumpOnFail = fn_803D6E6C((u8 *)battleCtx);
    int defending = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker) ^ 1;

    if (battleCtx->sideConditions[defending].toxicSpikesLayers == 2) {
        ATTACKER_SELF_TURN_FLAGS.skipPressureCheck = TRUE;
        battleCtx->scriptCursor += jumpOnFail;
    } else {
        battleCtx->sideConditionsMask[defending] |= SIDE_CONDITION_TOXIC_SPIKES;
        battleCtx->sideConditions[defending].toxicSpikesLayers++;
    }

    return 0;
}
}

#pragma pop

extern "C" {


}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CheckToxicSpikes
s32 fn_803D45F4(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int jumpIfNoToxicSpikes = fn_803D6E6C((u8 *)battleCtx);

    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);
    int side = BattleSystem_GetBattlerSide(battleSys, battler);

    if (battleCtx->sideConditions[side].toxicSpikesLayers) {
        battleCtx->calcTemp = battleCtx->sideConditions[side].toxicSpikesLayers;
        battleCtx->sideEffectType = SIDE_EFFECT_TYPE_TOXIC_SPIKES;
        battleCtx->sideEffectMon = battler;

        if (MON_HAS_TYPE(battleCtx->switchedMon, TYPE_POISON)) {
            battleCtx->sideConditionsMask[side] &= ~SIDE_CONDITION_TOXIC_SPIKES;
            battleCtx->sideConditions[side].toxicSpikesLayers = 0;
            battleCtx->calcTemp = 0;
        }
    } else {
        battleCtx->scriptCursor += jumpIfNoToxicSpikes;
    }

    return 0;
}
}

#pragma pop

extern "C" {

// pokeplatinum BtlCmd_CheckIgnorableAbility
s32 fn_803D4708(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int op = fn_803D6E6C((u8 *)battleCtx);
    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int ability = fn_803D6E6C((u8 *)battleCtx);
    int jump = fn_803D6E6C((u8 *)battleCtx);

    int battler;
    if (inBattler == BTLSCR_ALL_BATTLERS) {
        int maxBattlers = BattleSystem_GetMaxBattlers(battleSys);

        for (int i = 0; i < maxBattlers; i++) {
            battler = battleCtx->monSpeedOrder[i];

            if (op == CHECK_HAVE) {
                if (Battler_IgnorableAbility(battleCtx, battleCtx->attacker, battler, ability) == TRUE
                    && battleCtx->battleMons[battler].curHP) {
                    battleCtx->scriptCursor += jump;
                    battleCtx->abilityMon = battler;
                    lbl_8048CE28._18 = battler;
                    break;
                }
            } else if (Battler_IgnorableAbility(battleCtx, battleCtx->attacker, battler, ability) == FALSE
                || battleCtx->battleMons[battler].curHP == 0) {
                battleCtx->scriptCursor += jump;
                battleCtx->abilityMon = battler;
                break;
            }
        }
    } else {
        battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);

        if (op == CHECK_HAVE) {
            if (Battler_IgnorableAbility(battleCtx, battleCtx->attacker, battler, ability) == TRUE
                && battleCtx->battleMons[battler].curHP) {
                battleCtx->scriptCursor += jump;
                battleCtx->abilityMon = battler;
                lbl_8048CE28._18 = battler;
            }
        } else if (Battler_IgnorableAbility(battleCtx, battleCtx->attacker, battler, ability) == FALSE
            || battleCtx->battleMons[battler].curHP == 0) {
            battleCtx->scriptCursor += jump;
            battleCtx->abilityMon = battler;
        }
    }

    return 0;
}
}

#pragma pop

extern "C" {

}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_IfSameSide
s32 fn_803D48F8(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int inBattler1 = fn_803D6E6C((u8 *)battleCtx);
    int inBattler2 = fn_803D6E6C((u8 *)battleCtx);
    int jumpIfSameSide = fn_803D6E6C((u8 *)battleCtx);

    int battler1 = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler1);
    int battler2 = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler2);

    if (BattleSystem_GetBattlerSide(battleSys, battler1) == BattleSystem_GetBattlerSide(battleSys, battler2)) {
        battleCtx->scriptCursor += jumpIfSameSide;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D4C24(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    *(u32 *)(b + *(u32 *)(b + 0x64) * 0x1c + 0x2d4) |= 0x08000000;
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D4C50(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    if (Battler_MovedThisTurn((BattleContext *)b, fn_803D803C(a, b, x)) == 1) {
        *(u32 *)(b + 0xb4) += y;
    }
    return 0;
}

s32 fn_803D4CDC(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    s32 w = fn_803D6E6C(b);
    u32 x = fn_803D6E6C(b);
    s32 y = fn_803D6E6C(b);
    u32 z = fn_803D6E6C(b);
    u32 r = fn_803D803C(a, b, x);
    if (w == 0) {
        if (y == (s32)Battler_HeldItemEffect((BattleContext *)b, r)) {
            *(u32 *)(b + 0xb4) += z;
        }
    } else {
        if (y != (s32)Battler_HeldItemEffect((BattleContext *)b, r)) {
            *(u32 *)(b + 0xb4) += z;
        }
    }
    return 0;
}

s32 fn_803D4DA8(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    u32 *r = fn_803D6E8C(a, b, y);
    *r = BattleSystem_GetItemData((BattleContext *)b,
                                  Battler_HeldItem((BattleContext *)b, fn_803D803C(a, b, x)),
                                  (enum ItemDataParam)1);
    return 0;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_GetItemEffectParam
s32 fn_803D4E48(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int dstVar = fn_803D6E6C((u8 *)battleCtx);

    int *var = (int *)fn_803D6E8C((u8 *)battleSys, (u8 *)battleCtx, dstVar);
    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);
    u16 item = Battler_HeldItem(battleCtx, battler);

    *var = BattleSystem_GetItemData(battleCtx, item, ITEM_PARAM_EFFECT_PARAM);

    return 0;
}
}

#pragma pop

extern "C" {

u8 fn_803D4EE8(u32 i) {
    if (i > 12) {
        return 0;
    }
    return lbl_80405AC1[i];
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D4F08(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    if ((u8)Battler_Ability((BattleContext *)b, *(u32 *)(b + 0x64)) == 0x79) {
        *(u32 *)(b + 0xb4) += n;
        return 0;
    }
    s32 t = lbl_80405AC1[BattleSystem_GetTerrain((BattleSystem *)a)];
    if (t != BattleMon_Get((BattleContext *)b, *(u32 *)(b + 0x64), (enum BattleMonParam)0x1b, (void *)0) &&
        t != BattleMon_Get((BattleContext *)b, *(u32 *)(b + 0x64), (enum BattleMonParam)0x1c, (void *)0)) {
        b[*(u32 *)(b + 0x64) * 0xc0 + 0x2d64] = t;
        b[*(u32 *)(b + 0x64) * 0xc0 + 0x2d65] = t;
        *(s32 *)(b + 0x130) = t;
    } else {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}
}

#pragma pop

extern "C" {

u16 fn_803D5004(u32 i) {
    if (i > 12) {
        return 0;
    }
    return lbl_80405ACE[(u8)i];
}

s32 fn_803D5028(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    *(u32 *)(b + 0x124) = lbl_80405ACE[BattleSystem_GetTerrain((BattleSystem *)a)];
    return 0;
}

s32 fn_803D5078(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    *(u32 *)(b + 0x2174) = lbl_80405AE8[BattleSystem_GetTerrain((BattleSystem *)a)];
    return 0;
}

s32 fn_803D50C8(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    u32 r = Battler_NaturalGiftPower((BattleContext *)b, *(u32 *)(b + 0x64));
    if (r) {
        *(u32 *)(b + 0x2154) = r;
        *(u32 *)(b + 0x2160) = Battler_NaturalGiftType((BattleContext *)b, *(u32 *)(b + 0x64));
    } else {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D514C(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    if (*(u16 *)(b + *(u32 *)(b + 0x6c) * 0xc0 + 0x2db8) != 0 &&
        Battler_IgnorableAbility((BattleContext *)b, *(u32 *)(b + 0x64), *(u32 *)(b + 0x6c), 0x3c) == 1) {
        *(u32 *)(b + 0xb4) += x;
    } else if (BattleSystem_PluckBerry((BattleSystem *)a, (BattleContext *)b, *(u32 *)(b + 0x6c)) != 1) {
        *(u32 *)(b + 0xb4) += y;
    }
    return 0;
}

s32 fn_803D520C(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    if (BattleSystem_FlingItem((BattleSystem *)a, (BattleContext *)b, *(u32 *)(b + 0x64)) != 1) {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D5280(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitShowYesNoMenu((BattleSystem *)a, (BattleContext *)b, 0, 0, fn_803D6E6C(b), 0, 0);
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D52EC(u8 *a, u8 *b) {
    u8 v = BattleContext_IOBufferVal((BattleContext *)b, 0);
    if (v) {
        (*(u32 *)(b + 0xb4))++;
        u32 x = fn_803D6E6C(b);
        u32 y = fn_803D6E6C(b);
        if (v == 0xff) {
            *(u32 *)(b + 0xb4) += y;
        } else {
            *(u32 *)(b + 0xb4) += x;
        }
    }
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D5380(u8 *a, u8 *b) {
    BattleSystem_GetMaxBattlers((BattleSystem *)a);
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitShowPartyMenu((BattleSystem *)a, (BattleContext *)b, 0, 0, 0, 6);
    *(u32 *)(b + 0x78) = 0;
    return 0;
}

s32 fn_803D53EC(u8 *a, u8 *b) {
    u8 v = BattleContext_IOBufferVal((BattleContext *)b, 0);
    if (v) {
        (*(u32 *)(b + 0xb4))++;
        u32 n = fn_803D6E6C(b);
        if (v == 0xff) {
            *(u32 *)(b + 0xb4) += n;
        } else {
            b[0x21a0] = v - 1;
        }
    }
    return 0;
}

s32 fn_803D5470(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    if (BattleSystem_GetBattleType((BattleSystem *)a) & 4) {
        BattleController_EmitSubmitResult((BattleSystem *)a);
    }
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CheckStealthRock
s32 fn_803D54BC(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int inBattler = fn_803D6E6C((u8 *)battleCtx);
    int jumpNoEffect = fn_803D6E6C((u8 *)battleCtx);

    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);
    int side = BattleSystem_GetBattlerSide(battleSys, battler);
    int type1 = BattleMon_Get(battleCtx, battler, BATTLEMON_TYPE_1, NULL);
    int type2 = BattleMon_Get(battleCtx, battler, BATTLEMON_TYPE_2, NULL);

    if ((battleCtx->sideConditionsMask[side] & SIDE_CONDITION_STEALTH_ROCK)
        && battleCtx->battleMons[battler].curHP) {
        switch (BattleSystem_TypeMatchupMultiplier(TYPE_ROCK, type1, type2)) {
        case TYPE_MULTI_QUADRUPLE_DAMAGE:
            battleCtx->hpCalcTemp = 2;
            break;

        case TYPE_MULTI_DOUBLE_DAMAGE:
            battleCtx->hpCalcTemp = 4;
            break;

        case TYPE_MULTI_BASE_DAMAGE:
            battleCtx->hpCalcTemp = 8;
            break;

        case TYPE_MULTI_HALF_DAMAGE:
            battleCtx->hpCalcTemp = 16;
            break;

        case TYPE_MULTI_QUARTER_DAMAGE:
            battleCtx->hpCalcTemp = 32;
            break;

        case TYPE_MULTI_IMMUNE:
            battleCtx->scriptCursor += jumpNoEffect;
            return 0;

        default:
            fn_803D989C(FALSE, BTLSCR_ERR_INVALID);
            break;
        }

        battleCtx->hpCalcTemp = BattleSystem_Divide(battleCtx->battleMons[battler].maxHP * -1, battleCtx->hpCalcTemp);
    } else {
        battleCtx->scriptCursor += jumpNoEffect;
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D5660(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    u16 v;
    if ((u8)Battler_Ability((BattleContext *)b, *(u32 *)(b + 0x64)) == 0x20) {
        v = b[*(u32 *)(b + 0x3044) * 16 + 0x3e5] * 2;
    } else {
        v = b[*(u32 *)(b + 0x3044) * 16 + 0x3e5];
    }
    if ((s32)LCRNG_Next() % 100 < v && *(u32 *)(b + *(u32 *)(b + 0x94) * 0xc0 + 0x2d8c) != 0) {
        return 0;
    }
    *(u32 *)(b + 0xb4) += n;
    return 0;
}

s32 fn_803D5738(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    u8 *q = b + *(u32 *)(b + 0x64) * 0xc0;
    if (*(u16 *)(q + 0x2d40) == 0x1b9 && *(u32 *)(b + *(u32 *)(b + 0x6c) * 0xc0 + 0x2d8c) &&
        !(*(u32 *)(q + 0x2db0) & 0x200000)) {
        s32 p;
        switch (fn_803DA018((const TrainerInfo *)(BattleSystem_GetChatotCry((BattleSystem *)a, *(u32 *)(b + 0x64))))) {
            case 0:
            default: p = 0; break;
            case 1:  p = 10; break;
            case 2:  p = 30; break;
        }
        if ((s32)LCRNG_Next() % 100 > p) {
            *(u32 *)(b + 0xb4) += n;
        }
    } else {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D583C(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 v = fn_803D6E6C(b);
    *(u32 *)(b + 0x134) = MoveTable_Get((MoveTable *)(b + *(u32 *)(b + 0x3044) * 16 + 0x3de), v);
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D5898(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    u32 z = fn_803D6E6C(b);
    BattleController_EmitSetMosaic((BattleSystem *)a, fn_803D803C(a, b, x), y, z);
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D5924(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 r = fn_803D803C(a, b, fn_803D6E6C(b));
    BattleController_EmitChangeWeatherForm((BattleSystem *)a, r);
    *(u32 *)&lbl_8048CDE8 = r;
    *(u32 *)((u8 *)&lbl_8048CDE8 + 4) = ((*(u8 **)(a + 0x30))[r * 0xc0 + 0x2d66] >> 3) & 0x1f;
    fn_8016FA4C(0x16, &lbl_8048CDE8);
    return 0;
}

s32 fn_803D59BC(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitUpdateBG((BattleSystem *)a, 0);
    return 0;
}

s32 fn_803D59F0(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 r = fn_803D803C(a, b, fn_803D6E6C(b));
    BattleSystem_UseBagItem((BattleSystem *)a, r, b[r + 0x219c], 0, *(u32 *)(b + 0x128));
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D5A68(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    if (Battler_CanEscape((BattleSystem *)a, (BattleContext *)b, fn_803D803C(a, b, x))) {
        *(u32 *)(b + 0xb4) += y;
    }
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D5AF8(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitShowBattleStartPartyGauge((BattleSystem *)a, fn_803D803C(a, b, fn_803D6E6C(b)));
    return 0;
}

s32 fn_803D5B60(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitHideBattleStartPartyGauge((BattleSystem *)a, fn_803D803C(a, b, fn_803D6E6C(b)));
    return 0;
}

s32 fn_803D5BC8(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitShowPartyGauge((BattleSystem *)a, fn_803D803C(a, b, fn_803D6E6C(b)));
    return 0;
}

s32 fn_803D5C30(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitHidePartyGauge((BattleSystem *)a, fn_803D803C(a, b, fn_803D6E6C(b)));
    return 0;
}

s32 fn_803D5C98(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitLoadPartyGaugeGraphics((BattleSystem *)a);
    return 0;
}

s32 fn_803D5CC8(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitFreePartyGaugeGraphics((BattleSystem *)a);
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D5CF8(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    u32 z = fn_803D6E6C(b);
    BattleController_EmitIncrementRecord((BattleSystem *)a, fn_803D803C(a, b, x), y, z);
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D5D84(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitRestoreSprite((BattleSystem *)a, (BattleContext *)b, fn_803D803C(a, b, fn_803D6E6C(b)));
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D5DF0(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    if (BattleSystem_TriggerAbilityOnHit((BattleSystem *)a, (BattleContext *)b, (int *)(b + 0x138)) == 0) {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}

s32 fn_803D5E64(u8 *a, u8 *b) {
    s32 n = BattleSystem_GetMaxBattlers((BattleSystem *)a);
    (*(u32 *)(b + 0xb4))++;
    s32 c = fn_803D6E6C(b);
    s32 i;
    switch (c) {
        case 3:
            for (i = 0; i < n; i++) {
                if (!(((u8 *)BattleSystem_GetBattlerData((BattleSystem *)a, i))[0x185] & 1)) {
                    BattleController_EmitSpriteToOAM((BattleSystem *)a, i);
                }
            }
            break;
        case 4:
            for (i = 0; i < n; i++) {
                if (((u8 *)BattleSystem_GetBattlerData((BattleSystem *)a, i))[0x185] & 1) {
                    BattleController_EmitSpriteToOAM((BattleSystem *)a, i);
                }
            }
            break;
        default: BattleController_EmitSpriteToOAM((BattleSystem *)a, fn_803D803C(a, b, c)); break;
    }
    return 0;
}

s32 fn_803D5F64(u8 *a, u8 *b) {
    s32 n = BattleSystem_GetMaxBattlers((BattleSystem *)a);
    (*(u32 *)(b + 0xb4))++;
    s32 c = fn_803D6E6C(b);
    s32 i;
    switch (c) {
        case 3:
            for (i = 0; i < n; i++) {
                if (!(((u8 *)BattleSystem_GetBattlerData((BattleSystem *)a, i))[0x185] & 1)) {
                    BattleController_EmitOAMToSprite((BattleSystem *)a, i);
                }
            }
            break;
        case 4:
            for (i = 0; i < n; i++) {
                if (((u8 *)BattleSystem_GetBattlerData((BattleSystem *)a, i))[0x185] & 1) {
                    BattleController_EmitOAMToSprite((BattleSystem *)a, i);
                }
            }
            break;
        default: BattleController_EmitOAMToSprite((BattleSystem *)a, fn_803D803C(a, b, c)); break;
    }
    return 0;
}

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_CheckBlackOut
s32 fn_803D6064(BattleSystem *battleSys, BattleContext *battleCtx) {
    int inBattler;
    int jumpIfWhiteOut;
    int battler;
    int i;
    int aliveMons = 0;
    u32 battleType;
    Pokemon *mon;
    BattlerData *battlerData;

    battleCtx->scriptCursor++;

    inBattler = fn_803D6E6C((u8 *)battleCtx);
    jumpIfWhiteOut = fn_803D6E6C((u8 *)battleCtx);
    battleType = BattleSystem_GetBattleType(battleSys);
    battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);

    if ((battleType & BATTLE_TYPE_2vs2)
        || ((battleType & BATTLE_TYPE_TAG) && BattleSystem_GetBattlerSide(battleSys, battler))) {
        Party *party1 = BattleSystem_GetParty(battleSys, battler);
        Party *party2 = BattleSystem_GetParty(battleSys, BattleSystem_GetPartner(battleSys, battler));
        battlerData = BattleSystem_GetBattlerData(battleSys, battler);

        for (i = 0; i < Party_GetCurrentCount(party1); i++) {
            mon = Party_GetPokemonBySlotIndex(party1, i);

            if (Pokemon_GetValue(mon, MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_NONE
                && Pokemon_GetValue(mon, MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_EGG) {
                aliveMons += Pokemon_GetValue(mon, MON_DATA_HP, NULL);
            }
        }

        // Don't consider the second slot if we have a partner
        if (!((battleType & 0x7F) == BATTLE_TYPE_TRAINER_WITH_AI_PARTNER || (battleType & 0x7F) == BATTLE_TYPE_AI_PARTNER)
            || BattleSystem_GetBattlerSide(battleSys, battler) != BATTLER_US) {
            for (i = 0; i < Party_GetCurrentCount(party2); i++) {
                mon = Party_GetPokemonBySlotIndex(party2, i);

                if (Pokemon_GetValue(mon, MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_NONE
                    && Pokemon_GetValue(mon, MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_EGG) {
                    aliveMons += Pokemon_GetValue(mon, MON_DATA_HP, NULL);
                }
            }
        }

        if (aliveMons == 0) {
            battleCtx->scriptCursor += jumpIfWhiteOut;
        }
    } else {
        Party *party = BattleSystem_GetParty(battleSys, battler);
        battlerData = BattleSystem_GetBattlerData(battleSys, battler);

        for (i = 0; i < Party_GetCurrentCount(party); i++) {
            mon = Party_GetPokemonBySlotIndex(party, i);

            if (Pokemon_GetValue(mon, MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_NONE
                && Pokemon_GetValue(mon, MON_DATA_SPECIES_OR_EGG, NULL) != SPECIES_EGG) {
                aliveMons += Pokemon_GetValue(mon, MON_DATA_HP, NULL);
            }
        }

        if (aliveMons == 0) {
            battleCtx->scriptCursor += jumpIfWhiteOut;
        }
    }

    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D62F0(u8 *a, u8 *b) {
    s32 buf[7];
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    s32 cnt = 0;
    u8 *q = b + *(u32 *)(b + 0x6c) * 0xc0;
    for (s32 i = 1; i < 8; i++) {
        if ((s8)q[i + 0x2d58] < 12) {
            buf[cnt] = i - 1;
            cnt++;
        }
    }
    if (cnt) {
        *(u32 *)(b + 0x2170) = (buf[(s32)LCRNG_Next() % cnt] + 0x27) | 0x80000000;
    } else {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D63CC(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 r = fn_803D803C(a, b, fn_803D6E6C(b));
    *(u16 *)(b + r * 2 + 0x3124) = *(u16 *)(b + r * 0xc0 + 0x2db8);
    *(u16 *)(b + r * 0xc0 + 0x2db8) = 0;
    BattleMon_CopyToParty((BattleSystem *)a, (BattleContext *)b, r);
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D6458(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    u16 *q = (u16 *)(b + *(u32 *)(b + 0x64) * 2 + 0x3124);
    if (*q) {
        *(u32 *)(b + 0x128) = *q;
        *q = 0;
    } else {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}

s32 fn_803D64CC(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    if (BattleSystem_TriggerHeldItemOnHit((BattleSystem *)a, (BattleContext *)b, (int *)(b + 0x138)) == 0) {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D6540(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitResultMessage((BattleSystem *)a);
    return 0;
}

s32 fn_803D6570(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitEscapeMessage((BattleSystem *)a, (BattleContext *)b);
    return 0;
}

s32 fn_803D65A0(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitForfeitMessage((BattleSystem *)a);
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D65D0(u8 *a, u8 *b) {
    u32 r;
    s32 hit = 0;
    (*(u32 *)(b + 0xb4))++;
    r = fn_803D803C(a, b, fn_803D6E6C(b));
    s32 ab = Battler_HeldItemEffect((BattleContext *)b, r);
    s32 v = Battler_HeldItemPower((BattleContext *)b, r, (enum HeldItemPowerOp)0);
    if (ab == 0x40 && (s32)LCRNG_Next() % 100 < v) {
        hit = 1;
    }
    if (ab == 0x66 && *(u32 *)(b + r * 0xc0 + 0x2d8c) == *(u32 *)(b + r * 0xc0 + 0x2d90)) {
        hit = 1;
    }
    if (hit) {
        s32 hp = *(s32 *)(b + r * 0xc0 + 0x2d8c);
        if (*(s32 *)(b + 0x215c) + hp <= 0) {
            *(s32 *)(b + 0x215c) = -(hp - 1);
            *(u32 *)(b + 0x216c) |= 0x100;
            *(u32 *)((u8 *)&lbl_8048CE28 + 0x1c) = 1;
        }
    }
    return 0;
}

s32 fn_803D66F0(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    u32 r = fn_803D803C(a, b, x);
    u32 o = r * 0xc0;
    if (*(u32 *)(b + o + 0x2d8c) && b[r + 0x219c] != 6) {
        u8 *m = (u8 *)BattleSystem_GetPartyPokemon((BattleSystem *)a, r, b[r + 0x219c]);
        u32 v1 = Pokemon_GetValue((Pokemon *)m, 10, (void *)0);
        u32 v2 = Pokemon_GetValue((Pokemon *)m, 0x9f, (void *)0);
        if ((b + o)[0x2d67] != 0x1e && Ability_ForbidsStatus((BattleContext *)b, v1, v2) == 0) {
            *(u32 *)(b + 0xb4) += y;
        }
    } else {
        *(u32 *)(b + 0xb4) += y;
    }
    return 0;
}

s32 fn_803D67F4(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    u32 r = fn_803D803C(a, b, x);
    if ((*(u32 *)(b + r * 0xc0 + 0x2db0) & 0x1000000) || (*(u32 *)(b + r * 0x1c + 0x2e8) & 8)) {
        *(u32 *)(b + 0xb4) += y;
    }
    return 0;
}

s32 fn_803D6894(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    if (BattleSystem_CountAbility((BattleSystem *)a, (BattleContext *)b, (enum CountAbilityMode)8, 0, 0xd) ||
        BattleSystem_CountAbility((BattleSystem *)a, (BattleContext *)b, (enum CountAbilityMode)8, 0, 0x4c)) {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D6930(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    *(u32 *)(b + 0x6c) =
        BattleSystem_RandomOpponent((BattleSystem *)a, (BattleContext *)b, fn_803D803C(a, b, fn_803D6E6C(b)));
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D69A0(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 n = fn_803D6E6C(b);
    if (BattleSystem_TriggerHeldItemOnPivotMove((BattleSystem *)a, (BattleContext *)b, (int *)(b + 0x138)) == 0) {
        *(u32 *)(b + 0xb4) += n;
    }
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D6A14(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitRefreshSprite((BattleSystem *)a, (BattleContext *)b, fn_803D803C(a, b, fn_803D6E6C(b)));
    return 0;
}

s32 fn_803D6A80(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    BattleController_EmitPlayMoveHitSoundEffect((BattleSystem *)a,
                                                (BattleContext *)b,
                                                fn_803D803C(a, b, fn_803D6E6C(b)));
    return 0;
}
}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

s32 fn_803D6AEC(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    u32 x = fn_803D6E6C(b);
    u32 y = fn_803D6E6C(b);
    BattleController_EmitPlayMusic((BattleSystem *)a, fn_803D803C(a, b, x), y);
    return 0;
}
}

#pragma pop

extern "C" {

s32 fn_803D6B68(void) {
    return 0;
}

void fn_803D6B70(u8 *a, u8 *b) {
    BattleSystem_PopScript((BattleContext *)b);
}

s32 fn_803D6B78(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    lbl_8048CE28._0C = fn_803D803C(a, b, fn_803D6E6C(b));
    return 0;
}

s32 fn_803D6BE0(u8 *a, u8 *b) {
    (*(u32 *)(b + 0xb4))++;
    fn_803D6E6C(b);
    return 0;
}

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BtlCmd_RefreshMonData
s32 fn_803D6C14(BattleSystem *battleSys, BattleContext *battleCtx) {
    battleCtx->scriptCursor++;
    int inBattler = fn_803D6E6C((u8 *)battleCtx);

    int battler = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, inBattler);
    BattleSystem_ReloadPokemon(battleSys, battleCtx, battler, battleCtx->selectedPartySlot[battler]);

    return 0;
}
}

#pragma pop

extern "C" {

u32 fn_803D6E6C(u8 *p) {
    u32 i = *(u32 *)(p + 0xb4);
    u32 r = *(u32 *)(p + i * 4 + 0x2700);
    *(u32 *)(p + 0xb4) = i + 1;
    return r;
}

}

extern "C" {

// pokeplatinum BattleScript_VarAddress
u32 *fn_803D6E8C(u8 *a, u8 *b, u32 var) {
    BattleSystem *battleSys = (BattleSystem *)a;
    BattleContext *battleCtx = (BattleContext *)b;

    switch (var) {
    case BTLVAR_BATTLE_TYPE:
        return (u32 *)&battleSys->battleType;
    case BTLVAR_CRITICAL_BOOSTS:
        return (u32 *)&battleCtx->criticalBoosts;
    case BTLVAR_SIDE_EFFECT_FLAGS_DIRECT:
        return (u32 *)&battleCtx->sideEffectDirectFlags;
    case BTLVAR_SIDE_EFFECT_FLAGS_INDIRECT:
        return (u32 *)&battleCtx->sideEffectIndirectFlags;
    case BTLVAR_SIDE_EFFECT_FLAGS_ABILITY:
        return (u32 *)&battleCtx->sideEffectAbilityFlags;
    case BTLVAR_SIDE_EFFECT_TYPE:
        return (u32 *)&battleCtx->sideEffectType;
    case BTLVAR_BATTLE_CTX_STATUS:
        return (u32 *)&battleCtx->battleStatusMask;
    case BTLVAR_FIELD_CONDITIONS:
        return (u32 *)&battleCtx->fieldConditionsMask;
    case BTLVAR_POWER_MULTI:
        return (u32 *)&battleCtx->powerMul;
    case BTLVAR_CALC_TEMP:
        return (u32 *)&battleCtx->calcTemp;
    case BTLVAR_MOVE_STATUS_FLAGS:
        return (u32 *)&battleCtx->moveStatusFlags;
    case BTLVAR_SIDE_CONDITIONS_ATTACKER:
        return (u32 *)&battleCtx->sideConditionsMask[BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker)];
    case BTLVAR_SIDE_CONDITIONS_DEFENDER:
        return (u32 *)&battleCtx->sideConditionsMask[BattleSystem_GetBattlerSide(battleSys, battleCtx->defender)];
    case BTLVAR_SIDE_CONDITIONS_EFFECT_MON:
        return (u32 *)&battleCtx->sideConditionsMask[BattleSystem_GetBattlerSide(battleSys, battleCtx->sideEffectMon)];
    case BTLVAR_DAMAGE:
        return (u32 *)&battleCtx->damage;
    case BTLVAR_ATTACKER:
        return (u32 *)&battleCtx->attacker;
    case BTLVAR_DEFENDER:
        return (u32 *)&battleCtx->defender;
    case BTLVAR_SIDE_EFFECT_MON:
        return (u32 *)&battleCtx->sideEffectMon;
    case BTLVAR_FAINTED_MON:
        return (u32 *)&battleCtx->faintedMon;
    case BTLVAR_SWITCHED_MON:
        return (u32 *)&battleCtx->switchedMon;
    case BTLVAR_MSG_BATTLER_TEMP:
        return (u32 *)&battleCtx->msgBattlerTemp;
    case BTLVAR_ATTACKER_STORED_DAMAGE:
        return (u32 *)&battleCtx->storedDamage[battleCtx->attacker];
    case BTLVAR_MSG_TEMP:
        return (u32 *)&battleCtx->msgTemp;
    case BTLVAR_PAY_DAY_COUNT:
        return (u32 *)&battleCtx->payDayCount;
    case BTLVAR_CURRENT_MOVE:
        return (u32 *)&battleCtx->moveCur;
    case BTLVAR_TOTAL_TURNS:
        return (u32 *)&battleCtx->totalTurns;
    case BTLVAR_MSG_ATTACKER:
        return (u32 *)&battleCtx->msgAttacker;
    case BTLVAR_MSG_DEFENDER:
        return (u32 *)&battleCtx->msgDefender;
    case BTLVAR_MOVE_TEMP:
        return (u32 *)&battleCtx->moveTemp;
    case BTLVAR_LAST_BATTLER_ID:
        return (u32 *)&battleCtx->lastBattlerId;
    case BTLVAR_MOVE_POWER:
        return (u32 *)&battleCtx->movePower;
    case BTLVAR_AFTER_MOVE_MESSAGE_TYPE:
        return (u32 *)&battleCtx->afterMoveMessageType;
    case BTLVAR_HP_CALC_TEMP:
        return (u32 *)&battleCtx->hpCalcTemp;
    case BTLVAR_RESULT_MASK:
        return (u32 *)&battleSys->resultMask;
    case BTLVAR_SIDE_EFFECT_PARAM:
        return (u32 *)&battleCtx->sideEffectParam;
    case BTLVAR_MSG_MOVE_TEMP:
        return (u32 *)&battleCtx->msgMoveTemp;
    case BTLVAR_MSG_ITEM_TEMP:
        return (u32 *)&battleCtx->msgItemTemp;
    case BTLVAR_MSG_ABILITY_TEMP:
        return (u32 *)&battleCtx->msgAbilityTemp;
    case BTLVAR_WEATHER_TURNS:
        return (u32 *)&battleCtx->fieldConditions.weatherTurns;
    case BTLVAR_BATTLER_SPEED_TEMP:
        return (u32 *)&battleCtx->battlerSpeedTemp;
    case BTLVAR_MULTI_HIT_LOOP:
        return (u32 *)&battleCtx->multiHitLoop;
    case BTLVAR_ATTACKER_PHYSICAL_DAMAGE_MASK:
        return (u32 *)&battleCtx->turnFlags[battleCtx->attacker].physicalDamageAttackerMask;
    case BTLVAR_ATTACKER_SPECIAL_DAMAGE_MASK:
        return (u32 *)&battleCtx->turnFlags[battleCtx->attacker].specialDamageAttackerMask;
    case BTLVAR_SCRIPT_TEMP:
        return (u32 *)&battleCtx->scriptTemp;
    case BTLVAR_CRITICAL_MUL:
        return (u32 *)&battleCtx->criticalMul;
    case BTLVAR_ATTACKER_LAST_DAMAGE_TAKEN:
        return (u32 *)&battleCtx->turnFlags[battleCtx->attacker].lastDamageTaken;
    case BTLVAR_DEFENDER_LAST_DAMAGE_TAKEN:
        return (u32 *)&battleCtx->turnFlags[battleCtx->defender].lastDamageTaken;
    case BTLVAR_ATTACKER_SELF_TURN_STATUS_FLAGS:
        return (u32 *)&battleCtx->selfTurnFlags[battleCtx->attacker].statusFlags;
    case BTLVAR_DEFENDER_SELF_TURN_STATUS_FLAGS:
        return (u32 *)&battleCtx->selfTurnFlags[battleCtx->defender].statusFlags;
    case BTLVAR_SIDE_EFFECT_MON_SELF_TURN_STATUS_FLAGS:
        return (u32 *)&battleCtx->selfTurnFlags[battleCtx->sideEffectMon].statusFlags;
    case BTLVAR_FLING_TEMP:
        return (u32 *)&battleCtx->flingTemp;
    case BTLVAR_FLING_SCRIPT:
        return (u32 *)&battleCtx->flingScript;
    case BTLVAR_BATTLE_SYS_STATUS:
        return (u32 *)&battleSys->battleStatusMask;
    case BTLVAR_ATTACKER_LOCKED_MOVE:
        return (u32 *)&battleCtx->moveLockedInto[battleCtx->attacker];
    case BTLVAR_HIT_DAMAGE:
        return (u32 *)&battleCtx->hitDamage;
    case BTLVAR_NUM_SAFARI_BALLS:
        return (u32 *)&battleSys->safariBalls;
    case BTLVAR_SWITCHED_MON_TEMP:
        return (u32 *)&battleCtx->switchedMonTemp;
    case BTLVAR_MOVE_TYPE:
        return (u32 *)&battleCtx->moveType;
    case BTLVAR_MOVE_EFFECT_CHANCE:
        return (u32 *)&battleCtx->moveEffectChance;
    case BTLVAR_REGULATION_FLAG:
        return (u32 *)&battleSys->rulesetMask;
    case BTLVAR_BATTLE_CTX_STATUS_2:
        return (u32 *)&battleCtx->battleStatusMask2;
    case BTLVAR_TURN_ORDER_COUNTER:
        return (u32 *)&battleCtx->turnOrderCounter;
    case BTLVAR_MAX_BATTLERS:
        return (u32 *)&battleSys->maxBattlers;
    case BTLVAR_ATTACKER_TEMP:
        return (u32 *)&battleCtx->attackerTemp;
    case BTLVAR_DEFENDER_TEMP:
        return (u32 *)&battleCtx->defenderTemp;
    case BTLVAR_DEFENDER_PHYSICAL_DAMAGE_TAKEN:
        return (u32 *)&battleCtx->selfTurnFlags[battleCtx->defender].physicalDamageTaken;
    case BTLVAR_MSG_BATTLER_TEMP_ASSURANCE_DAMAGE_MASK:
        return (u32 *)&battleCtx->turnFlags[battleCtx->msgBattlerTemp].assuranceDamageMask;
    case BTLVAR_DEFENDER_ASSURANCE_DAMAGE_MASK:
        return (u32 *)&battleCtx->turnFlags[battleCtx->defender].assuranceDamageMask;
    case BTLVAR_ATTACKER_SHELL_BELL_DAMAGE_DEALT:
        return (u32 *)&battleCtx->selfTurnFlags[battleCtx->attacker].shellBellDamageDealt;
    }

    return NULL;
}
}

extern "C" {

void fn_803D8004(u8 *a, u8 *b) {
    fn_8016E0A0(b);
    fn_803DEF3C((Unk8063D230 *)a);
}

}

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BattleScript_Battler
u32 fn_803D803C(u8 *a, u8 *b, u32 battlerIn) {
    int battlerOut;
    BattlerData *battlerData;
    int maxBattlers, expectedBattlerType, side;
    BattleSystem *battleSys = (BattleSystem *)a;
    BattleContext *battleCtx = (BattleContext *)b;

    switch (battlerIn) {
    default:
    case BTLSCR_ATTACKER:
        battlerOut = battleCtx->attacker;
        break;

    case BTLSCR_DEFENDER:
        battlerOut = battleCtx->defender;
        break;

    case BTLSCR_FAINTED_MON:
        battlerOut = battleCtx->faintedMon;
        break;

    case BTLSCR_SWITCHED_MON:
    case BTLSCR_SWITCHED_MON_AFTER:
        battlerOut = battleCtx->switchedMon;
        break;

    case BTLSCR_SIDE_EFFECT_MON:
        battlerOut = battleCtx->sideEffectMon;
        break;

    case BTLSCR_ABILITY_MON:
        battlerOut = battleCtx->abilityMon;
        break;

    case BTLSCR_ENEMY:
        maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
        for (battlerOut = 0; battlerOut < maxBattlers; battlerOut++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, battlerOut);
            if (battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) {
                break;
            }
        }
        break;

    case BTLSCR_ENEMY_SLOT_1:
        maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
        for (battlerOut = 0; battlerOut < maxBattlers; battlerOut++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, battlerOut);
            if (battlerData->battlerType == BATTLER_TYPE_ENEMY_SIDE_SLOT_1 || battlerData->battlerType == BATTLER_TYPE_SOLO_ENEMY) {
                break;
            }
        }
        break;

    case BTLSCR_ENEMY_SLOT_2:
        if (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_DOUBLES) {
            expectedBattlerType = BATTLER_TYPE_ENEMY_SIDE_SLOT_2;
        } else {
            expectedBattlerType = BATTLER_TYPE_SOLO_ENEMY;
        }

        maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
        for (battlerOut = 0; battlerOut < maxBattlers; battlerOut++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, battlerOut);
            if (battlerData->battlerType == expectedBattlerType) {
                break;
            }
        }
        break;

    case BTLSCR_PLAYER:
        maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
        for (battlerOut = 0; battlerOut < maxBattlers; battlerOut++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, battlerOut);
            if ((battlerData->battlerType & BATTLER_TYPE_SOLO_ENEMY) == FALSE) {
                break;
            }
        }
        break;

    case BTLSCR_PLAYER_SLOT_1:
        maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
        for (battlerOut = 0; battlerOut < maxBattlers; battlerOut++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, battlerOut);
            if (battlerData->battlerType == BATTLER_TYPE_PLAYER_SIDE_SLOT_1
                || battlerData->battlerType == BATTLER_TYPE_SOLO_PLAYER) {
                break;
            }
        }
        break;

    case BTLSCR_PLAYER_SLOT_2:
        if (BattleSystem_GetBattleType(battleSys) & BATTLE_TYPE_DOUBLES) {
            expectedBattlerType = BATTLER_TYPE_PLAYER_SIDE_SLOT_2;
        } else {
            expectedBattlerType = BATTLER_TYPE_SOLO_PLAYER;
        }

        maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
        for (battlerOut = 0; battlerOut < maxBattlers; battlerOut++) {
            battlerData = BattleSystem_GetBattlerData(battleSys, battlerOut);
            if (battlerData->battlerType == expectedBattlerType) {
                break;
            }
        }
        break;

    case BTLSCR_MSG_ATTACKER:
        battlerOut = battleCtx->msgAttacker;
        break;

    case BTLSCR_MSG_DEFENDER:
        battlerOut = battleCtx->msgDefender;
        break;

    case BTLSCR_ATTACKER_PARTNER: {
        // must re-declare to match
        int battlers = BattleSystem_GetMaxBattlers(battleSys);
        for (battlerOut = 0; battlerOut < battlers; battlerOut++) {
            if (battlerOut != battleCtx->attacker
                && BattleSystem_GetBattlerSide(battleSys, battlerOut) == BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker)) {
                break;
            }
        }

        if (battlerOut == battlers) {
            GF_ASSERT("FALSE");
            battlerOut = 0;
        }
        break;
    }

    case BTLSCR_DEFENDER_PARTNER: {
        // must re-declare to match
        int battlers = BattleSystem_GetMaxBattlers(battleSys);
        for (battlerOut = 0; battlerOut < battlers; battlerOut++) {
            if (battlerOut != battleCtx->defender
                && BattleSystem_GetBattlerSide(battleSys, battlerOut) == BattleSystem_GetBattlerSide(battleSys, battleCtx->defender)) {
                break;
            }
        }

        if (battlerOut == battlers) {
            GF_ASSERT("FALSE");
            battlerOut = 0;
        }
        break;
    }

    case BTLSCR_ATTACKER_ENEMY:
        maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
        side = BattleSystem_GetBattlerSide(battleSys, battleCtx->attacker);

        for (battlerOut = 0; battlerOut < maxBattlers; battlerOut++) {
            if (side != BattleSystem_GetBattlerSide(battleSys, battlerOut)) {
                break;
            }
        }
        break;

    case BTLSCR_DEFENDER_ENEMY:
        maxBattlers = BattleSystem_GetMaxBattlers(battleSys);
        side = BattleSystem_GetBattlerSide(battleSys, battleCtx->defender);

        for (battlerOut = 0; battlerOut < maxBattlers; battlerOut++) {
            if (side != BattleSystem_GetBattlerSide(battleSys, battlerOut)) {
                break;
            }
        }
        break;

    case BTLSCR_MSG_TEMP:
    case BTLSCR_MSG_BATTLER_TEMP:
        battlerOut = battleCtx->msgBattlerTemp;
        break;
    }

    GF_ASSERT(battlerOut != BATTLER_NONE);
    return battlerOut;
}
}

#pragma pop

#pragma push
#pragma optimize_for_size on
#pragma dont_inline on

extern "C" {

// pokeplatinum BattleMessageParams_Make
#define battleCtx ((BattleContext *)b)
#define msgParams ((BattleMessageParams *)c)
void fn_803D8444(u8 *b, void *c) {
    int i;
    int tagCount = 0;

    msgParams->id = fn_803D6E6C((u8 *)battleCtx);
    msgParams->tags = fn_803D6E6C((u8 *)battleCtx);

    switch (msgParams->tags) {
    case TAG_NONE:
        tagCount = 0;
        break;

    case TAG_NONE_SIDE_CONSCIOUS:
    case TAG_NICKNAME:
    case TAG_MOVE:
    case TAG_STAT:
    case TAG_ITEM:
    case TAG_NUMBER:
    case TAG_NUMBERS:
    case TAG_TRNAME:
        tagCount = 1;
        break;

    case TAG_NICKNAME_NICKNAME:
    case TAG_NICKNAME_MOVE:
    case TAG_NICKNAME_ABILITY:
    case TAG_NICKNAME_STAT:
    case TAG_NICKNAME_TYPE:
    case TAG_NICKNAME_POKE:
    case TAG_NICKNAME_ITEM:
    case TAG_NICKNAME_POFFIN:
    case TAG_NICKNAME_NUM:
    case TAG_NICKNAME_TRNAME:
    case TAG_NICKNAME_BOX:
    case TAG_MOVE_SIDE:
    case TAG_MOVE_NICKNAME:
    case TAG_MOVE_MOVE:
    case TAG_ABILITY_NICKNAME:
    case TAG_ITEM_MOVE:
    case TAG_NUMBER_NUMBER:
    case TAG_TRNAME_TRNAME:
    case TAG_TRNAME_NICKNAME:
    case TAG_TRNAME_ITEM:
    case TAG_TRNAME_NUM:
    case TAG_TRCLASS_TRNAME:
        tagCount = 2;
        break;

    case TAG_NICKNAME_NICKNAME_MOVE:
    case TAG_NICKNAME_NICKNAME_ABILITY:
    case TAG_NICKNAME_NICKNAME_ITEM:
    case TAG_NICKNAME_MOVE_MOVE:
    case TAG_NICKNAME_MOVE_NUMBER:
    case TAG_NICKNAME_ABILITY_NICKNAME:
    case TAG_NICKNAME_ABILITY_MOVE:
    case TAG_NICKNAME_ABILITY_ITEM:
    case TAG_NICKNAME_ABILITY_STAT:
    case TAG_NICKNAME_ABILITY_TYPE:
    case TAG_NICKNAME_ABILITY_STATUS:
    case TAG_NICKNAME_ABILITY_NUMBER:
    case TAG_NICKNAME_ITEM_NICKNAME:
    case TAG_NICKNAME_ITEM_MOVE:
    case TAG_NICKNAME_ITEM_STAT:
    case TAG_NICKNAME_ITEM_STATUS:
    case TAG_NICKNAME_BOX_BOX:
    case TAG_ITEM_NICKNAME_FLAVOR:
    case TAG_TRNAME_NICKNAME_NICKNAME:
    case TAG_TRCLASS_TRNAME_NICKNAME:
    case TAG_TRCLASS_TRNAME_ITEM:
        tagCount = 3;
        break;

    case TAG_NICKNAME_ABILITY_NICKNAME_MOVE:
    case TAG_NICKNAME_ABILITY_NICKNAME_ABILITY:
    case TAG_NICKNAME_ABILITY_NICKNAME_STAT:
    case TAG_NICKNAME_ITEM_NICKNAME_ITEM:
    case TAG_TRNAME_NICKNAME_TRNAME_NICKNAME:
    case TAG_TRCLASS_TRNAME_NICKNAME_NICKNAME:
    case TAG_TRCLASS_TRNAME_NICKNAME_TRNAME:
    case TAG_TRCLASS_TRNAME_TRCLASS_TRNAME:
        tagCount = 4;
        break;

    case TAG_TRCLASS_TRNAME_NICKNAME_TRCLASS_TRNAME_NICKNAME:
        tagCount = 6;
        break;

    default:
        break;
    }

    for (i = 0; i < tagCount; i++) {
        msgParams->params[i] = fn_803D6E6C((u8 *)battleCtx);
    }
}
#undef battleCtx
#undef msgParams
}

#pragma pop

#pragma push
#pragma optimize_for_size on

extern "C" {

// pokeplatinum BattleMessage_Make
#define battleSys ((BattleSystem *)a)
#define battleCtx ((BattleContext *)b)
#define msgParams ((BattleMessageParams *)c)
#define msg ((BattleMessage *)d)
void fn_803D8520(u8 *a, u8 *b, void *c, u8 *d) {
    msg->id = msgParams->id;
    msg->tags = msgParams->tags;

    switch (msg->tags) {
    case TAG_NONE:
        break;

    case TAG_NONE_SIDE_CONSCIOUS:
        msg->params[0] = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        break;

    case TAG_NICKNAME:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        break;

    case TAG_MOVE:
        msg->params[0] = (int)fn_803D90A0((u8 *)battleCtx, msgParams->params[0]);
        break;

    case TAG_STAT:
        msg->params[0] = (int)fn_803D91D4((u8 *)battleCtx, msgParams->params[0]);
        break;

    case TAG_ITEM:
        msg->params[0] = fn_803D90C4(battleCtx, msgParams->params[0]);
        break;

    case TAG_NUMBER:
    case TAG_NUMBERS:
        msg->params[0] = (int)fn_803D915C((u8 *)battleCtx, msgParams->params[0]);
        break;

    case TAG_TRNAME:
        msg->params[0] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[0]);
        break;

    case TAG_NICKNAME_NICKNAME:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        break;

    case TAG_NICKNAME_MOVE:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = (int)fn_803D90A0((u8 *)battleCtx, msgParams->params[1]);
        break;

    case TAG_NICKNAME_ABILITY:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D917C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        break;

    case TAG_NICKNAME_STAT:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = (int)fn_803D91D4((u8 *)battleCtx, msgParams->params[1]);
        break;

    case TAG_NICKNAME_TYPE:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = (int)fn_803D916C((u8 *)battleCtx, msgParams->params[1]);
        break;

    case TAG_NICKNAME_POKE:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = BattleMessage_PokeTag(battleSys, battleCtx, msgParams->params[1]);
        break;

    case TAG_NICKNAME_ITEM:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D90C4(battleCtx, msgParams->params[1]);
        if (msg->id == 0x201) {
            lbl_8048CE28._0C = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        }
        break;

    case TAG_NICKNAME_POFFIN:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = BattleMessage_PoffinTag(battleCtx, msgParams->params[1]);
        break;

    case TAG_NICKNAME_NUM:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = (int)fn_803D915C((u8 *)battleCtx, msgParams->params[1]);
        break;

    case TAG_NICKNAME_TRNAME:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[1]);
        break;

    case TAG_NICKNAME_BOX:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = msgParams->params[1];
        break;

    case TAG_MOVE_SIDE:
        msg->params[0] = (int)fn_803D90A0((u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D803C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        break;

    case TAG_MOVE_NICKNAME:
        msg->params[0] = (int)fn_803D90A0((u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        break;

    case TAG_MOVE_MOVE:
        msg->params[0] = (int)fn_803D90A0((u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = (int)fn_803D90A0((u8 *)battleCtx, msgParams->params[1]);
        break;

    case TAG_ABILITY_NICKNAME:
        msg->params[0] = fn_803D917C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        break;

    case TAG_ITEM_MOVE:
        msg->params[0] = fn_803D90C4(battleCtx, msgParams->params[0]);
        msg->params[1] = (int)fn_803D90A0((u8 *)battleCtx, msgParams->params[1]);
        break;

    case TAG_NUMBER_NUMBER:
        msg->params[0] = (int)fn_803D915C((u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = (int)fn_803D915C((u8 *)battleCtx, msgParams->params[1]);
        break;

    case TAG_TRNAME_TRNAME:
        msg->params[0] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[0]);
        msg->params[1] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[1]);
        break;

    case TAG_TRNAME_NICKNAME:
        msg->params[0] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        break;

    case TAG_TRNAME_ITEM:
        msg->params[0] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D90C4(battleCtx, msgParams->params[1]);
        break;

    case TAG_TRNAME_NUM:
        msg->params[0] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[0]);
        msg->params[1] = (int)fn_803D915C((u8 *)battleCtx, msgParams->params[1]);
        break;

    case TAG_TRCLASS_TRNAME:
        msg->params[0] = BattleMessage_TrainerClassTag(battleSys, battleCtx, msgParams->params[0]);
        msg->params[1] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[1]);
        break;

    case TAG_NICKNAME_NICKNAME_MOVE:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = (int)fn_803D90A0((u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_NICKNAME_ABILITY:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D917C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_NICKNAME_ITEM:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D90C4(battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_MOVE_MOVE:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = (int)fn_803D90A0((u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = (int)fn_803D90A0((u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_MOVE_NUMBER:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = (int)fn_803D90A0((u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = (int)fn_803D915C((u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_ABILITY_NICKNAME:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D917C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_ABILITY_MOVE:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D917C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = (int)fn_803D90A0((u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_ABILITY_ITEM:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D917C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D90C4(battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_ABILITY_STAT:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D917C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = (int)fn_803D91D4((u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_ABILITY_TYPE:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D917C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = (int)fn_803D916C((u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_ABILITY_STATUS:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D917C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = (int)fn_803D91E4((u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_ABILITY_NUMBER:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D917C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = (int)fn_803D915C((u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_ITEM_NICKNAME:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D90C4(battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_ITEM_MOVE:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D90C4(battleCtx, msgParams->params[1]);
        msg->params[2] = (int)fn_803D90A0((u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_ITEM_STAT:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D90C4(battleCtx, msgParams->params[1]);
        msg->params[2] = (int)fn_803D91D4((u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_ITEM_STATUS:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D90C4(battleCtx, msgParams->params[1]);
        msg->params[2] = (int)fn_803D91E4((u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_BOX_BOX:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = msgParams->params[1];
        msg->params[2] = msgParams->params[2];
        break;

    case TAG_ITEM_NICKNAME_FLAVOR:
        msg->params[0] = fn_803D90C4(battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = BattleMessage_FlavorTag(battleCtx, msgParams->params[2]);
        break;

    case TAG_TRNAME_NICKNAME_NICKNAME:
        msg->params[0] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_TRCLASS_TRNAME_NICKNAME:
        msg->params[0] = BattleMessage_TrainerClassTag(battleSys, battleCtx, msgParams->params[0]);
        msg->params[1] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[2]);
        break;

    case TAG_TRCLASS_TRNAME_ITEM:
        msg->params[0] = BattleMessage_TrainerClassTag(battleSys, battleCtx, msgParams->params[0]);
        msg->params[1] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D90C4(battleCtx, msgParams->params[2]);
        break;

    case TAG_NICKNAME_ABILITY_NICKNAME_MOVE:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D917C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[2]);
        msg->params[3] = (int)fn_803D90A0((u8 *)battleCtx, msgParams->params[3]);
        break;

    case TAG_NICKNAME_ABILITY_NICKNAME_ABILITY:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D917C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[2]);
        msg->params[3] = fn_803D917C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[3]);
        break;

    case TAG_NICKNAME_ABILITY_NICKNAME_STAT:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D917C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[2]);
        msg->params[3] = (int)fn_803D91D4((u8 *)battleCtx, msgParams->params[3]);
        break;

    case TAG_NICKNAME_ITEM_NICKNAME_ITEM:
        msg->params[0] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D90C4(battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[2]);
        msg->params[3] = fn_803D90C4(battleCtx, msgParams->params[3]);
        break;

    case TAG_TRNAME_NICKNAME_TRNAME_NICKNAME:
        msg->params[0] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[0]);
        msg->params[1] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[1]);
        msg->params[2] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[2]);
        msg->params[3] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[3]);
        break;

    case TAG_TRCLASS_TRNAME_NICKNAME_NICKNAME:
        msg->params[0] = BattleMessage_TrainerClassTag(battleSys, battleCtx, msgParams->params[0]);
        msg->params[1] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[2]);
        msg->params[3] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[3]);
        break;

    case TAG_TRCLASS_TRNAME_NICKNAME_TRNAME:
        msg->params[0] = BattleMessage_TrainerClassTag(battleSys, battleCtx, msgParams->params[0]);
        msg->params[1] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[2]);
        msg->params[3] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[3]);
        break;

    case TAG_TRCLASS_TRNAME_TRCLASS_TRNAME:
        msg->params[0] = BattleMessage_TrainerClassTag(battleSys, battleCtx, msgParams->params[0]);
        msg->params[1] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[1]);
        msg->params[2] = BattleMessage_TrainerClassTag(battleSys, battleCtx, msgParams->params[2]);
        msg->params[3] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[3]);
        break;

    case TAG_TRCLASS_TRNAME_NICKNAME_TRCLASS_TRNAME_NICKNAME:
        msg->params[0] = BattleMessage_TrainerClassTag(battleSys, battleCtx, msgParams->params[0]);
        msg->params[1] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[1]);
        msg->params[2] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[2]);
        msg->params[3] = BattleMessage_TrainerClassTag(battleSys, battleCtx, msgParams->params[3]);
        msg->params[4] = BattleMessage_TrainerNameTag(battleSys, battleCtx, msgParams->params[4]);
        msg->params[5] = fn_803D903C((u8 *)battleSys, (u8 *)battleCtx, msgParams->params[5]);
        break;

    default:
        GF_ASSERT("FALSE");
        break;
    }
}
#undef battleSys
#undef battleCtx
#undef msgParams
#undef msg
}

#pragma pop

extern "C" {

u32 fn_803D903C(u8 *a, u8 *b, s32 c) {
    u32 r = fn_803D803C(a, b, c);
    if (c == 0x16) {
        return r | (b[r + 0x21a0] << 8);
    }
    return r | (b[r + 0x219c] << 8);
}

u8 *fn_803D90A0(u8 *p, s32 i) {
    switch (i) {
        case 1:    p = *(u8 **)(p + 0x3044); break;
        case 0xff: p = *(u8 **)(p + 0x124); break;
    }
    return p;
}

}

extern "C" {

// pokeplatinum BattleMessage_ItemTag
int fn_803D90C4(BattleContext *battleCtx, int battlerIn) {
    int item;
    switch (battlerIn) {
        case BTLSCR_ATTACKER:
            item = battleCtx->battleMons[battleCtx->attacker].heldItem;
            BattleAI_SetHeldItem(battleCtx, battleCtx->attacker, item);
            break;

        case BTLSCR_DEFENDER:
            item = battleCtx->battleMons[battleCtx->defender].heldItem;
            BattleAI_SetHeldItem(battleCtx, battleCtx->defender, item);
            break;

        case BTLSCR_MSG_BATTLER_TEMP:
            item = battleCtx->battleMons[battleCtx->msgBattlerTemp].heldItem;
            BattleAI_SetHeldItem(battleCtx, battleCtx->msgBattlerTemp, item);
            break;

        case BTLSCR_MSG_TEMP:
            item = battleCtx->msgItemTemp;
            break;

        default:
            break;
    }

    return item;
}
}

extern "C" {

u8 *fn_803D915C(u8 *p, s32 i) {
    if (i == 0xff) {
        p = *(u8 **)(p + 0x130);
    }
    return p;
}

u8 *fn_803D916C(u8 *p, s32 i) {
    if (i == 0xff) {
        p = *(u8 **)(p + 0x130);
    }
    return p;
}

u32 fn_803D917C(u8 *a, u8 *b, s32 c) {
    u32 r;
    switch (c) {
        case 0xff: return *(u32 *)(b + 0x12c);
        default:
            r = fn_803D803C(a, b, c);
            u8 *q = b + (u8)r;
            return q[0x390] = b[r * 0xc0 + 0x2d67];
    }
}

u8 *fn_803D91D4(u8 *p, s32 i) {
    if (i == 0xff) {
        p = *(u8 **)(p + 0x130);
    }
    return p;
}

u8 *fn_803D91E4(u8 *p, s32 i) {
    if (i == 0xff) {
        p = *(u8 **)(p + 0x130);
    }
    return p;
}
}
