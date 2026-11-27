/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK _memFree(int **, M2C_UNK *, M2C_UNK);       /* extern */
extern unsigned char D_000FE838;

int fontImgDat();
int i3dDrawImg();

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE7C4);

void consPrintf(const char *, ...);
unsigned int sceKernelGetGPI(void);
int *localeGetCntx(void);
int fontInit(int, int, int);
int fontTerm(void);
extern int l_tTtrFontOpenCntx;
extern unsigned char D_000FE7C4, D_000FE7E8;
int ttrFontOpen(void)
{
	int r;
	if (sceKernelGetGPI() & 1) consPrintf(&D_000FE7C4, "ttrFontOpen");
	if (l_tTtrFontOpenCntx) {
		if (sceKernelGetGPI() & 1) consPrintf("already opened\n");
		return 0;
	}
	r = fontInit(localeGetCntx()[0x24 / 4], localeGetCntx()[0x28 / 4], localeGetCntx()[0x2C / 4]);
	l_tTtrFontOpenCntx = 1;
	if (sceKernelGetGPI() & 1) consPrintf(&D_000FE7E8);
	return r;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE7E8);

int ttrFontClose(void)
{
	if (sceKernelGetGPI() & 1) consPrintf(&D_000FE7C4, "ttrFontClose");
	if (!l_tTtrFontOpenCntx) {
		if (sceKernelGetGPI() & 1) consPrintf("not opened\n");
		return 0;
	}
	fontTerm();
	l_tTtrFontOpenCntx = 0;
	if (sceKernelGetGPI() & 1) consPrintf(&D_000FE7E8);
	return 1;
}

int textGetLine(int *s, int n)
{
	int lines = 1;
	while (n != 0 && *s != 0 && *s != -1) {
		lines += (*s == '\n');
		n--;
		s++;
	}
	return lines;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE808);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE810);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE818);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE820);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE824);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", l_afAlign);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE838);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", ttrFontPrepare);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE85C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE864);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", ttrFontReplace);

void ttrFontInit(int a, int b, int c, int d, int e)
{
	ttrFontInitEx(a, b, c, 0, d, e);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE898);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", ttrFontInitEx);

int ttrFontTerm(int **arg0) {
    int *temp_v0;

    temp_v0 = *arg0;
    if (temp_v0 != NULL) {
        fontImgTerm(temp_v0);
    }
    _memFree(arg0, &D_000FE838, 0x183);
    return 1;
}

typedef struct { int w[16]; } TtrMat;
typedef struct { int w[12]; } TtrAttr;
int ttrFontUpdate(char *p, TtrMat *m, TtrAttr *a)
{
	*(TtrMat *)(p + 0x350) = *m;
	*(TtrAttr *)(p + 0x390) = *a;
	return 1;
}

int ttrFontDraw(int *p)
{
	i3dDrawImg(fontImgDat(p[0]), (char *)p + 0x350, (char *)p + 0x390);
	return 1;
}

void ttrFontClear(int a, int b)
{
	ttrFontInitEx(a, 0, 0, b, 0, 0);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE900);
