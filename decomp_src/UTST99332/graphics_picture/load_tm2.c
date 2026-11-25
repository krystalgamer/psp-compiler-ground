#include "common.h"

/* declarations recovered from DWARF */
struct SceGimPicture;
struct _anon1;
struct _anon1 { /* size 0x30 */
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
typedef struct _anon1 SceGimImageHeader;
struct _anon2;
struct _anon2 { /* size 0x20 */
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
typedef struct _anon2 SceGimSequenceHeader;
struct SceGimPicture { /* size 0x54 */
    int m_reference;
    int m_flags;
    SceGimImageHeader *m_image;
    SceGimImageHeader *m_palette;
    SceGimSequenceHeader *m_sequence;
    int m_buf_width;
    int m_clut_load;
    float m_frame_loop[2];
    float m_frame_rate;
    float m_frame;
    int m_enable_bits;
    int m_image_frame;
    int m_image_frame2;
    int m_palette_frame;
    int m_palette_frame2;
    float m_dissolve;
    float m_image_crop[4];
};
typedef struct SceGimPicture SceGimPicture;
struct _anon3;
struct _anon3 { /* size 0x10 */
    int fileid;
    char version;
    char format;
    short int n_pictures;
    char zero[8];
};
typedef struct _anon3 Tm2Header;
struct _anon4;
struct _anon4 { /* size 0x30 */
    int total_size;
    int clut_size;
    int image_size;
    short int header_size;
    short int clut_colors;
    char pict_format;
    char n_mipmaps;
    char clut_type;
    char image_type;
    short int image_width;
    short int image_height;
    int gs_tex0[2];
    int gs_tex1[2];
    int gs_regs;
    int gs_texclut;
};
typedef struct _anon4 Tm2Pict;
struct _anon5;
struct _anon5 { /* size 0x30 */
    int gs_miptbp1[2];
    int gs_miptbp2[2];
    int sizes[8];
};
typedef struct _anon5 Tm2MipMap;

extern int PixelFormats[6];

_Bool sceGimPictureLoadTm2(SceGimPicture *picture, const void *buf, int size, int idx);
static void copy_pixels(void *dst, const void *src, int width, int height, int type);
static void sort_clut(void *clut, int format, int width);

/* SDK functions */
int sceKernelDcacheWritebackAll(void);

#define copy_pixels copy_pixels_38A8

_Bool sceGimPictureReallocPalette(SceGimPicture *picture, int format, int w, int level, int frame, void *pixels);
_Bool sceGimPictureReallocImage(SceGimPicture *picture, int format, int w, int h, int level, int frame, void *pixels);
void *sceGimPictureGetImagePixels(SceGimPicture *picture, int level, int frame);
void *sceGimPictureGetPalettePixels(SceGimPicture *picture, int level, int frame);
void sceGimPictureUnload(SceGimPicture *picture);

#ifdef NON_MATCHING
/* argument set-up order of the palette copy_pixels call differs */
_Bool sceGimPictureLoadTm2(SceGimPicture *picture, const void *buf, int size, int idx)
{
	const Tm2Header *header;
	const Tm2Pict *pict;
	int clut_type;

	if (picture == NULL)
		return 0;
	sceGimPictureUnload(picture);
	header = (const Tm2Header *)buf;
	if (idx < 0 || idx >= header->n_pictures)
		return 0;
	pict = (const Tm2Pict *)((const char *)buf + (header->format == 0 ? 0x10 : 0x80));
	{
		int i;

		for (i = 0; i < idx; i++)
			pict = (const Tm2Pict *)((const char *)pict + pict->total_size);
	}
	if (pict->n_mipmaps != 0) {
		int format;
		int width;
		int height;
		int level;
		const Tm2MipMap *mipmap;
		const void *ptr;

		format = PixelFormats[(int)pict->image_type];
		width = pict->image_width;
		height = pict->image_height;
		level = pict->n_mipmaps;
		if (!sceGimPictureReallocImage(picture, format, width, height, level, 1, NULL))
			return 0;
		mipmap = (pict->n_mipmaps >= 2) ? (const Tm2MipMap *)(pict + 1) : NULL;
		ptr = (const char *)pict + pict->header_size;
		{
			int j;

			for (j = 0; j < pict->n_mipmaps; j++) {
				{
					void *ptr2;

					ptr2 = sceGimPictureGetImagePixels(picture, j, 0);
					copy_pixels(ptr2, ptr, width, height, pict->image_type);
				}
				if (mipmap != NULL) {
					width = (width + 1) / 2;
					height = (height + 1) / 2;
					ptr = (const char *)ptr + mipmap->sizes[j];
				}
			}
		}
	}
	clut_type = pict->clut_type & 7;
	if (clut_type != 0) {
		int clut_format;
		int clut_width;
		const void *ptr;
		void *ptr2;

		clut_format = PixelFormats[clut_type];
		clut_width = pict->clut_colors;
		ptr = (const char *)pict + pict->header_size + pict->image_size;
		sceGimPictureReallocPalette(picture, clut_format, clut_width, 1, 1, NULL);
		ptr2 = sceGimPictureGetPalettePixels(picture, 0, 0);
		if (ptr2 == NULL)
			return 0;
		copy_pixels(ptr2, ptr, clut_width, 1, clut_type);
		if (!(pict->clut_type & 0x80))
			sort_clut(ptr2, clut_format, clut_width);
	}
	sceKernelDcacheWritebackAll();
	return 1;
}
#else
INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/load_tm2", sceGimPictureLoadTm2);
#endif

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/load_tm2", copy_pixels_38A8);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/load_tm2", sort_clut);
