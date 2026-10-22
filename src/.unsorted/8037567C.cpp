#include ".unsorted/8037567C.hpp"

#include "common.hpp"

extern "C" {

s32 GetVariablePtr__Q44nw4r3snd6detail8SeqTrackFi(s32, s32);
s32 OSLockMutex(s32);
s32 OSUnlockMutex(s32);

s32 GetVariablePtr__Q44nw4r3snd6detail8SeqTrackFi(s32 arg0, s32 arg1) {
    s32 temp_r31;

    temp_r31 = arg0 + 0xC0;
    OSLockMutex(temp_r31);
    if (arg1 < 0x10) {
        OSUnlockMutex(temp_r31);
        return arg0 + (arg1 * 2) + 0x98;
    }
    OSUnlockMutex(temp_r31);
    return 0;
}
}
