#include ".unsorted/80049084.hpp"

#include "common.hpp"

extern "C" {

extern f32 lbl_806409D0;
void fn_8004911C(u8 *arg0);

void fn_800491F8(void) {}
void fn_8004927C(void) {}
void fn_800492AC(void) {}
void fn_80049334(void) {}
void fn_8004A75C(void) {}
void fn_8004A810(void) {
    ((void (*)(void))fn_8004911C)();
}
f32 fn_8004A814(void) {
    return lbl_806409D0;
}
void fn_8004A81C(void) {}
void fn_8004A98C(void) {}
void fn_8004A990(void) {}
void fn_8004AA60(void) {}
void fn_8004AB8C(void) {}
void fn_8004AC40(void) {
    ((void (*)(void))fn_8004911C)();
}
f32 fn_8004AC44(void) {
    return lbl_806409D0;
}
void fn_8004AC4C(void) {}
void fn_8004ACCC(void) {}
void fn_8004ACD0(void) {}
}

extern "C" {

extern f32 lbl_806409D0;

f32 fn_800491FC(u8 *arg0) {
    u8 *temp_r3;

    temp_r3 = (*(u8 **)((u8 *)(arg0) + (0x14)));
    if (temp_r3 == NULL) {
        return lbl_806409D0;
    }
    return (*(f32 *)((u8 *)(temp_r3) + (4)));
}
}

extern "C" {

s32 fn_80033088__Fv(void);
s32 fn_80033B7C__FP11Unk80033090Ul(s32, s32);
s32 fn_80035AB8__FP11Unk80035380(s32);
s32 fn_8004A320(s32);
s32 fn_801F5814(s32);

s32 fn_8004A320(s32 arg0) {
    s32 temp_r0;
    s32 temp_r31;
    s32 var_r3;

    var_r3 = fn_80033088__Fv();
    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x30)));
    temp_r31 = var_r3;
    if (temp_r0 != 0) {
        fn_801F5814(temp_r0);
        var_r3 = (*(s32 *)((u8 *)(arg0) + (0x30)));
        (*(u16 *)((u8 *)(var_r3) + (0xDC))) = (u16) ((*(u16 *)((u8 *)(var_r3) + (0xDC))) & 0xFFFE);
    }
    if (((s32) (*(u8 *)((u8 *)(arg0) + (0x38))) != 0) && (temp_r31 != 0)) {
        var_r3 = fn_80033B7C__FP11Unk80033090Ul(temp_r31, (s32) (u16) (*(s32 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x18)))) + (0x20))));
        if (var_r3 != 0) {
            var_r3 = fn_80035AB8__FP11Unk80035380(var_r3);
        }
    }
    return var_r3;
}
}

extern "C" {

s32 allocFromHeap__5GSmemFP12MEMiHeapHeadUl(s32, s32);
s32 fn_8004A4DC(s32, s32);
s32 fn_801F98EC(s32, s32);
s32 isInitialized__5GSmemFv(void);
extern s32 gGameHeap;

s32 fn_8004A4DC(s32 arg0, s32 arg1) {
    s32 var_r3;

    if (isInitialized__5GSmemFv() != 0) {
        var_r3 = allocFromHeap__5GSmemFP12MEMiHeapHeadUl(gGameHeap, 0x140);
    } else {
        var_r3 = 0;
    }
    if (var_r3 != 0) {
        var_r3 = fn_801F98EC(var_r3, (*(s32 *)((u8 *)(arg1) + (0x44))));
    }
    (*(s32 *)((u8 *)(arg0) + (0x2C))) = var_r3;
    return var_r3;
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8040A6E8;

void fn_80049084(u8 *arg0) {
    (*(f32 *)((u8 *)(arg0) + (0xC))) = (f32) lbl_806409D0;
    (*(s32 **)((u8 *)(arg0) + (0x28))) = &lbl_8040A6E8;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x24))) = 0;
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8040A698;

