/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", mes_window_dialog_inner);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", mes_window_history_move_inner);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", mes_window_set_interval_inner);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", mes_window_home);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", mes_window_get);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", mes_window_put);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", mes_window_new);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", mes_window_set_global_property);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_window", mes_event_handle_event);
