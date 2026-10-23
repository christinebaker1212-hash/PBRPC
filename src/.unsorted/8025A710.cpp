#include ".unsorted/8025A710.hpp"

#include "common.hpp"

extern "C" {

s32 OSReceiveMessage(s32, s32 *, s32);

s32 fn_8025ACEC(s32 arg0) {
    s32 sp8;

    OSReceiveMessage(arg0 + 0x254, &sp8, 1);
    return sp8;
}
}

extern "C" {

s32 fn_8025AD28(s32 arg0) {
    s32 sp8;

    OSReceiveMessage(arg0 + 0x29C, &sp8, 1);
    return sp8;
}
}

extern "C" {

s32 OSSendMessage(s32, s32, s32);
s32 fn_8025ACE0(s32, s32);

s32 fn_8025ACE0(s32 arg0, s32 arg1) {
    return OSSendMessage(arg0 + 0x20C, arg1, 1);
}
}

extern "C" {

s32 OSInitMessageQueue(s32, s32, s32);
s32 createThread__15GSthreadManagerFUlPFPv_PvPvUllUs(s32, s32, s32, s32, s32, s32, s32);
void fn_8025A984(void);
extern s32 sInstance__15GSthreadManager;

s32 fn_8025A710(s32 arg0) {
    s32 temp_r3;

    temp_r3 = createThread__15GSthreadManagerFUlPFPv_PvPvUllUs(sInstance__15GSthreadManager, 0x01F34C7C, (s32) &fn_8025A984, arg0, 0x1000, 0xC, 1);
    (*(s32 *)((u8 *)(arg0) + (0x200))) = temp_r3;
    if (temp_r3 == 0) {
        return 0;
    }
    OSInitMessageQueue(arg0 + 0x20C, arg0 + 0x22C, 0xA);
    OSInitMessageQueue(arg0 + 0x254, arg0 + 0x274, 0xA);
    OSInitMessageQueue(arg0 + 0x29C, arg0 + 0x2BC, 0xA);
    return 1;
}
}

extern "C" {

void fn_8025A850(s32 arg0, u8 *arg1) {
    u32 temp_r3;

    temp_r3 = (*(u32 *)((u8 *)(arg1) + (0x88))) + (*(s32 *)((u8 *)(arg1) + (0x7C)));
    (*(u32 *)((u8 *)(arg1) + (0x88))) = temp_r3;
    if (temp_r3 >= (u32) (*(u32 *)((u8 *)(arg1) + (0x20)))) {
        (*(u32 *)((u8 *)(arg1) + (0x88))) = (u32) (*(u32 *)((u8 *)(arg1) + (0x2C)));
    }
    (*(s32 *)((u8 *)(arg1) + (0x80))) = 1;
}
}

extern "C" {

void fn_8025AD1C(s32 arg0, s32 arg1) {
    OSSendMessage((s32)(arg0 + 0x254), (s32)(arg1), (s32)(1));
}
}

extern "C" {

void fn_8025AD58(s32 arg0, s32 arg1) {
    OSSendMessage((s32)(arg0 + 0x29C), (s32)(arg1), (s32)(1));
}
}

extern "C" {

s32 stopThread__14GSthreadHandleFb(s32, s32);

void fn_8025A7BC(u8 *arg0) {
    s32 sp8;
    s32 temp_r0;

    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x200)));
    if (temp_r0 != 0) {
        stopThread__14GSthreadHandleFb(temp_r0, 0);
        (*(s32 *)((u8 *)(arg0) + (0x200))) = 0;
    }
    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x6B))) != 0) {
        do {

        } while (OSReceiveMessage((s32)(arg0 + 0x254), (s32 *)(&sp8), (s32)(0)) != 0);
    }
    while (OSReceiveMessage((s32)(arg0 + 0x29C), (s32 *)(&sp8), (s32)(0)) != 0) {
        fn_8025ACE0((s32)(arg0), (s32)(sp8));
    }
}
}

extern "C" {

s32 resumeThread__14GSthreadHandleFv(s32);

void fn_8025A7A8(u8 *arg0) {
    s32 temp_r3;

    temp_r3 = (*(s32 *)((u8 *)(arg0) + (0x200)));
    if (temp_r3 != 0) {
        resumeThread__14GSthreadHandleFv(temp_r3);
    }
}
}
