#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int NetUseCommInet(void);
int NetUseCommSockets(void);
void rt_comm_platform_destroy(int);
int rt_comm_platform_display_state(void);
int rt_comm_platform_get_broadcast_ip(int *);
void rt_comm_platform_get_dns_servers(void);
int rt_comm_platform_get_host_by_name(const char *, int *);
int rt_comm_platform_get_listen_socket(int *);
int rt_comm_platform_get_local_ip(int *);
int rt_comm_platform_get_remote_ip(int, int *);
int rt_comm_platform_is_connected(int, int *);
int rt_comm_platform_linkaddress_isequal();
int rt_comm_platform_linkaddress_isnull();
int rt_comm_platform_linkaddress_toext();
int rt_comm_platform_linkaddress_toint(int *, int);
char * rt_comm_platform_linkaddress_tostr();
int rt_comm_platform_receive_echo(int, int, int, int);
int rt_comm_platform_receive_from(int, int, int *, void *, int, int *);
int rt_comm_platform_send_echo();
int rt_comm_platform_send_to();
int rt_comm_platform_shutdown(void);
int rt_comm_platform_startup(void);
int rt_comm_platform_update(void);
int rt_comm_platform_vsend_to();
void rt_ip_ip2string(char *, unsigned int);
unsigned int rt_ip_string2ip(const char *);
void rt_socket_cleanup_stack(void);
void rt_socket_get_dns_servers(void);
int rt_socket_get_host_by_name(int *, const char *);
typedef struct { unsigned int ip; unsigned int port; } RtLinkAddr;
typedef struct { char mac[6]; } RtAdhocAddr;
M2C_UNK *rt_comm_platform_resolve_interface(void);

extern void *gCommPlatformInterfacePtr;
extern unsigned char gCommPlatformInterface;
int rt_comm_platform_create();

int rt_comm_platform_get_avail_bytes_to_read();

void rt_comm_platform_linkaddress_setnull(RtLinkAddr *);

int rt_comm_platform_receive();

int rt_comm_platform_send();

int rt_comm_platform_vsend();

int NetUseCommInet(void) {
    rt_comm_platform_resolve_interface();
    return 0;
}

int NetUseCommSockets(void) {
    rt_comm_platform_resolve_interface();
    return 0;
}

M2C_UNK *rt_comm_platform_resolve_interface(void) {
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0) = &rt_comm_platform_startup;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 4) = &rt_comm_platform_shutdown;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 8) = &rt_comm_platform_create;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0xC) = &rt_comm_platform_destroy;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x10) = &rt_comm_platform_send;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x14) = &rt_comm_platform_send_to;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x18) = &rt_comm_platform_vsend;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x1C) = &rt_comm_platform_vsend_to;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x20) = &rt_comm_platform_send_echo;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x24) = &rt_comm_platform_receive;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x28) = &rt_comm_platform_receive_from;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x2C) = &rt_comm_platform_receive_echo;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x34) = &rt_comm_platform_get_local_ip;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x38) = &rt_comm_platform_get_broadcast_ip;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x3C) = &rt_comm_platform_get_host_by_name;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x30) = &rt_comm_platform_get_avail_bytes_to_read;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x40) = &rt_comm_platform_get_remote_ip;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x44) = &rt_comm_platform_display_state;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x48) = &rt_comm_platform_is_connected;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x4C) = &rt_comm_platform_update;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x50) = &rt_comm_platform_linkaddress_setnull;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x54) = &rt_comm_platform_linkaddress_isnull;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x58) = &rt_comm_platform_linkaddress_isequal;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x5C) = &rt_comm_platform_linkaddress_tostr;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x60) = &rt_comm_platform_linkaddress_toext;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x64) = &rt_comm_platform_linkaddress_toint;
    M2C_FIELD(&gCommPlatformInterface, M2C_UNK **, 0x68) = &rt_comm_platform_get_dns_servers;
    gCommPlatformInterfacePtr = &gCommPlatformInterface;
    return &gCommPlatformInterface;
}

