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


INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_callback", sceGimPictureSetMemoryManager);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_callback", sceGimPictureSetMemoryManager2);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_callback", sceGimPictureAllocMemory);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_callback", sceGimPictureAllocMemory2);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_callback", sceGimPictureFreeMemory);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_callback", sceGimPictureFreeMemory2);
