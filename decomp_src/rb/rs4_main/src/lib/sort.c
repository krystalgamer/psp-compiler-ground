/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);
extern unsigned char D_000FB370;

extern unsigned char D_000FB374, D_000FB390, D_000FB3A0;
unsigned int sprGetSize(void);

void consPrintf(const char *, ...);

int sortInit(void)
{
	consPrintf(&D_000FB370, "sortInit");
	if (sprGetSize() < 0x400) {
		consPrintf(&D_000FB374, &D_000FB390, 0x28, "sortInit", &D_000FB3A0);
	}
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB370);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB374);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB390);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB3A0);

int sortTerm(void) {
    consPrintf(&D_000FB370, "sortTerm");
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", sortTag);

void sortTagR(unsigned int *p)
{
	unsigned int *q = p + 255;
	unsigned int v = (unsigned int)(p + 254) | 0x80000000;
	do {
		*q = v;
		q--;
		v -= 4;
	} while (q != p);
	*p = 0;
}

unsigned int *sprCall(void);
void sprFree(unsigned int *p);
extern unsigned char D_000FB3CC, D_000FB3D8;
void sortPrio(int top, int prio, int next, int link, int *out)
{
	int *pCntx;
	int p;

	pCntx = (int *)sprCall();
	if (pCntx == NULL)
		consPrintf(&D_000FB374, &D_000FB390, 0x6C, "sortPrio", "pCntx");
	sortTagR((unsigned int *)pCntx);
	p = top;
	while (p != 0) {
		int *b = &pCntx[*(unsigned char *)(p + prio)];
		int n = *(int *)(p + next);
		*(int *)(p + link) = *b;
		*b = p;
		p = n;
	}
	*out = 0;
	p = pCntx[255];
	while (p != 0) {
		if (p > 0) {
			int n = *(int *)(p + link);
			*(int *)(p + link) = *out;
			*out = p;
			p = n;
		} else {
			p = *(int *)(p & 0x7FFFFFFF);
		}
	}
	sprFree((unsigned int *)pCntx);
}
