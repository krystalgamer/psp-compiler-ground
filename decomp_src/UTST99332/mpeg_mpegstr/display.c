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
typedef struct t_displayBuffer t_displayBuffer;
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
typedef void SceVoid;
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

/* SDK functions */
int sceDisplayWaitVblankStart(void);
int sceDisplaySetMode(int mode, int width, int height);
int sceDisplaySetFrameBuf(void *topaddr, int bufferwidth, int pixelformat, int sync);
int sceKernelDelayThread(unsigned int delay);
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);
int sceKernelDeleteSema(int semid);
int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
int printf(const char *fmt, ...);
void *malloc(unsigned int size);
void *memalign(unsigned int align, unsigned int size);
void free(void *p);

extern SceInt32 frameCount;
extern SceInt32 frameLoss;
extern SceChar8 *displayBuf[2];

SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 disp_size, SceInt32 disp_num, t_conditionCtrl *pCtrl);
static SceInt32 swap_buffer(SceChar8 *buffer);
SceInt32 dispbuf_reset(t_displayBuffer *pDisp);
SceInt32 dispbuf_delete(t_displayBuffer *pDisp);
SceInt32 dispbuf_dataSet(t_displayBuffer *pDisp);
static SceInt32 dispbuf_checkDecodeEnd(t_displayBuffer *pDisp);
SceInt32 dispbuf_checkDelayMode(t_displayBuffer *pDisp);
SceInt32 dispbuf_func(SceSize size, SceVoid *argp);
SceInt32 dispbuf_show(t_displayBuffer *pDisp);


SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 disp_size, SceInt32 disp_num, t_conditionCtrl *pCtrl)
{
	SceInt32 i, ret;
	SceChar8 *geAddr;

	pDisp->buf = NULL;
	pDisp->pts = NULL;

	ret = sceDisplaySetMode(0, 480, 272);
	if (ret < 0) {
		goto error;
	}

	pDisp->lockSema = sceKernelCreateSema("display_lockSema", 0, 1, 1, NULL);

	pDisp->delayFlag = sceKernelCreateEventFlag("display_delay_flag", 0x200, 0, 0);

	pDisp->buf = malloc(disp_num * sizeof(SceChar8 *));
	if (pDisp->buf == NULL) {
		ret = -1;
		goto error;
	}

	for (i = 0; i < disp_num; i++) {
		pDisp->buf[i] = NULL;
	}

	for (i = 0; i < disp_num; i++) {
		pDisp->buf[i] = memalign(16, disp_size);
		if (pDisp->buf[i] == NULL) {
			ret = -1;
			goto error;
		}
	}

	pDisp->pts = malloc(disp_num * sizeof(SceUInt32));
	if (pDisp->pts == NULL) {
		ret = -1;
		goto error;
	}

	geAddr = sceGeEdramGetAddr();

	displayBuf[0] = geAddr + 0x88000;
	displayBuf[1] = geAddr + 0x110000;

	pDisp->size = disp_num;

	pDisp->pCtrl = pCtrl;

	goto term;

error:
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

term:
	return ret;
}

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

SceInt32 dispbuf_func(SceSize size, SceVoid *argp)
{
	SceInt32 delayCheck;
	SceInt32 currentMode;
	t_avSyncControl **ppAvSync;
	t_avSyncControl *pAvSync;
	t_displayBuffer *pDisp;

	ppAvSync = argp;
	pAvSync = *ppAvSync;
	pDisp = pAvSync->pDisp;
	control_waitConditionDispStart(pDisp->pCtrl);
	while (dispbuf_checkDecodeEnd(pDisp) != 1 || dispbuf_getCurrentCount(pDisp) != 0) {
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
				sceKernelWaitSema(pDisp->lockSema, 1, NULL);
				pDisp->count--;
				sceKernelSignalSema(pDisp->lockSema, 1);
				frameCount++;
			}
		} else {
			frameLoss++;
		}
		control_setCondition(pDisp->pCtrl, 2);
		sceDisplayWaitVblankStart();
	}
	sceDisplaySetFrameBuf(NULL, 512, 3, 1);
	printf("frame count = %d\n", frameCount);
	printf("frame loss  = %d\n", frameLoss);
	control_setCondition(pDisp->pCtrl, 0x10);
	sceKernelExitThread(0);
	return 0;
}

SceInt32 dispbuf_show(t_displayBuffer *pDisp)
{
	SceChar8 *buffer;

	if (dispbuf_getMode(pDisp) == 1 || dispbuf_getMode(pDisp) == 0xff) {
		buffer = pDisp->buf[pDisp->read];
		swap_buffer(buffer);
		pDisp->read = (pDisp->read + 1) % pDisp->size;
		sceDisplayWaitVblankStart();
	} else {
		pDisp->read = (pDisp->read + 1) % pDisp->size;
	}
	return 0;
}
