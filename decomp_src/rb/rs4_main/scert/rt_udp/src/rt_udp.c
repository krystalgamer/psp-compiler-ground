#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void memcpy(void *, const void *, unsigned long);
int KM_GetLocalPublicKey();
int rt_list_buf_clear();
int rt_list_buf_get_pool_used();
unsigned int randomMT();
M2C_UNK *rt_udp_get_version_string(void);
int NetUseUDP(void);
int rt_udp_destroy_shared_channel_data(void *arg0);
int rt_udp_disable_nat_service_heartbeat(void *arg0);
int rt_udp_get_aggregation_interval(void *arg0, int *arg1);
int rt_udp_get_inactivity_timeout(int *arg0);
int rt_udp_get_local_address(void *arg0, void *arg1, int *arg2);
int rt_udp_get_virtual_port(void *arg0, unsigned short *arg1);
int rt_udp_listen(void *arg0, int arg1);
int rt_udp_set_aggregation_interval();
int rt_udp_set_connection_inactivity_timeout(void *arg0, int arg1);
int rt_udp_set_inactivity_timeout(int arg0);
int rt_upnp_disable_natservice_heartbeat(void *arg0);
void rt_comm_destroy(void *arg0);
void rt_udp_add_conn_to_list(void *arg0, void *arg1);
void rt_udp_del_conn_from_list(void *arg0, void *arg1);
void rt_udp_enable_unexpected_port(int arg0);
void rt_udp_set_peer_id(void *arg0, int arg1);
M2C_UNK rt_comm_shutdown();                         /* extern */
M2C_UNK rt_memory_free(void *);                     /* extern */
M2C_UNK rt_upnp_destroy(int);                       /* extern */
M2C_UNK rt_udp_resolve_interface();                 /* extern */
extern int gbEnableUnexpectedPort;
extern unsigned char gszRtUdpVersionString;
extern int RT_UDP_INACTIVITY_TIMEOUT;

void rt_udp_enable_unexpected_port(int arg0) {
    gbEnableUnexpectedPort = arg0;
}

unsigned short rt_udp_get_sequence_id(unsigned char *hdr)
{
    unsigned short id;

    ((unsigned char *)&id)[0] = hdr[2];
    ((unsigned char *)&id)[1] = hdr[3];
    return id;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_ack_list_flush);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_buffer_ack);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_get_first_sub_header);

int GetUDPSecurityMode(void)
{
    int mode = 1;

    if (KM_GetLocalPublicKey(-1, 0) != 0)
        mode = 2;
    return mode;
}

unsigned int randomNonZero(unsigned int n)
{
    unsigned int r;

    do
        r = randomMT() % n;
    while (r == 0);
    return r;
}

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

int rt_list_buf_resize_buffer();
int rt_udp_set_buffer_size(void *u, int *c, int which, int size)
{
    if (u == NULL) return 0xD2F2;
    if (c == NULL) return 0xD2F3;
    if (c[0] == 0) return 0xD2F3;
    if (size == 0) return 2;
    if (which == 0) return rt_list_buf_resize_buffer(c + 5, size);
    if (which == 1) return rt_list_buf_resize_buffer(c + 9, size);
    return 2;
}


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
int rt_udp_get_buffer_size(void *u, int *conn, int which, int *out)
{
    *out = 0;
    if (u == NULL) return 0xD2F2;
    if (conn == NULL) return 0xD2F3;
    if (conn[0] != 13) return 0xD2F3;
    if (which == 0) {
        *out = conn[5];
        return 0;
    }
    if (which == 1) {
        *out = conn[9];
        return 0;
    }
    return 2;
}

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

int rt_udp_send_version_exchange();
int rt_udp_accept(void *u, int *c)
{
    if (u == NULL) return 2;
    if (c == NULL) return 0xD2F3;
    if (c[0] != 8) return 0xD2F4;
    c[0] = 9;
    if (rt_udp_send_version_exchange(u, c) != 0) {
        c[0] = 7;
        return 0xD2F7;
    }
    return 0;
}

