#include ".unsorted/80228B0C.hpp"

#include ".unsorted/80226364.hpp"

#include "common.hpp"

extern "C" {

u32 fn_80228B84(Unk80226364_00 *obj) {
    return obj->_14;
}

// TODO role: sets the flag pair at 0x10/0x11 (three states, read back by fn_80228BF8)
void fn_80228BC0(Unk80226364_00 *obj) {
    obj->_10 = 1;
    obj->_11 = 0;
}

void fn_80228BD4(Unk80226364_00 *obj) {
    obj->_10 = 0;
    obj->_11 = 1;
}

void fn_80228BE8(Unk80226364_00 *obj) {
    obj->_10 = 0;
    obj->_11 = 0;
}

u32 fn_80228BF8(Unk80226364_00 *obj) {
    if (obj->_10 != 0) {
        return 1;
    }
    u32 result = 3;
    if (obj->_11 != 0) {
        result = 2;
    }
    return result;
}

// TODO role: stores a value at 0x04 and the same value plus 0x5001 at 0x00
void fn_80228C24(Unk80226364_00 *obj, u32 value) {
    obj->_04 = value;
    obj->_00 = value + 0x5001;
}

// TODO role: stores a value at 0x00 and, when a thread handle is attached, its id (value plus 0x2000)
void fn_80228C34(Unk80226364_00 *obj, u32 value) {
    obj->_00 = value;
    if (obj->_1C != NULL) {
        obj->_1C->mID = value + 0x2000;
    }
}

void fn_80228C50(Unk80226364_00 *obj, u32 x, u32 y) {
    obj->_08 = x;
    obj->_0C = y;
}

// TODO role: suspends the attached thread
void fn_80228C5C(Unk80226364_00 *obj) {
    if (obj->_1C != NULL) {
        obj->_1C->suspendThread();
    }
}

// TODO role: resumes the attached thread
void fn_80228C70(Unk80226364_00 *obj) {
    if (obj->_1C != NULL) {
        obj->_1C->resumeThread();
    }
}

void fn_80228FBC(void) {}

// TODO role: act on the current element of an array of records (indexed by the second member)
u32 fn_80228FC0(Unk80226364_04 *inner) {
    return fn_80228BF8(&inner->_00[inner->_04]);
}

void fn_80228FD4(Unk80226364_04 *inner, u32 value) {
    inner->_00[inner->_04]._220 = value;
}

void fn_80228FEC(Unk80226364_04 *inner, u32 x, u32 y) {
    fn_80228C50(&inner->_00[inner->_04], x, y);
}
}

extern "C" {

void fn_80228B8C(u8 *arg0);

u8 *fn_80228B0C(u8 *arg0) {
    ((s32 (*)(void))fn_80228B8C)();
    (*(s32 *)((u8 *)(arg0) + (0x14))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = 0;
    return arg0;
}
}

extern "C" {

s32 fn_80024DBC(void);

void fn_80228B48(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x14))) == 0) {
        (*(s32 *)((u8 *)(arg0) + (0x14))) = fn_80024DBC();
    }
}
}

extern "C" {

s32 fn_80228E44(u8 *arg0, s32 arg1) {
    s32 temp_r31;
    s32 temp_r4;
    s32 temp_r5;

    temp_r4 = (*(s32 *)((u8 *)(arg0) + (0)));
    temp_r5 = (*(s32 *)((u8 *)(arg0) + (4))) + 1;
    (*(s32 *)((u8 *)(arg0) + (4))) = temp_r5;
    temp_r31 = temp_r4 + (temp_r5 * 0x224);
    ((s32 (*)(s32, s32, s32))fn_80228B8C)(temp_r31, temp_r4, temp_r5);
    ((s32 (*)(s32))fn_80228BC0)(temp_r31);
    ((s32 (*)(s32, s32))fn_80228C24)(temp_r31, arg1);
    return temp_r31;
}
}

