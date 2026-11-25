#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread.h>
#include <displaysvc.h>
#include <power.h>
#include "display.h"
#include "sound.h"
#include "avsync.h"

extern SceInt32 display_write;
extern SceInt32 display_read;
extern SceInt32 display_count;
extern SceInt32 display_size;
extern SceInt32 display_mode;
extern SceInt32 frame_count;
extern SceInt32 frame_loss;

static SceInt32 dispbuf_isEnd(t_displayBuffer *pDisp);

SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 disp_size, SceInt32 disp_num)
{
	SceInt32 i;
	SceInt32 ret;

	pDisp->buf = NULL;
	pDisp->pts = NULL;

	ret = sceDisplaySetMode(0, 480, 272);
	if (ret < 0)
		goto ERROR;

	pDisp->start_sema = sceKernelCreateSema("start_sema", 0, 0, 1, NULL);
	pDisp->lock_sema = sceKernelCreateSema("lock_sema", 0, 1, 1, NULL);
	pDisp->display_wait_sema = sceKernelCreateSema("display_wait_sema", 0, 0, 1, NULL);

	pDisp->buf = malloc(disp_num * sizeof(SceChar8 *));
	if (pDisp->buf == NULL) {
		ret = -1;
		goto ERROR;
	}
	for (i = 0; i < disp_num; i++)
		pDisp->buf[i] = NULL;
	for (i = 0; i < disp_num; i++) {
		pDisp->buf[i] = memalign(16, disp_size);
		if (pDisp->buf[i] == NULL) {
			ret = -1;
			goto ERROR;
		}
	}

	pDisp->pts = malloc(disp_num * sizeof(SceUInt32));
	if (pDisp->pts == NULL) {
		ret = -1;
		goto ERROR;
	}

	pDisp->write = &display_write;
	pDisp->read = &display_read;
	pDisp->count = &display_count;
	pDisp->size = &display_size;
	pDisp->displayMode = &display_mode;
	display_size = disp_num;
	return ret;

ERROR:
	if (pDisp->buf) {
		for (i = 0; i < *pDisp->size; i++) {
			if (pDisp->buf[i])
				free(pDisp->buf[i]);
		}
		free(pDisp->buf);
	}
	if (pDisp->pts)
		free(pDisp->pts);
	return ret;
}

SceInt32 dispbuf_init(t_displayBuffer *pDisp)
{
	SceInt32 ret;

	frame_count = 0;
	frame_loss = 0;
	*pDisp->write = 0;
	*pDisp->read = 0;
	*pDisp->count = 0;
	dispbuf_setMode(pDisp, 1);
	sceKernelPollSema(pDisp->start_sema, 1);
	sceKernelPollSema(pDisp->display_wait_sema, 1);
	ret = sceDisplaySetMode(0, 480, 272);
	if (ret < 0)
		puts("error");
	sceDisplaySetFrameBuf(0, 512, 3, 1);
	return 0;
}

SceInt32 dispbuf_end(t_displayBuffer *pDisp)
{
	SceInt32 i;

	if (pDisp->buf) {
		for (i = 0; i < *pDisp->size; i++) {
			if (pDisp->buf[i])
				free(pDisp->buf[i]);
		}
		free(pDisp->buf);
	}
	if (pDisp->pts)
		free(pDisp->pts);
	sceKernelDeleteSema(pDisp->start_sema);
	sceKernelDeleteSema(pDisp->lock_sema);
	sceKernelDeleteSema(pDisp->display_wait_sema);
	return 0;
}

SceInt32 dispbuf_getDrawbuf(t_displayBuffer *pDisp, SceChar8 **buffer)
{
	SceInt32 ret;

	ret = dispbuf_getCapacity(pDisp);
	if (ret > 0)
		*buffer = pDisp->buf[*pDisp->write];
	else
		*buffer = NULL;
	return ret;
}

SceInt32 dispbuf_setPts(t_displayBuffer *pDisp, SceUInt32 pts)
{
	SceInt32 ret = 0;

	pDisp->pts[*pDisp->write] = pts;
	return ret;
}

