/* cflags: -O2 -std=gnu9x -fmerge-constants */
#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int size_t;
struct SceGmoModel;
typedef struct SceGmoModel SceGmoModel;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
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
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
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

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern int sce_newlib_heap_kb_size;
extern int DogSize;
extern int DogData;
extern char g_packet_buf[1048576];
extern ScePspFMatrix4 g_matrix_buf[16];
extern _Bool g_running;
extern ScePspFVector3 g_translate;
extern ScePspFVector3 g_rotate;
extern ScePspFVector3 g_scale;
extern SceGmoModel *g_model;
extern SceGmoModel *g_copies[3];

int main(int argc, char **argv);
static void begin_scene(void);
static void end_scene(void);
static void move_objects(void);
static void draw_objects(void);
static _Bool load_objects(int argc, char **argv);
static void unload_objects(void);
static _Bool load_file(const char *filename, int **buf, int *size);


/* SDK prototypes (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
int sceCtrlSetSamplingMode(int mode);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColorMaterial(int components);
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
void sceGuInit(void);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuLightColor(int light, int component, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuPatchDivide(unsigned int ulevel, unsigned int vlevel);
void sceGuScissor(int x, int y, int w, int h);
void sceGuShadeModel(int mode);
void sceGuStart(int type, void *list, int size);
void sceGuTerm(void);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumLoadIdentity(void);
void sceGumLookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center, const ScePspFVector3 *up);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumScale(const ScePspFVector3 *v);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumStoreMatrix(ScePspFMatrix4 *m);
void sceGumTranslate(const ScePspFVector3 *v);

void *malloc16(unsigned int size) {
    return memalign(0x10, size);
}

void free16(void *addr) {
    free();
}

void free(void *p);
void sceGmoModelSetMemoryManager(void *(*alloc)(unsigned int), void (*dealloc)(void *));
void sceGmoModelSetMemoryManager2(void *(*alloc)(unsigned int), void (*dealloc)(void *));
void swap_buffers(void);
void *malloc(unsigned int size);
void sceGimPictureSetMemoryManager(void *(*alloc)(unsigned int), void (*dealloc)(void *));
void sceGimPictureSetMemoryManager2(void *(*alloc)(unsigned int), void (*dealloc)(void *));
int main(int argc, char **argv)
{
	menuInit();
	sceCtrlSetSamplingMode(1);

	sceGuInit();
	sceGuStart(0, g_packet_buf, sizeof(g_packet_buf));
	sceGuDrawBuffer(1, (void *)0, 512);
	sceGuDispBuffer(480, 272, (void *)0x44000, 512);
	sceGuDepthBuffer((void *)0x88000, 512);
	sceGuOffset(2048 - 480 / 2, 2048 - 272 / 2);
	sceGuFinish();
	sceGuSync(0, 0);
	sceGumSetMatrixStack(g_matrix_buf, 4, 4, 8, 0);

	sceGimPictureSetMemoryManager(malloc, free);
	sceGimPictureSetMemoryManager2(malloc16, free16);
	sceGmoModelSetMemoryManager(malloc, free);
	sceGmoModelSetMemoryManager2(malloc, free);

	if (!load_objects(argc, argv))
		g_running = 0;
	sceGuDisplay(1);

	while (g_running) {
		sceGuStart(0, g_packet_buf, sizeof(g_packet_buf));
		begin_scene();
		move_objects();
		draw_objects();
		end_scene();
		sceGuFinish();
		swap_buffers();
	}

	unload_objects();

	sceGuTerm();
	menuTerm(1, 0x10);
	return 0;
}














#ifndef SCEGU_SCISSOR_TEST /* sample */
#define SCEGU_SCISSOR_TEST                 2
#endif
#ifndef SCEGU_CLEAR_ALL /* sample */
#define SCEGU_CLEAR_ALL               0x0007
#endif
#ifndef SCEGU_MATRIX_VIEW /* sample */
#define SCEGU_MATRIX_VIEW                  1
#endif
#ifndef SCEGU_MATRIX_PROJECTION /* sample */
#define SCEGU_MATRIX_PROJECTION            0
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
#ifndef SCEGU_MATRIX_WORLD /* sample */
#define SCEGU_MATRIX_WORLD                 2
#endif
#ifndef SCEGU_FOG /* sample */
#define SCEGU_FOG                          7
#endif
#ifndef SCEGU_LIGHTING /* sample */
#define SCEGU_LIGHTING                    10
#endif
#ifndef SCEGU_LIGHT0 /* sample */
#define SCEGU_LIGHT0                      11
#endif
#ifndef SCEGU_DIFFUSE_AND_SPECULAR /* sample */
#define SCEGU_DIFFUSE_AND_SPECULAR         6
#endif
#ifndef SCEGU_SPECULAR /* sample */
#define SCEGU_SPECULAR                     4
#endif
#ifndef SCEGU_LIGHT_DIRECTION /* sample */
#define SCEGU_LIGHT_DIRECTION              0
#endif
#ifndef SCEGU_DIFFUSE /* sample */
#define SCEGU_DIFFUSE                      2
#endif
#ifndef SCEGU_AMBIENT /* sample */
#define SCEGU_AMBIENT                      1
#endif
#ifndef SCEGU_ALPHA_TEST /* sample */
#define SCEGU_ALPHA_TEST                   0
#endif
#ifndef SCEGU_DEPTH_TEST /* sample */
#define SCEGU_DEPTH_TEST                   1
#endif
#ifndef SCEGU_BLEND /* sample */
#define SCEGU_BLEND                        4
#endif
#ifndef SCEGU_DITHER /* sample */
#define SCEGU_DITHER                       6
#endif
#ifndef SCEGU_TEXTURE /* sample */
#define SCEGU_TEXTURE                      9
#endif
#ifndef SCEGU_CULL_FACE /* sample */
#define SCEGU_CULL_FACE                    5
#endif
#ifndef SCEGU_CLIP_PLANE /* sample */
#define SCEGU_CLIP_PLANE                   8
#endif
#ifndef SCEGU_CULL_PATCH /* sample */
#define SCEGU_CULL_PATCH                  16
#endif
#ifndef SCEGU_NORMAL_REVERSE_PATCH /* sample */
#define SCEGU_NORMAL_REVERSE_PATCH        20
#endif
#ifndef SCEGU_CCW /* sample */
#define SCEGU_CCW                          1
#endif
#ifndef SCEGU_SMOOTH /* sample */
#define SCEGU_SMOOTH                       1
#endif
#ifndef SCEGU_GEQUAL /* sample */
#define SCEGU_GEQUAL                       7
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
#ifndef SCEGU_LINEAR_MIPMAP_LINEAR /* sample */
#define SCEGU_LINEAR_MIPMAP_LINEAR         7
#endif
#ifndef SCEGU_LINEAR /* sample */
#define SCEGU_LINEAR                       1
#endif
#ifndef SCEGU_TEX_MODULATE /* sample */
#define SCEGU_TEX_MODULATE                 0
#endif
#ifndef SCEGU_RGBA /* sample */
#define SCEGU_RGBA                         1
#endif
#ifndef SCEGU_REPEAT /* sample */
#define SCEGU_REPEAT                       0
#endif
void begin_scene()
{
	

	sceGuViewport( 2048, 2048, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT ) ;
	sceGuDepthRange( 0xe000, 0x1000 ) ;
	sceGuEnable( SCEGU_SCISSOR_TEST ) ;
	sceGuScissor( 0, 0, SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT ) ;
	sceGuClearColor( 0xff800000 ) ;
	sceGuClearDepth( 0 ) ;
	sceGuClearStencil( 0 ) ;
	sceGuClear( SCEGU_CLEAR_ALL ) ;

	

	sceGumMatrixMode( SCEGU_MATRIX_VIEW ) ;
	sceGumLoadIdentity() ;
	sceGumLookAt( &(ScePspFVector3){ 0, 0, 50 }, &(ScePspFVector3){ 0, 0, 0 }, &(ScePspFVector3){ 0, 1, 0 } ) ;
	sceGumMatrixMode( SCEGU_MATRIX_PROJECTION ) ;
	sceGumLoadIdentity() ;
	sceGumPerspective( 30.0f * 3.14f / 180.0f, SCEGU_SCR_ASPECT, 10.0f, 1000000.0f ) ;
	sceGumMatrixMode( SCEGU_MATRIX_WORLD ) ;

	

	sceGuEnable( SCEGU_FOG ) ;
	sceGuFog( 40, 100, 0xff800000 ) ;
	sceGuEnable( SCEGU_LIGHTING ) ;
	sceGuAmbient( 0xff404040 ) ;
	sceGuEnable( SCEGU_LIGHT0 ) ;
	sceGuLight( 0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE_AND_SPECULAR, &(ScePspFVector3){ -5, 10, 5 } ) ;
	sceGuLightColor( 0, SCEGU_DIFFUSE, 0xffffffff ) ;
	sceGuLightColor( 0, SCEGU_SPECULAR, 0xffffffff ) ;
	sceGuLight( 2, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &(ScePspFVector3){ 1, 0, 0 } ) ;
	sceGuLight( 3, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE, &(ScePspFVector3){ 0, 1, 0 } ) ;
	sceGuColorMaterial( SCEGU_DIFFUSE | SCEGU_AMBIENT ) ;

	

	sceGuEnable( SCEGU_ALPHA_TEST ) ;
	sceGuEnable( SCEGU_DEPTH_TEST ) ;
	sceGuEnable( SCEGU_BLEND ) ;
	sceGuEnable( SCEGU_DITHER ) ;
	sceGuEnable( SCEGU_TEXTURE ) ;
	sceGuEnable( SCEGU_CULL_FACE ) ;
	sceGuEnable( SCEGU_CLIP_PLANE ) ;
	sceGuEnable( SCEGU_CULL_PATCH ) ;
	sceGuEnable( SCEGU_NORMAL_REVERSE_PATCH ) ;
	sceGuFrontFace( SCEGU_CCW ) ;
	sceGuShadeModel( SCEGU_SMOOTH ) ;
	sceGuAlphaFunc( SCEGU_GEQUAL, 0, 255 ) ;
	sceGuDepthFunc( SCEGU_GEQUAL ) ;
	sceGuBlendFunc( SCEGU_ADD, SCEGU_SRC_ALPHA, SCEGU_ONE_MINUS_SRC_ALPHA, 0, 0 ) ;
	sceGuTexFilter( SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_LINEAR ) ;
	sceGuTexFunc( SCEGU_TEX_MODULATE, SCEGU_RGBA ) ;
	sceGuTexWrap( SCEGU_REPEAT, SCEGU_REPEAT ) ;
	sceGuPatchDivide( 4, 4 ) ;
}

