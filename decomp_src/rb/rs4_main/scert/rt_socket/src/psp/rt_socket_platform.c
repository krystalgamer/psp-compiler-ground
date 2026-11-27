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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_set_no_delay_tcp_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_set_non_blocking_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_get_available_bytes_to_read_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_check_readability_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_find_sockets_with_data_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_find_closed_sockets_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_get_host_by_name);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_get_local_ip_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_is_interface_up);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_is_connected_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_get_dns_servers_platform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_socket/src/psp/rt_socket_platform", rt_socket_sendmsg_platform);

int rt_socket_recvmsg_platform(void) {
    return 4;
}
