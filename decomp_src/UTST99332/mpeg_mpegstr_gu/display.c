/* cflags: -O2 -fmerge-constants */
#include "common.h"

/* declarations recovered from DWARF */
struct t_displayBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
typedef int SceInt32;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x4 */
    SceUID control_flag;
};
typedef struct t_conditionCtrl t_conditionCtrl;
struct SceMpeg;
typedef void SceVoid;
struct SceMpeg { /* size 0x4 */
    SceVoid *sys;
};
typedef struct SceMpeg SceMpeg;
struct t_displayBuffer { /* size 0x38 */
    SceUID lock_sema;
    SceUID delayFlag;
    SceChar8 **buf;
    SceChar8 *workBuf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 pixelFormat;
    SceInt32 displayMode;
    SceInt32 scale;
    t_conditionCtrl *pCtrl;
    SceMpeg *pMpeg;
};
typedef struct t_displayBuffer t_displayBuffer;
struct _anon1;
struct _anon1 { /* size 0x10 */
    SceUInt32 uiStartWidth;
    SceUInt32 uiStartHeight;
    SceUInt32 uiLenWidth;
    SceUInt32 uiLenHeight;
};
typedef struct _anon1 SceMpegAvcYCbCrRange;
typedef float SceFloat32;
struct SceKernelEventFlagInfo;
typedef unsigned int SceSize;
typedef unsigned int SceUInt;
struct SceKernelEventFlagInfo { /* size 0x34 */
    SceSize size;
    char name[32];
    SceUInt attr;
    SceUInt initPattern;
    SceUInt currentPattern;
    int numWaitThreads;
};
typedef struct SceKernelEventFlagInfo SceKernelEventFlagInfo;
struct t_avSyncControl;
struct t_soundBuffer;
struct t_soundBuffer { /* size 0x28 */
    SceUID lockSema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 bufSize;
    t_conditionCtrl *pCtrl;
    SceUInt32 soundLatestPts;
};
typedef struct t_soundBuffer t_soundBuffer;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x18 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceUInt32 videoLatestPts;
};
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSyncControl { /* size 0x20 */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};
typedef struct t_avSyncControl t_avSyncControl;
typedef short int SceShort16;

extern SceInt32 frameCount;
extern SceInt32 frameLoss;
extern SceChar8 disp_list[65536];
extern SceFloat32 displayScale[3];
extern SceShort16 board[2][3];

static SceInt32 init_all(t_displayBuffer *pDisp);
static SceInt32 draw_frame(t_displayBuffer *pDisp, SceChar8 *pYCbCrBuf);
SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceMpeg *pMpeg, SceInt32 disp_num, SceInt32 pixelFormat, t_conditionCtrl *pCtrl);
SceInt32 dispbuf_reset(t_displayBuffer *pDisp);
SceInt32 dispbuf_delete(t_displayBuffer *pDisp);
SceInt32 dispbuf_dataSet(t_displayBuffer *pDisp);
static SceInt32 dispbuf_checkDecodeEnd(t_displayBuffer *pDisp);
SceInt32 dispbuf_checkDelayMode(t_displayBuffer *pDisp);
SceInt32 dispbuf_func(SceSize size, SceVoid *argp);
SceInt32 dispbuf_show(t_displayBuffer *pDisp);


/* SDK prototypes (tools/sdk_protos.h) */
void *malloc(unsigned int size);
void *memalign(unsigned int align, unsigned int size);
int puts(const char *s);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColor(unsigned int color);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDisable(int state);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotation);
void sceGuEnable(int state);
int sceGuFinish(void);
void sceGuInit(void);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSpriteMode(int a0, int a1, int a2, int a3);
void sceGuStart(int type, void *list, int size);
int sceGuSync(int mode, int what);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexWrap(int u, int v);
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);
int sprintf(char *buf, const char *fmt, ...);

