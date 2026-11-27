/* cflags: -Os -fno-strength-reduce */
#include "common.h"
void bxAnmSetFrame(int, float);
void bxAnmSetSpeed(int, float);
void bxAnmSetLoop(int, int);
void bxAnmSetPause(int, int);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", Sub_ProfileEdit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", _AniSet_37FFC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_001033C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_001033DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_001033F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_00103404);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_00103408);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_00103420);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_00103438);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_0010344C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_00103474);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_00103480);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_0010348C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_00103498);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_001034A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_001034B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_001034BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_001034C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_00103508);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_00103518);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_00103528);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_00103534);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_0010353C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_00103544);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", D_0010354C);

void _AniInfoSet_38154(int anm)
{
	bxAnmSetFrame(anm, 0.0f);
	bxAnmSetSpeed(anm, 1.0f);
	bxAnmSetLoop(anm, 1);
	bxAnmSetPause(anm, 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", _FontPutSet_381A4);

extern unsigned char D_001033C0, D_001033DC, D_00103508, D_00103518, D_00103528;
int resGetDatLocal(int, int);
int **ttrFontInit(int, int, void *, int, void *);
void ttrFontTerm(int **);
void *memset(void *, int, unsigned int);
void consPrintf(const char *, ...);
int _TtrFontPutSet_382C4(int dat, int x, void *str)
{
	int prm[4];
	int fid = 0x53;
	int b = 0;
	int t;
	int **f;
	memset(prm, 0, 0x10);
	if (str == 0) {
		str = &D_00103508;
		fid = 5;
		b = 1;
		prm[0] = x;
	} else if (x != 0) {
		prm[0] = x;
		b = 1;
	}
	t = resGetDatLocal(1, dat);
	f = ttrFontInit(t, resGetDatLocal(1, fid), str, b, prm);
	if (f == 0)
		consPrintf(&D_001033C0, &D_001033DC, 0x217, &D_00103518, &D_00103528);
	ttrFontTerm(f);
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/proedit", _PutOsk_383C4);
