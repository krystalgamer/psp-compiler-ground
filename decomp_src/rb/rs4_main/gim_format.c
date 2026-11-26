#include "common.h"

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
	SceGimChunk *root = sceGimPictureGetRootChunk( buf, size ) ;
	return sceGimPictureCountChildChunk( root, SCEGIM_PICTURE ) ;
}

SceGimChunk *sceGimPictureGetChunk( const void *buf, int size, int idx )
{
	SceGimChunk *root = sceGimPictureGetRootChunk( buf, size ) ;
	return sceGimPictureFindChildChunk( root, SCEGIM_PICTURE, idx ) ;
}

SceGimChunk *sceGimPictureGetRootChunk( const void *buf, int size )
{
	{if ( buf == 0 ) {return 0 ;}}
	SceGimHeader *header = (SceGimHeader *)buf ;
	return (SceGimChunk *)( header + 1 ) ;
}

int sceGimPictureCountChildChunk( const SceGimChunk *chunk, int type )
{
	{if ( chunk == 0 ) {return 0 ;}}
	int count = 0 ;
	SceGimChunk *end = SCEGIM_CHUNK_NEXT( chunk ) ;
	{for ( chunk = SCEGIM_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGIM_CHUNK_NEXT( chunk ) ) {{
		{if ( type == 0 || SCEGIM_CHUNK_TYPE( chunk ) == type ) {{
			count ++ ;
		}}}
	}}}
	return count ;
}

SceGimChunk *sceGimPictureFindChildChunk( const SceGimChunk *chunk, int type, int idx )
{
	{if ( chunk == 0 ) {return 0 ;}}
	SceGimChunk *end = SCEGIM_CHUNK_NEXT( chunk ) ;
	{for ( chunk = SCEGIM_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGIM_CHUNK_NEXT( chunk ) ) {{
		{if ( type == 0 || SCEGIM_CHUNK_TYPE( chunk ) == type ) {{
			{if ( -- idx == -1 ) {return (SceGimChunk *)chunk ;}}
		}}}
	}}}
	return 0 ;
}
