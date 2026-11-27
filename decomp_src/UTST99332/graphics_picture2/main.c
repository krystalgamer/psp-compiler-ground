/* cflags: -O2 -std=gnu9x -fmerge-constants */
#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int size_t;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
struct SceGimPicture;
typedef struct SceGimPicture SceGimPicture;
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
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern int sce_newlib_heap_kb_size;
extern char g_packet_buf[1048576];
extern ScePspFMatrix4 g_matrix_buf[16];
extern int g_vformat;
extern float g_vbuffer[48];
extern int g_frame_count;
extern int g_frame_format;
extern void *g_frame_buffer;
extern _Bool g_running;
extern _Bool g_reload;
extern _Bool g_disp_wire;
extern SceGimPicture *g_picture;
extern ScePspFVector3 g_translate;
extern ScePspFVector3 g_rotate;
extern ScePspFVector3 g_scale;
extern int g_vbl_count;
extern int g_vbl_step;
extern int g_vbl_time;
extern int g_cpu_load;
extern int g_gpu_load;
extern const char *const g_default_picture_names[12];
extern const char *const *g_picture_names;
extern int g_picture_count;
extern int g_picture_size;
extern int g_menu_select;
extern int g_menu_picture;
extern int g_menu_subdiv;
extern int g_menu_pixel;
extern int g_menu_frame;
extern int g_menu_filter;
extern float g_menu_level;
extern int g_menu_dissolve;
extern int g_menu_copy;
extern int g_menu_count;

int main(int argc, const char **argv);
static void begin_scene(void);
static void end_scene(void);
static void swap_buffers(void);
static void move_objects(void);
static void draw_objects(void);
static void draw_objects2(void);
static const void *sceGimImageGetPixels(const SceGimImageHeader *image, int level, int frame);
static int sceGimImageGetBPP(const SceGimImageHeader *image);
static int sceGimImageGetWidth(const SceGimImageHeader *image, int level);
static int sceGimImageGetHeight(const SceGimImageHeader *image, int level);
static int sceGimImageGetBufWidth(const SceGimImageHeader *image, int width);
static _Bool load_objects(void);
static _Bool load_file(const char *filename, int **buf, int *size);
static void draw_rect(int x, int y, int w, int h, int color);

/* SDK functions (tools/sdk_protos.h) */
void *memalign(unsigned int align, unsigned int size);
void free(void *p);


