#include ".unsorted/8002ABE8.hpp"

#include "common.hpp"

extern "C" {

extern u8 *sInstance__8GSrender;

f32 fn_8002BA54(u8 *arg0) {
    return (*(f32 *)((u8 *)(arg0) + (0xC))) * (f32) (*(u16 *)((u8 *)(sInstance__8GSrender) + (4)));
}
}

extern "C" {

f32 fn_8002BA88(u8 *arg0) {
    return (*(f32 *)((u8 *)(arg0) + (0x10))) * (f32) (*(u16 *)((u8 *)(sInstance__8GSrender) + (6)));
}
}

extern "C" {

f32 fn_8002BABC(u8 *arg0) {
    return (*(f32 *)((u8 *)(arg0) + (0x14))) * (f32) (*(u16 *)((u8 *)(sInstance__8GSrender) + (4)));
}
}

extern "C" {

f32 fn_8002BAF0(u8 *arg0) {
    return (*(f32 *)((u8 *)(arg0) + (0x18))) * (f32) (*(u16 *)((u8 *)(sInstance__8GSrender) + (6)));
}
}
