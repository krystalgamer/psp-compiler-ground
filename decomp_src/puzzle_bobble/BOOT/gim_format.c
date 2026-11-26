/* SDK gim_picture library: devkit 0.6.0's src/gim_picture/gim_format.c, preprocessed (macros expanded) */
#include "umdt/graphics_model/gim_private.h"

_Bool sceGimPictureCheckFileHeader( const void *buf, int size )
{
 if ( buf == 0 ) return 0 ;
 if ( size > 0 && size < sizeof( SceGimHeader ) + sizeof( SceGimChunk ) ) {
  ;
  return 0 ;
 }
 SceGimHeader *header = (SceGimHeader *)buf ;
 if ( header->signature != (0x2e47494d) ) {
  ;
  return 0 ;
 }
 if ( header->version != (0x312e3030) ) {
  ;
  return 0 ;
 }
 if ( header->style != (0x00505350) ) {
  ;
  return 0 ;
 }
 return 1 ;
}

int sceGimPictureGetChunkCount( const void *buf, int size )
{
 if ( buf == 0 ) return 0 ;
 SceGimHeader *header = (SceGimHeader *)buf ;
 SceGimChunk *chunk = (SceGimChunk *)( header + 1 ) ;
 return sceGimPictureCountChunk( chunk, SCEGIM_PICTURE ) ;
}

SceGimChunk *sceGimPictureGetChunk( const void *buf, int size, int index )
{
 if ( buf == 0 ) return 0 ;
 SceGimHeader *header = (SceGimHeader *)buf ;
 SceGimChunk *chunk = (SceGimChunk *)( header + 1 ) ;
 return sceGimPictureFindChunk( chunk, SCEGIM_PICTURE, index ) ;
}

/* gim_private.c (the split puts it in this unit: it has no local symbols) */

int sceGimPictureCountChunk( SceGimChunk *chunk, int type )
{
 int count = 0 ;
 SceGimChunk *end = SCEGIM_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGIM_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGIM_CHUNK_NEXT( chunk ) ) {
  if ( type == 0 || SCEGIM_CHUNK_TYPE( chunk ) == type ) {
   count ++ ;
  }
 }
 return count ;
}

SceGimChunk *sceGimPictureFindChunk( SceGimChunk *chunk, int type, int index )
{
 SceGimChunk *end = SCEGIM_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGIM_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGIM_CHUNK_NEXT( chunk ) ) {
  if ( type == 0 || SCEGIM_CHUNK_TYPE( chunk ) == type ) {
   if ( -- index == -1 ) return chunk ;
  }
 }
 return 0 ;
}