int rt_udp_send_reset();
int rt_udp_deny(void *u, int *c)
{
    if (u == NULL) return 2;
    if (c == NULL) return 0xD2F3;
    if (c[0] != 8) return 0xD2F4;
    c[0] = 5;
    rt_udp_send_reset(u, c);
    return 0;
}

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

char *rt_udp_find_free_connection(char *u)
{
    char *c = *(char **)(u + 8);
    unsigned int i;
    for (i = 0; i < *(unsigned int *)(u + 0x60); i++, c += 0x90) {
        if (*(int *)c == 0) {
            memset(c, 0, 0x90);
            *(int *)(c + 0x44) = RT_UDP_INACTIVITY_TIMEOUT;
            *(int *)(c + 0x74) = i;
            return c;
        }
    }
    return NULL;
}

void rt_udp_setup_packet_sub_header(char *u, char *c, unsigned short flags, int len, unsigned short *h)
{
    h[0] = (flags & 0xF800) | (len & 0x7FF);
    h[1] = 0;
    if (flags & 0x4000) {
        if (c != NULL) {
            h[1] = *(unsigned short *)(c + 0x64);
            if (++*(unsigned short *)(c + 0x64) == 0)
                ++*(unsigned short *)(c + 0x64);
        }
    } else if (flags & 0x2000) {
        h[1] = *(unsigned short *)(u + 0x7C);
        if (++*(unsigned short *)(u + 0x7C) == 0)
            ++*(unsigned short *)(u + 0x7C);
    } else
        h[1] = 0;
}

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

int rt_udp_process_reset(int *conn)
{
    if (conn == NULL)
        return 0xD2F3;
    if (conn[0] != 5) {
        conn[0] = 2;
        rt_list_buf_clear(conn + 5);
        rt_list_buf_clear(conn + 9);
    }
    return 0;
}

int memcmp(const void *, const void *, unsigned int);
int rt_udp_process_heartbeat(void *a, void *data, int *msg)
{
    short z;
    int r = 0;
    if (msg == NULL) return 0xD2F3;
    z = 0;
    if (memcmp(&z, data, 2) != 0 || *msg != 13) r = (*msg == 13) ? 0xD2F4 : 0xD2F5;
    return r;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_process_acknowlege);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_process_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_process_unconnected_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_find_connection);

int rt_comm_send_to();
typedef struct { unsigned short h, a, b; } RtUdpRst;
int rt_udp_send_reset(int *ch, char *conn)
{
    int x = 0;
    RtUdpRst p = {0, 0, 0};
    p.h = (*(unsigned short *)(conn + 0x5E) & 0x3FF) | 0x1000;
    rt_comm_send_to(*ch, conn + 8, *(int *)(conn + 0x10), &p, 6, &x);
    return 0;
}

int rt_udp_buffer_ack(int, int, int);
int rt_udp_send_ack(int a, int b, unsigned char *c)
{
    return rt_udp_buffer_ack(a, b, rt_udp_get_sequence_id(c));
}

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

typedef struct { int ip; int port; } RtUberAddr;
typedef void (*RtUberCb)(void *, int, RtUberAddr *, int, int);
void rt_udp_uber_resolve_cb(int a, int b, int c, RtUberAddr *addr, int e, char *ctx)
{
    RtUberAddr l = *addr;
    if (ctx == NULL) return;
    *(int *)(ctx + 0x84) = 0;
    (*(RtUberCb *)(ctx + 0xB0))(ctx, b, &l, e, *(int *)(ctx + 0xB4));
}

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

int rt_udp_get_latency_info(int *u, int *out)
{
    if (u == NULL) return 0xD2F3;
    if (u[0] != 13) return 0xD2F3;
    if (out == NULL) return 2;
    out[0] = u[0x50 / 4];
    out[1] = u[0x54 / 4];
    out[2] = u[0x4C / 4];
    return 0;
}

int rt_udp_get_pool_used(void *udp)
{
    int ret = 2;

    if (udp != NULL)
        ret = rt_list_buf_get_pool_used((char *)udp + 0x14);
    return ret;
}
