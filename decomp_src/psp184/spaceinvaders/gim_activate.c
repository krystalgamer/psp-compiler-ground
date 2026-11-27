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
void sceGimPictureActivateTexture( SceGimPicture *picture ) ;
void sceGimPictureActivateRenderState( SceGimPicture *picture ) ;
static void reconfigure_picture(SceGimPicture *picture);

_Bool sceGimPictureLoadCache( SceGimPicture *picture )
{
	return 1 ;
}

void sceGimPictureUnloadCache(void) {
}

void sceGimPictureActivate( SceGimPicture *picture )
{
	sceGimPictureActivateTexture( picture ) ;
	sceGimPictureActivateRenderState( picture ) ;
}

void sceGuTexMode( int tpsm, int maxmips, int a2, int swizzle ) ;
void sceGuTexImage( int mipmap, int width, int height, int tbw, const void *tbp ) ;
void sceGuClutMode( int cpsm, int shift, int mask, int a3 ) ;
void sceGuClutLoad( int num_blocks, const void *cbp ) ;
static __inline__ int sceGimPicturePow2( int n )
{
	return 1 << ( 32 - __builtin_allegrex_clz( n - 1 ) ) ;
}

void sceGimPictureActivateTexture( SceGimPicture *picture )
{
	if ( picture == 0 ) return ;

	if ( picture->m_flags == 0 ) {
		SceGimImageHeader *img = picture->m_image ;
		if ( img != 0 ) {
			sceGuTexMode( img->format, 0, 0, img->order ) ;
			void **offsets = (void **)( (char *)img + img->offsets ) ;
			sceGuTexImage( 0, img->width, img->height, picture->m_buf_width, *offsets ) ;
		}
		SceGimPaletteHeader *pal = picture->m_palette ;
		if ( pal != 0 ) {
			sceGuClutMode( pal->format,
				picture->m_palette_offset[ 0 ],
				picture->m_palette_offset[ 1 ],
				picture->m_palette_offset[ 2 ] ) ;
			void **offsets = (void **)( (char *)pal + pal->offsets ) ;
			sceGuClutLoad( picture->m_clut_load, *offsets ) ;
		}
		return ;
	}

	SceGimImageHeader *img = picture->m_image ;
	if ( img != 0 ) {
		int w = img->width ;
		int h = img->height ;
		int w2 = sceGimPicturePow2( w ) ;
		int h2 = sceGimPicturePow2( h ) ;
		int align = img->pitch_align * 8 / img->bpp - 1 ;
		int n_levels = img->level_count ;
		void **offsets = (void **)( (char *)img + img->offsets ) ;

		int n_frames = img->frame_count ;
		int frame = picture->m_image_frame % n_frames ;
		if ( frame < 0 ) frame += n_frames ;

		if ( picture->m_enable_bits & 0x0001 ) {
			int clut = 0 ;
			if ( picture->m_flags & 0x0008 ) clut = 1 ;
			sceGuTexMode( img->format, 1, clut, img->order ) ;
			w = ( w + align ) & ~align ;
			void *buf = offsets[ frame * n_levels ] ;
			sceGuTexImage( 0, w2, h2, w, buf ) ;
			frame = picture->m_image_frame2 % n_frames ;
			if ( frame < 0 ) frame = frame + n_frames ;
			buf = offsets[ frame * n_levels ] ;
			sceGuTexImage( 1, w2, h2, w, buf ) ;
		} else {
			offsets += frame * n_levels ;
			int clut = 0 ;
			if ( picture->m_flags & 0x0004 ) clut = 1 ;
			sceGuTexMode( img->format, n_levels - 1, clut, img->order ) ;
			{ int i ; for ( i = 0 ; i < n_levels ; i ++ ) {
				void *buf = *( offsets ++ ) ;
				sceGuTexImage( i, w2, h2, ( w + align ) & ~align, buf ) ;
				if ( img->level_type == 1 ) {
					w = ( w + 1 ) / 2 ;
					w2 = ( w2 + 1 ) / 2 ;
					h2 = ( h2 + 1 ) / 2 ;
				}
			} }
		}
	}

	SceGimPaletteHeader *pal = picture->m_palette ;
	if ( pal != 0 ) {
		sceGuClutMode( pal->format,
			picture->m_palette_offset[ 0 ],
			picture->m_palette_offset[ 1 ],
			picture->m_palette_offset[ 2 ] ) ;

		void **offsets = (void **)( (char *)pal + pal->offsets ) ;
		int n_levels = pal->level_count ;
		int n_frames = pal->frame_count ;
		int frame = picture->m_palette_frame % n_frames ;
		if ( frame < 0 ) frame = frame + n_frames ;
		if ( !( picture->m_enable_bits & 0x0001 ) ) {
			sceGuClutLoad( picture->m_clut_load, offsets[ frame * n_levels ] ) ;
		} else {
			int count = pal->width / 16 ;
			if ( pal->format == 3 ) count *= 2 ;
			int frame2 = picture->m_palette_frame2 % n_frames ;
			if ( frame2 < 0 ) frame2 = frame2 + n_frames ;
			if ( frame2 == frame + 1 && n_levels == 1 && count <= 16 ) {
				sceGuClutLoad( count * 2, offsets[ frame * n_levels ] ) ;
			} else {
				sceGuClutLoad( count * 2, (char *)offsets[ frame2 * n_levels ] - count * 32 ) ;
				sceGuClutLoad( count, offsets[ frame * n_levels ] ) ;
			}
		}
	}
}

void sceGuTexLevelMode( int mode, float bias ) ;
void sceGuTexOffset( float u, float v ) ;
void sceGuTexScale( float u, float v ) ;
void sceGuBlendFunc( int op, int src, int dst, unsigned int srcfix, unsigned int destfix ) ;
void sceGuTexFunc( int tfx, int tcc ) ;
void sceGuTexFilter( int min, int mag ) ;
void sceGuTexWrap( int u, int v ) ;
extern const float D_00083770[4] ;
extern const int D_00083780[][4] ;
void sceGimPictureActivateRenderState( SceGimPicture *picture )
{
	if ( picture == 0 ) return ;

	int enable = picture->m_enable_bits ;
	if ( enable == 0 ) return ;

	if ( enable & 0x0002 ) {
		if ( enable & 0x0001 ) {
			sceGuTexLevelMode( 1, picture->m_dissolve ) ;
		} else {
			sceGuTexLevelMode( 0, 0 ) ;
		}
	}

	if ( enable & 0x0004 ) {
		const float *crop = picture->m_image_crop ;
		if ( !( picture->m_flags & 0x0020 ) ) crop = D_00083770 ;
		sceGuTexOffset( crop[ 0 ], crop[ 1 ] ) ;
		sceGuTexScale( crop[ 2 ], crop[ 3 ] ) ;
	}

	if ( enable & 0x0100 ) {
		const int *modes = D_00083780[ picture->m_blend[ 0 ] ] ;
		sceGuBlendFunc( modes[ 0 ], modes[ 1 ], modes[ 2 ], 0xffffffff, modes[ 3 ] ) ;
	}
	if ( enable & 0x0200 ) {
		sceGuTexFunc( picture->m_func[ 0 ], picture->m_func[ 1 ] ) ;
	}
	if ( enable & 0x0400 ) {
		sceGuTexFilter( picture->m_filter[ 0 ], picture->m_filter[ 1 ] ) ;
	}
	if ( enable & 0x0800 ) {
		sceGuTexWrap( picture->m_wrap[ 0 ], picture->m_wrap[ 1 ] ) ;
	}
}
