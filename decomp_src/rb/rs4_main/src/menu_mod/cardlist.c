/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK _memFree(int, M2C_UNK *, M2C_UNK);          /* extern */
extern unsigned char D_00101FCC;
extern int l_atCardList;
extern int l_nCardIDMax;
extern int l_nCardNum;
void consPrintf(const char *, ...);
extern unsigned char D_00102244;
void *cardlistFindOne();                            /* extern */
typedef struct { int pad[0x80]; unsigned short id; char p1[0x2A]; int iid; char p2[8]; char prog[0xB60 - 0x238]; } CardEnt;
extern unsigned char D_001021A0;

int *resGetDatLocal();
int ttrGetStringByIndex();

extern const float D_00102594;
int sscanf(const char *, const char *, ...);

float cardlistCpyTtr2Float32();

void cardlistCpyTtr2Ascii();

int cardlistGetCardID(int id)
{
	int a, b;
	if (ttrGetStringByIndex(resGetDatLocal(1, 15), id, &a, &b))
		return b;
	return -1;
}

typedef struct { int c[13]; } TtrNF;
extern TtrNF D_00101F4C;
char *ttrGetStringByNumber();

void cardlistCpyTtr2Ucs4(int *dst, int ttr, int num, int max)
{
	TtrNF def;
	int len;
	int n;
	unsigned short *p;
	char *s = ttrGetStringByNumber(ttr, num, &len);
	if (s == NULL) {
		def = D_00101F4C;
		s = (char *)&def;
	}
	p = (unsigned short *)s;
	for (n = len / 2; n != 0 && max >= 2; n--) {
		max--;
		*dst++ = *p++;
	}
	*dst = 0;
}

void cardlistCpyTtr2Ascii(char *dst, int ttr, int num)
{
	TtrNF def;
	int len;
	int n;
	short *p;
	char *s = ttrGetStringByNumber(ttr, num, &len);
	if (s == NULL) {
		def = D_00101F4C;
		s = (char *)&def;
	}
	p = (short *)s;
	for (n = len / 2; n != 0; n--) {
		*dst++ = *p++;
	}
	*dst = 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00101F4C);

float cardlistCpyTtr2Float32(a, b)
	int a, b;
{
	char buf[0x40];
	float f = D_00102594;
	memset(buf, 0, 0x40);
	cardlistCpyTtr2Ascii(buf, a, b);
	sscanf(buf, "%f", &f);
	return f;
}

/* the conversion is an inline-asm cvt.w.s (rounds), not a cast (trunc.w.s) */
int cardlistCpyTtr2Int32() {
    float r;
    float f = cardlistCpyTtr2Float32();
    __asm__ volatile ("cvt.w.s %0, %1" : "=f"(r) : "f"(f));
    return *(int *)&r;
}

int cardlistCpyTtr2Bool(int a, int b)
{
	char buf[0x40];
	memset(buf, 0, 0x40);
	cardlistCpyTtr2Ascii(buf, a, b);
	return buf[0] == 'o';
}

int cardlistCpyTtr2Enum(void) {
    return cardlistCpyTtr2Int32() - 1;
}

M2C_UNK cardlistRefresh();                          /* extern */
int ttrGetMaxNumber(signed char **);                         /* extern */
extern unsigned char D_00101F94;
extern unsigned char D_00101F9C;
extern unsigned char D_00101FB0;
extern unsigned char D_00101FE4;
extern unsigned char D_00102004;
extern unsigned char D_00102014;
extern unsigned char D_00102038;

int cardlistInit(void) {
    M2C_UNK *temp_v0;
    int temp_a5;
    int temp_v0_2;
    int temp_v0_4;
    void *temp_v0_3;

    temp_v0 = "cardlistInit";
    consPrintf(&D_00101F94, temp_v0);
    if (l_atCardList != NULL) {
        consPrintf(&D_00101FB0, &D_00101FCC, 0x9D, temp_v0, &D_00101F9C);
    }
    l_nCardNum = ttrGetIndexNum(resGetDatLocal(1, 0xF));
    if (l_nCardNum > 0x100) {
        consPrintf(&D_00101FB0, &D_00101FCC, 0xA0, temp_v0, &D_00101FE4);
    }
    l_atCardList = _memAllocZero(l_nCardNum * 0xB60, &D_00101FCC, 0xA2);
    if (l_atCardList == NULL) {
        consPrintf(&D_00101FB0, &D_00101FCC, 0xA3, temp_v0, &D_00102004);
    }
    l_nCardIDMax = ttrGetMaxNumber(resGetDatLocal(1, 0xF));
    if (l_nCardIDMax >= 0x190) {
        consPrintf(&D_00101FB0, &D_00101FCC, 0xA6, temp_v0, &D_00102014);
    }
    cardlistRefresh();
    consPrintf(&D_00102038, temp_v0);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00101F94);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00101F9C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00101FB0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00101FCC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00101FE4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102004);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102014);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102038);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102040);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistRefresh);

int cardlistTerm(void) {
    l_nCardIDMax = 0;
    l_nCardNum = 0;
    _memFree(l_atCardList, &D_00101FCC, 0x142);
    l_atCardList = 0;
    return 1;
}

int cardlistGetMaxCardID(void) {
    return l_nCardIDMax;
}

int cardlistGetCardNum(void) {
    return l_nCardNum;
}

