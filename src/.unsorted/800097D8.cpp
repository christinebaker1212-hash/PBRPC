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
