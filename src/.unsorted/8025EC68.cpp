#include ".unsorted/8025EC68.hpp"

#include "common.hpp"

extern "C" {

s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(s32);
s32 fn_8025CF9C(void);
s32 fn_8025D2CC(void);
s32 fn_8025DFD0(void);
s32 fn_8025E304(void);

void fn_8025EE18(void) {
    s32 temp_r31;

    temp_r31 = OSDisableInterrupts();
    fn_8025DFD0();
    fn_8025E304();
    if (fn_8025D2CC() != 0) {
        fn_8025DFD0();
        fn_8025E304();
        fn_8025CF9C();
    }
    OSRestoreInterrupts(temp_r31);
}
}