SceInt32 init_all(t_displayBuffer *pDisp)
{
	sceGuInit();

	sceGuStart(0, disp_list, 0x10000);

	if (pDisp->pixelFormat == 3) {
		sceGuDrawBuffer(3, (void *)0, 512);
		sceGuDispBuffer(480, 272, (void *)0x88000, 512);
		sceGuDepthBuffer((void *)0x110000, 512);
	} else {
		if (pDisp->pixelFormat == 0) {
			sceGuDrawBuffer(0, (void *)0, 512);
		} else if (pDisp->pixelFormat == 1) {
			sceGuDrawBuffer(1, (void *)0, 512);
		} else if (pDisp->pixelFormat == 2) {
			sceGuDrawBuffer(2, (void *)0, 512);
		} else {
			return -1;
		}
		sceGuDispBuffer(480, 272, (void *)0x44000, 512);
		sceGuDepthBuffer((void *)0x88000, 512);
	}

	sceGuOffset(0, 0);

	sceGuScissor(0, 0, 480, 272);
	sceGuEnable(2);

	sceGuTexFunc(0, 1);
	sceGuTexFilter(7, 0);
	sceGuTexWrap(0, 0);
	sceGuEnable(9);

	sceGuClearColor(0);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuFinish();
	sceGuSync(0, 0);
	sceDisplayWaitVblankStart();

	sceGuDisplay(1);

	return 0;
}

