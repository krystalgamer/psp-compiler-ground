#include "common.h"
#include <psptypes.h>
#include <libgu.h>
#include <libgum.h>
#include <kerneltypes.h>

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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", PositioningMultMatrix);

static void PositioningStoreMatrix( Positioning* _Positioning
	, ScePspMatrix4* _Mat )
{
	sceGumPushMatrix();
	sceGumLoadIdentity();

	PositioningMultMatrix( _Positioning );

	sceGumStoreMatrix( &_Mat->fm );
	sceGumPopMatrix();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", draw_dragon_with_camera_transform);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", pad_read);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", MainThread);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", D_000133D0);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", StartMainThread);

int main(void) {
    StartMainThread();
    return 0;
}
