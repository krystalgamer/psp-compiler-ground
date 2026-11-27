/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern MesClassDef mes_select_def;
extern MesClass *mes_select_class;
int Util_HTMLSelectElement_getLength(void *sel);
int JSI_getSelectedIndex(void *sel);
void JSI_setSelectedIndex(void *sel, int idx);
typedef struct MesSelectPriv {
    void *elem;
} MesSelectPriv;

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", mes_select_handle_event);

MesValue mes_select_get(MesContext *ctx, MesObject *obj, MesSelectPriv *priv, int id)
{
    switch (id) {
    case 8:
        return MES_INT(Util_HTMLSelectElement_getLength(priv->elem));
    case 10:
        return MES_INT(JSI_getSelectedIndex(priv->elem));
    case 1:
    case 2:
    case 3:
        return mes_input_get(ctx, obj, priv, id, 19);
    case 0:
    default:
        return MES_UNDEFINED;
    }
}

int mes_select_put(MesContext *ctx, MesObject *obj, MesSelectPriv *priv, int id, MesValue v)
{
    int ret;

    switch (id) {
    case 8:
    case 9:
        ret = 1;
        break;
    case 10:
        if ((v & 3) == 1)
            JSI_setSelectedIndex(priv->elem, v >> 2);
        ret = 1;
        break;
    default:
        ret = mes_input_put(ctx, obj, priv, id, 19, v);
        break;
    }
    return ret;
}

void mes_select_mark(void) {
}

void mes_select_class_init(MesContext *ctx)
{
    mes_select_class = mes_class_init(ctx, &mes_select_def);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", mes_select_new);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FD48);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FD50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FD58);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FD60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FD68);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FD78);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FD80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FD88);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FD90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FD9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FDA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FDAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FDB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FDBC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FDC4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FDCC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FDD4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FDDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FDE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FDF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE28);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE44);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE4C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE5C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE84);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE8C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FE94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_select", D_0013FEA0);
