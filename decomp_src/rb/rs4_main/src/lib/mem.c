/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
int semaTerm(int);                                  /* extern */
extern signed char D_000FACF8;
extern unsigned char D_000FAD14;
extern unsigned char D_000FAD44;
extern int pFree;
extern void *pHeap;

#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK semaLock(int);                              /* extern */
extern int MemSema;
M2C_UNK semaUnlock(int);                            /* extern */
void consPrintf(const char *, ...);
extern void *pAlloc;
extern int pRoot;

void *_memAlloc();                                  /* extern */
extern int MemBreak;
void *memset(void *s, int c, unsigned int n);
void *memset(void *s, int c, unsigned int n);

void memLock(void);
void memUnlock(void);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FACEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FACF4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FACF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FAD14);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FAD24);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FAD30);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FAD3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FAD44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FAD4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FAD64);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FAD7C);

#ifndef NULL
#define NULL ((void *)0)
#endif
void free(void *p);

int memTerm(void) {
    M2C_UNK *temp_v0;

    temp_v0 = "memTerm";
    consPrintf("%s : 0x%08x\n", temp_v0, pHeap);
    if (pHeap == NULL) {
        consPrintf(&D_000FACF8, &D_000FAD14, 0x8F, temp_v0, &D_000FAD44);
    }
    memLock();
    free(pHeap);
    pRoot = 0;
    pAlloc = 0;
    pFree = 0;
    pHeap = NULL;
    memUnlock();
    if (semaTerm(MemSema) != 1) {
        consPrintf(&D_000FACF8, &D_000FAD14, 0x9E, temp_v0, "Ret == TRUE");
    }
    MemSema = -1;
    return 1;
}

void memLock(void) {
    if (MemSema > 0) {
        semaLock(MemSema);
    }
}

void memUnlock(void) {
    if (MemSema > 0) {
        semaUnlock(MemSema);
    }
}

int memGetCntxSize(void) {
    return 0x40;
}

int memGetAlignSize(void) {
    return 0x40;
}

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

void memBreak(int arg0) {
    MemBreak = arg0;
}

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
