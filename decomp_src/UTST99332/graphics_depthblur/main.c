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

static const float D_00015258[14] = { -1.0f, 0.0f, -1.0f, 1.333333254f, 1.0f, 1.333333254f, 1.0f, 0.0f, 1.0f, -1.333333254f, -1.0f, -1.333333254f, -1.0f, 0.0f };

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

void DepthBlurSetFocus(float _Focus);
void ResetAllPositioning()
{
	_camera_inverse_transform._pos.x=  0.0f;
	_camera_inverse_transform._pos.y=-12.0f;
	_camera_inverse_transform._pos.z=-44.0f;
	_camera_inverse_transform._rot.x= 16.0f;
	_camera_inverse_transform._rot.y=310.0f;
	_camera_inverse_transform._rot.z=  0.0f;

	_dragon_transform._pos.x=0.0f;
	_dragon_transform._pos.y=0.0f;
	_dragon_transform._pos.z=0.0f;
	_dragon_transform._rot.x=0.0f;
	_dragon_transform._rot.y=10.0f;
	_dragon_transform._rot.z=0.0f;

	focus = 0.0f;

	DepthBlurSetFocus( focus );
}

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


#ifndef SCEGU_PI /* sample */
#define SCEGU_PI                           3.1415926535897932384626433832f
#endif
#ifndef SCEGU_VERTEX_FLOAT /* sample */
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )
#endif
#ifndef SCEGU_NORMAL_REVERSE_PATCH /* sample */
#define SCEGU_NORMAL_REVERSE_PATCH        20
#endif
void DrawTorus(float inner, float outer)
{
	int		i, cnt;
	float	dist;

	cnt=0;
	
	float* arry = sceGuGetMemory(7*7*3*4);
	
	for (i=0; i<7; i++) {
		dist=outer+inner*(float)cosf(0.0f);
		arry[cnt+0 ]=arry[cnt+3]=D_00015258[i*2+0]*dist;
		arry[cnt+1 ]=arry[cnt+4]=D_00015258[i*2+1]*dist;
		arry[cnt+2 ]=0.0f;
		arry[cnt+5 ]=inner*1.333333f;

		dist=outer+inner*(float)cosf(SCEGU_PI);
		arry[cnt+6 ]=arry[cnt+ 9]=D_00015258[i*2+0]*dist;
		arry[cnt+7 ]=arry[cnt+10]=D_00015258[i*2+1]*dist;
		arry[cnt+8 ]=inner*1.333333f;
		arry[cnt+11]=0.0f;

		arry[cnt+12]= arry[cnt+6];
		arry[cnt+13]= arry[cnt+7];
		arry[cnt+14]=-arry[cnt+8];

		arry[cnt+15]= arry[cnt+3];
		arry[cnt+16]= arry[cnt+4];
		arry[cnt+17]=-arry[cnt+5];

		arry[cnt+18]=arry[cnt+0];
		arry[cnt+19]=arry[cnt+1];
		arry[cnt+20]=arry[cnt+2];
		cnt+=21;
	}
	sceGuDisable(SCEGU_NORMAL_REVERSE_PATCH);
	sceGumDrawBezier(SCEGU_VERTEX_FLOAT, 7, 7, 0, arry);
	sceGuEnable(SCEGU_NORMAL_REVERSE_PATCH);
}

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

