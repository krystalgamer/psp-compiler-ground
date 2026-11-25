#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
typedef short unsigned int u_short16;
typedef unsigned int u_int32;
struct _anon2;
struct _anon2 { /* size 0xa */
    u_short16 u;
    u_short16 v;
    short int p[3];
};
typedef struct _anon2 Gu2dVertex16T;
struct _anon1 { /* size 0x40 */
    u_short16 visible;
    short int x;
    short int y;
    short int w;
    short int h;
    short int cw;
    short int ch;
    short int bw;
    short int bh;
    short int scrollx;
    short int scrolly;
    short int __dummy;
    u_int32 color;
    u_short16 *map;
    u_int32 *chr;
    u_int32 *clut;
    u_int32 *work;
    Gu2dVertex16T model[2];
};
typedef struct _anon1 BGDATA;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
struct _scemoduleinfo;
struct _scemoduleinfo { /* size 0x34 */
    short unsigned int modattribute;
    unsigned char modversion[2];
    char modname[27];
    char terminal;
    void *gp_value;
    const void *ent_top;
    const void *ent_end;
    const void *stub_top;
    const void *stub_end;
};

extern unsigned int plt_bgmap0[8];
extern unsigned int chr_bgmap0[608];
extern short unsigned int map_bgmap0[1024];
extern unsigned int plt_bgmap1[8];
extern unsigned int chr_bgmap1[544];
extern short unsigned int map_bgmap1[1024];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char disp_list[65536];
extern int frame;
extern int select;
extern BGDATA bgdata[4];
extern u_int32 bgwork[4][65536];
extern u_int32 cont;

static void init_map(void);
static void draw_cursor(void);
static void draw_frame(void);
static int pad_read(void);


void DrawBG(BGDATA *bg);

static void init_map(void)
{
	BGDATA *bg;

	bg = bgdata;
	bg->visible = 1;
	bg->x = 16;
	bg->y = 16;
	bg->w = 32;
	bg->h = 32;
	bg->cw = 16;
	bg->ch = 16;
	bg->bw = 256;
	bg->bh = 128;
	bg->scrollx = 0;
	bg->scrolly = 0;
	bg->color = 0xffffffff;
	bg->map = map_bgmap0;
	bg->chr = chr_bgmap0;
	bg->clut = plt_bgmap0;
	bg->work = bgwork[0];
	bg++;
	bg->visible = 1;
	bg->x = 80;
	bg->y = 54;
	bg->w = 32;
	bg->h = 32;
	bg->cw = 16;
	bg->ch = 16;
	bg->bw = 256;
	bg->bh = 128;
	bg->scrollx = 8;
	bg->scrolly = 8;
	bg->color = 0xffffffff;
	bg->map = map_bgmap1;
	bg->chr = chr_bgmap1;
	bg->clut = plt_bgmap1;
	bg->work = bgwork[1];
	bg++;
	bg->visible = 1;
	bg->x = 144;
	bg->y = 92;
	bg->w = 32;
	bg->h = 32;
	bg->cw = 16;
	bg->ch = 16;
	bg->bw = 256;
	bg->bh = 128;
	bg->scrollx = 8;
	bg->scrolly = 8;
	bg->color = 0xffffffff;
	bg->map = map_bgmap0;
	bg->chr = chr_bgmap0;
	bg->clut = plt_bgmap0;
	bg->work = bgwork[2];
	bg++;
	bg->visible = 1;
	bg->x = 208;
	bg->y = 130;
	bg->w = 32;
	bg->h = 32;
	bg->cw = 16;
	bg->ch = 16;
	bg->bw = 256;
	bg->bh = 128;
	bg->scrollx = 0;
	bg->scrolly = 0;
	bg->color = 0xffffffff;
	bg->map = map_bgmap1;
	bg->chr = chr_bgmap1;
	bg->clut = plt_bgmap1;
	bg->work = bgwork[3];
}

#define p D_00012748	/* draw_cursor's static short p[6] */
extern short p[6];

#ifdef NON_MATCHING
/* store scheduling of p[] differs */
static void draw_cursor(void)
{
	BGDATA *bg;

	bg = &bgdata[select];
	p[0] = bg->x - 2;
	p[1] = bg->y - 2;
	p[2] = 0;
	p[3] = bg->x + bg->bw + 2;
	p[4] = bg->y + bg->bh + 2;
	p[5] = 0;
	sceKernelDcacheWritebackAll();
	sceGuDisable(9);
	sceGuColor(0xff4040ff);
	sceGuDrawArray(6, 0x800100, 2, NULL, p);
	sceGuEnable(9);
}
#else
INCLUDE_ASM("tmp/asm/UTST99332/graphics_map/nonmatchings/main", draw_cursor);
#endif
#undef p

static void draw_frame(void)
{
	int i;
	BGDATA *bg;

	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuClear(7);
	for (i = 0; i < 4; i++) {
		if (select == i)
			continue;
		bg = &bgdata[i];
		DrawBG(bg);
		if (frame & 1) {
			switch (i) {
			case 0:
				bg->scrollx++;
				bg->scrolly++;
				break;
			case 1:
				bg->scrollx++;
				break;
			case 2:
				bg->scrolly++;
				break;
			case 3:
				bg->scrollx--;
				bg->scrolly--;
				break;
			}
		}
	}
	draw_cursor();
	DrawBG(&bgdata[select]);
	sceGuFinish();
	sceGuSync(0, 0);
	frame++;
}

void init_all(void)
{
	sceGuInit();
	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuDrawBuffer(1, NULL, 0x200);
	sceGuDispBuffer(0x1E0, 0x110, (void *)0x44000, 0x200);
	sceGuDepthBuffer((void *)0x88000, 0x200);
	sceGuOffset(0, 0);
	sceGuScissor(0, 0, 0x1E0, 0x110);
	sceGuEnable(2);
	sceGuBlendFunc(0, 2, 3, 0, 0);
	sceGuEnable(4);
	sceGuAlphaFunc(6, 0, 0xFF);
	sceGuEnable(0);
	sceGuEnable(9);
	sceGuTexFunc(0, 1);
	sceGuTexFilter(7, 0);
	sceGuTexWrap(0, 0);
	sceGuTexMode(4, 0, 0, 0);
	sceGuClutMode(1, 0, 0xFF, 0);
	sceGuColor(0xffffffff);
	sceGuClearColor(0);
	sceGuClearDepth(0);
	sceGuClearStencil(0);
	sceGuFinish();
	sceGuSync(0, 0);
	sceDisplayWaitVblankStart();
	init_map();
	frame = 0;
	select = 0;
	sceGuDisplay(1);
}

static int pad_read(void)
{
	SceCtrlData buf;
	u_int32 oldcont, trg;
	BGDATA *bg;

	oldcont = cont;
	sceCtrlReadBufferPositive(&buf, 1);
	bg = &bgdata[select];
	cont = buf.Buttons;
	trg = cont & (cont ^ oldcont);
	if (cont & 0x0010)
		bg->scrolly--;
	if (cont & 0x0040)
		bg->scrolly++;
	if (cont & 0x0080)
		bg->scrollx--;
	if (cont & 0x0020)
		bg->scrollx++;
	if (trg & 0x2000) {
		if (++select >= 4)
			select = 0;
	}
	if (trg & 0x4000) {
		if (--select < 0)
			select = 3;
	}
	if (trg & 0x0009)
		return 0;
	return 1;
}

int main(void) {
    menuInit();
    init_all();
loop_1:
    if (pad_read() != 0) {
        draw_frame();
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 0xD);
    return 0;
}
