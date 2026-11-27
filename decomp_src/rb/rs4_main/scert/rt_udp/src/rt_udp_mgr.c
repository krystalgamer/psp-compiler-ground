#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_udp_mgr_destroy(void);
M2C_UNK rt_udp_destroy(int);                        /* extern */
extern int gMgr;

int rt_udp_create();
int rt_udp_mgr_create(char *cfg, int *out)
{
    int r;
    if (cfg == NULL) return 2;
    memset(&gMgr, 0, 0x108);
    *(int *)(cfg + 0x24) = 1;
    r = rt_udp_create(&gMgr, cfg);
    if (r != 0) return r;
    *out = gMgr;
    return 0;
}

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
