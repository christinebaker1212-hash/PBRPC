#include "common.hpp"

extern "C" {

s32 _fseek(s32, s32, s32);

void fn_801CA0F4(u8 *arg0) {
    (*(s8 *)((u8 *)(arg0) + (0xA))) = 0;
    _fseek((s32) arg0, 0, 0);
    (*(s8 *)((u8 *)(arg0) + (0xA))) = 0;
}
}
