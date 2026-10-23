#include ".unsorted/8008D8CC.hpp"

#include "common.hpp"

extern "C" {

void fn_8008E4F0(void) {}
void fn_80090BC0(void) {}
}

extern "C" {

s32 fn_80090B94(s32, s32);
s32 fn_80253EDC(s32, s32, s32, s32);

s32 fn_80090B94(s32 arg0, s32 arg1) {
    s32 sp8;

    return fn_80253EDC((s32) (s16) arg0, arg1, 3, (s32) &sp8);
}
}

extern "C" {

s32 fn_80059A3C(s32, s32);
s32 fn_8015C4F4(s32, s32);
extern u8 lbl_8063ED0C;
extern u8 lbl_8063ED31;

void fn_8008E7A8(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C(1, (s32) sp10);
        break;
    case 0:                                         /* switch 1 */
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C(2, (s32) sp10);
        break;
    }
    if ((u8) lbl_8063ED31 == 1) {
        switch ((s32) lbl_8063ED0C) {               /* switch 2; irregular */
        case 1:                                     /* switch 2 */
            fn_8015C4F4(2, 0x2A44);
            return;
        case 2:                                     /* switch 2 */
            fn_8015C4F4(2, 0x2A45);
            return;
        case 3:                                     /* switch 2 */
            fn_8015C4F4(2, 0x2A57);
            break;
        }
    }
}
}

extern "C" {

s32 fn_80090C54(s32, s32, s32, s32, s32);
extern s32 lbl_8063ED90;

void fn_80090340(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 0x6:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(7), (s32)((s32) sp10));
        return;
    case 0x5C:
        fn_80090C54(arg0, arg1, lbl_8063ED90 + 0x3BB0, 0x52, 0x2AB8);
        return;
    case 0x5F:
        fn_80090C54(arg0, arg1, lbl_8063ED90 + 0x6C10, 0x51, 0x2AB7);
        return;
    case 0x62:
        fn_80090C54(arg0, arg1, lbl_8063ED90 + 0x72FC, 0x51, 0x2AB7);
        return;
    case 0x65:
        fn_80090C54(arg0, arg1, lbl_8063ED90 + 0x79E8, 0x51, 0x2AB7);
        return;
    case 0x68:
        fn_80090C54(arg0, arg1, lbl_8063ED90 + 0x80D4, 0x51, 0x2AB7);
        return;
    case 0x6B:
        fn_80090C54(arg0, arg1, lbl_8063ED90 + 0x87C0, 0x51, 0x2AB7);
        return;
    }
}
}

extern "C" {

void fn_80090588(s32 arg0, s32 arg1) {
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

void fn_80090628(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 3:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(0x21), (s32)((s32) sp10));
        return;
    case 4:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(0x22), (s32)((s32) sp10));
        return;
    }
}
}

extern "C" {

s32 fn_8005A9F8(s32);
s32 fn_80253F04(s32, s32, s32, s32);
extern f32 lbl_80640D88;
extern f32 lbl_80640D8C;

void fn_800906C8(s32 arg0, s32 arg1) {
    s32 sp30[10];
    f32 sp10[8];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 0:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp30));
        fn_80059A3C((s32)(0x1E), (s32)((s32) sp30));
        return;
    case 1:
        sp10[1] = lbl_80640D88;
        sp10[0] = lbl_80640D88;
        sp10[3] = lbl_80640D88;
        sp10[6] = lbl_80640D88;
        sp10[5] = lbl_80640D8C;
        sp10[2] = lbl_80640D8C;
        sp10[7] = lbl_80640D8C;
        sp10[4] = lbl_80640D8C;
        fn_80253F04(arg0, arg1, 2, fn_8005A9F8(0x1A));
        fn_80253F04(arg0, arg1, 1, (s32) sp10);
        return;
    }
}
}

extern "C" {

void fn_800907A0(s32 arg0, s32 arg1) {
    s32 sp30[10];
    f32 sp10[8];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 1:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp30));
        fn_80059A3C((s32)(0x1E), (s32)((s32) sp30));
        return;
    case 2:
        sp10[1] = lbl_80640D88;
        sp10[0] = lbl_80640D88;
        sp10[3] = lbl_80640D88;
        sp10[6] = lbl_80640D88;
        sp10[5] = lbl_80640D8C;
        sp10[2] = lbl_80640D8C;
        sp10[7] = lbl_80640D8C;
        sp10[4] = lbl_80640D8C;
        fn_80253F04((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(fn_8005A9F8((s32)(0x1A))));
        fn_80253F04((s32)(arg0), (s32)(arg1), (s32)(1), (s32)((s32) sp10));
        return;
    }
}
}
