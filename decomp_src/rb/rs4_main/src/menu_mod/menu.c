/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "../minmax.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int cusGetKeyName(M2C_UNK, M2C_UNK, int, int, M2C_UNK); /* extern */
extern int D_0011A46C;

extern unsigned char l_tMenuCntx;
int cusGetKeyIndex(M2C_UNK, M2C_UNK, int);      /* extern */
extern unsigned char l_szEdition;
void consPrintf(const char *, ...);
int gameChgGameMode(int);                           /* extern */
int gameChgModule(int, int);
extern unsigned char D_00102EDC;
extern unsigned char D_00103018;
M2C_UNK cardlistRefresh();                          /* extern */
M2C_UNK databaseRefresh();                          /* extern */
M2C_UNK *localeChange(int, int);                    /* extern */
void *localeGetRegionCntx();
typedef struct { int flow[16]; } MenuFlowHd;
typedef struct { char name[4]; int module; int mode; } MenuModDB;
extern MenuModDB l_atMenuModuleDB[7];
extern unsigned char D_00102E94;
int strncmp(const char *, const char *, unsigned int);
int sceKernelGetGPI(void);
int thrState(int);
int mainGetThrBack(void);
int *gameGetCntx();
int menuGetNextFlowID(int sel);

typedef struct { int flow[16]; } MenuFlowHead;

typedef struct { char pad[0x348]; int a; char pad2[0x64C - 0x34C]; int b; } MenuCB;

extern int D_0011A464;

typedef struct { char pad[0x348]; int a; char pad2[0x64C - 0x34C]; int b; } MenuCB2;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", D_00102E94);

int menuGetFlowName(int arg0, int arg1);
int menuGetFlowID(int arg0);
int menuNextFlow(int sel);
void cusSetInst(int arg0);
void cusSetSection(int arg0, int arg1);
void cusGetKeyNum(int arg0, int arg1);
int menuIsCardBattle(void);
int menuGetModule(int id)
{
	char name[32];
	unsigned int i;
	MenuModDB *e;
	int r;
	if (id < 0) id = *(int *)&l_tMenuCntx;
	r = menuGetFlowName(id, name);
	if (r < 0) return r;
	for (i = 0; i < 7; i++) {
		e = &l_atMenuModuleDB[i];
		if (strncmp(name, e->name, 4) == 0) return e->module;
	}
	consPrintf(&D_00102E94, "menuGetModule", id);
	return -4;
}

int menuGetGameMode(int id)
{
	char name[32];
	unsigned int i;
	MenuModDB *e;
	int r;
	if (id < 0) id = *(int *)&l_tMenuCntx;
	r = menuGetFlowName(id, name);
	if (r < 0) return r;
	for (i = 0; i < 7; i++) {
		e = &l_atMenuModuleDB[i];
		if (strncmp(name, e->name, 4) == 0) return e->mode < 0 ? -5 : e->mode;
	}
	consPrintf(&D_00102E94, "menuGetGameMode", id);
	return -4;
}

