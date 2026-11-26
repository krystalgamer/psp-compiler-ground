#include "common.h"
#include "gim_picture_sdk.h"

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureCreate);

void sceGimPictureDelete( SceGimPicture *picture )
{
 if ( picture == 0 ) return ;
 if ( -- picture->m_reference == 0 ) {
  sceGimPictureUnload( picture ) ;
  sceGimPictureFreeMemory( picture ) ;
 }
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureDuplicate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureLoadFile);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureLoad);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureUnload);

void sceGimPictureSetEnableBits( SceGimPicture *picture, int bits, int value )
{
 if ( picture == 0 ) return ;
 picture->m_enable_bits &= ~bits ;
 picture->m_enable_bits |= ( bits & value ) ;
}

int sceGimPictureGetEnableBits( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_enable_bits ;
}

void sceGimPictureSetImageCrop( SceGimPicture *picture, const float *crop )
{
 if ( picture == 0 ) return ;
 if ( crop == 0 ) {
  picture->m_flags &= ~IS_CROPPED ;
 } else {
  memcpy( picture->m_image_crop, crop, sizeof( float ) * 4 ) ;
  picture->m_flags |= IS_CROPPED ;
 }
}

const float *sceGimPictureGetImageCrop( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 if ( !( picture->m_flags & IS_CROPPED ) ) return 0 ;
 return picture->m_image_crop ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureGetImage);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureGetPalette);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureGetImagePixels);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureGetPalettePixels);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureSetImagePixels);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureSetPalettePixels);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureReallocImage);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureReallocPalette);

_Bool sceGimPictureHasAnimation( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return ( ( picture->m_flags & IS_ANIMATED ) != 0 ) ;
}

void sceGimPictureSetFrameLoop( SceGimPicture *picture, float start, float end )
{
 if ( picture == 0 ) return ;
 picture->m_frame_loop[ 0 ] = start ;
 picture->m_frame_loop[ 1 ] = end ;
}

const float *sceGimPictureGetFrameLoop( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_frame_loop ;
}

void sceGimPictureSetFrameRate( SceGimPicture *picture, float fps )
{
 if ( picture == 0 ) return ;
 picture->m_frame_rate = fps ;
}

float sceGimPictureGetFrameRate( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0.0f ;
 return picture->m_frame_rate ;
}

void sceGimPictureSetFrameRepeat( SceGimPicture *picture, int mode )
{
 if ( picture == 0 ) return ;
 if ( mode == SCEGIM_REPEAT_HOLD ) {
  picture->m_flags |= IS_NOREPEAT ;
 } else {
  picture->m_flags &= ~IS_NOREPEAT ;
 }
}

int sceGimPictureGetFrameRepeat( SceGimPicture *picture )
{
 if ( picture == 0 ) return SCEGIM_REPEAT_HOLD ;
 return ( picture->m_flags & IS_NOREPEAT ) ? SCEGIM_REPEAT_HOLD : SCEGIM_REPEAT_CYCLE ;
}

void sceGimPictureSetFrame( SceGimPicture *picture, float frame )
{
 if ( picture == 0 ) return ;
 picture->m_frame = frame ;
}

float sceGimPictureGetFrame( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0.0f ;
 return picture->m_frame ;
}

void sceGimPictureSetImageFrame( SceGimPicture *picture, int frame )
{
 if ( picture == 0 ) return ;
 picture->m_image_frame = frame ;
}

int sceGimPictureGetImageFrame( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_image_frame ;
}

void sceGimPictureSetImageFrame2( SceGimPicture *picture, int frame )
{
 if ( picture == 0 ) return ;
 picture->m_image_frame2 = frame ;
}

int sceGimPictureGetImageFrame2( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_image_frame2 ;
}

void sceGimPictureSetPaletteFrame( SceGimPicture *picture, int frame )
{
 if ( picture == 0 ) return ;
 picture->m_palette_frame = frame ;
}

int sceGimPictureGetPaletteFrame( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_palette_frame ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureSetPaletteFrame2);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureGetPaletteFrame2);

void sceGimPictureSetDissolve( SceGimPicture *picture, float dissolve )
{
 if ( picture == 0 ) return ;
 picture->m_dissolve = dissolve ;
}

float sceGimPictureGetDissolve( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0.0f ;
 return picture->m_dissolve ;
}

int sceGimPictureGetSequenceCount( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_n_sequences ;
}

SceGimSequenceHeader *sceGimPictureGetSequence( SceGimPicture *picture, int idx )
{
 if ( picture == 0 ) return 0 ;
 if ( idx < 0 || idx >= picture->m_n_sequences ) return 0 ;
 return picture->m_sequences[ idx ] ;
}

void sceGimPictureSetCurrentSequence( SceGimPicture *picture, int idx )
{
 if ( picture == 0 ) return ;
 picture->m_current_sequence = idx ;
 picture->m_frame = 0.0f ;
 if ( idx < 0 || idx >= picture->m_n_sequences ) return ;
 SceGimSequenceHeader *sequence = picture->m_sequences[ idx ] ;
 sceGimPictureSetFrameLoop( picture, sequence->frame_start, sequence->frame_end ) ;
 sceGimPictureSetFrameRate( picture, sequence->frame_rate ) ;
 sceGimPictureSetFrameRepeat( picture, sequence->frame_repeat ) ;
 SceGimConstant *cp = (SceGimConstant *)( (char *)sequence + sequence->constants ) ;
 { int i ; for ( i = 0 ; i < sequence->n_constants ; i ++ ) {
  sceGimPictureControl( picture, cp->param, (float)cp->value ) ;
  cp ++ ;
 } }
}

int sceGimPictureGetCurrentSequence( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_current_sequence ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureGetImagePlaneCount);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureSetImagePlane);

int sceGimPictureGetImagePlane( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_image_plane ;
}

void sceGimPictureSetPaletteOffset( SceGimPicture *picture, int shift, int mask, int offs )
{
 if ( picture == 0 ) return ;
 picture->m_palette_offset[ 0 ] = shift ;
 picture->m_palette_offset[ 1 ] = mask ;
 picture->m_palette_offset[ 2 ] = offs ;
}

const int *sceGimPictureGetPaletteOffset( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_palette_offset ;
}

void sceGimPictureSetBlend( SceGimPicture *picture, int mode )
{
 if ( picture == 0 ) return ;
 picture->m_blend[ 0 ] = mode ;
}

const int *sceGimPictureGetBlend( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_blend ;
}

void sceGimPictureSetFunc( SceGimPicture *picture, int mode, int comp )
{
 if ( picture == 0 ) return ;
 picture->m_func[ 0 ] = mode ;
 picture->m_func[ 1 ] = comp ;
}

const int *sceGimPictureGetFunc( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_func ;
}

void sceGimPictureSetFilter( SceGimPicture *picture, int mag, int min )
{
 if ( picture == 0 ) return ;
 picture->m_filter[ 0 ] = mag ;
 picture->m_filter[ 1 ] = min ;
}

const int *sceGimPictureGetFilter( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_filter ;
}

void sceGimPictureSetWrap( SceGimPicture *picture, int u, int v )
{
 if ( picture == 0 ) return ;
 picture->m_wrap[ 0 ] = u ;
 picture->m_wrap[ 1 ] = v ;
}

const int *sceGimPictureGetWrap( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_wrap ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", reconfigure_picture);

