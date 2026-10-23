#include ".unsorted/8022773C.hpp"

#include "common.hpp"

extern "C" {

void fn_8022894C(void) {}
}

extern "C" {

s32 fn_80227964(void);
s32 fn_802279C4(void);

s32 fn_80227B50(void) {
    if (fn_802279C4() != 0) {
        return fn_80227964();
    }
    return 0;
}
}

extern "C" {

s32 fn_80227BB4(void);

s32 fn_80227B84(s32 arg0) {
    fn_80227BB4();
    return arg0;
}
}

extern "C" {

void fn_80227BD8(u8 *arg0, s8 arg1, s32 arg2, s32 arg3) {
    fn_80227BB4();
    (*(s32 *)((u8 *)(arg0) + (0x14))) = arg2;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = 1;
    (*(s8 *)((u8 *)(arg0) + (0x18))) = arg1;
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = arg3;
}
}

extern "C" {

s32 fn_80227C3C(void);
s32 fn_80227FC4(void);

void fn_802281E8(void) {
    if (fn_80227FC4() != 0) {
        fn_80227C3C();
    }
}
}

extern "C" {

s32 fn_80227C80(void);

void fn_80228214(void) {
    if (fn_80227FC4() != 0) {
        fn_80227C80();
    }
}
}

extern "C" {

s32 fn_80227CC4(void);

void fn_80228240(void) {
    if (fn_80227FC4() != 0) {
        fn_80227CC4();
    }
}
}

extern "C" {

s32 fn_8022809C(s32, s32);

s32 fn_8022809C(s32 arg0, s32 arg1) {
    u8 **temp_r5_2;
    u8 *temp_r5;

    temp_r5 = (*(u8 **)((u8 *)(arg1) + (0)));
    if (temp_r5 != NULL) {
        (*(u8 ***)((u8 *)(temp_r5) + (4))) = (u8 **) (*(u8 ***)((u8 *)(arg1) + (4)));
    }
    temp_r5_2 = (*(u8 ***)((u8 *)(arg1) + (4)));
    if (temp_r5_2 != NULL) {
        *temp_r5_2 = (*(u8 **)((u8 *)(arg1) + (0)));
    }
    if ((u32) (*(u32 *)((u8 *)(arg0) + (0xC))) == (u32) arg1) {
        (*(u32 *)((u8 *)(arg0) + (0xC))) = (u32) (*(u8 ***)((u8 *)(arg1) + (4)));
    }
    (*(u8 **)((u8 *)(arg1) + (0))) = NULL;
    (*(u8 ***)((u8 *)(arg1) + (4))) = NULL;
    return arg0;
}
}

extern "C" {

s32 fn_80227804(s32);
s32 fn_80227830(s32);
s32 fn_8022AB38(s32, s32);

s32 fn_80227830(s32 arg0) {
    s32 var_r3;

    var_r3 = fn_80227804(arg0);
    if (var_r3 != 0) {
        var_r3 = fn_8022AB38(var_r3, (*(s32 *)((u8 *)(arg0) + (4))));
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8022786C(s32);
s32 fn_8022AB74(s32, s32);

s32 fn_8022786C(s32 arg0) {
    s32 var_r3;

    var_r3 = fn_80227804((s32)(arg0));
    if (var_r3 != 0) {
        var_r3 = fn_8022AB74(var_r3, (*(s32 *)((u8 *)(arg0) + (4))));
    }
    return var_r3;
}
}

extern "C" {

s32 fn_802278A8(s32);
s32 fn_8022A8A8(s32, s32);

s32 fn_802278A8(s32 arg0) {
    s32 var_r3;

    var_r3 = fn_80227804((s32)(arg0));
    if (var_r3 != 0) {
        var_r3 = fn_8022A8A8(var_r3, (*(s32 *)((u8 *)(arg0) + (4))));
    }
    return var_r3;
}
}

extern "C" {

s32 fn_802278E4(s32, s32, s32, s32);
s32 fn_80227A04(s32, s32, s32, s32, s32);

s32 fn_80227A04(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_r3;

    var_r3 = ((s32 (*)(s32, s32))fn_802279C4)(arg0, arg1);
    if (var_r3 != 0) {
        var_r3 = fn_802278E4(var_r3, arg2, arg3, arg4);
    }
    return var_r3;
}
}

extern "C" {

s32 fn_80227A60(s32);

s32 fn_80227A60(s32 arg0) {
    fn_80227830((s32)(arg0));
    fn_80227830((s32)(arg0 + 8));
    return fn_80227830((s32)(arg0 + 0x10));
}
}

extern "C" {

s32 fn_80227A9C(s32);

s32 fn_80227A9C(s32 arg0) {
    fn_8022786C((s32)(arg0));
    fn_8022786C((s32)(arg0 + 8));
    return fn_8022786C((s32)(arg0 + 0x10));
}
}

extern "C" {

s32 fn_80227AD8(s32);

s32 fn_80227AD8(s32 arg0) {
    fn_802278A8((s32)(arg0));
    fn_802278A8((s32)(arg0 + 8));
    return fn_802278A8((s32)(arg0 + 0x10));
}
}

extern "C" {

s32 fn_80227B14(s32);

s32 fn_80227B14(s32 arg0) {
    fn_802278A8((s32)(arg0));
    fn_802278A8((s32)(arg0 + 8));
    return fn_802278A8((s32)(arg0 + 0x10));
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 __dla__FPv(s32);
__declspec(section ".data") extern s32 lbl_80423E7C;

u8 *fn_80227EE8(u8 *arg0, s32 arg1) {
    s32 temp_r5;

    if (arg0 != NULL) {
        temp_r5 = (*(s32 *)((u8 *)(arg0) + (0)));
        (*(s32 **)((u8 *)(arg0) + (0x14))) = &lbl_80423E7C;
        if (temp_r5 != 0) {
            __dla__FPv(temp_r5 - 0x10);
        }
        if (arg1 > 0) {
            __dl__FPv((s32) arg0);
        }
    }
    return arg0;
}
}

extern "C" {

u8 *fn_80227F78(void);
s32 fn_80228000(u8 *, u8 *);

s32 fn_802280E8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;
    s32 temp_r3_3;
    u8 *temp_r3_2;

    if (arg3 == 0) {
        return 0;
    }
    temp_r3_2 = fn_80227F78();
    if (temp_r3_2 == NULL) {
        return 0;
    }
    fn_80227BB4();
    ((s32 (*)(u8 *, s32, s32, s32))fn_80227BD8)(temp_r3_2, arg1, arg2, arg3);
    fn_80228000(arg0, temp_r3_2);
    temp_r3_3 = (*(s32 *)((u8 *)(arg0) + (8))) + 1;
    (*(s32 *)((u8 *)(arg0) + (8))) = temp_r3_3;
    if (temp_r3_3 == 0) {
        (*(s32 *)((u8 *)(arg0) + (8))) = (s32) (temp_r3_3 + 1);
    }
    temp_r3 = (*(s32 *)((u8 *)(arg0) + (8)));
    (*(s32 *)((u8 *)(temp_r3_2) + (8))) = temp_r3;
    return temp_r3;
}
}

extern "C" {

s32 fn_80227CDC(s32);

void fn_80228190(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(s32, s32))fn_80227FC4)(arg0, arg1);
    if (temp_r3 != 0) {
        fn_80227CDC(temp_r3);
        fn_8022809C((s32)(arg0), (s32)(temp_r3));
        ((s32 (*)(s32))fn_80227BB4)(temp_r3);
    }
}
}
