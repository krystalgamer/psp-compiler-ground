/* cflags: -Os -fno-strength-reduce */
#include "common.h"

extern int GimDebug;
extern unsigned char D_000FCC50;
void *_memAllocMBL();
void *gimAlloc(int size)
{
	if (GimDebug == 1) {
		char *ra;
		__asm__ volatile("or %0, $31, $0\n\taddiu %0, %0, -8" : "=r"(ra));
		consPrintf("%s : %p %x\n", "gimAlloc", ra, size);
	}
	return _memAllocMBL(size, &D_000FCC50, 60);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCC50);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", gimFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", i3dInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCC88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCC8C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCCA8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCCB8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCCC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCCD8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCDB0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCDC0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCDCC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", i3dTerm);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCDE0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", i3dAsmImg);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCDF4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCE10);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCE1C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCE28);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCE30);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCE38);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", i3dAsmMdl);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCE5C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCE60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCE6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCE80);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCE90);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCEA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCED0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCED8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCEE4);
