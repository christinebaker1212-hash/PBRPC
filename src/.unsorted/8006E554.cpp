#include ".unsorted/8006E554.hpp"

#include "common.hpp"

extern "C" {

void fn_80058E34();
void fn_8007C3E0(s32 arg0);
void fn_801577C4();

BOOL fn_800728C4(void) {
    return lbl_8063D4D0->_00 == 3;
}
BOOL fn_80072908(void) {
    return lbl_8063D4D0->_04 == 2;
}
BOOL fn_80072944(void) {
    return lbl_8063D4D0->_14 == 2;
}
BOOL fn_80072CD8(void) {
    return lbl_8063D4D0->_08 == 2;
}
void fn_80073EA0(u32 i) {
    lbl_8063D4D0->_420[i] = -1;
}

void fn_800745D8(void) {}
void fn_800753F4(void) {}
void fn_8007B9F4(void) {}
void fn_8007BA80(void) {}
void fn_8007C290(void) {}
void fn_8007C3DC(void) {
    ((void (*)(void))fn_8007C3E0)();
}
void fn_8007C6D0(void) {
    fn_801577C4();
}
void fn_8007C80C(void) {
    fn_80058E34();
}
}

extern "C" {

s32 fn_80253CBC(u16);
extern u16 lbl_8063D4D4;

void fn_8006F134(void) {
    fn_80253CBC(lbl_8063D4D4);
}
}

extern "C" {

s32 fn_8007247C(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0x2ECF;
    case 1:
        return 0x2ED0;
    default:
        return 0;
    }
}
}

extern "C" {

s32 fn_800724AC(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0:
        return 0xE8D;
    case 1:
        return 0xE90;
    default:
        return 0;
    }
}
}

extern "C" {

s32 fn_80162A90(s32);

s32 fn_8007C6D4(void) {
    if ((fn_80162A90(9) == 0) && (fn_80162A90(0x19B) == 0)) {
        return 0;
    }
    if (fn_80162A90(0x19B) == 1U) {
        return 1;
    }
    return 2;
}
}

extern "C" {

s32 fn_8006F0EC();
s32 fn_80253E4C(s32, s32, s32);


}

