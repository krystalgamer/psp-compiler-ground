/* cflags: -O0 */
#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread.h>
#include <displaysvc.h>
#include <libgu.h>
#include "display.h"
#include "sound.h"
#include "avsync.h"
#include "menu.h"
#include "utils.h"

typedef struct {
	int write;
	int read;
	int count;
	int size;
	int scale;
	int posx;
	int posy;
	int mode;
} DISP_ENV;

typedef struct {
	void *pix;
	int w;
	int h;
} GRID_ENV;

typedef struct {
	void *pix;
	void *ipix;
	int w;
	int h;
	int tw;
	int sw;
	int sh;
} NAME_ENV;

typedef struct {
	int lx;
	int ly;
	int lw;
	int lh;
	int rx;
	int ry;
	int rw;
	int rh;
} SPRT_ENV;

extern MOVIE_LIST movie_list[12];
extern MENU_LIST menu_list;
extern unsigned int pix_BG[];
extern unsigned int clut_BG[];
extern unsigned int pix_focus[];
extern unsigned int clut_focus[];
extern unsigned int pix_arrow[];
extern unsigned int pix_line[];
extern GRID_ENV grid[3];
extern NAME_ENV name[12];
extern SPRT_ENV sprt;
extern DISP_ENV dispenv;
extern int frame_count;
extern int frame_loss;
extern int prevcur;
extern int blinkframe;
extern int not_ready;
extern int ablinkframe;
extern int ablinkdir;
extern SceChar8 disp_list[65536];
extern SceUID _fplid_73D8[2];
extern SceInt32 display_terminate_flag;
extern SceInt32 display_write;
extern SceInt32 display_read;
extern SceInt32 display_count;
extern SceInt32 display_size;

void *sceGeEdramGetAddr(void);
static int init_all(t_displayBuffer *pDisp);
static void draw_frame(t_displayBuffer *pDisp, SceChar8 *buffer);
static SceInt32 dispbuf_isEnd(t_displayBuffer *pDisp);

SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 disp_size, SceInt32 disp_num, SceUID sync_sema)
{
	SceInt32 i;
	SceInt32 ret;
	void *addr;
	SceInt32 err;
	char msg1[112];
	char msg2[112];
	char msg3[112];

	pDisp->buf = NULL;
	ret = sceDisplaySetMode(0, 480, 272);
	if (ret < 0)
		return -1;
	pDisp->start_sema = sceKernelCreateSema("start_sema", 0, 0, 1, NULL);
	pDisp->lock_sema = sceKernelCreateSema("lock_sema", 0, 1, 1, NULL);
	pDisp->display_wait_sema = sceKernelCreateSema("display_wait_sema", 0, 0, 1, NULL);
	_fplid_73D8[0] = sceKernelCreateFpl("MovieTestDisplay1Fpl", 2, 0x100, disp_num * 4, 1, NULL);
	if (_fplid_73D8[0] < 0) {
		sprintf(msg1, "Display sceKernelCreateFpl 1 = %08X", _fplid_73D8[0]);
		sceIoWrite(0, msg1, strlen(msg1));
		_fplid_73D8[0] = 0;
		return -1;
	}
	err = sceKernelTryAllocateFpl(_fplid_73D8[0], (void **)&pDisp->buf);
	if (err < 0) {
		sprintf(msg2, "Display sceKernelTryAllocateFpl 1 = %08X", err);
		sceIoWrite(0, msg2, strlen(msg2));
		return -1;
	}
	_fplid_73D8[1] = sceKernelCreateFpl("MovieTest2DisplayFpl", 2, 0x100, disp_size * disp_num + 16, 1, NULL);
	if (_fplid_73D8[1] < 0) {
		sprintf(msg2, "Display sceKernelCreateFpl 2 = %08X", _fplid_73D8[1]);
		sceIoWrite(0, msg2, strlen(msg2));
		_fplid_73D8[1] = 0;
		return -1;
	}
	err = sceKernelTryAllocateFpl(_fplid_73D8[1], &addr);
	if (err < 0) {
		sprintf(msg3, "Display sceKernelTryAllocateFpl 2 = %08X", err);
		sceIoWrite(0, msg3, strlen(msg3));
		return -1;
	}
	addr = (void *)(((unsigned int)addr + 15) & ~15);
	for (i = 0; i < disp_num; i++)
		pDisp->buf[i] = (SceChar8 *)addr + disp_size * i;
	pDisp->terminate_flag = &display_terminate_flag;
	pDisp->write = &display_write;
	pDisp->read = &display_read;
	pDisp->count = &display_count;
	pDisp->size = &display_size;
	pDisp->sync_sema = sync_sema;
	*pDisp->size = disp_num;
	return 0;
}

