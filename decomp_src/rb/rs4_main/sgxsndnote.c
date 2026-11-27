#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxPortFree(int);                           /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", WaveInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", NoteInit);

#ifndef NULL
#define NULL ((void *)0)
#endif

void NoteTerm(void *arg0) {
    int temp_v0;

    temp_v0 = M2C_FIELD(arg0, int *, 0x94);
    if (temp_v0 >= 0) {
        sgxPortFree(temp_v0);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", NoteProcPost);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", NotePause);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", NoteRel);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", WaveCalcBufAlign);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", WaveCheckReq);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", NoteCheckReq);