extern "C" {

s32 fn_8006F6DC(void);
s32 fn_80155C18(s32, s32);
extern s32 lbl_8063EC70;

s32 fn_8006F6DC(void) {
    s32 var_r3;

    var_r3 = lbl_8063EC70;
    if (var_r3 != 0) {
        var_r3 = fn_80155C18(var_r3, 1);
        lbl_8063EC70 = 0;
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8007C22C(s32, s32);
s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_8007C22C(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    if (sp8 != 1) {
        return temp_r3;
    }
    return fn_80253EB4(arg0, arg1, 2, 0x5243);
}
}

extern "C" {

s32 fn_8007C734(s32, s32, s32, s32);
s32 fn_80162940(s32, s32, s32);

s32 fn_8007C734(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r3;

    if (arg3 != 0) {
        fn_80162940(arg0, 1, 1);
        return fn_80162940(arg1, 0, 1);
    }
    fn_80162940(arg0, 2, 1);
    fn_80162940(arg1, fn_80162A90((s32)(arg1)) + 1, 1);
    var_r3 = fn_80162A90((s32)(arg1));
    if ((u32) var_r3 == 2U) {
        var_r3 = fn_80162940(arg1, 0, 1);
        if (arg2 != 0) {
            var_r3 = fn_80162A90((s32)(arg2));
            if (var_r3 != 0) {
                var_r3 = fn_80162940(arg2, fn_80162A90((s32)(arg2)) - 1, 1);
            }
        }
    }
    return var_r3;
}
}

extern "C" {

s32 fn_80253CCC(s32);

void fn_8006F308() {
    if ((s16) (*(s16 *)((u8 *)(&lbl_8063D4D4) + (2))) != -1) {
        fn_80253CCC((s32) (u16) (*(s16 *)((u8 *)(&lbl_8063D4D4) + (2))));
        (*(s16 *)((u8 *)(&lbl_8063D4D4) + (2))) = -1;
    }
}
}

extern "C" {

u16 fn_80253DD0(s32);

s32 fn_8006F088() {
    s32 sp8;

    if ((s16) (*(s16 (*))&lbl_8063D4D4) == -1) {
        return 1;
    }
    if (fn_80253DD0((s32) (*(s16 (*))&lbl_8063D4D4)) == 3) {
        return 1;
    }
    fn_80253E4C((s32)((s32) (*(s16 (*))&lbl_8063D4D4)), (s32)(8), (s32)((s32) &sp8));
    return sp8 == 0;
}
}

extern "C" {

s32 fn_8006F0EC() {
    s32 sp8;

    if ((s16) (*(s16 (*))&lbl_8063D4D4) == -1) {
        return 1;
    }
    fn_80253E4C((s32)((s32) (*(s16 (*))&lbl_8063D4D4)), (s32)(8), (s32)((s32) &sp8));
    return sp8 == 0;
}
}

extern "C" {

s32 fn_80253DF0(s32, s32, s32);

void fn_80071CB4(s32 arg0) {
    s32 sp8;

    fn_80253E4C((s32)(arg0), (s32)(1), (s32)((s32) &sp8));
    switch (sp8) {
    case 0:
        if (fn_80253DD0((s32)(arg0)) == 3) {
            fn_80253DF0(arg0, 8, 0);
            fn_80253DF0(arg0, 1, 3);
            (*(s16 *)((u8 *)(&(*(u8 (*))&lbl_8063D4D4)) + (2))) = -1;
        }
    }
    return;
}
}

extern "C" {

s32 fn_80059A3C(s32, s32);
s32 fn_80253EDC(s32, s32, s32, s32);

void fn_8007A0CC(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC(arg0, arg1, 3, (s32) &sp8);
    switch (sp8) {                                  /* irregular */
    case 1:
        fn_80253EDC(arg0, arg1, 6, (s32) sp10);
        fn_80059A3C(1, (s32) sp10);
        return;
    case 2:
        fn_80253EDC(arg0, arg1, 6, (s32) sp10);
        fn_80059A3C(2, (s32) sp10);
        return;
    }
}
}

extern "C" {

s32 fn_8015F748(void);

void fn_8007A400(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;
    s32 var_r31;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* switch 1 */
    case 5:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F08));
        return;
    case 9:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F2D));
        return;
    case 8:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F2E));
        return;
    case 7:                                         /* switch 1 */
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x2F2F));
        return;
    case 3:                                         /* switch 1 */
        var_r31 = 0;
        temp_r3 = fn_8015F748();
        switch (temp_r3) {                          /* switch 2; irregular */
        case 0:                                     /* switch 2 */
            var_r31 = 0x2F29;
            break;
        case 1:                                     /* switch 2 */
            var_r31 = 0x2F2A;
            break;
        case 2:                                     /* switch 2 */
            var_r31 = 0x2F2B;
            break;
        case 3:                                     /* switch 2 */
            var_r31 = 0x2F2C;
            break;
        }
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(var_r31));
        /* fallthrough */
    default:                                        /* switch 1 */
        return;
    }
}
}

extern "C" {

void fn_8007AA34(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 4:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(1), (s32)((s32) sp10));
        return;
    case 3:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(2), (s32)((s32) sp10));
        return;
    case 2:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(3), (s32)((s32) sp10));
        return;
    case 1:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(4), (s32)((s32) sp10));
        return;
    }
}
}

extern "C" {

void fn_8007AC24(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 3:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(1), (s32)((s32) sp10));
        return;
    case 2:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(2), (s32)((s32) sp10));
        return;
    case 1:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(3), (s32)((s32) sp10));
        return;
    }
}
}

extern "C" {

void fn_8007C33C(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 0:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(1), (s32)((s32) sp10));
        return;
    case 1:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(2), (s32)((s32) sp10));
        return;
    }
}
}

