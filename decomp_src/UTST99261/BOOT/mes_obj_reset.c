/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern MesClassDef mes_reset_def;
extern MesClass *mes_reset_class;

int mes_reset_handle_event(MesContext *ctx, MesObject *obj)
{
    short type = g_JS_EVENT_REC_->type;

    if (type == 2 || type == 4 || type == 8 || type == 13 || type == 14 || type == 15 || type == 16 || type == 17)
        return mes_event_handle_event(ctx, obj, type);
    return 12;
}

MesValue mes_reset_get(MesContext *ctx, MesObject *obj, void *elem, int id)
{
    return mes_input_get(ctx, obj, elem, id, 18);
}

int mes_reset_put(MesContext *ctx, MesObject *obj, void *elem, int id, MesValue v)
{
    return mes_input_put(ctx, obj, elem, id, 18, v);
}

void mes_reset_mark(void) {
}

void mes_reset_class_init(MesContext *ctx)
{
    mes_reset_class = mes_class_init(ctx, &mes_reset_def);
}

MesObject *mes_reset_new(MesContext *ctx, void *elem)
{
    MesObject *obj = mes_class_new(ctx, mes_reset_class);
    mes_class_private_set(obj, elem);
    return obj;
}
