/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon1 { /* size 0x10 */
    short unsigned int type;
    short unsigned int unused;
    unsigned int next_offs;
    unsigned int child_offs;
    unsigned int data_offs;
};
typedef struct _anon1 SceGimChunk;
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
typedef SceGimImageHeader SceGimPaletteHeader;

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
static int SCEGIM_CHUNK_TYPE(SceGimChunk *chunk);
void sceGimPictureUnload(SceGimPicture *picture);
void sceGimPictureAnimate(SceGimPicture *picture, float step);
void sceGimPictureActivate(SceGimPicture *picture);
static int pow2(int n);
void *sceGimPictureGetImagePixels(SceGimPicture *picture, int level, int frame);
void *sceGimPictureGetPalettePixels(SceGimPicture *picture, int level, int frame);
void sceGimPictureSetImagePixels(SceGimPicture *picture, int level, int frame, void *pixels);
void sceGimPictureSetPalettePixels(SceGimPicture *picture, int level, int frame, void *pixels);
_Bool sceGimPictureReallocImage(SceGimPicture *picture, int format, int w, int h, int level, int frame, void *pixels);
_Bool sceGimPictureReallocPalette(SceGimPicture *picture, int format, int w, int level, int frame, void *pixels);
_Bool sceGimPictureHasAnimation(SceGimPicture *picture);
static void reconfigure_picture(SceGimPicture *picture);
void sceGimPictureSetEnableBits(SceGimPicture *picture, int bits, int value);
void sceGimPictureSetFrameLoop(SceGimPicture *picture, float start, float end);
void sceGimPictureSetImageCrop(SceGimPicture *picture, const float *crop);
const float *sceGimPictureGetImageCrop(SceGimPicture *picture);


/* SDK prototypes (tools/sdk_protos.h) */
void *memcpy(void *d, const void *s, unsigned int n);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
int sceKernelDcacheWritebackAll(void);

/* module functions defined in other units */
_Bool sceGimPictureCheckFileHeader(const void *buf, int size);
void sceGimPictureFreeMemory(void *addr);
void sceGimPictureFreeMemory2(void *addr);
const SceGimChunk *sceGimPictureGetChunk(const void *buf, int size, int idx);
_Bool sceGimPictureLoadBmp(SceGimPicture *picture, const void *buf, int size);
_Bool sceGimPictureLoadTga(SceGimPicture *picture, const void *buf, int size);
_Bool sceGimPictureLoadTm2(SceGimPicture *picture, const void *buf, int size, int idx);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", __psp_libinfo___21BD4);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", sceGimPictureCreate);

void sceGimPictureDelete(SceGimPicture *picture)
{
	if (picture != NULL) {
		if (--picture->m_reference == 0) {
			sceGimPictureUnload(picture);
			sceGimPictureFreeMemory(picture);
		}
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", sceGimPictureDuplicate);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", sceGimPictureLoadFile);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", sceGimPictureLoad);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", sceGimPictureUnload);

void sceGimPictureAnimate(SceGimPicture *picture, float step)
{
	float frame;
	float prev;
	float start, end;
	int i;

	if (picture == NULL) {
		return;
	}
	if (!(picture->m_flags & 0x10)) {
		return;
	}

	prev = picture->m_frame;
	frame = prev + picture->m_frame_rate * step;
	start = picture->m_frame_loop[0];
	end = picture->m_frame_loop[1];
	if (frame >= end && prev < end) {
		frame = start;
	} else if (frame < start && prev >= start) {
		frame = end;
	}
	picture->m_frame = frame;

	i = (int)frame;
	if (frame < 0.0f) {
		i--;
	}
	picture->m_image_frame = i;
	picture->m_image_frame2 = i + 1;
	picture->m_palette_frame = i;
	picture->m_palette_frame2 = i + 1;
	picture->m_dissolve = frame - (float)i;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", sceGimPictureActivate);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", sceGimPictureGetImagePixels);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", sceGimPictureGetPalettePixels);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", sceGimPictureSetImagePixels);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", sceGimPictureSetPalettePixels);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", sceGimPictureReallocImage);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", sceGimPictureReallocPalette);

