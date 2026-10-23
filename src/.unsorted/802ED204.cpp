#include ".unsorted/802ED204.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063DEC0;
extern u32 lbl_8063DECC;
extern u32 lbl_8064020C;
extern u8 lbl_80445BB0[];
extern u8 lbl_8057AAB8[];
void fn_802ED628();
u8 **fn_802F7FC0(u8 ***arg0);

u8 *fn_802EDD5C(void) {
    return lbl_80445BB0;
}
s32 fn_802EDE48(void) {
    return 0;
}
void fn_802F3264(void) {}
u32 fn_802F4CF8(void) {
    return lbl_8064020C;
}
u32 fn_802F5190(void) {
    return lbl_8063DEC0;
}
void fn_802F5198(void) {
    fn_802ED628();
}
u8 *fn_802F5A44(void) {
    return lbl_8057AAB8;
}
u32 fn_802F5A50(void) {
    return lbl_8063DECC;
}
void fn_802F6D6C(void) {}
void fn_802F6D78(void) {}
void fn_802F7C00(u8 *p, u32 v) {
    *(u32 *)(p + 0x7d8) = v;
}
void fn_802F7C08(u8 *p, u32 v) {
    *(u32 *)(p + 0x7d4) = v;
}
u32 fn_802F7C10(u8 *p) {
    return *(u32 *)(p + 0x7d4);
}
void fn_802F83F0(void) {
    ((void (*)(void))fn_802F7FC0)();
}
void fn_802F8440(void) {}
u32 fn_802FAA68(u8 *p) {
    return *(u32 *)(p + 0x348);
}
void fn_802FFED0(void) {}
u8 *fn_802FFED4(u8 *p) {
    return p + 0x800;
}
u8 *fn_802FFEDC(u8 *p) {
    return p + 0x808;
}
u8 *fn_802FFEE4(u8 *p) {
    return p + 0x840;
}
u8 *fn_802FFEEC(u8 *p) {
    return p + 0x80c;
}
void fn_802F83F4(u8 *p) {
    *(u32 *)(p + 0x18) = 0x0;
}
void fn_802F8CB4(u8 *p) {
    *(u32 *)(p + 0x0) = 0x0;
}
void fn_802FAA50(u8 *p) {
    *(u32 *)(p + 0x348) = 0x0;
}
void fn_802FAA5C(u8 *p) {
    *(u32 *)(p + 0x348) = 0x1;
}
}

extern "C" {

s32 fn_802EDD68(s32, s32, s32, s32);

void fn_802EDED8(void) {
    fn_802EDD68(0x1003, 0, 0, 0);
}
}

extern "C" {

s32 OSReceiveMessage(s32, s32 *, s32);
extern s32 lbl_80643030;

s32 fn_802F09B0(s32 *arg0, s32 arg1) {
    s32 sp8;

    if (arg1 == 1) {
        OSReceiveMessage(lbl_80643030 + 0x58E4, &sp8, 1);
        goto block_4;
    }
    if (OSReceiveMessage(lbl_80643030 + 0x58E4, &sp8, 0) == 0) {
        *arg0 = 0;
        return -0xED;
    }
block_4:
    *arg0 = sp8;
    if (sp8 == 0) {
        return -0x100;
    }
    return 0;
}
}

extern "C" {

s32 OSSendMessage(s32, s32, s32, s32);

void fn_802F0A44(s32 arg0) {
    OSSendMessage(lbl_80643030 + 0x58E4, arg0, 0, lbl_80643030);
}
}

extern "C" {

s32 fn_802EDFC4(s16 arg0, s32 arg1);
u16 fn_802F3F18();

s32 fn_802F0FD4(s32 arg0) {
    s32 temp_r3;

    temp_r3 = fn_802EDFC4((s16)(fn_802F3F18()), (s32)(arg0));
    return temp_r3 & (temp_r3 >> 0x1F);
}
}

extern "C" {

s32 fn_802EE064(s16 arg0);

s32 fn_802F1014(void) {
    s32 temp_r3;

    temp_r3 = fn_802EE064((s16)(fn_802F3F18()));
    return temp_r3 & (temp_r3 >> 0x1F);
}
}

extern "C" {

s32 OSInitMessageQueue(s32, s32, s32);

s32 fn_802F1488(void) {
    s32 temp_r31;

    temp_r31 = lbl_80643030;
    OSInitMessageQueue(temp_r31 + 0x6DE4, temp_r31 + 0x6E04, 0x20);
    OSInitMessageQueue(temp_r31 + 0x6E88, temp_r31 + 0x6EA8, 0x20);
    OSInitMessageQueue(temp_r31 + 0x6F28, temp_r31 + 0x6F48, 0x20);
    return 0;
}
}

extern "C" {

s32 memset(s32, s32, s32);

void fn_802F1628(void) {
    s32 temp_r31;

    temp_r31 = lbl_80643030;
    if (temp_r31 != 0) {
        memset(temp_r31 + 0x6E04, 0, 0x80);
        memset(temp_r31 + 0x6EA8, 0, 0x80);
        memset(temp_r31 + 0x6F48, 0, 0x80);
    }
}
}

extern "C" {

s32 OSGetTick();

void fn_802F22BC(s32 arg0) {
    (*(s32 *)((u8 *)((lbl_80643030 + (arg0 * 4))) + (0x64C4))) = OSGetTick();
}
}

extern "C" {

u32 fn_802F22F8(s32 arg0, s32 arg1) {
    return (u32) ((*(s32 *)((u8 *)((lbl_80643030 + (arg0 * 4))) + (0x64C4))) - arg1) >> 0x1FU;
}
}

extern "C" {

void fn_802F2808(void) {
    s32 temp_r31;

    temp_r31 = lbl_80643030;
    if (temp_r31 != 0) {
        memset(temp_r31 + 0x6634, 0, 0x80);
        memset(temp_r31 + 0x66D4, 0, 4);
    }
}
}

extern "C" {

s32 fn_802F3158(void) {
    s32 temp_r31;

    temp_r31 = lbl_80643030;
    memset(temp_r31 + 0x2140, 0, 0x1000);
    memset(temp_r31 + 0x6FC8, 0, 0x318);
    return 0;
}
}

extern "C" {

s32 memcpy(s32, s32);

void fn_802F400C(s32 arg0, s32 arg1) {
    memcpy(arg1, arg0);
}
}

extern "C" {

s32 fn_802ED95C(s32 *, s32 *, s32 *);
s32 fn_802F4D70(s32, s32, s32);

s32 fn_802F4D18(void) {
    s32 sp10;
    s32 spC;
    s32 sp8;
    s32 var_r31;

    var_r31 = 0x63;
    if (fn_802ED95C(&sp10, &spC, &sp8) >= 0) {
        var_r31 = fn_802F4D70(sp10, spC, sp8);
    }
    return var_r31;
}
}

extern "C" {

s32 fn_802F546C(s32);

void fn_802F5460(void) {
    fn_802F546C(0x927C0);
}
}

extern "C" {

s32 IOS_Ioctl(s32, s32, void *, s32, s32, s32);
void *fn_802F5AA8(s32, s32);
s32 fn_802F5B90(s32, void *, s32);
s32 fn_802F5BC4(s32 arg0, s32 *arg1);
s32 fn_802F5CAC(s32, s32);

void fn_802F61FC(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp8;
    s32 var_r31;
    void *temp_r3;

    if (fn_802F5BC4(0, &sp8) == 0) {
        if (arg0 == 0x17) {
            var_r31 = -5;
        } else {
            temp_r3 = fn_802F5AA8(0xC, 0x20);
            if (temp_r3 == NULL) {
                var_r31 = -0x31;
            } else {
                (*(s32 *)((u8 *)(temp_r3) + (0))) = arg0;
                (*(s32 *)((u8 *)(temp_r3) + (4))) = arg1;
                (*(s32 *)((u8 *)(temp_r3) + (8))) = arg2;
                var_r31 = IOS_Ioctl(sp8, 0xF, temp_r3, 0xC, 0, 0);
                fn_802F5B90(0xC, temp_r3, 0x20);
            }
        }
        fn_802F5CAC(0, var_r31);
    }
}
}

