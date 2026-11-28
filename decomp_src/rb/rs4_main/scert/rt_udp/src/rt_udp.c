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

extern void *gUDPInterface[37];
extern void **gUDPInterfacePtr;
int rt_udp_broadcast();
int rt_udp_connect();
int rt_udp_create();
int rt_udp_deny(void *u, int *c);
int rt_udp_destroy();
int rt_udp_disable_nat_service_heartbeat(void *arg0);
void rt_udp_disconnect();
int rt_udp_event_check();
int rt_udp_event_process();
int rt_udp_get_address();
int rt_udp_get_aggregation_interval(void *arg0, int *arg1);
int rt_udp_get_buffer_size(void *u, int *conn, int which, int *out);
int rt_udp_get_buffer_stats();
int rt_udp_get_local_address(void *arg0, void *arg1, int *arg2);
int rt_udp_get_pool_used(void *udp);
int rt_udp_get_resolved_address();
M2C_UNK *rt_udp_get_version_string(void);
int rt_udp_get_virtual_port(void *arg0, unsigned short *arg1);
int rt_udp_listen(void *arg0, int arg1);
int rt_udp_mgr_create();
int rt_udp_mgr_destroy();
int rt_udp_mgr_find_channel_ref();
int rt_udp_mgr_get_channel_ref();
int rt_udp_mgr_release_channel_ref();
int rt_udp_pre_accept();
int rt_udp_resolve_address();
int rt_udp_send();
int rt_udp_send_list();
int rt_udp_send_unconnected();
int rt_udp_set_aggregation_interval();
int rt_udp_set_buffer_size(void *u, int *c, int which, int size);
void rt_udp_set_peer_id(void *arg0, int arg1);
void rt_udp_resolve_interface(void)
{
    gUDPInterface[0] = (void *)rt_udp_get_version_string;
    gUDPInterface[1] = (void *)rt_udp_create;
    gUDPInterface[2] = (void *)rt_udp_destroy;
    gUDPInterface[3] = (void *)rt_udp_set_buffer_size;
    gUDPInterface[4] = (void *)rt_udp_set_aggregation_interval;
    gUDPInterface[5] = (void *)rt_udp_get_buffer_size;
    gUDPInterface[6] = (void *)rt_udp_get_aggregation_interval;
    gUDPInterface[7] = (void *)rt_udp_get_virtual_port;
    gUDPInterface[8] = (void *)rt_udp_get_buffer_stats;
    gUDPInterface[9] = (void *)rt_udp_resolve_address;
    gUDPInterface[10] = (void *)rt_udp_get_resolved_address;
    gUDPInterface[11] = (void *)rt_udp_get_local_address;
    gUDPInterface[12] = (void *)rt_udp_get_address;
    gUDPInterface[13] = (void *)rt_udp_disable_nat_service_heartbeat;
    gUDPInterface[14] = (void *)rt_udp_connect;
    gUDPInterface[15] = (void *)rt_udp_disconnect;
    gUDPInterface[16] = (void *)rt_udp_set_peer_id;
    gUDPInterface[17] = (void *)rt_udp_send;
    gUDPInterface[18] = (void *)rt_udp_send_list;
    gUDPInterface[19] = (void *)rt_udp_send_unconnected;
    gUDPInterface[20] = (void *)rt_udp_broadcast;
    gUDPInterface[21] = (void *)rt_udp_listen;
    gUDPInterface[23] = (void *)rt_udp_deny;
    gUDPInterface[24] = (void *)rt_udp_pre_accept;
    gUDPInterface[25] = (void *)rt_udp_event_process;
    gUDPInterface[26] = (void *)rt_udp_event_check;
    gUDPInterface[27] = (void *)rt_udp_mgr_create;
    gUDPInterface[28] = (void *)rt_udp_mgr_destroy;
    gUDPInterface[29] = (void *)rt_udp_mgr_get_channel_ref;
    gUDPInterface[30] = (void *)rt_udp_mgr_release_channel_ref;
    gUDPInterface[31] = (void *)rt_udp_mgr_find_channel_ref;
    gUDPInterface[32] = (void *)rt_udp_get_pool_used;
    gUDPInterface[33] = (void *)0xE4A;
    gUDPInterface[34] = 0;
    gUDPInterface[35] = (void *)0x10000;
    gUDPInterface[36] = 0;
    gUDPInterfacePtr = gUDPInterface;
}

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

