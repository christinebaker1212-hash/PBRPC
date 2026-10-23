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
