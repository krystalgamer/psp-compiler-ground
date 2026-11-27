/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
extern signed char D_000FCC88;
extern unsigned char D_000FCDC0;
extern unsigned char D_000FCDCC;
extern void *pI3dTrash;
int I3cRoot__Unpack(int);                           /* extern */
int sceKernelGetGPI();                              /* extern */
extern signed char D_000FCDE0;
extern signed char D_000FCE38;
int taskProc(int, M2C_UNK, int *, M2C_UNK);         /* extern */
extern unsigned char D_000FD24C;
extern signed char D_000FD254;
extern signed char D_000FD368;
extern unsigned char D_000FD388;
extern unsigned char D_000FD394;
extern unsigned char D_000FD3A0;

#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_000FCC8C;
extern unsigned char D_000FCCA8;
extern unsigned char D_000FCFE4;
extern float D_000FD4FC;
M2C_UNK I3cRoot__SetBothFaceEnable(int, M2C_UNK);   /* extern */
int i3dMakeHitAssignTbl(int, int);                  /* extern */
extern unsigned char D_000FCDF4;
extern unsigned char D_000FD060;
void *_memAlloc(M2C_UNK, M2C_UNK *, M2C_UNK);       /* extern */
extern unsigned char D_000FD2FC;
M2C_UNK _memFree(int, M2C_UNK *, M2C_UNK);          /* extern */
extern int pI3dRender;
extern int pI3dStage;
int I3dRender__SetTexInfo(int, int, int);           /* extern */
extern unsigned char D_000FCDB0;
extern unsigned char D_000FD3BC;
extern int D_001199D0;
extern int D_001199D4;
int I3rRoot__GetNodeIndexByName(int, int);          /* extern */
extern unsigned char D_000FD48C;
unsigned int I3rRoot__Get_nNode(int);                        /* extern */
extern unsigned char D_000FD4A4;
extern unsigned char D_000FD4B8;
extern unsigned char D_000FD4C4;

M2C_UNK copLetVec(int, int);                        /* extern */
M2C_UNK copSubVec(int, int, int);                   /* extern */
M2C_UNK copQuatMat(int, int);                       /* extern */
M2C_UNK copSclMat3(int, int, int);
extern const float D_000FD4F4;

extern const float D_000FD4F8;

int copLetMat();
int i3dAttachProc();

int I3dRender__BeginScene(int);
extern unsigned char D_000FCE5C, D_000FCF68, D_000FCF6C, D_000FCF70;
int resCmpExt(void *, void *);
int i3dAsmImg();
int i3dAsmMdl();
int i3dAsmMot();
int i3dReleaseImg();
int I3dPicture__Destruct(void *);
int i3dMakeStage(int, int, float);
int i3dSetTex();
extern unsigned char D_000FD358;

int I3dRenderStage__GetCurrentViewStatus(int);
int copPersVec();

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCC88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCC8C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCCA8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCCB8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCCC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCCD8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCDB0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCDC0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCDCC);

#ifndef NULL
#define NULL ((void *)0)
#endif

int i3dTerm(void) {
    M2C_UNK *temp_v0;

    temp_v0 = "i3dTerm";
    consPrintf(&D_000FCC88, temp_v0);
    if (pI3dTrash == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x52, temp_v0, &D_000FCDC0);
    }
    if (pI3dRender == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x53, temp_v0, &D_000FCDCC);
    }
    I3dRender__Destruct(pI3dRender);
    _memFree(pI3dRender, &D_000FCCA8, 0x57);
    pI3dRender = NULL;
    _memFree(pI3dTrash, &D_000FCCA8, 0x5A);
    pI3dTrash = NULL;
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCDE0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAsmImg);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCDF4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCE10);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCE1C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCE28);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCE30);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCE38);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAsmMdl);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCE5C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCE60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCE6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCE80);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCE90);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCEA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCED0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCED8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCEE4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", _i3dAsmMotOpt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAsmMot);

