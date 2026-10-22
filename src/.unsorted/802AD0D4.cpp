#include ".unsorted/802AD0D4.hpp"

#include "common.hpp"

extern "C" {

void fn_802AFDB8(void) {}
}

extern "C" {

void __a1_3d_data_type(void) {

}
}

extern "C" {

void __a1_unused_report(void) {

}
}

extern "C" {

s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(s32);
s32 memset(s32, s32, s32);

void fn_802AD15C(u8 *arg0) {
    s32 temp_r31;

    temp_r31 = OSDisableInterrupts();
    (*(s8 *)((u8 *)(arg0) + (0))) = 0;
    (*(s8 *)((u8 *)(arg0) + (1))) = 0;
    memset((*(s32 *)((u8 *)(arg0) + (4))), 0, (*(s32 *)((u8 *)(arg0) + (8))) * 0x30);
    OSRestoreInterrupts(temp_r31);
}
}

extern "C" {

void fn_802B4504(void) {

}
}

extern "C" {

s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(s32);
s32 memset(s32, s32, s32);

void WPADiClearQueue(u8 *arg0) {
    s32 temp_r31;

    temp_r31 = OSDisableInterrupts();
    (*(s8 *)((u8 *)(arg0) + (0))) = 0;
    (*(s8 *)((u8 *)(arg0) + (1))) = 0;
    memset((*(s32 *)((u8 *)(arg0) + (4))), 0, (*(s32 *)((u8 *)(arg0) + (8))) * 0x30);
    OSRestoreInterrupts(temp_r31);
}
}

extern "C" {

s32 __CanPushCmdQueue(s32, s32);

s32 __CanPushCmdQueue(s32 arg0, s32 arg1) {
    s32 temp_r3;
    s8 var_r31;

    temp_r3 = OSDisableInterrupts();
    var_r31 = (*(u8 *)((u8 *)(arg0) + (1))) - (*(u8 *)((u8 *)(arg0) + (0)));
    if (var_r31 < 0) {
        var_r31 += (*(s32 *)((u8 *)(arg0) + (8)));
    }
    OSRestoreInterrupts(temp_r3);
    if ((u32) (var_r31 + (s8) arg1) <= (u32) ((*(s32 *)((u8 *)(arg0) + (8))) - 1)) {
        return 1;
    }
    return 0;
}
}
