/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
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
extern int D_00585288;
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_gc", mes_gc_mark);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_gc", mes_gc_gc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_gc", mes_gc_alloc);

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
