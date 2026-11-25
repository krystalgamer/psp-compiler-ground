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
typedef int SceUID;
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
extern char vagWork[8][40960];
extern POS pos[256];
extern int maxnum;
extern char disp_list[131072];

static void draw_frame(void);
static void init_pos(void);
static int pad_read(void);
static int file_read(const char *pFile, void *pBuf, unsigned int uBufSize, unsigned int *uSize, unsigned int uOffset);
static void vag_read(void);
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
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuClutLoad(int num_blocks, const void *cbp);


INCLUDE_ASM("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", draw_frame);

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

INCLUDE_ASM("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", init_pos);

INCLUDE_ASM("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", pad_read);

INCLUDE_ASM("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", file_read);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", D_00010F00);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", D_00010F30);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", D_00010F60);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", D_00010F90);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", D_00010FC0);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", D_00010FF0);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", D_00011020);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", D_00011050);

INCLUDE_RODATA("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", D_00011080);

INCLUDE_ASM("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", vag_read);

INCLUDE_ASM("tmp/asm/UTST99332/sound_starsound/nonmatchings/main", main);
