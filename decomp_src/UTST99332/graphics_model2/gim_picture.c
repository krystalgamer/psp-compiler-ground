/* SDK gim_picture library: devkit 0.6.0's src/gim_picture/gim_picture.c, preprocessed (macros expanded);
   reconfigure_picture, sceGimPictureActivate and the pixel accessors are the newer revision (clz, pitch_align) */
#include "gim_private.h"

static const char __psp_libinfo__[24] __attribute__((used)) = "Lib-PSP libgim_pictu....";

extern char D_00020194[]; /* Bpps (sceGimPictureReallocImage) */
extern char D_0002019C[]; /* Bpps (sceGimPictureReallocPalette) */
static void reconfigure_picture( SceGimPicture *picture ) ;

enum {
 HAS_IMAGE_LEVELS = SCEGIM_PICTURE_HAS_IMAGE_LEVELS,
 HAS_IMAGE_FRAMES = SCEGIM_PICTURE_HAS_IMAGE_FRAMES,
 HAS_PALETTE_LEVELS = SCEGIM_PICTURE_HAS_PALETTE_LEVELS,
 HAS_PALETTE_FRAMES = SCEGIM_PICTURE_HAS_PALETTE_FRAMES,

 HAS_ANIMATION = SCEGIM_PICTURE_HAS_ANIMATION,
 HAS_CROPPING = SCEGIM_PICTURE_HAS_CROPPING,
 HAS_NONPOW2 = SCEGIM_PICTURE_HAS_NONPOW2,
} ;

enum {
 TM2_FORMAT_SIGNATURE = 0x324d4954,
 BMP_FORMAT_SIGNATURE = 0x4d42
} ;

SceGimPicture *sceGimPictureCreate( SceGimChunk *chunk )
{
 SceGimPicture *picture = (SceGimPicture *)sceGimPictureAllocMemory( sizeof( SceGimPicture ) ) ;
 if ( picture == 0 ) {
  ;
  return 0 ;
 }
 picture->m_reference = 1 ;
 picture->m_flags = 0 ;
 picture->m_image = 0 ;
 picture->m_palette = 0 ;
 picture->m_sequence = 0 ;
 picture->m_buf_width = 0 ;
 picture->m_clut_load = 0 ;
 picture->m_frame_loop[ 0 ] = -1000000.0f ;
 picture->m_frame_loop[ 1 ] = 1000000.0f ;
 picture->m_frame_rate = 12.0f ;
 picture->m_frame = 0.0f ;
 picture->m_enable_bits = 0 ;
 picture->m_image_frame = 0 ;
 picture->m_image_frame2 = 0 ;
 picture->m_palette_frame = 0 ;
 picture->m_palette_frame2 = 0 ;
 picture->m_dissolve = 0.0f ;
 picture->m_image_crop[ 0 ] = 0.0f ;
 picture->m_image_crop[ 1 ] = 0.0f ;
 picture->m_image_crop[ 2 ] = 1.0f ;
 picture->m_image_crop[ 3 ] = 1.0f ;

 if ( chunk != 0 && !sceGimPictureLoad( picture, chunk ) ) {
  sceGimPictureDelete( picture ) ;
  return 0 ;
 }
 return picture ;
}

void sceGimPictureDelete( SceGimPicture *picture )
{
 if ( picture == 0 ) return ;
 if ( -- picture->m_reference == 0 ) {
  sceGimPictureUnload( picture ) ;
  sceGimPictureFreeMemory( picture ) ;
 }
}

