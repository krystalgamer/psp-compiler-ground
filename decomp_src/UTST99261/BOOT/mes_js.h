#ifndef MES_JS_H
#define MES_JS_H

/* JavaScript engine (mes_*) of the browser */

#include "dom_domi.h"

typedef int MesValue;                 /* tagged value: (int << 2) | 1, 0x20 = undefined */
typedef struct MesContext MesContext;
typedef struct MesObject MesObject;
typedef struct MesClass MesClass;
typedef struct MesClassDef MesClassDef;

#define MES_INT(i) (((i) << 2) | 1)
#define MES_NULL 4
#define MES_UNDEFINED 0x20

typedef struct JSEventRec {
    short type;
} JSEventRec;

extern JSEventRec *g_JS_EVENT_REC_;

MesClass *mes_class_init(MesContext *ctx, MesClassDef *def);
MesObject *mes_class_new(MesContext *ctx, MesClass *cls);
void mes_class_private_set(MesObject *obj, void *priv);
MesValue mes_string_new(MesContext *ctx, const void *str, int len);
int mes_event_handle_event(MesContext *ctx, MesObject *obj, int type);
MesValue mes_input_get(MesContext *ctx, MesObject *obj, void *elem, int id, int type);
int mes_input_put(MesContext *ctx, MesObject *obj, void *elem, int id, int type, MesValue v);

/* JS interface (JSI) to the browser */
void *JSI_getLinkURL(void *elem);
void JSI_freeURLRec(void *url);
MesValue mes_link_common_get_sub(MesContext *ctx, void *elem, int id, void *url, int type);
int mes_link_common_put_sub(MesContext *ctx, void *elem, int id, MesValue v, void *url, int type);

/* DOM API (DOMAPI.c) */
extern DOMString _DOMname;
DOMString Element_getAttribute(void *elem, DOMString *name);
void *Node_getFirstChild(void *node);
DOMString Node_getNodeValue(void *node);
int JSI_getElementPosition(void *elem, int *x, int *y);

#endif
