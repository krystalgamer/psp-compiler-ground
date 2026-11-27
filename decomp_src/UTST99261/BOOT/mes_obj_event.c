/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern MesClassDef mes_event_def;
extern MesClass *mes_event_class;

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", mes_event_get);

void mes_event_mark(void) {
}

void mes_event_free(void) {
}

void mes_event_class_init(MesContext *ctx)
{
    mes_event_class = mes_class_init(ctx, &mes_event_def);
}

MesObject *mes_event_new(MesContext *ctx)
{
    return mes_class_new(ctx, mes_event_class);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C78C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C794);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C79C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C7FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C800);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", mes_link_common_set_href);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C814);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", mes_link_common_get_sub);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", mes_link_common_put_sub);
