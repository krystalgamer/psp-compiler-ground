/* cflags: -O2 -fno-merge-constants */
#include "common.h"
#include <libgu.h>
void UtilsSpriteMode(int sw, int sh, int dw, int dh);
void UtilsDrawSprite(int x, int y, int z, int u, int v, int flip, int rotate);
void UtilsDrawSpriteF(float x, float y, float z, int u, int v, int flip, int rotate);

/* declarations recovered from DWARF */
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
typedef int SceInt32;
struct t_displayBuffer { /* size 0x38 */
    SceUID start_sema;
    SceUID lock_sema;
    SceUID display_wait_sema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 *write;
    SceInt32 *read;
    SceInt32 *count;
    SceInt32 *size;
    SceInt32 pixelFormat;
    SceInt32 *displayMode;
    SceInt32 *scale;
    SceInt32 *posx;
    SceInt32 *posy;
};
struct _anon1;
struct _anon1 { /* size 0x1c */
    int thumbpts;
    int fullptss;
    int fullpts;
    int fullptse;
    void *texture;
    int posx;
    int posy;
};
typedef struct _anon1 MOVIE_LIST;
struct _anon2;
struct _anon2 { /* size 0xc */
    void *pix;
    int w;
    int h;
};
typedef struct _anon2 GRID_ENV;
struct _anon3;
struct _anon3 { /* size 0x1c */
    void *pix;
    void *ipix;
    int w;
    int h;
    int tw;
    int sw;
    int sh;
};
typedef struct _anon3 NAME_ENV;
typedef unsigned int u_int32;
typedef unsigned int SceSize;
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_soundBuffer t_soundBuffer;
struct t_soundBuffer;
struct t_soundBuffer { /* size 0x24 */
    SceUID lock_sema;
    SceInt32 *terminate_flag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 *write;
    SceInt32 *read;
    SceInt32 *count;
    SceInt32 *size;
    SceUID start_sema;
};
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x14 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
};
struct t_avSyncControl { /* size 0x1c */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};
struct _anon4;
struct _anon4 { /* size 0x14 */
    int current;
    int page;
    int pos;
    int selected;
    int saved;
};
typedef struct _anon4 MENU_LIST;
struct _anon5;
struct _anon5 { /* size 0x20 */
    int write;
    int read;
    int count;
    int size;
    int scale;
    int posx;
    int posy;
    int mode;
};
typedef struct _anon5 DISP_ENV;
struct _anon6;
struct _anon6 { /* size 0x20 */
    int lx;
    int ly;
    int lw;
    int lh;
    int rx;
    int ry;
    int rw;
    int rh;
};
typedef struct _anon6 SPRT_ENV;

extern MOVIE_LIST movie_list[];
extern MENU_LIST menu_list;
extern unsigned int pix_BG[];
extern unsigned int clut_BG[];
extern unsigned int pix_grid1[];
extern unsigned int pix_grid2[];
extern unsigned int pix_grid3[];
extern unsigned int pix_focus[];
extern unsigned int clut_focus[];
extern unsigned int pix_arrow[];
extern unsigned int pix_line[];
extern unsigned int pix_ceroall[];
extern unsigned int pix_cerores[];
extern unsigned int pix_playall[];
extern unsigned int pix_arm[];
extern unsigned int pix_vampire[];
extern unsigned int pix_gaga[];
extern unsigned int pix_sangoku[];
extern unsigned int pix_talkman[];
extern unsigned int pix_toro[];
extern unsigned int pix_puyo[];
extern unsigned int pix_maj[];
extern unsigned int pix_golf[];
extern unsigned int pix_metal[];
extern unsigned int pix_moji[];
extern unsigned int pix_ridge[];
extern unsigned int pix_rengoku[];
extern DISP_ENV dispenv;
extern int frame_count;
extern int frame_loss;
extern int not_ready;
extern int blinkframe;
extern int ablinkframe;
extern int ablinkdir;
extern int prevcur;
extern GRID_ENV grid[3];
extern NAME_ENV name[14];
extern SPRT_ENV sprt;
extern SceChar8 disp_list[65536];

