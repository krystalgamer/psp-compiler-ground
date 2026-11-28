/* cflags: -O1 */
#include "common.h"
#include "dom_esp.h"
#include "m2c_macros.h"
extern DOMStr _DOMvalue;
DOMStr Element_getAttribute(void *node, DOMStr *name);
extern int destroyFlag;
extern void *gBEINSI_UI;
extern EspContext *esp_context;
#define VESP (*(EspContext *volatile *)&esp_context)
extern void *jsapi_lock;
extern char *gESPRIT_LO_GLOBAL_NDA;
int OS_thread_mutex_lock(void *m);
int OS_thread_mutex_unlock(void *m);
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
extern void *gNDA_NAME_JS_GLOBAL;
int OS_thread_self();                               /* extern */
int esp_postMsgLoadPage(int, int, int, M2C_UNK, M2C_UNK, int, M2C_UNK); /* extern */
M2C_UNK esp_postMsgSaveURL(int, int, int);          /* extern */
M2C_UNK esp_postMsgDataAttr(int, M2C_UNK, int, int); /* extern */
int MEM_addHaltCallback(M2C_UNK, int);              /* extern */

extern int attached;
M2C_UNK esp_getMemoNum();                           /* extern */
M2C_UNK esp_loadMemoList();                         /* extern */
M2C_UNK HST_getHistoryLength();                     /* extern */
M2C_UNK HST_getCurrentIndex();                      /* extern */
M2C_UNK esp_setDialogReply();                       /* extern */


void *HST_getHttpHeader(void *h);
typedef struct JSOPT { struct JSOPT *next; int u4[4]; int selected; } JSOPT;
int GUI_Choice_select(void *w, int idx);
int GUI_List_select(void *w, int idx);
int GUI_List_deselect(void *w, int idx);
unsigned int Util_HTMLSelectElement_getLength(void *node);
typedef struct JSRAD { void *prev; struct JSRAD *next; void *x8; char *name; } JSRAD;
int GUI_RadioButton_setState(void *w, int state);
int strcmp(const char *a, const char *b);
int get_global_ptr(void);
typedef struct { int type; int sid; int x8; int cmd; int x10; int x14; int x18; int x1C; } JSMSG;
typedef struct { int hdr; JSMSG m; } JSMSGBUF;
int OS_mq_receive(int q, void *buf, int size, int flag);
int OS_mq_send(int q, void *buf, int size, int flag);
int CLIB_time(void *t);
extern char D_00133BB8[];
extern char D_00133BC4[];
int esp_postMsgQuit(void *msg);
int OS_thread_join(int t, int x);
void GUI_Toolkit_freeFont(int f);
void GUI_Toolkit_terminateSystem(void);
int OS_mq_unlink(char *name);
void esp_freeConfig(EspConfig *c);
void OS_timer_destroy(void);
int OS_thread_create(int *tid, int attr, void (*fn)(), char **argv);
int esp_jsThread();
extern char D_00133A2C[];
void *HST_searchDocumentHistoryNode(void *doc);
char *get_cookie(char *uri);
char *strtok(char *s, const char *d);
int strncmp(const char *a, const char *b, unsigned int n);
char *strcat(char *d, const char *s);
int strlen(const char *s);
typedef struct { u16 port; DOMStr *proto; DOMStr *host; DOMStr *path; DOMStr *x10; DOMStr *x14; } JSURLINFO;
typedef struct { char *proto; char *host; int port; char *path; char *x10; char *x14; } JSURL;
JSURL *URL_new(char *s);
void URL_free(JSURL *u);
#define NEWDS(s) ((s) != NULL ? newDOMString_4B5FC((s), strlen(s)) : newDOMString_4B5FC(D_00133A2C, 0))
int ucs2ToAscii(char *d, unsigned short *s, int n);
void URL_setScheme(JSURL *u, char *s);
void URL_setHost(JSURL *u, char *s);
void URL_setPath(JSURL *u, char *s);
void URL_setQuery(JSURL *u, char *s);
void URL_setAnchor(JSURL *u, char *s);
char *URL_toString(JSURL *u);
extern DOMStr _DOMhref;
char *URL_toAbsoluteURL(char *base, char *rel);
char *HST_getBaseURI(void *h);
void *Node_getOwnerDocument(void *n);
typedef struct OptItem { struct OptItem *next; int x4; char *text; } OptItem;
int GUI_List_isIndexSelected();
int GUI_Choice_getSelectedItem();
int Document_createTextNode();
int Node_getFirstChild();
int Node_getChildNodes();
unsigned int NodeList_getLength();
int NodeList_item();
int Node_getNodeType();
int ucs2ToUtf8();
int utf8ToUcs2(unsigned short *d, const char *s, int n);
void Element_setAttribute(void *, void *, void *);
int GUI_Button_setLabel(void *, char *label);
int GUI_Component_update(void *, int x, int y, int width, int height);
int GUI_Checkbox_getState(void *);
int GUI_Checkbox_setState(void *, int v);
int set_cookie(void *x, char *hdr);
void *HST_searchSessionIDHistoryNode(int sid);
void *Node_getSid(void *);
int HST_getRefURI(void *arg0);
int HST_getRefURIlen(void *arg0);
char *GUI_TextField_getText(void *);
void *memset(void *, int, unsigned int);
int Util_HTMLOptionElement_getIndex(void *);
char *GUI_List_getItem(void *, int idx);
char *GUI_Choice_getItem(void *, int idx);
int GUI_List_remove(void *, int idx);
int GUI_List_add(void *, char *text, int pos);
int GUI_Choice_remove(void *, int id);
int GUI_Choice_insert(void *, char *text, int id);
void *Node_appendChild(void *, void *);
void *Node_replaceChild(void *, void *, void *);
int GUI_TextArea_setText(void *, char *s);
int GUI_TextField_setText(void *, char *s);
int GUI_Component_getSize(void *, int *width, int *height);
int GUI_ScrollPane_getScrollPosition(void *, int *x, int *y);
int GUI_ScrollPane_getViewportSize(void *, int *width, int *height);
int HST_getTargetName(void *arg0);
int HST_setTargetName(void *node, const char *src, int len);
void js_delTimerID(int id, int type, int flag);
void OS_timer_clear(int arg0);
void mes_context_free(void *arg0);
int MEM_init(void *, void *mem, unsigned int size);
int FIO_init(void);
void *MEM_calloc(void *, unsigned int size);
int esp_defaultConfig(int *cfg);
int FIO_destroy(void);
void MEM_destroy(void *);
int esp_postMsgSubmitForm(int q, char *url, char *data, int dlen, char *ref, int x, char *hdr);
int ESP_reloadPage(int arg0);
int esp_postMsgStop(int q);
void esp_freeMemoList(void);
int esp_postMsgFreeScroll(int q, int a);
int esp_postMsgFindString(int q, int dir, int flags, char *str);
int esp_postMsgDeviceEvent(int q, void *a);
int ESP_malloc(int arg0);
int esp_postMsgDeleteCookie(int q);
int esp_postMsgConfigChanged(int q);
int esp_postMsgRepaint(int q);
int esp_postMsgInputData(int q, char *str);
DOMStr *newDOMString_4B5FC(const char *utf8, int len) {
    DOMStr *s = MEM_malloc(0, sizeof(DOMStr));

    if (s == NULL) {
        return NULL;
    }
    if (len > 0) {
        s->str = MEM_malloc(0, len * 2 + 2);
        if (s->str == NULL) {
            MEM_free(0, s);
            return NULL;
        }
        s->size = s->len = utf8ToUcs2(s->str, utf8, len);
    } else {
        s->size = 0;
        s->len = 0;
        s->str = NULL;
    }
    return s;
}

