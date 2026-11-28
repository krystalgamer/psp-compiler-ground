/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int js_setChildOfDocument(int a, int b, int c, int d, int type);
int js_setChildOfForm(int a, int b, int c, int d, int type);
void *js_setChildOfWindow(void *ctx, int b, int c, int type);
void JSObjSetEventHandler(int a, int b, int c);
typedef unsigned short UCSChar;
int mes_event_new();                                /* extern */
M2C_UNK mes_object_setup(void *, int, M2C_UNK *, int, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK JSPtrListAdd(void *);                       /* extern */
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK OS_thread_mutex_lock(int);                  /* extern */
M2C_UNK OS_thread_mutex_unlock(int);                /* extern */
extern int jsapi_lock;
int SelectSetInternal();
int TextSetInternal();
int TextAreaSetInternal();
int HiddenSetInternal();
int PasswordSetInternal();
int FileUploadSetInternal();
int ButtonSetInternal();
int SubmitSetInternal();
int ResetSetInternal();
int CheckboxSetInternal();
int RadioSetInternal();
int ImageSetInternal();
int EventHandlerSetInternal();
int ASetInternal();
int FormSetInternal();

M2C_UNK js_setChildOfSelect();                      /* extern */


void *WindowSetInternal(int a, int b, void *hist);
int DocumentSetInternal(int a, int b, void *dom, int c);
void *HST_getDomObject(void *hist);
void *mes_history_new(void *ctx, int a);
void *mes_location_new(void *ctx, int a);
void *mes_screen_new(void *ctx, int a);
void mes_class_property_set(void *ctx, int parent, char *name, void *o);
typedef struct { int size; unsigned int len; unsigned short *str; } JDStr;
void Element_getAttribute(JDStr *s, int node, void *name);
extern int _DOMname;
extern int _DOMhref;
int AnchorSetInternal(int a, int b, int c, int d);
int LinkSetInternal(int a, int b, int c, int d);
extern int _DOMclass;
extern int _DOMid;
extern int mes_select_properties;
extern int mes_select_methods;
int mes_option_new(int ctx, int *priv);
int mes_class_property_get(int ctx, int obj, const char *name);
void mes_array_set(int ctx, int arr, int v);
void mes_obj_common_addNewReferenceByNameOrId(int ctx, int parent, int obj, int arr, JDStr *name, void *props, void *methods, int f);
extern int mes_form_properties;
extern int mes_form_methods;
int mes_button_new(int ctx, int *priv);
int mes_checkbox_new(int ctx, int *priv);
int mes_fileupload_new(int ctx, int *priv);
int mes_hidden_new(int ctx, int *priv);
int mes_password_new(int ctx, int *priv);
int mes_radio_new(int ctx, int *priv);
int mes_reset_new(int ctx, int *priv);
int mes_select_new(int ctx, int *priv);
int mes_submit_new(int ctx, int *priv);
int mes_text_new(int ctx, int *priv);
int mes_textarea_new(int ctx, int *priv);
void *JSI_getDocumentURL(void *dom);
void JSI_freeURLRec(void *u);
int mes_document_new(void *ctx, int *priv);
typedef struct JDUrlStr { int f0; int len; UCSChar *str; } JDUrlStr;
typedef struct JDUrl { int f0; int f4; JDUrlStr *s; } JDUrl;
int JSObjGetCharsLength(const UCSChar *s)
{
    int n = 0;

    while (*s != 0) {
        s++;
        n++;
    }
    return n;
}

unsigned int strlen(const char *s);
int mes_util_streq3(const UCSChar *a, const char *b, unsigned int n);
int mes_string_new(void *ctx, const UCSChar *s, int len);
void *js_common_buffer_open(UCSChar *s, int n);
int js_common_execute(void *ctx, void *buf, int f);
void js_common_buffer_close(void *buf);
typedef struct JSEvCtx {
    char pad[0x14];
    int error;
    int *sp;
} JSEvCtx;
typedef struct JSEvStr {
    UCSChar *str;
    int len;
} JSEvStr;
void JSObjSetEventHandler(int ctx_, int b, int c)
{
    char *names[24] = {
        "onabort", "onblur", "onchange", "onclick", "ondblclick", "ondragdrop",
        "onerror", "onfocus", "onkeydown", "onkeypress", "onkeyup", "onload",
        "onmousedown", "onmousemove", "onmouseout", "onmouseover", "onmouseup", "onmove",
        "onreset", "onresize", "onselect", "onsubmit", "onunload", 0
    };
    int i;
    int v;
    int r;
    void *buf;
    int null;

    if (((UCSChar **)c) == NULL)
        return;
    null = 4;
    while (((UCSChar **)c)[0] != NULL) {
        for (i = 0; names[i] != NULL; i++) {
            if (mes_util_streq3(((UCSChar **)c)[0], names[i], strlen(names[i])) != 1)
                continue;
            v = mes_string_new((JSEvCtx *)ctx_, ((UCSChar **)c)[1], JSObjGetCharsLength(((UCSChar **)c)[1]));
            *--((JSEvCtx *)ctx_)->sp = v;
            if ((v & 3) != 3)
                continue;
            buf = js_common_buffer_open(((JSEvStr *)(v & ~3))->str, ((JSEvStr *)(v & ~3))->len * 2);
            r = js_common_execute((JSEvCtx *)ctx_, buf, 0);
            ((JSEvCtx *)ctx_)->error = 0;
            if (r == 0) {
                ((JSEvCtx *)ctx_)->sp++;
                break;
            }
            *--((JSEvCtx *)ctx_)->sp = r;
            mes_object_setup((JSEvCtx *)ctx_, null ? b : null, (M2C_UNK *)names[i], r, 0, 0);
            ((JSEvCtx *)ctx_)->sp += 2;
            js_common_buffer_close(buf);
        }
        c += 8;
    }
}

void *js_setChildOfWindow(void *ctx, int parent, int a, int type)
{
    void *o;
    char *name;
    void *sp;

    switch (type) {
    case 5:
        o = mes_history_new(ctx, a);
        name = "history";
        mes_class_property_setup(ctx, parent, name, o, 7);
        break;
    case 6:
        o = mes_location_new(ctx, a);
        name = "location";
        mes_class_property_set(ctx, parent, name, o);
        break;
    case 7:
        o = mes_screen_new(ctx, a);
        name = "screen";
        mes_class_property_setup(ctx, parent, name, o, 7);
        break;
    default:
        return NULL;
    }
    sp = M2C_FIELD(ctx, void **, 0x18);
    M2C_FIELD(ctx, void **, 0x18) = (void *) ((char *)sp - 4);
    M2C_FIELD(sp, void **, -4) = o;
    mes_object_setup(ctx, M2C_FIELD(ctx, int *, 0xC), name, o, 7, 0);
    M2C_FIELD(ctx, void **, 0x18) = (void *) ((char *)M2C_FIELD(ctx, void **, 0x18) + 4);
    return o;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", js_setChildOfDocument);

int js_setChildOfForm(int ctx, int parent, int elem, int handler, int type)
{
    JDStr name;
    JDStr cls;
    JDStr id;
    int *priv;
    int obj;
    int arr;

    obj = 0;
    priv = MEM_malloc(0, 8);
    if (priv != NULL) {
        priv[0] = elem;
        priv[1] = parent;
        switch (type) {
        case 12:
            obj = mes_button_new(ctx, priv);
            break;
        case 13:
            obj = mes_checkbox_new(ctx, priv);
            break;
        case 14:
            obj = mes_fileupload_new(ctx, priv);
            break;
        case 15:
            obj = mes_hidden_new(ctx, priv);
            break;
        case 16:
            obj = mes_password_new(ctx, priv);
            break;
        case 17:
            obj = mes_radio_new(ctx, priv);
            break;
        case 18:
            obj = mes_reset_new(ctx, priv);
            break;
        case 19:
            obj = mes_select_new(ctx, priv);
            break;
        case 20:
            obj = mes_submit_new(ctx, priv);
            break;
        case 21:
            obj = mes_text_new(ctx, priv);
            break;
        case 22:
            obj = mes_textarea_new(ctx, priv);
            break;
        }
        if (obj != 0) {
            *--M2C_FIELD(ctx, int **, 0x18) = obj;
            arr = mes_class_property_get(ctx, parent, "elements");
            mes_array_set(ctx, arr, obj);
            Element_getAttribute(&name, elem, &_DOMname);
            mes_obj_common_addNewReferenceByNameOrId(ctx, parent, obj, arr, &name, &mes_form_properties, &mes_form_methods, 1);
            Element_getAttribute(&cls, elem, &_DOMclass);
            mes_obj_common_addNewReferenceByNameOrId(ctx, parent, obj, arr, &cls, &mes_form_properties, &mes_form_methods, 1);
            Element_getAttribute(&id, elem, &_DOMid);
            mes_obj_common_addNewReferenceByNameOrId(ctx, parent, obj, arr, &id, &mes_form_properties, &mes_form_methods, 1);
            JSObjSetEventHandler(ctx, obj, handler);
            M2C_FIELD(ctx, int **, 0x18)++;
        } else
            MEM_free(0, priv);
    }
    return obj;
}

int js_setChildOfSelect(ctx, parent, elem)
    int ctx;
    int parent;
    int elem;
{
    JDStr name;
    JDStr cls;
    JDStr id;
    int *priv;
    int opt;
    int arr;

    opt = 0;
    priv = MEM_malloc(0, 8);
    if (priv != NULL) {
        priv[0] = elem;
        priv[1] = parent;
        opt = mes_option_new(ctx, priv);
        if (opt != 0) {
            *--M2C_FIELD(ctx, int **, 0x18) = opt;
            arr = mes_class_property_get(ctx, parent, "options");
            mes_array_set(ctx, arr, opt);
            Element_getAttribute(&name, elem, &_DOMname);
            mes_obj_common_addNewReferenceByNameOrId(ctx, parent, opt, arr, &name, &mes_select_properties, &mes_select_methods, 1);
            Element_getAttribute(&cls, elem, &_DOMclass);
            mes_obj_common_addNewReferenceByNameOrId(ctx, parent, opt, arr, &cls, &mes_select_properties, &mes_select_methods, 1);
            Element_getAttribute(&id, elem, &_DOMid);
            mes_obj_common_addNewReferenceByNameOrId(ctx, parent, opt, arr, &id, &mes_select_properties, &mes_select_methods, 1);
            M2C_FIELD(ctx, int **, 0x18)++;
        } else
            MEM_free(0, priv);
    }
    return opt;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", WindowSetInternal);

int DocumentSetInternal(int a, int b, void *dom, int c)
{
    int *priv;
    int doc;
    int domain;
    JDUrl *u;
    int t;

    priv = MEM_malloc(0, 8);
    priv[0] = (int)dom;
    priv[1] = 4;
    doc = mes_document_new((void *)a, priv);
    *--M2C_FIELD(a, int **, 0x18) = doc;
    mes_object_setup((void *)a, M2C_FIELD(a, int *, 0xC), (M2C_UNK *)"document", doc, 7, 0);
    u = JSI_getDocumentURL(dom);
    domain = mes_string_new((void *)a, u->s->str, u->s->len);
    *--M2C_FIELD(a, int **, 0x18) = domain;
    JSI_freeURLRec(u);
    mes_class_property_setup(a, b, "document", doc, 7);
    mes_class_property_set((void *)a, doc, "domain", (void *)domain);
    t = HistoryObjSetInternal(a, b);
    *--M2C_FIELD(a, int **, 0x18) = t;
    t = LocationSetInternal(a, b, (int)dom);
    *--M2C_FIELD(a, int **, 0x18) = t;
    JSObjSetEventHandler(a, doc, c);
    M2C_FIELD(a, int **, 0x18) += 4;
    return doc;
}

int ASetInternal(int ctx, int b, int node, int d)
{
    JDStr name;
    JDStr href;
    int a;
    int r;

    Element_getAttribute(&name, node, &_DOMname);
    Element_getAttribute(&href, node, &_DOMhref);
    a = 0;
    if (name.str != NULL) {
        a = AnchorSetInternal(ctx, b, node, d);
        *--M2C_FIELD(ctx, int **, 0x18) = a;
    }
    if (href.str != NULL) {
        r = LinkSetInternal(ctx, b, node, d);
        if (a != 0)
            M2C_FIELD(ctx, int **, 0x18)++;
        return r;
    }
    if (a != 0)
        M2C_FIELD(ctx, int **, 0x18)++;
    return 0;
}

void *NavigatorSetInternal(void *arg0, int arg1)
{
    void *nav = mes_navigator_new(arg0);
    void *sp;

    mes_class_property_setup(arg0, arg1, "navigator", nav, 7);
    sp = M2C_FIELD(arg0, void **, 0x18);
    M2C_FIELD(arg0, void **, 0x18) = (void *) ((char *)sp - 4);
    M2C_FIELD(sp, void **, -4) = nav;
    mes_object_setup(arg0, M2C_FIELD(arg0, int *, 0xC), "navigator", nav, 7, 0);
    M2C_FIELD(arg0, void **, 0x18) = (void *) ((char *)M2C_FIELD(arg0, void **, 0x18) + 4);
    return nav;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int EventSetInternal(void *arg0) {
    int temp_s1;
    void *temp_v1;

    temp_s1 = mes_event_new();
    temp_v1 = M2C_FIELD(arg0, void **, 0x18);
    M2C_FIELD(arg0, void **, 0x18) = (void *) (temp_v1 - 4);
    M2C_FIELD(temp_v1, int *, -4) = temp_s1;
    mes_object_setup(arg0, M2C_FIELD(arg0, int *, 0xC), "event", temp_s1, 7, 0);
    M2C_FIELD(arg0, void **, 0x18) = (void *) (M2C_FIELD(arg0, void **, 0x18) + 4);
    return temp_s1;
}

int HistoryObjSetInternal(int a, int b)
{
    return (int)js_setChildOfWindow((void *)a, b, 0, 5);
}

int LocationSetInternal(int a, int b, int c)
{
    return (int)js_setChildOfWindow((void *)a, b, c, 6);
}

int ScreenSetInternal(int a, int b)
{
    return (int)js_setChildOfWindow((void *)a, b, 0, 7);
}

int EventHandlerSetInternal(int a, int b, int c, int d)
{
    JSObjSetEventHandler(a, b, d);
    return 0;
}

int AnchorSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfDocument(a, b, c, d, 8);
}

int FormSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfDocument(a, b, c, d, 9);
}

int ImageSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfDocument(a, b, c, d, 10);
}

int LinkSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfDocument(a, b, c, d, 11);
}

int ButtonSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 12);
}

int CheckboxSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 13);
}

int FileUploadSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 14);
}

int HiddenSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 15);
}

int PasswordSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 16);
}

int RadioSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 17);
}

int ResetSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 18);
}

int SelectSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 19);
}

int SubmitSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 20);
}

int TextSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 21);
}

int TextAreaSetInternal(int a, int b, int c, int d)
{
    return js_setChildOfForm(a, b, c, d, 22);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void OptionSetInternal(void) {
    js_setChildOfSelect();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void *JSObjectSetInternal(int (*arg0)(int, int, int, int), void *arg1, int arg2, int arg3) {
    int temp_v0_2;
    void *temp_v0;

    OS_thread_mutex_lock(jsapi_lock);
    temp_v0 = MEM_malloc(0, 0x10);
    if (temp_v0 != NULL) {
        temp_v0_2 = arg0(M2C_FIELD(arg1, int *, 0), M2C_FIELD(arg1, int *, 4), arg2, arg3);
        M2C_FIELD(temp_v0, int *, 0) = (int) M2C_FIELD(arg1, int *, 0);
        M2C_FIELD(temp_v0, int *, 4) = temp_v0_2;
        JSPtrListAdd(temp_v0);
    }
    OS_thread_mutex_unlock(jsapi_lock);
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void SelectSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&SelectSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void TextSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&TextSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void TextAreaSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&TextAreaSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void HiddenSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&HiddenSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void PasswordSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&PasswordSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void FileUploadSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&FileUploadSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ButtonSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&ButtonSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void SubmitSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&SubmitSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ResetSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&ResetSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void CheckboxSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&CheckboxSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void RadioSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&RadioSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ImageSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&ImageSetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void EventHandlerSet(int arg0, int arg1) {
    JSObjectSetInternal(&EventHandlerSetInternal, arg0, 0, arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ASet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&ASetInternal, arg0, arg1, arg2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void FormSet(int arg0, int arg1, int arg2) {
    JSObjectSetInternal(&FormSetInternal, arg0, arg1, arg2);
}

void *OptionSet(int a, int b, int c)
{
    return JSObjectSetInternal(OptionSetInternal, a, b, c);
}

void *DocumentSet(int *win, void *hist, int c) {
    int *d;
    int *w;
    int a, b;

    OS_thread_mutex_lock(jsapi_lock);
    if (win != NULL)
        w = WindowSetInternal(win[0], win[1], hist);
    else
        w = WindowSetInternal(0, 0, hist);
    d = MEM_malloc(0, 0x10);
    d[0] = w[0];
    d[1] = DocumentSetInternal(w[0], w[1], HST_getDomObject(hist), c);
    JSPtrListAdd(w);
    JSPtrListAdd(d);
    OS_thread_mutex_unlock(jsapi_lock);
    return d;
}

UCSChar *UCS_strcpy(UCSChar *d, const UCSChar *s)
{
    UCSChar *r = d;

    while ((*d++ = *s++) != 0)
        ;
    return r;
}

UCSChar *UCS_strncpy(UCSChar *d, const UCSChar *s, int n)
{
    UCSChar *r = d;

    while (--n != -1 && (*d++ = *s++) != 0)
        ;
    return r;
}

short UCS_strcmp(const UCSChar *a, const UCSChar *b)
{
    short r;

    do {
        r = *a - *b++;
        if (r != 0)
            break;
    } while (*a++ != 0);
    return r;
}

short UCS_strncmp(const UCSChar *a, const UCSChar *b, int n)
{
    short r = 0;

    while (n != 0) {
        r = *a - *b++;
        if (r != 0)
            break;
        if (*a++ == 0)
            break;
        n--;
    }
    return r;
}

int UCS_strcasecmp(const UCSChar *a, const UCSChar *b)
{
    UCSChar c1, c2;

    do {
        c1 = *a++;
        c2 = *b++;
        if (c1 == 0 || c2 == 0)
            break;
        if (c1 == c2)
            continue;
        if (c1 >= 'A' && c1 <= 'Z')
            c1 += 'a' - 'A';
        if (c2 >= 'A' && c2 <= 'Z')
            c2 += 'a' - 'A';
    } while (c1 == c2);
    return c1 - c2;
}

int UCS_strncasecmp(const UCSChar *a, const UCSChar *b, int n)
{
    UCSChar c1, c2;

    c2 = 0;
    c1 = 0;

    while (n != 0) {
        c1 = *a++;
        c2 = *b++;
        if (c1 == 0 || c2 == 0)
            break;
        if (c1 != c2) {
            if (c1 >= 'A' && c1 <= 'Z')
                c1 += 'a' - 'A';
            if (c2 >= 'A' && c2 <= 'Z')
                c2 += 'a' - 'A';
            if (c1 != c2)
                break;
        }
        n--;
    }
    return c1 - c2;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int UCS_strdup(int arg0) {
    int temp_v0;
    int var_v1;

    temp_v0 = MEM_malloc(0, (UCS_strlen() * 2) + 2);
    var_v1 = 0;
    if (temp_v0 != 0) {
        var_v1 = UCS_strcpy(temp_v0, arg0);
    }
    return var_v1;
}

UCSChar *UCS_strndup(const UCSChar *s, int n)
{
    UCSChar *p = MEM_malloc(0, n * 2 + 2);

    if (p == NULL)
        return NULL;
    UCS_strncpy(p, s, n);
    p[n] = 0;
    return p;
}

UCSChar *UCS_strstr(UCSChar *hay, const UCSChar *needle)
{
    int nl = UCS_strlen(needle);
    int hl;

    if (nl == 0)
        return hay;
    hl = UCS_strlen(hay);
    while (hl >= nl) {
        hl--;
        if (UCS_strncmp(hay, needle, nl) == 0)
            return hay;
        hay++;
    }
    return NULL;
}

int UCS_strlen(const UCSChar *s)
{
    const UCSChar *p = s;

    while (*p != 0)
        p++;
    return p - s;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_for_parser", gDomiAttrVt);
