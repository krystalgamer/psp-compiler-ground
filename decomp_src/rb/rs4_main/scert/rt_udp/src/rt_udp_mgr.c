#include "common.h"
#include "rb/rs4_main/scert/scert.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp_mgr", rt_udp_mgr_create);

void *memset(void *s, int c, unsigned int n);
int rt_udp_mgr_destroy(void) {
    rt_udp_destroy(gMgr);
    memset(&gMgr, 0, 0x108U);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp_mgr", rt_udp_mgr_get_channel_ref);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp_mgr", rt_udp_mgr_release_channel_ref);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp_mgr", rt_udp_mgr_find_channel_ref);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp_mgr", rcsid_10CC14);