extern "C" {

s32 fn_8011C974(void);

void fn_8007C3E0(s32 arg0) {
    s32 temp_r4;
    u8 *temp_r3;

    temp_r3 = (unsigned char *)(fn_8011C974());
    temp_r4 = (*(s32 *)((u8 *)(temp_r3) + (0x10)));
    switch (temp_r4) {
    case 0x3E8:
        if ((s32) (*(u8 *)((u8 *)(temp_r3) + (0x14))) == 0) {
            fn_8007C734((s32)(0x23), (s32)(0x19C), (s32)(0x3D), (s32)(arg0));
            return;
        }
        fn_8007C734((s32)(0x1B1), (s32)(0x19D), (s32)(0x3E), (s32)(arg0));
        return;
    case 0x3E9:
        if ((u16) (*(u16 *)((u8 *)(temp_r3) + (0x9A))) == 1) {
            fn_8007C734((s32)(0x24), (s32)(0x19E), (s32)(0x3F), (s32)(arg0));
            return;
        }
        fn_8007C734((s32)(0x1B2), (s32)(0x19F), (s32)(0x40), (s32)(arg0));
        return;
    case 0x3EA:
        if ((u16) (*(u16 *)((u8 *)(temp_r3) + (0x9A))) == 1) {
            fn_8007C734((s32)(0x25), (s32)(0x1A0), (s32)(0x41), (s32)(arg0));
            return;
        }
        fn_8007C734((s32)(0x1B3), (s32)(0x1A1), (s32)(0x42), (s32)(arg0));
        return;
    case 0x3EB:
        if ((u16) (*(u16 *)((u8 *)(temp_r3) + (0x9A))) == 1) {
            fn_8007C734((s32)(0x26), (s32)(0x1A2), (s32)(0x43), (s32)(arg0));
            return;
        }
        fn_8007C734((s32)(0x1B4), (s32)(0x1A3), (s32)(0x44), (s32)(arg0));
        return;
    case 0x3EC:
        if ((u16) (*(u16 *)((u8 *)(temp_r3) + (0x9A))) == 1) {
            fn_8007C734((s32)(0x27), (s32)(0x1A4), (s32)(0x45), (s32)(arg0));
            return;
        }
        fn_8007C734((s32)(0x1B5), (s32)(0x1A5), (s32)(0x46), (s32)(arg0));
        return;
    case 0x3ED:
        if ((u8) (*(u8 *)((u8 *)(temp_r3) + (0x14))) == 6) {
            if ((u16) (*(u16 *)((u8 *)(temp_r3) + (0x9A))) == 1) {
                fn_8007C734((s32)(0x28), (s32)(0x1A6), (s32)(0x47), (s32)(arg0));
                return;
            }
            fn_8007C734((s32)(0x1B6), (s32)(0x1A7), (s32)(0x48), (s32)(arg0));
            return;
        }
        fn_8007C734((s32)(0x1B7), (s32)(0x1A8), (s32)(0x49), (s32)(arg0));
        return;
    case 0x3EE:
        if ((u16) (*(u16 *)((u8 *)(temp_r3) + (0x9A))) == 1) {
            fn_8007C734((s32)(0x29), (s32)(0x1A9), (s32)(0x4A), (s32)(arg0));
            return;
        }
        fn_8007C734((s32)(0x1B8), (s32)(0x1AA), (s32)(0x4B), (s32)(arg0));
        return;
    case 0x3EF:
        if ((u8) (*(u8 *)((u8 *)(temp_r3) + (0x14))) == 0xA) {
            if ((u16) (*(u16 *)((u8 *)(temp_r3) + (0x9A))) == 1) {
                fn_8007C734((s32)(0x2A), (s32)(0x1AB), (s32)(0x4C), (s32)(arg0));
                return;
            }
            fn_8007C734((s32)(0x1B9), (s32)(0x1AC), (s32)(0x4D), (s32)(arg0));
            return;
        }
        fn_80162940((s32)(0x1BA), (s32)(1), (s32)(1));
        return;
    case 0x3F0:
        if ((u16) (*(u16 *)((u8 *)(temp_r3) + (0x9A))) == 1) {
            fn_8007C734((s32)(0x2B), (s32)(0x1AD), (s32)(0x4E), (s32)(arg0));
            return;
        }
        fn_8007C734((s32)(0x1BB), (s32)(0x1AE), (s32)(0x4F), (s32)(arg0));
        return;
    case 0x3F1:
        if (fn_80162A90((s32)(0x39)) == 0) {
            fn_8007C734((s32)(0x2C), (s32)(0x1AF), (s32)(0), (s32)(arg0));
            return;
        }
        fn_8007C734((s32)(0x1BC), (s32)(0x1B0), (s32)(0x50), (s32)(arg0));
    default:
        return;
    }
}
}
