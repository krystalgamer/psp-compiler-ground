/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
M2C_UNK semaLock(int);                              /* extern */
extern int GameSema;
M2C_UNK semaUnlock(int);                         /* extern */
extern unsigned char GameData;
M2C_UNK gameOvlProcInst(int, int, int, int, int);   /* extern */
int resGetCurrentInst();
typedef struct { char pad[0x9C]; int mode; int pad2; int player; } GameDataSw;
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameChkChange);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameOvlProcInst);

void gameOvlProcCurrent(int arg0, int arg1, int arg2, int arg3) {
    gameOvlProcInst(resGetCurrentInst(), arg0, arg1, arg2, arg3);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameOvlProcAll);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameTaskTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", _gameTaskProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameTaskProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameTaskMove);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameChgGameMode);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameSetFinish);

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
