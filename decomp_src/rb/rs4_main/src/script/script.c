/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
int sceKernelGetGPI();                              /* extern */
int taskMake(void *, M2C_UNK *, M2C_UNK, M2C_UNK);  /* extern */
extern unsigned char ProgFrameIn;

typedef struct { int a, b, c, d; } ScrOpnd;
typedef struct { int *ucs4; int pad[2]; int len; } ConvEnt;
typedef struct { char **words; int num; ConvEnt *ent; } ConvTblT;
extern ConvTblT ConvTbl[19];
typedef struct { int *str; int line; int pos; } ScrTok;
extern unsigned char D_001000E0, D_001000F4, D_00100164;
void consPrintf(const char *, ...);
void *_memAllocZero(int, void *, int);
int _memFree();
unsigned int strlen(const char *);
int *textASCIItoUCS4(const char *);
char *textUCS4toASCII(int *);
int textCmp(int *, int *);
int textLen(int *);
void ScriptCompileError(char *msg, ScrTok *t, int code);
int ScriptWordSearchUCS4(int t, int *s);
extern unsigned char D_001001E8, D_001001F0, D_00100218, D_00100220, D_0010022C;
void *_memAlloc(int, void *, int);
int textPrintf(int *);
int ScriptSearchName(char *s, unsigned int type, int *name);
typedef struct ScrVar { struct ScrVar *next; int addr; int type; ScrTok *tok; } ScrVar;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001000E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001000F4);

int ScriptInit(void)
{
	unsigned int i;
	int j;
	ConvTblT *c;
	int num;
	char **w;
	ConvEnt *e;
	int len;
	int *u;
	for (i = 0; i < 19; i++) {
		c = &ConvTbl[i];
		num = c->num;
		w = c->words;
		e = _memAllocZero(num * 16, &D_001000E0, 0x206);
		if (e == NULL)
			consPrintf(&D_001000F4, &D_001000E0, 0x207, "ScriptInit", "apTok");
		c->ent = e;
		for (j = 0; j < num; j++) {
			len = strlen(w[j]);
			u = textASCIItoUCS4(w[j]);
			if (u == NULL)
				consPrintf(&D_001000F4, &D_001000E0, 0x20F, "ScriptInit", "pStr");
			e[j].ucs4 = u;
			e[j].len = len;
		}
	}
	return 1;
}

int ScriptTerm(void)
{
	unsigned int i;
	int j, num;
	ConvEnt *e;
	for (i = 0; i < 19; i++) {
		num = ConvTbl[i].num;
		e = ConvTbl[i].ent;
		for (j = 0; j < num; j++)
			_memFree(e[j].ucs4, &D_001000E0, 0x224);
		_memFree(ConvTbl[i].ent, &D_001000E0, 0x226);
	}
	return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptCompileError);

static inline int _wcmp(int *s, int *u)
{
	if (u == NULL) return -1;
	return textCmp(s, u);
}
int ScriptWordSearch(char **w, int n, int *s)
{
	int i = 0;
	int *u;
	int r;
	while (n) {
		u = w[i] ? textASCIItoUCS4(w[i]) : NULL;
		r = _wcmp(s, u);
		if (u) _memFree(u, &D_001000E0, 0x24B);
		if (r == 0) return i;
		i++;
		n--;
	}
	return -1;
}

int ScriptWordSearchUCS4(int t, int *s)
{
	int len = textLen(s);
	int num = ConvTbl[t].num;
	ConvEnt *e = ConvTbl[t].ent;
	int i, n = 0;
	for (i = 0; n < num; i++, n++, e++) {
		if (e->len == len && textCmp(s, e->ucs4) == 0)
			return i;
	}
	return -1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100164);

