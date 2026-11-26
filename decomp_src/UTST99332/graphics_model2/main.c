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
struct SceGmoModel;
typedef struct SceGmoModel SceGmoModel;
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
struct SceGmoMotion;
typedef struct SceGmoMotion SceGmoMotion;
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
extern char g_launch_buf[4096];
extern char g_packet_buf[2][1048576];
extern int g_packet;
extern ScePspFMatrix4 g_matrix_buf[16];
extern int g_frame;
extern _Bool g_running;
extern _Bool g_reload;
extern SceGmoModel *g_model;
extern ScePspFVector3 g_translate;
extern ScePspFVector3 g_rotate;
extern ScePspFVector3 g_scale;
extern int g_vbl_count;
extern int g_vbl_step;
extern int g_vbl_time;
extern int g_cpu_load;
extern int g_gpu_load;
extern const char *const g_default_model_names[6];
extern const char *const *g_model_names;
extern int g_model_count;
extern int g_model_size;
extern int g_menu_select;
extern int g_menu_model;
extern int g_menu_vertex;
extern int g_menu_texture;
extern int g_menu_packet;
extern int g_menu_count;
extern int g_menu_cache;
extern char g_cache_buf[1048576];
extern char *g_cache_top;
extern char *g_cache_packets[50];
extern char *g_cache_packet;
extern float g_cache_loop[2];
extern float g_cache_fps;
extern float g_cache_frame;

int main(int argc, const char **argv);
static void begin_scene(void);
static void end_scene(void);
static void swap_buffers(void);
static void move_objects(void);
static void draw_objects(void);
static void clear_cache(void);
static void update_cache(void);
static void draw_cache(void);
static _Bool load_objects(void);
static _Bool load_file(const char *filename, int **buf, int *size);
static void draw_rect(int x, int y, int w, int h, int color);
static ScePspFMatrix4 *inverse_orthonormal(ScePspFMatrix4 *m0, const ScePspFMatrix4 *m1);


