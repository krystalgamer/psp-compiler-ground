#include "common.h"
#include "gmo_private_sdk.h"

int sceGmoModelCountChunk( SceGmoChunk *chunk, int type )
{
 int count = 0 ;
 SceGmoChunk *end = SCEGMO_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGMO_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGMO_CHUNK_NEXT( chunk ) ) {
  if ( type == 0 || SCEGMO_CHUNK_TYPE( chunk ) == type ) {
   count ++ ;
  }
 }
 return count ;
}

SceGmoChunk *sceGmoModelFindChunk( SceGmoChunk *chunk, int type, int index )
{
 SceGmoChunk *end = SCEGMO_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGMO_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGMO_CHUNK_NEXT( chunk ) ) {
  if ( type == 0 || SCEGMO_CHUNK_TYPE( chunk ) == type ) {
   if ( -- index == -1 ) return chunk ;
  }
 }
 return 0 ;
}

_Bool sceGmoModelAllocPtr( void *ptr_ptr, int size )
{
 void *ptr = *(void **)ptr_ptr ;
 if ( ptr != 0 ) {
  sceGmoModelFreeMemory( ptr ) ;
 }
 if ( size <= 0 ) {
  *(void **)ptr_ptr = 0 ;
  return 1 ;
 } else {
  ptr = sceGmoModelAllocMemory( size ) ;
  *(void **)ptr_ptr = ptr ;
  return ( ptr != 0 ) ;
 }
}

_Bool sceGmoModelAllocPtr2( void *ptr_ptr, int size )
{
 void *ptr = *(void **)ptr_ptr ;
 if ( ptr != 0 ) {
  sceGmoModelFreeMemory2( ptr ) ;
 }
 if ( size <= 0 ) {
  *(void **)ptr_ptr = 0 ;
  return 1 ;
 } else {
  ptr = sceGmoModelAllocMemory2( size ) ;
  *(void **)ptr_ptr = ptr ;
  return ( ptr != 0 ) ;
 }
}

_Bool sceGmoModelCopyPtr( void *ptr_ptr, const void *src, int size )
{
 if ( !sceGmoModelAllocPtr( ptr_ptr, size ) ) return 0 ;
 memcpy( *(void **)ptr_ptr, src, size ) ;
 return 1 ;
}

_Bool sceGmoModelCopyPtr2( void *ptr_ptr, const void *src, int size )
{
 if ( !sceGmoModelAllocPtr2( ptr_ptr, size ) ) return 0 ;
 memcpy( *(void **)ptr_ptr, src, size ) ;
 return 1 ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_private", sceGmoModelAllocUncachedBuffer);

