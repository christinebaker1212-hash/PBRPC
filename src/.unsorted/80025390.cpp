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

extern "C" {

s32 __construct_new_array(s32, s32, s32, s32, s32);
s32 __nw__FUl(s32);
s32 __nwa__FUl(s32);
s32 createThread__15GSthreadManagerFUlPFPv_PvPvUllUs(s32, s32, s32, s32, s32, s32, s32);
s32 fn_80032E60(s32, s32);
s32 fn_80229C08(s32);
void fn_80027ED4(void);
__declspec(section ".data") extern s32 lbl_804096D0;
extern u8 lbl_8063E9BE;
extern s32 lbl_8063E9C0;
extern s32 sInstance__15GSthreadManager;

s32 fn_80025390(s32 arg0) {
    s32 temp_r3;

    fn_80229C08(arg0);
    (*(s32 **)((u8 *)(arg0) + (0x988))) = &lbl_804096D0;
    fn_80032E60(arg0 + 0x998, (s32) &lbl_804096D0);
    if ((s32) lbl_8063E9BE == 0) {
        temp_r3 = __nw__FUl(0x10);
        if (temp_r3 != 0) {
            (*(s32 *)((u8 *)(temp_r3) + (0xC))) = 0;
            (*(s32 *)((u8 *)(temp_r3) + (4))) = 0;
            (*(s32 *)((u8 *)(temp_r3) + (8))) = 0;
            (*(s32 *)((u8 *)(temp_r3) + (0))) = 8;
            (*(s32 *)((u8 *)(temp_r3) + (0xC))) = __construct_new_array(__nwa__FUl(0x110), (s32) &fn_80025478, 0, 0x20, 8);
        }
        lbl_8063E9C0 = temp_r3;
        createThread__15GSthreadManagerFUlPFPv_PvPvUllUs(sInstance__15GSthreadManager, 0x65, (s32) &fn_80027ED4, 0, 0x4000, 8, 1);
        lbl_8063E9BE = 1;
    }
    (*(s32 *)((u8 *)(arg0) + (0x98C))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x990))) = 0;
    lbl_8063E9BF = 0;
    return arg0;
}
}

extern "C" {

s32 fn_80032E64(s32, s32);
s32 fn_80224964(s32, s32, s32);
extern u8 lbl_8063D350;

void fn_800255A8(u8 *arg0, s32 arg1) {
    s32 temp_r31;
    s32 temp_r3;

    temp_r31 = fn_8003E15C();
    temp_r3 = fn_80224964(arg1, (s32) &lbl_8063D350, 0);
    if (temp_r3 != 0) {
        fn_80032E64((s32)(arg0 + 0x998), (s32)(temp_r3 + 0x10));
        if ((temp_r31 != 0) && ((s32) (*(s32 *)((u8 *)(arg0) + (0x998))) != 0)) {
            fn_8003E388((s32)(temp_r31), (s32)((s32) (arg0 + 0x998)));
        }
    }
}
}
