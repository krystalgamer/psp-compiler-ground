#include "common.h"
#include "rb/rs4_main/scert/scert.h"

int rt_comm_get_version_string_ptr(void) {
    return gpszVersion_11536C;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rcsid_10E72C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", header_rcsid_10E788);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", header2_rcsid);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", D_0010E854);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_get_build_timestamp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_startup);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_shutdown);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_update);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_set_default_options);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_create);

void rt_comm_destroy(void *arg0) {
    if (rt_comm_is_valid_channel() == 0) {

    } else {
        M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(int), 0xC)(M2C_FIELD(arg0, int *, 8));
        M2C_FIELD(arg0, int *, 4) = 0;
        M2C_FIELD(arg0, int *, 0) = 0;
        rt_comm_release_channel_id(arg0);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_send);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_send_to);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_vsend);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_vsend_to);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_send_echo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_receive);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_receive_from);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_receive_echo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_get_avail_bytes_to_read);

void rt_comm_get_local_ip(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x34)();
}

void rt_comm_get_broadcast_ip(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x38)();
}

void rt_comm_get_host_by_name(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x3C)();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_get_remote_ip);

void rt_comm_display_state(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x44)();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_get_metrics);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_get_interface_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_get_local_port);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_is_connected);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_get_host_by_name_nb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_generate_lookup_query);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_resend_lookup_query);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_check_for_query_response);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_process_response_header);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_skip_query_section);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_process_rr);

int rt_isdigit(int arg0) {
    return (unsigned int) (arg0 - 0x30) < 0xAU;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_get_new_channel_id);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_release_channel_id);


int rt_comm_is_valid_channel(arg0)
    void *arg0;
{
    int var_v1;
    var_v1 = 0;
    if ((arg0 != NULL) && (M2C_FIELD(arg0, int *, 0) != 0) && ((var_v1 = 1, (M2C_FIELD(arg0, int *, 4) == 0)) || ((unsigned int) M2C_FIELD(arg0, unsigned int *, 0xC) >= 4U))) {
        var_v1 = 0;
    }
    return var_v1;
}
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_metric_init);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_metric_add_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_metric_update);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_metric_update_single);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_linkaddress_setnull);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_linkaddress_isnull);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_linkaddress_isequal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_linkaddress_tostr);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_linkaddress_toext);

void rt_comm_linkaddress_toint(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x64)();
}

int rt_comm_echo_is_enabled(void) {
    return gEchoInfo;
}

void rt_comm_echo_set_default_options(int *arg0) {
    *arg0 = 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_echo_enable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_echo_send);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_echo_update);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_comm/src/rt_comm", rt_comm_echo_shutdown);

void rt_comm_get_dns_servers(void) {
    M2C_FIELD(gCommPlatformInterfacePtr, M2C_UNK (**)(), 0x68)();
}
