#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_socket_cleanup_stack_platform(void);
int rt_socket_close_platform(void);
int rt_socket_recvmsg_platform(void);
int rt_socket_get_err_platform();                   /* extern */
int sceNetInetClose();                              /* extern */

int sceNetResolverCreate(int *, void *, int);
int sceNetResolverStartNtoA(int, const char *, void *, int, int);
int sceNetResolverDelete(int);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rcsid_10D120);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_get_err_platform);

int rt_time_start();
void rt_time_elapsed();
int rt_socket_is_interface_up();
int rt_socket_initialize_stack_platform(void)
{
    char start[16];
    int up;
    unsigned int el;
    int r;
    rt_time_start(start);
    for (;;) {
        r = rt_socket_is_interface_up(&up);
        if (r != 0) return r;
        if (up != 0) return 0;
        rt_time_elapsed(start, &el);
        if (el > 95000) return 0xCF0C;
    }
}

int rt_socket_cleanup_stack_platform(void) {
    return 0;
}

int rt_socket_close_platform(void) {
    int var_v1;

    var_v1 = 0;
    if (sceNetInetClose() != 0) {
        var_v1 = rt_socket_get_err_platform();
    }
    return var_v1;
}

int sceNetInetSetsockopt(int, int, int, const void *, int);
int rt_socket_get_err_platform();
int rt_socket_set_no_delay_tcp_platform(int s, int v)
{
    int val = v;
    if (sceNetInetSetsockopt(s, 6, 1, &val, 4) != 0) return rt_socket_get_err_platform();
    return 0;
}

int sceNetInetSetsockopt(int, int, int, const void *, int);
int rt_socket_get_err_platform();
int rt_socket_set_non_blocking_platform(int s, int v)
{
    int val = v;
    if (sceNetInetSetsockopt(s, 0xFFFF, 0x1009, &val, 4) != 0) return rt_socket_get_err_platform();
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_get_available_bytes_to_read_platform);

typedef struct { int fd; short events; short revents; } RtPollFd;
int sceNetInetPoll();
int rt_socket_check_readability_platform(RtPollFd *fds, unsigned int n, int timeout, int *ready)
{
    unsigned int i;
    int r;

    for (i = 0; i < n; i++)
        fds[i].events = 0x19;
    r = sceNetInetPoll(fds, n, timeout);
    if (r == -1) {
        *ready = 0;
        return rt_socket_get_err_platform();
    }
    *ready = r;
    return 0;
}

int rt_socket_check_readability_platform();
int rt_socket_find_sockets_with_data_platform(int *socks, int n, int timeout, int *count)
{
    int c;
    int r;
    if (socks == NULL || count == NULL) return 2;
    r = rt_socket_check_readability_platform(socks, n, timeout, &c);
    if (r != 0) {
        *count = 0;
        return r;
    }
    *count = c;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_find_closed_sockets_platform);

int rt_socket_get_host_by_name(int *out, const char *name)
{
    int ip[4];
    char buf[0x400];
    int rid;
    if (sceNetResolverCreate(&rid, buf, 0x400) < 0) return 1;
    if (sceNetResolverStartNtoA(rid, name, ip, 5000000, 5) < 0) return 1;
    *out = ip[0];
    sceNetResolverDelete(rid);
    return 0;
}

int sceNetApctlGetInfo(int, void *);
int sceNetInetInetAddr(const char *);
int rt_socket_get_local_ip_platform(int *ip)
{
    char info[128];
    if (sceNetApctlGetInfo(8, info) < 0) return 1;
    *ip = sceNetInetInetAddr(info);
    return 0;
}

int rt_socket_is_interface_up(int *up)
{
    char info[128];
    if (sceNetApctlGetInfo(8, info) < 0) {
        *up = 0;
        return 1;
    }
    *up = 1;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_is_connected_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_get_dns_servers_platform);

typedef struct { void *buf; int len; } RtSockIov;
typedef struct { RtSockIov e[8]; int total; int n; } RtSockVec;
typedef struct { unsigned char len; unsigned char family; unsigned short port; unsigned int addr; char zero[8]; } RtSockAddrIn;
typedef struct { void *name; int namelen; RtSockIov *iov; int iovlen; void *control; int controllen; int flags; } RtSockMsg;
int sceNetInetSendmsg();
int rt_socket_sendmsg_platform(int s, RtSockVec *v, unsigned int ip, int port, int *sent)
{
    RtSockMsg msg;
    RtSockIov iov[8];
    RtSockAddrIn sa;
    int i;
    int r;

    *sent = 0;
    if (ip != 0 && port != 0) {
        sa.family = 2;
        sa.addr = ip;
        sa.port = __builtin_allegrex_wsbh((unsigned short)port);
        msg.name = &sa;
        msg.namelen = 16;
    } else {
        msg.name = NULL;
        msg.namelen = 0;
    }
    msg.iov = iov;
    msg.control = NULL;
    msg.controllen = 0;
    msg.iovlen = v->n;
    msg.flags = 0;
    for (i = 0; i < v->n; i++)
        iov[i] = v->e[i];
    r = sceNetInetSendmsg(s, &msg, 0);
    if (r < 0) return rt_socket_get_err_platform();
    *sent = r;
    return 0;
}

int rt_socket_recvmsg_platform(void) {
    return 4;
}
