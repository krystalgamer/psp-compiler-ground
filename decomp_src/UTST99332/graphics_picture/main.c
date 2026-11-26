/* cflags: -O2 -std=gnu9x -fmerge-constants */
#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int size_t;
struct SceGimPicture;
typedef struct SceGimPicture SceGimPicture;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon1;
struct _anon1 { /* size 0x30 */
    short unsigned int header_size;
    short unsigned int reference;
    short unsigned int format;
    short unsigned int order;
    short unsigned int width;
    short unsigned int height;
    short unsigned int bpp;
    short unsigned int pitch_align;
    short unsigned int height_align;
    short unsigned int dim_count;
    short unsigned int reserved;
    short unsigned int reserved2;
    unsigned int offsets;
    unsigned int images;
    unsigned int total;
    unsigned int plane_mask;
    short unsigned int level_type;
    short unsigned int level_count;
    short unsigned int frame_type;
    short unsigned int frame_count;
};
typedef struct _anon1 SceGimImageHeader;
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
extern int g_vformat;
extern float g_vbuffer[32];
extern _Bool g_running;
extern ScePspFVector3 g_translate;
extern ScePspFVector3 g_rotate;
extern ScePspFVector3 g_scale;
extern SceGimPicture *g_picture;
extern SceGimPicture *g_copies[3];

int main(int argc, char **argv);
static void begin_scene(void);
static void end_scene(void);
static void move_objects(void);
static void draw_objects(void);
static _Bool load_objects(int argc, char **argv);
static void unload_objects(void);
static _Bool load_file(const char *filename, int **buf, int *size);

/* SDK functions (tools/sdk_protos.h) */
int sceGuSync(int mode, int what);
void *sceGuSwapBuffers(void);
int sceDisplayWaitVblankStart(void);
void *memalign(unsigned int align, unsigned int size);
void free(void *p);


/* SDK prototypes (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
int sceCtrlSetSamplingMode(int mode);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
void sceGuDepthBuffer(void *zbp, int frame_width);
void sceGuDepthRange(int near, int far);
void sceGuDisable(int state);
void sceGuDispBuffer(int width, int height, void *dbp, int frame_width);
int sceGuDisplay(int state);
void sceGuDrawBuffer(int psm, void *fbp, int frame_width);
void sceGuEnable(int state);
int sceGuFinish(void);
void sceGuInit(void);
void sceGuMaterial(int mode, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuScissor(int x, int y, int w, int h);
void sceGuStart(int type, void *list, int size);
void sceGuTerm(void);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexLevelMode(unsigned int mode, float bias);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumLoadIdentity(void);
void sceGumLookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center, const ScePspFVector3 *up);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumScale(const ScePspFVector3 *v);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumTranslate(const ScePspFVector3 *v);

void *malloc16(unsigned int size) {
    return memalign(0x10U, size);
}

void free16(void *addr) {
    free(addr);
}

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
	menuTerm(1, 0x15);
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
#ifndef SCEGU_AMBIENT /* sample */
#define SCEGU_AMBIENT                      1
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
#ifndef SCEGU_CLIP_PLANE /* sample */
#define SCEGU_CLIP_PLANE                   8
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
#ifndef SCEGU_CLAMP /* sample */
#define SCEGU_CLAMP                        1
#endif
void begin_scene( void )
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
	sceGumPerspective( 60.0f * 3.14f / 180.0f, SCEGU_SCR_ASPECT, 1.0f, 1000000.0f ) ;
	sceGumMatrixMode( SCEGU_MATRIX_WORLD ) ;

	

	sceGuDisable( SCEGU_FOG ) ;
	sceGuDisable( SCEGU_LIGHTING ) ;
	sceGuAmbient( 0xff404040 ) ;
	sceGuMaterial( SCEGU_AMBIENT, 0xffffffff ) ;

	

	sceGuEnable( SCEGU_BLEND ) ;
	sceGuEnable( SCEGU_DITHER ) ;
	sceGuEnable( SCEGU_TEXTURE ) ;
	sceGuEnable( SCEGU_CLIP_PLANE ) ;
	sceGuBlendFunc( SCEGU_ADD, SCEGU_SRC_ALPHA, SCEGU_ONE_MINUS_SRC_ALPHA, 0, 0 ) ;
	sceGuTexFilter( SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_LINEAR ) ;
	sceGuTexFunc( SCEGU_TEX_MODULATE, SCEGU_RGBA ) ;
	sceGuTexWrap( SCEGU_CLAMP, SCEGU_CLAMP ) ;
}

