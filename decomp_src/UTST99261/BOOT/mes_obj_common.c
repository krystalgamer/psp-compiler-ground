/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
typedef struct MesString {
    DOMChar *str;
    unsigned int len;
} MesString;




#ifndef NULL
#define NULL ((void *)0)
#endif
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", isAllowedAsPropertyName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", setNewPropertyReference);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", deleteOldPropertyReference);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", mes_obj_common_addNewReferenceByNameOrId);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", makeHref);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", D_0013F4C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_common", D_0013F4CC);
