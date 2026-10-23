#include ".unsorted/8025E348.hpp"

#include "gs/GSmem.hpp"

#include "common.hpp"

extern "C" {

/* lbl_8063F9B0 */ extern MEMHeapHandle lbl_8063F9B0;

void fn_8025E40C(MEMHeapHandle heap) {
    lbl_8063F9B0 = heap;
}

void fn_8025E474(u32 a) {
    fn_8025E414(a, 0x20);
}

void fn_8025E4D0(void *block) {
    if (block != NULL) {
        GSmem::freeToHeap(lbl_8063F9B0, block);
    }
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_80502AF8;
extern s32 lbl_8063F9B4;

u8 *fn_8025E4E8() {
    s32 temp_r0;
    s32 temp_r4;
    u8 *temp_r3;

    temp_r0 = lbl_8063F9B4 + 1;
    temp_r4 = lbl_8063F9B4 << 8;
    lbl_8063F9B4 = temp_r0;
    temp_r3 = (u8 *)(u8 *)&lbl_80502AF8 + temp_r4;
    if (temp_r0 >= 0x10) {
        lbl_8063F9B4 = 0;
        return temp_r3;
    }
    return temp_r3;
}
}