#ifndef NULL
#define NULL ((void *)0)
#endif

int i3dAsmHit(void *arg0, int arg1) {
    if (sceKernelGetGPI() & 1) {
        consPrintf(&D_000FCDE0, "i3dAsmHit");
    }
    if (M2C_FIELD(arg0, unsigned char *, 0x19) != 2) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x1FF, "i3dAsmHit", &D_000FCDF4);
    }
    if (I3cRoot__Unpack(M2C_FIELD(arg0, int *, 0)) != 0) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x204, "i3dAsmHit", &D_000FCDB0);
    }
    if (sceKernelGetGPI() & 1) {
        consPrintf(&D_000FCE38, "i3dAsmHit");
    }
    return arg1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dReleaseImg);

int i3dReleaseMdl() {
    return 1;
}

int i3dReleaseMot() {
    return 1;
}

int i3dReleaseHit() {
    return 1;
}

int i3dAsmRes(void *name, int a)
{
	int ret;
	if (resCmpExt(name, &D_000FCE5C) == 0) ret = i3dAsmImg(name, a);
	else if (resCmpExt(name, &D_000FCF68) == 0) ret = i3dAsmMdl(name, a);
	else if (resCmpExt(name, &D_000FCF6C) == 0) ret = i3dAsmMot(name, a);
	else if (resCmpExt(name, &D_000FCF70) == 0) ret = i3dAsmHit(name, a);
	else ret = 0;
	return ret;
}

int i3dReleaseRes(void *name)
{
	int ret;
	if (resCmpExt(name, &D_000FCE5C) == 0) ret = i3dReleaseImg(name);
	else if (resCmpExt(name, &D_000FCF68) == 0) ret = i3dReleaseMdl(name);
	else if (resCmpExt(name, &D_000FCF6C) == 0) ret = i3dReleaseMot(name);
	else if (resCmpExt(name, &D_000FCF70) == 0) ret = i3dReleaseHit(name);
	else ret = 0;
	return ret;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCF68);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCF6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCF70);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeMotAssignTbl);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCF88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCF8C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCFA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCFB4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", _i3dMakeMdl);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCFD0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCFD8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCFE4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCFEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FCFF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD004);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD010);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD01C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD024);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD030);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD03C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD048);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeMdl);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD060);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD068);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeMdlEx);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dFreeMdl);

int i3dImgGetWidth(int *img)
{
	return I3dPicture__Get_wPixel(((img[4] + 15) & ~15) + 16, 0);
}

int i3dImgGetHeight(int *img)
{
	return I3dPicture__Get_hPixel(((img[4] + 15) & ~15) + 16, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", _i3dMotTimeAdj);

void i3dMotTimeAdj(int a, int b, int c)
{
	_i3dMotTimeAdj(a, b, c, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotUpdate);

int i3dMotSetMotion(void *arg0, int arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x474, "i3dMotSetMotion", &D_000FCFE4);
    }
    if (arg1 < -1) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x475, "i3dMotSetMotion", "Motion >= -1");
    }
    if (arg1 >= M2C_FIELD(arg0, int *, 0x34)) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x476, "i3dMotSetMotion", "Motion < pCntx->MotNum");
    }
    M2C_FIELD(arg0, int *, 0x50) = arg1;
    M2C_FIELD(arg0, int *, 0x54) = 0;
    M2C_FIELD(arg0, float *, 0x5C) = D_000FD4F4;
    return 1;
}

int i3dMotGetMotion(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x483, "i3dMotGetMotion", &D_000FCFE4);
    }
    return M2C_FIELD(arg0, int *, 0x50);
}

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10], gap at: 0x8. */
int i3dMotSetTime(void *arg0, float fparg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x48E, "i3dMotSetTime", &D_000FCFE4);
    }
    M2C_FIELD(arg0, float *, 0x54) = fparg0;
    return 1;
}

