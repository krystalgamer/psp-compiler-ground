/* data-align: 16 */
#include "common.h"

/* declarations recovered from DWARF */
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
struct _anon1;
struct _anon1 { /* size 0x18 */
    ScePspFVector3 rot;
    ScePspFVector3 trans;
};
typedef struct _anon1 POS;
typedef struct ScePspFMatrix4 ScePspFMatrix4;
struct ScePspFMatrix4;
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};

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


extern int D_0018DCC4;
#define frame D_0018DCC4
/* texture.h: the textures and CLUTs are aligned(16), so is the object's .rodata (and its size) */
__asm__(".section .rodata\n\t.align 4\n\t.previous");
extern char disp_list_18DD00[65536];
#define disp_list disp_list_18DD00
#define SCEGU_IMMEDIATE 0
#define SCEGU_CLEAR_ALL 7
#define MODE_DIFFUSE 0
#define MODE_SPECULAR 1
#define MODE_ENVMAP 2
#define MODE_TOON 3
#define SCEGU_DIFFUSE 2
#define SCEGU_SPECULAR 4
#define SCEGU_DIFFUSE_AND_SPECULAR 6
#define SCEGU_LIGHT_DIRECTION 0
#define SCEGU_LIGHT0 11
#define SCEGU_LIGHT1 12
#define SCEGU_TEXTURE 9
#define SCEGU_PFIDX4 4
#define SCEGU_PFIDX8 5
#define SCEGU_SINGLE_CLUT 0
#define SCEGU_TEXBUF_NORMAL 0
#define SCEGU_LINEAR_MIPMAP_LINEAR 7
#define SCEGU_LINEAR 1
#define SCEGU_TEX_REPLACE 3
#define SCEGU_TEX_MODULATE 0
#define SCEGU_RGB 0
#define SCEGU_REPEAT 0
#define SCEGU_PF5551 1
#define SCEGU_SHADE_MAP 2
#define SCEGU_SYNC_FINISH 0
#define SCEGU_SYNC_WAIT 0
#define SCEGU_RAD(x) ((x) * 3.1415927f / 180.0f)
#define SCEGU_PF8888 3
#define SCEGU_VRAM_BP32_0 ((void *)0)
#define SCEGU_VRAM_BP32_1 ((void *)0x88000)
#define SCEGU_VRAM_BP32_2 ((void *)0x110000)
#define SCEGU_VRAM_WIDTH 512
#define SCEGU_SCR_WIDTH 480
#define SCEGU_SCR_HEIGHT 272
#define SCEGU_SCR_OFFSETX ((4096 - SCEGU_SCR_WIDTH) / 2)
#define SCEGU_SCR_OFFSETY ((4096 - SCEGU_SCR_HEIGHT) / 2)
#define SCEGU_SCR_ASPECT ((float)SCEGU_SCR_WIDTH / (float)SCEGU_SCR_HEIGHT)
#define SCEGU_BLEND 4
#define SCEGU_SCISSOR_TEST 2
#define SCEGU_GREATER 6
#define SCEGU_DEPTH_TEST 1
#define SCEGU_CCW 1
#define SCEGU_NORMAL_REVERSE_PATCH 20
#define SCEGU_SMOOTH 1
#define SCEGU_DITHER 6
#define SCEGU_LIGHTING 10
#define SCEGU_MATRIX_PROJECTION 0
#define SCEGU_MATRIX_WORLD 2
#define SCEGU_DISPLAY_ON 1

