/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_000FF7F4;
extern unsigned char D_000FF81C;
extern unsigned char D_000FF838;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF7F4);

int ProgramGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FF81C, &D_000FF7F4, 0x16, "ProgramGetNum", &D_000FF838);
    }
    return M2C_FIELD(arg0, int *, 0x94);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF81C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF838);

extern unsigned char D_000FF850, D_000FF878;
int ProgramSetTask(void *s, int idx, int task)
{
	if (s == NULL || M2C_FIELD(s, int **, 0x148) == NULL) {
		consPrintf(&D_000FF850, "ProgramSetTask", idx);
		return 0;
	}
	if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x94)) {
		M2C_FIELD(s, int **, 0x148)[idx] = task;
		return 1;
	}
	consPrintf(&D_000FF878, "ProgramSetTask", idx);
	return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF850);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF878);

extern unsigned char D_000FF850, D_000FF878;
int ProgramGetTask(void *s, int idx)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x148) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x94))
			return M2C_FIELD(s, int **, 0x148)[idx];
		consPrintf(&D_000FF878, "ProgramGetTask", idx);
		return 0;
	}
	consPrintf(&D_000FF850, "ProgramGetTask", idx);
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", ProgramTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF8BC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF8C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF8C4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF8CC);
