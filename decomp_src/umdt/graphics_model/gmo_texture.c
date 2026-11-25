/* SDK gmo_model library: devkit 0.6.0's src/gmo_model/gmo_texture.c, preprocessed (macros expanded) */
#include "gmo_private.h"

SceGmoTexture *sceGmoTextureCreate( SceGmoChunk *chunk )
{
 SceGmoTexture *texture = (SceGmoTexture *)sceGmoModelAllocMemory( sizeof( SceGmoTexture ) ) ;
 if ( texture == 0 ) {
  ;
  return 0 ;
 }
 sceGmoBaseConstruct( &( texture->m_base ) ) ;
 texture->m_picture = 0 ;
 texture->m_reference = 1 ;
 texture->m_flags = 0 ;

 if ( chunk != 0 && !sceGmoTextureLoad( texture, chunk ) ) {
  sceGmoTextureDelete( texture ) ;
  return 0 ;
 }
 return texture ;
}

void sceGmoTextureDelete( SceGmoTexture *texture )
{
 if ( texture == 0 ) return ;
 if ( -- texture->m_reference == 0 ) {
  sceGmoTextureUnload( texture ) ;
  sceGmoBaseDestruct( &( texture->m_base ) ) ;
  sceGmoModelFreeMemory( texture ) ;
 }
}

SceGmoTexture *sceGmoTextureDuplicate( SceGmoTexture *texture, int flags )
{

 if ( texture == 0 ) return 0 ;
 if ( flags & SCEGMO_DUPLICATE_AUTOMATIC ) {
  if ( sceGmoTextureHasAnimation( texture ) ) {
   flags |= SCEGMO_DUPLICATE_STRUCTURE ;
  }
 }
 if ( !( SCEGMO_DUPLICATE_STRUCTURE & flags )
   && !( SCEGMO_DUPLICATE_TEXTURE & flags ) ) {
  texture->m_reference ++ ;
  return texture ;
 }

 SceGmoTexture *texture2 = sceGmoTextureCreate( 0 ) ;
 if ( texture2 == 0 ) return 0 ;
 sceGmoBaseCopy( &( texture2->m_base ), &( texture->m_base ) ) ;

 SceGimPicture *src = texture->m_picture ;
 SceGimPicture *dst = sceGimPictureDuplicate( src, SCEGIM_DUPLICATE_AUTOMATIC ) ;
 if ( dst == 0 && src != 0 ) {
  sceGmoTextureDelete( texture2 ) ;
  return 0 ;
 }
 texture2->m_picture = dst ;

 texture2->m_flags = texture->m_flags ;
 return texture2 ;
}

_Bool sceGmoTextureLoad( SceGmoTexture *texture, SceGmoChunk *chunk )
{
 if ( texture == 0 ) return 0 ;
 if ( chunk == 0 ) return 0 ;

 sceGmoTextureUnload( texture ) ;

 char *filename = 0 ;
 void *fileimage = 0 ;
 int filesize = 0 ;

 SceGmoChunk *end = SCEGMO_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGMO_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGMO_CHUNK_NEXT( chunk ) ) {
  void *args = SCEGMO_CHUNK_ARGS( chunk ) ;

  switch ( SCEGMO_CHUNK_TYPE( chunk ) ) {
      case SCEGMO_FILE_NAME : {
   SceGmoFileName *cmd = (SceGmoFileName *)args ;
   filename = cmd->name ;
   break ;
      }
      case SCEGMO_FILE_IMAGE : {
   SceGmoFileImage *cmd = (SceGmoFileImage *)args ;
   fileimage = cmd->data ;
   filesize = cmd->size ;
   break ;
      }
  }
 }

 if ( fileimage != 0 ) {
  SceGimPicture *picture = sceGimPictureCreate( 0 ) ;
  if ( !sceGimPictureLoadFile( picture, fileimage, filesize, 0 ) ) {
   sceGimPictureDelete( picture ) ;
  } else {
   texture->m_picture = picture ;
   sceGmoModelExportPicture( filename, picture ) ;
  }
 }
 if ( texture->m_picture == 0 ) {
  SceGimPicture *picture = sceGmoModelImportPicture( filename ) ;
  texture->m_picture = sceGimPictureDuplicate( picture, SCEGIM_DUPLICATE_AUTOMATIC ) ;
 }
 return 1 ;
}

void sceGmoTextureUnload( SceGmoTexture *texture )
{
 if ( texture == 0 ) return ;
 sceGimPictureDelete( texture->m_picture ) ;
 texture->m_picture = 0 ;
}

void sceGmoTextureUpdate( SceGmoTexture *texture, SceGmoModel *model, float step )
{
 if ( texture == 0 ) return ;
 sceGimPictureAnimate( texture->m_picture, step ) ;
}

void sceGmoTextureActivate( SceGmoTexture *texture, SceGmoModel *model )
{
 if ( texture == 0 ) return ;
 SceGimPicture *picture = texture->m_picture ;
 sceGimPictureActivate( picture ) ;
 sceGmoContextSetTexTrim( (rect *)sceGimPictureGetImageCrop( picture ) ) ;
}

void sceGmoTextureSetParent( SceGmoTexture *texture, SceGmoModel *parent )
{
 if ( texture == 0 ) return ;
 sceGmoBaseSetParent( &( texture->m_base ), (SceGmoSubject *)parent ) ;
}

SceGmoModel *sceGmoTextureGetParent( SceGmoTexture *texture )
{
 if ( texture == 0 ) return 0 ;
 return (SceGmoModel *)sceGmoBaseGetParent( &( texture->m_base ) ) ;
}

void sceGmoTextureSetPicture( SceGmoTexture *texture, SceGimPicture *picture, int flags )
{
 if ( texture == 0 ) return ;
 if ( picture == texture->m_picture ) return ;
 sceGimPictureDelete( texture->m_picture ) ;
 texture->m_picture = sceGimPictureDuplicate( picture, flags ) ;
}

SceGimPicture *sceGmoTextureGetPicture( SceGmoTexture *texture )
{
 if ( texture == 0 ) return 0 ;
 return texture->m_picture ;
}

_Bool sceGmoTextureHasAnimation( SceGmoTexture *texture )
{
 if ( texture == 0 ) return 0 ;
 return sceGimPictureHasAnimation( texture->m_picture ) ;
}
