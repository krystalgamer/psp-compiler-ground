/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
typedef struct JSINavigatorRec {
    DOMString *appCodeName;
    DOMString *appName;
    DOMString *appVersion;
    DOMString *language;
    DOMString *platform;
    DOMString *userAgent;
} JSINavigatorRec;
extern JSINavigatorRec *gJSI_NAVIGATOR_REC;
extern MesClassDef mes_navigator_def;
extern MesClass *mes_navigator_class;


#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_navigator_java_enabled(void) {
    return 8;
}

MesValue mes_navigator_get(MesContext *ctx, MesObject *obj, void *elem, int id)
{
    JSINavigatorRec *rec = gJSI_NAVIGATOR_REC;
    DOMString *s;

    if (rec != NULL) {
        switch (id) {
        case 1: s = rec->appCodeName; break;
        case 2: s = rec->appName; break;
        case 3: s = rec->appVersion; break;
        case 4: s = rec->language; break;
        case 5: s = rec->platform; break;
        case 6: s = rec->userAgent; break;
        default: s = NULL; break;
        }
        if (s != NULL)
            return mes_string_new(ctx, s->str, s->len);
    }
    return MES_NULL;
}

void mes_navigator_mark(void) {
}

void mes_navigator_free(void) {
}

void mes_navigator_class_init(MesContext *ctx)
{
    mes_navigator_class = mes_class_init(ctx, &mes_navigator_def);
}

MesObject *mes_navigator_new(MesContext *ctx)
{
    return mes_class_new(ctx, mes_navigator_class);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FAA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FAB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FABC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FAC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FAD4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FAE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FAEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FAF8);
