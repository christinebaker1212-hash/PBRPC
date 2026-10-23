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

extern "C" {

s32 __ct__7GSsceneFP11GSsceneData(s32, s32);
s32 __dl__FPv(s32);
s32 __dt__7GSsceneFv(s32, s32);
s32 allocFromHeap__5GSmemFP12MEMiHeapHeadUl(s32, s32);
s32 fn_80055E30__FPv(s32);
s32 fn_8007FA58(void);
s32 fn_80080D90(void);
s32 fn_800834E0(f32);
s32 fn_80089C24(s32, s32);
s32 fn_8008A124(s32);
s32 fn_801E34DC__FP11GSsceneDataUl(s32, s32);
s32 fn_801E37F0(s32);
s32 isInitialized__5GSmemFv(void);
extern s32 gGameHeap;
extern s32 lbl_8063ECDC;
extern u16 lbl_8063ECE2;
extern u8 *lbl_8063ED90;
extern f32 lbl_80640CF0;

s32 fn_8008A124(s32 arg0) {
    s32 temp_r3;
    s32 var_r3;

    switch (arg0) {                                 /* irregular */
    case 0:
        loadFsys__6GSfsysFUl(0x3EF);
        fn_8007FA58();
        if ((s32) (*(s32 *)((u8 *)(lbl_8063ED68) + (0x18))) == 0) {
            temp_r3 = fn_80055D98__FUlUl((s32)(0x3EF), (s32)(0x27510000));
            lbl_8063ECDC = temp_r3;
            fn_801E34DC__FP11GSsceneDataUl(temp_r3, temp_r3);
            if (isInitialized__5GSmemFv() != 0) {
                var_r3 = allocFromHeap__5GSmemFP12MEMiHeapHeadUl(gGameHeap, 0x14);
            } else {
                var_r3 = 0;
            }
            if (var_r3 != 0) {
                var_r3 = __ct__7GSsceneFP11GSsceneData(var_r3, temp_r3);
            }
            (*(s32 *)((u8 *)(lbl_8063ED68) + (0x18))) = var_r3;
        }
        fn_80089C24((s32) (*(u16 *)((u8 *)(lbl_8063ED90) + (0x3BCC))), 0);
        fn_80089C24((s32) (*(u16 *)((u8 *)(lbl_8063ED90) + (0x49A4))), 1);
        lbl_8063ECE2 = 0x74;
        return 1;
    case 1:
        fn_800834E0(lbl_80640CF0);
        return (lbl_8063ECE2 - 0x76) == 0;
    default:
        fn_80080D90();
        if ((s32) lbl_8063ECDC != 0) {
            fn_801E37F0(lbl_8063ECDC);
            __dt__7GSsceneFv((*(s32 *)((u8 *)(lbl_8063ED68) + (0x18))), 1);
            fn_80055E30__FPv(lbl_8063ECDC);
            lbl_8063ECDC = 0;
        }
        if ((u8 *) lbl_8063ED68 != NULL) {
            __dl__FPv((s32) lbl_8063ED68);
        }
        lbl_8063ED68 = NULL;
        fn_80249890__6GSfsysFUl(0x3EF);
        freeFsysCacheEntries__7GScacheFUl(0x3EF);
        return 1;
    }
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_8047A9C0;

void fn_8007FF20() {
    loadFsys__6GSfsysFUl((s32)(0x4CE));
    loadFsys__6GSfsysFUl((s32)(0x3EF));
    (*(s32 *)((u8 *)(&lbl_8047A9C0) + (0))) = fn_80055D98__FUlUl((s32)(0xE), (s32)(0x19A51A00));
    (*(s32 *)((u8 *)(&lbl_8047A9C0) + (4))) = fn_80055D98__FUlUl((s32)(0xE), (s32)(0x044B1A00));
    (*(s32 *)((u8 *)(&lbl_8047A9C0) + (8))) = fn_80055D98__FUlUl((s32)(0xE), (s32)(0x044E1A00));
    (*(s32 *)((u8 *)(&lbl_8047A9C0) + (0xC))) = fn_80055D98__FUlUl((s32)(0xE), (s32)(0x044C1A00));
    (*(s32 *)((u8 *)(&lbl_8047A9C0) + (0x10))) = fn_80055D98__FUlUl((s32)(0xE), (s32)(0x04501A00));
    (*(s32 *)((u8 *)(&lbl_8047A9C0) + (0x14))) = fn_80055D98__FUlUl((s32)(0xE), (s32)(0x206E1A00));
    (*(s32 *)((u8 *)(&lbl_8047A9C0) + (0x18))) = fn_80055D98__FUlUl((s32)(0xE), (s32)(0x1D571A00));
}
}

extern "C" {

s32 fn_8007FFFC(void);
s32 fn_800800E8(void);
s32 fn_8008029C(void);
s32 fn_80080658(void);
s32 fn_8011C974(void);
s32 fn_80162A90(s32);

void fn_80080B58() {
    s32 temp_r0;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r3;
    s32 var_r3_2;

    if (fn_80162A90(0x37) == 0) {
        fn_8007FA58();
        ((s32 (*)(void))fn_8007FF20)();
        fn_8007FFFC();
        fn_8008029C();
    }
    if (fn_80162A90(0x37) == 1U) {
        fn_8007FA58();
        ((s32 (*)(void))fn_8007FF20)();
        fn_8007FFFC();
        fn_8008029C();
    }
    if (fn_80162A90(0x37) == 3U) {
        fn_8007FA58();
        temp_r0 = (*(s32 *)((u8 *)(lbl_8063ED90) + (0x10)));
        switch (temp_r0) {                          /* irregular */
        case 0x3E8:
            if (fn_80162A90(0x27F) != 0) {
                lbl_8063ECE2 = 0x35;
            } else {
                lbl_8063ECE2 = 0x71;
            }
            break;
        case 0x3EC:
            lbl_8063ECE2 = 0x5D;
            break;
        case 0x3EE:
            lbl_8063ECE2 = 0x90;
            break;
        case 0x3EF:
            if ((fn_80162A90(0x39) != 0) && ((u16) (*(u16 *)((u8 *)(lbl_8063ED90) + (0x16))) > 1U)) {
                lbl_8063ECE2 = 0x37;
            } else {
                lbl_8063ECE2 = 0x71;
            }
            break;
        default:
            lbl_8063ECE2 = 0x71;
            break;
        }
        lbl_8063ED90 = (unsigned char *)(fn_8011C974());
        ((s32 (*)(void))fn_8007FF20)();
        fn_800800E8();
        ((s32 (*)(void))fn_800801D4)();
        fn_80080658();
        if ((s32) (*(s32 *)((u8 *)(lbl_8063ED68) + (0x18))) == 0) {
            temp_r3 = fn_80055D98__FUlUl((s32)(0x3EF), (s32)(0x27510000));
            lbl_8063ECDC = temp_r3;
            fn_801E34DC__FP11GSsceneDataUl((s32)(temp_r3), (s32)(temp_r3));
            if (isInitialized__5GSmemFv() != 0) {
                var_r3 = allocFromHeap__5GSmemFP12MEMiHeapHeadUl((s32)(gGameHeap), (s32)(0x14));
            } else {
                var_r3 = 0;
            }
            if (var_r3 != 0) {
                var_r3 = __ct__7GSsceneFP11GSsceneData((s32)(var_r3), (s32)(temp_r3));
            }
            (*(s32 *)((u8 *)(lbl_8063ED68) + (0x18))) = var_r3;
        }
    }
    if (fn_80162A90(0x37) == 2U) {
        fn_8007FA58();
        ((s32 (*)(void))fn_8007FF20)();
        fn_800800E8();
        ((s32 (*)(void))fn_800801D4)();
        fn_80080658();
        if ((s32) (*(s32 *)((u8 *)(lbl_8063ED68) + (0x18))) == 0) {
            temp_r3_2 = fn_80055D98__FUlUl((s32)(0x3EF), (s32)(0x27510000));
            lbl_8063ECDC = temp_r3_2;
            fn_801E34DC__FP11GSsceneDataUl((s32)(temp_r3_2), (s32)(temp_r3_2));
            if (isInitialized__5GSmemFv() != 0) {
                var_r3_2 = allocFromHeap__5GSmemFP12MEMiHeapHeadUl((s32)(gGameHeap), (s32)(0x14));
            } else {
                var_r3_2 = 0;
            }
            if (var_r3_2 != 0) {
                var_r3_2 = __ct__7GSsceneFP11GSsceneData((s32)(var_r3_2), (s32)(temp_r3_2));
            }
            (*(s32 *)((u8 *)(lbl_8063ED68) + (0x18))) = var_r3_2;
        }
    }
}
}

extern "C" {

s32 findTarget__14GSrenderTargetFl(s32);
s32 fn_800563EC__FPvi(s32, s32);
s32 fn_80162940(s32, s32, s32);
s32 fn_80253F54(s32, s32);

void fn_80081268() {
    findTarget__14GSrenderTargetFl(4);
    if (fn_80162A90((s32)(0x37)) == 0) {
        lbl_8063ECE2 = 1;
    }
    if (fn_80162A90((s32)(0x37)) == 1U) {
        if (fn_80162A90((s32)(6)) == 0xDU) {
            fn_800563EC__FPvi(0x21, 0);
            lbl_8063ECE2 = 0x24;
            fn_80162940(6, 5, 1);
        } else {
            lbl_8063ECE2 = 0x1F;
        }
    }
    fn_80253F54((s32) &fn_800834E0, (s32) &fn_80089BE8);
}
}

extern "C" {

s32 fn_800599C8(s32, s32, s32, s32, s32, s32);

void fn_8008347C(u8 *arg0) {
    s32 var_r31;
    u8 temp_r4;
    u8 *var_r30;

    var_r31 = 0;
    var_r30 = arg0;
loop_1:
    temp_r4 = (*(u8 *)((u8 *)(var_r30) + (0)));
    if (temp_r4 != 0xFF) {
        fn_800599C8(var_r31 + 1, (s32) temp_r4, (s32) (*(u8 *)((u8 *)(var_r30) + (1))), (s32) (*(u8 *)((u8 *)(var_r30) + (2))), (s32) (*(u8 *)((u8 *)(var_r30) + (3))), 0);
        var_r31 += 1;
        var_r30 += 4;
        goto loop_1;
    }
}
}
