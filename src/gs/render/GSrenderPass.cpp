#include "gs/render/GSrenderPass.hpp"

extern "C" {

extern u8 *lbl_8063F700;
extern u8 *lbl_8063F704;

void fn_80236BF0(u8 *arg0) {
    if ((u8 *) lbl_8063F700 == NULL) {
        lbl_8063F700 = arg0;
    }
    if ((u8 *) lbl_8063F704 != NULL) {
        (*(u8 **)((u8 *)(lbl_8063F704) + (0xC))) = arg0;
    }
    lbl_8063F704 = arg0;
}
}

extern "C" {

extern s32 sActiveRenderPass__12GSrenderPass;

void fn_80236C88(s32 arg0) {
    sActiveRenderPass__12GSrenderPass = arg0;
}
}

extern "C" {

void fn_80236C90(void) {
    sActiveRenderPass__12GSrenderPass = 0;
}
}

#include "common.hpp"

extern "C" {

__declspec(section ".data") extern s32 lbl_804246D4;

u8 *fn_80236B08(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*(s32 *)((u8 *)(arg0) + (0))) = arg1;
    (*(s32 **)((u8 *)(arg0) + (0x10))) = &lbl_804246D4;
    (*(s32 *)((u8 *)(arg0) + (4))) = arg2;
    (*(s32 *)((u8 *)(arg0) + (8))) = arg3;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
    ((s32 (*)(s32, s32, s32, s32, s32))fn_80236BF0)((s32) arg0, arg1, arg2, arg3, (s32) &lbl_804246D4);
    return arg0;
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 fn_802365CC(s32, s32);
s32 fn_80236C18(s32);

u8 *fn_80236B58(u8 *arg0, s32 arg1) {
    if (arg0 != NULL) {
        (*(s32 **)((u8 *)(arg0) + (0x10))) = &lbl_804246D4;
        fn_802365CC((s32) arg0, (s32) &lbl_804246D4);
        fn_80236C18((s32) arg0);
        if (arg1 > 0) {
            __dl__FPv((s32) arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8023645C__FPv(s32);
__declspec(section ".data") extern s32 lbl_804246A0;

u8 *fn_80236D34(u8 *arg0, s32 arg1) {
    s32 temp_r0;
    s32 temp_r3;

    if (arg0 != NULL) {
        temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x18)));
        (*(s32 **)((u8 *)(arg0) + (0x10))) = &lbl_804246A0;
        if (temp_r0 != 0) {
            fn_8023645C__FPv(temp_r0);
        }
        temp_r3 = (*(s32 *)((u8 *)(arg0) + (0x14)));
        if (temp_r3 != 0) {
            fn_8023645C__FPv(temp_r3);
        }
        ((s32)fn_80236B58((u8 *)((s32) arg0), (s32)(0)));
        if (arg1 > 0) {
            __dl__FPv((s32)((s32) arg0));
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8023623C__FUlUlUlUlUlUl(s32, s32, s32, s32, s32, s32);

u8 *fn_80236C9C(u8 *arg0) {
    ((s32 (*)(void))fn_80236B08)();
    (*(s32 *)((u8 *)(arg0) + (0x14))) = 0;
    (*(s32 **)((u8 *)(arg0) + (0x10))) = &lbl_804246A0;
    (*(s32 *)((u8 *)(arg0) + (0x18))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x1C))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x1D))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x1E))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x1F))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x14))) = fn_8023623C__FUlUlUlUlUlUl(0x45, 0, 0, 0, 1, 0);
    (*(s32 *)((u8 *)(arg0) + (0x18))) = fn_8023623C__FUlUlUlUlUlUl(0x43, 0, 0, 1, 1, 0);
    return arg0;
}
}
