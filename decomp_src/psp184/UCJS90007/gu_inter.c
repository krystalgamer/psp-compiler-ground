/* SDK 2.5.0 libgim_picture gu_inter.o, built -O2 by 1.8.4.internal from the SDK 6.6.0
   src/gim_picture/gu_inter.c.
   Sony compiled it with -std=gnu9x, which the cflags line cannot carry: the extra
   braces around every if/while/for/do/switch statement and body are the block scopes
   gcc 3.3 adds in C99 mode (c-parse.in c99_block_start), made explicit for a C89 compile. */
/* cflags: -O2 */
#include "gim_sdk.h"


//----------------------------------------------------------------
//  activate
//----------------------------------------------------------------

bool sceGimPictureActivate( SceGimPicture *picture )
{
	unsigned int size ;
	unsigned int *buf = (unsigned int *)sceGuBeginPacket( &size ) ;
	bool res = sceGimPictureActivateEx( picture, &buf, &size, SCEGIM_ACTIVATE_ALL ) ;
	sceGuEndPacket( buf ) ;
	return res ;
}

bool sceGimPictureActivateTexture( SceGimPicture *picture )
{
	unsigned int size ;
	unsigned int *buf = (unsigned int *)sceGuBeginPacket( &size ) ;
	bool res = sceGimPictureActivateEx( picture, &buf, &size, SCEGIM_ACTIVATE_TEXTURE ) ;
	sceGuEndPacket( buf ) ;
	return res ;
}

bool sceGimPictureActivateRenderState( SceGimPicture *picture )
{
	unsigned int size ;
	unsigned int *buf = (unsigned int *)sceGuBeginPacket( &size ) ;
	bool res = sceGimPictureActivateEx( picture, &buf, &size, SCEGIM_ACTIVATE_RENDERSTATE ) ;
	sceGuEndPacket( buf ) ;
	return res ;
}
