#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxSeqFree(int);                            /* extern */
int sgxResFindSeq();                                /* extern */


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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndseq", SeqPause);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndseq", SeqWait);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndseq", SeqRel);

#ifndef NULL
#define NULL ((void *)0)
#endif

int SeqCheckReq(void) {
    return sgxResFindSeq() != 0;
}
