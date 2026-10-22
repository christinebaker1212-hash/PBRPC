#include ".unsorted/8037C81C.hpp"

#include "common.hpp"

extern "C" {

s32 Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(s32, s32, s32);
s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(s32);
s32 fn_8037C81C(s32, s32);

s32 fn_8037C81C(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 temp_r31;

    temp_r31 = OSDisableInterrupts();
    sp8 = arg0 + 0x388;
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(arg0 + 0x384, (s32) &sp8, arg1);
    return OSRestoreInterrupts(temp_r31);
}
}

extern "C" {

s32 Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(s32, s32);
s32 fn_8037C880(s32, s32);

s32 fn_8037C880(s32 arg0, s32 arg1) {
    s32 temp_r31;

    temp_r31 = OSDisableInterrupts();
    Erase__Q44nw4r2ut6detail12LinkListImplFPQ34nw4r2ut12LinkListNode(arg0 + 0x384, arg1);
    return OSRestoreInterrupts(temp_r31);
}
}