/* SDK prototypes (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
int sceCtrlSetSamplingMode(int mode);
void sceGuAlphaFunc(int a0, int a1, int a2);
void sceGuAmbient(unsigned int color);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuCallList(const void *list);
void sceGuClear(int flags);
void sceGuClearColor(unsigned int color);
void sceGuClearDepth(unsigned int depth);
void sceGuClearStencil(unsigned int stencil);
void sceGuColorMaterial(int components);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
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
void sceGumMultMatrix(const ScePspFMatrix4 *m);
void sceGumPerspective(float fovy, float aspect, float near, float far);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumScale(const ScePspFVector3 *v);
void sceGumSetMatrixStack(void *stack, int proj, int view, int model, int texture);
void sceGumStoreMatrix(ScePspFMatrix4 *m);
void sceGumTranslate(const ScePspFVector3 *v);
void sceGumUpdateMatrix(void);

void *malloc16(unsigned int size) {
    return memalign(0x10U, size);
}

void free16(void *addr) {
    free(addr);
}

void sceGmoModelSetMemoryManager2(void *(*alloc_func)(unsigned int), void (*free_func)(void *));
void sceGmoModelSetMemoryManager(void *(*alloc_func)(unsigned int), void (*free_func)(void *));
void sceGimPictureSetMemoryManager(void *(*alloc)(unsigned int), void (*dealloc)(void *));
void sceGimPictureSetMemoryManager2(void *(*alloc)(unsigned int), void (*dealloc)(void *));
void *malloc(unsigned int size);
void free(void *p);
void myHeapTerm(void);
void unload_objects(void);
#ifndef SCE_CTRL_MODE_DIGITALANALOG /* sample */
#define SCE_CTRL_MODE_DIGITALANALOG	1
#endif
#ifndef SCEGU_PF5551 /* sample */
#define SCEGU_PF5551                       1
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
#ifndef SCEGU_SCR_WIDTH /* sample */
#define SCEGU_SCR_WIDTH       480
#endif
#ifndef SCEGU_SCR_OFFSETX /* sample */
#define SCEGU_SCR_OFFSETX     ((4096 - SCEGU_SCR_WIDTH) / 2)
#endif
#ifndef SCEGU_SCR_HEIGHT /* sample */
#define SCEGU_SCR_HEIGHT      272
#endif
#ifndef SCEGU_SCR_OFFSETY /* sample */
#define SCEGU_SCR_OFFSETY     ((4096 - SCEGU_SCR_HEIGHT) / 2)
#endif
#ifndef SCEGU_SYNC_FINISH /* sample */
#define SCEGU_SYNC_FINISH                  0
#endif
#ifndef SCEGU_SYNC_WAIT /* sample */
#define SCEGU_SYNC_WAIT                    0
#endif
#ifndef LAUNCH_BUFSIZE /* sample */
#define LAUNCH_BUFSIZE	(4096)
#endif
#ifndef SCEGU_CALL /* sample */
#define SCEGU_CALL                         1
#endif
#ifndef SCEGU_IMMEDIATE /* sample */
#define SCEGU_IMMEDIATE                    0
#endif
#ifndef PACKET_BUFSIZE /* sample */
#define PACKET_BUFSIZE	(1024*1024)
#endif
int main( int argc, const char **argv )
{
	menuInit() ;
	sceCtrlSetSamplingMode( SCE_CTRL_MODE_DIGITALANALOG ) ;

	sceGuInit() ;
	sceGuStart( SCEGU_IMMEDIATE, g_packet_buf[ 0 ], PACKET_BUFSIZE ) ;
	sceGuDrawBuffer( SCEGU_PF5551, SCEGU_VRAM_BP_0, SCEGU_VRAM_WIDTH ) ;
	sceGuDispBuffer( SCEGU_SCR_WIDTH, SCEGU_SCR_HEIGHT, SCEGU_VRAM_BP_1, SCEGU_VRAM_WIDTH ) ;
	sceGuDepthBuffer( SCEGU_VRAM_BP_2, SCEGU_VRAM_WIDTH ) ;
	sceGuOffset( SCEGU_SCR_OFFSETX, SCEGU_SCR_OFFSETY ) ;
	sceGuFinish() ;
	sceGuSync( SCEGU_SYNC_FINISH, SCEGU_SYNC_WAIT ) ;
	sceGumSetMatrixStack( g_matrix_buf, 4, 4, 8, 0 ) ;

	

	sceGimPictureSetMemoryManager( malloc, free ) ;
	sceGimPictureSetMemoryManager2( malloc16, free16 ) ;
	sceGmoModelSetMemoryManager( malloc, free ) ;
	sceGmoModelSetMemoryManager2( malloc, free ) ;

	if ( argc > 1 ) {
		g_model_count = argc - 1 ;
		g_model_names = argv + 1 ;
	}
	sceGuDisplay( 1 ) ;

	while ( g_running ) {
		if ( g_reload ) {
			if ( !load_objects() ) break ;
			clear_cache() ;
			g_packet = -1 ;
			g_vbl_count = -1 ;
		}
		if ( g_menu_packet == 0 ) {		
			sceGuStart( SCEGU_IMMEDIATE, g_packet_buf[ 0 ], PACKET_BUFSIZE ) ;
			begin_scene() ;
			move_objects() ;
			draw_objects() ;
			end_scene() ;
			sceGuFinish() ;
		} else if ( g_menu_packet == 1 ) {	
			sceGuStart( SCEGU_IMMEDIATE, g_launch_buf, LAUNCH_BUFSIZE ) ;
			begin_scene() ;
			if ( g_packet >= 0 ) sceGuCallList( g_packet_buf[ g_packet ] ) ;
			end_scene() ;
			sceGuFinish() ;

			g_packet = ( g_packet != 0 ) ? 0 : 1 ;
			sceGuStart( SCEGU_CALL, g_packet_buf[ g_packet ], PACKET_BUFSIZE ) ;
			move_objects() ;
			draw_objects() ;
			sceGuFinish() ;
		} else {				
			sceGuStart( SCEGU_IMMEDIATE, g_packet_buf[ 0 ], PACKET_BUFSIZE ) ;
			begin_scene() ;
			move_objects() ;
			update_cache() ;
			draw_cache() ;
			end_scene() ;
			sceGuFinish() ;
		}
		swap_buffers() ;
	}
	unload_objects() ;

	myHeapTerm() ;
	sceGuTerm() ;
	menuTerm( 1, 0x11 ) ;
	return 0 ;
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E510);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E520);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E530);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E540);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E550);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E560);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", g_default_model_names);



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
#ifndef SCEGU_ADD /* sample */
#define SCEGU_ADD                          0
#endif
#ifndef SCEGU_SRC_ALPHA /* sample */
#define SCEGU_SRC_ALPHA                    2
#endif
#ifndef SCEGU_ONE_MINUS_SRC_ALPHA /* sample */
#define SCEGU_ONE_MINUS_SRC_ALPHA          3
#endif
#ifndef SCEGU_GEQUAL /* sample */
#define SCEGU_GEQUAL                       7
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
	sceGuBlendFunc( SCEGU_ADD, SCEGU_SRC_ALPHA, SCEGU_ONE_MINUS_SRC_ALPHA, 0, 0 ) ;
	sceGuDepthFunc( SCEGU_GEQUAL ) ;
	sceGuTexFilter( SCEGU_LINEAR_MIPMAP_LINEAR, SCEGU_LINEAR ) ;
	sceGuTexFunc( SCEGU_TEX_MODULATE, SCEGU_RGBA ) ;
	sceGuTexWrap( SCEGU_REPEAT, SCEGU_REPEAT ) ;
	sceGuPatchDivide( 4, 4 ) ;
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E5B8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E5BC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E5C4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E5CC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E5D0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E5D4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E5DC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E5E4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E5EC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E5F4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E600);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E610);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E61C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E628);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E634);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E640);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E64C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E658);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E660);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E674);

