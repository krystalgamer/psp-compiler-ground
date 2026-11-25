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
void sceGimPictureFreeMemory(void *addr);
void sceGimPictureFreeMemory2(void *addr);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/gim_callback", sceGimPictureSetMemoryManager);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/gim_callback", sceGimPictureSetMemoryManager2);

extern __typeof__(g_alloc_memory) g_alloc_memory_20184;
#define g_alloc_memory g_alloc_memory_20184
void *sceGimPictureAllocMemory(size_t size)
{
	if (size == 0)
		return NULL;
	return g_alloc_memory(size);
}
#undef g_alloc_memory

extern __typeof__(g_alloc_memory2) g_alloc_memory2_2018C;
#define g_alloc_memory2 g_alloc_memory2_2018C
void *sceGimPictureAllocMemory2(size_t size)
{
	if (size == 0)
		return NULL;
	return g_alloc_memory2(size);
}
#undef g_alloc_memory2

extern __typeof__(g_free_memory) g_free_memory_20188;
#define g_free_memory g_free_memory_20188
void sceGimPictureFreeMemory(void *addr) {
    if (addr != NULL) {
        g_free_memory(addr);
    }
}
#undef g_free_memory

extern __typeof__(g_free_memory2) g_free_memory2_20190;
#define g_free_memory2 g_free_memory2_20190
void sceGimPictureFreeMemory2(void *addr) {
    if (addr != NULL) {
        g_free_memory2(addr);
    }
}
#undef g_free_memory2
