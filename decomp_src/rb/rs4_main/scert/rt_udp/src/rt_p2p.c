#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_p2p_generic_disconnect();
int rt_udp_send_unconnected();
int NetUsePeerToPeer(void *arg0);
int NetUseUDP(void);
int rt_p2p_get_max_peers(void *arg0, int *arg1);
int rt_p2p_get_overlay_peer_count(void *arg0, int arg1, int *arg2);
int rt_p2p_get_virtual_port(void *arg0, unsigned short *arg1);
int rt_p2p_pack_type(int arg0, int arg1);
int rt_p2p_process_local_broadcast_test(void *arg0, int arg1);
int rt_p2p_set_send_aggregation(int *arg0);
int rt_p2p_tick(int arg0);
int rt_udp_set_aggregation_interval();
void rt_p2p_reset_peer_info(void *arg0, void *arg1);
void rt_p2p_resolve_interface(void);
M2C_UNK rt_comm_linkaddress_setnull(int);           /* extern */
extern void *gUDPInterfacePtr;
typedef struct { int a; int conn1; int conn2; int pad[17]; } RtP2PPeer;
typedef struct { int a; int conn; int time; } RtP2PBacklog;
typedef struct { struct { void *buf; int len; } e[8]; int total; int n; } RtP2PVec;
extern void *gP2PInterface[35];
extern void **gP2PInterfacePtr;
int rt_p2p_create(); int rt_p2p_destroy(); int rt_p2p_get_current_address_type(char *, unsigned short, int *); int rt_p2p_get_peer_address();
int rt_p2p_get_my_address(); int rt_p2p_get_my_peer_index(void *p2p, unsigned short *out);
int rt_p2p_get_host_index(void *p2p, unsigned short *out); int rt_p2p_get_buffer_stats(); int rt_p2p_get_peer_buffer_stats();
int rt_p2p_host(); int rt_p2p_incoming_peer(); int rt_p2p_connect(); int rt_p2p_disconnect(); int rt_p2p_update();
int rt_p2p_send(); int rt_p2p_send_list(); int rt_p2p_receive_broadcasts(char *, int);
typedef struct { unsigned int ip; unsigned int port; } RtP2PAddr;
int rt_p2p_send_to(void *p2p, RtP2PAddr addr, void *data, int len);
int rt_p2p_set_max_peers(void *p2p, int n); int rt_p2p_set_overlay_type(); int rt_p2p_join_overlay(); int rt_p2p_quit_overlay();
int rt_p2p_quit_all_overlays(); int rt_p2p_ignore_peer_in_overlay();
int rt_p2p_is_peer_in_overlay(char *p, unsigned char ov, unsigned short peer, int *out);
int rt_p2p_send_overlay(); int rt_p2p_send_token_msg(); int rt_p2p_send_token_list_msg(); int rt_p2p_token_event_notify();
int rt_p2p_get_latency_info(char *, unsigned short, void *);

int NetUsePeerToPeer(void *arg0) {
    rt_p2p_resolve_interface();
    NetUseUDP();
    if (gUDPInterfacePtr != NULL) {
        M2C_FIELD(gUDPInterfacePtr, int *, 0x84) = (int) M2C_FIELD(arg0, int *, 0);
        M2C_FIELD(gUDPInterfacePtr, int *, 0x88) = (int) M2C_FIELD(arg0, int *, 4);
        M2C_FIELD(gUDPInterfacePtr, int *, 0x8C) = (int) M2C_FIELD(arg0, int *, 0xC);
        M2C_FIELD(gUDPInterfacePtr, int *, 0x90) = (int) M2C_FIELD(arg0, int *, 8);
    }
    return 0;
}

void *memcpy(void *, const void *, unsigned int);
typedef struct { unsigned char a, b, idx, c; int v; } RtP2pOvl;
typedef void (*RtP2pBcCb)(int, int, int);

