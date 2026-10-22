#include ".unsorted/80131CF0.hpp"

#include "common.hpp"

extern "C" {

BOOL fn_80131FC4(void) {
    return lbl_8063D568->_70 == 0;
}
}

extern "C" {

u8 *fn_8011C974(void);
s32 fn_80162940(s32, s32, s32);

void fn_801332E8(s32 arg0) {
    if ((s32) (*(s32 *)((u8 *)(fn_8011C974()) + (0xC))) == 0) {
        fn_80162940(0x199, arg0, 1);
        return;
    }
    fn_80162940(0x199, 0, 1);
}
}

extern "C" {

s32 fn_8015C308(s32, s32);
u32 fn_80162A90(s32);
s32 fn_802502F4(s32);

s32 fn_8013A51C(void) {
    if (fn_80162A90(0x24B) == 1U) {
        fn_80162940(0x24B, 2, 1);
        fn_8015C308(0xE, fn_802502F4(0x29C8));
        return 0x4607;
    }
    if (fn_80162A90(0x24C) == 1U) {
        fn_80162940(0x24C, 2, 1);
        fn_8015C308(0xE, fn_802502F4(0x29C9));
        fn_8015C308(0xF, fn_802502F4(0x29CA));
        return 0x4608;
    }
    if (fn_80162A90(0x24D) == 1U) {
        fn_80162940(0x24D, 2, 1);
        fn_8015C308(0xE, fn_802502F4(0x29CB));
        return 0x4607;
    }
    if (fn_80162A90(0x24E) == 1U) {
        fn_80162940(0x24E, 2, 1);
        fn_8015C308(0xE, fn_802502F4(0x29CC));
        fn_8015C308(0xF, fn_802502F4(0x29CD));
        return 0x4608;
    }
    if (fn_80162A90(0x24F) == 1U) {
        fn_80162940(0x24F, 2, 1);
        fn_8015C308(0xE, fn_802502F4(0x29CE));
        return 0x4607;
    }
    if (fn_80162A90(0x250) == 1U) {
        fn_80162940(0x250, 2, 1);
        fn_8015C308(0xE, fn_802502F4(0x29CF));
        return 0x4607;
    }
    return 0;
}
}