static int init_all(t_displayBuffer *pDisp);
static void set_blink(void);
static void draw_menu(void);
static void draw_frame(t_displayBuffer *pDisp, SceChar8 *buffer);
SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 disp_size, SceInt32 disp_num, SceInt32 pixelFormat);
SceInt32 dispbuf_init(t_displayBuffer *pDisp);
SceInt32 dispbuf_end(t_displayBuffer *pDisp);
SceInt32 dispbuf_getDrawbuf(t_displayBuffer *pDisp, SceChar8 **buffer);
SceInt32 dispbuf_dataSet(t_displayBuffer *pDisp);
SceInt32 dispbuf_getCapacity(t_displayBuffer *pDisp);
SceInt32 dispbuf_getCurrentCount(t_displayBuffer *pDisp);
static SceInt32 dispbuf_isEnd(t_displayBuffer *pDisp);
SceInt32 dispbuf_setPts(t_displayBuffer *pDisp, SceUInt32 pts);
SceInt32 dispbuf_getPts(t_displayBuffer *pDisp, SceUInt32 *pPts);
SceInt32 dispbuf_setMode(t_displayBuffer *pDisp, SceInt32 mode);
SceInt32 dispbuf_getMode(t_displayBuffer *pDisp);
SceInt32 dispbuf_decode_sleep(t_displayBuffer *pDisp);
SceInt32 dispbuf_setStartFlag(t_displayBuffer *pDisp);
SceInt32 dispbuf_show(t_displayBuffer *pDisp);
SceInt32 dispbuf_scale(t_displayBuffer *pDisp, int scale);
SceInt32 dispbuf_pos(t_displayBuffer *pDisp, int x, int y);
SceInt32 dispbuf_func(SceSize size, void *argp);


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
	sceGuTexWrap(1, 1);
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

extern unsigned char blinkalpha;

static void set_blink(void)
{
	int c;

	c = blinkframe * 255 / 8;
	if (blinkframe >= 9)
		c = 255;
	else
		blinkframe++;

	if (ablinkframe >= 9)
		ablinkdir = -1;

	if (ablinkframe < 0)
		ablinkdir = 1;

	ablinkframe += ablinkdir;
	blinkalpha = c;
}

typedef struct {
	void *pix;
	void *ipix;
	int w;
	int h;
	int sw;
	int sh;
} PAL_NAME_ENV;
extern unsigned int D_002733C0[];
extern unsigned int D_002731C0[];
extern GRID_ENV D_00273094[3];
extern SPRT_ENV D_002A23E4;
extern unsigned int D_00294FE0[];
extern unsigned int D_00295FE0[];
extern PAL_NAME_ENV D_002730AC[];
extern unsigned int D_002931E0[];
extern unsigned int D_002931C0[];

static void draw_menu(void)
{
	MOVIE_LIST *pMv;
	GRID_ENV *pg;
	PAL_NAME_ENV *pn;
	u_int32 col;
	int i;
	int n;
	float x;
	float y;

	sceGuTexFunc(0, 1);
	col = (blinkalpha << 24) | 0xFFFFFF;
	sceGuColor(0xFFFFFFFF);
	sceGuEnable(9);
	sceGuDisable(4);
	sceGuTexMode(5, 0, 0, 0);
	sceGuTexImage(0, 512, 512, 480, D_002733C0);
	sceGuClutMode(1, 0, 0xFF, 0);
	sceGuClutLoad(16, D_002731C0);
	UtilsSpriteMode(480, 272, 480, 272);
	UtilsDrawSprite(0, 0, 0, 0, 0, 0, 0);

	sceGuEnable(9);
	sceGuEnable(4);
	sceGuTexMode(3, 0, 0, 1);
	UtilsSpriteMode(0x90, 0x50, 0x8F, 0x51);
	pMv = &movie_list[menu_list.page * 6];
	for (i = 0; i < 6; i++, pMv++) {
		n = menu_list.page * 6 + i;
		if (n >= 11)
			break;
		if (n != 0) {
			sceGuTexImage(0, 256, 128, 144, pMv->texture);
			UtilsDrawSprite(pMv->posx, pMv->posy, 0, 0, 0, 0, 0);
		}
	}

	sceGuEnable(9);
	sceGuEnable(4);
	sceGuTexMode(3, 0, 0, 1);
	pg = &D_00273094[menu_list.page];
	sceGuTexImage(0, 512, 256, 480, pg->pix);
	UtilsSpriteMode(pg->w, pg->h, pg->w, pg->h);
	UtilsDrawSprite(0, 16, 0, 0, 0, 0, 0);

	sceGuTexMode(3, 0, 0, 1);
	sceGuEnable(9);
	sceGuEnable(4);
	UtilsSpriteMode(23, 23, D_002A23E4.lw - ablinkframe / 2, D_002A23E4.lh - ablinkframe / 2);
	sceGuTexImage(0, 32, 32, 32, D_00294FE0);
	if (menu_list.page > 0) {
		x = D_002A23E4.lx + (ablinkframe * 2) * 0.125f;
		y = D_002A23E4.ly + (ablinkframe * 2) * 0.125f;
		UtilsDrawSpriteF(x, y, 0.0f, 1, 1, 1, 0);
	}
	if (menu_list.page <= 0) {
		x = D_002A23E4.rx + (ablinkframe * 2) * 0.125f;
		y = D_002A23E4.ry + (ablinkframe * 2) * 0.125f;
		UtilsDrawSpriteF(x, y, 0.0f, 1, 1, 0, 0);
	}

	sceGuEnable(9);
	sceGuEnable(4);
	sceGuTexMode(3, 0, 0, 1);
	sceGuTexImage(0, 512, 32, 392, D_00295FE0);
	UtilsSpriteMode(392, 32, 392, 32);
	UtilsDrawSprite(0, 198, 0, 0, 0, 0, 0);

	sceGuColor(col);
	sceGuEnable(9);
	sceGuEnable(4);
	sceGuTexMode(3, 0, 0, 1);
	pn = &D_002730AC[menu_list.current];
	sceGuTexImage(0, pn->w, pn->h, pn->sw, pn->pix);
	UtilsSpriteMode(pn->sw, pn->sh, pn->sw, pn->sh);
	UtilsDrawSprite(14, 200, 0, 0, 0, 0, 0);
	if (pn->ipix != NULL) {
		sceGuTexImage(0, 64, 64, 64, pn->ipix);
		UtilsSpriteMode(64, 64, 64, 64);
		UtilsDrawSprite(414, 202, 0, 0, 0, 0, 0);
	}

	sceGuColor(col);
	sceGuEnable(9);
	sceGuEnable(4);
	sceGuTexMode(4, 0, 0, 0);
	sceGuTexImage(0, 256, 128, 160, D_002931E0);
	sceGuClutMode(1, 0, 0xFF, 0);
	sceGuClutLoad(1, D_002931C0);
	UtilsSpriteMode(160, 93, 160, 93);
	pMv = &movie_list[menu_list.current];
	UtilsDrawSprite(pMv->posx - 6, pMv->posy - 6, 0, 0, 0, 0, 0);
}

