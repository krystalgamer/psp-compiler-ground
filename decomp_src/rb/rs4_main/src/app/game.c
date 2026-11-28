/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#include "../minmax.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
M2C_UNK semaLock(int);                              /* extern */
extern int GameSema;
M2C_UNK semaUnlock(int);                         /* extern */
extern unsigned char GameData;
int resGetCurrentInst();
typedef struct { char pad[0x9C]; int mode; int pad2; int player; } GameDataSw;
typedef struct { int module; int f4; int f8; void *task[2]; } GameInst;
typedef struct { int flags; int f4; int f8; GameInst inst[5]; int f70, f74; unsigned char b78, b79, b7a, b7b; int f7c; int f80; int f84, f88, f8c, f90; int f94; int f98; int mode; int fA0; int player; } GameDataT;
#define G ((GameDataT *)&GameData)
extern unsigned char D_000FC690, D_000FC6AC, D_000FCB74;
void *taskInit(int);
void ctrlSetVirtualType(int);
void taskAllFree(void);
void taskTerm(void *);
void randLoad(int);
void randSave(int);
int taskMove();
int taskDraw();
int gameTaskMove(void *t, int a, int b);
int gameTaskSort();
int gameTaskDraw(int a, int b, int c);
void _gameTaskProc(int inst);
void *taskSwitchCntx(void *);
int resOvlProcInst(int, int, int, int, int);
int thrState(int);
int mainGetThrBack(void);
int taskProc();
void gameSwitchPlayer(int a);
int SaruNet_ResidentData__Is_Server();
void *rsvNextAlive(void *);                         /* extern */
M2C_UNK sortPrio(void *, M2C_UNK, M2C_UNK, M2C_UNK, void **); /* extern */
extern int D_001116AC;
extern int D_001116B0;
extern int D_001116B4;
extern int D_001116B8;
extern int D_001116BC;
extern int D_001116C0;
extern int D_001116E8;
extern unsigned char D_000FCBC8;
extern unsigned char D_000FCBD0;

extern int D_001116C4;
extern int D_001116C8;
extern int D_001116CC;
extern int D_001116D0;
extern int D_001116D4;
extern int D_001116D8;
extern int D_001116DC;
extern int D_001116E0;
extern int D_001116E4;
void consPrintf(const char *, ...);
extern unsigned char D_000FCBE4;
extern unsigned char D_000FCBEC;
extern signed char D_00111688;

extern unsigned char GameData;
extern const float D_000FCC1C, D_000FCC20;

extern unsigned char D_000FCBFC;
typedef struct { int f0, f4, f8; } GameDataHd;

extern unsigned char D_000FCC0C;
typedef struct { int f0, f4, f8; } GameDataHd2;

M2C_UNK *viewGetDefault(void);
M2C_UNK *gameGetCntx(void) {
    return &GameData;
}

void gameLock(void) {
    if (GameSema > 0) {
        semaLock(GameSema);
    }
}

void gameUnlock(void) {
    if (GameSema > 0) {
        semaUnlock(GameSema);
    }
}

int gameChkChange(void)
{
	int cur = resGetCurrentInst();
	int i;
	int n;

	for (i = 0; i <= cur; i++) {
		n = G->inst[i].f4;
		if (G->inst[i].module != n) {
			G->inst[i].f4 = amax(n, 0);
			break;
		}
	}
	return i > cur ? -1 : cur;
}

void gameSwitchPlayer(int a)
{
	GameDataSw *g = (GameDataSw *)&GameData;
	if (g->mode != 2)
		g->player = a;
	else
		g->player = !SaruNet_ResidentData__Is_Server();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameMain);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameProc);

int gameOvlProcInst(int inst, int a, int b, int c, int d)
{
	GameDataT *g = (GameDataT *)&GameData;
	int save = g->player;
	void *old = taskSwitchCntx(0);
	unsigned int j;
	void *t;
	for (j = 0; j < 2; j++) {
		t = ((GameDataT *)&GameData)->inst[inst].task[j];
		if (t != NULL) {
			gameSwitchPlayer(j);
			taskSwitchCntx(t);
			resOvlProcInst(inst, a, b, c, d);
		}
	}
	taskSwitchCntx(old);
	((GameDataT *)&GameData)->player = save;
	return 1;
}

