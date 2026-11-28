/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern void *mes_classes[];
int *mes_util_vals(int n, int a);
int mes_eval(void *ctx, int code, int *args, void *thisobj, int f);
int mes_eval_to_string(void *ctx, int v);
int mes_eval_string(void *ctx, int s, void *thisobj, int f);
void *mes_native_new(void *ctx, int a, void *fn, int nargs, int flags);
int mes_object_get(void *obj, unsigned int id);
typedef struct GcMethod {
    int f0;
    int kind;
} GcMethod;
typedef struct ClsProp {
    const char *name;
    unsigned char index;              /* 0x4 */
    unsigned char flags;              /* 0x5 */
} ClsProp;
typedef struct ClsMethod {
    const char *name;
    void *fn;                         /* 0x4 */
    unsigned char nargs;              /* 0x8 */
} ClsMethod;
typedef struct ClassDef {
    const char *name;
    ClsProp *props;                   /* 0x4 */
    ClsMethod *methods;               /* 0x8 */
    void *ctor;                       /* 0xC */
    void *get;                        /* 0x10 */
    char pad14[8];
    void (*free)(void *obj, void *priv);
} ClassDef;
typedef struct MesUser {
    GcMethod *gc;
    void *props;
    struct MesUser *proto;
    int fC;
    signed char cls;
    ClassDef *def;                    /* 0x14 */
    void *priv;                       /* 0x18 */
} MesUser;
typedef struct UserProp {
    unsigned int id;
    int value;
    unsigned char flags;
    char pad;
    short index;
} UserProp;
typedef struct MesStr {
    void *str;
    int len;
} MesStr;
int mes_object_setup(void *ctx, void *obj, const char *name, int v, int flags, int x);
void mes_object_free(void *obj);
void *mes_gc_alloc(void *ctx, int kind);
void mes_object_init(void *obj, int cls, void *proto);
UserProp *mes_object_search(void *obj, unsigned int id);
unsigned int mes_context_id2(void *ctx, const char *name);
unsigned int mes_context_id3(void *ctx, void *str, int len);
int mes_eval_object_get(void *ctx, void *obj, unsigned int id);
int mes_eval_object_put(void *ctx, void *obj, unsigned int id, int v);
M2C_UNK mes_object_set(void *, int, int, M2C_UNK);  /* extern */
M2C_UNK mes_gc_register(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern unsigned char mes_user_method;



MesUser *mes_class_init(void *ctx, ClassDef *def)
{
    MesUser *o;
    ClsProp *p;
    ClsMethod *m;
    unsigned int id;
    void *n;

    o = mes_gc_alloc(ctx, 12);
    if (o != NULL) {
        mes_object_init(o, 9, (*(void * *)((char *)mes_classes + 0x24)));
        o->def = def;
        o->priv = NULL;
        *--*(int **)((char *)ctx + 0x18) = (int)o;
        for (p = def->props; p->name != NULL; p++)
            mes_object_setup(ctx, o, p->name, 0, p->flags | 0x10, p->index);
        for (m = def->methods; m->name != NULL; m++) {
            id = mes_context_id2(ctx, m->name);
            *--*(int **)((char *)ctx + 0x18) = id;
            n = mes_native_new(ctx, id, m->fn, m->nargs, 0);
            *--*(int **)((char *)ctx + 0x18) = (int)n;
            mes_object_set(o, id, (int)n, 0);
            *(int **)((char *)ctx + 0x18) += 2;
        }
        id = mes_context_id2(ctx, def->name);
        *--*(int **)((char *)ctx + 0x18) = id;
        n = mes_native_new(ctx, id, def->ctor, 0, 1);
        ((void **)n)[3] = o;
        *--*(int **)((char *)ctx + 0x18) = (int)n;
        mes_object_set(*(void **)((char *)ctx + 0xC), id, (int)n, 0);
        *(int **)((char *)ctx + 0x18) += 3;
    }
    return o;
}

MesUser *mes_class_new(void *ctx, MesUser *cls)
{
    MesUser *o = mes_gc_alloc(ctx, 12);

    if (o != NULL) {
        mes_object_init(o, 9, cls);
        o->def = cls->def;
        o->priv = NULL;
    }
    return o;
}

int mes_class_instance_of(MesUser *v, MesUser *cls)
{
    if (((int)v & 3) != 0 || (unsigned int)v <= 0x20)
        return 0;
    for (; v != NULL; v = v->proto) {
        if (v == cls)
            return 1;
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_class_get(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

int mes_class_property_get(void *ctx, void *obj, const char *name)
{
    return mes_eval_object_get(ctx, obj, mes_context_id2(ctx, name));
}

int mes_class_property_get2(void *ctx, void *obj, int strv)
{
    MesStr *s = (MesStr *)(strv & ~3);

    return mes_eval_object_get(ctx, obj, mes_context_id3(ctx, s->str, s->len));
}

int mes_class_property_set(void *ctx, void *obj, const char *name, int v)
{
    return mes_eval_object_put(ctx, obj, mes_context_id2(ctx, name), v);
}

int mes_class_property_set2(void *ctx, void *obj, int strv, int v)
{
    MesStr *s = (MesStr *)(strv & ~3);

    return mes_eval_object_put(ctx, obj, mes_context_id3(ctx, s->str, s->len), v);
}

int mes_class_property_setup(void *ctx, void *obj, const char *name, int v, int flags)
{
    return mes_object_setup(ctx, obj, name, v, flags, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void mes_class_private_set(unsigned int arg0, int arg1) {
    if ((!(arg0 & 3) & (arg0 >= 0x21U)) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0), int *, 4) == 0xC)) {
        M2C_FIELD(arg0, int *, 0x18) = arg1;
    }
}

void *mes_class_private_get(MesUser *v)
{
    if (((int)v & 3) != 0 || (unsigned int)v <= 0x20 || v->gc->kind != 12)
        return NULL;
    return v->priv;
}

int mes_class_call(void *ctx, int code, int argc, int *argv, void *thisobj)
{
    int *vals;
    int i;
    int r;

    vals = mes_util_vals(argc, 0);
    if (vals != NULL)
        for (i = 0; i < argc; i++)
            vals[i + 1] = *argv++;
    r = mes_eval(ctx, code, vals, thisobj, 0);
    if (r != 0x20)
        return r;
    code = mes_eval_to_string(ctx, code);
    *--*(int **)((char *)ctx + 0x18) = code;
    code = mes_eval_string(ctx, code, thisobj, 0);
    **(int **)((char *)ctx + 0x18) = code;
    r = mes_eval(ctx, code, vals, thisobj, 0);
    if (r != 0x20)
        return r;
    return code;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void mes_user_mark(void *arg0) {
    M2C_UNK (*temp_v0)(void *, int);

    mes_object_mark(arg0);
    temp_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), M2C_UNK (**)(void *, int), 0x18);
    if (temp_v0 != NULL) {
        temp_v0(arg0, M2C_FIELD(arg0, int *, 0x18));
    }
}

void mes_user_free(MesUser *obj)
{
    if (obj->def->free != NULL)
        obj->def->free(obj, obj->priv);
    mes_object_free(obj);
}

int mes_user_index(MesUser *obj, int id)
{
    UserProp *pr;

    for (; obj != NULL; obj = obj->proto) {
        pr = mes_object_search(obj, id);
        if (pr != NULL) {
            if (pr->flags & 0x10)
                return pr->index;
            return -1;
        }
    }
    return -1;
}

int mes_user_get(void *ctx, MesUser *o, unsigned int id)
{
    int (*get)(void *, MesUser *, void *, int) = o->def->get;
    int idx;
    int r;

    if (get != NULL && (idx = mes_user_index(o, id)) >= 0) {
        r = get(ctx, o, o->priv, idx);
        if (r != 0x20)
            return r;
    }
    return mes_object_get(o, id);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_user_put(int arg0, void *arg1, int arg2, int arg3) {
    int (*temp_s1)(int, void *, int, int, int);
    int temp_v0;

    temp_s1 = M2C_FIELD(M2C_FIELD(arg1, void **, 0x14), int (**)(int, void *, int, int, int), 0x14);
    if ((temp_s1 == NULL) || (temp_v0 = mes_user_index(arg1, arg2), (temp_v0 < 0)) || (temp_s1(arg0, arg1, M2C_FIELD(arg1, int *, 0x18), temp_v0, arg3) == 0)) {
        mes_object_set(arg1, arg2, arg3, 8);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_class_initialize(void) {
    mes_gc_register(&mes_user_method, 0x1C, 0x64, 0x64);
}
