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

void geSetLight(int n, int param, geLIGHT *light)
{
	int enable = 0;

	if (n >= 4) {
		return;
	}

	geDrawStart();
	if (param & 1) {
		sceGuLight(n, light->type, light->comp, &light->vec);
		sceGuLightColor(n, 2, light->diff_col);
		sceGuLightColor(n, 4, light->spec_col);
		enable = 1;
	}

	if (param & 2) {
		sceGuLightSpot(n, &light->spot_vec, light->spot_s, light->spot_c);
		enable = 1;
	}

	if (param & 4) {
		sceGuLightAtt(n, light->att_a, light->att_b, light->att_c);
		enable = 1;
	}

	if (enable) {
		sceGuEnable(n + 11);
		sceGuEnable(10);
	}
	geDrawFinWait();
}

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

static inline void set_state(int flag, int state)
{
	if (flag == 1) {
		sceGuEnable(state);
	} else {
		sceGuDisable(state);
	}
}

static void init_context(void)
{
	geDrawStart();

	if (pCont->vramdepth == 1) {
		sceGuDrawBuffer(1, (void *)0, 512);
		sceGuDispBuffer(480, 272, (void *)0x44000, 512);
		sceGuDepthBuffer((void *)0x88000, 512);
	} else if (pCont->vramdepth == 3) {
		sceGuDrawBuffer(3, (void *)0, 512);
		sceGuDispBuffer(480, 272, (void *)0x88000, 512);
		sceGuDepthBuffer((void *)0x110000, 512);
	}

	sceGumSetMatrixStack(ge_matrix_stack, 8, 8, 16, 0);
	sceGuOffset(pCont->offset_x, pCont->offset_y);
	sceGuViewport(2048, 2048, 480, 272);
	sceGuDepthRange(pCont->depth_max, pCont->depth_min);

	sceGuScissor(0, 0, 480, 272);
	sceGuEnable(2);

	if (pCont->depth_test != -1) {
		sceGuEnable(1);
		sceGuDepthFunc(pCont->depth_test);
	} else {
		sceGuDisable(1);
	}

	sceGuShadeModel(pCont->shade_mode);
	sceGuFrontFace(pCont->front_face);
	set_state(pCont->clip_plane, 8);
	set_state(pCont->normal_patch, 20);
	set_state(pCont->normal_prim, 19);
	set_state(pCont->cull_face, 5);
	set_state(pCont->dither, 6);

	if (pCont->dither != -1) {
		sceGuSetDither(&ge_dith);
	}

	sceGuColorMaterial(pCont->col_material);
	sceGuSpecular(pCont->specular);

	if (pCont->fog != -1) {
		sceGuEnable(7);
		sceGuFog(pCont->fog_param.zs, pCont->fog_param.ze, pCont->fog_param.col);
	} else {
		sceGuDisable(7);
	}

	if (pCont->alpha != -1) {
		sceGuEnable(0);
		sceGuAlphaFunc(pCont->alpha_param.func, pCont->alpha_param.aref, pCont->alpha_param.amsk);
	} else {
		sceGuDisable(0);
	}

	if (pCont->blend != -1) {
		sceGuEnable(4);
		sceGuBlendFunc(pCont->blend_param.equ, pCont->blend_param.asel, pCont->blend_param.bsel, pCont->blend_param.afix, pCont->blend_param.bfix);
	} else {
		sceGuDisable(4);
	}

	sceGumMatrixMode(2);

	sceGuColor(pCont->col_model);
	sceGuAmbient(pCont->col_ambient);
	sceGuClearColor(pCont->col_clear);
	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuPatchDivide(4, 4);

	geDrawFinWait();
}
