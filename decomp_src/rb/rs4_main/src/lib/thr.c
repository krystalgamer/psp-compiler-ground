/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

void consPrintf(const char *, ...);
M2C_UNK thrDelete(void *);                          /* extern */
extern unsigned char D_000FB638;
extern void *pThrEntry;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", D_000FB638);

void thrInit(void) {
    consPrintf(&D_000FB638, "thrInit");
    pThrEntry = 0;
}

void thrTerm(void) {
    void *var_s0;

    consPrintf(&D_000FB638, "thrTerm");
    var_s0 = pThrEntry;
    if (var_s0 != NULL) {
        do {
            thrDelete(var_s0);
            var_s0 = M2C_FIELD(var_s0, void **, 0x14);
        } while (var_s0 != NULL);
    }
    pThrEntry = NULL;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", D_000FB64C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrMake);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", D_000FB680);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", D_000FB690);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", D_000FB698);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrEntry);

extern unsigned char D_000FB64C, D_000FB680, D_000FB690;
#ifndef THR_ASSERT
#define THR_ASSERT(line, fn) consPrintf(&D_000FB64C, &D_000FB680, line, fn, &D_000FB690)
#endif
int sceKernelSleepThreadCB(void);
void thrChange(void)
{
	int ret = sceKernelSleepThreadCB();
	switch (ret) {
	case 0:
		break;
	default:
		THR_ASSERT(0xCB, "thrChange");
		break;
	case 0x800201AA:
		THR_ASSERT(0xCC, "thrChange");
		break;
	case 0x800201A7:
		THR_ASSERT(0xCD, "thrChange");
		break;
	case 0x80020064:
		THR_ASSERT(0xCE, "thrChange");
		break;
	}
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrDelete);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrVSync);
