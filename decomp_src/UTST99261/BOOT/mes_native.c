/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
typedef struct MesNative {
    struct MesObject obj;
    int f14;
    void *fn;                         /* 0x18 */
    unsigned char nargs;              /* 0x1C */
    unsigned char f1D;
} MesNative;
extern unsigned int D_005852E4;       /* "length" */
extern MesObject *D_00585344;
void mes_object_set(MesObject *obj, unsigned int id, MesValue value, int flags);
MesValue mes_object_get(MesObject *obj, unsigned int id);
void *mes_gc_alloc(MesContext *ctx, int kind);
void mes_object_init(MesObject *obj, int cls, MesObject *proto);
extern unsigned char mes_native_method;



MesNative *mes_native_new(MesContext *ctx, int a, void *fn, int nargs, int flags)
{
    MesNative *n = mes_gc_alloc(ctx, 4);

    if (n != NULL) {
        mes_object_init(&n->obj, 5, D_00585344);
        n->f14 = a;
        n->fn = fn;
        n->nargs = nargs;
        n->f1D = flags;
    }
    return n;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_native", mes_native_setup);

MesValue mes_native_get(MesContext *ctx, MesNative *n, unsigned int id)
{
    if (n->obj.proto == NULL)
        n->obj.proto = D_00585344;
    if (id == D_005852E4)
        return MES_INT(n->nargs);
    return mes_object_get(&n->obj, id);
}

void mes_native_put(MesContext *ctx, MesNative *n, unsigned int id, MesValue v)
{
    if (id != D_005852E4)
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
