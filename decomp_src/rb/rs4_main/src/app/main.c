#include "common.h"
#include "m2c_macros.h"
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", mainGet_sce_newlib_heap_kb_size);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", mainGet_sce_newlib_stack_kb_size);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", movInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDBFC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDC10);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDC20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDC3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDC44);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", movTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", movLock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", movUnlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", movPrepare);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", movCleanup);
