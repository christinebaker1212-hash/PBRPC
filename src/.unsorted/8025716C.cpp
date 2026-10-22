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

s32 fn_802598D8(s32);

s32 fn_802598D8(s32 arg0) {
    s32 temp_r3;
    s32 var_r4;
    u32 temp_r3_2;

    temp_r3 = ((s32 (*)(s32))fn_80259420)(arg0);
    if (temp_r3 == 0) {
        return 0;
    }
    temp_r3_2 = fn_8025821C((u8 *)(temp_r3));
    var_r4 = 0;
    if ((temp_r3_2 > 0xBU) || !((1 << temp_r3_2) & 0xA01)) {
        var_r4 = 1;
    }
    return var_r4;
}
}
