#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_socket_cleanup_stack_platform(void);
int rt_socket_close_platform(void);
int rt_socket_get_version_string(void);
int rt_socket_listen_tcp(void);
int rt_socket_recvmsg_platform(void);
void rt_socket_cleanup_stack(void);
void rt_socket_close(void);
void rt_socket_find_closed_sockets(void);
void rt_socket_find_sockets_with_data(void);
void rt_socket_get_available_bytes_to_read(void);
void rt_socket_get_dns_servers(void);
void rt_socket_get_local_ip(void);
void rt_socket_initialize_stack(void);
void rt_socket_is_connected(void);
void rt_socket_recvmsg(void);
void rt_socket_sendmsg(void);
void rt_socket_set_no_delay_tcp(void);
void rt_socket_set_non_blocking(void);
M2C_UNK rt_socket_get_local_ip_platform();          /* extern */
int rt_socket_get_err_platform();                   /* extern */
M2C_UNK rt_socket_get_dns_servers_platform();       /* extern */
M2C_UNK rt_socket_get_available_bytes_to_read_platform(); /* extern */
int sceNetInetListen();                             /* extern */
M2C_UNK rt_socket_sendmsg_platform();               /* extern */
M2C_UNK rt_socket_is_connected_platform();          /* extern */
M2C_UNK rt_socket_find_sockets_with_data_platform(); /* extern */
M2C_UNK rt_socket_find_closed_sockets_platform();   /* extern */
M2C_UNK rt_socket_set_non_blocking_platform();      /* extern */
M2C_UNK rt_socket_initialize_stack_platform();      /* extern */
M2C_UNK rt_socket_set_no_delay_tcp_platform();      /* extern */
extern int gpszVersion_114A2C;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_get_version);

int rt_socket_get_version_string(void) {
    return gpszVersion_114A2C;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rcsid_10CFCC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", header_rcsid_10D030);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", RT_SOCKET_MINOR_VERSION);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", D_0010D098);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", D_0010D0B8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_get_build_timestamp);

void rt_socket_initialize_stack(void) {
    rt_socket_initialize_stack_platform();
}

void rt_socket_cleanup_stack(void) {
    rt_socket_cleanup_stack_platform();
}

int sceNetInetShutdown();
int rt_socket_get_err_platform();
int rt_socket_shutdown(int s)
{
    if (sceNetInetShutdown(s, 2) != 0) return rt_socket_get_err_platform();
    return 0;
}

void rt_socket_close(void) {
    rt_socket_close_platform();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_get_type);

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
int rt_socket_get_err_platform();
int rt_socket_set_reuse_address(int s, int v)
{
    int val = v;
    if (sceNetInetSetsockopt(s, 0xFFFF, 4, &val, 4) != 0) return rt_socket_get_err_platform();
    return 0;
}

int sceNetInetSetsockopt(int, int, int, const void *, int);
int rt_socket_get_err_platform();
int rt_socket_set_send_buffer_size(int s, int v)
{
    int val = v;
    if (sceNetInetSetsockopt(s, 0xFFFF, 0x1001, &val, 4) != 0) return rt_socket_get_err_platform();
    return 0;
}

int sceNetInetSetsockopt(int, int, int, const void *, int);
int rt_socket_get_err_platform();
int rt_socket_set_receive_buffer_size(int s, int v)
{
    int val = v;
    if (sceNetInetSetsockopt(s, 0xFFFF, 0x1002, &val, 4) != 0) return rt_socket_get_err_platform();
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_get_receive_buffer_size);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_get_send_buffer_size);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_bind);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_bind_with_ip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_bind_dynamic);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_connect_to_service);

void rt_socket_find_sockets_with_data(void) {
    rt_socket_find_sockets_with_data_platform();
}

void rt_socket_find_closed_sockets(void) {
    rt_socket_find_closed_sockets_platform();
}

void rt_socket_get_local_ip(void) {
    rt_socket_get_local_ip_platform();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_create_tcp);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_accept_connection_tcp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_read_data_tcp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_send_data_tcp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_peek_data_tcp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_create_udp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_accept_connection_udp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_read_data_udp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_send_data_udp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_read_data_connected_udp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_send_data_connected_udp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", in_cksum);

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
