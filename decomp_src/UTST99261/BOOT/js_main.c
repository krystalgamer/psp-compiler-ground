/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
#define JSTimer JSTimer_t
#include "dom_esp.h"
void JS_halt();
#undef JSTimer
extern char D_001339EC[];
extern int *g_JS_MSG_SID_;
extern int *g_JS_PAGECHANGED_;
extern void *g_JS_EVENT_REC_;
extern void *g_JS_NEEDREDRAW_;
extern int g_JSRUNTIME_;
extern int *js_err_msg;
extern void *jsapi_lock;
extern char D_001339E0[];
int JSEventLoop();                                  /* extern */
M2C_UNK JSInitInternal();                           /* extern */
M2C_UNK OS_thread_exit(M2C_UNK);                    /* extern */


void JSStartInternal(int x) {
    int m[8];

    SetIpcMember(m, 8, x, 1, 0x801, 0, 0, 0);
    JSSendMail(m, D_001339E0);
}

void JSRunInternal(int *msg) {
    int *g;
    int **arg;
    unsigned short *src;
    int *ctx;
    int len;
    void *buf;
    int r;
    int r0;
    int *res;
    int m[8];
    int *sidp;
    int *pcp;

    g = get_global_ptr();
    sidp = g_JS_MSG_SID_;
    *sidp = msg[1];
    arg = (int **)msg[7];
    src = (unsigned short *)arg[1];
    ctx = arg[0];
    MEM_free(0, arg);
    JSRunStart(ctx);
    pcp = g_JS_PAGECHANGED_;
    *pcp = 0;
    len = 0;
    while (src[len] != 0) {
        len++;
    }
    r0 = ctx[0];
    buf = js_common_buffer_open(src, len * 2);
    r = js_common_execute(r0, buf, 1);
    js_common_buffer_close(buf);
    MEM_free(0, src);
    if (*pcp != 1) {
        res = MEM_calloc(0, 0xC);
        res[2] = 0;
        res[0] = (r != 0x20) - 1;
        SetIpcMember(m, 8, *sidp, 1, 0x802, 0, 0, res);
        m[5] = msg[5];
        m[6] = 0xC;
        JSSendMail(m, D_001339E0);
    }
    JSRunFinish(ctx);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSFreeJSPtrInternal);

void JSHandleEventInternal(int *msg) {
    int flags;
    int *g;
    int code;
    int *ev;
    int *ctx;
    int cx;
    int obj;
    int m[8];
    int *sidp;
    int *pcp;
    int *nrp;

    flags = 2;
    g = get_global_ptr();
    sidp = g_JS_MSG_SID_;
    *sidp = msg[1];
    code = msg[4];
    ev = (int *)msg[7];
    ctx = (int *)ev[0];
    cx = ctx[0];
    obj = ctx[1];
    *(JSEvRec *)g_JS_EVENT_REC_ = *(JSEvRec *)(ev + 1);
    JSRunStart(ctx);
    pcp = g_JS_PAGECHANGED_;
    *pcp = 0;
    nrp = g_JS_NEEDREDRAW_;
    *nrp = 0;
    if (code != 0) {
        if (js_common_eval(cx, code, 0, obj, 1) == 8) {
            flags &= ~2;
        }
    } else {
        flags |= 1;
    }
    if (*pcp != 1) {
        if (*nrp == 1) {
            flags |= 4;
        }
        SetIpcMember(m, 8, *sidp, 1, 0x804, flags, 0, msg[7]);
        JSSendMail(m, D_001339E0);
        JSRunFinish(ctx);
    } else {
        MEM_free(0, msg[7]);
    }
}

