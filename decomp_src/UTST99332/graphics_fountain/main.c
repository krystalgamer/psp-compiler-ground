#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1 { /* size 0x184 */
    ScePspFVector3 array[28];
    ScePspFVector3 pos;
    ScePspFVector3 dpos;
    float rot;
    float scale;
    int t;
    int a;
    int d;
    int c;
    int w;
};
typedef struct _anon1 GRAIN_DAT;
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
struct _anon2;
struct _anon2 { /* size 0x1c */
    u_int32 col;
    ScePspFVector3 normal;
    ScePspFVector3 vertex;
};
typedef struct _anon2 MODEL;

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
extern GRAIN_DAT grain[500];
extern int num_of_grain;
extern int autoflag;
extern const float orifice[96];
extern const MODEL ground[18];
extern u_int32 cont;


/* SDK functions (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);

static void set_divide(int pt);
static void init_grain(int i);
static void move_grain(void);
static void draw_grain(void);
static void init_all(void);
static int pad_read(void);
int main(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void sceGuClear(int flags);
void sceGuColor(unsigned int color);
void sceGuSpecular(float power);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);


INCLUDE_ASM("tmp/asm/UTST99332/graphics_fountain/nonmatchings/main", set_divide);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_fountain/nonmatchings/main", orifice);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_fountain/nonmatchings/main", ground);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_fountain/nonmatchings/main", D_000122E0);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_fountain/nonmatchings/main", init_grain);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_fountain/nonmatchings/main", move_grain);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_fountain/nonmatchings/main", draw_grain);

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10, 0x14], gap at: 0x8. */
void draw_frame(void) {
    sceGuStart(0, disp_list, 0x10000);
    sceGuClear(7);
    sceGumPushMatrix();
    sceGumLoadIdentity();
    sceGumTranslate(&pos);
    sceGumRotateX((rot.x * 3.1415927f) / 180.0f);
    sceGumRotateY((rot.y * 3.1415927f) / 180.0f);
    sceGumRotateZ((rot.z * 3.1415927f) / 180.0f);
    sceGuSpecular(50.0f);
    sceGumDrawArray(5, 0x1FC, 0x12, NULL, ground);
    sceGuColor(0xFFE0E0E0U);
    sceGumDrawArray(4, 0x1E0, 0xA, NULL, orifice);
    sceGumDrawArray(4, 0x1E0, 0xA, NULL, &orifice[0xC]);
    sceGumDrawArray(4, 0x1E0, 0xA, NULL, &orifice[0x18]);
    sceGumDrawArray(4, 0x1E0, 0xA, NULL, &orifice[0x24]);
    sceGuSpecular(10.0f);
    draw_grain();
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_fountain/nonmatchings/main", init_all);

int pad_read(void) {
    SceCtrlData buf;
    int temp_s0;
    unsigned int temp_s0_2;

    temp_s0_2 = cont;
    sceCtrlReadBufferPositive(&buf, 1);
    temp_s0 = buf.Buttons & (buf.Buttons ^ temp_s0_2);
    cont = buf.Buttons;
    if (temp_s0 & 0x2000) {
        autoflag ^= 1;
    }
    return (temp_s0 & 9) == 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_fountain/nonmatchings/main", main);
