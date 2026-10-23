#include "common.hpp"

extern "C" {

void fn_8023EC6C(u8 *arg0, f32 farg0) {
    s32 (**temp_r3)(f32);
    s32 (*temp_r12)(f32);
    u8 *var_r31;

    var_r31 = (*(u8 **)((u8 *)(arg0) + (0x10)));
    while (var_r31 != NULL) {
        temp_r3 = (*(s32 (***)(f32))((u8 *)(var_r31) + (0)));
        if (temp_r3 != NULL) {
            temp_r12 = *temp_r3;
            if (temp_r12 != NULL) {
                temp_r12(farg0);
            }
        }
        var_r31 = (*(u8 **)((u8 *)(var_r31) + (4)));
    }
}
}