extern "C" {

void fn_802F6374(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 var_r31;
    void *temp_r3;

    if (fn_802F5BC4((s32)(0), (s32 *)(&sp8)) == 0) {
        temp_r3 = fn_802F5AA8(0xC, 0x20);
        if (temp_r3 == NULL) {
            var_r31 = -0x31;
        } else {
            (*(s32 *)((u8 *)(temp_r3) + (0))) = arg0;
            (*(s32 *)((u8 *)(temp_r3) + (4))) = arg1;
            var_r31 = IOS_Ioctl(sp8, 0xA, temp_r3, 8, 0, 0);
            fn_802F5B90(0xC, temp_r3, 0x20);
        }
        fn_802F5CAC(0, var_r31);
    }
}
}

extern "C" {

s32 fn_802F6D84(s32, s32, s32, s32, s32, s32, s32, s32);

void fn_802F6834(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    fn_802F6D84(0, arg0, arg1, arg2, arg3, arg4, arg2, arg1);
}
}

extern "C" {

s32 fn_802F7024(s32, s32, s32, s32, s32, s32, s32, s32);

void fn_802F6880(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    fn_802F7024(0, arg0, arg1, arg2, arg3, arg4, arg2, arg1);
}
}

extern "C" {

void fn_802F69FC(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 var_r31;
    void *temp_r3;

    if (fn_802F5BC4((s32)(0), (s32 *)(&sp8)) == 0) {
        temp_r3 = fn_802F5AA8(0xC, 0x20);
        if (temp_r3 == NULL) {
            var_r31 = -0x31;
        } else {
            (*(s32 *)((u8 *)(temp_r3) + (0))) = arg0;
            (*(s32 *)((u8 *)(temp_r3) + (4))) = arg1;
            var_r31 = IOS_Ioctl(sp8, 0xE, temp_r3, 8, 0, 0);
            fn_802F5B90(0xC, temp_r3, 0x20);
        }
        fn_802F5CAC(0, var_r31);
    }
}
}

extern "C" {

u16 fn_802F6D70(u16 arg0) {
    return arg0;
}
}

extern "C" {

u16 fn_802F6D7C(u16 arg0) {
    return arg0;
}
}

extern "C" {

void fn_802F7B34(void *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0x7D4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x7D8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x7C4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x7C8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x7CC))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x7D0))) = -1;
    (*(s32 *)((u8 *)(arg0) + (0x7DC))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x7E0))) = 0;
}
}

extern "C" {

void *fn_802FFE68();

s32 fn_802F7B60(s32 arg0, s32 arg1) {
    s32 (*temp_r12)(s32, s32);

    temp_r12 = (*(s32 (**)(s32, s32))((u8 *)(fn_802FFE68()) + (0x7C4)));
    if (temp_r12 != NULL) {
        return temp_r12(arg0, arg1);
    }
    return 0;
}
}

extern "C" {

void fn_802F7BBC(s32 arg0) {
    s32 (*temp_r12)(s32);

    temp_r12 = (*(s32 (**)(s32))((u8 *)(fn_802FFE68()) + (0x7C8)));
    if (temp_r12 != NULL) {
        temp_r12(arg0);
    }
}
}

extern "C" {

void fn_802F81A4(void *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
}
}

extern "C" {

s32 OSInitMutex();

void fn_802F8400(void *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x18))) == 0) {
        OSInitMutex();
        (*(s32 *)((u8 *)(arg0) + (0x18))) = 1;
    }
}
}

extern "C" {

s32 OSLockMutex();

void fn_802F8444(void) {
    OSLockMutex();
}
}

extern "C" {

s32 OSUnlockMutex();

void fn_802F8448(void) {
    OSUnlockMutex();
}
}

extern "C" {

s32 fn_802FE914();

s32 fn_802F85F4(void) {
    fn_802FE914();
    return 0;
}
}

extern "C" {

s32 fn_802F8C3C(void *arg0, u32 arg1) {
    return (u32) (*(u32 *)((u8 *)(arg0) + (0x1C))) <= arg1;
}
}

extern "C" {

s32 strlen();

void fn_802FA0E0(void) {
    strlen();
}
}

extern "C" {

s32 strcmp();

void fn_802FA0E4(void) {
    strcmp();
}
}

extern "C" {

void fn_802FFEF4(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        (*(s32 *)((u8 *)(arg0) + (0x48))) = arg1;
    }
}
}

extern "C" {

s32 fn_802FFF04(void *arg0) {
    if (arg0 != NULL) {
        return (*(s32 *)((u8 *)(arg0) + (0x48)));
    }
    return 0;
}
}

extern "C" {

void fn_80300C04(void) {
    OSInitMutex();
}
}

extern "C" {

void fn_80300C08(void) {
    OSLockMutex();
}
}

extern "C" {

void fn_80300C0C(void) {
    OSUnlockMutex();
}
}

extern "C" {

s32 WDi_Ioctlv(s32, s32, s32, u8 *);
u8 *fn_802EDD5C(void);
u8 *iosAllocAligned(s32, s32, s32);
s32 iosFree(s32, u8 *);

s32 fn_802EDE50(s32 arg0) {
    s32 temp_r31;
    u8 *temp_r3;

    temp_r3 = iosAllocAligned((*(s32 *)((u8 *)(fn_802EDD5C()) + (8))), 0xC, 0x20);
    (*(s32 *)((u8 *)(temp_r3) + (0))) = (s32) (temp_r3 + 8);
    (*(s32 *)((u8 *)(temp_r3) + (8))) = arg0;
    (*(s32 *)((u8 *)(temp_r3) + (4))) = 4;
    temp_r31 = WDi_Ioctlv(0x1002, 1, 0, temp_r3);
    iosFree((*(s32 *)((u8 *)(fn_802EDD5C()) + (8))), temp_r3);
    return temp_r31;
}
}

extern "C" {

s32 fn_802EE464(s32 arg0, s32 arg1) {
    s32 temp_r31;
    u8 *temp_r3;

    temp_r3 = iosAllocAligned((*(s32 *)((u8 *)(fn_802EDD5C()) + (8))), 8, 0x20);
    (*(s32 *)((u8 *)(temp_r3) + (0))) = arg0;
    (*(s32 *)((u8 *)(temp_r3) + (4))) = arg1;
    temp_r31 = WDi_Ioctlv(0x8000, 0, 1, temp_r3);
    iosFree((*(s32 *)((u8 *)(fn_802EDD5C()) + (8))), temp_r3);
    return temp_r31;
}
}

extern "C" {

s32 SSLWrite(s32, s32, s32);                        /* extern */
s32 fn_802F9DD0(s32, s32, s32, s32);                /* extern */

s32 fn_802F9F68(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r0;
    s32 var_r3;

    if ((*(s32 *)((u8 *)(arg0) + (0xAC))) > 0) {
        var_r3 = SSLWrite((*(s32 *)((u8 *)(arg0) + (0xAC))), arg2, arg3);
    } else {
        var_r3 = fn_802F9DD0(arg1, arg2, arg3, arg4);
    }
    if (var_r3 < 0) {
        if ((s32) (*(s32 *)((u8 *)(arg0) + (0))) != 0) {
            return -0x3EA;
        }
        if ((s32) (*(s32 *)((u8 *)(arg0) + (0xAC))) > 0) {
            if ((u32) (var_r3 + 7) <= 1U) {
                return 0;
            }
            goto block_11;
        }
        if (var_r3 == -0x38) {
            return 0;
        }
block_11:
        var_r3 = -0x3E9;
        /* Duplicate return node #12. Try simplifying control flow for better match */
        return var_r3;
    }
    return var_r3;
}
}

extern "C" {

s32 fn_802F1D98(void);
extern s32 lbl_806401F8;

s32 fn_802F1D98(void) {
    if ((s32) lbl_806401F8 != 0) {
        return (*(s32 *)((u8 *)(lbl_80643030) + (0x5764)));
    }
    return 0;
}
}

extern "C" {

s32 fn_802EE180(s32, s32, s32);
s32 fn_802F0F80(s32, s32, s32, s32);

s32 fn_802F0F80(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    temp_r3 = fn_802EE180(arg0, (s32) (u16) arg1, arg2);
    return temp_r3 & (temp_r3 >> 0x1F);
}
}

extern "C" {

s32 fn_802F1F30(s32, s32, s32);
s32 fn_802F2314(s32);

s32 fn_802F2314(s32 arg0) {
    return fn_802F1F30(arg0, 1, 0);
}
}

extern "C" {

s32 fn_802F2320(s32);

s32 fn_802F2320(s32 arg0) {
    return fn_802F1F30(arg0, 1, 1);
}
}

