#include ".unsorted/80371DEC.hpp"

#include "common.hpp"

extern "C" {

void fn_803746A4();
void fn_80374408(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
void fn_80371DFC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

void fn_80371DF8(void) {
    fn_803746A4();
}
void fn_80371E0C(void) {}
void fn_80371E10(void) {}
void fn_80371E58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_80374408(a0 - 0x74, a1, a2, a3, a4, a5, a6, a7);
}
void fn_80371E60(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_80371DFC(a0 - 0x80, a1, a2, a3, a4, a5, a6, a7);
}
}

extern "C" {

s32 Shutdown__Q34nw4r3snd12SoundArchiveFv(void);

void Shutdown__Q34nw4r3snd18MemorySoundArchiveFv(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0x108))) = 0;
    Shutdown__Q34nw4r3snd12SoundArchiveFv();
}
}

extern "C" {

s32 fn_80371E14(u8 *arg0) {
    return (*(u8 *)((u8 *)(arg0) + (0x8E))) != 0;
}
}

extern "C" {

s32 fn_80371E28(u8 *arg0) {
    return (*(u8 *)((u8 *)(arg0) + (0x8D))) != 0;
}
}

extern "C" {

s32 fn_80371E3C(u8 *arg0) {
    return (*(u8 *)((u8 *)(arg0) + (0x8C))) != 0;
}
}
