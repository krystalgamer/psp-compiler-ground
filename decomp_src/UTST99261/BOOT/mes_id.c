/* cflags: -O1 */
#include "common.h"
extern const char *mes_id_ids[];
int mes_context_id2(void *ctx, const char *name);
int mes_string_new(void *ctx, void *s, int len);
extern int mes_ids[0x46];
extern int mes_classes[0x12];
extern int mes_empty;

void mes_id_initialize(void)
{
    int i;

    for (i = 0; i < 0x46; i++)
        mes_ids[i] = mes_context_id2(0, mes_id_ids[i]);
    mes_empty = mes_string_new(0, 0, 0);
}

void mes_id_free(void)
{
    int i;

    for (i = 0; i < 0x46; i++)
        mes_ids[i] = 0;
    for (i = 0; i < 0x12; i++)
        mes_classes[i] = 0;
    mes_empty = 0;
}
