/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern MesClassDef mes_hidden_def;
extern MesClass *mes_hidden_class;

MesValue mes_hidden_get(MesContext *ctx, MesObject *obj, void *elem, int id)
{
    return mes_input_get(ctx, obj, elem, id, 15);
}

int mes_hidden_put(MesContext *ctx, MesObject *obj, void *elem, int id, MesValue v)
{
    return mes_input_put(ctx, obj, elem, id, 15, v);
}

void mes_hidden_mark(void) {
}

void mes_hidden_class_init(MesContext *ctx)
{
    mes_hidden_class = mes_class_init(ctx, &mes_hidden_def);
}

MesObject *mes_hidden_new(MesContext *ctx, void *elem)
{
    MesObject *obj = mes_class_new(ctx, mes_hidden_class);
    mes_class_private_set(obj, elem);
    return obj;
}
