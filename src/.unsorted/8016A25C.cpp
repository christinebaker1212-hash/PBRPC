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