int puts(const char *);
int sceGuStart(int, void *, int);
void sceGuClear(int);
void sceGuColor(unsigned int);
void sceGuAmbient(unsigned int);
void sceGuLightColor(int, int, unsigned int);
void sceGuLight(int, int, int, const ScePspFVector3 *);
void sceGuEnable(int);
void sceGuDisable(int);
void sceGuTexImage(int, int, int, int, const void *);
void sceGuTexMode(int, int, int, int);
void sceGuTexFilter(int, int);
void sceGuTexFunc(int, int);
void sceGuTexWrap(int, int);
void sceGuClutMode(unsigned int, unsigned int, unsigned int, unsigned int);
void sceGuClutLoad(int, const void *);
void sceGuTexMapMode(int, unsigned int, unsigned int);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumLoadIdentity(void);
void sceGumTranslate(const ScePspFVector3 *);
void sceGumRotateXYZ(const ScePspFVector3 *);
void sceGumRotateX(float);
void sceGumRotateY(float);
int sceGuFinish(void);
int sceGuSync(int, int);
void sceGuInit(void);
void sceGuDrawBuffer(int, void *, int);
void sceGuDispBuffer(int, int, void *, int);
void sceGuDepthBuffer(void *, int);
void sceGuOffset(unsigned int, unsigned int);
void sceGuViewport(int, int, int, int);
void sceGuDepthRange(int, int);
void sceGuScissor(int, int, int, int);
void sceGuDepthFunc(int);
void sceGuFrontFace(int);
void sceGuShadeModel(int);
void sceGuSpecular(float);
void sceGumSetMatrixStack(ScePspFMatrix4 *, int, int, int, int);
void sceGumMatrixMode(int);
void sceGumPerspective(float, float, float, float);
void sceGuClearColor(unsigned int);
void sceGuClearDepth(unsigned int);
void sceGuClearStencil(unsigned int);
int sceGuDisplay(int);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/draw", env_clut);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/draw", env_tex);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/draw", toon_clut);

INCLUDE_RODATA("tmp/asm/htmlviewer/htmlviewer/nonmatchings/draw", toon_tex);

void draw_frame(void)
{
    ScePspFVector3 vec;

    sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));

    sceGuClear(SCEGU_CLEAR_ALL);

    if (changed) {
        changed = 0;
        switch (mode) {
        case MODE_SPECULAR:
            sceGuColor(0xffb2b2a5);
            sceGuAmbient(0x00000000);
            vec.x = -1.299999f;
            vec.y = 4.125459f;
            vec.z = 3.799998f;
            sceGuLightColor(0, SCEGU_DIFFUSE, 0x77777777);
            sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
            sceGuEnable(SCEGU_LIGHT0);
            vec.x = 3.949999f;
            vec.y = 8.825475f;
            vec.z = 4.900001f;
            sceGuLightColor(1, SCEGU_DIFFUSE, 0x00000000);
            sceGuLightColor(1, SCEGU_SPECULAR, 0x77777777);
            sceGuLight(1, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE_AND_SPECULAR, &vec);
            sceGuEnable(SCEGU_LIGHT1);
            sceGuDisable(SCEGU_TEXTURE);
            puts("test1_new");
            break;
        case MODE_TOON:
            vec.x = 1.0f;
            vec.y = 0.0f;
            vec.z = 0.0f;
            sceGuLightColor(0, SCEGU_DIFFUSE, 0x77777777);
            sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
            sceGuEnable(SCEGU_LIGHT0);
            vec.x = 0.0f;
            vec.y = 1.0f;
            vec.z = 0.0f;
            sceGuLightColor(1, SCEGU_DIFFUSE, 0x77777777);
            sceGuLight(1, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
            sceGuEnable(SCEGU_LIGHT1);
            sceGuTexImage(0, 32, 32, 32, toon_tex);
            sceGuTexMode(SCEGU_PFIDX4, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
            sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_LINEAR);
            sceGuTexFunc(SCEGU_TEX_REPLACE, SCEGU_RGB);
            sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
            sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
            sceGuClutLoad(1, toon_clut);
            sceGuTexMapMode(SCEGU_SHADE_MAP, 0, 1);
            sceGuEnable(SCEGU_TEXTURE);
            puts("test2");
            break;
        case MODE_ENVMAP:
            sceGuColor(0xff97c5d0);
            sceGuAmbient(0x00000000);
            vec.x = 1.0f;
            vec.y = 0.0f;
            vec.z = 0.0f;
            sceGuLightColor(0, SCEGU_DIFFUSE, 0x77777777);
            sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
            sceGuEnable(SCEGU_LIGHT0);
            vec.x = 0.0f;
            vec.y = 1.0f;
            vec.z = 0.0f;
            sceGuLightColor(1, SCEGU_DIFFUSE, 0x77777777);
            sceGuLight(1, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
            sceGuEnable(SCEGU_LIGHT1);
            sceGuTexImage(0, 32, 32, 32, env_tex);
            sceGuTexMode(SCEGU_PFIDX8, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
            sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_LINEAR);
            sceGuTexFunc(SCEGU_TEX_MODULATE, SCEGU_RGB);
            sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
            sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
            sceGuClutLoad(16, env_clut);
            sceGuTexMapMode(SCEGU_SHADE_MAP, 0, 1);
            sceGuEnable(SCEGU_TEXTURE);
            puts("test3");
            break;
        case MODE_DIFFUSE:
        default:
            sceGuColor(0xff99bfcc);
            sceGuAmbient(0x00000000);
            vec.x = -1.299999f;
            vec.y = 4.125459f;
            vec.z = 3.799998f;
            sceGuLightColor(0, SCEGU_DIFFUSE, 0x77777777);
            sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
            sceGuEnable(SCEGU_LIGHT0);
            sceGuDisable(SCEGU_LIGHT1);
            sceGuDisable(SCEGU_TEXTURE);
            puts("test4");
            break;
        }
    }

    sceGumPushMatrix();
    sceGumLoadIdentity();
    sceGumTranslate(&pos.trans);
    if (autoflag) {
        angle = SCEGU_RAD((float)((frame * 2) % 360));
        vec.x = angle;
        vec.y = angle;
        vec.z = angle;
        sceGumRotateXYZ(&vec);
    } else {
        sceGumRotateX(SCEGU_RAD(pos.rot.x));
        sceGumRotateY(SCEGU_RAD(pos.rot.y));
    }

    sceGumPopMatrix();

    sceGuFinish();
    sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);

    frame++;
}

