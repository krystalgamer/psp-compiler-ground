/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int uint;
struct _anon1;
struct _anon1 { /* size 0x10 */
    int state;
    int alpha;
    int step;
    uint color;
};
typedef struct _anon1 geFADE;
struct _anon2;
struct _anon2 { /* size 0x6 */
    short int p[3];
};
typedef struct _anon2 ge2DV16;

extern geFADE geFade;
extern geFADE *pFade;
extern ge2DV16 fade_model[15][2];

void geFadeDraw(void);
void geFadeSetup(int mode, int step, uint c);
int geFadeState(void);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuColor(unsigned int color);
void sceGuDisable(int state);
void sceGuEnable(int state);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
int sceKernelDcacheWritebackAll(void);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_effect", geFadeDraw);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_effect", geFadeSetup);

int geFadeState(void) {
    return pFade->state;
}
