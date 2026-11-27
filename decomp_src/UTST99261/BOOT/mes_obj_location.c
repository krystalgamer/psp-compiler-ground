/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
void *JSI_getDocumentURL(void *elem);
typedef struct FragIDs {
    int f0, f4, f8, fC, f10;
    char *frag;                       /* 0x14 */
} FragIDs;
typedef struct URLRec {
    int f0, f4, f8, fC;
    DOMString *frag;                  /* 0x10 */
} URLRec;
FragIDs *HST_getFragmentIDs(void *node, int x);
unsigned int strlen(const char *s);
DOMString *JSI_newDOMString(const char *s, int len);
void JSI_freeDOMString(DOMString *s);
extern MesClassDef mes_location_def;
extern MesClass *mes_location_class;
void *HST_searchSessionIDHistoryNode(int sid);




#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_location_check_value(MesContext *ctx, MesObject *obj, void **elem, int *sid, void **node)
{
    void *e;
    int s;
    void *n;
    MesObject *o;

    o = obj;
    if (obj == NULL)
        o = ctx->frame->thisobj;
    e = mes_class_private_get(o);
    s = Node_getSid(e);
    n = HST_searchSessionIDHistoryNode(s);
    *elem = e;
    *sid = s;
    *node = n;
}

MesValue mes_location_to_string(MesContext *ctx)
{
    void *elem;
    int sid;
    char *node;

    mes_location_check_value(ctx, ctx->frame->thisobj, &elem, &sid, (void **)&node);
    if (elem != NULL && node != NULL && *(void **)(node + 0x6C) != NULL)
        return mes_location_get(ctx, ctx->frame->thisobj, elem, 4);
    return MES_UNDEFINED;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", mes_location_reload);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", mes_location_replace);

MesValue mes_location_get(MesContext *ctx, MesObject *obj, void *elem, int id)
{
    int sid;
    char *node;
    URLRec *url;
    FragIDs *f;
    DOMString *s;
    DOMString ds;
    MesValue r;

    mes_location_check_value(ctx, obj, &elem, &sid, (void **)&node);
    if (elem != NULL && node != NULL && *(void **)(node + 0x6C) != NULL && (unsigned int)(id - 1) < 8) {
        url = JSI_getDocumentURL(elem);
        if (url != NULL) {
            f = HST_getFragmentIDs(node, 0);
            ds.len = f->frag != NULL ? strlen(f->frag) : 0;
            if (ds.len != 0) {
                s = JSI_newDOMString(f->frag, ds.len);
                if (s != NULL) {
                    if (url->frag != NULL)
                        JSI_freeDOMString(url->frag);
                    url->frag = s;
                } else {
                    JSI_freeURLRec(url);
                    return MES_UNDEFINED;
                }
            }
            r = mes_link_common_get_sub(ctx, elem, id, url, 6);
            JSI_freeURLRec(url);
            return r;
        }
    }
    return MES_UNDEFINED;
}

int mes_location_put(MesContext *ctx, MesObject *obj, void *elem, int id, MesValue v)
{
    int sid;
    char *node;
    void *url;
    int r;

    mes_location_check_value(ctx, obj, &elem, &sid, (void **)&node);
    if (elem != NULL && node != NULL && *(void **)(node + 0x6C) != NULL && (unsigned int)(id - 1) < 8) {
        url = JSI_getDocumentURL(elem);
        if (url != NULL) {
            r = mes_link_common_put_sub(ctx, elem, id, v, url, 6);
            JSI_freeURLRec(url);
            return r;
        }
    }
    return 0;
}

void mes_location_mark(void) {
}

void mes_location_free(void) {
}

void mes_location_class_init(MesContext *ctx)
{
    mes_location_class = mes_class_init(ctx, &mes_location_def);
}

MesObject *mes_location_new(MesContext *ctx, void *elem)
{
    MesObject *obj = mes_class_new(ctx, mes_location_class);

    if (obj != NULL)
        mes_class_private_set(obj, elem);
    return obj;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", D_0013FA0C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", D_0013FA18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", D_0013FA20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", D_0013FA28);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", D_0013FA34);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", D_0013FA3C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", D_0013FA48);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", D_0013FA50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", D_0013FA5C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", D_0013FA64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", D_0013FA70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", D_0013FA78);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_location", D_0013FA80);
