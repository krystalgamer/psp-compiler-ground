#include "common.h"
#include "rb/rs4_main/scert/scert.h"

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_shutdown);

void rt_socket_close(void) {
    rt_socket_close_platform();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_get_type);

void rt_socket_set_non_blocking(void) {
    rt_socket_set_non_blocking_platform();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_set_broadcast);

void rt_socket_get_available_bytes_to_read(void) {
    rt_socket_get_available_bytes_to_read_platform();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_set_reuse_address);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_set_send_buffer_size);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/rt_socket", rt_socket_set_receive_buffer_size);

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
