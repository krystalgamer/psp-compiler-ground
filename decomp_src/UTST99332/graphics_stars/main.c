#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
typedef unsigned int u_int32;
struct _anon1 { /* size 0x14 */
    u_int32 x;
    u_int32 y;
    u_int32 dx;
    u_int32 dy;
    u_int32 col;
};
typedef struct _anon1 POS;
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

/* SDK functions */
void sceGuClear(int flags);
void sceGuColor(unsigned int color);
void sceGuSpriteMode(int a0, int a1, int a2, int a3);
void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotation);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

extern unsigned int starcolor[8];
extern unsigned int star16x16[64];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern POS pos[256];
extern int maxnum;
extern char disp_list[131072];

int rand(void);
static void draw_frame(void);
static void init_pos(void);
static int pad_read(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuInit(void);
void sceGuTerm(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuEnable(int state);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuClutLoad(int num_blocks, const void *cbp);
int sceDisplayWaitVblankStart(void);


#ifndef SCEGU_IMMEDIATE
#define SCEGU_IMMEDIATE                    0
#ifndef SCEGU_CLEAR_ALL
#define SCEGU_CLEAR_ALL               0x0007
#endif
#ifndef SCEGU_TEXTURE
#define SCEGU_TEXTURE                      9
#endif
#ifndef SCEGU_SCR_WIDTH
#define SCEGU_SCR_WIDTH       480
#endif
#ifndef WALL_X
#define WALL_X		(SCEGU_SCR_WIDTH-SIZE)
#endif
#ifndef SCEGU_SCR_HEIGHT
#define SCEGU_SCR_HEIGHT      272
#endif
#ifndef SIZE
#define SIZE		16
#endif
#ifndef WALL_Y
#define WALL_Y		(SCEGU_SCR_HEIGHT-SIZE)
#endif
#ifndef MAXOBJ
#define MAXOBJ		8
#endif
#ifndef SCEGU_NOFLIP
#define SCEGU_NOFLIP                       0
#endif
#ifndef SCEGU_SYNC_FINISH
#define SCEGU_SYNC_FINISH                  0
#endif
#ifndef SCEGU_SYNC_WAIT
#define SCEGU_SYNC_WAIT                    0
#endif
static void draw_frame(void)
{
	POS	*p = pos;
	int	x, y, px, py;
	int	i, j;

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
	sceGuClear(SCEGU_CLEAR_ALL);

	sceGuEnable(SCEGU_TEXTURE);
	sceGuSpriteMode(SIZE, SIZE, SIZE, SIZE);
	for (j = 0; j < maxnum; j++, p++) {	
		if ((x = ((p->x+=p->dx) % (WALL_X*2))) >= WALL_X) {
			px = WALL_X*2 - x;
		} else {
			px = x;
		}
		if ((y = ((p->y+=p->dy) % (WALL_Y*2))) >= WALL_Y) {
			py = WALL_Y*2 - y;
		} else {
			py = y;
		}
		for (i = 1; i < MAXOBJ; i++) {
			if ((x = ((x+p->dx*2) % (WALL_X*2))) >= WALL_X) {
				px = WALL_X*2 - x;
			} else {
				px = x;
			}
			if ((y = ((y+p->dy*2) % (WALL_Y*2))) >= WALL_Y) {
				py = WALL_Y*2 - y;
			} else {
				py = y;
			}

			sceGuColor(p->col + ((0xff/(MAXOBJ-i)) << 24));
			sceGuDrawSprite(px, py, 0, 0, 0, SCEGU_NOFLIP, 0);
		}
	}
	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
}
#endif

void init_all(void) {
    sceGuInit();
    sceGuStart(0, disp_list, 0x20000);
    sceGuDrawBuffer(1, NULL, 0x200);
    sceGuDispBuffer(0x1E0, 0x110, (void *)0x44000, 0x200);
    sceGuDepthBuffer((void *)0x88000, 0x200);
    sceGuOffset(0U, 0U);
    sceGuScissor(0, 0, 0x1E0, 0x110);
    sceGuEnable(2);
    sceGuTexMode(4, 0, 0, 0);
    sceGuTexFilter(7, 0);
    sceGuTexFunc(0, 1);
    sceGuTexWrap(1, 1);
    sceGuTexImage(0, 0x10, 0x10, 0x20, star16x16);
    sceGuClutMode(1U, 0U, 0xFFU, 0U);
    sceGuClutLoad(1, starcolor);
    sceGuEnable(9);
    sceGuAlphaFunc(6, 0, 0xFF);
    sceGuEnable(0);
    sceGuBlendFunc(0, 2, 3, 0U, 0U);
    sceGuEnable(4);
    sceGuClearColor(0U);
    sceGuClearDepth(0U);
    sceGuClearStencil(0U);
    sceGuFinish();
    sceGuSync(0, 0);
    sceGuDisplay(1);
}

static void init_pos(void)
{
	int i;

	for (i = 0; i < 256; i++) {
		pos[i].x = rand() % 928;
		pos[i].y = rand() % 512;
		pos[i].dx = rand() % 4 + 2;
		pos[i].dy = rand() % 4 + 2;
		pos[i].col = ((rand() % 192 + 64) << 16) | ((rand() % 192 + 64) << 8) | (rand() % 192 + 64);
	}
}

static int pad_read(void)
{
	SceCtrlData buf;

	sceCtrlReadBufferPositive(&buf, 1);
	if (buf.Buttons & 0x0080) {
		if (--maxnum < 2)
			maxnum = 1;
	}
	if (buf.Buttons & 0x0020) {
		if (++maxnum >= 256)
			maxnum = 256;
	}
	if (buf.Buttons & 0x0001)
		return 0;
	return 1;
}

int main(void) {
    menuInit();
    init_all();
    init_pos();
loop_1:
    if (pad_read() != 0) {
        draw_frame();
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 0x1C);
    return 0;
}
