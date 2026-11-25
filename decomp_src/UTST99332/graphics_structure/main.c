#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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

extern const unsigned int star_clut[128];
extern const unsigned int star_tex[256];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern int pause_flag;
extern int rot_flag;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[16];

static void init_all(void);
static int pad_read(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTerm(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
void sceGuClear(int flags);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
int sceDisplayWaitVblankStart(void);


extern int rot_flag_294C4;

void draw_frame(void) {
    sceGuStart(0, disp_list, 0x10000);
    sceGuClear(7);
    sceGumPushMatrix();
    sceGumLoadIdentity();
    DrawData(pause_flag, rot_flag_294C4);
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_structure/nonmatchings/main", star_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_structure/nonmatchings/main", star_tex);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_structure/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_structure/nonmatchings/main", pad_read);

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
    menuTerm(1, 0x1F);
    return 0;
}
