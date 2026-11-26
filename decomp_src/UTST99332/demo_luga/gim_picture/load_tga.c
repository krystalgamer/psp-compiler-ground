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


/* SDK prototypes (tools/sdk_protos.h) */
int sceKernelDcacheWritebackAll(void);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_tga", sceGimPictureLoadTga);

int read_header_EEFC(void *arg0, unsigned char *arg1) {
    return read_char(read_char(read_short_EFC0(read_short_EFC0(read_short_EFC0(read_short_EFC0(read_char(read_short_EFC0(read_short_EFC0(read_char(read_char(read_char(arg0, arg1), arg1 + 1), arg1 + 2), arg1 + 4), arg1 + 6), arg1 + 8), arg1 + 0xA), arg1 + 0xC), arg1 + 0xE), arg1 + 0x10), arg1 + 0x12), arg1 + 0x13) + *arg1;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_tga", read_char);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_tga", read_short_EFC0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/load_tga", copy_pixels_EFF0);
