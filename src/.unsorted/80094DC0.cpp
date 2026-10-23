#include ".unsorted/80094DC0.hpp"

#include "common.hpp"

extern "C" {

s32 fn_80095858(s32, s32);
s32 fn_80253E8C(s32, s32, s32, s32);
extern s32 lbl_8063EDB8;

s32 fn_80095858(s32 arg0, s32 arg1) {
    s32 sp8;
    s32 var_r3;

    var_r3 = fn_80253E8C((s32) (s16) arg0, arg1, 3, (s32) &sp8);
    if (sp8 < 5) {
        if (sp8 < 3) {
            return var_r3;
        }
        if ((s32) lbl_8063EDB8 == 1) {
            var_r3 = 0x40;
            (*(u8 *)((u8 *)(arg1) + (2))) = 0x40;
            (*(u8 *)((u8 *)(arg1) + (3))) = 0x40;
            (*(u8 *)((u8 *)(arg1) + (4))) = 0x40;
            (*(u8 *)((u8 *)(arg1) + (5))) = 0xFF;
        }
        /* Duplicate return node #5. Try simplifying control flow for better match */
        return var_r3;
    }
    return var_r3;
}
}

extern "C" {

s32 fn_80059A3C(s32, s32);
s32 fn_80253EDC(s32, s32, s32, s32);

void fn_800958CC(s32 arg0, s32 arg1) {
    s32 sp10[10];
    s32 sp8;

    fn_80253EDC(arg0, arg1, 3, (s32) &sp8);
    switch (sp8) {                                  /* irregular */
    case 4:
        fn_80253EDC(arg0, arg1, 6, (s32) sp10);
        fn_80059A3C(0x1F, (s32) sp10);
        return;
    case 3:
        fn_80253EDC(arg0, arg1, 6, (s32) sp10);
        fn_80059A3C(0x20, (s32) sp10);
        return;
    }
}
}
