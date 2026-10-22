#include ".unsorted/8038D688.hpp"

#include "common.hpp"

extern "C" {

s32 __dl__FPv(s32);
s32 fn_8038D6FC(s32, s32);

s32 fn_8038D6FC(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv(arg0);
    }
    return arg0;
}
}
