#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_socket_cleanup_stack_platform(void);
int rt_socket_close_platform(void);
int rt_socket_recvmsg_platform(void);
int sceNetInetClose();                              /* extern */

int sceNetResolverCreate(int *, void *, int);
int sceNetResolverStartNtoA(int, const char *, void *, int, int);
int sceNetResolverDelete(int);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rcsid_10D120);

//== rt_socket_get_err_platform
int sceNetInetGetErrno();
int rt_socket_get_err_platform()
{
    switch (sceNetInetGetErrno()) {
    case 11:
        return 0xCF0E;
    case 22:
        return 0xCF35;
    case 23:
        return 0xCF33;
    case 24:
        return 0xCF34;
    case 32:
        return 0xCF36;
    case 66:
        return 0xCF32;
    case 81:
        return 0xCF37;
    case 90:
        return 0xCF2D;
    case 91:
        return 0xCF2A;
    case 92:
        return 0xCF29;
    case 95:
        return 0xCF18;
    case 96:
        return 0xCF19;
    case 104:
        return 0xCF21;
    case 105:
        return 0xCF22;
    case 106:
        return 0xCF1A;
    case 107:
        return 0xCF14;
    case 108:
        return 0xCF11;
    case 109:
        return 0xCF15;
    case 110:
        return 0xCF25;
    case 111:
        return 0xCF28;
    case 112:
        return 0xCF1B;
    case 113:
        return 0xCF20;
    case 114:
        return 0xCF1E;
    case 115:
        return 0xCF1D;
    case 116:
        return 0xCF27;
    case 117:
        return 0xCF2B;
    case 118:
        return 0xCF2C;
    case 119:
        return 0xCF0F;
    case 120:
        return 0xCF10;
    case 121:
        return 0xCF12;
    case 122:
        return 0xCF13;
    case 123:
        return 0xCF16;
    case 124:
        return 0xCF17;
    case 125:
        return 0xCF1C;
    case 126:
        return 0xCF1F;
    case 127:
        return 0xCF23;
    case 128:
        return 0xCF24;
    case 129:
        return 0xCF26;
    default:
        return 0xCF0B;
    case 131:
        return 0xCF2F;
    case 132:
        return 0xCF30;
    case 133:
        return 0xCF31;
    }
}

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

int sceNetInetGetsockopt(); int sceNetInetRecv(); int sceNetInetRecvfrom(); int *__errno();
int rt_socket_get_available_bytes_to_read_platform(int s, int *avail)
{
    char buf[0x800];
    int type;
    int len;
    int r;

    *avail = 0;
    len = 4;
    type = 0;
    if (sceNetInetGetsockopt(s, 0xFFFF, 0x1008, &type, &len) != 0)
        return rt_socket_get_err_platform();
    if (type == 1)
        r = sceNetInetRecv(s, buf, 0x800, 2);
    else if (type == 2)
        r = sceNetInetRecvfrom(s, buf, 0x800, 2, 0, 0);
    else
        return 4;
    if (r > 0) {
        *avail = r;
        return 0;
    }
    if (r < 0 && *__errno() == 0xB) return 0;
    return rt_socket_get_err_platform();
}

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

int sceNetInetRecv();
int rt_socket_find_closed_sockets_platform(RtPollFd *fds, unsigned int n, int timeout, int *count)
{
    char buf[16];
    int ready;
    unsigned int i;
    int r;

    if (fds == NULL || count == NULL) return 2;
    r = rt_socket_check_readability_platform(fds, n, timeout, &ready);
    if (r != 0) {
        *count = 0;
        return r;
    }
    if (ready == 0) {
        *count = 0;
        return 0;
    }
    ready = 0;
    for (i = 0; i < n; i++) {
        if (fds[i].revents & 0x18) {
            fds[i].revents = 1;
            ready++;
        } else if (fds[i].revents & 0x40) {
            if (sceNetInetRecv(fds[i].fd, buf, 1, 2) <= 0) {
                fds[i].revents = 1;
                ready++;
            } else
                fds[i].revents = 0;
        }
    }
    *count = ready;
    return 0;
}

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

typedef struct { unsigned int bits[8]; } RtFdSet;
typedef struct { int sec; int usec; } RtTimeval;
int sceNetInetSelect();
#define RT_FD_ZERO(p) do { unsigned int _i; char *_c = (char *)(p); for (_i = 0; _i < sizeof(*(p)); _i++) *_c++ = 0; } while (0)
#define RT_FD_SET(n, p) ((p)->bits[(unsigned int)(n) >> 5] |= 1 << ((n) & 31))
#define RT_FD_ISSET(n, p) ((p)->bits[(unsigned int)(n) >> 5] & (1 << ((n) & 31)))
int rt_socket_is_connected_platform(int s, int *conn)
{
    RtFdSet rs;
    RtFdSet ws;
    RtTimeval tv;
    int err;
    int len;
    int n;

    if (conn == NULL) return 2;
    *conn = 0;
    RT_FD_ZERO(&rs);
    RT_FD_SET(s, &rs);
    RT_FD_ZERO(&ws);
    RT_FD_SET(s, &ws);
    tv.sec = 0;
    tv.usec = 0;
    err = n = sceNetInetSelect(s + 1, &ws, &rs, NULL, &tv);
    if (n <= 0) {
        if (n == 0) return 0;
        return rt_socket_get_err_platform();
    }
    if (RT_FD_ISSET(s, &ws) || RT_FD_ISSET(s, &rs)) {
        len = 4;
        if (sceNetInetGetsockopt(s, 0xFFFF, 0x1007, &err, &len) != 0)
            return rt_socket_get_err_platform();
        if (err != 0) return 0xCF28;
        *conn = 1;
    }
    return 0;
}

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
