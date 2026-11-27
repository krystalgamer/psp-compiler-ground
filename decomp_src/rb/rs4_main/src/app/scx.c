/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
int sceKernelGetGPI();                              /* extern */
M2C_UNK sgxResClose(int);                           /* extern */
extern unsigned char D_000FE640;

int consPrintf();
M2C_UNK sgxResCloseAll();                           /* extern */
M2C_UNK sgxSndStopAll(M2C_UNK);                     /* extern */
M2C_UNK sgxTerm();                                  /* extern */
extern unsigned char D_000FE5F4;


extern char D_000FE5A0[];
void *scxMalloc(int size)
{
	return _memAlloc(size, D_000FE5A0, 0x34);
}

extern char D_000FE5A0[];
void scxMfree(void *p)
{
	_memFree(p, D_000FE5A0, 0x3D);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE5A0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE5F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE5F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE604);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE620);

#ifndef NULL
#define NULL ((void *)0)
#endif

int scxTerm(void) {
    consPrintf(&D_000FE5F4, "scxTerm");
    sgxSndStopAll(0);
    sgxResCloseAll();
    sgxTerm();
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE62C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE634);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE640);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE64C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE654);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE65C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE678);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE69C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6A8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6BC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxAsm);

#ifndef NULL
#define NULL ((void *)0)
#endif

int scxRelease(void *arg0) {
    if (sceKernelGetGPI() & 1) {
        consPrintf(&D_000FE5F4, &D_000FE640);
    }
    sgxResClose(*M2C_FIELD(arg0, int **, 0x10));
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxPlay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxVolume);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxStop);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", scxPause);

extern unsigned char D_000FE65C, D_000FE6BC;
int sgxSndGetStatus();
int scxState(int id)
{
	if (id >= 0)
		return sgxSndGetStatus(id);
	consPrintf(&D_000FE65C, &D_000FE6BC, id);
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void scxStopAll(void) {
    sgxSndStopAll(0);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE6F8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", ttrGetIndexNum);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE718);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", ttrGetMaxNumber);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", D_000FE730);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", ttrGetStringByNumber);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", ttrGetStringByIndex);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/scx", ttrGetString);
