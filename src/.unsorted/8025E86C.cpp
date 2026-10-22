#include ".unsorted/8025E86C.hpp"

#include "common.hpp"

extern "C" {

void fn_8025EB40(u8 *p, u32 v) {
    *(u32 *)(p + 0xee8) = v;
}
void fn_8025EB48(u8 *p, u32 v) {
    *(u32 *)(p + 0xee4) = v;
}
void fn_8025EB50(u8 *p, u32 v) {
    *(u32 *)(p + 0xef0) = v;
}
void fn_8025EB58(u8 *p, u32 v) {
    *(u32 *)(p + 0xeec) = v;
}
void fn_8025EB60(u8 *p, u32 v) {
    *(u32 *)(p + 0xef4) = v;
}
void fn_8025EB68(u8 *p, u32 v) {
    *(u32 *)(p + 0xef8) = v;
}
void fn_8025EB70(u8 *p, u32 v) {
    *(u32 *)(p + 0xefc) = v;
}
}

extern "C" {

s32 fn_8025E7D8(s32, s32, s32);
s32 memset(s32, s32, s32);

void fn_8025E86C(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r31;

    var_r31 = arg2;
    if (arg2 > 0x10) {
        var_r31 = 0x10;
    }
    memset(arg0 + 4, 0, 0x20);
    fn_8025E7D8(arg0 + 4, arg1, var_r31);
}
}

extern "C" {

s32 fn_8025E370(void);

void fn_8025E8D8(s32 arg0, u32 arg1, s32 arg2) {
    if (arg1 < 0x10U) {
        (*(s32 *)((u8 *)((arg0 + ((arg1 * 4) & 0x3FFFC))) + (0xEA4))) = (s32) (fn_8025E370() - (arg2 * 0xA));
    }
}
}
