#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
unsigned short in_cksum(unsigned short *, int);
int rt_socket_accept_connection_tcp(int, int *);
int rt_socket_accept_connection_udp(int, char *);
void rt_socket_cleanup_stack(void);
int rt_socket_cleanup_stack_platform(void);
void rt_socket_close(void);
int rt_socket_close_platform(void);
int rt_socket_create_tcp(int *);
int rt_socket_create_udp(int *);
void rt_socket_find_closed_sockets(void);
int rt_socket_find_closed_sockets_platform();
void rt_socket_find_sockets_with_data(void);
int rt_socket_find_sockets_with_data_platform();
void rt_socket_get_available_bytes_to_read(void);
int rt_socket_get_available_bytes_to_read_platform();
void rt_socket_get_dns_servers(void);
int rt_socket_get_dns_servers_platform();
int rt_socket_get_err_platform(void);
void rt_socket_get_local_ip(void);
int rt_socket_get_local_ip_platform();
int rt_socket_get_receive_buffer_size(int, int *);
int rt_socket_get_send_buffer_size(int, int *);
int rt_socket_get_type(int, int *);
int rt_socket_get_version(unsigned char *, unsigned char *, unsigned char *);
int rt_socket_get_version_string(void);
void rt_socket_initialize_stack(void);
int rt_socket_initialize_stack_platform(void);
void rt_socket_is_connected(void);
int rt_socket_is_connected_platform();
int rt_socket_listen_tcp(void);
int rt_socket_peek_data_tcp(int, void *, int, int *);
int rt_socket_read_data_connected_udp(int, void *, int, int *);
int rt_socket_read_data_tcp(int, void *, int, int *);
void rt_socket_recvmsg(void);
int rt_socket_recvmsg_platform(void);
int rt_socket_send_data_connected_udp(int, void *, int, int *);
int rt_socket_send_data_tcp(int, void *, int, int *);
void rt_socket_sendmsg(void);
int rt_socket_sendmsg_platform();
int rt_socket_set_broadcast(int, int);
void rt_socket_set_no_delay_tcp(void);
int rt_socket_set_no_delay_tcp_platform();
void rt_socket_set_non_blocking(void);
int rt_socket_set_non_blocking_platform();
int rt_socket_set_receive_buffer_size(int, int);
int rt_socket_set_reuse_address(int, int);
int rt_socket_set_send_buffer_size(int, int);
int rt_socket_shutdown(int);

int sceNetInetListen();                             /* extern */

extern int gpszVersion_114A2C;

int sceNetInetRecv();
int sceNetInetSend();
int sceNetInetGetsockopt();
int sceNetInetAccept();
int sceNetInetBind();
void *memset(void *, int, unsigned long);

int rt_socket_get_version(unsigned char *maj, unsigned char *min, unsigned char *rev)
{
    if (maj == NULL || min == NULL) return 2;
    if (rev == NULL) return 2;
    *maj = 2;
    *min = 10;
    *rev = 5;
    return 0;
}

int rt_socket_get_version_string(void) {
    return gpszVersion_114A2C;
}

int sceNetInetConnect(int, void *, int);
typedef struct { unsigned char len, family; unsigned short port; int addr; char zero[8]; } RtSin2;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rcsid_10CFCC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", header_rcsid_10D030);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", RT_SOCKET_MINOR_VERSION);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", D_0010D098);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", D_0010D0B8);

typedef struct { unsigned char len; unsigned char family; unsigned short port; unsigned int addr; char zero[8]; } RtSockAddrIn;
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_get_build_timestamp);

void rt_socket_initialize_stack(void) {
    rt_socket_initialize_stack_platform();
}

void rt_socket_cleanup_stack(void) {
    rt_socket_cleanup_stack_platform();
}

int sceNetInetShutdown();

int rt_socket_shutdown(int s)
{
    if (sceNetInetShutdown(s, 2) != 0) return rt_socket_get_err_platform();
    return 0;
}

void rt_socket_close(void) {
    rt_socket_close_platform();
}

int rt_socket_get_type(int s, int *out)
{
    int v;
    int len;
    if (out == NULL) return 2;
    len = 4;
    if (sceNetInetGetsockopt(s, 0xFFFF, 0x1008, &v, &len) != 0) return rt_socket_get_err_platform();
    *out = v;
    return 0;
}

void rt_socket_set_non_blocking(void) {
    rt_socket_set_non_blocking_platform();
}

int rt_socket_set_broadcast(int s, int on)
{
    int val = on == 1;
    if (sceNetInetSetsockopt(s, 0xFFFF, 0x20, &val, 4) != 0) return rt_socket_get_err_platform();
    return 0;
}

void rt_socket_get_available_bytes_to_read(void) {
    rt_socket_get_available_bytes_to_read_platform();
}

int sceNetInetSetsockopt(int, int, int, const void *, int);