int rt_udp_get_buffer_stats(void *u, unsigned int *c, int dir, unsigned int *used, unsigned int *size, unsigned int *pct)
{
    if (u == NULL) return 0xD2F2;
    if (c == NULL) return 0xD2F3;
    if (c[0] != 13) return 0xD2F3;
    if (dir == 0) {
        if (used != NULL) *used = c[5];
        if (size != NULL) *size = c[6];
        if (pct != NULL) {
            *pct = c[6] * 100 / c[5];
            if (*pct > 100) *pct = 100;
        }
    } else if (dir == 1) {
        if (used != NULL) *used = c[9];
        if (size != NULL) *size = c[10];
        if (pct != NULL) {
            *pct = c[10] * 100 / c[9];
            if (*pct > 100) *pct = 100;
        }
    } else
        return 2;
    return 0;
}

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

typedef struct { unsigned char b[2]; } RtUdpRaw2;
typedef struct { struct { void *buf; int len; } e[8]; int total; int n; } RtUdpVec;
typedef struct { unsigned short hlen; unsigned short flags; } RtUdpSubInfo2;
int rt_udp_buffer_data_for_send(void *u, void *list, RtUdpVec *v, unsigned short flags, int conn);
void rt_udp_setup_packet_sub_header(char *u, char *c, unsigned short flags, int len, unsigned short *h);
void rt_udp_disconnect(char *u, int *c)
{
    unsigned short sub[2];
    RtUdpVec vec;
    RtUdpSubInfo2 s;
    int st;

    if (u == NULL || c == NULL) {
    } else {
    st = c[0];
    c[0x7C / 4] = 0;
    c[0x80 / 4] = 0;
    c[0x88 / 4] = 0;
    c[0x60 / 4] = 0;
    if (st == 13 || st == 4) {
        if (st == 13) c[0] = 6;
        else if (st == 4) c[0] = 5;
        rt_udp_setup_packet_sub_header(u, (char *)c, 0x4000, 0, sub);
        ((unsigned char *)&s.flags)[0] = ((unsigned char *)sub)[0];
        ((unsigned char *)&s.flags)[1] = ((unsigned char *)sub)[1];
        s.flags &= 0xF800;
        if (s.flags & 0x6000) s.hlen = 4; else s.hlen = 2;
        vec.e[0].buf = sub;
        vec.e[0].len = s.hlen;
        vec.total = s.hlen;
        vec.n = 1;
        if (rt_udp_buffer_data_for_send(u, c + 5, &vec, 0x2000, 0) != 0)
            (*(unsigned short *)((char *)c + 0x64))--;
    } else if (st != 0)
        c[0] = 5;
    }
}

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

int rt_list_buf_append_data();
int rt_udp_append_data_to_packet(void *u, void *list, unsigned short flags, int *pkt, char *data)
{
    unsigned short *h;
    unsigned short len;
    int r;

    h = pkt ? (unsigned short *)((char *)pkt + 0x18) : (unsigned short *)0x10;
    len = *h & 0x7FF;
    r = rt_list_buf_append_data(list, &pkt, data, (pkt ? pkt[0] : 0) - 4);
    if (r != 0) return r;
    h = pkt ? (unsigned short *)((char *)pkt + 0x18) : (unsigned short *)0x10;
    *h = (*h & ~0x7FF) | ((len + *(unsigned short *)(data + 0x40)) & 0x7FF) | (flags & ~0x7FF);
    rt_udp_set_packet_seed(pkt, 0);
    return 0;
}

typedef struct { unsigned char b[4]; } RtUdpRaw4;
typedef struct { unsigned short len; unsigned short hlen; unsigned short flags; } RtUdpSubInfo;
int rt_udp_get_packet_seed(int *pkt, unsigned int *seed)
{
    RtUdpSubInfo s;
    unsigned char *h = pkt ? (unsigned char *)pkt + 0x18 : (unsigned char *)0x10;

    ((unsigned char *)&s.len)[0] = h[0];
    ((unsigned char *)&s.len)[1] = h[1];
    s.len &= 0x7FF;
    ((unsigned char *)&s.flags)[0] = h[0];
    ((unsigned char *)&s.flags)[1] = h[1];
    s.flags &= 0xF800;
    if (s.flags & 0x6000) s.hlen = 4; else s.hlen = 2;
    if (pkt != NULL && s.hlen + s.len < (unsigned int)pkt[0])
        *(RtUdpRaw4 *)seed = *(RtUdpRaw4 *)((char *)pkt + pkt[0] + 4);
    else
        *seed = 0;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_set_packet_seed);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_send_messages);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_udp", rt_udp_remove_non_delivery_critical_packets);