extern "C" {

s32 fn_802F0AF0(s32, s32);
s32 fn_802F3604(s32, s32);

s32 fn_802F3604(s32 arg0, s32 arg1) {
    s32 *temp_r5;

    temp_r5 = (*(s32 **)((u8 *)(arg1) + (0x30)));
    if (temp_r5 != NULL) {
        *temp_r5 = (*(s32 *)((u8 *)(arg1) + (0x2C)));
    }
    return fn_802F0AF0(arg0, arg1);
}
}

extern "C" {

s32 OSDisableInterrupts(void);
s32 OSGetCurrentThread(void);
s32 OSRestoreInterrupts(s32);
extern s32 lbl_8064021C;

s32 fn_802F5CAC(s32 arg0, s32 arg1) {
    s32 temp_r31;
    s32 temp_r3;

    temp_r31 = OSDisableInterrupts();
    temp_r3 = OSGetCurrentThread();
    if (temp_r3 != 0) {
        (*(s32 *)((u8 *)(temp_r3) + (0x30C))) = arg1;
    } else {
        lbl_8064021C = arg1;
    }
    OSRestoreInterrupts(temp_r31);
    return arg1;
}
}

extern "C" {

s32 fn_802F7250(void);

s32 fn_802F7250(void) {
    s32 sp8;
    s32 temp_r3;
    s32 var_r30;

    var_r30 = 0;
    temp_r3 = fn_802F5BC4((s32)((s32)(0)), (s32 *)((s32 *)((s32) &sp8)));
    if (temp_r3 == 0) {
        var_r30 = IOS_Ioctl((s32)(sp8), (s32)(0x10), (void *)(0), (s32)(0), (s32)(0), (s32)(0));
        fn_802F5CAC((s32)(0), (s32)(temp_r3));
    }
    return var_r30;
}
}

extern "C" {

s32 fn_802F81B4(s32, s32);

s32 fn_802F81B4(s32 arg0, s32 arg1) {
    s32 temp_r3;
    s32 temp_r4_2;
    s32 var_r31;
    u8 **temp_r4;

    var_r31 = -1;
    temp_r3 = fn_802F7B60((s32)(0x14), (s32)(4));
    if (temp_r3 != 0) {
        temp_r4 = (*(u8 ***)((u8 *)(arg0) + (0)));
        if (temp_r4 != NULL) {
            (*(u8 **)((u8 *)(temp_r3) + (0))) = (u8 *) *temp_r4;
            (*(u8 ***)((u8 *)(temp_r3) + (4))) = (u8 **) (*(u8 ***)((u8 *)(arg0) + (0)));
            (*(s32 *)((u8 *)(*(*(u8 ***)((u8 *)(arg0) + (0)))) + (4))) = temp_r3;
            *(*(u8 ***)((u8 *)(arg0) + (0))) = (u8 *) temp_r3;
        } else {
            (*(u8 **)((u8 *)(temp_r3) + (0))) = (u8 *) temp_r3;
            (*(u8 ***)((u8 *)(temp_r3) + (4))) = (u8 **) temp_r3;
            (*(u8 ***)((u8 *)(arg0) + (0))) = (u8 **) temp_r3;
        }
        temp_r4_2 = (*(s32 *)((u8 *)(arg0) + (4)));
        (*(s32 *)((u8 *)(temp_r3) + (8))) = temp_r4_2;
        (*(s32 *)((u8 *)(arg0) + (4))) = (s32) (temp_r4_2 + 1);
        (*(s32 *)((u8 *)(temp_r3) + (0xC))) = arg1;
        (*(s32 *)((u8 *)(temp_r3) + (0x10))) = -1;
        var_r31 = (*(s32 *)((u8 *)(temp_r3) + (8)));
        if ((s32) (*(s32 *)((u8 *)(arg0) + (4))) < 0) {
            (*(s32 *)((u8 *)(arg0) + (4))) = 0;
        }
    }
    return var_r31;
}
}

extern "C" {

s32 fn_802F8C58(s32, s32, s32, s32);
s32 fn_802F9D24(s32, s32, s32, s32, s32);

s32 fn_802F8C58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *temp_r8;

    temp_r8 = (*(u8 **)((u8 *)(arg0) + (0x2C)));
    return fn_802F9D24(arg0, arg1, (*(s32 *)((u8 *)(temp_r8) + (0x28))) + arg2, (*(s32 *)((u8 *)(temp_r8) + (0x1C))) - arg2, arg3);
}
}

extern "C" {

s32 fn_802F7408(s32, s32, s32, s32);
void fn_802F76EC(s32 arg0);
s32 fn_802FA068(s32, s32);
void fn_802FA0DC(u8 *arg0, u8 *arg1, u32 arg2);

s32 fn_802FA068(s32 arg0, s32 arg1) {
    s32 spC;
    u8 *sp8;

    spC = 0;
    if (fn_802F7408(arg1, 0, 0, (s32) &sp8) == 0) {
        fn_802FA0DC((u8 *)((s32) &spC), (u8 *)((*(s32 *)((u8 *)(sp8) + (0x18))) + 4), (u32)(4));
        fn_802F76EC((s32)((s32) sp8));
    } else {
        spC = 0;
    }
    return spC;
}
}

extern "C" {

s32 fn_802FEEBC(void);

s32 fn_802FEEBC(void) {
    return fn_802F7C10((u8 *)(fn_802FFE68()));
}
}

extern "C" {

s32 fn_802FF0C4(s32, s32, s32, s32, s32, s32);
s32 fn_802FF0D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);

s32 fn_802FF0C4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    return fn_802FF0D0((s32)(arg0), (s32)(arg1), (s32)(arg2), (s32)(arg3), (s32)(arg4), (s32)(arg5), (s32)(0), (s32)(0));
}
}

extern "C" {

s32 fn_802FF858(s32, s32, s32);
s32 fn_802FF968(s32, s32);

s32 fn_802FF968(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_802FF858(arg0, arg1, 3);
    return (s32) ~(temp_r3 | -temp_r3) >> 0x1F;
}
}

extern "C" {

s32 fn_802FF998(s32, s32);

s32 fn_802FF998(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_802FF858((s32)(arg0), (s32)(arg1), (s32)(4));
    return (s32) ~(temp_r3 | -temp_r3) >> 0x1F;
}
}

extern "C" {

s32 fn_802FF9C8(s32, s32);

s32 fn_802FF9C8(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_802FF858((s32)(arg0), (s32)(arg1), (s32)(0));
    if (temp_r3 != 0) {
        return (*(s32 *)((u8 *)(temp_r3) + (0x2C)));
    }
    return 0;
}
}

extern "C" {

s32 fn_802FFA00(s32, s32);

s32 fn_802FFA00(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_802FF858((s32)(arg0), (s32)(arg1), (s32)(0));
    if (temp_r3 != 0) {
        return (*(s32 *)((u8 *)(temp_r3) + (0x30)));
    }
    return 0;
}
}

extern "C" {

s32 fn_802FFA38(s32, s32);

s32 fn_802FFA38(s32 arg0, s32 arg1) {
    return fn_802FF858((s32)(arg0), (s32)(arg1), (s32)(1));
}
}

extern "C" {

s32 fn_802FFA40(s32, s32);

s32 fn_802FFA40(s32 arg0, s32 arg1) {
    return fn_802FF858((s32)(arg0), (s32)(arg1), (s32)(2));
}
}

extern "C" {

s32 fn_802FFA48(s32, s32);

s32 fn_802FFA48(s32 arg0, s32 arg1) {
    return fn_802FF858((s32)(arg0), (s32)(arg1), (s32)(0));
}
}

extern "C" {

s32 fn_802FFA50(s32, s32);

s32 fn_802FFA50(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_802FF858((s32)(arg0), (s32)(arg1), (s32)(0));
    if (temp_r3 != 0) {
        return (*(s32 *)((u8 *)(temp_r3) + (0x2C)));
    }
    return arg1;
}
}

extern "C" {

s32 fn_802FFA94(s32, s32);

s32 fn_802FFA94(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_802FF858((s32)(arg0), (s32)(arg1), (s32)(0));
    if (temp_r3 != 0) {
        return (*(s32 *)((u8 *)(temp_r3) + (0x30)));
    }
    return arg1;
}
}

