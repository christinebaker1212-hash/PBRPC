#include ".unsorted/8016A25C.hpp"

#include "common.hpp"

extern "C" {

/* lbl_8041F820 */ extern u8 lbl_8041F820[];
extern u8 lbl_8063F1C0;
extern u8 lbl_8063F1C4[4];

u8 fn_8016CE10(u32, Unk8016A25C *obj) {
    return lbl_8041F820[obj->_08];
}
void fn_8016D1C0(u8 v) {
    lbl_8063F1C0 = v;
}
void fn_8016D1C8(u32 i, u8 v) {
    lbl_8063F1C4[i] = v;
}
}

extern "C" {

s32 fn_8016E66C(void);
s32 fn_8016E6B0(s32);
extern s32 lbl_8063F188;
extern s32 lbl_8063F1AC;
extern s32 lbl_8063F1C8;

s32 fn_8016C100(void) {
    s32 temp_r3;

    if (((u32) (((lbl_8063F188 & 0x80000 & ~0x1000) | (lbl_8063F188 & 0x1000)) + 0xFFF80000) == 0x1000U) && ((s32) lbl_8063F1AC != 0)) {
        lbl_8063F1AC = 0;
        return 3;
    }
    temp_r3 = fn_8016E6B0(lbl_8063F1C8);
    if (temp_r3 != 0) {
        return temp_r3;
    }
    do {

    } while (fn_8016E66C() == 0);
    return fn_8016E6B0(lbl_8063F1C8);
}
}

extern "C" {

s32 BattleContext_Set__FP12BattleSystemP13BattleContext18BattleContextParamii(s32, s32, s32, s32, s32);
s32 BattleSystem_GetBattleContext(void);
s32 fn_803AC828(void);

void fn_8016DDD8(s32 arg0) {
    s32 temp_r31;

    temp_r31 = fn_803AC828();
    BattleContext_Set__FP12BattleSystemP13BattleContext18BattleContextParamii(temp_r31, BattleSystem_GetBattleContext(), 3, 0, arg0);
}
}

extern "C" {

s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
s32 getHeapBlockSize__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;
extern s32 lbl_8063F17C;

void fn_8016E0A0(s32 arg0) {
    lbl_8063F17C -= getHeapBlockSize__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, arg0);
    freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, arg0);
}
}

extern "C" {

s32 fn_80045590(void);
s32 fn_800456BC(s32);
s32 fn_8016A640(void);
s32 fn_8016E5C0(s32, s32);
s32 fn_8016F314(void);
s32 fn_80176B34(s32, s32);
s32 fn_8017B518(void);
s32 fn_803AC5F0(void);
s32 fn_803D9D7C__Fv(void);
extern s32 lbl_8063F16C;

s32 fn_8016A640(void) {
    s32 temp_r3;
    s32 var_r3;

    fn_803AC5F0();
    if (((lbl_8063F188 & 0x40000 & ~0x2000) | (lbl_8063F188 & 0x2000)) != 0) {
        fn_8017B518();
    }
    fn_8016F314();
    fn_803D9D7C__Fv();
    temp_r3 = fn_80045590();
    if (temp_r3 != 0) {
        fn_800456BC(temp_r3);
    }
    if ((s32) lbl_8063F16C != 0) {
        fn_80176B34(lbl_8063F16C, 1);
        lbl_8063F16C = 0;
    }
    var_r3 = lbl_8063F1C8;
    if (var_r3 != 0) {
        var_r3 = fn_8016E5C0(var_r3, 1);
    }
    return var_r3;
}
}

extern "C" {

s32 BattleSystem_SetResultMask(s32, s32);
s32 fn_8005EC20(s32);
s32 fn_80167C4C(s32);
s32 fn_8016C8A4(s32);
s32 sleepCurrentThread__15GSthreadManagerFv(s32);
extern s32 sInstance__15GSthreadManager;

s32 fn_8016C8A4(s32 arg0) {
    u32 temp_r3;
    u32 var_r31;

    sleepCurrentThread__15GSthreadManagerFv(sInstance__15GSthreadManager);
    if (lbl_8063F188 & 0x800) {
        temp_r3 = fn_80167C4C(arg0);
        var_r31 = temp_r3;
        if (temp_r3 == 7U) {
            BattleSystem_SetResultMask(fn_803AC828(), 7);
        }
    } else {
        var_r31 = fn_8005EC20(arg0);
    }
    return (s32) var_r31;
}
}

extern "C" {

s32 fn_8000C7E8__Fv(void);
s32 fn_800217CC__FP11Unk8063E970iPv(s32, s32, s32);
s32 fn_8016D1D4(s32, s32, s32, s32);
s32 fn_80176C04(s32);
s32 fn_80176D58(s32, s32, s32, s32, s32);

s32 fn_8016D1D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    fn_80176C04(lbl_8063F16C);
    fn_80176D58(lbl_8063F16C, arg0, arg1 | (arg3 << 0x10), arg2, 1);
    return fn_800217CC__FP11Unk8063E970iPv(fn_8000C7E8__Fv(), 3, (arg0 << 0x10) | arg1);
}
}

