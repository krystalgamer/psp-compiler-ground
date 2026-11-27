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

static void *open_cluster( int type, size_t size, size_t align )
{
	close_cluster( type ) ;
	if ( size == 0 ) return 0 ;

	int mask = align - 1 ;
	if ( mask < 3 || ( mask & align ) != 0 ) mask = 3 ;

	size = sizeof( Cluster ) + size + mask ;
	size = ( size + mask ) & ~mask ;
	Cluster *curr = (Cluster *)g_alloc_memory[ type ]( size ) ;
	if ( curr == 0 ) return 0 ;

	curr->m_count = 0 ;
	curr->m_mask = mask ;
	curr->m_end = (char *)curr + size ;
	unsigned int top = (unsigned int)curr + sizeof( Cluster ) ;
	curr->m_top = (char *)( ( top + mask ) & ~mask ) ;

	curr->m_next = g_cluster_list[ type ] ;
	g_cluster_list[ type ] = curr ;
	g_cluster_curr[ type ] = curr ;
	return curr ;
}

static size_t close_cluster( int type )
{
	Cluster *curr = g_cluster_curr[ type ] ;
	if ( curr == 0 ) return 0 ;
	g_cluster_curr[ type ] = 0 ;
	return curr->m_top - (char *)curr ;
}

extern __typeof__(g_alloc_memory) g_alloc_memory_836CC;
#define g_alloc_memory g_alloc_memory_836CC
extern __typeof__(g_cluster_curr) g_cluster_list;
#define g_cluster_curr g_cluster_list
void *alloc_from_cluster( int type, size_t size )
{
	{if ( size == 0 ) {return 0 ;}}
	// Cluster *curr = g_cluster_list[ type ] ;	// 1.5.0 and before
	Cluster *curr = g_cluster_curr[ type ] ;	// 2.0.0
	{if ( curr != 0 ) {{
		int mask = curr->m_mask ;
		size = ( size + mask ) & ~mask ;
		char *top = curr->m_top ;
		{if ( curr->m_end >= top + size ) {{
			curr->m_count ++ ;
			curr->m_top = top + size ;
			return top ;
		}}}
	}}}
	return g_alloc_memory[ type ]( size ) ;
}
#undef g_alloc_memory
#undef g_cluster_curr

static void free_from_cluster( int type, void *addr )
{
	if ( addr == 0 ) return ;
	Cluster *curr = g_cluster_list[ type ] ;
	while ( curr != 0 ) {
		if ( addr > (void *)curr && addr < (void *)curr->m_end ) {
			if ( -- curr->m_count == 0 ) {
				g_cluster_list[ type ] = curr->m_next ;
				g_free_memory[ type ]( curr ) ;
			}
			return ;
		}
		curr = curr->m_next ;
	}
	g_free_memory[ type ]( addr ) ;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_callback", __psp_libinfo___7EC2C);
