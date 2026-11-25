/* SDK gmo_model library: devkit 0.6.0's src/gmo_model/gmo_format.c, preprocessed (macros expanded) */
#include "gmo_private.h"

_Bool sceGmoModelCheckFileHeader( const void *buf, int size )
{
 if ( buf == 0 ) return 0 ;
 if ( size > 0 && size < sizeof( SceGmoHeader ) + sizeof( SceGmoChunk ) ) {
  ;
  return 0 ;
 }
 SceGmoHeader *header = (SceGmoHeader *)buf ;
 if ( header->signature != (0x2e474d4f) ) {
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

int sceGmoModelGetChunkCount( const void *buf, int size )
{
 if ( buf == 0 ) return 0 ;
 SceGmoHeader *header = (SceGmoHeader *)buf ;
 SceGmoChunk *chunk = (SceGmoChunk *)( header + 1 ) ;
 return sceGmoModelCountChunk( chunk, SCEGMO_MODEL ) ;
}

SceGmoChunk *sceGmoModelGetChunk( const void *buf, int size, int index )
{
 if ( buf == 0 ) return 0 ;
 SceGmoHeader *header = (SceGmoHeader *)buf ;
 SceGmoChunk *chunk = (SceGmoChunk *)( header + 1 ) ;
 return sceGmoModelFindChunk( chunk, SCEGMO_MODEL, index ) ;
}
