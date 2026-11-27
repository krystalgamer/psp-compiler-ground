/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned int mes_ids[];
extern void *mes_classes[];
extern unsigned int D_005852B8;
extern int mes_empty;
extern unsigned int mes_regexp_dollar[];
extern void *mes_regexp_table;
int mes_regexp_constructor();
void *mes_object_new(void *ctx, int cls, void *proto);
void *mes_native_new(void *ctx, int a, void *fn, int nargs, int flags);
void mes_native_setup(void *ctx, void *o, void *table, int n);
void mes_object_set(void *obj, unsigned int id, int value, int flags);
unsigned int mes_context_id2(void *ctx, const char *name);
M2C_UNK mes_gc_mark(int);                           /* extern */
M2C_UNK mes_util_vals_mark(int);                    /* extern */
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */
M2C_UNK mes_gc_register(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern unsigned char mes_cap_method;
extern unsigned char mes_closure_method;
extern unsigned char mes_regexp_method;
extern unsigned char mes_state_method;

M2C_UNK mes_util_vals_free(int);                    /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_new);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_regexp_mark(void *arg0) {
    mes_object_mark(arg0);
    mes_gc_mark(M2C_FIELD(arg0, int *, 0x14));
    mes_gc_mark(M2C_FIELD(arg0, int *, 0x18));
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_get);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_put);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_canput);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_closure_new);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_closure_mark(void *arg0) {
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0);
    if (!(temp_v1 & 1)) {
        M2C_FIELD(arg0, int *, 0) = (int) (temp_v1 | 1);
        mes_util_vals_mark(M2C_FIELD(arg0, int *, 8));
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_closure_free(void *arg0) {
    mes_util_vals_free(M2C_FIELD(arg0, int *, 8));
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_cap_new);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_cap_mark);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_cap_free(void *arg0) {
    if (M2C_FIELD(arg0, int *, 4) > 0) {
        MEM_free(0, M2C_FIELD(arg0, int *, 8));
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_state_new);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_state_mark(void *arg0) {
    int temp_v1;

    temp_v1 = M2C_FIELD(arg0, int *, 0);
    if (!(temp_v1 & 1)) {
        M2C_FIELD(arg0, int *, 0) = (int) (temp_v1 | 1);
        mes_gc_mark(M2C_FIELD(arg0, int *, 8));
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_regexp_initialize(void) {
    mes_gc_register(&mes_regexp_method, 0x30, 0x10, 0x10);
    mes_gc_register(&mes_closure_method, 0xC, 0x10, 0x10);
    mes_gc_register(&mes_cap_method, 0xC, 0x10, 0x10);
    mes_gc_register(&mes_state_method, 0xC, 0x10, 0x10);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_charset_match);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_decimal_digits);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_atom);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_is_word_char);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_assertion_tester);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_assertion);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_term);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_alternative);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_disjunction);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_eval);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_pattern_exec);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_compile);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_constructor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_execute);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_exec);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_test);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", mes_regexp_to_string);

void mes_regexp_setup(void *ctx)
{
    void *proto;
    void *ctor;
    char buf[3];
    int i;
    unsigned int id;

    proto = mes_object_new(ctx, 9, mes_classes[9]);
    mes_classes[12] = proto;
    ctor = mes_native_new(ctx, mes_ids[12], mes_regexp_constructor, 2, 1);
    mes_object_set(*(void **)((char *)ctx + 0xC), mes_ids[12], (int)ctor, 7);
    mes_object_set(ctor, mes_ids[59], (int)proto, 7);
    buf[0] = '$';
    buf[2] = 0;
    for (i = 1; i < 10; i++) {
        buf[1] = '0' + i;
        id = mes_context_id2(ctx, buf);
        mes_regexp_dollar[i - 1] = id;
        mes_object_set(ctor, id, mes_empty, 0);
    }
    mes_object_set(proto, D_005852B8, (int)ctor, 2);
    mes_native_setup(ctx, proto, &mes_regexp_table, 3);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFE4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013BFF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C000);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C008);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C014);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C020);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C030);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C038);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C040);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C048);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C054);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C064);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C06C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C074);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C080);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C08C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C098);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C0FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C108);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C10C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C120);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C128);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C130);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C13C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C148);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C150);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C158);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C160);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C168);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C174);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C180);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C188);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C190);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C1F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C200);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C208);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C210);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C218);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C224);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C22C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C234);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C23C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C24C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C258);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C260);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C26C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C274);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C280);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_regexp", D_0013C284);
