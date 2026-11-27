/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int cusGetKeyName(M2C_UNK, M2C_UNK, int, int, M2C_UNK); /* extern */
extern int D_0011A46C;

extern unsigned char l_tMenuCntx;
M2C_UNK cusGetKeyIndex(M2C_UNK, M2C_UNK, int);      /* extern */
extern unsigned char l_szEdition;
void consPrintf(const char *, ...);
int gameChgGameMode(int);                           /* extern */
M2C_UNK *gameChgModule(M2C_UNK, int);               /* extern */
int menuGetGameMode(M2C_UNK);                       /* extern */
int menuGetModule(M2C_UNK);                         /* extern */
extern unsigned char D_00102EDC;
extern unsigned char D_00103018;
M2C_UNK cardlistRefresh();                          /* extern */
M2C_UNK databaseRefresh();                          /* extern */
M2C_UNK *localeChange(int, int);                    /* extern */
void *localeGetRegionCntx();
typedef struct { int flow[16]; } MenuFlowHd;
int menuGetNextFlowID();

typedef struct { int flow[16]; } MenuFlowHead;

typedef struct { char pad[0x348]; int a; char pad2[0x64C - 0x34C]; int b; } MenuCB;

extern int D_0011A464;

typedef struct { char pad[0x348]; int a; char pad2[0x64C - 0x34C]; int b; } MenuCB2;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", D_00102E94);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", menuGetModule);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", menuGetGameMode);

M2C_UNK *menuGetCntx(void) {
    return &l_tMenuCntx;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", D_00102EDC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", menuFlowInit);

void menuGetFlowID(int arg0) {
    cusSetInst(1);
    cusSetSection(6, (int) &l_szEdition);
    cusGetKeyIndex(6, 0, arg0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", menuGetNextFlowID);

int menuGetFlowName(int arg0, int arg1) {
    int var_v1;

    cusSetInst(1);
    cusSetSection(6, (int) &l_szEdition);
    var_v1 = 0;
    if (cusGetKeyName(6, 0, arg0, arg1, 0x20) == 0) {
        consPrintf("%s : IDOverFlow\n", "menuGetFlowName");
        var_v1 = -2;
    }
    return var_v1;
}

void menuGetFlowIDNum(void) {
    cusSetInst(1);
    cusGetKeyNum(6, (int) &l_szEdition);
}

int menuNextFlow(void)
{
	int n = menuGetNextFlowID();
	int i;
	if (n < 0)
		return n;
	for (i = 15; i != 0; i--)
		((MenuFlowHd *)&l_tMenuCntx)->flow[i] = ((MenuFlowHd *)&l_tMenuCntx)->flow[i - 1];
	((MenuFlowHd *)&l_tMenuCntx)->flow[0] = n;
	return 0;
}

int menuSetNewFlowForce(int a)
{
	int i;
	for (i = 15; i != 0; i--)
		((MenuFlowHead *)&l_tMenuCntx)->flow[i] = ((MenuFlowHead *)&l_tMenuCntx)->flow[i - 1];
	((MenuFlowHead *)&l_tMenuCntx)->flow[0] = a;
	return a;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", menuGuessLastSelect);

M2C_UNK *menuChgModule(void) {
    M2C_UNK *var_s0;
    M2C_UNK *var_v1;
    int temp_v0;
    int temp_v0_2;
    int var_v0;

    consPrintf(&D_00102EDC, "menuChgModule");
    temp_v0 = menuGetModule(-1);
    var_v1 = NULL;
    if (temp_v0 >= 0) {
        var_s0 = gameChgModule(2, temp_v0);
        temp_v0_2 = menuGetGameMode(-1);
        if (temp_v0_2 >= 0) {
            var_v0 = 0;
            if (var_s0 != NULL) {
                var_v0 = gameChgGameMode(temp_v0_2) != 0;
            }
            var_s0 = (M2C_UNK *) var_v0;
        }
        consPrintf(&D_00103018, var_s0);
        var_v1 = var_s0;
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", menuChgResetModule);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", D_00103018);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", menuGosubCardBattle);

int menuIsCardBattle(void)
{
	return ((MenuCB *)&l_tMenuCntx)->a == -1 && ((MenuCB *)&l_tMenuCntx)->b == -1;
}

M2C_UNK *menuReturnCardBattle(void) {
    M2C_UNK *temp_v0;

    consPrintf(&D_00102EDC, "menuReturnCardBattle");
    temp_v0 = gameChgModule(2, D_0011A464);
    consPrintf(&D_00103018, temp_v0);
    return temp_v0;
}

int menuChkCardBattle(void)
{
	return ((MenuCB2 *)&l_tMenuCntx)->a != -1 && ((MenuCB2 *)&l_tMenuCntx)->b != -1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", menuGosubSaruColle);

int menuIsSaruColle(void) {
    return ~D_0011A46C == 0;
}

int *menuReturnSaruColle(void) {
    int *temp_v0;

    consPrintf(&D_00102EDC, "menuReturnSaruColle");
    D_0011A46C = 0;
    temp_v0 = menuChgModule();
    consPrintf(&D_00103018, temp_v0);
    return temp_v0;
}

int menuChkSaruColle(void) {
    return ~D_0011A46C != 0;
}

M2C_UNK *menuChangeLocale(int arg0, int arg1) {
    M2C_UNK *temp_v0;
    unsigned char temp_s0;

    consPrintf(&D_00102EDC, "menuChangeLocale");
    temp_s0 = M2C_FIELD(localeGetRegionCntx(), unsigned char *, 1);
    temp_v0 = localeChange(arg0, arg1);
    if (temp_v0 != temp_s0) {
        cardlistRefresh();
        databaseRefresh();
    }
    consPrintf(&D_00103018, temp_v0);
    return temp_v0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", D_0010308C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", D_00103090);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", D_00103094);
