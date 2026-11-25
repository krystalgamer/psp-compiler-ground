#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon1 { /* size 0x10 */
    unsigned int color;
    int unum;
    int vnum;
    const float *vert;
};
typedef struct _anon1 RING_PARTS;
struct _anon2;
typedef unsigned int u_int32;
struct ScePspFVector3;
struct ScePspFVector3 { /* size 0xc */
    float x;
    float y;
    float z;
};
typedef struct ScePspFVector3 ScePspFVector3;
struct _anon2 { /* size 0x68 */
    u_int32 amb;
    u_int32 diff;
    u_int32 spec;
    ScePspFVector3 pos;
    ScePspFVector3 dir;
    float exp;
    float cut;
    float atte[3];
    ScePspFVector3 trans;
    ScePspFVector3 rot;
    ScePspFVector3 angle;
    ScePspFVector3 speed;
};
typedef struct _anon2 LIGHT_INFO;
struct _anon3;
struct _anon3 { /* size 0x1c */
    int w;
    int h;
    int tw;
    float scalex;
    float scaley;
    const unsigned int *clut;
    const unsigned int *tex;
};
typedef struct _anon3 TEX_INFO;

extern LIGHT_INFO spots;
extern const unsigned int wall_clut[8];
extern const unsigned int guest_clut[8];
extern const unsigned int wall_tex[32];
extern const unsigned int guest_tex[128];
extern TEX_INFO tinfo[2];
extern const float light_body[5][48];
extern const float light_arm[48];
extern const float light_spot[5][48];
extern const float mat[48];
extern const float wall[48];
extern const float guest[48];
extern const float pole_1[48];
extern const float pole_2[48];
extern const float pole_head[48];
extern const float cushion[60];
extern const float rope[48];
extern const ScePspFVector3 rot[4];
extern const ScePspFVector3 trans[3];
extern const ScePspFVector3 light_pos;
extern const ScePspFVector3 light_trans;
extern RING_PARTS ring_parts[11];

void DrawRing(void);

/* SDK functions (tools/sdk_protos.h) */
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexWrap(int u, int v);
void sceGuTexOffset(float u, float v);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);


void InitRing(void) {
    sceGuTexMode(4, 0, 0, 0);
    sceGuTexFilter(7, 1);
    sceGuTexFunc(0, 1);
    sceGuTexWrap(0, 0);
    sceGuTexMapMode(0, 0U, 1U);
    sceGuTexOffset(0.0f, 0.0f);
    sceGuClutMode(1U, 0U, 0xFFU, 0U);
}

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", wall_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", guest_clut);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", wall_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", guest_tex);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", light_body);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", light_arm);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", light_spot);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", mat);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", wall);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", guest);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", pole_1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", pole_2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", pole_head);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", cushion);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", rope);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", rot);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", trans);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", light_pos);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", light_trans);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_spots/nonmatchings/ring", DrawRing);
