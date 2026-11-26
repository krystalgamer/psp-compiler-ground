/* cflags: -O0 */
#include "common.h"

typedef struct {
	float x, y, z;
} Vec3;

typedef struct {
	int fpl;
	void *addr;
} MemPool;

void *memset(void *s, int c, unsigned int n);
int sprintf(char *buf, const char *fmt, ...);
int sceKernelCreateFpl(const char *name, int part, int attr, unsigned int size, unsigned int blocks, void *opt);
int sceKernelTryAllocateFpl(int fpl, void **data);
int sceKernelDeleteFpl(int fpl);

extern MemPool _mempool[200];
extern int g_menu_select;
extern int g_menu_model;
extern int g_menu_vertex;
extern int g_menu_texture;
extern int g_menu_packet;
extern int g_menu_count;
extern int g_menu_cache;
extern Vec3 g_translate;
extern Vec3 g_rotate;
extern char g_running;
extern char g_reload;

void *malloc(unsigned int size)
{
	int i;
	int ret;
	void *p = 0;

	for (i = 0; i < 200; i++) {
		if (_mempool[i].addr == 0) {
			_mempool[i].fpl = sceKernelCreateFpl("ModelTestFpl", 2, 256, size + 16, 1, 0);
			if (_mempool[i].fpl < 0) {
				_mempool[i].fpl = 0;
				break;
			}
			ret = sceKernelTryAllocateFpl(_mempool[i].fpl, &p);
			if (ret < 0) {
				p = 0;
				break;
			}
			p = (void *)(((unsigned int)p + 15) & ~15);
			_mempool[i].addr = p;
			break;
		}
	}
	return p;
}

void free(void *addr)
{
	int i;

	for (i = 0; i < 200; i++) {
		if (_mempool[i].addr == addr) {
			sceKernelDeleteFpl(_mempool[i].fpl);
			_mempool[i].fpl = 0;
			_mempool[i].addr = 0;
			break;
		}
	}
}

static void MemPoolCheck(void)
{
	int i;

	for (i = 0; i < 200; i++)
		;
}

int *__errno(void)
{
}

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016250);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016260);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016270);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016280);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016290);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_000162A0);

static void _GlobalInit(void)
{
	Vec3 v;
	static const Vec3 t0 = { -8.609375f, -0.957031012f, 10.5f };
	static const Vec3 r0 = { 0.0f, -0.942f, 0.0f };

	g_menu_select = 0;
	g_menu_model = 0;
	g_menu_vertex = 1;
	g_menu_texture = 1;
	g_menu_packet = 2;
	g_menu_count = 10;
	g_menu_cache = 40;
	v = t0;
	g_translate = v;
	v = r0;
	g_rotate = v;
	g_running = 1;
	g_reload = 1;
}

int GraphicsModelEntry(int a, int b)
{
	memset(_mempool, 0, sizeof(_mempool));
	return 0;
}







INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/main", GraphicsModelMain);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_000162D4);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_000162D8);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_000162DC);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_000162E0);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_000162E4);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_000162E8);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_000162EC);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_000162F0);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_000162F4);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_000162F8);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_000162FC);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016300);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/main", begin_scene);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_0001631C);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016320);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016328);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_0001632C);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016330);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016338);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016340);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/main", end_scene);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/main", swap_buffers);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/main", move_objects);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/main", draw_objects);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/main", clear_cache);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/main", update_cache);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/main", draw_cache);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016434);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_00016438);

INCLUDE_RODATA("tmp/asm/umdt/graphics_model/nonmatchings/main", D_0001643C);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/main", load_objects);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/main", unload_objects);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/main", load_file);

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

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/main", inverse_orthonormal);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/main", rotate_vector3);

void GraphicsModelTestVersion(char *buf)
{
	sprintf(buf, "Ver. 041027_2");
}
