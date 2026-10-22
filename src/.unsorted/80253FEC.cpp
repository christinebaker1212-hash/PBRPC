#include ".unsorted/80253FEC.hpp"

#include "common.hpp"

extern "C" {

s32 __dl__FPv(void);

s32 fn_80253FEC(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}
