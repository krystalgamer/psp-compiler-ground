/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK I3dHierarchy__GetIndexByName(int);          /* extern */

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/bin_common", I3dHierarchy__GetIndexByName);

int I3dIsActiveTypeId(int id) {
    if (id == 0x4 || id == 0x16 || id == 0x24 || id == 0x2C || id == 0x2E || id == 0x2F || id == 0x36 || id == 0x3F || id == 0x40 || id == 0x41 || id == 0x48 || id == 0x4E || id == 0x51) return 0;
    return 1;
}


void ErrorEntity__Pack(void) {
}

void ErrorEntity__Unpack(void) {
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/bin_common", I3dHierarchy__RecursivePack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/bin_common", I3dHierarchy__RecursiveUnpack);

void I3dCommonArrayEntity__Pack(void) {
}

void I3dCommonArrayEntity__Unpack(void) {
}

void I3dCommonHashEntity__Pack(void) {
}

void I3dCommonHashEntity__Unpack(void) {
}

void I3rLoopControlEntity__Pack(void) {
}

void I3rLoopControlEntity__Unpack(void) {
}

void I3rArrayKeyFrameVector4Entity__Pack(int *p)
{
    if (p[8] != 0)
        p[8] = p[8] - (int)p;
    if (p[9] != 0)
        p[9] = p[9] - (int)p;
    if (p[10] != 0)
        p[10] = p[10] - (int)p;
}

