/* SDK gmo_model library: devkit 0.6.0's src/gmo_model/gmo_part.c, preprocessed (macros expanded) */
#include "gmo_private.h"

static void draw_mesh( SceGmoMesh *mesh ) ;
static void reset_arrays( SceGmoPart *part ) ;
static _Bool set_arrays( int index ) ;
static void draw_arrays( SceGmoDrawArrays *cmd ) ;
static void draw_b_spline( SceGmoDrawBSpline *cmd ) ;
static void draw_rect_patch( SceGmoDrawRectPatch *cmd ) ;
static void draw_rect_mesh( SceGmoDrawRectMesh *cmd ) ;

extern SceGmoPart *g_current_part;
extern SceGmoArraysHeader *g_current_arrays;
extern int g_current_index;

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

_Bool sceGmoPartLoad( SceGmoPart *part, const SceGmoChunk *load_chunk )
{
 SceGmoChunk *chunk ;
 if ( part == 0 ) return 0 ;
 if ( load_chunk == 0 ) return 0 ;

 sceGmoPartUnload( part ) ;

 if ( !sceGmoModelCopyPtr2( &( part->m_chunk ), load_chunk, SCEGMO_CHUNK_SIZE( (SceGmoChunk *)load_chunk ) ) ) {
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
  ;
  return 0 ;
 }
 mesh->m_chunk = 0 ;
 mesh->m_reference = 1 ;
 mesh->m_flags = 0 ;
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

_Bool sceGmoMeshLoad( SceGmoMesh *mesh, SceGmoChunk *chunk )
{
 if ( mesh == 0 ) return 0 ;
 if ( chunk == 0 ) return 0 ;

 sceGmoMeshUnload( mesh ) ;

 mesh->m_chunk = chunk ;

 SceGmoChunk *end = SCEGMO_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGMO_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGMO_CHUNK_NEXT( chunk ) ) {
  void *args = SCEGMO_CHUNK_ARGS( chunk ) ;

  switch ( SCEGMO_CHUNK_TYPE( chunk ) ) {
      case SCEGMO_SET_MATERIAL : {
   SceGmoSetMaterial *cmd = (SceGmoSetMaterial *)args ;
   mesh->m_material = cmd->material ;
   break ;
      }
      case SCEGMO_BLEND_SUBSET : {
   SceGmoBlendSubset *cmd = (SceGmoBlendSubset *)args ;
   mesh->m_blend_subset = cmd->indices ;
   mesh->m_n_blend_subset = cmd->n_indices ;
   break ;
      }
  }
 }
 return 1 ;
}

void sceGmoMeshUnload( SceGmoMesh *mesh )
{
 if ( mesh == 0 ) return ;

 mesh->m_chunk = 0 ;
 mesh->m_blend_subset = 0 ;
 mesh->m_n_blend_subset = 0 ;
}

void sceGmoMeshDraw( SceGmoMesh *mesh, SceGmoModel *model, SceGmoBone *bone, SceGmoPart *part )
{
 if ( mesh == 0 ) return ;

 sceGmoContextSetBone( bone, model, mesh->m_blend_subset, mesh->m_n_blend_subset ) ;

 SceGmoMaterial *material = sceGmoModelGetMaterial( model, mesh->m_material ) ;
 if ( material == 0 ) {
  reset_arrays( part ) ;
  draw_mesh( mesh ) ;
  return ;
 }

 reset_arrays( part ) ;
 int count = sceGmoMaterialGetLayerCount( material ) ;
 { int i ; for ( i = 0 ; i < count ; i ++ ) {

  if ( sceGmoContextSetMaterial( material, model, i ) == 0 ) continue ;
  draw_mesh( mesh ) ;
 } }
}

