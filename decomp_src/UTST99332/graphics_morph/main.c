#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon2;
struct _anon3;
struct _anon3 { /* size 0x10 */
    unsigned int col;
    float vertex[3];
};
typedef struct _anon3 PRIM;
struct _anon2 { /* size 0x20 */
    PRIM prim0;
    PRIM prim1;
};
typedef struct _anon2 MODEL;
struct _anon1 { /* size 0x10 */
    int type;
    int ctrl[2];
    const MODEL *model;
};
typedef struct _anon1 MODELLIST;
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
extern const MODEL r_front_hair[20];
extern const MODEL l_front_hair[20];
extern const MODEL r_body[36];
extern const MODEL l_body[36];
extern const MODEL face[36];
extern const MODEL head[30];
extern const MODEL horn1[24];
extern const MODEL horn2[20];
extern const MODEL r_ear[16];
extern const MODEL l_ear[16];
extern const MODEL r_hand[16];
extern const MODEL l_hand[16];
extern const MODEL r_back_hair1[20];
extern const MODEL r_back_hair2[20];
extern const MODEL l_back_hair1[20];
extern const MODEL l_back_hair2[20];
extern const MODEL r_leg_out1[20];
extern const MODEL r_leg_out2[16];
extern const MODEL r_leg_in1[20];
extern const MODEL r_leg_in2[16];
extern const MODEL r_foot_out[20];
extern const MODEL r_foot_in[20];
extern const MODEL l_leg_in1[20];
extern const MODEL l_leg_in2[16];
extern const MODEL l_leg_out1[20];
extern const MODEL l_leg_out2[16];
extern const MODEL l_foot_in[20];
extern const MODEL l_foot_out[20];
extern const MODEL r_wing1[16];
extern const MODEL r_wing2[16];
extern const MODEL r_wing_skin[16];
extern const MODEL l_wing1[16];
extern const MODEL l_wing2[16];
extern const MODEL l_wing_skin[16];
extern MODELLIST model_list[34];
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];
extern ScePspFVector3 pos;
extern ScePspFVector3 rot;
extern int morph;
extern float weight;
extern float dir;
extern int cont;

static void draw_morph(void);
static void init_all(void);
static int pad_read(void);
int main(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuStart(int type, void *list, int size);
int sceGuFinish(void);
int sceGuSync(int mode, int what);
void sceGuClear(int flags);
void sceGumLoadIdentity(void);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumTranslate(const ScePspFVector3 *v);


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_front_hair);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_front_hair);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_body);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_body);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", face);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", head);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", horn1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", horn2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_ear);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_ear);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_hand);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_hand);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_back_hair1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_back_hair2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_back_hair1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_back_hair2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_leg_out1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_leg_out2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_leg_in1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_leg_in2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_foot_out);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_foot_in);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_leg_in1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_leg_in2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_leg_out1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_leg_out2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_foot_in);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_foot_out);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_wing1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_wing2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", r_wing_skin);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_wing1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_wing2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", l_wing_skin);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", D_00017190);

float step_morph(float d) {
    float temp_f0;
    float var_f12;

    var_f12 = d;
    temp_f0 = weight + var_f12;
    weight = temp_f0;
    if (var_f12 > 0.0f) {
        if (temp_f0 > 1.0f) {
            var_f12 = -0.05f;
            weight = 1.0f;
        }
    } else if (temp_f0 < 0.0f) {
        weight = 0.0f;
        var_f12 = 0.05f;
    }
    return var_f12;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", draw_morph);

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
    draw_morph();
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_morph/nonmatchings/main", pad_read);

void menuInit(void);
void menuTerm(int cat, int num);

int main(void)
{
	menuInit();

	init_all();

	while (pad_read()) {
		draw_frame();
		sceDisplayWaitVblankStart();
		sceGuSwapBuffers();

		if (morph) {
			dir = step_morph(dir);
		}
	}

	sceGuTerm();

	menuTerm(1, 19);

	return 0;
}