u8 *fn_80049488(u8 *arg0) {
    ((s32 (*)(void))fn_80049084)();
    (*(s8 *)((u8 *)(arg0) + (0x38))) = 0;
    (*(s32 **)((u8 *)(arg0) + (0x28))) = &lbl_8040A698;
    return arg0;
}
}

extern "C" {

s32 __dt__7GSsceneFv(s32, s32);

void fn_80049540(u8 *arg0) {
    s32 temp_r0;

    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x2C)));
    if (temp_r0 != 0) {
        __dt__7GSsceneFv(temp_r0, 1);
        (*(s32 *)((u8 *)(arg0) + (0x2C))) = 0;
        (*(s32 *)((u8 *)(arg0) + (0x30))) = 0;
    }
    ((s32 (*)(u8 *))fn_8004911C)(arg0);
}
}

extern "C" {

extern f32 lbl_806409D4;

f32 fn_80049864(u8 *arg0) {
    u8 *var_r3_2;
    u8 *var_r3;
    u8 *temp_r4;
    u8 *temp_r3_2;
    u8 *temp_r3;
    u8 **temp_r5;
    f32 var_f1;

    temp_r4 = (*(u8 **)((u8 *)(arg0) + (0x14)));
    if (temp_r4 == NULL) {
        return lbl_806409D0;
    }
    var_f1 = (*(f32 *)((u8 *)(temp_r4) + (4)));
    if (lbl_806409D0 == var_f1) {
        temp_r3 = (*(u8 **)((u8 *)(arg0) + (0x2C)));
        if (temp_r3 != NULL) {
            temp_r5 = (*(u8 ***)((u8 *)(temp_r3) + (4)));
            if (temp_r5 == NULL) {
                var_r3 = NULL;
            } else if ((s32) (*(u16 *)((u8 *)((*(u8 **)((u8 *)(temp_r3) + (0)))) + (0x18))) == 0) {
                var_r3 = NULL;
            } else {
                var_r3 = *temp_r5;
            }
            if (var_r3 != NULL) {
                temp_r3_2 = (*(u8 **)((u8 *)(var_r3) + (4)));
                if (temp_r3_2 == NULL) {
                    var_r3_2 = NULL;
                } else if ((s32) (*(u16 *)((u8 *)(temp_r3_2) + (8))) == 0) {
                    var_r3_2 = NULL;
                } else {
                    var_r3_2 = (*(u8 **)((u8 *)(temp_r3_2) + (0xC)));
                }
                if (var_r3_2 != NULL) {
                    var_f1 = (*(f32 *)((u8 *)(var_r3_2) + (0xC)));
                }
            }
        }
    }
    if ((*(s32 *)((u8 *)(temp_r4) + (0x38))) & 2) {
        return lbl_806409D4;
    }
    return var_f1;
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8040A648;

u8 *fn_8004A3CC(u8 *arg0) {
    ((s32 (*)(void))fn_80049084)();
    (*(s32 **)((u8 *)(arg0) + (0x28))) = &lbl_8040A648;
    return arg0;
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8040A5A8;

u8 *fn_8004A760(u8 *arg0) {
    ((s32 (*)(void))fn_80049084)();
    (*(s32 **)((u8 *)(arg0) + (0x28))) = &lbl_8040A5A8;
    return arg0;
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8040A5F8;

u8 *fn_8004A994(u8 *arg0) {
    ((s32 (*)(void))fn_80049084)();
    (*(s32 **)((u8 *)(arg0) + (0x28))) = &lbl_8040A5F8;
    return arg0;
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8040A558;

u8 *fn_8004AB90(u8 *arg0) {
    ((s32 (*)(void))fn_80049084)();
    (*(s32 **)((u8 *)(arg0) + (0x28))) = &lbl_8040A558;
    return arg0;
}
}

extern "C" {

s32 fn_800252EC(s32, s32, s32, s32, s32, s32, s32);
s32 fn_80037D2C(s32, s32);
s32 fn_8003D4B4(s32);
s32 fn_8003D4CC(s32);
s32 fn_8003D80C(s32);
s32 fn_8003D824(s32);
s32 fn_800482AC(s32);
__declspec(section ".data") extern s32 lbl_8040A508;
extern s32 lbl_8063E9B0;

void fn_8004A820(u8 *arg0) {
    u8 *temp_r5;
    u8 *temp_r30;
    u32 temp_r7;
    s32 *temp_r3;
    s32 temp_r29;

    temp_r30 = (*(u8 **)((u8 *)(arg0) + (0x14)));
    temp_r5 = (*(u8 **)((u8 *)(arg0) + (0x18)));
    temp_r7 = (*(u32 *)((u8 *)(temp_r30) + (0x3C)));
    temp_r29 = lbl_8063E9B0;
    temp_r3 = (long *)((*(s32 *)((u8 *)(temp_r5) + (0x34))));
    switch (temp_r7) {
    case 0:
        if (temp_r3 != 0) {
            fn_8003D4CC((s32)(temp_r3));
        }
        break;
    case 1:
        if (temp_r3 != 0) {
            fn_8003D824((s32)(temp_r3));
        }
        break;
    case 2:
        if (temp_r3 != 0) {
            fn_80037D2C((s32)(temp_r3), (s32)(0));
        }
        break;
    case 3:
        if (temp_r3 != 0) {
            fn_80037D2C((s32)(temp_r3), (s32)(1));
        }
        break;
    case 5:
        if (temp_r3 != 0) {
            *temp_r3 = (s32) (*temp_r3 | 0x1000);
        }
        break;
    case 6:
        if (temp_r3 != 0) {
            *temp_r3 = (s32) (*temp_r3 & 0xFFFFEFFF);
        }
        break;
    case 7:
        if (temp_r3 != 0) {
            fn_8003D4B4((s32)(temp_r3));
        }
        break;
    case 9:
        if (temp_r3 != 0) {
            fn_8003D80C((s32)(temp_r3));
        }
        break;
    case 11:
        fn_800482AC((s32) temp_r5);
        break;
    case 10:
        if (temp_r29 != 0) {
            fn_800252EC(temp_r29, 0, (s32) &lbl_8040A508, 0, (s32) temp_r7, (*(s32 *)((u8 *)(temp_r30) + (0x40))), (*(s32 *)((u8 *)(temp_r30) + (0x44))));
            fn_800252EC(temp_r29, 2, (s32) &lbl_8040A508, 0, (s32) (*(u32 *)((u8 *)(temp_r30) + (0x3C))), (*(s32 *)((u8 *)(temp_r30) + (0x40))), (*(s32 *)((u8 *)(temp_r30) + (0x44))));
        }
        break;
    }
    (*(s32 *)((u8 *)(arg0) + (8))) = (s32) ((*(s32 *)((u8 *)(arg0) + (8))) | 2);
}
}

extern "C" {

void fn_8004911C(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = 0;
}
}

extern "C" {

s32 fn_80049918(s32, s32);

void fn_8004A3B0(u8 *arg0) {
    if (!(*(*(s32 **)((u8 *)(arg0) + (0x14))) & 4)) {
        fn_80049918((s32) arg0, 0);
    }
}
}

extern "C" {

s32 fn_801E4BCC(s32, s32);

void fn_8004AA44(u8 *arg0) {
    s32 temp_r3;

    temp_r3 = (*(s32 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x14)))) + (0x48)));
    if (temp_r3 != 0) {
        fn_801E4BCC(temp_r3, 0);
    }
}
}

