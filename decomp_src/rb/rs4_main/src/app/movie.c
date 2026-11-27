/* cflags: -Os -fno-strength-reduce */
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
void movAudio(void);
int sceMpegFinish();                                /* extern */
int semaTerm(int);                                  /* extern */
M2C_UNK semaLock(int);                              /* extern */
M2C_UNK semaUnlock(int);
extern char *StreamPtr;
extern int StreamSize;
void *memcpy(void *, const void *, unsigned int);
typedef struct MovBlk { struct MovBlk *next; void *buf; } MovBlk;
extern MovBlk *pHead, *pDrop;
extern int AudioBlock;
int _memFree();
int sceWaveAudioWriteBlocking(int, int, int, void *);
void sceKernelDelayThread(int);
void movLock(void);
void movUnlock(void);
extern unsigned char Mpeg, VideoAu;
extern void *pVideoStream;
extern void *pVideoRenderBuf[2];
extern void *pVideoRender;
extern int D_00119B74;
int sceMpegGetAvcAu(void *, void *, void *, void *);
int sceMpegAvcDecode(void *, void *, int, void *, int *);

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
    thrEntry(&ThrMovie, (M2C_UNK *)movAudio, 0, 0);
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

void movAudio(void)
{
	for (;;) {
		if (pHead) {
			if (sceWaveAudioWriteBlocking(1, 0x8000, 0x8000, pHead->buf) < 0) continue;
			movLock();
			if (pDrop) {
				_memFree(pDrop->buf, &D_000FDC10, 0x231);
				_memFree(pDrop, &D_000FDC10, 0x232);
				pDrop = 0;
				AudioBlock--;
			}
			pDrop = pHead;
			if (pHead) pHead = pHead->next;
			movUnlock();
		} else {
			sceKernelDelayThread(1000);
		}
	}
}