extern const char *const D_0001E5C4[], *const D_0001E5D4[], *const D_0001E5F4[];
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
extern const char D_0001E5B8[];
extern const char D_0001E5BC[];
extern const char D_0001E5CC[];
extern const char D_0001E5D0[];
extern const char D_0001E5DC[];
extern const char D_0001E5E4[];
extern const char D_0001E5EC[];
extern const char D_0001E600[];
extern const char D_0001E610[];
extern const char D_0001E61C[];
extern const char D_0001E628[];
extern const char D_0001E634[];
extern const char D_0001E640[];
extern const char D_0001E64C[];
extern const char D_0001E658[];
extern const char D_0001E660[];
extern const char D_0001E674[];
#define MENU_CACHE ((0)+5)
#define SCEGU_TEXTURE                      9
#define SCEGU_DEPTH_TEST                   1

void end_scene()
{
	char buf[ 64 ] ;
	if ( g_frame * g_vbl_step % 30 < 15 ) {
		sceGuDebugPrint( 0, g_menu_select * 10 + 10, 0xffffffff, D_0001E674 ) ;
	}
	sprintf( buf, D_0001E600, g_model_names[ g_menu_model ], ( g_model_size + 1023 ) / 1024 ) ;
	sceGuDebugPrint( 10, 10, 0xffffffff, buf ) ;
	sprintf( buf, D_0001E610, D_0001E5C4[ g_menu_vertex ] ) ;
	sceGuDebugPrint( 10, 20, 0xffffffff, buf ) ;
	sprintf( buf, D_0001E61C, D_0001E5D4[ g_menu_texture ] ) ;
	sceGuDebugPrint( 10, 30, 0xffffffff, buf ) ;
	sprintf( buf, D_0001E628, D_0001E5F4[ g_menu_packet ] ) ;
	sceGuDebugPrint( 10, 40, 0xffffffff, buf ) ;
	sprintf( buf, D_0001E634, g_menu_count ) ;
	sceGuDebugPrint( 10, 50, 0xffffffff, buf ) ;
	if ( g_menu_select == MENU_CACHE ) {
		sprintf( buf, D_0001E660, g_menu_cache, ( g_cache_top - g_cache_buf + 1023 ) / 1024 ) ;
		sceGuDebugPrint( 10, 60, 0xffffffff, buf ) ;
	}
	sprintf( buf, D_0001E640, g_cpu_load ) ;
	sceGuDebugPrint( 10, 240, 0xffffffff, buf ) ;
	sprintf( buf, D_0001E64C, g_gpu_load ) ;
	sceGuDebugPrint( 10, 250, 0xffffffff, buf ) ;
	if ( g_reload ) {
		sceGuDebugPrint( 400, 10, 0xffffffff, D_0001E658 ) ;
	}

	sceGuDisable( SCEGU_TEXTURE ) ;
	sceGuDisable( SCEGU_DEPTH_TEST ) ;
	draw_rect( 82, 241, g_cpu_load, 7, 0x8f00 ) ;
	draw_rect( 82, 251, g_gpu_load, 7, 0x800f ) ;
}

