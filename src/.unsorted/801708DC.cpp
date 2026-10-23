#include ".unsorted/801708DC.hpp"

#include "common.hpp"

extern "C" {

void fn_80170BEC(void) {}
void fn_80170C34(void) {}
void fn_80174E2C(void) {}
void fn_80174E70(void) {}
void fn_80176B14(u8 *p, u8 v) {
    *(u8 *)(p + 0x4) = v;
}
}

extern "C" {

s32 fn_80170958(u32 arg0) {
    if ((arg0 == 0x8AU) || (arg0 == 0x47U) || (arg0 == 0x48U) || (arg0 == 0x8DU) || (arg0 == 0xCAU) || (arg0 == 0x199U)) {
        return 1;
    }
    return 0;
}
}

extern "C" {

u8 *fn_80170D14(u8 *arg0, u8 *arg1, u8 *arg2) {
    u16 temp_r0;
    u16 temp_r6;

    (*(u8 *)((u8 *)(arg1) + (0))) = (u8) (*(u8 *)((u8 *)(arg0) + (1)));
    temp_r6 = (*(u16 *)((u8 *)(arg0) + (2)));
    (*(u16 *)((u8 *)(arg1) + (0x14))) = temp_r6;
    (*(u16 *)((u8 *)(arg1) + (0x18))) = (u16) (*(u16 *)((u8 *)(arg0) + (4)));
    temp_r0 = (*(u16 *)((u8 *)(arg0) + (6)));
    if (temp_r6 < temp_r0) {
        (*(s16 *)((u8 *)(arg1) + (0x16))) = 0;
    } else {
        (*(s16 *)((u8 *)(arg1) + (0x16))) = (s16) (temp_r6 - temp_r0);
    }
    (*(s8 *)((u8 *)(arg1) + (2))) = 3;
    (*(s32 *)((u8 *)(arg2) + (0xC))) = (s32) ((*(s32 *)((u8 *)(arg2) + (0xC))) + 8);
    return arg0 + 8;
}
}

extern "C" {

u8 *fn_80170D68(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3, s32 arg4) {
    if (arg4 != 0) {
        (*(u8 *)((u8 *)(arg1) + (0))) = (u8) (*(u8 *)((u8 *)(arg0) + (1)));
    }
    if (arg3 != 0) {
        (*(u16 *)((u8 *)(arg1) + (8))) = (u16) (*(u16 *)((u8 *)(arg0) + (2)));
        (*(s32 *)((u8 *)(arg1) + (0x10))) = (s32) (*(s32 *)((u8 *)(arg0) + (4)));
    } else {
        (*(u16 *)((u8 *)(arg1) + (6))) = (u16) (*(u16 *)((u8 *)(arg0) + (2)));
        (*(s32 *)((u8 *)(arg1) + (0xC))) = (s32) (*(s32 *)((u8 *)(arg0) + (4)));
    }
    (*(s32 *)((u8 *)(arg2) + (0xC))) = (s32) ((*(s32 *)((u8 *)(arg2) + (0xC))) + 8);
    return arg0 + 8;
}
}

extern "C" {

u8 *fn_80170DB8(u8 *arg0, u8 *arg1, u8 *arg2) {
    (*(u8 *)((u8 *)(arg1) + (0))) = (u8) (*(u8 *)((u8 *)(arg0) + (1)));
    (*(s16 *)((u8 *)(arg1) + (4))) = 0x64;
    (*(s32 *)((u8 *)(arg2) + (0xC))) = (s32) ((*(s32 *)((u8 *)(arg2) + (0xC))) + 4);
    (*(u16 *)((u8 *)(arg1) + (6))) = (u16) (*(u16 *)((u8 *)(arg0) + (6)));
    (*(s32 *)((u8 *)(arg1) + (0xC))) = (s32) (*(s32 *)((u8 *)(arg0) + (8)));
    (*(s32 *)((u8 *)(arg2) + (0xC))) = (s32) ((*(s32 *)((u8 *)(arg2) + (0xC))) + 8);
    return arg0 + 0xC;
}
}

extern "C" {

u8 *fn_80170998(void);
s32 fn_80174D88(s32);
s32 fn_80174DDC(u8);

s32 fn_80174E74(u8 *arg0) {
    s32 var_r4;
    u8 temp_r0;

    var_r4 = 0;
    temp_r0 = (*(u8 *)((u8 *)(arg0) + (0)));
    switch ((s32) temp_r0) {                        /* irregular */
    case 18:
        var_r4 = fn_80174D88((*(s32 *)((u8 *)(fn_80170998()) + (4))));
        break;
    case 10:
        var_r4 = fn_80174D88((*(s32 *)((u8 *)(arg0) + (4))));
        break;
    case 14:
        var_r4 = fn_80174DDC((*(u8 *)((u8 *)(arg0) + (2))));
        break;
    }
    return var_r4;
}
}

extern "C" {

s32 memset(u8 *, s32, s32);

u8 *fn_801763E4(u8 *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    memset(arg0 + 0xC, 0, 0xC);
    return arg0;
}
}

extern "C" {

s32 loadFsys__6GSfsysFUl(s32);

s32 fn_801764BC(u8 *arg0, s32 arg1) {
    loadFsys__6GSfsysFUl(arg1);
    (*(s32 *)((u8 *)(arg0) + (4))) = arg1;
    (*(s8 *)((u8 *)(arg0) + (0))) = 1;
    return 1;
}
}

