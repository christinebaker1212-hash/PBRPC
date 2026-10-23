#include ".unsorted/8022773C.hpp"

#include "common.hpp"

extern "C" {

void fn_8022894C(void) {}
}

extern "C" {

s32 fn_80227964(s32 arg0);
s32 fn_802279C4(void);

s32 fn_80227B50(void) {
    if (fn_802279C4() != 0) {
        return ((s32 (*)(void))fn_80227964)();
    }
    return 0;
}
}

extern "C" {

void fn_80227BB4(u8 *arg0);

s32 fn_80227B84(s32 arg0) {
    ((s32 (*)(void))fn_80227BB4)();
    return arg0;
}
}

extern "C" {

void fn_80227BD8(u8 *arg0, s8 arg1, s32 arg2, s32 arg3) {
    ((s32 (*)(void))fn_80227BB4)();
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

void fn_80227CC4(u8 *arg0);

void fn_80228240(void) {
    if (fn_80227FC4() != 0) {
        ((s32 (*)(void))fn_80227CC4)();
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

s32 fn_80227804(s32 *arg0);
s32 fn_80227830(s32);
s32 fn_8022AB38(s32, s32);

s32 fn_80227830(s32 arg0) {
    s32 var_r3;

    var_r3 = fn_80227804((s32 *)(arg0));
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

    var_r3 = fn_80227804((s32 *)((s32)(arg0)));
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

    var_r3 = fn_80227804((s32 *)((s32)(arg0)));
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
    ((s32 (*)(void))fn_80227BB4)();
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

void fn_80227CDC(u8 *arg0);

void fn_80228190(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(s32, s32))fn_80227FC4)(arg0, arg1);
    if (temp_r3 != 0) {
        fn_80227CDC((u8 *)(temp_r3));
        fn_8022809C((s32)(arg0), (s32)(temp_r3));
        ((s32 (*)(s32))fn_80227BB4)(temp_r3);
    }
}
}

extern "C" {

u8 *fn_80227F58(u8 *arg0) {
    u8 *var_r3;
    u8 *var_r4;

    var_r4 = (*(u8 **)((u8 *)(arg0) + (0xC)));
    var_r3 = NULL;
    while (var_r4 != NULL) {
        var_r3 = var_r4;
        var_r4 = (*(u8 **)((u8 *)(var_r4) + (4)));
    }
    return var_r3;
}
}

extern "C" {

void fn_8022826C(u8 *arg0, u32 arg1) {
    u8 *var_r31;

    var_r31 = (*(u8 **)((u8 *)(arg0) + (0)));
    while ((u32) var_r31 != (u32) ((*(u8 **)((u8 *)(arg0) + (0))) + ((*(s32 *)((u8 *)(arg0) + (4))) * 0x34))) {
        if (arg1 == (u32) (*(u32 *)((u8 *)(var_r31) + (0x14)))) {
            ((s32 (*)(s32, s32))fn_80228190)((s32) arg0, (*(s32 *)((u8 *)(var_r31) + (8))));
        }
        var_r31 += 0x34;
    }
}
}

extern "C" {

s32 fn_80226910(s32);
s32 fn_8022AA30(s32, s32);
extern u8 *lbl_8063F640;

void fn_802282E4(u8 *arg0, u32 arg1) {
    s32 temp_r3;
    s32 temp_r3_2;
    u8 *var_r31;

    var_r31 = (*(u8 **)((u8 *)(arg0) + (0xC)));
    while (var_r31 != NULL) {
        if (arg1 == (u32) (*(u32 *)((u8 *)(var_r31) + (0x14)))) {
            ((s32 (*)(s32, s32))fn_802281E8)((s32) arg0, (*(s32 *)((u8 *)(var_r31) + (8))));
        }
        var_r31 = (*(u8 **)((u8 *)(var_r31) + (4)));
    }
    temp_r3 = (*(s32 *)((u8 *)(lbl_8063F640) + (0x20)));
    if (temp_r3 != 0) {
        fn_8022AA30(temp_r3, (s32) arg1);
    }
    temp_r3_2 = fn_80226910((s32) lbl_8063F640);
    if (temp_r3_2 != 0) {
        fn_8022AA30(temp_r3_2, (s32) arg1);
    }
}
}

extern "C" {

s32 fn_8022AAB4(s32, s32);

void fn_8022837C(u8 *arg0, u32 arg1) {
    s32 temp_r3;
    s32 temp_r3_2;
    u8 *var_r31;

    var_r31 = (*(u8 **)((u8 *)(arg0) + (0xC)));
    while (var_r31 != NULL) {
        if (arg1 == (u32) (*(u32 *)((u8 *)(var_r31) + (0x14)))) {
            ((s32 (*)(s32, s32))fn_80228214)((s32) arg0, (*(s32 *)((u8 *)(var_r31) + (8))));
        }
        var_r31 = (*(u8 **)((u8 *)(var_r31) + (4)));
    }
    temp_r3 = (*(s32 *)((u8 *)(lbl_8063F640) + (0x20)));
    if (temp_r3 != 0) {
        fn_8022AAB4(temp_r3, (s32) arg1);
    }
    temp_r3_2 = fn_80226910((s32)((s32) lbl_8063F640));
    if (temp_r3_2 != 0) {
        fn_8022AAB4(temp_r3_2, (s32) arg1);
    }
}
}

extern "C" {

s32 fn_8022A9AC(s32, s32);

void fn_80228414(u8 *arg0, u32 arg1) {
    s32 temp_r3;
    s32 temp_r3_2;
    u8 *var_r31;

    var_r31 = (*(u8 **)((u8 *)(arg0) + (0xC)));
    while (var_r31 != NULL) {
        if (arg1 == (u32) (*(u32 *)((u8 *)(var_r31) + (0x14)))) {
            ((s32 (*)(s32, s32))fn_80228240)((s32) arg0, (*(s32 *)((u8 *)(var_r31) + (8))));
        }
        var_r31 = (*(u8 **)((u8 *)(var_r31) + (4)));
    }
    temp_r3 = (*(s32 *)((u8 *)(lbl_8063F640) + (0x20)));
    if (temp_r3 != 0) {
        fn_8022A9AC(temp_r3, (s32) arg1);
    }
    temp_r3_2 = fn_80226910((s32)((s32) lbl_8063F640));
    if (temp_r3_2 != 0) {
        fn_8022A9AC(temp_r3_2, (s32) arg1);
    }
}
}

extern "C" {

s32 fn_80228888(s32, s32);
s32 sleepCurrentThread__15GSthreadManagerFv(s32);
extern s32 sInstance__15GSthreadManager;

void fn_802288F8(s32 arg0, s32 arg1) {
    while (fn_80228888(arg0, arg1) == 0) {
        sleepCurrentThread__15GSthreadManagerFv(sInstance__15GSthreadManager);
    }
}
}

extern "C" {

s32 fn_8022A900(s32, s32);

s32 fn_80227964(s32 arg0) {
    s32 temp_r3;

    temp_r3 = fn_80227804((s32 *)((s32)(arg0)));
    if (temp_r3 == 0) {
        return 0;
    }
    if (fn_8022A900(temp_r3, (*(s32 *)((u8 *)(arg0) + (4)))) == 0) {
        (*(s32 *)((u8 *)(arg0) + (4))) = 0;
        return 0;
    }
    return 1;
}
}

extern "C" {

void fn_80227BB4(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x19))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x1A))) = 0;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x14))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x18))) = 0;
}
}

