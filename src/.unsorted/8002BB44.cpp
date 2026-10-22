#include ".unsorted/8002BB44.hpp"

#include "common.hpp"

extern "C" {

void fn_8002CA74(void) {}
f32 fn_8002CAB4(Unk8002BB44 *obj) {
    return obj->_4E0;
}

// TODO same inline Vec setter as fn_8002A5C8
void fn_8002CABC(Vec *v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void fn_8002CACC(Vec *v) {
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = 0.0f;
}
}

extern "C" {

s32 fn_80050388(u8 *);

void fn_8002CA78(u8 *arg0, f32 farg0) {
    (*(f32 *)((u8 *)(arg0) + (0x4E0))) = farg0;
    fn_80050388(arg0 + 4);
    (*(s8 *)((u8 *)(arg0) + (1))) = 1;
}
}
