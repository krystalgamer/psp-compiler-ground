/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
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
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *);           /* extern */
extern unsigned char D_000FCBE4;
extern unsigned char D_000FCBEC;
extern signed char D_00111688;
extern unsigned char D_000FCC24;
extern int GimDebug;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", _gameTaskProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameTaskProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameTaskMove);

#ifndef NULL
#define NULL ((void *)0)
#endif

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameTaskDraw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameChgGameMode);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameInitArg);

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetGameMode(void) {
    return D_001116AC;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetCapacity(void) {
    return D_001116B0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetEntry(void) {
    return D_001116B4;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetAdvantage(void) {
    return D_001116B8;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetHandicap(void) {
    return D_001116BC;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetDifficult(void) {
    return D_001116C0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameSetResult);

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameSetOsioki(int arg0) {
    D_001116CC = arg0;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameSetOsiokiWinnerHP(int arg0) {
    D_001116D0 = arg0;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameSetOsiokiWinnerBanana(int arg0) {
    D_001116D4 = arg0;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameSetOsiokiWinnerExt(int arg0) {
    D_001116D8 = arg0;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameSetOsiokiLoserHP(int arg0) {
    D_001116DC = arg0;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameSetOsiokiLoserBanana(int arg0) {
    D_001116E0 = arg0;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameSetOsiokiLoserExt(int arg0) {
    D_001116E4 = arg0;
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameSetFinish);

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetWinner(void) {
    return D_001116C4;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetResult);

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetOsioki(void) {
    return D_001116CC;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetOsiokiWinnerHP(void) {
    return D_001116D0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetOsiokiWinnerBanana(void) {
    return D_001116D4;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetOsiokiWinnerExt(void) {
    return D_001116D8;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetOsiokiLoserHP(void) {
    return D_001116DC;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetOsiokiLoserBanana(void) {
    return D_001116E0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetOsiokiLoserExt(void) {
    return D_001116E4;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int gameGetFinish(void) {
    return D_001116E8;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameChgModule);

#ifndef NULL
#define NULL ((void *)0)
#endif

void gameDisSoftReset(void) {
    consPrintf(&D_000FCBC8, &D_000FCBD0);
    D_00111688 = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void gameEnSoftReset(void) {
    consPrintf(&D_000FCBE4, &D_000FCBEC);
    D_00111688 = 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameCtrlLock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameCtrlUnlock);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", D_000FCC24);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gimInit);

#ifndef NULL
#define NULL ((void *)0)
#endif

void gimTerm(void) {
    consPrintf(&D_000FCC24, "gimTerm");
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void gimDebug(int arg0) {
    GimDebug = arg0;
}
