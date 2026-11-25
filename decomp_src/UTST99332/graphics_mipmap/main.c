#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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
struct _anon1;
struct _anon1 { /* size 0x8 */
    int num;
    const unsigned int *clut;
};
typedef struct _anon1 CLUT_INFO;
struct _anon2;
struct _anon2 { /* size 0x10 */
    int tw;
    int th;
    int w;
    const unsigned int *tex;
};
typedef struct _anon2 TEX_INFO;
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
struct _anon3;
struct _anon3 { /* size 0x24 */
    ScePspFVector3 rot;
    ScePspFVector3 trans;
    ScePspFVector3 scale;
};
typedef struct _anon3 POS;
struct _anon4;
struct _anon4 { /* size 0x24 */
    ScePspFVector3 eye;
    ScePspFVector3 center;
    ScePspFVector3 up;
};
typedef struct _anon4 VIEW;
struct _anon5;
struct _anon5 { /* size 0x8 */
    float u;
    float v;
};
typedef struct _anon5 TEXD;
struct _anon6;
struct _anon6 { /* size 0x8 */
    int tmode;
    int cmode;
};
typedef struct _anon6 TEXMODE;
struct _anon7;
struct _anon7 { /* size 0x30 */
    int ofx;
    int ofy;
    int sx;
    int sy;
    char str[32];
};
typedef struct _anon7 MIPMAP;
struct ScePspFMatrix4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
typedef struct ScePspFMatrix4 ScePspFMatrix4;

extern const unsigned int grid_clut[64];
extern const unsigned int way_clut[128];
extern const unsigned int grid_1_tex[2048];
extern const unsigned int grid_2_tex[512];
extern const unsigned int grid_3_tex[128];
extern const unsigned int grid_4_tex[64];
extern const unsigned int grid_5_tex[32];
extern const unsigned int grid_6_tex[16];
extern const unsigned int grid_7_tex[16];
extern const unsigned int grid_8_tex[4];
extern const unsigned int way_1_tex[4096];
extern const unsigned int way_2_tex[1024];
extern const unsigned int way_3_tex[256];
extern const unsigned int way_4_tex[64];
extern const unsigned int way_5_tex[32];
extern const unsigned int way_6_tex[16];
extern const unsigned int way_7_tex[8];
extern const unsigned int way_8_tex[4];
extern const CLUT_INFO cinfo[2];
extern const TEX_INFO tinfo[2][8];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern POS pos;
extern VIEW view;
extern TEXD toffset;
extern int moving;
extern int maxlod;
extern int mode;
extern const u_int32 bg_col[2];
extern const TEXMODE tmode[2];
extern const float road_poly[20];
extern const MIPMAP mipmap[4];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[16];

static void draw_frame(void);
static void init_all(void);
static void init_param(void);
static int pad_read(void);
int main(void);


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_1_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_2_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_3_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_4_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_5_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_6_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_7_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", grid_8_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_1_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_2_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_3_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_4_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_5_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_6_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_7_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", way_8_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", cinfo);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", tinfo);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", bg_col);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", tmode);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", road_poly);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", mipmap);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", D_0001A248);

extern int D_0001BE04;

void frame_update(void) {
    int temp_v1;

    temp_v1 = D_0001BE04 + 1;
    toffset.v += -0.005524693f;
    D_0001BE04 = temp_v1;
    if (temp_v1 >= 0x5A0) {
        D_0001BE04 = 0;
        toffset.v = -0.044444f;
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", init_param);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", pad_read);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_mipmap/nonmatchings/main", main);