extern "C" {

s32 fn_802FFE10(s32, s32);

s32 fn_802FFE10(s32 arg0, s32 arg1) {
    s32 (*temp_r12)(s32, s32, s32);
    s32 var_r3;

    var_r3 = fn_802FF858((s32)(arg0), (s32)(arg1), (s32)(0));
    if (var_r3 != 0) {
        temp_r12 = (*(s32 (**)(s32, s32, s32))((u8 *)(arg1) + (0x38)));
        if (temp_r12 != NULL) {
            var_r3 = temp_r12(arg1, 4, 0);
        }
    }
    return var_r3;
}
}

extern "C" {

s32 IOS_Close(s32);

s32 WD_Cleanup(void) {
    s32 temp_r30;
    s32 temp_r3;
    s32 var_r31;

    temp_r30 = OSDisableInterrupts();
    temp_r3 = IOS_Close(*((s32 *)fn_802EDD5C()));
    var_r31 = temp_r3;
    if (temp_r3 >= 0) {
        *((s32 *)fn_802EDD5C()) = -1;
        var_r31 = fn_802EDE48();
    }
    OSRestoreInterrupts((s32)(temp_r30));
    return var_r31;
}
}

extern "C" {

s32 fn_802EE064(s16 arg0) {
    s32 temp_r31;
    u8 *temp_r3;

    temp_r3 = iosAllocAligned((s32)((*(s32 *)((u8 *)(fn_802EDD5C()) + (8)))), (s32)(0xC), (s32)(0x20));
    (*(s16 *)((u8 *)(temp_r3) + (8))) = arg0;
    (*(u8 **)((u8 *)(temp_r3) + (0))) = (u8 *) (temp_r3 + 8);
    (*(s32 *)((u8 *)(temp_r3) + (4))) = 2;
    temp_r31 = WDi_Ioctlv((s32)(0x1010), (s32)(1), (s32)(0), (u8 *)(temp_r3));
    iosFree((s32)((*(s32 *)((u8 *)(fn_802EDD5C()) + (8)))), (u8 *)(temp_r3));
    return temp_r31;
}
}

extern "C" {

void fn_802F3144(void) {
    ((s32 (*)(s32, s32, s32))OSSendMessage)(lbl_80643030 + 0x66B4, 0, 0);
}
}

extern "C" {

void fn_802F4008(void) {
    ((s32 (*)(void))memset)();
}
}

extern "C" {

void fn_802F62D0(s32 arg0) {
    s32 var_r31;
    s32 *temp_r3;
    s32 sp8;

    if (fn_802F5BC4((s32)((s32)(0)), (s32 *)((s32 *)(&sp8))) == 0) {
        temp_r3 = ((s32 *)fn_802F5AA8((s32)(0xC), (s32)(0x20)));
        if (temp_r3 == NULL) {
            var_r31 = -0x31;
        } else {
            *temp_r3 = arg0;
            var_r31 = IOS_Ioctl((s32)(sp8), (s32)(3), (void *)(temp_r3), (s32)(4), (s32)(0), (s32)(0));
            fn_802F5B90((s32)(0xC), (void *)(temp_r3), (s32)(0x20));
        }
        fn_802F5CAC((s32)(0), (s32)(var_r31));
    }
}
}

extern "C" {

void fn_802F6568(s32 arg0, u8 *arg1) {
    s32 sp8;
    s32 var_r31;
    u8 temp_r0;
    u8 *temp_r3;

    if (fn_802F5BC4((s32)((s32)(0)), (s32 *)((s32 *)(&sp8))) == 0) {
        if ((arg1 == NULL) || (temp_r0 = *arg1, ((temp_r0 > 8U) != 0)) || (temp_r0 < 8U)) {
            var_r31 = -0x1C;
        } else {
            temp_r3 = ((u8 *)fn_802F5AA8((s32)(0xC), (s32)(0x40)));
            if (temp_r3 == NULL) {
                var_r31 = -0x31;
            } else {
                (*(s32 *)((u8 *)(temp_r3) + (0))) = arg0;
                (*(s32 *)((u8 *)(temp_r3) + (4))) = 1;
                ((s32 (*)(u8 *, u8 *, u8))memcpy)(temp_r3 + 8, arg1, *arg1);
                var_r31 = IOS_Ioctl((s32)(sp8), (s32)(2), (void *)(temp_r3), (s32)(0x24), (s32)(0), (s32)(0));
                fn_802F5B90((s32)(0xC), (void *)(temp_r3), (s32)(0x40));
            }
        }
        fn_802F5CAC((s32)(0), (s32)(var_r31));
    }
}
}

extern "C" {

void fn_802F6650(s32 arg0, u8 *arg1) {
    s32 sp8;
    s32 var_r31;
    u8 temp_r0;
    u8 *temp_r3;

    if (fn_802F5BC4((s32)((s32)(0)), (s32 *)((s32 *)(&sp8))) == 0) {
        if ((arg1 == NULL) || (temp_r0 = *arg1, ((temp_r0 > 8U) != 0)) || (temp_r0 < 8U)) {
            var_r31 = -0x1C;
        } else {
            temp_r3 = ((u8 *)fn_802F5AA8((s32)(0xC), (s32)(0x40)));
            if (temp_r3 == NULL) {
                var_r31 = -0x31;
            } else {
                (*(s32 *)((u8 *)(temp_r3) + (0))) = arg0;
                (*(s32 *)((u8 *)(temp_r3) + (4))) = 1;
                ((s32 (*)(u8 *, u8 *, u8))memcpy)(temp_r3 + 8, arg1, *arg1);
                var_r31 = IOS_Ioctl((s32)(sp8), (s32)(4), (void *)(temp_r3), (s32)(0x24), (s32)(0), (s32)(0));
                fn_802F5B90((s32)(0xC), (void *)(temp_r3), (s32)(0x40));
            }
        }
        fn_802F5CAC((s32)(0), (s32)(var_r31));
    }
}
}

extern "C" {

void fn_802F685C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    ((s32 (*)(s32, s32, s32, s32, s32, s32))fn_802F6D84)(0, arg0, arg1, arg2, arg3, 0);
}
}

extern "C" {

void fn_802F68A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    ((s32 (*)(s32, s32, s32, s32, s32, s32))fn_802F7024)(0, arg0, arg1, arg2, arg3, 0);
}
}

extern "C" {

s32 fn_802F5A58(void);

void fn_802F76EC(s32 arg0) {
    s32 temp_r31;

    temp_r31 = OSDisableInterrupts();
    if ((fn_802F5A58() == 1) && (arg0 != 0)) {
        fn_802F5B90((s32)(0xA), (void *)(arg0), (s32)(0x840));
    }
    OSRestoreInterrupts((s32)(temp_r31));
}
}

extern "C" {

void fn_802F7854(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg_sp0) {
    s32 sp8;
    s32 var_r31;
    u8 *temp_r3;

    if (fn_802F5BC4((s32)((s32)(0)), (s32 *)((s32 *)(&sp8))) == 0) {
        if ((arg4 < 0) || (arg4 > 0x14)) {
            var_r31 = -0x1C;
        } else {
            temp_r3 = ((u8 *)fn_802F5AA8((s32)(0xC), (s32)(0x40)));
            if (temp_r3 == NULL) {
                var_r31 = -0x31;
            } else {
                (*(s32 *)((u8 *)(temp_r3) + (0))) = arg0;
                (*(s32 *)((u8 *)(temp_r3) + (4))) = arg1;
                (*(s32 *)((u8 *)(temp_r3) + (8))) = arg2;
                (*(s32 *)((u8 *)(temp_r3) + (0xC))) = arg4;
                if (arg3 != 0) {
                    ((s32 (*)(u8 *, s32, s32))memcpy)(temp_r3 + 0x10, arg3, arg4);
                } else {
                    memset((s32)(temp_r3 + 0x10), (s32)(0), (s32)(arg4));
                }
                var_r31 = IOS_Ioctl((s32)(sp8), (s32)(9), (void *)(temp_r3), (s32)(0x24), (s32)(0), (s32)(0));
                fn_802F5B90((s32)(0xC), (void *)(temp_r3), (s32)(0x40));
            }
        }
        fn_802F5CAC((s32)(0), (s32)(var_r31));
    }
}
}

extern "C" {

s32 fn_802F9880(u8 *arg0) {
    s32 sp8;
    s32 temp_r3;
    s32 var_r0;

    temp_r3 = ((s32 (*)(s32, s32, s32))fn_802F61FC)(2, 1, 0);
    var_r0 = 0;
    sp8 = 0;
    if (arg0 != NULL) {
        var_r0 = (*(s32 *)((u8 *)(arg0) + (0x238)));
        sp8 = var_r0;
    }
    if ((temp_r3 >= 0) && (var_r0 != 0)) {
        ((s32 (*)(s32, s32, s32, s32 *, s32))fn_802F7854)(temp_r3, 0xFFFF, 0x1002, &sp8, 4);
    }
    return temp_r3;
}
}

