#include ".unsorted/80024914.hpp"

#include "common.hpp"

extern "C" {

void fn_80024E40(void) {
    if (lbl_8063E9B0 != NULL) {
        fn_80025024(lbl_8063E9B0);
    }
}

void fn_80025360(Unk80024914 *obj, u32 v) {
    obj->_0C = v;
}
u32 fn_80025368(Unk80024914 *obj) {
    return obj->_0C;
}
}

extern "C" {

u8 *__nw__FUl(s32);
u8 *fn_80025390(void);

u8 *fn_80024DBC(void) {
    u8 *var_r3;

    var_r3 = __nw__FUl(0xAA0);
    if (var_r3 != NULL) {
        var_r3 = fn_80025390();
    }
    if (var_r3 != NULL) {
        (*(s8 *)((u8 *)(var_r3) + (0x93C))) = 1;
        return var_r3;
    }
    return NULL;
}
}

extern "C" {

s32 fn_80226868(s32);
s32 fn_80229F44(s32);
s32 fn_8022A9AC(s32, s32);
extern s32 lbl_8063F640;

void fn_80025120(u8 *arg0, s32 arg1) {
    if (arg1 == 0) {
        fn_80229F44((*(s32 *)((u8 *)(arg0) + (4))));
        return;
    }
    fn_8022A9AC((*(s32 *)((u8 *)(arg0) + (0))), fn_80226868(lbl_8063F640));
    fn_80229F44((*(s32 *)((u8 *)(arg0) + (0))));
}
}
