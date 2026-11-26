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
struct _anon1 { /* size 0x18 */
    ScePspFVector3 _pos;
    ScePspFVector3 _rot;
};
typedef struct _anon1 Positioning;
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
typedef unsigned int SceSize;
typedef int SceUID;
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
typedef int bool;
struct _anon2;
struct _anon2 { /* size 0x14 */
    unsigned int format;
    bool toggle;
    bool copy;
    bool final32;
    const char *desc;
};

extern unsigned int checkcolor[1];
extern unsigned int check32x32[128];
extern unsigned int check16x16[64];
extern unsigned int check8x8[32];
extern unsigned int check4x4[16];
extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern int sce_newlib_heap_kb_size;
extern char disp_list[65536];
extern ScePspFMatrix4 matrix_stack[48];
extern Positioning _camera_inverse_transform;
extern Positioning _dragon_transform;
extern int texflag;
extern bool frame32;
extern bool depthspread;
extern float focus;
extern int mode;
extern const struct _anon2 modes[5];
extern float wall[80];
extern u_int32 cont;

void ResetAllPositioning();

/* SDK functions (tools/sdk_protos.h) */
void sceGuDisable(int state);
void sceGumPushMatrix(void);
void sceGumPopMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumTranslate(const ScePspFVector3 *v);

static void PositioningMultMatrix(Positioning *_Positioning);
static void draw_dragon_with_camera_transform();
void InitWall(void);
void DrawTorus(float inner, float outer);
void DrawRoom(void);
static void draw_frame(void);
static void init_gfx(void);
static int pad_read(void);
void StartMainThread();


/* SDK prototypes (tools/sdk_protos.h) */
float cosf(float x);
int puts(const char *s);
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuColor(unsigned int color);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
int sceGuFinish(void);
void sceGuFog(float near, float far, unsigned int color);
void sceGuFrontFace(int order);
unsigned int sceGuGetAllStatus(void);
void *sceGuGetMemory(int size);
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetAllStatus(unsigned int status);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuSpecular(float power);
void sceGuStart(int type, void *list, int size);
int sceGuSync(int mode, int what);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumScale(const ScePspFVector3 *v);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
int sceKernelCreateThread(const char *name, void *entry, int prio, int stacksize, unsigned int attr, void *option);
int sceKernelDcacheWritebackInvalidateAll(void);
int sceKernelSleepThread(void);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);
int sprintf(char *buf, const char *fmt, ...);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000151A0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000151AC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000151C8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000151D8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000151E4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", modes);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015258);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015290);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000152A0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000152AC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000152C0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000152D4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000152E4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015300);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015340);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015348);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015358);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015368);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015394);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000153A0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000153B0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000153BC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000153CC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000153E0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000153F4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_00015404);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", ResetAllPositioning);

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x0, 0x4, 0x10, 0x14], gap at: 0x8. */
void PositioningMultMatrix(Positioning *_Positioning) {
    sceGumTranslate(&_Positioning->_pos);
    sceGumRotateX((_Positioning->_rot.x * 3.1415927f) / 180.0f);
    sceGumRotateY((_Positioning->_rot.y * 3.1415927f) / 180.0f);
    sceGumRotateZ((_Positioning->_rot.z * 3.1415927f) / 180.0f);
}

void draw_dragon_with_camera_transform(void) {
    sceGumPushMatrix();
    PositioningMultMatrix(&_camera_inverse_transform);
    PositioningMultMatrix(&_dragon_transform);
    sceGuDisable(4);
    sceGuDisable(0);
    sceGuDisable(5);
    DrawDragon(texflag);
    sceGumPopMatrix();
}

void InitWall(void)
{
	float* vert = wall;
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			*(vert++)=i/3.0f;
			*(vert++)=j/3.0f;
			*(vert++)=-1+i*2/3.0f;
			*(vert++)=1;
			*(vert++)=-1+j*2/3.0f;
		}
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", DrawTorus);

