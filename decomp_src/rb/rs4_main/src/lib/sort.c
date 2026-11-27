/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"

void consPrintf(const char *, ...);
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

M2C_UNK _memFree(void *, M2C_UNK *, M2C_UNK);       /* extern */
extern unsigned char D_000FB408;
extern unsigned char D_000FB428;
extern unsigned char D_000FB444;

int textTerm(void *arg0) {
    void *temp_v0;

    if (arg0 == NULL) {
        consPrintf(&D_000FB428, &D_000FB408, 0xEB, "textTerm", &D_000FB444);
    }
    if (M2C_FIELD(arg0, void **, 0x10) == NULL) {
        consPrintf(&D_000FB428, &D_000FB408, 0xEC, "textTerm", "pCntx->pCopy");
    }
    temp_v0 = M2C_FIELD(arg0, void **, 0x14);
    if (temp_v0 != NULL) {
        _memFree(temp_v0, &D_000FB408, 0xEF);
    }
    _memFree(M2C_FIELD(arg0, void **, 0x10), &D_000FB408, 0xF0);
    _memFree(arg0, &D_000FB408, 0xF1);
    return 1;
}

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

int *_memAlloc(int, M2C_UNK *, M2C_UNK);            /* extern */
int textToUCS4(M2C_UNK, unsigned char);                        /* extern */
extern unsigned char D_000FB4FC;

int *textASCIItoUCS4(signed char *arg0) {
    int *temp_v0_2;
    int *var_s0;
    int *var_v0;
    signed char *var_s3;
    unsigned int temp_v0;
    unsigned int var_s1;

    var_v0 = NULL;
    var_s3 = arg0;
    if (arg0 != NULL) {
        temp_v0 = strlen(arg0);
        var_s1 = temp_v0;
        temp_v0_2 = _memAlloc((temp_v0 * 4) + 4, &D_000FB408, 0x351);
        var_s0 = temp_v0_2;
        if (temp_v0_2 == NULL) {
            consPrintf(&D_000FB428, &D_000FB408, 0x354, "textASCIItoUCS4", &D_000FB4FC);
        }
        if (var_s1 != 0) {
            do {
                var_s1 -= 1;
                *var_s0 = textToUCS4(0, (unsigned char) *var_s3);
                var_s3 += 1;
                var_s0 += 1;
            } while (var_s1 != 0);
        }
        *var_s0 = -1;
        var_v0 = temp_v0_2;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textUCS4toASCII);

int *textChr(int *p, int c)
{
	while (p) {
		if (*p == 0 || *p == -1) {
			p = 0;
			break;
		}
		if (*p == c)
			break;
		p++;
	}
	return p;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sort", textCmp);

int *textCpy(int *d, int *s)
{
	int *r = d;
	while (d && s) {
		if (*s == 0 || *s == -1)
			d = 0;
		else {
			*d = *s;
			s++;
			d++;
		}
	}
	return r;
}

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
