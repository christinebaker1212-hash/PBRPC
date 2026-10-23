#include ".unsorted/8009C1A8.hpp"

#include "common.hpp"

extern "C" {

s32 fn_8009D800(s32, s32);
s32 fn_80253E8C(s32, s32, s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

s32 fn_8009D800(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C(arg0, arg1, 3, (s32) &sp8);
    if (sp8 != 0xE) {
        if (sp8 < 0xE) {
            if (sp8 != 0xB) {
                return temp_r3;
            }
            goto block_6;
        }
        if (sp8 != 0x11) {
            return temp_r3;
        }
        goto block_6;
    }
block_6:
    return fn_80253EB4(arg0, arg1, 1, 0);
}
}

extern "C" {

s32 fn_8009DA2C(s32, s32);

s32 fn_8009DA2C(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r3;

    temp_r3 = fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    if (sp8 != 0xE) {
        if (sp8 < 0xE) {
            if (sp8 != 0xB) {
                return temp_r3;
            }
            goto block_6;
        }
        if (sp8 != 0x11) {
            return temp_r3;
        }
        goto block_6;
    }
block_6:
    return fn_80253EB4(arg0, arg1, 1, 0);
}
}

extern "C" {

s32 fn_8009F080(s32, s32);

s32 fn_8009F080(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 var_r3;

    var_r3 = fn_80253E8C((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    if (sp8 != 1) {
        var_r3 = fn_80253EB4(arg0, arg1, 1, 0);
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8009F510(s32, s32);
s32 fn_80253EDC(s32, s32, s32, s32);

s32 fn_8009F510(s32 arg0, s32 arg1) {
    s32 sp8;

    return fn_80253EDC((s32) (s16) arg0, arg1, 3, (s32) &sp8);
}
}

extern "C" {

s32 fn_80059A3C(s32, s32);

void fn_8009DD08(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 0:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C(1, (s32) sp10);
        return;
    case 1:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C(2, (s32) sp10);
        return;
    case 2:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C(3, (s32) sp10);
        return;
    }
}
}

extern "C" {

void fn_8009F604(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(3), (s32)((s32) &sp8));
    switch (sp8) {                                  /* irregular */
    case 0:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(7), (s32)((s32) sp10));
        return;
    case 1:
        fn_80253EDC((s32)(arg0), (s32)(arg1), (s32)(6), (s32)((s32) sp10));
        fn_80059A3C((s32)(8), (s32)((s32) sp10));
        return;
    }
}
}
