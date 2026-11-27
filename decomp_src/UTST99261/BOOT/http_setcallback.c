/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
int http_setcallback(int arg0, int arg1, int arg2) {
    int temp_v1;
    int var_v0;

    temp_v1 = arg0 * 2;
    var_v0 = -0x64;
    if (arg0 != 0) {
        M2C_FIELD(temp_v1, int *, 0x68) = arg1;
        M2C_FIELD(temp_v1, int *, 0x6C) = arg2;
        var_v0 = 0;
    }
    return var_v0;
}
