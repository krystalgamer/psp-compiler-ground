/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"

M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *);           /* extern */
M2C_UNK thrDelete(void *);                          /* extern */
extern unsigned char D_000FB638;
extern void *pThrEntry;


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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB3EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB3F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB3FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB408);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB418);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB428);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB444);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB44C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB458);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB460);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB46C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB474);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB484);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textGetSJIS);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textGetEUC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textGetUTF8);

#ifndef NULL
#define NULL ((void *)0)
#endif
int textGetUTF16LE(void *arg0, void **arg1) {
    int temp_a0;
    int temp_v1;
    int var_a5;
    void *var_a4;

    var_a5 = -1;
    var_a4 = NULL;
    if (arg0 != NULL) {
        temp_a0 = M2C_FIELD(arg0, unsigned char *, 0) | (M2C_FIELD(arg0, unsigned char *, 1) << 8);
        if ((unsigned int) (temp_a0 + 0xFFFF2800) >= 0x800U) {
            var_a5 = temp_a0;
            var_a4 = arg0 + 2;
        } else if ((unsigned int) (temp_a0 + 0xFFFF27FF) < 0x3FEU) {
            temp_v1 = M2C_FIELD(arg0, unsigned char *, 2) | (M2C_FIELD(arg0, unsigned char *, 3) << 8);
            if ((unsigned int) (temp_v1 + 0xFFFF23FF) < 0x3FEU) {
                var_a5 = (((temp_a0 & 0x3FF) << 0xA) | (temp_v1 & 0x3FF)) + 0x10000;
                var_a4 = arg0 + 4;
            }
        }
    }
    if (arg1 != NULL) {
        *arg1 = var_a4;
    }
    return var_a5;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int textGetUTF16BE(void *arg0, void **arg1) {
    int temp_a0;
    int temp_v1;
    int var_a5;
    void *var_a4;

    var_a5 = -1;
    var_a4 = NULL;
    if (arg0 != NULL) {
        temp_a0 = M2C_FIELD(arg0, unsigned char *, 1) | (M2C_FIELD(arg0, unsigned char *, 0) << 8);
        if ((unsigned int) (temp_a0 + 0xFFFF2800) >= 0x800U) {
            var_a5 = temp_a0;
            var_a4 = arg0 + 2;
        } else if ((unsigned int) (temp_a0 + 0xFFFF27FF) < 0x3FEU) {
            temp_v1 = M2C_FIELD(arg0, unsigned char *, 3) | (M2C_FIELD(arg0, unsigned char *, 2) << 8);
            if ((unsigned int) (temp_v1 + 0xFFFF23FF) < 0x3FEU) {
                var_a5 = (((temp_a0 & 0x3FF) << 0xA) | (temp_v1 & 0x3FF)) + 0x10000;
                var_a4 = arg0 + 4;
            }
        }
    }
    if (arg1 != NULL) {
        *arg1 = var_a4;
    }
    return var_a5;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textGetChar);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB4C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB4D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB4D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB4DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB4E4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textCheckCode);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB4FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB504);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB510);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB52C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB53C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB554);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB570);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB580);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB598);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB5B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB5C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB5D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB5E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB5E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB5E8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textToUCS4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textASCIItoUCS4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textUCS4toASCII);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textChr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textCmp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textCpy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textCSpn);

int textLen(int *p)
{
	int n = 0;
	for (; p; p++, n++)
		if (*p == 0 || *p == -1)
			break;
	return n;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textSpn);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textStr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textMid);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textPrintf);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB638);

#ifndef NULL
#define NULL ((void *)0)
#endif

void thrInit(void) {
    consPrintf(&D_000FB638, "thrInit");
    pThrEntry = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

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

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB64C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", thrMake);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB680);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB690);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", D_000FB698);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", thrState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", thrEntry);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", thrChange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", thrDelete);
