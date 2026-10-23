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

extern "C" {

void initialize__Q23EGG5VideoFP16_GXRenderModeObj(s32 arg0, s32 arg1) {
    ((s32 (*)(s32, s32))unlockCacheEntry__7GScacheFUlUl)(arg0, arg1);
    getCachedFile__7GScacheFUlUl((u32)(arg0), (s32)(arg1));
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_803E5928;

s32 *fn_80007940() {
    return &lbl_803E5928;
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_803E6ED0;

s32 *fn_800079C0() {
    return &lbl_803E6ED0;
}
}

extern "C" {

__declspec(section ".data") extern s32 lbl_803E90A8;

s32 *fn_80007A40() {
    return &lbl_803E90A8;
}
}

extern "C" {

s32 createCacheEntryAligned__7GScacheFUlUlUlUlPFPvUlUl_b(s32, s32, s32, s32, s32);
s32 fn_802268F4(s32);
void fn_80007B74(void);

s32 fn_80007C54(u32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r4;
    s32 var_r31;

    if (fn_802268F4(lbl_8063F640) != 0) {
        return 0;
    }
    temp_r4 = (arg2 + 0x1F) & 0xFFFFFFE0;
    if ((arg0 == 0xCU) || (arg0 == 0xAU)) {
        var_r31 = createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b((s32)(gUnkHeap2), (s32)(temp_r4), (s32)(0x20), (s32)((s32) arg0), (s32)(arg1), (s32)((s32) &fn_80007B74));
    } else {
        var_r31 = createCacheEntryAligned__7GScacheFUlUlUlUlPFPvUlUl_b(temp_r4, 0x20, (s32) arg0, arg1, (s32) &fn_80007B74);
    }
    lockCacheEntry__7GScacheFUlUl((s32)((s32) arg0), (s32)(arg1));
    return var_r31;
}
}

extern "C" {

s32 fn_80007EA0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;

    temp_r31 = createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b((s32)(gUnkHeap2), (s32)((arg2 + 0x1F) & 0xFFFFFFE0), (s32)(0x20), (s32)(arg0), (s32)(arg1), (s32)((s32) &fn_80007E50));
    lockCacheEntry__7GScacheFUlUl((s32)(arg0), (s32)(arg1));
    return temp_r31;
}
}

extern "C" {

s32 fn_8004DB54(s32, s32, s32);

s32 fn_80007F14(s32 arg0, s32 arg1) {
    s32 temp_r3;
    s32 temp_r30;

    temp_r30 = fn_8004D80C();
    ((s32 (*)(s32, s32))unlockCacheEntry__7GScacheFUlUl)(arg0, arg1);
    temp_r3 = getCachedFile__7GScacheFUlUl((u32)(arg0), (s32)(arg1));
    if ((temp_r3 != 0) && (temp_r30 != 0)) {
        fn_8004DB54(temp_r30, arg0, arg1);
    }
    return temp_r3;
}
}

extern "C" {

s32 fn_80007FCC(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;

    temp_r31 = createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b((s32)(gUnkHeap2), (s32)((arg2 + 0x1F) & 0xFFFFFFE0), (s32)(0x20), (s32)(arg0), (s32)(arg1), (s32)((s32) &fn_80007FA0));
    lockCacheEntry__7GScacheFUlUl((s32)(arg0), (s32)(arg1));
    return temp_r31;
}
}

extern "C" {

s32 fn_800080CC(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;

    temp_r31 = createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b((s32)(gUnkHeap2), (s32)((arg2 + 0x1F) & 0xFFFFFFE0), (s32)(0x20), (s32)(arg0), (s32)(arg1), (s32)((s32) &fn_800080A0));
    lockCacheEntry__7GScacheFUlUl((s32)(arg0), (s32)(arg1));
    return temp_r31;
}
}

extern "C" {

s32 fn_800081A8(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;

    temp_r31 = createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b((s32)(gUnkHeap2), (s32)((arg2 + 0x1F) & 0xFFFFFFE0), (s32)(0x20), (s32)(arg0), (s32)(arg1), (s32)((s32) &fn_800081A0));
    lockCacheEntry__7GScacheFUlUl((s32)(arg0), (s32)(arg1));
    return temp_r31;
}
}

extern "C" {

s32 fn_80008260(s32 arg0, s32 arg1, s32 arg2);

s32 fn_800087A0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;

    temp_r31 = createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b((s32)(gUnkHeap2), (s32)((arg2 + 0x1F) & 0xFFFFFFE0), (s32)(0x20), (s32)(arg0), (s32)(arg1), (s32)((s32) &fn_80008260));
    lockCacheEntry__7GScacheFUlUl((s32)(arg0), (s32)(arg1));
    return temp_r31;
}
}