int ScriptWordSection(ScrTok *t, int *a, int *b)
{
	int r = -1;
	int x, y;
	if (t->pos == 0) {
	x = -1;
	r = ScriptWordSearchUCS4(0, t->str);
	y = 1;
	if (r >= 0) {
		switch (r) {
		default:
			ScriptCompileError((char *)&D_00100164, t, 0x280);
			y = 0;
			break;
		case 0: x = 1; break;
		case 1: x = 2; break;
		case 2: x = 3; break;
		case 3: x = 4; break;
		case 4: x = 5; break;
		case 5: x = 6; break;
		case 6: x = 7; break;
		case 7: x = 8; break;
		case 8: x = 9; break;
		case 9: x = 10; break;
		case 10: x = 11; break;
		case 11: x = 12; break;
		}
	}
	if (a) *a = x;
	if (b) *b = y;
	}
	return r;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptChkSpace);

typedef struct ScrNameEnt { struct ScrNameEnt *next; int **str; int val; } ScrNameEnt;
int ScriptSearchName(char *s, unsigned int type, int *name)
{
	int ret = -1;
	ScrNameEnt *e;
	int idx;
	if (type < 15) {
		e = *(ScrNameEnt **)(s + type * 8 + 0x98);
		idx = type == 13;
		while (e) {
			if (textCmp(*e->str + idx, name) == 0) {
				ret = e->val;
				break;
			}
			e = e->next;
		}
	}
	return ret;
}

typedef struct { ScrNameEnt *head, *tail; } ScrNL;
int ScriptEntryName(char *s, unsigned int type, ScrTok *tok, int val)
{
	ScrNameEnt *e;
	ScrNameEnt **l;
	if (s == NULL)
		consPrintf(&D_001000F4, &D_001000E0, 0x376, "ScriptEntryName", &D_001001E8);
	if (type < 15) {
		if (ScriptSearchName(s, type, tok->str) >= 0) {
			ScriptCompileError((char *)&D_001001F0, tok, 0x37C);
			return 0;
		}
		e = _memAlloc(12, &D_001000E0, 0x382);
		if (e == NULL)
			consPrintf(&D_001000F4, &D_001000E0, 0x383, "ScriptEntryName", &D_00100218);
		e->next = NULL;
		e->str = (int **)tok;
		e->val = val;
		if (sceKernelGetGPI() & 1)
			consPrintf(&D_00100220, "ScriptEntryName", val);
		if (sceKernelGetGPI() & 1)
			textPrintf(tok->str);
		if (*(ScrNameEnt **)(s + type * 8 + 0x98) == NULL) *(ScrNameEnt **)(s + type * 8 + 0x98) = e;
		if (*(ScrNameEnt **)(s + type * 8 + 0x9C) != NULL) (*(ScrNameEnt **)(s + type * 8 + 0x9C))->next = e;
		*(ScrNameEnt **)(s + type * 8 + 0x9C) = e;
		return 1;
	}
	consPrintf(&D_001000F4, &D_001000E0, 0x395, "ScriptEntryName", &D_0010022C);
	return 1;
}

typedef struct ScrName { struct ScrName *next; } ScrName;
void *memset(void *, int, unsigned int);
extern unsigned char D_001000E0;
typedef struct { ScrName *head; int x4; } ScrNameList;
int ScriptCleanupName(char *s)
{
	unsigned int i;
	ScrName *e, *n;
	for (i = 0; i < 15; i++) {
		e = ((ScrNameList *)(s + 0x98))[i].head;
		while (e) {
			n = e->next;
			_memFree(e, &D_001000E0, 0x3A5);
			e = n;
		}
	}
	memset(s + 0x98, 0, 0x78);
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001001E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001001F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100218);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100220);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_0010022C);

int ScriptEntryVariable(char *s, int type, ScrTok *tok)
{
	ScrVar *v;
	if (s == NULL)
		consPrintf(&D_001000F4, &D_001000E0, 0x3B7, "ScriptEntryVariable", &D_001001E8);
	if (*(int *)(s + 0x24) == 1) return 1;
	{
		v = _memAlloc(16, &D_001000E0, 0x3BC);
		if (v != NULL) {
			switch (type) {
			case 3:
				v->addr = *(int *)(s + 0x38) - 8;
				break;
			case 0:
			case 1:
			case 2:
			case 4:
				v->addr = *(int *)(s + 0x2C) - 16;
				break;
			}
			v->next = NULL;
			v->type = type;
			v->tok = tok;
			if (*(ScrVar **)(s + 0x110) == NULL) *(ScrVar **)(s + 0x110) = v;
			if (*(ScrVar **)(s + 0x114) != NULL) (*(ScrVar **)(s + 0x114))->next = v;
			*(ScrVar **)(s + 0x114) = v;
			return 1;
		} else {
			ScriptCompileError("Error !! : Few memory", tok, 0x3DD);
			return 0;
		}
	}
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptSettleVariable);

