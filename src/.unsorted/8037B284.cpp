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