//== rt_udp_send_broadcasts
int rt_list_buf_remove();
int rt_udp_send_broadcasts(char *u)
{
    int sent;
    char *e;
    char *rm;
    unsigned short len;

    sent = 0;
    e = u + 0x3C != NULL ? *(char **)(u + 0x48) : NULL;
    while (e != NULL) {
        rm = NULL;
        if (*(int *)e != 0) {
            *(short *)(e + 0x16) = (*(unsigned short *)(u + 0x78) & 0x3FF) | (short)0x8000;
            len = *(unsigned short *)e - 0x12;
            if (rt_comm_send_to(*(int *)u, u + 0x8C, *(int *)(u + 0x9C), e + 0x16, len, &sent) != 0) break;
            if (len != sent) break;
            rm = e;
        }
        e = *(char **)(e + 4);
        if (rm != NULL) rt_list_buf_remove(u + 0x3C, rm);
    }
    return 0;
}

typedef struct { unsigned int ip; unsigned int port; } RtUdpLinkAddr;
int rt_comm_receive_from(); int rt_comm_linkaddress_isequal(RtUdpLinkAddr, RtUdpLinkAddr); int rt_udp_process_message();
int rt_udp_receive_messages(char *u)
{
    RtUdpLinkAddr from;
    int port;
    unsigned int len;
    int r;

    len = 0;
    do {
        len = 0;
        r = rt_comm_receive_from(*(int *)u, &from, &port, *(void **)(u + 0x5C), 0x5AA, &len);
        if (r == 0) {
            if (len == 0) break;
            if (len >= 2) {
                if (!rt_comm_linkaddress_isequal(from, *(RtUdpLinkAddr *)(u + 0x94)) || port != *(int *)(u + 0x9C))
                    rt_udp_process_message(u, from, port, len);
            }
        }
    } while (len != 0);
    return 0;
}

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

typedef struct { unsigned int ip; unsigned int port; } RtUdpUAddr;
typedef struct { RtUdpUAddr addr; int port; } RtUdpUFrom;
typedef struct { unsigned char *data; int len; RtUdpUFrom *from; int x; char pad[0x30]; int total; int type; } RtUdpUMsg;
int rt_list_buf_insert(); int rt_list_buf_get_tail();
int rt_udp_process_unconnected_data(char *u, unsigned char *data, RtUdpUAddr *addr, int port)
{
    RtUdpUAddr a;
    RtUdpUFrom f;
    RtUdpUMsg m;
    RtUdpSubInfo s;

    ((unsigned char *)&s.len)[0] = data[0];
    ((unsigned char *)&s.len)[1] = data[1];
    s.len &= 0x7FF;
    a = *addr;
    f.addr = *addr;
    f.port = port;
    ((unsigned char *)&s.flags)[0] = data[0];
    ((unsigned char *)&s.flags)[1] = data[1];
    s.flags &= 0xF800;
    if (s.flags & 0x6000) s.hlen = 4; else s.hlen = 2;
    m.data = data;
    m.len = s.hlen + s.len;
    m.from = &f;
    m.x = 12;
    m.total = m.len + 12;
    m.type = 2;
    return rt_list_buf_insert(u + 0x2C, rt_list_buf_get_tail(u + 0x2C), &m);
}

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

int rt_comm_startup(); int rt_memory_allocate_init_zero(); int rt_comm_create(); int rt_comm_get_local_port(); int rt_comm_get_local_ip(); int rt_comm_get_broadcast_ip();
typedef struct { int type; int mtu; int a; int b; } RtUdpCommCfg;
int rt_udp_create_shared_channel_data(char *u)
{
    RtUdpCommCfg cfg;
    RtUdpLinkAddr addr;
    int r;

    r = rt_comm_startup();
    if (r != 0) return r;
    rt_comm_linkaddress_setnull(&addr);
    rt_memory_allocate_init_zero(u + 0x58, 0x5AA);
    if (*(void **)(u + 0x58) == NULL) return 100;
    rt_memory_allocate_init_zero(u + 0x5C, 0x5AA);
    if (*(void **)(u + 0x5C) == NULL) return 100;
    cfg.mtu = 0x5AA;
    cfg.type = 1;
    cfg.a = 0;
    cfg.b = 0;
    r = rt_comm_create(u, &addr, *(int *)(u + 0x9C), &cfg);
    if (r != 0) return r;
    r = rt_comm_get_local_port(*(int *)u, u + 0x9C);
    if (r != 0) return r;
    r = rt_comm_get_local_ip(u + 0x94);
    if (r != 0) return r;
    r = rt_comm_get_broadcast_ip(u + 0x8C);
    return r;
}

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
