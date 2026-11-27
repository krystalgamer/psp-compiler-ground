/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
void *localeGetCntx();

unsigned char UtilGetMessageLang(void) {
    return M2C_FIELD(localeGetCntx(), unsigned char *, 2);
}

int UtilGetAssign(void) {
    return M2C_FIELD(localeGetCntx(), int *, 0xC) & 1;
}
