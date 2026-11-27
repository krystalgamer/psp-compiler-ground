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

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rcsid_10D120);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_get_err_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_initialize_stack_platform);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_check_readability_platform);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_get_host_by_name);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_sendmsg_platform);

int rt_socket_recvmsg_platform(void) {
    return 4;
}
