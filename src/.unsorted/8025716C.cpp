#include ".unsorted/8025716C.hpp"

#include "common.hpp"

extern "C" {

u8 fn_8025821C(u8 *p) {
    return *(u8 *)(p + 0x69);
}
void fn_80259930(void) {}
void fn_80259934(void) {}
}

extern "C" {

s32 OSReceiveMessage(s32, s32 *, s32);

s32 fn_802571A0(s32 arg0) {
    s32 sp8;

    if (OSReceiveMessage(arg0 + 0x2E4, &sp8, 0) != 0) {
        return sp8;
    }
    return 0;
}
}

extern "C" {

s32 fn_8025ACE0(u8 *, u8 *);
s32 fn_8025B0C4(u8 *, u8 *);
s32 fn_8025B60C(u8 *, u8 *);

void fn_80257BEC(u8 *arg0) {
    s32 var_r31;
    s32 var_r31_2;
    s32 var_r31_3;
    u8 *var_r30;
    u8 *var_r30_2;
    u8 *var_r30_3;

    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x6D))) == 0) {
        var_r30 = arg0 + 0xD0;
        var_r31 = 0;
        do {
            fn_8025ACE0(arg0, var_r30);
            var_r31 += 1;
            var_r30 += 8;
        } while (var_r31 < 0xA);
    }
    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x6B))) != 0) {
        var_r30_2 = arg0 + 0x150;
        var_r31_2 = 0;
        do {
            fn_8025B0C4(arg0, var_r30_2);
            var_r31_2 += 1;
            var_r30_2 += 0xC;
        } while (var_r31_2 < 6);
    }
    var_r30_3 = arg0 + 0x120;
    var_r31_3 = 0;
    do {
        fn_8025B60C(arg0, var_r30_3);
        var_r31_3 += 1;
        var_r30_3 += 0x10;
    } while (var_r31_3 < 3);
}
}

extern "C" {

void fn_802590C0(u8 *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = (*(s32 *)((u8 *)(arg0) + (0x1A0)));
    *arg2 = (*(s32 *)((u8 *)(arg0) + (0x1A4)));
}
}

extern "C" {

s32 AXRegisterCallback(s32);
s32 fn_801DBA8C__7GScacheFv(void);
s32 fn_80297B98(void);
s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;
extern u8 lbl_8063F91E;
extern s32 lbl_8063F920;
extern s32 lbl_8063F924;
extern u8 *sInstance__8GSrender;

void fn_80259390(u8 *arg0) {
    if ((s32) lbl_8063F91E != 0) {
        fn_801DBA8C__7GScacheFv();
        (*(s32 *)((u8 *)(sInstance__8GSrender) + (0x74))) = (s32) lbl_8063F920;
        lbl_8063F920 = 0;
        AXRegisterCallback(lbl_8063F924);
        lbl_8063F924 = 0;
        fn_80297B98();
        freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, (*(s32 *)((u8 *)(arg0) + (0x18))));
        (*(s32 *)((u8 *)(arg0) + (0x18))) = 0;
        lbl_8063F91E = 0;
    }
}
}

extern "C" {

u8 *fn_80259420(void);

void fn_802598A0(void) {
    u8 *temp_r3;

    temp_r3 = fn_80259420();
    if (temp_r3 != NULL) {
        (*(u8 *)((u8 *)(temp_r3) + (0x69))) = (u8) (*(u8 *)((u8 *)(temp_r3) + (0x68)));
        (*(s8 *)((u8 *)(temp_r3) + (0x71))) = 1;
    }
}
}

extern "C" {

s32 fn_80259938(void) {
    u8 temp_r0;
    u8 *temp_r3;

    temp_r3 = fn_80259420();
    if ((temp_r3 == NULL) || ((s32) (*(u8 *)((u8 *)(temp_r3) + (0x6C))) == 0) || (temp_r0 = (*(u8 *)((u8 *)(temp_r3) + (0x69))), ((temp_r0 == 0xB) != 0))) {
        return -1;
    }
    if (((s32) temp_r0 == 0) || (temp_r0 == 9)) {
        return 0;
    }
    return 1;
}
}

extern "C" {

s32 OSSendMessage(s32, s32, s32);
s32 fn_8025716C(s32, s32);

s32 fn_8025716C(s32 arg0, s32 arg1) {
    return OSSendMessage(arg0 + 0x2E4, arg1, 0) != 0;
}
}

