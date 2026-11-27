/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern char D_0013F7FC[];
extern DOMString _DOMaction, _DOMenctype, _DOMmethod, _DOMtarget;
MesObject *mes_array_new(MesContext *ctx, unsigned int len);
int mes_class_property_setup(MesContext *ctx, MesObject *obj, const char *name, MesValue v, int flags);
int mes_util_streq3(const DOMChar *a, const char *b, int n);
int Util_HTMLFormElement_getLength(void *form);
extern MesClassDef mes_form_def;
extern MesClass *mes_form_class;
extern char D_0013F788[];
extern char D_0013F7C4[];
typedef struct MesFormPriv {
    void *form;
} MesFormPriv;

typedef struct MesStrF { DOMChar *str; int len; } MesStrF;
typedef struct MesFormPriv2 { void *form; int obj; } MesFormPriv2;
void Element_setAttribute(void *elem, DOMString *name, DOMString *value);
void *memcpy(void *d, const void *s, unsigned int n);
MesStrF *mes_obj_common_to_string(MesContext *ctx, MesValue v);
int isAllowedAsPropertyName(MesStrF *s, void *t, void *x);
int setNewPropertyReference(MesContext *ctx, int a, int c, MesValue s, MesObject *b, int y);
int deleteOldPropertyReference(MesContext *ctx, int a, int c, MesValue s, MesValue old, MesObject *b);
extern DOMString _DOMname;
MesValue mes_class_property_get(MesContext *ctx, int obj, const char *name);
extern char mes_form_properties[], mes_form_methods[];
int mes_form_handle_event(MesContext *ctx, MesObject *obj)
{
    short type = g_JS_EVENT_REC_->type;

    if (type == 2 || type == 4 || type == 8 || type == 13 || type == 14 || type == 15 || type == 16 || type == 17
        || type == 19 || type == 22)
        return mes_event_handle_event(ctx, obj, type);
    return 12;
}

int mes_form_reset(MesContext *ctx)
{
    IpcMsg msg;
    void *form = ((MesFormPriv *)mes_class_private_get(ctx->frame->thisobj))->form;

    SetIpcMember(&msg, 8, Node_getSid(Node_getOwnerDocument(form)), 0, 0x80B, 1, 0, form);
    JSSendMail(&msg, D_0013F788);
    return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F788);

int mes_form_submit(MesContext *ctx)
{
    void *form = ((MesFormPriv *)mes_class_private_get(ctx->frame->thisobj))->form;
    DOMString s = Element_getAttribute(form, &_DOMaction);
    IpcMsg msg;

    if (mes_util_streq3(s.str, "mailto:", 7) || mes_util_streq3(s.str, "news::", 5))
        return 1;
    SetIpcMember(&msg, 8, Node_getSid(Node_getOwnerDocument(form)), 0, 0x80B, 0, 0, form);
    JSSendMail(&msg, D_0013F788);
    return 0;
}

MesValue mes_form_get(MesContext *ctx, MesObject *obj, MesFormPriv *priv, int id)
{
    DOMString s;

    switch (id) {
    case 1:
        s = Element_getAttribute(priv->form, &_DOMaction);
        return mes_string_new(ctx, s.str, s.len);
    case 3:
        s = Element_getAttribute(priv->form, &_DOMenctype);
        return mes_string_new(ctx, s.str, s.len);
    case 4:
        return MES_INT(Util_HTMLFormElement_getLength(priv->form));
    case 5:
        s = Element_getAttribute(priv->form, &_DOMmethod);
        return mes_string_new(ctx, s.str, s.len);
    case 6:
        s = Element_getAttribute(priv->form, &_DOMname);
        return mes_string_new(ctx, s.str, s.len);
    case 7:
        s = Element_getAttribute(priv->form, &_DOMtarget);
        return mes_string_new(ctx, s.str, s.len);
    }
    return MES_UNDEFINED;
}


INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F7C4);

