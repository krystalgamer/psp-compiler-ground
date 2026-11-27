/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);
int sceMpegInit();                                  /* extern */
int semaInit(M2C_UNK *);                            /* extern */
M2C_UNK thrEntry(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK thrMake(M2C_UNK *, M2C_UNK, M2C_UNK *);     /* extern */
extern unsigned char D_000FDBFC;
extern unsigned char D_000FDC10;
extern unsigned char D_000FDC20;
extern unsigned char D_000FDC3C;
extern unsigned char D_000FDC44;
extern int MovSema;
extern unsigned char ThrMovie;
extern unsigned char movAudio;
int sceMpegFinish();                                /* extern */
int semaTerm(int);                                  /* extern */
M2C_UNK semaLock(int);                              /* extern */
M2C_UNK semaUnlock(int);

int movInit(void) {
    int temp_v0;

    if (sceMpegInit() != 0) {
        consPrintf(&D_000FDC20, &D_000FDC10, 0x5F, "movInit", &D_000FDBFC);
    }
    temp_v0 = semaInit(&D_000FDC3C);
    MovSema = temp_v0;
    if (temp_v0 <= 0) {
        consPrintf(&D_000FDC20, &D_000FDC10, 0x63, "movInit", &D_000FDC44);
    }
    thrMake(&ThrMovie, 0x12, &D_000FDC3C);
    thrEntry(&ThrMovie, &movAudio, 0, 0);
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDBFC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDC10);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDC20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDC3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDC44);

int movTerm(void) {
    if (semaTerm(MovSema) != 1) {
        consPrintf(&D_000FDC20, &D_000FDC10, 0x73, "movTerm", "Ret == TRUE");
    }
    MovSema = -1;
    if (sceMpegFinish() != 0) {
        consPrintf(&D_000FDC20, &D_000FDC10, 0x79, "movTerm", &D_000FDBFC);
    }
    return 1;
}

void movLock(void) {
    if (MovSema > 0) {
        semaLock(MovSema);
    }
}

void movUnlock(void) {
    if (MovSema > 0) {
        semaUnlock(MovSema);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movPrepare);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movCleanup);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movPutCB);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movDecodeVideo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movDecodeAudio);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movDraw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movAudio);