void rt_p2p_resolve_interface(void)
{
    gP2PInterface[0] = (void *)rt_p2p_create;
    gP2PInterface[1] = (void *)rt_p2p_destroy;
    gP2PInterface[2] = (void *)rt_p2p_get_current_address_type;
    gP2PInterface[3] = (void *)rt_p2p_get_peer_address;
    gP2PInterface[4] = (void *)rt_p2p_get_my_address;
    gP2PInterface[5] = (void *)rt_p2p_get_my_peer_index;
    gP2PInterface[6] = (void *)rt_p2p_get_host_index;
    gP2PInterface[7] = (void *)rt_p2p_get_virtual_port;
    gP2PInterface[8] = (void *)rt_p2p_get_buffer_stats;
    gP2PInterface[9] = (void *)rt_p2p_get_peer_buffer_stats;
    gP2PInterface[10] = (void *)rt_p2p_set_send_aggregation;
    gP2PInterface[11] = (void *)rt_p2p_host;
    gP2PInterface[12] = (void *)rt_p2p_incoming_peer;
    gP2PInterface[13] = (void *)rt_p2p_connect;
    gP2PInterface[14] = (void *)rt_p2p_disconnect;
    gP2PInterface[15] = (void *)rt_p2p_tick;
    gP2PInterface[16] = (void *)rt_p2p_update;
    gP2PInterface[17] = (void *)rt_p2p_send;
    gP2PInterface[18] = (void *)rt_p2p_send_list;
    gP2PInterface[19] = (void *)rt_p2p_receive_broadcasts;
    gP2PInterface[20] = (void *)rt_p2p_send_to;
    gP2PInterface[21] = (void *)rt_p2p_get_max_peers;
    gP2PInterface[22] = (void *)rt_p2p_set_max_peers;
    gP2PInterface[23] = (void *)rt_p2p_set_overlay_type;
    gP2PInterface[24] = (void *)rt_p2p_join_overlay;
    gP2PInterface[25] = (void *)rt_p2p_quit_overlay;
    gP2PInterface[26] = (void *)rt_p2p_quit_all_overlays;
    gP2PInterface[27] = (void *)rt_p2p_ignore_peer_in_overlay;
    gP2PInterface[29] = (void *)rt_p2p_is_peer_in_overlay;
    gP2PInterface[28] = (void *)rt_p2p_get_overlay_peer_count;
    gP2PInterface[30] = (void *)rt_p2p_send_overlay;
    gP2PInterface[31] = (void *)rt_p2p_send_token_msg;
    gP2PInterface[32] = (void *)rt_p2p_send_token_list_msg;
    gP2PInterface[33] = (void *)rt_p2p_token_event_notify;
    gP2PInterface[34] = (void *)rt_p2p_get_latency_info;
    gP2PInterfacePtr = gP2PInterface;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_destroy);

int rt_p2p_get_current_address_type(char *p, unsigned short idx, int *type)
{
    RtP2PPeer *peer;

    *type = -1;
    if (p == NULL) return 2;
    if (idx >= *(unsigned short *)(p + 0x19C)) return 0xD4E6;
    peer = (RtP2PPeer *)(idx * sizeof(RtP2PPeer) + *(int *)(p + 0x184));
    if (peer->conn1 != 0) {
        *type = 0;
    } else if (peer->conn2 != 0) {
        *type = 1;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_get_peer_address);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_get_my_address);

int rt_p2p_get_my_peer_index(void *p2p, unsigned short *out)
{
    int ret = 2;

    if (out != NULL) {
        if (p2p != NULL) {
            *out = M2C_FIELD(p2p, unsigned short *, 0x1A4);
            ret = 0;
        }
    }
    return ret;
}

int rt_p2p_get_host_index(void *p2p, unsigned short *out)
{
    int ret = 2;

    if (out != NULL) {
        if (p2p != NULL) {
            *out = M2C_FIELD(p2p, unsigned short *, 0x1A2);
            ret = 0;
        }
    }
    return ret;
}

int rt_p2p_get_virtual_port(void *arg0, unsigned short *arg1) {
    int var_v1;

    var_v1 = 2;
    if (arg1 != NULL) {
        *arg1 = 0;
        if (arg0 != NULL) {
            var_v1 = 0;
            *arg1 = M2C_FIELD(arg0, unsigned short *, 0x1CC);
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_get_buffer_stats);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_get_peer_buffer_stats);

int rt_p2p_set_send_aggregation(int *arg0) {
    int var_v0;

    var_v0 = 2;
    if (arg0 != NULL) {
        var_v0 = rt_udp_set_aggregation_interval(*arg0);
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_host);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_incoming_peer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_connect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_disconnect);

int rt_p2p_tick(int arg0) {
    return (arg0 != 0) ? 0 : 2;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_update);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_send);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_send_list);

int rt_p2p_isend_list();
int rt_p2p_receive_broadcasts(char *p, int flag)
{
    int ret;
    int r;
    RtP2PVec vec;
    struct { unsigned short type; unsigned char flag; } msg;

    msg.type = rt_p2p_pack_type(2, 4);
    ret = 2;
    msg.flag = flag;
    if (p != NULL) {
        *(int *)(p + 0x1B8) = flag;
        vec.e[0].buf = &msg;
        vec.e[0].len = 4;
        vec.total = 4;
        vec.n = 1;
        r = rt_p2p_isend_list(p, 0, 0, 0xF000, &vec);
        ret = (r != 0 && r != 0xD2F3) ? r : 0;
    }
    return ret;
}

