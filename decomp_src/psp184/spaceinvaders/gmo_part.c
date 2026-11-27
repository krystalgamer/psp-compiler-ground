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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_part", draw_mesh);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_part", draw_arrays);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_part", draw_b_spline);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_part", draw_rect_mesh);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_part", draw_rect_patch);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_part", get_packet_size);