extern "C" {

s32 fn_802FA2A4(u8 *arg0, s8 arg1) {
    s32 temp_r4;
    s32 temp_r5;
    s32 var_r0;
    s32 var_r0_2;

    if (arg1 == 0x20) {
        (*(s8 *)((u8 *)(arg0) + (0))) = 0x2B;
        return 1;
    }
    if (((arg1 >= 0x30) && (arg1 <= 0x39)) || ((arg1 >= 0x41) && (arg1 <= 0x5A)) || ((arg1 >= 0x61) && (arg1 <= 0x7A))) {
        (*(s8 *)((u8 *)(arg0) + (0))) = arg1;
        return 1;
    }
    temp_r5 = ((u32) arg1 >> 4U) & 0xF;
    (*(s8 *)((u8 *)(arg0) + (0))) = 0x25;
    temp_r4 = arg1 & 0xF;
    var_r0 = temp_r5 + 0x37;
    if (temp_r5 < 0xA) {
        var_r0 = temp_r5 + 0x30;
    }
    (*(s8 *)((u8 *)(arg0) + (1))) = var_r0;
    var_r0_2 = temp_r4 + 0x37;
    if (temp_r4 < 0xA) {
        var_r0_2 = temp_r4 + 0x30;
    }
    (*(s8 *)((u8 *)(arg0) + (2))) = var_r0_2;
    return 3;
}
}

extern "C" {

s32 fn_802F8528(void);

s32 fn_802FCFA4(s32 *arg0) {
    u8 *temp_r3;
    u8 **temp_r3_2;
    s32 temp_r30;
    s32 temp_r29;

    temp_r30 = ((s32)fn_802FFE68());
    temp_r29 = ((s32 (*)(void))fn_802FFEEC)();
    ((s32 (*)(void))fn_802F8444)();
    ((s32)fn_802FFED4((u8 *)(temp_r30)));
    temp_r3 = ((u8 * (*)(void))fn_802F83F0)();
    if (temp_r3 != NULL) {
        temp_r3_2 = ((u8 **)fn_802FFEDC((u8 *)(temp_r30)));
        *arg0 = (*(s32 *)((u8 *)(temp_r3) + (8)));
        *temp_r3_2 = temp_r3;
    } else {
        *arg0 = -1;
    }
    ((s32 (*)(s32))fn_802F8448)(temp_r29);
    if ((s32) *arg0 < 0) {
        ((s32)fn_802FFEE4((u8 *)(temp_r30)));
        fn_802F8528();
        return 0;
    }
    return 1;
}
}

extern "C" {

s32 fn_802F9A38(u8 *, s32, u8 *, s32);
s32 fn_802FAF78(u8 *);
s32 fn_802FB714(u8 *);

s32 fn_802FD338(u8 *arg0) {
    s32 temp_r30;
    s32 temp_r30_2;
    s32 temp_r3;
    u8 **temp_r31;
    u8 *temp_r29;
    u8 *temp_r31_2;

    temp_r30 = ((s32)fn_802FFE68());
    temp_r29 = ((u8 * (*)(void))fn_802FFED0)();
    temp_r31 = ((u8 **)fn_802FFEDC((u8 *)(temp_r30)));
    temp_r30_2 = ((s32)fn_802FFEEC((u8 *)(temp_r30)));
    temp_r31_2 = (*(u8 **)((u8 *)(*temp_r31) + (0xC)));
    (*(s32 *)((u8 *)(arg0) + (0x330))) = 0xA;
    if (((s32) (*(s32 *)((u8 *)(temp_r31_2) + (8))) != 0) && ((s32) (*(s32 *)((u8 *)(temp_r31_2) + (0xC))) != 0)) {
        temp_r3 = fn_802FAF78(arg0);
        if (temp_r3 != 0) {
            return temp_r3;
        }
        if (fn_802FB714(arg0) == 0) {
            return 1;
        }
        if (fn_802F9A38(temp_r29, temp_r30_2, temp_r31_2, (*(s32 *)((u8 *)(temp_r29) + (0x7D0)))) != 0) {
            if (((s32)fn_802F7C10((u8 *)(temp_r29))) != 0) {
                (*(s32 *)((u8 *)(arg0) + (0x330))) = 0xE;
            }
            return 1;
        }
        goto block_10;
    }
block_10:
    return 0;
}
}

extern "C" {

s32 fn_8026FC14(u8 *);
u8 *fn_802F8CC0(s32, s32, s32, s32, s32, s32, s32, s32);

u8 *fn_802FEB18(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg_sp0) {
    u8 *temp_r3_2;
    u8 *temp_r3;
    s32 temp_r31;
    s32 temp_r30;
    s32 temp_r29;

    temp_r30 = ((s32)fn_802FFE68());
    temp_r31 = ((s32 (*)(void))fn_802FFED0)();
    temp_r29 = ((s32)fn_802FFEEC((u8 *)(temp_r30)));
    temp_r3 = ((u8 *)fn_802F7B60((s32)(0x50), (s32)(4)));
    if (temp_r3 == NULL) {
        ((s32 (*)(s32, s32))fn_802F7C00)(temp_r31, 1);
        return NULL;
    }
    temp_r3_2 = fn_802F8CC0(temp_r31, arg0, arg1, arg2, arg3, arg5, 0, 0);
    (*(u8 **)((u8 *)(temp_r3) + (0x2C))) = temp_r3_2;
    if (temp_r3_2 == NULL) {
        ((s32 (*)(u8 *))fn_802F7BBC)(temp_r3);
        return NULL;
    }
    (*(s32 *)((u8 *)(temp_r3) + (0x30))) = (s32) (*(s32 *)((u8 *)(temp_r3_2) + (0x2C)));
    (*(s32 *)((u8 *)(temp_r3) + (0))) = 0;
    (*(s32 *)((u8 *)(temp_r3) + (0x38))) = arg4;
    (*(s32 *)((u8 *)(temp_r3) + (0x40))) = 0;
    (*(s32 *)((u8 *)(temp_r3) + (0x44))) = 0;
    (*(s32 *)((u8 *)(temp_r3) + (0x34))) = -1;
    fn_802FF968((s32)(temp_r29), (s32)(temp_r3));
    (*(s32 *)((u8 *)(temp_r3) + (4))) = 0xF;
    fn_8026FC14(temp_r3 + 0xC);
    ((s32 (*)(u8 *))OSInitMutex)(temp_r3 + 0x14);
    ((s32 (*)(u8 *, s32))fn_802FFEF4)(temp_r3, 0);
    (*(s32 *)((u8 *)(temp_r3) + (0x4C))) = 0;
    return temp_r3;
}
}

extern "C" {

s32 fn_802EDAD8(s32, s32, s32);
s32 fn_802EDC6C(void);
s32 fn_80303D90(void);
s32 fn_80303DA0(void);
__declspec(section ".data") extern s32 lbl_80445AF0;
__declspec(section ".data") extern u8 lbl_80579060;
extern u8 *lbl_806401F4;

s32 fn_802ED204(s8 arg0) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r30;

    if (OSGetCurrentThread() == 0) {
        return -5;
    }
    fn_802EDC6C();
    temp_r3 = fn_80303D90();
    if (temp_r3 == 0) {
        temp_r3_2 = fn_802EDAD8((s32) &lbl_80445AF0, 0, 3);
        var_r30 = temp_r3_2;
        if (temp_r3_2 == 0) {
            (*(s8 *)((u8 *)(lbl_806401F4) + (5))) = arg0;
            var_r30 = fn_802EDAD8((s32) &lbl_80445AF0, 0, 4);
        }
        fn_80303DA0();
    } else if (temp_r3 == -0x16) {
        var_r30 = -4;
    } else {
        var_r30 = -2;
        if (temp_r3 == -0x1D) {
            var_r30 = -8;
        }
    }
    ((s32 (*)(s32))OSUnlockMutex)((s32)(&lbl_80579060));
    return var_r30;
}
}

