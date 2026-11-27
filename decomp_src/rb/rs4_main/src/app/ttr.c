/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_000FE6D4, D_000FE6F0, D_000FE6F8, D_000FE718;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", D_000FE6D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", D_000FE6F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", D_000FE6F8);

int ttrGetIndexNum(char **p)
{
	char *ttr_buf = *p;
	char *head;
	if (ttr_buf == NULL)
		consPrintf(&D_000FE6D4, &D_000FE6F8, 0x39, "ttrGetIndexNum", &D_000FE6F0);
	head = ttr_buf;
	if (head == NULL)
		consPrintf(&D_000FE6D4, &D_000FE6F8, 0x3C, "ttrGetIndexNum", &D_000FE718);
	return *(int *)(head + 0x7C);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", D_000FE718);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", ttrGetMaxNumber);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", D_000FE730);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", ttrGetStringByNumber);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", ttrGetStringByIndex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttr", ttrGetString);