static void swap_buffers()
{
	int cpu_time = sceKernelGetSystemTimeLow();
	int gpu_time;
	int vbl_time;
	int vbl_count;

	sceGuSync(0, 0);
	gpu_time = sceKernelGetSystemTimeLow();
	sceDisplayWaitVblankStart();
	sceGuSwapBuffers();
	g_frame++;
	vbl_time = sceKernelGetSystemTimeLow();
	vbl_count = sceDisplayGetVcount();
	if (g_vbl_count >= 0) {
		g_vbl_step = vbl_count - g_vbl_count;
		if (g_frame % 6 == 0) {
			g_cpu_load = (cpu_time - g_vbl_time) * 100 / 16667;
			g_gpu_load = (gpu_time - g_vbl_time) * 100 / 16667;
		}
	}
	g_vbl_time = vbl_time;
	g_vbl_count = vbl_count;
}

void *malloc(unsigned int size);
void free(void *p);
void sceGmoModelSetEnableBits(SceGmoModel *model, int bits, int value);
void sceGmoModelSetEnableMask(SceGmoModel *model, int mask, int value);
#ifndef SCE_CTRL_SELECT /* sample */
#define SCE_CTRL_SELECT				(1<<0)
#endif
#ifndef SCE_CTRL_START /* sample */
#define SCE_CTRL_START				(1<<3)
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
#ifndef SCE_CTRL_UP /* sample */
#define SCE_CTRL_UP					(1<<4)
#endif
#ifndef SCE_CTRL_DOWN /* sample */
#define SCE_CTRL_DOWN				(1<<6)
#endif
#ifndef MENU_MODEL /* sample */
#define MENU_MODEL (0)
#endif
#ifndef MENU_VERTEX /* sample */
#define MENU_VERTEX ((0)+1)
#endif
#ifndef MENU_TEXTURE /* sample */
#define MENU_TEXTURE ((0)+2)
#endif
#ifndef SCEGMO_ENABLE_TEXTURE /* sample */
#define SCEGMO_ENABLE_TEXTURE (0x0004)
#endif
#ifndef MENU_PACKET /* sample */
#define MENU_PACKET ((0)+3)
#endif
#ifndef MENU_COUNT /* sample */
#define MENU_COUNT ((0)+4)
#endif
#ifndef MENU_CACHE /* sample */
#define MENU_CACHE ((0)+5)
#endif
#ifndef SCE_CTRL_CIRCLE /* sample */
#define SCE_CTRL_CIRCLE				(1<<13)
#endif
#ifndef CACHE_MAX /* sample */
#define CACHE_MAX	(50)
#endif
#ifndef SCE_CTRL_CROSS /* sample */
#define SCE_CTRL_CROSS				(1<<14)
#endif
void move_objects()
{
	float move = g_vbl_step * 0.5f ;
	float turn = g_vbl_step * ( 2.0f * 3.14f / 180.0f ) ;

	SceCtrlData buf ;
	sceCtrlReadBufferPositive( &buf, 1 ) ;

	extern int D_00020A38;
	int state = buf.Buttons ;
	int press = state & ~D_00020A38 ;
	D_00020A38 = state ;

	if ( press & SCE_CTRL_SELECT ) {
		g_running = 0 ;
		return ;
	}
	if ( press & SCE_CTRL_START ) {
		g_translate = (ScePspFVector3){ 0, 0, 0 } ;
		g_rotate = (ScePspFVector3){ 0, 0, 0 } ;
		g_menu_model = 0 ;
		g_menu_vertex = 0 ;
		g_menu_texture = 1 ;
		g_menu_packet = 0 ;
		g_menu_count = 3 ;
		g_menu_cache = 40 ;
		g_reload = 1 ;
		return ;
	}
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

	

	if ( press & SCE_CTRL_UP ) {
		if ( g_menu_select > 0 ) g_menu_select -= 1 ;
	}
	if ( press & SCE_CTRL_DOWN ) {
		if ( g_menu_select < MENU_CACHE ) g_menu_select += 1 ;
	}

	switch ( g_menu_select ) {
	    case MENU_MODEL : {
		if ( press & SCE_CTRL_CIRCLE ) {
			if ( g_menu_model < g_model_count - 1 ) {
				g_menu_model += 1 ;
				g_reload = 1 ;
			}
		}
		if ( press & SCE_CTRL_CROSS ) {
			if ( g_menu_model > 0 ) {
				g_menu_model -= 1 ;
				g_reload = 1 ;
			}
		}
		break ;
	    }
	    case MENU_VERTEX : {
		if ( press & ( SCE_CTRL_CIRCLE | SCE_CTRL_CROSS ) ) {
			g_menu_vertex = !g_menu_vertex ;
			g_reload = 1 ;
		}
		break ;
	    }
	    case MENU_TEXTURE : {
		if ( press & ( SCE_CTRL_CIRCLE | SCE_CTRL_CROSS ) ) {
			g_menu_texture = !g_menu_texture ;
			int bits = g_menu_texture ? -1 : 0 ;
			SceGmoModel *model = g_model ;
			sceGmoModelSetEnableMask( model, SCEGMO_ENABLE_TEXTURE, ~bits ) ;
			sceGmoModelSetEnableBits( model, SCEGMO_ENABLE_TEXTURE, bits ) ;
			if ( g_menu_packet == 2 ) clear_cache() ;
		}
		break ;
	    }
	    case MENU_PACKET : {
		if ( press & SCE_CTRL_CIRCLE ) {
			if ( g_menu_packet < 2 ) {
				g_menu_packet += 1 ;
				g_packet = -1 ;
				g_frame %= 2 ;
				clear_cache() ;
			}
		}
		if ( press & SCE_CTRL_CROSS ) {
			if ( g_menu_packet > 0 ) {
				g_menu_packet -= 1 ;
				g_packet = -1 ;
				g_frame %= 2 ;
				clear_cache() ;
			}
		}
		break ;
	    }
	    case MENU_COUNT : {
		if ( press & SCE_CTRL_CIRCLE ) {
			if ( g_menu_count < 10 ) g_menu_count += 1 ;
		}
		if ( press & SCE_CTRL_CROSS ) {
			if ( g_menu_count > 0 ) g_menu_count -= 1 ;
		}
		break ;
	    }
	    case MENU_CACHE : {
		if ( state & SCE_CTRL_CIRCLE ) {
			if ( g_menu_cache < CACHE_MAX ) {
				g_menu_cache += 1 ;
				clear_cache() ;
			}
		}
		if ( state & SCE_CTRL_CROSS ) {
			if ( g_menu_cache > 1 ) {
				g_menu_cache -= 1 ;
				clear_cache() ;
			}
		}
		break ;
	    }
	}
}

