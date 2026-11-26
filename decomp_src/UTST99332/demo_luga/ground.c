/* cflags: -O2 -frename-registers */
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
typedef unsigned int uint;
struct _anon3;
struct _anon4;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon4 { /* size 0x24 */
    ScePspFVector3 trans;
    ScePspFVector3 rotate;
    ScePspFVector3 scale;
};
typedef struct _anon4 geWORLD;
struct _anon5;
struct ScePspFMatrix4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
} __attribute__((aligned(16)));
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
typedef struct ScePspFMatrix4 ScePspFMatrix4;
struct _anon5 { /* size 0xb0 */
    int type;
    int model;
    int motion;
    float step;
    ScePspFVector3 t;
    ScePspFVector3 r;
    ScePspFVector3 s;
    ScePspFMatrix4 m;
    ScePspFVector3 co[2];
    uint swflag;
    int dummy[3];
};
typedef struct _anon5 geOBJECT;
struct _anon3 { /* size 0xb50 */
    int walkmode;
    int nextgnd;
    int count;
    int light_dir;
    int light_flag;
    int light_cnt;
    int obj_num;
    int tex_num;
    int face;
    int face_cnt;
    int face_wait;
    geWORLD world;
    geOBJECT obj[16];
};
typedef struct _anon3 *PMAINDATA;

extern unsigned char map_0[81000];
extern unsigned char map_1[107088];
extern unsigned char map_2[107996];
extern unsigned char map_3[88468];
extern unsigned char map_4[100296];
extern unsigned char map_5[57536];
extern PMAINDATA md;

int post_ground(void);
void set_nextgnd(void);
void texture_gorund(SceGimPicture *picture);
void init_ground(void);
void draw_ground(void);
static void __sort_gnd(int *lst);
static uint set_ground_light(float z);


/* module functions defined in other units */
int geModelLoad(int num, int *model, int size);
void geModelNormalTexFunc(SceGimPicture *picture);
void geModelSetTexFunc(void (*callback)(SceGimPicture *));
void geModelTexFunc(int mode);
void geObjectDraw(geOBJECT *obj);
int geTexSend(int n);
void light_ctrl(uint c);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", post_ground);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", set_nextgnd);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", D_00020E40);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", D_00020E44);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", D_00020E48);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", D_00020E4C);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", D_00020E50);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", D_00020E54);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", texture_gorund);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", init_ground);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", draw_ground);

void term_ground(void) {
    geModelDelete(3);
    geModelDelete(4);
    geModelDelete(5);
    geModelDelete(6);
    geModelDelete(7);
    geModelDelete(8);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", __sort_gnd);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", set_ground_light);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", D_00020E80);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", D_00020F30);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", D_00020FE0);

INCLUDE_RODATA("tmp/asm/UTST99332/demo_luga/nonmatchings/ground", D_00021090);
