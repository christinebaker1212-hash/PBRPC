#include ".unsorted/8000AAC4.hpp"

extern "C" {

/* lbl_80405F60 */ extern const u8 lbl_80405F60[];

void fn_8000AAC4(Unk8000AAC4 *obj, Unk8000AAC4Sub *sub) {
    obj->_04 = sub;
}
u8 fn_8000AACC(Unk8000AAC4 *obj) {
    return obj->_04->_05;
}
u32 fn_8000AAD8(Unk8000AAC4 *obj) {
    return obj->_04->_08;
}
u32 fn_8000AAE4(Unk8000AAC4 *obj) {
    return obj->_04->_08;
}
u16 fn_8000AAF0(Unk8000AAC4 *obj) {
    return obj->_04->_06;
}
BOOL fn_8000AAFC(Unk8000AAC4 *obj) {
    return obj->_04->_10 < 0;
}
u32 fn_8000AB0C(Unk8000AAC4 *obj) {
    return obj->_04->_0C;
}
u8 fn_8000AB18(Unk8000AAC4 *obj) {
    return obj->_04->_02;
}
u16 fn_8000AB24(Unk8000AAC4 *obj) {
    return obj->_04->_00;
}
u8 fn_8000AB30(Unk8000AAC4 *obj) {
    return obj->_04->_03;
}
void fn_8000AC34(Unk8000AAC4 *obj) {
    obj->_00 = lbl_80405F60;
}
}

extern "C" {

s32 fn_8022683C(s32);
s32 fn_802275FC(s32, s32);
extern s32 lbl_8063F640;

void fn_8000AB3C(void) {
    fn_802275FC(lbl_8063F640, fn_8022683C(lbl_8063F640));
}
}

extern "C" {

s32 __nw__FUl(s32);
s32 fn_8000A9B8(void);
s32 fn_8000AB6C(void);
s32 fn_802265DC(s32, s32);
s32 fn_802276A4(s32, s32, s32);
extern s32 lbl_8063E948;

void fn_8000AC94(void) {
    s32 var_r3;

    var_r3 = __nw__FUl(0xC);
    if (var_r3 != 0) {
        var_r3 = fn_8000AB6C();
    }
    lbl_8063E948 = var_r3;
    fn_802276A4(4, 0x20, var_r3);
    fn_802265DC(lbl_8063F640, 1);
    fn_8000A9B8();
}
}

extern "C" {

s32 sleepCurrentThread__15GSthreadManagerFv(s32);
extern s32 sInstance__15GSthreadManager;

void fn_8000ACE8(void) {
loop_1:
    sleepCurrentThread__15GSthreadManagerFv(sInstance__15GSthreadManager);
    sleepCurrentThread__15GSthreadManagerFv(sInstance__15GSthreadManager);
    sleepCurrentThread__15GSthreadManagerFv(sInstance__15GSthreadManager);
    sleepCurrentThread__15GSthreadManagerFv(sInstance__15GSthreadManager);
    goto loop_1;
}
}

extern "C" {

s32 fn_80224584__15GSthreadManagerFb(s32, s32);

void fn_8000AD50(void) {
    fn_80224584__15GSthreadManagerFb(sInstance__15GSthreadManager, 0);
}
}

#include "common.hpp"

extern "C" {

s32 fn_80227574(s32 *, s32, s32, s32, s32);

void fn_8000AD18(s32 arg0) {
    fn_80227574((s32 *)(&fn_8000ACE8), (s32)(arg0), (s32)(0x2000), (s32)(9), (s32)(1));
}
}

extern "C" {

s32 __register_global_object(s32 *, s32 *, s32 *);
s32 fn_80225E94(s32 *, s32, s32 *, s32 *, s32 *);
void fn_8000AD34(void);
void fn_80225EE0(void);
__declspec(section ".data") extern s32 lbl_80474F00;
__declspec(section ".data") extern s32 lbl_80474F0C;

void fn_8000AD5C() {
    fn_80225E94((s32 *)(&lbl_80474F0C), (s32)(1), (s32 *)(&fn_8000AD18), (s32 *)(&fn_8000AD34), (s32 *)(&fn_8000AD50));
    __register_global_object((s32 *)(&lbl_80474F0C), (s32 *)(&fn_80225EE0), (s32 *)(&lbl_80474F00));
}
}