extern "C" {

s32 fn_80008E68(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;
    s32 var_r31;

    temp_r31 = (arg2 + 0x1F) & 0xFFFFFFE0;
    if ((fn_80007B18((u32)(arg0)) != 0) || ((u32) arg0 == 0x1EAAU) || ((u32) arg0 == 0xCU)) {
        var_r31 = createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b((s32)(gUnkHeap2), (s32)(temp_r31), (s32)(0x20), (s32)(arg0), (s32)(arg1), (s32)((s32) &fn_80008E3C));
    } else {
        var_r31 = createCacheEntryAligned__7GScacheFUlUlUlUlPFPvUlUl_b((s32)(temp_r31), (s32)(0x20), (s32)(arg0), (s32)(arg1), (s32)((s32) &fn_80008E3C));
    }
    lockCacheEntry__7GScacheFUlUl((s32)(arg0), (s32)(arg1));
    return var_r31;
}
}

extern "C" {

s32 fn_8000904C(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;

    temp_r31 = createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b((s32)(gUnkHeap2), (s32)((arg2 + 0x1F) & 0xFFFFFFE0), (s32)(0x20), (s32)(arg0), (s32)(arg1), (s32)((s32) &fn_80009020));
    lockCacheEntry__7GScacheFUlUl((s32)(arg0), (s32)(arg1));
    return temp_r31;
}
}

extern "C" {

s32 fn_801E3920(s32, s32);

s32 fn_800090C0(s32 arg0, s32 arg1) {
    s32 temp_r3;

    ((s32 (*)(s32, s32))unlockCacheEntry__7GScacheFUlUl)(arg0, arg1);
    temp_r3 = getCachedFile__7GScacheFUlUl((u32)(arg0), (s32)(arg1));
    if (temp_r3 != 0) {
        fn_801E3920(temp_r3, temp_r3);
    }
    return temp_r3;
}
}

extern "C" {

s32 fn_80009148(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;

    temp_r31 = createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b((s32)(gUnkHeap2), (s32)((arg2 + 0x1F) & 0xFFFFFFE0), (s32)(0x20), (s32)(arg0), (s32)(arg1), (s32)((s32) &fn_8000911C));
    lockCacheEntry__7GScacheFUlUl((s32)(arg0), (s32)(arg1));
    return temp_r31;
}
}

extern "C" {

s32 fn_801E3C94(s32, s32);

s32 fn_800091BC(s32 arg0, s32 arg1) {
    s32 temp_r3;

    ((s32 (*)(s32, s32))unlockCacheEntry__7GScacheFUlUl)(arg0, arg1);
    temp_r3 = getCachedFile__7GScacheFUlUl((u32)(arg0), (s32)(arg1));
    if (temp_r3 != 0) {
        fn_801E3C94(temp_r3, temp_r3);
    }
    return temp_r3;
}
}

extern "C" {

s32 fn_80009220(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;

    temp_r31 = createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b((s32)(gUnkHeap2), (s32)((arg2 + 0x1F) & 0xFFFFFFE0), (s32)(0x20), (s32)(arg0), (s32)(arg1), (s32)((s32) &fn_80009218));
    lockCacheEntry__7GScacheFUlUl((s32)(arg0), (s32)(arg1));
    return temp_r31;
}
}

