/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_000FF3AC;
extern unsigned char D_000FF3CC;
extern unsigned char D_000FF3E8;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF3AC);

int EventGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FF3CC, &D_000FF3AC, 0xF, "EventGetNum", &D_000FF3E8);
    }
    return M2C_FIELD(arg0, int *, 0x54);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF3CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF3E8);

extern unsigned char D_000FF400, D_000FF428;
int EventSetTask(void *s, int idx, int task)
{
	if (s == NULL || M2C_FIELD(s, int **, 0x134) == NULL) {
		consPrintf(&D_000FF400, "EventSetTask", idx);
		return 0;
	}
	if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x54)) {
		M2C_FIELD(s, int **, 0x134)[idx] = task;
		return 1;
	}
	consPrintf(&D_000FF428, "EventSetTask", idx);
	return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF400);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF428);

extern unsigned char D_000FF400, D_000FF428;
int EventGetTask(void *s, int idx)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x134) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x54))
			return M2C_FIELD(s, int **, 0x134)[idx];
		consPrintf(&D_000FF428, "EventGetTask", idx);
		return 0;
	}
	consPrintf(&D_000FF400, "EventGetTask", idx);
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", EventTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF46C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF470);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF474);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF490);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF494);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF498);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF49C);
