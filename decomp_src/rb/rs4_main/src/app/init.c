/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);

extern unsigned char D_000FDA40, D_000FDA48;
int mainGet_sce_newlib_heap_kb_size(void);
int memInit();
int consInit();
int thrInit();
int fileInit();

extern unsigned char D_000FDA40, D_000FDA48;
void fileTerm(void);
void thrTerm(void);
void consTerm(void);
void memTerm(void);

int initInitSys(int a, int b)
{
	consPrintf(&D_000FDA40, "initInitSys");
	memInit((mainGet_sce_newlib_heap_kb_size() << 10) - 0x80000);
	consInit();
	thrInit();
	fileInit(a, b);
	consPrintf(&D_000FDA48);
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/init", D_000FDA40);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/init", D_000FDA48);

int initTermSys(void)
{
	consPrintf(&D_000FDA40, "initTermSys");
	fileTerm();
	thrTerm();
	consTerm();
	memTerm();
	consPrintf(&D_000FDA48);
	return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/init", initInitApp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/init", initTermApp);
