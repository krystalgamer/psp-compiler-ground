/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
int http_setrule(int arg0, int arg1) {
    int var_v0;

    var_v0 = -0x64;
    if (arg0 != 0) {
        M2C_FIELD((arg0 * 2), int *, 4) = arg1;
        var_v0 = 0;
    }
    return var_v0;
}
