/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
extern int sce_newlib_heap_kb_size;
extern int sce_newlib_stack_kb_size;
                            /* extern */

int mainMain(int argc, char **argv);
M2C_UNK sceKernelExitThread(M2C_UNK);               /* extern */
extern int g_argc;
extern char *g_argv[16];
M2C_UNK gameMain();                                 /* extern */
M2C_UNK initInitApp();                              /* extern */
M2C_UNK initTermApp();                              /* extern */
extern unsigned char ThrMain;
extern unsigned char ThrBack;
void consPrintf(const char *, ...);
int strcmp(const char *, const char *);
int atoi(const char *);
int *gameGetCntx();
extern unsigned char D_000FDB38, D_000FDB44, D_000FDB50, D_000FDB54;
int sceKernelGetThreadId(void);
int sceKernelReferThreadStatus(int, void *);
int sceKernelCreateThread(const char *, void *, int, int, int, void *);
int sceKernelStartThread(int, int, void *);
int mainBoot(void);

void mainSpritArgs(int len, char *p);
int empty_start(int len, char *args)
{
	int info[0x6C / 4];
	int i;
	consPrintf("\n\n\n\n\n\n\n\n\n\n\n-- %s %08x\n\n", "empty_start", 0x2070110);
	mainSpritArgs(len, args);
	consPrintf(&D_000FDB38, g_argc);
	for (i = 0; i < g_argc; i++)
		consPrintf(&D_000FDB44, i, g_argv[i]);
	consPrintf(&D_000FDB50);
	info[0] = 0x6C;
	sceKernelReferThreadStatus(sceKernelGetThreadId(), info);
	sceKernelStartThread(sceKernelCreateThread((char *)&D_000FDB54, mainBoot, info[0x40 / 4], info[0x34 / 4], 0, 0), 0, 0);
	return 0;
}

int empty_stop(void) {
    return 0;
}

void mainSpritArgs(int len, char *p)
{
	char *end = p + len;
	g_argc = 0;
	g_argv[0] = 0;
	while (g_argc < 16 && p < end) {
		g_argv[g_argc++] = p;
		while (*p++) ;
	}
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDB38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDB44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDB50);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/main", D_000FDB54);

void mainOption(int argc, char **argv)
{
	int i;
	int *c;
	for (i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-n") == 0) {
			i++;
			c = gameGetCntx();
			c[0x74 / 4] = atoi(argv[i]);
			consPrintf("nid = %d\n", gameGetCntx()[0x74 / 4]);
		}
	}
}

int mainBoot(void) {
    mainMain(g_argc, g_argv);
    sceKernelExitThread(0);
    return 0;
}

void sceKernelDelayThread(int);
int sceDemoStart(int, char **);
int sceDemoEnd(void);
void sceKernelSetGPO(int);
int sceKernelWaitThreadEndCB(int, void *);
int thrMake(void *, int, const char *);
int thrEntry(void *, void *, int, int);
int initInitSys(int, int);
int initTermSys(void);
void mainProc(void);
/* STAND-IN (likely): one asm block with $6 as scratch (thrProc has the same block);
   separate cfc1/ins/ctc1 statements allocate other registers. */
static inline void _mainFpuInit(int rm)
{
	__asm__ volatile("cfc1 $6, $31\n\tins $6, %0, 0, 2\n\tins $6, $0, 7, 5\n\tctc1 $6, $31" : : "r"(rm) : "$6");
}
static inline void _mainPrintArgs(int argc, char **argv)
{
	int i;
	consPrintf((char *)&D_000FDB38, argc);
	for (i = 0; i < argc; i++)
		consPrintf((char *)&D_000FDB44, i, argv[i]);
	consPrintf((char *)&D_000FDB50);
}
int mainMain(int argc, char **argv)
{
	consPrintf("\n-- %s %08x\n\n", "mainMain", 0x2070110);
	sceKernelDelayThread(3000000);
	sceDemoStart(argc, argv);
	if (argv[0]) argv[0] = "host0:../../main.prx";
	_mainFpuInit(1);
	sceKernelSetGPO(0);
	_mainPrintArgs(0, NULL);
	mainOption(0, 0);
	initInitSys(0, 0);
	thrMake(&ThrMain, 0x13, "Main");
	thrMake(&ThrBack, 0x14, "Back");
	thrEntry(&ThrMain, mainProc, 0, 0);
	if (sceKernelWaitThreadEndCB(*(int *)&ThrMain, 0) < 0)
		consPrintf("cassert : %s %d : %s : %s\n", "src/app/main.c", 0xDE, "mainMain", "Ret >= 0");
	initTermSys();
	consPrintf("\n-- term\n\n");
	sceKernelDelayThread(3000000);
	sceDemoEnd();
	sceKernelDelayThread(3000000);
	return 0;
}

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