int rt_p2p_send_to(void *p2p, RtP2PAddr addr, void *data, int len)
{
    int ret = 2;

    if (p2p != NULL)
        ret = rt_udp_send_unconnected(M2C_FIELD(p2p, int *, 0), addr, data, len);
    return ret;
}

int rt_p2p_get_max_peers(void *arg0, int *arg1) {
    int var_v1;

    var_v1 = 2;
    if (arg1 != NULL) {
        *arg1 = 0;
        if (arg0 != NULL) {
            var_v1 = 0;
            *arg1 = (int) M2C_FIELD(arg0, unsigned short *, 0x19C);
        }
    }
    return var_v1;
}

int rt_p2p_set_max_peers(void *p2p, int n)
{
    int ret = 2;

    if (p2p != NULL) {
        M2C_FIELD(p2p, unsigned short *, 0x19C) = n;
        ret = 0;
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_set_overlay_type);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_join_overlay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_quit_overlay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_quit_all_overlays);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_ignore_peer_in_overlay);

int rt_p2p_get_overlay_peer_count(void *arg0, int arg1, int *arg2) {
    int temp_v1;
    int var_a3;
    unsigned int temp_a1;

    temp_a1 = arg1 & 0xFF;
    var_a3 = 2;
    if (arg2 != NULL) {
        *arg2 = 0;
        if ((arg0 != NULL) && (temp_a1 < (unsigned int) M2C_FIELD(arg0, unsigned int *, 0x1D8))) {
            temp_v1 = M2C_FIELD(arg0, int *, 0x188);
            var_a3 = 3;
            if (temp_v1 != 0) {
                var_a3 = 0;
                *arg2 = M2C_FIELD(((temp_a1 * 0x18) + temp_v1), int *, 0x10);
            }
        }
    }
    return var_a3;
}

int rt_p2p_is_peer_in_overlay(char *p, unsigned char ov, unsigned short peer, int *out)
{
    char *tab;
    if (out == NULL) return 2;
    *out = 0;
    if (p == NULL) return 2;
    if (ov >= *(unsigned int *)(p + 0x1D8)) return 2;
    tab = *(char **)(p + 0x188);
    if (tab == NULL) return 3;
    if (peer >= *(unsigned short *)(p + 0x19C)) return 2;
    if ((*(int **)(tab + ov * 24))[peer] == 0) return 0;
    *out = 1;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_send_overlay);

int rt_p2p_pack_type(int arg0, int arg1) {
    return (arg1 & 0x7FF) | ((arg0 & 0x1F) << 0xB);
}

void rt_msg_get_u2byte();
void rt_p2p_unpack_type(void *msg, int *type, unsigned short *len)
{
    unsigned short v;
    rt_msg_get_u2byte(msg, &v);
    *type = v >> 11;
    *len = v & 0x7FF;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid1);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid2);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid3);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid5);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid6);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid7);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid9);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid10);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid11);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid12);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid13);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid14);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid15);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid16);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid17);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid19);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid21);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid22);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid23);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid24);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid25);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid26);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid27);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid28);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid29);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid30);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid31);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", grid32);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rcsid_10C87C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", headerfile_rcsid_10C8DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", header_rcsid_10C93C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_udp_event_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_udp_data_cb);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_send_peer_info);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_handle_connect_event);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_handle_connected_event);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_handle_timeout_event);

static int rt_p2p_handle_closed_event(void *p2p, int conn, void *data)
{
    return rt_p2p_generic_disconnect(p2p, conn, 3, data);
}

static int rt_p2p_handle_reset_event(void *p2p, int conn, void *data)
{
    return rt_p2p_generic_disconnect(p2p, conn, 3, data);
}

static int rt_p2p_handle_error_event(void *p2p, int conn, void *data)
{
    return rt_p2p_generic_disconnect(p2p, conn, 3, data);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_get_peer_by_address);

int rt_p2p_get_peer_by_connection(char *p, int conn)
{
    unsigned short i;
    for (i = 0; i < *(unsigned short *)(p + 0x19C); i++) {
        if (conn == (*(RtP2PPeer **)(p + 0x184))[i].conn1) return i;
        if (conn == (*(RtP2PPeer **)(p + 0x184))[i].conn2) return i;
    }
    return 0xFFFE;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_get_my_peer_status);

