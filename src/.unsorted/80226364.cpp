#include ".unsorted/80226364.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063F644;

void fn_802265D4(u32, u32 v) {
    lbl_8063F644 = v;
}

u32 fn_80226868(Unk80226364 *obj) {
    return obj->_04->_00[obj->_04->_04]._00;
}
u8 fn_802268D8(Unk80226364 *obj) {
    return obj->_04->_00[obj->_04->_04]._10;
}
u8 fn_802268F4(Unk80226364 *obj) {
    return obj->_04->_00[obj->_04->_04]._11;
}
u32 fn_80226910(Unk80226364 *obj) {
    return fn_80228B84(&obj->_04->_00[obj->_04->_04]);
}

void fn_80227558(Unk80227558 *flags) {
    flags->_30 = 1;
    flags->_34 = 2;
}

void fn_8022756C(void) {}
void fn_80227570(void) {}
void fn_802275F8(void) {
    fn_80227574();
}

void fn_80227620(Unk80226364 *obj) {
    Unk80226364_00 *elem = &obj->_04->_00[obj->_04->_04];
    if (elem != NULL) {
        fn_80228CF8(elem);
    }
}

void fn_80227640(Unk80226364 *) {}

void fn_80227644(void) {
    if (lbl_8063F640 != NULL) {
        fn_80227620(lbl_8063F640);
    }
}

void fn_80227658(void) {
    if (lbl_8063F640 != NULL) {
        fn_80227640(lbl_8063F640);
    }
}
}

extern "C" {

s32 fn_80226700(u8 *arg0, s32 arg1) {
    u8 *temp_r6;

    temp_r6 = (*(u8 **)((u8 *)(arg0) + (4)));
    if ((u32) (*(u32 *)((u8 *)(temp_r6) + (4))) >= (u32) ((*(s32 *)((u8 *)(temp_r6) + (8))) - 1)) {
        return 0;
    }
    (*(s32 *)((u8 *)(arg0) + (8))) = 4;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = arg1;
    (*(s8 *)((u8 *)(arg0) + (0x14))) = 1;
    return 1;
}
}

extern "C" {

s32 fn_8022683C(u8 *arg0) {
    u8 *temp_r3;

    temp_r3 = (*(u8 **)((u8 *)(arg0) + (4)));
    if (temp_r3 != NULL) {
        return (*(s32 *)((u8 *)(((*(s32 *)((u8 *)(temp_r3) + (0))) + ((*(s32 *)((u8 *)(temp_r3) + (4))) * 0x224))) + (4)));
    }
    return 0;
}
}

extern "C" {

s32 fn_80226690(u8 *arg0);
s32 fn_8022673C(s32);

s32 fn_8022673C(s32 arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (8))) != 2) {
        return 0;
    }
    if ((s32) (*(s32 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (4)))) + (4))) <= 0) {
        return 0;
    }
    fn_80226690((u8 *)(arg0));
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 5;
    (*(s8 *)((u8 *)(arg0) + (0x14))) = 1;
    return 1;
}
}

extern "C" {

s32 fn_8023EB58(s32, s32 *, s32 *, s32, s32);
__declspec(section ".data") extern s32 lbl_80423E38;
extern s32 lbl_8063F778;

u8 *fn_80226364(u8 *arg0) {
    (*(s32 **)((u8 *)(arg0) + (0x3C))) = &lbl_80423E38;
    (*(s8 *)((u8 *)(arg0) + (0x14))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x28))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x2C))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x24))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x20))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = 0;
    fn_8023EB58((s32)(lbl_8063F778), (s32 *)(&fn_80227644), (s32 *)(&fn_80227658), (s32)(3), (s32)(0xC));
    return arg0;
}
}

extern "C" {

s32 fn_80226A18(u8 *arg0) {
    u8 *temp_r3;
    u8 *temp_r4;

    temp_r4 = (*(u8 **)((u8 *)(arg0) + (4)));
    temp_r3 = (unsigned char *)((*(s32 *)((u8 *)(temp_r4) + (0))) + ((*(s32 *)((u8 *)(temp_r4) + (4))) * 0x224));
    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x24))) != 0) {
        return 3;
    }
    if ((s32) (*(u8 *)((u8 *)(temp_r3) + (0x11))) != 0) {
        return 2;
    }
    return (*(u8 *)((u8 *)(temp_r3) + (0x10))) != 0;
}
}

