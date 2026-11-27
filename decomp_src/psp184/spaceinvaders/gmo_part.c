#include "common.h"
#include "gmo_part_sdk.h"

SceGmoPart *sceGmoPartCreate( SceGmoChunk *chunk )
{
 SceGmoPart *part = (SceGmoPart *)sceGmoModelAllocMemory( sizeof( SceGmoPart ) ) ;
 if ( part == 0 ) {
  ;
  return 0 ;
 }
 sceGmoBaseConstruct( &( part->m_base ) ) ;
 part->m_chunk = 0 ;
 part->m_reference = 1 ;
 part->m_flags = 0 ;
 part->m_meshes = 0 ;
 part->m_arrays = 0 ;
 part->m_n_meshes = 0 ;
 part->m_n_arrays = 0 ;
 if ( chunk != 0 && !sceGmoPartLoad( part, chunk ) ) {
  sceGmoPartDelete( part ) ;
  return 0 ;
 }
 return part ;
}

void sceGmoPartDelete( SceGmoPart *part )
{
 if ( part == 0 ) return ;
 if ( -- part->m_reference == 0 ) {
  sceGmoPartUnload( part ) ;
  sceGmoBaseDestruct( &( part->m_base ) ) ;
  sceGmoModelFreeMemory( part ) ;
 }
}

SceGmoPart *sceGmoPartDuplicate( SceGmoPart *part, int flags )
{
 if ( part == 0 ) return 0 ;
 part->m_reference ++ ;
 return part ;
}

_Bool sceGmoPartLoad( SceGmoPart *part, SceGmoChunk *chunk )
{
 if ( part == 0 ) return 0 ;
 if ( chunk == 0 ) return 0 ;
 sceGmoPartUnload( part ) ;
 if ( !sceGmoModelCopyPtr2( &( part->m_chunk ), chunk, SCEGMO_CHUNK_SIZE( chunk ) ) ) {
  ;
  return 0 ;
 }
 chunk = part->m_chunk ;
 chunk->type = 1 ;
 int n_meshes = sceGmoModelCountChunk( chunk, SCEGMO_MESH ) ;
 int n_arrays = sceGmoModelCountChunk( chunk, SCEGMO_ARRAYS ) ;
 if ( !sceGmoModelAllocPtr( &( part->m_meshes ), n_meshes * sizeof( void * ) )
   || !sceGmoModelAllocPtr( &( part->m_arrays ), n_arrays * sizeof( void * ) ) ) {
  ;
  return 0 ;
 }
 SceGmoChunk *end = SCEGMO_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGMO_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGMO_CHUNK_NEXT( chunk ) ) {
  switch ( SCEGMO_CHUNK_TYPE( chunk ) ) {
      case SCEGMO_MESH : {
   SceGmoMesh *mesh = sceGmoMeshCreate( chunk ) ;
   if ( mesh == 0 ) return 0 ;
   part->m_meshes[ part->m_n_meshes ++ ] = mesh ;
   break ;
      }
      case SCEGMO_ARRAYS : {
   part->m_arrays[ part->m_n_arrays ++ ] = chunk ;
   break ;
      }
  }
 }
 return 1 ;
}

void sceGmoPartUnload( SceGmoPart *part )
{
 if ( part == 0 ) return ;
 SceGmoChunk *chunk = part->m_chunk ;
 if ( chunk != 0 ) {
  if ( -- chunk->type == 0 ) sceGmoModelFreeMemory2( chunk ) ;
  part->m_chunk = 0 ;
 }
 { int i ; for ( i = 0 ; i < part->m_n_meshes ; i ++ ) {
  sceGmoMeshDelete( part->m_meshes[ i ] ) ;
 } }
 sceGmoModelFreeMemory( part->m_meshes ) ;
 sceGmoModelFreeMemory( part->m_arrays ) ;
 part->m_meshes = 0 ;
 part->m_arrays = 0 ;
 part->m_n_meshes = 0 ;
 part->m_n_arrays = 0 ;
}

_Bool sceGmoPartLoadCache( SceGmoPart *part )
{
	if ( part == 0 ) return 0 ;
	{ int i ; for ( i = 0 ; i < part->m_n_meshes ; i ++ ) {
		if ( !sceGmoMeshLoadCache( part->m_meshes[ i ], part ) ) return 0 ;
	} }
	return 1 ;
}

void sceGmoPartUnloadCache( SceGmoPart *part )
{
	if ( part == 0 ) return ;
	{ int i ; for ( i = 0 ; i < part->m_n_meshes ; i ++ ) {
		sceGmoMeshUnloadCache( part->m_meshes[ i ] ) ;
	} }
}

