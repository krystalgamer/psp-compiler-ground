#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int u_int32;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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
extern float array_cone[204];
extern ScePspFVector3 array_sphere[28];
extern int primflag;
extern int description;
extern const int mat_mod[6][3];
extern const short int line[18];
extern const char mat_names[3][12];
extern const char mod_names[3][8];
extern u_int32 cont;


/* SDK functions (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

static void draw_description(void);
static void draw_primitive(void);
static void draw_frame(void);
static void init_all(void);
static int pad_read(void);


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_material/nonmatchings/main", mat_mod);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_material/nonmatchings/main", line);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_material/nonmatchings/main", draw_description);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_material/nonmatchings/main", D_00011E90);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_material/nonmatchings/main", draw_primitive);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_material/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_material/nonmatchings/main", init_all);

int pad_read(void) {
    SceCtrlData buf;
    int temp_a0;
    unsigned int temp_s0;

    temp_s0 = cont;
    sceCtrlReadBufferPositive(&buf, 1);
    temp_a0 = buf.Buttons & (buf.Buttons ^ temp_s0);
    cont = buf.Buttons;
    if (temp_a0 & 0x2000) {
        primflag ^= 1;
    }
    if (cont & 0x1000) {
        description = 1;
    } else {
        description = 0;
    }
    return (temp_a0 & 9) == 0;
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
    menuTerm(1, 0xE);
    return 0;
}