SceGimPicture *sceGimPictureDuplicate( SceGimPicture *picture, int flags )
{
 if ( picture == 0 ) return 0 ;

 if ( flags & SCEGIM_DUPLICATE_AUTOMATIC ) {
  flags &= ~SCEGIM_DUPLICATE_AUTOMATIC ;
  if ( sceGimPictureHasAnimation( picture ) ) {
   flags |= SCEGIM_DUPLICATE_STRUCTURE ;
  }
 }
 if ( flags == SCEGIM_DUPLICATE_REFERENCE ) {
  picture->m_reference ++ ;
  return picture ;
 }

 SceGimPicture *picture2 = sceGimPictureCreate( 0 ) ;
 if ( picture2 == 0 ) return 0 ;
 SceGimImageHeader *image = picture->m_image ;
 SceGimPaletteHeader *palette = picture->m_palette ;
 SceGimSequenceHeader *sequence = picture->m_sequence ;
 if ( image != 0 ) image->reference ++ ;
 if ( palette != 0 ) palette->reference ++ ;
 if ( sequence != 0 ) sequence->reference ++ ;
 picture2->m_flags = picture->m_flags ;
 picture2->m_image = image ;
 picture2->m_palette = palette ;
 picture2->m_sequence = sequence ;
 picture2->m_buf_width = picture->m_buf_width ;
 picture2->m_clut_load = picture->m_clut_load ;
 picture2->m_frame_loop[ 0 ] = picture->m_frame_loop[ 0 ] ;
 picture2->m_frame_loop[ 1 ] = picture->m_frame_loop[ 1 ] ;
 picture2->m_frame_rate = picture->m_frame_rate ;
 picture2->m_frame = picture->m_frame ;
 picture2->m_enable_bits = picture->m_enable_bits ;
 picture2->m_image_frame = picture->m_image_frame ;
 picture2->m_image_frame2 = picture->m_image_frame2 ;
 picture2->m_palette_frame = picture->m_palette_frame ;
 picture2->m_palette_frame2 = picture->m_palette_frame2 ;
 picture2->m_dissolve = picture->m_dissolve ;
 memcpy( picture2->m_image_crop, picture->m_image_crop, sizeof( picture->m_image_crop ) ) ;
 return picture2 ;
}

_Bool sceGimPictureLoadFile( SceGimPicture *picture, const void *buf, int size, int index )
{
 if ( picture == 0 ) return 0 ;
 if ( buf == 0 || size < 4 ) return 0 ;

 int signature = *(int *)buf ;
 if ( signature == (0x2e47494d) ) {
  if ( !sceGimPictureCheckFileHeader( buf, size ) ) return 0 ;
  SceGimChunk *chunk = sceGimPictureGetChunk( buf, size, index ) ;
  if ( chunk == 0 ) {
   ;
   return 0 ;
  }
  ;
  return sceGimPictureLoad( picture, chunk ) ;

 } else if ( signature == TM2_FORMAT_SIGNATURE ) {
  return sceGimPictureLoadTm2( picture, buf, size, index ) ;

 } else if ( ( 0xffff & signature ) == BMP_FORMAT_SIGNATURE ) {
  if ( index != 0 ) return 0 ;
  return sceGimPictureLoadBmp( picture, buf, size ) ;

 } else {
  if ( index != 0 ) return 0 ;
  return sceGimPictureLoadTga( picture, buf, size ) ;
 }
}

_Bool sceGimPictureLoad( SceGimPicture *picture, SceGimChunk *chunk )
{
 if ( picture == 0 ) return 0 ;
 if ( chunk == 0 ) return 0 ;

 sceGimPictureUnload( picture ) ;

 SceGimChunk *end = SCEGIM_CHUNK_NEXT( chunk ) ;
 for ( chunk = SCEGIM_CHUNK_CHILD( chunk ) ; chunk < end ; chunk = SCEGIM_CHUNK_NEXT( chunk ) ) {
  void *data = SCEGIM_CHUNK_DATA( chunk ) ;
  int size = SCEGIM_CHUNK_DATA_SIZE( chunk ) ;
  switch ( SCEGIM_CHUNK_TYPE( chunk ) ) {
      case SCEGIM_IMAGE : {
   if ( picture->m_image != 0 ) break ;
   SceGimImageHeader *img = (SceGimImageHeader *)sceGimPictureAllocMemory2( size ) ;
   if ( img == 0 ) {
    ;
    return 0 ;
   }
   picture->m_image = img ;
   memcpy( img, data, size ) ;
   img->reference = 1 ;
   int *offsets = (int *)( (char *)img + img->offsets ) ;
   { int i ; for ( i = img->level_count * img->frame_count ; i > 0 ; -- i ) {
    *( offsets ++ ) += (int)img ;
   } }
   if ( img->width > 512 || img->height > 512 ) {
    ;
    return 0 ;
   }
   break ;
      }
      case SCEGIM_PALETTE : {
   if ( picture->m_palette != 0 ) break ;
   SceGimPaletteHeader *pal = (SceGimPaletteHeader *)sceGimPictureAllocMemory2( size ) ;
   if ( pal == 0 ) {
    ;
    return 0 ;
   }
   picture->m_palette = pal ;
   memcpy( picture->m_palette, data, size ) ;
   pal->reference = 1 ;
   int *offsets = (int *)( (char *)pal + pal->offsets ) ;
   { int i ; for ( i = pal->level_count * pal->frame_count ; i > 0 ; -- i ) {
    *( offsets ++ ) += (int)pal ;
   } }
   if ( pal->width > 256 ) {
    ;
    return 0 ;
   }
   break ;
      }
      case SCEGIM_SEQUENCE : {
   break ;
      }
  }
 }
 reconfigure_picture( picture ) ;
 sceKernelDcacheWritebackAll();
 return 1 ;
}

