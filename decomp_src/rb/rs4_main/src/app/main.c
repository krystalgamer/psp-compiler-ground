/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
extern int sce_newlib_heap_kb_size;
extern int sce_newlib_stack_kb_size;
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
int sceMpegInit();                                  /* extern */
int semaInit(M2C_UNK *);                            /* extern */
M2C_UNK thrEntry(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK thrMake(M2C_UNK *, M2C_UNK, M2C_UNK *);     /* extern */
extern unsigned char D_000FDBFC;
extern unsigned char D_000FDC10;
extern unsigned char D_000FDC20;
extern unsigned char D_000FDC3C;
extern unsigned char D_000FDC44;
extern int MovSema;
extern unsigned char ThrMovie;
extern unsigned char movAudio;
int sceMpegFinish();                                /* extern */
int semaTerm(int);                                  /* extern */
M2C_UNK semaLock(int);                              /* extern */
M2C_UNK semaUnlock(int);                            /* extern */

M2C_UNK mainMain(int, M2C_UNK *);                   /* extern */
M2C_UNK sceKernelExitThread(M2C_UNK);               /* extern */
extern int g_argc;
extern unsigned char g_argv;
M2C_UNK gameMain();                                 /* extern */
M2C_UNK initInitApp();                              /* extern */
M2C_UNK initTermApp();                              /* extern */
extern unsigned char ThrMain;
extern unsigned char ThrBack;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", mainSpritArgs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", mainOption);

#ifndef NULL
#define NULL ((void *)0)
#endif

int mainBoot(void) {
    mainMain(g_argc, &g_argv);
    sceKernelExitThread(0);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", mainMain);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mainProc(void) {
    initInitApp();
    gameMain();
    initTermApp();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mainGet_sce_newlib_heap_kb_size(void) {
    return sce_newlib_heap_kb_size;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mainGet_sce_newlib_stack_kb_size(void) {
    return sce_newlib_stack_kb_size;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *mainGetThrMain(void) {
    return &ThrMain;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *mainGetThrBack(void) {
    return &ThrBack;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int movInit(void) {
    int temp_v0;

    if (sceMpegInit() != 0) {
        consPrintf(&D_000FDC20, &D_000FDC10, 0x5F, "movInit", &D_000FDBFC);
    }
    temp_v0 = semaInit(&D_000FDC3C);
    MovSema = temp_v0;
    if (temp_v0 <= 0) {
        consPrintf(&D_000FDC20, &D_000FDC10, 0x63, "movInit", &D_000FDC44);
    }
    thrMake(&ThrMovie, 0x12, &D_000FDC3C);
    thrEntry(&ThrMovie, &movAudio, 0, 0);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDBFC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDC10);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDC20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDC3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDC44);

#ifndef NULL
#define NULL ((void *)0)
#endif

int movTerm(void) {
    if (semaTerm(MovSema) != 1) {
        consPrintf(&D_000FDC20, &D_000FDC10, 0x73, "movTerm", "Ret == TRUE");
    }
    MovSema = -1;
    if (sceMpegFinish() != 0) {
        consPrintf(&D_000FDC20, &D_000FDC10, 0x79, "movTerm", &D_000FDBFC);
    }
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void movLock(void) {
    if (MovSema > 0) {
        semaLock(MovSema);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void movUnlock(void) {
    if (MovSema > 0) {
        semaUnlock(MovSema);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", movPrepare);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", movCleanup);
