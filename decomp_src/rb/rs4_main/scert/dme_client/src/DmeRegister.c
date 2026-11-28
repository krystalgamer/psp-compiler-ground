#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int NetIRegParseMessage(void);
int NetIRegisterMessage();
int NetIUpdateParseMessage(void);
int rt_parse_register();                            /* extern */
int rt_parse_reg_parser();                          /* extern */
int rt_parse_update_parser();                       /* extern */

int NetIRegisterMessage() {
    return (rt_parse_register() == 0) ? 0 : 0x1E;
}

int NetIRegParseMessage(void) {
    return (rt_parse_reg_parser() == 0) ? 0 : 0x1E;
}

int NetIUpdateParseMessage(void) {
    return (rt_parse_update_parser() == 0) ? 0 : 0x1E;
}

int NetIRegisterApplicationMessage(int a, int b)
{
    return NetIRegisterMessage(a, 2, b);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeRegister", rcsid_10E4E4);
