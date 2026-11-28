/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
void *FIO_fopen(const char *path, const char *mode);
int FIO_fseek(void *fp, int off, int whence);
int FIO_ftell(void *fp);
int FIO_fread(void *buf, int size, int n, void *fp);
int FIO_fwrite(void *buf, int size, int n, void *fp);
int FIO_fclose(void *fp);
void *memset(void *p, int c, unsigned int n);
void *CSS_newPoolBuf(void);
int CSS_putSPoolBuf(void *pb, const char *s);
int CSS_putsPoolBuf(void *pb, void *s);
void *CSS_getMediaTypeString(int t);
void CSS_freePoolBuf(void *pb);
void *newCSSNode(int a, int size);
void CSS_StyleSheetRuleSingle(void *ss, char *text);
void popCSSNode(void *n);
void addCSSNode(void *p, void *n);
void pushCSSNode(void *p, void *n);
void freeCSSStyleSheet(void *ss);
int Node_getSid(void *node);
typedef struct InpMsg {
    int w[8];                         /* inp */
} InpMsg;
void SetIpcMember(InpMsg *msg, int a, int sid, int b, int cmd, int c, int d, void *node);
int JSSendMail(InpMsg *msg, const char *name);
void *mes_class_private_get(void *obj);
void *Node_getOwnerDocument(void *node);
typedef struct MesContext MesContext;
int mes_input_inner(MesContext *ctx, int cmd, int kind);
typedef struct CSSRule {
    short type;
    char pad[0x22];
    void *f24;
} CSSRule;
void freeCSSNode(void *node);
M2C_UNK FIO_remove();                               /* extern */
int CSS_getPoolBuf(unsigned short *);                          /* extern */

void addCSSRule();                               /* extern */


void *MEM_malloc(void *, unsigned int size);
void *newCSSRule(int type, int size, void *a2, void *a3);
typedef struct InpStr { int size; unsigned int len; unsigned short *str; } InpStr;
typedef struct InpPriv { void *dom; int form; } InpPriv;
extern InpStr _DOMname, _DOMtype, _DOMvalue, _DOMchecked, _DOM_textarea;
InpStr Element_getAttribute(void *elem, InpStr *name);
int Element_hasAttribute(void *elem, InpStr *name);
InpStr CharacterData_getData(void *node);
InpStr Util_HTMLSelectElement_getType(void *sel);
void *Node_getFirstChild(void *node);
void *Node_getNextSibling(void *node);
int Node_getNodeType(void *node);
InpStr *JSI_getTextValue(void *node);
void JSI_freeDOMString(InpStr *s);
int JSI_getCheckboxState(void *node);
int JSI_getRadioState(void *node);
int mes_string_new(MesContext *ctx, const void *str, int len);
int mes_string_new2(MesContext *ctx, const char *str, int len);
typedef struct InpStrF { unsigned short *str; int len; } InpStrF;
extern char mes_form_properties[], mes_form_methods[];
void Element_setAttribute(void *elem, InpStr *name, InpStr *value);
void Element_removeAttribute(void *elem, InpStr *name);
void CharacterData_setData(void *node, InpStr *s);
void JSI_setButtonValue(void *node, InpStr *s);
void JSI_setTextValue(void *node, InpStr *s);
void JSI_setCheckboxState(void *node, int state);
void JSI_setRadioState(void *node, int state);
void *memcpy(void *d, const void *s, unsigned int n);
InpStrF *mes_obj_common_to_string(MesContext *ctx, int v);
int isAllowedAsPropertyName(InpStrF *s, void *t, void *x);
int setNewPropertyReference(MesContext *ctx, int a, int c, int s, void *b, int y);
int deleteOldPropertyReference(MesContext *ctx, int a, int c, int s, int old, void *b);
int mes_class_property_get(MesContext *ctx, int obj, const char *name);
int mes_input_inner(MesContext *ctx, int cmd, int kind)
{
    InpMsg msg;
    void **priv = mes_class_private_get(M2C_FIELD(M2C_FIELD(ctx, void **, 0x10), void **, 0x1C));

    SetIpcMember(&msg, 8, Node_getSid(Node_getOwnerDocument(*priv)), 0, cmd, kind, 0, *priv);
    JSSendMail(&msg, "/tmp/mq_lo");
    return 0;
}

int mes_input_blur(MesContext *ctx)
{
    return mes_input_inner(ctx, 0x808, 1);
}

int mes_input_click(MesContext *ctx)
{
    return mes_input_inner(ctx, 0x80B, 2);
}

int mes_input_focus(MesContext *ctx)
{
    return mes_input_inner(ctx, 0x808, 0);
}

int mes_input_select(MesContext *ctx)
{
    return mes_input_inner(ctx, 0x80A, 0);
}

