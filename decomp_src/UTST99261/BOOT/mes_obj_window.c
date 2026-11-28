/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
typedef struct WinStr {
    unsigned short *chars;            /* 0x0 */
    int n;                            /* 0x4 */
} WinStr;
typedef struct WinDS {
    int size;                         /* 0x0 */
    int dlen;                         /* 0x4 */
    unsigned short *buf;              /* 0x8 */
} WinDS;
void *JSI_getDocumentURL(void *elem);
int mes_link_common_set_href(MesContext *ctx, void *dom, unsigned short *str, int len);
int JSI_setWindowName(void *dom, WinDS *ds);
typedef struct WinPriv {
    void *dom;                        /* 0x0 */
    MesValue f4;                      /* 0x4 */
    MesValue f8;                      /* 0x8 */
} WinPriv;
typedef struct WinRec {
    short f0, f2, f4, f6, f8, fA, fC, fE, f10;
} WinRec;
int mes_class_property_get(void *ctx, void *obj, const char *name);
char *HST_getTargetName(void *node);
int JSI_getWindowRec(void *dom, WinRec *rec);
int strncmp(const char *a, const char *b, int n);
unsigned int strlen(const char *s);
DOMString *JSI_newDOMString(const char *s, int len);
typedef struct WinDomStr {
    int f0;
    int len;                          /* 0x4 */
    unsigned short *str;              /* 0x8 */
} WinDomStr;
int mes_window_dialog_inner_sub(int kind, int sid, void *s, unsigned short *out, unsigned int d);
void *mes_obj_common_to_string(MesContext *ctx, MesValue v);
void *JSWaitMail(int cmd, int sid);
WinDomStr *JSI_getBrowserHomeURL(void);
void JSI_freeDOMString(WinDomStr *s);
void *memcpy(void *d, const void *s, unsigned int n);
extern char D_0013C28C[];
extern int *g_JS_PAGECHANGED_;
unsigned int mes_context_id2(void *ctx, const char *name);
MesProp *mes_object_search(MesObject *obj, unsigned int id);
void *mes_class_private_get(MesObject *o);
int Node_getSid(void *node);
void *HST_searchSessionIDHistoryNode(int sid);
void *HST_getHistoryWithOffset(int n);
void mes_window_scroll_inner(void *dom, int kind, int x, int y, int sid);
extern MesClassDef mes_window_def;
extern MesClass *mes_window_class;
extern char D_0013C294[];
extern char D_0013C2A0[];
extern char D_0013C2A8[];
int mes_window_history_move_inner(MesContext *ctx, int n);
void js_delTimerID(int id, int kind, int b);
MesValue mes_window_set_interval_inner(MesContext *ctx, MesValue *argv, int argc, int kind);
void *mes_window_dialog_inner(MesContext *ctx, int kind, MesValue msg, void *out, int d);
void mes_window_check_validate(MesContext *ctx, void **a, void **b, int *sid, void **node);
void *HST_getDomObject(void *node);
typedef struct DialogResult {
    char pad[0x10];
    int ok;
} DialogResult;