float i3dMotGetTime(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x497, "i3dMotGetTime", &D_000FCFE4);
    }
    return M2C_FIELD(arg0, float *, 0x54);
}

float I3mRoot__GetMaxTime(void *);
float i3dMotGetMaxTime(char *o)
{
	int i;
	void *m;
	if (o == NULL)
		consPrintf(&D_000FCC8C, &D_000FCCA8, 0x49F, "i3dMotGetMaxTime", &D_000FCFE4);
	i = *(int *)(o + 0x50);
	m = i >= 0 ? (*(void ***)(o + 0x38))[i] : NULL;
	if (m)
		return I3mRoot__GetMaxTime(m);
	return 0.0f;
}

int i3dMotSetSpeed(void *arg0, float fparg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x4B1, "i3dMotSetSpeed", &D_000FCFE4);
    }
    M2C_FIELD(arg0, float *, 0x58) = fparg0 / D_000FD4F8;
    return 1;
}

float i3dMotGetSpeed(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x4BA, "i3dMotGetSpeed", &D_000FCFE4);
    }
    return M2C_FIELD(arg0, float *, 0x58);
}

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10], gap at: 0x8. */
int i3dMotSetRate(void *arg0, float fparg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x4C5, "i3dMotSetRate", &D_000FCFE4);
    }
    if (!(fparg0 >= 0.0f)) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x4C6, "i3dMotSetRate", "Rate >= 0");
    }
    if (!(fparg0 <= D_000FD4FC)) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x4C7, "i3dMotSetRate", "Rate <= 1");
    }
    M2C_FIELD(arg0, float *, 0x5C) = fparg0;
    return 1;
}

float i3dMotGetRate(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x4D1, "i3dMotGetRate", &D_000FCFE4);
    }
    return M2C_FIELD(arg0, float *, 0x5C);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotSetSmooth);

float i3dMotGetSmooth(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x4EB, "i3dMotGetSmooth", &D_000FCFE4);
    }
    return M2C_FIELD(arg0, float *, 0x60);
}

int i3dMotSetLoop(void *arg0, int arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x4F6, "i3dMotSetLoop", &D_000FCFE4);
    }
    M2C_FIELD(arg0, int *, 0x64) = (int) (arg1 != 0);
    return 1;
}

int i3dMotGetLoop(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x4FF, "i3dMotGetLoop", &D_000FCFE4);
    }
    return M2C_FIELD(arg0, int *, 0x64);
}

int i3dMotSetPause(void *arg0, int arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x50A, "i3dMotSetPause", &D_000FCFE4);
    }
    M2C_FIELD(arg0, int *, 0x68) = (int) (arg1 != 0);
    return 1;
}

int i3dMotGetPause(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x513, "i3dMotGetPause", &D_000FCFE4);
    }
    return M2C_FIELD(arg0, int *, 0x68);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotAnimate);

void *i3dMakeAttach(void) {
    void *temp_v0;

    temp_v0 = _memAlloc(0x10, &D_000FCCA8, 0x547);
    if (temp_v0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x548, "i3dMakeAttach", &D_000FCFE4);
    }
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = -1;
    M2C_FIELD(temp_v0, int *, 0xC) = -1;
    return temp_v0;
}

int i3dFreeAttach(int p)
{
	_memFree(p, &D_000FCCA8, 0x558);
	return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int i3dAttachGetInfo(int arg0, int *arg1) {
    int var_v0;
    int var_v1;

    if (arg1 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x564, "i3dAttachGetInfo", &D_000FD24C);
    }
    var_v0 = 0;
    if (arg0 != 0) {
        var_v0 = taskProc(arg0, 0x18, arg1, 0);
    }
    *arg1 = var_v0;
    var_v1 = 1;
    if (var_v0 == 0) {
        consPrintf(&D_000FD254, 0);
        var_v1 = 0;
    }
    return var_v1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD24C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD254);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAttach);

