#ifndef MES_JS_H
#define MES_JS_H

/* JavaScript engine (mes_*) of the browser */

#include "dom_domi.h"

typedef int MesValue;                 /* tagged value: (int << 2) | 1, 0x20 = undefined */
typedef struct MesContext MesContext;
typedef struct MesObject MesObject;
typedef struct MesClass MesClass;
typedef struct MesClassDef MesClassDef;
typedef struct MesPage MesPage;

/* property: id is a string/atom value, kept sorted in a B-tree of pages */
typedef struct MesProp {
    unsigned int id;
    MesValue value;
    signed char flags;
} MesProp;

struct MesPage {
    int n;
    MesProp items[4];
    MesPage *child[5];
};

struct MesObject {
    int f0;
    MesPage *props;
    MesObject *proto;
    int fC;
    signed char cls;
};

#define MES_INT(i) (((i) << 2) | 1)
#define MES_NULL 4
#define MES_FALSE 8
#define MES_TRUE 12
#define MES_IS_OBJECT(v) ((((v) & 3) == 0) & ((unsigned int)(v) > 0x20))
#define MES_UNDEFINED 0x20

/* per-call state: this object at 0x1C */
typedef struct MesArgs {
    int argc;
    MesValue argv[1];
} MesArgs;

typedef struct MesFrame {
    char pad[0x16];
    unsigned char construct;          /* 0x16: called with new */
    char pad17[5];
    MesObject *thisobj;
    int f20;
    MesArgs *args;
} MesFrame;

struct MesContext {
    char pad[0x10];
    MesFrame *frame;
    int f14;
    MesValue *sp;                     /* value stack, grows down */
    char pad1C[0x24];
    MesValue stack[1];                /* 0x40 */
};

typedef struct JSEventRec {
    short type;
} JSEventRec;

extern JSEventRec *g_JS_EVENT_REC_;

MesClass *mes_class_init(MesContext *ctx, MesClassDef *def);
MesObject *mes_class_new(MesContext *ctx, MesClass *cls);
void mes_class_private_set(MesObject *obj, void *priv);
void *mes_class_private_get(MesObject *obj);
void mes_gc_mark(MesValue v);
void *MEM_malloc(int heap, unsigned int size);
void MEM_free(int heap, void *p);
MesValue mes_eval_to_string(MesContext *ctx, MesValue v);
MesValue mes_string_new(MesContext *ctx, const void *str, int len);
int mes_event_handle_event(MesContext *ctx, MesObject *obj, int type);
MesValue mes_input_get(MesContext *ctx, MesObject *obj, void *elem, int id, int type);
int mes_input_put(MesContext *ctx, MesObject *obj, void *elem, int id, int type, MesValue v);

/* JS interface (JSI) to the browser */
void *JSI_getLinkURL(void *elem);
void JSI_freeURLRec(void *url);
MesValue mes_link_common_get_sub(MesContext *ctx, void *elem, int id, void *url, int type);
int mes_link_common_put_sub(MesContext *ctx, void *elem, int id, MesValue v, void *url, int type);

typedef struct IpcMsg {
    int w[8];
} IpcMsg;

void SetIpcMember(IpcMsg *msg, int a, int sid, int b, int cmd, int c, int d, void *node);
void JSSendMail(IpcMsg *msg, const char *name);

/* DOM API (DOMAPI.c) */
extern DOMString _DOMname;
DOMString Element_getAttribute(void *elem, DOMString *name);
void *Node_getFirstChild(void *node);
void *Node_getOwnerDocument(void *node);
int Node_getSid(void *node);
DOMString Node_getNodeValue(void *node);
int JSI_getElementPosition(void *elem, int *x, int *y);

#endif