extern "C" {

void fn_80227CC4(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x10))) == 3) {
        fn_80227B14((s32)((s32) (arg0 + 0x1C)));
    }
}
}

extern "C" {

void fn_80227CDC(u8 *arg0) {
    s32 temp_r0;

    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x10)));
    switch (temp_r0) {                              /* irregular */
    case 3:
        fn_80227AD8((s32)((s32) (arg0 + 0x1C)));
        return;
    case 5:
        fn_802278A8((s32)((s32) (arg0 + 0x1C)));
        return;
    case 4:
        return;
    }
}
}

extern "C" {

s32 fn_80227E04(u8 *arg0, s32 arg1) {
    s32 temp_r0;

    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x10)));
    switch (temp_r0) {                              /* irregular */
    case 3:
        return ((s32 (*)(s32, s32))fn_80227B50)((s32) (arg0 + 0x1C), arg1);
    case 5:
        if (arg1 == (s32) (*(s32 *)((u8 *)(arg0) + (0xC)))) {
            return fn_80227964((s32)((s32) (arg0 + 0x1C)));
        }
        return 0;
    default:
    case 4:
        return 0;
    }
}
}

extern "C" {

struct VT_fn_8022773C_0 { virtual void v0(); virtual s32 v1(s32, s32); };
struct VT_fn_8022773C_1 { virtual void v0(); virtual void v1(); virtual s32 v2(s32, s32); };
struct VT_fn_8022773C_2 { virtual void v0(); virtual void v1(); virtual void v2(); virtual s32 v3(s32, s32); };
struct VT_fn_8022773C_3 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual s32 v4(s32, s32); };
struct VT_fn_8022773C_4 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual s32 v5(s32, s32); };

s32 fn_8022773C(u8 **arg0, u32 arg1, s32 arg2, s32 arg3) {
    switch (arg1) {
    case 1:
        ((VT_fn_8022773C_0 *)(arg0))->v1((s32)(arg2), (s32)(arg3));
        break;
    case 2:
        ((VT_fn_8022773C_1 *)(arg0))->v2((s32)(arg2), (s32)(arg3));
        break;
    case 4:
        ((VT_fn_8022773C_2 *)(arg0))->v3((s32)(arg2), (s32)(arg3));
        break;
    case 6:
        ((VT_fn_8022773C_3 *)(arg0))->v4((s32)(arg2), (s32)(arg3));
        break;
    case 8:
        ((VT_fn_8022773C_4 *)(arg0))->v5((s32)(arg2), (s32)(arg3));
        break;
    }
    return 1;
}
}

extern "C" {

s32 fn_80227804(s32 *arg0) {
    if ((u32) ((*arg0 & 0xFFFF0000)) == 0x5960000U) {
        return (*(s32 *)((u8 *)(lbl_8063F640) + (0x20)));
    }
    return fn_80226910((s32)(lbl_8063F640));
}
}
