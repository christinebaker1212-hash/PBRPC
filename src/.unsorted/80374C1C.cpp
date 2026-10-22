#include ".unsorted/80374C1C.hpp"

#include "common.hpp"

extern "C" {

void fn_80373BB0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

void fn_80374C1C(void) {}
void fn_80374C20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_80373BB0(a0 - 0x74, a1, a2, a3, a4, a5, a6, a7);
}
void fn_80374C28(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_80373BB0(a0 - 0x80, a1, a2, a3, a4, a5, a6, a7);
}
}

extern "C" {

s32 InitParam__Q44nw4r3snd6detail10BasicSoundFv(void);

void fn_80374D24(u8 *arg0) {
    InitParam__Q44nw4r3snd6detail10BasicSoundFv();
    (*(s32 *)((u8 *)(arg0) + (0x21C))) = 0;
}
}
