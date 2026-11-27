/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

void consPrintf(const char *, ...);
extern unsigned char DefView;

typedef struct View { struct View *next, *prev; } View;
extern View *pMount, *pChain;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/view", viewInit);

int viewTerm(void) {
    consPrintf("%s\n", "viewTerm");
    return 1;
}

M2C_UNK *viewGetDefault(void) {
    return &DefView;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/view", viewMount);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/view", viewProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/view", persMount);

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

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/view", D_000FC250);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/view", D_000FC254);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/fw/view", D_000FC258);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/fw/view", persSetup);
