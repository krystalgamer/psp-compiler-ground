#include "common.h"
#include "m2c_macros.h"
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameTaskSort);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameTaskDraw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameChgGameMode);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameInitArg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetGameMode);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetCapacity);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetEntry);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetAdvantage);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetHandicap);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetDifficult);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetWinner);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetResult);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetOsioki);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetOsiokiWinnerHP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetOsiokiWinnerBanana);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetOsiokiWinnerExt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetOsiokiLoserHP);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetOsiokiLoserBanana);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetOsiokiLoserExt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameGetFinish);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameChgModule);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/game", gameDisSoftReset);

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
