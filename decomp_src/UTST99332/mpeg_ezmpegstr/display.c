#include "common.h"

/* declarations recovered from DWARF */
typedef char SceChar8;
typedef int SceInt32;
struct t_displayBuffer;
typedef int SceUID;
typedef unsigned int SceUInt32;
struct t_displayBuffer { /* size 0x28 */
    SceUID start_sema;
    SceUID lock_sema;
    SceUID display_wait_sema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 displayMode;
};
typedef struct t_displayBuffer t_displayBuffer;
typedef void SceVoid;
struct t_avSyncControl;
struct t_soundBuffer;
struct t_soundBuffer { /* size 0x28 */
    SceUID lock_sema;
    SceUID status_flag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 buf_size;
    SceUInt32 soundLatestTimestamp;
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

extern SceInt32 frameCount;
extern SceInt32 frameLoss;
extern SceChar8 *displayBuf[2];

static SceInt32 swap_buffer(SceChar8 *buffer);
SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 disp_size, SceInt32 disp_num);
SceInt32 dispbuf_reset(t_displayBuffer *pDisp);
SceInt32 dispbuf_delete(t_displayBuffer *pDisp);
SceInt32 dispbuf_dataSet(t_displayBuffer *pDisp);
SceInt32 dispbuf_display(SceVoid *pAv);
static SceInt32 dispbuf_show(t_displayBuffer *pDisp);


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

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/display", dispbuf_create);

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
	ret = sceDisplaySetMode(0, 480, 272);
	if (ret < 0) {
		return ret;
	}
	sceDisplaySetFrameBuf(0, 512, 3, 1);
	return 0;
}

SceInt32 dispbuf_delete(t_displayBuffer *pDisp)
{
	SceInt32 i;

	if (pDisp->buf != NULL) {
		for (i = 0; i < pDisp->size; i++) {
			if (pDisp->buf[i] != NULL) {
				free(pDisp->buf[i]);
			}
		}
		free(pDisp->buf);
	}

	if (pDisp->pts != NULL) {
		free(pDisp->pts);
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

int dispbuf_setMode(t_displayBuffer *pDisp, int mode) {
    pDisp->displayMode = mode;
    return 0;
}

int dispbuf_getMode(t_displayBuffer *pDisp) {
    return pDisp->displayMode;
}

SceInt32 dispbuf_display(SceVoid *pAv)
{
	SceInt32 currentMode;
	t_avSyncControl *pAvSync = (t_avSyncControl *)pAv;
	t_displayBuffer *pDisp = pAvSync->pDisp;

	currentMode = avsync_Compare(pAvSync);
	dispbuf_setMode(pDisp, currentMode);

	if (dispbuf_getCurrentCount(pDisp) > 0) {
		if (dispbuf_getMode(pDisp) != 3) {
			dispbuf_show(pDisp);

			pDisp->count--;

			frameCount++;
		}
	} else {
		frameLoss++;
	}

	return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/display", dispbuf_show);
