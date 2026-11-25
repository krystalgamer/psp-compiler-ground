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

extern ScePspFVector3 light_vec;
extern const unsigned int marble_clut[8];
extern const unsigned int ref_clut[8];
extern const unsigned int marble_tex[2048];
extern const unsigned int ref_tex[512];
extern const float alphabet[26][300];
extern float morph[16][600];
extern char cur_word[17];
extern int cur_len;
extern int cur_stat;
extern int new_len;
extern int frame;
extern int wait;
extern float stepx;
extern float startx;
extern float ground[48];
extern ScePspFMatrix4 shadow_mat;

static void init_morph(int n, int src, int dst);
static void draw_alphabet(void);
static void update_data(void);
void DrawData(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuMorphWeight(int index, float weight);


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_string/nonmatchings/draw", marble_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_string/nonmatchings/draw", ref_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_string/nonmatchings/draw", marble_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_string/nonmatchings/draw", ref_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_string/nonmatchings/draw", alphabet);

static void init_morph(int n, int src, int dst)
{
	int i;
	int j;

	for (i = 0; i < 100; i++) {
		if (src == 0) {
			morph[n][i * 6 + 0] = 0.0f;
			morph[n][i * 6 + 1] = 10.0f;
			morph[n][i * 6 + 2] = 0.0f;
		} else {
			for (j = 0; j < 3; j++)
				morph[n][i * 6 + j] = alphabet[src - 'A'][i * 3 + j];
		}
		if (dst == 0) {
			morph[n][i * 6 + 3] = 0.0f;
			morph[n][i * 6 + 4] = 10.0f;
			morph[n][i * 6 + 5] = 0.0f;
		} else {
			for (j = 0; j < 3; j++)
				morph[n][i * 6 + 3 + j] = alphabet[dst - 'A'][i * 3 + j];
		}
	}
	sceKernelDcacheWritebackInvalidateRange(morph, sizeof(morph));
	sceGuMorphWeight(0, 1.0f);
	sceGuMorphWeight(1, 0.0f);
}

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x10], gap at: 0x4. */
void update_morph(int frame) {
    float temp_f20;

    temp_f20 = (float) frame / 15.0f;
    sceGuMorphWeight(0, 1.0f - temp_f20);
    sceGuMorphWeight(1, temp_f20);
}

void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumScale(const ScePspFVector3 *v);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
static void draw_alphabet(void)
{
	ScePspFVector3 vec;
	int i;

	sceGumPushMatrix();
	vec.x = 1.0f / 150.0f;
	vec.y = 1.0f / 150.0f;
	vec.z = 1.0f / 150.0f;
	sceGumScale(&vec);
	vec.x = startx;
	vec.y = 0.0f;
	vec.z = 0.0f;
	sceGumTranslate(&vec);
	for (i = 0; i < cur_len; i++) {
		vec.x = 23.5f;
		vec.y = 0.0f;
		vec.z = 0.0f;
		sceGumTranslate(&vec);
		sceGumDrawSpline(0x40180, 4, 25, 3, 3, NULL, morph[i]);
	}
	sceGumPopMatrix();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_string/nonmatchings/draw", update_data);

void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuColor(unsigned int color);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuPatchDivide(unsigned int ulevel, unsigned int vlevel);
void sceGumMultMatrix(const ScePspFMatrix4 *m);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void DrawData(void)
{
	ScePspFVector3 vec;

	update_data();
	sceGumPushMatrix();
	vec.x = 15.0f;
	vec.y = -15.0f;
	vec.z = 15.0f;
	sceGumScale(&vec);
	sceGuColor(0xffffffff);
	sceGuEnable(0xA);
	sceGuDisable(4);
	sceGuDisable(9);
	sceGuPatchDivide(2, 2);
	draw_alphabet();
	sceGumPopMatrix();
	sceGumPushMatrix();
	vec.x = 15.0f;
	vec.y = 15.0f;
	vec.z = 15.0f;
	sceGumScale(&vec);
	sceGuColor(0xe0ffffff);
	sceGuDisable(0xA);
	sceGuEnable(4);
	sceGuTexMode(4, 0, 0, 0);
	sceGuTexMapMode(0, 0, 1);
	sceGuTexImage(0, 128, 128, 128, marble_tex);
	sceGuClutLoad(1, marble_clut);
	sceGuEnable(9);
	sceGuPatchDivide(16, 16);
	sceGumDrawBezier(0x180, 4, 4, NULL, ground);
	sceGuColor(0xffffffff);
	sceGuEnable(0xA);
	sceGuDisable(4);
	sceGuTexMode(4, 0, 0, 0);
	sceGuTexMapMode(2, 2, 3);
	sceGuTexImage(0, 64, 64, 64, ref_tex);
	sceGuClutLoad(1, ref_clut);
	sceGuEnable(9);
	sceGuEnable(0xD);
	sceGuEnable(0xE);
	sceGuPatchDivide(4, 4);
	draw_alphabet();
	sceGuDisable(0xD);
	sceGuDisable(0xE);
	vec.x = 0.0f;
	vec.y = 0.001f;
	vec.z = 0.0f;
	sceGumTranslate(&vec);
	shadow_mat.y.x = -light_vec.x / light_vec.y;
	shadow_mat.y.z = -light_vec.z / light_vec.y;
	sceGumMultMatrix(&shadow_mat);
	sceGuColor(0xc0404040);
	sceGuDisable(0xA);
	sceGuEnable(4);
	sceGuDisable(9);
	sceGuEnable(3);
	sceGuPatchDivide(1, 1);
	draw_alphabet();
	sceGuDisable(3);
	sceGumPopMatrix();
}
