/* SDK gim_picture library: devkit 0.6.0's src/gim_picture/gim_private.c, preprocessed (macros expanded) */
#include "gim_private.h"

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
