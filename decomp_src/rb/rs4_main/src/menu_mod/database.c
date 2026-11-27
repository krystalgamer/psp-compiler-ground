/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
extern signed char D_001025CC;
extern signed char D_001026FC;
extern unsigned char D_00102718;
extern signed char D_00102728;

void cardlistCpyTtr2Ucs4(void *, int, int, int); /* extern */
int resGetDatLocal(M2C_UNK, M2C_UNK);               /* extern */
extern int l_nAssortNum;

M2C_UNK _memFree(int, M2C_UNK *, M2C_UNK);          /* extern */
extern unsigned char D_001025E8;
typedef struct { char pad[0x40]; char name[0x20]; char rest[0x60]; } AssortDB;
extern AssortDB *l_patAssortDB;
void *memset(void *s, int c, unsigned int n);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_001025CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_001025E8);

extern int l_anFameList[26];
int ttrGetIndexNum();
int cardlistCpyTtr2Int32();

int databaseFameRefresh(void)
{
	int ttr = resGetDatLocal(1, 0x4F);
	int i;
	if (ttrGetIndexNum(ttr) < 25)
		consPrintf(&D_001025CC, &D_001025E8, 0x28, "databaseFameRefresh", "nMaxFameList >= Profile_Ranking_Num");
	for (i = 0; i < 25; i++)
		l_anFameList[i] = cardlistCpyTtr2Int32(ttr, i + 1);
	l_anFameList[25] = l_anFameList[24] + 1;
	return 1;
}

int databaseAssortNameRefresh(void)
{
	int i;
	for (i = 0; i < l_nAssortNum; i++) {
		memset(l_patAssortDB[i].name, 0, 0x20);
		cardlistCpyTtr2Ucs4(l_patAssortDB[i].name, resGetDatLocal(1, 0x4D), i + 1, 0x20);
	}
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102638);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", databaseInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_001026FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102704);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102718);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102728);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102730);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_0010273C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102740);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102744);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_00102748);

#ifndef NULL
#define NULL ((void *)0)
#endif

int databaseRefresh(void) {
    M2C_UNK *temp_v0;

    temp_v0 = "databaseRefresh";
    consPrintf(&D_001026FC, temp_v0);
    if (l_patAssortDB == 0) {
        consPrintf(&D_001025CC, &D_001025E8, 0x95, temp_v0, &D_00102718);
    }
    databaseFameRefresh();
    databaseAssortNameRefresh();
    consPrintf(&D_00102728, temp_v0);
    return 1;
}

int databaseTerm(void) {
    if (l_patAssortDB != 0) {
        _memFree((int)l_patAssortDB, &D_001025E8, 0xA2);
    }
    l_patAssortDB = 0;
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", databaseChkRankingBattle);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", databaseCalcRanking);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", databaseChkAssort);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_001027E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_001027E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/database", D_001027E8);