int i3dDetach(int arg0, void *arg1) {
    int var_v1;

    if (arg1 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x5CA, "i3dDetach", &D_000FCFE4);
    }
    var_v1 = 0;
    if (M2C_FIELD(arg1, int *, 0) != 0) {
        i3dAttachProc(arg0, arg1);
        copLetMat(arg0 + 0xD0, arg0 + 0x90);
        M2C_FIELD(arg1, int *, 0) = 0;
        var_v1 = 1;
        M2C_FIELD(arg1, int *, 4) = 0;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAttachProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeHitAssignTbl);

int i3dCollisionInitModel(void *arg0, void *arg1) {
    int temp_s0;

    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x642, "i3dCollisionInitModel", &D_000FCFE4);
    }
    if (arg1 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x643, "i3dCollisionInitModel", &D_000FD060);
    }
    if (M2C_FIELD(arg1, unsigned char *, 0x19) != 2) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x644, "i3dCollisionInitModel", &D_000FCDF4);
    }
    temp_s0 = M2C_FIELD(arg1, int *, 0);
    M2C_FIELD(arg0, int *, 0x78) = i3dMakeHitAssignTbl(M2C_FIELD(arg0, int *, 0), temp_s0);
    M2C_FIELD(arg0, int *, 0x74) = temp_s0;
    I3cRoot__SetBothFaceEnable(temp_s0, 1);
    return 1;
}

int i3dCollisionTermModel(char *p)
{
	int t = *(int *)(p + 0x78);
	*(int *)(p + 0x74) = 0;
	*(int *)(p + 0x78) = 0;
	if (t)
		_memFree(t, &D_000FCCA8, 0x65F);
	return 1;
}

void *i3dCollisionMakePrim(float fparg0) {
    void *temp_v0;

    temp_v0 = _memAlloc(0x20, &D_000FCCA8, 0x66B);
    if (temp_v0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x66C, "i3dCollisionMakePrim", &D_000FD2FC);
    }
    M2C_FIELD(temp_v0, float *, 0xC) = fparg0;
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0x10) = 0;
    M2C_FIELD(temp_v0, int *, 0x14) = 0;
    M2C_FIELD(temp_v0, int *, 0x18) = 0;
    M2C_FIELD(temp_v0, int *, 0x1C) = 0;
    return temp_v0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD2FC);

int i3dCollisionFreePrim(int arg0) {
    if (arg0 == 0) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x681, "i3dCollisionFreePrim", &D_000FD2FC);
    }
    _memFree(arg0, &D_000FCCA8, 0x682);
    return 1;
}

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10], gap at: 0x8. */
int i3dCollisionSetSize(void *arg0, float fparg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x68E, "i3dCollisionSetSize", &D_000FD2FC);
    }
    M2C_FIELD(arg0, float *, 0xC) = fparg0;
    return 1;
}

float i3dCollisionGetSize(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x69A, "i3dCollisionGetSize", &D_000FD2FC);
    }
    return M2C_FIELD(arg0, float *, 0xC);
}

int i3dCollisionMovePrim(int arg0, int arg1, int arg2) {
    copLetVec(arg1, arg0);
    copSubVec(arg2, arg1, arg0 + 0x10);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int i3dCollisionGetInfo(int arg0, int *arg1) {
    int var_v0;
    int var_v1;

    if (arg1 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x6B3, "i3dCollisionGetInfo", &D_000FD24C);
    }
    var_v0 = 0;
    if (arg0 != 0) {
        var_v0 = taskProc(arg0, 0x19, arg1, 0);
    }
    *arg1 = var_v0;
    var_v1 = 1;
    if (var_v0 == 0) {
        consPrintf(&D_000FD254, 0);
        var_v1 = 0;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", _i3dTriIntersect);

int _i3dBoxIntersect(void) {
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD358);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD368);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD388);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD394);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD3A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD3AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD3BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD3C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD3D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD3DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD3E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD400);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD410);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD420);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD42C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD434);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD448);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD458);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD46C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD478);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD48C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD4A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD4B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD4C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD4F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD4F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD4F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD4FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD500);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD504);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD508);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCollisionCheck);