unsigned short rt_p2p_find_free_peer_index(char *p)
{
    unsigned short i;
    int *peer;

    if (p == NULL) return 0xFFFE;
    i = 0;
    peer = *(int **)(p + 0x184);
    for (; i < *(unsigned short *)(p + 0x19C); i++, peer += 20) {
        if (*peer == 0) {
            rt_p2p_reset_peer_info(p, peer);
            return i;
        }
    }
    return 0xFFFE;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_fill_new_peer_struct);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_process_internal_message);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_process_new_peer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_process_coordinate_data);

void rt_p2p_get_my_peer_status(char *p, int *status, short *idx);
int rt_p2p_process_connect_complete(char *p, unsigned short idx)
{
    short me;
    int st;

    me = -2;
    st = 0;
    rt_p2p_get_my_peer_status(p, &st, &me);
    (*(unsigned short *)(p + 0x19E))++;
    if (st == 8 || st == 9)
        (*(void (**)(int, int, int))(p + 0x1FC))(idx, 0, *(int *)(p + 0x218));
    else
        *(int *)(idx * 80 + *(int *)(p + 0x184) + 0x1C) = 1;
    return 0;
}

int rt_p2p_process_broadcast_update(char *p, unsigned short idx, void *msg)
{
    struct { unsigned char a, b, c, d; } m;
    memcpy(&m, msg, 4);
    *(int *)(*(char **)(p + 0x184) + idx * 80 + 0x14) = m.c;
    (*(RtP2pBcCb *)(p + 0x204))(idx, m.c, *(int *)(p + 0x218));
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_process_connection_detached);

typedef struct { unsigned char a, b; unsigned short idx; unsigned short id; } RtP2PBcDisc;
int rt_p2p_process_broadcast_disconnect(char *p, int conn, void *msg)
{
    RtP2PBcDisc m;
    RtP2PPeer *peer;

    memcpy(&m, msg, 6);
    peer = (RtP2PPeer *)(m.idx * sizeof(RtP2PPeer) + *(int *)(p + 0x184));
    if (*(unsigned short *)((char *)peer + 0x34) == m.id) {
        if (peer->conn1 != 0)
            rt_p2p_generic_disconnect(p, peer->conn1, 1, 0xD2F3);
        else if (peer->conn2 != 0)
            rt_p2p_generic_disconnect(p, peer->conn2, 1, 0xD2F3);
    }
    return 0;
}

int rt_p2p_process_local_broadcast_test(void *arg0, int arg1) {
    void *temp_a0;

    temp_a0 = ((arg1 & 0xFFFF) * 0x50) + M2C_FIELD(arg0, int *, 0x184);
    if (M2C_FIELD(temp_a0, int *, 0x18) != 1) {
        M2C_FIELD(temp_a0, int *, 0x18) = 1;
    }
    return 0;
}

int rt_p2p_process_overlay_type(char *p, int peer, void *msg)
{
    RtP2pOvl m;

    memcpy(&m, msg, 8);
    if (*(char **)(p + 0x188) == NULL) return 0;
    *(int *)(*(char **)(p + 0x188) + m.idx * 24 + 0x14) = m.v;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_process_join_overlay);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_process_join_response);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_process_quit_overlay);

typedef struct { unsigned char a, b, ov, c; unsigned short peer, d; int v; } RtP2pIgn;
int rt_p2p_process_ignore_update(char *p, int peer, void *msg)
{
    RtP2pIgn m;

    memcpy(&m, msg, 12);
    if (*(char **)(p + 0x188) == NULL) return 0;
    *(int *)((*(char ***)(*(char **)(p + 0x188) + m.ov * 24))[m.peer] + 0x48) = m.v;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_process_grid_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_complete_connection);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_send_local_broadcast_tests);

int rt_udp_send(int, int, int, int);
int rt_p2p_isend(int *p, int *peer, unsigned short a, int b)
{
    int ret = 0xD2F3;
    if (peer[1] != 0 && peer[3] != 0) ret = rt_udp_send(p[0], peer[1], a, b);
    else if (peer[2] != 0 && peer[4] != 0) ret = rt_udp_send(p[0], peer[2], a, b);
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_isend_list);

int rt_p2p_send_my_broadcast_flag(char *p, unsigned short idx)
{
    struct { unsigned short type; unsigned char flag; } msg;
    RtP2PVec vec;

    if (idx >= *(unsigned short *)(p + 0x19C)) return 0xD4E6;
    msg.type = rt_p2p_pack_type(2, 4);
    msg.flag = *(int *)(p + 0x1B8);
    vec.e[0].buf = &msg;
    vec.e[0].len = 4;
    vec.total = 4;
    vec.n = 1;
    return rt_p2p_isend((int *)p, (int *)(*(char **)(p + 0x184) + idx * 80), 0xF000, (int)&vec);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_generic_disconnect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_determine_new_host);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_send_connection_detached_to_host);