extern "C" {

s32 fn_80206D8C(s32);
s32 setCacheEntryBuffer__7GScacheFPvUlUlPFPvUlUl_b(s32, s32, s32, s32);

s32 fn_800092E8(s32 arg0, s32 arg1) {
    s32 temp_r3;

    ((s32 (*)(s32, s32))unlockCacheEntry__7GScacheFUlUl)(arg0, arg1);
    temp_r3 = fn_80206D8C(getCachedFile__7GScacheFUlUl((u32)(arg0), (s32)(arg1)));
    if (temp_r3 != 0) {
        setCacheEntryBuffer__7GScacheFPvUlUlPFPvUlUl_b(temp_r3, arg0, (arg1 & 0x7FFF0000) | 0xE00, (s32) &fn_80009294);
    }
    return temp_r3;
}
}

extern "C" {

s32 fn_80009390(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;

    temp_r31 = createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b((s32)(gUnkHeap2), (s32)((arg2 + 0x1F) & 0xFFFFFFE0), (s32)(0x20), (s32)(arg0), (s32)(arg1), (s32)((s32) &fn_80009360));
    lockCacheEntry__7GScacheFUlUl((s32)(arg0), (s32)(arg1));
    return temp_r31;
}
}

extern "C" {

s32 fn_801E4970(s32);

s32 fn_80009448(s32 arg0, s32 arg1) {
    s32 temp_r3;

    ((s32 (*)(s32, s32))unlockCacheEntry__7GScacheFUlUl)(arg0, arg1);
    temp_r3 = fn_801E4970(getCachedFile__7GScacheFUlUl((u32)(arg0), (s32)(arg1)));
    if (temp_r3 != 0) {
        setCacheEntryBuffer__7GScacheFPvUlUlPFPvUlUl_b((s32)(temp_r3), (s32)(arg0), (s32)((arg1 & 0x7FFF0000) | 0x2C00), (s32)((s32) &fn_80009404));
    }
    return temp_r3;
}
}

extern "C" {

s32 fn_800094F0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;

    temp_r31 = createCacheEntryOnHeapAligned__7GScacheFP12MEMiHeapHeadUlUlUlUlPFPvUlUl_b((s32)(gUnkHeap2), (s32)((arg2 + 0x1F) & 0xFFFFFFE0), (s32)(0x20), (s32)(arg0), (s32)(arg1), (s32)((s32) &fn_800094C0));
    lockCacheEntry__7GScacheFUlUl((s32)(arg0), (s32)(arg1));
    return temp_r31;
}
}

extern "C" {

void fn_800096C0(s32 arg0, s32 arg1) {
    ((s32 (*)(s32, s32))unlockCacheEntry__7GScacheFUlUl)(arg0, arg1);
    getCachedFile__7GScacheFUlUl((u32)(arg0), (s32)(arg1));
}
}

extern "C" {

void fn_80009774(s32 arg0, s32 arg1) {
    ((s32 (*)(s32, s32))unlockCacheEntry__7GScacheFUlUl)(arg0, arg1);
    getCachedFile__7GScacheFUlUl((u32)(arg0), (s32)(arg1));
}
}

