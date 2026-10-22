// Imported from doldecomp/ogws (CC0), src/revolution/GX/GXDraw.c: GXDrawCylinder and GXDrawSphere.
// The other functions are written from the binary.
#include <math.h>
#include <revolution/gx.h>

// ogws uses a single-precision pi here
#undef M_PI
#define M_PI 3.141592653589793f

// +1 for null terminator
static GXVtxDescList vcd[GX_VA_MAX_ATTR + 1];
static GXVtxAttrFmtList vat[GX_VA_MAX_ATTR + 1];

// Saves the vertex format 3 state and sets it up for f32 positions and normals
static inline void SaveVtxState(void) {
    GXGetVtxDescv(vcd);
    GXGetVtxAttrFmtv(GX_VTXFMT3, vat);

    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
}

static inline void RestoreVtxState(void) {
    GXSetVtxDescv(vcd);
    GXSetVtxAttrFmtv(GX_VTXFMT3, vat);
}

static inline void VecNormalize(f32 v[3]) {
    f32 len = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);

    v[0] /= len;
    v[1] /= len;
    v[2] /= len;
}

static inline void VecSub(const f32 a[3], const f32 b[3], f32 out[3]) {
    u32 i;

    for (i = 0; i < 3; i++) {
        out[i] = b[i] - a[i];
    }
}

static inline void VecCross(const f32 a[3], const f32 b[3], f32 out[3]) {
    f32 tmp[3];

    tmp[0] = a[1] * b[2] - a[2] * b[1];
    tmp[1] = a[2] * b[0] - a[0] * b[2];
    tmp[2] = a[0] * b[1] - a[1] * b[0];

    out[0] = tmp[0];
    out[1] = tmp[1];
    out[2] = tmp[2];
}

static inline void SendVertex(f32 pos[3], f32 nrm[3]) {
    GXPosition3f32(pos[0], pos[1], pos[2]);
    GXNormal3f32(nrm[0], nrm[1], nrm[2]);
}

static inline void DrawSphereTriangle(f32 v0[3], f32 v1[3], f32 v2[3]) {
    GXBegin(GX_TRIANGLES, GX_VTXFMT3, 3);
    SendVertex(v0, v0);
    SendVertex(v1, v1);
    SendVertex(v2, v2);
    GXEnd();
}

// Draws a triangle of the unit sphere split depth times, each vertex being its own normal
void Subdivide(u8 depth, f32 v0[3], f32 v1[3], f32 v2[3]) {
    f32 m01[3];
    f32 m12[3];
    f32 m20[3];
    u32 i;

    if (depth == 0) {
        DrawSphereTriangle(v0, v1, v2);
        return;
    }

    for (i = 0; i < 3; i++) {
        m01[i] = v0[i] + v1[i];
        m12[i] = v1[i] + v2[i];
        m20[i] = v2[i] + v0[i];
    }

    VecNormalize(m01);
    VecNormalize(m12);
    VecNormalize(m20);

    Subdivide(depth - 1, v0, m01, m20);
    Subdivide(depth - 1, v1, m12, m01);
    Subdivide(depth - 1, v2, m20, m12);
    Subdivide(depth - 1, m01, m12, m20);
}

void GXDrawCylinder(u8 sides) {
    // Unit-circle vertices
    f32 vx[100];
    f32 vy[100];

    f32 z, zn;
    f32 sectorAngle;
    s32 i;

    // Radius in both directions
    z = 1.0f;
    zn = -z;

    // Backup VAT/VCD
    GXGetVtxDescv(vcd);
    GXGetVtxAttrFmtv(GX_VTXFMT3, vat);

    // Set custom VAT/VCD
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);

    // Calculate vertices
    for (i = 0; i <= sides; i++) {
        sectorAngle = 2.0f * i * M_PI / sides;
        vx[i] = cosf(sectorAngle);
        vy[i] = sinf(sectorAngle);
    }

    GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT3, (sides + 1) * 2);
    {
        for (i = 0; i <= sides; i++) {
            GXPosition3f32(vx[i], vy[i], zn);
            GXPosition3f32(vx[i], vy[i], 0.0f);
            GXPosition3f32(vx[i], vy[i], z);
            GXPosition3f32(vx[i], vy[i], 0.0f);
        }
    }
    GXEnd();

    GXBegin(GX_TRIANGLEFAN, GX_VTXFMT3, sides + 2);
    {
        GXPosition3f32(0.0f, 0.0f, z);
        GXPosition3f32(0.0f, 0.0f, 1.0f);

        for (i = 0; i <= sides; i++) {
            GXPosition3f32(vx[i], -vy[i], z);
            GXPosition3f32(0.0f, 0.0f, 1.0f);
        }
    }
    GXEnd();

    GXBegin(GX_TRIANGLEFAN, GX_VTXFMT3, sides + 2);
    {
        GXPosition3f32(0.0f, 0.0f, zn);
        GXPosition3f32(0.0f, 0.0f, -1.0f);

        for (i = 0; i <= sides; i++) {
            GXPosition3f32(vx[i], vy[i], zn);
            GXPosition3f32(0.0f, 0.0f, -1.0f);
        }
    }
    GXEnd();

    // Restore old VAT/VCD
    GXSetVtxDescv(vcd);
    GXSetVtxAttrFmtv(GX_VTXFMT3, vat);
}