extern "C" {

s32 AXSetVoiceState(s32, s32);
s32 fn_80259000(s32);

s32 fn_80259000(s32 arg0) {
    s32 temp_r0;
    s32 var_r3;

    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x1A0)));
    if (temp_r0 != 0) {
        AXSetVoiceState(temp_r0, 1);
    }
    var_r3 = (*(s32 *)((u8 *)(arg0) + (0x1A4)));
    if (var_r3 != 0) {
        var_r3 = AXSetVoiceState(var_r3, 1);
    }
    return var_r3;
}
}

extern "C" {

s32 AXFreeVoice(s32);
s32 fn_80259054(s32);
s32 fn_80299274(s32);

s32 fn_80259054(s32 arg0) {
    s32 temp_r0;
    s32 var_r3;

    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x1A0)));
    if (temp_r0 != 0) {
        fn_80299274(temp_r0);
        AXFreeVoice((*(s32 *)((u8 *)(arg0) + (0x1A0))));
        (*(s32 *)((u8 *)(arg0) + (0x1A0))) = 0;
    }
    var_r3 = (*(s32 *)((u8 *)(arg0) + (0x1A4)));
    if (var_r3 != 0) {
        fn_80299274(var_r3);
        var_r3 = AXFreeVoice((*(s32 *)((u8 *)(arg0) + (0x1A4))));
        (*(s32 *)((u8 *)(arg0) + (0x1A4))) = 0;
    }
    return var_r3;
}
}

extern "C" {

s32 fn_802598D8();


}

extern "C" {

s32 findTarget__14GSrenderTargetFl(s32);
s32 fn_8023B3B8__14GSrenderTargetFUl(s32, s32);
s32 memset(s32, s32, s32);
s32 streamFsys__6GSfsysFUl(s32);
extern u8 *lbl_8063F928;

s32 fn_802575E4(u8 *arg0, s32 arg1, s8 arg2, s8 arg3, s8 arg4, s32 arg5) {
    s32 temp_r3;
    s32 temp_r3_2;
    u32 temp_r31;
    u32 temp_r31_2;

    memset((s32)(arg0 + 0x48), (s32)(0), (s32)(0xC));
    memset((s32)(arg0 + 0x54), (s32)(0), (s32)(0x10));
    if (streamFsys__6GSfsysFUl(arg1) == 0) {
        return 0;
    }
    (*(s32 *)((u8 *)(arg0) + (0))) = arg1;
    (*(s8 *)((u8 *)(arg0) + (0x6A))) = 1;
    (*(s8 *)((u8 *)(arg0) + (0x69))) = 1;
    (*(s8 *)((u8 *)(arg0) + (0x68))) = 1;
    (*(s8 *)((u8 *)(arg0) + (0x6D))) = arg3;
    (*(s8 *)((u8 *)(arg0) + (0x6E))) = arg4;
    (*(s8 *)((u8 *)(arg0) + (0x74))) = arg2;
    (*(s32 *)((u8 *)(arg0) + (0x1FC))) = arg5;
    (*(s8 *)((u8 *)(arg0) + (0x6C))) = 1;
    (*(s8 *)((u8 *)(arg0) + (0x70))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x6F))) = 1;
    (*(s32 *)((u8 *)(arg0) + (0x1F8))) = 0;
    if (arg5 != 0) {
        temp_r31 = (*(u32 *)((u8 *)(lbl_8063F928) + (0x10)));
        temp_r3 = findTarget__14GSrenderTargetFl((s32) (u8) (temp_r31 >> 0x10U));
        if (temp_r3 != 0) {
            fn_8023B3B8__14GSrenderTargetFUl(temp_r3, (s32) temp_r31);
        }
    } else {
        temp_r31_2 = (*(u32 *)((u8 *)(lbl_8063F928) + (0x14)));
        temp_r3_2 = findTarget__14GSrenderTargetFl((s32) (u8) (temp_r31_2 >> 0x10U));
        if (temp_r3_2 != 0) {
            fn_8023B3B8__14GSrenderTargetFUl(temp_r3_2, (s32) temp_r31_2);
        }
    }
    return 1;
}
}

