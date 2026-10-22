#include ".unsorted/80294B5C.hpp"

#include "common.hpp"

extern "C" {

void fn_80294F48();

void fn_80294C44(void) {
    fn_80294F48();
}
}

extern "C" {

s32 fn_80294C48(void);

void fn_80294B5C(u8 *arg0) {
    (*(f32 *)((u8 *)(arg0) + (0xB8))) = (f32) (*(f32 *)((u8 *)(arg0) + (0xF8)));
    fn_80294C48();
}
}

extern "C" {

s32 fn_80294EF4(void);

s32 fn_80294BC4(void) {
    fn_80294EF4();
    return 1;
}
}