void init_all(void)
{
    sceGuInit();

    sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
    sceGuDrawBuffer(SCEGU_PF8888, SCEGU_VRAM_BP32_0, SCEGU_VRAM_WIDTH);
    sceGuDispBuffer(SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT, SCEGU_VRAM_BP32_1, SCEGU_VRAM_WIDTH);
    sceGuDepthBuffer(SCEGU_VRAM_BP32_2, SCEGU_VRAM_WIDTH);

    sceGuOffset(SCEGU_SCR_OFFSETX, SCEGU_SCR_OFFSETY);
    sceGuViewport(2048, 2048, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
    sceGuDepthRange(50000, 10000);

    sceGuDisable(SCEGU_BLEND);

    sceGuScissor(0, 0, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
    sceGuEnable(SCEGU_SCISSOR_TEST);

    sceGuDepthFunc(SCEGU_GREATER);
    sceGuEnable(SCEGU_DEPTH_TEST);

    sceGuFrontFace(SCEGU_CCW);
    sceGuEnable(SCEGU_NORMAL_REVERSE_PATCH);

    sceGuDisable(SCEGU_TEXTURE);
    sceGuShadeModel(SCEGU_SMOOTH);

    sceGuEnable(SCEGU_DITHER);
    sceGuEnable(SCEGU_LIGHTING);

    sceGuSpecular(75.0f);

    sceGumSetMatrixStack(matrix_stack, 8, 8, 32, 0);
    sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
    sceGumLoadIdentity();
    sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT, 1.000000f, 100.000000f);

    sceGuClearColor(0x00000000);
    sceGuClearDepth(0);
    sceGuClearStencil(0);

    sceGumMatrixMode(SCEGU_MATRIX_WORLD);
    sceGuFinish();
    sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
    sceGuDisplay(SCEGU_DISPLAY_ON);

    init_pos();
}

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