void gameOvlProcCurrent(int arg0, int arg1, int arg2, int arg3) {
    gameOvlProcInst(resGetCurrentInst(), arg0, arg1, arg2, arg3);
}

void gameOvlProcAll(int a, int b, int c, int d)
{
	int i;
	int n = resGetCurrentInst();
	for (i = 0; i <= n; i++)
		gameOvlProcInst(i, a, b, c, d);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC690);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC6AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC6BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC6C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC6D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC6FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC71C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC73C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC75C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC77C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC79C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC7B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC7DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC7FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC81C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC83C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC85C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC87C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC898);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC8B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC8D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC8E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC904);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC91C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC938);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC958);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC98C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC9B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FC9E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCA18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCA48);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCA74);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCAA0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCAC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCAD4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCB24);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameTaskInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCB74);

int gameTaskTerm(void)
{
	int inst = resGetCurrentInst();
	int save = G->player;
	void *old = taskSwitchCntx(0);
	unsigned int j;
	void *t;
	for (j = 0; j < 2; j++) {
		t = G->inst[inst].task[j];
		if (t != NULL) {
			gameSwitchPlayer(j);
			taskSwitchCntx(t);
			taskAllFree();
			taskTerm(t);
			G->inst[inst].task[j] = NULL;
		}
	}
	switch (G->mode) {
	case 0:
	case 1:
	case 3:
	case 4:
		break;
	case 2:
		ctrlSetVirtualType(0);
		break;
	}
	taskSwitchCntx(old);
	G->player = save;
	return 1;
}

void _gameTaskProc(int inst)
{
	unsigned int j;
	void *t;
	for (j = 0; j < 2; j++) {
		t = G->inst[inst].task[j];
		if (t != NULL) {
			randLoad(j);
			gameSwitchPlayer(j);
			taskSwitchCntx(t);
			resOvlProcInst(inst, 0, 14, 0, 0);
			taskMove(gameTaskMove, 0, 0, 0);
			resOvlProcInst(inst, 0, 15, 0, 0);
			if (G->b79 == 1)
				taskDraw(gameTaskSort, gameTaskDraw, 0, 0);
			resOvlProcInst(inst, 0, 16, 0, 0);
			randSave(j);
		}
	}
}

int gameTaskProc(void)
{
	int i, n;
	randSave(0);
	randSave(1);
	switch (D_001116AC) {
	case 0:
	case 1:
	case 3:
	case 4:
	default:
		n = resGetCurrentInst();
		for (i = 0; i <= n; i++)
			_gameTaskProc(i);
		break;
	case 2:
		for (i = resGetCurrentInst(); i >= 0; i--)
			_gameTaskProc(i);
		break;
	}
	return 1;
}

int gameTaskMove(void *t, int a, int b)
{
	int f = ((GameDataT *)&GameData)->flags;
	if (*(int *)((char *)t + 0x2C) & f)
		taskProc(t, 14, a, b);
	else
		taskProc(t, 2, a, b);
	return 0;
}

int gameTaskSort(void **arg0, void *arg1, int *arg2) {
    int *var_v0;
    int temp_s2;
    void *temp_v0;
    void *temp_v0_2;
    void *var_s0;

    var_v0 = arg2;
    var_s0 = arg1;
    if (arg2 == NULL) {
        var_v0 = viewGetDefault();
    }
    temp_s2 = M2C_FIELD(var_v0, int *, 8);
    if (var_s0 != NULL) {
        do {
            if (M2C_FIELD(var_s0, int *, 0x28) & temp_s2) {
                temp_v0_2 = *arg0;
                *arg0 = var_s0;
                M2C_FIELD(var_s0, void **, 0x20) = temp_v0_2;
            }
            temp_v0 = rsvNextAlive(var_s0);
            var_s0 = temp_v0;
        } while (temp_v0 != NULL);
    }
    sortPrio(*arg0, 0x24, 0x20, 0x20, arg0);
    return 0;
}

int gameTaskDraw(int a, int b, int c)
{
	taskProc(a, 3, b, c);
	return 0;
}

