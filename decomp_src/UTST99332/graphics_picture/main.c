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


void *malloc16(unsigned int size) {
    return memalign(0x10U, size);
}

void free16(void *addr) {
    free(addr);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/main", main);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture/nonmatchings/main", D_00014D20);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture/nonmatchings/main", D_00014D2C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture/nonmatchings/main", D_00014D38);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture/nonmatchings/main", D_00014D3C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture/nonmatchings/main", D_00014D48);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture/nonmatchings/main", D_00014D4C);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture/nonmatchings/main", D_00014D58);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_picture/nonmatchings/main", D_00014D60);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/main", begin_scene);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/main", end_scene);

void swap_buffers(void) {
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/main", move_objects);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/main", draw_objects);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/main", load_objects);

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

extern const char D_00014D60[]; /* "host0:%s" (rodata emitted elsewhere) */
int sprintf(char *buf, const char *fmt, ...);
int sceIoOpen(const char *file, int flags, int mode);
long long sceIoLseek(int fd, long long offset, int whence);
int sceIoRead(int fd, void *data, unsigned int size);
int sceIoClose(int fd);
void *malloc(unsigned int size);

static _Bool load_file(const char *filename, int **buf, int *size)
{
	char fullpath[256];

	sprintf(fullpath, D_00014D60, filename);

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
