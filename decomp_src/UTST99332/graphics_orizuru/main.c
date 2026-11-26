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
struct _anon1 { /* size 0x1c */
    float speed;
    float theta;
    ScePspFVector3 v;
    float angle;
    unsigned int col;
};
typedef struct _anon1 ORIZURUDAT;
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
struct _anon2;
struct _anon2 { /* size 0x8 */
    short unsigned int col;
    short int vec[3];
};
typedef struct _anon2 PRIM_BG;

extern unsigned char neck_index[12];
extern unsigned char body_index0[7];
extern unsigned char body_index1[6];
extern unsigned char body_index2[5];
extern unsigned char body_index3[5];
extern unsigned char body_index4[5];
extern unsigned char body_index5[30];
extern float neck[48];
extern float body[210];
extern float face[36];
extern float tail[36];
extern float rwing[30];
extern float lwing[30];
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
extern int moving;
extern ORIZURUDAT orizuru[128];
extern PRIM_BG background[4];
extern int cont;

static void tick(void);
static void add_orizuru(void);
static void remove_orizuru(void);
static void draw_orizuru(void);
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
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
float sinf(float x);
float cosf(float x);


/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10, 0x14], gap at: 0x8. */
void tick_per_orizuru(int i) {
    ORIZURUDAT *temp_s0;
    float temp_f0;
    float temp_f20;

    temp_s0 = &orizuru[i];
    temp_f20 = temp_s0->theta + temp_s0->speed;
    temp_s0->theta = temp_f20;
    temp_s0->v.z = (cosf(temp_f20) * 6.0f) + -13.0f;
    temp_s0->v.x = sinf(2.0f * temp_f20) * 10.0f;
    temp_s0->v.y = sinf(temp_f20 / 3.4f) * 6.0f;
    temp_f0 = (((sinf(temp_f20) * 2.6779454f) - 1.5707964f) * 180.0f) / 3.1415927f;
    temp_s0->angle = temp_f0;
    if (temp_s0->speed < 0.0f) {
        temp_s0->angle = temp_f0 + 180.0f;
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_orizuru/nonmatchings/main", tick);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_orizuru/nonmatchings/main", add_orizuru);

static void remove_orizuru(void)
{
	int i;

	for (i = 127; i > 0; i--) {
		if (orizuru[i].speed != 0.0f) {
			orizuru[i].speed = 0.0f;
			return;
		}
	}
}

void model_orizuru(void) {
    sceGumDrawArray(4, 0x9E0, 0xC, neck_index, neck);
    sceGumDrawArray(4, 0x9E0, 7, body_index0, body);
    sceGumDrawArray(4, 0x9E0, 6, body_index1, body);
    sceGumDrawArray(4, 0x9E0, 5, body_index2, body);
    sceGumDrawArray(4, 0x9E0, 5, body_index3, body);
    sceGumDrawArray(4, 0x9E0, 5, body_index4, body);
    sceGumDrawArray(4, 0x9E0, 0x1E, body_index5, body);
    sceGumDrawArray(4, 0x1E0, 6, NULL, face);
    sceGumDrawArray(4, 0x1E0, 6, NULL, tail);
    sceGumDrawArray(4, 0x1E0, 5, NULL, rwing);
    sceGumDrawArray(4, 0x1E0, 5, NULL, lwing);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_orizuru/nonmatchings/main", draw_orizuru);

void draw_frame(void) {
    sceGuStart(0, disp_list, 0x10000);
    sceGuClear(7);
    sceGumPushMatrix();
    sceGumLoadIdentity();
    sceGumTranslate(&pos);
    draw_orizuru();
    sceGumPopMatrix();
    sceGuFinish();
    sceGuSync(0, 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_orizuru/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_orizuru/nonmatchings/main", pad_read);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_orizuru/nonmatchings/main", main);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_orizuru/nonmatchings/main", D_00011EB0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_orizuru/nonmatchings/main", D_00011ED0);
