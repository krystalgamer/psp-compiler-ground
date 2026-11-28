/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
extern MesClassDef mes_image_def;
extern struct {
    MesClass *cls;
    int arg;
} mes_image_class_global;
extern int D_0025BC9C;
typedef struct MesImagePriv {
    int v;
    int f4;
    void *f8;
    void *fC;
} MesImagePriv;
MesObject *mes_image_new(MesContext *ctx, MesImagePriv *priv);



typedef struct MesStrI { DOMChar *str; int len; } MesStrI;
typedef struct ImgSrcMsg { int has; void *elem; int len; DOMChar *str; } ImgSrcMsg;
extern DOMString _DOMlowsrc, _DOMsrc;
void Element_setAttribute(void *elem, DOMString *name, DOMString *value);
void *memcpy(void *d, const void *s, unsigned int n);
int mes_image_handle_event(MesContext *ctx, MesObject *obj)
{
    short type = g_JS_EVENT_REC_->type;

    if (type == 1 || type == 2 || type == 4 || type == 7 || type == 8 || type == 12 || type == 13 || type == 14 || type == 15
        || type == 16 || type == 17)
        return mes_event_handle_event(ctx, obj, type);
    return 12;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mes_image_constructor(int arg0) {
    int var_v0;
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x10);
    var_v0 = 0x20;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0) = 4;
        M2C_FIELD(temp_v0, int *, 4) = 0;
        M2C_FIELD(temp_v0, int *, 8) = 0;
        M2C_FIELD(temp_v0, int *, 0xC) = 0;
        var_v0 = mes_image_new(arg0, temp_v0);
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", mes_image_get);

int mes_image_put(MesContext *ctx, MesObject *o, MesImagePriv *p, int id, MesValue v)
{
    MesStrI *s;
    DOMString ds;
    IpcMsg msg;
    void *elem;
    int obj;
    ImgSrcMsg *m;
    DOMString *nd;
    int sid;
    int ret;

    ret = 0;
    if (p == NULL)
        goto out;
    if ((v & 3) != 3)
        goto out;
    obj = p->v;
    elem = (void *)p->f4;
    switch (id) {
    case 5:
        ret = 0;
        if (elem == NULL)
            break;
        s = (MesStrI *)(v & ~3);
        ds.size = ds.len = s->len;
        ds.str = MEM_malloc(0, s->len * 2);
        memcpy(ds.str, s->str, s->len * 2);
        Element_setAttribute(elem, &_DOMlowsrc, &ds);
        MEM_free(0, ds.str);
        ret = 1;
        break;
    case 7:
        s = (MesStrI *)(v & ~3);
        ds.size = ds.len = s->len;
        ds.str = MEM_malloc(0, s->len * 2);
        if (ds.str != NULL) {
            m = MEM_malloc(0, s->len * 2 + 0x10);
            if (m != NULL) {
                memcpy(ds.str, s->str, s->len * 2);
                if (elem != NULL) {
                    if (id == 5)
                        Element_setAttribute(elem, &_DOMlowsrc, &ds);
                    else
                        Element_setAttribute(elem, &_DOMsrc, &ds);
                    m->has = 1;
                    m->elem = elem;
                    sid = Node_getSid(Node_getOwnerDocument(elem));
                } else {
                    m->has = 0;
                    m->elem = NULL;
                    elem = *(void **)mes_class_private_get((MesObject *)obj);
                    sid = Node_getSid(elem);
                    nd = MEM_malloc(0, s->len * 2 + 0xE);
                    nd->size = s->len;
                    nd->len = s->len;
                    nd->str = (DOMChar *)(nd + 1);
                    memcpy(nd->str, s->str, s->len * 2);
                    if (id == 5) {
                        if (p->f8 != NULL)
                            MEM_free(0, p->f8);
                        p->f8 = nd;
                    } else {
                        if (p->fC != NULL)
                            MEM_free(0, p->fC);
                        p->fC = nd;
                    }
                }
                m->len = s->len;
                m->str = (DOMChar *)(m + 1);
                memcpy(m->str, s->str, s->len * 2);
                SetIpcMember(&msg, 8, sid, 0, 0x80E, 0, s->len * 2 + 0x10, m);
                JSSendMail(&msg, "/tmp/mq_lo");
            }
            MEM_free(0, ds.str);
        }
        ret = 1;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 8:
    case 9:
        ret = 0;
        break;
    }
out:
    return ret;
}

void mes_image_mark(void) {
}

void mes_image_free(MesContext *ctx, MesImagePriv *priv)
{
    if (priv != NULL) {
        if (priv->f8 != NULL)
            MEM_free(0, priv->f8);
        if (priv->fC != NULL)
            MEM_free(0, priv->fC);
        MEM_free(0, priv);
    }
}

int mes_image_class_init(MesContext *ctx, int arg)
{
    mes_image_class_global.cls = mes_class_init(ctx, &mes_image_def);
    mes_image_class_global.arg = arg;
    return 0;
}

MesObject *mes_image_new(MesContext *ctx, MesImagePriv *priv)
{
    MesObject *obj;

    if (priv->v == MES_NULL)
        priv->v = D_0025BC9C;
    obj = mes_class_new(ctx, mes_image_class_global.cls);
    mes_class_private_set(obj, priv);
    return obj;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F938);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F940);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F94C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F954);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F95C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F964);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F96C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F970);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F978);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F980);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F98C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F994);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F99C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F9A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F9B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F9B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F9C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F9CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F9D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F9E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F9E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F9F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F9F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013F9F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_image", D_0013FA04);
