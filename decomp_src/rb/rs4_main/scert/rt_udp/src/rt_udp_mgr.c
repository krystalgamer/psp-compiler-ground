#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_udp_destroy(char *);
int rt_udp_mgr_create(char *, int *);
int rt_udp_mgr_destroy(void);
int rt_udp_mgr_release_channel_ref(unsigned short);

typedef struct { unsigned short port; short pad; int a, b, c; } RtUdpMgrCh;
typedef struct { int udp; RtUdpMgrCh ch[16]; unsigned int count; } RtUdpMgr;
extern RtUdpMgr gMgr;

int rt_udp_create();
int rt_udp_mgr_create(char *cfg, int *out)
{
    int r;
    if (cfg == NULL) return 2;
    memset(&gMgr, 0, 0x108);
    *(int *)(cfg + 0x24) = 1;
    r = rt_udp_create(&gMgr, cfg);
    if (r != 0) return r;
    *out = gMgr.udp;
    return 0;
}

void *memset(void *s, int c, unsigned int n);
int rt_udp_mgr_destroy(void) {
    rt_udp_destroy(gMgr.udp);
    memset(&gMgr, 0, 0x108U);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp_mgr", rt_udp_mgr_get_channel_ref);

int rt_udp_mgr_release_channel_ref(unsigned short port)
{
    unsigned int i;

    if (port == 0) return 2;
    for (i = 0; i < 16; i++) {
        if (gMgr.ch[i].port == port) {
            memset(&gMgr.ch[i], 0, sizeof(RtUdpMgrCh));
            gMgr.count--;
            return 0;
        }
    }
    return 2;
}

int rt_udp_mgr_find_channel_ref(unsigned short port, RtUdpMgrCh **out)
{
    unsigned int k = 16;
    unsigned int i;

    if (out == NULL) return 2;
    *out = NULL;
    for (i = 0; i < 16; i++) {
        if (port != 0 && gMgr.ch[i].port == port) {
            *out = &gMgr.ch[i];
            return 0;
        }
        if (gMgr.ch[i].port != 0 && k == 16) k = i;
    }
    if (*out == NULL && k != 16) *out = &gMgr.ch[k];
    return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp_mgr", rcsid_10CC14);