extern "C" {

s32 fn_802EDFC4(s16 arg0, s32 arg1) {
    s32 temp_r31;
    u8 *temp_r3;

    temp_r3 = (unsigned char *)(((s32)iosAllocAligned((s32)((*(s32 *)((u8 *)(((s32)fn_802EDD5C())) + (8)))), (s32)(0x14), (s32)(0x20))));
    (*(s32 *)((u8 *)(temp_r3) + (0))) = (s32) (temp_r3 + 0x10);
    (*(s16 *)((u8 *)(temp_r3) + (0x10))) = arg0;
    (*(s32 *)((u8 *)(temp_r3) + (8))) = arg1;
    (*(s32 *)((u8 *)(temp_r3) + (4))) = 2;
    (*(s32 *)((u8 *)(temp_r3) + (0xC))) = 0x80;
    temp_r31 = WDi_Ioctlv((s32)(0x1006), (s32)(2), (s32)(0), (u8 *)((s32) temp_r3));
    iosFree((s32)((*(s32 *)((u8 *)(((s32)fn_802EDD5C())) + (8)))), (u8 *)((s32) temp_r3));
    return temp_r31;
}
}

extern "C" {

s32 fn_802EE0EC(u8 *arg0) {
    s32 temp_r31;
    u8 *temp_r0;
    u8 *temp_r3;

    temp_r3 = (unsigned char *)(((s32)iosAllocAligned((s32)((*(s32 *)((u8 *)(((s32)fn_802EDD5C())) + (8)))), (s32)(0x10), (s32)(0x20))));
    temp_r0 = temp_r3 + 8;
    (*(u8 **)((u8 *)(temp_r3) + (0))) = temp_r0;
    ((s32 (*)(s32, s32, s32))memcpy)((s32)(temp_r0), (s32)(arg0), (s32)(6U));
    (*(s32 *)((u8 *)(temp_r3) + (4))) = 6;
    temp_r31 = WDi_Ioctlv((s32)(0x1007), (s32)(1), (s32)(0), (u8 *)((s32) temp_r3));
    iosFree((s32)((*(s32 *)((u8 *)(((s32)fn_802EDD5C())) + (8)))), (u8 *)((s32) temp_r3));
    return temp_r31;
}
}

extern "C" {

s32 OSInitSemaphore(s32, s32);
s32 OSWaitSemaphore(s32);

s32 fn_802F0A58(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r31;

    if (arg2 == 1) {
        OSInitSemaphore(arg1 + 8, 0);
        temp_r31 = OSDisableInterrupts();
        ((s32 (*)(s32, s32, s32))OSSendMessage)(arg0, arg1, 1);
        OSWaitSemaphore(arg1 + 8);
        OSRestoreInterrupts((s32)(temp_r31));
        goto block_4;
    }
    if (((s32 (*)(s32, s32, s32))OSSendMessage)(arg0, arg1, 0) == 0) {
        return -0xED;
    }
block_4:
    return 0;
}
}

extern "C" {

s32 fn_802F1044(s32 arg0) {
    s32 temp_r3;
    s32 var_r0;

    temp_r3 = fn_802EE0EC((u8 *)(arg0));
    var_r0 = -0xFF;
    if ((u32) (temp_r3 + 0x80000000) != 0x8001U) {
        var_r0 = temp_r3;
    }
    return var_r0;
}
}

extern "C" {

extern u8 lbl_80640218;

s32 fn_802F5BC4(s32 arg0, s32 *arg1) {
    s32 var_r30;
    s32 temp_r3;
    s32 temp_r29;

    var_r30 = 0;
    temp_r29 = OSDisableInterrupts();
    switch ((s32) lbl_80640218) {                   /* irregular */
    case 0:
        var_r30 = -0x27;
        break;
    default:
    case 1:
        var_r30 = -0x1C;
        break;
    case 2:
        if ((s32) (*(s32 *)((u8 *)(&lbl_8057AAB8) + (8))) < 0) {
            var_r30 = -0xA;
        } else if (OSGetCurrentThread() == 0) {
            var_r30 = 0x80000000;
        } else {
            *arg1 = (*(s32 *)((u8 *)(&lbl_8057AAB8) + (0xC)));
        }
        break;
    }
    if (var_r30 != 0) {
        temp_r3 = OSGetCurrentThread();
        if (temp_r3 != 0) {
            (*(s32 *)((u8 *)(temp_r3) + (0x30C))) = var_r30;
        } else {
            lbl_8064021C = var_r30;
        }
    }
    OSRestoreInterrupts((s32)(temp_r29));
    return var_r30;
}
}

extern "C" {

void fn_802F7750(s32 arg0, s32 arg1, s32 arg2, u8 *arg3, s32 *arg4) {
    s32 var_r31;
    s32 temp_r5;
    s32 temp_r3_2;
    s32 temp_r3;
    s32 sp8;

    if (fn_802F5BC4((s32)(0), (s32 *)((s32) &sp8)) == 0) {
        temp_r3 = ((s32)fn_802F5AA8((s32)(0xC), (s32)(0x20)));
        if (temp_r3 == 0) {
            var_r31 = -0x31;
        } else {
            (*(s32 *)((u8 *)(temp_r3) + (0))) = arg0;
            (*(s32 *)((u8 *)(temp_r3) + (4))) = arg1;
            (*(s32 *)((u8 *)(temp_r3) + (8))) = arg2;
            temp_r3_2 = IOS_Ioctl((s32)(sp8), (s32)(8), (void *)(0), (s32)(0), (s32)(temp_r3), (s32)(0x18));
            var_r31 = temp_r3_2;
            if ((temp_r3_2 >= 0) && (arg4 != NULL)) {
                temp_r5 = (*(s32 *)((u8 *)(temp_r3) + (0xC)));
                if ((s32) *arg4 >= temp_r5) {
                    if (arg3 != NULL) {
                        ((s32 (*)(s32, s32, s32))memcpy)((s32)(arg3), (s32)(temp_r3 + 0x10), (s32)((u32) temp_r5));
                    }
                    *arg4 = (*(s32 *)((u8 *)(temp_r3) + (0xC)));
                } else {
                    *arg4 = temp_r5;
                    var_r31 = -0x1C;
                }
            }
            fn_802F5B90((s32)(0xC), (void *)(temp_r3), (s32)(0x20));
        }
        fn_802F5CAC((s32)(0), (s32)(var_r31));
    }
}
}

extern "C" {

void fn_802F84E0(s32 arg0, u8 *arg1);
s32 fn_802F855C(s32, s32);
s32 fn_802F95D8(s32);
s32 fn_802FFAD8(void);
s32 printf(s32, ...);
__declspec(section ".data") extern s8 lbl_80446038;

void fn_802F7DA4(s32 arg0, s32 (*arg1)()) {
    s32 (*temp_r12)(s32);
    s32 temp_r30;
    s32 temp_r31;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;

    temp_r30 = ((s32 (*)(void))fn_802FFED0)();
    temp_r3 = ((s32)fn_802FFEE4((u8 *)(arg0)));
    fn_802F855C(temp_r3, 1);
    fn_802F95D8(arg0);
    fn_802F84E0((s32)(temp_r3), (u8 *)(temp_r30));
    temp_r31 = (*(s32 *)((u8 *)(temp_r30) + (0x7E0)));
    temp_r12 = (*(s32 (**)(s32))((u8 *)(((s32)fn_802FFE68())) + (0x7C8)));
    if (temp_r12 != NULL) {
        temp_r12(temp_r31);
    }
    (*(s32 *)((u8 *)(temp_r30) + (0x7E0))) = 0;
    ((s32 (*)(void))fn_802F8440)();
    (*(s32 *)((u8 *)(temp_r30) + (0x7CC))) = 0;
    if (arg1 != NULL) {
        arg1();
    }
    temp_r3_2 = fn_802FFAD8();
    if (temp_r3_2 != 0) {
        printf((s32)(&lbl_80446038), temp_r3_2);
    }
    temp_r3_3 = (*(s32 *)((u8 *)(temp_r30) + (0x7D0)));
    if (temp_r3_3 >= 0) {
        ((s32 (*)(s32))fn_802F62D0)(temp_r3_3);
        (*(s32 *)((u8 *)(temp_r30) + (0x7D0))) = -1;
    }
}
}

extern "C" {

s32 OSCreateThread(s32, s32, s32, s32, s32, s32, s32);
s32 OSResumeThread(s32);

s32 fn_802F844C(s32 arg0, s32 arg1, s32 arg2) {
    if (((s32)fn_802FAA68((u8 *)(arg0))) == 0) {
        OSInitMessageQueue((s32)(arg0), (s32)(arg0 + 0x20), (s32)(3));
        ((s32 (*)(s32))fn_802FAA5C)(arg0);
    }
    OSCreateThread(arg0 + 0x30, (s32) &fn_802F85F4, 0, arg2 + 0x2000, 0x2000, arg1, 0);
    OSResumeThread(arg0 + 0x30);
    return 1;
}
}

