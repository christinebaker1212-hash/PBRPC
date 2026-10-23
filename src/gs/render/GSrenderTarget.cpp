#include "gs/render/GSrenderTarget.hpp"

#include "common.hpp"

GSrenderTarget *GSrenderTarget::sHead;
GSrenderTarget *GSrenderTarget::sTail;

GSrenderTarget::GSrenderTarget(s32 id, u8 arg1, u8 arg2, u32 arg3)
    : mId(id), _4(arg1), _5(arg2), _6(), _8(arg3), _c(), _10(), _14(), mNext() {
    registerTarget(this);
}

GSrenderTarget::~GSrenderTarget() {
    fn_8023B2F0();
    unregisterTarget(this);
}

GSrenderTarget *GSrenderTarget::findTarget(s32 id) {
    GSrenderTarget *module = sHead;
    while (module) {
        if (module->mId == id) {
            return module;
        }
        module = module->mNext;
    }
    return NULL;
}

void GSrenderTarget::registerTarget(GSrenderTarget *target) {
    if (!sHead) {
        sHead = target;
    }

    if (sTail) {
        sTail->mNext = target;
    }

    sTail = target;
}

void GSrenderTarget::unregisterTarget(GSrenderTarget *target) {
    if (target == sHead) {
        sHead = target->mNext;

        if (sTail == target) {
            sTail = NULL;
        }
    } else {
        GSrenderTarget *prev = sHead;
        while (prev) {
            if (prev->mNext == target) {
                break;
            }
            prev = prev->mNext;
        }

        prev->mNext = target->mNext;

        if (sTail == target) {
            sTail = target->mNext;
        }
    }

    target->mNext = NULL;
}

void GSrenderTarget::fn_8023B3B8(u32 arg0) {
    u8 targetId = (arg0 >> 16) & 0xff;
    if (targetId != mId) {
        return;
    }

    s32 _unk1 = (arg0 >> 8) & 0xff;
    if (!_unk1) {
        return;
    }

    u8 _unk2 = arg0 & 0xff;
    if (!_unk2) {
        return;
    }

    _UnkRenderTargetStruct_1 *_unk3 = _10;
    while (_unk3) {
        if (_unk1 == _unk3->_0->_0 && _unk2 == _unk3->_4->_4) {
            _unk3->_8++;
            return;
        }
        _unk3 = _unk3->mNext;
    }
}

void GSrenderTarget::fn_8023B59C() {}

extern "C" {

s32 fn_8023481C(s32, s32, s32, s32);
s32 fn_8023B490(s32, s32);
s32 fn_8023B5A0(s32);
extern s32 lbl_8063F730;
extern s32 lbl_8063F734;
extern s32 sInstance__8GSrender;

s32 fn_8023B5A0(s32 arg0) {
    s32 temp_r31;
    s32 var_r3;
    u8 temp_r4;

    var_r3 = arg0;
    temp_r31 = var_r3;
    if ((s32) (*(s32 *)((u8 *)(var_r3) + (0xC))) != 0) {
        if ((s32) (*(u16 *)((u8 *)(var_r3) + (6))) != 0) {
            return var_r3;
        }
        lbl_8063F730 = var_r3;
        lbl_8063F734 = (*(s32 *)((u8 *)(var_r3) + (0xC)));
        var_r3 = fn_8023B490(var_r3, 0);
        temp_r4 = (*(u8 *)((u8 *)(temp_r31) + (4)));
        if (((s32) temp_r4 != 0) || ((s32) (*(u8 *)((u8 *)(temp_r31) + (5))) != 0)) {
            var_r3 = fn_8023481C(sInstance__8GSrender, (s32) temp_r4, (s32) temp_r4, (s32) (*(u8 *)((u8 *)(temp_r31) + (5))));
        }
        lbl_8063F730 = 0;
        lbl_8063F734 = 0;
        /* Duplicate return node #7. Try simplifying control flow for better match */
        return var_r3;
    }
    return var_r3;
}
}

extern "C" {

s32 __dl__FPv(s32);

void fn_8023B2F0__14GSrenderTargetFv(u8 *arg0) {
    u8 *temp_r31;
    u8 *var_r3;

    var_r3 = (*(u8 **)((u8 *)(arg0) + (0x10)));
    while (var_r3 != NULL) {
        temp_r31 = (*(u8 **)((u8 *)(var_r3) + (0x10)));
        __dl__FPv((s32) var_r3);
        var_r3 = temp_r31;
    }
}
}

extern "C" {

void fn_8023B240(u8 *arg0, u32 arg1) {
    u8 *temp_r31;
    u8 *var_r3;

    var_r3 = (*(u8 **)((u8 *)(arg0) + (0x10)));
    while (var_r3 != NULL) {
        temp_r31 = (*(u8 **)((u8 *)(var_r3) + (0x10)));
        if ((u32) (*(u32 *)((u8 *)(var_r3) + (0))) == arg1) {
            __dl__FPv((s32)((s32) var_r3));
        }
        var_r3 = temp_r31;
    }
}
}

extern "C" {

void fn_8023B298(u8 *arg0, u32 arg1) {
    u8 *temp_r31;
    u8 *var_r3;

    var_r3 = (*(u8 **)((u8 *)(arg0) + (0x10)));
    while (var_r3 != NULL) {
        temp_r31 = (*(u8 **)((u8 *)(var_r3) + (0x10)));
        if ((u32) (*(u32 *)((u8 *)(var_r3) + (4))) == arg1) {
            __dl__FPv((s32)((s32) var_r3));
        }
        var_r3 = temp_r31;
    }
}
}
