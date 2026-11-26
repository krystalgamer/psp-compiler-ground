/* SDK 2.5.0 libgim_picture gim_callback.o, built -O2 by 1.8.4.internal from the SDK 6.6.0
   src/gim_picture/gim_callback.c; its tables are the module's .data/.bss.
   Sony compiled it with -std=gnu9x, which the cflags line cannot carry: the extra
   braces around every if/while/for/do/switch statement and body are the block scopes
   gcc 3.3 adds in C99 mode (c-parse.in c99_block_start), made explicit for a C89 compile. */
/* cflags: -O2 */
#include "gim_sdk.h"


static void *dummy_malloc( size_t size ) __attribute__((used)) ;
static void dummy_free( void *addr ) __attribute__((used)) ;

//----------------------------------------------------------------
//  callback functions
//----------------------------------------------------------------

extern void *(*g_alloc_memory[ 3 ])( size_t size ) ;
extern void (*g_free_memory[ 3 ])( void *addr ) ;

//----------------------------------------------------------------
//  memory cluster
//----------------------------------------------------------------


typedef struct Cluster {
	struct Cluster *m_next ;	// next cluster
	unsigned short m_count ;	// block count
	unsigned short m_mask ;		// alignment mask
	char *m_end ;			// end of cluster
	char *m_top ;			// top of cluster
} Cluster ;

extern Cluster *g_cluster_curr[ 3 ] ;
extern Cluster *g_cluster_list[ 3 ] ;

static void *open_cluster( int type, size_t size, size_t align ) ;
static size_t close_cluster( int type ) ;
static void *alloc_from_cluster( int type, size_t size ) ;
static void free_from_cluster( int type, void *addr ) ;


//----------------------------------------------------------------
//  callback functions
//----------------------------------------------------------------

void sceGimPictureSetMemoryManager( void *(*alloc_func)( size_t size ), void (*free_func)( void *addr ) )
{
	{if ( alloc_func == 0 ) {alloc_func = malloc ;}}
	{if ( free_func == 0 ) {free_func = free ;}}
	g_alloc_memory[ 0 ] = alloc_func ;
	g_free_memory[ 0 ] = free_func ;
	g_alloc_memory[ 1 ] = alloc_func ;
	g_free_memory[ 1 ] = free_func ;
	// g_alloc_memory[ 2 ] = alloc_func ;
	// g_free_memory[ 2 ] = free_func ;
}

void sceGimPictureSetMemoryManager2( void *(*alloc_func)( size_t size ), void (*free_func)( void *addr ) )
{
	{if ( alloc_func == 0 ) {alloc_func = malloc ;}}
	{if ( free_func == 0 ) {free_func = free ;}}
	g_alloc_memory[ 1 ] = alloc_func ;
	g_free_memory[ 1 ] = free_func ;
	// g_alloc_memory[ 2 ] = alloc_func ;
	// g_free_memory[ 2 ] = free_func ;
}

void sceGimPictureSetMemoryManager3( void *(*alloc_func)( size_t size ), void (*free_func)( void *addr ) )
{
	{if ( alloc_func == 0 ) {alloc_func = dummy_malloc ;}}
	{if ( free_func == 0 ) {free_func = dummy_free ;}}
	g_alloc_memory[ 2 ] = alloc_func ;
	g_free_memory[ 2 ] = free_func ;
}

//----------------------------------------------------------------
//  memory cluster
//----------------------------------------------------------------

void *sceGimPictureOpenMemoryCluster( size_t size, size_t align )
{
		return open_cluster( 0, size, align ) ;
	}

void *sceGimPictureOpenMemoryCluster2( size_t size, size_t align )
{
		return open_cluster( 1, size, align ) ;
	}

void *sceGimPictureOpenMemoryCluster3( size_t size, size_t align )
{
		return open_cluster( 2, size, align ) ;
	}

int sceGimPictureCloseMemoryCluster()
{
		return close_cluster( 0 ) ;
	}

