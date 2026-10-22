#include ".unsorted/80372D5C.hpp"

#include "common.hpp"

extern "C" {

void DestroyImpl__Q44nw4r3snd6detail8PoolImplFPvUl(
    u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7); // nw4r::snd::detail::PoolImpl::DestroyImpl
void CountImpl__Q44nw4r3snd6detail8PoolImplCFv(
    u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7); // nw4r::snd::detail::PoolImpl::CountImpl

void fn_80372EF8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    DestroyImpl__Q44nw4r3snd6detail8PoolImplFPvUl(a0 + 0x8, a1, a2, a3, a4, a5, a6, a7);
}
void fn_80372F00(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    CountImpl__Q44nw4r3snd6detail8PoolImplCFv(a0 + 0x8, a1, a2, a3, a4, a5, a6, a7);
}
}

extern "C" {

s32 NANDClose(u8 *);
s32 Shutdown__Q34nw4r3snd12SoundArchiveFv(u8 *);

void Close__Q34nw4r3snd16NandSoundArchiveFv(u8 *arg0) {
    if ((s32) (*(u8 *)((u8 *)(arg0) + (0x1D8))) != 0) {
        NANDClose(arg0 + 0x14C);
        (*(u8 *)((u8 *)(arg0) + (0x1D8))) = 0U;
    }
    Shutdown__Q34nw4r3snd12SoundArchiveFv(arg0);
}
}

extern "C" {

s32 fn_80371E70(s32, u8 *, s32);

void fn_80372DB0(u8 *arg0, s32 arg1) {
    fn_80371E70((*(s32 *)((u8 *)(arg0) + (0xD8))), arg0, arg1);
}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_80372F08(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

s32 CreateImpl__Q44nw4r3snd6detail8PoolImplFPvUlUl(s32, s32, s32, s32);
s32 fn_80372EEC(s32, s32, s32);

s32 fn_80372EEC(s32 arg0, s32 arg1, s32 arg2) {
    return CreateImpl__Q44nw4r3snd6detail8PoolImplFPvUlUl(arg0 + 8, arg1, arg2, 0xF0);
}
}