extern const char D_00015290[];
extern const char D_000152A0[];
extern const char D_000152AC[];
extern const char D_000152C0[];
extern const char D_000152D4[];
extern const char D_000152E4[];
unsigned long long sceKernelGetSystemTimeWide(void);
#ifndef SCEGU_IMMEDIATE /* sample */
#define SCEGU_IMMEDIATE                    0
#endif
#ifndef SCEGU_CLEAR_ALL /* sample */
#define SCEGU_CLEAR_ALL               0x0007
#endif
#ifndef SCEGU_BLEND /* sample */
#define SCEGU_BLEND                        4
#endif
#ifndef SCEGU_MATRIX_WORLD /* sample */
#define SCEGU_MATRIX_WORLD                 2
#endif
#ifndef SCEGU_SYNC_FINISH /* sample */
#define SCEGU_SYNC_FINISH                  0
#endif
#ifndef SCEGU_SYNC_WAIT /* sample */
#define SCEGU_SYNC_WAIT                    0
#endif
extern const double D_000154C8;
extern double D_00019990;
extern double D_00019998;
extern float D_000199A0;
#define t_start D_00019990
#define t_end D_00019998
#define t D_000199A0
static void draw_frame(void)
{
	double t_diff = t_end - t_start;

	
	unsigned int status = sceGuGetAllStatus();

	t+=1.f/60.f;

	t_start = ((double) sceKernelGetSystemTimeWide())/ D_000154C8;
	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));

	
	sceGuClear(SCEGU_CLEAR_ALL);
	
	sceGuDisable(SCEGU_BLEND);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);
	sceGumLoadIdentity();

	DrawRoom();
	
	draw_dragon_with_camera_transform();

	if( modes[mode].toggle )
	{
		GenFrameBufferBlurmap(modes[mode].format,modes[mode].copy,
			!depthspread,frame32,modes[mode].final32);
	
		DepthBlurUpdate();
		DepthBlurDraw(); 
	}
	

	
	char buff[256];
	sprintf(buff,D_00015290,(float)t_diff);
	sceGuDebugPrint(10,10,0xff0000ff,buff);
	sceGuDebugPrint(10,20,0xff0000ff,modes[mode].desc);
	sprintf(buff,D_000152A0,focus);
	sceGuDebugPrint(10,30,0xff0000ff,buff);
	if(frame32)
		sceGuDebugPrint(10,40,0xff0000ff,D_000152AC);
	else
		sceGuDebugPrint(10,40,0xff0000ff,D_000152C0);
	if(depthspread)
		sceGuDebugPrint(10,50,0xff0000ff,D_000152D4);
	else
		sceGuDebugPrint(10,50,0xff0000ff,D_000152E4);
	
	
	
	
	sceKernelDcacheWritebackInvalidateAll();

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	t_end = ((double) sceKernelGetSystemTimeWide()) / D_000154C8;
	
	sceGuSetAllStatus(status);
}
#undef t_start
#undef t_end
#undef t

