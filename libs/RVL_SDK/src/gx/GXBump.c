// Imported from koopthekoopa/wii-ipl (CC0), libs/RVL_SDK/src/gx/GXBump.c
#include <private/os.h>
#include <revolution/os.h>

#include <private/gx.h>
#include <revolution/gx.h>

#include <private/hollywood.h>

#include <revolution/base/PPCArch.h>

#define GX_WRITE_SOME_REG5(a, b)                                                                                                                     \
    {                                                                                                                                                \
        GX_WRITE_U8(a);                                                                                                                              \
        GX_WRITE_U32(b);                                                                                                                             \
    }

void GXSetTevIndirect(GXTevStageID tev_stage, GXIndTexStageID ind_stage, GXIndTexFormat format, GXIndTexBiasSel bias_sel, GXIndTexMtxID matrix_sel,
                      GXIndTexWrap wrap_s, GXIndTexWrap wrap_t, GXBool add_prev, GXBool utc_lod, GXIndTexAlphaSel alpha_sel) NO_INLINE {
    u32 reg = 0;

    GX_SET_REG_FIELD(reg, 2, 0, ind_stage);
    GX_SET_REG_FIELD(reg, 2, 2, format);
    GX_SET_REG_FIELD(reg, 3, 4, bias_sel);
    GX_SET_REG_FIELD(reg, 2, 7, alpha_sel);
    GX_SET_REG_FIELD(reg, 4, 9, matrix_sel);
    GX_SET_REG_FIELD(reg, 3, 13, wrap_s);
    GX_SET_REG_FIELD(reg, 3, 16, wrap_t);
    GX_SET_REG_FIELD(reg, 1, 19, utc_lod);
    GX_SET_REG_FIELD(reg, 1, 20, add_prev);
    GX_SET_REG_FIELD(reg, 8, 24, tev_stage + 16);

    GX_WRITE_SOME_REG5(GX_LOAD_BP_REG, reg);

    __GXData->bpSentNot = GX_FALSE;
}

void GXSetIndTexMtx(GXIndTexMtxID mtx_id, const Mtx23 offset, s8 scale_exp) {
    s32 mtx[6];
    u32 reg;
    u32 id;

    switch (mtx_id) {
        case GX_ITM_0:
        case GX_ITM_1:
        case GX_ITM_2: {
            id = mtx_id - 1;
            break;
        }
        case GX_ITM_S0:
        case GX_ITM_S1:
        case GX_ITM_S2: {
            id = mtx_id - 5;
            break;
        }
        case GX_ITM_T0:
        case GX_ITM_T1:
        case GX_ITM_T2: {
            id = mtx_id - 9;
            break;
        }
        default: {
            id = 0;
            break;
        }
    }

    mtx[0] = (int)(1024.0f * offset[0][0]) & 0x7FF;
    mtx[1] = (int)(1024.0f * offset[1][0]) & 0x7FF;
    scale_exp += 17;
    reg = 0;
    GX_SET_REG_FIELD(reg, 11, 0, mtx[0]);
    GX_SET_REG_FIELD(reg, 11, 11, mtx[1]);
    GX_SET_REG_FIELD(reg, 2, 22, scale_exp & 3);
    GX_SET_REG_FIELD(reg, 8, 24, id * 3 + 6);
    GX_WRITE_SOME_REG5(GX_LOAD_BP_REG, reg);

    mtx[2] = (int)(1024.0f * offset[0][1]) & 0x7FF;
    mtx[3] = (int)(1024.0f * offset[1][1]) & 0x7FF;
    reg = 0;
    GX_SET_REG_FIELD(reg, 11, 0, mtx[2]);
    GX_SET_REG_FIELD(reg, 11, 11, mtx[3]);
    GX_SET_REG_FIELD(reg, 2, 22, (scale_exp >> 2) & 3);
    GX_SET_REG_FIELD(reg, 8, 24, id * 3 + 7);
    GX_WRITE_SOME_REG5(GX_LOAD_BP_REG, reg);

    mtx[4] = (int)(1024.0f * offset[0][2]) & 0x7FF;
    mtx[5] = (int)(1024.0f * offset[1][2]) & 0x7FF;
    reg = 0;
    GX_SET_REG_FIELD(reg, 11, 0, mtx[4]);
    GX_SET_REG_FIELD(reg, 11, 11, mtx[5]);
    GX_SET_REG_FIELD(reg, 2, 22, (scale_exp >> 4) & 3);
    GX_SET_REG_FIELD(reg, 8, 24, id * 3 + 8);
    GX_WRITE_SOME_REG5(GX_LOAD_BP_REG, reg);

    __GXData->bpSentNot = GX_FALSE;
}

