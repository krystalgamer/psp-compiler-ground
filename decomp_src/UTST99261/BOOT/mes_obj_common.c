/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
typedef struct PropName {
    const char *name;                 /* 0x0 pn */
    int f4;                           /* 0x4 pn */
} PropName;
int mes_util_streq2(const DOMChar *a, const char *b, int n);
unsigned int strlen(const char *s);
int setNewPropertyReference(MesContext *ctx, int a, int c, MesValue s, int b, int y);
typedef struct MesString {
    DOMChar *str;
    unsigned int len;
} MesString;




#ifndef NULL
#define NULL ((void *)0)
#endif
MesValue mes_class_property_get2(MesContext *ctx, int obj, MesValue name);
void mes_class_property_set2(MesContext *ctx, int obj, MesValue name, MesValue v);
void mes_array_set(MesContext *ctx, MesValue arr, MesValue v);
void mes_eval_object_delete(MesContext *ctx, int obj, unsigned int id);
unsigned int mes_context_id3(MesContext *ctx, const DOMChar *s, int len);
MesValue mes_eval_object_get(MesContext *ctx, MesValue obj, MesValue id);
typedef struct HrefUrl {
    unsigned short port;
    DOMString *scheme;                /* 0x4 */
    DOMString *host;                  /* 0x8 */
    DOMString *path;                  /* 0xC */
    DOMString *hash;                  /* 0x10 */
    DOMString *search;                /* 0x14 */
} HrefUrl;
double pow(double x, double y);
void *memcpy(void *d, const void *s, unsigned int n);
int mes_obj_common_constructor_not_allowed(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

MesValue mes_obj_common_to_string(MesContext *ctx, MesValue v)
{
    MesValue r = mes_eval_to_string(ctx, v);

    *--ctx->sp = r;
    return r & ~3;
}

void mes_val2domstr(MesContext *ctx, MesValue v, DOMString *out)
{
    MesString *s = (MesString *)(mes_eval_to_string(ctx, v) & ~3);

    out->size = out->len = s->len;
    out->str = s->str;
}

int isAllowedAsPropertyName(MesString *s, PropName *t, int x)
{
    const char *nm;

    if (s->len == 0)
        return 0;
    for (; (nm = t->name) != NULL; t++) {
        if (mes_util_streq2(s->str, nm, s->len) == 1 && strlen(nm) == s->len)
            return 0;
    }
    return 1;
}

int setNewPropertyReference(MesContext *ctx, int a, int c, MesValue s, int b, int y)
{
    MesString *str = (MesString *)(s & ~3);
    MesValue old;
    MesValue arr;
    int r = 0;

    if (str->len != 0) {
        old = mes_class_property_get2(ctx, a, s);
        if (old == 0x20) {
            if (y == 1)
                mes_class_property_set2(ctx, a, s, b);
            mes_class_property_set2(ctx, c, s, b);
            r = 1;
        } else {
            if (y == 1) {
                if (mes_class_instance_of((MesObject *)old, mes_classes[0]) == 0) {
                    arr = mes_array_new(ctx, 0);
                    mes_array_set(ctx, arr, old);
                    mes_array_set(ctx, arr, b);
                    mes_class_property_set2(ctx, a, s, arr);
                } else
                    mes_array_set(ctx, old, b);
                mes_eval_object_delete(ctx, c, mes_context_id3(ctx, str->str, str->len));
            }
            r = 1;
        }
    }
    return r;
}

int deleteOldPropertyReference(MesContext *ctx, int a, int c, MesValue s, MesValue old, int b)
{
    MesString *str = (MesString *)(s & ~3);
    MesString *ostr = (MesString *)(old & ~3);
    MesValue v;
    MesValue e0, e1, e;
    MesValue arr;
    int n, i;
    int r = 0;

    if (str->len != 0) {
        v = mes_class_property_get2(ctx, a, s);
        if (v != 0x20) {
            if (mes_class_instance_of((MesObject *)v, mes_classes[0]) == 0) {
                if (v == b)
                    mes_eval_object_delete(ctx, a, mes_context_id3(ctx, str->str, str->len));
            } else {
                n = M2C_FIELD(v, int *, 0x14);
                if (n == 2) {
                    e0 = mes_eval_object_get(ctx, v, MES_INT(0));
                    e1 = mes_eval_object_get(ctx, v, MES_INT(1));
                    if ((e0 == b) | (e1 == b)) {
                        mes_eval_object_delete(ctx, a, mes_context_id3(ctx, str->str, str->len));
                        mes_class_property_set2(ctx, a, (int)str | 3, e0 == b ? e1 : e0);
                    }
                } else if (n >= 3) {
                    arr = mes_array_new(ctx, 0);
                    for (i = 0; i < n; i++) {
                        e = mes_eval_object_get(ctx, v, MES_INT(i));
                        if (e != b)
                            mes_array_set(ctx, arr, e);
                    }
                    mes_eval_object_delete(ctx, a, mes_context_id3(ctx, str->str, str->len));
                    mes_class_property_set2(ctx, a, (int)str | 3, arr);
                } else
                    return 0;
            }
        }
        mes_eval_object_delete(ctx, c, mes_context_id3(ctx, ostr->str, ostr->len));
        r = 1;
    }
    return r;
}

int mes_obj_common_addNewReferenceByNameOrId(MesContext *ctx, int a, int b, int c, DOMString *pds, PropName *tbl, int x, int y)
{
    DOMString d = *pds;
    int r = 0;
    MesValue s;

    if (d.len != 0) {
        s = mes_string_new(ctx, d.str, d.len);
        *--ctx->sp = s;
        if (isAllowedAsPropertyName((MesString *)(s & ~3), tbl, x) == 1)
            r = setNewPropertyReference(ctx, a, c, s, b, y);
        ctx->sp++;
    }
    return r;
}

DOMString *makeHref(HrefUrl *u)
{
    int digits;
    int n;
    int pos;
    int i;
    int p;
    int colon;
    int q;
    int size;
    DOMChar *buf;
    DOMString *r;

    digits = 0;
    if (u->port != 80) {
        n = u->port;
        digits = 1;
        while (n >= 10) {
            n /= 10;
            digits++;
        }
        digits++;
    }
    colon = 0;
    if (u->scheme->str[u->scheme->len - 1] != ':')
        colon = 1;
    size = (colon + u->scheme->len + u->host->len + digits + u->path->len + u->search->len + u->hash->len) * 2 + 4;
    buf = MEM_malloc(0, size);
    memcpy(buf, u->scheme->str, u->scheme->len * 2);
    pos = u->scheme->len;
    if (u->scheme->str[pos - 1] != ':')
        buf[pos++] = ':';
    buf[pos++] = '/';
    buf[pos++] = '/';
    memcpy(buf + pos, u->host->str, u->host->len * 2);
    pos += u->host->len;
    if (u->port != 80) {
        buf[pos++] = ':';
        n = u->port;
        digits--;
        for (i = 0; i < digits; i++) {
            p = pow(10.0, digits - i - 1);
            buf[pos++] = n / p + '0';
            n = n - n / p * p;
        }
    }
    if (u->path->len != 0) {
        memcpy(buf + pos, u->path->str, u->path->len * 2);
        pos += u->path->len;
    }
    if (u->search->len != 0) {
        memcpy(buf + pos, u->search->str, u->search->len * 2);
        pos += u->search->len;
    }
    if (u->hash->len != 0) {
        memcpy(buf + pos, u->hash->str, u->hash->len * 2);
        pos += u->hash->len;
    }
    r = MEM_malloc(0, 0xC);
    r->size = pos;
    r->len = pos;
    r->str = buf;
    return r;
}