void *malloc(unsigned int size);
void free(void *p);
void sceGmoModelAnimate(SceGmoModel *model, float step);
void sceGmoModelDraw(SceGmoModel *model);
void sceGmoModelSetWorldMatrix(SceGmoModel *model, const ScePspFMatrix4 *m);
void sceGmoModelUpdate(SceGmoModel *model);
#ifndef SCEGU_MATRIX_WORLD /* sample */
#define SCEGU_MATRIX_WORLD                 2
#endif
static void draw_objects()
{
	float step = g_vbl_step * ( 1.0f / 60.0f ) ;

	sceGumMatrixMode( SCEGU_MATRIX_WORLD ) ;
	sceGumLoadIdentity() ;
	sceGumTranslate( &g_translate ) ;
	sceGumRotateY( g_rotate.y ) ;
	sceGumRotateX( g_rotate.x ) ;

	ScePspFMatrix4 m ;
	for ( int i = 0 ; i < g_menu_count ; i ++ ) {
		ScePspFVector3 move = { ( ( i % 2 == 0 ) ? i : -i ) * 10, 0, 0 } ;
		sceGumTranslate( &move ) ;
		sceGumPushMatrix() ;
		sceGumScale( &g_scale ) ;
		sceGumStoreMatrix( &m ) ;

		SceGmoModel *model = g_model ;
		sceGmoModelSetWorldMatrix( model, &m ) ;
		sceGmoModelAnimate( model, step ) ;
		sceGmoModelUpdate( model ) ;
		sceGmoModelDraw( model ) ;

		sceGumPopMatrix() ;
		step = 0.0f ;
	}
}

