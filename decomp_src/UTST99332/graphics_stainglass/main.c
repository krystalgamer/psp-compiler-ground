#include "common.h"
#include <psptypes.h>
#include <libgu.h>
#include <libgum.h>
#include <kerneltypes.h>
#include <ctrlsvc.h>
#include <displaysvc.h>

/* types and file-scope data from the SDK sample's main.c (data defined in the asm data files) */
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef int bool;
#define true 1
#define false 0

typedef struct
{
	ScePspFVector3 _pos;
	ScePspFVector3 _rot;

} Positioning;

extern char disp_list[0x10000];
extern ScePspFMatrix4 matrix_stack[8+8+32+0];
extern Positioning _camera_inverse_transform;
extern Positioning _dragon_transform;
extern Positioning _stainglass_transform;
extern int texflag;
extern float distort;
extern u_int32 cont;

extern void DrawDragon(int tex);
void GenFrameBufferMipmap(void);
void UseFrameBufferMipmap(void);
void StainGlassInit(void);
void StainGlassRelease(void);
void StainGlassUpdate(void);
void StainGlassDraw( bool textured );
void StainGlassSetTransform( const ScePspFMatrix4 *m );
void StainGlassSetDistorsion( const float _Distort );

void ResetAllPositioning();
static void PositioningMultMatrix( Positioning* _Positioning );
static void PositioningStoreMatrix( Positioning* _Positioning, ScePspMatrix4* _Mat );
static void draw_dragon_with_camera_transform();
static void draw_frame(void);
static void init_all(void);
static int pad_read(void);
int MainThread( SceSize _ArgNum, void* _ArgData );
void StartMainThread();


/* SDK prototypes (tools/sdk_protos.h) */
int puts(const char *s);
int sceDisplayWaitVblankStart(void);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthFunc(int function);
void sceGuDepthRange(int near, int far);
void sceGuDisable(int state);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
int sceGuFinish(void);
void sceGuFog(float near, float far, unsigned int color);
void sceGuFrontFace(int order);
void sceGuInit(void);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuSetDither(const void *matrix);
void sceGuShadeModel(int mode);
void sceGuSpecular(float power);
void sceGuStart(int type, void *list, int size);
void *sceGuSwapBuffers(void);
int sceGuSync(int mode, int what);
void sceGuTerm(void);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumLoadIdentity(void);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
int sceKernelCreateThread(const char *name, void *entry, int prio, int stacksize, unsigned int attr, void *option);
int sceKernelDcacheWritebackInvalidateAll(void);
int sceKernelSleepThread(void);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);

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

	_stainglass_transform._pos.x=0.f;
	_stainglass_transform._pos.y=0.f;
	_stainglass_transform._pos.z=-28.f;
	_stainglass_transform._rot.x=30.f;
	_stainglass_transform._rot.y=10.f;
	_stainglass_transform._rot.z=0.f;

	distort=0.015f;

	StainGlassSetDistorsion( distort );
}

void sceGumTranslate(const ScePspFVector3 *v);
static void PositioningMultMatrix( Positioning* _Positioning )
{
	sceGumTranslate( &_Positioning->_pos );
	sceGumRotateX( (_Positioning->_rot.x * 3.1415927f / 180.0f) );
	sceGumRotateY( (_Positioning->_rot.y * 3.1415927f / 180.0f) );
	sceGumRotateZ( (_Positioning->_rot.z * 3.1415927f / 180.0f) );
}

static void PositioningStoreMatrix( Positioning* _Positioning
	, ScePspMatrix4* _Mat )
{
	sceGumPushMatrix();
	sceGumLoadIdentity();

	PositioningMultMatrix( _Positioning );

	sceGumStoreMatrix( &_Mat->fm );
	sceGumPopMatrix();
}

#define SCEGU_BLEND                        4
#define SCEGU_ALPHA_TEST                   0
#define SCEGU_CULL_FACE                    5

