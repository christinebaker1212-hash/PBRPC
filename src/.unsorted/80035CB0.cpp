#include ".unsorted/80035CB0.hpp"

#include "common.hpp"

extern "C" {

/* lbl_8063EA68 */ extern Unk80035CB0 *lbl_8063EA68;

Unk80035CB0 *fn_80035D9C(void) {
    return lbl_8063EA68;
}
u32 fn_80035E38(Unk80035CB0 *p) {
    return p->_00;
}
void fn_80035E40(Unk80035CB0 *p, u32 v) {
    p->_00 = v;
}
u32 fn_80035E48(Unk80035CB0 *p) {
    return p->_04;
}
void fn_80035E50(Unk80035CB0 *p, u32 v) {
    p->_04 = v;
}
u32 fn_80035E58(Unk80035CB0 *p) {
    return p->_08;
}
void fn_80035E60(Unk80035CB0 *p, u32 v) {
    p->_08 = v;
}
u32 fn_80035E68(Unk80035CB0 *p) {
    return p->_0C;
}
void fn_80035E70(Unk80035CB0 *p, u32 v) {
    p->_0C = v;
}
u32 fn_80035E78(Unk80035CB0 *p) {
    return p->_10;
}
void fn_80035E80(Unk80035CB0 *p, u32 v) {
    p->_10 = v;
}
u32 fn_80035E88(Unk80035CB0 *p) {
    return p->_14;
}
void fn_80035E90(Unk80035CB0 *p, u32 v) {
    p->_14 = v;
}
void fn_80035E98(Unk80035CB0 *p, u32 v) {
    p->_2C = v;
}
u32 fn_80035EA0(Unk80035CB0 *p) {
    return p->_2C;
}
u16 fn_80035EA8(Unk80035CB0 *p) {
    return p->_970->_02;
}
void fn_80035EB4(Unk80035CB0 *p, u16 v) {
    p->_970->_02 = v;
}
u8 fn_80035EC0(Unk80035CB0 *p) {
    return p->_970->_04;
}
void fn_80035ECC(Unk80035CB0 *p, u8 v) {
    p->_970->_04 = v;
}
u8 fn_80035ED8(Unk80035CB0 *p) {
    return p->_970->_05;
}
void fn_80035EE4(Unk80035CB0 *p, u8 v) {
    p->_970->_05 = v;
}
u8 fn_80035EF0(Unk80035CB0 *p) {
    return p->_970->_06;
}
u16 fn_80035EFC(Unk80035CB0 *p) {
    return p->_970->_08;
}
void fn_80035F08(Unk80035CB0 *p, u16 v) {
    p->_970->_08 = v;
}
u16 fn_80035F14(Unk80035CB0 *p) {
    return p->_970->_0A;
}
void fn_80035F20(Unk80035CB0 *p, u16 v) {
    p->_970->_0A = v;
}
u16 fn_80035F2C(Unk80035CB0 *p) {
    return p->_970->_0C;
}
void fn_80035F38(Unk80035CB0 *p, u16 v) {
    p->_970->_0C = v;
}
u16 fn_80035F44(Unk80035CB0 *p) {
    return p->_970->_18;
}
u8 fn_80035F50(Unk80035CB0 *p) {
    return p->_970->_24;
}
void fn_80035F5C(Unk80035CB0 *p, u8 v) {
    p->_970->_24 = v;
}
u8 fn_80035F68(Unk80035CB0 *p) {
    return p->_970->_25;
}
void fn_80035F74(Unk80035CB0 *p, u8 v) {
    p->_970->_25 = v;
}
u8 fn_80035F80(Unk80035CB0 *p) {
    return p->_970->_26;
}
u8 fn_80035F8C(Unk80035CB0 *p) {
    return p->_970->_27;
}
BOOL fn_80035F98(Unk80035CB0 *p) {
    return p->_970->_26 != 0xFF;
}
s32 fn_80036844(void) {
    return 0;
}
u8 fn_80036F18(Unk80035CB0 *p) {
    return p->_330;
}
void fn_80036F20(Unk80035CB0 *p, u8 v) {
    p->_330 = v;
}
BOOL fn_80036F50(Unk80035CB0 *p, u32 mask) {
    return (p->mFlags & mask) != 0;
}
}

extern "C" {

void fn_80035CB0(u8 *arg0) {
    (*(s8 *)((u8 *)(arg0) + (7))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0))) = 0;
    (*(s16 *)((u8 *)(arg0) + (2))) = 0;
    (*(s8 *)((u8 *)(arg0) + (4))) = 0;
    (*(s8 *)((u8 *)(arg0) + (5))) = 0;
    (*(s8 *)((u8 *)(arg0) + (6))) = 0;
    (*(s8 *)((u8 *)(arg0) + (8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0xA))) = 0;
}
}