void sceGmoPartDraw( SceGmoPart *part, SceGmoModel *model, SceGmoBone *bone )
{
 if ( part == 0 ) return ;
 SceGmoSubject *parent = sceGmoBaseGetParent( &( part->m_base ) ) ;
 if ( parent != 0 ) model = (SceGmoModel *)parent ;
 { int i ; for ( i = 0 ; i < part->m_n_meshes ; i ++ ) {
  sceGmoMeshDraw( part->m_meshes[ i ], model, bone, part ) ;
 } }
}

void sceGmoPartSetParent( SceGmoPart *part, SceGmoModel *parent )
{
 if ( part == 0 ) return ;
 sceGmoBaseSetParent( &( part->m_base ), (SceGmoSubject *)parent ) ;
}

SceGmoModel *sceGmoPartGetParent( SceGmoPart *part )
{
 if ( part == 0 ) return 0 ;
 return (SceGmoModel *)sceGmoBaseGetParent( &( part->m_base ) ) ;
}

int sceGmoPartGetMeshCount( SceGmoPart *part )
{
 if ( part == 0 ) return 0 ;
 return part->m_n_meshes ;
}

int sceGmoPartGetArraysCount( SceGmoPart *part )
{
 if ( part == 0 ) return 0 ;
 return part->m_n_arrays ;
}

SceGmoMesh *sceGmoPartGetMesh( SceGmoPart *part, int index )
{
 if ( part == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= part->m_n_meshes ) return 0 ;
 return part->m_meshes[ index ] ;
}

SceGmoChunk *sceGmoPartGetArrays( SceGmoPart *part, int index )
{
 if ( part == 0 ) return 0 ;
 index = (0x0fff&(index)) ;
 if ( index >= part->m_n_arrays ) return 0 ;
 return part->m_arrays[ index ] ;
}

SceGmoMesh *sceGmoMeshCreate( SceGmoChunk *chunk )
{
	SceGmoMesh *mesh = (SceGmoMesh *)sceGmoModelAllocMemory( sizeof( SceGmoMesh ) ) ;
	if ( mesh == 0 ) {
		return 0 ;
	}
	mesh->m_chunk = 0 ;
	mesh->m_reference = 1 ;
	mesh->m_flags = 0 ;
	mesh->m_cache = 0 ;
	mesh->m_material = -1 ;
	mesh->m_blend_subset = 0 ;
	mesh->m_n_blend_subset = 0 ;

	if ( chunk != 0 && !sceGmoMeshLoad( mesh, chunk ) ) {
		sceGmoMeshDelete( mesh ) ;
		return 0 ;
	}
	return mesh ;
}

void sceGmoMeshDelete( SceGmoMesh *mesh )
{
 if ( mesh == 0 ) return ;
 if ( -- mesh->m_reference == 0 ) {
  sceGmoMeshUnload( mesh ) ;
  sceGmoModelFreeMemory( mesh ) ;
 }
}