int sceGmoModelGetCurrentMotion(SceGmoModel *model);
SceGmoMotion *sceGmoModelGetMotion(SceGmoModel *model, int index);
const float *sceGmoMotionGetFrameLoop(SceGmoMotion *motion);
float sceGmoMotionGetFrameRate(SceGmoMotion *motion);
float sceGmoMotionGetFrame(SceGmoMotion *motion);
void *memset(void *s, int c, unsigned int n);

static void clear_cache(void)
{
	SceGmoModel *model = g_model;
	int current = sceGmoModelGetCurrentMotion(model);
	SceGmoMotion *motion = sceGmoModelGetMotion(model, current);
	const float *loop = sceGmoMotionGetFrameLoop(motion);

	g_cache_loop[0] = (loop == 0) ? 0.0f : loop[0];
	g_cache_loop[1] = (loop == 0) ? 0.0f : loop[1];
	g_cache_fps = sceGmoMotionGetFrameRate(motion);
	g_cache_frame = sceGmoMotionGetFrame(motion);

	memset(g_cache_packets, 0, sizeof(g_cache_packets));
	g_cache_top = g_cache_buf;
	g_cache_packet = 0;
}

int sceGuFinish(void);
void *malloc(unsigned int size);
void free(void *p);
void sceGmoModelAnimate(SceGmoModel *model, float step);
void sceGmoModelDraw(SceGmoModel *model);
void sceGmoModelSetWorldMatrix(SceGmoModel *model, const ScePspFMatrix4 *m);
void sceGmoModelUpdate(SceGmoModel *model);
void sceGmoMotionSetFrame(SceGmoMotion *motion, float frame);
int sceGuCheckList(void);
#ifndef CACHE_BUFSIZE /* sample */
#define CACHE_BUFSIZE	(1024*1024)
#endif
#ifndef SCEGU_CALL /* sample */
#define SCEGU_CALL                         1
#endif
void update_cache()
{
	if ( g_menu_cache == 0 ) return ;

	

	float step = g_vbl_step * ( 1.0f / 60.0f ) ;
	float f = g_cache_frame + g_cache_fps * step ;
	float f0 = g_cache_loop[ 0 ] ;
	float f1 = g_cache_loop[ 1 ] ;
	if ( f >= f1 ) f = f0 ;
	if ( f < f0 ) f = f1 ;
	g_cache_frame = f ;
	f = ( f0 == f1 ) ? 0.0f : ( f - f0 ) / ( f1 - f0 ) ;
	int index = (int)( ( g_menu_cache - 1 ) * f + 0.5f ) ;
	g_cache_packet = g_cache_packets[ index ] ;

	

	if ( g_cache_packet == 0 ) {
		int size = CACHE_BUFSIZE - ( g_cache_top - g_cache_buf ) ;
		sceGuStart( SCEGU_CALL, g_cache_top, size ) ;
		sceGumUpdateMatrix() ;	
		sceGuFinish() ;
		sceGuStart( SCEGU_CALL, g_cache_top, size ) ;
		SceGmoModel *model = g_model ;
		int current = sceGmoModelGetCurrentMotion( model ) ;
		SceGmoMotion *motion = sceGmoModelGetMotion( model, current ) ;
		sceGmoMotionSetFrame( motion, g_cache_frame ) ;
		sceGmoModelSetWorldMatrix( model, 0 ) ;
		sceGmoModelAnimate( model, 0.0f ) ;
		sceGmoModelUpdate( model ) ;
		sceGmoModelDraw( model ) ;
		size = sceGuFinish() ;
		size = ( size + 63 ) / 64 * 64 ;
		g_cache_packets[ index ] = g_cache_top ;
		g_cache_packet = g_cache_top ;
		g_cache_top += size ;
	}
}

