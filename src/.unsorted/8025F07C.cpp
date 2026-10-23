#include ".unsorted/8025F07C.hpp"

#include "common.hpp"

extern "C" {

s32 fn_8025F49C(s32, s32, s32);
s32 fn_8025FB64(s32, s32, s32);
s32 fn_80260A88(s32, s32);

s32 fn_8025F49C(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;
    s32 var_r3;

    temp_r31 = (*(s32 *)((u8 *)(arg1) + (8)));
    var_r3 = fn_8025FB64(arg0, 2, (s32) (*(u16 *)((u8 *)(arg1) + (4))));
    if (var_r3 != 0) {
        var_r3 = fn_80260A88(var_r3, temp_r31);
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8025FDCC(s32, s32);
s32 fn_8025FF74(s32, s32);
s32 fn_80260AD4(s32);

s32 fn_8025FDCC(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_8025FB64((s32)(arg0), (s32)(2), (s32)(arg1));
    if (temp_r3 == 0) {
        return -1;
    }
    fn_8025FF74(arg0, temp_r3);
    fn_80260AD4(temp_r3);
    return 0;
}
}

extern "C" {

s32 fn_8025FBE0(s32, s32, s32);
s32 fn_8025FE34(s32, s32, s32, s32);
s32 fn_80260EC8(s32, s32, s32);

s32 fn_8025FE34(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    temp_r3 = fn_8025FBE0(arg0, 2, arg1);
    if (temp_r3 == 0) {
        return -1;
    }
    fn_80260EC8(temp_r3, arg2, arg3);
    return arg1;
}
}

extern "C" {

s32 fn_8025FEA0(s32, s32, s32, s32);

s32 fn_8025FEA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;

    temp_r3 = fn_8025FBE0((s32)(arg0), (s32)(1), (s32)(arg1));
    if (temp_r3 == 0) {
        return -1;
    }
    fn_80260EC8(temp_r3, arg2, arg3);
    return arg1;
}
}

extern "C" {

s32 fn_8025FF0C(s32, s32);

s32 fn_8025FF0C(s32 arg0, s32 arg1) {
    s32 temp_r3;

    temp_r3 = fn_8025FB64((s32)(arg0), (s32)(1), (s32)(arg1));
    if (temp_r3 == 0) {
        return -1;
    }
    fn_8025FF74(arg0, temp_r3);
    fn_80260AD4(temp_r3);
    return 0;
}
}

extern "C" {

s32 fn_8025E4D0(s32);
s32 fn_802609E0(s32);
s32 fn_802609F8(s32);
s32 fn_80260D48(s32);

s32 fn_8025FF74(s32 arg0, s32 arg1) {
    s32 temp_r3;
    s32 var_r3;

    var_r3 = fn_802609E0(arg1);
    if (var_r3 == 0) {
        if (fn_802609F8(arg1) & 2) {
            temp_r3 = fn_80260D48(arg1);
            if (temp_r3 != 0) {
                fn_8025E4D0(temp_r3);
            }
        }
        var_r3 = fn_80260AD4(arg1);
    }
    return var_r3;
}
}

extern "C" {

void fn_8025F07C(s32 arg0) {
    s32 var_r31;
    s32 var_r30;

    var_r31 = arg0 + 0x24;
    var_r30 = 0;
    do {
        if (fn_802609E0((s32)(var_r31)) == 0) {
            fn_8025FF74((s32)(arg0), (s32)(var_r31));
        }
        var_r30 += 1;
        var_r31 += 0x74;
    } while (var_r30 < 0x20);
}
}

extern "C" {

void fn_8025F0E8(s32 arg0) {
    s32 var_r31;
    s32 var_r30;

    var_r31 = arg0 + 0x24;
    var_r30 = 0;
    do {
        fn_80260AD4((s32)(var_r31));
        var_r30 += 1;
        var_r31 += 0x74;
    } while (var_r30 < 0x20);
}
}
