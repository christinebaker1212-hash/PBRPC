#include "common.hpp"

extern "C" {

s32 findTarget__14GSrenderTargetFl(s32);
s32 fn_8023B420__14GSrenderTargetFUl(s32, s32);
extern u8 *lbl_8063F410;

void fn_801E0904(u8 *arg0) {
    s32 temp_r3;
    u32 temp_r31;

    if ((s32) (*(u8 *)((u8 *)(arg0) + (1))) != 0) {
        if ((s32) (*(u8 *)((u8 *)(arg0) + (3))) != 0) {
            temp_r31 = (*(u32 *)((u8 *)(lbl_8063F410) + (0x10)));
            temp_r3 = findTarget__14GSrenderTargetFl((s32) (u8) (temp_r31 >> 0x10U));
            if (temp_r3 != 0) {
                fn_8023B420__14GSrenderTargetFUl(temp_r3, (s32) temp_r31);
            }
        }
        (*(u8 *)((u8 *)(arg0) + (1))) = 0U;
        (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    }
}
}
