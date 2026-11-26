/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned char uchar;
struct _anon1;
typedef unsigned int u_int32;
struct _anon1 { /* size 0x20 */
    int flag;
    int mode;
    int num_module;
    int exitflag;
    int pad_margin;
    u_int32 cont;
    u_int32 vcount;
    u_int32 rand_data;
};
typedef struct _anon1 gePROGRAM;

extern gePROGRAM *pProg;

float geAnalogDegree(int mode, uchar ax, uchar ay);
void geSetAnalogMargin(int m);


INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_control", geAnalogDegree);

void geSetAnalogMargin(int m) {
    pProg->pad_margin = m;
}