DOMStr *duplicateDOMString(DOMStr *src) {
    DOMStr *d = MEM_malloc(0, sizeof(DOMStr));

    if (d == NULL) {
        return NULL;
    }
    d->size = 0;
    d->len = 0;
    d->str = NULL;
    if (src->len != 0) {
        d->str = MEM_malloc(0, src->len * 2);
        if (d->str == NULL) {
            MEM_free(0, d);
            return NULL;
        }
        memcpy(d->str, src->str, src->len * 2);
        d->size = src->len;
        d->len = src->len;
    }
    return d;
}

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

int JSI_getElementPosition(void *node, int *x, int *y) {
    LayoutBox *box;

    if (!attached) {
        JSI_init();
    }
    if (node == NULL || (box = Node_getBox(node)) == NULL) {
        return 0;
    }
    if (x != NULL) {
        *x = box->x;
    }
    if (y != NULL) {
        *y = box->y;
    }
    return 1;
}

int JSI_setButtonValue(void *node, DOMStr *s) {
    LayoutBox *box;
    char *buf;

    if (node == NULL || s == NULL || (box = Node_getBox(node)) == NULL || box->type != 0x10) {
        return 0;
    }
    buf = MEM_malloc(0, s->len * 3 + 1);
    if (buf == NULL) {
        return 0;
    }
    Element_setAttribute(node, &_DOMvalue, s);
    buf[ucs2ToUtf8(buf, s->str, s->len)] = 0;
    OS_thread_mutex_lock(M2C_FIELD(gESPRIT_LO_GLOBAL_NDA, void **, 0x3C));
    if (M2C_FIELD(box->data, char **, 8) != NULL) {
        MEM_free(0, M2C_FIELD(box->data, char **, 8));
    }
    M2C_FIELD(box->data, char **, 8) = buf;
    OS_thread_mutex_unlock(M2C_FIELD(gESPRIT_LO_GLOBAL_NDA, void **, 0x3C));
    if (box->widget != NULL) {
        GUI_Button_setLabel(box->widget, buf);
        GUI_Component_update(box->widget, 0, 0, 0, 0);
    }
    return 1;
}

int JSI_getCheckboxState(void *node) {
    LayoutBox *box;

    if (node == NULL || (box = Node_getBox(node)) == NULL || box->type != 14 || box->widget == NULL) {
        return -1;
    }
    return GUI_Checkbox_getState(box->widget) == 1;
}

