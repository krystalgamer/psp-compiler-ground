/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
typedef struct JSIScreenRec {
    int f0, f4, f8, fC, f10, f14, f18, f1C;
} JSIScreenRec;
extern JSIScreenRec *gJSI_SCREEN_REC;
extern MesClassDef mes_screen_def;
extern MesClass *mes_screen_class;

MesValue mes_screen_get(MesContext *ctx, MesObject *obj, void *elem, int id)
{
    JSIScreenRec *rec = gJSI_SCREEN_REC;
    int v;

    if (rec == NULL)
        return MES_UNDEFINED;
    switch (id) {
    case 1: v = rec->f14; break;
    case 2: v = rec->f8; break;
    case 3: v = rec->fC; break;
    case 4: v = rec->f10; break;
    case 5: v = rec->f18; break;
    case 6: v = rec->f4; break;
    case 7: v = rec->f1C; break;
    case 8: v = rec->f0; break;
    default: return MES_UNDEFINED;
    }
    return MES_INT(v);
}

void mes_screen_mark(void) {
}

void mes_screen_free(void) {
}

void mes_screen_class_init(MesContext *ctx)
{
    mes_screen_class = mes_class_init(ctx, &mes_screen_def);
}

MesObject *mes_screen_new(MesContext *ctx)
{
    return mes_class_new(ctx, mes_screen_class);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_screen", D_0013FCBC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_screen", D_0013FCC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_screen", D_0013FCD4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_screen", D_0013FCE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_screen", D_0013FCEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_screen", D_0013FCF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_screen", D_0013FD00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_screen", D_0013FD0C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_screen", D_0013FD14);
