#include "common.h"
#include "gim_picture_sdk.h"

SceGimPicture *sceGimPictureCreate( const SceGimChunk *chunk )
{
	SceGimPicture *picture = (SceGimPicture *)sceGimPictureAllocMemory( sizeof( SceGimPicture ) ) ;
	if ( picture == 0 ) {
		return 0 ;
	}
	picture->m_reference = 1 ;
	picture->m_flags = 0 ;
	picture->m_enable_bits = 0 ;
	picture->m_unk0C = 0 ;
	picture->m_image = 0 ;
	picture->m_palette = 0 ;

	picture->m_buf_width = 0 ;
	picture->m_clut_load = 0 ;
	picture->m_image_crop[ 0 ] = 0.0f ;
	picture->m_image_crop[ 1 ] = 0.0f ;
	picture->m_image_crop[ 2 ] = 1.0f ;
	picture->m_image_crop[ 3 ] = 1.0f ;

	picture->m_frame_loop[ 0 ] = -1000000.0f ;
	picture->m_frame_loop[ 1 ] = 1000000.0f ;
	picture->m_frame_rate = 12.0f ;
	picture->m_frame = 0.0f ;
	picture->m_dissolve = 0.0f ;
	picture->m_image_frame = 0 ;
	picture->m_image_frame2 = 0 ;
	picture->m_palette_frame = 0 ;
	picture->m_palette_frame2 = 0 ;

	picture->m_sequences = 0 ;
	picture->m_n_sequences = 0 ;
	picture->m_current_sequence = -1 ;

	picture->m_image_plane = 0 ;
	picture->m_palette_offset[ 0 ] = 0 ;
	picture->m_palette_offset[ 1 ] = 255 ;
	picture->m_palette_offset[ 2 ] = 0 ;

	picture->m_blend[ 0 ] = 1 ;
	picture->m_func[ 0 ] = 0 ;
	picture->m_func[ 1 ] = 1 ;
	picture->m_filter[ 0 ] = 1 ;
	picture->m_filter[ 1 ] = 7 ;
	picture->m_wrap[ 0 ] = 0 ;
	picture->m_wrap[ 1 ] = 0 ;

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

	if ( flags & 0x0002 ) {
		flags &= ~0x0002 ;
		if ( sceGimPictureHasAnimation( picture ) ) {
			flags |= 0x0001 ;
		}
	}
	if ( flags == 0 ) {
		picture->m_reference ++ ;
		return picture ;
	}

	SceGimPicture *picture2 = sceGimPictureCreate( 0 ) ;
	if ( picture2 == 0 ) return 0 ;

	*picture2 = *picture ;
	picture2->m_reference = 1 ;
	picture2->m_unk0C = 0 ;
	if ( picture2->m_image != 0 ) picture2->m_image->reference ++ ;
	if ( picture2->m_palette != 0 ) picture2->m_palette->reference ++ ;

	if ( picture2->m_n_sequences > 0 ) {
		int size = sizeof( void * ) * picture2->m_n_sequences ;
		picture2->m_sequences = (SceGimSequenceHeader **)sceGimPictureAllocMemory( size ) ;
		if ( picture2->m_sequences == 0 ) {
			picture2->m_n_sequences = 0 ;
			sceGimPictureDelete( picture2 ) ;
			return 0 ;
		}
		{ int i ; for ( i = 0 ; i < picture2->m_n_sequences ; i ++ ) {
			picture2->m_sequences[ i ] = picture->m_sequences[ i ] ;
			picture2->m_sequences[ i ]->reference ++ ;
		} }
	}

	return picture2 ;
}

