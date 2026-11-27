/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK semaLock(int);                              /* extern */
extern int MemSema;
M2C_UNK semaUnlock(int);                            /* extern */
int consPrintf();
extern void *pAlloc;
extern int pRoot;

void *_memAlloc();                                  /* extern */
extern int MemBreak;


#ifndef NULL
#define NULL ((void *)0)
#endif

void memLock(void) {
    if (MemSema > 0) {
        semaLock(MemSema);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void memUnlock(void) {
    if (MemSema > 0) {
        semaUnlock(MemSema);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int memGetCntxSize(void) {
    return 0x40;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int memGetAlignSize(void) {
    return 0x40;
}

extern unsigned char D_000FB180, D_000FB19C, D_000FB210;
void *rsvNextAlive();

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memLog);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memAlloc);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FADB0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FADB8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FADC4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FADE0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FAE0C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memRealloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memReallocMBL);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void *_memAllocZero(unsigned int arg0) {
    void *temp_v0;

    temp_v0 = _memAlloc();
    if (temp_v0 != NULL) {
        memset(temp_v0, 0, arg0);
    }
    return temp_v0;
}

void *_memAllocMBL(int a, int b, int c)
{
	unsigned char *p = _memAlloc(a, b, c);
	if (p)
		p[-0x2F] = 1;
	return p;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void *_memAllocZeroMBL(unsigned int arg0) {
    void *temp_v0;

    temp_v0 = _memAlloc();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, signed char *, -0x2F) = 1;
        memset(temp_v0, 0, arg0);
    }
    return temp_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memDiag);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memDiag);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memSnap);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB0D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB0F0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memClean);

#ifndef NULL
#define NULL ((void *)0)
#endif

void memBreak(int arg0) {
    MemBreak = arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *memList(int arg0) {
    int var_s2;
    unsigned char temp_a6;
    void *var_a0;
    void *var_s0;
    void *var_s1;
    void *var_s4;

    var_a0 = NULL;
    var_s1 = NULL;
    if (pRoot != 0) {
        var_s0 = pAlloc;
        var_s4 = NULL;
        var_s2 = 0;
        if (var_s0 != NULL) {
loop_2:
            temp_a6 = M2C_FIELD(var_s0, unsigned char *, 0x13);
            if ((temp_a6 == arg0) && (M2C_FIELD(var_s0, unsigned char *, 0x11) == 0)) {
                var_s1 = (var_s1 == NULL) ? (var_s0 + 0x40) : var_s1;
                consPrintf("%4d : 0x%08x : More 0x%08x : Less 0x%08x : Size 0x%08x : %d : %s %d\n", var_s2, var_s0, M2C_FIELD(var_s0, void **, 8), M2C_FIELD(var_s0, int *, 0xC), M2C_FIELD(var_s0, int *, 0x14), temp_a6, var_s0 + 0x20, M2C_FIELD(var_s0, int *, 0x18));
            }
            var_s2 += 1;
            var_a0 = NULL;
            if (M2C_FIELD(var_s0, int *, 0xC) == var_s4) {
                var_s4 = var_s0;
                if (M2C_FIELD(var_s0, unsigned char *, 0x12) == 1) {
                    var_s0 = M2C_FIELD(var_s0, void **, 8);
                    if (var_s0 == NULL) {
                        goto block_8;
                    }
                    goto loop_2;
                }
            }
        } else {
block_8:
            var_a0 = var_s1;
        }
    }
    return var_a0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB180);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB19C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB1C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB1D0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvTerm);

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

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB210);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvCall);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvFree);
