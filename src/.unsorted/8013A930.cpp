#include ".unsorted/8013A930.hpp"

#include "common.hpp"

extern "C" {

u32 fn_8013B030(void) {
    return lbl_8063EFA8->_00;
}
u32 fn_8013B03C(void) {
    return lbl_8063EFA8->_684;
}

void fn_8013B2D8(u32 a, u32 b) {
    lbl_8063EFA8->_6DC = a;
    lbl_8063EFA8->_6D8 = b;
}

void fn_8013BF80(void) {}
void fn_8013CAF0(void) {}
}

extern "C" {

s32 fn_800599C8(s32, s32, s32, s32, s32, s32);

void fn_8013D004(s32 arg0) {
    if (arg0 != 0) {
        fn_800599C8(0xA, 0, 0, 1, 0, 0);
        fn_800599C8(1, 0, 0xA, 0, 2, 0);
        fn_800599C8(2, 1, 0xA, 0, 0x63, 0);
        fn_800599C8(0x63, 2, 0xA, 0, 0, 0);
        return;
    }
    fn_800599C8(1, 0, 0, 0, 2, 0);
    fn_800599C8(2, 1, 0, 0, 0x63, 0);
    fn_800599C8(0x63, 2, 0, 0, 0, 0);
}
}

extern "C" {

s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

void fn_8013C3AC(s32 arg0, s32 arg1) {
    s32 sp8;

    fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    switch (sp8) {                                  /* irregular */
    case 3:
        fn_80253EB4(arg0, arg1, 2, 0x43E4);
        return;
    case 7:
        fn_80253EB4(arg0, arg1, 2, 0x43E9);
        return;
    }
}
}

extern "C" {

void fn_8013C75C(s32 arg0, s32 arg1) {
    s32 sp8;

    fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 4:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x43ED));
        return;
    case 8:
        fn_80253EB4((s32)(arg0), (s32)(arg1), (s32)(2), (s32)(0x43EF));
        return;
    }
}
}

extern "C" {

s32 fn_80059A3C(s32, s32);
s32 fn_8005A9F8(s32);
s32 fn_80253EDC(s32, s32, s32, s32);
s32 fn_80253F04(s32, s32, s32, s32);
extern f32 lbl_806413E8;
extern f32 lbl_806413EC;

void fn_8013B478(s32 arg0, s32 arg1) {
    s32 sp30[10];
    f32 sp10[8];
    s32 sp8;

    fn_80253EDC(arg0, arg1, 3, (s32) &sp8);
    switch (sp8) {                                  /* irregular */
    case 0:
        fn_80253EDC(arg0, arg1, 6, (s32) sp30);
        fn_80059A3C(0x63, (s32) sp30);
        return;
    case 1:
        sp10[3] = lbl_806413E8;
        sp10[6] = lbl_806413E8;
        sp10[1] = lbl_806413E8;
        sp10[0] = lbl_806413E8;
        sp10[7] = lbl_806413EC;
        sp10[4] = lbl_806413EC;
        sp10[5] = lbl_806413EC;
        sp10[2] = lbl_806413EC;
        fn_80253F04(arg0, arg1, 2, fn_8005A9F8(0x1B));
        fn_80253F04(arg0, arg1, 1, (s32) sp10);
        return;
    }
}
}