void GXDrawTorus(f32 rc, u8 numc, u8 numt) {
    GXAttrType tex0;
    s32 i, j, k;
    f32 s, t;
    f32 x, y, z;
    f32 twopi = 2.0f * M_PI;
    f32 rt;

    rt = 1.0f - rc;

    GXGetVtxDesc(GX_VA_TEX0, &tex0);
    SaveVtxState();

    if (tex0 != GX_NONE) {
        GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
        GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    }

    for (i = 0; i < numc; i++) {
        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT3, (numt + 1) * 2);

        for (j = 0; j <= numt; j++) {
            for (k = 1; k >= 0; k--) {
                s = (i + k) % numc;
                t = j % numt;

                x = (rt - rc * cosf(s * twopi / numc)) * cosf(t * twopi / numt);
                y = (rt - rc * cosf(s * twopi / numc)) * sinf(t * twopi / numt);
                z = rc * sinf(s * twopi / numc);
                GXPosition3f32(x, y, z);

                x = -cosf(t * twopi / numt) * cosf(s * twopi / numc);
                y = -sinf(t * twopi / numt) * cosf(s * twopi / numc);
                z = sinf(s * twopi / numc);
                GXNormal3f32(x, y, z);

                if (tex0 != GX_NONE) {
                    GXTexCoord2f32((i + k) / (f32)numc, j / (f32)numt);
                }
            }
        }

        GXEnd();
    }

    RestoreVtxState();
}

void GXDrawSphere(u32 stacks, u32 sectors) {
    GXAttrType tex0, tex0_copy;
    f32 radius;
    f32 stackStep, sectorStep;
    f32 stackAngle, stackAngleNext;
    f32 now_xy, next_xy;
    f32 now_z, next_z;
    f32 sectorAngle;
    f32 cosv, sinv;
    int i, j;

    stackStep = M_PI / stacks;
    sectorStep = 2 * M_PI / sectors;
    radius = 1.0f;

    // Check texcoord attributes
    GXGetVtxDesc(GX_VA_TEX0, &tex0);

    // Backup VAT/VCD
    GXGetVtxDescv(vcd);
    GXGetVtxAttrFmtv(GX_VTXFMT3, vat);

    // Set custom VAT/VCD
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_NRM, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);

    // Setup texcoord VAT/VCD if enabled
    if (tex0 != GX_NONE) {
        GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
        GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    }

    for (i = 0; i < (int)stacks; i++) {
        stackAngle = i * stackStep;
        stackAngleNext = stackAngle + stackStep;

        now_xy = radius * sinf(stackAngle);
        next_xy = radius * sinf(stackAngleNext);
        now_z = radius * cosf(stackAngle);
        next_z = radius * cosf(stackAngleNext);

        GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT3, (sectors + 1) * 2);
        {
            tex0_copy = tex0;

            for (j = 0; j <= (int)sectors; j++) {
                sectorAngle = j * sectorStep;
                cosv = cosf(sectorAngle);
                sinv = sinf(sectorAngle);

                // Vertex 2 position
                GXPosition3f32(cosv * next_xy, sinv * next_xy, next_z);
                // Vertex 2 normal
                GXPosition3f32(cosv * next_xy / radius, sinv * next_xy / radius, next_z / radius);

                // Vertex 2 texcoord (S,T)
                if (tex0_copy != GX_NONE) {
                    GXTexCoord2f32((f32)j / sectors, (f32)(i + 1) / stacks);
                }

                // Vertex 1 position
                GXPosition3f32(cosv * now_xy, sinv * now_xy, now_z);
                // Vertex 1 normal
                GXPosition3f32(cosv * now_xy / radius, sinv * now_xy / radius, now_z / radius);

                // Vertex 1 texcoord (S,T)
                if (tex0_copy != GX_NONE) {
                    GXTexCoord2f32((f32)j / sectors, (f32)i / stacks);
                }
            }
        }
        GXEnd();
    }

    // Restore old VAT/VCD
    GXSetVtxDescv(vcd);
    GXSetVtxAttrFmtv(GX_VTXFMT3, vat);
}