extern "C" {

s32 fn_80228760(s32, s32, s32, s32, s32, s32);
s32 fn_802288F8(s32, s32);
s32 sleepCurrentThread__15GSthreadManagerFv(s32);
extern s32 sInstance__15GSthreadManager;

void fn_80226FA8(s32 *arg0, u8 *arg1, s32 arg2) {
    ((s32 (*)(void))fn_8022756C)();
    if (arg2 == 1) {
        fn_80228760(*arg0, (*(s32 *)((u8 *)(arg1) + (4))), 6, 1, arg2, -1);
    } else {
        fn_80228760(*arg0, (*(s32 *)((u8 *)(arg1) + (4))), 6, 0xFF, arg2, -1);
    }
    sleepCurrentThread__15GSthreadManagerFv(sInstance__15GSthreadManager);
    if (arg2 != 1) {
        fn_802288F8(*arg0, 6);
    }
}
}

extern "C" {

s32 fn_80228414(s32, s32);
s32 fn_80228FD4(s32, s32);

s32 fn_80226690(u8 *arg0) {
    u8 *temp_r4;

    if ((s32) (*(s32 *)((u8 *)(arg0) + (8))) != 2) {
        return 0;
    }
    temp_r4 = (*(u8 **)((u8 *)(arg0) + (4)));
    fn_80228414((*(s32 *)((u8 *)(arg0) + (0))), *(s32 *)((u8 *)0 + ((*(s32 *)((u8 *)(temp_r4) + (0))) + ((*(s32 *)((u8 *)(temp_r4) + (4))) * 0x224))));
    fn_80228FD4((s32) (*(u8 **)((u8 *)(arg0) + (4))), 6);
    (*(s32 *)((u8 *)(arg0) + (0x10))) = -1;
    return 1;
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 fn_80228DDC(s32, s32);
struct VT_fn_802263EC_0 { u8 pad[20];  virtual s32 v0(s32); };

u8 *fn_802263EC(u8 *arg0, s32 arg1) {
    s32 temp_r3;
    u8 *temp_r0;

    if (arg0 != NULL) {
        temp_r0 = (*(u8 **)((u8 *)(arg0) + (0)));
        (*(s32 **)((u8 *)(arg0) + (0x3C))) = &lbl_80423E38;
        if (!(temp_r0 == NULL)) {
            if (!(temp_r0 == NULL)) {
                ((VT_fn_802263EC_0 *)(temp_r0))->v0((s32)(1));
            }
            (*(u8 **)((u8 *)(arg0) + (0))) = NULL;
        }
        temp_r3 = (*(s32 *)((u8 *)(arg0) + (4)));
        if (temp_r3 != 0) {
            fn_80228DDC(temp_r3, 1);
            (*(s32 *)((u8 *)(arg0) + (4))) = 0;
        }
        if (arg1 > 0) {
            __dl__FPv((s32) arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 __nw__FUl(s32);
s32 createThread__15GSthreadManagerFUlPFPv_PvPvUllUs(s32, s32, s32, s32, s32, s32, s32);
s32 fn_80227E58(s32, s32);
s32 fn_802280E8(s32, s32, s32, s32);
s32 fn_80228D38(s32, s32);
s32 strncpy(s32, s32, s32);
void fn_8022766C(void);
__declspec(section ".data") extern s32 lbl_80423D94;
__declspec(section ".data") extern s8 lbl_80423DF8;
struct VT_fn_80226494_0 { u8 pad[20];  virtual s32 v0(s32); };

void fn_80226494(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;
    s32 *temp_r3_2;
    s32 temp_r3_4;
    s32 var_r3;
    s32 var_r3_2;
    u8 *temp_r0;
    u8 *temp_r3_3;

    temp_r0 = (*(u8 **)((u8 *)(arg0) + (0)));
    if (!(temp_r0 == NULL)) {
        if (!(temp_r0 == NULL)) {
            ((VT_fn_80226494_0 *)(temp_r0))->v0((s32)(1));
        }
        (*(u8 **)((u8 *)(arg0) + (0))) = NULL;
    }
    temp_r3 = (*(s32 *)((u8 *)(arg0) + (4)));
    if (temp_r3 != 0) {
        fn_80228DDC((s32)(temp_r3), (s32)(1));
        (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    }
    var_r3 = __nw__FUl(0x18);
    if (var_r3 != 0) {
        var_r3 = fn_80227E58(var_r3, arg2);
    }
    (*(u8 **)((u8 *)(arg0) + (0))) = (u8 *) var_r3;
    var_r3_2 = __nw__FUl(0xC);
    if (var_r3_2 != 0) {
        var_r3_2 = fn_80228D38(var_r3_2, arg1);
    }
    (*(s32 *)((u8 *)(arg0) + (4))) = var_r3_2;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
    temp_r3_2 = (long *)(__nw__FUl(8));
    if (temp_r3_2 != 0) {
        *temp_r3_2 = (long)(&lbl_80423D94);
    }
    temp_r3_3 = (*(u8 **)((u8 *)(arg0) + (0)));
    if (temp_r3_3 != NULL) {
        fn_802280E8((s32) temp_r3_3, (s32)(0), (s32)(0), (s32)(temp_r3_2));
    }
    temp_r3_4 = createThread__15GSthreadManagerFUlPFPv_PvPvUllUs(sInstance__15GSthreadManager, 0x7D0, (s32) &fn_8022766C, 0, 0x4000, 8, 1);
    if (&lbl_80423DF8 != NULL) {
        strncpy((s32)(temp_r3_4 + 0x348), (s32)(&lbl_80423DF8), (s32)(0x20U));
    }
}
}

extern "C" {

s32 fn_80228C24(s32, s32);
s32 fn_80229000(s32, s32);
struct VT_fn_802265DC_0 {  virtual s32 v0(void); };

s32 fn_802265DC(u8 *arg0, s32 arg1) {
    u8 *temp_r3;

    if ((s32) (*(s32 *)((u8 *)(arg0) + (8))) != 0) {
        return 0;
    }
    if (((u8 **) (*(u8 **(*))&lbl_8063F644) != NULL) && (((VT_fn_802265DC_0 *)((*(u8 **(*))&lbl_8063F644)))->v0() == 0)) {
        return 0;
    }
    temp_r3 = (*(u8 **)((u8 *)(arg0) + (4)));
    fn_80228C24((*(s32 *)((u8 *)(temp_r3) + (0))) + ((*(s32 *)((u8 *)(temp_r3) + (4))) * 0x224), arg1);
    fn_80229000((s32) (*(u8 **)((u8 *)(arg0) + (4))), arg1 + 0x5001);
    fn_80228FD4((s32)((s32) (*(u8 **)((u8 *)(arg0) + (4)))), (s32)(2));
    (*(s32 *)((u8 *)(arg0) + (8))) = 1;
    return 1;
}
}

extern "C" {

struct VT_fn_802267A8_0 {  virtual s32 v0(void); };

s32 fn_802267A8(u8 *arg0, s32 arg1) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (8))) != 2) {
        return 0;
    }
    if (((u8 **) (*(u8 **(*))&lbl_8063F644) != NULL) && (((VT_fn_802267A8_0 *)((*(u8 **(*))&lbl_8063F644)))->v0() == 0)) {
        return 0;
    }
    fn_80226690((u8 *)((s32) arg0));
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 3;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = arg1;
    (*(s8 *)((u8 *)(arg0) + (0x14))) = 1;
    return 1;
}
}

extern "C" {

s32 fn_802275FC(s32 arg0, s32 arg1);
struct VT_fn_80226880_0 { virtual void v0(); virtual void v1(); virtual s32 v2(void); };

s32 fn_80226880(s32 arg0) {
    s32 temp_r3;

    temp_r3 = fn_802275FC((s32)(arg0), (s32)(fn_8022683C((u8 *)(arg0))));
    if (temp_r3 != 0) {
        return ((VT_fn_80226880_0 *)(temp_r3))->v2();
    }
    return 0;
}
}

extern "C" {

s32 loadFsys__6GSfsysFUl(s32);
s32 setDefaultGroupID__5GSmemFUs(u16);
struct VT_fn_80226ABC_0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual u16 v6(void); };
struct VT_fn_80226ABC_1 { virtual void v0(); virtual void v1(); virtual s32 v2(void); };
struct VT_fn_80226ABC_2 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual s32 v4(void); };

void fn_80226ABC(s32 *arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;
    u8 **temp_r3;

    temp_r3 = ((u8 ** (*)(void))fn_802275FC)();
    setDefaultGroupID__5GSmemFUs(((VT_fn_80226ABC_0 *)(temp_r3))->v6());
    temp_r31 = ((VT_fn_80226ABC_1 *)(temp_r3))->v2();
    fn_80228760((s32)(*arg0), (s32)(((VT_fn_80226ABC_2 *)(temp_r3))->v4()), (s32)(1), (s32)(1), (s32)(arg2), (s32)(-1));
    if (temp_r31 != 0) {
        loadFsys__6GSfsysFUl(temp_r31);
    }
    sleepCurrentThread__15GSthreadManagerFv((s32)(sInstance__15GSthreadManager));
    sleepCurrentThread__15GSthreadManagerFv((s32)(sInstance__15GSthreadManager));
}
}

extern "C" {

struct VT_fn_802275FC_0 {  virtual s32 v0(void); };

s32 fn_802275FC(s32 arg0, s32 arg1) {
    if ((u8 **) (*(u8 **(*))&lbl_8063F644) != NULL) {
        return ((VT_fn_802275FC_0 *)((*(u8 **(*))&lbl_8063F644)))->v0();
    }
    return 0;
}
}
