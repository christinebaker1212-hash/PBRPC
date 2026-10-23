#include ".unsorted/80025390.hpp"

#include "common.hpp"

extern "C" {

extern u8 lbl_8063E9BF;

s32 fn_800254E4(void) {
    return 1;
}
s32 fn_80027B44(void) {
    return 0;
}
u8 fn_80027ECC(void) {
    return lbl_8063E9BF;
}
}

extern "C" {

void fn_80025478(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 fn_8002548C(s32, s32);
s32 fn_80229D48(s32, s32);

s32 fn_8002548C(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_80229D48(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_80025634(s32);
s32 fn_8003E15C(void);
s32 fn_8003E388(s32, s32);
s32 fn_8003E42C(s32);

s32 fn_80025634(s32 arg0) {
    s32 temp_r31;
    s32 var_r3;

    var_r3 = fn_8003E15C();
    temp_r31 = var_r3;
    if ((var_r3 != 0) && ((s32) (*(s32 *)((u8 *)(arg0) + (0x998))) != 0)) {
        var_r3 = fn_8003E42C(var_r3);
        if ((u32) var_r3 == (u32) (arg0 + 0x998)) {
            var_r3 = fn_8003E388(temp_r31, 0);
        }
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8002569C(s32);

s32 fn_8002569C(s32 arg0) {
    s32 var_r3;

    var_r3 = fn_8003E15C();
    if ((var_r3 != 0) && ((s32) (*(s32 *)((u8 *)(arg0) + (0x998))) != 0)) {
        var_r3 = fn_8003E388((s32)(var_r3), (s32)(arg0 + 0x998));
    }
    return var_r3;
}
}