#ifndef SCEGIM_ENABLE_DISSOLVE /* sample */
#define SCEGIM_ENABLE_DISSOLVE (0x0001)
#endif
void end_scene()
{
	SceGimPicture *picture = g_copies[ 0 ] ;
	char buf[ 64 ] ;
	int bits = sceGimPictureGetEnableBits( picture ) ;
	sprintf( buf, "DISSOLVE %s", ( SCEGIM_ENABLE_DISSOLVE & bits ) ? "ON" : "OFF" ) ;
	sceGuDebugPrint( 10, 10, 0xffffffff, buf ) ;
}

void swap_buffers(void) {
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}

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
#ifndef SCEGIM_ENABLE_DISSOLVE /* sample */
#define SCEGIM_ENABLE_DISSOLVE (0x0001)
#endif
void move_objects( void )
{
	const float move = 0.5f ;
	const float turn = 2.0f * 3.14f / 180.0f ;

	SceCtrlData buf ;
	sceCtrlReadBufferPositive( &buf, 1 ) ;

	extern int D_0002AC04;
	int state = buf.Buttons ;
	int press = state & ~D_0002AC04 ;
	D_0002AC04 = state ;

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
		SceGimPicture *picture = g_copies[ 0 ] ;
		int bits = sceGimPictureGetEnableBits( picture ) ;
		sceGimPictureSetEnableBits( picture, SCEGIM_ENABLE_DISSOLVE, ~bits ) ;
	}
}

void sceGimPictureAnimate(SceGimPicture *picture, float step);
void sceGimPictureActivate(SceGimPicture *picture);
int sceGimPictureGetEnableBits(SceGimPicture *picture);
float sceGimPictureGetDissolve(SceGimPicture *picture);
const float *sceGimPictureGetImageCrop(SceGimPicture *picture);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
#ifndef SCEGU_MATRIX_WORLD /* sample */
#define SCEGU_MATRIX_WORLD                 2
#endif
#ifndef N_COPIES /* sample */
#define N_COPIES 3
#endif
#ifndef SCEGIM_ENABLE_DISSOLVE /* sample */
#define SCEGIM_ENABLE_DISSOLVE (0x0001)
#endif
#ifndef SCEGU_LOD_CONSTANT /* sample */
#define SCEGU_LOD_CONSTANT                 1
#endif
#ifndef SCEGU_PRIM_TRIANGLE_STRIP /* sample */
#define SCEGU_PRIM_TRIANGLE_STRIP          4
#endif
#ifndef ENABLE_CROPPING /* sample */
#define ENABLE_CROPPING 1
#endif
#ifndef ENABLE_DISSOLVE /* sample */
#define ENABLE_DISSOLVE 1
#endif
#ifndef SCEGU_LOD_AUTO /* sample */
#define SCEGU_LOD_AUTO                     0
#endif
void draw_objects( void )
{
	sceGumMatrixMode( SCEGU_MATRIX_WORLD ) ;
	sceGumLoadIdentity() ;
	sceGumTranslate( &g_translate ) ;
	sceGumRotateY( g_rotate.y ) ;
	sceGumRotateX( g_rotate.x ) ;
	sceGumRotateZ( g_rotate.z ) ;
	sceGumScale( &g_scale ) ;

	

	for ( int i = 0 ; i < N_COPIES ; i ++ ) {
		sceGumPushMatrix() ;
		ScePspFVector3 move = { ( i * 2 + 1 - N_COPIES ) * 0.5f, 0, 0 } ;
		sceGumTranslate( &move ) ;

		SceGimPicture *picture = g_copies[ i ] ;
		sceGimPictureAnimate( picture, 1.0f / 60.0f ) ;
		sceGimPictureActivate( picture ) ;
#if ( ENABLE_CROPPING )
		extern float D_00016224[];
		const float *crop = sceGimPictureGetImageCrop( picture ) ;
		if ( crop == 0 ) crop = D_00016224 ;
		sceGuTexOffset( crop[ 0 ], crop[ 1 ] ) ;
		sceGuTexScale( crop[ 2 ], crop[ 3 ] ) ;
#endif
#if ( ENABLE_DISSOLVE )
		int bits = sceGimPictureGetEnableBits( picture ) ;
		if ( bits & SCEGIM_ENABLE_DISSOLVE ) {
			float dissolve = sceGimPictureGetDissolve( picture ) ;
			sceGuTexLevelMode( SCEGU_LOD_CONSTANT, dissolve ) ;
		} else {
			sceGuTexLevelMode( SCEGU_LOD_AUTO, 0 ) ;
		}
#endif
		sceGumDrawArray( SCEGU_PRIM_TRIANGLE_STRIP, g_vformat, 4, 0, g_vbuffer ) ;

		sceGumPopMatrix() ;
	}

#if ( ENABLE_CROPPING )
	sceGuTexOffset( 0, 0 ) ;
	sceGuTexScale( 1, 1 ) ;
#endif
#if ( ENABLE_DISSOLVE )
	sceGuTexLevelMode( SCEGU_LOD_AUTO, 0.0f ) ;
#endif
}

