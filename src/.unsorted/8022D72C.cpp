#include ".unsorted/8022D72C.hpp"

#include "common.hpp"

extern "C" {

void fn_8022DD2C(void) {}
void fn_8022DD30(void) {}
}

extern "C" {

s32 atoi(s32);
s32 fn_8022910C(s32 *);
__declspec(section ".data") extern s32 lbl_80424050;

s32 fn_8022DD34(u8 *arg0) {
    if ((s16) (*(s16 *)((u8 *)(arg0) + (0))) == 3) {
        return atoi((*(s32 *)((u8 *)(arg0) + (4))));
    }
    fn_8022910C(&lbl_80424050);
    return 0;
}
}

extern "C" {

f64 atof(s32);
__declspec(section ".data") extern s32 lbl_80424068;
extern f32 lbl_806422E0;

f32 fn_8022DD78(u8 *arg0) {
    if ((s16) (*(s16 *)((u8 *)(arg0) + (0))) == 3) {
        return (f32) atof((*(s32 *)((u8 *)(arg0) + (4))));
    }
    fn_8022910C((s32 *)(&lbl_80424068));
    return lbl_806422E0;
}
}