int mes_input_get(MesContext *ctx, void *obj, InpPriv *elem, int id, int type)
{
    InpStr s;
    InpStr *v;
    void *n;
    int r;

    switch (id) {
    case 1:
        return elem->form;
    case 2:
        s = Element_getAttribute(elem->dom, &_DOMname);
        goto str;
    case 3:
        switch (type) {
        case 19:
            s = Util_HTMLSelectElement_getType(elem->dom);
            break;
        case 22:
            s = _DOM_textarea;
            break;
        default:
            s = Element_getAttribute(elem->dom, &_DOMtype);
            break;
        }
        goto str;
    case 4:
        switch (type) {
        case 14:
        case 16:
        case 21:
        case 22:
            v = JSI_getTextValue(elem->dom);
            r = 4;
            if (v != NULL) {
                r = mes_string_new(ctx, v->str, v->len);
                JSI_freeDOMString(v);
            }
            return r;
        case 17:
            s = Element_getAttribute(elem->dom, &_DOMvalue);
            if (s.len == 0)
                r = mes_string_new2(ctx, "on", 2);
            else
                r = mes_string_new(ctx, s.str, s.len);
            return r;
        default:
            s = Element_getAttribute(elem->dom, &_DOMvalue);
            goto str;
        }
    case 5:
        if (type == 22) {
            n = Node_getFirstChild(elem->dom);
            while (n != NULL && Node_getNodeType(n) != 3)
                n = Node_getNextSibling(n);
            if (n == NULL) {
                s.size = 0;
                s.len = 0;
                s.str = NULL;
            } else
                s = CharacterData_getData(n);
        } else
            s = Element_getAttribute(elem->dom, &_DOMvalue);
    str:
        return mes_string_new(ctx, s.str, s.len);
    case 6:
        if (type == 13)
            return JSI_getCheckboxState(elem->dom) == 1 ? 12 : 8;
        return JSI_getRadioState(elem->dom) == 1 ? 12 : 8;
    case 7:
        return Element_hasAttribute(elem->dom, &_DOMchecked) ? 12 : 8;
    default:
        return 4;
    }
}

