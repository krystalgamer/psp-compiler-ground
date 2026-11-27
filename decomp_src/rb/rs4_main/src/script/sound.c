/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_00101B98;
extern unsigned char D_00101BB8;
extern unsigned char D_00101BD4;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101B98);

int SoundGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_00101BB8, &D_00101B98, 0x10, "SoundGetNum", &D_00101BD4);
    }
    return M2C_FIELD(arg0, int *, 0x88);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101BB8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101BD4);

extern unsigned char D_00101BEC, D_00101C14;
int SoundSetTask(void *s, int idx, int task)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x13C) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x88)) {
			M2C_FIELD(s, int **, 0x13C)[idx] = task;
			return 1;
		}
		consPrintf(&D_00101C14, "SoundSetTask", idx);
		return 0;
	}
	consPrintf(&D_00101BEC, "SoundSetTask", idx);
	__asm__ volatile("sync\n\tbreak");
	return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101BEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101C14);

extern unsigned char D_00101BEC, D_00101C14;
int SoundGetTask(void *s, int idx)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x13C) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x88))
			return M2C_FIELD(s, int **, 0x13C)[idx];
		consPrintf(&D_00101C14, "SoundGetTask", idx);
		return 0;
	}
	consPrintf(&D_00101BEC, "SoundGetTask", idx);
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", SoundTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101C58);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101C5C);