extern "C" {

s32 fn_8038F804(s32);
s32 fn_8038FAA4(s32);
s32 fn_8038FCDC(s32);
s32 fn_80390324(s32);
s32 fn_803905F8(s32);
s32 fn_803908B4(s32);
s32 fn_80390BC4(s32);
s32 fn_80391114(s32);
s32 fn_803915EC(s32);
s32 fn_80391824(s32);
s32 fn_80392234(s32);
s32 fn_803924F8(s32);
s32 fn_803927B8(s32);
s32 fn_80392AD0(s32);
s32 fn_80395190(s32);
s32 fn_80395A20(s32);
s32 fn_80395D7C(s32);
s32 fn_8039633C(s32);
s32 fn_80396634(s32);
s32 fn_803969C4(s32);
s32 fn_80396C98(s32);
s32 fn_803970A4(s32);
s32 fn_8039754C(s32);
s32 fn_80397874(s32);
s32 fn_80397E10(s32);
s32 fn_80398578(s32);
s32 fn_803988B4(s32);
s32 fn_80398BA4(s32);
s32 fn_80398EFC(s32);
s32 fn_803994BC(s32);
s32 fn_803997B0(s32);
s32 fn_80399BF0(s32);
s32 fn_80399EAC(s32);
__declspec(section ".data") extern s32 lbl_8063CE34;

s32 fn_80008260(s32 arg0, s32 arg1, s32 arg2) {
    switch (arg2) {                                 /* irregular */
    case 0x800200:
        fn_80391114((s32) &lbl_8063CE34);
        break;
    case 0x7D0200:
        fn_803908B4((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 4));
        break;
    case 0x7B0200:
        fn_8038F804((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 8));
        break;
    case 0x7C0200:
        fn_8038FCDC((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0xC));
        break;
    case 0x810200:
        fn_80391824((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x10));
        break;
    case 0x820200:
        fn_80392234((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x14));
        break;
    case 0x840200:
        fn_80392AD0((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x18));
        break;
    case 0x7F0200:
        fn_803924F8((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x1C));
        break;
    case 0x830200:
        fn_80390324((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x20));
        break;
    case 0x7E0200:
        fn_803905F8((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x24));
        break;
    case 0x850200:
        fn_80395D7C((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x28));
        break;
    case 0x860200:
        fn_80395190((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x2C));
        break;
    case 0x870200:
        fn_80395A20((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x30));
        break;
    case 0xBB70200:
        fn_80390BC4((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x34));
        break;
    case 0x11830200:
        fn_8039633C((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x38));
        break;
    case 0x11C00200:
        fn_803915EC((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x3C));
        break;
    case 0x12330200:
        fn_8038FAA4((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x40));
        break;
    case 0x12880200:
        fn_80396634((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x44));
        break;
    case 0x12A90200:
        fn_803927B8((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x48));
        break;
    case 0x16410200:
        fn_803969C4((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x4C));
        break;
    case 0x1B070200:
        fn_80396C98((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x50));
        break;
    case 0x1BF50200:
        fn_803970A4((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x54));
        break;
    case 0x1CE50200:
        fn_8039754C((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x58));
        break;
    case 0x1D5A0200:
        fn_80397874((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x5C));
        break;
    case 0x1D9C0200:
        fn_80397E10((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x60));
        break;
    case 0x1D9D0200:
        fn_80398578((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x64));
        break;
    case 0x1DAF0200:
        fn_803988B4((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x68));
        break;
    case 0x20A70200:
        fn_80398BA4((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x6C));
        break;
    case 0x21150200:
        fn_80398EFC((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x70));
        break;
    case 0x215B0200:
        fn_803994BC((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x74));
        break;
    case 0x216E0200:
        fn_803997B0((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x78));
        break;
    case 0x23550200:
        fn_80399BF0((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x7C));
        break;
    case 0x27CD0200:
        fn_80399EAC((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x80));
        break;
    }
    return 1;
}
}

