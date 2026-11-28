/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxSeqFree(int);                            /* extern */
int sgxResFindSeq();                                /* extern */


void sgxSeqCommand(int, int *);

int sgxSeqAlloc();

int SeqInit(char *s)
{
    int cmd[8];
    int id;
    id = -1;
    *(int *)(s + 0x94) = id;
    id = sgxSeqAlloc(s);
    if (id < 0) return 0;
    *(int *)(s + 0x94) = id;
    cmd[0] = 0;
    cmd[1] = 0;
    cmd[2] = *(short *)(s + 0x12);
    cmd[3] = *(int *)(s + 0x14);
    cmd[4] = *(int *)(s + 0x18);
    sgxSeqCommand(id, cmd);
    return 1;
}

int SeqStrInit(char *s)
{
    int cmd[8];
    int id;
    *(int *)(s + 0x94) = -1;
    id = sgxSeqAlloc(s);
    if (id < 0) return 0;
    *(int *)(s + 0x94) = id;
    cmd[0] = 1;
    cmd[2] = *(int *)(s + 0x14);
    cmd[1] = 0;
    cmd[3] = *(int *)(s + 0x18);
    sgxSeqCommand(id, cmd);
    return 1;
}

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

int sgxSeqGetStatus(int);

void SeqProcPost(char *s)
{
    int id = *(int *)(s + 0x94);
    int st, r;
    if (id < 0) return;
    sgxDI();
    st = *(int *)(s + 0xC);
    r = sgxSeqGetStatus(id);
    st = (st & ~0x142) | (r & 0x142);
    st |= 0x20;
    if (r & 4) st &= ~0x42;
    if (!(r & 2)) {
        st &= ~2;
        st |= 0x10;
    }
    *(int *)(s + 0xC) = st;
    sgxEI();
}

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
