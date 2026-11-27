/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK _memFree(void *, M2C_UNK *, M2C_UNK);       /* extern */

float cusGetFloat(int, M2C_UNK, M2C_UNK *, float);      /* extern */
extern float D_000FE260;

M2C_UNK copLetMat(int, int);                        /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", _PartCusConvEnv);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE1C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE24);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE2C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE34);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE54);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE5C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE64);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDE6C);

#ifndef NULL
#define NULL ((void *)0)
#endif

int _PartCusConvPart_c(void *arg0, int arg1) {
    float temp_f0;

    temp_f0 = cusGetFloat(arg1, 0, "AgeMax", D_000FE260);
    M2C_FIELD(arg0, float *, 4) = temp_f0;
    if (temp_f0 < 0.0f) {
        return 0;
    }
    M2C_FIELD(arg0, float *, 8) = cusGetFloat(arg1, 0, "AgeMin", temp_f0);
    M2C_FIELD(arg0, float *, 0xC) = cusGetFloat(arg1, 0, "SizeRange", 0.0f);
    M2C_FIELD(arg0, float *, 0x10) = cusGetFloat(arg1, 0, "SpdLeanX", 0.0f);
    M2C_FIELD(arg0, float *, 0x14) = cusGetFloat(arg1, 0, "SpdLeanY", 0.0f);
    M2C_FIELD(arg0, float *, 0x18) = cusGetFloat(arg1, 0, "SpdLeanZ", 0.0f);
    M2C_FIELD(arg0, float *, 0x1C) = 0.0f;
    M2C_FIELD(arg0, float *, 0x30) = cusGetFloat(arg1, 0, "SpdRangeL", 0.0f);
    M2C_FIELD(arg0, float *, 0x20) = cusGetFloat(arg1, 0, "SpdTurbX", 0.0f);
    M2C_FIELD(arg0, float *, 0x24) = cusGetFloat(arg1, 0, "SpdTurbY", 0.0f);
    M2C_FIELD(arg0, float *, 0x28) = cusGetFloat(arg1, 0, "SpdTurbZ", 0.0f);
    M2C_FIELD(arg0, float *, 0x2C) = 0.0f;
    M2C_FIELD(arg0, float *, 0x34) = cusGetFloat(arg1, 0, "SpdRadiR", 0.0f);
    M2C_FIELD(arg0, float *, 0x38) = cusGetFloat(arg1, 0, "SpdRangeR", 0.0f);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDEFC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF08);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF10);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF28);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF30);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF40);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF58);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF64);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FDF70);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", _PartCusConvPart2D);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", _PartCusConvPart3D);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", _PartCusConvEmit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE0C4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", _partInit2DBaseCntx);

extern unsigned char D_000FE0C4;
int _partFree2DBaseCntx(void *p)
{
	_memFree(p, &D_000FE0C4, 0x1C0);
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE100);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", _partInit3DBaseCntx);

extern unsigned char D_000FE0C4;
int _partFree3DBaseCntx(void *p)
{
	_memFree(p, &D_000FE0C4, 0x1FD);
	return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", _partEzEnvelope);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partCusConvExt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partInitEnvCntx);

int partFreeEnvCntx(void *p)
{
	if (p != NULL) {
		_memFree(p, &D_000FE0C4, 0x2E3);
	}
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE190);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partInitEmitCntx);

#ifndef NULL
#define NULL ((void *)0)
#endif

int partFreeEmitCntx(void *arg0) {
    int **temp_v1;
    int temp_a1;

    temp_v1 = M2C_FIELD(arg0, int ***, 0x80);
    if (temp_v1 != NULL) {
        temp_a1 = **temp_v1;
        switch (temp_a1) {                          /* irregular */
        case 0:
            _partFree2DBaseCntx(temp_v1);
            break;
        case 1:
            _partFree3DBaseCntx(temp_v1);
            break;
        }
    }
    _memFree(arg0, &D_000FE0C4, 0x34A);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE210);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE220);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE234);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE240);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE254);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE260);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE264);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE268);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE26C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE270);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE274);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE278);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE27C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE280);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE284);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE288);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE28C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", D_000FE290);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partEmitAnimate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partInitPart2DCntx);

extern unsigned char D_000FE0C4;
int partFree2DCntx(void *p)
{
	_memFree(p, &D_000FE0C4, 0x402);
	return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", _partPartCommonAnimate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partPart2DAnimate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partDrawPart2D);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partInitPart3DCntx);

extern unsigned char D_000FE0C4;
int partFree3DCntx(void *p)
{
	_memFree(p, &D_000FE0C4, 0x533);
	return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partPart3DAnimate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/particle", partDrawPart3D);

#ifndef NULL
#define NULL ((void *)0)
#endif
float partEmitGetOps(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x74);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float partEmitGetSpd(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x78);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float partEmitGetTime(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x70);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int partEmitGetAfct(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x7C), int *, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void partEmitSetOps(void *arg0, float fparg0) {
    M2C_FIELD(arg0, float *, 0x74) = fparg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void partEmitSetSpd(void *arg0, float fparg0) {
    M2C_FIELD(arg0, float *, 0x78) = fparg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void partEmitSetMaster(int arg0, int arg1) {
    copLetMat(arg1, arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float partPart2DGetAge(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float partPart2DGetWidth(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x40);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float partPart2DGetHeight(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x44);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float partPart2DGetRot(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x74);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float partPart2DGetRotSpd(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x78);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float partPart2DGetScale(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x48);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float partPart2DGetTime(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x24);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float partPart3DGetAge(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float partPart3DGetWidth(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x40);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float partPart3DGetHeight(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x44);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float partPart3DGetScale(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x48);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
float partPart3DGetTime(void *arg0) {
    return M2C_FIELD(arg0, float *, 0x24);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void partPart2DSetRot(void *arg0, float fparg0) {
    M2C_FIELD(arg0, float *, 0x74) = fparg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void partPart2DSetRotSpd(void *arg0, float fparg0) {
    M2C_FIELD(arg0, float *, 0x78) = fparg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void partPart2DSetScale(void *arg0, float fparg0) {
    M2C_FIELD(arg0, float *, 0x48) = fparg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void partPart3DSetScale(void *arg0, float fparg0) {
    M2C_FIELD(arg0, float *, 0x48) = fparg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int partPart2DGetPtPos(int arg0) {
    return arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int partPart2DGetPtTexCut(int arg0) {
    return arg0 + 0x60;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int partPart2DGetPtCol(int arg0) {
    return arg0 + 0x50;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int partPart3DGetPtPos(int arg0) {
    return arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int partPart3DGetPtTexCut(int arg0) {
    return arg0 + 0x60;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int partPart3DGetPtCol(int arg0) {
    return arg0 + 0x50;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int partPart3DGetPtMat(int arg0) {
    return arg0 + 0xA0;
}
