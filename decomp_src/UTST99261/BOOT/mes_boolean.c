/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern MesObject *mes_classes[];
extern unsigned int mes_ids[];
extern void *mes_boolean_table;
MesValue mes_boolean_constructor(MesContext *ctx, MesValue v);
void *mes_native_new(MesContext *ctx, int a, void *fn, int nargs, int flags);
void mes_native_setup(MesContext *ctx, MesObject *o, void *table, int n);
void mes_object_set(MesObject *obj, unsigned int id, MesValue value, int flags);
typedef struct MesValueObj {
    struct MesObject obj;
} MesValueObj;
MesValue mes_eval_to_boolean(MesContext *ctx, MesValue v);
MesValue mes_eval_type_error(MesContext *ctx);
MesObject *mes_object_new(MesContext *ctx, int cls, MesObject *proto);

MesValue mes_boolean_constructor(MesContext *ctx, MesValue v)
{
    MesValue b = mes_eval_to_boolean(ctx, v);
    MesObject *o;

    if (ctx->frame->construct) {
        o = mes_object_new(ctx, 1, mes_classes[1]);
        o->fC = b;
        return (MesValue)o;
    }
    return b;
}

MesValue mes_boolean_to_string(MesContext *ctx)
{
    MesValue v = (MesValue)ctx->frame->thisobj;

    if (MES_IS_OBJECT(v))
        v = ((MesObject *)v)->fC;
    if (v == MES_TRUE)
        return (*(MesValue *)((char *)&mes_ids + 0x104));
    if (v == MES_FALSE)
        return (*(MesValue *)((char *)&mes_ids + 0xAC));
    return mes_eval_type_error(ctx);
}

MesValue mes_boolean_value_of(MesContext *ctx)
{
    MesValue v = (MesValue)ctx->frame->thisobj;

    if (MES_IS_OBJECT(v))
        v = ((MesObject *)v)->fC;
    if (v != MES_TRUE && v != MES_FALSE)
        return mes_eval_type_error(ctx);
    return v;
}

void mes_boolean_setup(MesContext *ctx)
{
    MesObject *proto;
    MesObject *ctor;

    proto = mes_object_new(ctx, 1, mes_classes[9]);
    mes_classes[1] = proto;
    proto->fC = 8;
    ctor = mes_native_new(ctx, mes_ids[1], mes_boolean_constructor, 1, 1);
    mes_object_set(ctx->global, mes_ids[1], (MesValue)ctor, 7);
    mes_object_set(ctor, mes_ids[59], (MesValue)proto, 7);
    mes_object_set(proto, mes_ids[40], (MesValue)ctor, 2);
    mes_native_setup(ctx, proto, &mes_boolean_table, 2);
}
