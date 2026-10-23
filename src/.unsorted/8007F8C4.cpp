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
