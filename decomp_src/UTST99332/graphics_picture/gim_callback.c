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


INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/gim_callback", sceGimPictureSetMemoryManager);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/gim_callback", sceGimPictureSetMemoryManager2);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/gim_callback", sceGimPictureAllocMemory);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/gim_callback", sceGimPictureAllocMemory2);

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
