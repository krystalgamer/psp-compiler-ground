/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern MesClassDef mes_anchor_def;
extern MesClass *mes_anchor_class;

MesValue mes_anchor_get(MesContext *ctx, MesObject *obj, void *elem, int id)
{
    DOMString s;
    int x, y;

    if (elem != NULL) {
        switch (id) {
        case 1:
            s = Element_getAttribute(elem, &_DOMname);
            return mes_string_new(ctx, s.str, s.len);
        case 2:
            s = Node_getNodeValue(Node_getFirstChild(elem));
            return mes_string_new(ctx, s.str, s.len);
        case 3:
            if (JSI_getElementPosition(elem, &x, &y) == 1)
                return MES_INT(x);
        case 4:
            if (JSI_getElementPosition(elem, &x, &y) == 1)
                return MES_INT(y);
            break;
        }
    }
    return MES_UNDEFINED;
}

void mes_anchor_mark(void) {
}

void mes_anchor_free(void) {
}

void mes_anchor_class_init(MesContext *ctx)
{
    mes_anchor_class = mes_class_init(ctx, &mes_anchor_def);
}

MesObject *mes_anchor_new(MesContext *ctx, void *elem)
{
    MesObject *obj = mes_class_new(ctx, mes_anchor_class);
    mes_class_private_set(obj, elem);
    return obj;
}
