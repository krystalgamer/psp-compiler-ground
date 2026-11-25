#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int u_int32;
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
void sceGuTerm(void);
void *sceGuSwapBuffers(void);
void sceGuDisable(int state);
void sceGuColor(unsigned int color);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuSpriteMode(int a0, int a1, int a2, int a3);
void sceGuDrawSprite(int x, int y, int z, int u, int v, int flip, int rotation);
int sceDisplayGetVcount(void);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

extern unsigned int pix_pf8888[65536];
extern unsigned int clut_pfidx8[128];
extern unsigned int pix_pfidx8[16384];
extern unsigned int pix_dxt1[8192];
extern unsigned int pix_dxt3[16384];
extern unsigned int pix_dxt5[16384];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern int hcnt;
extern int vcnt;
extern int prev_vcnt;
extern int cur_vcnt;
extern char disp_list[65536];
extern int draw;
extern int change;
extern short int board[2][3];
extern const char char_mode[6][16];

static void draw_sprite(void);
int sceDisplayGetCurrentHcount(void);
void menuInit(void);
void menuTerm(int cat, int num);
static void set_texture(void);
static void draw_frame(void);
static int pad_read(void);
int main(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuInit(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
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
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
int sceDisplayWaitVblankStart(void);


static void draw_sprite(void)
{
	int x, y, i;

	sceGuColor(0xffffffff);
	sceGuSpriteMode(64, 256, 64, 256);
	for (i = 0; i < 4; i++) {
		x = i * 64;
		y = 0;
		sceGuDrawSprite(x + 112, y + 8, 0, x, y, 0, 0);
	}
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_texcomp/nonmatchings/main", char_mode);

static void set_texture(void)
{
	switch (draw) {
	case 1:
		sceGuEnable(9);
		sceGuTexMode(3, 0, 0, 0);
		sceGuTexImage(0, 256, 256, 256, pix_pf8888);
		break;
	case 2:
		sceGuEnable(9);
		sceGuTexMode(5, 0, 0, 0);
		sceGuTexImage(0, 256, 256, 256, pix_pfidx8);
		sceGuClutMode(1, 0, 0xff, 0);
		sceGuClutLoad(16, clut_pfidx8);
		break;
	case 3:
		sceGuEnable(9);
		sceGuTexMode(8, 0, 0, 0);
		sceGuTexImage(0, 256, 256, 256, pix_dxt1);
		break;
	case 4:
		sceGuEnable(9);
		sceGuTexMode(9, 0, 0, 0);
		sceGuTexImage(0, 256, 256, 256, pix_dxt3);
		break;
	case 5:
		sceGuEnable(9);
		sceGuTexMode(10, 0, 0, 0);
		sceGuTexImage(0, 256, 256, 256, pix_dxt5);
		break;
	default:
		sceGuDisable(9);
		break;
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_texcomp/nonmatchings/main", draw_frame);

void init_all(void) {
    sceGuInit();
    sceGuStart(0, disp_list, 0x10000);
    sceGuDrawBuffer(3, NULL, 0x200);
    sceGuDispBuffer(0x1E0, 0x110, (void *)0x88000, 0x200);
    sceGuDepthBuffer((void *)0x110000, 0x200);
    sceGuOffset(0U, 0U);
    sceGuScissor(0, 0, 0x1E0, 0x110);
    sceGuEnable(2);
    sceGuBlendFunc(0, 2, 3, 0U, 0U);
    sceGuEnable(4);
    sceGuTexFunc(0, 1);
    sceGuTexFilter(1, 1);
    sceGuTexWrap(0, 0);
    sceGuClearColor(0x404040U);
    sceGuClearDepth(0U);
    sceGuClearStencil(0U);
    sceGuFinish();
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    change = 1;
    draw = 0;
    sceGuDisplay(1);
}

#define cont D_00088500	/* pad_read's static */
extern u_int32 cont;

static int pad_read(void)
{
	u_int32 prev, padd;
	SceCtrlData buf;
	int old;

	prev = cont;
	old = draw;
	sceCtrlReadBufferPositive(&buf, 1);
	padd = buf.Buttons & (buf.Buttons ^ prev);
	cont = buf.Buttons;
	if (padd & 0x0010)
		draw = 1;
	if (padd & 0x0040)
		draw = 2;
	if (padd & 0x1000)
		draw = 3;
	if (padd & 0x2000)
		draw = 4;
	if (padd & 0x4000)
		draw = 5;
	if (old != draw)
		change = 1;
	if (padd & 0x0008)
		draw = 0;
	if (padd & 0x0001)
		return 0;
	return 1;
}

int main(void)
{
	menuInit();
	init_all();
	for (;;) {
		if (!pad_read())
			break;
		draw_frame();
		hcnt = sceDisplayGetCurrentHcount();
		prev_vcnt = cur_vcnt;
		cur_vcnt = sceDisplayGetVcount();
		sceDisplayWaitVblankStart();
		vcnt = cur_vcnt - prev_vcnt;
		sceGuSwapBuffers();
	}
	sceGuTerm();
	menuTerm(1, 33);
	return 0;
}