extern "C" {

s32 fn_80228EAC(u8 *arg0) {
    s32 temp_r31;
    s32 temp_r4;
    s32 temp_r5;

    temp_r4 = (*(s32 *)((u8 *)(arg0) + (0)));
    temp_r5 = (*(s32 *)((u8 *)(arg0) + (4))) - 1;
    (*(s32 *)((u8 *)(arg0) + (4))) = temp_r5;
    temp_r31 = temp_r4 + (temp_r5 * 0x224);
    ((s32 (*)(s32, s32, s32))fn_80228BD4)(temp_r31, temp_r4, temp_r5);
    return temp_r31;
}
}

extern "C" {

void fn_80229000(u8 *arg0) {
    s32 temp_r31;

    temp_r31 = (*(s32 *)((u8 *)(arg0) + (0))) + ((*(s32 *)((u8 *)(arg0) + (4))) * 0x224);
    ((s32 (*)(s32))fn_80228C34)(temp_r31);
    ((s32 (*)(s32))fn_80228C70)(temp_r31);
}
}

extern "C" {

u8 *memset(u8 *, s32, u32);

void fn_80228B8C(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x10))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x11))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x18))) = 1;
    (*(s32 *)((u8 *)(arg0) + (0x220))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = 0;
    memset(arg0 + 0x20, 0, 0x200);
}
}

extern "C" {

s32 suspendThread__15GSthreadManagerFUl(s32, s32);
extern s32 sInstance__15GSthreadManager;

void fn_80229044(u8 *arg0) {
    suspendThread__15GSthreadManagerFUl(sInstance__15GSthreadManager, *(s32 *)((u8 *)0 + ((*(s32 *)((u8 *)(arg0) + (0))) + ((*(s32 *)((u8 *)(arg0) + (4))) * 0x224))));
    ((s32 (*)(s32))fn_80228C5C)((*(s32 *)((u8 *)(arg0) + (0))) + ((*(s32 *)((u8 *)(arg0) + (4))) * 0x224));
}
}

extern "C" {

s32 resumeThread__15GSthreadManagerFUl(s32, s32);

void fn_80229098(u8 *arg0) {
    resumeThread__15GSthreadManagerFUl(sInstance__15GSthreadManager, *(s32 *)((u8 *)0 + ((*(s32 *)((u8 *)(arg0) + (0))) + ((*(s32 *)((u8 *)(arg0) + (4))) * 0x224))));
    ((s32 (*)(s32))fn_80228C70)((*(s32 *)((u8 *)(arg0) + (0))) + ((*(s32 *)((u8 *)(arg0) + (4))) * 0x224));
}
}

extern "C" {

s32 freeFileCacheEntry__7GScacheFUlUl(s32, s32);

void fn_80228C84(s32 arg0) {
    s32 temp_r3;
    u8 *var_r30;

    var_r30 = (unsigned char *)(arg0 + 0x20);
    while ((u32) var_r30 != (u32) (arg0 + 0x220)) {
        temp_r3 = (*(s32 *)((u8 *)(var_r30) + (0)));
        if (temp_r3 != 0) {
            freeFileCacheEntry__7GScacheFUlUl(temp_r3, (*(s32 *)((u8 *)(var_r30) + (4))));
        }
        var_r30 += 8;
    }
    ((s32)memset((u8 *)(arg0 + 0x20), (s32)(0), (u32)(0x200U)));
}
}

extern "C" {

s32 __dl__FPv(s32);

s32 *fn_80228DDC(s32 *arg0, s32 arg1) {
    s32 temp_r3;

    if (arg0 != NULL) {
        temp_r3 = *arg0;
        if (temp_r3 != 0) {
            __dl__FPv(temp_r3);
            *arg0 = 0;
        }
        if (arg1 > 0) {
            __dl__FPv((s32) arg0);
        }
    }
    return arg0;
}
}
