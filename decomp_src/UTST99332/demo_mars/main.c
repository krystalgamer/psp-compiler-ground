#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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
    float x;
    float y;
    float z;
};
typedef struct _anon1 VERTEX;
struct _anon2;
struct _anon2 { /* size 0x20 */
    float u;
    float v;
    float nx;
    float ny;
    float nz;
    float x;
    float y;
    float z;
};
typedef struct _anon2 QVERTEX;
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
struct _anon3;
struct _anon3 { /* size 0x20 */
    float u;
    float v;
    float nx;
    float ny;
    float nz;
    float vx;
    float vy;
    float vz;
};
typedef struct _anon3 MODEL;
struct _anon4;
struct _anon4 { /* size 0x4 */
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
};
typedef struct _anon4 CLUT;

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern VERTEX vqtable[256];
extern QVERTEX sphere[24][9][9];
extern unsigned char highttexmip128[24][129][144];
extern unsigned char bumptexmip128[24][129][144];
extern unsigned char highttexmip64[24][65][80];
extern unsigned char bumptexmip64[24][65][80];
extern unsigned char highttexmip32[24][33][48];
extern unsigned char bumptexmip32[24][33][48];
extern unsigned char highttexmip16[24][17][32];
extern unsigned char bumptexmip16[24][17][32];
extern unsigned char highttexmip8[24][9][16];
extern unsigned char bumptexmip8[24][9][16];
extern short unsigned int pix_logo[4096];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[6];
extern MODEL model[24][144];
extern CLUT clut[256];
extern CLUT cltbf[256];
extern CLUT cltsea[256];

int main(void);
void CLUT_Earth_Color(int sealev);
void CLUT_Depth_SEA(int sea);
void set_model_data(void);


void draw_scei(void) {
    sceGuColor(-1);
    sceGuEnable(4);
    sceGuTexMode(2, 0, 0, 0);
    sceGuTexImage(0, 0x80, 0x20, 0x80, pix_logo);
    sceGuSpriteMode(0x80, 0x20, 0x80, 0x20);
    sceGuDrawSprite(8, 0xF4, 0xFFFF, 0, 0, 0, 0);
    sceGuColor(-1);
    sceGuTexMode(5, 4, 0, 0);
}

INCLUDE_RODATA("tmp/asm/UTST99332/demo_mars/nonmatchings/main", D_00013650);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_mars/nonmatchings/main", D_0001365C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_mars/nonmatchings/main", main);

INCLUDE_ASM("tmp/asm/UTST99332/demo_mars/nonmatchings/main", CLUT_Earth_Color);

INCLUDE_ASM("tmp/asm/UTST99332/demo_mars/nonmatchings/main", CLUT_Depth_SEA);

INCLUDE_ASM("tmp/asm/UTST99332/demo_mars/nonmatchings/main", set_model_data);
