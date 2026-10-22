#include ".unsorted/8037B284.hpp"

#include "common.hpp"

extern "C" {

void fn_8037BE70(u8 *p, u16 v) {
    *(u16 *)(p + 0x26) = v;
}
}

extern "C" {

void detail_SetPlayableSoundLimit__Q34nw4r3snd11SoundPlayerFi(u8 *arg0, s16 arg1) {
    (*(s16 *)((u8 *)(arg0) + (0x26))) = arg1;
}
}

extern "C" {

s32 Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(s32, s32, s32);
s32 OSLockMutex(s32);
s32 OSUnlockMutex(s32);
s32 detail_AppendPlayerHeap__Q34nw4r3snd11SoundPlayerFPQ44nw4r3snd6detail10PlayerHeap(s32, s32);

s32 detail_AppendPlayerHeap__Q34nw4r3snd11SoundPlayerFPQ44nw4r3snd6detail10PlayerHeap(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r31;

    temp_r31 = arg0 + 0x48;
    OSLockMutex(temp_r31);
    (*(s32 *)((u8 *)(arg1) + (0x38))) = arg0;
    sp8 = arg0 + 0x1C;
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(arg0 + 0x18, (s32) &sp8, arg1 + 0x2C);
    (*(s8 *)((u8 *)(arg0) + (0x2D))) = 1;
    return OSUnlockMutex(temp_r31);
}
}
