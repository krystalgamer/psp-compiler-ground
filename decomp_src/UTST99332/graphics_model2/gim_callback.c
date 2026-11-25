/* SDK gim_picture library: devkit 0.6.0's src/gim_picture/gim_callback.c, preprocessed (macros expanded) */
#include "gim_private.h"
#define g_alloc_memory g_alloc_memory_20184
#define g_alloc_memory2 g_alloc_memory2_2018C
#define g_free_memory g_free_memory_20188
#define g_free_memory2 g_free_memory2_20190

extern void *(*g_alloc_memory)( size_t size );
extern void (*g_free_memory)( void *addr );
extern void *(*g_alloc_memory2)( size_t size );
extern void (*g_free_memory2)( void *addr );

void sceGimPictureSetMemoryManager( void *(*alloc_func)( size_t size ), void (*free_func)( void *addr ) )
{
 if ( alloc_func == 0 ) alloc_func = malloc ;
 if ( free_func == 0 ) free_func = free ;
 g_alloc_memory = alloc_func ;
 g_free_memory = free_func ;
 g_alloc_memory2 = alloc_func ;
 g_free_memory2 = free_func ;
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
