#include "common.h"

/* declarations recovered from DWARF */
struct ScePspIMatrix4;
struct ScePspIVector4;
struct ScePspIVector4 { /* size 0x10 */
    int x;
    int y;
    int z;
    int w;
};
typedef struct ScePspIVector4 ScePspIVector4;
struct ScePspIMatrix4 { /* size 0x40 */
    ScePspIVector4 x;
    ScePspIVector4 y;
    ScePspIVector4 z;
    ScePspIVector4 w;
};
typedef struct ScePspIMatrix4 ScePspIMatrix4;
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

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];
extern ScePspFVector3 pos;
extern ScePspFVector3 rot;
extern int mode;
extern int prim;
extern int current;
extern ScePspFVector3 control[16];
extern const int primflag[3];
extern const char char_prim[3][16];
extern const char char_mode[2][8];
extern const float bezier[48];
extern const float dot[12];
extern u_int32 cont;


/* SDK functions (tools/sdk_protos.h) */
void sceGuColor(unsigned int color);
void sceGuPatchDivide(unsigned int ulevel, unsigned int vlevel);
void sceGuPatchPrim(int prim);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
int sceKernelDcacheWritebackAll(void);

static void draw_bezier(void);
static void draw_dot(void);
static void draw_frame(void);
static void init_all(void);
static int pad_read(void);


void draw_bezier(void) {
    sceGuPatchDivide(0x10U, 0x10U);
    sceGuPatchPrim(primflag[prim]);
    sceGumPushMatrix();
    sceGuColor(-0x7F01U);
    sceGumDrawBezier(0x180, 4, 4, NULL, control);
    sceKernelDcacheWritebackAll();
    sceGumPopMatrix();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", draw_dot);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", primflag);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", draw_frame);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", bezier);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", dot);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", D_00011E20);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", D_00011E60);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", D_00011E64);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editgrid/nonmatchings/main", pad_read);

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
    menuTerm(1, 8);
    return 0;
}