#ifndef SCEGMO_ENABLE_LIGHTING /* sample */
#define SCEGMO_ENABLE_LIGHTING (0x0001)
#endif
#ifndef SCEGMO_ENABLE_FOG /* sample */
#define SCEGMO_ENABLE_FOG (0x0002)
#endif
#ifndef SCEGMO_ENABLE_TEXTURE /* sample */
#define SCEGMO_ENABLE_TEXTURE (0x0004)
#endif
void end_scene()
{
	SceGmoModel *model = g_copies[ 0 ] ;
	char buf[ 64 ] ;
	sprintf( buf, "MOTION  %d", sceGmoModelGetCurrentMotion( model ) ) ;
	sceGuDebugPrint( 10, 10, 0xffffffff, buf ) ;
	int bits = sceGmoModelGetEnableBits( model ) ;
	sprintf( buf, "LITING  %s", ( SCEGMO_ENABLE_LIGHTING & bits ) ? "ON" : "OFF" ) ;
	sceGuDebugPrint( 10, 20, 0xffffffff, buf ) ;
	sprintf( buf, "FOG     %s", ( SCEGMO_ENABLE_FOG & bits ) ? "ON" : "OFF" ) ;
	sceGuDebugPrint( 10, 30, 0xffffffff, buf ) ;
	sprintf( buf, "TEXTURE %s", ( SCEGMO_ENABLE_TEXTURE & bits ) ? "ON" : "OFF" ) ;
	sceGuDebugPrint( 10, 40, 0xffffffff, buf ) ;
}

