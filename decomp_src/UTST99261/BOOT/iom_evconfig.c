/* cflags: -O1 */
#include "common.h"
#include "iom_global.h"
#include "m2c_macros.h"
M2C_UNK iom_capacityCache();                        /* extern */
M2C_UNK iom_destroyCookie();                        /* extern */
M2C_UNK iom_sendMsg(void *, int);                   /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_evConfig(void *arg0) {
    iom_capacityCache();
    iom_freeMsg(arg0);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int iom_evDestroyCookie(void *arg0) {
    void *temp_v0;

    iom_destroyCookie();
    temp_v0 = iom_newMsg(arg0);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0x10) = 0x2B;
        M2C_FIELD(temp_v0, int *, 0x14) = 0;
        iom_sendMsg(temp_v0, iom.mqReply);
    }
    iom_freeMsg(arg0);
    return 0;
}