extern "C" {

void fn_8004AB70(u8 *arg0) {
    s32 temp_r3;

    temp_r3 = (*(s32 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x14)))) + (0x48)));
    if (temp_r3 != 0) {
        fn_801E4BCC((s32)(temp_r3), (s32)(0));
    }
}
}

extern "C" {

struct VT_fn_80049218_0 { u8 pad[40];  virtual s32 v0(void); };
struct VT_fn_80049218_1 { u8 pad[40]; virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual f32 v7(void); };

void fn_80049218(u8 *arg0, s32 arg1) {
    s32 temp_r4;

    temp_r4 = (*(s32 *)((u8 *)(arg0) + (8)));
    if (!(temp_r4 & 1)) {
        (*(s32 *)((u8 *)(arg0) + (8))) = (s32) (temp_r4 | 1);
        ((VT_fn_80049218_0 *)(arg0))->v0();
        (*(f32 *)((u8 *)(arg0) + (0x10))) = ((VT_fn_80049218_1 *)(arg0))->v7();
    }
}
}

extern "C" {

struct VT_fn_80049280_0 { u8 pad[40]; virtual void v0(); virtual s32 v1(void); };

void fn_80049280(u8 *arg0) {
    s32 temp_r4;

    temp_r4 = (*(s32 *)((u8 *)(arg0) + (8)));
    if (temp_r4 & 1) {
        (*(s32 *)((u8 *)(arg0) + (8))) = (s32) ((temp_r4 & 0xFFFFFFFE) | 2);
        ((VT_fn_80049280_0 *)(arg0))->v1();
    }
}
}