int mes_input_put(MesContext *ctx, void *obj, InpPriv *priv, int id, int type, int v)
{
    InpStrF *s;
    InpStr ds;
    int old;
    int forms;
    void *n;

    switch (id) {
    case 2:
        if ((v & 3) != 3)
            break;
        s = (InpStrF *)(v & ~3);
        ds.str = MEM_malloc(0, s->len * 2);
        if (ds.str != NULL) {
            old = mes_class_property_get(ctx, (int)obj, "name");
            *--((int **)ctx)[6] = old;
            forms = mes_class_property_get(ctx, priv->form, "elements");
            deleteOldPropertyReference(ctx, priv->form, forms, v, old, obj);
            ds.len = ds.size = s->len;
            memcpy(ds.str, s->str, s->len * 2);
            Element_setAttribute(priv->dom, &_DOMname, &ds);
            MEM_free(0, ds.str);
            ((int **)ctx)[6]++;
            if (isAllowedAsPropertyName(s, mes_form_properties, mes_form_methods) == 1)
                setNewPropertyReference(ctx, priv->form, forms, v, obj, 1);
        }
        ((int **)ctx)[6]++;
        break;
    case 4:
        s = mes_obj_common_to_string(ctx, v);
        if (s->len != 0) {
            ds.str = MEM_malloc(0, s->len * 2);
            if (ds.str == NULL)
                break;
            memcpy(ds.str, s->str, s->len * 2);
        } else if (s->len == 0)
            ds.str = MEM_malloc(0, 2);
        ds.len = ds.size = s->len;
        ((int **)ctx)[6]++;
        switch (type) {
        case 12:
        case 18:
        case 20:
            JSI_setButtonValue(priv->dom, &ds);
            break;
        case 16:
        case 21:
        case 22:
            JSI_setTextValue(priv->dom, &ds);
            break;
        default:
            Element_setAttribute(priv->dom, &_DOMvalue, &ds);
            break;
        }
        if (ds.str != NULL)
            MEM_free(0, ds.str);
        break;
    case 5:
        s = mes_obj_common_to_string(ctx, v);
        ds.str = MEM_malloc(0, s->len * 2);
        if (ds.str != NULL) {
            ds.len = ds.size = s->len;
            memcpy(ds.str, s->str, s->len * 2);
            if (type == 22) {
                n = Node_getFirstChild(priv->dom);
                while (n != NULL && Node_getNodeType(n) != 3)
                    n = Node_getNextSibling(n);
                if (n != NULL)
                    CharacterData_setData(n, &ds);
            } else
                Element_setAttribute(priv->dom, &_DOMvalue, &ds);
            MEM_free(0, ds.str);
        }
        ((int **)ctx)[6]++;
        break;
    case 6:
        if (v == 12 || v == 8) {
            if (type == 13)
                JSI_setCheckboxState(priv->dom, v == 12);
            else if (type == 17)
                JSI_setRadioState(priv->dom, v == 12);
        }
        break;
    case 7:
        if (v == 12) {
            ds.size = _DOMchecked.size;
            ds.len = _DOMchecked.len;
            ds.str = MEM_malloc(0, _DOMchecked.len * 2);
            if (ds.str == NULL)
                break;
            memcpy(ds.str, _DOMchecked.str, _DOMchecked.len * 2);
            Element_setAttribute(priv->dom, &_DOMchecked, &ds);
            MEM_free(0, ds.str);
        } else if (v == 8)
            Element_removeAttribute(priv->dom, &_DOMchecked);
        break;
    }
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void mes_input_free(void) {
    MEM_free(0);
}

void *readCFData(char *path, int *size)
{
    void *fp;
    int n;
    void *buf;

    *size = 0;
    if (path[0] == 0)
        return NULL;
    fp = FIO_fopen(path, "rb");
    if (fp == NULL)
        return NULL;
    FIO_fseek(fp, 0, 2);
    n = FIO_ftell(fp);
    FIO_fseek(fp, 0, 0);
    buf = MEM_malloc(0, n + 1);
    if (buf == NULL) {
        FIO_fclose(fp);
        return NULL;
    }
    memset(buf, 0, n + 1);
    FIO_fread(buf, n, 1, fp);
    FIO_fclose(fp);
    *size = n;
    return buf;
}

int writeCFData(char *path, void *buf, int size, int off)
{
    void *fp;

    if (path[0] == 0)
        return -0x78;
    if (size == 0)
        return -0x78;
    if (off == 0)
        fp = FIO_fopen(path, "wb");
    else
        fp = FIO_fopen(path, "ab");
    if (fp == NULL)
        return -0x6E;
    FIO_fseek(fp, off, 0);
    if (FIO_fwrite(buf, size, 1, fp) != 1) {
        FIO_fclose(fp);
        FIO_remove(path);
        return -0x8C;
    }
    FIO_fclose(fp);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int removeCFData(signed char *arg0) {
    int var_v1;

    var_v1 = -0x78;
    if (*arg0 != 0) {
        FIO_remove();
        var_v1 = 0;
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void newCSSCharsetRule(void *arg0, void *arg1) {
    newCSSRule(2, 0x28, arg0, arg1);
}

void freeCSSCharsetRule(CSSRule *r)
{
    if (r != NULL && r->type == 2) {
        if (r->f24 != NULL)
            MEM_free(0, r->f24);
        freeCSSNode(r);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void addCSSCharsetRule(void) {
    addCSSRule();
}

int CSSCharsetRule_getType(CSSRule *r)
{
    if (r != NULL && r->type == 2)
        return 2;
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int CSSCharsetRule_getCssText(void *arg0) {
    int temp_s0;
    int var_v0;
    unsigned short *temp_v0;

    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 2)) {
        return 0;
    }
    temp_v0 = CSS_newPoolBuf();
    var_v0 = 0;
    if (temp_v0 != NULL) {
        CSS_putSPoolBuf(temp_v0, "@charset \"");
        CSS_putsPoolBuf(temp_v0, M2C_FIELD(arg0, unsigned short **, 0x24));
        CSS_putSPoolBuf(temp_v0, "\";");
        CSS_putSPoolBuf(temp_v0, "\n");
        temp_s0 = CSS_getPoolBuf(temp_v0);
        CSS_freePoolBuf(temp_v0);
        var_v0 = temp_s0;
    }
    return var_v0;
}

int CSSCharsetRule_setCssText(void *r, char *text)
{
    int ret = -1;
    void *ss;
    CSSRule *n;
    CSSRule *old;

    if (r != NULL && M2C_FIELD(r, void **, 0x1C) != NULL && M2C_FIELD(M2C_FIELD(r, void **, 0x1C), short *, 0x36) == 0
        && (ss = newCSSNode(0, 0x3C)) != NULL) {
    CSS_StyleSheetRuleSingle(ss, text);
    n = M2C_FIELD(ss, CSSRule **, 0xC);
    if (n != NULL && n->type == 2 && n->f24 != NULL) {
        old = M2C_FIELD(M2C_FIELD(r, void **, 0x1C), CSSRule **, 0xC);
        ret = 0;
        if (old != NULL && old->type == 2)
            freeCSSCharsetRule(old);
        popCSSNode(n);
        pushCSSNode(M2C_FIELD(r, void **, 0x1C), n);
    }
    freeCSSStyleSheet(ss);
    }
    return ret;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSCharsetRule_getParentStyleSheet(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 2)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x1C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSCharsetRule_getParentRule(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 2)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x20);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSCharsetRule_getEncoding(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 2)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x24);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSCharsetRule_setEncoding(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 2)) {
        M2C_FIELD(arg0, int *, 0x24) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSCharsetRule_setParentStyleSheet(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 2)) {
        M2C_FIELD(arg0, int *, 0x1C) = arg1;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void CSSCharsetRule_setParentRule(void *arg0, int arg1) {
    if ((arg0 != NULL) && (M2C_FIELD(arg0, short *, 0) == 2)) {
        M2C_FIELD(arg0, int *, 0x20) = arg1;
    }
}
