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
