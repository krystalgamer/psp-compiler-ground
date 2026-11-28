/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
typedef struct ObjStr {
    unsigned short *chars;            /* 0x0 */
    int slen;                         /* 0x4 */
} ObjStr;
int mes_is_number(MesValue v);
MesValue mes_eval_to_object(MesContext *ctx, MesValue v);
extern MesObject *D_00585334;
extern MesObject *D_00585350;
extern MesObject *D_00585364;
extern unsigned int D_005852E4;
void mes_object_set(MesObject *obj, unsigned int id, int value, int flags);
unsigned short *mes_util_strcp(unsigned short *d, const char *s);
void mes_memory_copy(const void *src, void *dst, int n);
extern unsigned int mes_ids[];
extern void *mes_object_object_table;
MesValue mes_object_object(MesContext *ctx, MesValue v);
unsigned int mes_context_id2(void *ctx, const char *name);
void *mes_native_new(MesContext *ctx, int a, void *fn, int nargs, int flags);
void mes_native_setup(MesContext *ctx, MesObject *o, void *table, int n);
MesContext *mes_context_new(void);
void mes_function_class_setup(MesContext *ctx, MesObject *proto);
void mes_eval_global_setup(MesContext *ctx);
void mes_object_object_setup(MesContext *ctx);
void mes_function_setup(MesContext *ctx);
void mes_array_setup(MesContext *ctx);
void mes_string_setup(MesContext *ctx);
void mes_boolean_setup(MesContext *ctx);
void mes_number_setup(MesContext *ctx);
void mes_math_setup(MesContext *ctx);
void mes_date_setup(MesContext *ctx);
void mes_regexp_setup(MesContext *ctx);
void mes_error_setup(MesContext *ctx);
extern int mes_stack_bottom;
extern int mes_stack_limit;
extern int mes_stack_max;
extern MesObject *D_00585354;
void *mes_gc_alloc(MesContext *ctx, int kind);
void mes_object_init(MesObject *obj, int cls, MesObject *proto);
int mes_eval_to_index(MesContext *ctx, MesValue v);
MesObject *mes_object_new(MesContext *ctx, int cls, MesObject *proto);
MesProp *mes_object_prop(MesObject *obj, unsigned int id);
MesProp *mes_object_search(MesObject *obj, unsigned int id);
void mes_object_insert(MesObject *obj, unsigned int id);
void mes_object_mark_page(MesPage *pg);
void mes_object_free_page(MesPage *pg);
int mes_object_insert_page(MesPage *pg, MesProp *item, MesPage **split);
MesPage *mes_object_page_new(void);