SceInt32 dispbuf_getPts(t_displayBuffer *pDisp, SceUInt32 *pPts)
{
	SceInt32 ret = 0;

	*pPts = pDisp->pts[*pDisp->read];
	return ret;
}

SceInt32 dispbuf_dataSet(t_displayBuffer *pDisp)
{
	sceKernelWaitSema(pDisp->lock_sema, 1, NULL);
	(*pDisp->count)++;
	*pDisp->write = (*pDisp->write + 1) % *pDisp->size;
	sceKernelSignalSema(pDisp->lock_sema, 1);
	return 0;
}

SceInt32 dispbuf_getCapacity(t_displayBuffer *pDisp)
{
	return *pDisp->size - *pDisp->count;
}

SceInt32 dispbuf_getCurrentCount(t_displayBuffer *pDisp)
{
	return *pDisp->count;
}

static SceInt32 dispbuf_isEnd(t_displayBuffer *pDisp)
{
	return dispbuf_getMode(pDisp) == 0xFF;
}

SceInt32 dispbuf_setMode(t_displayBuffer *pDisp, SceInt32 mode)
{
	*pDisp->displayMode = mode;
	return 0;
}

SceInt32 dispbuf_getMode(t_displayBuffer *pDisp)
{
	return *pDisp->displayMode;
}

SceInt32 display_func(SceSize size, void *argp)
{
	SceInt32 firstFlag;
	SceInt32 currentMode;
	t_avSyncControl *pAvSync;
	t_displayBuffer *pDisp;

	pAvSync = (t_avSyncControl *)argp;
	pDisp = pAvSync->pDisp;
	firstFlag = 1;

	sceKernelWaitSema(pDisp->start_sema, 1, NULL);

	while (!dispbuf_isEnd(pDisp)) {
		currentMode = dispbuf_getMode(pDisp);
		if (currentMode != 4) {
			currentMode = avsync_Compare(pAvSync);
			dispbuf_setMode(pDisp, currentMode);
		}
		if (dispbuf_getCurrentCount(pDisp) > 0) {
			if (currentMode == 1 || currentMode == 2) {
				dispbuf_show(pDisp);
				if (firstFlag) {
					firstFlag = 0;
				} else {
					sceKernelWaitSema(pDisp->lock_sema, 1, NULL);
					(*pDisp->count)--;
					sceKernelSignalSema(pDisp->lock_sema, 1);
				}
			}
			sceKernelSignalSema(pDisp->display_wait_sema, 1);
			frame_count++;
		} else {
			frame_loss++;
		}
		sceDisplayWaitVblankStartCB();
	}

	while (dispbuf_getCurrentCount(pDisp) >= 2) {
		dispbuf_show(pDisp);
		sceKernelWaitSema(pDisp->lock_sema, 1, NULL);
		(*pDisp->count)--;
		sceKernelSignalSema(pDisp->lock_sema, 1);
		sceDisplayWaitVblankStartCB();
		frame_count++;
	}

	sceDisplaySetFrameBuf(0, 512, 3, 1);
	printf("frame count = %d\n", frame_count);
	printf("frame loss  = %d\n", frame_loss);
	sceKernelExitThread(0);
	return 0;
}

SceInt32 dispbuf_decode_sleep(t_displayBuffer *pDisp)
{
	return sceKernelWaitSema(pDisp->display_wait_sema, 1, NULL);
}

SceInt32 dispbuf_setStartFlag(t_displayBuffer *pDisp)
{
	return sceKernelSignalSema(pDisp->start_sema, 1);
}

SceInt32 dispbuf_show(t_displayBuffer *pDisp)
{
	SceChar8 *buffer;

	sceKernelPowerTick(0);
	if (dispbuf_getMode(pDisp) == 1) {
		buffer = pDisp->buf[*pDisp->read];
		sceDisplaySetFrameBuf(buffer, 512, 3, 1);
		sceDisplayWaitVblankStartCB();
	}
	*pDisp->read = (*pDisp->read + 1) % *pDisp->size;
	return 0;
}
