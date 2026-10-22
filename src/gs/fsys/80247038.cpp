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
bool UnkClass1::fn_802470E8() {
    // Does not match as a single `if`
    if (mFileIds != NULL) {
        if (mFileIds[0] != 0) {
            return false;
        }
    }
    return true;
}

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

u32 *UnkClass1::fn_80247180() {
    return mFileIds;
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
