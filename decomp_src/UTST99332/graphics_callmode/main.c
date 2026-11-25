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
struct _anon1;
struct _anon1 { /* size 0xc */
    unsigned int col;
    short int x;
    short int y;
    short unsigned int z;
};
typedef struct _anon1 CRECT;

/* SDK functions */
void sceGuInit(void);
void sceGuTerm(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGuCallList(const void *list);
void sceGuCallMode(int mode);
int sceDisplayWaitVblankStart(void);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
int sprintf(char *buf, const char *fmt, ...);

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern CRECT rect[32][2];
extern int snum;
extern char disp_list[4096];
extern char call_list[32][256];

static void mk_list(void);
static void draw_frame(void);
static int pad_read(void);


static void mk_list(void)
{
	int i;

	for (i = 0; i < 32; i++) {
		sceGuStart(1, call_list[i], sizeof(call_list[i]));
		sceGuDrawArray(6, 0x80011c, 2, NULL, rect[i]);
		if (i != 31)
			sceGuCallList(call_list[i + 1]);
		sceGuFinish();
	}
}

static void draw_frame(void)
{
	char str[32];

	sceGuStart(0, disp_list, sizeof(disp_list));
	sceGuClear(7);
	sceGuCallList(call_list[snum]);
	sprintf(str, "CALL LEVEL:%d\n", 32 - snum);
	sceGuDebugPrint(0, 0, 0xffffffff, str);
	sceGuFinish();
	sceGuSync(0, 0);
}

void init_all(void) {
    sceGuInit();
    sceGuStart(0, disp_list, 0x1000);
    sceGuCallMode(1);
    sceGuDrawBuffer(1, 0, 0x200);
    sceGuDispBuffer(0x1E0, 0x110, 0x44000, 0x200);
    sceGuOffset(0, 0);
    sceGuScissor(0, 0, 0x1E0, 0x110);
    sceGuEnable(2);
    sceGuDisable(1);
    sceGuDisable(9);
    sceGuClearColor(0);
    sceGuClearDepth(0);
    sceGuClearStencil(0);
    sceGuFinish();
    sceGuSync(0, 0);
    sceGuDisplay(1);
}

static int pad_read(void)
{
	SceCtrlData buf;
	u_int32 padd;

	sceCtrlReadBufferPositive(&buf, 1);
	padd = buf.Buttons;
	if (padd & 0x0010) {
		snum--;
		if (snum < 0)
			snum = 0;
	}
	if (padd & 0x0040) {
		snum++;
		if (snum >= 32)
			snum = 31;
	}
	if (padd & 0x0001)
		return 0;
	return 1;
}

int main(void) {
    menuInit();
    init_all();
    mk_list();
loop_1:
    if (pad_read() != 0) {
        draw_frame();
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 3);
    return 0;
}