void swap_buffers(void) {
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}

void sceGmoModelSetWorldMatrix(SceGmoModel *model, const ScePspFMatrix4 *m);
void sceGmoModelAnimate(SceGmoModel *model, float step);
void sceGmoModelUpdate(SceGmoModel *model);
void sceGmoModelDraw(SceGmoModel *model);
void sceGmoModelSetCurrentMotion(SceGmoModel *model, int index, float delay);
int sceGmoModelGetCurrentMotion(SceGmoModel *model);
void sceGmoModelSetEnableBits(SceGmoModel *model, int bits, int value);
int sceGmoModelGetEnableBits(SceGmoModel *model);
void sceGmoModelSetEnableMask(SceGmoModel *model, int mask, int value);
SceGmoModel *sceGmoModelCreate(void *chunk);
void sceGmoModelDelete(SceGmoModel *model);
SceGmoModel *sceGmoModelDuplicate(SceGmoModel *model, int flags);
#ifndef SCE_CTRL_SELECT /* sample */
#define SCE_CTRL_SELECT				(1<<0)
#endif
#ifndef SCE_CTRL_START /* sample */
#define SCE_CTRL_START				(1<<3)
#endif
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
#ifndef SCE_CTRL_CIRCLE /* sample */
#define SCE_CTRL_CIRCLE				(1<<13)
#endif
#ifndef SCE_CTRL_TRIANGLE /* sample */
#define SCE_CTRL_TRIANGLE			(1<<12)
#endif
#ifndef SCEGMO_ENABLE_LIGHTING /* sample */
#define SCEGMO_ENABLE_LIGHTING (0x0001)
#endif
#ifndef SCE_CTRL_SQUARE /* sample */
#define SCE_CTRL_SQUARE				(1<<15)
#endif
#ifndef SCEGMO_ENABLE_FOG /* sample */
#define SCEGMO_ENABLE_FOG (0x0002)
#endif
#ifndef SCE_CTRL_CROSS /* sample */
#define SCE_CTRL_CROSS				(1<<14)
#endif
#ifndef SCEGMO_ENABLE_TEXTURE /* sample */
#define SCEGMO_ENABLE_TEXTURE (0x0004)
#endif
void move_objects()
{
	const float move = 0.5f ;
	const float turn = 2.0f * 3.14f / 180.0f ;

	SceCtrlData buf ;
	sceCtrlReadBufferPositive( &buf, 1 ) ;

	extern int D_00034A44;
	int state = buf.Buttons ;
	int press = state & ~D_00034A44 ;
	D_00034A44 = state ;

	if ( press & SCE_CTRL_SELECT ) {
		g_running = 0 ;
		return ;
	}
	if ( press & SCE_CTRL_START ) {
		g_translate = (ScePspFVector3){ 0, 0, 0 } ;
		g_rotate = (ScePspFVector3){ 0, 0, 0 } ;
	}
	if ( state & SCE_CTRL_UP ) g_rotate.x -= turn ;
	if ( state & SCE_CTRL_DOWN ) g_rotate.x += turn ;
	if ( state & SCE_CTRL_LEFT ) g_rotate.y -= turn ;
	if ( state & SCE_CTRL_RIGHT ) g_rotate.y += turn ;
	if ( state & SCE_CTRL_L1 ) g_translate.z -= move ;
	if ( state & SCE_CTRL_R1 ) g_translate.z += move ;
	float dx = ( buf.Lx - 128 ) / 128.0f ;
	float dy = ( buf.Ly - 128 ) / 128.0f ;
	if ( dx > -0.75f && dx < 0.75f ) dx = 0.0f ;
	if ( dy > -0.75f && dy < 0.75f ) dy = 0.0f ;
	g_translate.x += move * dx ;
	g_translate.y -= move * dy ;

	if ( press & SCE_CTRL_CIRCLE ) {
		SceGmoModel *model = g_copies[ 0 ] ;
		int motion = sceGmoModelGetCurrentMotion( model ) ;
		motion = ( motion + 1 ) % 2 ;
		sceGmoModelSetCurrentMotion( model, motion, 0.1f ) ;
	}
	if ( press & SCE_CTRL_TRIANGLE ) {
		SceGmoModel *model = g_copies[ 0 ] ;
		int bits = sceGmoModelGetEnableBits( model ) ;
		sceGmoModelSetEnableBits( model, SCEGMO_ENABLE_LIGHTING, ~bits ) ;
	}
	if ( press & SCE_CTRL_SQUARE ) {
		SceGmoModel *model = g_copies[ 0 ] ;
		int bits = sceGmoModelGetEnableBits( model ) ;
		sceGmoModelSetEnableBits( model, SCEGMO_ENABLE_FOG, ~bits ) ;
	}
	if ( press & SCE_CTRL_CROSS ) {
		SceGmoModel *model = g_copies[ 0 ] ;
		int bits = sceGmoModelGetEnableBits( model ) ;
		sceGmoModelSetEnableMask( model, SCEGMO_ENABLE_TEXTURE, bits ) ;
		sceGmoModelSetEnableBits( model, SCEGMO_ENABLE_TEXTURE, ~bits ) ;
	}
}

