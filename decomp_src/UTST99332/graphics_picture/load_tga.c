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
struct _anon3 { /* size 0x14 */
    unsigned char id_size;
    unsigned char clut_type;
    unsigned char image_type;
    short unsigned int first_entry;
    short unsigned int clut_count;
    unsigned char entry_size;
    short unsigned int org_x;
    short unsigned int org_y;
    short unsigned int width;
    short unsigned int height;
    unsigned char depth;
    unsigned char image_desc;
};
typedef struct _anon3 TgaHeader;



_Bool sceGimPictureLoadTga(SceGimPicture *picture, const void *buf, int size);
static const void *read_header(const void *src, TgaHeader *header);
static const void *read_char(const void *src, unsigned char *val);
static const void *read_short(const void *src, short unsigned int *val);
static void copy_pixels(char *dp, const char *sp, int count, int src_step, _Bool run);

/* SDK functions */
int sceKernelDcacheWritebackAll(void);

_Bool sceGimPictureReallocPalette(SceGimPicture *picture, int format, int w, int level, int frame, void *pixels);
_Bool sceGimPictureReallocImage(SceGimPicture *picture, int format, int w, int h, int level, int frame, void *pixels);
void *sceGimPictureGetImagePixels(SceGimPicture *picture, int level, int frame);
void *sceGimPictureGetPalettePixels(SceGimPicture *picture, int level, int frame);
void sceGimPictureUnload(SceGimPicture *picture);

#ifdef NON_MATCHING
/* the RLE loop's registers and scheduling differ */
_Bool sceGimPictureLoadTga(SceGimPicture *picture, const void *buf, int size)
{
	TgaHeader header;
	const void *ptr;
	int type;
	int format;
	int src_step;
	int dst_step;
	int width;
	int height;
	void *ptr2;
	int pitch;
	int pitch2;
	const char *sp;
	char *dp;

	if (picture == NULL)
		return 0;
	sceGimPictureUnload(picture);
	ptr = read_header(buf, &header);
	type = header.image_type & ~8;
	if (type != 1 && type != 2)
		return 0;
	if (header.clut_type != 0) {
		int clut_count;
		void *ptr2;
		const unsigned char *sp;
		unsigned int *dp;

		clut_count = header.clut_count;
		sceGimPictureReallocPalette(picture, 3, clut_count, 1, 1, NULL);
		ptr2 = sceGimPictureGetPalettePixels(picture, 0, 0);
		if (ptr2 == NULL)
			return 0;
		sp = ptr;
		dp = ptr2;
		if (header.entry_size == 24) {
			int i;

			for (i = 0; i < clut_count; i++) {
				*dp++ = 0xff000000 | (sp[0] << 16) | (sp[1] << 8) | sp[2];
				sp += 3;
			}
		} else {
			int i;

			for (i = 0; i < clut_count; i++) {
				*dp++ = (sp[3] << 24) | (sp[0] << 16) | (sp[1] << 8) | sp[2];
				sp += 4;
			}
		}
		ptr = sp;
	}
	format = 5;
	src_step = 1;
	dst_step = 1;
	if (header.depth > 8) {
		format = 1;
		src_step = 2;
		dst_step = 2;
		if (header.depth > 16) {
			format = 3;
			src_step = 3;
			dst_step = 4;
			if (header.depth > 24) {
				src_step = 4;
				dst_step = 4;
			}
		}
	}
	width = header.width;
	height = header.height;
	sceGimPictureReallocImage(picture, format, width, height, 1, 1, NULL);
	ptr2 = sceGimPictureGetImagePixels(picture, 0, 0);
	if (ptr2 == NULL)
		return 0;
	sp = ptr;
	dp = ptr2;
	pitch = (width * dst_step + 15) & ~15;
	pitch2 = width * src_step;
	if (!(header.image_desc & 0x20)) {
		dp += pitch * (height - 1);
		pitch = -pitch;
	}
	if (!(header.image_type & 8)) {
		int i;

		for (i = 0; i < height; i++) {
			copy_pixels(dp, sp, width, src_step, 0);
			sp += pitch2;
			dp += pitch;
		}
	} else {
		int x_pos;
		int y_pos;

		x_pos = 0;
		y_pos = 0;
		while (y_pos < height) {
			int count;
			_Bool run;

			count = (*sp & 0x7f) + 1;
			run = (*sp & 0x80) != 0;
			sp++;
			while (count > 0) {
				int step;

				step = width - x_pos;
				if (count < step)
					step = count;
				copy_pixels(dp, sp, step, src_step, run);
				x_pos += step;
				if (!run)
					sp += step * src_step;
				dp += step * dst_step;
				count -= step;
				if (x_pos >= width) {
					y_pos++;
					dp += pitch - x_pos * dst_step;
					x_pos = 0;
				}
			}
			if (run)
				sp += src_step;
		}
	}
	sceKernelDcacheWritebackAll();
	return 1;
}
#else
INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/load_tga", sceGimPictureLoadTga);
#endif

#define read_header read_header_3424
#define read_short read_short_34E8
#define copy_pixels copy_pixels_3518

static const void *read_header(const void *src, TgaHeader *header)
{
	src = read_char(src, &header->id_size);
	src = read_char(src, &header->clut_type);
	src = read_char(src, &header->image_type);
	src = read_short(src, &header->first_entry);
	src = read_short(src, &header->clut_count);
	src = read_char(src, &header->entry_size);
	src = read_short(src, &header->org_x);
	src = read_short(src, &header->org_y);
	src = read_short(src, &header->width);
	src = read_short(src, &header->height);
	src = read_char(src, &header->depth);
	src = read_char(src, &header->image_desc);
	return (const char *)src + header->id_size;
}

static const void *read_char(const void *src, unsigned char *val)
{
	*val = *(const unsigned char *)src;
	return (const unsigned char *)src + 1;
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




static void copy_pixels(char *dp, const char *sp, int count, int src_step, _Bool run)
{
	int step;

	step = run ? 0 : src_step;
	switch (src_step) {
	case 1:
		{
			int i;

			for (i = 0; i < count; i++) {
				*dp++ = *sp;
				sp += step;
			}
		}
		break;
	case 3:
		{
			int i;

			for (i = 0; i < count; i++) {
				dp[0] = sp[2];
				dp[1] = sp[1];
				dp[2] = sp[0];
				dp[3] = 0xff;
				sp += step;
				dp += 4;
			}
		}
		break;
	case 2:
		{
			const unsigned char *sp2 = (const unsigned char *)sp;
			short unsigned int *dp2 = (short unsigned int *)dp;
			int i;

			for (i = 0; i < count; i++) {
				int src = (sp2[1] << 8) | sp2[0];
				int r = (src & 0x7c00) >> 10;
				int b = src & 0x001f;

				*dp2++ = (src & ~0x7c1f) | r | (b << 10) | 0x8000;
				sp2 += step;
			}
		}
		break;
	case 4:
		{
			int i;

			for (i = 0; i < count; i++) {
				dp[0] = sp[2];
				dp[1] = sp[1];
				dp[2] = sp[0];
				dp[3] = sp[3];
				sp += step;
				dp += 4;
			}
		}
		break;
	}
}
