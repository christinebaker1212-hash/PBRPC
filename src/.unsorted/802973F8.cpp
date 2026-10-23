#include ".unsorted/802973F8.hpp"

#include "common.hpp"

extern "C" {

s32 MEMGetSizeForMBlockExpHeap(u8 *arg0) {
    return (*(s32 *)((u8 *)(arg0) + (-0xC)));
}
}

extern "C" {

u8 MEMGetGroupIDForMBlockExpHeap(u8 *arg0) {
    return (u8) (*(u16 *)((u8 *)(arg0) + (-0xE)));
}
}
