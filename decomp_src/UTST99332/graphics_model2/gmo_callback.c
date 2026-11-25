#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int size_t;
struct SceGimPicture;
typedef struct SceGimPicture SceGimPicture;

extern void *(*g_alloc_memory)(size_t);
extern void (*g_free_memory)(void *);
extern void *(*g_alloc_memory2)(size_t);
extern void (*g_free_memory2)(void *);
extern SceGimPicture *(*g_get_picture)(const char *);
extern void (*g_set_picture)(const char *, SceGimPicture *);

void sceGmoModelSetMemoryManager(void *(*alloc_func)(size_t), void (*free_func)(void *));
void sceGmoModelSetMemoryManager2(void *(*alloc_func)(size_t), void (*free_func)(void *));
void *sceGmoModelAllocMemory(size_t size);
void *sceGmoModelAllocMemory2(size_t size);
void sceGmoModelFreeMemory(void *addr);
void sceGmoModelFreeMemory2(void *addr);


extern __typeof__(g_alloc_memory) g_alloc_memory_20068;
extern __typeof__(g_free_memory) g_free_memory_2006C;
extern __typeof__(g_alloc_memory2) g_alloc_memory2_20070;
extern __typeof__(g_free_memory2) g_free_memory2_20074;
#define g_alloc_memory g_alloc_memory_20068
#define g_free_memory g_free_memory_2006C
#define g_alloc_memory2 g_alloc_memory2_20070
#define g_free_memory2 g_free_memory2_20074
void *malloc(size_t size);
void free(void *ptr);
void sceGmoModelSetMemoryManager(void *(*alloc_func)(size_t), void (*free_func)(void *))
{
	if (alloc_func == NULL)
		alloc_func = malloc;
	if (free_func == NULL)
		free_func = free;
	g_alloc_memory = alloc_func;
	g_free_memory = free_func;
	g_alloc_memory2 = alloc_func;
	g_free_memory2 = free_func;
}

void sceGmoModelSetMemoryManager2(void *(*alloc_func)(size_t), void (*free_func)(void *))
{
	if (alloc_func == NULL)
		alloc_func = malloc;
	if (free_func == NULL)
		free_func = free;
	g_alloc_memory2 = alloc_func;
	g_free_memory2 = free_func;
}

void sceGmoModelSetPictureManager(SceGimPicture *(*get_func)(signed char *), void (*set_func)(signed char *, SceGimPicture *)) {
    g_get_picture = get_func;
    g_set_picture = set_func;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

void *sceGmoModelAllocMemory(size_t size)
{
	if (size == 0)
		return NULL;
	return g_alloc_memory(size);
}

void *sceGmoModelAllocMemory2(size_t size)
{
	if (size == 0)
		return NULL;
	return g_alloc_memory2(size);
}

void sceGmoModelFreeMemory(void *addr)
{
	if (addr != NULL)
		g_free_memory(addr);
}

void sceGmoModelFreeMemory2(void *addr)
{
	if (addr != NULL)
		g_free_memory2(addr);
}

extern signed char D_0001E75C;

SceGimPicture *sceGmoModelImportPicture(signed char *filename) {
    SceGimPicture *var_v0;
    signed char *var_a0;

    var_a0 = filename;
    var_v0 = NULL;
    if (g_get_picture != NULL) {
        if (var_a0 == NULL) {
            var_a0 = &D_0001E75C;
        }
        var_v0 = g_get_picture(var_a0);
    }
    return var_v0;
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

extern signed char D_0001E75C;

void sceGmoModelExportPicture(signed char *filename, SceGimPicture *picture) {
    signed char *var_a0;

    var_a0 = filename;
    if (g_set_picture != NULL) {
        if (var_a0 == NULL) {
            var_a0 = &D_0001E75C;
        }
        g_set_picture(var_a0, picture);
    }
}
/* Warning: struct SceGimPicture is not defined (only forward-declared) */

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model2/nonmatchings/gmo_callback", D_0001E75C);
