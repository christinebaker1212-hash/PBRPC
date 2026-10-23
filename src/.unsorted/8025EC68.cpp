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

extern "C" {

s32 fn_8025CF50(s32);
s32 fn_8025D000(s32, s32, s32, s32, s32);

void fn_8025EC68(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r31_2;
    s32 temp_r31;
    s32 temp_r30;

    temp_r30 = OSDisableInterrupts();
    temp_r31 = fn_8025D000(((s32 (*)(s32))fn_8025E304)(fn_8025DFD0()), arg1, arg2, arg3, arg4);
    OSRestoreInterrupts((s32)(temp_r30));
    if (temp_r31 < 0) {
        temp_r31_2 = OSDisableInterrupts();
        fn_8025CF50(((s32 (*)(s32))fn_8025E304)(fn_8025DFD0()));
        OSRestoreInterrupts((s32)(temp_r31_2));
    }
}
}

extern "C" {

s32 fn_8025EF54() {
    s32 temp_r31;
    s32 temp_r30;

    temp_r30 = OSDisableInterrupts();
    temp_r31 = ((s32 (*)(s32))fn_8025D2CC)(((s32 (*)(s32))fn_8025E304)(fn_8025DFD0()));
    OSRestoreInterrupts((s32)(temp_r30));
    return temp_r31;
}
}
