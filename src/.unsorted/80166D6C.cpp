#include ".unsorted/80166D6C.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80166FB0(s32);
s32 fn_8025DFD0(void);
s32 fn_8025E31C(s32);
s32 fn_80267F6C(s32, s32);

s32 fn_80166FB0(s32 arg0) {
    return fn_80267F6C(fn_8025E31C(fn_8025DFD0()), arg0) != 0;
}
}
