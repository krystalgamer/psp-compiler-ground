/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#include "../minmax.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_00103854;
extern unsigned char D_00103870;
extern unsigned char D_001038A4;
extern unsigned char D_001038B0;
int salbumCalcCardNumBySaveID(int, int, int, int);
int salbumClearNewFlagBySaveID();

                           /* extern */

int cardlistGetSaveID(int arg0);
int salbumCalcKinds(int *p)
{
	int (*k)[3] = (int (*)[3])p;
	int n = 0;
	int i, j;
	for (i = 0xFF; i >= 0; i--) {
		for (j = 0; j < 3; j++) {
			n += (unsigned int)((k[i][j] & 0x7F) - 1) < 0x7E;
		}
	}
	p[0x300] = n;
	return n;
}

typedef struct { unsigned int num : 7, isnew : 1, rest : 24; } SalbumEnt0;
int salbumCalcKindsContainLostCard(SalbumEnt0 *p)
{
	SalbumEnt0 (*k)[3] = (SalbumEnt0 (*)[3])p;
	int n = 0;
	int i, j;
	for (i = 0xFF; i >= 0; i--) {
		for (j = 0; j < 3; j++) {
			if (k[i][j].num > 0)
				n++;
		}
	}
	return n;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", D_00103854);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", D_00103870);

int salbumGetCardDupBySaveID(int arg0, unsigned int arg1, int arg2, int *arg3, int *arg4) {
    int *temp_v1;
    int temp_a3;

    if (arg0 == 0) {
        consPrintf(&D_00103854, &D_00103870, 0x35, "salbumGetCardDupBySaveID", &D_001038A4);
    }
    if ((arg1 < 0x100U) & (arg2 < 3)) {
        temp_v1 = (((arg1 * 3) + arg2) * 4) + arg0;
        temp_a3 = *temp_v1 & 0x7F;
        if (arg3 != NULL) {
            *arg3 = temp_a3 == 0x7F;
        }
        if (arg4 != NULL) {
            *arg4 = __builtin_allegrex_ext(*temp_v1, 7, 1);
        }
        return ((temp_a3 ^ 0x7F) == 0) ? 0 : temp_a3;
    }
    if (arg3 != NULL) {
        *arg3 = 0;
    }
    if (arg4 != NULL) {
        *arg4 = 0;
    }
    return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", D_001038A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", D_001038B0);

void salbumGetCardDup(int arg0, void *arg1, int arg2, int arg3) {
    if (arg1 == NULL) {
        consPrintf(&D_00103854, &D_00103870, 0x4E, "salbumGetCardDup", &D_001038B0);
    }
    salbumGetCardDupBySaveID(arg0, cardlistGetSaveID((int) M2C_FIELD(arg1, unsigned short *, 2)), M2C_FIELD(arg1, unsigned char *, 0), arg2, arg3);
}

typedef struct { unsigned int num : 7; unsigned int new : 1; } SalCard;
int salbumCalcCardNumBySaveID(int p, int id, int kind, int add)
{
	SalCard (*tbl)[3] = (SalCard (*)[3])p;
	int c, n, o, ret;

	if (tbl == NULL)
		consPrintf(&D_00103854, &D_00103870, 0x5D, "salbumCalcCardNumBySaveID", &D_001038A4);
	if ((unsigned int)id >= 256 || kind >= 3)
		return -1;
	if (add > 0) {
		c = tbl[id][kind].num;
		if (c == 0 || c == 0x7F)
			tbl[id][kind].new = 1;
		tbl[id][kind].num = amin(c != 0x7F ? c + add : add, 9);
	} else if (add < 0) {
		n = tbl[id][kind].num;
		o = n;
		if (n != 0 && n != 0x7F)
			n += add;
		n = amax(n, 0);
		if (n == 0 && o != 0x7F)
			n = 0x7F;
		tbl[id][kind].num = n;
	}
	ret = tbl[id][kind].num;
	return ret == 0x7F ? 0 : ret;
}

void salbumCalcCardNum(int arg0, void *arg1, int arg2) {
    if (arg1 == NULL) {
        consPrintf(&D_00103854, &D_00103870, 0x87, "salbumCalcCardNum", &D_001038B0);
    }
    salbumCalcCardNumBySaveID(arg0, cardlistGetSaveID((int) M2C_FIELD(arg1, unsigned short *, 2)), M2C_FIELD(arg1, unsigned char *, 0), arg2);
}

typedef struct { unsigned int num : 7, isnew : 1, rest : 24; } SalbumEnt;
extern unsigned char D_00103854, D_00103870, D_001038A4;
int salbumClearNewFlagBySaveID(SalbumEnt *p, unsigned int id, int kind)
{
	int r;
	if (p == NULL)
		consPrintf(&D_00103854, &D_00103870, 0x95, "salbumClearNewFlagBySaveID", &D_001038A4);
	if (id >= 256 || kind >= 3)
		return -1;
	r = p[id * 3 + kind].isnew;
	p[id * 3 + kind].isnew = 0;
	return r;
}

void salbumClearNewFlag(int arg0, void *arg1) {
    if (arg1 == NULL) {
        consPrintf(&D_00103854, &D_00103870, 0xA6, "salbumClearNewFlag", &D_001038B0);
    }
    salbumClearNewFlagBySaveID(arg0, cardlistGetSaveID((int) M2C_FIELD(arg1, unsigned short *, 2)), M2C_FIELD(arg1, unsigned char *, 0));
}

int salbumTouchCardBySaveID(int arg0, unsigned int arg1, int arg2) {
    int *temp_v1;
    int temp_v0;
    int var_a1;

    if (arg0 == 0) {
        consPrintf(&D_00103854, &D_00103870, 0xB6, "salbumTouchCardBySaveID", &D_001038A4);
    }
    var_a1 = -1;
    temp_v1 = (((arg1 * 3) + arg2) * 4) + arg0;
    if (((arg1 >= 0x100U) | (arg2 >= 3)) == 0) {
        temp_v0 = *temp_v1;
        if (!(temp_v0 & 0x7F)) {
            *temp_v1 = temp_v0 | 0x7F;
        }
        var_a1 = *temp_v1 & 0x7F;
    }
    return var_a1;
}

void salbumTouchCard(int arg0, void *arg1) {
    if (arg1 == NULL) {
        consPrintf(&D_00103854, &D_00103870, 0xC7, "salbumTouchCard", &D_001038B0);
    }
    salbumTouchCardBySaveID(arg0, cardlistGetSaveID((int) M2C_FIELD(arg1, unsigned short *, 2)), M2C_FIELD(arg1, unsigned char *, 0));
}

int cardlistGetCardNum();
int salbumGetAll(void *p)
{
	int i;
	int n = cardlistGetCardNum() - 1;
	for (i = 0; i <= n; i++) {
		salbumCalcCardNumBySaveID(p, i, 0, 1);
		salbumCalcCardNumBySaveID(p, i, 1, 1);
		salbumCalcCardNumBySaveID(p, i, 2, 1);
	}
	return 1;
}
