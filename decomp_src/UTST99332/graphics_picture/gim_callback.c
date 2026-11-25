#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int size_t;

extern void *(*g_alloc_memory)(size_t);
extern void (*g_free_memory)(void *);
extern void *(*g_alloc_memory2)(size_t);
extern void (*g_free_memory2)(void *);

void sceGimPictureSetMemoryManager(void *(*alloc_func)(size_t), void (*free_func)(void *));
void sceGimPictureSetMemoryManager2(void *(*alloc_func)(size_t), void (*free_func)(void *));
void *sceGimPictureAllocMemory(size_t size);
void *sceGimPictureAllocMemory2(size_t size);


void *malloc(size_t size);
void free(void *ptr);

void sceGimPictureSetMemoryManager(void *(*alloc_func)(size_t), void (*free_func)(void *))
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

void sceGimPictureSetMemoryManager2(void *(*alloc_func)(size_t), void (*free_func)(void *))
{
	if (alloc_func == NULL)
		alloc_func = malloc;
	if (free_func == NULL)
		free_func = free;
	g_alloc_memory2 = alloc_func;
	g_free_memory2 = free_func;
}

void *sceGimPictureAllocMemory(size_t size)
{
	if (size == 0)
		return NULL;
	return g_alloc_memory(size);
}

void *sceGimPictureAllocMemory2(size_t size)
{
	if (size == 0)
		return NULL;
	return g_alloc_memory2(size);
}

void sceGimPictureFreeMemory(void *addr) {
    if (addr != NULL) {
        g_free_memory(addr);
    }
}

void sceGimPictureFreeMemory2(void *addr) {
    if (addr != NULL) {
        g_free_memory2(addr);
    }
}