void sceGmoModelSetWorldMatrix(SceGmoModel *model, const ScePspFMatrix4 *m);
void sceGmoModelAnimate(SceGmoModel *model, float step);
void sceGmoModelUpdate(SceGmoModel *model);
void sceGmoModelDraw(SceGmoModel *model);
#ifndef SCEGU_MATRIX_WORLD /* sample */
#define SCEGU_MATRIX_WORLD                 2
#endif
#ifndef N_COPIES /* sample */
#define N_COPIES 3
#endif
void draw_objects()
{
	sceGumMatrixMode( SCEGU_MATRIX_WORLD ) ;
	sceGumLoadIdentity() ;
	sceGumTranslate( &g_translate ) ;
	sceGumRotateY( g_rotate.y ) ;
	sceGumRotateX( g_rotate.x ) ;

	

	ScePspFMatrix4 m ;
	for ( int i = 0 ; i < N_COPIES ; i ++ ) {
		sceGumPushMatrix() ;
		ScePspFVector3 move = { ( i * 2 + 1 - N_COPIES ) * 5, 0, 0 } ;
		sceGumTranslate( &move ) ;
		sceGumScale( &g_scale ) ;
		sceGumStoreMatrix( &m ) ;

		SceGmoModel *model = g_copies[ i ] ;
		sceGmoModelSetWorldMatrix( model, &m ) ;
		sceGmoModelAnimate( model, 1.0f / 60.0f ) ;
		sceGmoModelUpdate( model ) ;
		sceGmoModelDraw( model ) ;

		sceGumPopMatrix() ;
	}
}