int mes_form_put(MesContext *ctx, MesObject *obj, MesFormPriv2 *priv, int id, MesValue v)
{
    MesStrF *s;
    DOMString ds;
    MesValue old;
    int forms;
    int ret;

    switch (id) {
    case 1:
        s = mes_obj_common_to_string(ctx, v);
        ds.size = ds.len = s->len;
        ds.str = MEM_malloc(0, s->len * 2);
        memcpy(ds.str, s->str, s->len * 2);
        ctx->sp++;
        Element_setAttribute(priv->form, &_DOMaction, &ds);
        MEM_free(0, ds.str);
        ret = 1;
        break;
    case 3:
        s = mes_obj_common_to_string(ctx, v);
        ds.size = ds.len = s->len;
        ds.str = MEM_malloc(0, s->len * 2);
        memcpy(ds.str, s->str, s->len * 2);
        ctx->sp++;
        Element_setAttribute(priv->form, &_DOMenctype, &ds);
        MEM_free(0, ds.str);
        ret = 1;
        break;
    case 4:
        ret = 1;
        break;
    case 5:
        s = mes_obj_common_to_string(ctx, v);
        ds.size = ds.len = s->len;
        ds.str = MEM_malloc(0, s->len * 2);
        memcpy(ds.str, s->str, s->len * 2);
        ctx->sp++;
        Element_setAttribute(priv->form, &_DOMmethod, &ds);
        MEM_free(0, ds.str);
        ret = 1;
        break;
    case 6:
        ret = 0;
        if ((v & 3) != 3)
            break;
        s = (MesStrF *)(v & ~3);
        ds.str = MEM_malloc(0, s->len * 2);
        if (ds.str != NULL) {
            old = mes_class_property_get(ctx, (int)obj, D_0013F7C4);
            *--ctx->sp = old;
            forms = mes_class_property_get(ctx, priv->obj, "forms");
            deleteOldPropertyReference(ctx, priv->obj, forms, v, old, obj);
            ds.len = ds.size = s->len;
            memcpy(ds.str, s->str, s->len * 2);
            Element_setAttribute(priv->form, &_DOMname, &ds);
            MEM_free(0, ds.str);
            ctx->sp++;
            if (isAllowedAsPropertyName(s, mes_form_properties, mes_form_methods) == 1)
                setNewPropertyReference(ctx, priv->obj, forms, v, obj, 1);
        }
        ret = 1;
        break;
    case 7:
        s = mes_obj_common_to_string(ctx, v);
        ds.size = ds.len = s->len;
        ds.str = MEM_malloc(0, s->len * 2);
        memcpy(ds.str, s->str, s->len * 2);
        ctx->sp++;
        Element_setAttribute(priv->form, &_DOMtarget, &ds);
        MEM_free(0, ds.str);
        ret = 1;
        break;
    case 2:
        ret = 1;
        break;
    default:
        ret = 0;
    }
    return ret;
}

void mes_form_mark(void) {
}

void mes_form_free(MesContext *ctx, void *priv)
{
    if (priv != NULL)
        MEM_free(0, priv);
}

void mes_form_class_init(MesContext *ctx)
{
    mes_form_class = mes_class_init(ctx, &mes_form_def);
}

MesObject *mes_form_new(MesContext *ctx, MesFormPriv *priv)
{
    MesObject *o = mes_class_new(ctx, mes_form_class);
    MesObject *a;

    mes_class_private_set(o, priv);
    *--ctx->sp = (MesValue)o;
    a = mes_array_new(ctx, 0);
    *--ctx->sp = (MesValue)a;
    mes_class_property_setup(ctx, o, D_0013F7FC, (MesValue)a, 7);
    ctx->sp += 2;
    return o;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F7F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F7FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F808);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F814);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F81C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F824);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F82C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F838);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F840);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F848);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F850);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F858);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F860);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F868);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F870);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F878);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F880);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F888);
