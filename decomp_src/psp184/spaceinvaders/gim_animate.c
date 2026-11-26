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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_animate", sceGimPictureAnimate);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_animate", sceGimPictureControl);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_animate", eval_fcurve_62354);
