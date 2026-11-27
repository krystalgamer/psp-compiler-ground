/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/notice", D_000FF5E0);

extern unsigned char D_000FF5E0, D_000FF61C;
float NoticeGetVariable(void *s, int idx)
{
	if (s != NULL && M2C_FIELD(s, float **, 0x64) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x6C))
			return M2C_FIELD(s, float **, 0x64)[idx];
		consPrintf(&D_000FF61C, "NoticeGetVariable", idx);
		return 0.0f;
	}
	consPrintf(&D_000FF5E0, "NoticeGetVariable", idx);
	return 0.0f;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/notice", D_000FF61C);

extern unsigned char D_000FF5E0, D_000FF61C;
int NoticeSetVariable(void *s, int idx, float v)
{
	if (s != NULL && M2C_FIELD(s, float **, 0x64) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x6C)) {
			M2C_FIELD(s, float **, 0x64)[idx] = v;
			return 1;
		}
		consPrintf(&D_000FF61C, "NoticeSetVariable", idx);
		return 0;
	}
	consPrintf(&D_000FF5E0, "NoticeSetVariable", idx);
	return 0;
}