extern int gbInitialized_1313FC;
typedef struct { int sock; int pad; int ip; } RtListenSocket;
extern RtListenSocket gaListenSocket[];

int rt_socket_get_local_ip();

int rt_socket_recv_icmp_echo_response();
int rt_socket_send_icmp_echo_request();
int rt_socket_initialize_stack();

int rt_socket_sendmsg();
int rt_socket_send_data_udp();

int rt_comm_platform_get_listen_socket(int *s)
{
    int ret = 2;
    unsigned int i = *s + 0x101;

    if ((unsigned int)(*s + 0x100) < 0xFF) {
        *s = gaListenSocket[i].sock;
        ret = 0;
    } else
        *s = -1;
    return ret;
}

void rt_comm_platform_linkaddress_setnull(RtLinkAddr *a)
{
    a->ip = 0;
    a->port = 0;
}

int rt_comm_platform_linkaddress_isnull(RtLinkAddr a)
{
    return a.ip == 0;
}

int rt_comm_platform_linkaddress_isequal(RtLinkAddr a, RtLinkAddr b)
{
    return a.ip == b.ip;
}

char *rt_comm_platform_linkaddress_tostr(char *buf, RtLinkAddr a)
{
    rt_ip_ip2string(buf, a.ip);
    return buf;
}

int rt_comm_platform_linkaddress_toext(char *out, RtLinkAddr a)
{
    rt_ip_ip2string(out, a.ip);
    return 0;
}

int rt_comm_platform_linkaddress_toint(int *arg0, int arg1) {
    *arg0 = rt_ip_string2ip(arg1);
    return 0;
}

int rt_comm_platform_startup(void)
{
    int r;
    unsigned int i;
    if (gbInitialized_1313FC != 0)
        return 0xC351;
    r = rt_socket_initialize_stack();
    if (r != 0)
        return r;
    for (i = 0; i < 256; i++)
        gaListenSocket[i].sock = -1;
    gbInitialized_1313FC = 1;
    return 0;
}

int rt_comm_platform_shutdown(void)
{
    unsigned int i;
    for (i = 0; i < 256; i++)
        if (gaListenSocket[i].sock != -1 && gaListenSocket[i].sock != -0x101)
            rt_comm_platform_destroy(gaListenSocket[i].sock);
    rt_socket_cleanup_stack();
    gbInitialized_1313FC = 0;
}

int rt_comm_platform_update(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_create);

