#include ".unsorted/80155B50.hpp"

#include "common.hpp"

extern "C" {

void fn_80157188(void) {}
}

extern "C" {

s32 __dl__FPv(s32);
s32 fn_801572AC(s32);
s32 fn_801574B4(s32);
s32 fn_80157730(s32);
s32 fn_80253F9C(s32, s32);
extern s32 lbl_8063EFD0;
struct VT_fn_80155C18_0 { u8 pad[256];  virtual s32 v0(s32); };

s32 fn_80155C18(s32 arg0, s32 arg1) {
    u8 *temp_r3;

    if (arg0 != 0) {
        fn_80157730(arg0);
        temp_r3 = (*(u8 **)((u8 *)(arg0) + (0x10)));
        if (!(temp_r3 == NULL)) {
            if (!(temp_r3 == NULL)) {
                ((VT_fn_80155C18_0 *)(temp_r3))->v0((s32)(1));
            }
            (*(u8 **)((u8 *)(arg0) + (0x10))) = NULL;
        }
        fn_801572AC(arg0);
        fn_801574B4(arg0);
        fn_80253F9C(0, 0);
        lbl_8063EFD0 = 0;
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}