int ScriptEnumOperand(int a, ScrOpnd *p)
{
	int n = 0;
	while (p[n].c)
		n++;
	return n;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100278);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001002A8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001002BC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptSequence);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100530);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100540);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100560);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100580);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001005E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100634);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100688);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001006DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100730);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100784);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001007D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_0010082C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100880);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001008D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100928);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_0010097C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001009D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100A24);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100A78);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100ACC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100B20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100B74);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100BC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100C1C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100C70);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100CC4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100D18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100D6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100DC0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100E14);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100E68);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100EC0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100F14);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100F68);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100FBC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptSchedule);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptEvent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptRole);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptCompile);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptCompileInit);

#define SFREE(p, l) if (p) _memFree(p, &D_001000E0, l)
int ScriptCompileTerm(char *s)
{
	int i;
	void *t;
	if (s == NULL)
		consPrintf(&D_001000F4, &D_001000E0, 0xFA8, "ScriptCompileTerm", &D_001001E8);
	if (*(void **)(s + 0x160)) i3dFreeMdl(*(void **)(s + 0x160));
	if (*(void ***)(s + 0x58)) {
		for (i = 0; i < *(int *)(s + 0x60); i++) {
			t = (*(void ***)(s + 0x58))[i * 2];
			(*(void ***)(s + 0x58))[i * 2] = NULL;
			SFREE(t, 0xFB2);
		}
	}
	SFREE(*(void **)(s + 0x28), 0xFB6);
	SFREE(*(void **)(s + 0x34), 0xFB7);
	SFREE(*(void **)(s + 0x40), 0xFB8);
	SFREE(*(void **)(s + 0x4C), 0xFB9);
	SFREE(*(void **)(s + 0x58), 0xFBA);
	SFREE(*(void **)(s + 0x64), 0xFBB);
	SFREE(*(void **)(s + 0x70), 0xFBC);
	SFREE(*(void **)(s + 0x138), 0xFBE);
	SFREE(*(void **)(s + 0x134), 0xFBF);
	SFREE(*(void **)(s + 0x128), 0xFC0);
	SFREE(*(void **)(s + 0x13C), 0xFC1);
	SFREE(*(void **)(s + 0x140), 0xFC2);
	SFREE(*(void **)(s + 0x148), 0xFC3);
	SFREE(*(void **)(s + 0x158), 0xFC5);
	*(void **)(s + 0x138) = NULL;
	*(void **)(s + 0x134) = NULL;
	*(void **)(s + 0x128) = NULL;
	*(void **)(s + 0x13C) = NULL;
	*(void **)(s + 0x140) = NULL;
	*(void **)(s + 0x148) = NULL;
	*(void **)(s + 0x28) = NULL;
	*(void **)(s + 0x34) = NULL;
	*(void **)(s + 0x40) = NULL;
	*(void **)(s + 0x4C) = NULL;
	*(void **)(s + 0x58) = NULL;
	*(void **)(s + 0x64) = NULL;
	*(void **)(s + 0x70) = NULL;
	*(void **)(s + 0x158) = NULL;
	_memFree(s, &D_001000E0, 0xFD8);
	return 1;
}

void _ScriptManual(void *arg0) {
    M2C_FIELD(arg0, int *, 0x40) = 2;
    M2C_FIELD(arg0, int *, 0x44) = 0xA;
    if (!(sceKernelGetGPI() & 2)) {
        M2C_FIELD(arg0, int *, 0x40) = 1;
        M2C_FIELD(arg0, int *, 0x3C) = taskMake(arg0, &ProgFrameIn, 0, 0);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101384);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101388);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_0010138C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101398);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013A8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101400);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101404);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101410);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101418);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101420);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101428);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101430);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101438);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101440);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101448);
