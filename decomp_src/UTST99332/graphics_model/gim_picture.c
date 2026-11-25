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
typedef unsigned int size_t;

extern const unsigned char __psp_libinfo__[24];

SceGimPicture *sceGimPictureCreate(SceGimChunk *chunk);
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
void *sceGimPictureGetImagePixels(SceGimPicture *picture, int level, int frame);
void *sceGimPictureGetPalettePixels(SceGimPicture *picture, int level, int frame);
void sceGimPictureSetImagePixels(SceGimPicture *picture, int level, int frame, void *pixels);
void sceGimPictureSetPalettePixels(SceGimPicture *picture, int level, int frame, void *pixels);
_Bool sceGimPictureReallocImage(SceGimPicture *picture, int format, int w, int h, int level, int frame, void *pixels);
_Bool sceGimPictureReallocPalette(SceGimPicture *picture, int format, int w, int level, int frame, void *pixels);
void sceGimPictureSetFrameLoop(SceGimPicture *picture, float start, float end);
void sceGimPictureSetImageCrop(SceGimPicture *picture, const float *crop);
static void reconfigure_picture(SceGimPicture *picture);


INCLUDE_RODATA("tmp/asm/UTST99332/graphics_model/nonmatchings/gim_picture", __psp_libinfo___1DBB4);

SceGimPicture *sceGimPictureCreate(SceGimChunk *chunk)
{
	SceGimPicture *picture;

	picture = (SceGimPicture *)sceGimPictureAllocMemory(sizeof(SceGimPicture));
	if (picture == NULL)
		return NULL;
	picture->m_reference = 1;
	picture->m_flags = 0;
	picture->m_image = NULL;
	picture->m_palette = NULL;
	picture->m_sequence = NULL;
	picture->m_buf_width = 0;
	picture->m_clut_load = 0;
	picture->m_frame_loop[0] = -1000000.0f;
	picture->m_frame_loop[1] = 1000000.0f;
	picture->m_frame_rate = 12.0f;
	picture->m_frame = 0.0f;
	picture->m_enable_bits = 0;
	picture->m_image_frame = 0;
	picture->m_image_frame2 = 0;
	picture->m_palette_frame = 0;
	picture->m_palette_frame2 = 0;
	picture->m_dissolve = 0.0f;
	picture->m_image_crop[0] = 0.0f;
	picture->m_image_crop[1] = 0.0f;
	picture->m_image_crop[2] = 1.0f;
	picture->m_image_crop[3] = 1.0f;
	if (chunk != NULL && !sceGimPictureLoad(picture, chunk)) {
		sceGimPictureDelete(picture);
		return NULL;
	}
	return picture;
}

void sceGimPictureDelete(SceGimPicture *picture) {
    int temp_v0;

    if ((picture == NULL) || (temp_v0 = picture->m_reference - 1, picture->m_reference = temp_v0, (temp_v0 != 0))) {

    } else {
        sceGimPictureUnload(picture);
        sceGimPictureFreeMemory(picture);
    }
}

void *memcpy(void *d, const void *s, unsigned int n);
void *memcpy(void *, const void *, size_t);
SceGimPicture *sceGimPictureDuplicate(SceGimPicture *picture, int flags)
{
	SceGimPicture *picture2;
	SceGimImageHeader *image;
	SceGimPaletteHeader *palette;
	SceGimSequenceHeader *sequence;

	if (picture == NULL)
		return NULL;
	if (flags & 2) {
		flags &= ~2;
		if (sceGimPictureHasAnimation(picture))
			flags |= 1;
	}
	if (flags == 0) {
		picture->m_reference++;
		return picture;
	}
	picture2 = sceGimPictureCreate(NULL);
	if (picture2 == NULL)
		return NULL;
	image = picture->m_image;
	palette = picture->m_palette;
	sequence = picture->m_sequence;
	if (image != NULL)
		image->reference++;
	if (palette != NULL)
		palette->reference++;
	if (sequence != NULL)
		sequence->reference++;
	picture2->m_flags = picture->m_flags;
	picture2->m_image = image;
	picture2->m_palette = palette;
	picture2->m_sequence = sequence;
	picture2->m_buf_width = picture->m_buf_width;
	picture2->m_clut_load = picture->m_clut_load;
	picture2->m_frame_loop[0] = picture->m_frame_loop[0];
	picture2->m_frame_loop[1] = picture->m_frame_loop[1];
	picture2->m_frame_rate = picture->m_frame_rate;
	picture2->m_frame = picture->m_frame;
	picture2->m_enable_bits = picture->m_enable_bits;
	picture2->m_image_frame = picture->m_image_frame;
	picture2->m_image_frame2 = picture->m_image_frame2;
	picture2->m_palette_frame = picture->m_palette_frame;
	picture2->m_palette_frame2 = picture->m_palette_frame2;
	picture2->m_dissolve = picture->m_dissolve;
	memcpy(picture2->m_image_crop, picture->m_image_crop, sizeof(picture2->m_image_crop));
	return picture2;
}

