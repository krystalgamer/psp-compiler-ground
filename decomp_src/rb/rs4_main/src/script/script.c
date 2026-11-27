/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
int sceKernelGetGPI();                              /* extern */
int taskMake(void *, M2C_UNK *, M2C_UNK, M2C_UNK);  /* extern */
extern unsigned char ProgFrameIn;

typedef struct { int a, b, c, d; } ScrOpnd;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001000E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001000F4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptCompileError);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptWordSearch);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptWordSearchUCS4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100164);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptWordSection);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptChkSpace);

typedef struct ScrNameEnt { struct ScrNameEnt *next; int **str; int val; } ScrNameEnt;
int ScriptSearchName(char *s, unsigned int type, int *name)
{
	int ret = -1;
	ScrNameEnt *e;
	int idx;
	if (type < 15) {
		e = *(ScrNameEnt **)(s + type * 8 + 0x98);
		idx = type == 13;
		while (e) {
			if (textCmp(*e->str + idx, name) == 0) {
				ret = e->val;
				break;
			}
			e = e->next;
		}
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptEntryName);

typedef struct ScrName { struct ScrName *next; } ScrName;
int _memFree();
void *memset(void *, int, unsigned int);
extern unsigned char D_001000E0;
int ScriptCleanupName(char *s)
{
	unsigned int i;
	ScrName *e, *n;
	char *q;
	for (i = 0; i < 15; i++) {
		q = (char *)(i * 8);
		q += (int)s;
		e = *(ScrName **)(q + 0x98);
		while (e) {
			n = e->next;
			_memFree(e, &D_001000E0, 0x3A5);
			e = n;
		}
	}
	memset(s + 0x98, 0, 0x78);
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001001E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001001F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100218);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100220);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_0010022C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptEntryVariable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptSettleVariable);

int ScriptEnumOperand(int a, ScrOpnd *p)
{
	int n = 0;
	char *q;
	while (q = (char *)(n * sizeof(ScrOpnd)), q += (int)p, ((ScrOpnd *)q)->c)
		n++;
	return n;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100278);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001002A8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001002BC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptSequence);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100530);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100540);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100560);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100580);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001005E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100634);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100688);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001006DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100730);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100784);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001007D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_0010082C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100880);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001008D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100928);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_0010097C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001009D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100A24);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100A78);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100ACC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100B20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100B74);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100BC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100C1C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100C70);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100CC4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100D18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100D6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100DC0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100E14);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100E68);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100EC0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100F14);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100F68);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00100FBC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptSchedule);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptEvent);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptRole);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptCompile);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptCompileInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptCompileTerm);

void _ScriptManual(void *arg0) {
    M2C_FIELD(arg0, int *, 0x40) = 2;
    M2C_FIELD(arg0, int *, 0x44) = 0xA;
    if (!(sceKernelGetGPI() & 2)) {
        M2C_FIELD(arg0, int *, 0x40) = 1;
        M2C_FIELD(arg0, int *, 0x3C) = taskMake(arg0, &ProgFrameIn, 0, 0);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", ScriptTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101384);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101388);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_0010138C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101398);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013A8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_001013F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101400);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101404);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101410);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101418);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101420);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101428);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101430);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101438);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101440);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/script", D_00101448);