void sceGimPictureUnload( SceGimPicture *picture )
{
 if ( picture == 0 ) return ;
 SceGimImageHeader *image = picture->m_image ;
 if ( image != 0 ) {
  if ( -- image->reference == 0 ) sceGimPictureFreeMemory2( image ) ;
  picture->m_image = 0 ;
 }
 SceGimPaletteHeader *palette = picture->m_palette ;
 if ( palette != 0 ) {
  if ( -- palette->reference == 0 ) sceGimPictureFreeMemory2( palette ) ;
  picture->m_palette = 0 ;
 }
 SceGimSequenceHeader *sequence = picture->m_sequence ;
 if ( sequence != 0 ) {
  if ( -- sequence->reference == 0 ) sceGimPictureFreeMemory2( sequence ) ;
  picture->m_sequence = 0 ;
 }
}

void sceGimPictureAnimate( SceGimPicture *picture, float step )
{
 if ( picture == 0 ) return ;
 if ( !( picture->m_flags & HAS_ANIMATION ) ) return ;

 float frame = picture->m_frame + picture->m_frame_rate * step ;
 float start = picture->m_frame_loop[ 0 ] ;
 float end = picture->m_frame_loop[ 1 ] ;
 if ( frame >= end && picture->m_frame < end ) {
  frame = start ;
 } else if ( frame < start && picture->m_frame >= start ) {
  frame = end ;
 }
 picture->m_frame = frame ;

 int f = (int)frame ;
 if ( frame < 0.0f ) f -= 1 ;
 picture->m_image_frame = f ;
 picture->m_image_frame2 = f + 1 ;
 picture->m_palette_frame = f ;
 picture->m_palette_frame2 = f + 1 ;
 picture->m_dissolve = frame - (float)f ;
}

