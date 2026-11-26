#include "common.h"
#include "gmo_callback_sdk.h"

void sceGmoModelSetMemoryManager( void *(*alloc_func)( size_t size ), void (*free_func)( void *addr ) )
{
 if ( alloc_func == 0 ) alloc_func = malloc ;
 if ( free_func == 0 ) free_func = free ;
 g_alloc_memory[ 0 ] = alloc_func ;
 g_free_memory[ 0 ] = free_func ;
 g_alloc_memory[ 1 ] = alloc_func ;
 g_free_memory[ 1 ] = free_func ;
}

void sceGmoModelSetMemoryManager2( void *(*alloc_func)( size_t size ), void (*free_func)( void *addr ) )
{
 if ( alloc_func == 0 ) alloc_func = malloc ;
 if ( free_func == 0 ) free_func = free ;
 g_alloc_memory[ 1 ] = alloc_func ;
 g_free_memory[ 1 ] = free_func ;
}

void sceGmoModelSetPictureManager( SceGimPicture *(*get_func)( const char *filename ), void (*set_func)( const char *filename, SceGimPicture *picture ) )
{
 g_get_picture = get_func ;
 g_set_picture = set_func ;
}

void *sceGmoModelOpenMemoryCluster( size_t size, size_t align )
{
 return open_cluster( 0, size, align ) ;
}

void *sceGmoModelOpenMemoryCluster2( size_t size, size_t align )
{
 return open_cluster( 1, size, align ) ;
}

int sceGmoModelCloseMemoryCluster()
{
 return close_cluster( 0 ) ;
}

int sceGmoModelCloseMemoryCluster2()
{
 return close_cluster( 1 ) ;
}

void *sceGmoModelAllocMemory( size_t size )
{
 return ( size == 0 ) ? 0 : alloc_from_cluster( 0, size ) ;
}

void *sceGmoModelAllocMemory2( size_t size )
{
 return ( size == 0 ) ? 0 : alloc_from_cluster( 1, size ) ;
}

void sceGmoModelFreeMemory( void *addr )
{
 if ( addr != 0 ) free_from_cluster( 0, addr ) ;
}

void sceGmoModelFreeMemory2( void *addr )
{
 if ( addr != 0 ) free_from_cluster( 1, addr ) ;
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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", open_cluster);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", close_cluster);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", alloc_from_cluster);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", free_from_cluster);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", __psp_libinfo___7EC2C);
