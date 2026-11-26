/* cflags: -O2 -frename-registers */
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
typedef struct ScePspFVector3 ScePspFVector3;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFMatrix4 ScePspFMatrix4;
struct ScePspFMatrix4;
typedef struct ScePspFVector4 ScePspFVector4;
struct ScePspFVector4;
struct ScePspFVector4 { /* size 0x10 */
    float x;
    float y;
    float z;
    float w;
};
struct ScePspFMatrix4 { /* size 0x40 */
    ScePspFVector4 x;
    ScePspFVector4 y;
    ScePspFVector4 z;
    ScePspFVector4 w;
};
typedef unsigned int uint;
struct _anon3 { /* size 0xb0 */
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
typedef struct _anon3 geOBJECT;
typedef struct SceGmoModel SceGmoModel;
struct SceGmoModel;

extern char ge_heap_buf[2097152];
extern SceGmoModel *ge_model[128];
extern int ge_tex_mode;
extern void (*ge_tex_callback)(SceGimPicture *);
extern int (*ObjProc[128])(void *);

void geModelNormalTexFunc(SceGimPicture *picture);
void geObjectDraw(geOBJECT *obj);
float geModelMotionFrame(int num);
void geModelDraw(int num, float step);
int geModelLoad(int num, int *model, int size);
void geModelDelete(int num);
void geModelMotion(int num, int motion);
void geModelInit(int heap);
void geModelTexFunc(int mode);
void geModelTerm(void);
void geModelSetTexFunc(void (*callback)(SceGimPicture *));
int geModelDoTextureFunc(SceGimPicture *picture);
void geObjectSetProc(int n, int (*proc)(void *));
void geObjectSwitch(geOBJECT *obj, int num);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuEnable(int state);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexWrap(int u, int v);
void sceGumMatrixMode(int mode);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);
void sceGumRotateX(float angle);
void sceGumRotateY(float angle);
void sceGumRotateZ(float angle);
void sceGumScale(const ScePspFVector3 *v);
void sceGumStoreMatrix(ScePspFMatrix4 *m);
void sceGumTranslate(const ScePspFVector3 *v);

/* module functions defined in other units */
void geDrawFinWait(void);
void geDrawStart(void);
void sceGmoModelAnimate(SceGmoModel *model, float step);
void sceGmoModelDelete(SceGmoModel *model);
void sceGmoModelDraw(SceGmoModel *model);
void sceGmoModelSetCurrentMotion(SceGmoModel *model, int idx, float delay);
void sceGmoModelUpdate(SceGmoModel *model);

/* module functions defined in other units */
int sceGmoModelGetCurrentMotion(SceGmoModel *model);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_model", geModelNormalTexFunc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_model", geObjectDraw);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_model", geModelLoad);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_model", geModelDelete);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_model", geModelDraw);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_model", geModelMotion);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_model", geModelMotionFrame);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_model", geModelInit);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_model", geModelTerm);

void geModelTexFunc(int mode) {
    ge_tex_mode = mode;
}

void geModelSetTexFunc(void (*callback)(SceGimPicture *)) {
    ge_tex_callback = callback;
}

int geModelDoTextureFunc(SceGimPicture *picture) {
    int var_a1;

    var_a1 = 0;
    switch (ge_tex_mode) {                          /* irregular */
    case 0:
        break;
    case 1:
        if (ge_tex_callback != NULL) {
            ge_tex_callback(picture);
            var_a1 = 1;
        }
        break;
    }
    return var_a1;
}

void geObjectSetProc(int n, int (*proc)(void *)) {
    ObjProc[n] = proc;
}

void geObjectSwitch(geOBJECT *obj, int num) {
    int temp_a2;

    if (obj->type == 0) {
        temp_a2 = obj->dummy[2];
        if ((temp_a2 >= 0) && !(temp_a2 & 0x40000000)) {
            obj->dummy[2] = num | 0x80000000;
        }
    }
}
