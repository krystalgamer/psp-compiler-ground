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

typedef struct {
	int current;
	int page;
	int pos;
	int selected;
	int saved;
} MENU_LIST;

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

extern MENU_LIST menu_list;
extern DISP_ENV dispenv;
extern int frame_count;
extern int frame_loss;
extern int prevcur;
extern int blinkframe;
extern int not_ready;
extern int ablinkframe;
extern int ablinkdir;
extern SceChar8 disp_list[65536];

void *sceGeEdramGetAddr(void);
static int init_all(t_displayBuffer *pDisp);
static void draw_frame(t_displayBuffer *pDisp, SceChar8 *buffer);
static SceInt32 dispbuf_isEnd(t_displayBuffer *pDisp);
SceInt32 dispbuf_scale(t_displayBuffer *pDisp, int scale);
SceInt32 dispbuf_pos(t_displayBuffer *pDisp, int x, int y);

static int init_all(t_displayBuffer *pDisp)
{
	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuDrawBuffer(3, (void *)0, 512);
	sceGuDispBuffer(480, 272, (void *)0x88000, 512);
	sceGuOffset(0, 0);
	sceGuScissor(0, 0, 480, 272);
	sceGuEnable(2);
	sceGuDisable(1);
	sceGuTexFunc(0, 1);
	sceGuTexFilter(1, 1);
	sceGuTexWrap(0, 0);
	sceGuEnable(9);
	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuDisable(4);
	sceGuColor(0xFFFFFFFF);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuClearColor(0);
	sceGuFinish();
	sceGuSync(0, 0);
	sceDisplayWaitVblankStart();
	sceGuDisplay(1);
	return 0;
}

#ifdef NON_MATCHING
/* the original loads ablinkframe after the blinkframe if; ours hoists the load */
static unsigned char set_blink(void)
{
	int val;

	if (blinkframe < 9) {
		val = blinkframe * 255 / 8;
		blinkframe++;
	} else {
		val = 255;
	}
	if (ablinkframe >= 9)
		ablinkdir = -1;
	if (ablinkframe < 0)
		ablinkdir = 1;
	ablinkframe += ablinkdir;
	return val;
}
#else
INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/display", set_blink);
#endif

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/display", draw_menu);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/display", draw_frame);

#ifdef NON_MATCHING
/* only two stores swapped by the scheduler */
SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 disp_size, SceInt32 disp_num, SceInt32 pixelFormat)
{
	SceChar8 *ge_addr;

	pDisp->buf = NULL;
	pDisp->start_sema = sceKernelCreateSema("start_sema", 0, 0, 1, NULL);
	pDisp->lock_sema = sceKernelCreateSema("lock_sema", 0, 1, 1, NULL);
	pDisp->display_wait_sema = sceKernelCreateSema("display_wait_sema", 0, 0, 1, NULL);
	pDisp->buf = malloc(disp_num * sizeof(SceChar8 *));
	if (pDisp->buf == NULL)
		return -1;
	pDisp->pts = malloc(disp_num * sizeof(SceUInt32));
	if (pDisp->pts == NULL) {
		if (pDisp->buf)
			free(pDisp->buf);
		return -1;
	}
	ge_addr = (SceChar8 *)sceGeEdramGetAddr() + 0x110000;
	pDisp->buf[0] = ge_addr;
	pDisp->buf[1] = ge_addr + 0x88000;
	pDisp->pixelFormat = pixelFormat;
	dispenv.size = disp_num;
	pDisp->write = &dispenv.write;
	pDisp->read = &dispenv.read;
	pDisp->count = &dispenv.count;
	pDisp->size = &dispenv.size;
	pDisp->scale = &dispenv.scale;
	pDisp->posx = &dispenv.posx;
	pDisp->posy = &dispenv.posy;
	pDisp->displayMode = &dispenv.mode;
	return 0;
}
#else
INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/display", dispbuf_create);
#endif

