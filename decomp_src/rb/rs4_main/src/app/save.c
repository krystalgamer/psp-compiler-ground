/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK _memFree(void *, M2C_UNK *, M2C_UNK);       /* extern */
extern signed char D_000FE460;
extern unsigned char D_000FE498;
extern unsigned char D_000FE4A0;
extern unsigned char D_000FE4BC;
extern unsigned char D_000FE4C8;
extern unsigned char D_000FE4D4;
extern unsigned char D_000FE4E8;

void consPrintf(const char *, ...);
extern unsigned char D_000FE464;
extern unsigned char D_000FE474;

M2C_UNK saveDataInit();

enum { SaveData_Account_Num = 1 };
typedef struct { unsigned char b0 : 1, b1 : 1, rest : 6; } SaveOpt;
typedef struct { char pad[6]; SaveOpt opt[SaveData_Account_Num]; } SaveSub;
typedef struct { char pad[0x20]; SaveSub sub; } SaveData;
unsigned char *localeGetCntx(void);
M2C_UNK saveDataInit(p)
unsigned char *p;
{
	unsigned char *l;
	int i;
	memset(p, 0, 0x14B0);
	l = localeGetCntx();
	p[0x1C] = l[2];
	p[0x1D] = l[3];
	p[0x14] = l[0];
	p[0x15] = l[1];
	for (i = 0; i < SaveData_Account_Num; i++)
		((SaveData *)p)->sub.opt[i].b1 = l[0xC] & 1;
}

extern unsigned char D_000FE490;
void *_memAllocZero(int, void *, int);
typedef struct { int num; int size; int f8; char *data; } SaveCntx;
SaveCntx *saveInit(int n)
{
	SaveCntx *c;
	int i;
	consPrintf(&D_000FE460, "saveInit");
	if (n <= 0)
		consPrintf(&D_000FE474, &D_000FE464, 0x40, "saveInit", &D_000FE490);
	c = _memAllocZero(16, &D_000FE464, 0x43);
	if (c == NULL)
		consPrintf(&D_000FE474, &D_000FE464, 0x44, "saveInit", &D_000FE498);
	c->num = n;
	c->f8 = 0;
	c->size = n * 0x14B0;
	c->data = _memAllocZero(n * 0x14B0, &D_000FE464, 0x4C);
	if (c->data == NULL)
		consPrintf(&D_000FE474, &D_000FE464, 0x4D, "saveInit", &D_000FE4A0);
	for (i = 0; i < n; i++)
		saveDataInit(c->data + i * 0x14B0, i);
	return c;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE460);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE464);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE474);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE490);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE498);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4A0);

#ifndef NULL
#define NULL ((void *)0)
#endif

int saveTerm(void *arg0) {
    M2C_UNK *temp_v0;

    temp_v0 = "saveTerm";
    consPrintf(&D_000FE460, temp_v0);
    if (arg0 == NULL) {
        consPrintf(&D_000FE474, &D_000FE464, 0x60, temp_v0, &D_000FE498);
    }
    if (M2C_FIELD(arg0, int *, 0) == 0) {
        consPrintf(&D_000FE474, &D_000FE464, 0x61, temp_v0, &D_000FE4BC);
    }
    if (M2C_FIELD(arg0, int *, 4) == 0) {
        consPrintf(&D_000FE474, &D_000FE464, 0x62, temp_v0, &D_000FE4C8);
    }
    if (M2C_FIELD(arg0, int *, 8) != 0) {
        consPrintf(&D_000FE474, &D_000FE464, 0x63, temp_v0, &D_000FE4D4);
    }
    if (M2C_FIELD(arg0, void **, 0xC) == NULL) {
        consPrintf(&D_000FE474, &D_000FE464, 0x64, temp_v0, &D_000FE4A0);
    }
    if (M2C_FIELD(arg0, int *, 4) != (M2C_FIELD(arg0, int *, 0) * 0x14B0)) {
        consPrintf(&D_000FE474, &D_000FE464, 0x65, temp_v0, &D_000FE4E8);
    }
    _memFree(M2C_FIELD(arg0, void **, 0xC), &D_000FE464, 0x67);
    _memFree(arg0, &D_000FE464, 0x68);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE4E8);

extern unsigned char D_000FE524, D_000FE530, D_000FE544;
typedef struct { int d[0x14B0 / 4]; } SaveBlk;

