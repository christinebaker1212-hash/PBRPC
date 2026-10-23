#include ".unsorted/8000748C.hpp"

#include "common.hpp"

extern "C" {

/* lbl_8063E918 */ extern Unk8000748C *lbl_8063E918;

void fn_800074C0(void) {
    if (lbl_8063E918 != NULL) {
        fn_8000764C(lbl_8063E918);
    }
}

void fn_800074D4(void) {
    if (lbl_8063E918 != NULL) {
        fn_800077C0(lbl_8063E918);
    }
}

void fn_800074E8(void) {
    if (lbl_8063E918 != NULL) {
        lbl_8063E918->_00 = 1;
    }
}

void fn_80007564(u8 v) {
    if (lbl_8063E918 != NULL) {
        lbl_8063E918->_01 = v;
    }
}

u32 fn_80007578(u32 v) {
    u32 old = 0;
    if (lbl_8063E918 != NULL) {
        old = lbl_8063E918->_10;
        lbl_8063E918->_10 = v;
    }
    return old;
}

void fn_800077C0(Unk8000748C *obj) {
    obj->_06 = 1;
}
}

extern "C" {

s32 fn_8000981C(void);
s32 fn_80162B70(void);
extern s32 lbl_8063E904;
extern u8 *lbl_8063F640;

s32 fn_800075D0(u8 *arg0) {
    if ((fn_8000981C() != 0) || (((u8 *) lbl_8063F640 != NULL) && ((s32) (*(u8 *)((u8 *)(lbl_8063F640) + (0x14))) != 0)) || ((s32) lbl_8063E904 != 0) || ((fn_80162B70() == 1) && ((s32) (*(u8 *)((u8 *)(arg0) + (6))) == 0))) {
        return 0;
    }
    return 1;
}
}

extern "C" {

s32 fn_80007524(s32, s32);

s32 fn_80007524(s32 arg0, s32 arg1) {
    u16 temp_r0;

    if ((u8 *) lbl_8063E918 != NULL) {
        temp_r0 = 1 << arg0;
        if (arg1 != 0) {
            (*(u16 *)((u8 *)(lbl_8063E918) + (0xC))) = (u16) ((*(u16 *)((u8 *)(lbl_8063E918) + (0xC))) | temp_r0);
            return (s32) temp_r0;
        }
        (*(u16 *)((u8 *)(lbl_8063E918) + (0xC))) = (u16) ((*(u16 *)((u8 *)(lbl_8063E918) + (0xC))) & ~temp_r0);
        return (s32) temp_r0;
    }
    return arg0;
}
}

extern "C" {

s32 __nw__FUl(s32);
s32 fn_80007598(void);

void fn_8000748C() {
    s32 var_r3;

    var_r3 = __nw__FUl(0x20);
    if (var_r3 != 0) {
        var_r3 = fn_80007598();
    }
    (*(s32 (*))&lbl_8063E918) = var_r3;
}
}

extern "C" {

s32 fn_80007890(s8 *, s32);

void fn_80007500() {
    if ((s8 *) (*(s8 *(*))&lbl_8063E918) != NULL) {
        *(*(s8 *(*))&lbl_8063E918) = 0;
        fn_80007890((*(s8 *(*))&lbl_8063E918), 1);
    }
}
}