int sceGimPictureCloseMemoryCluster2()
{
		return close_cluster( 1 ) ;
	}

int sceGimPictureCloseMemoryCluster3()
{
		return close_cluster( 2 ) ;
	}

//----------------------------------------------------------------
//  memory manager
//----------------------------------------------------------------

void *sceGimPictureAllocMemory( size_t size )
{
		return ( size == 0 ) ? 0 : alloc_from_cluster( 0, size ) ;
	}

void *sceGimPictureAllocMemory2( size_t size )
{
		return ( size == 0 ) ? 0 : alloc_from_cluster( 1, size ) ;
	}

void *sceGimPictureAllocMemory3( size_t size )
{
		return ( size == 0 ) ? 0 : alloc_from_cluster( 2, size ) ;
	}

void sceGimPictureFreeMemory( void *addr )
{
		{if ( addr != 0 ) {free_from_cluster( 0, addr ) ;}}
	}

void sceGimPictureFreeMemory2( void *addr )
{
		{if ( addr != 0 ) {free_from_cluster( 1, addr ) ;}}
	}

void sceGimPictureFreeMemory3( void *addr )
{
		{if ( addr != 0 ) {free_from_cluster( 2, addr ) ;}}
	}

//----------------------------------------------------------------
//  subroutines ( memory cluster )
//----------------------------------------------------------------


void *open_cluster( int type, size_t size, size_t align )
{
	close_cluster( type ) ;
	{if ( size == 0 ) {return 0 ;}}

	int mask = align - 1 ;
	{if ( mask < 3 || ( mask & align ) != 0 ) {mask = 3 ;}}

	size = sizeof( Cluster ) + size + mask ;
	size = ( size + mask ) & ~mask ;
	Cluster *curr = (Cluster *)g_alloc_memory[ type ]( size ) ;
	{if ( curr == 0 ) {return 0 ;}}

	// curr->m_count = 0 ;			// 1.5.0 and before
	curr->m_count = 1 ;			// 2.0.0
	curr->m_mask = mask ;
	curr->m_end = (char *)curr + size ;
	unsigned int top = (unsigned int)curr + sizeof( Cluster ) ;
	curr->m_top = (char *)( ( top + mask ) & ~mask ) ;

	curr->m_next = g_cluster_list[ type ] ;
	g_cluster_list[ type ] = curr ;
	g_cluster_curr[ type ] = curr ;
	return curr ;
}

size_t close_cluster( int type )
{
	Cluster *curr = g_cluster_curr[ type ] ;
	{if ( curr == 0 ) {return 0 ;}}
	free_from_cluster( type, curr ) ;	// 2.0.0
	g_cluster_curr[ type ] = 0 ;
	return curr->m_top - (char *)curr ;
}

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

void free_from_cluster( int type, void *addr )
{
	{if ( addr == 0 ) {return ;}}
	Cluster *prev = 0 ;
	Cluster *curr = g_cluster_list[ type ] ;
	{while ( curr != 0 ) {{
		{if ( addr >= (void *)curr && addr < (void *)curr->m_end ) {{
			{if ( -- curr->m_count == 0 ) {{
				{if ( prev != 0 ) {{
					prev->m_next = curr->m_next ;
				}} else {{
					g_cluster_list[ type ] = curr->m_next ;
				}}}
				g_free_memory[ type ]( curr ) ;
			}}}
			return ;
		}}}
		prev = curr ;		// 2.0.0
		curr = curr->m_next ;
	}}}
	g_free_memory[ type ]( addr ) ;
}


//----------------------------------------------------------------
//  subroutines ( dummy functions )
//----------------------------------------------------------------

void *dummy_malloc( size_t size )
{
	(void)size ;
	return 0 ;
}

void dummy_free( void *addr )
{
	(void)addr ;
	return ;
}


/* the module's .data (g_alloc_memory/g_free_memory) points at them */
__asm__(".globl dummy_malloc\n.globl dummy_free") ;