extern "C" {

s32 fn_8023B420__14GSrenderTargetFUl(s32, s32);
s32 fn_80249890__6GSfsysFUl(s32);
s32 fn_802580C0(s32);
s32 free__5GSmemFPv(s32);

void fn_802576E8(u8 *arg0) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    u32 temp_r31;
    u32 temp_r31_2;

    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x6C))) != 0) {
        if ((s32) (*(s32 *)((u8 *)(arg0) + (0x1FC))) != 0) {
            temp_r31 = (*(u32 *)((u8 *)(lbl_8063F928) + (0x10)));
            temp_r3 = findTarget__14GSrenderTargetFl((s32)((s32) (u8) (temp_r31 >> 0x10U)));
            if (temp_r3 != 0) {
                fn_8023B420__14GSrenderTargetFUl(temp_r3, (s32) temp_r31);
            }
        } else {
            temp_r31_2 = (*(u32 *)((u8 *)(lbl_8063F928) + (0x14)));
            temp_r3_2 = findTarget__14GSrenderTargetFl((s32)((s32) (u8) (temp_r31_2 >> 0x10U)));
            if (temp_r3_2 != 0) {
                fn_8023B420__14GSrenderTargetFUl(temp_r3_2, (s32) temp_r31_2);
            }
        }
        fn_802580C0((s32) arg0);
        fn_80249890__6GSfsysFUl((*(s32 *)((u8 *)(arg0) + (0))));
        temp_r3_3 = (*(s32 *)((u8 *)(arg0) + (0x19C)));
        (*(u8 *)((u8 *)(arg0) + (0x6C))) = 0U;
        (*(s8 *)((u8 *)(arg0) + (0x6F))) = 0;
        if (temp_r3_3 != 0) {
            free__5GSmemFPv(temp_r3_3);
            (*(s32 *)((u8 *)(arg0) + (0x19C))) = 0;
        }
    }
}
}

extern "C" {

s32 fn_802578F8(s32);
s32 fn_80257CA8(s32, s32, s32, s32);
s32 readFsysStream__6GSfsysFUlUlPvUlUlPFUlUlUl_vUlUl(s32, s32, s32, s32, s32, s32, s32, s32);
__declspec(section ".data") extern s32 lbl_804FDC20;

s32 fn_80257CEC(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_r4;

    if (((s32) (*(u8 *)((u8 *)(arg0) + (0x6C))) == 0) || ((u8) (*(u8 *)((u8 *)(arg0) + (0x69))) != 2)) {
        return 0;
    }
    if (fn_802578F8((s32) arg0) == 0) {
        ((s32 (*)(s32))fn_802576E8)((s32) arg0);
        return 0;
    }
    (*(u8 *)((u8 *)(arg0) + (0x69))) = 3U;
    if (arg1 > 0) {
        temp_r4 = (*(s32 *)((u8 *)(arg0) + (0x28)));
        if (temp_r4 == 0) {
            return 0;
        }
        if ((u32) (*(u32 *)((u8 *)(arg0) + (0x18))) > (u32) arg1) {
            if (readFsysStream__6GSfsysFUlUlPvUlUlPFUlUlUl_vUlUl((*(s32 *)((u8 *)(arg0) + (0))), 0, (s32) &lbl_804FDC20, 0x20, temp_r4 + ((arg1 - 1) * 4), (s32) fn_80257CA8, (s32) arg0, arg1) == 0) {
                return 0;
            }
            goto block_13;
        }
        return 0;
    }
    (*(s16 *)((u8 *)(&lbl_804FDC20) + (0))) = 0;
    (*(s16 *)((u8 *)(&lbl_804FDC20) + (2))) = (s16) (*(s32 *)((u8 *)(arg0) + (0x1C)));
    fn_80257CA8(0, (s32) arg0, 0, (s32) &lbl_804FDC20);
block_13:
    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x6B))) != 0) {
        if ((arg2 < 0) || ((u32) arg2 >= (u32) (*(u32 *)((u8 *)(arg0) + (0x60))))) {
            return 0;
        }
        (*(s32 *)((u8 *)(arg0) + (0xBC))) = arg2;
        goto block_18;
    }
block_18:
    (*(s32 *)((u8 *)(arg0) + (0xA0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xB8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x9C))) = 0;
    return 1;
}
}

