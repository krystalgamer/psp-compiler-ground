#include "common.h"

/* declarations recovered from DWARF (UTST99332 graphics_model gim_picture) */
struct _anon1;
struct _anon1 { /* size 0x10 */
    short unsigned int type;
    short unsigned int unused;
    unsigned int next_offs;
    unsigned int child_offs;
    unsigned int data_offs;
};
typedef struct _anon1 SceGimChunk;
typedef struct SceGimPicture SceGimPicture;
struct SceGimPicture;
struct _anon2;
struct _anon2 { /* size 0x30 */
    short unsigned int header_size;
    short unsigned int reference;
    short unsigned int format;
    short unsigned int order;
    short unsigned int width;
    short unsigned int height;
    short unsigned int bpp;
    short unsigned int pitch_align;
    short unsigned int height_align;
    short unsigned int dim_count;
    short unsigned int reserved;
    short unsigned int reserved2;
    unsigned int offsets;
    unsigned int images;
    unsigned int total;
    unsigned int plane_mask;
    short unsigned int level_type;
    short unsigned int level_count;
    short unsigned int frame_type;
    short unsigned int frame_count;
};
typedef struct _anon2 SceGimImageHeader;
struct _anon3;
struct _anon3 { /* size 0x20 */
    short unsigned int header_size;
    short unsigned int reference;
    short unsigned int frame_start;
    short unsigned int frame_end;
    short unsigned int frame_rate;
    short unsigned int reserved;
    short unsigned int n_constants;
    short unsigned int n_functions;
    unsigned int constants;
    unsigned int functions;
    unsigned int keyframes;
    unsigned int total;
};
typedef struct _anon3 SceGimSequenceHeader;
struct SceGimPicture { /* size 0x8c (gim_picture 1.5.0) */
    int m_reference;
    int m_flags;
    int m_enable_bits;
    void *m_unk0C;
    SceGimImageHeader *m_image;
    SceGimImageHeader *m_palette;
    int m_buf_width;
    int m_clut_load;
    float m_image_crop[4];
    float m_frame_loop[2];
    float m_frame_rate;
    float m_frame;
    float m_dissolve;
    int m_image_frame;
    int m_image_frame2;
    int m_palette_frame;
    int m_palette_frame2;
    SceGimSequenceHeader **m_sequences;
    int m_n_sequences;
    int m_current_sequence;
    int m_image_plane;
    int m_palette_offset[3];
    int m_blend[1];
    int m_func[2];
    int m_filter[2];
    int m_wrap[2];
};
typedef SceGimImageHeader SceGimPaletteHeader;
typedef unsigned int size_t;

extern const unsigned char __psp_libinfo__[24];

