#include ".unsorted/800097D8.hpp"

#include "common.hpp"

extern "C" {

/* lbl_8063E930 */ extern Unk800097D8 *lbl_8063E930;

// TODO name: returns the previous value of the flag at 0x03 and clears it
u8 fn_80009D78(Unk800097D8 *obj);
// TODO name: returns the previous value of the flag at 0x03 and sets it
u8 fn_80009D94(Unk800097D8 *obj);

u8 fn_800097D8(void) {
    if (lbl_8063E930 != NULL) {
        return fn_80009D78(lbl_8063E930);
    }
    return 1;
}

u8 fn_800097F0(void) {
    if (lbl_8063E930 != NULL) {
        return fn_80009D94(lbl_8063E930);
    }
    return 1;
}

void fn_80009808(u8 v) {
    if (lbl_8063E930 != NULL) {
        lbl_8063E930->_04 = v;
    }
}

u8 fn_8000981C(void) {
    if (lbl_8063E930 != NULL) {
        return lbl_8063E930->_04;
    }
    return 0;
}

u8 fn_80009838(void) {
    if (lbl_8063E930 != NULL) {
        return lbl_8063E930->_01;
    }
    return 0;
}

u8 fn_80009D78(Unk800097D8 *obj) {
    u8 flag = obj->_03;
    if (flag != 0) {
        obj->_03 = 0;
    }
    return flag;
}

u8 fn_80009D94(Unk800097D8 *obj) {
    u8 flag = obj->_03;
    if (flag == 0) {
        obj->_03 = 1;
    }
    return flag;
}

s32 fn_80009DB0(u32, u8 v) {
    if (lbl_8063E930 != NULL) {
        lbl_8063E930->_0D = v;
    }
    return 0;
}

void fn_8000A72C(Unk800097D8 *obj, u32 v) {
    obj->_D0 = v;
}
Unk800097D8 *fn_8000A734(void) {
    return lbl_8063E930;
}

void fn_8000A77C(void) {
    if (lbl_8063E930 != NULL) {
        fn_8000A0F0(lbl_8063E930);
    }
}

void fn_8000A790(void) {
    if (lbl_8063E930 != NULL) {
        fn_8000A54C(lbl_8063E930);
    }
}
}

extern "C" {

s32 GXClearVtxDesc(void);
s32 GXSetBlendMode(s32, s32, s32, s32);
s32 GXSetCurrentMtx(s32);
s32 GXSetNumChans(s32);
s32 GXSetNumTevStages(s32);
s32 GXSetNumTexGens(s32);
s32 GXSetTevOp(s32, s32);
s32 GXSetTevOrder(s32, s32, s32, s32);
s32 GXSetVtxAttrFmt(s32, s32, s32, s32, s32);
s32 GXSetVtxDesc(s32, s32);
s32 GXSetZMode(s32, s32, s32);

void fn_80009A78(void) {
    GXClearVtxDesc();
    GXSetVtxAttrFmt(4, 9, 0, 4, 0);
    GXSetVtxAttrFmt(4, 0xB, 0, 1, 0);
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetNumChans(1);
    GXSetNumTexGens(0);
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0xFF, 0xFF, 4);
    GXSetTevOp(0, 4);
    GXSetBlendMode(0, 0, 0, 0);
    GXSetZMode(1, 3, 1);
    GXSetCurrentMtx(3);
}
}

extern "C" {

s32 fn_80009854(void);
s32 fn_80162A90(s32);
s32 fn_80162B70(void);
extern s32 lbl_8063E904;
extern u8 *lbl_8063F640;

s32 fn_80009854(void) {
    if ((u8 *) lbl_8063E930 == NULL) {
        return 0;
    }
    if ((fn_80162B70() != 0) || (fn_80162A90(0x261) == 3U) || (fn_80162A90(0x261) == 4U) || ((s32) (*(u8 *)((u8 *)(lbl_8063E930) + (3))) != 0) || ((s32) (*(u8 *)((u8 *)(lbl_8063E930) + (4))) != 0) || (((u8 *) lbl_8063F640 != NULL) && ((s32) (*(u8 *)((u8 *)(lbl_8063F640) + (0x14))) != 0)) || ((s32) lbl_8063E904 != 0)) {
        return 0;
    }
    return 1;
}
}

extern "C" {

s32 C_MTXOrtho(s32, f32, f32, f32, f32, f32, f32);
s32 GXSetProjection(s32, s32);
extern f32 lbl_80640628;
extern f32 lbl_8064062C;
extern f32 lbl_80640630;
extern f32 lbl_80640634;
extern f32 lbl_80640638;
extern f32 lbl_8064063C;
extern f32 lbl_80640640;
extern f32 lbl_80640644;

void fn_800099EC(s32 arg0, s32 arg1) {
    s32 sp8[18];

    if (arg1 != 0) {
        C_MTXOrtho((s32) sp8, lbl_80640628, lbl_8064062C, lbl_80640630, lbl_80640634, lbl_80640638, lbl_8064063C);
    } else {
        C_MTXOrtho((s32) sp8, lbl_80640628, lbl_8064062C, lbl_80640640, lbl_80640644, lbl_80640638, lbl_8064063C);
    }
    GXSetProjection((s32) sp8, 1);
}
}

