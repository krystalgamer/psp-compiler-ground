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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/load_tm2", sceGimPictureLoadTm2);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/load_tm2", copy_pixels_BD20);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/load_tm2", sort_clut);