extern char D_0013C3FC[];
extern char D_0013C434[];
extern char D_0013C454[];
extern char D_0013C45C[];
extern char D_0013C3A8[];
extern char D_0013C3E8[];
extern char mes_window_native_table[];
MesObject *mes_class_new(MesContext *ctx, MesClass *cls);
MesValue mes_array_new(MesContext *ctx, int n);
int mes_class_property_setup(MesContext *ctx, MesObject *o, const char *name, MesValue v, int flags);
void mes_native_setup(MesContext *ctx, MesObject *o, void *table, int n);
void mes_object_setup(MesContext *ctx, MesObject *o, const char *name, MesValue v, int flags, int x);
extern char D_0013C3D0[];
extern char D_0013C3C4[];
extern char D_0013C410[];
extern char D_0013C404[];
extern char D_0013C41C[];
extern char D_0013C428[];
extern char D_0013C444[];
extern char D_0013C44C[];
int mes_class_instance_of(MesObject *obj, void *cls);
extern void *mes_event_class;
int mes_class_call(MesContext *ctx, int f, int argc, MesValue *argv, MesObject *thisobj);
typedef struct WsiCtx { MesContext *ctx; MesObject *obj; } WsiCtx;
typedef struct WsiTimer { int id; int kind; WsiCtx *wc; int len; void *data; } WsiTimer;
typedef struct WsiCall { MesValue fn; int argc; int *vals; } WsiCall;
typedef struct WsiStr { void *chars; int len; } WsiStr;
int js_checkAddTimer(void);
int get_global_ptr(void);
int *mes_util_vals(int n, int a);
MesValue mes_eval_to_number(MesContext *ctx, MesValue v);
int OS_timer_set(int a, int b, int c, int d, int e);
int OS_timer_start(int id);
void js_addTimer(int arg0, int arg1, int arg2, int arg3);
void SetIpcmsg(void *m, void *b);
extern int *g_JS_MSG_SID_;
void mes_window_check_validate(MesContext *ctx, void **a, void **b, int *sid, void **node)
{
    MesObject *o;
    void **priv;
    int s;
    void *n;

    o = (MesObject *)mes_object_search(ctx->global, mes_context_id2(ctx, D_0013C28C))->value;
    priv = mes_class_private_get(o);
    s = Node_getSid(*priv);
    n = HST_searchSessionIDHistoryNode(s);
    *a = o;
    *b = priv;
    *sid = s;
    *node = n;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", mes_window_dialog_inner_sub);

void *mes_window_dialog_inner(MesContext *ctx, int kind, MesValue msg, void *out, int d)
{
    struct {
        void *a;
        void *b;
        int sid;
        void *node;
    } v;
    void *r;
    void *s;

    mes_window_check_validate(ctx, &v.a, &v.b, &v.sid, &v.node);
    r = NULL;
    if (v.node != NULL) {
        s = NULL;
        if (msg != 0)
            s = mes_obj_common_to_string(ctx, msg);
        if (mes_window_dialog_inner_sub(kind, v.sid, s, out, d) == 0)
            r = JSWaitMail(0x407, v.sid);
        if (msg != 0)
            ctx->sp++;
    }
    return r;
}

int mes_window_history_move_inner(MesContext *ctx, int n)
{
    IpcMsg msg;
    void *a, *b;
    int sid;
    void *node;

    mes_window_check_validate(ctx, &a, &b, &sid, &node);
    if (node != NULL && HST_getHistoryWithOffset(-1) != NULL) {
        SetIpcMember(&msg, 8, sid, 0, 0x805, n, 0, NULL);
        if (JSSendMail(&msg, D_0013C294) == 0) {
            *g_JS_PAGECHANGED_ = 1;
            return 0;
        }
    }
    return -1;
}

void mes_window_scroll_inner(void *dom, int kind, int x, int y, int sid)
{
    IpcMsg msg;
    int *buf = MEM_malloc(0, 16);

    if (buf != NULL) {
        buf[0] = (int)dom;
        buf[1] = kind;
        buf[2] = x;
        buf[3] = y;
        SetIpcMember(&msg, 8, sid, 0, 0x80C, 0, 16, buf);
        JSSendMail(&msg, D_0013C294);
    }
}

MesValue mes_window_set_interval_inner(MesContext *ctx, MesValue *argv, int argc, int kind)
{
    IpcMsg msg;
    MesValue code;
    int ms;
    WsiCtx *wc;
    WsiTimer *t;
    WsiCall *fc;
    int n, i;
    int *vals;
    void *m;
    int type;
    MesValue iv;

    if (argv == NULL || argc < 2)
        return 0;
    code = argv[0];
    iv = argv[1];
    if ((code & 3) != 3 && !MES_IS_OBJECT(code))
        return 0;
    ms = mes_eval_to_number(ctx, iv) >> 2;
    if (ms <= 0) {
        ms = 0;
        kind = 2;
    }
    if (js_checkAddTimer() != 0)
        return 0;
    wc = MEM_malloc(0, 0x10);
    if (wc != NULL) {
        wc->ctx = ctx;
        wc->obj = ctx->frame->thisobj;
        t = MEM_malloc(0, 0x14);
        if (t != NULL) {
            t->kind = kind;
            t->wc = wc;
            if ((code & 3) == 3) {
                WsiStr *s = (WsiStr *)(code & ~3);
                t->data = s->chars;
                t->len = s->len;
                type = 0;
            } else if (MES_IS_OBJECT(code) && ((unsigned char *)code)[0x10] == 5) {
                fc = MEM_malloc(0, 0xC);
                if (fc == NULL)
                    goto fail_t;
                fc->fn = argv[0];
                n = argc - 2;
                fc->argc = n;
                vals = mes_util_vals(n, 0);
                for (i = 0; i < argc - 2; i++)
                    vals[i + 1] = argv[i + 2];
                fc->vals = vals;
                t->data = fc;
                type = 1;
            } else
                goto fail_t;
            SetIpcMember(&msg, 8, *g_JS_MSG_SID_, 0, 0x810, type, 0x14, t);
            m = MEM_malloc(0, 0x24);
            if (m != NULL) {
                SetIpcmsg(m, &msg);
                t->id = OS_timer_set(((int *)get_global_ptr())[5], 0, ms, (int)m, 0);
                OS_timer_start(t->id);
                js_addTimer(t->id, kind, (int)m, (int)ctx);
                return MES_INT(t->id);
            }
            MEM_free(0, t->data);
        fail_t:
            MEM_free(0, t);
        }
        MEM_free(0, wc);
    }
    return 0;
}

MesValue mes_window_alert(MesContext *ctx, MesValue msg)
{
    int tmp[4];
    void *r = mes_window_dialog_inner(ctx, 0, msg, tmp, 0);

    if (r != NULL)
        MEM_free(0, r);
    return 0;
}

MesValue mes_window_blur(MesContext *ctx)
{
    IpcMsg msg;
    void *a, *b;
    int sid;
    void *node;

    mes_window_check_validate(ctx, &a, &b, &sid, &node);
    if (node != NULL) {
        SetIpcMember(&msg, 8, sid, 0, 0x808, 1, 0, HST_getDomObject(node));
        JSSendMail(&msg, D_0013C294);
    }
    return 0;
}

MesValue mes_window_clear_interval(MesContext *ctx, MesValue v)
{
    if ((v & 3) == 1)
        js_delTimerID(v >> 2, 1, 1);
    return 0;
}

MesValue mes_window_clear_timeout(MesContext *ctx, MesValue v)
{
    if ((v & 3) == 1)
        js_delTimerID(v >> 2, 2, 1);
    return 0;
}

MesValue mes_window_confirm(MesContext *ctx, MesValue msg)
{
    int tmp[4];
    DialogResult *r = mes_window_dialog_inner(ctx, 1, msg, tmp, 0);
    MesValue ret;

    if (r == NULL)
        return 8;
    ret = r->ok == 0 ? 12 : 8;
    MEM_free(0, r);
    return ret;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_window_find(void) {
    return 8;
}

MesValue mes_window_focus(MesContext *ctx)
{
    IpcMsg msg;
    void *a, *b;
    int sid;
    void *node;

    mes_window_check_validate(ctx, &a, &b, &sid, &node);
    if (node != NULL) {
        SetIpcMember(&msg, 8, sid, 0, 0x808, 0, 0, HST_getDomObject(node));
        JSSendMail(&msg, D_0013C294);
    }
    return 0;
}

MesValue mes_window_back(MesContext *ctx)
{
    mes_window_history_move_inner(ctx, -1);
    return 0;
}

MesValue mes_window_forward(MesContext *ctx)
{
    mes_window_history_move_inner(ctx, 1);
    return 0;
}

int mes_window_handle_event(MesContext *ctx, MesObject *obj)
{
    short type = g_JS_EVENT_REC_->type;

    if (type == 2 || type == 7 || type == 8 || type == 12 || type == 18 || type == 20 || type == 23)
        return mes_event_handle_event(ctx, obj, type);
    return 12;
}

MesValue mes_window_home(MesContext *ctx)
{
    IpcMsg msg;
    struct {
        void *a;
        void *b;
        int sid;
        void *node;
    } v;
    WinDomStr *url;
    int len, n, size;
    int *buf;

    mes_window_check_validate(ctx, &v.a, &v.b, &v.sid, &v.node);
    if (v.node != NULL && (url = JSI_getBrowserHomeURL()) != NULL) {
        len = url->len;
        n = len * 2;
        size = n + 16;
        buf = MEM_malloc(0, size);
        buf[0] = 0;
        buf[1] = 0;
        buf[2] = len;
        memcpy(buf + 3, url->str, n);
        JSI_freeDOMString(url);
        SetIpcMember(&msg, 8, v.sid, 0, 0x805, 0, size, buf);
        if (JSSendMail(&msg, D_0013C294) == 0)
            *g_JS_PAGECHANGED_ = 1;
    }
    return 0;
}

MesValue mes_window_scroll_by(MesContext *ctx, MesValue x, MesValue y)
{
    struct {
        void *a;
        void *b;
        int sid;
        char *node;
    } v;

    if ((x & 3) == 1 && (y & 3) == 1) {
        mes_window_check_validate(ctx, &v.a, &v.b, &v.sid, (void **)&v.node);
        if (v.node != NULL && *(void **)(v.node + 0x6C) != NULL)
        {
            x >>= 2;
            y >>= 2;
            mes_window_scroll_inner(HST_getDomObject(v.node), 1, x, y, v.sid);
        }
    }
    return 0;
}

MesValue mes_window_scroll_to(MesContext *ctx, MesValue x, MesValue y)
{
    struct {
        void *a;
        void *b;
        int sid;
        char *node;
    } v;

    if ((x & 3) == 1 && (y & 3) == 1) {
        mes_window_check_validate(ctx, &v.a, &v.b, &v.sid, (void **)&v.node);
        if (v.node != NULL && *(void **)(v.node + 0x6C) != NULL)
        {
            x >>= 2;
            y >>= 2;
            mes_window_scroll_inner(HST_getDomObject(v.node), 0, x, y, v.sid);
        }
    }
    return 0;
}

MesValue mes_window_set_interval(MesContext *ctx)
{
    MesArgs *args = ctx->frame->args;

    if (args == NULL)
        return 0;
    return mes_window_set_interval_inner(ctx, args->argv, args->argc, 1);
}

MesValue mes_window_set_timeout(MesContext *ctx)
{
    MesArgs *args = ctx->frame->args;

    if (args == NULL)
        return 0;
    return mes_window_set_interval_inner(ctx, args->argv, args->argc, 2);
}

MesValue mes_window_stop(MesContext *ctx)
{
    IpcMsg msg;
    void *a, *b;
    int sid;
    char *node;

    mes_window_check_validate(ctx, &a, &b, &sid, (void **)&node);
    if (node == NULL || *(void **)(node + 0x6C) == NULL)
        return 0;
    SetIpcMember(&msg, 8, sid, 0, 0x806, 0, 0, 0);
    JSSendMail(&msg, D_0013C294);
    return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C28C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C294);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C2A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C2A8);



MesValue mes_window_get(MesContext *ctx, MesObject *obj, WinPriv *priv, int id)
{
    char *node;
    char *name;
    DOMString *s;
    MesValue r;
    int v;

    if (priv == NULL)
        return MES_UNDEFINED;
    switch (id) {
    case 1:
        node = HST_searchSessionIDHistoryNode(Node_getSid(priv->dom));
        return *(void **)(node + 0x6C) == NULL ? MES_TRUE : MES_FALSE;
    case 2:
        return priv->f4;
    case 7:
        v = mes_class_property_get(ctx, obj, D_0013C2A0);
        *--ctx->sp = v;
        r = mes_class_property_get(ctx, (void *)v, D_0013C2A8);
        ctx->sp++;
        goto ret;
    case 9:
        node = HST_searchSessionIDHistoryNode(Node_getSid(priv->dom));
        name = HST_getTargetName(node);
        if (name == NULL || strncmp(name, "__", 2) == 0) {
            r = MES_NULL;
            goto ret;
        }
        s = JSI_newDOMString(name, strlen(name));
        r = mes_string_new(ctx, s->str, s->len);
        JSI_freeDOMString((void *)s);
        return r;
    case 5: case 6: case 12: case 13: case 14: case 15: case 18: case 19:
        node = HST_searchSessionIDHistoryNode(Node_getSid(priv->dom));
        if (*(void **)(node + 0x6C) == NULL) {
            r = MES_NULL;
            goto ret;
        }
        {
            WinRec rec = {0};
        JSI_getWindowRec(HST_getDomObject(node), &rec);
        switch (id) {
        case 6: r = MES_INT(rec.fE); break;
        case 5: r = MES_INT(rec.f10); break;
        case 13: r = MES_INT(rec.f6); break;
        case 12: r = MES_INT(rec.f8); break;
        case 14: r = MES_INT(rec.fA); break;
        case 15: r = MES_INT(rec.fC); break;
        case 18: r = MES_INT(rec.f2); break;
        case 19: r = MES_INT(rec.f4); break;
        default: r = MES_NULL; break;
        }
        }
    ret:
        return r;
    case 8:
        return priv->f8;
    case 22:
    default:
        break;
    }
    return MES_UNDEFINED;
}

int mes_window_put(MesContext *ctx, MesObject *obj, WinPriv *priv, int id, MesValue v)
{
    int sid;
    char *node;
    void *dom;
    void *url;
    WinStr *str;
    WinDS ds;

    if (priv != NULL) {
        switch (id) {
        case 8:
            if (MES_IS_OBJECT(v)) {
                if (priv->f8 == 0) {
                    priv->f8 = v;
                } else if ((v & 3) == 3) {
                    mes_window_check_validate(ctx, (void **)&obj, (void **)&priv, &sid, (void **)&node);
                    if (priv->dom != NULL && node != NULL && *(void **)(node + 0x6C) != NULL
                        && (dom = HST_getDomObject(node)) != NULL
                        && (url = JSI_getDocumentURL(dom)) != NULL)
                        mes_link_common_put_sub(ctx, dom, 4, v, url, 6);
                }
                return 1;
            }
            str = mes_obj_common_to_string(ctx, v);
            mes_link_common_set_href(ctx, priv->dom, str->chars, str->n);
            ctx->sp++;
            return 1;
        case 9:
            mes_window_check_validate(ctx, (void **)&obj, (void **)&priv, &sid, (void **)&node);
            dom = HST_getDomObject(node);
            if (dom == NULL)
                break;
            str = mes_obj_common_to_string(ctx, v);
            ds.size = ds.dlen = str->n;
            ds.buf = MEM_malloc(0, str->n * 2);
            if (ds.buf != NULL) {
                memcpy(ds.buf, str->chars, str->n * 2);
                JSI_setWindowName(dom, &ds);
                MEM_free(0, ds.buf);
            }
            ctx->sp++;
            return 1;
        case 2:
            priv->f4 = v;
            return 1;
        case 0: case 1: case 3: case 4: case 5: case 6: case 7: case 10: case 11:
        case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20: case 21:
        case 22:
            break;
        }
    }
    return 0;
}

void mes_window_mark(void) {
}

void mes_window_free(MesContext *ctx, void *p)
{
    MEM_free(0, p);
}

void mes_window_class_init(MesContext *ctx)
{
    mes_window_class = mes_class_init(ctx, &mes_window_def);
}

MesObject *mes_window_new(MesContext *ctx, void *priv)
{
    MesObject *w;
    MesValue frames;

    w = mes_class_new(ctx, mes_window_class);
    mes_class_private_set(w, priv);
    *--ctx->sp = (MesValue)w;
    frames = mes_array_new(ctx, 0);
    mes_class_property_setup(ctx, w, D_0013C2A0, frames, 7);
    mes_native_setup(ctx, ctx->global, mes_window_native_table, 0x11);
    mes_object_setup(ctx, ctx->global, D_0013C2A0, frames, 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C3FC, 4, 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C434, (MesValue)w, 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C454, (MesValue)w, 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C45C, (MesValue)w, 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C28C, (MesValue)w, 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C3A8, 8, 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C2A8, 1, 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C3E8, 4, 7, 0);
    ctx->sp++;
    return w;
}

void mes_window_set_global_property(MesContext *ctx)
{
    WinPriv *priv;

    priv = mes_class_private_get((MesObject *)mes_class_property_get(ctx, ctx->global, D_0013C28C));
    {
    WinRec rec = {0};
    JSI_getWindowRec(priv->dom, &rec);
    mes_object_setup(ctx, ctx->global, D_0013C3D0, MES_INT(rec.fE), 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C3C4, MES_INT(rec.f10), 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C410, MES_INT(rec.f6), 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C404, MES_INT(rec.f8), 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C41C, MES_INT(rec.fA), 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C428, MES_INT(rec.fC), 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C444, MES_INT(rec.f2), 7, 0);
    mes_object_setup(ctx, ctx->global, D_0013C44C, MES_INT(rec.f4), 7, 0);
    }
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C3A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C3B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C3BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C3C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C3D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C3DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C3E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C3F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C3FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C404);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C410);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C41C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C428);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C434);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C43C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C444);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C44C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C454);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C45C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C460);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C468);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C470);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C478);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C488);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C498);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C4A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C4A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C4B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C4B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C4C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C4CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C4D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C4E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C4EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C4F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C504);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", D_0013C50C);