_Bool sceGimPictureLoadTga(SceGimPicture *picture, const void *buf, int size);
_Bool sceGimPictureLoadBmp(SceGimPicture *picture, const void *buf, int size);
_Bool sceGimPictureLoadTm2(SceGimPicture *picture, const void *buf, int size, int idx);
_Bool sceGimPictureCheckFileHeader(const void *buf, int size);
const SceGimChunk *sceGimPictureGetChunk(const void *buf, int size, int idx);
_Bool sceGimPictureLoadFile(SceGimPicture *picture, const void *buf, int size, int idx)
{
	int signature;

	if (picture == NULL)
		return 0;
	if (buf == NULL || size < 4)
		return 0;
	signature = *(const int *)buf;
	if (signature == 0x2E47494D) {
		const SceGimChunk *chunk;

		if (!sceGimPictureCheckFileHeader(buf, size))
			return 0;
		chunk = sceGimPictureGetChunk(buf, size, idx);
		if (chunk == NULL)
			return 0;
		return sceGimPictureLoad(picture, chunk);
	}
	if (signature == 0x324D4954)
		return sceGimPictureLoadTm2(picture, buf, size, idx);
	if ((signature & 0xffff) == 0x4D42) {
		if (idx != 0)
			return 0;
		return sceGimPictureLoadBmp(picture, buf, size);
	}
	if (idx != 0)
		return 0;
	return sceGimPictureLoadTga(picture, buf, size);
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gim_picture", sceGimPictureLoad);

void sceGimPictureUnload(SceGimPicture *picture)
{
	SceGimImageHeader *image;
	SceGimPaletteHeader *palette;
	SceGimSequenceHeader *sequence;

	if (picture == NULL)
		return;
	image = picture->m_image;
	if (image != NULL) {
		if (--image->reference == 0)
			sceGimPictureFreeMemory2(image);
		picture->m_image = NULL;
	}
	palette = picture->m_palette;
	if (palette != NULL) {
		if (--palette->reference == 0)
			sceGimPictureFreeMemory2(palette);
		picture->m_palette = NULL;
	}
	sequence = picture->m_sequence;
	if (sequence != NULL) {
		if (--sequence->reference == 0)
			sceGimPictureFreeMemory2(sequence);
		picture->m_sequence = NULL;
	}
}

void sceGimPictureAnimate(SceGimPicture *picture, float step)
{
	float frame;
	float start;
	float end;
	int f;

	if (picture == NULL || !(picture->m_flags & 0x10))
		return;
	frame = picture->m_frame + picture->m_frame_rate * step;
	start = picture->m_frame_loop[0];
	end = picture->m_frame_loop[1];
	if (frame >= end && picture->m_frame < end)
		frame = start;
	else if (frame < start && picture->m_frame >= start)
		frame = end;
	picture->m_frame = frame;
	f = (int)frame;
	if (frame < 0.0f)
		f--;
	picture->m_image_frame = f;
	picture->m_image_frame2 = f + 1;
	picture->m_palette_frame = f;
	picture->m_palette_frame2 = f + 1;
	picture->m_dissolve = frame - (float)f;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gim_picture", sceGimPictureActivate);

void sceGimPictureSetEnableBits(SceGimPicture *picture, int bits, int value) {
    if (picture != NULL) {
        picture->m_enable_bits = (picture->m_enable_bits & ~bits) | (bits & value);
    }
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

void *sceGimPictureGetImagePixels(SceGimPicture *picture, int level, int frame)
{
	SceGimImageHeader *image;
	int n_levels;
	int n_frames;
	void **offsets;

	if (picture == NULL)
		return NULL;
	image = picture->m_image;
	if (image == NULL)
		return NULL;
	n_levels = image->level_count;
	n_frames = image->frame_count;
	if (level < 0 || level >= n_levels)
		return NULL;
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

	if (picture == NULL)
		return NULL;
	palette = picture->m_palette;
	if (palette == NULL)
		return NULL;
	n_levels = palette->level_count;
	n_frames = palette->frame_count;
	if (level < 0 || level >= n_levels)
		return NULL;
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

	if (picture == NULL)
		return;
	if (pixels == NULL)
		return;
	image = picture->m_image;
	if (image == NULL)
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

	if (picture == NULL)
		return;
	if (pixels == NULL)
		return;
	palette = picture->m_palette;
	if (palette == NULL)
		return;
	n_levels = palette->level_count;
	n_frames = palette->frame_count;
	if (level < 0 || level >= n_levels)
		return;
	frame %= n_frames; if (frame & 0x8000) frame = (frame + n_frames) & 0x7fff;
	offsets = (void **)((char *)palette + palette->offsets);
	offsets[n_levels * frame + level] = pixels;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gim_picture", sceGimPictureReallocImage);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gim_picture", sceGimPictureReallocPalette);

int sceGimPictureHasAnimation(SceGimPicture *picture) {
    int var_v0;

    var_v0 = 0;
    if (picture != NULL) {
        var_v0 = ((unsigned int) picture->m_flags >> 4) & 1;
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

void *memcpy(void *, const void *, size_t);
void sceGimPictureSetImageCrop(SceGimPicture *picture, const float *crop)
{
	if (picture == NULL)
		return;
	if (crop == NULL) {
		picture->m_flags &= ~0x20;
		return;
	}
	memcpy(picture->m_image_crop, crop, sizeof(picture->m_image_crop));
	picture->m_flags |= 0x20;
}

float *sceGimPictureGetImageCrop(SceGimPicture *picture) {
    float *var_v0;

    var_v0 = NULL;
    if (picture != NULL) {
        var_v0 = !(picture->m_flags & 0x20) ? NULL : picture->m_image_crop;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gim_picture", reconfigure_picture);
