// Imported from koopthekoopa/wii-ipl (CC0), libs/RVL_SDK/src/mtx/vec.c
#include <math.h>
#include <revolution/mtx.h>
#include <revolution/os.h>

// clang-format off

void C_VECNormalize(const Vec* src, Vec* unit) {
    f32 mag;

    mag = (src->z * src->z) + ((src->x * src->x) + (src->y * src->y));

    mag = 1.0f/ sqrtf(mag);
    unit->x = src->x * mag;
    unit->y = src->y * mag;
    unit->z = src->z * mag;
}

void PSVECNormalize(const register Vec* src, register Vec* unit) {
    register float c_half = 0.5f;
    register float c_three = 3.0f;
    register float v1_xy;
    register float v1_z;
    register float xx_zz;
    register float xx_yy;
    register float sqsum;
    register float rsqrt;
    register float nwork0;
    register float nwork1;

    asm {
        psq_l v1_xy, 0x0(src), 0, 0
        ps_mul xx_yy, v1_xy, v1_xy
        psq_l v1_z, 0x8(src), 1, 0
        ps_madd xx_zz, v1_z, v1_z, xx_yy
        ps_sum0 sqsum, xx_zz, v1_z, xx_yy
        frsqrte rsqrt, sqsum
        fmuls nwork0, rsqrt, rsqrt
        fmuls nwork1, rsqrt, c_half
        fnmsubs nwork0, nwork0, sqsum, c_three
        fmuls rsqrt, nwork0, nwork1
        ps_muls0 v1_xy, v1_xy, rsqrt
        psq_st v1_xy, 0x0(unit), 0, 0
        ps_muls0 v1_z, v1_z, rsqrt
        psq_st v1_z, 0x8(unit), 1, 0
    }
}

void C_VECCrossProduct(const Vec* a, const Vec* b, Vec* axb) {
    Vec vTmp;

    vTmp.x = (a->y * b->z) - (a->z * b->y);
    vTmp.y = (a->z * b->x) - (a->x * b->z);
    vTmp.z = (a->x * b->y) - (a->y * b->x);
    axb->x = vTmp.x;
    axb->y = vTmp.y;
    axb->z = vTmp.z;
}

asm void PSVECCrossProduct(const register Vec* a, const register Vec* b, register Vec* axb) {
    psq_l f1, Vec.x(b), 0, 0
    lfs f2, Vec.z(a)
    psq_l f0, Vec.x(a), 0, 0
    ps_merge10 f6, f1, f1
    lfs f3, Vec.z(b)
    ps_mul f4, f1, f2
    ps_muls0 f7, f1, f0
    ps_msub f5, f0, f3, f4
    ps_msub f8, f0, f6, f7
    ps_merge11 f9, f5, f5
    ps_merge01 f10, f5, f8
    psq_st f9, Vec.x(axb), 1, 0
    ps_neg f10, f10
    psq_st f10, Vec.y(axb), 0, 0
}

// clang-format on

asm f32 PSVECDotProduct(const __REGISTER Vec* a, const __REGISTER Vec* b) {
    psq_l f2, Vec.y(a), 0, 0
    psq_l f3, Vec.y(b), 0, 0
    ps_mul f2, f2, f3
    psq_l f5, Vec.x(a), 0, 0
    psq_l f4, Vec.x(b), 0, 0
    ps_madd f3, f5, f4, f2
    ps_sum0 f1, f3, f2, f2
}

f32 PSVECMag(const __REGISTER Vec* v) {
    __REGISTER f32 vxy, vzz;
    __REGISTER f32 sqmag, rmag;
    __REGISTER f32 nwork0, nwork1;
    __REGISTER f32 c_three, c_half, c_zero;

    c_half = 0.5f;

    asm {
        psq_l vxy, 0x0(v), 0, 0
        ps_mul vxy, vxy, vxy
        lfs vzz, 0x8(v)
        fsubs c_zero, c_half, c_half
        ps_madd sqmag, vzz, vzz, vxy
        ps_sum0 sqmag, sqmag, vxy, vxy
        fcmpu cr0, sqmag, c_zero
        beq L_000005F0
        frsqrte rmag, sqmag
    }

    c_three = 3.0f;

    asm {
        fmuls nwork0, rmag, rmag
        fmuls nwork1, rmag, c_half
        fnmsubs nwork0, nwork0, sqmag, c_three
        fmuls rmag, nwork0, nwork1
        fmuls sqmag, sqmag, rmag
    L_000005F0:
    }

    return sqmag;
}

