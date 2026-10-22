#include ".unsorted/801679F8.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80164C6C(void);
s32 fn_80166C1C(void);
s32 fn_80167A30(void);

s32 fn_80167C4C(void) {
    if (fn_80167A30() < 0) {
        return 7;
    }
    if (fn_80164C6C() == 0) {
        return 7;
    }
    return fn_80166C1C();
}
}
