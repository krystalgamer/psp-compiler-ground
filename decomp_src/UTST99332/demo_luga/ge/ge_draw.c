/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon1 { /* size 0x14 */
    int type;
    int u;
    int v;
    void *index;
    void *p;
};
typedef struct _anon1 geBEZIER;
struct _anon2;
struct _anon2 { /* size 0x1c */
    int type;
    int u;
    int v;
    int uflag;
    int vflag;
    void *index;
    void *p;
};
typedef struct _anon2 geSPLINE;
struct _anon3;
struct _anon3 { /* size 0x14 */
    int prim;
    int type;
    int count;
    void *index;
    void *p;
};
typedef struct _anon3 gePRIM;



void geDrawBezier(geBEZIER *p);
void geDrawSpline(geSPLINE *p);
void geDrawArray(gePRIM *p);


void geDrawBezier(geBEZIER *p) {
    sceGumDrawBezier(p->type, p->u, p->v, p->index, p->p);
}

void geDrawSpline(geSPLINE *p) {
    sceGumDrawSpline(p->type, p->u, p->v, p->uflag, p->vflag, p->index, p->p);
}

void geDrawArray(gePRIM *p) {
    sceGumDrawArray(p->prim, p->type, p->count, p->index, p->p);
}
