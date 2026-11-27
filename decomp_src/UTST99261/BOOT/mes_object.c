/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct MesObj {
    int f0;
    int f4;
    struct MesObj *proto;
    int fC;
    signed char cls;
} MesObj;
typedef struct MesProp {
    int id;
    int value;
    signed char flags;
} MesProp;
typedef struct MesCtxFrame {
    char pad[0x1C];
    MesObj *thisobj;
} MesCtxFrame;
typedef struct MesCtx {
    char pad[0x10];
    MesCtxFrame *frame;
    int f14;
    int *sp;
    char pad2[0x24];
    int stack[1];
} MesCtx;
extern int mes_stack_bottom;
extern int mes_stack_limit;
extern int mes_stack_max;
extern MesObj *D_00585354;
void *mes_gc_alloc(MesCtx *ctx, int kind);
MesProp *mes_object_insert(MesObj *obj, int id);
MesObj *mes_object_new(MesCtx *ctx, int cls, MesObj *proto);
MesProp *mes_object_prop(MesObj *obj, int id);
void *mes_object_search();                          /* extern */
M2C_UNK MEM_malloc(M2C_UNK, M2C_UNK);               /* extern */
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
M2C_UNK mes_object_delete_page(void *);             /* extern */
M2C_UNK mes_gc_mark(int);                           /* extern */
M2C_UNK mes_object_mark_page(int);                  /* extern */
M2C_UNK mes_gc_register(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern unsigned char mes_object_method;
int mes_eval_to_index();                            /* extern */
M2C_UNK mes_array_initialize();                     /* extern */
M2C_UNK mes_byte_initialize();                      /* extern */
M2C_UNK mes_class_initialize();                     /* extern */
M2C_UNK mes_date_initialize();                      /* extern */
M2C_UNK mes_eval_initialize();                      /* extern */
M2C_UNK mes_id_initialize();                        /* extern */
M2C_UNK mes_lex_initialize();                       /* extern */
M2C_UNK mes_native_initialize();                    /* extern */
M2C_UNK mes_number_initialize();                    /* extern */
M2C_UNK mes_regexp_initialize();                    /* extern */
M2C_UNK mes_string_initialize();                    /* extern */
extern int mes_gc_enabled;
M2C_UNK mes_context_free(int);                      /* extern */
M2C_UNK mes_context_hash_free();                    /* extern */
M2C_UNK mes_gc_free();                              /* extern */
M2C_UNK mes_id_free();                              /* extern */
extern int mes_context_head;

M2C_UNK mes_object_free_page(int);                  /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif
void mes_object_init(void *arg0, int arg1, int arg2) {
    M2C_FIELD(arg0, int *, 4) = 0;
    M2C_FIELD(arg0, signed char *, 0x10) = arg1;
    M2C_FIELD(arg0, int *, 8) = arg2;
    M2C_FIELD(arg0, int *, 0xC) = 0;
}

MesObj *mes_object_new(MesCtx *ctx, int cls, MesObj *proto)
{
    MesObj *o = mes_gc_alloc(ctx, 0);

    if (o != NULL)
        mes_object_init(o, cls, proto);
    return o;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_search);

#ifndef NULL
#define NULL ((void *)0)
#endif

int mes_object_get(void) {
    int var_v1;
    void *temp_v0;

    temp_v0 = mes_object_search();
    var_v1 = 0x20;
    if (temp_v0 != NULL) {
        var_v1 = M2C_FIELD(temp_v0, int *, 4);
    }
    return var_v1;
}

MesProp *mes_object_prop(MesObj *obj, int id)
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

void mes_object_page_new(void) {
    MEM_malloc(0, 0x48);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_insert_one);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_insert_page);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_insert);

void mes_object_set(MesObj *obj, int id, int value, int flags)
{
    MesProp *p = mes_object_prop(obj, id);

    p->value = value;
    if (!(flags & 8))
        p->flags = flags;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mes_object_canput(void) {
    int var_v1;
    void *temp_v0;

    temp_v0 = mes_object_search();
    var_v1 = 1;
    if (temp_v0 != NULL) {
        var_v1 = 0;
        if (!(M2C_FIELD(temp_v0, unsigned char *, 8) & 1)) {
            var_v1 = 1;
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_delete_one);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_prop_next);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_setup);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_mark_page);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_free_page);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_object);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_to_string);

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_object_value_of(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), int *, 0x1C);
}

int mes_object_has_own_property(MesCtx *ctx, int v)
{
    MesObj *obj = ctx->frame->thisobj;

    return mes_object_search(obj, mes_eval_to_index(ctx, v)) != NULL ? 12 : 8;
}

int mes_object_is_prototype_of(MesCtx *ctx, MesObj *v)
{
    MesObj *obj = ctx->frame->thisobj;

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

int mes_object_property_is_enumerable(void *arg0) {
    int temp_s0;
    int var_v1;
    void *temp_v0;

    temp_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), int *, 0x1C);
    temp_v0 = mes_object_search(temp_s0, mes_eval_to_index());
    var_v1 = 8;
    if (temp_v0 != NULL) {
        var_v1 = 0xC;
        if (M2C_FIELD(temp_v0, unsigned char *, 8) & 2) {
            var_v1 = 8;
        }
    }
    return var_v1;
}

void mes_object_class_setup(MesCtx *ctx)
{
    D_00585354 = mes_object_new(ctx, 9, 0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_object_object_setup);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_object", mes_setup);

void mes_stack_init(int limit)
{
    mes_stack_bottom = (int)&limit;
    mes_stack_limit = limit;
    mes_stack_max = 0;
}

int mes_stack_check(MesCtx *ctx)
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