#ifndef SCEGU_IMMEDIATE /* sample */
#define SCEGU_IMMEDIATE                    0
#endif
#ifndef SCEGU_PF8888 /* sample */
#define SCEGU_PF8888                       3
#endif
#ifndef SCEGU_VRAM_BP32_0 /* sample */
#define SCEGU_VRAM_BP32_0     (void *)(SCEGU_VRAM_TOP)
#endif
#ifndef SCEGU_VRAM_BP32_1 /* sample */
#define SCEGU_VRAM_BP32_1     (void *)(SCEGU_VRAM_TOP+SCEGU_VRAM_BUFSIZE32)
#endif
#ifndef SCEGU_VRAM_BUFSIZE32 /* sample */
#define SCEGU_VRAM_BUFSIZE32  (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*4)
#endif
#ifndef SCEGU_VRAM_BP32_2 /* sample */
#define SCEGU_VRAM_BP32_2     (void *)(SCEGU_VRAM_TOP+(SCEGU_VRAM_BUFSIZE32*2))
#endif
#ifndef SCEGU_PF5650 /* sample */
#define SCEGU_PF5650                       0
#endif
#ifndef SCEGU_VRAM_BP_0 /* sample */
#define SCEGU_VRAM_BP_0       (void *)(SCEGU_VRAM_TOP)
#endif
#ifndef SCEGU_VRAM_BP_1 /* sample */
#define SCEGU_VRAM_BP_1       (void *)(SCEGU_VRAM_TOP+SCEGU_VRAM_BUFSIZE)
#endif
#ifndef SCEGU_VRAM_TOP /* sample */
#define SCEGU_VRAM_TOP        0x00000000
#endif
#ifndef SCEGU_VRAM_BUFSIZE /* sample */
#define SCEGU_VRAM_BUFSIZE    (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*2)
#endif
#ifndef SCEGU_VRAM_BP_2 /* sample */
#define SCEGU_VRAM_BP_2       (void *)(SCEGU_VRAM_TOP+(SCEGU_VRAM_BUFSIZE*2))
#endif
#ifndef SCEGU_VRAM_WIDTH /* sample */
#define SCEGU_VRAM_WIDTH      512
#endif
#ifndef SCEGU_SCR_OFFSETX /* sample */
#define SCEGU_SCR_OFFSETX     ((4096 - SCEGU_SCR_WIDTH) / 2)
#endif
#ifndef SCEGU_SCR_OFFSETY /* sample */
#define SCEGU_SCR_OFFSETY     ((4096 - SCEGU_SCR_HEIGHT) / 2)
#endif
#ifndef SCEGU_ADD /* sample */
#define SCEGU_ADD                          0
#endif
#ifndef SCEGU_SRC_ALPHA /* sample */
#define SCEGU_SRC_ALPHA                    2
#endif
#ifndef SCEGU_ONE_MINUS_SRC_ALPHA /* sample */
#define SCEGU_ONE_MINUS_SRC_ALPHA          3
#endif
#ifndef SCEGU_BLEND /* sample */
#define SCEGU_BLEND                        4
#endif
#ifndef SCEGU_SCISSOR_TEST /* sample */
#define SCEGU_SCISSOR_TEST                 2
#endif
#ifndef SCEGU_GREATER /* sample */
#define SCEGU_GREATER                      6
#endif
#ifndef SCEGU_ALPHA_TEST /* sample */
#define SCEGU_ALPHA_TEST                   0
#endif
#ifndef SCEGU_GEQUAL /* sample */
#define SCEGU_GEQUAL                       7
#endif
#ifndef SCEGU_DEPTH_TEST /* sample */
#define SCEGU_DEPTH_TEST                   1
#endif
#ifndef SCEGU_CW /* sample */
#define SCEGU_CW                           0
#endif
#ifndef SCEGU_NORMAL_REVERSE_PATCH /* sample */
#define SCEGU_NORMAL_REVERSE_PATCH        20
#endif
#ifndef SCEGU_TEX_MODULATE /* sample */
#define SCEGU_TEX_MODULATE                 0
#endif
#ifndef SCEGU_RGBA /* sample */
#define SCEGU_RGBA                         1
#endif
#ifndef SCEGU_LINEAR_MIPMAP_LINEAR /* sample */
#define SCEGU_LINEAR_MIPMAP_LINEAR         7
#endif
#ifndef SCEGU_NEAREST /* sample */
#define SCEGU_NEAREST                      0
#endif
#ifndef SCEGU_REPEAT /* sample */
#define SCEGU_REPEAT                       0
#endif
#ifndef SCEGU_TEXTURE /* sample */
#define SCEGU_TEXTURE                      9
#endif
#ifndef SCEGU_DITHER /* sample */
#define SCEGU_DITHER                       6
#endif
#ifndef SCEGU_CLIP_PLANE /* sample */
#define SCEGU_CLIP_PLANE                   8
#endif
#ifndef SCEGU_SMOOTH /* sample */
#define SCEGU_SMOOTH                       1
#endif
#ifndef SCEGU_SPECULAR /* sample */
#define SCEGU_SPECULAR                     4
#endif
#ifndef SCEGU_DIFFUSE_AND_SPECULAR /* sample */
#define SCEGU_DIFFUSE_AND_SPECULAR         6
#endif
#ifndef SCEGU_LIGHT0 /* sample */
#define SCEGU_LIGHT0                      11
#endif
#ifndef SCEGU_LIGHT_DIRECTION /* sample */
#define SCEGU_LIGHT_DIRECTION              0
#endif
#ifndef SCEGU_DIFFUSE /* sample */
#define SCEGU_DIFFUSE                      2
#endif
#ifndef SCEGU_LIGHT1 /* sample */
#define SCEGU_LIGHT1                      12
#endif
#ifndef SCEGU_LIGHTING /* sample */
#define SCEGU_LIGHTING                    10
#endif
#ifndef SCEGU_FOG /* sample */
#define SCEGU_FOG                          7
#endif
#ifndef SCEGU_MATRIX_PROJECTION /* sample */
#define SCEGU_MATRIX_PROJECTION            0
#endif
#ifndef SCEGU_PI /* sample */
#define SCEGU_PI                           3.1415926535897932384626433832f
#endif
#ifndef SCEGU_RAD /* sample */
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#endif
#ifndef SCEGU_SCR_WIDTH /* sample */
#define SCEGU_SCR_WIDTH       480
#endif
#ifndef SCEGU_SCR_HEIGHT /* sample */
#define SCEGU_SCR_HEIGHT      272
#endif
#ifndef SCEGU_SCR_ASPECT /* sample */
#define SCEGU_SCR_ASPECT      ((float)SCEGU_SCR_WIDTH / (float)SCEGU_SCR_HEIGHT)
#endif
#ifndef SCEGU_MATRIX_VIEW /* sample */
#define SCEGU_MATRIX_VIEW                  1
#endif
#ifndef SCEGU_MATRIX_WORLD /* sample */
#define SCEGU_MATRIX_WORLD                 2
#endif
#ifndef SCEGU_CULL_FACE /* sample */
#define SCEGU_CULL_FACE                    5
#endif
#ifndef SCEGU_SYNC_FINISH /* sample */
#define SCEGU_SYNC_FINISH                  0
#endif
#ifndef SCEGU_SYNC_WAIT /* sample */
#define SCEGU_SYNC_WAIT                    0
#endif
extern const ScePspIMatrix4 D_00015300;
static void init_gfx(void)
{
	ScePspIMatrix4 dith = D_00015300;
	ScePspFVector3 vec;

	sceGuInit();

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
	if(frame32)
	{
		sceGuDrawBuffer(SCEGU_PF8888, SCEGU_VRAM_BP32_0, SCEGU_VRAM_WIDTH);
		sceGuDispBuffer(SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT, SCEGU_VRAM_BP32_1, SCEGU_VRAM_WIDTH);
		sceGuDepthBuffer(SCEGU_VRAM_BP32_2, SCEGU_VRAM_WIDTH);
	}
	else
	{
		sceGuDrawBuffer(SCEGU_PF5650, SCEGU_VRAM_BP_0, SCEGU_VRAM_WIDTH);
		sceGuDispBuffer(SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT, SCEGU_VRAM_BP_1, SCEGU_VRAM_WIDTH);
		sceGuDepthBuffer(SCEGU_VRAM_BP_2, SCEGU_VRAM_WIDTH);
	}

	sceGuOffset(SCEGU_SCR_OFFSETX, SCEGU_SCR_OFFSETY);
	sceGuViewport(2048, 2048, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuDepthRange(32767, 0);

	sceGuBlendFunc(SCEGU_ADD, SCEGU_SRC_ALPHA, SCEGU_ONE_MINUS_SRC_ALPHA, 0, 0);
	sceGuEnable(SCEGU_BLEND);

	sceGuScissor(0, 0, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuEnable(SCEGU_SCISSOR_TEST);

	sceGuAlphaFunc(SCEGU_GREATER, 0x00, 0xff);
	sceGuEnable(SCEGU_ALPHA_TEST);

	sceGuDepthFunc(SCEGU_GEQUAL);
	sceGuEnable(SCEGU_DEPTH_TEST);

	sceGuFrontFace(SCEGU_CW);
	sceGuEnable(SCEGU_NORMAL_REVERSE_PATCH);

	sceGuTexFunc(SCEGU_TEX_MODULATE, SCEGU_RGBA);
	sceGuTexFilter(SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_NEAREST);
	sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
	sceGuDisable(SCEGU_TEXTURE);

	sceGuSetDither(&dith);
	sceGuEnable(SCEGU_DITHER);
	sceGuEnable(SCEGU_CLIP_PLANE);
	sceGuShadeModel(SCEGU_SMOOTH);

	vec.x=10.0f;
	vec.y= 4.0f;
	vec.z=10.0f;
	sceGuLightColor(0, SCEGU_DIFFUSE, 0xff008000);
	sceGuLightColor(0, SCEGU_SPECULAR, 0xffffffff);
	sceGuLight(0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE_AND_SPECULAR, &vec);
	sceGuEnable(SCEGU_LIGHT0);

	vec.x=-1.0f;
	vec.y=-2.0f;
	vec.z= 1.0f;
	sceGuLightColor(1, SCEGU_DIFFUSE, 0xff000080);
	sceGuLight(1, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &vec);
	sceGuEnable(SCEGU_LIGHT1);
	sceGuEnable(SCEGU_LIGHTING);

	sceGuSpecular(60.0f);

	sceGuFog(24.0f, 60.0f, 0xff000000);
	sceGuDisable(SCEGU_FOG);

	sceGuAmbient(0xffc0c0c0);

	sceGumSetMatrixStack(&matrix_stack[0], 8, 8, 32, 0);

	sceGumMatrixMode(SCEGU_MATRIX_PROJECTION);
	sceGumLoadIdentity();
	sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT, 1.000000f, 1000.000000f);

	sceGumMatrixMode(SCEGU_MATRIX_VIEW);
	sceGumLoadIdentity();

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);
	sceGumLoadIdentity();

	

	sceGuClearColor( 0xFF0F0F0F );

	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuDisable( SCEGU_CULL_FACE );

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();
	sceGuDisplay(1);
	
}

