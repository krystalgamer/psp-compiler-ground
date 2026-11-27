/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
                            /* extern */
void consPrintf(const char *, ...);

extern unsigned char D_000FB180, D_000FB19C, D_000FB210;
void *rsvNextAlive();
void consPrintf(const char *, ...);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB180);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB19C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", rsvInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB1C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB1D0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", rsvTerm);

void *rsvHeadAlive(void **arg0) {
    void *p = *arg0;
    int s;
    if (p == NULL) return NULL;
    s = M2C_FIELD(p, int *, 4);
    if (s == 0) {
        consPrintf(&D_000FB180, &D_000FB19C, 0x56, "rsvHeadAlive", &D_000FB210);
    }
    if (s > 0) return p;
    return rsvNextAlive(p);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", D_000FB210);

void *rsvNextAlive(void **p) {
    int s;
    if (p != NULL) {
        while ((p = *p) != NULL) {
            s = ((int *)p)[1];
            if (s == 0) {
                consPrintf(&D_000FB180, &D_000FB19C, 0x67, "rsvNextAlive", &D_000FB210);
            }
            if (s > 0) break;
        }
    }
    return p;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", rsvCall);

int rsvKill(void *arg0) {
    int temp_s0;
    int var_v0;

    temp_s0 = M2C_FIELD(arg0, int *, 4);
    if (temp_s0 == 0) {
        consPrintf(&D_000FB180, &D_000FB19C, 0xA1, "rsvKill", &D_000FB210);
    }
    var_v0 = 0;
    if (temp_s0 > 0) {
        M2C_FIELD(arg0, int *, 4) = (int) ~temp_s0;
        var_v0 = 1;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", rsvFree);

int rsvDummy(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", rsvMove);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/rsv", rsvLoop);

int rsvKeyState(int *p, int k)
{
	if (k <= 0)
		return 1;
	if (!p)
		return 0;
	if ((k ^ p[1]) == 0)
		return 2;
	if ((k ^ p[1]) == -1)
		return 3;
	return 4;
}
