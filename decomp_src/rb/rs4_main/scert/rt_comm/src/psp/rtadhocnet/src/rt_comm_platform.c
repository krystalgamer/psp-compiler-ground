#include "common.h"
#include "rb/rs4_main/scert/scert.h"

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_linkaddress_setnull);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_linkaddress_isnull);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_linkaddress_isequal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_linkaddress_tostr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_linkaddress_toext);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_linkaddress_toint);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_startup);

void rt_comm_adhoc_shutdown(void) {
    gbInitialized_130B2C = 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_send_to);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_vsend_to);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_receive_from);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_get_local_ip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_get_broadcast_ip);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_get_stat);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_send_echo);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rt_comm_adhoc_get_dns_servers);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/psp/rtadhocnet/src/rt_comm_platform", rcsid_10CEE4);