extern "C" {

s32 fn_800360D0(u8 *arg0) {
    s32 var_r3;
    u8 *temp_r4;

    temp_r4 = (*(u8 **)((u8 *)(arg0) + (0x970)));
    var_r3 = 0;
    if ((u8) (*(u8 *)((u8 *)(temp_r4) + (0x2C))) != 0xFF) {
        var_r3 = 1;
        if ((u8) (*(u8 *)((u8 *)(temp_r4) + (0x64))) != 0xFF) {
            var_r3 = 2;
            if ((u8) (*(u8 *)((u8 *)(temp_r4) + (0x9C))) != 0xFF) {
                var_r3 = 3;
                if ((u8) (*(u8 *)((u8 *)(temp_r4) + (0xD4))) != 0xFF) {
                    return 4;
                }
            }
        }
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8003698C(s32 arg0, s32 arg1) {
    if (((arg1 >= 0x80) && (arg1 <= 0x84)) || ((arg1 >= 0) && (arg1 <= 4))) {
        return (*(s32 *)((u8 *)((arg0 + ((arg1 * 4) & 0xC))) + (0x18)));
    }
    return 0;
}
}

extern "C" {

void fn_800369C4(s32 arg0, s32 arg1, s32 arg2) {
    if (((arg1 >= 0x80) && (arg1 <= 0x84)) || ((arg1 >= 0) && (arg1 <= 4))) {
        (*(s32 *)((u8 *)((arg0 + ((arg1 * 4) & 0xC))) + (0x18))) = arg2;
    }
}
}

extern "C" {

s32 fn_80036D14(s32 arg0, s32 arg1) {
    if ((arg1 < 0) || (arg1 > 3)) {
        return 0;
    }
    return arg0 + (arg1 * 0x34) + 0x340;
}
}

extern "C" {

s32 fn_80036D78(s32 arg0, s32 arg1) {
    if ((arg1 < 0) || (arg1 > 3)) {
        return 0;
    }
    return arg0 + (arg1 * 0x34) + 0x410;
}
}

extern "C" {

u8 fn_80036E6C(s32 arg0, s32 arg1, u32 arg2) {
    if (arg2 == 1U) {
        return (*(u8 *)((u8 *)((arg0 + (arg1 * 0x34))) + (0x420)));
    }
    return (*(u8 *)((u8 *)((arg0 + (arg1 * 0x34))) + (0x350)));
}
}

extern "C" {

u8 fn_80036E94(s32 arg0, s32 arg1, u32 arg2) {
    if (arg2 == 1U) {
        return (*(u8 *)((u8 *)((arg0 + (arg1 * 0x34))) + (0x421)));
    }
    return (*(u8 *)((u8 *)((arg0 + (arg1 * 0x34))) + (0x351)));
}
}

extern "C" {

void fn_80036F28(u8 *arg0, s32 arg1, s32 arg2) {
    if (arg2 != 0) {
        (*(s32 *)((u8 *)(arg0) + (0x334))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0x334))) | arg1);
        return;
    }
    (*(s32 *)((u8 *)(arg0) + (0x334))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0x334))) & ~arg1);
}
}

extern "C" {

u8 *memset(u8 *, s32, u32);

void fn_80035DA4(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = -1;
    (*(s32 *)((u8 *)(arg0) + (8))) = -1;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x14))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x330))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x2C))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x334))) = 0;
    memset(arg0 + 0x860, 0, 0x10C);
    memset(arg0 + 0x4E0, 0, 0x380);
    memset(arg0 + 0x340, 0, 0xD0);
    (*(u8 **)((u8 *)(arg0) + (0x970))) = (u8 *) (arg0 + 0x860);
    (*(u8 **)((u8 *)(arg0) + (0x96C))) = (u8 *) (arg0 + 0x4E0);
}
}

extern "C" {

s32 fn_80035CE0(s32);

s32 fn_80035CE0(s32 arg0) {
    s32 var_r31;
    u32 var_r30;

    var_r31 = arg0 + 0x340;
    var_r30 = arg0 + 0x410;
    do {
        fn_80035CB0((u8 *)(var_r31));
        var_r31 += 0x34;
    } while ((u32) var_r31 < var_r30);
    do {
        fn_80035CB0((u8 *)((s32) var_r30));
        var_r30 += 0x34;
    } while (var_r30 < (u32) (arg0 + 0x4E0));
    fn_80035DA4((u8 *)(arg0));
    return arg0;
}
}

extern "C" {

s32 fn_80036068(s32);
s32 fn_8016F628(s32);
s32 fn_80177080(s32, s32, s32);

s32 fn_80036068(s32 arg0) {
    s32 temp_r3_2;
    u16 temp_r3;

    temp_r3 = (*(u16 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x970)))) + (8)));
    if ((s32) temp_r3 == 0) {
        return 0;
    }
    temp_r3_2 = fn_8016F628((s32) temp_r3);
    if (temp_r3_2 == 0) {
        return 0;
    }
    fn_80177080(arg0 + 0x30, temp_r3_2, 0x80);
    return arg0 + 0x30;
}
}
