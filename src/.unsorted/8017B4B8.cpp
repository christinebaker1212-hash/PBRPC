#include ".unsorted/8017B4B8.hpp"

#include "common.hpp"

extern "C" {

s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;
extern s32 lbl_8063F228;

void fn_8017B518(void) {
    freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, lbl_8063F228);
}
}

extern "C" {

s32 allocFromHeap__5GSmemFP12MEMiHeapHeadUl(s32, s32, u32);
s32 fn_801700DC(u32, s32);

s32 fn_8017B584(u8 *arg0, u8 *arg1) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r3_2;
    s32 temp_r5;
    s32 var_r31;
    u32 temp_r3;
    u32 temp_r5_2;

    var_r31 = 0;
    temp_r5 = (*(s32 *)((u8 *)(arg0) + (8)));
    if ((temp_r5 != 0) && ((u32) (*(u32 *)((u8 *)(arg0) + (0))) < (u32) temp_r5)) {
        (*(s8 *)((u8 *)(arg1) + (5))) = 2;
        temp_r5_2 = (*(u32 *)((u8 *)(arg0) + (0)));
        temp_r0 = (*(s32 *)((u8 *)(arg0) + (8))) - temp_r5_2;
        (*(s32 *)((u8 *)(arg1) + (0x14))) = temp_r0;
        var_r31 = allocFromHeap__5GSmemFP12MEMiHeapHeadUl(gUnkHeap2, temp_r0, temp_r5_2);
        fn_801700DC((*(u32 *)((u8 *)(arg0) + (0))), var_r31);
        (*(s32 *)((u8 *)(arg1) + (0x10))) = var_r31;
        (*(u32 *)((u8 *)(arg0) + (0))) = (u32) ((*(u32 *)((u8 *)(arg0) + (0))) + (*(s32 *)((u8 *)(arg1) + (0x14))));
    }
    temp_r0_2 = (*(s32 *)((u8 *)(arg0) + (0x10)));
    if (temp_r0_2 != 0) {
        temp_r3 = (*(u32 *)((u8 *)(arg0) + (4)));
        if (temp_r3 < (u32) temp_r0_2) {
            (*(s32 *)((u8 *)(arg1) + (0x18))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0x14))) + (temp_r3 * 0x24));
            temp_r3_2 = (*(s32 *)((u8 *)(arg0) + (0x10))) - (*(u32 *)((u8 *)(arg0) + (4)));
            (*(s32 *)((u8 *)(arg1) + (0x1C))) = temp_r3_2;
            (*(u32 *)((u8 *)(arg0) + (4))) = (u32) ((*(u32 *)((u8 *)(arg0) + (4))) + temp_r3_2);
            (*(s32 *)((u8 *)(arg1) + (0x1C))) = (s32) ((*(s32 *)((u8 *)(arg1) + (0x1C))) * 0x24);
        }
    }
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x18))) != 0) {
        (*(s32 *)((u8 *)(arg1) + (0x20))) = (s32) (*(s32 *)((u8 *)(arg0) + (0x1C)));
        (*(s32 *)((u8 *)(arg1) + (0x24))) = (s32) (*(s32 *)((u8 *)(arg0) + (0x18)));
    }
    (*(u8 *)((u8 *)(arg1) + (6))) = (u8) ((*(u8 *)((u8 *)(arg1) + (6))) | 1);
    return var_r31;
}
}

extern "C" {

extern s32 lbl_8063F1C8;

void fn_8017BDB0(u8 *arg0, s32 arg1) {
    (*(s32 *)((u8 *)(arg0) + (0x2C))) = 0x28;
    (*(s32 *)((u8 *)(arg0) + (0x28))) = (s32) (*(s32 *)((u8 *)((lbl_8063F1C8 + (arg1 * 4))) + (0x60)));
    (*(s8 *)((u8 *)(arg0) + (7))) = (s8) (arg1 ^ 1);
    (*(u8 *)((u8 *)(arg0) + (6))) = (u8) ((*(u8 *)((u8 *)(arg0) + (6))) | 8);
}
}

extern "C" {

s32 fn_803D9AEC__FP13BattleMessagePUl(s32, s32 *);
s32 memcpy(s32, s32, s32);

void fn_8017BDE4(u8 *arg0) {
    s32 sp8;
    s32 temp_r31;

    memcpy((*(s32 *)((u8 *)((lbl_8063F1C8 + ((*(u8 *)((u8 *)(arg0) + (7))) * 4))) + (0x60))), (*(s32 *)((u8 *)(arg0) + (0x28))), (*(s32 *)((u8 *)(arg0) + (0x2C))));
    temp_r31 = (*(s32 *)((u8 *)((lbl_8063F1C8 + ((*(u8 *)((u8 *)(arg0) + (7))) * 4))) + (0x60)));
    memcpy(temp_r31 + 0x28, fn_803D9AEC__FP13BattleMessagePUl(temp_r31 + 4, &sp8), sp8);
}
}

extern "C" {

s32 fn_8016F3FC(s32);
s32 fn_8016F40C(s32);
s32 fn_8016F73C(s32);
s32 fn_8017B538(s32);

s32 fn_8017B538(s32 arg0) {
    s32 temp_r3;

    (*(s32 *)((u8 *)(arg0) + (0xC))) = fn_8016F3FC(arg0 + 8);
    (*(s32 *)((u8 *)(arg0) + (0x14))) = fn_8016F40C(arg0 + 0x10);
    temp_r3 = fn_8016F73C(arg0 + 0x18);
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = temp_r3;
    return temp_r3;
}
}

extern "C" {

s32 fn_80168B68(void);
s32 fn_8017B848(s32, s32);
s32 fn_8017C514(void);

s32 fn_8017C514(void) {
    s32 temp_r3;

    temp_r3 = fn_80168B68();
    if (temp_r3 == 0) {
        return 0;
    }
    if ((s32) (*(s32 *)((u8 *)(temp_r3) + (0xC))) != 0) {
        fn_8017B848(temp_r3, 1);
    }
    return (s32) (*(u8 *)((u8 *)(temp_r3) + (4)));
}
}

extern "C" {

s32 memset(s32, s32, s32);
__declspec(section ".data") extern s32 lbl_8048DF68;

void fn_8017B4B8() {
    memset((s32) &lbl_8048DF68, 0, 0x20);
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8048DF98;

void fn_8017BE5C(u8 *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((u8 *)(arg0) + (0x2C))) = (s32) (arg1 * 4);
    (*(s32 **)((u8 *)(arg0) + (0x28))) = &lbl_8048DF98;
    (*(u8 *)((u8 *)(arg0) + (6))) = (u8) ((*(u8 *)((u8 *)(arg0) + (6))) | 0x20);
}
}

extern "C" {

struct S_lbl_8048DF88 { s32 f_0; s32 f_4; s32 f_8; s32 f_C; };
__declspec(section ".data") extern struct S_lbl_8048DF88 lbl_8048DF88;

void fn_8017B4CC() {
    lbl_8063F228 = ((s32 (*)(s32, s32))allocFromHeap__5GSmemFP12MEMiHeapHeadUl)(gUnkHeap2, 0xA0);
    ((s32 (*)(void))fn_8017B4B8)();
    lbl_8048DF88.f_0 = 0;
    lbl_8048DF88.f_4 = 0;
    lbl_8048DF88.f_8 = 0;
    lbl_8048DF88.f_C = 0;
}
}
