#include ".unsorted/8025B164.hpp"

#include "common.hpp"

extern "C" {

s32 stopThread__14GSthreadHandleFb(s32, s32);

void fn_8025B214(u8 *arg0) {
    s32 temp_r0;

    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x204)));
    if (temp_r0 != 0) {
        stopThread__14GSthreadHandleFb(temp_r0, 0);
        (*(s32 *)((u8 *)(arg0) + (0x204))) = 0;
    }
}
}

extern "C" {

s32 OSReceiveMessage(s32, s32 *, s32);

s32 fn_8025B5DC(s32 arg0) {
    s32 sp8;

    OSReceiveMessage(arg0 + 0x310, &sp8, 1);
    return sp8;
}
}

extern "C" {

s32 fn_8025B640(s32 arg0) {
    s32 sp8;

    if (OSReceiveMessage(arg0 + 0x33C, &sp8, 0) != 0) {
        return sp8;
    }
    return 0;
}
}

extern "C" {

s32 OSSendMessage(s32, s32, s32);
s32 fn_8025B60C(s32, s32);

s32 fn_8025B60C(s32 arg0, s32 arg1) {
    return OSSendMessage(arg0 + 0x310, arg1, 0) != 0;
}
}