SceGmoMesh *sceGmoMeshDuplicate( SceGmoMesh *mesh, int flags )
{
 if ( mesh == 0 ) return 0 ;
 mesh->m_reference ++ ;
 return mesh ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_part", sceGmoMeshLoad);

void sceGmoMeshUnload( SceGmoMesh *mesh )
{
	if ( mesh == 0 ) return ;
	sceGmoMeshUnloadCache( mesh ) ;
	mesh->m_chunk = 0 ;
	mesh->m_blend_subset = 0 ;
	mesh->m_n_blend_subset = 0 ;
}

_Bool sceGmoMeshLoadCache( SceGmoMesh *mesh, SceGmoPart *part )
{
	if ( mesh == 0 || part == 0 ) return 0 ;
	if ( mesh->m_cache != 0 ) return 1 ;
	int size = get_packet_size( mesh ) ;
	void *cache = sceGmoModelAllocUncachedBuffer( &( mesh->m_cache ), size ) ;
	if ( cache == 0 ) return 0 ;
	sceGuStart( 1, cache, size ) ;
	draw_mesh( mesh, part ) ;
	sceGuFinish() ;
	return 1 ;
}

void sceGmoMeshUnloadCache( SceGmoMesh *mesh )
{
	if ( mesh == 0 ) return ;
	sceGmoModelFreeMemory2( mesh->m_cache ) ;
	mesh->m_cache = 0 ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_part", sceGmoMeshDraw);

static void draw_mesh( SceGmoMesh *mesh, SceGmoPart *part )
{
	SceGmoArraysHeader *arrays = 0 ;
	int index = -1 ;

	SceGmoChunk *chunk = mesh->m_chunk ;
	SceGmoChunk *end = SCEGMO_CHUNK_NEXT( chunk ) ;
	for ( chunk = SCEGMO_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGMO_CHUNK_NEXT( chunk ) ) {
		int type = SCEGMO_CHUNK_TYPE( chunk ) ;
		if ( type < SCEGMO_DRAW_ARRAYS || type > SCEGMO_DRAW_RECT_PATCH ) continue ;
		SceGmoDrawArrays *cmd = (SceGmoDrawArrays *)SCEGMO_CHUNK_ARGS( chunk ) ;
		int idx = cmd->arrays ;
		if ( index != idx ) {
			SceGmoChunk *chunk2 = sceGmoPartGetArrays( part, idx ) ;
			if ( chunk2 == 0 ) continue ;
			arrays = (SceGmoArraysHeader *)SCEGMO_CHUNK_ARGS( chunk2 ) ;
			index = idx ;
		}
		switch ( type ) {
		    case SCEGMO_DRAW_ARRAYS :
			draw_arrays( arrays, (SceGmoDrawArrays *)cmd ) ;
			break ;
		    case SCEGMO_DRAW_B_SPLINE :
			draw_b_spline( arrays, (SceGmoDrawBSpline *)cmd ) ;
			break ;
		    case SCEGMO_DRAW_RECT_MESH :
			draw_rect_mesh( arrays, (SceGmoDrawRectMesh *)cmd ) ;
			break ;
		    case SCEGMO_DRAW_RECT_PATCH :
			draw_rect_patch( arrays, (SceGmoDrawRectPatch *)cmd ) ;
			break ;
		}
	}
}

static void draw_arrays( SceGmoArraysHeader *arrays, SceGmoDrawArrays *cmd )
{
	int mode = cmd->mode ;
	int n_verts = cmd->n_verts ;
	int n_prims = cmd->n_prims ;
	unsigned short *indices = cmd->indices ;
	int format = arrays->format ;
	void *buffer = arrays + 1 ;
	if ( SCEGMO_PRIM_SEQUENTIAL & mode ) {
		int stride = format >> 24 ;
		stride += ( ( format >> 18 ) & 7 ) * stride ;
		buffer = (char *)buffer + stride * indices[ 0 ] ;
		format &= ~(2 << 11) ;
		indices = 0 ;
	}
	sceGuDrawArrayN( mode, format, n_verts, n_prims, indices, buffer ) ;
}

static void draw_b_spline( SceGmoArraysHeader *arrays, SceGmoDrawBSpline *cmd )
{
	int width = cmd->width ;
	int height = cmd->height ;
	int format = arrays->format ;
	int mode = cmd->mode ;
	int flags_u = 3 & ( mode >> 12 ) ;
	int flags_v = 3 & ( mode >> 14 ) ;
	unsigned short *indices = cmd->indices ;
	void *buffer = arrays + 1 ;
	if ( SCEGMO_PRIM_SEQUENTIAL & mode ) {
		int stride = format >> 24 ;
		stride += ( ( format >> 18 ) & 7 ) * stride ;
		buffer = (char *)buffer + stride * indices[ 0 ] ;
		format &= ~(2 << 11) ;
		indices = 0 ;
	}
	sceGuDrawSpline( format, width, height, flags_u, flags_v, indices, buffer ) ;
}

static void draw_rect_mesh( SceGmoArraysHeader *arrays, SceGmoDrawRectMesh *cmd )
{
	int mode = cmd->mode ;
	int width = cmd->width ;
	int height = cmd->height ;
	unsigned short *indices = (unsigned short *)sceGuGetMemory( sizeof( short ) * width * 2 * ( height - 1 ) ) ;
	unsigned short *sp = cmd->indices ;
	unsigned short *dp = indices ;
	int index = 0 ;
	if ( SCEGMO_PRIM_SEQUENTIAL & mode ) {
		index = sp[ 0 ] ;
		sp = 0 ;
	}
	int index2 = index + width ;
	{ int i ; for ( i = 1 ; i < height ; i ++ ) {
		{ int j ; for ( j = 0 ; j < width ; j ++ ) {
			dp[ 0 ] = ( sp == 0 ) ? index : sp[ index ] ;
			dp[ 1 ] = ( sp == 0 ) ? index2 : sp[ index2 ] ;
			dp += 2 ;
			index += 1 ;
			index2 += 1 ;
		} }
	} }
	int n_verts = width * 2 ;
	int format = arrays->format ;
	void *buffer = arrays + 1 ;
	sceGuDrawArrayN( mode, format, n_verts, height - 1, indices, buffer ) ;
}

static void draw_rect_patch( SceGmoArraysHeader *arrays, SceGmoDrawRectPatch *cmd )
{
	int width = cmd->width ;
	int height = cmd->height ;
	int format = arrays->format ;
	int mode = cmd->mode ;
	unsigned short *indices = cmd->indices ;
	void *buffer = arrays + 1 ;
	if ( SCEGMO_PRIM_SEQUENTIAL & mode ) {
		int stride = format >> 24 ;
		stride += ( ( format >> 18 ) & 7 ) * stride ;
		buffer = (char *)buffer + stride * indices[ 0 ] ;
		format &= ~(2 << 11) ;
		indices = 0 ;
	}
	sceGuDrawBezier( format, width, height, indices, buffer ) ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_part", get_packet_size);