static void draw_dragon_with_camera_transform()
{
	sceGumPushMatrix();

	PositioningMultMatrix( & _camera_inverse_transform );

	PositioningMultMatrix( & _dragon_transform );

	sceGuDisable( SCEGU_BLEND );
	sceGuDisable( SCEGU_ALPHA_TEST);

	sceGuDisable( SCEGU_CULL_FACE );

	DrawDragon(texflag);

	sceGumPopMatrix();
}

#define SCEGU_IMMEDIATE                    0
#define SCEGU_CLEAR_ALL               0x0007
#define SCEGU_MATRIX_WORLD                 2
#define SCEGU_SYNC_FINISH                  0
#define SCEGU_SYNC_WAIT                    0

static void draw_frame(void)
{
	extern float D_00017484;

	{
		ScePspMatrix4 stain_mat;
		PositioningStoreMatrix( &_stainglass_transform, &stain_mat );
		StainGlassSetTransform( &stain_mat.fm );
	}

	D_00017484+=1.f/60.f;

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));

	sceGuClear(SCEGU_CLEAR_ALL);

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);



	
	
	

	

	sceGumLoadIdentity();

	draw_dragon_with_camera_transform();



	GenFrameBufferMipmap();



	StainGlassUpdate();



	StainGlassDraw(true); 

	

	
	
	sceKernelDcacheWritebackInvalidateAll();

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
}

#define SCEGU_PF8888                       3
#define SCEGU_VRAM_BP32_0     (void *)(SCEGU_VRAM_TOP)
#define SCEGU_VRAM_BP32_1     (void *)(SCEGU_VRAM_TOP+SCEGU_VRAM_BUFSIZE32)
#define SCEGU_VRAM_TOP        0x00000000
#define SCEGU_VRAM_BUFSIZE32  (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*4)
#define SCEGU_VRAM_BP32_2     (void *)(SCEGU_VRAM_TOP+(SCEGU_VRAM_BUFSIZE32*2))
#define SCEGU_VRAM_WIDTH      512
#define SCEGU_SCR_OFFSETX     ((4096 - SCEGU_SCR_WIDTH) / 2)
#define SCEGU_SCR_OFFSETY     ((4096 - SCEGU_SCR_HEIGHT) / 2)
#define SCEGU_ADD                          0
#define SCEGU_SRC_ALPHA                    2
#define SCEGU_ONE_MINUS_SRC_ALPHA          3
#define SCEGU_SCISSOR_TEST                 2
#define SCEGU_GREATER                      6
#define SCEGU_GEQUAL                       7
#define SCEGU_DEPTH_TEST                   1
#define SCEGU_CW                           0
#define SCEGU_NORMAL_REVERSE_PATCH        20
#define SCEGU_TEX_MODULATE                 0
#define SCEGU_RGBA                         1
#define SCEGU_LINEAR_MIPMAP_LINEAR         7
#define SCEGU_NEAREST                      0
#define SCEGU_REPEAT                       0
#define SCEGU_TEXTURE                      9
#define SCEGU_DITHER                       6
#define SCEGU_CLIP_PLANE                   8
#define SCEGU_SMOOTH                       1
#define SCEGU_SPECULAR                     4
#define SCEGU_DIFFUSE_AND_SPECULAR         6
#define SCEGU_LIGHT0                      11
#define SCEGU_LIGHT_DIRECTION              0
#define SCEGU_DIFFUSE                      2
#define SCEGU_LIGHT1                      12
#define SCEGU_LIGHTING                    10
#define SCEGU_FOG                          7
#define SCEGU_MATRIX_PROJECTION            0
#define SCEGU_PI                           3.1415926535897932384626433832f
#define SCEGU_RAD(a)                       ((a)*SCEGU_PI/180.0f)
#define SCEGU_SCR_WIDTH       480
#define SCEGU_SCR_HEIGHT      272
#define SCEGU_SCR_ASPECT      ((float)SCEGU_SCR_WIDTH / (float)SCEGU_SCR_HEIGHT)
#define SCEGU_MATRIX_VIEW                  1
#define SCEGU_DISPLAY_ON		1

