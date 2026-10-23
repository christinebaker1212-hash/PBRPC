#include ".unsorted/8025B6E8.hpp"

#include "common.hpp"

extern "C" {

/* lbl_80424F60 */ extern Unk80424F60 lbl_80424F60;
/* lbl_80425110 */ extern Unk80425110 lbl_80425110;
/* lbl_80502548 */ extern u32 lbl_80502548[];
extern u32 lbl_8063F958;
extern u32 lbl_8063F95C;
extern u32 lbl_8063F960;
extern u32 lbl_8063F968;

void fn_8025BA00();
void fn_802F0760();
void fn_802F1BB8();
void fn_802F0588(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
void fn_8025DBA0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

void fn_8025B6E8(void) {
    fn_8025BA00();
}

s32 fn_8025B720(u32 v) {
    lbl_8063F95C = v;
    return 0;
}

s32 fn_8025B7F0(u32 v) {
    lbl_8063F958 = v;
    return 0;
}

void fn_8025B8B4(u32 v) {
    lbl_80424F60._28 = v;
}
void fn_8025B8C4(u32 v) {
    lbl_80424F60._2C = v;
}
void fn_8025B8D4(u32 v) {
    lbl_80424F60._10 = v;
}
void fn_8025B8E4(u32 v) {
    lbl_80424F60._14 = v;
}
u32 fn_8025B8F4(void) {
    return lbl_80424F60._38;
}
void fn_8025B948(u32 v) {
    lbl_80424F60._24 = v;
}
void fn_8025B958(u32 v) {
    lbl_80424F60._20 = v;
}
void fn_8025B9DC(u32 v) {
    lbl_80424F60._18 = v;
}
void fn_8025B9EC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_802F0588((u32)&lbl_80424F60, a1, a2, a3, a4, a5, a6, a7);
}
void fn_8025B9F8(void) {
    fn_802F0760();
}
void fn_8025B9FC(void) {
    fn_802F1BB8();
}
u32 fn_8025BD9C(void) {
    return lbl_8063F960;
}

void fn_8025BF04(u32 seed) {
    lbl_8063F968 = (seed << 16) | seed;
}

u8 fn_8025BF14(void) {
    u32 next = lbl_8063F968 * 0x45 + 0x1111;
    lbl_8063F968 = next & 0x7FFFFFFF;
    return next >> 16;
}

u32 fn_8025CA88(void) {
    return lbl_80425110._08;
}
u32 fn_8025CA98(void) {
    return lbl_80425110._0C;
}
void fn_8025CC38(void) {
    lbl_80502548[0] = 0;
}
u32 fn_8025CC94(void) {
    return lbl_80502548[1];
}

void fn_8025CEF8(Unk8025CEF8 *obj) {
    obj->_6050 = 0;
    obj->_6054 = 0;
    obj->_6058 = 0;
}

void fn_8025D390(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_8025DBA0(a0 + 0x6030, a1, a2, a3, a4, a5, a6, a7);
}
}

extern "C" {

void fn_8025CF9C(u8 *arg0);
void fn_8025CFF0(s32 arg0);

void fn_8025CF0C(u8 *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((u8 *)(arg0) + (0x6054))) = arg2;
    (*(s32 *)((u8 *)(arg0) + (0x6050))) = arg1;
    ((s32 (*)(void))fn_8025CF9C)();
    (*(s32 *)((u8 *)(arg0) + (0x6058))) = 1;
    fn_8025CFF0((s32)(arg0));
}
}

extern "C" {

void fn_8025CF50(u8 *arg0) {
    if (((s32) (*(s32 *)((u8 *)(arg0) + (0x6050))) != 0) && ((s32) (*(s32 *)((u8 *)(arg0) + (0x6054))) != 0)) {
        ((s32 (*)(void))fn_8025CF9C)();
        fn_8025CFF0((s32)(arg0));
    }
}
}