void draw_mesh( SceGmoMesh *mesh )
{

 SceGmoChunk *chunk = mesh->m_chunk ;
 SceGmoChunk *end = SCEGMO_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGMO_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGMO_CHUNK_NEXT( chunk ) ) {
  void *args = SCEGMO_CHUNK_ARGS( chunk ) ;

  switch ( SCEGMO_CHUNK_TYPE( chunk ) ) {
      case SCEGMO_KNOT_VECTOR_U : {
   break ;
      }
      case SCEGMO_KNOT_VECTOR_V : {
   break ;
      }
      case SCEGMO_DRAW_ARRAYS : {
   SceGmoDrawArrays *cmd = (SceGmoDrawArrays *)args ;
   if ( set_arrays( cmd->arrays ) ) draw_arrays( cmd ) ;
   break ;
      }
      case SCEGMO_DRAW_PARTICLE : {
   break ;
      }
      case SCEGMO_DRAW_B_SPLINE : {
   SceGmoDrawBSpline *cmd = (SceGmoDrawBSpline *)args ;
   if ( set_arrays( cmd->arrays ) ) draw_b_spline( cmd ) ;
   break ;
      }
      case SCEGMO_DRAW_RECT_MESH : {
   SceGmoDrawRectMesh *cmd = (SceGmoDrawRectMesh *)args ;
   if ( set_arrays( cmd->arrays ) ) draw_rect_mesh( cmd ) ;
   break ;
      }
      case SCEGMO_DRAW_RECT_PATCH : {
   SceGmoDrawRectPatch *cmd = (SceGmoDrawRectPatch *)args ;
   if ( set_arrays( cmd->arrays ) ) draw_rect_patch( cmd ) ;
   break ;
      }
  }
 }

}

void reset_arrays( SceGmoPart *part )
{
 g_current_part = part ;
 g_current_arrays = 0 ;
 g_current_index = -1 ;
}

_Bool set_arrays( int index )
{
 if ( g_current_index == index ) return 1 ;
 SceGmoChunk *chunk = sceGmoPartGetArrays( g_current_part, index ) ;
 if ( chunk == 0 ) return 0 ;
 g_current_arrays = (SceGmoArraysHeader *)SCEGMO_CHUNK_ARGS( chunk ) ;
 g_current_index = index ;
 return 1 ;
}

void draw_arrays( SceGmoDrawArrays *cmd )
{
 SceGmoArraysHeader *arrays = g_current_arrays ;

 sceGmoContextSetTexOffs( 0 ) ;

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
  format &= ~( 2 << 11 ) ;
  indices = 0 ;
 }
 sceGuDrawArrayN( mode, format, n_verts, n_prims, indices, buffer ) ;
}

void draw_b_spline( SceGmoDrawBSpline *cmd )
{
 SceGmoArraysHeader *arrays = g_current_arrays ;

 int width = cmd->width ;
 int height = cmd->height ;
 int format = arrays->format ;
 if ( ( 3 << 0 ) & format ) {
  sceGmoContextSetTexOffs( 0 ) ;
 } else {
  rect tmp = { 0, 0, 1.0f / ( width - 3 ), 1.0f / ( height - 3 ) } ;
  sceGmoContextSetTexOffs( &tmp ) ;
 }

 int mode = cmd->mode ;
 int flags_u = 3 & ( mode >> 12 ) ;
 int flags_v = 3 & ( mode >> 14 ) ;
 unsigned short *indices = cmd->indices ;
 void *buffer = arrays + 1 ;
 if ( SCEGMO_PRIM_SEQUENTIAL & mode ) {
  int stride = format >> 24 ;
  stride += ( ( format >> 18 ) & 7 ) * stride ;
  buffer = (char *)buffer + stride * indices[ 0 ] ;
  format &= ~( 2 << 11 ) ;
  indices = 0 ;
 }
 sceGuDrawSpline( format, width, height, flags_u, flags_v, indices, buffer ) ;
}

void draw_rect_mesh( SceGmoDrawRectMesh *cmd )
{
 SceGmoArraysHeader *arrays = g_current_arrays ;

 sceGmoContextSetTexOffs( 0 ) ;

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
 sceKernelDcacheWritebackAll();
 sceGuDrawArrayN( mode, format, n_verts, height - 1, indices, buffer ) ;
}

void draw_rect_patch( SceGmoDrawRectPatch *cmd )
{
 SceGmoArraysHeader *arrays = g_current_arrays ;

 int width = cmd->width ;
 int height = cmd->height ;
 int format = arrays->format ;
 if ( ( 3 << 0 ) & format ) {
  sceGmoContextSetTexOffs( 0 ) ;
 } else {
  rect tmp = { 0, 0, 1.0f / ( width / 3 ), 1.0f / ( height / 3 ) } ;
  sceGmoContextSetTexOffs( &tmp ) ;
 }

 int mode = cmd->mode ;
 unsigned short *indices = cmd->indices ;
 void *buffer = arrays + 1 ;
 if ( SCEGMO_PRIM_SEQUENTIAL & mode ) {
  int stride = format >> 24 ;
  stride += ( ( format >> 18 ) & 7 ) * stride ;
  buffer = (char *)buffer + stride * indices[ 0 ] ;
  format &= ~( 2 << 11 ) ;
  indices = 0 ;
 }
 sceGuDrawBezier( format, width, height, indices, buffer ) ;
}
