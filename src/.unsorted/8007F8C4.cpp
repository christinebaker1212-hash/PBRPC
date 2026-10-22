#include ".unsorted/8007F8C4.hpp"

#include "common.hpp"

extern "C" {

void fn_80089C20(void) {}
}

extern "C" {

s32 fn_8007F8C4(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 1:
        return 1;
    case 2:
        return 2;
    case 4:
        return 6;
    default:
    case 3:
        return 1;
    }
}
}

extern "C" {

s32 fn_80055D98__FUlUl(s32, s32);
s32 fn_80249890__6GSfsysFUl(s32);
s32 freeFsysCacheEntries__7GScacheFUl(s32);
s32 loadFsys__6GSfsysFUl(s32);
extern s32 lbl_8063ECD8;

void fn_800801D4(void) {
    loadFsys__6GSfsysFUl(0x408);
    lbl_8063ECD8 = fn_80055D98__FUlUl(0x408, 0x27971A00);
    fn_80249890__6GSfsysFUl(0x408);
    freeFsysCacheEntries__7GScacheFUl(0x408);
}
}

extern "C" {

s32 fn_8005A44C(void);
extern u8 *lbl_8063ED68;
extern u8 *sInstance__12GSmenuModule;

void fn_80089BE8(void) {
    s32 temp_r0;

    fn_8005A44C();
    temp_r0 = (*(s32 *)((u8 *)(lbl_8063ED68) + (0x18)));
    if (temp_r0 != 0) {
        (*(s32 *)((u8 *)(sInstance__12GSmenuModule) + (0x118))) = temp_r0;
    }
}
}

extern "C" {

void fn_8008A27C(void) {
    s32 temp_r0;

    temp_r0 = (*(s32 *)((u8 *)(lbl_8063ED68) + (0x18)));
    if (temp_r0 != 0) {
        (*(s32 *)((u8 *)(sInstance__12GSmenuModule) + (0x118))) = temp_r0;
    }
}
}
