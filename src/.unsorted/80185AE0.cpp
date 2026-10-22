#include ".unsorted/80185AE0.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80185D20(void) {
    return 0;
}
}

extern "C" {

u8 fn_80187570(u8 *arg0) {
    if (arg0 == NULL) {
        return 0U;
    }
    return (*(u8 *)((u8 *)(arg0) + (0xC)));
}
}

extern "C" {

s32 fn_801864F8(s32, s32, s32, s32, s32, s32);
s32 fn_801868AC(s32, s32, s32, s32, s32);

s32 fn_801864F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    return fn_801868AC(arg2, arg4, arg0, arg1, (s32) (s8) arg5);
}
}
