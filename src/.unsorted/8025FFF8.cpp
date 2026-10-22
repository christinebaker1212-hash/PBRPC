#include ".unsorted/8025FFF8.hpp"

#include "common.hpp"

extern "C" {

void fn_8025FDCC();
void fn_8025FF0C();

void fn_802604F8(void) {
    fn_8025FF0C();
}
void fn_802609BC(void) {
    fn_8025FDCC();
}
}

extern "C" {

s32 fn_8025FB64(s32, s32, s32);
s32 fn_80260458(s32, s32);
s32 fn_80260B10(s32);

s32 fn_80260458(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_8025FB64(arg0, 1, arg1);
    if (temp_r3 == 0) {
        return 0;
    }
    return fn_80260B10(temp_r3) == 0;
}
}

extern "C" {

s32 fn_8026049C(s32, s32);

s32 fn_8026049C(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_8025FB64((s32)(arg0), (s32)(1), (s32)(arg1));
    if (temp_r3 == 0) {
        return 0;
    }
    if (fn_80260B10((s32)(temp_r3)) != 0) {
        return (*(s32 *)((u8 *)(temp_r3) + (0x10)));
    }
    return 0;
}
}

extern "C" {

s32 fn_8025FAB8(s32, s32);
s32 fn_8025FEA0(s32, s32, s32, s32);
s32 fn_802604FC(s32, s32, s32);

s32 fn_802604FC(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r0;

    temp_r3 = fn_8025FAB8(arg0, 1);
    if (temp_r3 < 0) {
        return -1;
    }
    temp_r3_2 = fn_8025FEA0(arg0, (s32) (u16) temp_r3, arg1, arg2);
    var_r0 = -1;
    if (temp_r3_2 >= 0) {
        var_r0 = temp_r3_2;
    }
    return var_r0;
}
}

extern "C" {

s32 fn_8025FE34(s32, s32, s32, s32);
s32 fn_80260678(s32, s32, s32);

s32 fn_80260678(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r0;

    temp_r3 = fn_8025FAB8((s32)(arg0), (s32)(2));
    if (temp_r3 < 0) {
        return -1;
    }
    temp_r3_2 = fn_8025FE34(arg0, (s32) (u16) temp_r3, arg1, arg2);
    var_r0 = -1;
    if (temp_r3_2 >= 0) {
        var_r0 = temp_r3_2;
    }
    return var_r0;
}
}

extern "C" {

s32 fn_802608CC(s32, s32);
s32 fn_80260A10(s32);
s32 fn_80260B84(s32);

s32 fn_802608CC(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_8025FB64((s32)(arg0), (s32)(2), (s32)(arg1));
    if (temp_r3 == 0) {
        return 0;
    }
    if (fn_80260B84(temp_r3) != 0) {
        return 0;
    }
    if ((fn_80260B10((s32)(temp_r3)) != 0) && (fn_80260A10(temp_r3) != 0)) {
        return 0;
    }
    return 1;
}
}

extern "C" {

s32 fn_80260950(s32, s32);

s32 fn_80260950(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_8025FB64((s32)(arg0), (s32)(2), (s32)(arg1));
    if (temp_r3 == 0) {
        return 0;
    }
    if ((fn_80260B10((s32)(temp_r3)) != 0) && (fn_80260A10((s32)(temp_r3)) != 0)) {
        return (*(s32 *)((u8 *)(temp_r3) + (0x10)));
    }
    return 0;
}
}