void GXSetIndTexCoordScale(GXIndTexStageID ind_state, GXIndTexScale scale_s, GXIndTexScale scale_t) {
    switch (ind_state) {
        case GX_INDTEXSTAGE0: {
            GX_SET_REG_FIELD(__GXData->IndTexScale0, 4, 0, scale_s);
            GX_SET_REG_FIELD(__GXData->IndTexScale0, 4, 4, scale_t);
            GX_SET_REG_FIELD(__GXData->IndTexScale0, 8, 24, 0x25);
            GX_WRITE_SOME_REG5(GX_LOAD_BP_REG, __GXData->IndTexScale0);
            break;
        }
        case GX_INDTEXSTAGE1: {
            GX_SET_REG_FIELD(__GXData->IndTexScale0, 4, 8, scale_s);
            GX_SET_REG_FIELD(__GXData->IndTexScale0, 4, 12, scale_t);
            GX_SET_REG_FIELD(__GXData->IndTexScale0, 8, 24, 0x25);
            GX_WRITE_SOME_REG5(GX_LOAD_BP_REG, __GXData->IndTexScale0);
            break;
        }
        case GX_INDTEXSTAGE2: {
            GX_SET_REG_FIELD(__GXData->IndTexScale1, 4, 0, scale_s);
            GX_SET_REG_FIELD(__GXData->IndTexScale1, 4, 4, scale_t);
            GX_SET_REG_FIELD(__GXData->IndTexScale1, 8, 24, 0x26);
            GX_WRITE_SOME_REG5(GX_LOAD_BP_REG, __GXData->IndTexScale1);
            break;
        }
        case GX_INDTEXSTAGE3: {
            GX_SET_REG_FIELD(__GXData->IndTexScale1, 4, 8, scale_s);
            GX_SET_REG_FIELD(__GXData->IndTexScale1, 4, 12, scale_t);
            GX_SET_REG_FIELD(__GXData->IndTexScale1, 8, 24, 0x26);
            GX_WRITE_SOME_REG5(GX_LOAD_BP_REG, __GXData->IndTexScale1);
            break;
        }
        default: {
            break;
        }
    }

    __GXData->bpSentNot = GX_FALSE;
}

void GXSetIndTexOrder(GXIndTexStageID ind_stage, GXTexCoordID tex_coord, GXTexMapID tex_map) {
    if (tex_map == GX_TEXMAP_NULL) {
        tex_map = GX_TEXMAP0;
    }

    if (tex_coord == GX_TEXCOORD_NULL) {
        tex_coord = GX_TEXCOORD0;
    }

    switch (ind_stage) {
        case GX_INDTEXSTAGE0: {
            GX_SET_REG_FIELD(__GXData->iref, 3, 0, tex_map);
            GX_SET_REG_FIELD(__GXData->iref, 3, 3, tex_coord);
            break;
        }
        case GX_INDTEXSTAGE1: {
            GX_SET_REG_FIELD(__GXData->iref, 3, 6, tex_map);
            GX_SET_REG_FIELD(__GXData->iref, 3, 9, tex_coord);
            break;
        }
        case GX_INDTEXSTAGE2: {
            GX_SET_REG_FIELD(__GXData->iref, 3, 12, tex_map);
            GX_SET_REG_FIELD(__GXData->iref, 3, 15, tex_coord);
            break;
        }
        case GX_INDTEXSTAGE3: {
            GX_SET_REG_FIELD(__GXData->iref, 3, 18, tex_map);
            GX_SET_REG_FIELD(__GXData->iref, 3, 21, tex_coord);
            break;
        }
        default: {
            break;
        }
    }
    GX_WRITE_SOME_REG5(GX_LOAD_BP_REG, __GXData->iref);

    __GXData->dirtyState |= 3;

    __GXData->bpSentNot = GX_FALSE;
}

void GXSetNumIndStages(u8 nIndStages) {
    GX_SET_REG_FIELD(__GXData->genMode, 3, 16, nIndStages);
    __GXData->dirtyState |= 6;
}

void GXSetTevDirect(GXTevStageID tev_stage) {
    GXSetTevIndirect(tev_stage, GX_INDTEXSTAGE0, GX_ITF_8, GX_ITB_NONE, GX_ITM_OFF, GX_ITW_OFF, GX_ITW_OFF, GX_FALSE, GX_FALSE, GX_ITBA_OFF);
}

