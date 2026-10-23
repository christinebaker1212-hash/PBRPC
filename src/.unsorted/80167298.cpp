#include ".unsorted/80167298.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80167298(s32, s32, s32);

s32 fn_80167298(s32 arg0, s32 arg1, s32 arg2) {
    return arg2;
}
}

extern "C" {

s32 fn_801673C4(s32, s32);

s32 fn_801673C4(s32 arg0, s32 arg1) {
    if ((u32) arg1 < 4U) {
        return arg1;
    }
    return 4;
}
}

extern "C" {

s32 fn_8016741C(s32, s32);

s32 fn_8016741C(s32 arg0, s32 arg1) {
    if ((u32) arg1 < 8U) {
        return arg1;
    }
    return 8;
}
}

extern "C" {

s32 fn_8016747C(s32, s32);

s32 fn_8016747C(s32 arg0, s32 arg1) {
    if ((u32) arg1 < 0x6ECU) {
        return arg1;
    }
    return 0x6EC;
}
}

extern "C" {

s32 fn_801673D8(s32, s32);
s32 fn_801687D0(void);
s32 memcpy(s32, s32, s32);

s32 fn_801673D8(s32 arg0, s32 arg1) {
    s32 sp8;

    sp8 = fn_801687D0();
    memcpy(arg1, (s32) &sp8, 4);
    return 4;
}
}

extern "C" {

s32 fn_80167490(s32, s32);
s32 fn_801689A0(void);
s32 fn_80168B6C(s32);

s32 fn_80167490(s32 arg0, s32 arg1) {
    s32 temp_r31;

    temp_r31 = fn_801689A0();
    fn_80168B6C(fn_801689A0());
    memcpy((s32)(arg1), (s32)(temp_r31), (s32)(0x6EC));
    return 0x6EC;
}
}

extern "C" {

s32 strlen(s32);
__declspec(section ".data") extern s8 lbl_8048C928;

u32 fn_80167354(s32 arg0, u8 *arg1, u32 arg2) {
    u32 var_r31;

    var_r31 = strlen((s32)(&lbl_8048C928)) + 1;
    if (var_r31 > arg2) {
        var_r31 = arg2;
    }
    memcpy((s32)((s32)(arg1)), (s32)((s32)((u8 *) &lbl_8048C928)), (s32)((s32)(var_r31)));
    return var_r31;
}
}

extern "C" {

s32 fn_80168AFC(void);
s32 fn_80168B0C(void);

s32 fn_80167430(s32 arg0, u8 *arg1) {
    s32 sp8[2];

    sp8[0] = fn_80168AFC();
    sp8[1] = fn_80168B0C();
    memcpy((s32)((s32)(arg1)), (s32)((s32)((u8 *) sp8)), (s32)((s32)(8U)));
    return 8;
}
}

extern "C" {

u8 fn_80058BA4__Fv(void);
s32 sprintf(s8 *, const s8 *, ...);
s8 *strcpy(s8 *, const s8 *);
__declspec(section ".data") extern s32 lbl_8041F390;
__declspec(section ".data") extern s32 lbl_8041F39C;
extern s32 lbl_8063D2D0;

u32 fn_801672A0(s32 arg0, u32 arg1) {
    u32 var_r3;
    u8 *temp_r30;

    strcpy((s8 *)(&(*(s32 (*))&lbl_8048C928)), (const s8 *)(lbl_8063D2D0));
    temp_r30 = (u8 *)&(*(s32 (*))&lbl_8048C928) + ((u32)strlen((s32)((const s8 *)(&(*(s32 (*))&lbl_8048C928)))));
    sprintf((s8 *)(temp_r30), (const s8 *)(&lbl_8041F390), fn_80058BA4__Fv());
    sprintf((s8 *)((u8 *)&(*(s32 (*))&lbl_8048C928) + ((u32)strlen((s32)((const s8 *)(&(*(s32 (*))&lbl_8048C928)))))), (const s8 *)(&lbl_8041F39C), 1U);
    var_r3 = ((u32)strlen((s32)((const s8 *)(&(*(s32 (*))&lbl_8048C928))))) + 1;
    if (var_r3 > arg1) {
        var_r3 = arg1;
    }
    return var_r3;
}
}
