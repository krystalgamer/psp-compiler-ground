/* lang: c++ */
/* cflags: -Os */
#include "common.h"
extern "C" {

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_cif", SaruNet_Network__Get_Instance_p);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_cif", SaruNet_Network__Update);

} /* extern "C": m2c drafts with mangled names, kept as C linkage */
