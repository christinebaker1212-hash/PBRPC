#include ".unsorted/800B9E10.hpp"

#include "common.hpp"

extern "C" {

Unk800B9E10 *fn_800BA550(void) {
    return lbl_8063EED8;
}

void fn_800BA558(u16 v) {
    if (lbl_8063EED8 == NULL) {
        return;
    }
    lbl_8063EED8->_0A = lbl_8063EED8->_08;
    lbl_8063EED8->_08 = v;
}

u16 fn_800BA578(void) {
    if (lbl_8063EED8 != NULL) {
        return lbl_8063EED8->_08;
    }
    return 0xFFFF;
}

u16 fn_800BA598(void) {
    if (lbl_8063EED8 != NULL) {
        return lbl_8063EED8->_0A;
    }
    return 0xFFFF;
}

void fn_800BA5B8(u16 v) {
    if (lbl_8063EED8 == NULL) {
        return;
    }
    lbl_8063EED8->_0C = v;
}

u16 fn_800BA5CC(void) {
    if (lbl_8063EED8 != NULL) {
        return lbl_8063EED8->_0C;
    }
    return 0xFFFF;
}

void fn_800BA5EC(s32 v) {
    if (lbl_8063EED8 == NULL) {
        return;
    }
    lbl_8063EED8->_10 = v;
}

s32 fn_800BA600(void) {
    if (lbl_8063EED8 != NULL) {
        return lbl_8063EED8->_10;
    }
    return -1;
}

void fn_800BA970(u16 i, u16 v) {
    if (lbl_8063EED8 == NULL) {
        return;
    }
    lbl_8063EED8->_14[i] = v;
}

void fn_800BA9B0(u16 i, u32 v) {
    if (lbl_8063EED8 == NULL) {
        return;
    }
    lbl_8063EED8->_54[i] = v;
}

void fn_800BA9F0(u16 i, u32 v) {
    if (lbl_8063EED8 == NULL) {
        return;
    }
    lbl_8063EED8->_28C[i] = v;
}

u8 fn_800BB9D4(s32 v) {
    return v / 6;
}

void fn_800C5940(void) {}
void fn_800C5944(void) {}
}

extern "C" {

s32 fn_800B9E40(void);

s32 fn_800B9E10(s32 arg0) {
    fn_800B9E40();
    return arg0;
}
}

extern "C" {

s32 fn_800BB9C8(s32 arg0, s32 arg1) {
    return arg0 + (arg1 * 6);
}
}

extern "C" {

u8 fn_800BB9F0(s32 arg0) {
    return (u8) (arg0 % 6);
}
}

extern "C" {

u16 fn_800BA578(void);
s32 fn_80253E10(s32, s32, f32);
extern f32 lbl_80640F78;
extern f32 lbl_80640FC0;
extern f32 lbl_80640FC4;

void fn_800C21DC(s32 arg0) {
    if (fn_800BA578() != 4) {
        fn_80253E10(arg0, 4, lbl_80640FC0);
    } else {
        fn_80253E10(arg0, 4, lbl_80640F78);
    }
    fn_80253E10(arg0, 5, lbl_80640FC4);
    fn_80253E10(arg0, 6, lbl_80640FC4);
}
}
