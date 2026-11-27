/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern MesClassDef mes_checkbox_def;
extern MesClass *mes_checkbox_class;

int mes_checkbox_handle_event(MesContext *ctx, MesObject *obj)
{
    short type = g_JS_EVENT_REC_->type;

    if (type == 2 || type == 4 || type == 8 || type == 13 || type == 14 || type == 15 || type == 16 || type == 17)
        return mes_event_handle_event(ctx, obj, type);
    return 12;
}

MesValue mes_checkbox_get(MesContext *ctx, MesObject *obj, void *elem, int id)
{
    return mes_input_get(ctx, obj, elem, id, 13);
}

int mes_checkbox_put(MesContext *ctx, MesObject *obj, void *elem, int id, MesValue v)
{
    return mes_input_put(ctx, obj, elem, id, 13, v);
}

void mes_checkbox_mark(void) {
}

void mes_checkbox_class_init(MesContext *ctx)
{
    mes_checkbox_class = mes_class_init(ctx, &mes_checkbox_def);
}

MesObject *mes_checkbox_new(MesContext *ctx, void *elem)
{
    MesObject *obj = mes_class_new(ctx, mes_checkbox_class);
    mes_class_private_set(obj, elem);
    return obj;
}
