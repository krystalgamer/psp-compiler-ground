/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern MesClassDef mes_textarea_def;
extern MesClass *mes_textarea_class;

int mes_textarea_handle_event(MesContext *ctx, MesObject *obj)
{
    short type = g_JS_EVENT_REC_->type;

    if (type == 2 || type == 3 || type == 4 || type == 8 || type == 13 || type == 14 || type == 15 || type == 16 || type == 17 || type == 21)
        return mes_event_handle_event(ctx, obj, type);
    return 12;
}

MesValue mes_textarea_get(MesContext *ctx, MesObject *obj, void *elem, int id)
{
    return mes_input_get(ctx, obj, elem, id, 22);
}

int mes_textarea_put(MesContext *ctx, MesObject *obj, void *elem, int id, MesValue v)
{
    return mes_input_put(ctx, obj, elem, id, 22, v);
}

void mes_textarea_mark(void) {
}

void mes_textarea_class_init(MesContext *ctx)
{
    mes_textarea_class = mes_class_init(ctx, &mes_textarea_def);
}

MesObject *mes_textarea_new(MesContext *ctx, void *elem)
{
    MesObject *obj = mes_class_new(ctx, mes_textarea_class);
    mes_class_private_set(obj, elem);
    return obj;
}