void sceGimPictureActivate( SceGimPicture *picture )
{
 if ( picture == 0 ) return ;

 if ( picture->m_flags == 0 ) {
  SceGimImageHeader *image = picture->m_image ;
  if ( image != 0 ) {
   sceGuTexMode( image->format, 0, 0, image->order ) ;
   void **offsets = (void **)( (char *)image + image->offsets ) ;
   sceGuTexImage( 0, image->width, image->height, picture->m_buf_width, *offsets ) ;
  }
  SceGimPaletteHeader *palette = picture->m_palette ;
  if ( palette != 0 ) {
   sceGuClutMode( palette->format, 0, 255, 0 ) ;
   void **offsets = (void **)( (char *)palette + palette->offsets ) ;
   sceGuClutLoad( picture->m_clut_load, *offsets ) ;
  }
  return ;
 }

 SceGimImageHeader *image = picture->m_image ;
 if ( image != 0 ) {
  int w = image->width ;
  int h = image->height ;
  int w2 = 1 << ( 32 - __builtin_allegrex_clz( w - 1 ) ) ;
  int h2 = 1 << ( 32 - __builtin_allegrex_clz( h - 1 ) ) ;
  int align = image->pitch_align * 8 / image->bpp - 1 ;
  int n_frames = image->frame_count ;
  int n_levels = image->level_count ;
  int frame = picture->m_image_frame % n_frames ;

  if ( 0x8000 & frame ) frame = 0x7fff & ( frame + n_frames ) ;
  void **offsets = (void **)( (char *)image + image->offsets ) ;
  if ( !( picture->m_enable_bits & SCEGIM_ENABLE_DISSOLVE ) ) {
   int clut = 0 ;
   if ( picture->m_flags & HAS_PALETTE_LEVELS ) clut = 1 ;
   sceGuTexMode( image->format, n_levels - 1, clut, image->order ) ;
   offsets += frame * n_levels ;
   { int i ; for ( i = 0 ; i < n_levels ; i ++ ) {
    void *buf = *( offsets ++ ) ;
    sceGuTexImage( i, w2, h2, ( w + align ) & ~align, buf ) ;
    if ( image->level_type == SCEGIM_TYPE_MIPMAP ) {
     w = ( w + 1 ) / 2 ;
     w2 = ( w2 + 1 ) / 2 ;
     h2 = ( h2 + 1 ) / 2 ;
    }
   } }
  } else {
   int clut = 0 ;
   if ( picture->m_flags & HAS_PALETTE_FRAMES ) clut = 1 ;
   sceGuTexMode( image->format, 1, clut, image->order ) ;
   w = ( w + align ) & ~align ;
   void *buf = offsets[ frame * n_levels ] ;
   sceGuTexImage( 0, w2, h2, w, buf ) ;
   frame = picture->m_image_frame2 % n_frames ;

   if ( 0x8000 & frame ) frame = 0x7fff & ( frame + n_frames ) ;
   buf = offsets[ frame * n_levels ] ;
   sceGuTexImage( 1, w2, h2, w, buf ) ;
  }
 }
 SceGimPaletteHeader *pal = picture->m_palette ;
 if ( pal != 0 ) {
  sceGuClutMode( pal->format, 0, 255, 0 ) ;
  int n_frames = pal->frame_count ;
  int n_levels = pal->level_count ;
  int frame = picture->m_image_frame % n_frames ;

  if ( 0x8000 & frame ) frame = 0x7fff & ( frame + n_frames ) ;
  void **offsets = (void **)( (char *)pal + pal->offsets ) ;
  if ( !( picture->m_enable_bits & SCEGIM_ENABLE_DISSOLVE ) ) {
   sceGuClutLoad( picture->m_clut_load, offsets[ frame * n_levels ] ) ;
  } else {
   int size = ( pal->format == 3 ) ? 4 : 2 ;
   size *= pal->width ;
   int frame2 = picture->m_palette_frame2 % n_frames ;

   if ( 0x8000 & frame2 ) frame2 = 0x7fff & ( frame2 + n_frames ) ;
   if ( frame2 == frame + 1 && n_levels == 1 ) {
    sceGuClutLoad( size / 16, offsets[ frame * n_levels ] ) ;
   } else {
    sceGuClutLoad( size / 16, (char *)offsets[ frame2 * n_levels ] - size ) ;
    sceGuClutLoad( size / 32, offsets[ frame * n_levels ] ) ;
   }
  }
 }
}

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

SceGimImageHeader *sceGimPictureGetImage( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_image ;
}

SceGimPaletteHeader *sceGimPictureGetPalette( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_palette ;
}

void *sceGimPictureGetImagePixels(SceGimPicture *picture, int level, int frame)
{
	SceGimImageHeader *image;
	int n_levels;
	int n_frames;
	void **offsets;

	if (picture == 0)
		return 0;
	image = picture->m_image;
	if (image == 0)
		return 0;
	n_levels = image->level_count;
	n_frames = image->frame_count;
	if (level < 0 || level >= n_levels)
		return 0;
	frame %= n_frames; if (frame & 0x8000) frame = (frame + n_frames) & 0x7fff;
	offsets = (void **)((char *)image + image->offsets);
	return offsets[n_levels * frame + level];
}

void *sceGimPictureGetPalettePixels(SceGimPicture *picture, int level, int frame)
{
	SceGimPaletteHeader *palette;
	int n_levels;
	int n_frames;
	void **offsets;

	if (picture == 0)
		return 0;
	palette = picture->m_palette;
	if (palette == 0)
		return 0;
	n_levels = palette->level_count;
	n_frames = palette->frame_count;
	if (level < 0 || level >= n_levels)
		return 0;
	frame %= n_frames; if (frame & 0x8000) frame = (frame + n_frames) & 0x7fff;
	offsets = (void **)((char *)palette + palette->offsets);
	return offsets[n_levels * frame + level];
}

void sceGimPictureSetImagePixels(SceGimPicture *picture, int level, int frame, void *pixels)
{
	SceGimImageHeader *image;
	int n_levels;
	int n_frames;
	void **offsets;

	if (picture == 0)
		return;
	if (pixels == 0)
		return;
	image = picture->m_image;
	if (image == 0)
		return;
	n_levels = image->level_count;
	n_frames = image->frame_count;
	if (level < 0 || level >= n_levels)
		return;
	frame %= n_frames; if (frame & 0x8000) frame = (frame + n_frames) & 0x7fff;
	offsets = (void **)((char *)image + image->offsets);
	offsets[n_levels * frame + level] = pixels;
}

