#include ".unsorted/8025DF80.hpp"

#include ".unsorted/8025E348.hpp"

#include "common.hpp"

extern "C" {

void fn_8025E370();

Unk8025DF80 *fn_8025DFD0(void) {
    return lbl_8063F998;
}
u32 fn_8025E0A8(Unk8025DF80 *obj) {
    return obj->_04;
}
void fn_8025E120(void) {}
void fn_8025E154(void) {}
void fn_8025E188(void) {}
u32 fn_8025E304(Unk8025DF80 *obj) {
    return obj->_14;
}
u32 fn_8025E30C(Unk8025DF80 *obj) {
    return obj->_08;
}
u32 fn_8025E314(Unk8025DF80 *obj) {
    return obj->_0C;
}
u8 *fn_8025E31C(Unk8025DF80 *obj) {
    return obj->_10;
}
void fn_8025E324(void) {
    fn_8025E370();
}
}

#include "common.hpp"

extern "C" {

void fn_8025DFC0(u32, u32 a) {
    fn_8025E474(a);
}
void fn_8025DFC8(u32, void *block) {
    fn_8025E4D0(block);
}
}

extern "C" {

s32 fn_8025E2B8(u8 *arg0) {
    s32 temp_r0;

    temp_r0 = (*(s32 *)((u8 *)(arg0) + (4)));
    switch (temp_r0) {                              /* irregular */
    case 1:
        return (*(s32 *)((u8 *)(arg0) + (8)));
    case 2:
        return (*(s32 *)((u8 *)(arg0) + (0xC)));
    case 3:
        return (*(s32 *)((u8 *)(arg0) + (0x10)));
    default:
    case 0:
        return 0;
    }
}
}

extern "C" {

struct VT_fn_8025E0B0_0 { virtual void v0(); virtual void v1(); virtual s32 v2(void); };

s32 fn_8025E0B0(s32 arg0) {
    s32 temp_r3;

    temp_r3 = fn_8025E2B8((u8 *)(arg0));
    if (temp_r3 != 0) {
        return ((VT_fn_8025E0B0_0 *)(temp_r3))->v2();
    }
    return -1;
}
}

extern "C" {

s32 fn_8025CF50(s32);
s32 fn_8025E9A0(s32);
struct VT_fn_8025E18C_0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual s32 v12(void); };
struct VT_fn_8025E18C_1 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual s32 v4(void); };
struct VT_fn_8025E18C_2 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual s32 v5(void); };

void fn_8025E18C(s32 arg0) {
    s32 temp_r3;
    u8 **temp_r3_2;
    u8 **temp_r3_3;
    u8 **temp_r3_4;

    temp_r3 = fn_8025E2B8((u8 *)(arg0));
    if (temp_r3 != 0) {
        ((VT_fn_8025E18C_0 *)(temp_r3))->v12();
        if ((((VT_fn_8025E18C_1 *)(temp_r3))->v4() == 0) && (((VT_fn_8025E18C_2 *)(temp_r3))->v5() == 0)) {
            fn_8025CF50((*(s32 *)((u8 *)(arg0) + (0x14))));
            (*(s32 *)((u8 *)(arg0) + (4))) = 0;
            return;
        }
        fn_8025E9A0(temp_r3);
        return;
    }
    temp_r3_2 = (*(u8 ***)((u8 *)(arg0) + (8)));
    if ((temp_r3_2 != NULL) && (((VT_fn_8025E18C_1 *)(temp_r3_2))->v4() != 0)) {
        (*(s32 *)((u8 *)(arg0) + (4))) = 1;
    }
    temp_r3_3 = (*(u8 ***)((u8 *)(arg0) + (0xC)));
    if ((temp_r3_3 != NULL) && (((VT_fn_8025E18C_1 *)(temp_r3_3))->v4() != 0)) {
        (*(s32 *)((u8 *)(arg0) + (4))) = 2;
    }
    temp_r3_4 = (*(u8 ***)((u8 *)(arg0) + (0x10)));
    if ((temp_r3_4 != NULL) && (((VT_fn_8025E18C_1 *)(temp_r3_4))->v4() != 0)) {
        (*(s32 *)((u8 *)(arg0) + (4))) = 3;
    }
}
}
