/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"

int SDomiStringData_Free(SDomiStringData *d) {
    return d->ref != 0 && --d->ref != 0;
}