void GXSetTevIndWarp(GXTevStageID tev_stage, GXIndTexStageID ind_stage, GXBool signed_offset, GXBool replace_mode, GXIndTexMtxID matrix_sel) {
    GXIndTexWrap wrap = replace_mode ? GX_ITW_0 : GX_ITW_OFF;
    GXIndTexBiasSel bias = signed_offset ? GX_ITB_STU : GX_ITB_NONE;

    GXSetTevIndirect(tev_stage, ind_stage, GX_ITF_8, bias, matrix_sel, wrap, wrap, GX_FALSE, GX_FALSE, GX_ITBA_OFF);
}

static inline GXIndTexWrap TileSizeToWrap(u16 size) {
    switch (size) {
        case 256:
            return GX_ITW_256;
        case 128:
            return GX_ITW_128;
        case 64:
            return GX_ITW_64;
        case 32:
            return GX_ITW_32;
        case 16:
            return GX_ITW_16;
        default:
            return GX_ITW_OFF;
    }
}

void GXSetTevIndTile(GXTevStageID tev_stage, GXIndTexStageID ind_stage, u16 tilesize_s, u16 tilesize_t, u16 tilespacing_s, u16 tilespacing_t,
                     GXIndTexFormat format, GXIndTexMtxID matrix_sel, GXIndTexBiasSel bias_sel, GXIndTexAlphaSel alpha_sel) {
    GXIndTexWrap wrap_s = TileSizeToWrap(tilesize_s);
    GXIndTexWrap wrap_t = TileSizeToWrap(tilesize_t);
    f32 mtx[2][3];

    mtx[0][0] = tilespacing_s / 1024.0f;
    mtx[0][1] = mtx[0][2] = 0.0f;
    mtx[1][1] = tilespacing_t / 1024.0f;
    mtx[1][0] = mtx[1][2] = 0.0f;
    GXSetIndTexMtx(matrix_sel, mtx, 10);

    GXSetTevIndirect(tev_stage, ind_stage, format, bias_sel, matrix_sel, wrap_s, wrap_t, GX_FALSE, GX_TRUE, alpha_sel);
}

void GXSetTevIndBumpST(GXTevStageID tev_stage, GXIndTexStageID ind_stage, GXIndTexMtxID matrix_sel) {
    GXIndTexMtxID mtx_s;
    GXIndTexMtxID mtx_t;

    switch (matrix_sel) {
        case GX_ITM_0:
            mtx_s = GX_ITM_S0;
            mtx_t = GX_ITM_T0;
            break;
        case GX_ITM_1:
            mtx_s = GX_ITM_S1;
            mtx_t = GX_ITM_T1;
            break;
        case GX_ITM_2:
            mtx_s = GX_ITM_S2;
            mtx_t = GX_ITM_T2;
            break;
    }

    GXSetTevIndirect(tev_stage, ind_stage, GX_ITF_8, GX_ITB_ST, mtx_s, GX_ITW_0, GX_ITW_0, GX_FALSE, GX_FALSE, GX_ITBA_OFF);
    GXSetTevIndirect((GXTevStageID)(tev_stage + 1), ind_stage, GX_ITF_8, GX_ITB_ST, mtx_t, GX_ITW_0, GX_ITW_0, GX_TRUE, GX_FALSE, GX_ITBA_OFF);
    GXSetTevIndirect((GXTevStageID)(tev_stage + 2), ind_stage, GX_ITF_8, GX_ITB_NONE, GX_ITM_OFF, GX_ITW_OFF, GX_ITW_OFF, GX_TRUE, GX_FALSE,
                     GX_ITBA_OFF);
}

void GXSetTevIndBumpXYZ(GXTevStageID tev_stage, GXIndTexStageID ind_stage, GXIndTexMtxID matrix_sel) {
    GXSetTevIndirect(tev_stage, ind_stage, GX_ITF_8, GX_ITB_STU, matrix_sel, GX_ITW_OFF, GX_ITW_OFF, GX_FALSE, GX_FALSE, GX_ITBA_OFF);
}

void GXSetTevIndRepeat(GXTevStageID tev_stage) {
    GXSetTevIndirect(tev_stage, GX_INDTEXSTAGE0, GX_ITF_8, GX_ITB_NONE, GX_ITM_OFF, GX_ITW_0, GX_ITW_0, GX_TRUE, GX_FALSE, GX_ITBA_OFF);
}

void __GXUpdateBPMask() {
}

void __GXSetIndirectMask(u32 mask) {
    GX_SET_REG_FIELD(__GXData->bpMask, 8, ~0xFF, mask);

    GX_WRITE_SOME_REG5(GX_LOAD_BP_REG, __GXData->bpMask);

    __GXData->bpSentNot = GX_FALSE;
}

void __GXFlushTextureState() {
    GX_WRITE_SOME_REG5(GX_LOAD_BP_REG, __GXData->bpMask);

    __GXData->bpSentNot = GX_FALSE;
}
