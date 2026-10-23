#include ".unsorted/80254460.hpp"

#include "common.hpp"

extern "C" {

extern u32 lbl_8063F908;

u32 fn_802544D0(void) {
    return lbl_8063F908;
}
s32 fn_80256520(void) {
    return 1;
}
}

#include "common.hpp"

extern "C" {

void fn_80377024(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

void fn_802558FC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    fn_80377024(*(u32 *)(a0 + 0x0), a1, a2, a3, a4, a5, a6, a7);
}
void fn_80256E34(u8 *p) {
    *(u32 *)(p + 0x0) = 0x0;
}
void fn_80256E80(u8 *p) {
    *(u32 *)(p + 0x0) = 0x0;
}
}

extern "C" {

s32 LoadGroup__Q34nw4r3snd18SoundArchivePlayerFUlPQ34nw4r3snd22SoundMemoryAllocatableUl(s32, u32, s32, s32);
void fn_80255904(s32 *arg0);


}

extern "C" {

s32 GetSoundPlayer__Q34nw4r3snd18SoundArchivePlayerFUl(s32);
s32 SetVolume__Q34nw4r3snd11SoundPlayerFf(f32);

void fn_80255520(u8 *arg0, f32 farg0) {
    GetSoundPlayer__Q34nw4r3snd18SoundArchivePlayerFUl((*(s32 *)((u8 *)(arg0) + (4))));
    SetVolume__Q34nw4r3snd11SoundPlayerFf(farg0);
}
}

extern "C" {

u32 fn_80255968(void);

s32 fn_80255710(void) {
    return (fn_80255968() >> 0x1FU) ^ 1;
}
}

extern "C" {

void fn_80256880(u8 *arg0, s8 arg1, s32 arg2, f32 farg0) {
    (*(s8 *)((u8 *)(arg0) + (0xF4))) = arg1;
    (*(f32 *)((u8 *)(arg0) + (0xF8))) = farg0;
    (*(s32 *)((u8 *)(arg0) + (0xFC))) = arg2;
}
}

extern "C" {

s32 fn_80256E24(u8 *arg0) {
    return ((u32) (*(u32 *)((u8 *)(arg0) + (0x58))) >> 0x1FU) ^ 1;
}
}

extern "C" {

void fn_80259104(s32 *arg0) {
    *arg0 = 0;
}
}

extern "C" {

s32 __dl__FPv(void);

s32 fn_80259110(s32 arg0, s32 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
}

extern "C" {

void fn_80259480(s32 *arg0) {
    *arg0 = 0;
}
}

extern "C" {

s32 Update__Q34nw4r3snd18SoundArchivePlayerFv(s32);
s32 fn_80254C74(void);

void fn_802594E0(u8 *arg0) {
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x48))) > 0) {
        fn_80254C74();
    }
    Update__Q34nw4r3snd18SoundArchivePlayerFv((*(s32 *)((u8 *)(arg0) + (4))));
}
}

extern "C" {

s32 GetInstance__Q44nw4r3snd6detail9AxManagerFv(void);
s32 SetOutputMode__Q44nw4r3snd6detail9AxManagerFQ34nw4r3snd10OutputMode(s32, s32);
s32 fn_802544D8(s32);

s32 fn_802544D8(s32 arg0) {
    return SetOutputMode__Q44nw4r3snd6detail9AxManagerFQ34nw4r3snd10OutputMode(GetInstance__Q44nw4r3snd6detail9AxManagerFv(), arg0);
}
}

extern "C" {

s32 detail_PrepareSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(s32, s32, s32, s32, s32, s32);
s32 fn_802553B8(s32, s32, s32);
s32 fn_80255920(s32, s32);

s32 fn_802553B8(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;
    s32 var_r3;

    if ((u32) arg1 >= ((s32 (*)(s32))fn_802558FC)(arg0)) {
        return -1;
    }
    temp_r3 = fn_80255920(arg0, arg1);
    if (temp_r3 < 0) {
        return -1;
    }
    if (arg2 != 0) {
        var_r3 = detail_PrepareSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo(arg2, (*(s32 *)((u8 *)(arg0) + (0xC))) + (temp_r3 * 4), arg1, 0, 0, 0);
    } else {
        var_r3 = detail_PrepareSound__Q34nw4r3snd14SoundStartableFPQ34nw4r3snd11SoundHandleUlPQ54nw4r3snd6detail10BasicSound14AmbientArgInfoPQ44nw4r3snd6detail19ExternalSoundPlayerPCQ44nw4r3snd14SoundStartable9StartInfo((*(s32 *)((u8 *)(arg0) + (4))) + 0xC, (*(s32 *)((u8 *)(arg0) + (0xC))) + (temp_r3 * 4), arg1, 0, 0, 0);
    }
    if (var_r3 != 0) {
        return -1;
    }
    return temp_r3;
}
}