SceGimPicture *sceGimPictureCreate(SceGimChunk *chunk);
void sceGimPictureDelete(SceGimPicture *picture);
SceGimPicture *sceGimPictureDuplicate(SceGimPicture *picture, int flags);
_Bool sceGimPictureLoadFile(SceGimPicture *picture, const void *buf, int size, int idx);
_Bool sceGimPictureLoad(SceGimPicture *picture, const SceGimChunk *chunk);
static SceGimChunk *SCEGIM_CHUNK_NEXT(SceGimChunk *chunk);
static SceGimChunk *SCEGIM_CHUNK_CHILD(SceGimChunk *chunk);
static void *SCEGIM_CHUNK_DATA(SceGimChunk *chunk);
static int SCEGIM_CHUNK_DATA_SIZE(SceGimChunk *chunk);
void sceGimPictureUnload(SceGimPicture *picture);
void sceGimPictureAnimate(SceGimPicture *picture, float step);
void sceGimPictureActivate(SceGimPicture *picture);
static int pow2(int n);
void sceGimPictureSetEnableBits(SceGimPicture *picture, int bits, int value);
int sceGimPictureGetEnableBits(SceGimPicture *picture);
SceGimImageHeader *sceGimPictureGetImage(SceGimPicture *picture);
SceGimPaletteHeader *sceGimPictureGetPalette(SceGimPicture *picture);
void *sceGimPictureGetImagePixels(SceGimPicture *picture, int level, int frame);
void *sceGimPictureGetPalettePixels(SceGimPicture *picture, int level, int frame);
void sceGimPictureSetImagePixels(SceGimPicture *picture, int level, int frame, void *pixels);
void sceGimPictureSetPalettePixels(SceGimPicture *picture, int level, int frame, void *pixels);
_Bool sceGimPictureReallocImage(SceGimPicture *picture, int format, int w, int h, int level, int frame, void *pixels);
_Bool sceGimPictureReallocPalette(SceGimPicture *picture, int format, int w, int level, int frame, void *pixels);
_Bool sceGimPictureHasAnimation(SceGimPicture *picture);
void sceGimPictureSetFrameLoop(SceGimPicture *picture, float start, float end);
const float *sceGimPictureGetFrameLoop(SceGimPicture *picture);
void sceGimPictureSetFrameRate(SceGimPicture *picture, float fps);
float sceGimPictureGetFrameRate(SceGimPicture *picture);
void sceGimPictureSetFrame(SceGimPicture *picture, float frame);
float sceGimPictureGetFrame(SceGimPicture *picture);
void sceGimPictureSetImageFrame(SceGimPicture *picture, int frame);
int sceGimPictureGetImageFrame(SceGimPicture *picture);
void sceGimPictureSetImageFrame2(SceGimPicture *picture, int frame);
int sceGimPictureGetImageFrame2(SceGimPicture *picture);
void sceGimPictureSetPaletteFrame(SceGimPicture *picture, int frame);
int sceGimPictureGetPaletteFrame(SceGimPicture *picture);
void sceGimPictureSetPaletteFrame2(SceGimPicture *picture, int frame);
int sceGimPictureGetPaletteFrame2(SceGimPicture *picture);
void sceGimPictureSetDissolve(SceGimPicture *picture, float dissolve);
float sceGimPictureGetDissolve(SceGimPicture *picture);
void sceGimPictureSetImageCrop(SceGimPicture *picture, const float *crop);
const float *sceGimPictureGetImageCrop(SceGimPicture *picture);
static void reconfigure_picture(SceGimPicture *picture);

static void eval_fcurve( SceGimPicture *picture, SceGimSequenceHeader *sequence, int index, float frame ) ;
void sceGimPictureAnimate( SceGimPicture *picture, float step )
{
	if ( picture == 0 ) return ;
	if ( !( picture->m_flags & 0x0010 ) ) return ;

	float frame0 = picture->m_frame ;
	float frame = frame0 + picture->m_frame_rate * step ;
	float start = picture->m_frame_loop[ 0 ] ;
	float end = picture->m_frame_loop[ 1 ] ;
	if ( frame >= end && frame0 < end ) {
		frame = ( picture->m_flags & 0x0080 ) ? end : start ;
	} else if ( frame < start && frame0 >= start ) {
		frame = ( picture->m_flags & 0x0080 ) ? start : end ;
	}
	picture->m_frame = frame ;

	int idx = picture->m_current_sequence ;
	if ( idx >= 0 && idx < picture->m_n_sequences ) {
		SceGimSequenceHeader *sequence = picture->m_sequences[ idx ] ;
		{ int i ; for ( i = 0 ; i < sequence->n_functions ; i ++ ) {
			eval_fcurve( picture, sequence, i, frame ) ;
		} }
		return ;
	}

	int f = (int)frame ;
	if ( frame < 0.0f ) f -- ;
	picture->m_image_frame = f ;
	picture->m_image_frame2 = f + 1 ;
	picture->m_palette_frame = f ;
	picture->m_palette_frame2 = f + 1 ;
	picture->m_dissolve = frame - (float)f ;
}

void sceGimPictureSetImagePlane( SceGimPicture *picture, int plane ) ;
static __inline__ int sceGimPicturePow2( int n )
{
	return 1 << ( 32 - __builtin_allegrex_clz( n - 1 ) ) ;
}

