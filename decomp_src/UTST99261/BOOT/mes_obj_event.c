/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern int *g_JS_MSG_SID_;
extern int *g_JS_PAGECHANGED_;
void *memcpy(void *d, const void *s, unsigned int n);
int Node_getSid(void *node);
extern MesClassDef mes_event_def;
extern MesClass *mes_event_class;

typedef struct LinkStr { DOMChar *str; unsigned int len; } LinkStr;
extern DOMString _DOMhref;
extern DOMString _DOMtarget;
DOMString *makeHref(void *url);
void JSI_freeDOMString(DOMString *s);
void mes_val2domstr(MesContext *ctx, MesValue v, DOMString *out);
LinkStr *mes_obj_common_to_string(MesContext *ctx, MesValue v);
MesValue mes_eval_to_number(MesContext *ctx, MesValue v);
void JSI_setURLHash(void *u, DOMString *s);
void JSI_setURLHost(void *u, DOMString *s);
void JSI_setURLPathname(void *u, DOMString *s);
void JSI_setURLPort(void *u, int port);
void JSI_setURLProtocol(void *u, DOMString *s);
void JSI_setURLSearch(void *u, DOMString *s);
int Element_setAttribute();
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", mes_event_get);

void mes_event_mark(void) {
}

void mes_event_free(void) {
}

void mes_event_class_init(MesContext *ctx)
{
    mes_event_class = mes_class_init(ctx, &mes_event_def);
}

MesObject *mes_event_new(MesContext *ctx)
{
    return mes_class_new(ctx, mes_event_class);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C78C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C794);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C79C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C800);

int mes_link_common_set_href(MesContext *ctx, void *dom, unsigned short *str, int len)
{
    int *sidp = g_JS_MSG_SID_;
    IpcMsg msg;
    int n = len * 2;
    int size = n + 16;
    int *buf = MEM_malloc(0, size);

    if (buf != NULL) {
        buf[0] = 0;
        buf[1] = 0;
        buf[2] = len;
        memcpy(buf + 3, str, n);
        SetIpcMember(&msg, 8, Node_getSid(dom), 0, 0x805, 0, size, buf);
        msg.w[5] = *sidp;
        if (JSSendMail(&msg, "/tmp/mq_lo") == 0)
            *g_JS_PAGECHANGED_ = 1;
    }
    return 1;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C814);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", mes_link_common_get_sub);

int mes_link_common_put_sub(MesContext *ctx, void *elem, int id, MesValue v, void *urlp, int type)
{
    DOMString s;
    LinkStr *o;
    DOMChar *p;
    unsigned int n;
    unsigned int i;
    unsigned int len;
    int port;
    DOMString *h;

    switch (id) {
    case 1:
        mes_val2domstr(ctx, v, &s);
        JSI_setURLHash(urlp, &s);
        break;
    case 2:
        mes_val2domstr(ctx, v, &s);
        JSI_setURLHost(urlp, &s);
        break;
    case 5:
        mes_val2domstr(ctx, v, &s);
        JSI_setURLPathname(urlp, &s);
        break;
    case 6:
        port = mes_eval_to_number(ctx, v) >> 2;
        JSI_setURLPort(urlp, port);
        break;
    case 7:
        mes_val2domstr(ctx, v, &s);
        if (s.len == 0)
            return 1;
        JSI_setURLProtocol(urlp, &s);
        break;
    case 8:
        mes_val2domstr(ctx, v, &s);
        JSI_setURLSearch(urlp, &s);
        break;
    case 4:
        if (type == 6) {
            mes_val2domstr(ctx, v, &s);
            mes_link_common_set_href(ctx, elem, s.str, s.len);
            break;
        }
    case 9:
        o = mes_obj_common_to_string(ctx, v);
        s.size = s.len = o->len;
        s.str = MEM_malloc(0, s.len * 2);
        if (s.str != NULL) {
            memcpy(s.str, o->str, s.len * 2);
            Element_setAttribute(elem, id == 4 ? &_DOMhref : &_DOMtarget, &s);
            MEM_free(0, s.str);
        }
        ctx->sp++;
        break;
    case 3:
        o = mes_obj_common_to_string(ctx, v);
        p = o->str;
        n = o->len;
        for (i = 0; i < o->len; i++) {
            if (*p++ == ':') {
                n = i;
                break;
            }
        }
        if ((int)n > 0) {
            s.size = s.len = n;
            s.str = o->str;
            JSI_setURLHost(urlp, &s);
        }
        if (n == o->len)
            port = 80;
        else {
            port = 0;
            for (i = n + 1; i < o->len; i++, p++) {
                if (*p < '0' || *p > '9')
                    break;
                port = port * 10 + *p - '0';
            }
        }
        JSI_setURLPort(urlp, port);
        ctx->sp++;
        break;
    case 10:
    case 11:
    case 12:
        break;
    }
    if (type == 11) {
        switch (id) {
        case 1: case 2: case 3: case 5: case 6: case 7: case 8:
            h = makeHref(urlp);
            Element_setAttribute(elem, &_DOMhref, h);
            JSI_freeDOMString(h);
        }
    } else {
        switch (id) {
        case 1: case 2: case 3: case 5: case 6: case 7: case 8:
            h = makeHref(urlp);
            mes_link_common_set_href(ctx, elem, h->str, h->len);
            JSI_freeDOMString(h);
        }
    }
    return 1;
}