int JSI_setCheckboxState(void *node, int state) {
    LayoutBox *box;
    int on;

    if (node == NULL || (box = Node_getBox(node)) == NULL || box->type != 14 || box->widget == NULL) {
        return 0;
    }
    on = state != 0;
    GUI_Checkbox_setState(box->widget, on);
    OS_thread_mutex_lock(*(void **)(gESPRIT_LO_GLOBAL_NDA + 0x3C));
    ((int *)box->data)[2] = on;
    OS_thread_mutex_unlock(*(void **)(gESPRIT_LO_GLOBAL_NDA + 0x3C));
    return 1;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", D_00133A2C);

DOMStr *JSI_getDocumentCookie(void *doc) {
    void *h;
    char *cookie;
    char *out;
    char *tok;
    DOMStr *r = NULL;
    h = HST_searchDocumentHistoryNode(doc);
    if (h == NULL) {
        return r;
    }
    cookie = get_cookie(HST_getCurURI(h));
    if (cookie == NULL) {
        return newDOMString_4B5FC(D_00133A2C, 0);
    }
    out = MEM_malloc(0, strlen(cookie) + 1);
    strcpy(cookie, cookie);
    out[0] = 0;
    for (tok = strtok(cookie, " "); tok != NULL; tok = strtok(NULL, " ")) {
        if (strncmp(tok, "Cookie:", 7) == 0 || tok[0] == '$') {
            continue;
        }
        if (out[0] != 0) {
            strcat(out, " ");
        }
        strcat(out, tok);
    }
    r = newDOMString_4B5FC(out, strlen(out));
    MEM_free(0, cookie);
    MEM_free(0, out);
    return r;
}

int JSI_setDocumentCookie(void *doc, DOMStr *s) {
    void *h;
    char *buf;

    h = HST_searchDocumentHistoryNode(doc);
    if (h == NULL) {
        return 0;
    }
    buf = MEM_malloc(0, s->len * 3 + 1);
    if (buf == NULL) {
        return 0;
    }
    buf[ucs2ToUtf8(buf, s->str, s->len)] = 0;
    set_cookie(HST_getCurURI(h), buf);
    MEM_free(0, buf);
    return 1;
}

DOMStr *JSI_getDocumentLastModified(void *node) {
    void *h;
    if (node == NULL) {
        return NULL;
    }
    if (attached == 0) {
        JSI_init();
    }
    h = HST_searchSessionIDHistoryNode(Node_getSid(node));
    if (h == NULL) {
        return NULL;
    }
    node = HST_getHttpHeader(h);
    if (node == NULL) {
        return NULL;
    }
    if (M2C_FIELD(node, char **, 0x20) == NULL) {
        return NULL;
    }
    return newDOMString_4B5FC(M2C_FIELD(node, char **, 0x20), strlen(M2C_FIELD(node, char **, 0x20)));
}

DOMStr *JSI_getDocumentReferrer(void *node) {
    void *h;
    char *ref;

    if (node == NULL) {
        return NULL;
    }
    if (attached == 0) {
        JSI_init();
    }
    h = HST_searchSessionIDHistoryNode(Node_getSid(node));
    if (h == NULL) {
        return NULL;
    }
    ref = HST_getRefURI(h);
    if (ref == NULL) {
        return NULL;
    }
    return newDOMString_4B5FC(ref, HST_getRefURIlen(h));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void JSI_getDocumentSelection(void) {
    newDOMString_4B5FC(0, 0);
}

int JSI_getDocumentSize(void *node, int *w, int *h) {
    LayoutBox *box;

    if (attached == 0) {
        JSI_init();
    }
    if (node == NULL || (box = Node_getBox(node)) == NULL) {
        return 0;
    }
    if (w != NULL) {
        *w = ((int *)box)[6];
    }
    if (h != NULL) {
        *h = ((int *)box)[7];
    }
    return 1;
}

DOMStr *JSI_getFileUploadValue(void *node) {
    LayoutBox *box;
    char *text;
    DOMStr *r;

    if (node == NULL || (box = Node_getBox(node)) == NULL || box->type != 0xD || box->widget == NULL) {
        return NULL;
    }
    text = GUI_TextField_getText(box->widget);
    if (text == NULL) {
        return NULL;
    }
    r = newDOMString_4B5FC(text, strlen(text));
    MEM_free(0, text);
    return r;
}

int JSI_getImageComplete(void *node) {
    LayoutBox *box;

    if (node == NULL || (box = Node_getBox(node)) == NULL) {
        return 0;
    }
    return *(int *)box->data != 0;
}

JSURLINFO *JSI_getLinkURL(void *node) {
    DOMStr href;
    JSURLINFO *r;
    char *buf;
    char *abs;
    void *h;
    char *base;
    JSURL *u;

    abs = NULL;
    if (node == NULL)
        return NULL;
    if (attached == 0)
        JSI_init();
    href = Element_getAttribute(node, &_DOMhref);
    r = MEM_malloc(0, 0x18);
    if (r == NULL)
        return NULL;
    memset(r, 0, 0x18);
    buf = MEM_malloc(0, href.len * 3 + 1);
    if (buf == NULL)
        goto fail;
    buf[ucs2ToAscii(buf, href.str, href.len)] = 0;
    h = HST_searchSessionIDHistoryNode(Node_getSid(Node_getOwnerDocument(node)));
    if (h == NULL)
        goto fail;
    base = HST_getBaseURI(h);
    if (base == NULL)
        base = HST_getCurURI(h);
    abs = URL_toAbsoluteURL(base, buf);
    u = URL_new(abs);
    if (u == NULL)
        goto fail;
    if (u->port == 0)
        r->port = 80;
    else
        r->port = u->port;
    r->proto = NEWDS(u->proto);
    r->host = NEWDS(u->host);
    r->path = NEWDS(u->path);
    r->x10 = NEWDS(u->x14);
    r->x14 = NEWDS(u->x10);
    URL_free(u);
    MEM_free(0, abs);
    MEM_free(0, buf);
    return r;
fail:
    if (abs != NULL)
        MEM_free(0, abs);
    if (buf != NULL)
        MEM_free(0, buf);
    if (r != NULL)
        MEM_free(0, r);
    return NULL;
}

int JSI_setLinkURL(void *node, JSURLINFO *info) {
    JSURL *u;
    DOMStr *ds;
    char *s;

    u = URL_new(D_00133A2C);
    if (u == NULL)
        return 0;
    if (info->port == 80)
        u->port = 0;
    else
        u->port = info->port;
    ds = info->proto;
    s = MEM_malloc(0, ds->len + 1);
    if (s == NULL) {
        URL_free(u);
        return 0;
    }
    s[ucs2ToAscii(s, ds->str, ds->len)] = 0;
    URL_setScheme(u, s);
    MEM_free(0, s);
    ds = info->host;
    s = MEM_malloc(0, ds->len + 1);
    if (s == NULL) {
        URL_free(u);
        return 0;
    }
    s[ucs2ToAscii(s, ds->str, ds->len)] = 0;
    URL_setHost(u, s);
    MEM_free(0, s);
    ds = info->path;
    s = MEM_malloc(0, ds->len + 1);
    if (s == NULL) {
        URL_free(u);
        return 0;
    }
    s[ucs2ToAscii(s, ds->str, ds->len)] = 0;
    URL_setPath(u, s);
    MEM_free(0, s);
    ds = info->x14;
    s = MEM_malloc(0, ds->len + 1);
    if (s == NULL) {
        URL_free(u);
        return 0;
    }
    s[ucs2ToAscii(s, ds->str, ds->len)] = 0;
    URL_setQuery(u, s);
    MEM_free(0, s);
    ds = info->x10;
    s = MEM_malloc(0, ds->len + 1);
    if (s == NULL) {
        URL_free(u);
        return 0;
    }
    s[ucs2ToAscii(s, ds->str, ds->len)] = 0;
    URL_setAnchor(u, s);
    MEM_free(0, s);
    s = URL_toString(u);
    if (s == NULL) {
        URL_free(u);
        return 0;
    }
    Element_setAttribute(node, &_DOMhref, newDOMString_4B5FC(s, strlen(s)));
    MEM_free(0, s);
    URL_free(u);
    return 1;
}

JSURLINFO *JSI_getDocumentURL(void *node) {
    JSURLINFO *r;
    void *h;
    JSURL *u;
    if (node == NULL) {
        return NULL;
    }
    if (!attached) {
        JSI_init();
    }
    r = MEM_malloc(0, 0x18);
    if (r == NULL) {
        return NULL;
    }
    memset(r, 0, 0x18);
    h = HST_searchSessionIDHistoryNode(Node_getSid(node));
    if (h == NULL || (u = URL_new(HST_getCurURI(h))) == NULL) {
        MEM_free(0, r);
        return NULL;
    }
    if (u->port == 0) {
        r->port = 80;
    } else {
        r->port = u->port;
    }
    r->proto = NEWDS(u->proto);
    r->host = NEWDS(u->host);
    r->path = NEWDS(u->path);
    r->x10 = NEWDS(u->x14);
    r->x14 = NEWDS(u->x10);
    URL_free(u);
    return r;
}

int JSI_getOptionState(void *node) {
    LayoutBox *box;
    int idx;
    int *info;

    if (node == NULL || (box = Node_getBox(node)) == NULL) {
        return -1;
    }
    for (; box != NULL; box = box->parent) {
        if (box->type == 0x12) {
            break;
        }
    }
    if (box == NULL) {
        return -1;
    }
    idx = Util_HTMLOptionElement_getIndex(node);
    info = box->data;
    if (info[1] >= 2 || info[0] == 1) {
        return GUI_List_isIndexSelected(box->widget, idx) != 0;
    }
    return GUI_Choice_getSelectedItem(box->widget) == idx;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_setOptionState);

DOMStr *JSI_getOptionText(void *node) {
    LayoutBox *box;
    LayoutBox *b;
    int idx;
    int *info;
    char *s;
    DOMStr *r;

    if (node == NULL || (box = Node_getBox(node)) == NULL) {
        return NULL;
    }
    idx = Util_HTMLOptionElement_getIndex(node);
    for (b = box->parent; b != NULL; b = b->parent) {
        if (b->type == 0x12) {
            break;
        }
    }
    if (b == NULL) {
        return NULL;
    }
    info = b->data;
    if (info[1] >= 2 || info[0] == 1) {
        s = GUI_List_getItem(b->widget, idx);
    } else {
        s = GUI_Choice_getItem(b->widget, idx);
    }
    r = newDOMString_4B5FC(s, strlen(s));
    MEM_free(0, s);
    return r;
}

int JSI_setOptionText(void *node, DOMStr *text) {
    LayoutBox *box;
    char *s;
    int idx;
    int *info;
    int sel;
    OptItem *p;
    int i;
    int tn;
    int list;
    unsigned int n;
    int c;

    if (node == NULL || (box = Node_getBox(node)) == NULL || box->parent->widget == NULL)
        return 0;
    s = MEM_malloc(0, text->len * 3 + 1);
    if (s == NULL)
        return 0;
    s[ucs2ToUtf8(s, text->str, text->len)] = 0;
    idx = Util_HTMLOptionElement_getIndex(node);
    info = box->parent->data;
    if (info[1] >= 2 || info[0] == 1) {
        sel = GUI_List_isIndexSelected(box->parent->widget, idx);
        GUI_List_remove(box->parent->widget, idx);
        GUI_List_add(box->parent->widget, s, idx);
        if (sel)
            GUI_List_select(box->parent->widget, idx);
    } else {
        sel = idx == GUI_Choice_getSelectedItem(box->parent->widget);
        GUI_Choice_remove(box->parent->widget, idx);
        GUI_Choice_insert(box->parent->widget, s, idx);
        if (sel)
            GUI_Choice_select(box->parent->widget, idx);
    }
    GUI_Component_update(box->parent->widget, 0, 0, 0, 0);
    OS_thread_mutex_lock(M2C_FIELD(gESPRIT_LO_GLOBAL_NDA, void **, 0x3C));
    i = 0;
    for (p = ((OptItem **)box->parent->data)[2]; p != NULL; p = p->next) {
        if (i == idx) {
            if (p->text != NULL)
                MEM_free(0, p->text);
            p->text = s;
            break;
        }
        i++;
    }
    OS_thread_mutex_unlock(M2C_FIELD(gESPRIT_LO_GLOBAL_NDA, void **, 0x3C));
    tn = Document_createTextNode(Node_getOwnerDocument(node), text);
    if (Node_getFirstChild(node) == 0) {
        Node_appendChild(node, tn);
        return 1;
    }
    list = Node_getChildNodes(node);
    for (n = 0; n < NodeList_getLength(list); n++) {
        c = NodeList_item(list, n);
        if (Node_getNodeType(c) == 3) {
            Node_replaceChild(node, tn, c);
            return 1;
        }
    }
    return 1;
}

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

int JSI_setRadioState(void *node, int state) {
    LayoutBox *box;
    JSRAD *p;
    if (node == NULL || (box = Node_getBox(node)) == NULL) {
        return 0;
    }
    if (box->type != 15 || box->widget == NULL) {
        return 0;
    }
    if (state != 0) {
        for (p = M2C_FIELD(((LayoutBox *)Node_getBox(Node_getOwnerDocument(node)))->data, JSRAD **, 0x80); p != NULL; p = p->next) {
            if (strcmp(p->name, *(char **)box->data) == 0) {
                break;
            }
        }
        if (p == NULL) {
            return 0;
        }
        for (p = p->x8; p != NULL; p = p->next) {
            if (M2C_FIELD(((LayoutBox *)p->x8)->data, int *, 8) != 0) {
                GUI_RadioButton_setState(((LayoutBox *)p->x8)->widget, 0);
                OS_thread_mutex_lock(M2C_FIELD(gESPRIT_LO_GLOBAL_NDA, void **, 0x3C));
                M2C_FIELD(((LayoutBox *)p->x8)->data, int *, 8) = 0;
                OS_thread_mutex_unlock(M2C_FIELD(gESPRIT_LO_GLOBAL_NDA, void **, 0x3C));
            }
        }
    }
    GUI_RadioButton_setState(box->widget, state != 0);
    OS_thread_mutex_lock(M2C_FIELD(gESPRIT_LO_GLOBAL_NDA, void **, 0x3C));
    M2C_FIELD(box->data, int *, 8) = state;
    OS_thread_mutex_unlock(M2C_FIELD(gESPRIT_LO_GLOBAL_NDA, void **, 0x3C));
    return 1;
}

int JSI_getSelectedIndex(void *node) {
    LayoutBox *box;
    unsigned int i;
    int *info;

    if (node == NULL || (box = Node_getBox(node)) == NULL || box->type != 0x12 || box->widget == NULL) {
        return -1;
    }
    info = box->data;
    if (info[1] >= 2 || info[0] == 1) {
        for (i = 0; i < Util_HTMLSelectElement_getLength(node); i++) {
            if (GUI_List_isIndexSelected(box->widget, i)) {
                return i;
            }
        }
        return -1;
    }
    return GUI_Choice_getSelectedItem(box->widget);
}

int JSI_setSelectedIndex(void *node, int idx) {
    LayoutBox *box;
    JSOPT *o;
    unsigned int i;
    if (node == NULL || (box = Node_getBox(node)) == NULL) {
        return 0;
    }
    if (box->type != 18 || box->widget == NULL) {
        return 0;
    }
    OS_thread_mutex_lock(M2C_FIELD(gESPRIT_LO_GLOBAL_NDA, void **, 0x3C));
    i = 0;
    for (o = M2C_FIELD(box->data, JSOPT **, 8); o != NULL; o = o->next) {
        o->selected = i == idx;
        i++;
    }
    OS_thread_mutex_unlock(M2C_FIELD(gESPRIT_LO_GLOBAL_NDA, void **, 0x3C));
    if (M2C_FIELD(box->data, int *, 4) >= 2) {
        for (i = 0; i < Util_HTMLSelectElement_getLength(node); i++) {
            if (i == idx) {
                GUI_List_select(box->widget, idx);
            } else {
                GUI_List_deselect(box->widget, i);
            }
        }
    } else if (GUI_Choice_select(box->widget, idx) < 0) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSI_getTextValue);

int JSI_setTextValue(void *node, DOMStr *s) {
    LayoutBox *box;
    char *buf;

    if (node == NULL || s == NULL || (box = Node_getBox(node)) == NULL || s->str == NULL || box->type != 0xD || box->widget == NULL) {
        return 0;
    }
    buf = MEM_malloc(0, s->len * 3 + 1);
    if (buf == NULL) {
        return 0;
    }
    buf[ucs2ToUtf8(buf, s->str, s->len)] = 0;
    if (*(int *)box->data == 1) {
        GUI_TextArea_setText(box->widget, buf);
    } else {
        GUI_TextField_setText(box->widget, buf);
    }
    GUI_Component_update(box->widget, 0, 0, 0, 0);
    MEM_free(0, buf);
    return 1;
}

int JSI_getWindowRec(void *node, short *rec) {
    LayoutBox *box;
    int w;
    int h;
    int sx;
    int sy;
    int vw;
    int vh;
    void *ui;

    if (node == NULL || (box = Node_getBox(node)) == NULL) {
        return -1;
    }
    rec[0] = 0;
    rec[1] = 0;
    rec[2] = 0;
    ui = gBEINSI_UI;
    if (ui == NULL) {
        return -1;
    }
    GUI_Component_getSize(M2C_FIELD(ui, void **, 0x74), &w, &h);
    rec[3] = w;
    rec[4] = h;
    GUI_ScrollPane_getScrollPosition(box->widget, &sx, &sy);
    rec[5] = sx;
    rec[6] = sy;
    GUI_ScrollPane_getViewportSize(box->widget, &vw, &vh);
    rec[7] = vw;
    rec[8] = vh;
    return 0;
}

DOMStr *JSI_getWindowName(void *doc) {
    void *h;
    char *name;

    if (doc == NULL) {
        return NULL;
    }
    h = HST_searchDocumentHistoryNode(doc);
    if (h == NULL) {
        return NULL;
    }
    name = HST_getTargetName(h);
    if (name == NULL) {
        return NULL;
    }
    return newDOMString_4B5FC(name, strlen(name));
}

int JSI_setWindowName(void *doc, DOMStr *s) {
    void *h;
    char *buf;
    LayoutBox *box;

    if (doc == NULL || s == NULL || s->str == NULL) {
        return 0;
    }
    h = HST_searchDocumentHistoryNode(doc);
    if (h == NULL) {
        return 0;
    }
    buf = MEM_malloc(0, s->len * 3 + 1);
    if (buf == NULL) {
        return 0;
    }
    buf[ucs2ToUtf8(buf, s->str, s->len)] = 0;
    HST_setTargetName(h, buf, strlen(buf));
    box = Node_getBox(doc);
    OS_thread_mutex_lock(M2C_FIELD(gESPRIT_LO_GLOBAL_NDA, void **, 0x3C));
    if (M2C_FIELD(box->data, char **, 0x2C) != NULL) {
        MEM_free(0, M2C_FIELD(box->data, char **, 0x2C));
    }
    M2C_FIELD(box->data, char **, 0x2C) = buf;
    OS_thread_mutex_unlock(M2C_FIELD(gESPRIT_LO_GLOBAL_NDA, void **, 0x3C));
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned int strlen(const char *s);

void JSI_getBrowserHomeURL(void) {
    void *temp_s0;

    temp_s0 = gPREF_UI;
    newDOMString_4B5FC(M2C_FIELD(temp_s0, int *, 0x40), strlen(M2C_FIELD(temp_s0, signed char **, 0x40)));
}

DOMStr *JSI_getAbsoluteURL(void *node, DOMStr *s) {
    void *h;
    char *base;
    char *buf;
    char *abs;
    DOMStr *r;

    if (node == NULL || s == NULL) {
        return NULL;
    }
    if (attached == 0) {
        JSI_init();
    }
    h = HST_searchSessionIDHistoryNode(Node_getSid(node));
    if (h == NULL) {
        return NULL;
    }
    base = HST_getBaseURI(h);
    if (base == NULL) {
        base = HST_getCurURI(h);
    }
    buf = MEM_malloc(0, s->len * 3 + 1);
    if (buf == NULL) {
        return NULL;
    }
    buf[ucs2ToUtf8(buf, s->str, s->len)] = 0;
    abs = URL_toAbsoluteURL(base, buf);
    if (abs == NULL) {
        MEM_free(0, buf);
        return NULL;
    }
    MEM_free(0, buf);
    r = newDOMString_4B5FC(abs, strlen(abs));
    MEM_free(0, abs);
    return r;
}

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

void JSI_setURLPathname(int *obj, DOMStr *s) {
    DOMStr *d;
    unsigned short *p;

    d = duplicateDOMString(s);
    if (d->len != 0 && d->str[0] != '/') {
        p = MEM_malloc(0, d->len * 2 + 2);
        p[0] = '/';
        memcpy(p + 1, d->str, d->len * 2);
        MEM_free(0, d->str);
        d->size++;
        d->len++;
        d->str = p;
    }
    JSI_freeDOMString((DOMStr *)obj[3]);
    obj[3] = (int)d;
}

void JSI_setURLHash(int *obj, DOMStr *s) {
    DOMStr *d;
    unsigned short *p;

    d = duplicateDOMString(s);
    if (d->len != 0 && d->str[0] != '#') {
        p = MEM_malloc(0, d->len * 2 + 2);
        p[0] = '#';
        memcpy(p + 1, d->str, d->len * 2);
        MEM_free(0, d->str);
        d->size++;
        d->len++;
        d->str = p;
    }
    JSI_freeDOMString((DOMStr *)obj[4]);
    obj[4] = (int)d;
}

void JSI_setURLSearch(int *obj, DOMStr *s) {
    DOMStr *d;
    unsigned short *p;

    d = duplicateDOMString(s);
    if (d->len != 0 && d->str[0] != '?') {
        p = MEM_malloc(0, d->len * 2 + 2);
        p[0] = '?';
        memcpy(p + 1, d->str, d->len * 2);
        MEM_free(0, d->str);
        d->size++;
        d->len++;
        d->str = p;
    }
    JSI_freeDOMString((DOMStr *)obj[5]);
    obj[5] = (int)d;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

DOMStr *JSI_newDOMString(const char *utf8, int len) {
    return newDOMString_4B5FC(utf8, len);
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

void *JSWaitMail(int cmd, int sid) {
    void *g;
    JSMSGBUF buf;
    JSMSG *m;
    JSMSG *r;
    int c;
    g = (void *)get_global_ptr();
    OS_thread_mutex_unlock(jsapi_lock);
    m = &buf.m;
    for (;;) {
        OS_mq_receive(M2C_FIELD(g, int *, 0x14), &buf, 0x24, 0);
        if (buf.m.cmd == cmd && buf.m.sid == sid) {
            break;
        }
        c = m->cmd;
        if (c == 0x810) {
            continue;
        }
        if (c == 0x403 || c == 0x409) {
            OS_mq_send(M2C_FIELD(g, int *, 0x18), &buf, 0x24, 0);
            OS_thread_mutex_lock(jsapi_lock);
            return NULL;
        }
        OS_mq_send(M2C_FIELD(g, int *, 0x18), &buf, 0x24, 0);
    }
    OS_thread_mutex_lock(jsapi_lock);
    r = MEM_malloc(0, 0x20);
    if (r != NULL) {
        *r = *m;
    }
    M2C_FIELD(g, int *, 8) = CLIB_time(NULL);
    return r;
}

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

void js_delTimerID(int id, int type, int flag) {
    JSTimer *prev;
    JSTimer *t;
    JSMsgBody *b;
    int *m;
    int *x;

    prev = g_JS_TIMER_;
    for (t = prev->next; t != NULL; t = t->next) {
        if (t->id == id) {
            break;
        }
        prev = t;
    }
    if (t == NULL) {
        return;
    }
    if (t->x00 != type && type != 3) {
        return;
    }
    if (flag == 1) {
        t->status = flag;
        return;
    }
    prev->next = t->next;
    OS_timer_clear(t->id);
    b = &((JSMsg *)t->x0C)->body;
    m = (int *)b->x1C;
    if (b->x10 == 1) {
        x = (int *)m[4];
        MEM_free(0, (void *)x[2]);
        MEM_free(0, x);
    }
    MEM_free(0, (void *)m[2]);
    MEM_free(0, m);
    MEM_free(0, t->x0C);
    MEM_free(0, t);
}

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

int JSCreate(void) {
    char *argv[3];
    int tid;
    char *buf;
    buf = MEM_malloc(0, 0x64);
    strcpy(buf, "REF_JS_MAIN");
    argv[0] = MEM_malloc(0, strlen(buf) + 1);
    strcpy(argv[0], buf);
    strcpy(buf, "0");
    argv[1] = MEM_malloc(0, strlen(buf) + 1);
    strcpy(argv[1], buf);
    argv[2] = NULL;
    OS_thread_create(&tid, 0, esp_jsThread, argv);
    MEM_free(0, argv[0]);
    MEM_free(0, argv[1]);
    MEM_free(0, buf);
    return tid;
}

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


INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", D_00133A54);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", JSHandleEvent);

int ESP_initCore(int size, int x) {
    int r;

    if (esp_context != NULL) {
        return -1;
    }
    r = MEM_init(0, size, x);
    if (r < 0) {
        return r;
    }
    r = FIO_init();
    if (r < 0) {
        goto fail;
    }
    esp_context = MEM_calloc(0, 0x10C);
    esp_context->state = 0;
    M2C_FIELD(esp_context, short *, 0xF2) = 1;
    r = esp_defaultConfig(&esp_context->config);
    if (r != 0) {
        FIO_destroy();
    fail:
        MEM_destroy(0);
        return r;
    }
    esp_loadConfig(&esp_context->config);
    gBEINSI_UI = (char *)esp_context + 4;
    gPREF_UI = &esp_context->config;
    destroyFlag = 0;
    return 0;
}

int ESP_initCookie(int a, int b, int c) {
    return iom_cookieFile_init(c, a, b);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", ESP_startCore);

int ESP_terminateCore(void) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 1) {
        esp_postMsgQuit(esp_context->msg);
        esp_context->state = 2;
    }
    return 0;
}

int ESP_destroyCore(void) {
    int i;
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 1) {
        esp_postMsgQuit(esp_context->msg);
        esp_context->state = 2;
    }
    if (esp_context->state == 2) {
        OS_thread_join(esp_context->xFC, 0);
        OS_thread_join(esp_context->x100, 0);
        for (i = 0; i < 28; i++) {
            GUI_Toolkit_freeFont(M2C_FIELD(esp_context, int *, 4 + i * 4));
        }
        GUI_Toolkit_terminateSystem();
        OS_mq_close(esp_context->xF4);
        OS_mq_unlink(D_00133BB8);
        OS_mq_close((int)esp_context->msg);
        OS_mq_unlink(D_00133BC4);
    }
    gBEINSI_UI = NULL;
    gPREF_UI = NULL;
    esp_freeConfig(&esp_context->config);
    MEM_free(0, esp_context);
    esp_context = NULL;
    OS_timer_destroy();
    FIO_destroy();
    MEM_destroy(0);
    return 0;
}

int ESP_loadPage(unsigned char *url, int a1, int flag, int mode) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (url == NULL) {
        url = (unsigned char *)esp_context->config.homeURL;
    }
    if (*url == 0) {
        return -1;
    }
    flag = (flag != 0) << 1;
    return esp_postMsgLoadPage((int)esp_context->msg, (int)url, a1, 0, flag, mode != 1, 0);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", D_00133BB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jsi", D_00133BC4);

int ESP_submitForm(unsigned char *url, char *data, int len) {
    if (url == NULL || *url == 0 || len < 0 || (len > 0 && data == NULL)) {
        return -1;
    }
    return esp_postMsgSubmitForm(esp_context->msg, url, data, len, 0, 0, "Content-Type: application/x-www-form-urlencoded\r\n\r\n");
}

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

int ESP_abortLoading(void) {
    int r;

    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    return esp_postMsgStop(esp_context->msg);
}

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

int ESP_findString(char *s, int a, int b) {
    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (s == NULL || *s == 0) {
        return -1;
    }
    return esp_postMsgFindString(esp_context->msg, a, b, s);
}

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

int ESP_beginConfig(void) {
    int r;
    EspContext *ctx;

    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (esp_context->prefs != NULL) {
        esp_freeConfig(esp_context->prefs);
        MEM_free(0, esp_context->prefs);
    }
    ctx = esp_context;
    ctx->prefs = MEM_malloc(0, 0x70);
    if (ctx->prefs == NULL) {
        return -1;
    }
    r = esp_copyConfig(esp_context->prefs, &esp_context->config);
    if (r != 0) {
        return r;
    }
    return 0;
}

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

int ESP_setEncoding(int enc) {
    int v;

    if (esp_context == NULL) {
        return -1;
    }
    if (esp_context->state == 2) {
        return -1;
    }
    if (enc == 0) {
        return -1;
    }
    v = 0;
    switch (enc) {
    case 1:
        v = 1;
        break;
    case 3:
        v = 3;
        break;
    case 2:
        v = 2;
        break;
    case 4:
        v = 4;
        break;
    case 5:
        v = 5;
        break;
    case 0:
        v = 0;
        break;
    }
    return esp_setIntConfig(&esp_context->config, 0x1001, v);
}

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