extern "C" {

s32 fn_80258280(s32);
s32 fn_8025A710(s32);
s32 fn_8025A7A8(s32);
s32 fn_8025AD84(s32);
s32 fn_8025AE20(s32);
s32 fn_8025B164(s32);
s32 fn_8025B200(s32);

void fn_80257E4C(s32 arg0, u8 *arg1, s32 arg2) {
    (*(s32 *)((u8 *)(arg1) + (0x198))) = arg2;
    if ((s32) (*(u8 *)((u8 *)(arg1) + (0x6D))) == 0) {
        fn_8025A710((s32) arg1);
    }
    if ((s32) (*(u8 *)((u8 *)(arg1) + (0x6B))) != 0) {
        fn_8025AD84((s32) arg1);
    }
    fn_8025B164((s32) arg1);
    (*(s32 *)((u8 *)(arg1) + (0xC0))) = -1;
    (*(s32 *)((u8 *)(arg1) + (0xC4))) = 0;
    (*(s32 *)((u8 *)(arg1) + (0xC8))) = 0;
    (*(s32 *)((u8 *)(arg1) + (0xCC))) = 0;
    ((s32 (*)(s32))fn_80257BEC)((s32) arg1);
    fn_8025B200((s32) arg1);
    if ((s32) (*(u8 *)((u8 *)(arg1) + (0x6B))) != 0) {
        fn_8025AE20((s32) arg1);
    }
    if ((s32) (*(u8 *)((u8 *)(arg1) + (0x6D))) == 0) {
        fn_8025A7A8((s32) arg1);
    }
    (*(s8 *)((u8 *)(arg1) + (0x69))) = 7;
    (*(s8 *)((u8 *)(arg1) + (0x68))) = 7;
    (*(s8 *)((u8 *)(arg1) + (0x6A))) = 0;
    if ((s32) (*(u8 *)((u8 *)(arg1) + (0x6B))) != 0) {
        fn_80258280((s32) arg1);
    }
}
}

extern "C" {

s32 fn_80257F20(u8 *arg0) {
    s32 temp_r5;
    s32 temp_r7;

    if (((s32) (*(u8 *)((u8 *)(arg0) + (0x6C))) == 0) || ((u8) (*(u8 *)((u8 *)(arg0) + (0x69))) != 5)) {
        return 0;
    }
    (*(u8 *)((u8 *)(arg0) + (0x69))) = 6U;
    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x6D))) != 0) {
        temp_r5 = (*(s32 *)((u8 *)(arg0) + (0x78)));
        temp_r7 = (*(s32 *)((u8 *)(arg0) + (0x2C)));
        if (readFsysStream__6GSfsysFUlUlPvUlUlPFUlUlUl_vUlUl((s32)((*(s32 *)((u8 *)(arg0) + (0)))), (s32)(0), (s32)(temp_r5), (s32)((*(s32 *)((u8 *)(arg0) + (0x7C)))), (s32)(temp_r7), (s32)((s32) fn_80257E4C), (s32)((s32) arg0), (s32)((temp_r5 + (*(s32 *)((u8 *)(arg0) + (0x84)))) - temp_r7)) == 0) {
            return 0;
        }
        goto block_7;
    }
    ((s32 (*)(s32, s32, s32))fn_80257E4C)(0, (s32) arg0, 0);
block_7:
    return 1;
}
}

extern "C" {

void fn_802589B4(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r0;
    u8 *temp_r4;

    temp_r4 = arg0 + ((*(s32 *)((u8 *)(arg0) + (0x1DC))) * 8);
    (*(s32 *)((u8 *)(temp_r4) + (0x1B4))) = arg3;
    (*(s32 *)((u8 *)(temp_r4) + (0x1B0))) = arg2;
    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x1DC))) + 1;
    (*(s32 *)((u8 *)(arg0) + (0x1DC))) = temp_r0;
    if (temp_r0 >= 5) {
        (*(s32 *)((u8 *)(arg0) + (0x1DC))) = 0;
    }
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 __dla__FPv(s32);
s32 __dt__14GSrenderModuleFv(s32, s32);
__declspec(section ".data") extern s32 lbl_80424F28;
extern s32 lbl_8063F918;
extern s16 lbl_8063F91C;

u8 *fn_80259248(u8 *arg0, s32 arg1) {
    if (arg0 != NULL) {
        (*(s32 **)((u8 *)(arg0) + (0xC))) = &lbl_80424F28;
        if ((s32) lbl_8063F918 != 0) {
            __dla__FPv(lbl_8063F918);
            lbl_8063F918 = 0;
            lbl_8063F91C = 0;
        }
        ((s32 (*)(s32))fn_80259390)((s32) arg0);
        lbl_8063F928 = 0;
        __dt__14GSrenderModuleFv((s32) arg0, 0);
        if (arg1 > 0) {
            __dl__FPv((s32) arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_802598D8() {
    s32 var_r4;
    u32 temp_r3;

    if (((s32)fn_80259420()) == 0) {
        return 0;
    }
    temp_r3 = ((u32 (*)(void))fn_8025821C)();
    var_r4 = 0;
    if ((temp_r3 > 0xBU) || !((1 << temp_r3) & 0xA01)) {
        var_r4 = 1;
    }
    return var_r4;
}
}
