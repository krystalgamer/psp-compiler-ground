/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);
extern unsigned char D_000FCC24;
extern int GimDebug;

void *gimAlloc();
void gimFree();
void sceGimPictureSetMemoryManager();
void sceGimPictureSetMemoryManager2();

extern int GimDebug;
extern unsigned char D_000FCC50;
void *_memAllocMBL();

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/gim", D_000FCC24);

void gimInit(void)
{
	consPrintf(&D_000FCC24, "gimInit");
	GimDebug = 0;
	sceGimPictureSetMemoryManager(gimAlloc, gimFree);
	sceGimPictureSetMemoryManager2(gimAlloc, gimFree);
}

void gimTerm(void) {
    consPrintf(&D_000FCC24, "gimTerm");
}

void gimDebug(int arg0) {
    GimDebug = arg0;
}

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

void gimFree(void *p)
{
	if (GimDebug == 1) {
		char *ra;
		__asm__ volatile("or %0, $31, $0\n\taddiu %0, %0, -8" : "=r"(ra));
		consPrintf("%s : %p\n", "gimFree", ra);
	}
	_memFree(p, &D_000FCC50, 73);
}

/* three unreferenced empty strings follow gimFree's */
__asm__(".section .rodata\n.align 2\n.asciz \"\"\n.align 2\n.asciz \"\"\n.align 2\n.asciz \"\"\n.previous");