void I3rArrayKeyFrameVector4Entity__Unpack(int *p)
{
    if (p[8] != 0)
        p[8] = p[8] + (int)p;
    if (p[9] != 0)
        p[9] = p[9] + (int)p;
    if (p[10] != 0)
        p[10] = p[10] + (int)p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rArrayKeyFrameVector4__GetLoopControl(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rArrayKeyFrameVector4__IsExistLoopControl(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

void I3rArrayAnimVector4Entity__Pack(int *p)
{
    if (*p != 0)
        *p = *p - (int)p;
}

void I3rArrayAnimVector4Entity__Unpack(int *p)
{
    if (*p != 0)
        *p = *p + (int)p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rArrayAnimVector4__GetArrayKeyFrameSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rArrayAnimVector4__GetArrayKeyFrameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rArrayAnimVector4__GetBeginArrayKeyFrame(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rArrayAnimVector4__GetEndArrayKeyFrame(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

void I3rObbEntity__Pack(void) {
}

void I3rObbEntity__Unpack(void) {
}

void I3rPrimitiveEntity__Pack_PSP(int *p)
{
    if (p[2] != 0)
        p[2] = p[2] - (int)p;
    if (p[4] != 0)
        p[4] = p[4] - (int)p;
    if (p[6] != 0)
        p[6] = p[6] - (int)p;
}

void I3rPrimitiveEntity__Unpack_PSP(int *p)
{
    if (p[2] != 0)
        p[2] = p[2] + (int)p;
    if (p[4] != 0)
        p[4] = p[4] + (int)p;
    if (p[6] != 0)
        p[6] = p[6] + (int)p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rPrimitive__GetColors(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rPrimitive__IsExistColors(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rPrimitive__GetNormals(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rPrimitive__IsExistNormals(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rPrimitive__GetPositions(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x20;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rPrimitive__IsExistPositions(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x20) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rPrimitive__GetStqs(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x30;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rPrimitive__IsExistStqs(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x30) != 0;
}

void I3rStripEntity__Pack_PS2(int *p)
{
    if (*p != 0)
        *p = *p - (int)p;
}

void I3rStripEntity__Unpack_PS2(int *p)
{
    if (*p != 0)
        *p = *p + (int)p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rStrip__GetColorsSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rStrip__GetColorsByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3rStrip__GetColorsIndexByName(void *arg0) {
    I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8));
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rStrip__GetColorsNameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 0x10) + M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8)), int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rStrip__GetColorsByName(void *arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_s0, int *, 8) + (I3dHierarchy__GetIndexByName(temp_s0) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rStrip__IsExistColors(void *arg0) {
    return ~I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8)) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rStrip__GetBeginColors(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rStrip__GetEndColors(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rStrip__GetStqsSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x14), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rStrip__GetStqsByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3rStrip__GetStqsIndexByName(void *arg0) {
    I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rStrip__GetStqsNameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 0x10) + M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18)), int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rStrip__GetStqsByName(void *arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, int *, 8) + 0x10;
    return M2C_FIELD(temp_s0, int *, 8) + (I3dHierarchy__GetIndexByName(temp_s0) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rStrip__IsExistStqs(void *arg0) {
    return ~I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x10) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rStrip__GetBeginStqs(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rStrip__GetEndStqs(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0x10;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

void I3rChannelEntity__Pack_PS2(void) {
}

void I3rChannelEntity__Unpack_PS2(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rChannel__GetStripSize_PS2(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rChannel__GetStripByIndex_PS2(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rChannel__GetBeginStrip_PS2(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rChannel__GetEndStrip_PS2(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

void I3rChannelEntity__Pack_PSP(void) {
}

void I3rChannelEntity__Unpack_PSP(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rChannel__GetPrimitiveSize_PSP(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rChannel__GetPrimitiveByIndex_PSP(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rChannel__GetBeginPrimitive_PSP(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rChannel__GetEndPrimitive_PSP(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

void I3rWeightInfoEntity__Pack_PS2(int *p)
{
    if (*p != 0)
        *p = *p - (int)p;
}

void I3rWeightInfoEntity__Unpack_PS2(int *p)
{
    if (*p != 0)
        *p = *p + (int)p;
}

void I3rClusterEntity__Pack_PS2(int *p)
{
    if (*p != 0)
        *p = *p - (int)p;
}

void I3rClusterEntity__Unpack_PS2(int *p)
{
    if (*p != 0)
        *p = *p + (int)p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetChannelSize_PS2(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetChannelByIndex_PS2(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetBeginChannel_PS2(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetEndChannel_PS2(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetIlluminationsSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x14), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetIlluminationsByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3rCluster__GetIlluminationsIndexByName(void *arg0) {
    I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetIlluminationsNameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 0x10) + M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18)), int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rCluster__GetIlluminationsByName(void *arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, int *, 8) + 0x10;
    return M2C_FIELD(temp_s0, int *, 8) + (I3dHierarchy__GetIndexByName(temp_s0) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rCluster__IsExistIlluminations(void *arg0) {
    return ~I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x10) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetBeginIlluminations(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetEndIlluminations(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0x10;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetNormalsSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x24), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetNormalsByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x28) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3rCluster__GetNormalsIndexByName(void *arg0) {
    I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetNormalsNameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 0x10) + M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x28)), int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rCluster__GetNormalsByName(void *arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, int *, 8) + 0x20;
    return M2C_FIELD(temp_s0, int *, 8) + (I3dHierarchy__GetIndexByName(temp_s0) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rCluster__IsExistNormals(void *arg0) {
    return ~I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x20) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetBeginNormals(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x28);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetEndNormals(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0x20;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetObb(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x30;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__IsExistObb(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x30) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetPositionsSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x44), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetPositionsByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x48) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3rCluster__GetPositionsIndexByName(void *arg0) {
    I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x40);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetPositionsNameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 0x10) + M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x48)), int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rCluster__GetPositionsByName(void *arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, int *, 8) + 0x40;
    return M2C_FIELD(temp_s0, int *, 8) + (I3dHierarchy__GetIndexByName(temp_s0) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rCluster__IsExistPositions(void *arg0) {
    return ~I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x40) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetBeginPositions(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x48);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetEndPositions(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0x40;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetWeightInfoSize_PS2(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x54), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetWeightInfoByIndex_PS2(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x58) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetBeginWeightInfo_PS2(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x58);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetEndWeightInfo_PS2(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0x50;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

void I3rClusterEntity__Pack_PSP(int *p)
{
    if (*p != 0)
        *p = *p - (int)p;
}

void I3rClusterEntity__Unpack_PSP(int *p)
{
    if (*p != 0)
        *p = *p + (int)p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetChannelSize_PSP(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetChannelByIndex_PSP(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetBeginChannel_PSP(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetEndChannel_PSP(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__GetObb_PSP(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rCluster__IsExistObb_PSP(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

void I3rAnimVector4Entity__Pack(void) {
}

void I3rAnimVector4Entity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rAnimVector4__GetArrayKeyFrame(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rAnimVector4__IsExistArrayKeyFrame(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

typedef struct { int a; int arr; int c; unsigned char pad[2]; unsigned char n; } I3rMogEnt;
void I3rMaterialOperationGroupEntity__Pack(I3rMogEnt *m)
{
    unsigned int i, n;

    n = m->n;
    for (i = 0; i < n; i++)
    {
        int *q = (int *)m->arr + i;
        if (*q != 0)
            *q = *q - (int)m;
    }
    if (m->a != 0)
        m->a = m->a - (int)m;
    if (m->arr != 0)
        m->arr = m->arr - (int)m;
    if (m->c != 0)
        m->c = m->c - (int)m;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/bin_common", I3rMaterialOperationGroupEntity__Unpack);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMaterialOperationGroup__GetClusterSize_PS2(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMaterialOperationGroup__GetClusterByIndex_PS2(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMaterialOperationGroup__GetBeginCluster_PS2(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMaterialOperationGroup__GetEndCluster_PS2(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMaterialOperationGroup__GetClusterSize_PSP(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x14), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMaterialOperationGroup__GetClusterByIndex_PSP(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMaterialOperationGroup__GetBeginCluster_PSP(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMaterialOperationGroup__GetEndCluster_PSP(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0x10;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMaterialOperationGroup__GetObb(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x20;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMaterialOperationGroup__IsExistObb(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x20) != 0;
}

void I3rArrayKeyFrameFloatEntity__Pack(int *p)
{
    if (p[2] != 0)
        p[2] = p[2] - (int)p;
    if (p[3] != 0)
        p[3] = p[3] - (int)p;
    if (p[4] != 0)
        p[4] = p[4] - (int)p;
}

void I3rArrayKeyFrameFloatEntity__Unpack(int *p)
{
    if (p[2] != 0)
        p[2] = p[2] + (int)p;
    if (p[3] != 0)
        p[3] = p[3] + (int)p;
    if (p[4] != 0)
        p[4] = p[4] + (int)p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rArrayKeyFrameFloat__GetLoopControl(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rArrayKeyFrameFloat__IsExistLoopControl(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

void I3rLayerDependPS2Entity__Pack(int *p)
{
    if (*p != 0)
        *p = *p - (int)p;
}

void I3rLayerDependPS2Entity__Unpack(int *p)
{
    if (*p != 0)
        *p = *p + (int)p;
}

void I3rAdjustColorEntity__Pack(void) {
}

void I3rAdjustColorEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rAdjustColor__GetAdd(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rAdjustColor__IsExistAdd(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rAdjustColor__GetMul(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rAdjustColor__IsExistMul(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

void I3rAdjustStqEntity__Pack(void) {
}

void I3rAdjustStqEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rAdjustStq__GetOffset(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rAdjustStq__IsExistOffset(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rAdjustStq__GetRepeat(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rAdjustStq__IsExistRepeat(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rAdjustStq__GetRotate(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x20;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rAdjustStq__IsExistRotate(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x20) != 0;
}

void I3rAnimFloatEntity__Pack(void) {
}

void I3rAnimFloatEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rAnimFloat__GetArrayKeyFrame(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rAnimFloat__IsExistArrayKeyFrame(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

void I3rLayerDependPlatformEntity__Pack(void) {
}

void I3rLayerDependPlatformEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rLayerDependPlatform__GetPS2(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rLayerDependPlatform__IsExistPS2(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

void I3rSkinOperationGroupEntity__Pack(int *p)
{
    if (*p != 0)
        *p = *p - (int)p;
}

void I3rSkinOperationGroupEntity__Unpack(int *p)
{
    if (*p != 0)
        *p = *p + (int)p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSkinOperationGroup__GetMaterialOperationGroupSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSkinOperationGroup__GetMaterialOperationGroupByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSkinOperationGroup__GetBeginMaterialOperationGroup(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSkinOperationGroup__GetEndMaterialOperationGroup(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

void I3rSolidOperationGroupEntity__Pack(void) {
}

void I3rSolidOperationGroupEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSolidOperationGroup__GetMaterialOperationGroupSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSolidOperationGroup__GetMaterialOperationGroupByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSolidOperationGroup__GetBeginMaterialOperationGroup(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSolidOperationGroup__GetEndMaterialOperationGroup(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

void I3rStqMapEntity__Pack(void) {
}

void I3rStqMapEntity__Unpack(void) {
}

void I3rDispControlEntity__Pack(void) {
}

void I3rDispControlEntity__Unpack(void) {
}

void I3rLayerEntity__Pack(int *p)
{
    if (p[5] != 0)
        p[5] = p[5] - (int)p;
    if (p[6] != 0)
        p[6] = p[6] - (int)p;
}

void I3rLayerEntity__Unpack(int *p)
{
    if (p[5] != 0)
        p[5] = p[5] + (int)p;
    if (p[6] != 0)
        p[6] = p[6] + (int)p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rLayer__GetAdjustColor(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rLayer__IsExistAdjustColor(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rLayer__GetAdjustStq(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rLayer__IsExistAdjustStq(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rLayer__GetDependPlatform(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x20;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rLayer__IsExistDependPlatform(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x20) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rLayer__GetStqMapSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x34), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rLayer__GetStqMapByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x38) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rLayer__GetBeginStqMap(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x38);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rLayer__GetEndStqMap(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0x30;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

void I3rMeshInstanceEntity__Pack(int *p)
{
    if (*p != 0)
        *p = *p - (int)p;
}

void I3rMeshInstanceEntity__Unpack(int *p)
{
    if (*p != 0)
        *p = *p + (int)p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMeshInstance__GetMorphTargetWeightSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMeshInstance__GetMorphTargetWeightByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMeshInstance__GetBeginMorphTargetWeight(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMeshInstance__GetEndMorphTargetWeight(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/bin_common", I3rSkinGroupEntity__Pack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/bin_common", I3rSkinGroupEntity__Unpack);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSkinGroup__GetSkinOperationGroupSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSkinGroup__GetSkinOperationGroupByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSkinGroup__GetBeginSkinOperationGroup(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSkinGroup__GetEndSkinOperationGroup(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

void I3rSolidGroupEntity__Pack(void) {
}

void I3rSolidGroupEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSolidGroup__GetObb(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSolidGroup__IsExistObb(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSolidGroup__GetSolidOperationGroupSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x14), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSolidGroup__GetSolidOperationGroupByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSolidGroup__GetBeginSolidOperationGroup(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rSolidGroup__GetEndSolidOperationGroup(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0x10;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

void I3rMaterialEntity__Pack(void) {
}

void I3rMaterialEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMaterial__GetLayerSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMaterial__GetLayerByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMaterial__GetBeginLayer(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMaterial__GetEndLayer(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

typedef struct { int arr; unsigned short n; } I3rMeshEnt;
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/bin_common", I3rMeshEntity__Pack);

void I3rMeshEntity__Unpack(I3rMeshEnt *m)
{
    unsigned int i, n;

    if (m->arr != 0)
        m->arr = m->arr + (int)m;
    n = m->n;
    for (i = 0; i < n; i++)
    {
        int *q = (int *)m->arr + i;
        if (*q != 0)
            *q = *q + (int)m;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMesh__GetSkinGroup(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMesh__IsExistSkinGroup(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMesh__GetSolidGroup(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rMesh__IsExistSolidGroup(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

void I3rNodeEntity__Pack(void) {
}

void I3rNodeEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rNode__GetDispControl(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rNode__IsExistDispControl(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rNode__GetMeshInstanceSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x14), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rNode__GetMeshInstanceByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3rNode__GetMeshInstanceIndexByName(void *arg0) {
    I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rNode__GetMeshInstanceNameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 0x10) + M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18)), int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rNode__GetMeshInstanceByName(void *arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, int *, 8) + 0x10;
    return M2C_FIELD(temp_s0, int *, 8) + (I3dHierarchy__GetIndexByName(temp_s0) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rNode__IsExistMeshInstance(void *arg0) {
    return ~I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x10) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rNode__GetBeginMeshInstance(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rNode__GetEndMeshInstance(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0x10;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

void I3rWorkEntity__Pack_PS2(int *p)
{
    if (*p != 0)
        *p = *p - (int)p;
}

void I3rWorkEntity__Unpack_PS2(int *p)
{
    if (*p != 0)
        *p = *p + (int)p;
}

void I3rWorkEntity__Pack_PSP(int *p)
{
    if (*p != 0)
        *p = *p - (int)p;
}

void I3rWorkEntity__Unpack_PSP(int *p)
{
    if (*p != 0)
        *p = *p + (int)p;
}

#define PACK_PTR_(f) { char *p_ = *(char **)(f); if (p_ != NULL) *(char **)(f) = p_ - (int)m; }
void I3rModelEntity__Pack(char *m)
{
	PACK_PTR_(m + 0x10);
	PACK_PTR_(m + 0x14);
	{
	unsigned int i, n = *(unsigned short *)(m + 0x2C);
	for (i = 0; i < n; i++) {
		char **q = *(char ***)(m + 0x18) + i;
		PACK_PTR_(q);
	}
	}
	PACK_PTR_(m + 0x18);
	{
	unsigned int i, n = *(unsigned short *)(m + 0x2E);
	for (i = 0; i < n; i++) {
		char **q = *(char ***)(m + 0x20) + i;
		PACK_PTR_(q);
	}
	}
	PACK_PTR_(m + 0x1C);
	PACK_PTR_(m + 0x20);
}

#define UNPACK_PTR_(f) { char *p_ = *(char **)(f); if (p_ != NULL) *(char **)(f) = p_ + (int)m; }
void I3rModelEntity__Unpack(char *m)
{
	UNPACK_PTR_(m + 0x10);
	UNPACK_PTR_(m + 0x14);
	UNPACK_PTR_(m + 0x18);
	{
	unsigned int i, n = *(unsigned short *)(m + 0x2C);
	for (i = 0; i < n; i++) {
		char **q = *(char ***)(m + 0x18) + i;
		UNPACK_PTR_(q);
	}
	}
	UNPACK_PTR_(m + 0x1C);
	UNPACK_PTR_(m + 0x20);
	{
	unsigned int i, n = *(unsigned short *)(m + 0x2E);
	for (i = 0; i < n; i++) {
		char **q = *(char ***)(m + 0x20) + i;
		UNPACK_PTR_(q);
	}
	}
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetMaterialSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetMaterialByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3rModel__GetMaterialIndexByName(void *arg0) {
    I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8));
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetMaterialNameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 0x10) + M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8)), int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rModel__GetMaterialByName(void *arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_s0, int *, 8) + (I3dHierarchy__GetIndexByName(temp_s0) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rModel__IsExistMaterial(void *arg0) {
    return ~I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8)) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetBeginMaterial(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetEndMaterial(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetMaterialAnimLoopControl(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__IsExistMaterialAnimLoopControl(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetMeshSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x24), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetMeshByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x28) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3rModel__GetMeshIndexByName(void *arg0) {
    I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetMeshNameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 0x10) + M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x28)), int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rModel__GetMeshByName(void *arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, int *, 8) + 0x20;
    return M2C_FIELD(temp_s0, int *, 8) + (I3dHierarchy__GetIndexByName(temp_s0) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3rModel__IsExistMesh(void *arg0) {
    return ~I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x20) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetBeginMesh(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x28);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetEndMesh(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0x20;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetNodeSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x34), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetNodeByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x38) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetBeginNode(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x38);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetEndNode(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0x30;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetObb(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x40;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__IsExistObb(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x40) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetVertexAnimLoopControl(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x50;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__IsExistVertexAnimLoopControl(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x50) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetWork_PS2(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x60;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__IsExistWork_PS2(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x60) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__GetWork_PSP(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x70;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rModel__IsExistWork_PSP(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x70) != 0;
}

void I3sLoopControlEntity__Pack(void) {
}

void I3sLoopControlEntity__Unpack(void) {
}

void I3sKeyFrameVector4Entity__Pack(void) {
}

void I3sKeyFrameVector4Entity__Unpack(void) {
}

void I3sAnimVector4Entity__Pack(void) {
}

void I3sAnimVector4Entity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimVector4__GetKeyFrameSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimVector4__GetKeyFrameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimVector4__GetBeginKeyFrame(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimVector4__GetEndKeyFrame(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimVector4__GetLoopControl(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimVector4__IsExistLoopControl(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

void I3sKeyFrameStringEntity__Pack(int *p)
{
    if (p[1] != 0)
        p[1] = p[1] - (int)p;
}

void I3sKeyFrameStringEntity__Unpack(int *p)
{
    if (p[1] != 0)
        p[1] = p[1] + (int)p;
}

void I3sAnimStringEntity__Pack(int *p)
{
    if (*p != 0)
        *p = *p - (int)p;
}

void I3sAnimStringEntity__Unpack(int *p)
{
    if (*p != 0)
        *p = *p + (int)p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimString__GetKeyFrameSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimString__GetKeyFrameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimString__GetBeginKeyFrame(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimString__GetEndKeyFrame(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimString__GetLoopControl(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimString__IsExistLoopControl(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

void I3sKeyFrameMatrix4x4Entity__Pack(void) {
}

void I3sKeyFrameMatrix4x4Entity__Unpack(void) {
}

void I3sAnimMatrix4x4Entity__Pack(void) {
}

void I3sAnimMatrix4x4Entity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimMatrix4x4__GetKeyFrameSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimMatrix4x4__GetKeyFrameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimMatrix4x4__GetBeginKeyFrame(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimMatrix4x4__GetEndKeyFrame(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimMatrix4x4__GetLoopControl(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimMatrix4x4__IsExistLoopControl(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

void I3sGsParamEntity__Pack(void) {
}

void I3sGsParamEntity__Unpack(void) {
}

typedef struct { int p; int arr; unsigned int n; } I3sArrEnt;
void I3sCornerEntity__Pack(I3sArrEnt *m)
{
    unsigned int i, n;

    n = m->n;
    for (i = 0; i < n; i++)
    {
        int *q = (int *)m->arr + i;
        if (*q != 0)
            *q = *q - (int)m;
    }
    if (m->p != 0)
        m->p = m->p - (int)m;
    if (m->arr != 0)
        m->arr = m->arr - (int)m;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/bin_common", I3sCornerEntity__Unpack);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sCorner__GetColor(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sCorner__IsExistColor(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sCorner__GetIllumination(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sCorner__IsExistIllumination(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sCorner__GetNormal(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x20;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sCorner__IsExistNormal(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x20) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sCorner__GetPosition(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x30;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sCorner__IsExistPosition(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x30) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sCorner__GetStq(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x40;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sCorner__IsExistStq(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x40) != 0;
}

void I3sKeyFrameFlagEntity__Pack(void) {
}

void I3sKeyFrameFlagEntity__Unpack(void) {
}

void I3sLayerDependPS2Entity__Pack(void) {
}

void I3sLayerDependPS2Entity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayerDependPS2__GetGsParamSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayerDependPS2__GetGsParamByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayerDependPS2__GetBeginGsParam(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayerDependPS2__GetEndGsParam(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

void I3sPixelConditionEntity__Pack(void) {
}

void I3sPixelConditionEntity__Unpack(void) {
}

void I3sStqMapOperationEntity__Pack(void) {
}

void I3sStqMapOperationEntity__Unpack(void) {
}

void I3sAdjustColorEntity__Pack(void) {
}

void I3sAdjustColorEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAdjustColor__GetAdd(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAdjustColor__IsExistAdd(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAdjustColor__GetMul(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAdjustColor__IsExistMul(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

void I3sAdjustStqEntity__Pack(void) {
}

void I3sAdjustStqEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAdjustStq__GetOffset(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAdjustStq__IsExistOffset(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAdjustStq__GetRepeat(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAdjustStq__IsExistRepeat(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAdjustStq__GetRotate(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x20;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAdjustStq__IsExistRotate(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x20) != 0;
}

void I3sAmbientEntity__Pack(void) {
}

void I3sAmbientEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAmbient__GetColor(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAmbient__IsExistColor(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

void I3sAnimFlagEntity__Pack(void) {
}

void I3sAnimFlagEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimFlag__GetKeyFrameSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimFlag__GetKeyFrameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimFlag__GetBeginKeyFrame(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimFlag__GetEndKeyFrame(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimFlag__GetLoopControl(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimFlag__IsExistLoopControl(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

void I3sChannelEntity__Pack(void) {
}

void I3sChannelEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sChannel__GetCornerSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sChannel__GetCornerByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sChannel__GetBeginCorner(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sChannel__GetEndCorner(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

void I3sDiffuseEntity__Pack(void) {
}

void I3sDiffuseEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sDiffuse__GetColor(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sDiffuse__IsExistColor(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

void I3sEmissionEntity__Pack(void) {
}

void I3sEmissionEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sEmission__GetColor(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sEmission__IsExistColor(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

void I3sFaceCullingEntity__Pack(void) {
}

void I3sFaceCullingEntity__Unpack(void) {
}

void I3sFogEntity__Pack(void) {
}

void I3sFogEntity__Unpack(void) {
}

void I3sLayerDependPlatformEntity__Pack(void) {
}

void I3sLayerDependPlatformEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayerDependPlatform__GetPS2(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayerDependPlatform__IsExistPS2(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

void I3sPixelBlendEntity__Pack(void) {
}

void I3sPixelBlendEntity__Unpack(void) {
}

void I3sPixelMaskEntity__Pack(void) {
}

void I3sPixelMaskEntity__Unpack(void) {
}

void I3sPixelTestEntity__Pack(void) {
}

void I3sPixelTestEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sPixelTest__GetAlphaTest(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sPixelTest__IsExistAlphaTest(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sPixelTest__GetDepthTest(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sPixelTest__IsExistDepthTest(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sPixelTest__GetStencilTest(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x20;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sPixelTest__IsExistStencilTest(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x20) != 0;
}

void I3sSpecularEntity__Pack(void) {
}

void I3sSpecularEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sSpecular__GetColor(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sSpecular__IsExistColor(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

void I3sStqClampEntity__Pack(void) {
}

void I3sStqClampEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sStqClamp__GetExtent(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sStqClamp__IsExistExtent(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sStqClamp__GetOffset(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sStqClamp__IsExistOffset(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

void I3sStqMapEntity__Pack(void) {
}

void I3sStqMapEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sStqMap__GetOperation(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sStqMap__IsExistOperation(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sStqMap__GetTransform(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sStqMap__IsExistTransform(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

void I3sLayerEntity__Pack(void) {
}

void I3sLayerEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetAdjustColor(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistAdjustColor(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetAdjustStq(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistAdjustStq(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetAmbient(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x20;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistAmbient(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x20) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetAssignChannel(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x30;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistAssignChannel(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x30) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetAssignTex(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x40;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistAssignTex(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x40) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetDependPlatform(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x50;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistDependPlatform(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x50) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetDiffuse(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x60;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistDiffuse(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x60) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetEmission(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x70;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistEmission(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x70) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetFaceCulling(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x80;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistFaceCulling(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x80) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetFog(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x90;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistFog(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x90) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetPixelBlend(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0xA0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistPixelBlend(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0xA0) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetPixelMask(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0xB0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistPixelMask(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0xB0) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetPixelTest(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0xC0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistPixelTest(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0xC0) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetSpecular(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0xD0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistSpecular(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0xD0) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetStqClamp(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0xE0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistStqClamp(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0xE0) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetStqMapSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0xF4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetStqMapByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0xF8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetBeginStqMap(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0xF8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetEndStqMap(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0xF0;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__GetVisibleFlag(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x100;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sLayer__IsExistVisibleFlag(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x100) != 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/bin_common", I3sMeshInstanceEntity__Pack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/bin_common", I3sMeshInstanceEntity__Unpack);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sMeshInstance__GetAssignMesh(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sMeshInstance__IsExistAssignMesh(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

void I3sPolygonEntity__Pack(void) {
}

void I3sPolygonEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sPolygon__GetAssignMaterial(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sPolygon__IsExistAssignMaterial(void *arg0) {
    return *M2C_FIELD(arg0, int **, 8) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sPolygon__GetChannelSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x14), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sPolygon__GetChannelByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3sPolygon__GetChannelIndexByName(void *arg0) {
    I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sPolygon__GetChannelNameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 0x10) + M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18)), int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3sPolygon__GetChannelByName(void *arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, int *, 8) + 0x10;
    return M2C_FIELD(temp_s0, int *, 8) + (I3dHierarchy__GetIndexByName(temp_s0) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3sPolygon__IsExistChannel(void *arg0) {
    return ~I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x10) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sPolygon__GetBeginChannel(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sPolygon__GetEndChannel(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0x10;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

void I3sKeyFrameFloatEntity__Pack(void) {
}

void I3sKeyFrameFloatEntity__Unpack(void) {
}

void I3sKeyFrameIntEntity__Pack(void) {
}

void I3sKeyFrameIntEntity__Unpack(void) {
}

void I3sMaterialEntity__Pack(void) {
}

void I3sMaterialEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sMaterial__GetLayerSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sMaterial__GetLayerByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sMaterial__GetBeginLayer(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sMaterial__GetEndLayer(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

typedef struct { int p; int arr; unsigned int n; } I3sArrEnt2;
void I3sMeshEntity__Pack(I3sArrEnt2 *m)
{
    unsigned int i, n;

    n = m->n;
    for (i = 0; i < n; i++)
    {
        int *q = (int *)m->arr + i;
        if (*q != 0)
            *q = *q - (int)m;
    }
    if (m->p != 0)
        m->p = m->p - (int)m;
    if (m->arr != 0)
        m->arr = m->arr - (int)m;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/bin_common", I3sMeshEntity__Unpack);

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sMesh__GetPolygonSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sMesh__GetPolygonByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sMesh__GetBeginPolygon(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sMesh__GetEndPolygon(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

void I3sNodeEntity__Pack(int *p)
{
    if (*p != 0)
        *p = *p - (int)p;
}

void I3sNodeEntity__Unpack(int *p)
{
    if (*p != 0)
        *p = *p + (int)p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sNode__GetMeshInstanceSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sNode__GetMeshInstanceByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3sNode__GetMeshInstanceIndexByName(void *arg0) {
    I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8));
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sNode__GetMeshInstanceNameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 0x10) + M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8)), int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3sNode__GetMeshInstanceByName(void *arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_s0, int *, 8) + (I3dHierarchy__GetIndexByName(temp_s0) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3sNode__IsExistMeshInstance(void *arg0) {
    return ~I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8)) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sNode__GetBeginMeshInstance(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sNode__GetEndMeshInstance(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sNode__GetTransform_Local(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sNode__IsExistTransform_Local(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

void I3sAnimFloatEntity__Pack(void) {
}

void I3sAnimFloatEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimFloat__GetKeyFrameSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimFloat__GetKeyFrameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimFloat__GetBeginKeyFrame(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimFloat__GetEndKeyFrame(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimFloat__GetLoopControl(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimFloat__IsExistLoopControl(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

void I3sAnimIntEntity__Pack(void) {
}

void I3sAnimIntEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimInt__GetKeyFrameSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimInt__GetKeyFrameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimInt__GetBeginKeyFrame(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimInt__GetEndKeyFrame(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimInt__GetLoopControl(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sAnimInt__IsExistLoopControl(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

void I3sModelEntity__Pack(void) {
}

void I3sModelEntity__Unpack(void) {
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetMaterialSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 4), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetMaterialByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3sModel__GetMaterialIndexByName(void *arg0) {
    I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8));
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetMaterialNameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 0x10) + M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8)), int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3sModel__GetMaterialByName(void *arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_s0, int *, 8) + (I3dHierarchy__GetIndexByName(temp_s0) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3sModel__IsExistMaterial(void *arg0) {
    return ~I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8)) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetBeginMaterial(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetEndMaterial(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 8);
    return M2C_FIELD(temp_a1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_a1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetMaterialAnimLoopControl(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x10;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__IsExistMaterialAnimLoopControl(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x10) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetMeshSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x24), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetMeshByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x28) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3sModel__GetMeshIndexByName(void *arg0) {
    I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetMeshNameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 0x10) + M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x28)), int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3sModel__GetMeshByName(void *arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, int *, 8) + 0x20;
    return M2C_FIELD(temp_s0, int *, 8) + (I3dHierarchy__GetIndexByName(temp_s0) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3sModel__IsExistMesh(void *arg0) {
    return ~I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x20) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetBeginMesh(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x28);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetEndMesh(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0x20;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetNodeSize(void *arg0) {
    return __builtin_allegrex_ext(M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x34), 0, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetNodeByIndex(void *arg0, int arg1) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x38) + (arg1 * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3sModel__GetNodeIndexByName(void *arg0) {
    I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x30);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetNodeNameByIndex(void *arg0, int arg1) {
    return M2C_FIELD(((arg1 * 0x10) + M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x38)), int *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3sModel__GetNodeByName(void *arg0) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, int *, 8) + 0x30;
    return M2C_FIELD(temp_s0, int *, 8) + (I3dHierarchy__GetIndexByName(temp_s0) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3sModel__IsExistNode(void *arg0) {
    return ~I3dHierarchy__GetIndexByName(M2C_FIELD(arg0, int *, 8) + 0x30) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetBeginNode(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x38);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetEndNode(void *arg0) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 8) + 0x30;
    return M2C_FIELD(temp_v1, int *, 8) + (__builtin_allegrex_ext(M2C_FIELD(temp_v1, int *, 4), 0, 0x18) * 0x10);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__GetVertexAnimLoopControl(void *arg0) {
    return M2C_FIELD(arg0, int *, 8) + 0x40;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3sModel__IsExistVertexAnimLoopControl(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 8), int *, 0x40) != 0;
}

void I3rAnimVector4_SectionParam_Linear__Solve(float *k, float t, float *out)
{
    float x = k[0] * t + k[4];
    float y = k[1] * t + k[5];
    float z = k[2] * t + k[6];
    float w = k[3] * t + k[7];
    out[0] = x;
    out[1] = y;
    out[2] = z;
    out[3] = w;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_00109700);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", apfuncI3rAnimVector4_SectionParam__GetMinMax_t);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", apfuncI3rAnimFloat_SectionParam__Solve);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", apfuncI3rAnimFloat_SectionParam__GetMinMax_t);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/bin_common", I3rAnimVector4_SectionParam_Linear__GetMinMax);

#ifndef NULL
#define NULL ((void *)0)
#endif
float I3rAnimFloat_SectionParam_Linear__Solve(void *arg0, float fparg0) {
    return (M2C_FIELD(arg0, float *, 0) * fparg0) + M2C_FIELD(arg0, float *, 4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void I3rAnimFloat_SectionParam_Linear__GetMinMax(void *arg0, float *arg1, float *arg2, float fparg0, float fparg1) {
    float temp_f1;

    *arg1 = (M2C_FIELD(arg0, float *, 0) * fparg0) + M2C_FIELD(arg0, float *, 4);
    temp_f1 = M2C_FIELD(arg0, float *, 4);
    *arg2 = (temp_f1 * fparg1) + temp_f1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int I3rRoot__TextDump(void) {
    return 0;
}

int I3dTtyPrintf(const char *fmt, ...);
extern const char D_00109720[];
void PrintVec(const float *v)
{
	I3dTtyPrintf(D_00109720, v[0], v[1], v[2], v[3]);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_00109720);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_0010972C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_00109748);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_00109758);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_00109770);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_00109788);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_001097A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_001097B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_001097D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_001097E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_00109800);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_00109818);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_00109830);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_00109840);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_00109854);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_00109868);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_0010986C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_00109870);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_0010987C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_001098A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_001098AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_001098B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_001098C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_001098D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_001098E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/bin_common", D_001098F4);

extern const char D_00109720[];
extern const float D_001098F8;
void Print16Vec(long long v)
{
	float s = D_001098F8;
	short *p = (short *)&v;
	I3dTtyPrintf(D_00109720, (float)p[0] * s, (float)p[1] * s, (float)p[2] * s, (float)p[3] * s);
}
const float D_001098F8 = 3.051850945e-05f;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/bin_common", I3mRoot__TextDump);
