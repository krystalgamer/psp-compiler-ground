/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
extern MesObject *mes_classes[];
extern unsigned int mes_ids[];
typedef struct MesNatEnt {
    const char *name;
    void *fn;                         /* 0x4 */
    unsigned char nargs;              /* 0x8 */
} MesNatEnt;
unsigned int mes_context_id2(void *ctx, const char *name);
typedef struct MesNative {
    struct MesObject obj;
    int f14;
    void *fn;                         /* 0x18 */
    unsigned char nargs;              /* 0x1C */
    unsigned char f1D;
} MesNative;
void mes_object_set(MesObject *obj, unsigned int id, MesValue value, int flags);
MesValue mes_object_get(MesObject *obj, unsigned int id);
void *mes_gc_alloc(MesContext *ctx, int kind);
void mes_object_init(MesObject *obj, int cls, MesObject *proto);
extern unsigned char mes_native_method;



MesNative *mes_native_new(MesContext *ctx, int a, void *fn, int nargs, int flags)
{
    MesNative *n = mes_gc_alloc(ctx, 4);

    if (n != NULL) {
        mes_object_init(&n->obj, 5, (*(MesObject * *)((char *)mes_classes + 0x14)));
        n->f14 = a;
        n->fn = fn;
        n->nargs = nargs;
        n->f1D = flags;
    }
    return n;
}

void mes_native_setup(MesContext *ctx, MesObject *obj, MesNatEnt *table, int n)
{
    int i;
    unsigned int id;

    for (i = 0; i < n; i++) {
        id = mes_context_id2(ctx, table[i].name);
        *--ctx->sp = id;
        mes_object_set(obj, id, (MesValue)mes_native_new(ctx, id, table[i].fn, table[i].nargs, 0), 2);
        ctx->sp++;
    }
}

MesValue mes_native_get(MesContext *ctx, MesNative *n, unsigned int id)
{
    if (n->obj.proto == NULL)
        n->obj.proto = (*(MesObject * *)((char *)mes_classes + 0x14));
    if (id == mes_ids[51])
        return MES_INT(n->nargs);
    return mes_object_get(&n->obj, id);
}

void mes_native_put(MesContext *ctx, MesNative *n, unsigned int id, MesValue v)
{
    if (id != mes_ids[51])
        mes_object_set(&n->obj, id, v, 8);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_native_mark(void *arg0) {
    mes_object_mark(arg0);
    mes_gc_mark(M2C_FIELD(arg0, int *, 0x14));
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void mes_native_free(void *arg0) {
    mes_object_free(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_native_initialize(void) {
    mes_gc_register(&mes_native_method, 0x20, 0x64, 0x64);
}
