/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxPortFree(int);                           /* extern */


void *sgxResFindWave();
void *sgxResFindRgn();
void sgxPortCommand(int, int *);

int sgxPortAlloc();
int sgxPortGetStatus(int);
void sgxDI();
void sgxEI();

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxsndnote", WaveInit);

int NoteInit(char *n)
{
	int cmd[12];
	int port = -1;
	*(int *)(n + 0x94) = port;
	port = sgxPortAlloc(0, n);
	if (port < 0)
		return 0;
	cmd[0] = 0;
	cmd[1] = 0;
	cmd[2] = *(short *)(n + 0x12);
	cmd[3] = *(int *)(n + 0x14);
	cmd[4] = *(int *)(n + 0x18);
	cmd[5] = 0x1000;
	sgxPortCommand(port, cmd);
	*(int *)(n + 0x94) = port;
	return 1;
}

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

void NoteProcPost(char *s)
{
    int id = *(int *)(s + 0x94);
    int st, r;
    if (id < 0) return;
    sgxDI();
    st = *(int *)(s + 0xC);
    r = sgxPortGetStatus(id);
    st = (st & ~0x160) | (r & 0x160);
    if (r & 0x40) st |= 2;
    else st &= ~2;
    if (r & 4) st &= ~0x42;
    if (!(r & 2)) {
        st &= ~2;
        st |= 0x10;
    }
    *(int *)(s + 0xC) = st;
    sgxEI();
}

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

int sgxGetFormUnitByte();
void WaveCalcBufAlign(char *n, int *align, int *size)
{
    *align = 0x10;
    if (*(short *)(n + 0x12) >= 0) {
        char *w = sgxResFindWave(*(short *)(n + 0x12), *(int *)(n + 0x14), 0);
        if (w == NULL) {
            *size = 0;
        } else {
            signed char ch = *(signed char *)(w + 9);
            *size = sgxGetFormUnitByte(*(signed char *)(w + 8)) * ch;
        }
    } else {
        *size = 0;
    }
}

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