int rt_socket_set_reuse_address(int s, int v)
{
    int val = v;
    if (sceNetInetSetsockopt(s, 0xFFFF, 4, &val, 4) != 0) return rt_socket_get_err_platform();
    return 0;
}

int sceNetInetSetsockopt(int, int, int, const void *, int);

int rt_socket_set_send_buffer_size(int s, int v)
{
    int val = v;
    if (sceNetInetSetsockopt(s, 0xFFFF, 0x1001, &val, 4) != 0) return rt_socket_get_err_platform();
    return 0;
}

int sceNetInetSetsockopt(int, int, int, const void *, int);

int rt_socket_set_receive_buffer_size(int s, int v)
{
    int val = v;
    if (sceNetInetSetsockopt(s, 0xFFFF, 0x1002, &val, 4) != 0) return rt_socket_get_err_platform();
    return 0;
}

int rt_socket_get_receive_buffer_size(int s, int *out)
{
    int v;
    int len = 4;
    if (sceNetInetGetsockopt(s, 0xFFFF, 0x1002, &v, &len) != 0) {
        *out = 0;
        return rt_socket_get_err_platform();
    }
    *out = v;
    return 0;
}

int rt_socket_get_send_buffer_size(int s, int *out)
{
    int v;
    int len = 4;
    if (sceNetInetGetsockopt(s, 0xFFFF, 0x1001, &v, &len) != 0) {
        *out = 0;
        return rt_socket_get_err_platform();
    }
    *out = v;
    return 0;
}

int rt_socket_bind(int s, int port)
{
    RtSin2 sin;
    memset(&sin, 0, sizeof sin);
    sin.addr = __builtin_allegrex_wsbw(0);
    sin.family = 2;
    sin.port = __builtin_allegrex_wsbh((unsigned short)port);
    if (sceNetInetBind(s, &sin, sizeof sin) != 0) return rt_socket_get_err_platform();
    return 0;
}

int rt_socket_bind_with_ip(int s, int ip, int port)
{
    RtSin2 sin;
    memset(&sin, 0, sizeof sin);
    sin.family = 2;
    sin.addr = ip;
    sin.port = __builtin_allegrex_wsbh((unsigned short)port);
    if (sceNetInetBind(s, &sin, sizeof sin) != 0) return rt_socket_get_err_platform();
    return 0;
}

int sceNetInetGetsockname();
int rt_socket_bind_dynamic(int s, int *port)
{
    RtSin2 sin;
    RtSin2 name;
    int len;

    memset(&sin, 0, sizeof sin);
    sin.family = 2;
    sin.addr = __builtin_allegrex_wsbw(0);
    if (*port == 0) sin.port = 0;
    else sin.port = __builtin_allegrex_wsbh((unsigned short)*port);
    if (sceNetInetBind(s, &sin, sizeof sin) != 0) return rt_socket_get_err_platform();
    if (*port == 0) {
        len = sizeof name;
        if (sceNetInetGetsockname(s, &name, &len) != 0) return rt_socket_get_err_platform();
        *port = (unsigned short)__builtin_allegrex_wsbh(name.port);
    }
    return 0;
}

int rt_socket_connect_to_service(int s, int ip, int port)
{
    RtSin2 sin;
    memset(&sin, 0, sizeof sin);
    sin.family = 2;
    sin.addr = ip;
    sin.port = __builtin_allegrex_wsbh((unsigned short)port);
    if (sceNetInetConnect(s, &sin, sizeof sin) != 0) return rt_socket_get_err_platform();
    return 0;
}

void rt_socket_find_sockets_with_data(void) {
    rt_socket_find_sockets_with_data_platform();
}

void rt_socket_find_closed_sockets(void) {
    rt_socket_find_closed_sockets_platform();
}

void rt_socket_get_local_ip(void) {
    rt_socket_get_local_ip_platform();
}

int sceNetInetSocket(int, int, int);
int rt_socket_create_tcp(int *s)
{
    int r = sceNetInetSocket(2, 1, 0);
    if (r == -1) {
        *s = r;
        return rt_socket_get_err_platform();
    }
    *s = r;
    return 0;
}

void rt_socket_set_no_delay_tcp(void) {
    rt_socket_set_no_delay_tcp_platform();
}

int rt_socket_listen_tcp(void) {
    int var_v1;

    var_v1 = 0;
    if (sceNetInetListen() != 0) {
        var_v1 = rt_socket_get_err_platform();
    }
    return var_v1;
}

int rt_socket_accept_connection_tcp(int s, int *out)
{
    RtSockAddrIn sa;
    int len;
    int r;
    if (out == NULL) return 2;
    len = 16;
    r = sceNetInetAccept(s, &sa, &len);
    if (r == -1) {
        out[0] = r;
        out[2] = 0;
        return rt_socket_get_err_platform();
    }
    out[0] = r;
    out[2] = sa.addr;
    out[1] = (unsigned short)__builtin_allegrex_wsbh(sa.port);
    return 0;
}

