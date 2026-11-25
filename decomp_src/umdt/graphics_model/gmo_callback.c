/* SDK gmo_model library: devkit 0.6.0's src/gmo_model/gmo_callback.c, preprocessed (macros expanded) */
#include "gmo_private.h"
#define g_alloc_memory g_alloc_memory_17B78
#define g_alloc_memory2 g_alloc_memory2_17B80
#define g_free_memory g_free_memory_17B7C
#define g_free_memory2 g_free_memory2_17B84

extern void *(*g_alloc_memory)( size_t size );
extern void (*g_free_memory)( void *addr );
extern void *(*g_alloc_memory2)( size_t size );
extern void (*g_free_memory2)( void *addr );

extern SceGimPicture *(*g_get_picture)( const char *filename );
extern void (*g_set_picture)( const char *filename, SceGimPicture *picture );

void sceGmoModelSetMemoryManager( void *(*alloc_func)( size_t size ), void (*free_func)( void *addr ) )
{
 if ( alloc_func == 0 ) alloc_func = malloc ;
 if ( free_func == 0 ) free_func = free ;
 g_alloc_memory = alloc_func ;
 g_free_memory = free_func ;
 g_alloc_memory2 = alloc_func ;
 g_free_memory2 = free_func ;
}

void sceGmoModelSetMemoryManager2( void *(*alloc_func)( size_t size ), void (*free_func)( void *addr ) )
{
 if ( alloc_func == 0 ) alloc_func = malloc ;
 if ( free_func == 0 ) free_func = free ;
 g_alloc_memory2 = alloc_func ;
 g_free_memory2 = free_func ;
}

void sceGmoModelSetPictureManager( SceGimPicture *(*get_func)( const char *filename ), void (*set_func)( const char *filename, SceGimPicture *picture ) )
{
 g_get_picture = get_func ;
 g_set_picture = set_func ;
}

void *sceGmoModelAllocMemory( size_t size )
{
 return ( size == 0 ) ? 0 : g_alloc_memory( size ) ;
}

void *sceGmoModelAllocMemory2( size_t size )
{
 return ( size == 0 ) ? 0 : g_alloc_memory2( size ) ;
}

void sceGmoModelFreeMemory( void *addr )
{
 if ( addr != 0 ) g_free_memory( addr ) ;
}

void sceGmoModelFreeMemory2( void *addr )
{
 if ( addr != 0 ) g_free_memory2( addr ) ;
}

SceGimPicture *sceGmoModelImportPicture( const char *filename )
{
 if ( g_get_picture == 0 ) return 0 ;
 if ( filename == 0 ) filename = "" ;
 return g_get_picture( filename ) ;
}

void sceGmoModelExportPicture( const char *filename, SceGimPicture *picture )
{
 if ( g_set_picture == 0 ) return ;
 if ( filename == 0 ) filename = "" ;
 g_set_picture( filename, picture ) ;
}
