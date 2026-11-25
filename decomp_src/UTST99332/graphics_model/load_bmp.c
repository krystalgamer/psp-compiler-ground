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
struct _anon3 { /* size 0x38 */
    short int type;
    int size;
    short int res1;
    short int res2;
    int bits;
    int size2;
    int width;
    int height;
    short int plane_count;
    short int bit_count;
    int compress;
    int image_size;
    int xppm;
    int yppm;
    int used_cols;
    int important;
};
typedef struct _anon3 BmpHeader;



_Bool sceGimPictureLoadBmp(SceGimPicture *picture, const void *buf, int size);
static const void *read_header(const void *src, BmpHeader *header);
static const void *read_short(const void *src, short int *val);
static const void *read_int(const void *src, int *val);
static void copy_idx4(void *dst, const void *src, int width, int height);
static void copy_idx8(void *dst, const void *src, int width, int height);
static void copy_5551(void *dst, const void *src, int width, int height);
static void copy_5650(void *dst, const void *src, int width, int height);
static void copy_8880(void *dst, const void *src, int width, int height);
static void copy_8888(void *dst, const void *src, int width, int height, int alpha);
static void copy_rle4(void *dst, const void *src, int width, int height);
static void copy_rle8(void *dst, const void *src, int width, int height);

/* SDK functions */
int sceKernelDcacheWritebackAll(void);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/load_bmp", sceGimPictureLoadBmp);

#define read_header read_header_AE00
#define read_short read_short_AEDC
static const void *read_header(const void *src, BmpHeader *header)
{
	src = read_short(src, &header->type);
	src = read_int(src, &header->size);
	src = read_short(src, &header->res1);
	src = read_short(src, &header->res2);
	src = read_int(src, &header->bits);
	src = read_int(src, &header->size2);
	src = read_int(src, &header->width);
	src = read_int(src, &header->height);
	src = read_short(src, &header->plane_count);
	src = read_short(src, &header->bit_count);
	src = read_int(src, &header->compress);
	src = read_int(src, &header->image_size);
	src = read_int(src, &header->xppm);
	src = read_int(src, &header->yppm);
	src = read_int(src, &header->used_cols);
	src = read_int(src, &header->important);
	return src;
}

static const void *read_short(const void *src, short unsigned int *val)
{
	if ((int)src & 1) {
		const unsigned char *cp = src;

		*val = cp[0] | (cp[1] << 8);
	} else {
		*val = *(const unsigned short *)src;
	}
	return (const unsigned char *)src + 2;
}

static const void *read_int(const void *src, int *val)
{
	if ((int)src & 3) {
		const unsigned char *cp = src;

		*val = (cp[3] << 24) | (cp[2] << 16) | (cp[1] << 8) | cp[0];
	} else {
		*val = *(const int *)src;
	}
	return (const char *)src + 4;
}

static void copy_idx4(void *dst, const void *src, int width, int height)
{
	int pitch;
	int pitch2;
	const char *sp;
	char *dp;

	width = (width + 1) / 2;
	pitch = (width + 15) & ~15;
	pitch2 = (width + 3) & ~3;
	sp = src;
	dp = (char *)dst + pitch * (height - 1);
	{
		int i;

		for (i = 0; i < height; i++) {
			const char *sp2 = sp;
			char *dp2 = dp;
			{
				int j;

				for (j = 0; j < width; j++) {
					int s = *(const unsigned char *)sp2++;

					*dp2++ = (s << 4) | (s >> 4);
				}
			}
			sp += pitch2;
			dp -= pitch;
		}
	}
}

static void copy_idx8(void *dst, const void *src, int width, int height)
{
	int pitch;
	int pitch2;
	const char *sp;
	char *dp;

	pitch = (width + 15) & ~15;
	pitch2 = (width + 3) & ~3;
	sp = src;
	dp = (char *)dst + pitch * (height - 1);
	{
		int i;

		for (i = 0; i < height; i++) {
			const char *sp2 = sp;
			char *dp2 = dp;
			{
				int j;

				for (j = 0; j < width; j++)
					*dp2++ = *sp2++;
			}
			sp += pitch2;
			dp -= pitch;
		}
	}
}

static void copy_5551(void *dst, const void *src, int width, int height)
{
	int pitch;
	int pitch2;
	const short int *sp;
	short int *dp;

	pitch = (width + 7) & ~7;
	pitch2 = (width + 1) & ~1;
	sp = src;
	dp = (short int *)dst + pitch * (height - 1);
	{
		int i;

		for (i = 0; i < height; i++) {
			const short int *sp2 = sp;
			short int *dp2 = dp;
			{
				int j;

				for (j = 0; j < width; j++) {
					int s = *sp2++;
					int r = (s & 0x7c00) >> 10;
					int b = s & 0x001f;

					*dp2++ = (s & 0x03e0) | r | (b << 10) | 0x8000;
				}
			}
			sp += pitch2;
			dp -= pitch;
		}
	}
}

static void copy_5650(void *dst, const void *src, int width, int height)
{
	int pitch;
	int pitch2;
	const short int *sp;
	short int *dp;

	pitch = (width + 7) & ~7;
	pitch2 = (width + 1) & ~1;
	sp = src;
	dp = (short int *)dst + pitch * (height - 1);
	{
		int i;

		for (i = 0; i < height; i++) {
			const short int *sp2 = sp;
			short int *dp2 = dp;
			{
				int j;

				for (j = 0; j < width; j++) {
					int s = *sp2++;
					int r = (s & 0xf800) >> 11;
					int b = s & 0x001f;

					*dp2++ = r | (s & 0x07e0) | (b << 11);
				}
			}
			sp += pitch2;
			dp -= pitch;
		}
	}
}

static void copy_8880(void *dst, const void *src, int width, int height)
{
	int pitch;
	int pitch2;
	const char *sp;
	char *dp;

	pitch = (width * 4 + 15) & ~15;
	pitch2 = (width * 3 + 3) & ~3;
	sp = src;
	dp = (char *)dst + pitch * (height - 1);
	{
		int i;

		for (i = 0; i < height; i++) {
			const char *sp2 = sp;
			char *dp2 = dp;
			{
				int j;

				for (j = 0; j < width; j++) {
					dp2[0] = sp2[2];
					dp2[1] = sp2[1];
					dp2[2] = sp2[0];
					dp2[3] = 0xff;
					sp2 += 3;
					dp2 += 4;
				}
			}
			sp += pitch2;
			dp -= pitch;
		}
	}
}

static void copy_8888(void *dst, const void *src, int width, int height, int alpha)
{
	int pitch;
	int pitch2;
	const char *sp;
	char *dp;

	pitch = (width * 4 + 15) & ~15;
	pitch2 = width * 4;
	sp = src;
	dp = (char *)dst + pitch * (height - 1);
	{
		int i;

		for (i = 0; i < height; i++) {
			const char *sp2 = sp;
			char *dp2 = dp;
			{
				int j;

				for (j = 0; j < width; j++) {
					dp2[0] = sp2[2];
					dp2[1] = sp2[1];
					dp2[2] = sp2[0];
					dp2[3] = sp2[3] | alpha;
					sp2 += 4;
					dp2 += 4;
				}
			}
			sp += pitch2;
			dp -= pitch;
		}
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/load_bmp", copy_rle4);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/load_bmp", copy_rle8);