void init_all(void) {
    init_gfx();
    ResetAllPositioning();
    InitWall();
}

void DepthBlurSetFocus(float _Focus);
#ifndef SCE_CTRL_UP /* sample */
#define SCE_CTRL_UP					(1<<4)
#endif
#ifndef SCE_CTRL_DOWN /* sample */
#define SCE_CTRL_DOWN				(1<<6)
#endif
#ifndef SCE_CTRL_LEFT /* sample */
#define SCE_CTRL_LEFT				(1<<7)
#endif
#ifndef SCE_CTRL_RIGHT /* sample */
#define SCE_CTRL_RIGHT				(1<<5)
#endif
#ifndef DROT /* sample */
#define DROT		4.0f
#endif
#ifndef SCE_CTRL_CROSS /* sample */
#define SCE_CTRL_CROSS				(1<<14)
#endif
#ifndef NUM_MODES /* sample */
#define NUM_MODES 5
#endif
#ifndef SCE_CTRL_SQUARE /* sample */
#define SCE_CTRL_SQUARE				(1<<15)
#endif
#ifndef SCE_CTRL_TRIANGLE /* sample */
#define SCE_CTRL_TRIANGLE			(1<<12)
#endif
#ifndef SCE_CTRL_L /* sample */
#define SCE_CTRL_L					(1<<8)
#endif
#ifndef SCE_CTRL_L1 /* sample */
#define SCE_CTRL_L1					SCE_CTRL_L
#endif
#ifndef SCE_CTRL_R /* sample */
#define SCE_CTRL_R					(1<<9)
#endif
#ifndef SCE_CTRL_R1 /* sample */
#define SCE_CTRL_R1					SCE_CTRL_R
#endif
#ifndef DPOS /* sample */
#define DPOS		2.0f
#endif
#ifndef SCE_CTRL_CIRCLE /* sample */
#define SCE_CTRL_CIRCLE				(1<<13)
#endif
#ifndef SCE_CTRL_SELECT /* sample */
#define SCE_CTRL_SELECT				(1<<0)
#endif
#ifndef SCE_CTRL_START /* sample */
#define SCE_CTRL_START				(1<<3)
#endif
static int pad_read(void)
{
	u_int32        prev=cont;
	u_int32        padd;
	SceCtrlData    buf[8];
	int            ret;
	extern Positioning*  D_0001912C;

     ret = sceCtrlReadBufferPositive(buf, 8);
	if ( ret != 0 )
	{
		cont = buf[0].Buttons;
	}
	else
	{
		cont = 0;
	}
	padd=cont&(cont^prev);

	if ( cont & SCE_CTRL_UP )
	{
		D_0001912C->_rot.x-=DROT;
		if ( D_0001912C->_rot.x<0.0f )
			D_0001912C->_rot.x=360.0f+D_0001912C->_rot.x;
	}
	if ( cont & SCE_CTRL_DOWN )
	{
		D_0001912C->_rot.x+=DROT;
		if ( D_0001912C->_rot.x>=360.0f )
			D_0001912C->_rot.x=D_0001912C->_rot.x-360.0f;
	}
	if ( cont & SCE_CTRL_LEFT )
	{
		D_0001912C->_rot.y-=DROT;
		if ( D_0001912C->_rot.y<0.0f )
			D_0001912C->_rot.y=360.0f+D_0001912C->_rot.y;
	}
	if ( cont & SCE_CTRL_RIGHT )
	{
		D_0001912C->_rot.y+=DROT;
		if ( D_0001912C->_rot.y>=360.0f )
			D_0001912C->_rot.y=D_0001912C->_rot.y-360.0f;
	}
	
	if ( cont & SCE_CTRL_CROSS )
	{
		if( !( prev & SCE_CTRL_CROSS ) ) 
		{
			
			mode++;
			if(mode >= NUM_MODES)
			{
				mode=0;
			}
		}
	}
	
	if ( cont & SCE_CTRL_SQUARE )
	{
		focus -= 0.01f;
		if( focus < 0 )
			focus = 0;
          
		DepthBlurSetFocus( focus );
	}

	if ( cont & SCE_CTRL_TRIANGLE )
	{
		focus += 0.01f;
		if( focus > 1 )
			focus = 1;
		
		DepthBlurSetFocus( focus );
	}
	

	if ( cont & SCE_CTRL_L1 )
		D_0001912C->_pos.z-=DPOS;
	if ( cont & SCE_CTRL_R1 )
		D_0001912C->_pos.z+=DPOS;

	if ( padd & SCE_CTRL_CIRCLE )
		texflag^=1;

	if( padd & SCE_CTRL_SELECT )
		return 0;

	if( padd & SCE_CTRL_START )
	{
		if( !( prev & SCE_CTRL_START ) ) 
		{
			depthspread=!depthspread;
		}
	}

	return 1;
}

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

