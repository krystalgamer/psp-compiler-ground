/* cflags: -O2 -fno-merge-constants */
#include "common.h"

/* declarations recovered from DWARF (UTST99332 mpeg_ezmpegstr display) */
typedef char SceChar8;
typedef int SceInt32;
typedef struct t_displayBuffer t_displayBuffer;
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
typedef void SceVoid;
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_soundBuffer t_soundBuffer;
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

static SceInt32 swap_buffer(SceChar8 *buffer);
SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 disp_size, SceInt32 disp_num);
SceInt32 dispbuf_setPts(t_displayBuffer *pDisp, SceUInt32 pts);
SceInt32 dispbuf_getPts(t_displayBuffer *pDisp, SceUInt32 *pPts);
SceInt32 dispbuf_getCapacity(t_displayBuffer *pDisp);
SceInt32 dispbuf_getCurrentCount(t_displayBuffer *pDisp);
SceInt32 dispbuf_setMode(t_displayBuffer *pDisp, SceInt32 mode);
SceInt32 dispbuf_getMode(t_displayBuffer *pDisp);
static SceInt32 dispbuf_show(t_displayBuffer *pDisp);

int inv_movie_result_disp(void *p);
void *inv_movie_result_addr(void);
void psp_free(void *p);
static SceInt32 swap_buffer(SceChar8 *buf)
{
	SceChar8 *tmp;

	sceDmacMemcpy(displayBuf[0], buf, 0x88000);
	if (inv_movie_result_disp(buf + 0x80000) == 1) {
		sceDmacMemcpy(displayBuf[0] + 0x80000, inv_movie_result_addr(), 0x3800);
	}
	sceDisplaySetFrameBuf(displayBuf[0], 512, 3, 1);
	tmp = displayBuf[0];
	displayBuf[0] = displayBuf[1];
	displayBuf[1] = tmp;
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_create);

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
	int i;

	sceKernelDeleteSema(pDisp->lock_sema);
	if (pDisp->buf != NULL) {
		for (i = 0; i < pDisp->size; i++) {
			if (pDisp->buf[i] != NULL) {
				psp_free(pDisp->buf[i]);
			}
		}
		psp_free(pDisp->buf);
	}
	if (pDisp->pts != NULL) {
		psp_free(pDisp->pts);
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
	sceKernelWaitSemaCB(pDisp->lock_sema, 1, 0);
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

SceInt32 dispbuf_display(t_avSyncControl *pAvSync)
{
	t_displayBuffer *pDisp = pAvSync->pDisp;

	dispbuf_setMode(pDisp, avsync_Compare(pAvSync));
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

static SceInt32 dispbuf_show(t_displayBuffer *pDisp)
{
	if (dispbuf_getMode(pDisp) == 1) {
		swap_buffer(pDisp->buf[pDisp->read]);
		pDisp->read = (pDisp->read + 1) % pDisp->size;
		sceKernelPowerTick(0);
		sceDisplayWaitVblankStartCB();
	} else {
		pDisp->read = (pDisp->read + 1) % pDisp->size;
	}
	return 0;
}

