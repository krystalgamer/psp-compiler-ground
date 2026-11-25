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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_picture/nonmatchings/load_tga", sceGimPictureLoadTga);

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
