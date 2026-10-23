#include ".unsorted/8004ACF4.hpp"

#include "common.hpp"

extern "C" {

extern f32 lbl_80640A08;

void fn_8004B104(void) {}
void fn_8004B128(void) {}
void fn_8004B14C(void) {}
void fn_8004B760(void) {}
void fn_8004B764(void) {}
void fn_8004B768(void) {}
void fn_8004B800(void) {}
void fn_8004B804(void) {}
void fn_8004B808(void) {}
void fn_8004BFEC(void) {}
void fn_8004BFF0(void) {}
void fn_8004BFF4(void) {}
void fn_8004C3E0(void) {}
f32 fn_8004C3E4(void) {
    return lbl_80640A08;
}
void fn_8004C6DC(void) {}
}

// Battle effect objects (color animation helpers, effect factory)
struct EffVTable {
    void *unk0;
    void *unk4;
    void (*dtor)(void *, s32);
    void (*fnC)(void *);
    void (*fn10)(void *);
    void (*fn14)(void *);
    f32 (*fn18)(void *);
};

struct EffObj {
    /* 0x00 */ u8 unk0[0x10];
    /* 0x10 */ EffVTable *vt;
};

struct EffOwner {
    /* 0x00 */ u8 unk0[0x2C];
    /* 0x2C */ EffObj *effect;
};

struct EffLink {
    /* 0x00 */ u8 unk0[0x18];
    /* 0x18 */ u8 *unk18;
};

struct EffBase {
    /* 0x00 */ u8 unk0[4];
    /* 0x04 */ EffLink *owner;
    /* 0x08 */ f32 *unk8;
    /* 0x0C */ u8 *unkC;
    /* 0x10 */ void *vt;
};

struct EffSource {
    /* 0x00 */ u8 unk0[0x14];
    /* 0x14 */ f32 *unk14;
};

extern "C" {

extern const f32 lbl_806409F8;
extern u8 lbl_8040AA70[];

void fn_8004ACF4(u8 *color, f32 *out) {
    f32 r = color[0];
    f32 g = color[1];
    f32 b = color[2];
    f32 a = color[3];
    out[0] = r;
    out[1] = g;
    out[2] = b;
    out[3] = a;
}

void fn_8004AD60(f32 *in, u8 *color) {
    u8 r = in[0];
    u8 g = in[1];
    u8 b = in[2];
    u8 a = in[3];
    color[0] = r;
    color[1] = g;
    color[2] = b;
    color[3] = a;
}

void fn_8004B0E4(EffOwner *owner) {
    EffObj *eff = owner->effect;
    if (eff != NULL) {
        eff->vt->fnC(eff);
    }
}

void fn_8004B108(EffOwner *owner) {
    EffObj *eff = owner->effect;
    if (eff != NULL) {
        eff->vt->fn10(eff);
    }
}

void fn_8004B12C(EffOwner *owner) {
    EffObj *eff = owner->effect;
    if (eff != NULL) {
        eff->vt->fn14(eff);
    }
}

EffBase *fn_8004B150(EffBase *self, EffSource *src) {
    self->owner = (EffLink *)src;
    self->vt = lbl_8040AA70;
    self->unk8 = src->unk14;
    self->unkC = (u8 *)src->unk14 + 0x38;
    return self;
}

void *fn_8004B174(void *self, s32 flag) {
    if (self != NULL && flag > 0) {
        operator delete(self);
    }
    return self;
}

u8 *fn_8004B1B4(EffBase *self) {
    EffLink *link = self->owner;
    if (link == NULL) {
        return NULL;
    }
    if (link->unk18 != NULL) {
        return *(u8 **)(link->unk18 + 0x34);
    }
    return NULL;
}

u32 fn_8004B1E4(EffBase *self) {
    EffLink *link = self->owner;
    if (link == NULL) {
        return 0;
    }
    if (link->unk18 != NULL) {
        u8 *p = *(u8 **)(link->unk18 + 0x34);
        if (p != NULL) {
            return *(u32 *)(p + 0xC04);
        }
    }
    return 0;
}

f32 fn_8004B220(EffBase *self) {
    if (self->unk8 != NULL) {
        return self->unk8[1];
    }
    return lbl_806409F8;
}
}

extern "C" {

s32 fn_8004B2F0(void);

void fn_8004B2E4(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0x88))) = 0;
    fn_8004B2F0();
}
}

extern "C" {

s32 fn_8004BC8C(void);

void fn_8004BC80(u8 *arg0) {
    (*(s32 *)((u8 *)(arg0) + (0x44))) = 0;
    fn_8004BC8C();
}
}

extern "C" {

s32 fn_80033088__Fv(void);
s32 fn_80034E68__FP11Unk80033090Uc(s32, s32);
s32 fn_80050388(u8 *);

void fn_8004BD24(u8 *arg0) {
    s32 temp_r31;

    temp_r31 = fn_80033088__Fv();
    (*(s8 *)((u8 *)(arg0) + (0))) = 0;
    fn_80050388(arg0 + 0x1C);
    if (*(*(s32 **)((u8 *)(arg0) + (0x14))) & 1) {
        fn_80034E68__FP11Unk80033090Uc(temp_r31, 0);
    }
}
}

extern "C" {

s32 __dl__FPv(s32);
s32 fn_8004B28C(s32, s32);

s32 fn_8004B28C(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8004B174((void *)(arg0), (s32)(0));
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8004B708(s32, s32);

s32 fn_8004B708(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8004B174((void *)(arg0), (s32)(0));
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8004B7A8(s32, s32);

s32 fn_8004B7A8(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8004B174((void *)(arg0), (s32)(0));
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8004B864(s32, s32);

s32 fn_8004B864(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8004B174((void *)(arg0), (s32)(0));
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8004B8BC(s32);
s32 fn_8004B900(s32);

s32 fn_8004B8BC(s32 arg0) {
    s32 var_r3;

    var_r3 = fn_8004B1E4((EffBase *)(arg0));
    if (var_r3 != 0) {
        (*(s32 *)((u8 *)(arg0) + (0x44))) = 0;
        var_r3 = fn_8004B900(arg0);
    }
    return var_r3;
}
}

extern "C" {

s32 fn_8004BC28(s32, s32);

s32 fn_8004BC28(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8004B174((void *)(arg0), (s32)(0));
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8004BF94(s32, s32);

s32 fn_8004BF94(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8004B174((void *)(arg0), (s32)(0));
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8004C740(s32, s32);

s32 fn_8004C740(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        fn_8004B174((void *)(arg0), (s32)(0));
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}

extern "C" {

s32 fn_8004C7E4(u8 *);

void fn_8004C798(u8 *arg0) {
    u8 *temp_r3;

    temp_r3 = ((u8 * (*)(void))fn_8004B1B4)();
    if (temp_r3 != NULL) {
        (*(s32 *)((u8 *)(arg0) + (0xB4))) = (s32) (*(s32 *)((u8 *)(temp_r3) + (0xC04)));
    }
    (*(s32 *)((u8 *)(arg0) + (0xB0))) = 0;
    fn_8004C7E4(arg0);
}
}
