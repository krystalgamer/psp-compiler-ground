/* SDK 2.5.0 libgim_picture gim_format.o, built -O2 by 1.8.4.internal from the SDK 6.6.0
   src/gim_picture/gim_format.c.
   Sony compiled it with -std=gnu9x, which the cflags line cannot carry: the extra
   braces around every if/while/for/do/switch statement and body are the block scopes
   gcc 3.3 adds in C99 mode (c-parse.in c99_block_start), made explicit for a C89 compile. */
/* cflags: -O2 */
#include "gim_sdk.h"


//----------------------------------------------------------------
//  file functions
//----------------------------------------------------------------

bool sceGimPictureCheckFileHeader( const void *buf, int size )
{
	{if ( buf == 0 ) {return false ;}}
	{if ( size > 0 && size < (int)( sizeof( SceGimHeader ) + sizeof( SceGimChunk ) ) ) {{
		WARNING( "wrong gim header ( size )\n" ) ;
		return false ;
	}}}
	SceGimHeader *header = (SceGimHeader *)buf ;
	{if ( header->signature != SCEGIM_FORMAT_SIGNATURE ) {{
		WARNING( "wrong gim header ( signature )\n" ) ;
		return false ;
	}}}
	{if ( header->version != SCEGIM_FORMAT_VERSION ) {{
		WARNING( "wrong gim header ( version )\n" ) ;
		return false ;
	}}}
	{if ( header->style != SCEGIM_FORMAT_STYLE_PSP ) {{
		WARNING( "wrong gim header ( style )\n" ) ;
		return false ;
	}}}
	return true ;
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

//----------------------------------------------------------------
//  chunk functions
//----------------------------------------------------------------

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
