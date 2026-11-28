#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int NetUseCommAdhoc(void);
void rt_comm_adhoc_destroy(int);
int rt_comm_adhoc_display_state(void);
int rt_comm_adhoc_get_avail_bytes_to_read(void);
int rt_comm_adhoc_get_dns_servers(void *, int, int *);
int rt_comm_adhoc_get_host_by_name(void);
int rt_comm_adhoc_get_remote_ip(void);
int rt_comm_adhoc_is_connected(void);
int rt_comm_adhoc_linkaddress_isequal();
int rt_comm_adhoc_linkaddress_isnull();
int rt_comm_adhoc_linkaddress_toext();
char * rt_comm_adhoc_linkaddress_tostr();
int rt_comm_adhoc_receive(void);
int rt_comm_adhoc_receive_echo(void);
int rt_comm_adhoc_send(void);
int rt_comm_adhoc_send_echo();
void rt_comm_adhoc_shutdown(void);
int rt_comm_adhoc_startup(void);
int rt_comm_adhoc_update(void);
int rt_comm_adhoc_vsend(void);
typedef struct { unsigned int ip; unsigned int port; } RtLinkAddr;
typedef struct { char mac[6]; } RtAdhocAddr;
M2C_UNK *rt_comm_adhoc_resolve_interface(void);

extern void *gCommPlatformInterfacePtr;
extern unsigned char gCommAdhocInterface;
int rt_comm_adhoc_create();

int rt_comm_adhoc_get_broadcast_ip();

int rt_comm_adhoc_get_local_ip();

void rt_comm_adhoc_linkaddress_setnull(RtLinkAddr *);

int rt_comm_adhoc_linkaddress_toint(RtAdhocAddr *, RtAdhocAddr *);

int rt_comm_adhoc_receive_from();

int rt_comm_adhoc_send_to();

int rt_comm_adhoc_vsend_to();
extern int gbInitialized_130B2C;

int NetUseCommAdhoc(void) {
    rt_comm_adhoc_resolve_interface();
    return 0;
}

M2C_UNK *rt_comm_adhoc_resolve_interface(void) {
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0) = &rt_comm_adhoc_startup;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 4) = &rt_comm_adhoc_shutdown;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 8) = &rt_comm_adhoc_create;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0xC) = &rt_comm_adhoc_destroy;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x10) = &rt_comm_adhoc_send;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x14) = &rt_comm_adhoc_send_to;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x18) = &rt_comm_adhoc_vsend;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x1C) = &rt_comm_adhoc_vsend_to;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x20) = &rt_comm_adhoc_send_echo;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x24) = &rt_comm_adhoc_receive;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x28) = &rt_comm_adhoc_receive_from;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x2C) = &rt_comm_adhoc_receive_echo;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x34) = &rt_comm_adhoc_get_local_ip;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x38) = &rt_comm_adhoc_get_broadcast_ip;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x3C) = &rt_comm_adhoc_get_host_by_name;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x30) = &rt_comm_adhoc_get_avail_bytes_to_read;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x40) = &rt_comm_adhoc_get_remote_ip;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x44) = &rt_comm_adhoc_display_state;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x48) = &rt_comm_adhoc_is_connected;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x4C) = &rt_comm_adhoc_update;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x50) = &rt_comm_adhoc_linkaddress_setnull;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x54) = &rt_comm_adhoc_linkaddress_isnull;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x58) = &rt_comm_adhoc_linkaddress_isequal;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x5C) = &rt_comm_adhoc_linkaddress_tostr;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x60) = &rt_comm_adhoc_linkaddress_toext;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x64) = &rt_comm_adhoc_linkaddress_toint;
    M2C_FIELD(&gCommAdhocInterface, M2C_UNK **, 0x68) = &rt_comm_adhoc_get_dns_servers;
    gCommPlatformInterfacePtr = &gCommAdhocInterface;
    return &gCommAdhocInterface;
}

void rt_comm_adhoc_linkaddress_setnull(RtLinkAddr *a)
{
    a->ip = 0;
    a->port = 0;
}

extern RtAdhocAddr gBroadcastAddress;
extern RtAdhocAddr gLocalAddress;
int sceNetEtherNtostr(unsigned char *, char *);
int memcmp(const void *, const void *, unsigned int);
void *memset(void *, int, unsigned int);

int rt_comm_adhoc_linkaddress_isnull(RtLinkAddr a)
{
    unsigned char *p = (unsigned char *)&a;
    unsigned int i;
    for (i = 0; i < 6; i++, p++)
        if (*p != 0) return 0;
    return 1;
}

int rt_comm_adhoc_linkaddress_isequal(RtLinkAddr a, RtLinkAddr b)
{
    return memcmp(&a, &b, 6) == 0;
}

char *rt_comm_adhoc_linkaddress_tostr(char *buf, RtLinkAddr a)
{
    sceNetEtherNtostr((unsigned char *)&a, buf);
    return buf;
}

int rt_comm_adhoc_linkaddress_toext(RtAdhocAddr *out, RtLinkAddr a)
{
    *out = *(RtAdhocAddr *)&a;
    return 0;
}

int rt_comm_adhoc_linkaddress_toint(RtAdhocAddr *out, RtAdhocAddr *a)
{
    *out = *a;
    return 0;
}

