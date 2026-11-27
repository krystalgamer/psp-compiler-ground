/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern MesClassDef mes_history_def;
extern MesClass *mes_history_class;
MesValue mes_history_go_inner(MesContext *ctx, int n);
int HST_getHistoryLength(void);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", mes_history_go_inner);

MesValue mes_history_back(MesContext *ctx)
{
    return mes_history_go_inner(ctx, -1);
}

MesValue mes_history_forward(MesContext *ctx)
{
    return mes_history_go_inner(ctx, 1);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", mes_history_go);

MesValue mes_history_get(MesContext *ctx, MesObject *obj, void *elem, int id)
{
    MesValue ret = MES_UNDEFINED;

    if (id == 2)
        ret = HST_getHistoryLength() * 4 | 1;
    return ret;
}

void mes_history_mark(void) {
}

void mes_history_free(void) {
}

void mes_history_class_init(MesContext *ctx)
{
    mes_history_class = mes_class_init(ctx, &mes_history_def);
}

MesObject *mes_history_new(MesContext *ctx)
{
    return mes_class_new(ctx, mes_history_class);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F89C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F8A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F8AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F8B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F8C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F8C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F8D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_history", D_0013F8D4);
