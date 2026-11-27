/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
typedef struct MesValueObj {
    struct MesObject obj;
} MesValueObj;
extern MesObject *D_00585334;
extern MesValue D_0058531C;           /* "true" */
extern MesValue D_005852C4;           /* "false" */
MesValue mes_eval_to_boolean(MesContext *ctx, MesValue v);
MesValue mes_eval_type_error(MesContext *ctx);
MesObject *mes_object_new(MesContext *ctx, int cls, MesObject *proto);

MesValue mes_boolean_constructor(MesContext *ctx, MesValue v)
{
    MesValue b = mes_eval_to_boolean(ctx, v);
    MesObject *o;

    if (ctx->frame->construct) {
        o = mes_object_new(ctx, 1, D_00585334);
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
        return D_0058531C;
    if (v == MES_FALSE)
        return D_005852C4;
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_boolean", mes_boolean_setup);