void mes_gc_register(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern unsigned char mes_object_method;
void mes_array_initialize();                     /* extern */
void mes_byte_initialize();                      /* extern */
void mes_class_initialize();                     /* extern */
void mes_date_initialize();                      /* extern */
void mes_eval_initialize();                      /* extern */
void mes_id_initialize();                        /* extern */
void mes_lex_initialize();                       /* extern */
void mes_native_initialize();                    /* extern */
void mes_number_initialize();                    /* extern */
void mes_regexp_initialize();                    /* extern */
void mes_string_initialize();                    /* extern */
extern int mes_gc_enabled;
void mes_context_free(int);                      /* extern */
void mes_context_hash_free();                    /* extern */
void mes_gc_free();                              /* extern */
void mes_id_free();                              /* extern */
extern int mes_context_head;



void mes_object_init(MesObject *obj, int cls, MesObject *proto)
{
    obj->props = NULL;
    obj->cls = cls;
    obj->proto = proto;
    obj->fC = 0;
}

MesObject *mes_object_new(MesContext *ctx, int cls, MesObject *proto)
{
    MesObject *o = mes_gc_alloc(ctx, 0);

    if (o != NULL)
        mes_object_init(o, cls, proto);
    return o;
}

MesProp *mes_object_search(MesObject *obj, unsigned int id)
{
    MesPage *pg;
    unsigned int k;
    int i;

    for (pg = obj->props; pg != NULL; pg = pg->child[i]) {
        for (i = 0; i < pg->n; i++) {
            k = pg->items[i].id;
            if (k == id)
                return &pg->items[i];
            if (id < k)
                break;
        }
    }
    return NULL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

MesValue mes_object_get(MesObject *obj, unsigned int id)
{
    MesProp *p = mes_object_search(obj, id);
    MesValue ret = MES_UNDEFINED;

    if (p != NULL)
        ret = p->value;
    return ret;
}

MesProp *mes_object_prop(MesObject *obj, unsigned int id)
{
    MesProp *p = mes_object_search(obj, id);

    if (p != NULL)
        return p;
    mes_object_insert(obj, id);
    return mes_object_search(obj, id);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

MesPage *mes_object_page_new(void)
{
    return MEM_malloc(0, sizeof(MesPage));
}

void mes_object_insert_one(MesPage *pg, MesProp *item, MesPage *child, int pos)
{
    int i;

    for (i = pg->n; pos < i; i--) {
        pg->items[i] = pg->items[i - 1];
        pg->child[i + 1] = pg->child[i];
    }
    pg->items[pos] = *item;
    pg->child[pos + 1] = child;
    pg->n++;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_insert_page);

void mes_object_insert(MesObject *obj, unsigned int id)
{
    MesProp item;
    MesPage *split;
    MesPage *pg;

    item.id = id;
    item.value = 0;
    item.flags = 0;
    split = NULL;
    if (mes_object_insert_page(obj->props, &item, &split) == 0) {
        pg = mes_object_page_new();
        if (pg != NULL) {
            pg->n = 1;
            pg->items[0] = item;
            pg->child[0] = obj->props;
            pg->child[1] = split;
            obj->props = pg;
        }
    }
}

void mes_object_set(MesObject *obj, unsigned int id, int value, int flags)
{
    MesProp *p = mes_object_prop(obj, id);

    p->value = value;
    if (!(flags & 8))
        p->flags = flags;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mes_object_canput(MesObject *obj, unsigned int id)
{
    MesProp *p = mes_object_search(obj, id);
    int ret = 1;

    if (p != NULL) {
        ret = 0;
        if (!((unsigned char)p->flags & 1))
            ret = 1;
    }
    return ret;
}

int mes_object_delete_one(MesPage *pg, int idx)
{
    int i;

    for (i = idx + 1; i < pg->n; i++) {
        pg->items[i - 1] = pg->items[i];
        pg->child[i] = pg->child[i + 1];
    }
    return --pg->n < 2;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_delete_page);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_object_delete(void *arg0) {
    void *temp_a0;
    void *temp_a1;

    temp_a0 = M2C_FIELD(arg0, void **, 4);
    if (temp_a0 != NULL) {
        mes_object_delete_page(temp_a0);
        temp_a1 = M2C_FIELD(arg0, void **, 4);
        if (M2C_FIELD(temp_a1, int *, 0) == 0) {
            M2C_FIELD(arg0, void **, 4) = (void *) M2C_FIELD(temp_a1, void **, 0x34);
            MEM_free(0, temp_a1);
        }
    }
}

unsigned int mes_object_prop_next(MesObject *obj, unsigned int id)
{
    MesPage *pg;
    MesProp *best;
    int i;

    best = NULL;
    do {
        if (best != NULL)
            id = best->id;
        best = NULL;
        for (pg = obj->props; pg != NULL; pg = pg->child[i]) {
                for (i = 0; i < pg->n; i++) {
                if (id < pg->items[i].id) {
                    if (best == NULL || pg->items[i].id < best->id)
                        best = &pg->items[i];
                    break;
                }
            }
        }
        if (best == NULL)
            return 0;
    } while (best->flags & 2);
    return best->id;
}

void mes_object_setup(MesContext *ctx, MesObject *obj, const char *name, MesValue value, int flags, int fA)
{
    unsigned int id;
    MesProp *p;

    *--ctx->sp = value;
    id = mes_context_id2(ctx, name);
    ctx->sp++;
    p = mes_object_prop(obj, id);
    p->value = value;
    p->flags = flags;
    p->fA = fA;
}

void mes_object_mark_page(MesPage *pg)
{
    int i;

    if (pg != NULL) {
        for (i = 0; i < pg->n; i++) {
            mes_gc_mark(pg->items[i].id);
            mes_gc_mark(pg->items[i].value);
            mes_object_mark_page(pg->child[i]);
        }
        mes_object_mark_page(pg->child[i]);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_object_mark(void *arg0) {
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0);
    if (!(temp_v1 & 1)) {
        M2C_FIELD(arg0, int *, 0) = (int) (temp_v1 | 1);
        mes_gc_mark(M2C_FIELD(arg0, int *, 8));
        mes_gc_mark(M2C_FIELD(arg0, int *, 0xC));
        mes_object_mark_page(M2C_FIELD(arg0, int *, 4));
    }
}

void mes_object_free_page(MesPage *pg)
{
    int i;

    if (pg != NULL) {
        for (i = 0; i < pg->n; i++)
            mes_object_free_page(pg->child[i]);
        mes_object_free_page(pg->child[i]);
        MEM_free(0, pg);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_object_free(void *arg0) {
    mes_object_free_page(M2C_FIELD(arg0, int *, 4));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_object_initialize(void) {
    mes_gc_register(&mes_object_method, 0x14, 0x64, 0x64);
}

MesValue mes_object_object(MesContext *ctx, MesValue v)
{
    MesObject *o;

    if (ctx->frame->construct) {
        o = ctx->frame->thisobj;
        if (v == 0 || v == 4) {
            o->proto = D_00585354;
        } else if (v == 0xC || v == 8) {
            o->cls = 1;
            o->proto = D_00585334;
            o->fC = v;
        } else if (mes_is_number(v)) {
            o->cls = 8;
            o->proto = D_00585350;
            o->fC = v;
        } else if ((v & 3) == 3) {
            o->cls = 13;
            o->proto = D_00585364;
            o->fC = v;
            mes_object_set(o, D_005852E4, MES_INT(((ObjStr *)(v & ~3))->slen), 7);
        } else
            return v;
        return (MesValue)o;
    }
    if (v == 0 || v == 4)
        return (MesValue)mes_object_new(ctx, 9, D_00585354);
    return mes_eval_to_object(ctx, v);
}

MesValue mes_object_to_string(MesContext *ctx)
{
    ObjStr *s;
    ObjStr *name;
    unsigned short *p;

    s = mes_gc_alloc(ctx, 1);
    if (s != NULL) {
        name = (ObjStr *)(mes_ids[(unsigned char)ctx->frame->thisobj->cls] & ~3);
        s->slen = name->slen + 9;
        p = MEM_malloc(0, s->slen * 2);
        s->chars = p;
        if (p != NULL) {
            p = mes_util_strcp(p, "[object ");
            mes_memory_copy(name->chars, p, name->slen * 2);
            p += name->slen;
            mes_util_strcp(p, "]");
            return (MesValue)s | 3;
        }
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_object_value_of(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), int *, 0x1C);
}

int mes_object_has_own_property(MesContext *ctx, int v)
{
    MesObject *obj = ctx->frame->thisobj;

    return mes_object_search(obj, mes_eval_to_index(ctx, v)) != NULL ? 12 : 8;
}

int mes_object_is_prototype_of(MesContext *ctx, MesObject *v)
{
    MesObject *obj = ctx->frame->thisobj;

    if (((int)v & 3) != 0 || (unsigned int)v <= 0x20)
        return 8;
    for (v = v->proto; v != NULL; v = v->proto) {
        if (v == obj)
            return 12;
    }
    return 8;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

MesValue mes_object_property_is_enumerable(MesContext *ctx, MesValue v)
{
    MesObject *obj = ctx->frame->thisobj;
    MesProp *p = mes_object_search(obj, mes_eval_to_index(ctx, v));
    MesValue ret = 8;

    if (p != NULL) {
        ret = 12;
        if ((unsigned char)p->flags & 2)
            ret = 8;
    }
    return ret;
}

MesObject *mes_object_class_setup(MesContext *ctx)
{
    return D_00585354 = mes_object_new(ctx, 9, 0);
}

void mes_object_object_setup(MesContext *ctx)
{
    MesObject *proto = D_00585354;
    MesObject *ctor;

    ctor = mes_native_new(ctx, mes_ids[9], mes_object_object, 1, 1);
    mes_object_set(ctx->global, mes_ids[9], (MesValue)ctor, 7);
    mes_object_set(ctor, mes_ids[59], (MesValue)proto, 7);
    mes_object_set(proto, mes_ids[40], (MesValue)ctor, 2);
    mes_native_setup(ctx, proto, &mes_object_object_table, 6);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_initialize(void) {
    if (mes_gc_enabled == 0) {
        mes_lex_initialize();
        mes_string_initialize();
        mes_byte_initialize();
        mes_object_initialize();
        mes_number_initialize();
        mes_eval_initialize();
        mes_native_initialize();
        mes_array_initialize();
        mes_date_initialize();
        mes_regexp_initialize();
        mes_class_initialize();
    }
    mes_id_initialize();
    mes_gc_enabled = 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_free(void) {
    if (mes_context_head != 0) {
        do {
            mes_context_free(mes_context_head);
        } while (mes_context_head != 0);
    }
    mes_id_free();
    mes_context_hash_free();
    mes_gc_free();
}

MesContext *mes_setup(void)
{
    MesContext *ctx;
    MesObject *g;
    MesObject *proto;

    ctx = mes_context_new();
    g = mes_classes[17];

    if (g == NULL) {
        proto = mes_object_class_setup(ctx);
        mes_function_class_setup(ctx, proto);
        g = mes_object_new(ctx, 17, proto);
        ctx->global = g;
        mes_eval_global_setup(ctx);
        mes_object_object_setup(ctx);
        mes_function_setup(ctx);
        mes_array_setup(ctx);
        mes_string_setup(ctx);
        mes_boolean_setup(ctx);
        mes_number_setup(ctx);
        mes_math_setup(ctx);
        mes_date_setup(ctx);
        mes_regexp_setup(ctx);
        mes_error_setup(ctx);
        mes_classes[17] = g;
    }
    ctx->global = mes_object_new(ctx, 17, g);
    return ctx;
}

void mes_stack_init(int limit)
{
    mes_stack_bottom = (int)&limit;
    mes_stack_limit = limit;
    mes_stack_max = 0;
}

int mes_stack_check(MesContext *ctx)
{
    int here;
    int used = mes_stack_bottom - (int)&here;
    int ret;

    if (mes_stack_max < used)
        mes_stack_max = used;
    ret = 0;
    if (ctx->sp < ctx->stack || mes_stack_limit < used)
        ret = 1;
    return ret;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", D_0013B384);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", D_0013B390);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", D_0013B3A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", D_0013B3A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", D_0013B3B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", D_0013B3C8);
