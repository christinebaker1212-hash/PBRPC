#include ".unsorted/80048728.hpp"

#include "common.hpp"

extern "C" {

void fn_80048D98(void) {}
void fn_80048FB4(void) {}
void fn_80048FB8(void) {}
void fn_80048FBC(void) {}
}

extern "C" {

void fn_80048728(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0x94))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x98))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x88))) = 0;
    (*(s8 *)((u8 *)(arg0) + (1))) = 0;
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 fn_8004879C(void);

s32 fn_80048748(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8004879C();
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_801E34DC__FP11GSsceneDataUl(s32, s32);

void fn_80048D9C(u8 *arg0, u8 *arg1) {
    s32 temp_r3;
    s32 temp_r5;

    temp_r5 = (*(s32 *)((u8 *)(arg1) + (0x44)));
    if (temp_r5 != 0) {
        (*(s32 *)((u8 *)(arg1) + (0x44))) = (s32) ((*(s32 *)((u8 *)(arg0) + (4))) + temp_r5);
    }
    temp_r3 = (*(s32 *)((u8 *)(arg1) + (0x44)));
    (*(s32 *)((u8 *)(arg1) + (0x48))) = temp_r3;
    fn_801E34DC__FP11GSsceneDataUl(temp_r3, temp_r3);
}
}

extern "C" {

s32 fn_80206D8C(s32);

void fn_80048E04(u8 *arg0, u8 *arg1) {
    s32 temp_r5;

    temp_r5 = (*(s32 *)((u8 *)(arg1) + (0x40)));
    if (temp_r5 != 0) {
        (*(s32 *)((u8 *)(arg1) + (0x40))) = (s32) ((*(s32 *)((u8 *)(arg0) + (4))) + temp_r5);
    }
    (*(s32 *)((u8 *)(arg1) + (0x44))) = fn_80206D8C((*(s32 *)((u8 *)(arg1) + (0x40))));
}
}

extern "C" {

s32 fn_801E4970(s32);

void fn_80048FC0(u8 *arg0, u8 *arg1) {
    s32 temp_r5;

    temp_r5 = (*(s32 *)((u8 *)(arg1) + (0x44)));
    if (temp_r5 != 0) {
        (*(s32 *)((u8 *)(arg1) + (0x44))) = (s32) ((*(s32 *)((u8 *)(arg0) + (4))) + temp_r5);
    }
    (*(s32 *)((u8 *)(arg1) + (0x48))) = fn_801E4970((*(s32 *)((u8 *)(arg1) + (0x44))));
}
}

extern "C" {

f32 fn_80049058(u8 *arg0) {
    return (*(f32 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x94)))) + (0x1C)));
}
}

extern "C" {

s32 fn_80048864(s32, s32);
s32 fn_800489C4(s32, s32);
s32 free__5GSmemFPv(s32);
s32 loadFile__6GSfileFPcPUl(s32, s32);
s32 strncpy(s32, s32, s32);

s32 fn_80048864(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r31;
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3 = loadFile__6GSfileFPcPUl(arg1, (s32) &sp8);
    if (temp_r3 == 0) {
        return 0;
    }
    if ((s32) (*(u8 *)((u8 *)(arg0) + (1))) != 0) {
        temp_r3_2 = (*(s32 *)((u8 *)(arg0) + (4)));
        if (temp_r3_2 != 0) {
            free__5GSmemFPv(temp_r3_2);
        }
    }
    (*(u8 *)((u8 *)(arg0) + (1))) = 1U;
    temp_r31 = fn_800489C4(arg0, temp_r3);
    strncpy(arg0 + 8, arg1, 0x80);
    return temp_r31;
}
}

extern "C" {

s32 fn_80048DC4(s32, s32);
s32 fn_801E37F0(s32);

s32 fn_80048DC4(s32 arg0, s32 arg1) {
    s32 var_r3;

    var_r3 = (*(s32 *)((u8 *)(arg1) + (0x48)));
    if (var_r3 != 0) {
        var_r3 = fn_801E37F0(var_r3);
        (*(s32 *)((u8 *)(arg1) + (0x48))) = 0;
    }
    return var_r3;
}
}

extern "C" {

s32 fn_80048E50(s32, s32);
s32 fn_80206DF4(s32);

s32 fn_80048E50(s32 arg0, s32 arg1) {
    s32 var_r3;

    var_r3 = (*(s32 *)((u8 *)(arg1) + (0x44)));
    if (var_r3 != 0) {
        var_r3 = fn_80206DF4(var_r3);
        (*(s32 *)((u8 *)(arg1) + (0x44))) = 0;
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8004900C(s32, s32);
s32 fn_801E4A84(s32);
s32 fn_801E4BCC(s32, s32);

s32 fn_8004900C(s32 arg0, s32 arg1) {
    s32 var_r3;

    var_r3 = (*(s32 *)((u8 *)(arg1) + (0x48)));
    if (var_r3 != 0) {
        fn_801E4BCC(var_r3, 0);
        var_r3 = fn_801E4A84((*(s32 *)((u8 *)(arg1) + (0x48))));
        (*(s32 *)((u8 *)(arg1) + (0x48))) = 0;
    }
    return var_r3;
}
}
