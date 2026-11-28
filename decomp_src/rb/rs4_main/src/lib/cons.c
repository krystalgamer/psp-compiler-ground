/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK _memFree(int, M2C_UNK *, M2C_UNK);          /* extern */
int semaTerm(int);                                  /* extern */
extern int ConsSema;
extern signed char D_000FAA78;
extern unsigned char D_000FAA94;
extern unsigned char D_000FAAA4;

void consPrintf(const char *, ...);
extern int LogIdx;
extern int pLogBuf;

void *_memAllocZero(int, void *, int);
extern unsigned char D_000FAAAC;
extern unsigned char D_000FAAC4;
extern unsigned char D_000FAACC;

int consInit(void) {
    M2C_UNK *temp_s0;
    int temp_v0_2;
    void *temp_v0;

    if (pLogBuf != NULL) {
        consPrintf(&D_000FAA78, &D_000FAA94, 0x23, "consInit", "pLogBuf == 0");
    }
    temp_v0 = _memAllocZero(0x400, &D_000FAA94, 0x25);
    pLogBuf = temp_v0;
    if (temp_v0 == NULL) {
        consPrintf(&D_000FAA78, &D_000FAA94, 0x26, "consInit", &D_000FAAA4);
    }
    temp_s0 = "consInit";
    consPrintf(&D_000FAAAC, temp_s0, pLogBuf, 0x400);
    temp_v0_2 = semaInit(&D_000FAAC4);
    ConsSema = temp_v0_2;
    if (temp_v0_2 <= 0) {
        consPrintf(&D_000FAA78, &D_000FAA94, 0x2C, temp_s0, &D_000FAACC);
    }
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/cons", D_000FAA78);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/cons", D_000FAA94);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/cons", D_000FAAA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/cons", D_000FAAAC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/cons", D_000FAAC4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/cons", D_000FAACC);

#ifndef NULL
#define NULL ((void *)0)
#endif

int consTerm(void) {
    if (semaTerm(ConsSema) != 1) {
        consPrintf(&D_000FAA78, &D_000FAA94, 0x39, "consTerm", "Ret == TRUE");
    }
    ConsSema = -1;
    if (pLogBuf == 0) {
        consPrintf(&D_000FAA78, &D_000FAA94, 0x3E, "consTerm", &D_000FAAA4);
    }
    consPrintf("%s : 0x%08x\n", "consTerm", pLogBuf);
    _memFree(pLogBuf, &D_000FAA94, 0x42);
    pLogBuf = 0;
    return 1;
}

void consPrintf(const char *fmt, ...)
{
}

int consLog(unsigned int arg0) {
    int var_v1;

    var_v1 = 0;
    if ((pLogBuf != 0) & (arg0 < 0x10U)) {
        var_v1 = pLogBuf + (((LogIdx + arg0) & 0xF) << 6);
    }
    return var_v1;
}
