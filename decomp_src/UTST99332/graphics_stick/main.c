#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
typedef unsigned int u_int32;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1 { /* size 0x10 */
    u_int32 c;
    ScePspFVector3 vtx;
};
typedef struct _anon1 MODEL;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
struct _anon2;
struct _anon2 { /* size 0x14 */
    int x;
    int y;
    u_int32 c;
    int comp;
    float high;
};
typedef struct _anon2 OBJECT;
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
struct _anon3;
struct _anon3 { /* size 0x18 */
    ScePspFVector3 pos;
    ScePspFVector3 rot;
};
typedef struct _anon3 POS;

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
extern POS world;
extern MODEL model[961];
extern OBJECT obj[2];

static void set_object(float *analog);
static void init_param(void);
static void init_all(void);
static int pad_read(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTerm(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
void sceGuClear(int flags);
void sceGuColor(unsigned int color);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
int sceDisplayWaitVblankStart(void);
int sceCtrlSetSamplingMode(int mode);


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_stick/nonmatchings/main", D_00011BE0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_stick/nonmatchings/main", D_00011C04);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stick/nonmatchings/main", set_object);

void draw_model(void) {
    sceGumPushMatrix();
    sceGuColor(-1U);
    sceGumDrawBezier(0x19C, 0x1F, 0x1F, NULL, model);
    sceGumPopMatrix();
}

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10, 0x14], gap at: 0x8. */
void draw_frame(void) {
    sceGuStart(0, disp_list, 0x10000);
    sceGuClear(7);
    sceGumPushMatrix();
    sceGumLoadIdentity();
    sceGumTranslate(&world.pos);
    sceGumRotateX((world.rot.x * 3.1415927f) / 180.0f);
    sceGumRotateY((world.rot.y * 3.1415927f) / 180.0f);
    sceGumRotateZ((world.rot.z * 3.1415927f) / 180.0f);
    draw_model();
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stick/nonmatchings/main", init_param);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stick/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stick/nonmatchings/main", pad_read);

int main(void) {
    menuInit();
    sceCtrlSetSamplingMode(1);
    init_all();
loop_1:
    if (pad_read() != 0) {
        draw_frame();
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
        goto loop_1;
    }
    sceGuTerm();
    menuTerm(1, 0x1D);
    return 0;
}
