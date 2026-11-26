#include "common.h"

/* declarations recovered from DWARF (UTST99332 graphics_model gmo_callback) */
typedef unsigned int size_t;
typedef struct SceGimPicture SceGimPicture;
struct SceGimPicture;

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", sceGmoModelSetMemoryManager);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", sceGmoModelSetMemoryManager2);

void sceGmoModelSetPictureManager(SceGimPicture *(*get_func)(const char *), void (*set_func)(const char *, SceGimPicture *))
{
	g_get_picture = get_func;
	g_set_picture = set_func;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", sceGmoModelOpenMemoryCluster);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", sceGmoModelOpenMemoryCluster2);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", sceGmoModelCloseMemoryCluster);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", sceGmoModelCloseMemoryCluster2);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", sceGmoModelAllocMemory);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", sceGmoModelAllocMemory2);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", sceGmoModelFreeMemory);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", sceGmoModelFreeMemory2);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", open_cluster);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", close_cluster);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", alloc_from_cluster);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", free_from_cluster);


INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", __psp_libinfo___7EC2C);
