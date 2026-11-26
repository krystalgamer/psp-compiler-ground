/* cflags: -O1 */
#include "common.h"
#include "dom_esp.h"
#include "m2c_macros.h"
extern void *jsapi_lock;
extern char *gESPRIT_LO_GLOBAL_NDA;
void OS_thread_mutex_lock(void *m);
void OS_thread_mutex_unlock(void *m);
void SetIpcmsg(void *m, void *b);
void *memcpy(void *d, const void *s, unsigned int n);
char *strcpy(char *d, const char *s);
int HST_getCurrentIndex(void);
char *HST_getCurURI(void *node);
char *HST_getTitle(void *node);
extern char D_00133A54[];
int OS_mq_open(const char *name, int mode);
int OS_mq_send(int q, void *msg, int len, int prio);
int OS_mq_close(int q);
int JSPtrListFind(JSPtr *p);
int JSPtrListFindEmpty(void);
M2C_UNK HST_attachHistory();                        /* extern */
int GUI_RadioButton_getState(int);                  /* extern */
void *Node_getBox();                                /* extern */
extern void *gPREF_UI;
void *duplicateDOMString(int);                      /* extern */
extern void *gNDA_NAME_JS_GLOBAL;
M2C_UNK js_delTimerID(int, M2C_UNK, M2C_UNK);       /* extern */
int OS_thread_self();                               /* extern */
int esp_postMsgLoadPage(int, int, int, M2C_UNK, M2C_UNK, int, M2C_UNK); /* extern */
M2C_UNK esp_postMsgSaveURL(int, int, int);          /* extern */
M2C_UNK esp_postMsgDataAttr(int, M2C_UNK, int, int); /* extern */
int MEM_addHaltCallback(M2C_UNK, int);              /* extern */

extern int attached;
M2C_UNK newDOMString_4B5FC();                       /* extern */
M2C_UNK esp_getMemoNum();                           /* extern */
M2C_UNK esp_loadMemoList();                         /* extern */
M2C_UNK HST_getHistoryLength();                     /* extern */
M2C_UNK HST_getCurrentIndex();                      /* extern */
M2C_UNK esp_setDialogReply();                       /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", newDOMString_4B5FC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", duplicateDOMString);

#ifndef NULL
#define NULL ((void *)0)
#endif

int JSI_init(void) {
    HST_attachHistory();
    attached = 1;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_free(void) {
    attached = 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getElementPosition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setButtonValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getCheckboxState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setCheckboxState);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", D_00133A2C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getDocumentCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setDocumentCookie);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getDocumentLastModified);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getDocumentReferrer);

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_getDocumentSelection(void) {
    newDOMString_4B5FC(0, 0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getDocumentSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getFileUploadValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getImageComplete);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getLinkURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setLinkURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getDocumentURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getOptionState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setOptionState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getOptionText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setOptionText);

#ifndef NULL
#define NULL ((void *)0)
#endif

int JSI_getRadioState(int arg0) {
    void *temp_v0;

    if ((arg0 == 0) || (temp_v0 = Node_getBox(), (temp_v0 == NULL)) || (M2C_FIELD(temp_v0, short *, 0x38) != 0xF)) {
        return -1;
    }
    return GUI_RadioButton_getState(M2C_FIELD(temp_v0, int *, 0x2C)) != 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setRadioState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getSelectedIndex);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setSelectedIndex);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getTextValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setTextValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getWindowRec);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getWindowName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setWindowName);

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int strlen(const char *s);

