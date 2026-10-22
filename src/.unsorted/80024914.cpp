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

extern "C" {

u8 *fn_80024EA8(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r3;
    u8 *var_r4;

    temp_r3 = __nw__FUl(0xAA0);
    var_r4 = temp_r3;
    if (temp_r3 != NULL) {
        var_r4 = fn_80025390();
    }
    (*(u8 **)((u8 *)(arg0) + (0))) = var_r4;
    (*(s8 *)((u8 *)(var_r4) + (0x93C))) = 1;
    var_r3 = __nw__FUl(0xAA0);
    if (var_r3 != NULL) {
        var_r3 = fn_80025390();
    }
    (*(u8 **)((u8 *)(arg0) + (4))) = var_r3;
    (*(s8 *)((u8 *)(var_r3) + (0x93C))) = 1;
    (*(s8 *)((u8 *)(arg0) + (8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0x10))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x16))) = 0xC;
    (*(s16 *)((u8 *)(arg0) + (0x18))) = 0xC;
    (*(s16 *)((u8 *)(arg0) + (0x12))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x14))) = 0;
    (*(u8 *)((u8 *)(arg0) + (0x1A))) = 0xFF;
    (*(u8 *)((u8 *)(arg0) + (0x1B))) = 0xFF;
    (*(u8 *)((u8 *)(arg0) + (0x1C))) = 0xFF;
    (*(u8 *)((u8 *)(arg0) + (0x1D))) = 0xFF;
    (*(s8 *)((u8 *)(arg0) + (0x11E))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x124))) = 0xC;
    (*(s16 *)((u8 *)(arg0) + (0x126))) = 0xC;
    (*(s16 *)((u8 *)(arg0) + (0x120))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x122))) = 0;
    (*(u8 *)((u8 *)(arg0) + (0x128))) = 0xFF;
    (*(u8 *)((u8 *)(arg0) + (0x129))) = 0xFF;
    (*(u8 *)((u8 *)(arg0) + (0x12A))) = 0xFF;
    (*(u8 *)((u8 *)(arg0) + (0x12B))) = 0xFF;
    (*(s8 *)((u8 *)(arg0) + (0x22C))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x232))) = 0xC;
    (*(s16 *)((u8 *)(arg0) + (0x234))) = 0xC;
    (*(s16 *)((u8 *)(arg0) + (0x22E))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x230))) = 0;
    (*(u8 *)((u8 *)(arg0) + (0x236))) = 0xFF;
    (*(u8 *)((u8 *)(arg0) + (0x237))) = 0xFF;
    (*(u8 *)((u8 *)(arg0) + (0x238))) = 0xFF;
    (*(u8 *)((u8 *)(arg0) + (0x239))) = 0xFF;
    (*(s8 *)((u8 *)(arg0) + (0x33A))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x340))) = 0xC;
    (*(s16 *)((u8 *)(arg0) + (0x342))) = 0xC;
    (*(s16 *)((u8 *)(arg0) + (0x33C))) = 0;
    (*(s16 *)((u8 *)(arg0) + (0x33E))) = 0;
    (*(u8 *)((u8 *)(arg0) + (0x344))) = 0xFF;
    (*(u8 *)((u8 *)(arg0) + (0x345))) = 0xFF;
    (*(u8 *)((u8 *)(arg0) + (0x346))) = 0xFF;
    (*(u8 *)((u8 *)(arg0) + (0x347))) = 0xFF;
    return arg0;
}
}
