/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern MesClassDef mes_form_def;
extern MesClass *mes_form_class;
extern char D_0013F788[];
typedef struct MesFormPriv {
    void *form;
} MesFormPriv;

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", mes_form_handle_event);

int mes_form_reset(MesContext *ctx)
{
    IpcMsg msg;
    void *form = ((MesFormPriv *)mes_class_private_get(ctx->frame->thisobj))->form;

    SetIpcMember(&msg, 8, Node_getSid(Node_getOwnerDocument(form)), 0, 0x80B, 1, 0, form);
    JSSendMail(&msg, D_0013F788);
    return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F788);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", mes_form_submit);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", mes_form_get);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F7C4);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", mes_form_put);

void mes_form_mark(void) {
}

void mes_form_free(MesContext *ctx, void *priv)
{
    if (priv != NULL)
        MEM_free(0, priv);
}

void mes_form_class_init(MesContext *ctx)
{
    mes_form_class = mes_class_init(ctx, &mes_form_def);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", mes_form_new);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F7F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F7FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F808);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F814);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F81C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F824);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F82C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F838);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F840);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F848);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F850);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F858);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F860);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F868);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F870);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F878);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F880);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_form", D_0013F888);
