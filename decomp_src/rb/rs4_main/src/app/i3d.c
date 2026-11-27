/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
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
M2C_UNK copSclMat3(int, int, int);                  /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", _i3dAsmMotOpt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAsmMot);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAsmHit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dReleaseImg);

#ifndef NULL
#define NULL ((void *)0)
#endif
int i3dReleaseMdl(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int i3dReleaseMot(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int i3dReleaseHit(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAsmRes);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dReleaseRes);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotSetMotion);

#ifndef NULL
#define NULL ((void *)0)
#endif

int i3dMotGetMotion(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x483, "i3dMotGetMotion", &D_000FCFE4);
    }
    return M2C_FIELD(arg0, int *, 0x50);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10], gap at: 0x8. */
int i3dMotSetTime(void *arg0, float fparg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x48E, "i3dMotSetTime", &D_000FCFE4);
    }
    M2C_FIELD(arg0, float *, 0x54) = fparg0;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

float i3dMotGetTime(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x497, "i3dMotGetTime", &D_000FCFE4);
    }
    return M2C_FIELD(arg0, float *, 0x54);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotGetMaxTime);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotSetSpeed);

#ifndef NULL
#define NULL ((void *)0)
#endif

float i3dMotGetSpeed(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x4BA, "i3dMotGetSpeed", &D_000FCFE4);
    }
    return M2C_FIELD(arg0, float *, 0x58);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

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

#ifndef NULL
#define NULL ((void *)0)
#endif

float i3dMotGetRate(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x4D1, "i3dMotGetRate", &D_000FCFE4);
    }
    return M2C_FIELD(arg0, float *, 0x5C);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotSetSmooth);

#ifndef NULL
#define NULL ((void *)0)
#endif

float i3dMotGetSmooth(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x4EB, "i3dMotGetSmooth", &D_000FCFE4);
    }
    return M2C_FIELD(arg0, float *, 0x60);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int i3dMotSetLoop(void *arg0, int arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x4F6, "i3dMotSetLoop", &D_000FCFE4);
    }
    M2C_FIELD(arg0, int *, 0x64) = (int) (arg1 != 0);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int i3dMotGetLoop(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x4FF, "i3dMotGetLoop", &D_000FCFE4);
    }
    return M2C_FIELD(arg0, int *, 0x64);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int i3dMotSetPause(void *arg0, int arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x50A, "i3dMotSetPause", &D_000FCFE4);
    }
    M2C_FIELD(arg0, int *, 0x68) = (int) (arg1 != 0);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int i3dMotGetPause(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x513, "i3dMotGetPause", &D_000FCFE4);
    }
    return M2C_FIELD(arg0, int *, 0x68);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMotAnimate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeAttach);

int i3dFreeAttach(int p)
{
	_memFree(p, &D_000FCCA8, 0x558);
	return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAttachGetInfo);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD24C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD254);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAttach);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dDetach);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dAttachProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeHitAssignTbl);

#ifndef NULL
#define NULL ((void *)0)
#endif

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

#ifndef NULL
#define NULL ((void *)0)
#endif

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

#ifndef NULL
#define NULL ((void *)0)
#endif

int i3dCollisionFreePrim(int arg0) {
    if (arg0 == 0) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x681, "i3dCollisionFreePrim", &D_000FD2FC);
    }
    _memFree(arg0, &D_000FCCA8, 0x682);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10], gap at: 0x8. */
int i3dCollisionSetSize(void *arg0, float fparg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x68E, "i3dCollisionSetSize", &D_000FD2FC);
    }
    M2C_FIELD(arg0, float *, 0xC) = fparg0;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

float i3dCollisionGetSize(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FCC8C, &D_000FCCA8, 0x69A, "i3dCollisionGetSize", &D_000FD2FC);
    }
    return M2C_FIELD(arg0, float *, 0xC);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int i3dCollisionMovePrim(int arg0, int arg1, int arg2) {
    copLetVec(arg1, arg0);
    copSubVec(arg2, arg1, arg0 + 0x10);
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCollisionGetInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", _i3dTriIntersect);

#ifndef NULL
#define NULL ((void *)0)
#endif
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dBeginScene);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dEndScene);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeStage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dMakeView);

#ifndef NULL
#define NULL ((void *)0)
#endif

int i3dGetRender(void) {
    return pI3dRender;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int i3dGetStage(void) {
    return pI3dStage;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dGetPos2D);

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

#ifndef NULL
#define NULL ((void *)0)
#endif

void i3dPosture2Mat(int arg0, int arg1) {
    copQuatMat(arg1 + 0x10, arg0);
    copSclMat3(arg0, arg1 + 0x20, arg0);
    copLetVec(arg1, arg0 + 0x30);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

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

#ifndef NULL
#define NULL ((void *)0)
#endif

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

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", AmbientColor);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD580);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD58C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD598);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD5A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD5B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD5B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD5BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD5C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD5C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD5E0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_Landscape);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD608);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD60C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD610);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD624);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_EzDraw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_EzModel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_Model);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_Stage);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD750);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_View);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD7E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD800);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD810);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_AiAi);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD840);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD848);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_Light);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD86C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD874);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD880);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD88C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD898);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD8A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD8BC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dTask_WallPaper);

#ifndef NULL
#define NULL ((void *)0)
#endif
int i3dCameraInit(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int i3dCameraTerm(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCameraProc);

extern unsigned char i3dTask_View;
void i3dCameraGetParam(int a, int b)
{
	taskSendProc(a, &i3dTask_View, 0x10, b, 0);
}

extern unsigned char i3dTask_View;
void i3dCameraSetParam(int a, int b)
{
	taskSendProc(a, &i3dTask_View, 0x11, b, 0);
}

extern unsigned char i3dTask_View;
void i3dCameraGetMatrix(int a, int b)
{
	taskSendProc(a, &i3dTask_View, 0x12, b, 0);
}

extern unsigned char i3dTask_View;
void i3dCameraSetMatrix(int a, int b)
{
	taskSendProc(a, &i3dTask_View, 0x13, b, 0);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD96C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD97C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD98C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FD9FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FDA00);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dCameraCardBattle);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dLightInit);

extern unsigned char D_000FD5E0;
int i3dLightTerm(int a, char *p)
{
	int t = *(int *)(p + 0x70);
	*(int *)(p + 0x70) = 0;
	if (t)
		_memFree(t, &D_000FD5E0, 0x577);
	return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", i3dLightProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", initInitSys);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FDA40);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", D_000FDA48);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", initTermSys);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", initInitApp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/i3d", initTermApp);