/* SDK prototypes (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
int sceCtrlSetSamplingMode(int mode);
int sceDisplayGetVcount(void);
int sceDisplayWaitVblankStart(void);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuCopyImage(int psm, int sx, int sy, int width, int height, int srcw, void *src, int dx, int dy, int destw, void *dest);
void sceGuDebugFlush(void);
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
void sceGuLogicalOp(int op);
void sceGuMaterial(int mode, unsigned int color);
void sceGuOffset(unsigned int x, unsigned int y);
void sceGuPatchDivide(unsigned int ulevel, unsigned int vlevel);
void sceGuPatchPrim(int prim);
void sceGuScissor(int x, int y, int w, int h);
void sceGuStart(int type, void *list, int size);
int sceGuSync(int mode, int what);
void sceGuTerm(void);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexLevelMode(unsigned int mode, float bias);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGuTexWrap(int u, int v);
void sceGuViewport(int cx, int cy, int width, int height);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGumLoadIdentity(void);
void sceGumLookAt(const ScePspFVector3 *eye, const ScePspFVector3 *center, const ScePspFVector3 *up);
void sceGumMatrixMode(int mode);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumScale(const ScePspFVector3 *v);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumTranslate(const ScePspFVector3 *v);
unsigned int sceKernelGetSystemTimeLow(void);

void *malloc16(unsigned int size) {
    return memalign(0x10U, size);
}

void free16(void *addr) {
    free(addr);
}


void menuInit(void);
void menuTerm(int a, int b);
void myHeapInit(void *addr, unsigned int size);
void myHeapTerm(void);
void *myHeapAlloc16(unsigned int size);
void myHeapFree16(void *addr);
void *malloc(unsigned int size);
int sprintf(char *buf, const char *fmt, ...);
void sceCtrlSetSamplingCycle(int cycle);
void *sceGeEdramGetAddr(void);
unsigned int sceGeEdramGetSize(void);
void sceGumRotateX(float angle);
void sceGimPictureSetMemoryManager(void *(*alloc_func)(size_t), void (*free_func)(void *));
void sceGimPictureSetMemoryManager2(void *(*alloc_func)(size_t), void (*free_func)(void *));
SceGimPicture *sceGimPictureCreate(void *chunk);
_Bool sceGimPictureLoadFile(SceGimPicture *picture, const void *buf, int size, int index);
void sceGimPictureDelete(SceGimPicture *picture);
void sceGimPictureAnimate(SceGimPicture *picture, float step);
void sceGimPictureActivate(SceGimPicture *picture);
void sceGimPictureSetEnableBits(SceGimPicture *picture, int bits, int value);
int sceGimPictureGetEnableBits(SceGimPicture *picture);
SceGimImageHeader *sceGimPictureGetImage(SceGimPicture *picture);
void sceGimPictureSetFrameRate(SceGimPicture *picture, float fps);
int sceGimPictureGetImageFrame(SceGimPicture *picture);
float sceGimPictureGetDissolve(SceGimPicture *picture);
const float *sceGimPictureGetImageCrop(SceGimPicture *picture);
void unload_objects(void);
void *malloc16(unsigned int size);
void free16(void *addr);

const char *const g_default_picture_names[12] = {
	"dog32_norm.gim",
	"dog32_fast.gim",
	"dog16_norm.gim",
	"dog16_fast.gim",
	"dog8_norm.gim",
	"dog8_fast.gim",
	"dog4_norm.gim",
	"dog4_fast.gim",
	"dog_dxt1.gim",
	"dog_dxt3.gim",
	"dog_dxt5.gim",
	"dog8_anim.gim",
};

int main( int argc, const char **argv )
{
	menuInit() ;
	sceCtrlSetSamplingMode( 1 ) ;

	sceGuInit() ;
	sceGuStart( 0, g_packet_buf, 0x100000 ) ;
	sceGuDrawBuffer( 3, (void *)0, 512 ) ;
	sceGuDispBuffer( 480, 272, (void *)0x88000, 512 ) ;
	sceGuDepthBuffer( (void *)0x110000, 512 ) ;
	sceGuOffset( 2048 - 240, 2048 - 136 ) ;
	sceGuFinish() ;
	sceGuSync( 0, 0 ) ;
	sceGumSetMatrixStack( g_matrix_buf, 4, 4, 8, 0 ) ;

	sceGimPictureSetMemoryManager( malloc, free ) ;
	sceGimPictureSetMemoryManager2( malloc16, free16 ) ;

	if ( argc > 1 ) {
		g_picture_count = argc - 1 ;
		g_picture_names = argv + 1 ;
	}

	sceGuDisplay( 1 ) ;

	while ( g_running ) {
		if ( g_reload ) {
			if ( !load_objects() ) break ;
			g_vbl_count = -1 ;
		}
		sceGuStart( 0, g_packet_buf, 0x100000 ) ;
		begin_scene() ;
		move_objects() ;
		if ( g_menu_copy == 0 ) {
			draw_objects() ;
		} else {
			draw_objects2() ;
		}
		end_scene() ;
		sceGuFinish() ;
		swap_buffers() ;
	}
	unload_objects() ;

	myHeapTerm() ;
	sceGuTerm() ;
	menuTerm( 1, 22 ) ;
	return 0 ;
}

void begin_scene()
{
	g_frame_format = ( g_menu_frame == 0 ) ? 3 : 1 ;
	g_frame_buffer = ( g_frame_count % 2 == 0 ) ? (void *)0 : (void *)0x88000 ;
	sceGuDrawBuffer( g_frame_format, g_frame_buffer, 512 ) ;
	sceGuDepthBuffer( (void *)0x110000, 512 ) ;
	sceGuOffset( 2048 - 240, 2048 - 136 ) ;
	sceGuViewport( 2048, 2048, 480, 272 ) ;
	sceGuDepthRange( 0xe000, 0x1000 ) ;
	sceGuEnable( 2 ) ;
	sceGuScissor( 0, 0, 480, 272 ) ;
	sceGuClearColor( 0xff800000 ) ;
	sceGuClearDepth( 0 ) ;
	sceGuClearStencil( 0 ) ;
	sceGuClear( 7 ) ;

	sceGumMatrixMode( 1 ) ;
	sceGumLoadIdentity() ;
	sceGumLookAt( &(ScePspFVector3){ 0, 0, 50 }, &(ScePspFVector3){ 0, 0, 0 }, &(ScePspFVector3){ 0, 1, 0 } ) ;
	sceGumMatrixMode( 0 ) ;
	sceGumLoadIdentity() ;
	sceGumPerspective( 60.0f * 3.14f / 180.0f, 480.0f / 272.0f, 10.0f, 1000000.0f ) ;
	sceGumMatrixMode( 2 ) ;

	sceGuDisable( 7 ) ;
	sceGuDisable( 10 ) ;
	sceGuAmbient( 0xff404040 ) ;
	sceGuMaterial( 1, 0xffffffff ) ;

	sceGuEnable( 4 ) ;
	sceGuEnable( 6 ) ;
	sceGuEnable( 9 ) ;
	sceGuEnable( 8 ) ;
	sceGuBlendFunc( 0, 2, 3, 0, 0 ) ;
	sceGuTexFunc( 0, 1 ) ;
	sceGuTexWrap( 1, 1 ) ;
	switch ( g_menu_filter ) {
	    case 0 :
		sceGuTexFilter( 7, 1 ) ;
		break ;
	    case 1 :
		sceGuTexFilter( 5, 1 ) ;
		break ;
	    case 2 :
		sceGuTexFilter( 4, 0 ) ;
		break ;
	}
	sceGuPatchDivide( g_menu_subdiv, g_menu_subdiv ) ;
}

void end_scene()
{
	static const char *const PixelModes[] = { "DDR", "EDRAM" } ;
	static const char *const FrameModes[] = { "32BPP", "16BPP" } ;
	static const char *const FilterModes[] = { "TRILINEAR", "BILINEAR", "POINT" } ;
	static const char *const DissolveModes[] = { "OFF", "ON" } ;
	static const char *const CopyModes[] = { "OFF", "ON" } ;
	char buf[ 64 ] ;
	if ( g_frame_count * g_vbl_step % 30 < 15 ) {
		sceGuDebugPrint( 0, g_menu_select * 10 + 10, 0xffffffff, ">" ) ;
	}
	sprintf( buf, "PICTURE  %s %dKB", g_picture_names[ g_menu_picture ], ( g_picture_size + 1023 ) / 1024 ) ;
	sceGuDebugPrint( 10, 10, 0xffffffff, buf ) ;
	sprintf( buf, "SUBDIV   %d", g_menu_subdiv ) ;
	sceGuDebugPrint( 10, 20, 0xffffffff, buf ) ;
	sprintf( buf, "PIXEL    %s", PixelModes[ g_menu_pixel ] ) ;
	sceGuDebugPrint( 10, 30, 0xffffffff, buf ) ;
	sprintf( buf, "FRAME    %s", FrameModes[ g_menu_frame ] ) ;
	sceGuDebugPrint( 10, 40, 0xffffffff, buf ) ;
	sprintf( buf, "FILTER   %s", FilterModes[ g_menu_filter ] ) ;
	sceGuDebugPrint( 10, 50, 0xffffffff, buf ) ;
	if ( g_menu_level < 0.0f ) {
		sprintf( buf, "LEVEL    AUTO" ) ;
	} else {
		sprintf( buf, "LEVEL    %.1f", g_menu_level ) ;
	}
	sceGuDebugPrint( 10, 60, 0xffffffff, buf ) ;
	sprintf( buf, "DISSOLVE %s", DissolveModes[ g_menu_dissolve ] ) ;
	sceGuDebugPrint( 10, 70, 0xffffffff, buf ) ;
	sprintf( buf, "COPY     %s", CopyModes[ g_menu_copy ] ) ;
	sceGuDebugPrint( 10, 80, 0xffffffff, buf ) ;
	sprintf( buf, "COUNT    %d", g_menu_count ) ;
	sceGuDebugPrint( 10, 90, 0xffffffff, buf ) ;
	sprintf( buf, "CPU %d%%", g_cpu_load ) ;
	sceGuDebugPrint( 10, 240, 0xffffffff, buf ) ;
	sprintf( buf, "GPU %d%%", g_gpu_load ) ;
	sceGuDebugPrint( 10, 250, 0xffffffff, buf ) ;
	if ( g_reload ) {
		sceGuDebugPrint( 400, 10, 0xffffffff, "LOADING" ) ;
	}

	sceGuDisable( 9 ) ;
	sceGuDisable( 1 ) ;
	draw_rect( 82, 241, g_cpu_load, 7, 0x8f00 ) ;
	draw_rect( 82, 251, g_gpu_load, 7, 0x800f ) ;
}

void swap_buffers()
{
	int cpu_time = sceKernelGetSystemTimeLow() ;
	sceGuSync( 0, 0 ) ;
	int gpu_time = sceKernelGetSystemTimeLow() ;
	sceGuDebugFlush() ;
	sceGuDispBuffer( 480, 272, g_frame_buffer, 512 ) ;
	sceDisplayWaitVblankStart() ;
	g_frame_count ++ ;

	int vbl_time = sceKernelGetSystemTimeLow() ;
	int vbl_count = sceDisplayGetVcount() ;
	if ( g_vbl_count >= 0 ) {
		g_vbl_step = vbl_count - g_vbl_count ;
		if ( g_frame_count % 6 == 0 ) {
			g_cpu_load = ( cpu_time - g_vbl_time ) * 100 / 16667 ;
			g_gpu_load = ( gpu_time - g_vbl_time ) * 100 / 16667 ;
		}
	}
	g_vbl_time = vbl_time ;
	g_vbl_count = vbl_count ;
}

void move_objects()
{
	float move = g_vbl_step * 0.5f ;
	float turn = g_vbl_step * ( 2.0f * 3.14f / 180.0f ) ;

	SceCtrlData buf ;
	sceCtrlReadBufferPositive( &buf, 1 ) ;

	extern int D_00017AFC ;
#define prev D_00017AFC
	int state = buf.Buttons ;
	int press = state & ~prev ;
	prev = state ;
#undef prev

	if ( press & 0x1 ) {
		g_running = 0 ;
		return ;
	}
	if ( press & 0x8 ) {
		g_translate = (ScePspFVector3){ 0, 0, 0 } ;
		g_rotate = (ScePspFVector3){ 0, 0, 0 } ;
		g_menu_picture = 0 ;
		g_menu_subdiv = 1 ;
		g_menu_pixel = 0 ;
		g_menu_frame = 0 ;
		g_menu_filter = 0 ;
		g_menu_level = -1.0f ;
		g_menu_dissolve = 0 ;
		g_menu_copy = 0 ;
		g_menu_count = 1 ;
		g_reload = 1 ;
		return ;
	}
	if ( state & 0x80 ) g_rotate.z += turn ;
	if ( state & 0x20 ) g_rotate.z -= turn ;
	if ( state & 0x100 ) g_translate.z -= move ;
	if ( state & 0x200 ) g_translate.z += move ;
	float dx = ( buf.Lx - 128 ) / 128.0f ;
	float dy = ( buf.Ly - 128 ) / 128.0f ;
	if ( dx > -0.75f && dx < 0.75f ) dx = 0.0f ;
	if ( dy > -0.75f && dy < 0.75f ) dy = 0.0f ;
	g_translate.x += move * dx ;
	g_translate.y -= move * dy ;

	if ( press & 0x10 ) {
		if ( g_menu_select > 0 ) g_menu_select -= 1 ;
	}
	if ( press & 0x40 ) {
		if ( g_menu_select < 8 ) g_menu_select += 1 ;
	}

	if ( !( state & ( 0x2000 | 0x4000 ) ) ) {
		g_disp_wire = 0 ;
	}

	switch ( g_menu_select ) {
	    case 0 : {
		if ( press & 0x2000 ) {
			if ( g_menu_picture < g_picture_count - 1 ) {
				g_menu_picture += 1 ;
				g_reload = 1 ;
			}
		}
		if ( press & 0x4000 ) {
			if ( g_menu_picture > 0 ) {
				g_menu_picture -= 1 ;
				g_reload = 1 ;
			}
		}
		break ;
	    }
	    case 1 : {
		if ( press & 0x2000 ) {
			if ( g_menu_subdiv < 64 ) g_menu_subdiv *= 2 ;
			g_disp_wire = 1 ;
		}
		if ( press & 0x4000 ) {
			if ( g_menu_subdiv > 1 ) g_menu_subdiv /= 2 ;
			g_disp_wire = 1 ;
		}
		break ;
	    }
	    case 2 : {
		if ( press & ( 0x2000 | 0x4000 ) ) {
			g_menu_pixel = !g_menu_pixel ;
			g_reload = 1 ;
		}
		break ;
	    }
	    case 3 : {
		if ( press & ( 0x2000 | 0x4000 ) ) {
			g_menu_frame = !g_menu_frame ;
		}
		break ;
	    }
	    case 4 : {
		if ( press & 0x2000 ) {
			if ( g_menu_filter < 2 ) g_menu_filter += 1 ;
		}
		if ( press & 0x4000 ) {
			if ( g_menu_filter > 0 ) g_menu_filter -= 1 ;
		}
		break ;
	    }
	    case 5 : {
		if ( state & 0x2000 ) {
			g_menu_level += 0.1f ;
			if ( g_menu_level > 7.0f ) g_menu_level = 7.0f ;
		}
		if ( state & 0x4000 ) {
			g_menu_level -= 0.1f ;
			if ( g_menu_level < -1.0f ) g_menu_level = -1.0f ;
		}
		break ;
	    }
	    case 6 : {
		if ( press & ( 0x2000 | 0x4000 ) ) {
			g_menu_dissolve = !g_menu_dissolve ;
			int bits = g_menu_dissolve ? -1 : 0 ;
			sceGimPictureSetEnableBits( g_picture, 1, bits ) ;
		}
		break ;
	    }
	    case 7 : {
		if ( press & ( 0x2000 | 0x4000 ) ) {
			g_menu_copy = !g_menu_copy ;
			g_translate.z = 0.0f ;
			g_rotate = (ScePspFVector3){ 0, 0, 0 } ;
		}
		break ;
	    }
	    case 8 : {
		if ( press & 0x2000 ) {
			if ( g_menu_count < 10 ) g_menu_count += 1 ;
		}
		if ( press & 0x4000 ) {
			if ( g_menu_count > 0 ) g_menu_count -= 1 ;
		}
		break ;
	    }
	}
}

void draw_objects()
{
	float step = g_vbl_step * ( 1.0f / 60.0f ) ;

	sceGumMatrixMode( 2 ) ;
	sceGumLoadIdentity() ;
	sceGumTranslate( &g_translate ) ;
	sceGumRotateY( g_rotate.y ) ;
	sceGumRotateX( g_rotate.x ) ;
	sceGumRotateZ( g_rotate.z ) ;
	sceGumScale( &g_scale ) ;

	for ( int i = 0 ; i < g_menu_count ; i ++ ) {
		SceGimPicture *picture = g_picture ;
		sceGimPictureAnimate( picture, step ) ;
		sceGimPictureActivate( picture ) ;
		extern float D_00017244[] ;
#define NoCrop D_00017244
		const float *crop = sceGimPictureGetImageCrop( picture ) ;
		if ( crop == 0 ) crop = NoCrop ;
#undef NoCrop
		sceGuTexOffset( crop[ 0 ], crop[ 1 ] ) ;
		sceGuTexScale( crop[ 2 ], crop[ 3 ] ) ;
		int bits = sceGimPictureGetEnableBits( picture ) ;
		if ( bits & 1 ) {
			float dissolve = sceGimPictureGetDissolve( picture ) ;
			sceGuTexLevelMode( 1, dissolve ) ;
		} else if ( g_menu_level > 0.0f ) {
			sceGuTexLevelMode( 1, g_menu_level ) ;
		} else {
			sceGuTexLevelMode( 0, 0.0f ) ;
		}
		sceGumDrawBezier( g_vformat, 4, 4, 0, g_vbuffer ) ;
		step = 0.0f ;
	}
	if ( g_disp_wire ) {
		sceGuPatchPrim( 2 ) ;
		sceGuDisable( 9 ) ;
		sceGuLogicalOp( 6 ) ;
		sceGumDrawBezier( g_vformat, 4, 4, 0, g_vbuffer ) ;
		sceGuPatchPrim( 4 ) ;
		sceGuEnable( 9 ) ;
	}
	sceGuTexOffset( 0.0f, 0.0f ) ;
	sceGuTexScale( 1.0f, 1.0f ) ;
	sceGuTexLevelMode( 0, 0.0f ) ;
}

static __inline__ int sceGimImageGetBPP( const SceGimImageHeader *image )
{
	return image->bpp ;
}

static __inline__ int sceGimImageGetWidth( const SceGimImageHeader *image, int level )
{
	int width = image->width ;
	if ( level > 0 && image->level_type == 2 ) {
		while ( -- level >= 0 ) width = ( width + 1 ) / 2 ;
	}
	return width ;
}

static __inline__ int sceGimImageGetHeight( const SceGimImageHeader *image, int level )
{
	int height = image->height ;
	if ( level > 0 && image->level_type == 2 ) {
		while ( -- level >= 0 ) height = ( height + 1 ) / 2 ;
	}
	return height ;
}

static __inline__ int sceGimImageGetBufWidth( const SceGimImageHeader *image, int width )
{
	int align = image->pitch_align * 8 / image->bpp - 1 ;
	return ( width + align ) & ~align ;
}

static __inline__ const void *sceGimImageGetPixels( const SceGimImageHeader *image, int level, int frame )
{
	int n_levels = image->level_count ;
	int n_frames = image->frame_count ;
	if ( level < 0 || level >= n_levels ) return 0 ;
	frame %= n_frames ;
	if ( 0x8000 & frame ) frame = 0x7fff & ( frame + n_frames ) ;
	void **offsets = (void **)( (char *)image + image->offsets ) ;
	return offsets[ n_levels * frame + level ] ;
}

void draw_objects2()
{
	float step = g_vbl_step * ( 1.0f / 60.0f ) ;

	for ( int i = 0 ; i < g_menu_count ; i ++ ) {
		SceGimPicture *picture = g_picture ;
		sceGimPictureAnimate( picture, step ) ;
		step = 0.0f ;
		SceGimImageHeader *image = sceGimPictureGetImage( picture ) ;
		if ( image == 0 ) continue ;
		int frame = sceGimPictureGetImageFrame( picture ) ;
		const void *pixels = sceGimImageGetPixels( image, 0, frame ) ;
		if ( pixels == 0 ) continue ;

		int sbpp = sceGimImageGetBPP( image ) ;
		int dbpp = ( g_frame_format == 3 ) ? 32 : 16 ;

		float proj = 4.71118f ;
		int cx = (int)( 240.0f + g_translate.x * proj + 0.5f ) ;
		int cy = (int)( 136.0f - g_translate.y * proj + 0.5f ) ;
		int sx = 0 ;
		int sy = 0 ;
		int sw = sceGimImageGetWidth( image, 0 ) ;
		int sh = sceGimImageGetHeight( image, 0 ) ;
		int sbw = sceGimImageGetBufWidth( image, sw ) ;
		sw = sw * sbpp / dbpp ;
		sbw = sbw * sbpp / dbpp ;

		int dx = cx - sw / 2 ;
		int dy = cy - sh / 2 ;
		if ( dx < 0 ) {
			sx = -dx ;
			sw += dx ;
			dx = 0 ;
		}
		if ( dy < 0 ) {
			sy = -dy ;
			sh += dy ;
			dy = 0 ;
		}
		if ( sw > 480 - dx ) sw = 480 - dx ;
		if ( sh > 272 - dy ) sh = 272 - dy ;
		if ( sw > 0 && sh > 0 ) {
			void *dbp = (char *)sceGeEdramGetAddr() + (int)g_frame_buffer ;
			sceGuCopyImage( g_frame_format, sx, sy, sw, sh, sbw, (void *)pixels, dx, dy, 512, dbp ) ;
		}
	}
}

_Bool load_objects()
{
	unload_objects() ;

	if ( g_menu_pixel == 0 ) {
		sceGimPictureSetMemoryManager( malloc, free ) ;
		sceGimPictureSetMemoryManager2( malloc16, free16 ) ;
	} else {
		int usage = 0x154000 ;
		int size = sceGeEdramGetSize() ;
		char *base = (char *)sceGeEdramGetAddr() ;
		myHeapInit( base + usage, size - usage ) ;
		sceGimPictureSetMemoryManager( malloc, free ) ;
		sceGimPictureSetMemoryManager2( myHeapAlloc16, myHeapFree16 ) ;
	}

	int *data ;
	int size ;
	const char *filename = g_picture_names[ g_menu_picture ] ;
	g_picture_size = 0 ;
	if ( !load_file( filename, &data, &size ) ) return 0 ;
	g_picture_size = size ;

	SceGimPicture *picture = sceGimPictureCreate( 0 ) ;
	g_picture = picture ;
	sceGimPictureLoadFile( picture, data, size, 0 ) ;
	sceGimPictureSetFrameRate( picture, 2.0f ) ;
	if ( g_menu_dissolve ) {
		sceGimPictureSetEnableBits( picture, 1, -1 ) ;
	}

	g_scale = (ScePspFVector3){ 1.0f, 1.0f, 1.0f } ;
	SceGimImageHeader *image = sceGimPictureGetImage( g_picture ) ;
	if ( image != 0 ) {
		float proj = 0.21226104f ;
		g_scale.x = sceGimImageGetWidth( image, 0 ) * proj ;
		g_scale.y = sceGimImageGetHeight( image, 0 ) * proj ;
	}
	free( data ) ;
	g_reload = 0 ;
	return ( picture != 0 ) ;
}

void unload_objects(void) {
    sceGimPictureDelete(g_picture);
    g_picture = NULL;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

int sprintf(char *buf, const char *fmt, ...);
int sceIoOpen(const char *file, int flags, int mode);
long long sceIoLseek(int fd, long long offset, int whence);
int sceIoRead(int fd, void *data, unsigned int size);
int sceIoClose(int fd);
void *malloc(unsigned int size);

static _Bool load_file(const char *filename, int **buf, int *size)
{
	char fullpath[256];

	sprintf(fullpath, "disc0:/PSP_GAME/USRDIR/DATA/gim/%s", filename);

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

void *sceGuGetMemory(int size);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void *sceGuGetMemory(int size);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void draw_rect(int x, int y, int w, int h, int color)
{
	int format = 0x800118;
	short *vertex = sceGuGetMemory(16);

	vertex[0] = color;
	vertex[1] = x;
	vertex[2] = y;
	vertex[3] = 0;
	vertex[4] = color;
	vertex[5] = x + w;
	vertex[6] = y + h;
	vertex[7] = 0;
	sceGuDrawArray(6, format, 2, 0, vertex);
}
