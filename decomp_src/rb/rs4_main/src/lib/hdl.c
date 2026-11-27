/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);

extern unsigned char D_000FABEC, D_000FAC08, D_000FAC3C;
int elmTerm();
int _memFree();

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", D_000FABEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", D_000FAC08);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", hdlInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", D_000FAC3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", D_000FAC44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", D_000FAC5C);

int hdlTerm(int *h)
{
	if (h == NULL) {
		consPrintf(&D_000FABEC, &D_000FAC08, 0x42, "hdlTerm", &D_000FAC3C);
	}
	consPrintf("%s : 0x%08x\n", "hdlTerm", h);
	if (h == NULL) {
		return 0;
	}
	elmTerm(*h);
	_memFree(h, &D_000FAC08, 0x4C);
	return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", hdlMake);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", D_000FAC88);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", hdlFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/hdl", hdlPtr);