void *malloc(unsigned int size);
void free(void *p);
ScePspFVector3 * rotate_vector3(ScePspFVector3 *v0, ScePspFMatrix4 *m1, ScePspFVector3 *v2);
void sceGmoModelAnimate(SceGmoModel *model, float step);
void sceGmoModelDraw(SceGmoModel *model);
void sceGmoModelSetWorldMatrix(SceGmoModel *model, const ScePspFMatrix4 *m);
void sceGmoModelUpdate(SceGmoModel *model);
#ifndef SCEGU_LIGHT_DIRECTION /* sample */
#define SCEGU_LIGHT_DIRECTION              0
#endif
#ifndef SCEGU_DIFFUSE_AND_SPECULAR /* sample */
#define SCEGU_DIFFUSE_AND_SPECULAR         6
#endif
#ifndef SCEGU_MATRIX_VIEW /* sample */
#define SCEGU_MATRIX_VIEW                  1
#endif
#ifndef SCEGU_MATRIX_WORLD /* sample */
#define SCEGU_MATRIX_WORLD                 2
#endif
void draw_cache()
{
	float step = g_vbl_step * ( 1.0f / 60.0f ) ;

	sceGumMatrixMode( SCEGU_MATRIX_WORLD ) ;
	sceGumLoadIdentity() ;
	sceGumTranslate( &g_translate ) ;
	sceGumRotateY( g_rotate.y ) ;
	sceGumRotateX( g_rotate.x ) ;

	ScePspFMatrix4 m ;
	for ( int i = 0 ; i < g_menu_count ; i ++ ) {
		ScePspFVector3 move = { ( ( i % 2 == 0 ) ? i : -i ) * 10, 0, 0 } ;
		sceGumTranslate( &move ) ;
		sceGumPushMatrix() ;
		sceGumScale( &g_scale ) ;
		sceGumStoreMatrix( &m ) ;
		sceGumPopMatrix() ;

		sceGumMatrixMode( SCEGU_MATRIX_VIEW ) ;
		sceGumPushMatrix() ;
		sceGumMultMatrix( &m ) ;
		sceGumMatrixMode( SCEGU_MATRIX_WORLD ) ;

		ScePspFMatrix4 m2 ;
		ScePspFVector3 v2 ;
		inverse_orthonormal( &m2, &m ) ;
		rotate_vector3( &v2, &m2, &(ScePspFVector3){ -5, 10, 5 } ) ;
		sceGuLight( 0, SCEGU_LIGHT_DIRECTION, SCEGU_DIFFUSE_AND_SPECULAR, &v2 ) ;

		if ( g_cache_packet != 0 ) {
			sceGumUpdateMatrix() ;
			sceGuCallList( g_cache_packet ) ;
		} else {
			SceGmoModel *model = g_model ;
			sceGmoModelSetWorldMatrix( model, 0 ) ;
			sceGmoModelAnimate( model, step ) ;
			sceGmoModelUpdate( model ) ;
			sceGmoModelDraw( model ) ;
		}
		sceGumMatrixMode( SCEGU_MATRIX_VIEW ) ;
		sceGumPopMatrix() ;
		sceGumMatrixMode( SCEGU_MATRIX_WORLD ) ;
		step = 0.0f ;
	}
}

