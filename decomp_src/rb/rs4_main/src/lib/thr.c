/* cflags: -Os */
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrChange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrDelete);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrVSync);