void JSTimer(int *msg) {
    int *g;
    char *t;
    int cx;
    int obj;
    int id;
    int rep;
    char *data;
    int len;
    void *buf;
    int *vals;
    int n;
    int i;
    char *args;

    g = get_global_ptr();
    t = (char *)msg[7];
    if (js_getTimerStatus(M2C_FIELD(t, int *, 0)) == 1) {
        js_delTimerID(M2C_FIELD(t, int *, 0), 3, 0);
        return;
    }
    cx = M2C_FIELD(t, int **, 8)[0];
    obj = M2C_FIELD(t, int **, 8)[1];
    id = M2C_FIELD(t, int *, 0);
    rep = M2C_FIELD(t, int *, 4);
    data = M2C_FIELD(t, char **, 0x10);
    len = M2C_FIELD(t, unsigned short *, 0xC);
    *g_JS_PAGECHANGED_ = 0;
    if (rep == 1) {
        OS_timer_start(id);
    }
    if (msg[4] == 0) {
        buf = js_common_buffer_open(data, len * 2);
        js_common_execute(cx, buf, 1);
        js_common_buffer_close(buf);
    } else if (msg[4] == 1) {
        args = data;
        n = M2C_FIELD(args, unsigned short *, 4);
        vals = mes_util_vals(n, 0);
        for (i = 0; i < n; i++) {
            vals[i + 1] = M2C_FIELD(args, int **, 8)[i + 1];
        }
        js_common_eval(cx, M2C_FIELD(args, int *, 0), vals, obj, 1);
    }
    if (rep == 2) {
        js_delTimerID(id, 2, 0);
    }
}

void JSDestroyInternal(int sid) {
    int *g;
    void *msgbuf;
    int q1;
    int q2;
    int q3;
    int q4;
    int m[8];

    g = get_global_ptr();
    if (g[0] != 0) {
        MEM_free(0, g[0]);
    }
    msgbuf = (void *)g[1];
    q1 = g[5];
    q2 = g[6];
    q3 = g[7];
    q4 = g[8];
    JSI_free();
    DOMAPI_Finalize();
    js_DestroyTimer();
    JSPtrListDestroy();
    delete_global_ptr();
    MEM_free(0, g_JS_EVENT_REC_);
    g_JS_EVENT_REC_ = NULL;
    MEM_free(0, g_JS_MSG_SID_);
    g_JS_MSG_SID_ = NULL;
    MEM_free(0, g_JS_NEEDREDRAW_);
    g_JS_NEEDREDRAW_ = NULL;
    MEM_free(0, g_JS_PAGECHANGED_);
    g_JS_PAGECHANGED_ = NULL;
    g_JSRUNTIME_ = 0;
    SetIpcMember(m, 8, sid, 1, 0x803, 0, 0, 0);
    SetIpcmsg(msgbuf, m);
    OS_mq_send(q3, msgbuf, 0x24, 0);
    OS_mq_close(q1);
    OS_mq_close(q4);
    OS_mq_close(q3);
    OS_mq_close(q2);
    OS_mq_unlink(D_001339EC);
    OS_thread_mutex_destroy(jsapi_lock);
    MEM_free(0, msgbuf);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", D_001339E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", D_001339EC);

void JS_halt(void) {
    int *g;
    JSMsg m;
    JSMsgBody b;
    JSMsg *msg;
    JSMsgBody *bp;

    g = get_global_ptr();
    msg = (JSMsg *)g[0];
    bp = &msg->body;
    bp->type = 8;
    bp->cmd = 0xFFFF;
    bp->x18 = 0;
    bp->x1C = 0;
    if (js_err_msg != NULL) {
        js_err_msg[0] = -1;
        js_err_msg[1] = (int)"AllocationError(JS)";
        bp->x18 = 8;
        bp->x1C = (int)js_err_msg;
        js_err_msg = NULL;
    }
    OS_mq_send(g[8], (void *)g[0], 0x24, 0);
    MEM_free(0, (void *)g[0]);
    g[0] = 0;
    OS_thread_mutex_unlock(jsapi_lock);
    if (g[4] == 0) {
        do {
            if (OS_mq_receive(g[5], &m, 0x24, 0) < 0) {
                break;
            }
            b = m.body;
        } while (b.type != 4 || b.cmd != 0x403);
    }
    mes_id_free();
    JSDestroyInternal(b.x04);
    OS_thread_exit(0);
}

