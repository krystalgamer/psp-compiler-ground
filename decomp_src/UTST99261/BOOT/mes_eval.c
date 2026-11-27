/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct EvObj {
    struct { int f0; int kind; } *gc;
    int f4, f8, fC, f10;
    int f14;
} EvObj;
typedef struct EvScope {
    char pad[0x20];
    EvObj *obj;
} EvScope;
typedef struct EvFrame {
    char pad[0x1C];
    int thisobj;
} EvFrame;
typedef struct EvCtx {
    char pad[0x10];
    EvFrame *frame;
} EvCtx;
extern unsigned int D_005852E4;
int mes_eval_object_set(int a, int b, int c, int d, int flags);
int mes_eval_string(EvCtx *ctx, int s, int thisobj, int x);
int mes_eval_to_number(EvCtx *ctx, int v);
int mes_error_type();                               /* extern */
int mes_util_hex(unsigned short);                              /* extern */
M2C_UNK mes_gc_mark(int);                           /* extern */
M2C_UNK mes_util_vals_mark(int);                    /* extern */
M2C_UNK mes_gc_register(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern unsigned char mes_eval_method;
M2C_UNK mes_native_setup(void *, int, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK mes_object_set(int, int, M2C_UNK, M2C_UNK); /* extern */
extern int D_00585320;
extern unsigned char mes_eval_native_table;

M2C_UNK mes_util_vals_free(int);                    /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_scope_new);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_scope_bind);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_scope_get);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_scope_put);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_scope_canput);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_type);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_to_primitive);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_to_boolean);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_to_number);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_to_integer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_to_int32);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_to_uint32);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_to_string);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_to_object);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_to_index);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_get_var);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_get_base);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_set_var);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_def_var);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_delete_var);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_object_get);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_object_canput);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_object_delete);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_object_set);

int mes_eval_object_put(int a, int b, int c, int d)
{
    return mes_eval_object_set(a, b, c, d, 8);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_object_put2);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B3E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B3E4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B3E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B3EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B3F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B3F4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_abs_equal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_strict_equal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_native);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_byte);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_string);

#ifndef NULL
#define NULL ((void *)0)
#endif

int mes_eval_type_error(void *arg0, int arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x18);
    M2C_FIELD(arg0, void **, 0x18) = (void *) (temp_v1 - 4);
    M2C_FIELD(temp_v1, int *, -4) = arg1;
    M2C_FIELD(arg0, int *, 0x14) = mes_error_type();
    M2C_FIELD(arg0, void **, 0x18) = (void *) (M2C_FIELD(arg0, void **, 0x18) + 4);
    return 0;
}

int mes_eval_eval(EvCtx *ctx, int s)
{
    return mes_eval_string(ctx, s, ctx->frame->thisobj, 0);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_parse_int);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_parse_float);

int mes_eval_is_nan(EvCtx *ctx, int v)
{
    return mes_eval_to_number(ctx, v) == 0x1C ? 12 : 8;
}

int mes_eval_is_finite(EvCtx *ctx, int v)
{
    int n = mes_eval_to_number(ctx, v);

    if (n == 0x10 || (n & 3) == 1 || (n & 3) == 2)
        return 12;
    return 8;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mes_eval_hex(void *arg0) {
    int temp_s1;
    int temp_v0;
    int var_a0;

    temp_s1 = mes_util_hex(M2C_FIELD(arg0, unsigned short *, 0));
    temp_v0 = mes_util_hex(M2C_FIELD(arg0, unsigned short *, 2));
    var_a0 = -1;
    if ((temp_v0 | temp_s1) >= 0) {
        var_a0 = (temp_s1 * 0x10) + temp_v0;
    }
    return var_a0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_decode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_decode_uri);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_decode_uri_component);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_url_hex);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_encode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_encode_uri);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_encode_uri_component);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_escape);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", mes_eval_unescape);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_eval_mark(void *arg0) {
    mes_object_mark(arg0);
    mes_gc_mark(M2C_FIELD(arg0, int *, 0x18));
    mes_gc_mark(M2C_FIELD(arg0, int *, 0x1C));
    mes_gc_mark(M2C_FIELD(arg0, int *, 0x20));
    mes_util_vals_mark(M2C_FIELD(arg0, int *, 0x24));
    mes_util_vals_mark(M2C_FIELD(arg0, int *, 0x28));
    mes_util_vals_mark(M2C_FIELD(arg0, int *, 0x2C));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_eval_free(void *arg0) {
    mes_util_vals_free(M2C_FIELD(arg0, int *, 0x24));
    mes_util_vals_free(M2C_FIELD(arg0, int *, 0x28));
    mes_util_vals_free(M2C_FIELD(arg0, int *, 0x2C));
    mes_object_free(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_eval_initialize(void) {
    mes_gc_register(&mes_eval_method, 0x30, 0x64, 0x64);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_eval_global_setup(void *arg0) {
    mes_object_set(M2C_FIELD(arg0, int *, 0xC), D_00585320, 0, 6);
    mes_native_setup(arg0, M2C_FIELD(arg0, int *, 0xC), &mes_eval_native_table, 0xB);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B6CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B6D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B6DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B6E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B6F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B6FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B708);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B710);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B71C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B728);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B73C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_eval", D_0013B748);