extern const ScePspIMatrix4 D_000133D0;
static void init_all(void)
{
	ScePspIMatrix4 dith = D_000133D0;
	ScePspFVector3 vec;

	sceGuInit();

	sceGuStart(SCEGU_IMMEDIATE, disp_list, sizeof(disp_list));
	sceGuDrawBuffer(SCEGU_PF8888, SCEGU_VRAM_BP32_0, SCEGU_VRAM_WIDTH);
	sceGuDispBuffer(SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT, SCEGU_VRAM_BP32_1, SCEGU_VRAM_WIDTH);
	sceGuDepthBuffer(SCEGU_VRAM_BP32_2, SCEGU_VRAM_WIDTH);

	sceGuOffset(SCEGU_SCR_OFFSETX, SCEGU_SCR_OFFSETY);
	sceGuViewport(2048, 2048, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT);
	sceGuDepthRange(50000, 10000);

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

	sceGuDisable(SCEGU_DITHER);
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
	sceGumPerspective(SCEGU_RAD(45.0f), SCEGU_SCR_ASPECT, 1.000000f, 100.000000f);

	sceGumMatrixMode(SCEGU_MATRIX_VIEW);
	sceGumLoadIdentity();

	sceGumMatrixMode(SCEGU_MATRIX_WORLD);
	sceGumLoadIdentity();

	

	sceGuClearColor( 0xFFFFFFFF );

	sceGuClearDepth(0);
	sceGuClearStencil(0);

	sceGuDisable( SCEGU_CULL_FACE );

	sceGuFinish();
	sceGuSync(SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT);
	sceDisplayWaitVblankStart();

	ResetAllPositioning();

	sceGuDisplay(SCEGU_DISPLAY_ON);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", pad_read);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", MainThread);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", D_000133D0);

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

void StartMainThread()
{
	SceUID main_thread = 0;

	main_thread = sceKernelCreateThread( "main", MainThread, SCE_KERNEL_USER_LOWEST_PRIORITY
		, 256*100, SCE_KERNEL_TH_USE_VFPU, NULL );

	if ( ((unsigned int)main_thread) == SCE_KERNEL_ERROR_NO_MEMORY )
	{
		printf( "no memory\n" );
	}
	else if ( ((unsigned int)main_thread) == SCE_KERNEL_ERROR_ILLEGAL_ATTR )
	{
		printf( "illegal attr\n" );
	}
	else if ( ((unsigned int)main_thread) == SCE_KERNEL_ERROR_ILLEGAL_STACK_SIZE )
	{
		printf( "illegal stack size\n" );
	}
	else if ( ((unsigned int)main_thread) == SCE_KERNEL_ERROR_ILLEGAL_CONTEXT )
	{
		printf( "illegal context\n" );
	}
	else if ( ((unsigned int)main_thread) == SCE_KERNEL_ERROR_ILLEGAL_PRIORITY )
	{
		printf( "illegal priority\n" );
	}
	else if ( ((unsigned int)main_thread) == SCE_KERNEL_ERROR_ILLEGAL_ENTRY )
	{
		printf( "illegal entry\n" );
	}
	else if ( ((unsigned int)main_thread) == SCE_KERNEL_ERROR_SPAD_INUSE )
	{
		printf( "spad inuse\n" );
	}
	else
	{
		int err = sceKernelStartThread( main_thread, 0, NULL );

		if ( ((unsigned int)err) == SCE_KERNEL_ERROR_UNKNOWN_THID )
		{
			printf( "unknown thid\n" );
		}
		else if ( ((unsigned int)err) == SCE_KERNEL_ERROR_ILLEGAL_THID )
		{
			printf( "illegal thid\n" );
		}
		else if ( ((unsigned int)err) == SCE_KERNEL_ERROR_ILLEGAL_CONTEXT )
		{
			printf( "illegal context\n" );
		}
		else if ( ((unsigned int)err) == SCE_KERNEL_ERROR_NOT_DORMANT )
		{
			printf( "not dormant\n" );
		}
		else
		{
			printf( "initial thread going to sleep, night night!\n" );

			sceKernelSleepThread();
		}
	}
}

int main(void) {
    StartMainThread();
    return 0;
}