void JSI_getBrowserHomeURL(void) {
    void *temp_s0;

    temp_s0 = gPREF_UI;
    newDOMString_4B5FC(M2C_FIELD(temp_s0, int *, 0x40), strlen(M2C_FIELD(temp_s0, signed char **, 0x40)));
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getAbsoluteURL);

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_freeDOMString(void *arg0) {
    void *temp_a1;

    if (arg0 != NULL) {
        temp_a1 = M2C_FIELD(arg0, void **, 8);
        if (temp_a1 != NULL) {
            MEM_free(0, temp_a1);
        }
        MEM_free(0, arg0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_freeURLRec(void *arg0) {
    if (arg0 != NULL) {
        JSI_freeDOMString(M2C_FIELD(arg0, int *, 4));
        JSI_freeDOMString(M2C_FIELD(arg0, int *, 8));
        JSI_freeDOMString(M2C_FIELD(arg0, int *, 0xC));
        JSI_freeDOMString(M2C_FIELD(arg0, int *, 0x10));
        JSI_freeDOMString(M2C_FIELD(arg0, int *, 0x14));
        MEM_free(0, arg0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_setURLProtocol(void *arg0, int arg1) {
    int temp_a0;
    void *temp_v0;

    temp_v0 = duplicateDOMString(arg1);
    temp_a0 = M2C_FIELD(temp_v0, int *, 4);
    if ((temp_a0 != 0) && (M2C_FIELD(((temp_a0 * 2) + M2C_FIELD(temp_v0, int *, 8)), unsigned short *, -2) == 0x3A)) {
        M2C_FIELD(temp_v0, int *, 0) = (int) (M2C_FIELD(temp_v0, int *, 0) - 1);
        M2C_FIELD(temp_v0, int *, 4) = (int) (temp_a0 - 1);
    }
    JSI_freeDOMString(M2C_FIELD(arg0, void **, 4));
    M2C_FIELD(arg0, void **, 4) = temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void JSI_setURLPort(short *arg0, short arg1) {
    *arg0 = arg1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_setURLHost(void *arg0, int arg1) {
    int temp_s1;

    temp_s1 = duplicateDOMString(arg1);
    JSI_freeDOMString(M2C_FIELD(arg0, int *, 8));
    M2C_FIELD(arg0, int *, 8) = temp_s1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setURLPathname);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setURLHash);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setURLSearch);

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_newDOMString(void) {
    newDOMString_4B5FC();
}

int JSSendMail(JSMsgBody *b, const char *qname) {
    JSMsg msg;
    char *nda;
    int q;

    if (b->cmd == 0x809) {
        nda = gESPRIT_LO_GLOBAL_NDA;
        OS_thread_mutex_unlock(jsapi_lock);
        OS_thread_mutex_lock(*(void **)(nda + 0x40));
        OS_thread_mutex_lock(jsapi_lock);
    }
    q = OS_mq_open(qname, 1);
    if (q == -1) {
        return -1;
    }
    SetIpcmsg(&msg, b);
    OS_mq_send(q, &msg, sizeof(msg), 0);
    OS_mq_close(q);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSWaitMail);

#ifndef NULL
#define NULL ((void *)0)
#endif
void SetIpcMember(void *arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6, int arg7) {
    M2C_FIELD(arg0, int *, 0) = arg1;
    M2C_FIELD(arg0, int *, 4) = arg2;
    M2C_FIELD(arg0, int *, 8) = arg3;
    M2C_FIELD(arg0, int *, 0xC) = arg4;
    M2C_FIELD(arg0, int *, 0x10) = arg5;
    M2C_FIELD(arg0, int *, 0x14) = 0;
    M2C_FIELD(arg0, int *, 0x18) = arg6;
    M2C_FIELD(arg0, int *, 0x1C) = arg7;
}

void SetIpcmsg(void *m, void *b) {
    memcpy((char *)m + 4, b, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *init_global_ptr(void) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = MEM_malloc(0, 0x24);
    var_v0 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0) = 0;
        M2C_FIELD(temp_v0, int *, 4) = 0;
        M2C_FIELD(temp_v0, int *, 8) = 0;
        M2C_FIELD(temp_v0, int *, 0xC) = 0;
        M2C_FIELD(temp_v0, int *, 0x10) = 0;
        M2C_FIELD(temp_v0, int *, 0x14) = 0;
        M2C_FIELD(temp_v0, int *, 0x18) = 0;
        M2C_FIELD(temp_v0, int *, 0x1C) = 0;
        M2C_FIELD(temp_v0, int *, 0x20) = 0;
        gNDA_NAME_JS_GLOBAL = temp_v0;
        var_v0 = temp_v0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void delete_global_ptr(void) {
    int temp_v0;

    temp_v0 = get_global_ptr();
    gNDA_NAME_JS_GLOBAL = 0;
    MEM_free(0, temp_v0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int get_global_ptr(void) {
    return gNDA_NAME_JS_GLOBAL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void js_InitTimer(void) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x18);
    M2C_FIELD(temp_v0, int *, 4) = -1;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0xC) = 0;
    M2C_FIELD(temp_v0, int *, 0x10) = 0;
    M2C_FIELD(temp_v0, int *, 0x14) = 0;
    g_JS_TIMER_ = temp_v0;
}

int js_getTimerStatus(int id) {
    JSTimer *t;

    for (t = g_JS_TIMER_; t != NULL; t = t->next) {
        if (t->id == id) {
            return t->status;
        }
    }
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int getTimerNum(void) {
    int var_v1;
    void *var_v0;

    var_v1 = 0;
    if (g_JS_TIMER_ != NULL) {
        var_v0 = M2C_FIELD(g_JS_TIMER_, void **, 0x14);
        if (var_v0 != NULL) {
            do {
                var_v0 = M2C_FIELD(var_v0, void **, 0x14);
                var_v1 += 1;
            } while (var_v0 != NULL);
        }
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int js_checkAddTimer(void) {
    return (getTimerNum() < 0xB) - 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void js_DestroyTimer(void) {
    void *temp_s0;

    temp_s0 = g_JS_TIMER_;
    if (M2C_FIELD(temp_s0, void **, 0x14) != NULL) {
        do {
            js_delTimerID(M2C_FIELD(M2C_FIELD(temp_s0, void **, 0x14), int *, 4), 3, 0);
        } while (M2C_FIELD(temp_s0, void **, 0x14) != NULL);
    }
    MEM_free(0, temp_s0);
    g_JS_TIMER_ = NULL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void js_addTimer(int arg0, int arg1, int arg2, int arg3) {
    void *temp_v0;
    void *var_s4;

    var_s4 = g_JS_TIMER_;
    temp_v0 = MEM_malloc(0, 0x18);
    M2C_FIELD(temp_v0, int *, 0) = arg1;
    M2C_FIELD(temp_v0, int *, 4) = arg0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0xC) = arg2;
    M2C_FIELD(temp_v0, int *, 0x10) = arg3;
    M2C_FIELD(temp_v0, int *, 0x14) = 0;
    if (M2C_FIELD(var_s4, int *, 0x14) != 0) {
        do {
            var_s4 = M2C_FIELD(var_s4, void **, 0x14);
        } while (M2C_FIELD(var_s4, int *, 0x14) != 0);
    }
    M2C_FIELD(var_s4, void **, 0x14) = temp_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", js_delTimerID);

int searchTimerCx(void *cx) {
    JSTimer *t;

    for (t = g_JS_TIMER_; t != NULL; t = t->next) {
        if (t->cx == cx) {
            return t->id;
        }
    }
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void js_delTimerCx(int arg0) {
    void *var_s0;

    var_s0 = g_JS_TIMER_;
    if (var_s0 != NULL) {
        do {
            if (M2C_FIELD(var_s0, int *, 0x10) == arg0) {
                js_delTimerID(M2C_FIELD(var_s0, int *, 4), 3, 1);
            }
            var_s0 = M2C_FIELD(var_s0, void **, 0x14);
        } while (var_s0 != NULL);
    }
}

void JSPtrListInit(void) {
    JSPtr **list = MEM_malloc(0, 10 * sizeof(JSPtr *));
    int i;

    for (i = 0; i < 10; i++) {
        list[i] = MEM_malloc(0, sizeof(JSPtr));
        list[i]->cx = NULL;
        list[i]->x04 = 0;
        list[i]->next = NULL;
    }
    g_JSPTRLIST_ = list;
}

void JSPtrListDestroy(void) {
    JSPtr **list = g_JSPTRLIST_;
    int i;

    for (i = 0; i < 10; i++) {
        MEM_free(0, list[i]);
    }
    MEM_free(0, list);
    g_JSPTRLIST_ = NULL;
}

int JSPtrListFindCx(void *cx) {
    JSPtr **list;
    int i;

    if (cx == NULL) {
        return -1;
    }
    list = g_JSPTRLIST_;
    for (i = 0; i < 10; i++) {
        if (list[i]->cx == cx) {
            return i;
        }
    }
    return -1;
}

int JSPtrListFind(JSPtr *p) {
    JSPtr **list;
    int i;

    if (p == NULL) {
        return -1;
    }
    list = g_JSPTRLIST_;
    for (i = 0; i < 10; i++) {
        if (list[i]->cx == p->cx) {
            return i;
        }
    }
    return -1;
}

int JSPtrListFindEmpty(void) {
    JSPtr **list = g_JSPTRLIST_;
    int i;

    for (i = 0; i < 10; i++) {
        if (list[i]->cx == NULL) {
            return i;
        }
    }
    return -1;
}

void JSPtrListAdd(JSPtr *p) {
    JSPtr **list;
    JSPtr *q;
    int i;

    if (p == NULL) {
        return;
    }
    list = g_JSPTRLIST_;
    p->next = NULL;
    i = JSPtrListFind(p);
    if (i != -1) {
        q = list[i];
        while (q->next != NULL) {
            q = q->next;
            if (q == p) {
                return;
            }
        }
        q->next = p;
        return;
    }
    i = JSPtrListFindEmpty();
    if (i == -1) {
        return;
    }
    list[i]->x0C = 0;
    list[i]->next = p;
    list[i]->cx = p->cx;
}

void JSPtrListDel(JSPtr *p) {
    JSPtr **list;
    JSPtr *q;
    int i;

    if (p == NULL) {
        return;
    }
    i = JSPtrListFind(p);
    if (i == -1) {
        return;
    }
    list = g_JSPTRLIST_;
    q = list[i];
    while (q->next != p) {
        q = q->next;
        if (q == NULL) {
            return;
        }
    }
    q->next = p->next;
    p->next = NULL;
    if (list[i]->next == NULL) {
        list[i]->cx = NULL;
        list[i]->x0C = 0;
    }
}

void JSPtrListDelAll(JSPtr *p) {
    JSPtr **list;
    int i;

    if (p == NULL) {
        return;
    }
    i = JSPtrListFind(p);
    if (i == -1) {
        return;
    }
    list = g_JSPTRLIST_;
    list[i]->next = NULL;
    list[i]->cx = NULL;
    list[i]->x0C = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSRunStart(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0xC) = OS_thread_self();
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void JSRunFinish(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0xC) = 0;
    }
}

void JSPtrListDumpAll(void) {
    JSPtr **list = g_JSPTRLIST_;
    JSPtr *q;
    int i;

    for (i = 0; i < 10; i++) {
        for (q = list[i]->next; q != NULL; q = q->next) {
        }
    }
}

void JSPtrListDumpOne(JSPtr *p) {
    JSPtr *q;
    int i;

    if (p == NULL) {
        return;
    }
    i = JSPtrListFind(p);
    if (i == -1) {
        return;
    }
    for (q = g_JSPTRLIST_[i]->next; q != NULL; q = q->next) {
    }
}

int JSFreeJSPtr(JSPtr *p) {
    JSPtr **list;
    JSPtr *q, *next;
    int i;

    if (p == NULL) {
        return -1;
    }
    js_delTimerCx(p->cx);
    mes_context_free(p->cx);
    i = JSPtrListFind(p);
    if (i == -1) {
        return -1;
    }
    list = g_JSPTRLIST_;
    q = list[i]->next;
    list[i]->next = NULL;
    list[i]->cx = NULL;
    while (q != NULL) {
        next = q->next;
        MEM_free(0, q);
        q = next;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSCreate);

int JSStart(void) {
    JSMsgBody b;
    JSMsg msg;
    int q;

    q = OS_mq_open(D_00133A54, 1);
    if (q == -1) {
        return -1;
    }
    b.x04 = 0;
    b.x08 = 0;
    b.x10 = 0;
    b.x14 = 0;
    b.x18 = 0;
    b.x1C = 0;
    b.type = 4;
    b.cmd = 0x401;
    msg.body = b;
    OS_mq_send(q, &msg, sizeof(msg), 0);
    OS_mq_close(q);
    return 0;
}

int JSRun(JSMsgBody *b) {
    JSMsg msg;
    int q;

    q = OS_mq_open(D_00133A54, 1);
    if (q == -1) {
        return -1;
    }
    msg.body = *b;
    OS_mq_send(q, &msg, sizeof(msg), 0);
    OS_mq_close(q);
    return 0;
}

int JSDestroy(JSMsg *m) {
    int q;

    q = OS_mq_open(D_00133A54, 1);
    if (q == -1) {
        return -1;
    }
    OS_mq_send(q, m, sizeof(JSMsg), 0);
    OS_mq_close(q);
    MEM_free(0, m);
    return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", D_00133A50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", D_00133A54);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSHandleEvent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_initCore);

int ESP_initCookie(int a, int b, int c) {
    return iom_cookieFile_init(c, a, b);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_startCore);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_terminateCore);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_destroyCore);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_loadPage);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", D_00133BB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", D_00133BC4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_submitForm);

int ESP_moveHistory(int off) {
    void *head;

    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    head = HST_getHeadHistoryNode();
    if (off == 0) {
        return ESP_reloadPage(1);
    }
    if (HST_getHistoryWithOffset(off) == NULL) {
        if (HST_getFragmentIDs(head, off) == 0) {
            return -1;
        }
    }
    return esp_postMsgLoadPage(esp_context->msg, 0, 0, off, 0, 3, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ESP_reloadPage(int arg0) {
    int *temp_v0;
    int temp_s0;
    int var_v0;

    temp_v0 = HST_getHeadHistoryNode();
    var_v0 = -1;
    if (temp_v0 != NULL) {
        temp_s0 = HST_getCurURI(temp_v0);
        var_v0 = esp_postMsgLoadPage(M2C_FIELD(esp_context, int *, 0xF8), temp_s0, HST_getRefURI(temp_v0), 0, 1, arg0 != 1, 0);
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_abortLoading);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_handleDeviceEvent);

#ifndef NULL
#define NULL ((void *)0)
#endif
int ESP_saveCurrentPage(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int ESP_deleteSavedPage(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int ESP_deleteAllSavedPage(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_getSavedPageNum(void) {
    esp_getMemoNum();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_loadSavedPageList(void) {
    esp_loadMemoList();
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void ESP_freeSavedPageList(int arg0) {
    if (arg0 != 0) {
        esp_freeMemoList();
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_downloadURL(int arg0, int arg1) {
    esp_postMsgSaveURL(M2C_FIELD(esp_context, int *, 0xF8), arg0, arg1);
}

int ESP_setFreeScrollEnabled(int en) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    return esp_postMsgFreeScroll(esp_context->msg, en);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_findString);

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_getPositionAttribute(int arg0, int arg1) {
    esp_postMsgDataAttr(M2C_FIELD(esp_context, int *, 0xF8), 0, arg0, arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_getFocusAttribute(void) {
    esp_postMsgDataAttr(M2C_FIELD(esp_context, int *, 0xF8), 1, 0, 0);
}

int ESP_setTextField(const char *text) {
    EspDevEvent *ev;

    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (text == NULL) {
        return -1;
    }
    ev = MEM_malloc(0, strlen(text) + sizeof(EspDevEvent) + 1);
    if (ev == NULL) {
        return -1;
    }
    ev->type = 0x19;
    ev->x04 = 0;
    ev->str = (char *)(ev + 1);
    strcpy(ev->str, text);
    return esp_postMsgDeviceEvent(esp_context->msg, ev);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_getHistoryLength(void) {
    HST_getHistoryLength();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_currentHistoryIndex(void) {
    HST_getCurrentIndex();
}

char *ESP_getHistoryURL(int off) {
    char *url = NULL;
    char *r = NULL;
    int idx;
    void *node;

    idx = HST_getCurrentIndex();
    if (idx < 0) {
        return NULL;
    }
    node = HST_getHistoryWithOffset(off - idx);
    if (node != NULL) {
        url = HST_getCurURI(node);
    }
    if (url == NULL) {
        return r;
    }
    r = (char *)ESP_malloc(strlen(url) + 1);
    if (r == NULL) {
        return NULL;
    }
    strcpy(r, url);
    return r;
}

char *ESP_getHistoryTitle(int off) {
    char *title = NULL;
    char *r = NULL;
    int idx;
    void *node;

    idx = HST_getCurrentIndex();
    if (idx < 0) {
        return NULL;
    }
    node = HST_getHistoryWithOffset(off - idx);
    if (node != NULL) {
        title = HST_getTitle(node);
    }
    if (title == NULL) {
        return r;
    }
    r = (char *)ESP_malloc(strlen(title) + 1);
    if (r == NULL) {
        return NULL;
    }
    strcpy(r, title);
    return r;
}

int ESP_hasNextHistory(void) {
    if (HST_getHistoryWithOffset(1) != NULL) {
        return 1;
    }
    return HST_getFragmentIDs(HST_getHeadHistoryNode(), 1) != 0;
}

int ESP_hasPreviousHistory(void) {
    if (HST_getHistoryWithOffset(-1) != NULL) {
        return 1;
    }
    return HST_getFragmentIDs(HST_getHeadHistoryNode(), -1) != 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int ESP_deleteCache(void) {
    return -1;
}

int ESP_setCookieEnabled(int en) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_context->config.cookieEnabled == en) {
        return 0;
    }
    if (ESP_beginConfig() != 0) {
        return -1;
    }
    ESP_setBoolPreference(0, en);
    if (ESP_endConfig() != 0) {
        return -1;
    }
    return 0;
}

int ESP_deleteAllCookies(void) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    return esp_postMsgDeleteCookie(esp_context->msg);
}

int ESP_setMouseTracking(int en) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_beginConfig);

int ESP_endConfig(void) {
    int r;

    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_context->prefs == NULL) {
        return -1;
    }
    esp_freeConfig(&esp_context->config);
    r = esp_copyConfig(&esp_context->config, esp_context->prefs);
    if (r != 0) {
        return r;
    }
    esp_postMsgConfigChanged(esp_context->msg);
    esp_freeConfig(esp_context->prefs);
    MEM_free(0, esp_context->prefs);
    esp_context->prefs = NULL;
    return 0;
}

int ESP_setBoolPreference(int key, int value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_context->prefs == NULL) {
        return -1;
    }
    return esp_setBoolConfig(esp_context->prefs, key, value);
}

int ESP_getBoolPreference(int key, void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (value == NULL) {
        return -1;
    }
    return esp_getBoolConfig(&esp_context->config, key, value);
}

int ESP_setIntPreference(int key, int value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_context->prefs == NULL) {
        return -1;
    }
    return esp_setIntConfig(esp_context->prefs, key, value);
}

int ESP_getIntPreference(int key, void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (value == NULL) {
        return -1;
    }
    return esp_getIntConfig(&esp_context->config, key, value);
}

int ESP_setStringPreference(int key, int value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_context->prefs == NULL) {
        return -1;
    }
    return esp_setStringConfig(esp_context->prefs, key, value);
}

int ESP_getStringPreference(int key, void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (value == NULL) {
        return -1;
    }
    return esp_getStringConfig(&esp_context->config, key, value);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_setEncoding);

int ESP_getEncoding(int *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (value == NULL) {
        return -1;
    }
    return esp_getIntConfig(&esp_context->config, 0x1001, value);
}

int ESP_setOnlineEnabled(int en) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    return esp_setIntConfig(&esp_context->config, 0x1004, en);
}

int ESP_setFontSize(int size) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (size < 1 || size > 5) {
        return -1;
    }
    if (esp_setIntConfig(&esp_context->config, 0x1002, size) < 0) {
        return -1;
    }
    return esp_postMsgRepaint(esp_context->msg);
}

int ESP_getFontSize(void) {
    int size;

    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_getIntConfig(&esp_context->config, 0x1002, &size) < 0) {
        return -1;
    }
    return size;
}

int ESP_setInputData(void *data) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    return esp_postMsgInputData(esp_context->msg, data);
}

int ESP_setEnabledInputDevice(int dev) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    esp_context->inputDevice = dev;
    return 0;
}

int ESP_setUnitId(void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_setStringConfig(&esp_context->config, 0x2004, value) < 0) {
        return -1;
    }
    return 0;
}

int ESP_getUnitId(void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_getStringConfig(&esp_context->config, 0x2004, value) < 0) {
        return -1;
    }
    return 0;
}

int ESP_setBgColor(void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_setStringConfig(&esp_context->config, 0x2005, value) < 0) {
        return -1;
    }
    return 0;
}

int ESP_getBgColor(void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_getStringConfig(&esp_context->config, 0x2005, value) < 0) {
        return -1;
    }
    return 0;
}

int ESP_setThreadPriority(void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_setIntConfig(&esp_context->config, 0x1005, value) < 0) {
        return -1;
    }
    return 0;
}

int ESP_getThreadPriority(void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_getIntConfig(&esp_context->config, 0x1005, value) < 0) {
        return -1;
    }
    return 0;
}

int ESP_setHomePageURL(void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_setStringConfig(&esp_context->config, 0x2000, value) < 0) {
        return -1;
    }
    return 0;
}

int ESP_getHomePageURL(void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_getStringConfig(&esp_context->config, 0x2000, value) < 0) {
        return -1;
    }
    return 0;
}

