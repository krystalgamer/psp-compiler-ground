#include "common.h"

/* declarations recovered from DWARF */
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

extern float parts[245];
extern ScePspFVector3 bone0[399];
extern ScePspFVector3 bone1[397];
extern ScePspFVector3 bone2[399];
extern ScePspFVector3 bone3[399];
extern ScePspFVector3 *bone_tbl[4];
extern short unsigned int mesh_pixel[256];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[80];
extern int frame;
extern ScePspFVector3 pos;
extern ScePspFVector3 rot;
extern ScePspFMatrix4 bone_m[4];
extern int cont;

static void boneCalc(void);
static void init_all(void);
static int pad_read(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTerm(void);
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
void sceGuClear(int flags);
void sceGuBoneMatrix(unsigned int index, const ScePspFMatrix4 *matrix);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
int sceDisplayWaitVblankStart(void);


INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/main", boneCalc);

extern float D_00011B58;
extern float D_00011B5C;

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10, 0x14], gap at: 0x8. */
void draw_frame(void) {
    float temp_f20;
    float temp_f21;

    sceGuStart(0, disp_list, 0x10000);
    sceGuClear(7);
    sceGumPushMatrix();
    sceGumLoadIdentity();
    sceGumTranslate(&pos);
    temp_f21 = D_00011B58;
    temp_f20 = D_00011B5C;
    sceGumRotateX((rot.x * temp_f21) / temp_f20);
    sceGumRotateY((rot.y * temp_f21) / temp_f20);
    sceGumRotateZ((rot.z * temp_f21) / temp_f20);
    boneCalc();
    sceGuBoneMatrix(0U, bone_m);
    sceGuBoneMatrix(1U, &bone_m[1]);
    sceGuBoneMatrix(2U, &bone_m[2]);
    sceGuBoneMatrix(3U, &bone_m[3]);
    sceGumDrawSpline(0xC780, 7, 5, 0, 3, NULL, parts);
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/main", pad_read);

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
    menuTerm(1, 0x19);
    return 0;
}
