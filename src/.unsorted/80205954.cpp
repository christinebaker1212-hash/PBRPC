#include ".unsorted/80205954.hpp"

#include "common.hpp"

extern "C" {

s32 __dl__FPv(void);

s32 fn_802072DC(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 fn_80207864(u8 *arg0);
s32 fn_802093CC(s32);


}

extern "C" {

extern f32 lbl_80641F68;

f32 fn_80207814(u8 *arg0) {
    if (arg0 == NULL) {
        return lbl_80641F68;
    }
    if ((*(u16 *)((u8 *)(arg0) + (0x148))) & 1) {
        return (*(f32 *)((u8 *)(arg0) + (0xC)));
    }
    return lbl_80641F68;
}
}

extern "C" {

f32 fn_80207840(u8 *arg0) {
    u8 *temp_r3;

    if ((arg0 == NULL) || (temp_r3 = (*(u8 **)((u8 *)(arg0) + (0x104))), ((temp_r3 == NULL) != 0))) {
        return lbl_80641F68;
    }
    return (*(f32 *)((u8 *)(temp_r3) + (0x2C)));
}
}

extern "C" {

s32 fn_801FA044(s32);
s32 fn_802043B0(s32);
s32 fn_802044C4(void);
s32 fn_8020A4E0(s32, s32, s32);
s32 fn_8023B948__8GSrenderFPv(s32, s32);
extern u8 *lbl_8063F4B0;
extern u8 lbl_8063F4B4;
extern s32 *lbl_8063F730;
extern s32 sInstance__8GSrender;

void fn_8020752C(u32 arg0, u8 *arg1) {
    u16 temp_r3_4;
    u16 temp_r3;
    s32 var_r4;
    s32 temp_r3_3;
    s32 temp_r3_2;
    s32 temp_r29;

    if (arg1 != NULL) {
        temp_r3 = (*(u16 *)((u8 *)(arg1) + (0x148)));
        if ((temp_r3 & 1) && (temp_r3 & 4) && (temp_r3 & 0x18) && ((temp_r3_2 = (*(s32 *)((u8 *)(arg1) + (0))), ((temp_r3_2 == 0) != 0)) || (temp_r3_3 = fn_801FA044(temp_r3_2), ((temp_r3_3 == 0) != 0)) || ((u32) temp_r3_3 == arg0))) {
            if ((s32 *) lbl_8063F730 != NULL) {
                var_r4 = *lbl_8063F730;
            } else {
                var_r4 = 0;
            }
            temp_r3_4 = (*(u16 *)((u8 *)(arg1) + (0x148)));
            if ((!(temp_r3_4 & 8) || (var_r4 == 2)) && (!(temp_r3_4 & 0x10) || (var_r4 == 4))) {
                lbl_8063F4B0 = arg1;
                temp_r29 = ((u32) *(*(u32 **)((u8 *)((*(u8 **)((u8 *)(arg1) + (0x110)))) + (8))) >> 0x1EU) & 1;
                if (temp_r29 != 0) {
                    fn_802044C4();
                }
                lbl_8063F4B4 = 0;
                fn_8020A4E0((s32) (arg1 + 8), (s32) arg0, (s32) (*(u32 **)((u8 *)((*(u8 **)((u8 *)(arg1) + (0x110)))) + (8))));
                if ((s32) lbl_8063F4B4 != 0) {
                    (*(s32 *)((u8 *)(arg1) + (0x14C))) = fn_8023B948__8GSrenderFPv(sInstance__8GSrender, (s32) arg1);
                }
                if (temp_r29 != 0) {
                    fn_802043B0((s32) arg0);
                }
            }
        }
    }
}
}

extern "C" {

s32 findTarget__14GSrenderTargetFl(s32);
s32 fn_8020A640(s32, s32);
s32 fn_8023B420__14GSrenderTargetFUl(s32, s32);
extern u8 *sInstance__12GSmenuModule;
extern u8 *sInstance__17GShierarchyModule;

void fn_8020764C(u8 *arg0) {
    s32 *temp_r31;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 temp_r3_6;
    s32 temp_r3_7;
    u32 temp_r29;
    u32 temp_r29_2;
    u32 temp_r29_3;
    u32 temp_r29_4;
    u32 temp_r29_5;
    u32 temp_r29_6;
    u32 temp_r29_7;

    if ((arg0 != NULL) && ((*(u16 *)((u8 *)(arg0) + (0x148))) & 1)) {
        lbl_8063F4B0 = arg0;
        temp_r31 = (*(s32 **)((u8 *)((*(u8 **)((u8 *)(arg0) + (0x110)))) + (8)));
        if (*temp_r31 & 0x2000) {
            temp_r29 = (*(u32 *)((u8 *)(sInstance__17GShierarchyModule) + (0x138)));
            temp_r3 = findTarget__14GSrenderTargetFl((s32) (u8) (temp_r29 >> 0x10U));
            if (temp_r3 != 0) {
                fn_8023B420__14GSrenderTargetFUl(temp_r3, (s32) temp_r29);
            }
            temp_r29_2 = (*(u32 *)((u8 *)(sInstance__12GSmenuModule) + (0x100)));
            temp_r3_2 = findTarget__14GSrenderTargetFl((s32) (u8) (temp_r29_2 >> 0x10U));
            if (temp_r3_2 != 0) {
                fn_8023B420__14GSrenderTargetFUl(temp_r3_2, (s32) temp_r29_2);
            }
        }
        if (*temp_r31 & 0x800000) {
            temp_r29_3 = (*(u32 *)((u8 *)(sInstance__17GShierarchyModule) + (0x13C)));
            temp_r3_3 = findTarget__14GSrenderTargetFl((s32) (u8) (temp_r29_3 >> 0x10U));
            if (temp_r3_3 != 0) {
                fn_8023B420__14GSrenderTargetFUl(temp_r3_3, (s32) temp_r29_3);
            }
        }
        if (*temp_r31 & 0x4000) {
            temp_r29_4 = (*(u32 *)((u8 *)(sInstance__17GShierarchyModule) + (0x144)));
            temp_r3_4 = findTarget__14GSrenderTargetFl((s32) (u8) (temp_r29_4 >> 0x10U));
            if (temp_r3_4 != 0) {
                fn_8023B420__14GSrenderTargetFUl(temp_r3_4, (s32) temp_r29_4);
            }
            temp_r29_5 = (*(u32 *)((u8 *)(sInstance__12GSmenuModule) + (0x110)));
            temp_r3_5 = findTarget__14GSrenderTargetFl((s32) (u8) (temp_r29_5 >> 0x10U));
            if (temp_r3_5 != 0) {
                fn_8023B420__14GSrenderTargetFUl(temp_r3_5, (s32) temp_r29_5);
            }
        }
        if (*temp_r31 & 0x01000000) {
            temp_r29_6 = (*(u32 *)((u8 *)(sInstance__17GShierarchyModule) + (0x148)));
            temp_r3_6 = findTarget__14GSrenderTargetFl((s32) (u8) (temp_r29_6 >> 0x10U));
            if (temp_r3_6 != 0) {
                fn_8023B420__14GSrenderTargetFUl(temp_r3_6, (s32) temp_r29_6);
            }
        }
        if (*temp_r31 & 0x8000) {
            temp_r29_7 = (*(u32 *)((u8 *)(sInstance__17GShierarchyModule) + (0x14C)));
            temp_r3_7 = findTarget__14GSrenderTargetFl((s32) (u8) (temp_r29_7 >> 0x10U));
            if (temp_r3_7 != 0) {
                fn_8023B420__14GSrenderTargetFUl(temp_r3_7, (s32) temp_r29_7);
            }
        }
        fn_8020A640((s32) (arg0 + 8), (s32) temp_r31);
        (*(u16 *)((u8 *)(arg0) + (0x148))) = (u16) ((*(u16 *)((u8 *)(arg0) + (0x148))) & 0x38);
    }
}
}

extern "C" {

s32 fn_80207864(u8 *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    if ((*(u16 *)((u8 *)(arg0) + (0x148))) & 1) {
        return *(*(s32 **)((u8 *)(arg0) + (0x104))) & 1;
    }
    return 0;
}
}

extern "C" {

void fn_802077D8(s32 arg0) {
    if (fn_80207864((u8 *)(arg0)) != 0) {
        fn_802093CC((s32)(arg0 + 8));
    }
}
}
