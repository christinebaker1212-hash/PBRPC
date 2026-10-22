#include ".unsorted/80213694.hpp"

#include "common.hpp"

extern "C" {

s32 fn_802328AC__13GSdisplayListFv(s32);
s32 freeToHeap__5GSmemFP12MEMiHeapHeadPv(s32, s32);
extern s32 gUnkHeap2;

void fn_80218134(u8 *arg0) {
    s32 temp_r0;

    temp_r0 = (*(s32 *)((u8 *)(arg0) + (0x434)));
    if (temp_r0 != 0) {
        fn_802328AC__13GSdisplayListFv(temp_r0);
        freeToHeap__5GSmemFP12MEMiHeapHeadPv(gUnkHeap2, (*(s32 *)((u8 *)(arg0) + (0x434))));
        (*(s32 *)((u8 *)(arg0) + (0x434))) = 0;
    }
}
}

extern "C" {

s32 fn_80219DFC(u8 **arg0) {
    u8 *temp_r4;

    temp_r4 = *arg0;
    return (*(u16 *)((u8 *)(temp_r4) + (0xA))) * (*(u16 *)((u8 *)(temp_r4) + (0xC))) * 2;
}
}

extern "C" {

s32 fn_80219E14(s32 *arg0, s32 arg1) {
    return (*(s32 *)((u8 *)((*arg0 + (arg1 * 4))) + (0x28)));
}
}

extern "C" {

s32 allocFromHeap__5GSmemFP12MEMiHeapHeadUl(s32, s32);
s32 fn_80218050(s32);
s32 fn_8021848C(s32);
s32 fn_80232BF0(s32, s32, s32, s32);
s32 fn_80232CB8(s32);
s32 memset(s32, s32, s32);

s32 fn_80218050(s32 arg0) {
    s32 temp_r3;
    s32 var_r3;
    u16 temp_r5_2;
    u8 *temp_r5;

    temp_r3 = allocFromHeap__5GSmemFP12MEMiHeapHeadUl(gUnkHeap2, 0x10);
    (*(s32 *)((u8 *)(arg0) + (0x434))) = temp_r3;
    memset(temp_r3, 0, 0x10);
    var_r3 = (*(s32 *)((u8 *)(arg0) + (0x434)));
    if (var_r3 != 0) {
        temp_r5 = (*(u8 **)((u8 *)(arg0) + (0)));
        temp_r5_2 = (*(u16 *)((u8 *)(temp_r5) + (0xC)));
        fn_80232BF0(var_r3, arg0 + 4, (s32) temp_r5_2, (s32) (u16) (temp_r5_2 * (((*(u16 *)((u8 *)(temp_r5) + (0xA))) + 1) * 2)));
        fn_8021848C(arg0);
        var_r3 = fn_80232CB8((*(s32 *)((u8 *)(arg0) + (0x434))));
    }
    return var_r3;
}
}

extern "C" {

s32 callDisplayList__8GSrenderFP13GSdisplayList(s32, s32);
s32 fn_802180D4(s32, s32, s32, s32);
s32 fn_80218184(s32, s32, s32);
s32 fn_802182B0(s32, s32, s32, s32);

s32 fn_802180D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x434))) != 0) {
        fn_80218184(arg0, arg2, arg3);
        return callDisplayList__8GSrenderFP13GSdisplayList(arg1, (*(s32 *)((u8 *)(arg0) + (0x434))));
    }
    return fn_802182B0(arg0, arg1, arg2, arg3);
}
}
