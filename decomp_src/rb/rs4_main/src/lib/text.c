/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

void consPrintf(const char *, ...);

M2C_UNK _memFree(void *, M2C_UNK *, M2C_UNK);       /* extern */
extern unsigned char D_000FB408;
extern unsigned char D_000FB428;
extern unsigned char D_000FB444;

int *_memAlloc(int, M2C_UNK *, M2C_UNK);            /* extern */
int textToUCS4(int code, int c);
extern unsigned char D_000FB4FC;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", textInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB3EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB3F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB3FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB408);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB418);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB428);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB444);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB44C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB458);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB460);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB46C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB474);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB484);

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

/* STAND-IN (maybe): the single-byte ranges as `goto single` tests (predicted not taken, so the
   delay slots take the next test); one `||` condition gives bnel/target fills instead. */
int textGetSJIS(unsigned char *s, unsigned char **next)
{
	int c = -1;
	unsigned char *n = NULL;
	unsigned int c0, c1;

	if (s != NULL) {
		c0 = s[0];
		if (c0 < 0x20 || c0 == 0x7F)
			goto single;
		if (c0 >= 0x20 && c0 <= 0x7E)
			goto single;
		if (c0 >= 0xA1 && c0 <= 0xDF) {
single:
			c = c0;
			n = s + 1;
		} else if ((c0 >= 0x81 && c0 <= 0x9F) || (c0 >= 0xE0 && c0 <= 0xEF)) {
			c1 = s[1];
			if ((c1 >= 0x40 && c1 <= 0x7E) || (c1 >= 0x80 && c1 <= 0xFC)) {
				c = c1 | (c0 << 8);
				n = s + 2;
			}
		}
	}
	if (next != NULL)
		*next = n;
	return c;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", textGetEUC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", textGetUTF8);

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

int textGetEUC(unsigned char *s, unsigned char **next);
int textGetUTF8(unsigned char *s, unsigned char **next);
int textGetChar(int code, void *s, void **next)
{
	switch (code) {
	case 0:
		return textGetSJIS(s, (unsigned char **)next);
	case 1:
		return textGetEUC(s, (unsigned char **)next);
	case 2:
		return textGetUTF8(s, (unsigned char **)next);
	case 3:
		return textGetUTF16BE(s, next);
	case 4:
		return textGetUTF16LE(s, next);
	case -1:
	default:
		return -1;
	}
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB4C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB4D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB4D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB4DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB4E4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", textCheckCode);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB4FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB504);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB510);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB52C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB53C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB554);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB570);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB580);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB598);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB5B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB5C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB5D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB5E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB5E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", D_000FB5E8);

typedef struct { int sjis; int euc; int ucs4; } TextCodeTbl;
extern TextCodeTbl D_00111040[];
int textToUCS4(int code, int c)
{
	TextCodeTbl *t, *e;
	int n, m;

	switch (code) {
	case 2:
	case 3:
	case 4:
		return c;
	case 0:
		for (t = D_00111040, n = 0x5D; n != 0; n--, t++)
			if (t->sjis == c)
				return t->ucs4;
		return c;
	case 1:
		for (e = D_00111040, m = 0x5D; m != 0; m--, e++)
			if (e->euc == c)
				return e->ucs4;
		return c;
	default:
		consPrintf(&D_000FB428, &D_000FB408, 0x329, "textToUCS4", "FALSE");
		return -1;
	}
}

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

char *textUCS4toASCII(int *s)
{
	char *p, *d;
	int n;
	int c;

	if (s == NULL)
		return NULL;
	n = textLen(s);
	p = (char *)_memAlloc(n + 1, &D_000FB408, 0x36D);
	d = p;
	if (p == NULL)
		consPrintf(&D_000FB428, &D_000FB408, 0x370, "textUCS4toASCII", &D_000FB4FC);
	for (; n != 0; n--) {
		c = *s;
		s++;
		*d = (c >= 0x21 && c <= 0x7E) ? c : '?';
		d++;
	}
	*d = 0;
	return p;
}

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", textCmp);

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

int textCSpn(int *s, int *set)
{
	int n = 0;
	while (s && set) {
		int c = *s++;
		if (c == 0 || c == -1)
			s = 0;
		else {
			if (textChr(set, c))
				return n;
			n++;
		}
	}
	return n;
}

int textLen(int *p)
{
	int n = 0;
	for (; p; p++, n++)
		if (*p == 0 || *p == -1)
			break;
	return n;
}

int textSpn(int *s, int *set)
{
	int n = 0;
	while (s && set) {
		int c = *s++;
		if (c == 0 || c == -1)
			s = 0;
		else {
			if (!textChr(set, c))
				return n;
			n++;
		}
	}
	return n;
}

int *textStr(int *s, int *k)
{
	int *r = 0;
	int *p, *q;
	while (s && k) {
		if (*s == 0 || *s == -1)
			s = 0;
		else {
			for (p = s, q = k; q; ) {
				r = s;
				if (*q == 0 || *q == -1)
					return r;
				if (*q++ != *p++)
					break;
			}
			s++;
		}
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", textMid);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/text", textPrintf);