int rt_socket_read_data_tcp(int s, void *buf, int len, int *got)
{
    int r;
    if (buf == NULL || got == NULL) {
        *got = 0;
        return 2;
    }
    if (len == 0) {
        *got = 0;
        return 0;
    }
    r = sceNetInetRecv(s, buf, len, 0);
    if (r < 0) {
        *got = 0;
        return rt_socket_get_err_platform();
    }
    *got = r;
    return 0;
}

int rt_socket_send_data_tcp(int s, void *buf, int len, int *got)
{
    int r;
    if (buf == NULL || got == NULL) {
        *got = 0;
        return 2;
    }
    if (len == 0) {
        *got = 0;
        return 0;
    }
    r = sceNetInetSend(s, buf, len, 0);
    if (r < 0) {
        *got = 0;
        return rt_socket_get_err_platform();
    }
    *got = r;
    return 0;
}

int rt_socket_peek_data_tcp(int s, void *buf, int len, int *got)
{
    int r;
    if (buf == NULL || got == NULL) {
        *got = 0;
        return 2;
    }
    if (len == 0) {
        *got = 0;
        return 0;
    }
    r = sceNetInetRecv(s, buf, len, 2);
    if (r < 0) {
        *got = 0;
        return rt_socket_get_err_platform();
    }
    *got = r;
    return 0;
}

int rt_socket_create_udp(int *s)
{
    int r = sceNetInetSocket(2, 2, 0);
    if (r == -1) {
        *s = r;
        return rt_socket_get_err_platform();
    }
    *s = r;
    return 0;
}

int rt_socket_accept_connection_udp(int s, char *a)
{
    RtSin2 sin;
    memset(&sin, 0, sizeof sin);
    sin.family = 2;
    sin.port = __builtin_allegrex_wsbh(*(unsigned short *)(a + 4));
    sin.addr = *(int *)(a + 8);
    if (sceNetInetConnect(s, &sin, sizeof sin) != 0) return rt_socket_get_err_platform();
    return 0;
}

int sceNetInetRecvfrom();
int rt_socket_read_data_udp(int s, void *buf, int len, int *got, int *ip, int *port)
{
    RtSin2 sin;
    int slen;
    int r;

    if (buf == NULL || got == NULL || ip == NULL || port == NULL) return 2;
    if (len == 0) {
        *got = 0;
        return 0;
    }
    slen = sizeof sin;
    r = sceNetInetRecvfrom(s, buf, len, 0, &sin, &slen);
    if (r < 0) {
        *got = 0;
        *ip = 0;
        *port = 0;
        return rt_socket_get_err_platform();
    }
    *got = r;
    *ip = sin.addr;
    *port = (unsigned short)__builtin_allegrex_wsbh(sin.port);
    return 0;
}

int rt_socket_send_data_udp(int s, void *buf, int len, int ip, int port, int *sent)
{
    RtSin2 sin;
    int r;

    if (buf == NULL || sent == NULL) return 2;
    if (len == 0) {
        *sent = 0;
        return 0;
    }
    sin.family = 2;
    sin.port = __builtin_allegrex_wsbh((unsigned short)port);
    sin.addr = ip;
    r = sceNetInetSendto(s, buf, len, 0, &sin, sizeof sin);
    if (r == -1) {
        *sent = 0;
        return rt_socket_get_err_platform();
    }
    *sent = r;
    return 0;
}

int rt_socket_read_data_connected_udp(int s, void *buf, int len, int *got)
{
    int r;
    if (buf == NULL || got == NULL) {
        *got = 0;
        return 2;
    }
    if (len == 0) {
        *got = 0;
        return 0;
    }
    r = sceNetInetRecv(s, buf, len, 0);
    if (r < 0) {
        *got = 0;
        return rt_socket_get_err_platform();
    }
    *got = r;
    return 0;
}

int rt_socket_send_data_connected_udp(int s, void *buf, int len, int *got)
{
    int r;
    if (buf == NULL || got == NULL) {
        *got = 0;
        return 2;
    }
    if (len == 0) {
        *got = 0;
        return 0;
    }
    r = sceNetInetSend(s, buf, len, 0);
    if (r < 0) {
        *got = 0;
        return rt_socket_get_err_platform();
    }
    *got = r;
    return 0;
}

unsigned short in_cksum(unsigned short *p, int len)
{
    int sum = 0;
    unsigned short odd;
    while (len > 1) {
        sum += *p++;
        len -= 2;
    }
    if (len == 1) {
        odd = 0;
        *(unsigned char *)&odd = *(unsigned char *)p;
        sum += odd;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return ~sum;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_create_icmp_echo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_send_icmp_echo_request);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_recv_icmp_echo_response);

void rt_socket_is_connected(void) {
    rt_socket_is_connected_platform();
}

void rt_socket_get_dns_servers(void) {
    rt_socket_get_dns_servers_platform();
}

void rt_socket_sendmsg(void) {
    rt_socket_sendmsg_platform();
}

void rt_socket_recvmsg(void) {
    rt_socket_recvmsg_platform();
}