extern "C" {

s32 fn_8005D78C(s32, s32, s32, s32);

void fn_8016C914() {
    if (lbl_8063F188 & 0x800) {
        fn_8005D78C(0, 0xF, 0, 0);
    } else {
        fn_8005D78C(0, 0xC, 0xF, 0);
    }
    do {
        sleepCurrentThread__15GSthreadManagerFv((s32)(sInstance__15GSthreadManager));
    } while (fn_8005EC20((s32)(0)) != 0xF4FAU);
}
}

extern "C" {

u8 BattleSystem_GetBattlerType(s32, s32);
s32 Party_GetPokemonBySlotIndex__FPC5Partyl(s32, s32);
s32 Pokemon_GetValue__FP7PokemonUlPv(s32, s32, s32);

s32 fn_8016D948(s32 arg0, u8 *arg1) {
    u8 temp_r0;
    u8 temp_r3;

    if (lbl_8063F188 & 8) {
        if (BattleSystem_GetBattlerType((*(s32 *)((u8 *)(arg1) + (4))), (*(s32 *)((u8 *)(arg1) + (0x1C)))) == 2) {
            if (arg0 & 1) {
                return 0x505A;
            }
            goto block_6;
        }
        if (!(arg0 & 1)) {
            return 0x505A;
        }
        goto block_6;
    }
block_6:
    if (Pokemon_GetValue__FP7PokemonUlPv(Party_GetPokemonBySlotIndex__FPC5Partyl((*(s32 *)((u8 *)(arg1) + (0))), arg0), 0xA2, 0) == 0) {
        (*(u8 *)((u8 *)(arg1) + (0xD))) = (u8) arg0;
        return 0x2ED2;
    }
    temp_r3 = (*(u8 *)((u8 *)((arg1 + arg0)) + (0x20)));
    if (((u8) (*(u8 *)((u8 *)(arg1) + (0xA))) == temp_r3) || ((u8) (*(u8 *)((u8 *)(arg1) + (0xB))) == temp_r3)) {
        (*(u8 *)((u8 *)(arg1) + (0xD))) = (u8) arg0;
        return 0x2ED1;
    }
    temp_r0 = (*(u8 *)((u8 *)(arg1) + (9)));
    if ((temp_r0 != 6) && (temp_r0 == temp_r3)) {
        (*(u8 *)((u8 *)(arg1) + (0xD))) = (u8) arg0;
        return 0x2ED3;
    }
    if ((s32) (*(u16 *)((u8 *)(arg1) + (0x1A))) != 0) {
        (*(u8 *)((u8 *)(arg1) + (0xD))) = (u8) (*(u8 *)((u8 *)(arg1) + (0xC)));
        return 0x30BB;
    }
    return 0;
}
}

extern "C" {

s32 fn_8016D850(void);
u8 fn_80177BDC(s32, s32);
__declspec(section ".data") extern s32 lbl_8048CDB4;

void fn_8016DC8C() {
    s32 var_r30;
    s32 var_r29;
    s32 temp_r3;

    if (lbl_8063F188 & 8) {
        var_r30 = 0;
loop_2:
        if (((s32) (*(u8 *)((u8 *)((lbl_8063F1C8 + var_r30)) + (0x7C))) == 0) && ((s32) fn_80177BDC(var_r30, 0xA) == 7)) {
            BattleSystem_SetResultMask((s32)(fn_803AC828()), (s32)(7));
            return;
        }
        var_r30 += 1;
        if (var_r30 >= 4) {
            return;
        }
        goto loop_2;
    }
    temp_r3 = fn_8016D850();
    if (!(temp_r3 & 3) && ((s32) fn_80177BDC(0, 0xA) == 7)) {
        BattleSystem_SetResultMask((s32)(fn_803AC828()), (s32)(7));
        return;
    }
    if (!(temp_r3 & 0xC) && ((s32) fn_80177BDC(1, 0xA) == 7)) {
        BattleSystem_SetResultMask((s32)(fn_803AC828()), (s32)(7));
        return;
    }
    var_r29 = 0;
loop_14:
    if (((*(u8 *)((u8 *)(&lbl_8048CDB4) + (0x1A))) & (8 << var_r29)) && ((s32) fn_80177BDC(var_r29, 0xA) == 7)) {
        BattleSystem_SetResultMask((s32)(fn_803AC828()), (s32)(7));
        return;
    }
    var_r29 += 1;
    if (var_r29 >= 4) {
        return;
    }
    goto loop_14;
}
}
