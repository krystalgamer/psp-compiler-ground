/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
typedef struct MesArray {
    struct MesObject obj;
    unsigned int length;              /* 0x14 */
} MesArray;
extern unsigned int D_005852E4;       /* "length" */
extern MesValue D_00585288;
extern MesObject *mes_classes[];
void *mes_gc_alloc(MesContext *ctx, int kind);
void mes_object_init(MesObject *obj, int cls, MesObject *proto);
void mes_object_set(MesObject *obj, unsigned int id, MesValue value, int flags);
MesValue mes_object_get(MesObject *obj, unsigned int id);
int mes_object_canput(MesObject *obj, unsigned int id);
MesValue mes_number_alloc_uint32(MesContext *ctx, unsigned int n);
MesValue mes_array_join(MesContext *ctx, int sep);
void *mes_util_string_new(void);
void mes_util_string_puti(void *s, int n, int w, int base);
MesValue mes_string_new3(MesContext *ctx, void *s);
void mes_util_string_free(void *s);
unsigned int mes_context_index(MesValue v);
M2C_UNK mes_gc_register(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern unsigned char mes_array_method;


MesArray *mes_array_new(MesContext *ctx, unsigned int len)
{
    MesArray *a = mes_gc_alloc(ctx, 6);

    if (a != NULL) {
        mes_object_init(&a->obj, 0, mes_classes[0]);
        a->length = len;
    }
    return a;
}

void mes_array_set(MesContext *ctx, MesArray *a, MesValue v)
{
    if (a != NULL) {
        if (v != MES_UNDEFINED)
            mes_object_set(&a->obj, MES_INT(a->length), v, 0);
        a->length++;
    }
}

MesValue mes_array_get(MesContext *ctx, MesArray *a, unsigned int id)
{
    if (id == D_005852E4)
        return mes_number_alloc_uint32(ctx, a->length);
    return mes_object_get(&a->obj, id);
}

unsigned int mes_array_number_index(MesContext *ctx, int n)
{
    unsigned int v = (n << 2) | 1;
    unsigned int ret;
    void *s;

    if (MES_INT(v) != n) {
        s = mes_util_string_new();
        if (s == NULL) {
            ctx->f14 = D_00585288;
            ret = 0;
        } else {
            mes_util_string_puti(s, n, 0, 10);
            v = mes_string_new3(ctx, s);
            mes_util_string_free(s);
            ret = mes_context_index(v);
        }
    } else {
        ret = v;
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_length);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_put);

int mes_array_canput(MesContext *ctx, MesArray *a, unsigned int id)
{
    int ret = 1;

    if (id != D_005852E4)
        ret = mes_object_canput(&a->obj, id);
    return ret;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_array_initialize(void) {
    mes_gc_register(&mes_array_method, 0x18, 0x20, 0x20);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_constructor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_join);

MesValue mes_array_to_string(MesContext *ctx)
{
    return mes_array_join(ctx, 0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_to_locale_string);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_concat);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_pop);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_push);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_reverse);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_shift);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_slice);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_sort_compare);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_sort);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_splice);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_unshift);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", mes_array_setup);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B890);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B894);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B898);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B89C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B8F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B900);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B908);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B910);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_array", D_0013B91C);
