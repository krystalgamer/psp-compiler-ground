/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
extern int *g_JS_MSG_SID_;
extern int *g_JS_PAGECHANGED_;
void *memcpy(void *d, const void *s, unsigned int n);
int Node_getSid(void *node);
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

int mes_link_common_set_href(MesContext *ctx, void *dom, unsigned short *str, int len)
{
    int *sidp = g_JS_MSG_SID_;
    IpcMsg msg;
    int n = len * 2;
    int size = n + 16;
    int *buf = MEM_malloc(0, size);

    if (buf != NULL) {
        buf[0] = 0;
        buf[1] = 0;
        buf[2] = len;
        memcpy(buf + 3, str, n);
        SetIpcMember(&msg, 8, Node_getSid(dom), 0, 0x805, 0, size, buf);
        msg.w[5] = *sidp;
        if (JSSendMail(&msg, "/tmp/mq_lo") == 0)
            *g_JS_PAGECHANGED_ = 1;
    }
    return 1;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", D_0013C814);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", mes_link_common_get_sub);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_event", mes_link_common_put_sub);
