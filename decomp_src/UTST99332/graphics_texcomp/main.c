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


INCLUDE_ASM("tmp/asm/UTST99332/graphics_texcomp/nonmatchings/main", draw_sprite);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_texcomp/nonmatchings/main", char_mode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_texcomp/nonmatchings/main", set_texture);

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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_texcomp/nonmatchings/main", pad_read);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_texcomp/nonmatchings/main", main);
