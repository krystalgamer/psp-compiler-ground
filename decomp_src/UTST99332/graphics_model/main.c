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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/main", main);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D5E0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D5EC);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D5F8);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D604);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D610);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D61C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D628);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D62C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D630);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D63C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D648);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D654);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/main", D_0001D65C);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/main", begin_scene);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/main", end_scene);

void swap_buffers(void) {
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/main", move_objects);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/main", draw_objects);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/main", load_objects);

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

extern const char D_0001D65C[]; /* "host0:%s" (rodata emitted elsewhere) */
int sprintf(char *buf, const char *fmt, ...);
int sceIoOpen(const char *file, int flags, int mode);
long long sceIoLseek(int fd, long long offset, int whence);
int sceIoRead(int fd, void *data, unsigned int size);
int sceIoClose(int fd);
void *malloc(unsigned int size);

static _Bool load_file(const char *filename, int **buf, int *size)
{
	char fullpath[256];

	sprintf(fullpath, D_0001D65C, filename);

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