#define SCE_KERNEL_USER_LOWEST_PRIORITY         111
#define SCE_KERNEL_TH_USE_ScratchSRAM   0x00008000U
#define SCE_KERNEL_TH_USE_VFPU          0x00004000U
#define SCE_KERNEL_ERROR_NO_MEMORY 0x80020190
#define SCE_KERNEL_ERROR_ILLEGAL_ATTR 0x80020191
#define SCE_KERNEL_ERROR_ILLEGAL_STACK_SIZE 0x80020194
#define SCE_KERNEL_ERROR_ILLEGAL_PRIORITY 0x80020193
#define SCE_KERNEL_ERROR_ILLEGAL_ENTRY 0x80020192
#define SCE_KERNEL_ERROR_SPAD_INUSE 0x800201b9
#define SCE_KERNEL_ERROR_UNKNOWN_THID 0x80020198
#define SCE_KERNEL_ERROR_ILLEGAL_THID 0x80020197
#define SCE_KERNEL_ERROR_ILLEGAL_CONTEXT 0x80020064
#define SCE_KERNEL_ERROR_NOT_DORMANT 0x800201a4

extern const char D_00015340[], D_00015348[], D_00015358[], D_00015368[], D_00015394[], D_000153A0[], D_000153B0[], D_000153BC[], D_000153CC[], D_000153E0[], D_000153F4[], D_00015404[];
int puts(const char *s);
void StartMainThread()
{
	SceUID main_thread = 0;

	main_thread = sceKernelCreateThread( D_00015340, MainThread,
		SCE_KERNEL_USER_LOWEST_PRIORITY, 256*100,
		SCE_KERNEL_TH_USE_VFPU, NULL );

	if ( ((unsigned int)main_thread) == SCE_KERNEL_ERROR_NO_MEMORY )
	{
		puts(D_00015404);
	}
	else if ( ((unsigned int)main_thread) == SCE_KERNEL_ERROR_ILLEGAL_ATTR )
	{
		puts(D_000153F4);
	}
	else if ( ((unsigned int)main_thread) == SCE_KERNEL_ERROR_ILLEGAL_STACK_SIZE )
	{
		puts(D_000153E0);
	}
	else if ( ((unsigned int)main_thread) == SCE_KERNEL_ERROR_ILLEGAL_CONTEXT )
	{
		puts(D_000153A0);
	}
	else if ( ((unsigned int)main_thread) == SCE_KERNEL_ERROR_ILLEGAL_PRIORITY )
	{
		puts(D_000153CC);
	}
	else if ( ((unsigned int)main_thread) == SCE_KERNEL_ERROR_ILLEGAL_ENTRY )
	{
		puts(D_000153BC);
	}
	else if ( ((unsigned int)main_thread) == SCE_KERNEL_ERROR_SPAD_INUSE )
	{
		puts(D_000153B0);
	}
	else
	{
		int err = sceKernelStartThread( main_thread, 0, NULL );

		if ( ((unsigned int)err) == SCE_KERNEL_ERROR_UNKNOWN_THID )
		{
			puts(D_00015348);
		}
		else if ( ((unsigned int)err) == SCE_KERNEL_ERROR_ILLEGAL_THID )
		{
			puts(D_00015358);
		}
		else if ( ((unsigned int)err) == SCE_KERNEL_ERROR_ILLEGAL_CONTEXT )
		{
			puts(D_000153A0);
		}
		else if ( ((unsigned int)err) == SCE_KERNEL_ERROR_NOT_DORMANT )
		{
			puts(D_00015394);
		}
		else
		{
			puts(D_00015368);

			sceKernelSleepThread();
		}
	}
}

int main(void) {
    StartMainThread();
    return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000154C8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/main", D_000154CC);
