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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", sortPrio);