extern "C" {

s32 StopAllSound__Q34nw4r3snd11SoundPlayerFi(s32, s32);
s32 fn_802554A0(s32, s32, s32);

s32 fn_802554A0(s32 arg0, s32 arg1, s32 arg2) {
    return StopAllSound__Q34nw4r3snd11SoundPlayerFi(((s32 (*)(s32, s32))GetSoundPlayer__Q34nw4r3snd18SoundArchivePlayerFUl)((*(s32 *)((u8 *)(arg0) + (4))), arg1), arg2);
}
}

extern "C" {

s32 PauseAllSound__Q34nw4r3snd11SoundPlayerFbi(s32, s32, s32);
s32 fn_802554D8(s32, s32, s32, s32);

s32 fn_802554D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return PauseAllSound__Q34nw4r3snd11SoundPlayerFbi(((s32 (*)(s32, s32))GetSoundPlayer__Q34nw4r3snd18SoundArchivePlayerFUl)((*(s32 *)((u8 *)(arg0) + (4))), arg1), arg2, arg3);
}
}

extern "C" {

s32 fn_802567E8(s32);
s32 fn_80256BC0(s32, s32);

s32 fn_802567E8(s32 arg0) {
    s32 temp_r3;

    temp_r3 = fn_80256BC0(arg0, 0);
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0))) > 0) {
        (*(s32 *)((u8 *)(arg0) + (0))) = 0;
        (*(s32 *)((u8 *)(arg0) + (0x54))) = 0;
    }
    if ((s32) (*(s32 *)((u8 *)(arg0) + (0x68))) > 0) {
        (*(s32 *)((u8 *)(arg0) + (0x68))) = 0;
    }
    (*(s32 *)((u8 *)(arg0) + (0x5C))) = -1;
    (*(s32 *)((u8 *)(arg0) + (0x58))) = -1;
    return temp_r3;
}
}

extern "C" {

s32 fn_802555F4(s32, s32, s32);

s32 fn_80256BC0(s32 arg0, s32 arg1) {
    s32 temp_r29;
    s32 temp_r31;
    s32 var_r3;

    var_r3 = arg0;
    temp_r29 = var_r3;
    if ((s32) (*(s32 *)((u8 *)(var_r3) + (0x58))) >= 0) {
        temp_r31 = (*(s32 *)((u8 *)(var_r3) + (0x5C)));
        if (temp_r31 < 0) {
            return var_r3;
        }
        var_r3 = fn_802555F4(fn_802544D0(), temp_r31, arg1);
        (*(s32 *)((u8 *)(temp_r29) + (0x5C))) = -1;
        (*(s32 *)((u8 *)(temp_r29) + (0x58))) = -1;
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return var_r3;
    }
    return var_r3;
}
}

extern "C" {

s32 Clear__Q44nw4r3snd6detail9FrameHeapFv(s32);
s32 OSLockMutex(s32);
s32 OSUnlockMutex(s32);

void fn_80254AD0(u8 *arg0, s32 arg1) {
    s32 temp_r31;
    s32 temp_r30;

    temp_r30 = (*(s32 *)((u8 *)(arg0) + (8))) + (arg1 * 0x2C);
    temp_r31 = temp_r30 + 4;
    OSLockMutex(temp_r31);
    Clear__Q44nw4r3snd6detail9FrameHeapFv(temp_r30 + 0x1C);
    OSUnlockMutex(temp_r31);
}
}

extern "C" {

s32 fn_803705F0(s32);

s32 fn_80254B24(u8 *arg0, s32 arg1) {
    s32 temp_r31;
    s32 temp_r30_2;
    s32 temp_r30;

    temp_r30_2 = (*(s32 *)((u8 *)(arg0) + (8))) + (arg1 * 0x2C);
    temp_r31 = temp_r30_2 + 4;
    OSLockMutex((s32)(temp_r31));
    temp_r30 = fn_803705F0(temp_r30_2 + 0x1C);
    OSUnlockMutex((s32)(temp_r31));
    return temp_r30;
}
}