int dencEncode(void *, int, int);
int saveSetData(SaveCntx *c, int idx, int key, SaveBlk *in)
{
	SaveBlk tmp;
	int r;
	if (c == NULL)
		consPrintf(&D_000FE474, &D_000FE464, 0x76, "saveSetData", &D_000FE498);
	if (c->num == 0)
		consPrintf(&D_000FE474, &D_000FE464, 0x77, "saveSetData", &D_000FE4BC);
	if (c->size == 0)
		consPrintf(&D_000FE474, &D_000FE464, 0x78, "saveSetData", &D_000FE4C8);
	if (c->f8 != 0)
		consPrintf(&D_000FE474, &D_000FE464, 0x79, "saveSetData", &D_000FE4D4);
	if (c->data == NULL)
		consPrintf(&D_000FE474, &D_000FE464, 0x7A, "saveSetData", &D_000FE4A0);
	if (c->size != c->num * 0x14B0)
		consPrintf(&D_000FE474, &D_000FE464, 0x7B, "saveSetData", &D_000FE4E8);
	if (idx < 0)
		consPrintf(&D_000FE474, &D_000FE464, 0x7D, "saveSetData", &D_000FE524);
	if (idx >= c->num)
		consPrintf(&D_000FE474, &D_000FE464, 0x7E, "saveSetData", &D_000FE530);
	if (in == NULL)
		consPrintf(&D_000FE474, &D_000FE464, 0x7F, "saveSetData", &D_000FE544);
	tmp = *in;
	r = dencEncode(&tmp, 0x14B0, key);
	((SaveBlk *)c->data)[idx] = tmp;
	return r;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE524);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE530);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE544);

int dencDecode(void *, int, int);
int saveGetData(SaveCntx *c, int idx, int key, SaveBlk *out)
{
	SaveBlk tmp;
	int r;
	if (c == NULL)
		consPrintf(&D_000FE474, &D_000FE464, 0x94, "saveGetData", &D_000FE498);
	if (c->num == 0)
		consPrintf(&D_000FE474, &D_000FE464, 0x95, "saveGetData", &D_000FE4BC);
	if (c->size == 0)
		consPrintf(&D_000FE474, &D_000FE464, 0x96, "saveGetData", &D_000FE4C8);
	if (c->f8 != 0)
		consPrintf(&D_000FE474, &D_000FE464, 0x97, "saveGetData", &D_000FE4D4);
	if (c->data == NULL)
		consPrintf(&D_000FE474, &D_000FE464, 0x98, "saveGetData", &D_000FE4A0);
	if (c->size != c->num * 0x14B0)
		consPrintf(&D_000FE474, &D_000FE464, 0x99, "saveGetData", &D_000FE4E8);
	if (idx < 0)
		consPrintf(&D_000FE474, &D_000FE464, 0x9B, "saveGetData", &D_000FE524);
	if (idx >= c->num)
		consPrintf(&D_000FE474, &D_000FE464, 0x9C, "saveGetData", &D_000FE530);
	if (out == NULL)
		consPrintf(&D_000FE474, &D_000FE464, 0x9D, "saveGetData", &D_000FE544);
	tmp = ((SaveBlk *)c->data)[idx];
	r = dencDecode(&tmp, 0x14B0, key);
	*out = tmp;
	return r;
}

int saveGetCurrentData(void) {
    void *temp_s0;

    temp_s0 = M2C_FIELD(gameGetCntx(), void **, 0x88);
    return M2C_FIELD(temp_s0, int *, 0xC) + (M2C_FIELD(gameGetCntx(), int *, 0x8C) * 0x14B0);
}

int saveGetPlayerCurrentData(int arg0) {
    void *temp_s1;

    temp_s1 = M2C_FIELD(gameGetCntx(), void **, 0x88);
    return M2C_FIELD(temp_s1, int *, 0xC) + (M2C_FIELD(((arg0 * 4) + gameGetCntx()), int *, 0x8C) * 0x14B0);
}

int saveGetAccountData(int arg0) {
    if (arg0 >= 3) {
        consPrintf(&D_000FE474, &D_000FE464, 0xBE, "saveGetAccountData", "Account < SaveData_Account_Num");
    }
    return M2C_FIELD(M2C_FIELD(gameGetCntx(), void **, 0x88), int *, 0xC) + (arg0 * 0x14B0);
}

void saveSetAccount(int arg0, int arg1) {
    M2C_FIELD(((arg0 * 4) + gameGetCntx()), int *, 0x8C) = arg1;
}

void saveCurrentDataInit(void) {
    saveDataInit(saveGetCurrentData(), 0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", saveIsRemainCard);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE58C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE594);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/save", D_000FE59C);
