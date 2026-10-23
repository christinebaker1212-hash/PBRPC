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

extern "C" {

u8 *fn_8025E474(s32);
s32 memcpy(u8 *, s32, s16);
struct VT_fn_8025EBA4_0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual s32 v21(u8 *, u16, s32); };

s32 fn_8025EBA4(u8 **arg0, s16 arg1, u16 arg2, s32 arg3, s32 arg4, s16 arg5) {
    u8 *temp_r3;

    temp_r3 = fn_8025E474(arg5 + 0x40);
    if (temp_r3 == NULL) {
        return 0;
    }
    (*(s16 *)((u8 *)(temp_r3) + (0))) = arg1;
    (*(u16 *)((u8 *)(temp_r3) + (2))) = arg2;
    (*(s16 *)((u8 *)(temp_r3) + (4))) = 0;
    (*(s16 *)((u8 *)(temp_r3) + (6))) = arg5;
    memcpy(temp_r3 + 8, arg4, arg5);
    return ((VT_fn_8025EBA4_0 *)(arg0))->v21((u8 *)(temp_r3), (u16)((*(u16 *)((u8 *)(temp_r3) + (2)))), (s32)(arg3));
}
}
