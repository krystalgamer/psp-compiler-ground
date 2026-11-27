#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxPortFree(int);                           /* extern */


void *sgxResFindWave();
void *sgxResFindRgn();
void sgxPortCommand(int, int *);

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

void NotePause(char *s, int x)
{
    int cmd[12];
    cmd[0] = 17;
    cmd[1] = x;
    sgxPortCommand(*(int *)(s + 0x94), cmd);
}

void NoteRel(char *s, int x)
{
    int cmd[12];
    cmd[0] = 4;
    cmd[2] = x;
    cmd[1] = 0;
    sgxPortCommand(*(int *)(s + 0x94), cmd);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", WaveCalcBufAlign);

int WaveCheckReq(int a, int b)
{
    return sgxResFindWave(a, b, 0) != NULL;
}

int NoteCheckReq(int a, int b)
{
    int n;
    int r = 0;
    if (sgxResFindRgn(a, b, &n) != NULL && n > 0) r = 1;
    return r;
}
