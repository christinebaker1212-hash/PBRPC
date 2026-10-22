#include ".unsorted/80383D24.hpp"

#include "common.hpp"

extern "C" {

void fn_803843CC();
void fn_8038428C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
void fn_803836AC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
void fn_80384BD0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

void fn_80384BCC(void) {
    fn_803843CC();
}
void fn_80384BE0(void) {}
void fn_80384C28(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_8038428C(a0 - 0x74, a1, a2, a3, a4, a5, a6, a7);
}
void fn_80384C30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_803836AC(a0 - 0x74, a1, a2, a3, a4, a5, a6, a7);
}
void fn_80384C38(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_80384BD0(a0 - 0x80, a1, a2, a3, a4, a5, a6, a7);
}
void fn_80384C48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_803836AC(a0 - 0x80, a1, a2, a3, a4, a5, a6, a7);
}
}

extern "C" {

s32 fn_80384BE4(u8 *arg0) {
    return (*(u8 *)((u8 *)(arg0) + (0x8E))) != 0;
}
}

extern "C" {

s32 fn_80384BF8(u8 *arg0) {
    return (*(u8 *)((u8 *)(arg0) + (0x8D))) != 0;
}
}

extern "C" {

s32 fn_80384C0C(u8 *arg0) {
    return (*(u8 *)((u8 *)(arg0) + (0x8C))) != 0;
}
}

extern "C" {

s32 GetInstance__Q44nw4r3snd6detail11SoundThreadFv(void);
s32 OSLockMutex(s32);
s32 OSUnlockMutex(s32);
s32 fn_8037C81C(s32, s32);
s32 fn_80383FBC(s32);

s32 fn_80383FBC(s32 arg0) {
    s32 temp_r31;
    s32 var_r30;

    temp_r31 = arg0 + 0xA8;
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

s32 FreeChannel__Q44nw4r3snd6detail7ChannelFPQ44nw4r3snd6detail7Channel(s32);
s32 GetInstance__Q44nw4r3snd6detail22DisposeCallbackManagerFv(void);
s32 Release__Q44nw4r3snd6detail7ChannelFv(s32);
s32 UnregisterDisposeCallback__Q44nw4r3snd6detail22DisposeCallbackManagerFPQ44nw4r3snd6detail15DisposeCallback(s32, s32);
s32 fn_8037C880(s32, s32);
s32 fn_80384030(s32);
s32 fn_80384778(s32);

s32 fn_80384030(s32 arg0) {
    s32 temp_r31;
    s32 var_r30;
    s32 var_r30_2;
    s32 var_r3;
    u8 *temp_r3;
    u8 *temp_r4;

    temp_r31 = arg0 + 0xA8;
    OSLockMutex(temp_r31);
    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x8D))) != 0) {
        var_r30 = arg0;
        if (arg0 != 0) {
            var_r30 = arg0 + 0x80;
        }
        fn_8037C880(GetInstance__Q44nw4r3snd6detail11SoundThreadFv(), var_r30);
        (*(u8 *)((u8 *)(arg0) + (0x8D))) = 0U;
    }
    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x8C))) != 0) {
        var_r30_2 = arg0;
        if (arg0 != 0) {
            var_r30_2 = arg0 + 0x74;
        }
        UnregisterDisposeCallback__Q44nw4r3snd6detail22DisposeCallbackManagerFPQ44nw4r3snd6detail15DisposeCallback(GetInstance__Q44nw4r3snd6detail22DisposeCallbackManagerFv(), var_r30_2);
        (*(u8 *)((u8 *)(arg0) + (0x8C))) = 0U;
    }
    temp_r4 = (*(u8 **)((u8 *)(arg0) + (0xEC)));
    var_r3 = 0;
    if ((temp_r4 != NULL) && ((s32) (*(u8 *)((u8 *)(temp_r4) + (0x32))) != 0)) {
        var_r3 = 1;
    }
    if (var_r3 != 0) {
        fn_80384778(arg0);
        Release__Q44nw4r3snd6detail7ChannelFv((s32) (*(u8 **)((u8 *)(arg0) + (0xEC))));
    }
    temp_r3 = (*(u8 **)((u8 *)(arg0) + (0xEC)));
    if (temp_r3 != NULL) {
        FreeChannel__Q44nw4r3snd6detail7ChannelFPQ44nw4r3snd6detail7Channel((s32) temp_r3);
    }
    (*(u8 **)((u8 *)(arg0) + (0xEC))) = NULL;
    return OSUnlockMutex(temp_r31);
}
}

extern "C" {

s32 Pause__Q44nw4r3snd6detail5VoiceFb(s32, s32);
s32 fn_8038412C(s32, s32);

s32 fn_8038412C(s32 arg0, s32 arg1) {
    s32 temp_r31;
    s32 var_r4;
    u8 *temp_r5;
    u8 *temp_r5_2;

    temp_r31 = arg0 + 0xA8;
    OSLockMutex(temp_r31);
    temp_r5 = (*(u8 **)((u8 *)(arg0) + (0xEC)));
    var_r4 = 0;
    (*(s8 *)((u8 *)(arg0) + (0x8E))) = (s8) ((u8) arg1 != 0);
    if ((temp_r5 != NULL) && ((s32) (*(u8 *)((u8 *)(temp_r5) + (0x32))) != 0)) {
        var_r4 = 1;
    }
    if (var_r4 != 0) {
        temp_r5_2 = (*(u8 **)((u8 *)(arg0) + (0xEC)));
        if ((u32) arg1 != (u32) ((*(u8 *)((u8 *)(temp_r5_2) + (0x31))) != 0)) {
            (*(u8 *)((u8 *)(temp_r5_2) + (0x31))) = (u8) arg1;
            Pause__Q44nw4r3snd6detail5VoiceFb((*(s32 *)((u8 *)(temp_r5_2) + (0xDC))), arg1);
        }
    }
    return OSUnlockMutex(temp_r31);
}
}

extern "C" {

s32 fn_803841E4(s32, s32);

s32 fn_803841E4(s32 arg0, s32 arg1) {
    s32 temp_r31;

    temp_r31 = arg0 + 0xA8;
    OSLockMutex(temp_r31);
    (*(s8 *)((u8 *)(arg0) + (0x9C))) = (s8) arg1;
    return OSUnlockMutex(temp_r31);
}
}

extern "C" {

s32 fn_80384238(s32, s32);

s32 fn_80384238(s32 arg0, s32 arg1) {
    s32 temp_r31;

    temp_r31 = arg0 + 0xA8;
    OSLockMutex(temp_r31);
    (*(s8 *)((u8 *)(arg0) + (0x90))) = (s8) arg1;
    return OSUnlockMutex(temp_r31);
}
}

extern "C" {

s32 fn_80384B90(s32, s32, s32);

s32 fn_80384B90(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r3;

    var_r3 = arg0;
    if (arg1 == 2) {
        var_r3 = FreeChannel__Q44nw4r3snd6detail7ChannelFPQ44nw4r3snd6detail7Channel((s32)(var_r3));
    }
    (*(s32 *)((u8 *)(arg2) + (0xEC))) = 0;
    return var_r3;
}
}
