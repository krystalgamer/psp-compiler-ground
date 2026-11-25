/* cflags: -O2 -frename-registers */
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
void sceGmoModelSetPictureManager(SceGimPicture *(*get_func)(const char *), void (*set_func)(const char *, SceGimPicture *));
void *sceGmoModelAllocMemory(size_t size);
void *sceGmoModelAllocMemory2(size_t size);
void sceGmoModelFreeMemory(void *addr);
void sceGmoModelFreeMemory2(void *addr);
SceGimPicture *sceGmoModelImportPicture(const char *filename);
void sceGmoModelExportPicture(const char *filename, SceGimPicture *picture);

extern __typeof__(g_alloc_memory) g_alloc_memory_147774;
extern __typeof__(g_free_memory) g_free_memory_147778;
extern __typeof__(g_alloc_memory2) g_alloc_memory2_14777C;
extern __typeof__(g_free_memory2) g_free_memory2_147780;
#define g_alloc_memory g_alloc_memory_147774
#define g_free_memory g_free_memory_147778
#define g_alloc_memory2 g_alloc_memory2_14777C
#define g_free_memory2 g_free_memory2_147780
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

void sceGmoModelSetPictureManager(SceGimPicture *(*get_func)(const char *), void (*set_func)(const char *, SceGimPicture *))
{
	g_get_picture = get_func;
	g_set_picture = set_func;
}

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

SceGimPicture *sceGmoModelImportPicture(const char *filename)
{
	if (g_get_picture == NULL)
		return NULL;
	if (filename == NULL)
		filename = "";
	return g_get_picture(filename);
}

void sceGmoModelExportPicture(const char *filename, SceGimPicture *picture)
{
	if (g_set_picture == NULL)
		return;
	if (filename == NULL)
		filename = "";
	g_set_picture(filename, picture);
}