extern "C" {

s32 GetFreeSize__Q44nw4r3snd6detail9FrameHeapCFv(s32);

s32 fn_80254C18(u8 *arg0, s32 arg1) {
    s32 temp_r31;
    s32 temp_r30_2;
    s32 temp_r30;

    temp_r30_2 = (*(s32 *)((u8 *)(arg0) + (8))) + (arg1 * 0x2C);
    temp_r31 = temp_r30_2 + 4;
    OSLockMutex((s32)(temp_r31));
    temp_r30 = GetFreeSize__Q44nw4r3snd6detail9FrameHeapCFv(temp_r30_2 + 0x1C);
    OSUnlockMutex((s32)(temp_r31));
    return temp_r30;
}
}

extern "C" {

s32 GetGroupCount__Q34nw4r3snd12SoundArchiveCFv(s32);

void fn_80255904(s32 *arg0) {
    GetGroupCount__Q34nw4r3snd12SoundArchiveCFv(*arg0);
}
}

extern "C" {

s32 fn_80256568(s32, s32);

s32 fn_80256568(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_80256BC0((s32)(arg0), (s32)(0));
        if (arg1 > 0) {
            ((s32 (*)(s32))__dl__FPv)(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 DetachSound__Q34nw4r3snd11SoundHandleFv(s32);
s32 fn_8025948C(s32, s32);

s32 fn_8025948C(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        DetachSound__Q34nw4r3snd11SoundHandleFv(arg0);
        if (arg1 > 0) {
            ((s32 (*)(s32))__dl__FPv)(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_80254A30(s32 arg0, u32 arg1, s32 arg2, s32 arg3) {
    s32 var_r31;

    var_r31 = arg3;
    if (arg1 >= ((s32 (*)(s32))fn_80255904)(arg0)) {
        return 0;
    }
    if ((var_r31 != 0) && (var_r31 & 0x3F)) {
        var_r31 = (var_r31 + 0x1F) & 0xFFFFFFE0;
    }
    return LoadGroup__Q34nw4r3snd18SoundArchivePlayerFUlPQ34nw4r3snd22SoundMemoryAllocatableUl((s32)((*(s32 *)((u8 *)(arg0) + (4)))), (u32)((s32) arg1), (s32)((*(s32 *)((u8 *)(arg0) + (8))) + (arg2 * 0x2C)), (s32)(var_r31)) != 0;
}
}

extern "C" {

s32 __construct_array(s32, s32, s32, s32, s32);
s32 memset(s32, s32, s32);

u8 *fn_80259044(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (8))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xC))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x10))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x14))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x18))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x1C))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x20))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x24))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x28))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x2C))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0x48))) = 0;
    __construct_array((s32) (arg0 + 0x4C), (s32) &fn_80259104, (s32) &fn_80259110, 0xC, 8);
    (*(s8 *)((u8 *)(arg0) + (0xAC))) = 0;
    (*(s8 *)((u8 *)(arg0) + (0xAD))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xB0))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xB4))) = 0;
    (*(s32 *)((u8 *)(arg0) + (0xD0))) = 0;
    memset((s32) (arg0 + 0x30), 0, 0xC);
    memset((s32) (arg0 + 0x3C), 0, 0xC);
    return arg0;
}
}

extern "C" {

void fn_802556A8(u8 *arg0, s32 arg1, s32 arg2) {
    u32 var_r31;
    u32 temp_r30;

    temp_r30 = (*(u32 *)((u8 *)((*(u8 **)((u8 *)(arg0) + (4)))) + (0x30)));
    var_r31 = 0U;
    while (var_r31 < temp_r30) {
        fn_802554D8((s32)((s32) arg0), (s32)((s32) var_r31), (s32)(arg1), (s32)(arg2));
        var_r31 += 1;
    }
}
}

extern "C" {

s32 fn_80255890(u8 *arg0) {
    s32 temp_r0;
    s32 var_r31;
    u32 var_r30;

    var_r31 = 0;
    var_r30 = 0U;
    while (var_r30 < (u32) (*(u32 *)((u8 *)(arg0) + (0x24)))) {
        temp_r0 = *((s32 * (*)(s32, u32))GetSoundPlayer__Q34nw4r3snd18SoundArchivePlayerFUl)((*(s32 *)((u8 *)(arg0) + (4))), var_r30);
        var_r30 += 1;
        var_r31 += temp_r0;
    }
    return var_r31;
}
}

