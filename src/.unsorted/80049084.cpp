#include ".unsorted/80049084.hpp"

#include "common.hpp"

extern "C" {

extern f32 lbl_806409D0;
void fn_8004911C();

void fn_800491F8(void) {}
void fn_8004927C(void) {}
void fn_800492AC(void) {}
void fn_80049334(void) {}
void fn_8004A75C(void) {}
void fn_8004A810(void) {
    fn_8004911C();
}
f32 fn_8004A814(void) {
    return lbl_806409D0;
}
void fn_8004A81C(void) {}
void fn_8004A98C(void) {}
void fn_8004A990(void) {}
void fn_8004AA60(void) {}
void fn_8004AB8C(void) {}
void fn_8004AC40(void) {
    fn_8004911C();
}
f32 fn_8004AC44(void) {
    return lbl_806409D0;
}
void fn_8004AC4C(void) {}
void fn_8004ACCC(void) {}
void fn_8004ACD0(void) {}
}

extern "C" {

extern f32 lbl_806409D0;

f32 fn_800491FC(u8 *arg0) {
    u8 *temp_r3;

    temp_r3 = (*(u8 **)((u8 *)(arg0) + (0x14)));
    if (temp_r3 == NULL) {
        return lbl_806409D0;
    }
    return (*(f32 *)((u8 *)(temp_r3) + (4)));
}
}