int gameChgGameMode(int mode)
{
	if (thrState(mainGetThrBack()) != 0) return 0;
	G->f94 = mode;
	G->f98 = resGetCurrentInst();
	switch (mode) {
	default:
		consPrintf(&D_000FC690, &D_000FC6AC, 0x355, "gameChgGameMode", &D_000FCB74);
		break;
	case 0:
	case 3:
	case 4:
		G->f80 = 0;
		break;
	case 2:
		G->f80 = 1;
		break;
	case 1:
		G->f80 = 2;
		break;
	}
	return 1;
}

void gameInitArg(void)
{
	int *p = (int *)&GameData;
	p[0xB4 / 4] = p[0xAC / 4];
}

int gameGetGameMode(void) {
    return D_001116AC;
}

int gameGetCapacity(void) {
    return D_001116B0;
}

int gameGetEntry(void) {
    return D_001116B4;
}

int gameGetAdvantage(void) {
    return D_001116B8;
}

int gameGetHandicap(void) {
    return D_001116BC;
}

int gameGetDifficult(void) {
    return D_001116C0;
}

int gameSetWinner(int arg0) {
    D_001116C4 = arg0;
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCBC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCBD0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCBE4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCBEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCBFC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCC0C);

/* gameSetResult/gameGetResult constants (the original's float pool lies here) */
__asm__(".section .rodata\n.align 2\n.globl D_000FCC1C\nD_000FCC1C: .float 256\n.globl D_000FCC20\nD_000FCC20: .float 0.00390625\n.previous");

int gameSetResult(float f)
{
	D_001116C8 = f * D_000FCC1C;
	return 1;
}

int gameSetOsioki(int arg0) {
    D_001116CC = arg0;
    return 1;
}

int gameSetOsiokiWinnerHP(int arg0) {
    D_001116D0 = arg0;
    return 1;
}

int gameSetOsiokiWinnerBanana(int arg0) {
    D_001116D4 = arg0;
    return 1;
}

int gameSetOsiokiWinnerExt(int arg0) {
    D_001116D8 = arg0;
    return 1;
}

int gameSetOsiokiLoserHP(int arg0) {
    D_001116DC = arg0;
    return 1;
}

int gameSetOsiokiLoserBanana(int arg0) {
    D_001116E0 = arg0;
    return 1;
}

int gameSetOsiokiLoserExt(int arg0) {
    D_001116E4 = arg0;
    return 1;
}

typedef struct { int a, b, c, cur, next; } GameEnt2;
extern int D_001116E8;
void *taskHeadAlive();
void *rsvNextAlive();
unsigned int sceKernelGetGPI(void);
int gameSetFinish(int f)
{
	int n = resGetCurrentInst();
	char *t;
	if (sceKernelGetGPI() & 4)
		((GameEnt2 *)&GameData)[n].next = -1;
	else
		((GameEnt2 *)&GameData)[n].cur = 0;
	D_001116E8 = f;
	for (t = taskHeadAlive(); t; t = rsvNextAlive(t))
		*(int *)(t + 0x28) = 0;
	return 1;
}

int gameGetWinner(void) {
    return D_001116C4;
}

float gameGetResult(void)
{
	return D_001116C8 * D_000FCC20;
}

int gameGetOsioki(void) {
    return D_001116CC;
}

int gameGetOsiokiWinnerHP(void) {
    return D_001116D0;
}

int gameGetOsiokiWinnerBanana(void) {
    return D_001116D4;
}

int gameGetOsiokiWinnerExt(void) {
    return D_001116D8;
}

int gameGetOsiokiLoserHP(void) {
    return D_001116DC;
}

int gameGetOsiokiLoserBanana(void) {
    return D_001116E0;
}

int gameGetOsiokiLoserExt(void) {
    return D_001116E4;
}

int gameGetFinish(void) {
    return D_001116E8;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameChgModule);

void gameDisSoftReset(void) {
    consPrintf(&D_000FCBC8, &D_000FCBD0);
    D_00111688 = 0;
}

void gameEnSoftReset(void) {
    consPrintf(&D_000FCBE4, &D_000FCBEC);
    D_00111688 = 1;
}

void gameCtrlLock(void)
{
	consPrintf(&D_000FCBC8, &D_000FCBFC);
	((GameDataHd *)&GameData)->f4 |= 0x40;
}

void gameCtrlUnlock(void)
{
	((GameDataHd2 *)&GameData)->f8 |= 0x40;
	consPrintf(&D_000FCBE4, &D_000FCC0C);
}