int rt_socket_close();
void rt_comm_platform_destroy(int s)
{
    int any;
    unsigned int i;
    unsigned int idx;
    RtListenSocket *l;

    if ((unsigned int)(s + 1) < 2) return;
    if (gbInitialized_1313FC == 0) return;
    if (s > 0) {
        rt_socket_close(s);
        return;
    }
    any = 0;
    idx = s + 0x101;
    if ((unsigned int)(s + 0x100) >= 0xFF) return;
    l = &gaListenSocket[idx];
    if (l->sock != -0x101)
        rt_socket_close(l->sock);
    l->sock = -1;
    for (i = 1; i < 256; i++)
        if (gaListenSocket[i].sock != -1)
            any = 1;
    if (!any) {
        rt_socket_close(gaListenSocket[0].sock);
        gaListenSocket[0].sock = -1;
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_send);

int rt_comm_platform_send_to(int s, RtLinkAddr addr, int len, void *buf, int flags, int *sent)
{
    int n = 0;
    int r;
    if (gbInitialized_1313FC != 1)
        return 5;
    if (s < 0)
        return 2;
    if (buf == NULL)
        return 2;
    if (sent == NULL)
        return 2;
    *sent = 0;
    if (len == 0)
        return 2;
    r = rt_socket_send_data_udp(s, buf, flags, addr.ip, len, &n);
    if (r != 0)
        return r;
    *sent = n;
    return 0;
}

int rt_comm_platform_vsend(int s, void *vec, int n)
{
    int r;
    int ret;

    if (gbInitialized_1313FC != 1) return 5;
    if ((unsigned int)(s + 1) < 2) return 2;
    if (s < 0) {
        ret = rt_comm_platform_get_listen_socket(&s);
        if (ret != 0) return ret;
    }
    r = rt_socket_sendmsg(s, vec, 0, 0, n);
    ret = (r != 0 && r != 0xCF0E) ? r : 0;
    return ret;
}

int rt_comm_platform_vsend_to(int s, RtLinkAddr addr, int n, void *iov, int *sent)
{
    if (gbInitialized_1313FC != 1)
        return 5;
    if (s < 0)
        return 2;
    if (iov == NULL)
        return 2;
    if (sent == NULL)
        return 2;
    *sent = 0;
    if (n == 0)
        return 2;
    return rt_socket_sendmsg(s, iov, addr.ip, n, sent);
}

int rt_comm_platform_send_echo(int s, int a, RtLinkAddr addr, int d)
{
    int r;
    if (gbInitialized_1313FC != 1)
        return 5;
    if (s < 0)
        return 2;
    r = rt_socket_send_icmp_echo_request(s, addr.ip, a, d);
    return (r != 0 && r != 0xCF0E) ? r : 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_receive);

int rt_socket_read_data_udp();
int rt_comm_platform_receive_from(int s, int flags, int *len, void *buf, int size, int *from)
{
    int addr = 0;
    int n;
    int r;

    if (gbInitialized_1313FC != 1) return 5;
    if (s < 0) return 2;
    if (len == NULL) return 2;
    if (buf == NULL) return 2;
    if (from == NULL) return 2;
    *from = 0;
    r = rt_socket_read_data_udp(s, buf, size, &addr, flags, &n);
    if (r != 0 && r != 0xCF0E) return r;
    *len = n;
    *from = addr;
    return 0;
}

int rt_comm_platform_receive_echo(int s, int a, int b, int d)
{
    int r;
    if (gbInitialized_1313FC != 1)
        return 5;
    if (s < 0)
        return 2;
    r = rt_socket_recv_icmp_echo_response(s, b, a, d);
    return (r != 0 && r != 0xCF0E) ? r : 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_get_avail_bytes_to_read);

int rt_comm_platform_get_local_ip(int *ip)
{
    if (gbInitialized_1313FC != 1)
        return 5;
    if (ip == NULL)
        return 2;
    return rt_socket_get_local_ip(ip);
}

extern int gbInitialized_1313FC;
int rt_comm_platform_get_broadcast_ip(int *ip)
{
    if (gbInitialized_1313FC != 1)
        return 5;
    *ip = -1;
    return 0;
}

int rt_comm_platform_get_host_by_name(const char *name, int *ip)
{
    if (gbInitialized_1313FC != 1)
        return 5;
    if (name == NULL)
        return 2;
    return rt_socket_get_host_by_name(ip, name);
}

int rt_comm_platform_get_remote_ip(int s, int *ip)
{
    unsigned int i;
    int r;

    if ((unsigned int)(s + 1) < 2) return 2;
    if (s >= 0) return 2;
    i = s + 0x101;
    r = rt_comm_platform_get_listen_socket(&s);
    if (r != 0) return r;
    if (s == -1) return 2;
    *ip = gaListenSocket[i].ip;
    return 0;
}

int rt_comm_platform_display_state(void) {
    return 0;
}

int rt_comm_platform_is_connected(int s, int *out)
{
    if (out == NULL)
        return 2;
    *out = 0;
    return rt_socket_is_connected(s, out);
}

void rt_comm_platform_get_dns_servers(void) {
    rt_socket_get_dns_servers();
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rcsid_10CF5C);
