#include ".unsorted/8021D0E0.hpp"

#include "common.hpp"

extern "C" {

s32 fn_8021D12C(void) {
    return 1;
}
void fn_8021D134(void) {}
s32 fn_8021D138(void) {
    return 1;
}
void fn_8021D140(void) {}
}

extern "C" {

s32 findTarget__14GSrenderTargetFl(s32);
s32 fn_8023B420__14GSrenderTargetFUl(s32, s32);
extern u8 *lbl_8063F550;
struct VT_fn_8021D1D0__Ff_0 { u8 pad[12]; virtual void v0(); virtual void v1(); virtual s32 v2(f32); };
struct VT_fn_8021D1D0__Ff_1 { u8 pad[12]; virtual void v0(); virtual s32 v1(void); };

void fn_8021D1D0__Ff(f32 farg0) {
    s32 temp_r3;
    u32 temp_r30;
    u8 *var_r29;

    var_r29 = lbl_8063F550;
    while (var_r29 != NULL) {
        if (((s32) (*(u8 *)((u8 *)(var_r29) + (8))) != 0) && (((VT_fn_8021D1D0__Ff_0 *)(var_r29))->v2((f32)(farg0)) == 0) && ((s32) (*(u8 *)((u8 *)(var_r29) + (8))) != 0)) {
            temp_r30 = (*(u32 *)((u8 *)(var_r29) + (4)));
            temp_r3 = findTarget__14GSrenderTargetFl((s32) (u8) (temp_r30 >> 0x10U));
            if (temp_r3 != 0) {
                fn_8023B420__14GSrenderTargetFUl(temp_r3, (s32) temp_r30);
            }
            ((VT_fn_8021D1D0__Ff_1 *)(var_r29))->v1();
            (*(u8 *)((u8 *)(var_r29) + (8))) = 0U;
        }
        var_r29 = (*(u8 **)((u8 *)(var_r29) + (0)));
    }
}
}
