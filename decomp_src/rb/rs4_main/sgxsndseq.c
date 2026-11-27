#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxSeqFree(int);                            /* extern */
int sgxResFindSeq();                                /* extern */


void sgxSeqCommand(int, int *);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndseq", SeqInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndseq", SeqStrInit);

#ifndef NULL
#define NULL ((void *)0)
#endif

void SeqTerm(void *arg0) {
    int temp_v0;

    temp_v0 = M2C_FIELD(arg0, int *, 0x94);
    if (temp_v0 >= 0) {
        sgxSeqFree(temp_v0);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndseq", SeqProcPost);

void SeqPause(char *s, int x)
{
    int cmd[8];
    cmd[0] = 6;
    cmd[1] = x;
    sgxSeqCommand(*(int *)(s + 0x94), cmd);
}

void SeqWait(char *s, int x)
{
    int cmd[8];
    cmd[0] = 7;
    cmd[1] = x;
    sgxSeqCommand(*(int *)(s + 0x94), cmd);
}

void SeqRel(char *s, int x)
{
    int cmd[8];
    cmd[0] = 2;
    cmd[2] = x;
    cmd[1] = 0;
    sgxSeqCommand(*(int *)(s + 0x94), cmd);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int SeqCheckReq(void) {
    return sgxResFindSeq() != 0;
}