SceInt32 dispbuf_init(t_displayBuffer *pDisp)
{
	if (init_all(pDisp) != 0) {
		puts("fatal error : init_all()");
		return -1;
	}
	frame_count = 0;
	frame_loss = 0;
	if (menu_list.current != prevcur) {
		prevcur = menu_list.current;
		blinkframe = 0;
	}
	*pDisp->write = 0;
	*pDisp->read = 0;
	*pDisp->count = 0;
	*pDisp->scale = 0;
	*pDisp->posx = 0;
	*pDisp->posy = 0;
	*pDisp->displayMode = 1;
	sceKernelPollSema(pDisp->start_sema, 1);
	sceKernelPollSema(pDisp->display_wait_sema, 1);
	return 0;
}

SceInt32 dispbuf_end(t_displayBuffer *pDisp)
{
	sceKernelDeleteSema(pDisp->start_sema);
	sceKernelDeleteSema(pDisp->lock_sema);
	sceKernelDeleteSema(pDisp->display_wait_sema);
	if (pDisp->buf)
		free(pDisp->buf);
	if (pDisp->pts)
		free(pDisp->pts);
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

static SceInt32 dispbuf_isEnd(t_displayBuffer *pDisp)
{
	return dispbuf_getMode(pDisp) == 0xFF;
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

SceInt32 dispbuf_setMode(t_displayBuffer *pDisp, SceInt32 mode)
{
	*pDisp->displayMode = mode;
	return 0;
}

SceInt32 dispbuf_getMode(t_displayBuffer *pDisp)
{
	return *pDisp->displayMode;
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

	if (*pDisp->displayMode == 1) {
		buffer = *pDisp->buf;
		draw_frame(pDisp, buffer);
		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();
	}
	return 0;
}

SceInt32 dispbuf_scale(t_displayBuffer *pDisp, int scale)
{
	*pDisp->scale = scale;
	return 0;
}

SceInt32 dispbuf_pos(t_displayBuffer *pDisp, int x, int y)
{
	*pDisp->posx = x;
	*pDisp->posy = y;
	return 0;
}

SceInt32 dispbuf_func(SceSize size, void *argp)
{
	SceInt32 currentMode;
	t_avSyncControl *pAvSync;
	t_displayBuffer *pDisp;

	pAvSync = (t_avSyncControl *)argp;
	pDisp = pAvSync->pDisp;
	not_ready = 1;
	while (sceKernelPollSema(pDisp->start_sema, 1) != 0) {
		dispbuf_show(pDisp);
		sceDisplayWaitVblankStart();
	}
	not_ready = 0;

	while (!dispbuf_isEnd(pDisp)) {
		currentMode = dispbuf_getMode(pDisp);
		if (currentMode != 4) {
			currentMode = avsync_Compare(pAvSync);
			dispbuf_setMode(pDisp, currentMode);
		}
		if (dispbuf_getCurrentCount(pDisp) > 0) {
			if (currentMode == 1 || currentMode == 2) {
				dispbuf_show(pDisp);
				sceKernelWaitSema(pDisp->lock_sema, 1, NULL);
				(*pDisp->count)--;
				sceKernelSignalSema(pDisp->lock_sema, 1);
			}
			sceKernelSignalSema(pDisp->display_wait_sema, 1);
			frame_count++;
		} else {
			frame_loss++;
		}
		sceDisplayWaitVblankStart();
	}

	while (dispbuf_getCurrentCount(pDisp) > 0) {
		dispbuf_show(pDisp);
		sceKernelWaitSema(pDisp->lock_sema, 1, NULL);
		(*pDisp->count)--;
		sceKernelSignalSema(pDisp->lock_sema, 1);
		sceDisplayWaitVblankStart();
		frame_count++;
	}

	sceDisplayWaitVblankStart();
	sceGuSwapBuffers();
	sceKernelExitThread(0);
	return 0;
}
