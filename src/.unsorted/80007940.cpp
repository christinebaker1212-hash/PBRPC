#include ".unsorted/80007940.hpp"

#include "gs/GSfsys.hpp"

#include "common.hpp"

extern "C" {

void fn_80007B14(void) {}
s32 fn_800081A0(void) {
    return 1;
}
s32 fn_80009218(void) {
    return 1;
}

bool fn_80009640(void) {
    return GSfsys::fn_802499E4();
}
bool fn_80009644(u32 fsysId) {
    return GSfsys::fn_802499EC(fsysId);
}
void *fn_80009648(u32 fsysId, u32 fileId, u32 size) {
    return GSfsys::fn_80249A28(fsysId, fileId, size);
}
void *fn_8000964C(u32 fsysId, u32 fileId, u32 size) {
    return GSfsys::fn_80249A44(fsysId, fileId, size);
}
}

extern "C" {

u32 fn_8022683C(s32);
extern s32 lbl_8063F640;

s32 fn_80007B18(u32 arg0) {
    u32 temp_r3;

    temp_r3 = fn_8022683C(lbl_8063F640);
    if ((temp_r3 >= 0x3E8U) && (temp_r3 <= 0x3F2U) && (arg0 >= 0x1B58U) && (arg0 <= 0x1B6DU)) {
        return 1;
    }
    return 0;
}
}

extern "C" {

s32 fn_8025008C(void);

s32 fn_80007FA0(s32 arg0) {
    if (arg0 != 0) {
        fn_8025008C();
    }
    return 1;
}
}

extern "C" {

s32 fn_8025006C(void);
s32 getCachedFile__7GScacheFUlUl(u32, s32);
s32 unlockCacheEntry__7GScacheFUlUl(void);

s32 fn_80008040(u32 arg0, s32 arg1) {
    s32 temp_r3;

    unlockCacheEntry__7GScacheFUlUl();
    temp_r3 = getCachedFile__7GScacheFUlUl(arg0, arg1);
    if ((arg0 != 0xAU) && (temp_r3 != 0)) {
        fn_8025006C();
    }
    return temp_r3;
}
}

extern "C" {

s32 fn_8025007C(void);

s32 fn_800080A0(s32 arg0) {
    if (arg0 != 0) {
        fn_8025007C();
    }
    return 1;
}
}

extern "C" {

s32 fn_8025005C(void);

s32 fn_80008140(u32 arg0, s32 arg1) {
    s32 temp_r3;

    unlockCacheEntry__7GScacheFUlUl();
    temp_r3 = getCachedFile__7GScacheFUlUl(arg0, arg1);
    if ((arg0 != 0xAU) && (temp_r3 != 0)) {
        fn_8025005C();
    }
    return temp_r3;
}
}

extern "C" {

s32 fn_801E37F0(void);

s32 fn_80008E3C(s32 arg0) {
    if (arg0 != 0) {
        fn_801E37F0();
    }
    return 1;
}
}

extern "C" {

s32 fn_801E3BA0(void);

s32 fn_80009020(s32 arg0) {
    if (arg0 != 0) {
        fn_801E3BA0();
    }
    return 1;
}
}

extern "C" {

s32 fn_801E3E80(void);

s32 fn_8000911C(s32 arg0) {
    if (arg0 != 0) {
        fn_801E3E80();
    }
    return 1;
}
}

extern "C" {

s32 fn_80206DF4(void);
s32 freeFileCacheEntry__7GScacheFUlUl(s32, s32);

s32 fn_80009294(s32 arg0, s32 arg1, s32 arg2) {
    if (arg0 != 0) {
        fn_80206DF4();
    }
    freeFileCacheEntry__7GScacheFUlUl(arg1, (arg2 & 0x7FFF0000) | 0xA00);
    return 1;
}
}

extern "C" {

s32 fn_8023E2D0__9GStextureFv(void);

s32 fn_80009564(s32 arg0) {
    if (arg0 != 0) {
        fn_8023E2D0__9GStextureFv();
    }
    return 1;
}
}

extern "C" {

s32 createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b(s32, s32, s32, s32, s32, s32);
s32 lockCacheEntry__7GScacheFUlUl(s32, s32);
extern s32 gUnkHeap2;

s32 fn_80009650(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;

    temp_r31 = createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b(gUnkHeap2, (arg2 + 0x1F) & 0xFFFFFFE0, 0x20, arg0, arg1, 0);
    lockCacheEntry__7GScacheFUlUl(arg0, arg1);
    return temp_r31;
}
}

extern "C" {

s32 fn_80009704(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;

    temp_r31 = createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b(gUnkHeap2, (arg2 + 0x1F) & 0xFFFFFFE0, 0x20, arg0, arg1, 0);
    lockCacheEntry__7GScacheFUlUl(arg0, arg1);
    return temp_r31;
}
}

extern "C" {

s32 fn_80007E50(s32, s32, s32);
s32 fn_8004D80C(void);
s32 fn_8004DBBC(s32, s32, s32);

s32 fn_80007E50(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;

    temp_r3 = fn_8004D80C();
    if (temp_r3 != 0) {
        fn_8004DBBC(temp_r3, arg1, arg2);
    }
    return 1;
}
}

extern "C" {

s32 __dt__7GSsceneFv(s32, s32);
s32 fn_80008E0C(s32);

s32 fn_80008E0C(s32 arg0) {
    if (arg0 != 0) {
        __dt__7GSsceneFv(arg0, 1);
    }
    return 1;
}
}

extern "C" {

s32 fn_80009360(s32, s32, s32);

s32 fn_80009360(s32 arg0, s32 arg1, s32 arg2) {
    freeFileCacheEntry__7GScacheFUlUl((s32)(arg1), (s32)((arg2 & 0x7FFF0000) | 0x2C00));
    return 1;
}
}

extern "C" {

s32 fn_80009404(s32);
s32 fn_801E4A84(s32);
s32 fn_801E4BCC(s32, s32);

s32 fn_80009404(s32 arg0) {
    if (arg0 != 0) {
        fn_801E4BCC(arg0, 0);
        fn_801E4A84(arg0);
    }
    return 1;
}
}

extern "C" {

s32 fn_800094C0(s32, s32, s32);

s32 fn_800094C0(s32 arg0, s32 arg1, s32 arg2) {
    freeFileCacheEntry__7GScacheFUlUl((s32)(arg1), (s32)((arg2 & 0x7FFF0000) | 0x1000));
    return 1;
}
}
