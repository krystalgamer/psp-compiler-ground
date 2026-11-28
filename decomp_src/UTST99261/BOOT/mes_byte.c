/* cflags: -O1 */
#include "common.h"
#include "mes_js.h"
#include "m2c_macros.h"
extern unsigned int mes_ids[];
typedef struct MesByteObj {
    struct MesObject obj;
    char pad[0x10];
    unsigned short len;               /* 0x24 */
} MesByteObj;
MesValue mes_object_get(MesObject *obj, unsigned int id);
M2C_UNK mes_util_vals_mark(int);                    /* extern */
M2C_UNK mes_util_vals_free(int);                    /* extern */
M2C_UNK mes_gc_register(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern unsigned char mes_byte_method;


MesValue mes_byte_get(MesContext *ctx, MesByteObj *b, unsigned int id)
{
    if (id == mes_ids[51])
        return MES_INT(b->len);
    return mes_object_get(&b->obj, id);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_byte_mark(void *arg0) {
    mes_object_mark(arg0);
    mes_gc_mark(M2C_FIELD(arg0, int *, 0x14));
    mes_util_vals_mark(M2C_FIELD(arg0, int *, 0x20));
    mes_gc_mark(M2C_FIELD(arg0, int *, 0x28));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_byte_free(void *arg0) {
    MEM_free(0, M2C_FIELD(arg0, int *, 0x1C));
    mes_util_vals_free(M2C_FIELD(arg0, int *, 0x20));
    mes_object_free(arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_byte_initialize(void) {
    mes_gc_register(&mes_byte_method, 0x2C, 0x64, 0x64);
}
