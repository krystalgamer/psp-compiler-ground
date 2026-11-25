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
struct _anon1 { /* size 0x18 */
    ScePspFVector3 rot;
    ScePspFVector3 trans;
};
typedef struct _anon1 POS;
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

extern unsigned int checkcolor[1];
extern unsigned int check32x32[128];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern const int mapmode[3];
extern const char mapstr[3][16];
extern POS pos;
extern int mode;
extern int autoflag;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[32];
extern float array[147];

static void draw_frame(int frame);
static void init_all(void);
static void init_pos(void);
static int pad_read(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTerm(void);
void *sceGuSwapBuffers(void);
int sceDisplayWaitVblankStart(void);


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_texmat/nonmatchings/main", mapmode);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_texmat/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_texmat/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_texmat/nonmatchings/main", init_pos);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_texmat/nonmatchings/main", pad_read);

int main(void) {
    int temp_a0;
    int var_s0;

    menuInit();
    var_s0 = 0;
    init_all();
    init_pos();
loop_1:
    temp_a0 = var_s0;
    var_s0 += 1;
    if (pad_read() != 0) {
        draw_frame(temp_a0);
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 0x22);
    return 0;
}
