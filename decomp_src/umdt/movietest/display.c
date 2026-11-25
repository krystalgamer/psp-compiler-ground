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

void *sceGeEdramGetAddr(void);
static int init_all(t_displayBuffer *pDisp);
static void draw_frame(t_displayBuffer *pDisp, SceChar8 *buffer);
static SceInt32 dispbuf_isEnd(t_displayBuffer *pDisp);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/display", dispbuf_create);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/display", dispbuf_init);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/display", dispbuf_end);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/display", dispbuf_getDrawbuf);

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

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/display", dispbuf_setDemuxEnd);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/display", dispbuf_isEnd);

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/display", display_func);

SceInt32 dispbuf_decode_sleep(t_displayBuffer *pDisp)
{
	return sceKernelWaitSema(pDisp->display_wait_sema, 1, NULL);
}

SceInt32 dispbuf_setStartFlag(t_displayBuffer *pDisp)
{
	return sceKernelSignalSema(pDisp->start_sema, 1);
}

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/display", dispbuf_show);
