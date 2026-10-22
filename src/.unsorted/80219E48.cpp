#include ".unsorted/80219E48.hpp"

#include "common.hpp"

extern "C" {

u32 fn_8021BF78(u8 *p) {
    return *(u32 *)(p + 0x958);
}
u32 fn_8021BF80(u8 *p) {
    return *(u32 *)(p + 0x95c);
}
}

extern "C" {

s32 fn_8021C03C(void);

void fn_8021BF88(u8 *arg0) {
    (*(u8 *)((u8 *)(arg0) + (0x151))) = (u8) ((*(u8 *)((u8 *)(arg0) + (0x151))) == 0);
    fn_8021C03C();
}
}