#define SCEGU_PFIDX4                       4
#define SCEGU_SINGLE_CLUT                  0
#define SCEGU_TEXBUF_NORMAL                0
#define SCEGU_LINEAR_MIPMAP_LINEAR         7
#define SCEGU_NEAREST                      0
#define SCEGU_TEX_MODULATE                 0
#define SCEGU_RGB                          0
#define SCEGU_REPEAT                       0
#define SCEGU_PF5551                       1
#define SCEGU_TEXTURE                      9
#define SCEGU_TEXTURE_FLOAT      ( 3 <<  0 )
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )
#define SCEGU_CULL_FACE                    5
#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)

void DrawRoom(void)
{
	ScePspFVector3	vec;
	float			*vp;
	extern float D_00019988;
	
	sceGuTexMode(SCEGU_PFIDX4, 3, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
	sceGuTexImage(0, 32, 32, 32, check32x32);
	sceGuTexImage(1, 16, 16, 32, check16x16);
	sceGuTexImage(2,  8,  8, 32, check8x8);
	sceGuTexImage(3,  4,  4, 32, check4x4);
	sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_NEAREST);
	sceGuTexFunc(SCEGU_TEX_MODULATE, SCEGU_RGB);
	sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
	sceGuTexOffset(0.0f, 0.0f);
	sceGuTexScale(2.0f, 2.0f);
	sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
	sceGuClutLoad(1, checkcolor);
	sceGuEnable(SCEGU_TEXTURE);
	
	sceGumPushMatrix();
	sceGumLoadIdentity();
	vec.x=0;
	vec.y=7;
	vec.z=-130;
	sceGumTranslate(&vec);
	vec.x = 40;
	vec.y = 20;
	vec.z = 100;
	sceGumScale(&vec);
	
	vp = (float*)sceGuGetMemory(5*4*4*4);
	memcpy((void *)vp, wall,5*4*4*4);
	
	sceGuDisable(SCEGU_CULL_FACE);
	sceGumDrawBezier(SCEGU_TEXTURE_FLOAT|SCEGU_VERTEX_FLOAT, 4, 4, 0, vp);
	sceGumRotateX(SCEGU_RAD(-90));
	sceGumDrawBezier(SCEGU_TEXTURE_FLOAT|SCEGU_VERTEX_FLOAT, 4, 4, 0, vp);
	sceGumRotateX(SCEGU_RAD(-90));
	sceGumDrawBezier(SCEGU_TEXTURE_FLOAT|SCEGU_VERTEX_FLOAT, 4, 4, 0, vp);
	sceGumRotateZ(SCEGU_RAD(90));
	sceGumDrawBezier(SCEGU_TEXTURE_FLOAT|SCEGU_VERTEX_FLOAT, 4, 4, 0, vp);
	sceGumRotateZ(SCEGU_RAD(180));
	sceGumDrawBezier(SCEGU_TEXTURE_FLOAT|SCEGU_VERTEX_FLOAT, 4, 4, 0, vp);
	sceGuEnable(SCEGU_CULL_FACE);
	
	sceGumPopMatrix();
	
	D_00019988 += 1;
	if(D_00019988>360)
		D_00019988-=360;
	
	sceGuTexScale(1.0f, 1.0f);
	
	sceGumPushMatrix();
	sceGumLoadIdentity();
	
	sceGumPushMatrix();
	vec.x=-12;
	vec.y=0;
	vec.z=-50;
	sceGumTranslate(&vec);
	sceGumRotateY(SCEGU_RAD(D_00019988));
	sceGuColor(0xff7f7f);
	DrawTorus(2,4);
	sceGumPopMatrix();
	
	sceGumPushMatrix();
	vec.x=6;
	vec.y=0;
	vec.z=-14;
	sceGumTranslate(&vec);
	sceGumRotateY(SCEGU_RAD(-D_00019988+46));
	sceGuColor(0x7f7fff);
	DrawTorus(2,4);
	sceGumPopMatrix();
	
	sceGumPopMatrix();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", init_gfx);

void init_all(void) {
    init_gfx();
    ResetAllPositioning();
    InitWall();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", pad_read);

int MainThread(unsigned int _ArgNum, void *_ArgData) {
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
    menuTerm(1, 5);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", StartMainThread);

int main(void) {
    StartMainThread();
    return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000154C8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000154CC);
