#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread.h>
#include <displaysvc.h>
#include "display.h"

static SceInt32 dispbuf_isEnd(t_displayBuffer *pDisp);
SceInt32 dispbuf_scale(t_displayBuffer *pDisp, int scale);
SceInt32 dispbuf_pos(t_displayBuffer *pDisp, int x, int y);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/display", init_all);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/display", set_blink);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/display", draw_menu);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/display", draw_frame);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/display", dispbuf_create);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/display", dispbuf_init);

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

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/display", dispbuf_show);

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

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/display", dispbuf_func);
