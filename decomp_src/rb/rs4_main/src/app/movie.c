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

int sceMpegAvcDecodeFlush(void *);
int sceMpegDelete(void *);
int sceMpegFreeAvcEsBuf(void *, int);
int sceMpegRingbufferDestruct(void *);
int sceMpegUnRegistStream(void *, int);
extern int MpegHdl;
extern unsigned char Ring;
extern int StreamOfs;
extern void *pAudioDecBuf;
extern int pAudioStream;
extern void *pAudioTmpBuf;
extern void *pRingBuf;
extern int pTail;
extern void *pVideoDecBuf;

int movCleanup(void) {
    void *temp_s1;
    void *var_s2;

    if (sceMpegAvcDecodeFlush(&Mpeg) != 0) {
        consPrintf(&D_000FDC20, &D_000FDC10, 0x10F, "movCleanup", &D_000FDBFC);
    }
    if (sceMpegFreeAvcEsBuf(&Mpeg, MpegHdl) != 0) {
        consPrintf(&D_000FDC20, &D_000FDC10, 0x113, "movCleanup", &D_000FDBFC);
    }
    if (sceMpegUnRegistStream(&Mpeg, pVideoStream) != 0) {
        consPrintf(&D_000FDC20, &D_000FDC10, 0x117, "movCleanup", &D_000FDBFC);
    }
    if (sceMpegUnRegistStream(&Mpeg, pAudioStream) != 0) {
        consPrintf(&D_000FDC20, &D_000FDC10, 0x11B, "movCleanup", &D_000FDBFC);
    }
    if (sceMpegDelete(&Mpeg) != 0) {
        consPrintf(&D_000FDC20, &D_000FDC10, 0x11F, "movCleanup", &D_000FDBFC);
    }
    if (sceMpegRingbufferDestruct(&Ring) != 0) {
        consPrintf(&D_000FDC20, &D_000FDC10, 0x123, "movCleanup", &D_000FDBFC);
    }
    if (pAudioTmpBuf != NULL) {
        _memFree(pAudioTmpBuf, &D_000FDC10, 0x127);
    }
    if (pAudioDecBuf != NULL) {
        _memFree(pAudioDecBuf, &D_000FDC10, 0x129);
    }
    if (pVideoDecBuf != NULL) {
        _memFree(pVideoDecBuf, &D_000FDC10, 0x12A);
    }
    if (pRingBuf != NULL) {
        _memFree(pRingBuf, &D_000FDC10, 0x12B);
    }
    pVideoRenderBuf[0] = NULL;
    var_s2 = pHead;
    pVideoRender = 0;
    StreamPtr = 0;
    StreamOfs = 0;
    pRingBuf = NULL;
    MpegHdl = 0;
    pVideoDecBuf = NULL;
    pAudioDecBuf = NULL;
    pVideoRenderBuf[1] = NULL;
    pAudioTmpBuf = NULL;
    StreamSize = 0;
    movLock();
    if (var_s2 != NULL) {
        do {
            temp_s1 = M2C_FIELD(var_s2, void **, 0);
            _memFree(M2C_FIELD(var_s2, void **, 4), &D_000FDC10, 0x149);
            _memFree(var_s2, &D_000FDC10, 0x14A);
            var_s2 = temp_s1;
        } while (temp_s1 != NULL);
    }
    if (pDrop != NULL) {
        _memFree(M2C_FIELD(pDrop, void **, 4), &D_000FDC10, 0x150);
        _memFree(pDrop, &D_000FDC10, 0x151);
    }
    pTail = 0;
    pDrop = NULL;
    pHead = NULL;
    AudioBlock = 0;
    movUnlock();
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movPutCB);

extern int D_00119B70;
extern unsigned char Ring;
extern int AudioInit;
int sceMpegRingbufferAvailableSize(void *);
int sceMpegRingbufferPut(void *, int, int);
int movDecodeVideo(void);
void movDecodeAudio(void);
int movProc(void)
{
	int n;
	D_00119B70 ^= 1;
	if (D_00119B70 != 0)
		return 1;
	n = sceMpegRingbufferAvailableSize(&Ring);
	if (n < 0)
		consPrintf(&D_000FDC20, &D_000FDC10, 0x18D, "movProc", "FreePack >= 0");
	if (sceMpegRingbufferPut(&Ring, 0x400, n) < 0)
		return 0;
	n = sceMpegRingbufferAvailableSize(&Ring);
	if (n < 0)
		return 0;
	if (n >= 0x400)
		return -1;
	movDecodeVideo();
	movDecodeAudio();
	AudioInit = 0;
	return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movDecodeVideo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movDecodeAudio);

extern float D_00112150[8], D_00112170[8], D_00112190[4];
void *i3dGetStage(void);
void *I3dRenderStage__OpenPacket(void *, float);
void I3dRenderStage__ClosePacket(void *, void *);
void *xuTexMode(void *, int, int, int, int);
void *xuTexImage(void *, int, int, int, int, void *);
void *xuEnable(void *, int);
void *xuTexFilter(void *, int, int);
void *xuTexFunc(void *, int, int);
void *xuTexWrap(void *, int, int);
void *xuTexFlush(void *);
void *I3dPk2dPrim_DrawSpriteFTU(void *, float *, float *, float *, float *, float *);
int movDraw(void)
{
	void *st;
	void *pk;
	int r = 0;
	if (pVideoRender != 0) {
		st = i3dGetStage();
		pk = I3dRenderStage__OpenPacket(st, 0.0f);
		pk = xuTexMode(pk, 3, 0, 0, 0);
		pk = xuTexImage(pk, 0, 0x200, 0x200, 0x200, pVideoRender);
		pk = xuEnable(pk, 9);
		pk = xuTexFilter(pk, 7, 1);
		pk = xuTexFunc(pk, 0, 0);
		pk = xuTexWrap(pk, 1, 1);
		pk = xuTexFlush(pk);
		pk = I3dPk2dPrim_DrawSpriteFTU(pk, &D_00112150[0], &D_00112150[4], &D_00112170[0], &D_00112170[4], D_00112190);
		I3dRenderStage__ClosePacket(st, pk);
		r = 1;
	}
	return r;
}

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
