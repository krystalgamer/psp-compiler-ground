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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", main);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015A90);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015AA0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015AB0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015AC0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015AD0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015AE0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015AF0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015B00);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015B10);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015B20);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015B30);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015B40);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", g_default_picture_names);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015B80);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015B8C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015B98);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015B9C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015BA4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015BAC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015BB4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015BBC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015BC4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015BD0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015BDC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015BE4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015BF0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015BF4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015BF8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015C00);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015C08);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015C1C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015C28);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015C34);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015C40);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015C4C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015C5C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015C68);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015C74);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015C80);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015C8C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015C98);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015CA0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015CB0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015CB4);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015CD8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", D_00015CE4);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", begin_scene);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", end_scene);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", swap_buffers);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", move_objects);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", draw_objects);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", draw_objects2);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture2/nonmatchings/main", load_objects);

void unload_objects(void) {
    sceGimPictureDelete(g_picture);
    g_picture = NULL;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

extern const char D_00015CE4[]; /* "host0:%s" (rodata emitted elsewhere) */
int sprintf(char *buf, const char *fmt, ...);
int sceIoOpen(const char *file, int flags, int mode);
long long sceIoLseek(int fd, long long offset, int whence);
int sceIoRead(int fd, void *data, unsigned int size);
int sceIoClose(int fd);
void *malloc(unsigned int size);

static _Bool load_file(const char *filename, int **buf, int *size)
{
	char fullpath[256];

	sprintf(fullpath, D_00015CE4, filename);

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