void sceGimPictureSetPalettePixels(SceGimPicture *picture, int level, int frame, void *pixels)
{
	SceGimPaletteHeader *palette;
	int n_levels;
	int n_frames;
	void **offsets;

	if (picture == 0)
		return;
	if (pixels == 0)
		return;
	palette = picture->m_palette;
	if (palette == 0)
		return;
	n_levels = palette->level_count;
	n_frames = palette->frame_count;
	if (level < 0 || level >= n_levels)
		return;
	frame %= n_frames; if (frame & 0x8000) frame = (frame + n_frames) & 0x7fff;
	offsets = (void **)((char *)palette + palette->offsets);
	offsets[n_levels * frame + level] = pixels;
}

_Bool sceGimPictureReallocImage( SceGimPicture *picture, int format, int w, int h, int level, int frame, void *pixels )
{
 if ( picture == 0 ) return 0 ;
 if ( w <= 0 || w > 512 ) return 0 ;
 if ( h <= 0 || h > 512 ) return 0 ;
 if ( level <= 0 || level > 8 ) return 0 ;
 if ( frame <= 0 ) return 0 ;

 int size1 = sizeof( SceGimImageHeader ) + level * frame * 4 ;
 size1 = ( size1 + 15 ) & ~15 ;

 int bpp = D_00020194[ 7 & format ] ;
 int level_sizes[ 8 ] ;
 int size2 = 0 ;
 int w2 = w ;
 int h2 = h ;
 { int i ; for ( i = 0 ; i < level ; i ++ ) {
  int level_size = ( ( ( bpp * w2 + 7 ) / 8 + 15 ) & ~15 ) * h2 ;
  level_sizes[ i ] = level_size ;
  size2 += level_size ;
  w2 = ( w2 + 1 ) / 2 ;
  h2 = ( h2 + 1 ) / 2 ;
 } }
 size2 *= frame ;
 if ( pixels != 0 ) size2 = 0 ;

 sceGimPictureFreeMemory2( picture->m_image ) ;
 picture->m_image = (SceGimImageHeader *)sceGimPictureAllocMemory2( size1 + size2 ) ;
 if ( picture->m_image == 0 ) {
  ;
  return 0 ;
 }

 SceGimImageHeader *img = picture->m_image ;
 img->header_size = sizeof( SceGimImageHeader ) ;
 img->reference = 1 ;
 img->format = format ;
 img->order = SCEGIM_ORDER_NORMAL ;
 img->width = w ;
 img->height = h ;
 img->bpp = bpp ;
 img->pitch_align = 16 ;
 img->height_align = 1 ;
 img->dim_count = 2 ;
 img->reserved = 0 ;
 img->reserved2 = 0 ;
 img->offsets = sizeof( SceGimImageHeader ) ;
 img->images = size1 ;
 img->total = size1 + size2 ;
 img->plane_mask = 0 ;
 img->level_type = SCEGIM_TYPE_MIPMAP ;
 img->level_count = level ;
 img->frame_type = SCEGIM_TYPE_SEQUENCE ;
 img->frame_count = frame ;

 char *offset = ( pixels != 0 ) ? (char *)pixels : (char *)img + size1 ;
 int *offsets = (int *)( img + 1 ) ;
 int count = level * frame ;
 { int i ; for ( i = 0 ; i < count ; i ++ ) {
  *( offsets ++ ) = (int)offset ;
  offset += level_sizes[ i % level ] ;
 } }
 reconfigure_picture( picture ) ;
 return 1 ;
}