int ESP_setUserAgent(void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_setStringConfig(&esp_context->config, 0x2003, value) < 0) {
        return -1;
    }
    return 0;
}

int ESP_getUserAgent(void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_getStringConfig(&esp_context->config, 0x2003, value) < 0) {
        return -1;
    }
    return 0;
}

int ESP_setCacheSize(void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_setIntConfig(&esp_context->config, 0x1000, value) < 0) {
        return -1;
    }
    return 0;
}

int ESP_getCacheSize(void *value) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_getIntConfig(&esp_context->config, 0x1000, value) < 0) {
        return -1;
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ESP_guiMemAlloc(int arg0) {
    int temp_s0;
    int var_s1;

    var_s1 = 0;
    if (esp_context != 0) {
        temp_s0 = MEM_addHaltCallback(0, 0);
        var_s1 = MEM_malloc(0, arg0);
        MEM_addHaltCallback(0, temp_s0);
    }
    return var_s1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_guiMemFree(int arg0) {
    if (esp_context != 0) {
        MEM_free(0, arg0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ESP_malloc(int arg0) {
    int temp_s0;
    int var_s1;

    var_s1 = 0;
    if (esp_context != 0) {
        temp_s0 = MEM_addHaltCallback(0, 0);
        var_s1 = MEM_malloc(0, arg0);
        MEM_addHaltCallback(0, temp_s0);
    }
    return var_s1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_free(int arg0) {
    if (esp_context != 0) {
        MEM_free(0, arg0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ESP_setModelessDialogReply(void) {
    esp_setDialogReply();
}
