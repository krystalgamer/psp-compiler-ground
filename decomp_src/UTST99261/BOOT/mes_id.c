/* cflags: -O1 */
#include "common.h"
extern int mes_ids[0x46];
extern int mes_classes[0x12];
extern int mes_empty;

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_id", mes_id_initialize);

void mes_id_free(void)
{
    int i;

    for (i = 0; i < 0x46; i++)
        mes_ids[i] = 0;
    for (i = 0; i < 0x12; i++)
        mes_classes[i] = 0;
    mes_empty = 0;
}