extern "C" {

s16 fn_8025D55C(u8 *, s32);
s16 fn_8025D5B4(u8 *, s32);
s32 *fn_8025D9FC(u8 *, s32 *, s32);

s32 fn_8025D218(u8 *arg0, s16 *arg1, s16 *arg2) {
    s32 sp8;
    s32 *temp_r3;

    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x6058))) == 0) {
        return 0;
    }
    temp_r3 = fn_8025D9FC(arg0 + 0x6010, &sp8, 0);
    if (temp_r3 == NULL) {
        return 0;
    }
    if (arg1 != NULL) {
        *arg1 = fn_8025D55C(arg0 + 0x6000, *temp_r3);
    }
    if (arg2 != NULL) {
        *arg2 = fn_8025D5B4(arg0 + 0x6000, *temp_r3);
    }
    return *temp_r3;
}
}

extern "C" {

s32 fn_8025DAB0(s32, u16 *, u8 *);

s32 fn_8025D31C(s32 arg0, u16 *arg1, u8 *arg2) {
    u16 spA;
    u8 sp8;
    s32 temp_r3;

    temp_r3 = fn_8025DAB0(arg0 + 0x6030, &spA, &sp8);
    if (temp_r3 == 0) {
        return 0;
    }
    if (arg1 != NULL) {
        *arg1 = spA;
    }
    if (arg2 != NULL) {
        *arg2 = sp8;
    }
    return temp_r3;
}
}

extern "C" {

s32 fn_8025BAB8(void);
s32 fn_802F1234(s32, s32);
s32 fn_802F39C8(s32 *, s32);
void fn_8025B7FC(s32 arg0, s32 arg1);

s32 fn_8025B838(s32 arg0, s32 arg1) {
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3 = fn_8025BAB8();
    if (temp_r3 == 0) {
        return -0xF0;
    }
    temp_r3_2 = fn_802F1234(arg0, arg1);
    if (temp_r3_2 < 0) {
        return temp_r3_2;
    }
    return fn_802F39C8((s32 *)(&fn_8025B7FC), (s32)(temp_r3));
}
}

extern "C" {

s32 fn_802F1308(void);
s32 fn_802F38A8(void);

void fn_8025B904(s32 arg0, s32 arg1) {
    (*(s32 *)((u8 *)(&lbl_80424F60) + (0x30))) = (s32) (arg0 != 0);
    if (arg1 != 0) {
        fn_802F1308();
        fn_802F38A8();
    }
}
}

extern "C" {

s32 OSLockMutex(s32 *);
s32 OSUnlockMutex(s32 *);
s32 fn_8025E47C(s32);
__declspec(section ".data") extern s32 lbl_80502530;

s32 fn_8025BCD8(s32 arg0, s32 arg1) {
    s32 var_r30;

    var_r30 = 0;
    if (arg1 > 0) {
        OSLockMutex(&lbl_80502530);
        var_r30 = fn_8025E47C(arg1);
        OSUnlockMutex(&lbl_80502530);
    }
    return var_r30;
}
}

extern "C" {

s32 fn_8025E4D0(s32);

void fn_8025BD40(s32 arg0, s32 arg1, s32 arg2) {
    if ((arg1 != 0) && (arg2 > 0)) {
        OSLockMutex((s32 *)(&lbl_80502530));
        fn_8025E4D0(arg1);
        OSUnlockMutex((s32 *)(&lbl_80502530));
    }
}
}