void sceGimPictureControl( SceGimPicture *picture, int param, float value )
{
	SceGimImageHeader *image = picture->m_image ;
	int ival = (int)value ;
	if ( value < 0.0f ) ival -- ;

	switch ( param ) {
	    case 0x0010 :
		if ( image != 0 ) {
			int pow2 = sceGimPicturePow2( image->width ) ;
			picture->m_image_crop[ 0 ] = value / (float)pow2 ;
			picture->m_flags |= 0x0020 ;
		}
		break ;
	    case 0x0011 :
		if ( image != 0 ) {
			int pow2 = sceGimPicturePow2( image->height ) ;
			picture->m_image_crop[ 1 ] = value / (float)pow2 ;
			picture->m_flags |= 0x0020 ;
		}
		break ;
	    case 0x0012 :
		if ( image != 0 ) {
			int pow2 = sceGimPicturePow2( image->width ) ;
			picture->m_image_crop[ 2 ] = value / (float)pow2 ;
			picture->m_flags |= 0x0020 ;
		}
		break ;
	    case 0x0013 :
		if ( image != 0 ) {
			int pow2 = sceGimPicturePow2( image->height ) ;
			picture->m_image_crop[ 3 ] = value / (float)pow2 ;
			picture->m_flags |= 0x0020 ;
		}
		break ;
	    case 0x0003 :
		picture->m_image_frame = picture->m_image_frame2 = ival ;
		break ;
	    case 0x000b :
		picture->m_palette_frame = picture->m_palette_frame2 = ival ;
		break ;
	    case 0x0001 :
		sceGimPictureSetImagePlane( picture, ival ) ;
		break ;
	    case 0x0020 :
		picture->m_blend[ 0 ] = ival ;
		break ;
	    case 0x0022 :
		picture->m_func[ 0 ] = ival ;
		break ;
	    case 0x0023 :
		picture->m_func[ 1 ] = ival ;
		break ;
	    case 0x0024 :
		picture->m_filter[ 0 ] = ival ;
		break ;
	    case 0x0025 :
		picture->m_filter[ 1 ] = ival ;
		break ;
	    case 0x0026 :
		picture->m_wrap[ 0 ] = ival ;
		break ;
	    case 0x0027 :
		picture->m_wrap[ 1 ] = ival ;
		break ;
	}
}

typedef struct {
	unsigned short param ;
	unsigned short interp ;
	unsigned int keyframes ;
} SceGimFunction ;

static void eval_fcurve( SceGimPicture *picture, SceGimSequenceHeader *sequence, int index, float frame )
{
	SceGimFunction *function = (SceGimFunction *)( (char *)sequence + sequence->functions ) ;
	function += index ;
	short *keyframes = (short *)( (char *)sequence + function->keyframes ) ;
	float f = 0.0f ;
	int value1 = 0 ;
	int value2 = 0 ;

	if ( frame < 0.0f ) frame = 0.0f ;
	int left = (int)frame ;
	for ( ; ; ) {
		int count = *( keyframes ++ ) ;
		if ( count == 0 ) {
			value1 = value2 = keyframes[ 0 ] ;
			break ;
		}
		if ( count > 0 ) {
			if ( count > left ) {
				f = frame / (float)count ;
				value1 = keyframes[ 0 ] ;
				value2 = keyframes[ 2 ] ;
				break ;
			}
			keyframes ++ ;
		} else {
			count = -count ;
			if ( count > left ) {
				f = frame - (float)left ;
				value1 = keyframes[ left ] ;
				if ( ++ left == count ) ++ left ;
				value2 = keyframes[ left ] ;
				break ;
			}
			keyframes += count ;
		}
		left -= count ;
		frame -= (float)count ;
	}

	int param = function->param ;
	int interp = function->interp ;
	int flags = interp ;
	interp &= 0x000f ;

	if ( flags & 0x0080 ) {
		if ( param == 0x0003 || param == 0x000b ) {
			if ( interp == 1 && value1 != value2 ) {
				float value = (float)( value2 - value1 ) * f + (float)value1 ;
				int ival = (int)value ;
				if ( value < 0.0f ) ival -- ;
				if ( value2 > value1 ) {
					value1 = ival ;
					value2 = ival + 1 ;
					f = value - (float)value1 ;
				} else {
					value1 = ival + 1 ;
					value2 = ival ;
					f = (float)value1 - value ;
				}
			}
			picture->m_dissolve = f ;
			if ( param == 0x0003 ) {
				picture->m_image_frame = value1 ;
				picture->m_image_frame2 = value2 ;
			} else {
				picture->m_palette_frame = value1 ;
				picture->m_palette_frame2 = value2 ;
			}
			return ;
		}
	}

	float value = (float)value1 ;
	if ( interp == 1 ) {
		value += (float)( value2 - value1 ) * f ;
	}
	sceGimPictureControl( picture, param, value ) ;
}
