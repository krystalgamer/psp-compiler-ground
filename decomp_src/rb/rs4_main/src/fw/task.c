/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"

int consPrintf();
extern unsigned char DefView;


int taskProc_Move(int a, int b, int c)
{
	taskProc(a, 2, b, c);
	return 0;
}

int taskProc_Free(int a, int b, int c)
{
	taskProc(a, 1, b, c);
	return 0;
}

extern int *pCurrent;
void rsvMove();
void taskMove(void *a, void *b, int c, int d)
{
	if (pCurrent)
		rsvMove(*pCurrent, a ? a : (void *)taskProc_Move, b ? b : (void *)taskProc_Free, c, d);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", taskProc_Sort);

int taskProc_Draw(int a, int b, int c)
{
	taskProc(a, 3, b, c);
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", taskDraw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", taskSetRefer);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC1E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC1F0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", taskGetRefer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", viewInit);

#ifndef NULL
#define NULL ((void *)0)
#endif

int viewTerm(void) {
    consPrintf("%s\n", "viewTerm");
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

M2C_UNK *viewGetDefault(void) {
    return &DefView;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", viewMount);

typedef struct View { struct View *next, *prev; } View;
extern View *pMount, *pChain;
void viewRemove(View *v)
{
	View *n = v->next, *p = v->prev;
	if (pMount == v)
		pMount = n;
	if (pChain == v)
		pChain = p;
	if (n)
		n->prev = p;
	if (p)
		p->next = n;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", viewProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", persMount);

#ifndef NULL
#define NULL ((void *)0)
#endif
void persRemove(void *arg0) {
    void **temp_a1;
    void *temp_a2;
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 8);
    temp_a2 = M2C_FIELD(arg0, void **, 0);
    temp_a1 = M2C_FIELD(arg0, void ***, 4);
    if (M2C_FIELD(temp_v1, void **, 0x40) == arg0) {
        M2C_FIELD(temp_v1, void **, 0x40) = temp_a2;
    }
    if (M2C_FIELD(temp_v1, void ***, 0x44) == arg0) {
        M2C_FIELD(temp_v1, void ***, 0x44) = temp_a1;
    }
    if (temp_a2 != NULL) {
        M2C_FIELD(temp_a2, void ***, 4) = temp_a1;
    }
    if (temp_a1 != NULL) {
        *temp_a1 = temp_a2;
    }
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC250);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC254);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC258);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", persSetup);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", GimSetI3dPicture);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", GpSetGIM);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC2EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC308);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC314);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC31C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", D_000FC328);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", GpSetGimTexture);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", GpDrawSpriteMtx);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", GtCalcPoint);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/task", avtGetDat);
