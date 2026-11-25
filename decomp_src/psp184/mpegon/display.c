#include "common.h"

/* declarations recovered from DWARF */
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
typedef int SceInt32;
typedef struct t_conditionCtrl t_conditionCtrl;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x8 */
    SceUID controlFlag;
    SceUID waitFlag;
};
struct t_displayBuffer { /* size 0x28 */
    SceUID lockSema;
    SceUID delayFlag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 displayMode;
    t_conditionCtrl *pCtrl;
};
typedef struct SceKernelEventFlagInfo SceKernelEventFlagInfo;
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
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_soundBuffer t_soundBuffer;
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
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x18 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceUInt32 videoLatestPts;
};
struct t_avSyncControl { /* size 0x20 */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};

extern SceInt32 frameCount;
extern SceInt32 frameLoss;
extern SceChar8 *displayBuf[2];

SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 dispSize, SceInt32 dispNum, t_conditionCtrl *pCtrl);
static SceInt32 swap_buffer(SceChar8 *buffer);
SceInt32 dispbuf_reset(t_displayBuffer *pDisp);
SceInt32 dispbuf_delete(t_displayBuffer *pDisp);
SceInt32 dispbuf_dataSet(t_displayBuffer *pDisp);
static SceInt32 dispbuf_checkDecodeEnd(t_displayBuffer *pDisp);
SceInt32 dispbuf_checkDelayMode(t_displayBuffer *pDisp);
int dispbuf_func(SceSize size, void *argp);
SceInt32 dispbuf_show(t_displayBuffer *pDisp);


INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/display", dispbuf_create);

int sceDisplaySetFrameBuf(void *topaddr, int bufferwidth, int pixelformat, int sync);
int sceDisplaySetFrameBuf(void *topaddr, int bufferwidth, int pixelformat, int sync);
static SceInt32 swap_buffer(SceChar8 *buffer)
{
	SceChar8 *storeBuf;

	sceDmacMemcpy(displayBuf[0], buffer, 0x88000);
	sceDisplaySetFrameBuf(displayBuf[0], 512, 3, 1);
	storeBuf = displayBuf[0];
	displayBuf[0] = displayBuf[1];
	displayBuf[1] = storeBuf;
	return 0;
}

int sceDisplaySetMode(int mode, int width, int height);
SceInt32 dispbuf_reset(t_displayBuffer *pDisp)
{
	SceInt32 ret;

	frameCount = 0;
	frameLoss = 0;
	pDisp->write = 0;
	pDisp->read = 0;
	pDisp->count = 0;
	dispbuf_setMode(pDisp, 1);
	sceKernelClearEventFlag(pDisp->delayFlag, 0);
	ret = sceDisplaySetMode(0, 480, 272);
	if (ret < 0)
		return ret;
	sceDisplaySetFrameBuf(NULL, 512, 3, 1);
	return 0;
}

int sceKernelDeleteSema(int semid);
void free(void *p);
SceInt32 dispbuf_delete(t_displayBuffer *pDisp)
{
	SceInt32 i;

	if (pDisp->buf) {
		for (i = 0; i < pDisp->size; i++) {
			if (pDisp->buf[i]) {
				free(pDisp->buf[i]);
				pDisp->buf[i] = NULL;
			}
		}
		free(pDisp->buf);
		pDisp->buf = NULL;
	}
	if (pDisp->pts) {
		free(pDisp->pts);
		pDisp->pts = NULL;
	}
	sceKernelDeleteSema(pDisp->lockSema);
	sceKernelDeleteEventFlag(pDisp->delayFlag);
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

int dispbuf_setPts(t_displayBuffer *pDisp, unsigned int pts) {
    pDisp->pts[pDisp->write] = pts;
    return 0;
}

int dispbuf_getPts(t_displayBuffer *pDisp, unsigned int *pPts) {
    *pPts = pDisp->pts[pDisp->read];
    return 0;
}

int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
SceInt32 dispbuf_dataSet(t_displayBuffer *pDisp)
{
	sceKernelWaitSema(pDisp->lockSema, 1, NULL);
	pDisp->count++;
	pDisp->write = (pDisp->write + 1) % pDisp->size;
	sceKernelSignalSema(pDisp->lockSema, 1);
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

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/display", dispbuf_func);

INCLUDE_ASM("tmp/asm/psp184/mpegon/nonmatchings/display", dispbuf_show);