SceInt32 draw_frame(t_displayBuffer *pDisp, SceChar8 *pYCbCrBuf)
{
	SceInt32 i;
	SceInt32 ret;
	SceChar8 str[32];
	SceMpegAvcYCbCrRange range;
	SceChar8 *buffer;
	SceInt32 pixelSize;
	SceInt32 currentSize;
	SceInt32 baseX;
	SceInt32 baseY;
	SceFloat32 scale;

	pixelSize = 128;

	buffer = pDisp->workBuf;
	scale = displayScale[pDisp->scale];

	baseX = (SceInt32)(240.0f - (scale * 480.0f) * 0.5f);
	baseY = (SceInt32)(136.0f - (scale * 272.0f) * 0.5f);

	for (i = 0; i < 4; i++) {
		if (480 - i * pixelSize < pixelSize) {
			currentSize = 480 % pixelSize;
		} else {
			currentSize = pixelSize;
		}

		range.uiStartWidth = i * pixelSize;
		range.uiStartHeight = 0;
		range.uiLenWidth = currentSize;
		range.uiLenHeight = 272;

		ret = sceMpegAvcCsc(pDisp->pMpeg, pYCbCrBuf, &range, pixelSize, buffer);
		if (ret != 0) {
			printf("fatal error : sceMpegAvcCsc() 0x%x\n", ret);
			ret = -1;
			goto term;
		}

		sceGuStart(0, disp_list, 0x10000);
		if (i == 0) {
			sceGuClear(7);
		}
		sceGuEnable(9);

		switch (pDisp->pixelFormat) {
case 3:
			sceGuTexMode(3, 0, 0, 0);
			break;
	case 0:
			sceGuTexMode(0, 0, 0, 0);
			break;
case 1:
			sceGuTexMode(1, 0, 0, 0);
			break;
case 2:
			sceGuTexMode(2, 0, 0, 0);
			break;
	}

		sceGuTexImage(0, 128, 512, 128, buffer);
		sceGuBlendFunc(0, 10, 10, 0xffffffff, 0);
		sceGuEnable(4);
		sceGuColor(0xffffffff);

		sceGuSpriteMode(currentSize, 272, (SceInt32)(currentSize * scale), (SceInt32)(scale * 272.0f));
		sceGuDrawSprite((SceInt32)(baseX + i * (scale * pixelSize)), baseY, 0, 0, 0, 0, 0);

		sceGuFinish();
		sceGuSync(0, 0);
	}

	sceGuStart(0, disp_list, 0x10000);

	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuEnable(4);

	sceGuDisable(9);
	sceGuColor(0x90000000);
	sceGuDrawArray(6, 0x800100, 2, 0, board);

	sceGuEnable(9);
	switch (pDisp->pixelFormat) {
case 3:
		sceGuDebugPrint(8, 8, 0xffffffff, "RGBA8888");
		break;
case 0:
		sceGuDebugPrint(8, 8, 0xffffffff, "RGB565");
		break;
case 1:
		sceGuDebugPrint(8, 8, 0xffffffff, "RGBA5551");
		break;
case 2:
		sceGuDebugPrint(8, 8, 0xffffffff, "RGBA4444");
		break;
	}

	sprintf(str, "SCALE : %3.1f", scale);
	sceGuDebugPrint(8, 16, 0xffffffff, str);
	sceGuDebugPrint(8, 32, 0xffffffff, "START : RESTART");
	sceGuDebugPrint(8, 40, 0xffffffff, "SELECT: EXIT");
	sceGuDebugPrint(8, 48, 0xffffffff, "CIRCLE: DISP WAIT");
	sceGuDebugPrint(8, 56, 0xffffffff, "R     : ZOOM IN");
	sceGuDebugPrint(8, 64, 0xffffffff, "L     : ZOOM OUT");

	sceGuFinish();
	sceGuSync(0, 0);

term:
	return ret;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", dispbuf_create);

SceInt32 dispbuf_reset(t_displayBuffer *pDisp)
{
	frameCount = 0;
	frameLoss = 0;

	pDisp->write = 0;
	pDisp->read = 0;
	pDisp->count = 0;
	pDisp->scale = 1;

	dispbuf_setMode(pDisp, 1);

	sceKernelClearEventFlag(pDisp->delayFlag, 0);

	switch (pDisp->pixelFormat) {
	case 3:
		sceDisplaySetFrameBuf(0, 512, 3, 1);
		break;
	case 0:
		sceDisplaySetFrameBuf(0, 512, 0, 1);
		break;
	case 1:
		sceDisplaySetFrameBuf(0, 512, 1, 1);
		break;
	case 2:
		sceDisplaySetFrameBuf(0, 512, 2, 1);
		break;
	}

	return 0;
}

SceInt32 dispbuf_delete(t_displayBuffer *pDisp)
{
	SceInt32 i;

	sceGuTerm();

	sceKernelDeleteSema(pDisp->lock_sema);
	sceKernelDeleteEventFlag(pDisp->delayFlag);

	if (pDisp->buf != NULL) {
		for (i = 0; i < pDisp->size; i++) {
			if (pDisp->buf[i] != NULL) {
				free(pDisp->buf[i]);
				pDisp->buf[i] = NULL;
			}
		}

		free(pDisp->buf);
		pDisp->buf = NULL;
	}

	if (pDisp->pts != NULL) {
		free(pDisp->pts);
		pDisp->pts = NULL;
	}

	return 0;
}

int dispbuf_getDrawbuf(t_displayBuffer *pDisp, signed char **buffer) {
    int temp_v0;

    temp_v0 = dispbuf_getCapacity(pDisp);
    if (temp_v0 > 0) {
        *buffer = pDisp->buf[pDisp->write];
    } else {
        *buffer = NULL;
    }
    return temp_v0;
}

SceInt32 dispbuf_dataSet(t_displayBuffer *pDisp)
{
	sceKernelWaitSema(pDisp->lock_sema, 1, NULL);

	pDisp->count++;
	pDisp->write = (pDisp->write + 1) % pDisp->size;

	sceKernelSignalSema(pDisp->lock_sema, 1);

	return 0;
}

int dispbuf_getCapacity(t_displayBuffer *pDisp) {
    return pDisp->size - pDisp->count;
}

int dispbuf_getCurrentCount(t_displayBuffer *pDisp) {
    return pDisp->count;
}

static SceInt32 dispbuf_checkDecodeEnd(t_displayBuffer *pDisp)
{
	SceUInt32 pattern;

	control_getCondition(pDisp->pCtrl, &pattern);
	if (pattern & 0x8) {
		dispbuf_setMode(pDisp, 0xff);
		return 1;
	}
	return 0;
}

int dispbuf_setPts(t_displayBuffer *pDisp, unsigned int pts) {
    pDisp->pts[pDisp->write] = pts;
    return 0;
}

int dispbuf_getPts(t_displayBuffer *pDisp, unsigned int *pPts) {
    *pPts = pDisp->pts[pDisp->read];
    return 0;
}

int dispbuf_setMode(t_displayBuffer *pDisp, int mode) {
    pDisp->displayMode = mode;
    return 0;
}

int dispbuf_getMode(t_displayBuffer *pDisp) {
    return pDisp->displayMode;
}

int dispbuf_setDelayMode(t_displayBuffer *pDisp) {
    return sceKernelSetEventFlag(pDisp->delayFlag, 1);
}

int dispbuf_setPlayMode(t_displayBuffer *pDisp) {
    return sceKernelClearEventFlag(pDisp->delayFlag, 0);
}

SceInt32 dispbuf_checkDelayMode(t_displayBuffer *pDisp)
{
	SceKernelEventFlagInfo info;
	SceInt32 ret;

	info.size = sizeof(info);
	sceKernelReferEventFlagStatus(pDisp->delayFlag, &info);
	if (info.currentPattern == 1)
		ret = 1;
	else
		ret = 0;
	return ret;
}

SceInt32 dispbuf_func(SceSize size, SceVoid *argp)
{
	SceInt32 delayCheck;
	SceInt32 currentMode;
	t_avSyncControl **ppAvSync = (t_avSyncControl **)argp;
	t_avSyncControl *pAvSync = *ppAvSync;
	t_displayBuffer *pDisp = pAvSync->pDisp;

	control_waitConditionDispStart(pDisp->pCtrl);

	while (1) {
		if (dispbuf_checkDecodeEnd(pDisp) == 1 && dispbuf_getCurrentCount(pDisp) == 0) {
			break;
		}

		delayCheck = dispbuf_checkDelayMode(pDisp);
		if (delayCheck == 1) {
			sceKernelDelayThread(1000000);
			dispbuf_setPlayMode(pDisp);
		}

		currentMode = avsync_Compare(pAvSync);
		dispbuf_setMode(pDisp, currentMode);

		if (dispbuf_getCurrentCount(pDisp) > 0) {
			if (dispbuf_getMode(pDisp) != 4) {
				dispbuf_show(pDisp);

				sceKernelWaitSema(pDisp->lock_sema, 1, NULL);
				pDisp->count--;
				sceKernelSignalSema(pDisp->lock_sema, 1);

				frameCount++;
			}
		} else {
			frameLoss++;
		}

		control_setCondition(pDisp->pCtrl, 2);

		sceDisplayWaitVblankStart();
	}

	sceDisplayWaitVblankStart();
	sceGuSwapBuffers();

	printf("frame count = %d\n", frameCount);
	printf("frame loss  = %d\n", frameLoss);

	control_setCondition(pDisp->pCtrl, 0x10);

	sceKernelExitThread(0);

	return 0;
}

SceInt32 dispbuf_show(t_displayBuffer *pDisp)
{
	SceChar8 *yCbCrBuf;

	if (dispbuf_getMode(pDisp) == 1 || dispbuf_getMode(pDisp) == 0xff) {
		yCbCrBuf = pDisp->buf[pDisp->read];

		draw_frame(pDisp, yCbCrBuf);

		pDisp->read = (pDisp->read + 1) % pDisp->size;
		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();
	} else {
		pDisp->read = (pDisp->read + 1) % pDisp->size;
	}

	return 0;
}

int dispbuf_zoomin(t_displayBuffer *pDisp) {
    int temp_v1;

    temp_v1 = pDisp->scale;
    if (temp_v1 >= 2) {
        return 0;
    }
    pDisp->scale = temp_v1 + 1;
    return 0;
}

int dispbuf_zoomout(t_displayBuffer *pDisp) {
    int temp_v1;

    temp_v1 = pDisp->scale;
    if (temp_v1 > 0) {
        pDisp->scale = temp_v1 - 1;
    }
    return 0;
}