extern "C" {

s32 fn_8038F1CC(s32);
s32 fn_8038F6A0(s32, s32);
s32 fn_8038F940(s32, s32);
s32 fn_8038FB78(s32, s32);
s32 fn_803901C0(s32, s32);
s32 fn_80390494(s32, s32);
s32 fn_80390750(s32, s32);
s32 fn_80390A60(s32, s32);
s32 fn_80390FB0(s32, s32);
s32 fn_80391488(s32, s32);
s32 fn_803916C0(s32, s32);
s32 fn_803920D0(s32, s32);
s32 fn_80392394(s32, s32);
s32 fn_80392654(s32, s32);
s32 fn_8039296C(s32, s32);
s32 fn_8039502C(s32, s32);
s32 fn_803958BC(s32, s32);
s32 fn_80395C18(s32, s32);
s32 fn_803961D8(s32, s32);
s32 fn_803964D0(s32, s32);
s32 fn_80396860(s32, s32);
s32 fn_80396B34(s32, s32);
s32 fn_80396F40(s32, s32);
s32 fn_803973E8(s32, s32);
s32 fn_80397710(s32, s32);
s32 fn_80397CAC(s32, s32);
s32 fn_80398414(s32, s32);
s32 fn_80398750(s32, s32);
s32 fn_80398A40(s32, s32);
s32 fn_80398D98(s32, s32);
s32 fn_80399358(s32, s32);
s32 fn_8039964C(s32, s32);
s32 fn_80399A8C(s32, s32);
s32 fn_80399D48(s32, s32);

s32 fn_80008814(s32 arg0, s32 arg1) {
    s32 temp_r31;

    ((s32 (*)(s32, s32))unlockCacheEntry__7GScacheFUlUl)(arg0, arg1);
    temp_r31 = getCachedFile__7GScacheFUlUl((u32)(arg0), (s32)(arg1));
    switch (arg1) {                                 /* irregular */
    case 0x800200:
        fn_80390FB0((s32) &lbl_8063CE34, temp_r31);
        break;
    case 0x7D0200:
        fn_80390750((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 4), temp_r31);
        break;
    case 0x7B0200:
        fn_8038F6A0((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 8), temp_r31);
        break;
    case 0x7C0200:
        fn_8038FB78((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0xC), temp_r31);
        break;
    case 0x810200:
        fn_803916C0((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x10), temp_r31);
        break;
    case 0x820200:
        fn_803920D0((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x14), temp_r31);
        break;
    case 0x840200:
        fn_8039296C((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x18), temp_r31);
        break;
    case 0x7F0200:
        fn_80392394((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x1C), temp_r31);
        break;
    case 0x830200:
        fn_803901C0((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x20), temp_r31);
        break;
    case 0x7E0200:
        fn_80390494((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x24), temp_r31);
        break;
    case 0x850200:
        fn_80395C18((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x28), temp_r31);
        break;
    case 0x860200:
        fn_8039502C((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x2C), temp_r31);
        break;
    case 0x870200:
        fn_803958BC((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x30), temp_r31);
        fn_8038F1CC((s32) &lbl_8063CE34);
        break;
    case 0xBB70200:
        fn_80390A60((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x34), temp_r31);
        break;
    case 0x11830200:
        fn_803961D8((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x38), temp_r31);
        break;
    case 0x11C00200:
        fn_80391488((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x3C), temp_r31);
        break;
    case 0x12330200:
        fn_8038F940((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x40), temp_r31);
        break;
    case 0x12880200:
        fn_803964D0((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x44), temp_r31);
        break;
    case 0x12A90200:
        fn_80392654((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x48), temp_r31);
        break;
    case 0x16410200:
        fn_80396860((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x4C), temp_r31);
        break;
    case 0x1B070200:
        fn_80396B34((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x50), temp_r31);
        break;
    case 0x1BF50200:
        fn_80396F40((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x54), temp_r31);
        break;
    case 0x1CE50200:
        fn_803973E8((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x58), temp_r31);
        break;
    case 0x1D5A0200:
        fn_80397710((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x5C), temp_r31);
        break;
    case 0x1D9C0200:
        fn_80397CAC((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x60), temp_r31);
        break;
    case 0x1D9D0200:
        fn_80398414((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x64), temp_r31);
        break;
    case 0x1DAF0200:
        fn_80398750((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x68), temp_r31);
        break;
    case 0x20A70200:
        fn_80398A40((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x6C), temp_r31);
        break;
    case 0x21150200:
        fn_80398D98((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x70), temp_r31);
        break;
    case 0x215B0200:
        fn_80399358((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x74), temp_r31);
        break;
    case 0x216E0200:
        fn_8039964C((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x78), temp_r31);
        break;
    case 0x23550200:
        fn_80399A8C((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x7C), temp_r31);
        break;
    case 0x27CD0200:
        fn_80399D48((s32) ((u8 *)(u8 *)&lbl_8063CE34 + 0x80), temp_r31);
        break;
    }
    return temp_r31;
}
}
