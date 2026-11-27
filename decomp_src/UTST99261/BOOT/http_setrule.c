/* cflags: -O1 */
#include "common.h"
#include "http_lib.h"
#include "m2c_macros.h"


int http_setrule(int h, int rule)
{
    HttpObj *o = (HttpObj *)(h * 2);

    if (h == 0)
        return -100;
    o->rule = rule;
    return 0;
}
