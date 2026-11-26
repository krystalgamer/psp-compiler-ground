#include "common.h"

/* declarations recovered from DWARF */
typedef struct SceGimPicture SceGimPicture;
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


/* SDK prototypes (tools/sdk_protos.h) */
int sceKernelDcacheWritebackAll(void);

/* module functions defined in other units */
void *sceGimPictureGetImagePixels(SceGimPicture *picture, int level, int frame);
void *sceGimPictureGetPalettePixels(SceGimPicture *picture, int level, int frame);
_Bool sceGimPictureReallocImage(SceGimPicture *picture, int format, int w, int h, int level, int frame, void *pixels);
_Bool sceGimPictureReallocPalette(SceGimPicture *picture, int format, int w, int level, int frame, void *pixels);
void sceGimPictureUnload(SceGimPicture *picture);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_bmp", sceGimPictureLoadBmp);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_bmp", read_header_E464);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_bmp", read_short_E540);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_bmp", read_int);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_bmp", copy_idx4);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_bmp", copy_idx8);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_bmp", copy_5551);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_bmp", copy_5650);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_bmp", copy_8880);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_bmp", copy_8888);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_bmp", copy_rle4);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_bmp", copy_rle8);