extern "C" {

void fn_8025C188(s32 arg0);
s32 fn_8031CF54(void);
s32 fn_8031D0E8(s32, s32 *, s32 *);
void fn_8025C24C(void);

s32 fn_8025C8D0() {
    switch ((s32) (*(s32 *)((u8 *)(&lbl_80425110) + (0)))) { /* irregular */
    case 7:
        break;
    case 3:
        (*(s32 *)((u8 *)(&lbl_80425110) + (4))) = fn_8031D0E8((s32)((*(s32 *)((u8 *)(&lbl_80425110) + (0x24)))), (s32 *)(&fn_8025C24C), (s32 *)(&lbl_80425110));
        ((s32 (*)(void))fn_8025C188)();
        if ((s32) (*(s32 *)((u8 *)(&lbl_80425110) + (4))) >= 0) {
            (*(s32 *)((u8 *)(&lbl_80425110) + (0))) = 4;
        } else {
            (*(s32 *)((u8 *)(&lbl_80425110) + (0))) = 1;
        }
        break;
    case 4:
        if (fn_8031CF54() == 0) {
            (*(s32 *)((u8 *)(&lbl_80425110) + (0))) = 1;
        }
        break;
    case 5:
        (*(s32 *)((u8 *)(&lbl_80425110) + (4))) = fn_8031D0E8((s32)((*(s32 *)((u8 *)(&lbl_80425110) + (0x24)))), (s32 *)(&fn_8025C24C), (s32 *)(&lbl_80425110));
        ((s32 (*)(void))fn_8025C188)();
        if ((s32) (*(s32 *)((u8 *)(&lbl_80425110) + (4))) >= 0) {
            (*(s32 *)((u8 *)(&lbl_80425110) + (0))) = 6;
        } else {
            (*(s32 *)((u8 *)(&lbl_80425110) + (0))) = 1;
        }
        break;
    case 6:
        if (fn_8031CF54() == 0) {
            (*(s32 *)((u8 *)(&lbl_80425110) + (0))) = 1;
        }
        break;
    }
    return (*(s32 *)((u8 *)(&lbl_80425110) + (0)));
}
}

extern "C" {

s32 fn_8025D7CC(s32, s32, s32);

void fn_8025CFF0(s32 arg0) {
    fn_8025D7CC(arg0 + 0x6030, arg0, 0x6000);
}
}

extern "C" {

s32 fn_8031D280(s32);

void fn_8025C9EC() {
    if ((s32) (*(s32 *)((u8 *)(&lbl_80425110) + (4))) >= 0) {
        fn_8031D280((*(s32 *)((u8 *)(&lbl_80425110) + (4))));
    }
    (*(s32 *)((u8 *)(&lbl_80425110) + (0))) = 0;
}
}

extern "C" {

void OSReport(const s8 *, ...);
s32 fn_802F5364(void);
s32 fn_802F5894(void);
__declspec(section ".data") extern s32 lbl_804250F0;
__declspec(section ".data") extern s32 lbl_804250FC;
extern u8 lbl_8063D9D8;

void fn_8025BEB4() {
    OSReport((const s8 *)(&lbl_804250FC));
    fn_802F5894();
    OSReport((const s8 *)(&lbl_804250F0));
    fn_802F5364();
    OSReport((const s8 *)(&lbl_8063D9D8));
}
}

extern "C" {

s32 fn_8025BB50(s32);

void fn_8025B72C(s32 arg0, s32 arg1) {
    (*(s32 (*(*))())&lbl_8063F95C)();
    fn_8025BB50(arg1);
}
}

extern "C" {

void fn_8025B7FC(s32 arg0, s32 arg1) {
    (*(s32 (*(*))())&lbl_8063F958)();
    fn_8025BB50((s32)(arg1));
}
}

extern "C" {

void fn_8025C188(s32 arg0) {
    switch (arg0) {
    case 0:
        (*(s32 *)((u8 *)(&(*(s32 (*))&lbl_80425110)) + (8))) = 0;
        return;
    case -6:
        (*(s32 *)((u8 *)(&(*(s32 (*))&lbl_80425110)) + (8))) = 1;
        return;
    case -5:
        (*(s32 *)((u8 *)(&(*(s32 (*))&lbl_80425110)) + (8))) = 2;
        return;
    case -4:
        (*(s32 *)((u8 *)(&(*(s32 (*))&lbl_80425110)) + (8))) = 3;
        return;
    case -3:
        (*(s32 *)((u8 *)(&(*(s32 (*))&lbl_80425110)) + (8))) = 4;
        return;
    case -2:
        (*(s32 *)((u8 *)(&(*(s32 (*))&lbl_80425110)) + (8))) = 5;
        return;
    case -1:
        (*(s32 *)((u8 *)(&(*(s32 (*))&lbl_80425110)) + (8))) = 6;
        return;
    default:
        (*(s32 *)((u8 *)(&(*(s32 (*))&lbl_80425110)) + (8))) = 0;
        return;
    }
}
}

