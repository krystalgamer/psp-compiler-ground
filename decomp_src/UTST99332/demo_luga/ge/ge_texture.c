/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon2;
struct _anon2 { /* size 0x10 */
    void *tbp;
    int w;
    int h;
    int bw;
};
typedef struct _anon2 geTEXIMAGE;
struct _anon3;
struct _anon3 { /* size 0x14 */
    void *cbp;
    int np;
    int shift;
    int mask;
    int csa;
};
typedef struct _anon3 geCLUT;
typedef unsigned int uint;
struct _anon1 { /* size 0xe8 */
    int tpf;
    int cpf;
    int mode_lod;
    int mode_mc;
    int mode_hsm;
    geTEXIMAGE tex[8];
    geCLUT clut;
    int func_mode;
    int func_comp;
    int fil_min;
    int fil_mag;
    int wrapu;
    int wrapv;
    int level_mode;
    float level_offset;
    int map_mode;
    int map_lu;
    int map_lv;
    float su;
    float sv;
    float tu;
    float tv;
    uint col;
};
typedef struct _anon1 geTEXTURE;

extern geTEXTURE geTexture[128];

int geTexSet(int n, geTEXTURE *tex);
int geTexOption(int n, int param, geTEXTURE *tex);
int geTexGet(int n, geTEXTURE *tex);
int geTexSend(int n);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuDisable(int state);
void sceGuEnable(int state);
void sceGuTexEnvColor(unsigned int color);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexLevelMode(unsigned int mode, float bias);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGuTexWrap(int u, int v);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_texture", geTexSet);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_texture", geTexOption);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_texture", geTexGet);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_texture", geTexSend);

int geTexCombine(int a, int b) {
    return 1;
}