M2C_UNK *menuGetCntx(void) {
    return &l_tMenuCntx;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/menu", D_00102EDC);

extern char l_szResetFlow[], l_szStartFlow[];
extern int l_nResetFlowID, l_nResetFlowGameMode, l_nResetFlowLabel;
void gameEnSoftReset(void);
static inline void _menuPushFlow(int n)
{
	int i;
	for (i = 15; i != 0; i--)
		((MenuFlowHd *)&l_tMenuCntx)->flow[i] = ((MenuFlowHd *)&l_tMenuCntx)->flow[i - 1];
	((MenuFlowHd *)&l_tMenuCntx)->flow[0] = n;
}
int menuFlowInit(void)
{
	int i, id;
	consPrintf(&D_00102EDC, "menuFlowInit");
	for (i = 0; i < 16; i++)
		((MenuFlowHd *)&l_tMenuCntx)->flow[i] = -1;
	consPrintf("%s:%c\n", "menuFlowInit", '[');
	_menuPushFlow(menuGetFlowID(l_szResetFlow));
	if (menuNextFlow(0) < 0)
		consPrintf("cassert : %s %d : %s : %s\n", "src/menu_mod/menu.c", 0x98, "menuFlowInit", "nRet>=0");
	l_nResetFlowID = ((MenuFlowHd *)&l_tMenuCntx)->flow[0];
	l_nResetFlowLabel = menuGetModule(l_nResetFlowID);
	l_nResetFlowGameMode = menuGetGameMode(l_nResetFlowID);
	_menuPushFlow(menuGetFlowID(l_szStartFlow));
	if (menuNextFlow(0) < 0)
		consPrintf("cassert : %s %d : %s : %s\n", "src/menu_mod/menu.c", 0xA1, "menuFlowInit", "nRet>=0");
	gameEnSoftReset();
	consPrintf("}\n");
	return 1;
}

int menuGetFlowID(int arg0) {
    cusSetInst(1);
    cusSetSection(6, (int) &l_szEdition);
    return cusGetKeyIndex(6, 0, arg0);
}

int cusGetIndexNum(int sec, char *key, char *name);
void cusGetStringIndex(int sec, char *key, char *name, int idx, char *buf, int size, const char *def);
int menuGetNextFlowID(int req)
{
	char name[32];
	char buf[32];
	int id = *(int *)&l_tMenuCntx;
	int sel = amin(req, 16);
	int r, num;

	cusSetInst(1);
	cusSetSection(6, (int)&l_szEdition);
	r = menuGetFlowName(id, (int)name);
	if (r < 0)
		return r;
	num = cusGetIndexNum(6, NULL, name);
	if (sel < 0)
		sel = num > 0 ? num - 1 : 0;
	cusGetStringIndex(6, NULL, name, sel, buf, 0x20, "-");
	if (buf[0] == '-') {
		consPrintf("%s : SelectOverFlow : NowFlow=%s Num=%d Req=%d\n", "menuGetNextFlowID", name, num, sel);
		return -3;
	}
	return cusGetKeyIndex(6, NULL, (int)buf);
}

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

int menuNextFlow(int sel)
{
	int n = menuGetNextFlowID(sel);
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

extern int l_nResetFlowID, l_nResetFlowGameMode, l_nResetFlowLabel;
int menuIsSaruColle();
int menuChgResetModule(void)
{
	int n = l_nResetFlowID;
	int i;
	if (n < 0)
		return -1;
	for (i = 15; i != 0; i--)
		((MenuFlowHd *)&l_tMenuCntx)->flow[i] = ((MenuFlowHd *)&l_tMenuCntx)->flow[i - 1];
	((MenuFlowHd *)&l_tMenuCntx)->flow[0] = n;
	gameChgGameMode(l_nResetFlowGameMode);
	if (menuIsCardBattle()) {
		M2C_FIELD(&l_tMenuCntx, int *, 0x348) = 2;
		M2C_FIELD(&l_tMenuCntx, int *, 0x64C) = 1;
	}
	if (menuIsSaruColle())
		M2C_FIELD(&l_tMenuCntx, int *, 0x65C) = 0;
	return l_nResetFlowLabel;
}

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

typedef struct { char pad[0x65C]; int f65C; } MenuCntxS;
int menuGosubSaruColle(void)
{
	int ret = 0;
	consPrintf(&D_00102EDC, "menuGosubSaruColle");
	if (!(sceKernelGetGPI() & 4)) {
		((MenuCntxS *)&l_tMenuCntx)->f65C = -1;
		ret = gameChgModule(2, 7);
		ret = ret && gameChgGameMode(3);
	} else {
		((MenuCntxS *)&l_tMenuCntx)->f65C = 0;
		if (thrState(mainGetThrBack()) == 0) {
			ret = 1;
			gameGetCntx()[0x38 / 4] = -1;
		}
	}
	consPrintf(&D_00103018, ret);
	return ret;
}

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