void *myHeapAlloc(unsigned int size);
void myHeapFree(void *p);
void *malloc(unsigned int size);
void free(void *p);
void myHeapInit(void *addr, unsigned int size);
SceGmoModel * sceGmoModelCreate(void *chunk);
const ScePspFVector3 * sceGmoModelGetBoundingBox(SceGmoModel *model);
_Bool sceGmoModelLoadFile(SceGmoModel *model, const void *buf, int size, int index);
void sceGmoModelSetCurrentMotion(SceGmoModel *model, int index, float delay);
void sceGmoModelSetEnableBits(SceGmoModel *model, int bits, int value);
void sceGmoModelSetEnableMask(SceGmoModel *model, int mask, int value);
void unload_objects(void);
#ifndef SCEGU_VRAM_BUFSIZE32 /* sample */
#define SCEGU_VRAM_BUFSIZE32  (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*4)
#endif
#ifndef SCEGU_VRAM_WIDTH /* sample */
#define SCEGU_VRAM_WIDTH      512
#endif
#ifndef SCEGU_SCR_HEIGHT /* sample */
#define SCEGU_SCR_HEIGHT      272
#endif
#ifndef SCEGU_VRAM_BUFSIZE /* sample */
#define SCEGU_VRAM_BUFSIZE    (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*2)
#endif
#ifndef SCEGMO_ENABLE_FOG /* sample */
#define SCEGMO_ENABLE_FOG (0x0002)
#endif
#ifndef SCEGMO_ENABLE_TEXTURE /* sample */
#define SCEGMO_ENABLE_TEXTURE (0x0004)
#endif
static _Bool load_objects()
{
	unload_objects() ;

	
	
	
	

	if ( g_menu_vertex == 0 ) {
		sceGimPictureSetMemoryManager( malloc, free ) ;
		sceGimPictureSetMemoryManager2( malloc16, free16 ) ;
		sceGmoModelSetMemoryManager( malloc, free ) ;
		sceGmoModelSetMemoryManager2( malloc, free ) ;
	} else {
		int usage = SCEGU_VRAM_BUFSIZE32 * 2 + SCEGU_VRAM_BUFSIZE ;
		int size = sceGeEdramGetSize() ;
		char *base = (char *)sceGeEdramGetAddr() ;
		myHeapInit( base + usage, size - usage ) ;

		sceGimPictureSetMemoryManager( malloc, free ) ;
		sceGimPictureSetMemoryManager2( malloc16, free16 ) ;
		sceGmoModelSetMemoryManager( malloc, free ) ;
		sceGmoModelSetMemoryManager2( myHeapAlloc, myHeapFree ) ;
	}

	

	g_model_size = 0 ;

	int *data, size ;
	const char *filename = g_model_names[ g_menu_model ] ;
	if ( !load_file( filename, &data, &size ) ) return 0 ;
	g_model_size = size ;

	

	SceGmoModel *model = g_model = sceGmoModelCreate( 0 ) ;
	sceGmoModelLoadFile( model, data, size, 0 ) ;
	sceGmoModelSetCurrentMotion( model, 0, 0.0f ) ;
	sceGmoModelSetEnableBits( model, SCEGMO_ENABLE_FOG, 0 ) ;
	if ( !g_menu_texture ) {
		sceGmoModelSetEnableMask( model, SCEGMO_ENABLE_TEXTURE, -1 ) ;
		sceGmoModelSetEnableBits( model, SCEGMO_ENABLE_TEXTURE, 0 ) ;
	}

	

	g_scale = (ScePspFVector3){ 1, 1, 1 } ;

	const ScePspFVector3 *box = sceGmoModelGetBoundingBox( model ) ;
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

	free( data ) ;
	g_reload = 0 ;
	return ( model != 0 ) ;
}

void unload_objects(void) {
    sceGmoModelDelete(g_model);
    g_model = NULL;
}
/* Warning: struct SceGmoModel is not defined (only forward-declared) */

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E69C);

extern const char D_0001E69C[]; /* "host0:%s" (rodata emitted elsewhere) */
int sprintf(char *buf, const char *fmt, ...);
int sceIoOpen(const char *file, int flags, int mode);
long long sceIoLseek(int fd, long long offset, int whence);
int sceIoRead(int fd, void *data, unsigned int size);
int sceIoClose(int fd);
void *malloc(unsigned int size);

static _Bool load_file(const char *filename, int **buf, int *size)
{
	char fullpath[256];

	sprintf(fullpath, D_0001E69C, filename);

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

static ScePspFMatrix4 *inverse_orthonormal(ScePspFMatrix4 *m0, const ScePspFMatrix4 *m1)
{
	float x = -m1->w.x;
	float y = -m1->w.y;
	float z = -m1->w.z;

	m0->x = (ScePspFVector4){ m1->x.x, m1->y.x, m1->z.x, 0 };
	m0->y = (ScePspFVector4){ m1->x.y, m1->y.y, m1->z.y, 0 };
	m0->z = (ScePspFVector4){ m1->x.z, m1->y.z, m1->z.z, 0 };
	m0->w = (ScePspFVector4){ m1->x.x * x + m1->x.y * y + m1->x.z * z,
	                          m1->y.x * x + m1->y.y * y + m1->y.z * z,
	                          m1->z.x * x + m1->z.y * y + m1->z.z * z, 1 };
	return m0;
}

ScePspFVector3 *rotate_vector3(ScePspFVector3 *v0, ScePspFMatrix4 *m1, ScePspFVector3 *v2) {
    float temp_f3;
    float temp_f4;
    float temp_f5;

    temp_f4 = v2->x;
    temp_f5 = v2->y;
    temp_f3 = v2->z;
    v0->x = (m1->x.x * temp_f4) + (m1->y.x * temp_f5) + (m1->z.x * temp_f3);
    v0->y = (m1->x.y * temp_f4) + (m1->y.y * temp_f5) + (m1->z.y * temp_f3);
    v0->z = (m1->x.z * temp_f4) + (m1->y.z * temp_f5) + (m1->z.z * temp_f3);
    return v0;
}
