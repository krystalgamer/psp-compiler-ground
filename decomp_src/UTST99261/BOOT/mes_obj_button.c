/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern MesClassDef mes_button_def;
extern MesClass *mes_button_class;

int mes_button_handle_event(MesContext *ctx, MesObject *obj)
{
    short type = g_JS_EVENT_REC_->type;

    if (type == 2 || type == 4 || type == 8 || type == 13 || type == 14 || type == 15 || type == 16 || type == 17)
        return mes_event_handle_event(ctx, obj, type);
    return 12;
}

MesValue mes_button_get(MesContext *ctx, MesObject *obj, void *elem, int id)
{
    return mes_input_get(ctx, obj, elem, id, 12);
}

int mes_button_put(MesContext *ctx, MesObject *obj, void *elem, int id, MesValue v)
{
    return mes_input_put(ctx, obj, elem, id, 12, v);
}

void mes_button_mark(void) {
}

void mes_button_class_init(MesContext *ctx)
{
    mes_button_class = mes_class_init(ctx, &mes_button_def);
}

MesObject *mes_button_new(MesContext *ctx, void *elem)
{
    MesObject *obj = mes_class_new(ctx, mes_button_class);
    mes_class_private_set(obj, elem);
    return obj;
}
