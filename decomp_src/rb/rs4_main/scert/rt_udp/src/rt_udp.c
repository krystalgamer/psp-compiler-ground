#include "common.h"
#include "rb/rs4_main/scert/scert.h"

void rt_udp_enable_unexpected_port(int arg0) {
    gbEnableUnexpectedPort = arg0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_get_sequence_id);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_ack_list_flush);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_buffer_ack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_get_first_sub_header);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", GetUDPSecurityMode);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", randomNonZero);

int NetUseUDP(void) {
    rt_udp_resolve_interface();
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_resolve_interface);

M2C_UNK *rt_udp_get_version_string(void) {
    return &gszRtUdpVersionString;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_set_buffer_size);


int rt_udp_set_aggregation_interval(arg0, arg1)
    void *arg0;
    int arg1;
{
    int var_v0;
    var_v0 = 0xD2F2;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0x70) = arg1;
        var_v0 = 0;
    }
    return var_v0;
}
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_get_buffer_size);

int rt_udp_get_aggregation_interval(void *arg0, int *arg1) {
    int var_v1;

    *arg1 = 0;
    var_v1 = 0xD2F2;
    if (arg0 != NULL) {
        var_v1 = 0;
        *arg1 = M2C_FIELD(arg0, int *, 0x70);
    }
    return var_v1;
}

int rt_udp_get_virtual_port(void *arg0, unsigned short *arg1) {
    int var_v1;

    *arg1 = 0;
    var_v1 = 0xD2F3;
    if (arg0 != NULL) {
        var_v1 = 0;
        *arg1 = M2C_FIELD(arg0, unsigned short *, 0x5C);
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_get_buffer_stats);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_resolve_address);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_get_resolved_address);

int rt_udp_get_local_address(void *arg0, void *arg1, int *arg2) {
    int var_a3;

    var_a3 = 0xD2F2;
    if (arg0 != NULL) {
        var_a3 = 0;
        M2C_FIELD(arg1, int *, 0) = (int) M2C_FIELD(arg0, int *, 0x94);
        M2C_FIELD(arg1, int *, 4) = (int) M2C_FIELD(arg0, int *, 0x98);
        *arg2 = M2C_FIELD(arg0, int *, 0x9C);
    }
    return var_a3;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_get_address);

int rt_udp_disable_nat_service_heartbeat(void *arg0) {
    int var_v0;

    var_v0 = 0xD2F2;
    if (arg0 != NULL) {
        rt_upnp_disable_natservice_heartbeat(M2C_FIELD(arg0, int *, 0x10));
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_connect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_disconnect);

void rt_udp_set_peer_id(void *arg0, int arg1) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0x70) = arg1;
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_send);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_send_list);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_send_unconnected);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_broadcast);

int rt_udp_listen(void *arg0, int arg1) {
    int var_v0;

    var_v0 = 2;
    if (arg0 != NULL) {
        M2C_FIELD(arg0, int *, 0x80) = arg1;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_accept);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_deny);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_pre_accept);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_event_process);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rcsid_10CAE0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", headerfile_rcsid_10CB40);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_event_check);

void rt_udp_add_conn_to_list(void *arg0, void *arg1) {
    M2C_FIELD(arg1, void **, 0x8C) = (void *) M2C_FIELD(arg0, void **, 0xC);
    M2C_FIELD(arg0, void **, 0xC) = arg1;
}

void rt_udp_del_conn_from_list(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_v0_2;
    void *var_v1;

    temp_v0 = M2C_FIELD(arg0, void **, 0xC);
    if (temp_v0 == arg1) {
        M2C_FIELD(arg0, void **, 0xC) = (void *) M2C_FIELD(arg1, void **, 0x8C);
        return;
    }
    var_v1 = temp_v0;
    if (temp_v0 != NULL) {
loop_4:
        temp_v0_2 = M2C_FIELD(var_v1, void **, 0x8C);
        if (arg1 == temp_v0_2) {
            M2C_FIELD(var_v1, void **, 0x8C) = (void *) M2C_FIELD(temp_v0_2, void **, 0x8C);
            return;
        }
        var_v1 = temp_v0_2;
        if (temp_v0_2 == NULL) {

        } else {
            goto loop_4;
        }
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_find_free_connection);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_setup_packet_sub_header);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_buffer_data_for_send);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_append_data_to_packet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_get_packet_seed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_set_packet_seed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_send_messages);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_remove_non_delivery_critical_packets);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_send_broadcasts);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_receive_messages);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_process_message);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_process_version_exchange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_send_version_exchange);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_process_new_connect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_process_disconnect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_process_reset);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_process_heartbeat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_process_acknowlege);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_process_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_process_unconnected_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_find_connection);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_send_reset);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_send_ack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_is_duplicate_packet);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_calculate_rto);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_create_shared_channel_data);

int rt_udp_destroy_shared_channel_data(void *arg0) {
    int temp_v1;

    rt_comm_destroy(M2C_FIELD(arg0, int *, 0));
    rt_memory_free(arg0 + 0x58);
    rt_memory_free(arg0 + 0x5C);
    temp_v1 = M2C_FIELD(arg0, int *, 0x10);
    if (temp_v1 != 0) {
        rt_upnp_destroy(temp_v1);
        M2C_FIELD(arg0, int *, 0x10) = 0;
    }
    rt_comm_shutdown();
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_uber_resolve_cb);

int rt_udp_set_inactivity_timeout(int arg0) {
    int var_v0;

    var_v0 = 2;
    if (arg0 != 0) {
        RT_UDP_INACTIVITY_TIMEOUT = arg0;
        var_v0 = 0;
    }
    return var_v0;
}

int rt_udp_get_inactivity_timeout(int *arg0) {
    *arg0 = RT_UDP_INACTIVITY_TIMEOUT;
    return 0;
}

int rt_udp_set_connection_inactivity_timeout(void *arg0, int arg1) {
    int var_v0;

    var_v0 = 2;
    if (arg1 != 0) {
        M2C_FIELD(arg0, int *, 0x44) = arg1;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_get_latency_info);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_get_pool_used);