_Bool sceGimPictureLoadFile( SceGimPicture *picture, const void *buf, int size, int idx )
{
	if ( picture == 0 ) return 0 ;
	if ( buf == 0 || size < 4 ) return 0 ;

	int signature = *(int *)buf ;
	if ( signature == 0x2e47494d ) {
		if ( !sceGimPictureCheckFileHeader( buf, size ) ) return 0 ;
		SceGimChunk *chunk = sceGimPictureGetChunk( buf, size, idx ) ;
		if ( chunk == 0 ) {
			return 0 ;
		}
		return sceGimPictureLoad( picture, chunk ) ;
	} else if ( signature == 0x324d4954 ) {
		return sceGimPictureLoadTm2( picture, buf, size, idx ) ;
	} else if ( ( 0xffff & signature ) == 0x4d42 ) {
		return sceGimPictureLoadBmp( picture, buf, size ) ;
	} else {
		return sceGimPictureLoadTga( picture, buf, size ) ;
	}
	return 0 ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_picture", sceGimPictureLoad);

void sceGimPictureUnload( SceGimPicture *picture )
{
	if ( picture == 0 ) return ;

	sceGimPictureUnloadCache( picture ) ;

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

	{ int i ; for ( i = 0 ; i < picture->m_n_sequences ; i ++ ) {
		SceGimSequenceHeader *sequence = picture->m_sequences[ i ] ;
		if ( -- sequence->reference == 0 ) sceGimPictureFreeMemory( sequence ) ;
	} }
	sceGimPictureFreeMemory( picture->m_sequences ) ;
	picture->m_sequences = 0 ;
	picture->m_n_sequences = 0 ;
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

void *sceGimPictureGetImagePixels( SceGimPicture *picture, int level, int frame )
{
	if ( picture == 0 ) return 0 ;
	SceGimImageHeader *image = picture->m_image ;
	if ( image == 0 ) return 0 ;
	int n_levels = image->level_count ;
	int n_frames = image->frame_count ;
	if ( level < 0 || level >= n_levels ) return 0 ;
	frame %= n_frames ;
	if ( frame < 0 ) frame += n_frames ;
	void **offsets = (void **)( (char *)image + image->offsets ) ;
	return offsets[ n_levels * frame + level ] ;
}

void *sceGimPictureGetPalettePixels( SceGimPicture *picture, int level, int frame )
{
	if ( picture == 0 ) return 0 ;
	SceGimPaletteHeader *palette = picture->m_palette ;
	if ( palette == 0 ) return 0 ;
	int n_levels = palette->level_count ;
	int n_frames = palette->frame_count ;
	if ( level < 0 || level >= n_levels ) return 0 ;
	frame %= n_frames ;
	if ( frame < 0 ) frame += n_frames ;
	void **offsets = (void **)( (char *)palette + palette->offsets ) ;
	return offsets[ n_levels * frame + level ] ;
}

void sceGimPictureSetImagePixels( SceGimPicture *picture, int level, int frame, void *pixels )
{
	if ( picture == 0 ) return ;
	if ( pixels == 0 ) return ;
	SceGimImageHeader *image = picture->m_image ;
	if ( image == 0 ) return ;
	int n_levels = image->level_count ;
	int n_frames = image->frame_count ;
	if ( level < 0 || level >= n_levels ) return ;
	frame %= n_frames ;
	if ( frame < 0 ) frame += n_frames ;
	void **offsets = (void **)( (char *)image + image->offsets ) ;
	offsets[ n_levels * frame + level ] = pixels ;
}

void sceGimPictureSetPalettePixels( SceGimPicture *picture, int level, int frame, void *pixels )
{
	if ( picture == 0 ) return ;
	if ( pixels == 0 ) return ;
	SceGimPaletteHeader *palette = picture->m_palette ;
	if ( palette == 0 ) return ;
	int n_levels = palette->level_count ;
	int n_frames = palette->frame_count ;
	if ( level < 0 || level >= n_levels ) return ;
	frame %= n_frames ;
	if ( frame < 0 ) frame += n_frames ;
	void **offsets = (void **)( (char *)palette + palette->offsets ) ;
	offsets[ n_levels * frame + level ] = pixels ;
}

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

void sceGimPictureSetPaletteFrame2( SceGimPicture *picture, int frame )
{
	{if ( picture == 0 ) {return ;}}
	picture->m_palette_frame = frame ;
}

int sceGimPictureGetPaletteFrame2( SceGimPicture *picture )
{
	{if ( picture == 0 ) {return 0 ;}}
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

int sceGimPictureGetImagePlaneCount( SceGimPicture *picture )
{
	if ( picture == 0 ) return 0 ;
	SceGimImageHeader *image = picture->m_image ;
	if ( image == 0 ) return 0 ;
	unsigned int mask = image->plane_mask ;
	if ( mask == 0 ) return 0 ;
	mask ^= mask >> 1 ;
	mask = ( mask & 0x55555555 ) + ( mask >> 1 & 0x55555555 ) ;
	mask = ( mask & 0x33333333 ) + ( mask >> 2 & 0x33333333 ) ;
	mask = ( mask + ( mask >> 4 ) ) & 0x0f0f0f0f ;
	mask += mask >> 8 ;
	mask += mask >> 16 ;
	return mask & 0xff ;
}

void sceGimPictureSetImagePlane( SceGimPicture *picture, int plane )
{
	if ( picture == 0 ) return ;
	picture->m_image_plane = plane ;

	SceGimImageHeader *image = picture->m_image ;
	if ( image == 0 ) return ;
	unsigned int mask = image->plane_mask ;
	if ( mask == 0 ) {
		sceGimPictureSetPaletteOffset( picture, 0, 255, 0 ) ;
		return ;
	}
	mask ^= mask >> 1 ;
	unsigned int bits = 1 ;
	while ( -- plane >= 0 ) bits += ( mask - bits ) ^ mask ;
	bits = ( mask - bits ) ^ mask ;
	int shift = sceGimPictureCTZ( bits ) ;
	sceGimPictureSetPaletteOffset( picture, shift, bits >> shift, 0 ) ;
}

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

static void reconfigure_picture( SceGimPicture *picture )
{
	picture->m_flags = 0 ;

	SceGimImageHeader *image = picture->m_image ;
	if ( image != 0 ) {
		if ( image->level_count > 1 ) picture->m_flags |= 0x0001 ;
		if ( image->frame_count > 1 ) picture->m_flags |= 0x0002 ;
		int w = image->width ;
		int h = image->height ;
		int w2 = sceGimPicturePow2( w ) ;
		int h2 = sceGimPicturePow2( h ) ;
		if ( w != w2 || h != h2 ) {
			picture->m_flags |= ( 0x0040 | 0x0020 ) ;
			picture->m_image_crop[ 0 ] = 0.0f ;
			picture->m_image_crop[ 1 ] = 0.0f ;
			picture->m_image_crop[ 2 ] = (float)image->width / w2 ;
			picture->m_image_crop[ 3 ] = (float)image->height / h2 ;
		}
		int align = image->pitch_align * 8 / image->bpp - 1 ;
		picture->m_buf_width = ( w + align ) & ~align ;
	}

	SceGimPaletteHeader *palette = picture->m_palette ;
	if ( palette != 0 ) {
		if ( palette->level_count > 1 ) picture->m_flags |= 0x0004 ;
		if ( palette->frame_count > 1 ) picture->m_flags |= 0x0008 ;
		int count = ( palette->width / 16 ) * palette->level_count ;
		if ( palette->format == 3 ) count *= 2 ;
		if ( count > 32 ) count = 32 ;
		picture->m_clut_load = count ;
	}

	if ( picture->m_flags & ( 0x0002 | 0x0008 ) ) {
		picture->m_flags |= 0x0010 ;
	} else {
		{ int i ; for ( i = 0 ; i < picture->m_n_sequences ; i ++ ) {
			SceGimSequenceHeader *sequence = picture->m_sequences[ i ] ;
			if ( sequence->n_functions > 0 ) {
				picture->m_flags |= 0x0010 ;
				break ;
			}
		} }
	}

	sceGimPictureSetImagePlane( picture, picture->m_image_plane ) ;
}

