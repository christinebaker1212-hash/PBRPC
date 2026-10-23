#include ".unsorted/80166D6C.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80166FB0(s32);
s32 fn_8025DFD0(void);
s32 fn_8025E31C(s32);
s32 fn_80267F6C(s32, s32);

s32 fn_80166FB0(s32 arg0) {
    return fn_80267F6C(fn_8025E31C(fn_8025DFD0()), arg0) != 0;
}
}

extern "C" {

s32 fn_80166E50(s32);
s32 fn_80267BDC(s32, s32);

s32 fn_80166E50(s32 arg0) {
    return fn_80267BDC(fn_8025E31C((s32)(fn_8025DFD0())), arg0);
}
}

extern "C" {

s32 fn_80166E88(s32, s32);
s32 fn_80268158(s32, s32, s32);

s32 fn_80166E88(s32 arg0, s32 arg1) {
    return fn_80268158(fn_8025E31C((s32)(fn_8025DFD0())), arg0, arg1);
}
}

extern "C" {

s32 fn_80166ED0(s32, s32);

s32 fn_80166ED0(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_80267F6C((s32)(fn_8025E31C((s32)(fn_8025DFD0()))), (s32)(arg0));
    if (temp_r3 != 0) {
        return (*(s32 *)((u8 *)(temp_r3) + (0x38)));
    }
    return 0;
}
}

extern "C" {

s32 fn_80166F1C(s32, s32);
s32 fn_802681B0(s32, s32, s32);

s32 fn_80166F1C(s32 arg0, s32 arg1) {
    return fn_802681B0(fn_8025E31C((s32)(fn_8025DFD0())), arg0, arg1);
}
}

extern "C" {

s32 fn_80166F64(s32, s32, s32);

s32 fn_80166F64(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;

    temp_r3 = fn_80267F6C((s32)(fn_8025E31C((s32)(fn_8025DFD0()))), (s32)(arg0));
    if (temp_r3 != 0) {
        return (*(s32 *)((u8 *)(temp_r3) + (0x3C)));
    }
    return 0;
}
}

extern "C" {

s32 fn_80167098(s32, s32);

s32 fn_80167098(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_80267F6C((s32)(fn_8025E31C((s32)(fn_8025DFD0()))), (s32)(arg0));
    if (temp_r3 != 0) {
        return (*(s32 *)((u8 *)(temp_r3) + (0x30)));
    }
    return 0;
}
}

extern "C" {

s32 fn_80267CE8(s32, s32, s32, s32, s32, s32, s32);

void fn_80166D6C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    fn_80267CE8(fn_8025E31C((s32)(fn_8025DFD0())), arg0, arg1, arg2, arg3, arg4, arg5);
}
}