extern "C" {

s32 OSJoinThread(s32, s32);

void fn_802F84E0(s32 arg0, u8 *arg1) {
    (*(s32 *)((u8 *)(arg1) + (0x7DC))) = 1;
    ((s32 (*)(s32, s32, s32))OSSendMessage)(arg0, 0, 0);
    OSJoinThread(arg0 + 0x30, 0);
}
}

extern "C" {

void fn_802F8550(s32 arg0) {
    ((s32 (*)(s32, s32, s32))OSSendMessage)(arg0, 0, 0);
}
}

extern "C" {

s32 fn_802F7E88(s32, s32, s32);

void fn_802F85F0(u8 *arg0, s32 arg1) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r3;
    u8 *temp_r30;

    temp_r3 = OSDisableInterrupts();
    temp_r0 = (*(s32 *)((u8 *)(arg0) + (8))) + 1;
    (*(s32 *)((u8 *)(arg0) + (8))) = temp_r0;
    if (temp_r0 == 1) {
        (*(s32 *)((u8 *)(arg0) + (0xC))) = temp_r3;
    }
    temp_r30 = arg0 + (arg1 * 0x34);
    fn_802F7E88((s32) arg0, arg1, 0);
    (*(s32 *)((u8 *)(temp_r30) + (0x2C))) = 0;
    ((s32 (*)(s32, s32, s32))fn_802F4008)((s32) (temp_r30 + 0x30), 0, 0x20);
    ((s32 (*)(s32, s32, s32))fn_802F4008)((s32) (temp_r30 + 0x50), 0, 4);
    (*(s32 *)((u8 *)(temp_r30) + (0x54))) = 0;
    (*(s32 *)((u8 *)(temp_r30) + (0x58))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x20))) = (s32) ((*(s32 *)((u8 *)(arg0) + (0x20))) | (1 << arg1));
    fn_802F7E88((s32) arg0, arg1, 1);
    temp_r0_2 = (*(s32 *)((u8 *)(arg0) + (8))) - 1;
    (*(s32 *)((u8 *)(arg0) + (8))) = temp_r0_2;
    if (temp_r0_2 == 0) {
        OSRestoreInterrupts((s32)((*(s32 *)((u8 *)(arg0) + (0xC)))));
    }
}
}

extern "C" {

s32 SSLShutdown(s32);

void fn_802F990C(s32 arg0, u8 *arg1, s32 arg2) {
    s32 temp_r3;

    ((s32 (*)(s32))fn_802F8444)(arg0);
    temp_r3 = (*(s32 *)((u8 *)(arg1) + (0xAC)));
    if (temp_r3 > 0) {
        SSLShutdown(temp_r3);
        (*(s32 *)((u8 *)(arg1) + (0xAC))) = -1;
    }
    ((s32 (*)(s32))fn_802F8448)(arg0);
    ((s32 (*)(s32))fn_802F62D0)(arg2);
}
}

extern "C" {

void fn_802FA014(s32 arg0, s32 arg1, s32 arg2) {
    ((s32 (*)(s32))fn_802F8444)(arg0);
    if (arg2 >= 0) {
        ((s32 (*)(s32, s32))fn_802F69FC)(arg2, 2);
    }
    ((s32 (*)(s32))fn_802F8448)(arg0);
}
}

extern "C" {

void fn_802FA0DC(u8 *arg0, u8 *arg1, u32 arg2) {
    ((s32 (*)(s32, s32, s32))memcpy)((s32)(arg0), (s32)(arg1), (s32)(arg2));
}
}

extern "C" {

void fn_802FA0E8(u8 *arg0, u32 arg1) {
    memset((s32)((s32)(arg0)), (s32)((s32)(0)), (s32)((s32)(arg1)));
}
}

extern "C" {

s32 fn_802F9454(s32, s32);

s32 fn_802FEC40(s32 arg0) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r4;

    temp_r3 = ((s32)fn_802FFE68());
    temp_r3_2 = fn_802FFA48((s32)(((s32)fn_802FFEEC((u8 *)(temp_r3)))), (s32)(arg0));
    if (temp_r3_2 == 0) {
        return -1;
    }
    temp_r4 = (*(s32 *)((u8 *)(temp_r3_2) + (0x2C)));
    if (temp_r4 == 0) {
        return -1;
    }
    temp_r3_3 = fn_802F9454(temp_r3, temp_r4);
    (*(s32 *)((u8 *)(temp_r3_2) + (0x34))) = temp_r3_3;
    if (temp_r3_3 >= 0) {
        (*(s32 *)((u8 *)(temp_r3_2) + (0))) = 1;
    }
    return 0;
}
}

extern "C" {

s32 fn_802FECCC(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;

    temp_r3_2 = ((s32)fn_802FFEEC((u8 *)(((s32)fn_802FFE68()))));
    temp_r3_3 = fn_802FFA48((s32)(temp_r3_2), (s32)(arg0));
    if (temp_r3_3 != 0) {
        temp_r3 = fn_802FFA00((s32)(temp_r3_2), (s32)(temp_r3_3));
        if (temp_r3 != 0) {
            *arg1 = (*(s32 *)((u8 *)(temp_r3) + (0x28)));
            *arg2 = (*(s32 *)((u8 *)(temp_r3) + (0x1C)));
            return (*(s32 *)((u8 *)(temp_r3) + (4)));
        }
        return -1;
    }
    return -1;
}
}

extern "C" {

s32 fn_802FED68(s32 arg0) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;

    temp_r3_2 = ((s32)fn_802FFEEC((u8 *)(((s32)fn_802FFE68()))));
    temp_r3_3 = fn_802FFA48((s32)(temp_r3_2), (s32)(arg0));
    if (temp_r3_3 != 0) {
        temp_r3 = fn_802FFA00((s32)(temp_r3_2), (s32)(temp_r3_3));
        if (temp_r3 != 0) {
            return (*(s32 *)((u8 *)(temp_r3) + (0x438)));
        }
        return 0;
    }
    return 0;
}
}

extern "C" {

s32 fn_802FEDDC(s32 arg0) {
    s32 temp_r3;

    temp_r3 = fn_802FFA48((s32)(((s32)fn_802FFEEC((u8 *)(((s32)fn_802FFE68()))))), (s32)(arg0));
    if (temp_r3 != 0) {
        return (*(s32 *)((u8 *)(temp_r3) + (4)));
    }
    return -1;
}
}

extern "C" {

s32 fn_802F9278(s32, s32);
void fn_802FEEE0(void);

s32 fn_802FF0D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 var_r4;

    temp_r3_2 = ((s32 (*)(s32, s32, s32, s32, s32, s32))fn_802FEB18)(arg0, arg1, arg2, arg3, (s32) &fn_802FEEE0, arg5);
    var_r4 = 0;
    if (temp_r3_2 != 0) {
        temp_r3_3 = ((s32)fn_802FFE68());
        temp_r3_4 = ((s32)fn_802FFEEC((u8 *)(temp_r3_3)));
        temp_r3_5 = fn_802FFA48((s32)(temp_r3_4), (s32)(temp_r3_2));
        temp_r3 = fn_802FF9C8((s32)(temp_r3_4), (s32)(temp_r3_5));
        var_r4 = temp_r3;
        if (temp_r3 != 0) {
            if ((u8 *) (*(u8 **)((u8 *)(temp_r3) + (0x2C))) != NULL) {
                (*(s32 *)((u8 *)(temp_r3_5) + (0x4C))) = arg4;
                (*(s32 *)((u8 *)((*(u8 **)((u8 *)(temp_r3) + (0x2C)))) + (0x2C))) = arg6;
                (*(s32 *)((u8 *)((*(u8 **)((u8 *)(temp_r3) + (0x2C)))) + (0x30))) = arg7;
                return temp_r3;
            }
            fn_802F9278(temp_r3_3, var_r4);
            fn_802FF998((s32)(temp_r3_4), (s32)(temp_r3_5));
            ((s32 (*)(s32))fn_802F7BBC)(temp_r3_5);
            var_r4 = 0;
            goto block_5;
        }
    }
block_5:
    return var_r4;
}
}

