#include ".unsorted/80091268.hpp"

#include "common.hpp"

extern "C" {

void fn_80091440(void) {}
void fn_8009187C(void) {}
void fn_800947FC(void) {}
void fn_80094800(void) {}
}

extern "C" {

s32 fn_8005AC60(s32, s32);
s32 fn_80253EB4(s32, s32, s32, s32);

void fn_80093FD4(s32 arg0, s32 arg1, s32 arg2) {
    fn_80253EB4(arg0, arg1, 1, fn_8005AC60(0x3EF, arg2));
}
}
