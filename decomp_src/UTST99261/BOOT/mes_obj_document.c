/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
typedef struct MesStrD {
    DOMChar *str;
    int len;
} MesStrD;
void *Util_HTMLDocument_getBody(void *doc);
void Element_setAttribute(void *elem, DOMString *name, DOMString *value);
void *memcpy(void *d, const void *s, unsigned int n);
typedef struct DocNames {
    const char *n[4];
} DocNames;
extern DocNames D_0013F654;
MesObject *mes_array_new(MesContext *ctx, unsigned int len);
int mes_class_property_setup(MesContext *ctx, MesObject *obj, const char *name, MesValue v, int flags);
extern MesClassDef mes_document_def;
extern MesClass *mes_document_class;
DOMString *JSI_getDocumentSelection(void *doc);
void JSI_freeDOMString(DOMString *s);
MesValue mes_document_write_inner(MesContext *ctx, int newline);
typedef struct MesDocPriv {
    void *doc;
    MesValue v;
} MesDocPriv;
extern int *g_JS_NEEDREDRAW_;


MesValue mes_document_get_selection(MesContext *ctx)
{
    MesDocPriv *priv = mes_class_private_get(ctx->frame->thisobj);
    DOMString *s = JSI_getDocumentSelection(priv->doc);
    MesValue ret;

    if (s == NULL)
        return MES_NULL;
    ret = mes_string_new(ctx, s->str, s->len);
    JSI_freeDOMString(s);
    return ret;
}

int mes_document_handle_event(MesContext *ctx, MesObject *obj)
{
    short type = g_JS_EVENT_REC_->type;

    if (type == 4 || type == 13 || type == 17)
        return mes_event_handle_event(ctx, obj, type);
    return 12;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", mes_document_write_inner);

MesValue mes_document_write(MesContext *ctx)
{
    return mes_document_write_inner(ctx, 0);
}

MesValue mes_document_writeln(MesContext *ctx)
{
    return mes_document_write_inner(ctx, 1);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", mes_document_setAttribute);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_document_redrawForce(void) {
    *g_JS_NEEDREDRAW_ = 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", mes_document_get);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F528);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", mes_document_put);

void mes_document_mark(MesContext *ctx, MesDocPriv *priv)
{
    if (priv != NULL && priv->v != MES_NULL)
        mes_gc_mark(priv->v);
}

void mes_document_free(MesContext *ctx, MesDocPriv *priv)
{
    if (priv != NULL)
        MEM_free(0, priv);
}

void mes_document_class_init(MesContext *ctx)
{
    mes_document_class = mes_class_init(ctx, &mes_document_def);
}

MesObject *mes_document_new(MesContext *ctx, void *priv)
{
    DocNames names = D_0013F654;
    MesObject *o = mes_class_new(ctx, mes_document_class);
    MesObject *a;
    unsigned int i;

    mes_class_private_set(o, priv);
    *--ctx->sp = (MesValue)o;
    for (i = 0; i < 4; i++) {
        a = mes_array_new(ctx, 0);
        *--ctx->sp = (MesValue)a;
        mes_class_property_setup(ctx, o, names.n[i], (MesValue)a, 7);
    }
    ctx->sp += i + 1;
    return o;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F57C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F588);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F590);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F598);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F5A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F5A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F5B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F5B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F5C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F5D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F5DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F5E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F5F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F5FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F604);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F608);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F614);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F61C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F62C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F638);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F640);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F648);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F654);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F664);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F66C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F674);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F678);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F67C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F684);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F68C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F694);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F69C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F6A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F6AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F6B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F6BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F6C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F6D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F6D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F6E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F6F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F6F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F700);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F708);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F710);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F718);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F720);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F72C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F738);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F740);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F748);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F750);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F758);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F760);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F768);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F770);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_document", D_0013F77C);