SceInt32 dispbuf_init(t_displayBuffer *pDisp)
{
	frame_count = 0;
	frame_loss = 0;
	*pDisp->terminate_flag = 0;
	*pDisp->write = 0;
	*pDisp->read = 0;
	*pDisp->count = 0;
	sceKernelPollSema(pDisp->start_sema, 1);
	sceKernelPollSema(pDisp->display_wait_sema, 1);
	sceKernelPollSema(pDisp->sync_sema, 1);
	sceDisplaySetFrameBuf(NULL, 512, 3, 1);
	return 0;
}

SceInt32 dispbuf_end(t_displayBuffer *pDisp)
{
	if (_fplid_73D8[0]) {
		sceKernelDeleteFpl(_fplid_73D8[0]);
		_fplid_73D8[0] = 0;
	}
	if (_fplid_73D8[1]) {
		sceKernelDeleteFpl(_fplid_73D8[1]);
		_fplid_73D8[1] = 0;
	}
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

SceInt32 dispbuf_setDemuxEnd(t_displayBuffer *pDisp)
{
	*pDisp->terminate_flag = 1;
	return 0;
}

static SceInt32 dispbuf_isEnd(t_displayBuffer *pDisp)
{
	return *pDisp->terminate_flag;
}

SceInt32 display_func(SceSize size, void *argp)
{
	SceInt32 first;
	t_displayBuffer *pDisp;
	char msg1[112];
	char msg2[112];

	pDisp = (t_displayBuffer *)argp;
	first = 1;
	sceKernelWaitSema(pDisp->start_sema, 1, NULL);
	while (!dispbuf_isEnd(pDisp)) {
		if (dispbuf_getCurrentCount(pDisp) > 0) {
			dispbuf_show(pDisp);
			if (!first) {
				sceKernelWaitSema(pDisp->lock_sema, 1, NULL);
				(*pDisp->count)--;
				sceKernelSignalSema(pDisp->lock_sema, 1);
			} else {
				first = 0;
				sceKernelSignalSema(pDisp->sync_sema, 1);
			}
			sceKernelSignalSema(pDisp->display_wait_sema, 1);
			frame_count++;
		} else {
			frame_loss++;
		}
		sceDisplayWaitVblankStart();
	}
	sceKernelSignalSema(pDisp->sync_sema, 1);
	while (dispbuf_getCurrentCount(pDisp) >= 2) {
		dispbuf_show(pDisp);
		sceKernelWaitSema(pDisp->lock_sema, 1, NULL);
		(*pDisp->count)--;
		sceKernelSignalSema(pDisp->lock_sema, 1);
		sceDisplayWaitVblankStart();
		frame_count++;
	}
	sceDisplaySetFrameBuf(NULL, 512, 3, 1);
	sprintf(msg1, "frame count = %d\n", frame_count);
	sceIoWrite(0, msg1, strlen(msg1));
	sprintf(msg2, "frame loss  = %d\n", frame_loss);
	sceIoWrite(0, msg2, strlen(msg2));
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

	buffer = pDisp->buf[*pDisp->read];
	sceDisplaySetFrameBuf(buffer, 512, 3, 1);
	sceDisplayWaitVblankStart();
	*pDisp->read = (*pDisp->read + 1) % *pDisp->size;
	return 0;
}
