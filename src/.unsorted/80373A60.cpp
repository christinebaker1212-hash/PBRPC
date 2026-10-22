#include ".unsorted/80373A60.hpp"

#include "common.hpp"

extern "C" {

s32 GetInstance__Q44nw4r3snd6detail11SoundThreadFv(void);
s32 OSLockMutex(s32);
s32 OSUnlockMutex(s32);
s32 fn_80374094(s32);
s32 fn_8037C81C(s32, s32);

s32 fn_80374094(s32 arg0) {
    s32 temp_r31;
    s32 var_r30;

    temp_r31 = arg0 + 0x11C;
    OSLockMutex(temp_r31);
    var_r30 = arg0;
    if (arg0 != 0) {
        var_r30 = arg0 + 0x80;
    }
    fn_8037C81C(GetInstance__Q44nw4r3snd6detail11SoundThreadFv(), var_r30);
    (*(s8 *)((u8 *)(arg0) + (0x8D))) = 1;
    OSUnlockMutex(temp_r31);
    return 1;
}
}

extern "C" {

s32 fn_80374204(s32, s32);
s32 fn_803759B0(s32, s32);

s32 fn_80374204(s32 arg0, s32 arg1) {
    s32 temp_r31;
    s32 var_r28;
    s32 var_r30;
    s32 var_r3;

    temp_r31 = arg0 + 0x11C;
    var_r28 = arg0;
    OSLockMutex(temp_r31);
    var_r30 = 0;
    (*(s8 *)((u8 *)(var_r28) + (0x8E))) = (s8) ((u8) arg1 != 0);
    do {
        if (var_r30 > 0xF) {
            var_r3 = 0;
        } else {
            var_r3 = (*(s32 *)((u8 *)(var_r28) + (0xB8)));
        }
        if (var_r3 != 0) {
            fn_803759B0(var_r3, arg1);
        }
        var_r30 += 1;
        var_r28 += 4;
    } while (var_r30 < 0x10);
    return OSUnlockMutex(temp_r31);
}
}

extern "C" {

s32 fn_80374360(s32, s32);

s32 fn_80374360(s32 arg0, s32 arg1) {
    s32 temp_r31;

    temp_r31 = arg0 + 0x11C;
    OSLockMutex(temp_r31);
    (*(s8 *)((u8 *)(arg0) + (0xA9))) = (s8) arg1;
    return OSUnlockMutex(temp_r31);
}
}

extern "C" {

s32 fn_803743B4(s32, s32);

s32 fn_803743B4(s32 arg0, s32 arg1) {
    s32 temp_r31;

    temp_r31 = arg0 + 0x11C;
    OSLockMutex(temp_r31);
    (*(s8 *)((u8 *)(arg0) + (0x8F))) = (s8) arg1;
    return OSUnlockMutex(temp_r31);
}
}
