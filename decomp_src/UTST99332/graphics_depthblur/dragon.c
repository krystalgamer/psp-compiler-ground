#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuColor(unsigned int color);
void sceGuDisable(int state);
void sceGuEnable(int state);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGumDrawBezier(int vtype, int ucount, int vcount, const void *indices, const void *vertices);
void sceGumDrawSpline(int vtype, int ucount, int vcount, int uedge, int vedge, const void *indices, const void *vertices);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", DrawDragon);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", body);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", face);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", head);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", horn1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", horn2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", l_hand);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", l_foot);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", l_leg1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", l_leg2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", r_foot);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", r_leg1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", r_leg2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", wing1);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", wing2);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", wing_skin);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", clut_face);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", chr_face);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", clut_body);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", chr_body);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/dragon", chr_wing);