// One face of the cube: n is its normal, t and b its tangent and binormal
void GXDrawCubeFace(f32 nx, f32 ny, f32 nz, f32 tx, f32 ty, f32 tz, f32 bx, f32 by, f32 bz, GXAttrType nbt, GXAttrType tex0) {
    // 1 / sqrt(3): the cube's corners are on the unit sphere
    GXPosition3f32(0.57735026f * (nx + tx + bx), 0.57735026f * (ny + ty + by), 0.57735026f * (nz + tz + bz));
    GXNormal3f32(nx, ny, nz);
    if (nbt != GX_NONE) {
        GXNormal3f32(tx, ty, tz);
        GXNormal3f32(bx, by, bz);
    }
    if (tex0 != GX_NONE) {
        GXTexCoord2s8(1, 1);
    }

    GXPosition3f32(0.57735026f * (nx - tx + bx), 0.57735026f * (ny - ty + by), 0.57735026f * (nz - tz + bz));
    GXNormal3f32(nx, ny, nz);
    if (nbt != GX_NONE) {
        GXNormal3f32(tx, ty, tz);
        GXNormal3f32(bx, by, bz);
    }
    if (tex0 != GX_NONE) {
        GXTexCoord2s8(0, 1);
    }

    GXPosition3f32(0.57735026f * (nx - tx - bx), 0.57735026f * (ny - ty - by), 0.57735026f * (nz - tz - bz));
    GXNormal3f32(nx, ny, nz);
    if (nbt != GX_NONE) {
        GXNormal3f32(tx, ty, tz);
        GXNormal3f32(bx, by, bz);
    }
    if (tex0 != GX_NONE) {
        GXTexCoord2s8(0, 0);
    }

    GXPosition3f32(0.57735026f * (nx + tx - bx), 0.57735026f * (ny + ty - by), 0.57735026f * (nz + tz - bz));
    GXNormal3f32(nx, ny, nz);
    if (nbt != GX_NONE) {
        GXNormal3f32(tx, ty, tz);
        GXNormal3f32(bx, by, bz);
    }
    if (tex0 != GX_NONE) {
        GXTexCoord2s8(1, 0);
    }
}

void GXDrawCube(void) {
    GXAttrType nbt;
    GXAttrType tex0;

    GXGetVtxDesc(GX_VA_NBT, &nbt);
    GXGetVtxDesc(GX_VA_TEX0, &tex0);
    SaveVtxState();

    if (nbt != GX_NONE) {
        GXSetVtxDesc(GX_VA_NBT, GX_DIRECT);
        GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_NBT, GX_NRM_NBT, GX_F32, 0);
    }

    if (tex0 != GX_NONE) {
        GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
        GXSetVtxAttrFmt(GX_VTXFMT3, GX_VA_TEX0, GX_TEX_ST, GX_S8, 0);
    }

    GXBegin(GX_QUADS, GX_VTXFMT3, 24);
    GXDrawCubeFace(-1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, nbt, tex0);
    GXDrawCubeFace(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, nbt, tex0);
    GXDrawCubeFace(0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, nbt, tex0);
    GXDrawCubeFace(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, nbt, tex0);
    GXDrawCubeFace(0.0f, 0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, nbt, tex0);
    GXDrawCubeFace(0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, nbt, tex0);
    GXEnd();

    RestoreVtxState();
}

// Pentagons of the dodecahedron, as indices into sDodecaVerts
static u32 sDodecaFaces[12][5] = {
    {0, 12, 10, 11, 16}, {1, 17, 8, 9, 13}, {2, 14, 9, 8, 18},  {3, 19, 11, 10, 15}, {4, 14, 2, 3, 15},  {5, 12, 0, 1, 13},
    {6, 17, 1, 0, 16},   {7, 19, 3, 2, 18}, {8, 17, 6, 7, 18},  {9, 14, 4, 5, 13},   {10, 12, 5, 4, 15}, {11, 19, 7, 6, 16},
};

