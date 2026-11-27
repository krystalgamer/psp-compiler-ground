/* cflags: -Os -fno-strength-reduce */
#include "common.h"
void bxAnmSetFrame(int, float);
void bxAnmSetSpeed(int, float);
void bxAnmSetLoop(int, int);
void bxAnmSetPause(int, int);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", Sub_DeckSel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", _AniSet_340E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102804);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102820);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102838);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102844);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102848);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102854);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102860);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102878);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_0010288C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_001028A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_001028B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102924);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_0010294C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102958);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102964);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102970);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_0010297C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102988);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102994);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_001029A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_001029AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_001029B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_001029C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102A2C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102A3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102A4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102A58);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102A60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102A68);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", D_00102A70);

void _AniInfoSet_342B8(int anm)
{
	bxAnmSetFrame(anm, 0.0f);
	bxAnmSetSpeed(anm, 1.0f);
	bxAnmSetLoop(anm, 1);
	bxAnmSetPause(anm, 0);
}

typedef struct { int f0; int cur; int f8[5]; int base[5]; int mode[5]; int done[5]; int anm[3]; } DsWin;
int bxAnmExec(int);
void _WinAniExe(DsWin *w, int unused, int frame)
{
	int b = w->base[w->cur];
	if (w->done[w->cur] == 0) {
		if (bxAnmExec(w->anm[b]) != 0)
			w->done[w->cur] = 1;
	} else if (w->mode[w->cur] != 1) {
		b += w->f8[w->cur] + 1;
		bxAnmExec(w->anm[b]);
		if (w->cur == 0 && w->done[0] != 0)
			bxAnmExec(w->anm[1]);
	}
	bxAnmSetFrame(w->anm[2], frame);
	bxAnmSetSpeed(w->anm[2], 0.0f);
	bxAnmExec(w->anm[2]);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", _FontPutSet_343E8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", _TtrFontPutSet_3450C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/decksel", _PutOsk_34620);