extern "C" {

s32 fn_800250E8(s32, s32);
s32 fn_8022A900(s32, s32);
s32 sleepCurrentThread__15GSthreadManagerFv(s32);
extern s32 lbl_8063E9B0;
extern s32 sInstance__15GSthreadManager;

void fn_801768AC(u8 *arg0) {
    s32 temp_r31;

    if (((s32) lbl_8063E9B0 != 0) && ((s32) (*(s32 *)((u8 *)(arg0) + (8))) != 0)) {
        temp_r31 = fn_800250E8(lbl_8063E9B0, 2);
        do {
            sleepCurrentThread__15GSthreadManagerFv(sInstance__15GSthreadManager);
        } while (fn_8022A900(temp_r31, (*(s32 *)((u8 *)(arg0) + (8)))) != 0);
    }
}
}

extern "C" {

void fn_80176B1C(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s8 *)((u8 *)(arg0) + (4))) = 0;
    (*(s8 *)((u8 *)(arg0) + (5))) = 0;
    (*(s8 *)((u8 *)(arg0) + (6))) = 0;
}
}

extern "C" {

s32 MoveTable_LoadParam__FUlUl(s32, s32);
s32 fn_80170DF8(s32, s32, s32, s32);

s32 fn_80170DF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u16 temp_r0;
    u16 temp_r7;

    temp_r7 = (*(u16 *)((u8 *)(arg0) + (2)));
    (*(u16 *)((u8 *)(arg1) + (2))) = temp_r7;
    (*(u16 *)((u8 *)(arg1) + (6))) = (u16) (*(u16 *)((u8 *)(arg0) + (4)));
    temp_r0 = (*(u16 *)((u8 *)(arg0) + (6)));
    if (temp_r7 < temp_r0) {
        (*(s16 *)((u8 *)(arg1) + (4))) = 0;
    } else {
        (*(s16 *)((u8 *)(arg1) + (4))) = (s16) (temp_r7 - temp_r0);
    }
    if (arg3 != 0) {
        (*(s8 *)((u8 *)(arg1) + (1))) = (s8) arg3;
    } else {
        (*(s8 *)((u8 *)(arg1) + (1))) = MoveTable_LoadParam__FUlUl((s32) (*(u16 *)((u8 *)(arg2) + (0x18))), 3);
    }
    (*(s32 *)((u8 *)(arg2) + (0xC))) = (s32) ((*(s32 *)((u8 *)(arg2) + (0xC))) + 8);
    return arg0 + 8;
}
}

extern "C" {

s32 fn_801708DC(s32);

s32 fn_801708DC(s32 arg0) {
    u16 temp_r3;

    temp_r3 = MoveTable_LoadParam__FUlUl((s32)(arg0), (s32)(0));
    if ((temp_r3 == 0x27) || (temp_r3 == 0x4B) || (temp_r3 == 0x91) || (temp_r3 == 0x97) || (temp_r3 == 0x9B) || (temp_r3 == 0xFF) || (temp_r3 == 0x100) || (temp_r3 == 0x107) || (temp_r3 == 0x110)) {
        return 1;
    }
    return 0;
}
}

extern "C" {

s32 fn_80176BC8(s32);
s32 fn_8022A940(s32);

s32 fn_80176BC8(s32 arg0) {
    s32 var_r3;

    var_r3 = lbl_8063E9B0;
    if (var_r3 != 0) {
        var_r3 = fn_800250E8((s32)(var_r3), (s32)(0));
        if (var_r3 != 0) {
            var_r3 = fn_8022A940(var_r3);
        }
    }
    return var_r3;
}
}

extern "C" {

s32 fn_80176920(s32, s32, s32, s32, s32);
s32 fn_801769A0(s32, s32);
s32 fn_80176C84(s32, s32, s32, s32);

s32 fn_80176C84(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;
    s32 temp_r4;

    temp_r3 = fn_80176920(arg0, 0xB, arg1, arg2, 0);
    temp_r4 = temp_r3;
    if (arg3 == 0) {
        return temp_r3;
    }
    fn_801769A0(arg0, temp_r4);
    return 0;
}
}

extern "C" {

s32 fn_80176CEC(s32, s32, s32, s32, s32);

s32 fn_80176CEC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r3;
    s32 temp_r4;

    temp_r3 = fn_80176920((s32)(arg0), (s32)(0xF), (s32)(arg1), (s32)(arg2), (s32)(arg3));
    temp_r4 = temp_r3;
    if (arg4 == 0) {
        return temp_r3;
    }
    fn_801769A0(arg0, temp_r4);
    return 0;
}
}

extern "C" {

s32 fn_80176D58(s32, s32, s32, s32, s32);

s32 fn_80176D58(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r3;
    s32 temp_r4;

    temp_r3 = fn_80176920((s32)(arg0), (s32)(5), (s32)(arg1), (s32)(arg2), (s32)(arg3));
    temp_r4 = temp_r3;
    if (arg4 == 0) {
        return temp_r3;
    }
    fn_801769A0(arg0, temp_r4);
    return 0;
}
}

extern "C" {

s32 fn_80176DC4(s32, s32, s32);

s32 fn_80176DC4(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;
    s32 temp_r4;

    temp_r3 = fn_80176920((s32)(arg0), (s32)(0x11), (s32)(arg1), (s32)(0), (s32)(0));
    temp_r4 = temp_r3;
    if (arg2 == 0) {
        return temp_r3;
    }
    fn_801769A0(arg0, temp_r4);
    return 0;
}
}

extern "C" {

s32 fn_80176E2C(s32, s32, s32);

s32 fn_80176E2C(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;
    s32 temp_r4;

    temp_r3 = fn_80176920((s32)(arg0), (s32)(0x10), (s32)(arg1), (s32)(0), (s32)(0));
    temp_r4 = temp_r3;
    if (arg2 == 0) {
        return temp_r3;
    }
    fn_801769A0(arg0, temp_r4);
    return 0;
}
}
