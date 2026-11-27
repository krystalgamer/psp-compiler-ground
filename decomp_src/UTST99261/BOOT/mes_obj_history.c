/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
typedef struct MesStrH {
    DOMChar *str;
    unsigned int len;
} MesStrH;
typedef struct HistMsg {
    int f0;
    int f4;
    int len;
    DOMChar str[2];
} HistMsg;
extern int *g_JS_PAGECHANGED_;
void *HST_getHistoryWithOffset(int n);
void *HST_getHeadHistoryNode(void);
char *HST_getCurURI(void *node);
int HST_getSessionID(void *node);
MesValue mes_string_new2(MesContext *ctx, const char *s, int len);
DOMChar *mes_util_strcp2(DOMChar *d, MesStrH *s);
char *strstr(const char *a, const char *b);
extern MesClassDef mes_history_def;
extern MesClass *mes_history_class;
MesValue mes_history_go_inner(MesContext *ctx, int n);
int HST_getHistoryLength(void);

MesValue mes_history_go_inner(MesContext *ctx, int n)
{
    IpcMsg msg;
    int offset = 0;
    HistMsg *buf = NULL;
    int size = 0;
    int ok = 0;
    MesValue s;
    MesStrH *str;

    if (n != 0 && HST_getHistoryWithOffset(n) != NULL) {
        offset = n;
        ok = 1;
    } else if (n == 0) {
        s = mes_string_new2(ctx, HST_getCurURI(HST_getHeadHistoryNode()), 0);
        if (s != 0) {
            *--ctx->sp = s;
            str = (MesStrH *)(s & ~3);
            size = str->len * 2 + 0x10;
            buf = MEM_malloc(0, size);
            if (buf != NULL) {
                buf->f0 = 1;
                buf->f4 = 1;
                buf->len = str->len;
                mes_util_strcp2(buf->str, str);
                ok = 1;
            }
            ctx->sp++;
        }
    }
    if (ok == 1) {
        SetIpcMember(&msg, 8, HST_getSessionID(HST_getHeadHistoryNode()), 0, 0x805, offset, size, buf);
        if (JSSendMail(&msg, "/tmp/mq_lo") == 0)
            *g_JS_PAGECHANGED_ = ok;
    }
    return 0;
}

MesValue mes_history_back(MesContext *ctx)
{
    return mes_history_go_inner(ctx, -1);
}

MesValue mes_history_forward(MesContext *ctx)
{
    return mes_history_go_inner(ctx, 1);
}

MesValue mes_history_go(MesContext *ctx, MesValue v)
{
    int n = 0;
    int ok = 0;
    MesStrH *s;
    char *buf;
    unsigned int i;
    int fwd, back, m;
    void *h;
    MesValue ret;

    if ((v & 3) == 1) {
        n = v >> 2;
        ok = 1;
    } else if ((v & 3) == 3) {
        s = (MesStrH *)(v & ~3);
        buf = MEM_malloc(0, s->len);
        if (buf != NULL) {
            for (i = 0; i < s->len; i++)
                buf[i] = s->str[i];
            buf[i] = 0;
            back = 1;
            fwd = 1;
            n = 1;
            do {
                if (fwd) {
                    h = HST_getHistoryWithOffset(n);
                    if (h != NULL) {
                        if (strstr(HST_getCurURI(h), buf) != NULL) {
                            ok = 1;
                            break;
                        }
                    } else
                        fwd = 0;
                }
                if (back) {
                    m = -n;
                    h = HST_getHistoryWithOffset(m);
                    if (h != NULL) {
                        if (strstr(HST_getCurURI(h), buf) != NULL) {
                            n = m;
                            ok = 1;
                            break;
                        }
                    } else
                        back = 0;
                }
                n++;
            } while (fwd | back);
            MEM_free(0, buf);
        }
    }
    ret = 0;
    if (ok == 1)
        ret = mes_history_go_inner(ctx, n);
    return ret;
}

MesValue mes_history_get(MesContext *ctx, MesObject *obj, void *elem, int id)
{
    MesValue ret = MES_UNDEFINED;

    if (id == 2)
        ret = HST_getHistoryLength() * 4 | 1;
    return ret;
}

void mes_history_mark(void) {
}

void mes_history_free(void) {
}

void mes_history_class_init(MesContext *ctx)
{
    mes_history_class = mes_class_init(ctx, &mes_history_def);
}

MesObject *mes_history_new(MesContext *ctx)
{
    return mes_class_new(ctx, mes_history_class);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F89C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F8A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F8AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F8B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F8C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F8C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F8D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F8D4);
