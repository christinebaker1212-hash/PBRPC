#include ".unsorted/80162B70.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063D5BC;
extern u8 lbl_8063D5B8;
s32 fn_80162EDC();

void fn_80162B88(void) {}
void fn_80162B8C(void) {}
void fn_80162C70(u32 v) {
    lbl_8063D5BC = v;
}
void fn_80162F14(void) {
    fn_80162EDC();
}
void fn_80162F18(void) {
    fn_80162EDC();
}
void fn_80162F1C(void) {
    fn_80162EDC();
}
u8 fn_801633E4(void) {
    return lbl_8063D5B8;
}
}

extern "C" {

extern s32 lbl_8063F048;
extern s32 lbl_8063F050;

s32 fn_80162B70(void) {
    if ((s32) lbl_8063F050 != 0) {
        return lbl_8063F050;
    }
    return lbl_8063F048;
}
}

extern "C" {

extern s32 lbl_8063F054;
extern s32 lbl_8063F058;

void fn_80162C64(s32 arg0, s32 arg1) {
    lbl_8063F054 = arg0;
    lbl_8063F058 = arg1;
}
}

extern "C" {

extern s32 lbl_8063D5D4;
extern s32 lbl_8063D5D8;

void fn_80162D6C(s32 arg0, s32 arg1) {
    lbl_8063D5D8 = arg0;
    lbl_8063D5D4 = arg1;
}
}

extern "C" {

s32 fn_80163674(void);

void fn_80162FD4(void) {
    fn_80163674();
    lbl_8063F048 = 0;
    lbl_8063F050 = 0;
}
}

extern "C" {

s32 fn_80009838(void);

void fn_80163098(void) {
    if (fn_80009838() == 0) {
        fn_80163674();
        lbl_8063F048 = 3;
    }
}
}

extern "C" {

void fn_80163134(void) {
    fn_80163674();
    lbl_8063F048 = 5;
}
}

extern "C" {

s32 fn_80162B90(void);
s32 fn_80167A60(void);
s32 fn_8025DFD0(void);
s32 fn_8025E0F0(s32);
s32 fn_8025E30C(s32);
s32 fn_802615A0(s32, s32);
s32 fn_80261800(s32, s32);
s32 fn_80262550(s32, s32, s32);

s32 fn_80162B90(void) {
    s32 temp_r3;

    fn_80162B88();
    fn_802615A0(fn_8025E30C(fn_8025DFD0()), 0x371);
    fn_80262550(fn_8025E30C(fn_8025DFD0()), 0, 0);
    temp_r3 = fn_8025E0F0(fn_8025DFD0());
    if (temp_r3 != 0) {
        return temp_r3;
    }
    fn_80167A60();
    return fn_80261800(fn_8025E30C(fn_8025DFD0()), 5);
}
}

extern "C" {

s32 fn_80162BFC(void);

s32 fn_80162BFC(void) {
    s32 temp_r3;

    fn_802615A0((s32)(fn_8025E30C((s32)(fn_8025DFD0()))), (s32)(0x371));
    fn_80262550((s32)(fn_8025E30C((s32)(fn_8025DFD0()))), (s32)(0), (s32)(0));
    temp_r3 = fn_8025E0F0((s32)(fn_8025DFD0()));
    if (temp_r3 != 0) {
        return temp_r3;
    }
    fn_80167A60();
    return fn_80261800((s32)(fn_8025E30C((s32)(fn_8025DFD0()))), (s32)(2));
}
}

extern "C" {

s32 fn_80162C78(void);
s32 fn_80262548(s32, s32);

s32 fn_80162C78(void) {
    s32 temp_r3;

    fn_802615A0((s32)(fn_8025E30C((s32)(fn_8025DFD0()))), (s32)(0x400318));
    fn_80262548(fn_8025E30C((s32)(fn_8025DFD0())), lbl_8063D5BC);
    fn_80262550((s32)(fn_8025E30C((s32)(fn_8025DFD0()))), (s32)(lbl_8063F058), (s32)(lbl_8063F054));
    temp_r3 = fn_8025E0F0((s32)(fn_8025DFD0()));
    if (temp_r3 != 0) {
        return temp_r3;
    }
    return fn_80261800((s32)(fn_8025E30C((s32)(fn_8025DFD0()))), (s32)(1));
}
}

extern "C" {

s32 fn_80162F20(void);
s32 fn_8025E0B0(s32);

s32 fn_80162F20(void) {
    fn_80162B8C();
    return fn_8025E0B0(fn_8025DFD0());
}
}

extern "C" {

s32 fn_8025E158(s32);

s32 fn_80162EDC() {
    s32 temp_r31;

    temp_r31 = fn_8025E158(fn_8025DFD0());
    fn_80167A60();
    return temp_r31;
}
}

extern "C" {

s32 createThread__15GSthreadManagerFUlPFPv_PvPvUllUs(s32, s32, s32, s32, s32, s32, s32);
s32 fn_8016340C(void);
s32 fn_80163B7C(s32);
s32 fn_801687C8(s32);
s32 fn_80168C48(void);
s32 fn_801694A0(void);
s32 fn_8025DF80(s32);
s32 fn_802ED204(s32);
void fn_8016315C(void);
extern s32 sInstance__15GSthreadManager;

void fn_80162F48(s32 arg0) {
    fn_8016340C();
    fn_802ED204(0);
    fn_8025DFD0();
    fn_8025DF80(arg0);
    fn_80163B7C(arg0);
    fn_80167A60();
    fn_80168C48();
    fn_801694A0();
    fn_801687C8(0x200);
    createThread__15GSthreadManagerFUlPFPv_PvPvUllUs(sInstance__15GSthreadManager, 0x1770, (s32) &fn_8016315C, 0, 0x4000, 8, 1);
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8041F178;

void fn_80163000(s32 arg0) {
    if (fn_80009838() == 0) {
        fn_80163674();
        ((s32 (*)(s32, s32))fn_80162D6C)((s32) &lbl_8041F178, 4);
        lbl_8063F048 = 4;
        lbl_8063F050 = 1;
    }
}
}

extern "C" {

void fn_8016304C() {
    if (fn_80009838() == 0) {
        fn_80163674();
        ((s32 (*)(s32, s32))fn_80162D6C)((s32) &lbl_8041F178, 1);
        lbl_8063F048 = 4;
        lbl_8063F050 = 2;
    }
}
}