_Bool sceGimPictureHasAnimation(SceGimPicture *picture)
{
	if (picture == NULL) {
		return 0;
	}
	return (picture->m_flags & 0x10) != 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", reconfigure_picture);

void sceGimPictureSetEnableBits(SceGimPicture *picture, int bits, int value)
{
	if (picture == NULL) {
		return;
	}
	picture->m_enable_bits &= ~bits;
	picture->m_enable_bits |= bits & value;
}

int sceGimPictureGetEnableBits(SceGimPicture *picture) {
    int var_v0;

    var_v0 = 0;
    if (picture != NULL) {
        var_v0 = picture->m_enable_bits;
    }
    return var_v0;
}

SceGimImageHeader *sceGimPictureGetImage(SceGimPicture *picture) {
    SceGimImageHeader *var_v0;

    var_v0 = NULL;
    if (picture != NULL) {
        var_v0 = picture->m_image;
    }
    return var_v0;
}

SceGimImageHeader *sceGimPictureGetPalette(SceGimPicture *picture) {
    SceGimImageHeader *var_v0;

    var_v0 = NULL;
    if (picture != NULL) {
        var_v0 = picture->m_palette;
    }
    return var_v0;
}

void sceGimPictureSetFrameLoop(SceGimPicture *picture, float start, float end)
{
	if (picture == NULL)
		return;
	picture->m_frame_loop[0] = start;
	picture->m_frame_loop[1] = end;
}

float *sceGimPictureGetFrameLoop(SceGimPicture *picture) {
    return (picture == NULL) ? NULL : picture->m_frame_loop;
}

void sceGimPictureSetFrameRate(SceGimPicture *picture, float fps) {
    if (picture != NULL) {
        picture->m_frame_rate = fps;
    }
}

float sceGimPictureGetFrameRate(SceGimPicture *picture) {
    float var_f0;

    var_f0 = 0.0f;
    if (picture != NULL) {
        var_f0 = picture->m_frame_rate;
    }
    return var_f0;
}

void sceGimPictureSetFrame(SceGimPicture *picture, float frame) {
    if (picture != NULL) {
        picture->m_frame = frame;
    }
}

float sceGimPictureGetFrame(SceGimPicture *picture) {
    float var_f0;

    var_f0 = 0.0f;
    if (picture != NULL) {
        var_f0 = picture->m_frame;
    }
    return var_f0;
}

void sceGimPictureSetImageFrame(SceGimPicture *picture, int frame) {
    if (picture != NULL) {
        picture->m_image_frame = frame;
    }
}

int sceGimPictureGetImageFrame(SceGimPicture *picture) {
    int var_v0;

    var_v0 = 0;
    if (picture != NULL) {
        var_v0 = picture->m_image_frame;
    }
    return var_v0;
}

void sceGimPictureSetImageFrame2(SceGimPicture *picture, int frame) {
    if (picture != NULL) {
        picture->m_image_frame2 = frame;
    }
}

int sceGimPictureGetImageFrame2(SceGimPicture *picture) {
    int var_v0;

    var_v0 = 0;
    if (picture != NULL) {
        var_v0 = picture->m_image_frame2;
    }
    return var_v0;
}

void sceGimPictureSetPaletteFrame(SceGimPicture *picture, int frame) {
    if (picture != NULL) {
        picture->m_palette_frame = frame;
    }
}

int sceGimPictureGetPaletteFrame(SceGimPicture *picture) {
    int var_v0;

    var_v0 = 0;
    if (picture != NULL) {
        var_v0 = picture->m_palette_frame;
    }
    return var_v0;
}

void sceGimPictureSetPaletteFrame2(SceGimPicture *picture, int frame) {
    if (picture != NULL) {
        picture->m_palette_frame = frame;
    }
}

int sceGimPictureGetPaletteFrame2(SceGimPicture *picture) {
    int var_v0;

    var_v0 = 0;
    if (picture != NULL) {
        var_v0 = picture->m_palette_frame;
    }
    return var_v0;
}

void sceGimPictureSetDissolve(SceGimPicture *picture, float dissolve) {
    if (picture != NULL) {
        picture->m_dissolve = dissolve;
    }
}

float sceGimPictureGetDissolve(SceGimPicture *picture) {
    float var_f0;

    var_f0 = 0.0f;
    if (picture != NULL) {
        var_f0 = picture->m_dissolve;
    }
    return var_f0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_picture", sceGimPictureSetImageCrop);

const float *sceGimPictureGetImageCrop(SceGimPicture *picture)
{
	if (picture == NULL) {
		return NULL;
	}
	if (!(picture->m_flags & 0x20)) {
		return NULL;
	}
	return picture->m_image_crop;
}
