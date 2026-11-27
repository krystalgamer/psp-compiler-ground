/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
extern int sce_newlib_heap_kb_size;
extern int sce_newlib_stack_kb_size;
                            /* extern */

M2C_UNK mainMain(int, M2C_UNK *);                   /* extern */
M2C_UNK sceKernelExitThread(M2C_UNK);               /* extern */
extern int g_argc;
extern unsigned char g_argv;
M2C_UNK gameMain();                                 /* extern */
M2C_UNK initInitApp();                              /* extern */
M2C_UNK initTermApp();                              /* extern */
extern unsigned char ThrMain;
extern unsigned char ThrBack;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", empty_start);

int empty_stop(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", mainSpritArgs);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDB38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDB44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDB50);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDB54);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", mainOption);

int mainBoot(void) {
    mainMain(g_argc, &g_argv);
    sceKernelExitThread(0);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", mainMain);

void mainProc(void) {
    initInitApp();
    gameMain();
    initTermApp();
}

int mainGet_sce_newlib_heap_kb_size(void) {
    return sce_newlib_heap_kb_size;
}

int mainGet_sce_newlib_stack_kb_size(void) {
    return sce_newlib_stack_kb_size;
}

M2C_UNK *mainGetThrMain(void) {
    return &ThrMain;
}

M2C_UNK *mainGetThrBack(void) {
    return &ThrBack;
}