void sceGmoModelSetWorldMatrix(SceGmoModel *model, const ScePspFMatrix4 *m);
void sceGmoModelAnimate(SceGmoModel *model, float step);
void sceGmoModelUpdate(SceGmoModel *model);
void sceGmoModelDraw(SceGmoModel *model);
void sceGmoModelSetCurrentMotion(SceGmoModel *model, int index, float delay);
int sceGmoModelGetCurrentMotion(SceGmoModel *model);
void sceGmoModelSetEnableBits(SceGmoModel *model, int bits, int value);
int sceGmoModelGetEnableBits(SceGmoModel *model);
void sceGmoModelSetEnableMask(SceGmoModel *model, int mask, int value);
SceGmoModel *sceGmoModelCreate(void *chunk);
void sceGmoModelDelete(SceGmoModel *model);
SceGmoModel *sceGmoModelDuplicate(SceGmoModel *model, int flags);
_Bool sceGmoModelLoadFile(SceGmoModel *model, const void *buf, int size, int index);
const ScePspFVector3 *sceGmoModelGetBoundingBox(SceGmoModel *model);
static _Bool load_objects( int argc, char **argv )
{
	const char *filename = ( argc < 2 ) ? "dog.gmo" : argv[ 1 ] ;

	int *data, size ;
	if ( !load_file( filename, &data, &size ) ) {
		data = (int *)&DogData ;
		size = DogSize ;
	}

	//  create models

	g_model = sceGmoModelCreate( 0 ) ;
	sceGmoModelLoadFile( g_model, data, size, 0 ) ;

	for ( int i = 0 ; i < 3 ; i ++ ) {
		g_copies[ i ] = sceGmoModelDuplicate( g_model, 0x0002 ) ;
		sceGmoModelSetCurrentMotion( g_copies[ i ], i % 2, 0.0f ) ;
	}

	//  init position

	g_translate = (ScePspFVector3){ 0, 0, 0 } ;
	g_rotate = (ScePspFVector3){ 0, 0, 0 } ;
	g_scale = (ScePspFVector3){ 1, 1, 1 } ;

	const ScePspFVector3 *box = sceGmoModelGetBoundingBox( g_model ) ;
	if ( box != 0 ) {
		float s = box[ 1 ].x - box[ 0 ].x ;
		float s2 = box[ 1 ].y - box[ 0 ].y ;
		if ( s2 > s ) s = s2 ;
		s2 = box[ 1 ].z - box[ 0 ].z ;
		if ( s2 > s ) s = s2 ;
		if ( s > 0.0f ) {
			s = 10.0f / s ;
			g_scale = (ScePspFVector3){ s, s, s } ;
		}
	}

	if ( data != (int *)&DogData ) free( data ) ;
	return ( g_model != 0 ) ;
}

static void unload_objects(void)
{
	{
		int i;

		for (i = 0; i < 3; i++) {
			sceGmoModelDelete(g_copies[i]);
			g_copies[i] = 0;
		}
	}

	sceGmoModelDelete(g_model);
	g_model = 0;
}

int sprintf(char *buf, const char *fmt, ...);
int sceIoOpen(const char *file, int flags, int mode);
long long sceIoLseek(int fd, long long offset, int whence);
int sceIoRead(int fd, void *data, unsigned int size);
int sceIoClose(int fd);
void *malloc(unsigned int size);

static _Bool load_file(const char *filename, int **buf, int *size)
{
	char fullpath[256];

	sprintf(fullpath, "host0:%s", filename);

	SceUID fd = sceIoOpen(fullpath, 1, 0777);
	if (fd < 0) {
		return 0;
	}

	*size = sceIoLseek(fd, 0, 2);
	if (*size <= 0) {
		sceIoClose(fd);
		return 0;
	}

	sceIoLseek(fd, 0, 0);
	*buf = malloc(*size);
	sceIoRead(fd, *buf, *size);
	sceIoClose(fd);

	return 1;
}
