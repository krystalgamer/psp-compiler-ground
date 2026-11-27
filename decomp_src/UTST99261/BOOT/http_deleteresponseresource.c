/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int UTL_mfiledelete(int);                           /* extern */
M2C_UNK htlib_setheaderkey(int, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif

int http_deleteresponseresource(int arg0) {
    int temp_a0;
    int temp_s0;

    temp_s0 = arg0 * 2;
    if (temp_s0 != -0x14) {
        htlib_setheaderkey(temp_s0 + 0x14, 0, 0, 0);
    }
    temp_a0 = M2C_FIELD(temp_s0, int *, 8);
    if (temp_a0 != 0) {
        M2C_FIELD(temp_s0, int *, 8) = UTL_mfiledelete(temp_a0);
    }
    return 0;
}
