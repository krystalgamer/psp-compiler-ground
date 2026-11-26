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


void *malloc16(unsigned int size) {
    return memalign(0x10U, size);
}

void free16(void *addr) {
    free(addr);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", main);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E510);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E520);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E530);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E540);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E550);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E560);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", g_default_model_names);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E588);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E594);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E5A0);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E5AC);

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

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E678);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E690);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", D_0001E69C);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", begin_scene);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", end_scene);

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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", move_objects);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", draw_objects);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", clear_cache);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", update_cache);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", draw_cache);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", load_objects);

void unload_objects(void) {
    sceGmoModelDelete(g_model);
    g_model = NULL;
}
/* Warning: struct SceGmoModel is not defined (only forward-declared) */

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/main", load_file);

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
