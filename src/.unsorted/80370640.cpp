#include ".unsorted/80370640.hpp"

#include "common.hpp"

extern "C" {

void CreateHeap__Q44nw4r3snd6detail8AxfxImplFPvUl(
    u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7); // nw4r::snd::detail::AxfxImpl::CreateHeap
void DestroyHeap__Q44nw4r3snd6detail8AxfxImplFv(
    u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7); // nw4r::snd::detail::AxfxImpl::DestroyHeap

void fn_803706E0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    CreateHeap__Q44nw4r3snd6detail8AxfxImplFPvUl(a0 + 0xc, a1, a2, a3, a4, a5, a6, a7);
}
void fn_803706E8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    DestroyHeap__Q44nw4r3snd6detail8AxfxImplFv(a0 + 0xc, a1, a2, a3, a4, a5, a6, a7);
}
void fn_80370B20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    CreateHeap__Q44nw4r3snd6detail8AxfxImplFPvUl(a0 + 0xc, a1, a2, a3, a4, a5, a6, a7);
}
void fn_80370B28(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    DestroyHeap__Q44nw4r3snd6detail8AxfxImplFv(a0 + 0xc, a1, a2, a3, a4, a5, a6, a7);
}
void fn_80370E78(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    CreateHeap__Q44nw4r3snd6detail8AxfxImplFPvUl(a0 + 0xc, a1, a2, a3, a4, a5, a6, a7);
}
void fn_80370E80(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    DestroyHeap__Q44nw4r3snd6detail8AxfxImplFv(a0 + 0xc, a1, a2, a3, a4, a5, a6, a7);
}
void fn_80371260(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    CreateHeap__Q44nw4r3snd6detail8AxfxImplFPvUl(a0 + 0xc, a1, a2, a3, a4, a5, a6, a7);
}
void fn_80371268(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    DestroyHeap__Q44nw4r3snd6detail8AxfxImplFv(a0 + 0xc, a1, a2, a3, a4, a5, a6, a7);
}
void fn_80371648(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    CreateHeap__Q44nw4r3snd6detail8AxfxImplFPvUl(a0 + 0xc, a1, a2, a3, a4, a5, a6, a7);
}
void fn_80371650(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    DestroyHeap__Q44nw4r3snd6detail8AxfxImplFv(a0 + 0xc, a1, a2, a3, a4, a5, a6, a7);
}
}

extern "C" {

s32 AXFXChorusGetMemSize(s32);

s32 fn_803706B4(s32 arg0) {
    return (AXFXChorusGetMemSize(arg0 + 0x24) + 0x87) & 0xFFFFFFE0;
}
}

extern "C" {

s32 AXFXChorusShutdown(u8 *);
s32 HookAlloc__Q44nw4r3snd6detail8AxfxImplFPPFUl_PvPPFPv_v(u8 *, s32 *, s32 *);
s32 RestoreAlloc__Q44nw4r3snd6detail8AxfxImplFPFUl_PvPFPv_v(u8 *, s32, s32);

void fn_8037079C(u8 *arg0) {
    s32 spC;
    s32 sp8;

    (*(s8 *)((u8 *)(arg0) + (0xC))) = 0;
    HookAlloc__Q44nw4r3snd6detail8AxfxImplFPPFUl_PvPPFPv_v(arg0 + 0xC, &spC, &sp8);
    AXFXChorusShutdown(arg0 + 0x24);
    RestoreAlloc__Q44nw4r3snd6detail8AxfxImplFPFUl_PvPFPv_v(arg0 + 0xC, spC, sp8);
}
}

extern "C" {

s32 AXFXDelayGetMemSize(s32);

s32 fn_80370AF4(s32 arg0) {
    return (AXFXDelayGetMemSize(arg0 + 0x24) + 0x87) & 0xFFFFFFE0;
}
}

extern "C" {

s32 AXFXDelayShutdown(u8 *);

void fn_80370BDC(u8 *arg0) {
    s32 spC;
    s32 sp8;

    (*(s8 *)((u8 *)(arg0) + (0xC))) = 0;
    HookAlloc__Q44nw4r3snd6detail8AxfxImplFPPFUl_PvPPFPv_v(arg0 + 0xC, &spC, &sp8);
    AXFXDelayShutdown(arg0 + 0x24);
    RestoreAlloc__Q44nw4r3snd6detail8AxfxImplFPFUl_PvPFPv_v(arg0 + 0xC, spC, sp8);
}
}

extern "C" {

s32 AXFXReverbHiGetMemSize(s32);

s32 fn_80370E4C(s32 arg0) {
    return (AXFXReverbHiGetMemSize(arg0 + 0x30) + 0x87) & 0xFFFFFFE0;
}
}

extern "C" {

s32 AXFXReverbHiShutdown(u8 *);

void fn_80370F34(u8 *arg0) {
    s32 spC;
    s32 sp8;

    (*(s8 *)((u8 *)(arg0) + (0xC))) = 0;
    HookAlloc__Q44nw4r3snd6detail8AxfxImplFPPFUl_PvPPFPv_v(arg0 + 0xC, &spC, &sp8);
    AXFXReverbHiShutdown(arg0 + 0x30);
    RestoreAlloc__Q44nw4r3snd6detail8AxfxImplFPFUl_PvPFPv_v(arg0 + 0xC, spC, sp8);
}
}

extern "C" {

s32 AXFXReverbHiGetMemSizeDpl2(s32);

s32 fn_80371234(s32 arg0) {
    return (AXFXReverbHiGetMemSizeDpl2(arg0 + 0x30) + 0x87) & 0xFFFFFFE0;
}
}

extern "C" {

s32 AXFXReverbHiShutdownDpl2(u8 *);

void fn_8037131C(u8 *arg0) {
    s32 spC;
    s32 sp8;

    (*(s8 *)((u8 *)(arg0) + (0xC))) = 0;
    HookAlloc__Q44nw4r3snd6detail8AxfxImplFPPFUl_PvPPFPv_v(arg0 + 0xC, &spC, &sp8);
    AXFXReverbHiShutdownDpl2(arg0 + 0x30);
    RestoreAlloc__Q44nw4r3snd6detail8AxfxImplFPFUl_PvPFPv_v(arg0 + 0xC, spC, sp8);
}
}

extern "C" {

s32 fn_80294B5C(s32);

s32 fn_8037161C(s32 arg0) {
    return (fn_80294B5C(arg0 + 0x2C) + 0x87) & 0xFFFFFFE0;
}
}

extern "C" {

s32 fn_80294BC4(u8 *);

void fn_80371704(u8 *arg0) {
    s32 spC;
    s32 sp8;

    (*(s8 *)((u8 *)(arg0) + (0xC))) = 0;
    HookAlloc__Q44nw4r3snd6detail8AxfxImplFPPFUl_PvPPFPv_v(arg0 + 0xC, &spC, &sp8);
    fn_80294BC4(arg0 + 0x2C);
    RestoreAlloc__Q44nw4r3snd6detail8AxfxImplFPFUl_PvPFPv_v(arg0 + 0xC, spC, sp8);
}
}

extern "C" {

s32 AXFXReverbStdGetMemSize(s32);

s32 GetRequiredMemSize__Q34nw4r3snd11FxReverbStdFv(s32 arg0) {
    return (AXFXReverbStdGetMemSize(arg0 + 0x2C) + 0x87) & 0xFFFFFFE0;
}
}