extern "C" {

struct VT_fn_8004A47C_0 { u8 pad[256];  virtual s32 v0(s32); };

void fn_8004A47C(u8 *arg0) {
    u8 *temp_r0;

    temp_r0 = (*(u8 **)((u8 *)(arg0) + (0x2C)));
    if (!(temp_r0 == NULL)) {
        if (!(temp_r0 == NULL)) {
            ((VT_fn_8004A47C_0 *)(temp_r0))->v0((s32)(1));
        }
        (*(u8 **)((u8 *)(arg0) + (0x2C))) = NULL;
    }
    ((s32 (*)(s32))fn_8004911C)((s32) arg0);
}
}

extern "C" {

s32 unattachChild__6GSnullFP6GSnull(s32, s32);

void fn_8004A724(u8 *arg0) {
    s32 temp_r3;
    u8 *temp_r4;
    u8 *temp_r4_2;

    temp_r4 = (*(u8 **)((u8 *)(arg0) + (0x2C)));
    if (temp_r4 != NULL) {
        (*(s32 *)((u8 *)(temp_r4) + (0x104))) = (s32) ((*(s32 *)((u8 *)(temp_r4) + (0x104))) | 4);
        (*(f32 *)((u8 *)(temp_r4) + (0x110))) = (f32) (0.0f);
        temp_r4_2 = (*(u8 **)((u8 *)(arg0) + (0x2C)));
        temp_r3 = (*(s32 *)((u8 *)(temp_r4_2) + (0xC0)));
        if (temp_r3 != 0) {
            unattachChild__6GSnullFP6GSnull(temp_r3, (s32) temp_r4_2);
        }
    }
}
}

extern "C" {

s32 fn_8000B170__Fiif(s32, s32, f32);

void fn_8004AC50(u8 *arg0) {
    f32 var_f1;
    s32 temp_r3;
    u8 *temp_r4;

    temp_r4 = (*(u8 **)((u8 *)(arg0) + (0x14)));
    var_f1 = (f32) (*(s16 *)((u8 *)(temp_r4) + (0x44)));
    if ((0.0f) == var_f1) {
        var_f1 = (1.0f);
    }
    temp_r3 = (*(s32 *)((u8 *)(temp_r4) + (0x3C)));
    if (temp_r3 != 0) {
        fn_8000B170__Fiif(temp_r3, 0, var_f1);
    }
    (*(s32 *)((u8 *)(arg0) + (8))) = (s32) ((*(s32 *)((u8 *)(arg0) + (8))) | 2);
}
}