SceGimPicture *sceGimPictureCreate(void *chunk);
_Bool sceGimPictureLoadFile(SceGimPicture *picture, const void *buf, int size, int index);
SceGimPicture *sceGimPictureDuplicate(SceGimPicture *picture, int flags);
void sceGimPictureSetFrameRate(SceGimPicture *picture, float fps);
SceGimImageHeader *sceGimPictureGetImage(SceGimPicture *picture);
static _Bool load_objects( int argc, char **argv )
{
	const char *filename = ( argc < 2 ) ? "dog.gim" : argv[ 1 ] ;

	int *data, size ;
	if ( !load_file( filename, &data, &size ) ) {
		data = (int *)&DogData ;
		size = DogSize ;
	}

	//  create pictures

	g_picture = sceGimPictureCreate( 0 ) ;
	sceGimPictureLoadFile( g_picture, data, size, 0 ) ;

	for ( int i = 0 ; i < 3 ; i ++ ) {
		g_copies[ i ] = sceGimPictureDuplicate( g_picture, 0x0002 ) ;

		extern float D_00016234[];
		sceGimPictureSetFrameRate( g_copies[ i ], D_00016234[ i % 3 ] ) ;
	}

	//  init position

	g_translate = (ScePspFVector3){ 0, 0, 0 } ;
	g_rotate = (ScePspFVector3){ 0, 0, 0 } ;
	g_scale = (ScePspFVector3){ 1, 1, 1 } ;

	SceGimImageHeader *image = sceGimPictureGetImage( g_picture ) ;
	if ( image != 0 ) {
		g_scale.x = image->width * ( 57.735f / 272 ) ;
		g_scale.y = image->height * ( 57.735f / 272 ) ;
	}

	if ( data != (int *)&DogData ) free( data ) ;
	return ( g_picture != 0 ) ;
}

static void unload_objects(void)
{
	{
		int i;

		for (i = 0; i < 3; i++) {
			sceGimPictureDelete(g_copies[i]);
			g_copies[i] = 0;
		}
	}

	sceGimPictureDelete(g_picture);
	g_picture = 0;
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