extern "C" {

s32 fn_8025CC48() {
    switch ((s32) (*(s32 (*))&lbl_80502548)) {                   /* irregular */
    case 1:
        return 1;
    case 3:
        (*(s32 (*))&lbl_80502548) = 1;
        return 1;
    default:
    case 2:
        return 0;
    }
}
}

extern "C" {

s32 fn_8025D3B8(s32, s32, s32);

void fn_8025CF9C(u8 *arg0) {
    s32 temp_r31;

    temp_r31 = (*(s32 *)((u8 *)(arg0) + (0x6050)));
    fn_8025D3B8((s32) (arg0 + 0x6000), temp_r31, 0x7000);
    fn_8025D7CC((s32)((s32) (arg0 + 0x6010)), (s32)(temp_r31 + 0x7000), (s32)(0x1000));
}
}

extern "C" {

s32 fn_8025D800(s32);

s32 fn_8025D2CC(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x6058))) != 0) {
        return fn_8025D800((s32) (arg0 + 0x6010));
    }
    return 0;
}
}

extern "C" {

struct S_lbl_80502548 { s32 f_0; s32 f_4; s32 f_8; s32 f_C; };

void fn_8025CAA8(s32 arg0, s32 arg1) {
    (*(struct S_lbl_80502548 (*))&lbl_80502548).f_0 = 1;
    (*(struct S_lbl_80502548 (*))&lbl_80502548).f_4 = 0;
    (*(struct S_lbl_80502548 (*))&lbl_80502548).f_C = arg1;
    (*(struct S_lbl_80502548 (*))&lbl_80502548).f_8 = arg0;
}
}

extern "C" {

s32 fn_8031C550(void);
__declspec(section ".data") extern s32 lbl_80425268;

s32 fn_8025CDD4(u32 arg0) {
    s32 var_r31;

    ((s32 (*)(u8 *, ...))OSReport)((u8 *)(u8 *)&lbl_80425268 + 0x7C, arg0);
    switch (arg0) {
    case 0:
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 9:
    case 10:
    case 14:
    case 20:
    case 21:
    case 22:
    case 23:
    case 32:
        var_r31 = -2;
        break;
    case 2:
    case 8:
    case 25:
        var_r31 = -2;
        break;
    case 11:
        ((s32 (*)(u8 *, ...))OSReport)((u8 *)(u8 *)&lbl_80425268 + 0x98);
        var_r31 = -3;
        break;
    case 12:
    case 13:
        ((s32 (*)(u8 *, ...))OSReport)((u8 *)(u8 *)&lbl_80425268 + 0xB8);
        var_r31 = -3;
        break;
    case 16:
    case 17:
    case 18:
    case 19:
    case 26:
    case 27:
    case 28:
    case 29:
    case 31:
        ((s32 (*)(u8 *, ...))OSReport)((u8 *)(u8 *)&lbl_80425268 + 0xD8);
        var_r31 = -1;
        break;
    case 15:
    case 30:
        ((s32 (*)(u8 *, ...))OSReport)((u8 *)(u8 *)&lbl_80425268 + 0x120);
        var_r31 = -1;
        break;
    default:
        var_r31 = -2;
        break;
    }
    if (var_r31 != -2) {
        fn_8031C550();
    }
    return var_r31;
}
}

extern "C" {

s32 fn_8025D2E8(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x6058))) != 0) {
        return ((s32 (*)(u8 *))fn_8025DBA0)(arg0 + 0x6010);
    }
    return 0;
}
}

extern "C" {

s32 fn_8025D60C(u8 *);

void fn_8025D304(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x6058))) != 0) {
        fn_8025D60C(arg0 + 0x6000);
    }
}
}