extern "C" {

struct VT_fn_802552AC_0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual s32 v3(void); };
struct VT_fn_802552AC_1 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual s32 v7(s32); };

s32 fn_802552AC(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_r30;
    s32 temp_r31;
    s32 temp_r3;
    u8 **temp_r3_2;
    u8 **temp_r3_3;

    temp_r3 = ((s32)fn_80255968());
    if (temp_r3 >= 0) {
        temp_r30 = (*(s32 *)((u8 *)(arg0) + (0xC)));
        temp_r31 = temp_r3 * 4;
        temp_r3_2 = *(u8 ** *)((u8 *)0 + (temp_r30 + temp_r31));
        if (temp_r3_2 != NULL) {
            ((VT_fn_802552AC_0 *)(temp_r3_2))->v3();
        }
        if (arg2 > 0) {
            temp_r3_3 = *(u8 ** *)((u8 *)0 + (temp_r30 + temp_r31));
            if (temp_r3_3 != NULL) {
                ((VT_fn_802552AC_1 *)(temp_r3_3))->v7((s32)(arg2));
            }
        }
    }
    return temp_r3;
}
}

extern "C" {

struct VT_fn_80255350_0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual s32 v4(s32); };

void fn_80255350(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;
    u8 **temp_r3_2;

    temp_r3 = ((s32)fn_80255968());
    if (temp_r3 >= 0) {
        temp_r3_2 = *(u8 ** *)((*(u8 **)((u8 *)(arg0) + (0xC))) + (temp_r3 * 4));
        if (temp_r3_2 != NULL) {
            ((VT_fn_80255350_0 *)(temp_r3_2))->v4((s32)(arg2));
        }
    }
}
}

extern "C" {

struct VT_fn_80255560_0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual s32 v3(void); };
struct VT_fn_80255560_1 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual s32 v7(s32); };

void fn_80255560(u8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;
    u8 **temp_r3;
    u8 **temp_r3_2;

    if (arg1 >= 0) {
        temp_r31 = arg1 * 4;
        temp_r3 = *(u8 ** *)((*(u8 **)((u8 *)(arg0) + (0xC))) + temp_r31);
        if (temp_r3 != NULL) {
            ((VT_fn_80255560_0 *)(temp_r3))->v3();
        }
        if (arg2 > 0) {
            temp_r3_2 = *(u8 ** *)((*(u8 **)((u8 *)(arg0) + (0xC))) + temp_r31);
            if (temp_r3_2 != NULL) {
                ((VT_fn_80255560_1 *)(temp_r3_2))->v7((s32)(arg2));
            }
        }
    }
}
}

extern "C" {

struct VT_fn_80255628_0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual s32 v12(s32); };

void fn_80255628(u8 *arg0, s32 arg1, s32 arg2) {
    u8 **temp_r3;

    if (arg1 >= 0) {
        temp_r3 = *(u8 ** *)((*(u8 **)((u8 *)(arg0) + (0xC))) + (arg1 * 4));
        if (temp_r3 != NULL) {
            ((VT_fn_80255628_0 *)(temp_r3))->v12((s32)(arg2));
        }
    }
}
}

extern "C" {

struct VT_fn_80255738_0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual s32 v9(void); };

s32 fn_80255738(u8 *arg0) {
    s32 temp_r3;
    s32 var_r31;
    u8 **temp_r3_2;

    temp_r3 = ((s32)fn_80255968());
    if (temp_r3 >= 0) {
        var_r31 = 0;
        temp_r3_2 = *(u8 ** *)((*(u8 **)((u8 *)(arg0) + (0xC))) + (temp_r3 * 4));
        if ((temp_r3_2 != NULL) && (((VT_fn_80255738_0 *)(temp_r3_2))->v9() != 0)) {
            var_r31 = 1;
        }
        return var_r31;
    }
    return 0;
}
}

extern "C" {

s32 fn_80255808(u8 *arg0, s32 arg1) {
    if (arg1 < 0) {
        return 0;
    }
    return *(s32 *)((u8 *)0 + ((*(s32 *)((u8 *)(arg0) + (0xC))) + (arg1 * 4))) != 0;
}
}
