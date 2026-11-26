#include "common.h"

/* declarations recovered from DWARF */
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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

extern const unsigned int env_clut[128];
extern const unsigned int env_tex[256];
extern const unsigned int toon_clut[8];
extern const unsigned int toon_tex[128];
extern POS pos;
extern float angle;
extern int changed;
extern int autoflag;
extern int mode;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];

void draw_frame(void);
void init_all(void);
static void init_pos(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTerm(void);
void *sceGuSwapBuffers(void);
int sceDisplayWaitVblankStart(void);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuAmbient(unsigned int color);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuColor(unsigned int color);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDisable(int state);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
int sceGuFinish(void);
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuShadeModel(int mode);
void sceGuSpecular(float power);
void sceGuStart(int type, void *list, int size);
int sceGuSync(int mode, int what);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateXYZ(const ScePspFVector3 *v);
void sceGumRotateY(float angle);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumTranslate(const ScePspFVector3 *v);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", env_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", env_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", toon_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", toon_tex);

extern __typeof__(disp_list) disp_list_44B40;
#define disp_list disp_list_44B40
#define SCEGU_IMMEDIATE                    0
#define SCEGU_CLEAR_ALL               0x0007
#define MODE_SPECULAR ((0)+1)
#define SCEGU_SPECULAR                     4
#define SCEGU_DIFFUSE_AND_SPECULAR         6
#define MODE_TOON ((0)+3)
#define SCEGU_PFIDX4                       4
#define SCEGU_TEX_REPLACE                  3
#define MODE_ENVMAP ((0)+2)
#define SCEGU_PFIDX8                       5
#define SCEGU_SINGLE_CLUT                  0
#define SCEGU_TEXBUF_NORMAL                0
#define SCEGU_LINEAR_MIPMAP_LINEAR         7
#define SCEGU_LINEAR                       1
#define SCEGU_TEX_MODULATE                 0
#define SCEGU_RGB                          0
#define SCEGU_REPEAT                       0
#define SCEGU_PF5551                       1
#define SCEGU_SHADE_MAP                    2
#define MODE_DIFFUSE (0)
#define SCEGU_LIGHT_DIRECTION              0
#define SCEGU_DIFFUSE                      2
#define SCEGU_LIGHT0                      11
#define SCEGU_LIGHT1                      12
#define SCEGU_TEXTURE                      9
#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#define SCEGU_SYNC_FINISH                  0
#define SCEGU_SYNC_WAIT                    0

void draw_frame(void)
{
	extern int D_00044B04;

	ScePspFVector3	vec;

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));

	sceGuClear(SCEGU_CLEAR_ALL);

	if (changed) {
		changed = 0;
		switch (mode) {
		case MODE_SPECULAR:
			
			sceGuColor(0xffb2b2a5);
			sceGuAmbient(0xff866557);

			
			vec.x = -1.299999f;
			vec.y = 4.125459f;
			vec.z = 3.799998f;
			sceGuLightColor(0, SCEGU_DIFFUSE, 0xffffffff);
			sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
			sceGuEnable(SCEGU_LIGHT0);
			vec.x = 3.949999f;
			vec.y = 8.825475f;
			vec.z = 4.900001f;
			sceGuLightColor(1, SCEGU_DIFFUSE, 0x00000000);
			sceGuLightColor(1, SCEGU_SPECULAR, 0xffffffff);
			sceGuLight(1, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE_AND_SPECULAR,
					&vec);
			sceGuEnable(SCEGU_LIGHT1);

			
			sceGuDisable(SCEGU_TEXTURE);
			break;
		case MODE_TOON:
			
			vec.x = 1.0f;
			vec.y = 0.0f;
			vec.z = 0.0f;
			sceGuLightColor(0, SCEGU_DIFFUSE, 0xffffffff);
			sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
			sceGuEnable(SCEGU_LIGHT0);
			vec.x = 0.0f;
			vec.y = 1.0f;
			vec.z = 0.0f;
			sceGuLightColor(1, SCEGU_DIFFUSE, 0xffffffff);
			sceGuLight(1, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
			sceGuEnable(SCEGU_LIGHT1);

			
			sceGuTexImage(0, 32, 32, 32, toon_tex);
			sceGuTexMode(SCEGU_PFIDX4, 0, SCEGU_SINGLE_CLUT,
					SCEGU_TEXBUF_NORMAL);
			sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_LINEAR);
			sceGuTexFunc(SCEGU_TEX_REPLACE, SCEGU_RGB);
			sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
			sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
			sceGuClutLoad(1, toon_clut);
			sceGuTexMapMode(SCEGU_SHADE_MAP, 0, 1);
			sceGuEnable(SCEGU_TEXTURE);
			break;
		case MODE_ENVMAP:
			
			sceGuColor(0xff97c5d0);
			sceGuAmbient(0xff648296);

			
			vec.x = 1.0f;
			vec.y = 0.0f;
			vec.z = 0.0f;
			sceGuLightColor(0, SCEGU_DIFFUSE, 0xffffffff);
			sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
			sceGuEnable(SCEGU_LIGHT0);
			vec.x = 0.0f;
			vec.y = 1.0f;
			vec.z = 0.0f;
			sceGuLightColor(1, SCEGU_DIFFUSE, 0xffffffff);
			sceGuLight(1, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
			sceGuEnable(SCEGU_LIGHT1);

			
			sceGuTexImage(0, 32, 32, 32, env_tex);
			sceGuTexMode(SCEGU_PFIDX8, 0, SCEGU_SINGLE_CLUT,
					SCEGU_TEXBUF_NORMAL);
			sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_LINEAR);
			sceGuTexFunc(SCEGU_TEX_MODULATE, SCEGU_RGB);
			sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
			sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
			sceGuClutLoad(16, env_clut);
			sceGuTexMapMode(SCEGU_SHADE_MAP, 0, 1);
			sceGuEnable(SCEGU_TEXTURE);
			break;
		case MODE_DIFFUSE:
		default:
			
			sceGuColor(0xff99bfcc);
			sceGuAmbient(0xff667272);

			
			vec.x = -1.299999f;
			vec.y = 4.125459f;
			vec.z = 3.799998f;
			sceGuLightColor(0, SCEGU_DIFFUSE, 0xffffffff);
			sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
			sceGuEnable(SCEGU_LIGHT0);
			sceGuDisable(SCEGU_LIGHT1);

			
			sceGuDisable(SCEGU_TEXTURE);
			break;
		}
	}

	sceGumPushMatrix();
	sceGumLoadIdentity();
	sceGumTranslate(&pos.trans);
	if (autoflag) {
		angle = SCEGU_RAD((float)((D_00044B04*2)%360));
		vec.x = angle;
		vec.y = angle;
		vec.z = angle;
		sceGumRotateXYZ(&vec);
	} else {
		sceGumRotateX(SCEGU_RAD(pos.rot.x));
		sceGumRotateY(SCEGU_RAD(pos.rot.y));
	}
	DrawPot();

	sceGumPopMatrix();

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);

	D_00044B04++;
}

INCLUDE_ASM("tmp/asm/UTST99332/utility_basic/nonmatchings/draw", init_all);

static void init_pos(void)
{
    pos.rot.x = 30.0f;
    pos.rot.y = pos.rot.z = 0.0f;
    pos.trans.x = 0.0f;
    pos.trans.y = -0.5f;
    pos.trans.z = -10.0f;
}

void term_all(void) {
    sceGuTerm();
}

void vsync_frame(void) {
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}
