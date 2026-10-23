#pragma once

#include <revolution/types.h>

// TODO Identify the record populated by fn_80126A10; only its prefix is known.
struct Unk80126A10 {
    /* 0x00 */ u8 unk00[2];
    /* 0x02 */ u8 _02;
    /* 0x03 */ u8 _03;
    /* 0x04 */ u8 _04;
    // size: unknown (known prefix: 0x05)
};

// TODO Identify the scene context referenced by lbl_8063D558.
struct Unk8011E1FC {
    /* 0x0000 */ u8 unk0000[0x12C];
    /* 0x012C */ u16 _12C;
    /* 0x012E */ u8 unk012E[0x1996];
    /* 0x1AC4 */ void *_1AC4;
    // size: unknown (known prefix: 0x1AC8)
};
