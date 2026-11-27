/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int mes_line_peekn(void *l, int n);
int mes_line_skipn(void *l, int n);
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_line", mes_line_new);

#ifndef NULL
#define NULL ((void *)0)
#endif

void mes_line_free(int arg0) {
    MEM_free(0, arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_line_getc(void *arg0) {
    int temp_v0;
    int var_v1;

    var_v1 = 0;
    if (M2C_FIELD(arg0, unsigned char *, 8) == 0) {
        temp_v0 = M2C_FIELD(arg0, int (**)(int), 0)(M2C_FIELD(arg0, int *, 4));
        var_v1 = temp_v0;
        if (temp_v0 >= 0) {
            M2C_FIELD(arg0, int *, 0x34) = (int) (M2C_FIELD(arg0, int *, 0x34) + 1);
        } else {
            M2C_FIELD(arg0, unsigned char *, 8) = 1U;
            var_v1 = 0;
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_line", mes_line_fill);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_line", mes_line_peekn);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_line", mes_line_skipn);

int mes_line_peek(void *l)
{
    return mes_line_peekn(l, 0);
}

int mes_line_skip(void *l)
{
    return mes_line_skipn(l, 1);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_line", mes_line_match);
