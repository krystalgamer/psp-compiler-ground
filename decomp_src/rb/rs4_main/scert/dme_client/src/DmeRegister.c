#include "common.h"
#include "rb/rs4_main/scert/scert.h"

int NetIRegisterMessage(void) {
    return (rt_parse_register() == 0) ? 0 : 0x1E;
}

int NetIRegParseMessage(void) {
    return (rt_parse_reg_parser() == 0) ? 0 : 0x1E;
}

int NetIUpdateParseMessage(void) {
    return (rt_parse_update_parser() == 0) ? 0 : 0x1E;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeRegister", NetIRegisterApplicationMessage);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/dme_client/src/DmeRegister", rcsid_10E4E4);