int JSInitInternal(void) {
    int *g;
    int attr[4];
    int *p;

    jsapi_lock = OS_thread_mutex_create();
    if (jsapi_lock == NULL) {
        return -1;
    }
    if (OS_thread_mutex_init(jsapi_lock, 0) != 0) {
        OS_thread_mutex_destroy(jsapi_lock);
        return -1;
    }
    g = init_global_ptr();
    g[5] = OS_mq_open("/tmp/mq_js", 2);
    g[7] = OS_mq_open(D_001339E0, 1);
    g[8] = OS_mq_open("/tmp/mq_ui", 1);
    attr[0] = 0;
    attr[1] = 0x14;
    attr[2] = 0x24;
    attr[3] = 0;
    OS_mq_unlink(D_001339EC);
    g[6] = OS_mq_open(D_001339EC, 0x4202, 0x1C0, attr);
    if (g[6] == -1) {
        return 0;
    }
    JSPtrListInit();
    js_InitTimer();
    HST_attachHistory();
    DOMAPI_Initialize();
    g[1] = (int)MEM_malloc(0, 0x24);
    memset((void *)g[1], 0, 0x24);
    g[0] = (int)MEM_malloc(0, 0x24);
    memset((void *)g[0], 0, 0x24);
    MEM_addHaltCallback(0, JS_halt);
    if (js_err_msg == NULL) {
        js_err_msg = MEM_malloc(0, 8);
    }
    p = MEM_malloc(0, 0x24);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    g_JS_EVENT_REC_ = p;
    g_JS_MSG_SID_ = MEM_malloc(0, 4);
    g_JS_PAGECHANGED_ = MEM_malloc(0, 4);
    g_JS_NEEDREDRAW_ = MEM_malloc(0, 4);
    return 0;
}

int JSEventLoop(void)
{
    int *g;
    JSMsg m;
    JSMsgBody b;
    int r;

    g = get_global_ptr();
    for (;;) {
        m.x00 = 0;
        m.body.type = 0;
        m.body.x04 = 0;
        m.body.x08 = 0;
        m.body.cmd = 0;
        m.body.x10 = 0;
        m.body.x14 = 0;
        m.body.x18 = 0;
        m.body.x1C = 0;
        r = OS_mq_receive(g[6], &m, 0x24, 0);
        if (r == -1)
            OS_mq_receive(g[5], &m, 0x24, 0);
        OS_thread_mutex_lock(jsapi_lock);
        if (m.body.type == 9)
            m = *(JSMsg *)m.body.x04;
        b = m.body;
        switch (b.cmd) {
        case 0x401:
            JSStartInternal(b.x04);
            break;
        case 0x402:
            JSRunInternal((int *)&b);
            break;
        case 0x403:
            g[4] = 1;
            JSFreeJSPtrInternal(b.x1C, b.x04, 0);
            r = b.x04;
            OS_thread_mutex_unlock(jsapi_lock);
            return r;
        case 0x404:
            JSHandleEventInternal((int *)&b);
            break;
        case 0x405:
            break;
        case 0x409:
            JSFreeJSPtrInternal(b.x1C, b.x04, 1);
            break;
        case 0x810:
            JSTimer((int *)&b);
            break;
        }
        OS_thread_mutex_unlock(jsapi_lock);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int esp_jsThread(void) {
    int temp_s1;

    js_err_msg = 0;
    JSInitInternal();
    temp_s1 = JSEventLoop();
    if (js_err_msg != 0) {
        MEM_free(0, js_err_msg);
    }
    JSDestroyInternal(temp_s1);
    OS_thread_exit(0);
    return 0;
}