int rt_p2p_send_broadcast_disconnect(char *p, unsigned short idx)
{
    RtP2PVec vec;
    struct { unsigned short type; unsigned short idx; unsigned short id; } msg;

    msg.type = rt_p2p_pack_type(3, 6);
    msg.idx = idx;
    msg.id = *(unsigned short *)(*(char **)(p + 0x184) + idx * 80 + 0x34);
    vec.e[0].buf = &msg;
    vec.e[0].len = 6;
    vec.total = 6;
    vec.n = 1;
    rt_p2p_isend_list(p, 0, 0, 0xF000, &vec);
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_notify_peers_disconnect_forwarding);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_notify_peers_disconnect);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_save_backlog_connection);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_find_backlog_connection);

int rt_time_elapsed();
int rt_udp_disconnect();
int rt_p2p_timeout_backlog_connection(int *p)
{
    unsigned int i;
    unsigned int el;
    RtP2PBacklog *b = (RtP2PBacklog *)p;

    for (i = 0; i < 32; i++, b++) {
        if (b->conn != 0) {
            rt_time_elapsed(&b->time, &el);
            if (el >= 7501) {
                rt_udp_disconnect(*p, b->conn);
                b->conn = 0;
            }
        }
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_generate_grid_fill_empties);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_generate_grid_add_peer);

int rt_p2p_generate_grid_add_peer();
int rt_p2p_generate_grid(char *p, unsigned int n)
{
    unsigned int i;
    int ret;

    memset(*(void **)(p + 0x198), -1, *(unsigned short *)(p + 0x19C) * 3);
    for (i = 0; i < n; i++) {
        ret = rt_p2p_generate_grid_add_peer(p, (signed char)i);
        if (ret != 0) return ret;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_get_peer_grid_edges);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_update_grid);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_send_token_msg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_send_token_list_msg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_process_token_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_token_event_notify);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_timebase_query);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_process_timebase_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_process_game_session_key);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_get_latency_info);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_set_host_invactivity_timeout_session);

int rt_udp_get_inactivity_timeout();
int rt_udp_set_connection_inactivity_timeout();
int rt_p2p_set_host_inactivity_timeout_connection(char *p, int conn)
{
    unsigned int t;
    if (*(int *)(p + 0x1E4) != 0) {
        rt_udp_get_inactivity_timeout(&t);
        t >>= 2;
        rt_udp_set_connection_inactivity_timeout(conn, t);
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_set_peer_update_bit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_send_new_peer_info);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_send_peer_updates);

void *memset(void *s, int c, unsigned int n);
void rt_p2p_reset_peer_info(void *arg0, void *arg1) {
    if (arg1 != NULL) {
        M2C_FIELD(arg1, int *, 0) = 0;
        M2C_FIELD(arg1, int *, 4) = 0;
        M2C_FIELD(arg1, int *, 8) = 0;
        M2C_FIELD(arg1, int *, 0xC) = 0;
        M2C_FIELD(arg1, int *, 0x10) = 0;
        M2C_FIELD(arg1, int *, 0x14) = 0;
        M2C_FIELD(arg1, int *, 0x18) = 0;
        M2C_FIELD(arg1, int *, 0x1C) = 0;
        M2C_FIELD(arg1, int *, 0x20) = 0;
        M2C_FIELD(arg1, short *, 0x24) = 0;
        rt_comm_linkaddress_setnull(arg1 + 0x28);
        M2C_FIELD(arg1, short *, 0x34) = 0;
        M2C_FIELD(arg1, short *, 0x36) = 0;
        M2C_FIELD(arg1, short *, 0x38) = 0;
        M2C_FIELD(arg1, short *, 0x3A) = 0;
        M2C_FIELD(arg1, short *, 0x3C) = 0;
        M2C_FIELD(arg1, short *, 0x3E) = 0;
        M2C_FIELD(arg1, short *, 0x40) = 0;
        M2C_FIELD(arg1, short *, 0x42) = 0;
        M2C_FIELD(arg1, short *, 0x44) = 0;
        M2C_FIELD(arg1, int *, 0x30) = 0;
        M2C_FIELD(arg1, int *, 0x48) = 0;
        memset(M2C_FIELD(arg1, void **, 0x4C), 0, (((unsigned int) (M2C_FIELD(arg0, unsigned short *, 0x19C) + 0x1F) >> 5) * 4) + 4);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_process_peer_host_query);
