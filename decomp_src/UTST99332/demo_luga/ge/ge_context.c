/* cflags: -O2 -frename-registers */
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
typedef unsigned int uint;
struct _anon1 { /* size 0x3c */
    int type;
    int comp;
    ScePspFVector3 vec;
    uint diff_col;
    uint spec_col;
    float spot_s;
    float spot_c;
    ScePspFVector3 spot_vec;
    float att_a;
    float att_b;
    float att_c;
};
typedef struct _anon1 geLIGHT;
struct _anon2;
struct _anon2 { /* size 0x34 */
    float cam_fovy;
    float cam_aspect;
    float cam_near;
    float cam_far;
    ScePspFVector3 cam_eye;
    ScePspFVector3 cam_center;
    ScePspFVector3 cam_up;
};
typedef struct _anon2 geCAMERA;
struct _anon3;
struct _anon4;
struct _anon4 { /* size 0xc */
    float zs;
    float ze;
    uint col;
};
typedef struct _anon4 geFOG;
struct _anon5;
struct _anon5 { /* size 0xc */
    int func;
    int aref;
    int amsk;
};
typedef struct _anon5 geALPHA;
struct _anon6;
struct _anon6 { /* size 0x14 */
    int equ;
    int asel;
    int bsel;
    int afix;
    int bfix;
};
typedef struct _anon6 geBLEND;
struct _anon3 { /* size 0x80 */
    int vramdepth;
    int offset_x;
    int offset_y;
    int depth_min;
    int depth_max;
    uint col_clear;
    uint col_ambient;
    uint col_model;
    int depth_test;
    int shade_mode;
    int front_face;
    int clip_plane;
    int normal_patch;
    int normal_prim;
    int cull_face;
    int dither;
    int col_material;
    float specular;
    int fog;
    geFOG fog_param;
    int alpha;
    geALPHA alpha_param;
    int blend;
    geBLEND blend_param;
};
typedef struct _anon3 geCONTEXT;
struct _anon7;
struct _anon7 { /* size 0x24 */
    ScePspFVector3 trans;
    ScePspFVector3 rotate;
    ScePspFVector3 scale;
};
typedef struct _anon7 geWORLD;
typedef unsigned char uchar;
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

extern ScePspFMatrix4 ge_matrix_stack[32];
extern ScePspIMatrix4 ge_dith;
extern geCONTEXT *pCont;

void geSetLight(int n, int param, geLIGHT *light);
void geSetCamera(int param, geCAMERA *camera);
void geSetContext(geCONTEXT *context);
void geGetContext(geCONTEXT *context);
void geSetWorld(geWORLD *world);
void geColor(uchar r, uchar g, uchar b, uchar a);
static void init_context(void);
static void set_mode(int mode, int state);


void sceGumTranslate(const ScePspFVector3 *v);
void sceGumScale(const ScePspFVector3 *v);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);

/* SDK prototypes (tools/sdk_protos.h) */
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColorMaterial(int components);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDisable(int state);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
void sceGuFog(float near, float far, unsigned int color);
void sceGuFrontFace(int order);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightAtt(int light, float atten0, float atten1, float atten2);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuLightSpot(int light, const ScePspFVector3 *direction, float exponent, float cutoff);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuPatchDivide(unsigned int ulevel, unsigned int vlevel);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuSpecular(float power);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumLookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center, const ScePspFVector3 *up);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);

/* module functions defined in other units */
void geDrawFinWait(void);
void geDrawStart(void);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_context", geSetLight);

void geSetCamera(int param, geCAMERA *camera)
{
	geDrawStart();

	if (param & 2) {
		sceGumMatrixMode(1);
		sceGumLoadIdentity();
		sceGumLookAt(&camera->cam_eye, &camera->cam_center, &camera->cam_up);
	}

	if (param & 1) {
		sceGumMatrixMode(0);
		sceGumLoadIdentity();
		sceGumPerspective(camera->cam_fovy, camera->cam_aspect, camera->cam_near, camera->cam_far);
	}

	sceGumMatrixMode(2);

	geDrawFinWait();
}

void geSetContext(geCONTEXT *context)
{
	int i;
	u32 *src = (u32 *)context;
	u32 *dst = (u32 *)pCont;

	for (i = 0; i < sizeof(geCONTEXT) / 4; i++) {
		dst[i] = src[i];
	}

	init_context();
}

void geGetContext(geCONTEXT *context)
{
	int i;
	u32 *src = (u32 *)pCont;
	u32 *dst = (u32 *)context;

	for (i = 0; i < sizeof(geCONTEXT) / 4; i++) {
		dst[i] = src[i];
	}
}

void geSetWorld(geWORLD *world) {
    sceGumTranslate(&world->trans);
    sceGumRotateX((world->rotate.x * 3.1415927f) / 180.0f);
    sceGumRotateY((world->rotate.y * 3.1415927f) / 180.0f);
    sceGumRotateZ((world->rotate.z * 3.1415927f) / 180.0f);
    sceGumScale(&world->scale);
}

void gePush(void) {
    sceGumPushMatrix();
}

void gePop(void) {
    sceGumPopMatrix();
}

void geIdentity(void) {
    sceGumLoadIdentity();
}

void geColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    sceGuColor((a << 0x18) + ((b & 0xFF) << 0x10) + ((g & 0xFF) << 8) + (r & 0xFF));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_context", init_context);