extern unsigned char D_00101FB0;
void *cardlistFindOne(uCardID)
unsigned int uCardID;
{
	int n = l_nCardNum;
	CardEnt *p = (CardEnt *)l_atCardList;
	if (!(uCardID <= l_nCardIDMax))
		consPrintf(&D_00101FB0, &D_00101FCC, 0x15C, "cardlistFindOne", "uCardID <= l_nCardIDMax");
	for (; n; n--, p++)
		if (p->id == uCardID)
			return p;
	return NULL;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_001021A0);

void *memset(void *, int, unsigned int);
CardEnt *cardlistGetOne(CardEnt *dst, int id)
{
	CardEnt *src = cardlistFindOne(id);
	if (src) {
		memset(dst, 0, sizeof(CardEnt));
		*dst = *src;
		return dst;
	}
	consPrintf(&D_001021A0, "cardlistGetOne", id);
	return NULL;
}

void *cardlistGetPtr(int id)
{
	void *p = cardlistFindOne(id);
	if (!p) {
		consPrintf(&D_001021A0, "cardlistGetPtr", id);
		return 0;
	}
	return p;
}

CardEnt *cardlistGetOneByInstructID(CardEnt *dst, int iid)
{
	int n = l_nCardNum;
	CardEnt *p = (CardEnt *)l_atCardList;
	for (; n; n--, p++) {
		if (p->iid == iid) {
			memset(dst, 0, sizeof(CardEnt));
			*dst = *p;
			consPrintf("%s : InstructID(%d) => Prog=%s, CardID=%d\n", "cardlistGetOneByInstructID", iid, p->prog, p->id);
			return dst;
		}
	}
	consPrintf("%s : InstructID(%d) not found.\n", "cardlistGetOneByInstructID", iid);
	return NULL;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102244);

CardEnt *cardlistGetOneBySaveID(CardEnt *dst, unsigned int i)
{
	if (i < (unsigned int)l_nCardNum) {
		CardEnt *src = &((CardEnt *)l_atCardList)[i];
		memset(dst, 0, sizeof(CardEnt));
		*dst = *src;
		return dst;
	}
	consPrintf(&D_00102244, "cardlistGetOneBySaveID", i);
	return NULL;
}

int cardlistGetPtrBySaveID(unsigned int arg0) {
    if (arg0 < (unsigned int) l_nCardNum) {
        return l_atCardList + (arg0 * 0xB60);
    }
    consPrintf(&D_00102244, "cardlistGetPtrBySaveID", arg0);
    return 0;
}

int cardlistSetInstructID(int arg0, int arg1) {
    int var_v1;
    void *temp_v0;

    temp_v0 = cardlistFindOne();
    var_v1 = 1;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0x22C) = arg1;
    } else {
        consPrintf(&D_001021A0, "cardlistSetInstructID", arg0);
        var_v1 = 0;
    }
    return var_v1;
}

int cardlistGetInstructID(int arg0) {
    void *temp_v0;

    temp_v0 = cardlistFindOne();
    if (temp_v0 != NULL) {
        return M2C_FIELD(temp_v0, int *, 0x22C);
    }
    consPrintf(&D_001021A0, "cardlistGetInstructID", arg0);
    return -1;
}

int cardlistGetSaveID(int arg0) {
    void *temp_v0;

    temp_v0 = cardlistFindOne();
    if (temp_v0 != NULL) {
        return M2C_FIELD(temp_v0, int *, 0x230);
    }
    consPrintf(&D_001021A0, "cardlistGetSaveID", arg0);
    return -1;
}

int cardlistGetCardIDFromSaveID(unsigned int arg0) {
    if (arg0 < (unsigned int) l_nCardNum) {
        return M2C_FIELD(((arg0 * 0xB60) + l_atCardList), unsigned short *, 0x200);
    }
    consPrintf(&D_00102244, "cardlistGetCardIDFromSaveID", arg0);
    return -1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetResultEfcTtrStr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetRarityTtrStr);

int cardlistGetCardNameBySaveID(unsigned int arg0) {
    if (arg0 < (unsigned int) l_nCardNum) {
        return l_atCardList + (arg0 * 0xB60);
    }
    consPrintf(&D_00102244, "cardlistGetCardNameBySaveID", arg0);
    return 0;
}

void *cardlistGetCardName(int id)
{
	void *p = cardlistFindOne(id);
	if (!p) {
		consPrintf(&D_001021A0, "cardlistGetCardName", id);
		return 0;
	}
	return p;
}

float randU(int, float);
void *_memAlloc(int, void *, int);
int *ShuffleRandAlloc(int seed, unsigned int n)
{
	int *t;
	int i = 0;
	t = _memAlloc(n * 4, &D_00101FCC, 0x234);
	for (i = 0; i < n; i++)
		t[i] = i;
	if (seed != -1) {
		for (i = n - 1; i >= 0; i--) {
			int k = randU(seed, i + 1);
			int a;
			if (t[i] != t[k]) {
				a = t[i];
				t[i] = t[k];
				t[k] = a;
			}
		}
	}
	for (i = 0; i < n; i++)
		;
	return t;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102340);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetOfficialDeck);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetEnemyDeck);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", cardlistGetBonusCard);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102594);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_00102598);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_0010259C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_001025A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_001025A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_001025A8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/cardlist", D_001025AC);
