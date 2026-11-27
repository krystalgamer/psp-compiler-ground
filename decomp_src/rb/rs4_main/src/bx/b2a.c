/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
#include "common.h"
extern "C" {

} /* extern "C" */

struct ScePspFMatrix4 { float m[16]; };
struct tagGpTEXDESC;

struct GpPrim {
	int a, b, c, d;
	float sx, sy, sz, sw;
	ScePspFMatrix4 mtx;
	tagGpTEXDESC *tex;
	int w, h;
	int cx, cy;
	unsigned int col;
	int pad[2];
};

extern "C" {
extern GpPrim sample_anm_list[128];
extern int GpPrim_cnt;
extern int GpPrim_dcnt;
extern const float D_00108F14;
void *memset(void *, int, unsigned int);
}

void GpPrim_Init()
{
	GpPrim *p;
	int i;

	GpPrim_cnt = 0;
	GpPrim_dcnt = 0;
	memset(sample_anm_list, 0, sizeof(sample_anm_list));
	p = sample_anm_list;
	for (i = 128; i != 0; i--, p++) {
		p->a = 0;
		p->b = 0;
		p->c = 0;
		p->sx = D_00108F14;
		p->sy = D_00108F14;
		p->sz = D_00108F14;
		p->mtx.m[0] = D_00108F14;
		p->mtx.m[1] = 0;
		p->mtx.m[2] = 0;
		p->mtx.m[3] = 0;
		p->mtx.m[4] = 0;
		p->mtx.m[5] = D_00108F14;
		p->mtx.m[6] = 0;
		p->mtx.m[7] = 0;
		p->mtx.m[8] = 0;
		p->mtx.m[9] = 0;
		p->mtx.m[10] = D_00108F14;
		p->mtx.m[11] = 0;
		p->mtx.m[12] = 0;
		p->mtx.m[13] = 0;
		p->mtx.m[14] = 0;
		p->mtx.m[15] = D_00108F14;
		p->w = 0;
		p->h = 0;
		p->cx = 0;
		p->cy = 0;
		p->col = 0x80808080;
	}
}

extern "C" const float D_00108F14 = 1.0f;

void GpPrim_SetStart()
{
	GpPrim_cnt = 0;
}

void GpPrim_DrawStart()
{
	GpPrim_dcnt = 0;
}

void GpPrim_SetTex(tagGpTEXDESC *tex)
{
	sample_anm_list[GpPrim_cnt].tex = tex;
}

void GpPrim_SetCol(int col)
{
	sample_anm_list[GpPrim_cnt].col = col;
}

void GpPrim_SetWH(int w, int h)
{
	GpPrim *p = &sample_anm_list[GpPrim_cnt];
	p->w = w;
	p->h = h;
}

void GpPrim_SetCenter(float x, float y)
{
	GpPrim *p = &sample_anm_list[GpPrim_cnt];
	p->cx = (int)x;
	p->cy = (int)y;
}

void GpPrim_SetMatrix(ScePspFMatrix4 *m)
{
	if (m) {
		GpPrim *p = &sample_anm_list[GpPrim_cnt];
		p->mtx = *m;
	}
}

tagGpTEXDESC *GpPrim_GetDrawTex()
{
	return sample_anm_list[GpPrim_dcnt].tex;
}

unsigned int GpPrim_GetDrawCol()
{
	return sample_anm_list[GpPrim_dcnt].col;
}

void GpPrim_GetDrawCenter(float *x, float *y)
{
	GpPrim *p = &sample_anm_list[GpPrim_dcnt];
	*x = p->cx;
	*y = p->cy;
}

void GpPrim_GetDrawWH(int *w, int *h)
{
	GpPrim *p = &sample_anm_list[GpPrim_dcnt];
	*w = p->w;
	*h = p->h;
}

void GpPrim_GetDrawMatrix(ScePspFMatrix4 *m)
{
	GpPrim *p = &sample_anm_list[GpPrim_dcnt];
	if (m)
		*m = p->mtx;
}

void GpPrim_SetNext()
{
	GpPrim_cnt++;
}

void GpPrim_DrawNext()
{
	GpPrim_dcnt++;
}

int GpPrim_GetMax()
{
	return GpPrim_cnt;
}

extern "C" {

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A9CreateB2AEPNS_7B2aFileE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A5StartEPNS_7ManagerE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A4CalcEPNS_7ManagerE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A4DrawEPNS_7ManagerE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A13DeleteManagerEPNS_7ManagerE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A12DeletePlayerEPNS_6PlayerE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7B2aFileC2EP7InstDatiiPP16TBxAnmInitAssign);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7B2aFileC1EP7InstDatiiPP16TBxAnmInitAssign);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7B2aFileD2Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7B2aFileD1Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7B2aFile8ReAssignEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7ManagerC2EPNS_7B2aFileE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7ManagerC1EPNS_7B2aFileE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7ManagerD2Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7ManagerD1Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager11EnableSceneEi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager12DisableSceneEi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager12CreatePlayerEi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager12DeletePlayerEPNS_6PlayerE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager10RefreshOneEib);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager7RefreshEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8SetFrameEf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8GetFrameEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager7SetLoopEi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager7GetLoopEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8SetPauseEi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8GetPauseEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8SetSpeedEf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8GetSpeedEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager11GetEndFrameEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager11SetEndFrameEf);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F1C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F24);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F28);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F2C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F30);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F34);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZZN3B2A7B2aFileC1EP7InstDatiiPP16TBxAnmInitAssignE12__FUNCTION__);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F50);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F58);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F70);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108F84);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108FA0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108FB0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108FB8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108FBC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", D_00108FDC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager7CalcOneEPNS_6PlayerE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager4CalcEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager7DrawOneEi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager4DrawEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager4playEif);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager4drawEiP14ScePspFMatrix4S2_j);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8getValueERfRNS_8KeyArrayINS_4LOOPEEEf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8getValueERiRNS_8KeyArrayINS_3PTNEEEf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8getValueERfRNS_8KeyArrayINS_3FLTEEEf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8getValueER4FVECRNS_8KeyArrayINS_3FXYEEEf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A7Manager8getValueERNS_4RGBAERNS_8KeyArrayIS1_EEf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A6ObjectC2Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A6ObjectC1Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A6Object5ClearEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A6Object7RefreshEv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A6Object6MoveToER4FVEC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A6Object5ScaleEff);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A6PlayerC2Ei);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A6PlayerC1Ei);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A6PlayerD2Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A6PlayerD1Ev);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _ZN3B2A6Player3SetEi);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _Z41__static_initialization_and_destruction_0ii_5A4F0);

void _ZN15SAMPLE_ANM_DATAC1Ev(void) {
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _GLOBAL__I__Z11GpPrim_Initv);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/bx/b2a", _GLOBAL__D__Z11GpPrim_Initv);

} /* extern "C": m2c drafts with mangled names, kept as C linkage */
