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


INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_texture", geTexSet);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_texture", geTexOption);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_texture", geTexGet);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_texture", geTexSend);

int geTexCombine(int a, int b) {
    return 1;
}
