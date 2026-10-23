#include ".unsorted/80032E60.hpp"

#include "common.hpp"

extern "C" {

void fn_80032E60(void) {}
}

extern "C" {

s32 fn_80032EC0(u8 *arg0, s32 arg1) {
    if ((arg1 < 0) || ((u32) arg1 >= (u32) (*(u32 *)((u8 *)(arg0) + (0))))) {
        return 0;
    }
    return *(s32 *)((u8 *)0 + ((*(s32 *)((u8 *)(arg0) + (4))) + (arg1 * 4)));
}
}
