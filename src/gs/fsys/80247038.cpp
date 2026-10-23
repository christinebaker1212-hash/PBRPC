#include "common.hpp"
#include "gs/GScache.hpp"


class UnkClass1 {
public:
    /* 0x0 */ s32 mCapacity;
    /* 0x4 */ u32 *mFileIds;

    UnkClass1(u32 param1);
    ~UnkClass1();

    bool fn_802470E8();
    bool fn_80247110(u32 param1);
    u32 *fn_80247180();
    void fn_80247188(u32 param1);
    void fn_802471F4(u32 param1);
};

UnkClass1::UnkClass1(u32 capacity) {
    mCapacity = capacity;
    mFileIds = new u32[capacity + 1];

    if (mFileIds != NULL) {
        mFileIds[0] = 0;
    }
}

UnkClass1::~UnkClass1() {
    if (mFileIds != NULL) {
        delete[] mFileIds;
    }
}

// isEmpty


// push_back
bool UnkClass1::fn_80247110(u32 fileId) {
    for (s32 i = 0; i < mCapacity; i++) {
        if (fileId == mFileIds[i]) {
            return true;
        }

        if (mFileIds[i] == 0) {
            mFileIds[i] = fileId;
            mFileIds[++i] = 0;
            return true;
        }
    }
    return false;
}



void UnkClass1::fn_80247188(u32 fsysId) {
    if (mFileIds == NULL) {
        return;
    }

    for (u32 i = 0; mFileIds[i] != 0; i++) {
        GScache::incrementRefCount(fsysId, mFileIds[i]);
    }
}

void UnkClass1::fn_802471F4(u32 fsysId) {
    if (mFileIds == NULL) {
        return;
    }

    for (u32 i = 0; mFileIds[i] != 0; i++) {
        GScache::decrementRefCount(fsysId, mFileIds[i]);
    }
}

extern "C" {

s32 *__nwa__FUl(s32);

u8 *fn_80247038(u8 *arg0, s32 arg1) {
    s32 *temp_r3;

    (*(s32 *)((u8 *)(arg0) + (0))) = arg1;
    temp_r3 = __nwa__FUl((arg1 + 1) * 4);
    (*(s32 **)((u8 *)(arg0) + (4))) = temp_r3;
    if (temp_r3 != NULL) {
        *temp_r3 = 0;
    }
    return arg0;
}
}

extern "C" {

s32 fn_802470E8(s32 arg0) {
    s32 *temp_r3;

    temp_r3 = (*(s32 **)((u8 *)(arg0) + (4)));
    if ((temp_r3 != NULL) && ((s32) *temp_r3 != 0)) {
        return 0;
    }
    return 1;
}
}

extern "C" {

s32 fn_80247180(s32 arg0) {
    return (*(s32 *)((u8 *)(arg0) + (4)));
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 __dla__FPv(s32);
s32 fn_80247088(s32, s32);

s32 fn_80247088(s32 arg0, s32 arg1) {
    s32 temp_r3;

    if (arg0 != 0) {
        temp_r3 = (*(s32 *)((u8 *)(arg0) + (4)));
        if (temp_r3 != 0) {
            __dla__FPv(temp_r3);
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

struct S_lbl_8063F848 { s8 f_0; u8 pad_1[1]; s16 f_2; s8 f_4; };
extern struct S_lbl_8063F848 lbl_8063F848;

void fn_80247260() {
    lbl_8063F848.f_0 = 1;
    lbl_8063F848.f_2 = 4;
    lbl_8063F848.f_4 = 0;
}
}
