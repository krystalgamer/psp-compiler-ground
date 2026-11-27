/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_000FF2BC;
extern unsigned char D_000FF2E0;
extern unsigned char D_000FF2FC;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF2BC);

int EffectGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FF2E0, &D_000FF2BC, 0x22, "EffectGetNum", &D_000FF2FC);
    }
    return M2C_FIELD(arg0, int *, 0x8C);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF2E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF2FC);

extern unsigned char D_000FF314, D_000FF33C;
int EffectSetTask(void *s, int idx, int task)
{
	if (s == NULL || M2C_FIELD(s, int **, 0x140) == NULL) {
		consPrintf(&D_000FF314, "EffectSetTask", idx);
		return 0;
	}
	if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x8C)) {
		M2C_FIELD(s, int **, 0x140)[idx] = task;
		return 1;
	}
	consPrintf(&D_000FF33C, "EffectSetTask", idx);
	return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF314);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF33C);

extern unsigned char D_000FF314, D_000FF33C;
int EffectGetTask(void *s, int idx)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x140) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x8C))
			return M2C_FIELD(s, int **, 0x140)[idx];
		consPrintf(&D_000FF33C, "EffectGetTask", idx);
		return 0;
	}
	consPrintf(&D_000FF314, "EffectGetTask", idx);
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", EffectTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF380);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF384);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF388);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF38C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF394);
