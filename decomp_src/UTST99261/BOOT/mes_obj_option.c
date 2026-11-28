/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
extern MesClassDef mes_option_def;
extern MesClass *mes_option_class;


typedef struct { unsigned short *str; int len; } OptStr;
typedef struct { void *elem; int form; } OptPriv;
extern DOMString _DOMselected;
extern DOMString _DOMvalue;
void Element_setAttribute(void *elem, DOMString *name, DOMString *value);
void Element_removeAttribute(void *elem, DOMString *name);
void JSI_setOptionState(void *elem, int on);
int JSI_setOptionText(void *elem, DOMString *s);
void *memcpy(void *d, const void *s, unsigned int n);
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", mes_option_get);

int mes_option_put(MesContext *ctx, MesObject *o, OptPriv *p, int id, MesValue v)
{
    DOMString ds;
    OptStr *s;

    if (p == NULL)
        return 0;
    switch (id) {
    case 0:
    case 2:
    case 3:
        break;
    case 1:
        if (v == 12) {
            ds.size = _DOMselected.size;
            ds.len = _DOMselected.len;
            ds.str = MEM_malloc(0, ds.len * 2);
            if (ds.str == NULL)
                break;
            memcpy(ds.str, _DOMselected.str, _DOMselected.len * 2);
            Element_setAttribute(p->elem, &_DOMselected, &ds);
            MEM_free(0, ds.str);
        } else if (v == 8) {
            Element_removeAttribute(p->elem, &_DOMselected);
        }
        break;
    case 4:
        if (v == 12 || v == 8)
            JSI_setOptionState(p->elem, v == 12);
        break;
    case 5:
        if ((v & 3) == 3) {
            s = (OptStr *)(v & ~3);
            ds.len = ds.size = s->len;
            ds.str = MEM_malloc(0, s->len * 2);
            if (ds.str == NULL)
                break;
            memcpy(ds.str, s->str, s->len * 2);
            JSI_setOptionText(p->elem, &ds);
            MEM_free(0, ds.str);
        }
        break;
    case 6:
        if ((v & 3) == 3) {
            s = (OptStr *)(v & ~3);
            ds.len = ds.size = s->len;
            ds.str = MEM_malloc(0, s->len * 2);
            if (ds.str == NULL)
                break;
            memcpy(ds.str, s->str, s->len * 2);
            Element_setAttribute(p->elem, &_DOMvalue, &ds);
            MEM_free(0, ds.str);
        }
        break;
    }
    return 1;
}

void mes_option_mark(void) {
}

void mes_option_free(MesContext *ctx, void *p)
{
    MEM_free(0, p);
}

void mes_option_class_init(MesContext *ctx)
{
    mes_option_class = mes_class_init(ctx, &mes_option_def);
}

MesObject *mes_option_new(MesContext *ctx, void *elem)
{
    MesObject *obj = mes_class_new(ctx, mes_option_class);
    mes_class_private_set(obj, elem);
    return obj;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FB44);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FB54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FB5C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FB64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FB70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FB78);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FB80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FB88);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FB98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FBA0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FBA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FBB0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FBB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FBC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FBC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FBD0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FBDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FBE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FBF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC28);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC44);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC4C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC5C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC84);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_option", D_0013FC90);
