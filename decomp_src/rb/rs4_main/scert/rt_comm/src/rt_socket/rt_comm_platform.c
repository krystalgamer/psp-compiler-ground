#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK *rt_comm_platform_resolve_interface(void);
int NetUseCommInet(void);
int NetUseCommSockets(void);
int rt_comm_platform_display_state(void);
int rt_comm_platform_linkaddress_toint(int *arg0, int arg1);
int rt_comm_platform_update(void);
void rt_comm_platform_get_dns_servers(void);
void rt_socket_get_dns_servers(void);
int rt_ip_string2ip(int);                           /* extern */
extern void *gCommPlatformInterfacePtr;
extern unsigned char gCommPlatformInterface;
extern unsigned char rt_comm_platform_create;
extern unsigned char rt_comm_platform_destroy;
extern unsigned char rt_comm_platform_get_avail_bytes_to_read;
extern unsigned char rt_comm_platform_get_broadcast_ip;
extern unsigned char rt_comm_platform_get_host_by_name;
extern unsigned char rt_comm_platform_get_local_ip;
extern unsigned char rt_comm_platform_get_remote_ip;
extern unsigned char rt_comm_platform_is_connected;
extern unsigned char rt_comm_platform_linkaddress_isequal;
extern unsigned char rt_comm_platform_linkaddress_isnull;
extern unsigned char rt_comm_platform_linkaddress_setnull;
extern unsigned char rt_comm_platform_linkaddress_toext;
extern unsigned char rt_comm_platform_linkaddress_tostr;
extern unsigned char rt_comm_platform_receive;
extern unsigned char rt_comm_platform_receive_echo;
extern unsigned char rt_comm_platform_receive_from;
extern unsigned char rt_comm_platform_send;
extern unsigned char rt_comm_platform_send_echo;
extern unsigned char rt_comm_platform_send_to;
extern unsigned char rt_comm_platform_shutdown;
extern unsigned char rt_comm_platform_startup;
extern unsigned char rt_comm_platform_vsend;
extern unsigned char rt_comm_platform_vsend_to;

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_get_listen_socket);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_linkaddress_setnull);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_linkaddress_isnull);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_linkaddress_isequal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_linkaddress_tostr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_linkaddress_toext);

int rt_comm_platform_linkaddress_toint(int *arg0, int arg1) {
    *arg0 = rt_ip_string2ip(arg1);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_startup);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_shutdown);

int rt_comm_platform_update(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_send);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_send_to);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_vsend);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_vsend_to);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_send_echo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_receive);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_receive_from);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_receive_echo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_get_avail_bytes_to_read);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_get_local_ip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_get_broadcast_ip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_get_host_by_name);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_get_remote_ip);

int rt_comm_platform_display_state(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rt_comm_platform_is_connected);

void rt_comm_platform_get_dns_servers(void) {
    rt_socket_get_dns_servers();
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_socket/rt_comm_platform", rcsid_10CF5C);
