#include "common.h"
#include "m2c_macros.h"
extern int g_nInst;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/part", _partDrawPart2D);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/part", _partDrawPart3D);

#ifndef NULL
#define NULL ((void *)0)
#endif

void partSetInst(int arg0) {
    g_nInst = arg0;
}