int mes_event_handle_event(MesContext *ctx, MesObject *obj, int type)
{
    MesObject *self;
    int f;

    if (mes_class_instance_of(obj, mes_event_class) == 1) {
        self = ctx->frame->thisobj;
        switch (type) {
        case 1:
            f = mes_class_property_get(ctx, self, "onabort");
            break;
        case 2:
            f = mes_class_property_get(ctx, self, "onblur");
            break;
        case 3:
            f = mes_class_property_get(ctx, self, "onchange");
            break;
        case 4:
            f = mes_class_property_get(ctx, self, "onclick");
            break;
        case 7:
            f = mes_class_property_get(ctx, self, "onerror");
            break;
        case 8:
            f = mes_class_property_get(ctx, self, "onfocus");
            break;
        case 12:
            f = mes_class_property_get(ctx, self, "onload");
            break;
        case 13:
            f = mes_class_property_get(ctx, self, "onmousedown");
            break;
        case 14:
            f = mes_class_property_get(ctx, self, "onmousemove");
            break;
        case 15:
            f = mes_class_property_get(ctx, self, "onmouseout");
            break;
        case 16:
            f = mes_class_property_get(ctx, self, "onmouseover");
            break;
        case 18:
            f = mes_class_property_get(ctx, self, "onmove");
            break;
        case 20:
            f = mes_class_property_get(ctx, self, "onresize");
            break;
        case 21:
            f = mes_class_property_get(ctx, self, "onselect");
            break;
        case 17:
        case 19:
        case 22:
            f = mes_class_property_get(ctx, self, "onmouseup");
            break;
        case 23:
            f = mes_class_property_get(ctx, self, "onunload");
            break;
        default:
            f = 0x20;
            break;
        }
        if (f != 0x20)
            mes_class_call(ctx, f, ctx->frame->args != NULL ? ctx->frame->args->argc : 0,
                           ctx->frame->args != NULL ? ctx->frame->args->argv : NULL, self);
    }
    return 0xC;
}
