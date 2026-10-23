#include ".unsorted/80049084.hpp"

#include "common.hpp"

extern "C" {

extern f32 lbl_806409D0;
void fn_8004911C();

void fn_800491F8(void) {}
void fn_8004927C(void) {}
void fn_800492AC(void) {}
void fn_80049334(void) {}
void fn_8004A75C(void) {}
void fn_8004A810(void) {
    fn_8004911C();
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
    fn_8004911C();
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