void i3dBeginScene(void) {
    if (I3dRender__BeginScene(pI3dRender) != 0) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x774, &D_000FD358, &D_000FCDB0);
    }
    i3dMakeStage(3, 0, 0);
    i3dSetTex(0, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void sceGuCallList(const void *list);

void i3dEndScene(void) {
    pI3dStage = 0;
    if (I3dRender__GetTrashRest(pI3dRender) == 0) {
        consPrintf(&D_000FD368, 0);
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x787, &D_000FD388, &D_000FD394);
    }
    if (I3dRender__GetTrashOverRun(pI3dRender) != 0) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x78C, &D_000FD388, &D_000FD3A0);
    }
    if (I3dRender__EndScene(pI3dRender) != 0) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x791, &D_000FD388, &D_000FCDB0);
    }
    sceGuCallList(I3dRender__GetDisplayListStartPoint(pI3dRender));
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeStage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeView);

int i3dGetRender(void) {
    return pI3dRender;
}

int i3dGetStage(void) {
    return pI3dStage;
}

int i3dSetTex(int arg0, int arg1) {
    if ((arg0 != 0) & (arg1 != 0)) {
        if ((arg0 != D_001199D0) || (arg1 != D_001199D4)) {
            if (I3dRender__SetTexInfo(pI3dRender, arg0, arg1) != 0) {
                consPrintf(&D_000FCC8C, &D_000FCCA8, 0x835, &D_000FD3BC, &D_000FCDB0);
            }
            D_001199D0 = arg0;
            D_001199D4 = arg1;
        }
    } else {
        D_001199D0 = 0;
        D_001199D4 = 0;
    }
    return 1;
}

int i3dGetPos2D(void *mat, char *out)
{
	int vs = I3dRenderStage__GetCurrentViewStatus(pI3dStage);
	copLetMat(mat, out);
	copPersVec(vs, out + 0x30, out + 0x30);
	return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawMdl);

void i3dDrawSprt(int a, int b, int c)
{
	i3dDrawSprtN(a, b, c, 0, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawSprtN);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawSprtR);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawImg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", _i3dDrawNum);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawScore);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDrawTime);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", _i3dDrawTexCut);

void i3dDrawTexCut(int a, int b, int c)
{
	_i3dDrawTexCut(a, b, c, 0);
}

void i3dDrawTexCutEx(int a, int b, int c)
{
	_i3dDrawTexCut(a, b, c, 1);
}

void i3dPosture2Mat(int arg0, int arg1) {
    copQuatMat(arg1 + 0x10, arg0);
    copSclMat3(arg0, arg1 + 0x20, arg0);
    copLetVec(arg1, arg0 + 0x30);
}

int i3dGetNodeIndexByName(int *arg0, int arg1) {
    int var_v0;

    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0xB7A, &D_000FD48C, &D_000FCFE4);
    }
    var_v0 = -1;
    if (arg1 != 0) {
        var_v0 = I3rRoot__GetNodeIndexByName(*arg0, arg1);
    }
    return var_v0;
}

int I3dGetNodeMatPtr(void *arg0, int arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0xB86, &D_000FD4A4, &D_000FCFE4);
    }
    if (arg1 < 0) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0xB87, &D_000FD4A4, &D_000FD4B8);
    }
    if ((unsigned int) arg1 >= I3rRoot__Get_nNode(M2C_FIELD(arg0, int *, 0))) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0xB88, &D_000FD4A4, &D_000FD4C4);
    }
    return M2C_FIELD(arg0, int *, 8) + (arg1 << 6);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD540);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD548);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD550);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD558);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD55C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD564);