static void draw_frame(t_displayBuffer *pDisp, SceChar8 *buffer)
{
	sceGuStart(0, disp_list, sizeof(disp_list));
	if (not_ready == 1 || menu_list.selected == 0)
	{
		set_blink();
		draw_menu();
	}
	sceGuEnable(4);
	sceGuColor((blinkalpha << 24) | 0xFFFFFF);
	sceGuTexFunc(0, 0);
	sceGuTexMode(3, 0, 0, 0);
	if (not_ready == 1) {
		if (menu_list.current == menu_list.saved && menu_list.current != 0) {
			sceGuTexImage(0, 512, 512, 512, pDisp->buf[1]);
			UtilsSpriteMode(0x90, 0x50, 0x8F, 0x51);
			UtilsDrawSprite(*pDisp->posx, *pDisp->posy, 0, 0, 0, 0, 0);
		}
	} else {
		sceGuTexImage(0, 512, 512, 512, buffer);
		if (*pDisp->scale == 0) {
			if (menu_list.current != 0) {
				UtilsSpriteMode(0x90, 0x50, 0x8F, 0x51);
				UtilsDrawSprite(*pDisp->posx, *pDisp->posy, 0, 0, 0, 0, 0);
				sceGuCopyImage(3, 0, 0, 0x90, 0x50, 512, pDisp->buf[0], 0, 0, 512, pDisp->buf[1]);
				menu_list.saved = menu_list.current;
			}
		} else {
			UtilsSpriteMode(0x1E0, 0x110, 0x1E0, 0x110);
			UtilsDrawSprite(0, 0, 0, 0, 0, 0, 0);
		}
	}
	sceGuFinish();
	sceGuSync(0, 0);
}

int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);
void *malloc(unsigned int size);
void free(void *p);
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
	pDisp->write = &dispenv.write;
	pDisp->read = &dispenv.read;
	pDisp->count = &dispenv.count;
	pDisp->size = &dispenv.size;
	pDisp->scale = &dispenv.scale;
	pDisp->posx = &dispenv.posx;
	pDisp->posy = &dispenv.posy;
	pDisp->displayMode = &dispenv.mode;
	*pDisp->size = disp_num;
	return 0;
}

int puts(const char *s);
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

int sceKernelDeleteSema(int semid);
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

int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
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

void *sceGuSwapBuffers(void);
int sceDisplayWaitVblankStart(void);
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
