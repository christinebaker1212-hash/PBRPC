#include ".unsorted/8003E854.hpp"

#include "common.hpp"

extern "C" {

u32 fn_8003E8F8(u8 *p) {
    return *(u32 *)(p + 0x4);
}
u8 *fn_8003E900(u8 *p) {
    return p + 0xd4;
}
u8 *fn_8003E908(u8 *p) {
    return p + 0x8;
}
}

extern "C" {

void fn_8003E854(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xD4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
}
}

extern "C" {

s32 fn_8003E9A0(void);

u8 *fn_8003E910(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s8 *)((u8 *)(arg0) + (1))) = 0;
    fn_8003E9A0();
    return arg0;
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 fn_8003EAB0(void);

s32 fn_8003E94C(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8003EAB0();
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 fn_8003EAB0(void);

s32 __dt__Q34nw4r3snd11SoundHandleFv(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8003EAB0();
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8003F51C(s32, s32);

s32 fn_8003F51C(s32 arg0, s32 arg1) {
    (*(s8 *)((u8 *)(arg1) + (2))) = 0;
    return arg0;
}
}
