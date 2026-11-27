/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern MesClassDef mes_link_def;
extern MesClass *mes_link_class;

int mes_link_handle_event(MesContext *ctx, MesObject *obj)
{
    short type = g_JS_EVENT_REC_->type;

    if (type == 2 || type == 4 || type == 8 || type == 13 || type == 14 || type == 15 || type == 16 || type == 17)
        return mes_event_handle_event(ctx, obj, type);
    return 12;
}

MesValue mes_link_get(MesContext *ctx, MesObject *obj, void *elem, int id)
{
    void *url;
    MesValue ret;

    if (elem != NULL && (url = JSI_getLinkURL(elem)) != NULL) {
        ret = mes_link_common_get_sub(ctx, elem, id, url, 11);
        JSI_freeURLRec(url);
    } else {
        ret = MES_UNDEFINED;
    }
    return ret;
}

int mes_link_put(MesContext *ctx, MesObject *obj, void *elem, int id, MesValue v)
{
    void *url;
    int ret;

    if (elem != NULL && (url = JSI_getLinkURL(elem)) != NULL) {
        ret = mes_link_common_put_sub(ctx, elem, id, v, url, 11);
        JSI_freeURLRec(url);
        return ret;
    }
    return 0;
}

void mes_link_mark(void) {
}

void mes_link_free(void) {
}

void mes_link_class_init(MesContext *ctx)
{
    mes_link_class = mes_class_init(ctx, &mes_link_def);
}

MesObject *mes_link_new(MesContext *ctx, void *elem)
{
    MesObject *obj = mes_class_new(ctx, mes_link_class);
    mes_class_private_set(obj, elem);
    return obj;
}
