#include "common.h"

/* declarations recovered from DWARF (UTST99332 graphics_model gim_callback) */
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

void *malloc(unsigned int size);
void free(void *p);
extern __typeof__(g_alloc_memory) g_alloc_memory_83750;
#define g_alloc_memory g_alloc_memory_83750
extern __typeof__(g_free_memory) g_free_memory_83754;
#define g_free_memory g_free_memory_83754
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

void sceGimPictureSetMemoryManager2( void *(*alloc_func)( size_t size ), void (*free_func)( void *addr ) )
{
 if ( alloc_func == 0 ) alloc_func = malloc ;
 if ( free_func == 0 ) free_func = free ;
 g_alloc_memory2 = alloc_func ;
 g_free_memory2 = free_func ;
}

void *sceGimPictureAllocMemory( size_t size )
{
 return ( size == 0 ) ? 0 : g_alloc_memory( size ) ;
}

void *sceGimPictureAllocMemory2( size_t size )
{
 return ( size == 0 ) ? 0 : g_alloc_memory2( size ) ;
}

void sceGimPictureFreeMemory( void *addr )
{
 if ( addr != 0 ) g_free_memory( addr ) ;
}

void sceGimPictureFreeMemory2( void *addr )
{
 if ( addr != 0 ) g_free_memory2( addr ) ;
}
