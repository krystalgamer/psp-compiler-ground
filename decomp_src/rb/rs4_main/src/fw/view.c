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

void viewMount(View *v)
{
	View *m = pMount;
	if (!m)
		m = v;
	v->next = NULL;
	v->prev = pChain;
	pMount = m;
	if (pChain)
		pChain->next = v;
	pChain = v;
}

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

void sortPrio(void *, int, int, int, void *);

void viewProc(void (*f0)(void *, int), void (*f1)(void *, int), void (*f2)(void *, int), int arg) {
    char *v;
    char *top;

    sortPrio(pMount, 0xC, 0, 0x4C, &top);
    for (v = top; v != NULL; v = *(char **)(v + 0x4C)) {
        if (*(int *)(v + 8) != 0) {
            if (f0 != NULL) f0(v, arg);
            if (f1 != NULL) f1(v, arg);
            if (f2 != NULL) f2(v, arg);
        }
    }
}

typedef struct Pers { struct Pers *next, *prev; struct PView *view; } Pers;
typedef struct PView { char pad[0x40]; Pers *head, *chain; } PView;
void persMount(PView *v, Pers *p)
{
	if (v == NULL)
		v = (PView *)&DefView;
	p->next = NULL;
	p->view = v;
	p->prev = v->chain;
	if (v->head == NULL)
		v->head = p;
	if (v->chain)
		v->chain->next = p;
	v->chain = p;
}

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

void copSclVec(void *, void *, float);
void sceGumPerspective(float, float, float, float);
void persSetup(char *p) {
    float v[4];
    float proj[16];
    float m[16];
    char *mat;

    copLetVec(p + 0x20, p + 0x90);
    copSclVec(p + 0x20, v, -1.0f);
    mat = p + 0xA0;
    copRevMat3(p + 0x60, mat);
    copRotVec(mat, v, p + 0xD0);
    memset(m, 0, 0x40);
    m[0] = -1.0f;
    m[10] = -1.0f;
    m[5] = 1.0f;
    m[15] = 1.0f;
    copMulMat(m, mat, m);
    sceGumMatrixMode(0);
    sceGumLoadIdentity();
    sceGumPerspective(*(float *)(p + 0x30), 1.7647059f, 1.0f, 65535.0f);
    sceGumStoreMatrix(proj);
    sceGuSetMatrix(0, proj);
    sceGumMatrixMode(1);
    sceGumLoadMatrix(m);
    sceGuSetMatrix(1, m);
    sceGumMatrixMode(2);
}
