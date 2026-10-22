#include ".unsorted/80388830.hpp"

#include "common.hpp"

extern "C" {

extern u32 typeInfo__Q34nw4r3lyt6Window;
extern u32 typeInfo__Q34nw4r3lyt8Bounding;

u32 *fn_8038A318(void) {
    return &typeInfo__Q34nw4r3lyt6Window;
}
void fn_8038A3C0(void) {}
u32 *fn_8038A3C4(void) {
    return &typeInfo__Q34nw4r3lyt8Bounding;
}
}

extern "C" {

s32 fn_8038A2E0(u8 *arg0, u32 arg1) {
    if (arg1 >= (u8) (*(u8 *)((u8 *)(arg0) + (0x100)))) {
        return 0;
    }
    return (*(s32 *)((u8 *)(((*(s32 *)((u8 *)(arg0) + (0xFC))) + (arg1 * 8))) + (4)));
}
}

extern "C" {

s32 GetFrameMaterial__Q34nw4r3lyt6WindowCFUl(u8 *arg0, u32 arg1) {
    if (arg1 >= (u8) (*(u8 *)((u8 *)(arg0) + (0x100)))) {
        return 0;
    }
    return (*(s32 *)((u8 *)(((*(s32 *)((u8 *)(arg0) + (0xFC))) + (arg1 * 8))) + (4)));
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 __dt__Q34nw4r3lyt4PaneFv(s32, s32);
s32 fn_8038A368(s32, s32);

s32 fn_8038A368(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        __dt__Q34nw4r3lyt4PaneFv(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}