extern "C" {

s32 fn_802FF2D0(s32 arg0) {
    s32 temp_r3;

    temp_r3 = fn_802FFA38((s32)(((s32)fn_802FFEEC((u8 *)(((s32)fn_802FFE68()))))), (s32)(arg0));
    if ((temp_r3 != 0) && (fn_802FEC40((s32)(temp_r3)) == 0)) {
        return (*(s32 *)((u8 *)(temp_r3) + (0x34)));
    }
    return -1;
}
}

extern "C" {

s32 fn_802F9680(s32, s32);

void fn_802FF36C(s32 arg0) {
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3 = ((s32)fn_802FFEEC((u8 *)(((s32)fn_802FFE68()))));
    temp_r3_2 = fn_802FFA40((s32)(temp_r3), (s32)(arg0));
    if (temp_r3_2 != 0) {
        if (fn_802FFA00((s32)(temp_r3), (s32)(temp_r3_2)) != 0) {
            fn_802F9680(temp_r3, (*(s32 *)((u8 *)(temp_r3_2) + (0x30))));
        }
        fn_802FF998((s32)(temp_r3), (s32)(temp_r3_2));
        ((s32 (*)(s32))fn_802F7BBC)(temp_r3_2);
    }
}
}

extern "C" {

s32 fn_802FF3F0(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_802FFA40((s32)(((s32)fn_802FFEEC((u8 *)(((s32)fn_802FFE68()))))), (s32)(arg0));
    if (temp_r3 != 0) {
        sp8 = 0;
        return fn_802FECCC((s32)(temp_r3), (s32 *)(arg1), (s32 *)((s32) &sp8));
    }
    return -1;
}
}

extern "C" {

s32 fn_802FF458(s32 arg0) {
    s32 temp_r3;

    temp_r3 = fn_802FFA94((s32)(((s32)fn_802FFEEC((u8 *)(((s32)fn_802FFE68()))))), (s32)(arg0));
    if (temp_r3 == 0) {
        return -1;
    }
    if ((s32) (*(s32 *)((u8 *)(temp_r3) + (0x14))) != 0) {
        return (*(s32 *)((u8 *)(temp_r3) + (0x18)));
    }
    return -1;
}
}

extern "C" {

s32 fn_802FF4B8(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_802FFA50((s32)(((s32)fn_802FFEEC((u8 *)(((s32)fn_802FFE68()))))), (s32)(arg0));
    if (temp_r3 == 0) {
        return -1;
    }
    (*(s32 *)((u8 *)(temp_r3) + (0xCC))) = arg1;
    return 0;
}
}

extern "C" {

s32 fn_802FF798(s32 arg0) {
    s32 temp_r3;

    temp_r3 = fn_802FFA50((s32)(((s32)fn_802FFEEC((u8 *)(((s32)fn_802FFE68()))))), (s32)(arg0));
    if (temp_r3 == 0) {
        return -1;
    }
    (*(s32 *)((u8 *)(temp_r3) + (0xC8))) = 1;
    (*(s32 *)((u8 *)(temp_r3) + (0xB0))) = 0;
    (*(s32 *)((u8 *)(temp_r3) + (0xB4))) = 0;
    (*(s32 *)((u8 *)(temp_r3) + (0xB8))) = 0;
    (*(s32 *)((u8 *)(temp_r3) + (0xBC))) = 0;
    return 0;
}
}

extern "C" {

s32 fn_802FF800(s32 arg0) {
    s32 temp_r3;

    temp_r3 = fn_802FFA50((s32)(((s32)fn_802FFEEC((u8 *)(((s32)fn_802FFE68()))))), (s32)(arg0));
    if (temp_r3 == 0) {
        return -1;
    }
    (*(s32 *)((u8 *)(temp_r3) + (0xC0))) = 0;
    (*(s32 *)((u8 *)(temp_r3) + (0xC4))) = 0;
    return 0;
}
}

extern "C" {

s32 fn_802F0B14(u8 *, s32 *);
extern s32 lbl_806401FC;
extern u8 lbl_80643038;

s32 fn_802F1C1C() {
    u8 *var_r31;
    u32 var_r30;
    u32 temp_r29;
    s32 temp_r3;

    if ((s32) lbl_806401F8 == 0) {
        return -0xEC;
    }
    if ((s32) lbl_806401FC != 0) {
        return -1;
    }
    var_r30 = 0U;
    temp_r29 = (*(u32 *)((u8 *)((*(u8 *(*))&lbl_80643030)) + (0x5760)));
    var_r31 = (*(u8 *(*))&lbl_80643030) + 0x5772;
loop_5:
    if ((var_r30 != temp_r29) && (fn_802F0B14((u8 *)(var_r31), (s32 *)(&lbl_80643038)) == 0)) {
        temp_r3 = fn_802F1F30((s32)(var_r30), (s32)(0), (s32)(0));
        if (temp_r3 < 0) {
            return temp_r3;
        }
    }
    var_r30 += 1;
    var_r31 += 6;
    if (var_r30 >= 0x10U) {
        return 0;
    }
    goto loop_5;
}
}

extern "C" {

void fn_802F1EA4() {
    u8 *temp_r31;

    temp_r31 = (*(u8 *(*))&lbl_80643030);
    if (temp_r31 != NULL) {
        (*(s32 *)((u8 *)(temp_r31) + (0x5760))) = 0;
        (*(s32 *)((u8 *)(temp_r31) + (0x5764))) = 0;
        memset((s32)(temp_r31 + 0x5772), (s32)(0), (s32)(0x60));
        memset((s32)(temp_r31 + 0x6504), (s32)(0), (s32)(0x20));
        memset((s32)(temp_r31 + 0x6084), (s32)(0), (s32)(0x400));
        memset((s32)(temp_r31 + 0x6484), (s32)(0), (s32)(0x40));
        memset((s32)(temp_r31 + 0x64C4), (s32)(0), (s32)(0x40));
    }
}
}

extern "C" {

void fn_802F320C() {
    u8 *temp_r31;

    temp_r31 = (*(u8 *(*))&lbl_80643030);
    if (temp_r31 != NULL) {
        if ((s32) (*(u16 *)((u8 *)(temp_r31) + (0x7290))) != 0) {
            OSJoinThread((s32)(temp_r31 + 0x6FC8), (s32)(0));
        }
        memset((s32)(temp_r31 + 0x6FC8), (s32)(0), (s32)(0x318));
    }
}
}

extern "C" {

s32 fn_802F3AB0() {
    u8 *temp_r30;

    temp_r30 = (*(u8 *(*))&lbl_80643030);
    OSInitMessageQueue((s32)(temp_r30 + 0x6524), (s32)(temp_r30 + 0x6544), (s32)(0x20));
    ((s32 (*)(u8 *))OSInitMutex)(temp_r30 + 0x65DC);
    memset((s32)(temp_r30 + 0x5560), (s32)(0), (s32)(0x80));
    (*(s32 *)((u8 *)(temp_r30) + (0x65F4))) = 0;
    memset((s32)(temp_r30 + 0x65F8), (s32)(0), (s32)(0x14));
    (*(s32 *)((u8 *)(temp_r30) + (0x660C))) = 0;
    (*(s32 *)((u8 *)(temp_r30) + (0x6610))) = 0;
    return 0;
}
}

extern "C" {

s32 fn_802F5018(void);

s32 fn_802F4FE8(s32 arg0, s32 arg1) {
    return fn_802F5018() - arg1;
}
}

extern "C" {

s32 fn_802F7E94(u8 *);

s32 fn_802F8008(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (4))) != 0) {
        return 0;
    }
    return fn_802F7E94(arg0 + 0x30);
}
}

extern "C" {

u8 **fn_802F7FC0(u8 ***arg0) {
    u8 **temp_r5;
    u8 *temp_r4;

    temp_r5 = *arg0;
    if (temp_r5 != NULL) {
        temp_r4 = (*(u8 **)((u8 *)(temp_r5) + (0)));
        if ((u32) (u32) temp_r5 != (u32) temp_r4) {
            (*(u8 ***)((u8 *)(temp_r4) + (4))) = (u8 **) (*(u8 ***)((u8 *)(temp_r5) + (4)));
            *(*(u8 ***)((u8 *)(temp_r5) + (4))) = (*(u8 **)((u8 *)(temp_r5) + (0)));
            *arg0 = (*(u8 ***)((u8 *)(temp_r5) + (4)));
        } else {
            *arg0 = NULL;
        }
    }
    return temp_r5;
}
}