f32 PSVECDistance(const __REGISTER Vec* a, const __REGISTER Vec* b) {
    __REGISTER f32 v0yz, v1yz, v0xy, v1xy, dyz, dxy;
    __REGISTER f32 sqdist, rdist;
    __REGISTER f32 nwork0, nwork1;
    __REGISTER f32 c_half, c_three, c_zero;

    asm {
        psq_l v0yz, 0x4(a), 0, 0
        psq_l v1yz, 0x4(b), 0, 0
        ps_sub dyz, v0yz, v1yz
        psq_l v0xy, 0x0(a), 0, 0
        psq_l v1xy, 0x0(b), 0, 0
        ps_mul dyz, dyz, dyz
        ps_sub dxy, v0xy, v1xy
    }

    c_half  = 0.5f;

    asm {
        ps_madd sqdist, dxy, dxy, dyz
        fsubs c_zero, c_half, c_half
        ps_sum0 sqdist, sqdist, dyz, dyz
        fcmpu cr0, c_zero, sqdist
        beq L_00000CBC
    }

    c_three = 3.0f;

    asm {
        frsqrte rdist, sqdist
        fmuls nwork0, rdist, rdist
        fmuls nwork1, rdist, c_half
        fnmsubs nwork0, nwork0, sqdist, c_three
        fmuls rdist, nwork0, nwork1
        fmuls sqdist, sqdist, rdist
    L_00000CBC:
    }

    return sqdist;
}

void C_VECHalfAngle(const Vec* a, const Vec* b, Vec* half) {
    Vec aTmp;
    Vec bTmp;
    Vec hTmp;

    ASSERTMSGLINE(713, a, "VECHalfAngle():  NULL VecPtr 'a' ");
    ASSERTMSGLINE(714, b, "VECHalfAngle():  NULL VecPtr 'b' ");
    ASSERTMSGLINE(715, half, "VECHalfAngle():  NULL VecPtr 'half' ");

    aTmp.x = -a->x;
    aTmp.y = -a->y;
    aTmp.z = -a->z;
    bTmp.x = -b->x;
    bTmp.y = -b->y;
    bTmp.z = -b->z;

    VECNormalize(&aTmp, &aTmp);
    VECNormalize(&bTmp, &bTmp);
    VECAdd(&aTmp, &bTmp, &hTmp);

    if (VECDotProduct(&hTmp, &hTmp) > 0.0f) {
        VECNormalize(&hTmp, half);
        return;
    }
    *half = hTmp;
}

void C_VECReflect(const Vec* src, const Vec* normal, Vec* dst) {
    f32 cosA;
    Vec uI;
    Vec uN;

    ASSERTMSGLINE(769, src, "VECReflect():  NULL VecPtr 'src' ");
    ASSERTMSGLINE(770, normal, "VECReflect():  NULL VecPtr 'normal' ");
    ASSERTMSGLINE(771, dst, "VECReflect():  NULL VecPtr 'dst' ");

    uI.x = -src->x;
    uI.y = -src->y;
    uI.z = -src->z;

    VECNormalize(&uI, &uI);
    VECNormalize(normal, &uN);

    cosA = VECDotProduct(&uI, &uN);
    dst->x = (2.0f * uN.x * cosA) - uI.x;
    dst->y = (2.0f * uN.y * cosA) - uI.y;
    dst->z = (2.0f * uN.z * cosA) - uI.z;
    VECNormalize(dst, dst);
}

f32 PSVECSquareMag(const __REGISTER Vec* v) {
    __REGISTER f32 vxy, vzz, sqmag;

    asm {
        psq_l vxy, 0x0(v), 0, 0
        ps_mul vxy, vxy, vxy
        lfs vzz, 0x8(v)
        ps_madd sqmag, vzz, vzz, vxy
        ps_sum0 sqmag, sqmag, vxy, vxy
    }

    return sqmag;
}
