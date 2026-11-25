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

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_callback", sceGmoModelSetMemoryManager);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_callback", sceGmoModelSetMemoryManager2);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_callback", sceGmoModelSetPictureManager);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_callback", sceGmoModelAllocMemory);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_callback", sceGmoModelAllocMemory2);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_callback", sceGmoModelFreeMemory);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_callback", sceGmoModelFreeMemory2);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_callback", sceGmoModelImportPicture);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_callback", sceGmoModelExportPicture);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gmo_model/gmo_callback", D_00021718);