int sceNetGetLocalEtherAddr(void *);
int rt_comm_adhoc_startup(void)
{
    if (gbInitialized_130B2C != 0) return 0xC351;
    if (sceNetGetLocalEtherAddr(&gLocalAddress) < 0) return 0xC350;
    memset(&gBroadcastAddress, 0xFF, 6);
    gbInitialized_130B2C = 1;
    return 0;
}

void rt_comm_adhoc_shutdown(void) {
    gbInitialized_130B2C = 0;
}

int sceNetAdhocPdpCreate();
int rt_comm_adhoc_create(int *out, RtLinkAddr addr, int *port, long *cfg, int *state)
{
    struct { void *next; int id; unsigned char mac[6]; unsigned short port; int rcvd; } st;
    void *mac;
    int id, r;

    mac = &addr;
    if (rt_comm_adhoc_linkaddress_isnull(addr)) mac = &gLocalAddress;
    if (gbInitialized_130B2C == 0) return 5;
    *state = 0;
    if (cfg[0] != 1) return 4;
    if (cfg[1] <= 0) return 2;
    id = sceNetAdhocPdpCreate(mac, (unsigned short)*port, 0xFFF3, 0);
    if (id <= 0) return 0xC350;
    if (*port == 0) {
        r = rt_comm_get_stat(id, &st);
        if (r != 0) return r;
        *port = st.port;
    }
    *state = 1;
    *out = id;
    return 0;
}

void rt_comm_adhoc_destroy(int id)
{
    if (gbInitialized_130B2C != 0) {
        if (id > 0)
            sceNetAdhocPdpDelete(id, 0);
    }
}

int sceNetAdhocPdpSend();
int rt_comm_adhoc_send_to(int id, RtLinkAddr addr, unsigned int port, void *data, int len, int *sent)
{
    if (gbInitialized_130B2C == 0) return 5;
    if (id < 0) return 2;
    if (rt_comm_adhoc_linkaddress_isnull(addr)) return 2;
    if (port & 0xFFFF0000) return 2;
    *sent = 0;
    if (sceNetAdhocPdpSend(id, &addr, (unsigned short)port, data, len, 0, 1) < 0) return 0xC350;
    *sent = len;
    return 0;
}

extern char D_00130B30[];
typedef struct { struct { void *buf; int len; } e[8]; int total; int n; } RtAdhocVec;
int rt_comm_adhoc_vsend_to(int id, RtLinkAddr addr, unsigned int port, RtAdhocVec *v, int *sent)
{
    int i;
    char *p = D_00130B30;

    for (i = 0; i < v->n; i++) {
        memcpy(p, v->e[i].buf, v->e[i].len);
        p += v->e[i].len;
    }
    return rt_comm_adhoc_send_to(id, addr, port, D_00130B30, v->total, sent);
}

int sceNetAdhocPdpRecv();
int rt_comm_adhoc_receive_from(int id, void *mac, int *port, void *buf, unsigned int size, int *got)
{
    unsigned short p;
    int len;
    int r;

    if (gbInitialized_130B2C == 0) return 5;
    if (id < 0) return 2;
    *got = 0;
    len = size > 0xFFF3 ? 0xFFF3 : size;
    r = sceNetAdhocPdpRecv(id, mac, &p, buf, &len, 0, 1);
    if (r < 0) {
        if (r != (int)0x80410709) return 0xC350;
        len = 0;
    }
    if (len != 0) *port = p;
    *got = len;
    return 0;
}

int rt_comm_adhoc_get_local_ip(RtAdhocAddr *out)
{
    if (gbInitialized_130B2C == 0) return 5;
    *out = gLocalAddress;
    return 0;
}

int rt_comm_adhoc_get_broadcast_ip(RtAdhocAddr *out)
{
    if (gbInitialized_130B2C == 0) return 5;
    *out = gBroadcastAddress;
    return 0;
}

typedef struct AdhocPdpStat { struct AdhocPdpStat *next; int id; int a, b, c; } AdhocPdpStat;
extern AdhocPdpStat D_00131330[];
int sceNetAdhocGetPdpStat();
int rt_comm_get_stat(int id, AdhocPdpStat *out)
{
    int len = 0x50;
    AdhocPdpStat *p;

    if (sceNetAdhocGetPdpStat(&len, D_00131330) == 0 && len != 0) {
        for (p = D_00131330; p != NULL; p = p->next) {
            if (p->id == id) {
                *out = *p;
                return 0;
            }
        }
    }
    return 0xC350;
}

int rt_comm_adhoc_send(void) {
    return 0xC350;
}

int rt_comm_adhoc_vsend(void) {
    return 4;
}

int rt_comm_adhoc_receive(void) {
    return 4;
}

int rt_comm_adhoc_get_avail_bytes_to_read(void) {
    return 4;
}

int rt_comm_adhoc_get_host_by_name(void) {
    return 4;
}

int rt_comm_adhoc_get_remote_ip(void) {
    return 4;
}

int rt_comm_adhoc_send_echo(RtLinkAddr a)
{
    return 4;
}

int rt_comm_adhoc_receive_echo(void) {
    return 4;
}

int rt_comm_adhoc_is_connected(void) {
    return 4;
}

int rt_comm_adhoc_display_state(void) {
    return 0;
}

int rt_comm_adhoc_update(void) {
    return 0;
}

int rt_comm_adhoc_get_dns_servers(void *list, int n, int *count)
{
    if (list == NULL) return 2;
    if (count == NULL) return 2;
    memset(list, 0, n * 8);
    *count = 0;
    return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rcsid_10CEE4);