static f32 sDodecaVerts[20][3] = {
    {-0.809015f, 0.0f, 0.309015f},  {-0.809015f, 0.0f, -0.309015f}, {0.809015f, 0.0f, -0.309015f},  {0.809015f, 0.0f, 0.309015f},
    {0.309015f, -0.809015f, 0.0f},  {-0.309015f, -0.809015f, 0.0f}, {-0.309015f, 0.809015f, 0.0f},  {0.309015f, 0.809015f, 0.0f},
    {0.0f, 0.309015f, -0.809015f},  {0.0f, -0.309015f, -0.809015f}, {0.0f, -0.309015f, 0.809015f},  {0.0f, 0.309015f, 0.809015f},
    {-0.5f, -0.5f, 0.5f},           {-0.5f, -0.5f, -0.5f},          {0.5f, -0.5f, -0.5f},           {0.5f, -0.5f, 0.5f},
    {-0.5f, 0.5f, 0.5f},            {-0.5f, 0.5f, -0.5f},           {0.5f, 0.5f, -0.5f},            {0.5f, 0.5f, 0.5f},
};

void GXDrawDodeca(void) {
    u32 i;
    f32* a;
    f32* b;
    f32* c;
    f32 u[3];
    f32 v[3];
    f32 n[3];

    SaveVtxState();

    for (i = 0; i < 12; i++) {
        a = sDodecaVerts[sDodecaFaces[i][0]];
        b = sDodecaVerts[sDodecaFaces[i][1]];
        c = sDodecaVerts[sDodecaFaces[i][2]];

        VecSub(b, c, u);
        VecSub(b, a, v);
        VecCross(u, v, n);
        VecNormalize(n);

        GXBegin(GX_TRIANGLEFAN, GX_VTXFMT3, 5);
        SendVertex(sDodecaVerts[sDodecaFaces[i][4]], n);
        SendVertex(sDodecaVerts[sDodecaFaces[i][3]], n);
        SendVertex(c, n);
        SendVertex(b, n);
        SendVertex(a, n);
        GXEnd();
    }

    RestoreVtxState();
}

static f32 sOctaVerts[6][3] = {
    {1.0f, 0.0f, 0.0f}, {-1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, -1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, -1.0f},
};

static u8 sOctaFaces[8][3] = {
    {0, 4, 2}, {1, 2, 4}, {0, 3, 4}, {1, 4, 3}, {0, 2, 5}, {1, 5, 2}, {0, 5, 3}, {1, 3, 5},
};

static inline void DrawFace(u8 depth, u8 face, f32 (*verts)[3], u8 (*faces)[3]) {
    Subdivide(depth, verts[faces[face][0]], verts[faces[face][1]], verts[faces[face][2]]);
}

void GXDrawOctahedron(void) {
    s32 i;

    SaveVtxState();

    for (i = 7; i >= 0; i--) {
        DrawFace(0, i, sOctaVerts, sOctaFaces);
    }

    RestoreVtxState();
}

static f32 sIcosaVerts[12][3] = {
    {-0.5257311f, 0.0f, 0.8506508f}, {0.5257311f, 0.0f, 0.8506508f},  {-0.5257311f, 0.0f, -0.8506508f}, {0.5257311f, 0.0f, -0.8506508f},
    {0.0f, 0.8506508f, 0.5257311f},  {0.0f, 0.8506508f, -0.5257311f}, {0.0f, -0.8506508f, 0.5257311f},  {0.0f, -0.8506508f, -0.5257311f},
    {0.8506508f, 0.5257311f, 0.0f},  {-0.8506508f, 0.5257311f, 0.0f}, {0.8506508f, -0.5257311f, 0.0f},  {-0.8506508f, -0.5257311f, 0.0f},
};

static u8 sIcosaFaces[20][3] = {
    {0, 4, 1},  {0, 9, 4},  {9, 5, 4},  {4, 5, 8},  {4, 8, 1},  {8, 10, 1}, {8, 3, 10}, {5, 3, 8},  {5, 2, 3},  {2, 7, 3},
    {7, 10, 3}, {7, 6, 10}, {7, 11, 6}, {11, 0, 6}, {0, 1, 6},  {6, 1, 10}, {9, 0, 11}, {9, 11, 2}, {9, 2, 5},  {7, 2, 11},
};

void GXDrawIcosahedron(void) {
    s32 i;

    SaveVtxState();

    for (i = 19; i >= 0; i--) {
        DrawFace(0, i, sIcosaVerts, sIcosaFaces);
    }

    RestoreVtxState();
}

void GXDrawSphere1(u8 depth) {
    s32 i;

    SaveVtxState();

    for (i = 19; i >= 0; i--) {
        DrawFace(depth, i, sIcosaVerts, sIcosaFaces);
    }

    RestoreVtxState();
}