extern "C" {

s32 HBMCreateSound(s32, s32, s32);
s32 allocFromHeapAndClear__5GSmemFP12MEMiHeapHeadUl(s32, s32);
s32 strcat(s32, s32);
s32 strcpy(s32, s32);
extern s32 gUnkHeap2;
__declspec(section ".data") extern s8 lbl_803FB728;
__declspec(section ".data") extern s8 lbl_80405E80;

void fn_8000A008(s32 arg0) {
    s8 sp8[40];

    strcpy((s32)(sp8), (s32)(&lbl_803FB728));
    strcat((s32)(sp8), (s32)(&lbl_80405E80));
    HBMCreateSound((s32) sp8, allocFromHeapAndClear__5GSmemFP12MEMiHeapHeadUl(gUnkHeap2, 0x80000), 0x80000);
}
}

extern "C" {

s32 __nw__FUl(s32);
u8 *fn_8000994C(u8 *arg0);
void fn_8000A060(u8 *arg0);

void fn_8000A73C() {
    s32 var_r3;

    var_r3 = __nw__FUl(0xD4);
    if (var_r3 != 0) {
        var_r3 = ((s32)fn_8000994C((u8 *)(var_r3)));
    }
    (*(s32 (*))&lbl_8063E930) = var_r3;
    if (var_r3 != 0) {
        fn_8000A060((u8 *)(var_r3));
    }
}
}

extern "C" {

void fn_80009DC8(u8 *arg0);
s32 memset(s32, s32, s32);

u8 *fn_8000994C(u8 *arg0) {
    (*(s8 *)((u8 *)(arg0) + (3))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0))) = 0;
    (*(s8 *)((u8 *)(arg0) + (4))) = 0;
    (*(s8 *)((u8 *)(arg0) + (1))) = 0;
    (*(s8 *)((u8 *)(arg0) + (2))) = 0;
    (*(s8 *)((u8 *)(arg0) + (5))) = 0;
    (*(s8 *)((u8 *)(arg0) + (6))) = 0;
    (*(s8 *)((u8 *)(arg0) + (8))) = 1;
    (*(s8 *)((u8 *)(arg0) + (7))) = 0;
    (*(f32 *)((u8 *)(arg0) + (0x18))) = (f32) (1.0f);
    (*(s8 *)((u8 *)(arg0) + (0xD))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0xE))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x14))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0xC))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xD0))) = 0;
    memset((s32)(arg0 + 0x20), (s32)(0), (s32)(0x40U));
    memset((s32)(arg0 + 0x60), (s32)(0), (s32)(0x40U));
    fn_80009DC8((u8 *)((s32) arg0));
    return arg0;
}
}

extern "C" {

void fn_80009DC8(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0x6C))) = 0;
    (*(f32 *)((u8 *)(arg0) + (0x64))) = (f32) (0.0f);
    (*(f32 *)((u8 *)(arg0) + (0x68))) = (f32) (0.0f);
    (*(f32 *)((u8 *)(arg0) + (0x74))) = (f32) (0.0f);
    (*(f32 *)((u8 *)(arg0) + (0x78))) = (f32) (0.0f);
    (*(s32 *)((u8 *)(arg0) + (0x7C))) = 0;
    (*(f32 *)((u8 *)(arg0) + (0x84))) = (f32) (0.0f);
    (*(f32 *)((u8 *)(arg0) + (0x88))) = (f32) (0.0f);
    (*(s32 *)((u8 *)(arg0) + (0x8C))) = 0;
    (*(f32 *)((u8 *)(arg0) + (0x94))) = (f32) (0.0f);
    (*(f32 *)((u8 *)(arg0) + (0x98))) = (f32) (0.0f);
    (*(s32 *)((u8 *)(arg0) + (0x9C))) = 0;
}
}

extern "C" {

void HBMCreate(u8 *);
void HBMSetAdjustFlag(u32);
void MEMInitAllocatorForExpHeap(u8 *, s32, s32);
s32 fn_80009E04(s32, s32);
extern u8 *sInstance__8GSrender;

void fn_8000A060(u8 *arg0) {
    if ((s32) (*(u8 *)((u8 *)(sInstance__8GSrender) + (0x7A))) != 0) {
        (*(u8 *)((u8 *)(arg0) + (2))) = 1U;
    }
    fn_80009E04((s32) arg0, (s32) (arg0 + 0x20));
    MEMInitAllocatorForExpHeap(arg0 + 0xA0, gUnkHeap2, 0x20);
    (*(s32 *)((u8 *)(arg0) + (0x30))) = 0;
    (*(u8 **)((u8 *)(arg0) + (0x5C))) = (u8 *) (arg0 + 0xA0);
    (*(s32 *)((u8 *)(arg0) + (0x4C))) = 0;
    HBMCreate(arg0 + 0x20);
    ((s32 (*)(s32))fn_8000A008)((s32) arg0);
    HBMSetAdjustFlag((u32) (*(u8 *)((u8 *)(arg0) + (2))));
    (*(s8 *)((u8 *)(arg0) + (0))) = 1;
}
}
