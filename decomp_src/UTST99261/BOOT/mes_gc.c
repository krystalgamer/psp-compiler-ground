/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned int mes_ids[];
typedef struct GcCtxNode {
    struct GcCtxNode *next;           /* 0x0 */
    int f4;                           /* 0x4 */
    void *list;                       /* 0x8 */
    int fC;                           /* 0xC */
    int f10;                          /* 0x10 */
    int f14;                          /* 0x14 */
    int *sp;                          /* 0x18 */
    int size;                         /* 0x1C */
    int stack[1];                     /* 0x20 */
} GcCtxNode;
extern GcCtxNode *mes_context_head;
void mes_context_mark(void);
void mes_context_gc(void);
void mes_list_mark(void *l);
typedef struct GcMethod {
    int f0;
    int kind;
    void (*mark)(void *obj);
    void (*free)(void *obj);
} GcMethod;
typedef struct GcPage {
    struct GcPage *next;
    int f4;
} GcPage;
typedef struct GcTable {
    GcPage *pages;
    GcMethod *method;
    int *freelist;
    int objsize;
    int perpage;
    int nfree;
    int nalloc;
    int threshold;
} GcTable;
typedef struct GcCtx {
    char pad[0x14];
    int error;
} GcCtx;
extern GcTable mes_gc_table[13];
void *MEM_malloc(int heap, unsigned int size);
void MEM_free(int heap, void *p);
void mes_memory_zero(void *p, int n);
void mes_gc_gc();
extern int mes_gc_enabled;



#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_gc_table_clear(void)
{
    int i;
    GcTable *t;

    mes_gc_enabled = 0;
    i = 0;
    do {
        t = &mes_gc_table[i];
        t->pages = NULL;
        t->method = NULL;
        t->freelist = NULL;
        t->objsize = 0;
        t->perpage = 0;
        t->nfree = 0;
        t->nalloc = 0;
        t->threshold = 0;
        i++;
    } while (i < 13);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_gc_register(GcMethod *m, int objsize, int perpage, int threshold)
{
    GcTable *t = &mes_gc_table[m->kind];

    t->pages = NULL;
    t->method = m;
    t->freelist = NULL;
    t->objsize = objsize;
    t->perpage = perpage;
    t->nfree = 0;
    t->nalloc = 0;
    t->threshold = threshold;
}

void mes_gc_mark(unsigned int v)
{
    GcMethod *m;

    switch (v & 3) {
    case 0:
        if (v > 0x20 && !(*(unsigned int *)v & 1)) {
            m = *(GcMethod **)v;
            if (m->mark != NULL) {
                m->mark((void *)v);
            } else {
                *(unsigned int *)v |= 1;
            }
        }
        break;
    case 1:
        break;
    case 2:
        *(unsigned int *)(v & ~3) |= 1;
        break;
    case 3:
        *(unsigned int *)(v & ~3) |= 1;
        break;
    }
}

void mes_gc_gc(void)
{
    GcCtxNode *c;
    int *p;
    int i;
    GcTable *t;
    GcPage *pg;
    int *o;
    int j;
    void (*fr)(void *);
    int h;

    mes_context_mark();
    for (c = mes_context_head; c != NULL; c = c->next) {
        mes_list_mark(c->list);
        mes_gc_mark(c->fC);
        mes_gc_mark(c->f10);
        mes_gc_mark(c->f14);
        for (p = c->sp; p < &c->stack[c->size]; p++)
            mes_gc_mark(*p);
    }
    mes_context_gc();
    for (i = 0; i < 13; i++) {
        t = &mes_gc_table[i];
        if (t->method != NULL) {
            t->nalloc = 0;
            t->nfree = 0;
            t->freelist = NULL;
            fr = t->method->free;
            for (pg = t->pages; pg != NULL; pg = pg->next) {
                o = (int *)(pg + 1);
                for (j = 0; j < t->perpage; j++) {
                    h = *o;
                    if (h & 1) {
                        *o = h & ~3;
                        t->nalloc++;
                    } else {
                        t->nfree++;
                        if (!(h & 2)) {
                            if (fr != NULL)
                                fr(o);
                        }
                        *o = (int)t->freelist | 2;
                        t->freelist = o;
                    }
                    o = (int *)((char *)o + t->objsize);
                }
            }
            t->threshold = t->nalloc * 2;
        }
    }
}

int *mes_gc_alloc(GcCtx *ctx, int kind)
{
    GcTable *t = &mes_gc_table[kind];
    GcPage *page;
    int *o;
    int i;

    o = t->freelist;
    if (o == NULL) {
        if (mes_gc_enabled && t->nalloc >= t->threshold) {
            mes_gc_gc();
            o = t->freelist;
        }
        if (o == NULL) {
            page = MEM_malloc(0, t->objsize * t->perpage + 8);
            if (page != NULL) {
                mes_memory_zero(page, t->objsize * t->perpage + 8);
                page->next = t->pages;
                t->pages = page;
                o = (int *)(page + 1);
                for (i = 0; i < t->perpage; i++) {
                    *o = (int)t->freelist | 2;
                    t->freelist = o;
                    o = (int *)((char *)o + t->objsize);
                }
                t->nfree += t->perpage;
            }
            o = t->freelist;
        }
    }
    if (o != NULL) {
        t->freelist = (int *)(*o & ~2);
        t->nfree--;
        t->nalloc++;
        *o = (int)t->method;
        return o;
    }
    if (ctx != NULL) {
        ctx->error = (*(int *)((char *)mes_ids + 0x70));
    }
    return NULL;
}

void mes_gc_free(void)
{
    int i, j;
    GcTable *t;
    GcPage *page;
    void (*freefn)(void *);
    char *p;

    for (i = 0; i < 13; i++) {
        t = &mes_gc_table[i];
        if (t->method == NULL)
            continue;
        t->freelist = NULL;
        t->threshold = 0;
        t->nalloc = 0;
        t->nfree = 0;
        freefn = t->method->free;
        for (page = t->pages; page != NULL; page = t->pages) {
            p = (char *)(page + 1);
            if (freefn != NULL) {
                for (j = 0; j < t->perpage; j++) {
                    if (!(*(int *)p & 2))
                        freefn(p);
                    p += t->objsize;
                }
            }
            t->pages = page->next;
            MEM_free(0, page);
        }
    }
}