_Bool sceGimPictureReallocPalette( SceGimPicture *picture, int format, int w, int level, int frame, void *pixels )
{
 if ( picture == 0 ) return 0 ;
 if ( w <= 0 || w > 256 ) return 0 ;
 if ( level <= 0 || level > 8 ) return 0 ;
 if ( frame <= 0 ) return 0 ;

 int size1 = sizeof( SceGimPaletteHeader ) + level * frame * 4 ;
 size1 = ( size1 + 15 ) / 16 * 16 ;

 int bpp = D_0002019C[ 7 & format ] ;
 int level_size = ( ( bpp * w + 7 ) / 8 + 15 ) & ~15 ;
 int size2 = ( pixels != 0 ) ? 0 : level_size * frame ;

 sceGimPictureFreeMemory2( picture->m_palette ) ;
 picture->m_palette = (SceGimPaletteHeader *)sceGimPictureAllocMemory2( size1 + size2 ) ;
 if ( picture->m_palette == 0 ) {
  ;
  return 0 ;
 }

 SceGimPaletteHeader *pal = picture->m_palette ;
 pal->header_size = sizeof( SceGimPaletteHeader ) ;
 pal->reference = 1 ;
 pal->format = format ;
 pal->order = SCEGIM_ORDER_NORMAL ;
 pal->width = w ;
 pal->height = 1 ;
 pal->bpp = bpp ;
 pal->pitch_align = 16 ;
 pal->height_align = 1 ;
 pal->dim_count = 2 ;
 pal->reserved = 0 ;
 pal->reserved2 = 0 ;
 pal->offsets = sizeof( SceGimPaletteHeader ) ;
 pal->images = size1 ;
 pal->total = size1 + size2 ;
 pal->plane_mask = 0 ;
 pal->level_type = SCEGIM_TYPE_MIPMAP2 ;
 pal->level_count = level ;
 pal->frame_type = SCEGIM_TYPE_SEQUENCE ;
 pal->frame_count = frame ;

 char *offset = ( pixels != 0 ) ? (char *)pixels : (char *)pal + size1 ;
 int *offsets = (int *)( pal + 1 ) ;
 int count = level * frame ;
 { int i ; for ( i = 0 ; i < count ; i ++ ) {
  *( offsets ++ ) = (int)offset ;
  offset += level_size ;
 } }
 reconfigure_picture( picture ) ;
 return 1 ;
}

_Bool sceGimPictureHasAnimation( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return ( picture->m_flags & HAS_ANIMATION ) ;
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

void sceGimPictureSetPaletteFrame2( SceGimPicture *picture, int frame )
{
 if ( picture == 0 ) return ;
 picture->m_palette_frame = frame ;
}

int sceGimPictureGetPaletteFrame2( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 return picture->m_palette_frame ;
}

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

void sceGimPictureSetImageCrop( SceGimPicture *picture, const float *crop )
{
 if ( picture == 0 ) return ;
 if ( crop == 0 ) {
  picture->m_flags &= ~HAS_CROPPING ;
 } else {
  memcpy( picture->m_image_crop, crop, sizeof( float ) * 4 ) ;
  picture->m_flags |= HAS_CROPPING ;
 }
}

const float *sceGimPictureGetImageCrop( SceGimPicture *picture )
{
 if ( picture == 0 ) return 0 ;
 if ( !( picture->m_flags & HAS_CROPPING ) ) return 0 ;
 return picture->m_image_crop ;
}

static void reconfigure_picture(SceGimPicture *picture)
{
	SceGimImageHeader *image;
	SceGimPaletteHeader *palette;

	picture->m_flags = 0;
	image = picture->m_image;
	if (image != 0) {
		int w;
		int h;
		int w2;
		int h2;
		int align;

		if (image->level_count >= 2)
			picture->m_flags |= 1;
		if (image->frame_count >= 2)
			picture->m_flags |= 2;
		w = image->width;
		h = image->height;
		w2 = 1 << (32 - __builtin_allegrex_clz(w - 1));
		h2 = 1 << (32 - __builtin_allegrex_clz(h - 1));
		if (w != w2 || h != h2) {
			picture->m_flags |= 0x60;
			picture->m_image_crop[0] = 0.0f;
			picture->m_image_crop[1] = 0.0f;
			picture->m_image_crop[2] = (float)w / (float)w2;
			picture->m_image_crop[3] = (float)h / (float)h2;
		}
		align = image->pitch_align * 8 / image->bpp - 1;
		picture->m_buf_width = (w + align) & ~align;
	}
	palette = picture->m_palette;
	if (palette != 0) {
		int count;

		if (palette->level_count >= 2)
			picture->m_flags |= 4;
		if (palette->frame_count >= 2)
			picture->m_flags |= 8;
		count = palette->width / 16 * palette->level_count;
		if (palette->format == 3)
			count *= 2;
		if (count > 32)
			count = 32;
		picture->m_clut_load = count;
	}
	if (picture->m_flags & 0xa)
		picture->m_flags |= 0x10;
}

