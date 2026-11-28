#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int NetUsePeerToPeer(void *);
int NetUseUDP(void);
int rt_comm_linkaddress_isequal();
void rt_comm_linkaddress_setnull(void *);
int rt_msg_get_u2byte(unsigned char *, unsigned short *);
int rt_p2p_determine_new_host(char *, unsigned short *);
unsigned short rt_p2p_find_free_peer_index(char *);
int rt_p2p_generate_grid(char *, unsigned int);
int rt_p2p_get_current_address_type(char *, unsigned short, int *);
int rt_p2p_get_host_index(void *, unsigned short *);
int rt_p2p_get_latency_info(char *, unsigned short, void *);
int rt_p2p_get_max_peers(void *, int *);
int rt_p2p_get_my_address(int *, int, void *, void *);
int rt_p2p_get_my_peer_index(void *, unsigned short *);
int rt_p2p_get_overlay_peer_count(void *, int, int *);
int rt_p2p_get_peer_by_connection(char *, int);
int rt_p2p_get_virtual_port(void *, unsigned short *);
void rt_p2p_handle_connected_event(char *, int);
int rt_p2p_ignore_peer_in_overlay(char *, unsigned char, unsigned short, unsigned int);
int rt_p2p_is_peer_in_overlay(char *, unsigned char, unsigned short, int *);
int rt_p2p_isend(int *, int *, unsigned short, int);
int rt_p2p_join_overlay(char *, unsigned char);
int rt_p2p_notify_peers_disconnect_forwarding(int, char *, int, unsigned short, unsigned short);
int rt_p2p_pack_type(int, int);
int rt_p2p_process_broadcast_disconnect(char *, int, void *);
int rt_p2p_process_broadcast_update(char *, unsigned short, void *);
int rt_p2p_process_connect_complete(char *, unsigned short);
int rt_p2p_process_connection_detached(char *, int, void *);
int rt_p2p_process_coordinate_data(char *, unsigned short);
int rt_p2p_process_ignore_update(char *, int, void *);
int rt_p2p_process_local_broadcast_test(void *, int);
int rt_p2p_process_overlay_type(char *, int, void *);
int rt_p2p_quit_overlay(char *, unsigned char);
int rt_p2p_receive_broadcasts(char *, int);
void rt_p2p_reset_peer_info(void *, void *);
void rt_p2p_resolve_interface(void);
int rt_p2p_send_broadcast_disconnect(char *, unsigned short);
int rt_p2p_send_connection_detached_to_host(char *, unsigned short, unsigned short);
int rt_p2p_send_local_broadcast_tests(char *);
int rt_p2p_send_my_broadcast_flag(char *, unsigned short);
int rt_p2p_send_to();
int rt_p2p_send_token_msg(char *, int, int, int, unsigned short);
int rt_p2p_set_host_inactivity_timeout_connection(char *, int);
int rt_p2p_set_host_invactivity_timeout_session(char *);
int rt_p2p_set_max_peers(void *, int);
int rt_p2p_set_overlay_type(char *, unsigned char, unsigned int);
int rt_p2p_set_send_aggregation(int *);
int rt_p2p_tick(int);
int rt_p2p_timeout_backlog_connection(int *);
void rt_p2p_unpack_type(void *, int *, unsigned short *);
int rt_p2p_update(char *);
int rt_time_elapsed(void *, unsigned int *);
int rt_time_start(void *);
int rt_token_build_token_msg(char *, unsigned int, unsigned int *, unsigned char, unsigned short, int);
void rt_udp_disconnect(char *, int *);
int rt_udp_get_inactivity_timeout(int *);
int rt_udp_get_latency_info(int *, int *);
int rt_udp_get_local_address(void *, void *, int *);
int rt_udp_set_connection_inactivity_timeout(void *, int);
int rt_p2p_generic_disconnect();
int rt_udp_send_unconnected();

int rt_udp_set_aggregation_interval();

extern void *gUDPInterfacePtr;
typedef struct { int a; int conn1; int conn2; int pad[17]; } RtP2PPeer;
typedef struct { int a; int conn; int time; } RtP2PBacklog;
typedef struct { struct { void *buf; int len; } e[8]; int total; int n; } RtP2PVec;
void rt_p2p_get_my_peer_status(char *p, int *status, short *idx);

typedef struct { unsigned char a, b; unsigned short from; unsigned short idx; } RtP2PDetach;
typedef struct { void **peers; int x[3]; int count; int type; } RtP2POvlTab;
extern void *gCryptInterfacePtr;
extern void *gP2PInterface[35];
extern void **gP2PInterfacePtr;
int rt_udp_get_address();
int rt_p2p_create(); int rt_p2p_destroy(); int rt_p2p_get_peer_address(int *, unsigned short, int, int *, int *);

int rt_p2p_get_buffer_stats(); int rt_p2p_get_peer_buffer_stats();
int rt_p2p_host(); int rt_p2p_incoming_peer(); int rt_p2p_connect(); void rt_p2p_disconnect();
int rt_p2p_send(char *, unsigned short, unsigned short, RtP2PVec *); int rt_p2p_send_list();
typedef struct { unsigned int ip; unsigned int port; } RtP2PAddr;

int rt_p2p_quit_all_overlays();

int rt_p2p_send_overlay(); int rt_p2p_send_token_list_msg(char *, int, unsigned char, int, int, int, int, unsigned short); int rt_p2p_token_event_notify(char *, unsigned short, unsigned short, void *, int, int, int);

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

int rt_udp_get_resolved_address();

int rt_p2p_get_my_address(int *p, int type, void *a, void *b)
{
    int r;

    if (p == NULL) return 2;
    if (type == 0) {
        r = rt_udp_get_local_address(*p, a, b);
        if (r != 0) return r;
    } else if (type == 1) {
        r = rt_udp_get_resolved_address(*p, a, b);
        if (r != 0) return r;
    } else
        return 2;
    return 0;
}

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

int rt_p2p_host(char *p, unsigned short *idx)
{
    short me;
    int st;
    unsigned char key[64];
    RtP2PPeer *peer;

    st = 0;
    me = -2;
    if (idx == NULL) return 2;
    *idx = 0xFFFE;
    if (p == NULL) return 2;
    rt_p2p_get_my_peer_status(p, &st, &me);
    if (st != 0) return 0xD4E7;
    peer = *(RtP2PPeer **)(p + 0x184);
    *(unsigned short *)((char *)peer + 0x34) = *(unsigned short *)(p + 0x1E0);
    *idx = 0;
    peer->conn1 = 0;
    peer->conn2 = 0;
    peer->a = 9;
    *(unsigned short *)(p + 0x1A4) = 0;
    *(unsigned short *)(p + 0x1A2) = 0;
    if (gCryptInterfacePtr != NULL) {
        (*(void (**)(void *))((char *)gCryptInterfacePtr + 0x54))(key);
        (*(void (**)(int, int, void *))((char *)gCryptInterfacePtr + 0x24))(-1, 0, key);
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_incoming_peer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_connect);

void rt_p2p_disconnect(char *p)
{
    unsigned short i;
    RtP2PPeer *peer;

    if (p == NULL) return;
    rt_p2p_quit_all_overlays(p);
    peer = *(RtP2PPeer **)(p + 0x184);
    for (i = 0; i < *(unsigned short *)(p + 0x19C); i++, peer++) {
        if (peer->a == 0) continue;
        if (peer->conn1 != 0) rt_udp_disconnect(*(char **)p, (int *)peer->conn1);
        if (peer->conn2 != 0) rt_udp_disconnect(*(char **)p, (int *)peer->conn2);
        rt_p2p_reset_peer_info(p, peer);
        peer->conn1 = 0;
        peer->conn2 = 0;
    }
    for (i = 0; i < 32; i++) {
        int *b = (int *)(i * 12 + (int)p);
        if (b[1] != 0) {
            rt_udp_disconnect(*(char **)p, (int *)b[1]);
            b[1] = 0;
        }
    }
    *(short *)(p + 0x1A0) = 0;
    *(short *)(p + 0x1A2) = -2;
    *(short *)(p + 0x1A4) = -2;
    *(unsigned short *)(p + 0x1E0) = 1;
}

int rt_p2p_tick(int arg0) {
    return (arg0 != 0) ? 0 : 2;
}

int rt_p2p_complete_connection();

int rt_p2p_send_peer_updates();
void rt_timebase_is_query_ready();
int rt_p2p_timebase_query();
int rt_p2p_update(char *p)
{
    int ret;
    int ready;

    if (p == NULL) return 2;
    if ((ret = rt_p2p_complete_connection(p)) != 0) return ret;
    if ((ret = rt_p2p_send_local_broadcast_tests(p)) != 0) return ret;
    if ((ret = rt_p2p_timeout_backlog_connection((int *)p)) != 0) return ret;
    if ((ret = rt_p2p_send_peer_updates(p)) != 0) return ret;
    if (*(unsigned short *)(p + 0x1A2) != 0xFFFE) {
        if (*(unsigned short *)(p + 0x1A2) != *(unsigned short *)(p + 0x1A4)) {
            ready = 0;
            rt_timebase_is_query_ready(&ready);
            if (ready != 0)
                rt_p2p_timebase_query(p);
        }
    }
    return 0;
}

int rt_p2p_send(char *p, unsigned short idx, unsigned short flags, RtP2PVec *v)
{
    unsigned short hdr;
    int ret;
    unsigned short i;
    RtP2PPeer *peer;
    unsigned int n = 0;
    int bc = 0;

    if (p == NULL) return 2;
    flags |= 0x8000;
    hdr = rt_p2p_pack_type(10, (unsigned short)(v->total + 2));
    if (v->n < 8) {
        v->e[v->n].buf = &hdr;
        v->e[v->n].len = 2;
        v->total += 2;
        v->n++;
    }
    if (idx != 0xFFFF) {
        if (idx >= *(unsigned short *)(p + 0x19C)) return 0xD4E6;
        peer = (RtP2PPeer *)*(int *)(p + 0x184) + idx;
        ret = 0xD2F3;
        if ((unsigned int)(peer->a - 3) < 2)
            ret = rt_p2p_isend((int *)p, (int *)peer, flags, (int)v);
    } else {
        i = 0;
        peer = *(RtP2PPeer **)(p + 0x184);
        for (; i < *(unsigned short *)(p + 0x19C); i++, peer++) {
            if (peer->pad[2] == 0) continue;
            if (peer->pad[3] != 0 && !(flags & 0x4000) && *(int *)(p + 0x1BC) != 0)
                bc = 1;
            else if ((unsigned int)(peer->a - 3) < 2)
                (*(RtP2PPeer ***)(p + 0x190))[n++] = peer;
        }
        ret = rt_p2p_isend_list(p, *(int ***)(p + 0x190), n, flags, v);
        if (ret != 0 && ret != 0xD2F3) return ret;
        ret = 0;
        if (bc) {
            ret = rt_udp_broadcast(*(int *)p, flags, v);
            if (ret != 0) return ret;
        }
    }
    v->n--;
    v->total -= v->e[v->n].len;
    return ret;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_send_list);

int rt_p2p_isend_list(void *, int **, unsigned int, unsigned short, void *);
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

int rt_p2p_set_overlay_type(char *p, unsigned char ov, unsigned int type)
{
    int ret;
    short me;
    int st;
    struct { unsigned short t; unsigned char ov; unsigned char pad; unsigned int type; } msg;
    RtP2PVec vec;

    me = -2;
    st = 0;
    if (p == NULL) return 2;
    if (ov >= *(unsigned int *)(p + 0x1D8)) return 2;
    if (*(char **)(p + 0x188) == NULL) return 3;
    rt_p2p_get_my_peer_status(p, &st, &me);
    if (st != 9) return 0xD4ED;
    ret = 2;
    if (type < 2) {
        *(unsigned int *)(*(char **)(p + 0x188) + ov * 24 + 0x14) = type;
        msg.t = rt_p2p_pack_type(5, 8);
        vec.e[0].buf = &msg;
        msg.ov = ov;
        msg.type = type;
        vec.e[0].len = 8;
        vec.total = 8;
        vec.n = 1;
        ret = rt_p2p_isend_list(p, 0, 0, 0xF000, &vec);
    }
    return ret;
}

int rt_p2p_join_overlay(char *p, unsigned char ov)
{
    short me;
    struct { unsigned short t; unsigned char ov; unsigned char pad; } msg;
    RtP2PVec vec;
    int st;
    RtP2POvlTab *o;
    unsigned int i;
    int ret, r;

    me = -2;
    st = 0;
    if (p == NULL) return 2;
    if (ov >= *(unsigned int *)(p + 0x1D8)) return 2;
    if (*(char **)(p + 0x188) == NULL) return 3;
    rt_p2p_get_my_peer_status(p, &st, &me);
    if ((unsigned short)me >= *(unsigned short *)(p + 0x19C) || (st != 8 && st != 9)) {
        *(unsigned char *)(p + 0x18C) = ov;
    } else {
    o = (RtP2POvlTab *)(*(char **)(p + 0x188) + ov * 24);
    for (i = 0; i < *(unsigned short *)(p + 0x19C); i++)
        o->peers[i] = NULL;
    for (i = 0; i < 3; i++)
        o->x[i] = 0;
    o->peers[(unsigned short)me] = (RtP2PPeer *)*(int *)(p + 0x184) + (unsigned short)me;
    o->count = 1;
    msg.t = rt_p2p_pack_type(6, 4);
    msg.ov = ov;
    vec.e[0].buf = &msg;
    vec.e[0].len = 4;
    vec.total = 4;
    vec.n = 1;
    r = rt_p2p_isend_list(p, 0, 0, 0xF000, &vec);
    if (r != 0 && r != 0xD2F3) return r;
    }
    return 0;
}

int rt_p2p_quit_overlay(char *p, unsigned char ov)
{
    short me;
    struct { unsigned short t; unsigned char ov; unsigned char pad; } msg;
    RtP2PVec vec;
    int st;
    RtP2POvlTab *o;
    unsigned int i;
    int r;

    me = -2;
    st = 0;
    if (p == NULL) return 2;
    if (ov >= *(unsigned int *)(p + 0x1D8)) return 2;
    if (*(char **)(p + 0x188) == NULL) return 3;
    o = (RtP2POvlTab *)(*(char **)(p + 0x188) + ov * 24);
    rt_p2p_get_my_peer_status(p, &st, &me);
    if ((unsigned short)me < *(unsigned short *)(p + 0x19C)) {
        if (*(unsigned char *)(p + 0x18C) == ov)
            *(unsigned char *)(p + 0x18C) = 0xFF;
        msg.t = rt_p2p_pack_type(8, 4);
        vec.e[0].buf = &msg;
        vec.e[0].len = 4;
        vec.total = 4;
        msg.ov = ov;
        vec.n = 1;
        r = rt_p2p_isend_list(p, 0, 0, 0xF000, &vec);
        if (r != 0 && r != 0xD2F3) return r;
    }
    for (i = 0; i < *(unsigned short *)(p + 0x19C); i++)
        o->peers[i] = NULL;
    o->x[0] = 0;
    o->x[1] = 0;
    o->x[2] = 0;
    o->type = *(int *)(p + 0x1DC);
    o->count = 0;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_quit_all_overlays);

int rt_p2p_ignore_peer_in_overlay(char *p, unsigned char ov, unsigned short peer, unsigned int mode)
{
    struct { unsigned short t; unsigned char ov; unsigned char pad; unsigned short peer; unsigned short pad2; unsigned int mode; } msg;
    RtP2PVec vec;
    int ret = 0;
    int r;

    if (p == NULL) return 2;
    if (ov >= *(unsigned int *)(p + 0x1D8)) return 2;
    if (*(char **)(p + 0x188) == NULL) return 3;
    if (peer >= *(unsigned short *)(p + 0x19C)) return 2;
    if (mode < 4) {
        *(unsigned int *)((char *)((RtP2POvlTab *)(*(char **)(p + 0x188) + ov * 24))->peers[peer] + 0x48) = mode;
        msg.t = rt_p2p_pack_type(9, 0xC);
        vec.e[0].buf = &msg;
        vec.e[0].len = 0xC;
        msg.ov = ov;
        msg.peer = peer;
        msg.mode = mode;
        vec.total = 0xC;
        vec.n = 1;
        r = rt_p2p_isend_list(p, 0, 0, 0xF000, &vec);
        if (r != 0) return r;
    } else
        ret = 2;
    return ret;
}

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

int rt_p2p_save_backlog_connection(char *p, int conn); int rt_udp_get_virtual_port(); int rt_udp_set_peer_id(); int rt_udp_accept(); int rt_udp_set_buffer_size(); int rt_udp_deny();
void rt_p2p_handle_connect_event(char *p, int conn)
{
    short me = -2;
    int st = 0;

    rt_p2p_get_my_peer_status(p, &st, &me);
    if (st != 9 || *(int *)(p + 0x1C8) == 0) {
        rt_p2p_save_backlog_connection(p, conn);
        return;
    }
    {
        unsigned short idx = rt_p2p_find_free_peer_index(p);
        RtP2PPeer *peer;
        if (idx == 0xFFFE) {
            rt_udp_deny(*(int *)p, conn);
            return;
        }
        peer = (RtP2PPeer *)(*(char **)(p + 0x184) + idx * 80);
        rt_p2p_reset_peer_info(p, peer);
        peer->a = 2;
        peer->conn1 = conn;
        rt_udp_get_virtual_port(conn, (char *)peer + 0x24);
        *(short *)((char *)peer + 0x34) = 0;
        rt_p2p_set_host_inactivity_timeout_connection(p, conn);
        rt_udp_set_peer_id(conn, idx);
        rt_udp_accept(*(int *)p, conn);
        rt_udp_set_buffer_size(*(int *)p, conn, 0, *(int *)(p + 0x1D0));
        rt_udp_set_buffer_size(*(int *)p, conn, 1, *(int *)(p + 0x1D4));
    }
}

int rt_p2p_send_peer_info();

void rt_p2p_handle_connected_event(char *p, int conn)
{
    unsigned int idx;
    RtP2PPeer *peer;

    idx = rt_p2p_get_peer_by_connection(p, conn);
    if (idx < *(unsigned short *)(p + 0x19C)) {
        peer = (RtP2PPeer *)(*(int *)(p + 0x184) + idx * sizeof(RtP2PPeer));
        rt_time_start(p + 0x1AC);
        *(int *)(p + 0x1A8) = 0;
        if ((void *)conn == ((void **)peer)[1])
            peer->pad[0] = 1;
        else if ((void *)conn == ((void **)peer)[2])
            peer->pad[1] = 1;
        rt_p2p_send_peer_info(p, peer, idx);
    } else
        rt_udp_disconnect(*(int *)p, conn);
}

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

void rt_p2p_get_my_peer_status(char *p, int *status, short *idx)
{
    int i;
    int st = 0;
    RtP2PPeer *peer;

    *idx = -2;
    *status = 0;
    for (i = *(unsigned short *)(p + 0x19C); i-- > 0; ) {
        st = (*(RtP2PPeer **)(p + 0x184))[i].a;
        if (st >= 7 && st <= 9) break;
        if (st == 1) { *status = 7; return; }
    }
    if (i >= 0) {
        *status = st;
        *idx = i;
    }
}

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

int rt_p2p_process_coordinate_data(char *p, unsigned short idx)
{
    short me;
    int st;
    unsigned int i;

    me = -2;
    st = 0;
    rt_p2p_get_my_peer_status(p, &st, &me);
    if (st == 8 || st == 9) {
        (*(RtP2PPeer **)(p + 0x184))[idx].pad[5] = 1;
        if (--*(unsigned short *)(p + 0x1A0) == 0) {
            (*(void (**)(int, int, int))(p + 0x214))(1, 1, *(int *)(p + 0x218));
            *(int *)(p + 0x1C4) = 1;
            for (i = 0; i < *(unsigned short *)(p + 0x19C); i++)
                (*(RtP2PPeer **)(p + 0x184))[i].pad[5] = 0;
        }
    }
    return 0;
}

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

int rt_p2p_process_connection_detached(char *p, int conn, void *msg)
{
    RtP2PDetach m;
    RtP2PPeer *peer;

    if (*(unsigned short *)(p + 0x1A4) != *(unsigned short *)(p + 0x1A2)) return 0;
    memcpy(&m, msg, 6);
    peer = (RtP2PPeer *)(m.from * sizeof(RtP2PPeer) + *(int *)(p + 0x184));
    if (peer->conn1 != 0 || peer->conn2 != 0) {
        peer = (RtP2PPeer *)(m.idx * sizeof(RtP2PPeer) + *(int *)(p + 0x184));
        if (peer->conn1 != 0)
            rt_p2p_generic_disconnect(p, peer->conn1, 1, 0xD2F3);
        else if (peer->conn2 != 0)
            rt_p2p_generic_disconnect(p, peer->conn2, 1, 0xD2F3);
    }
    return 0;
}

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

int rt_p2p_update_grid(char *p, RtP2POvlTab *o, unsigned short me);
int rt_p2p_process_join_overlay(char *p, unsigned short idx, void *msg)
{
    struct { unsigned char a, b, c, d; } m;
    struct { unsigned short type; unsigned char ov; } out;
    RtP2PVec vec;
    RtP2POvlTab *tab, *o;
    unsigned short me;

    if (p == NULL) return 2;
    me = *(unsigned short *)(p + 0x1A4);
    if (me >= *(unsigned short *)(p + 0x19C)) return 0;
    tab = *(RtP2POvlTab **)(p + 0x188);
    memcpy(&m, msg, 4);
    if (tab != NULL) {
    o = (RtP2POvlTab *)(m.c * 24 + (int)tab);
    if (o->peers[me] != NULL) {
    o->peers[idx] = (char *)*(void **)(p + 0x184) + idx * 80;
    o->count++;
    {
        int r = rt_p2p_update_grid(p, o, me);
        if (r != 0) return r;
    }
    out.type = rt_p2p_pack_type(7, 4);
    out.ov = m.c;
    vec.e[0].buf = &out;
    vec.e[0].len = 4;
    vec.total = 4;
    vec.n = 1;
    {
        int r = rt_p2p_isend((int *)p, (int *)(*(char **)(p + 0x184) + idx * 80), 0xF000, (int)&vec);
        if (r != 0) return r;
    }
    }
    }
    return 0;
}

int rt_p2p_process_join_response(char *p, unsigned short idx, void *msg)
{
    struct { unsigned char a, b, c, d; } m;
    RtP2POvlTab *tab, *o;
    unsigned short me;

    if (p == NULL) return 2;
    tab = *(RtP2POvlTab **)(p + 0x188);
    memcpy(&m, msg, 4);
    me = *(unsigned short *)(p + 0x1A4);
    if (tab != NULL) {
    o = (RtP2POvlTab *)(m.c * 24 + (int)tab);
    if (o->peers[me] != NULL && o->peers[idx] == NULL) {
    o->count++;
    o->peers[idx] = (char *)*(void **)(p + 0x184) + idx * 80;
    {
        int r = rt_p2p_update_grid(p, o, me);
        if (r != 0) return r;
    }
    }
    }
    return 0;
}

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

int rt_udp_broadcast();
int rt_p2p_send_local_broadcast_tests(char *p)
{
    RtP2PVec vec;
    unsigned int el;
    struct { unsigned short type; } msg;

    if (*(int *)(p + 0x1BC) != 0 && *(unsigned int *)(p + 0x1A8) < 10) {
        rt_time_elapsed(p + 0x1AC, &el);
        if (el >= 501) {
            msg.type = rt_p2p_pack_type(4, 2);
            vec.e[0].buf = &msg;
            vec.e[0].len = 2;
            vec.total = 2;
            vec.n = 1;
            rt_udp_broadcast(*(int *)p, 0, &vec);
            (*(unsigned int *)(p + 0x1A8))++;
            rt_time_start(p + 0x1AC);
        }
    }
    return 0;
}

int rt_udp_send(int, int, int, int);
int rt_p2p_isend(int *p, int *peer, unsigned short a, int b)
{
    int ret = 0xD2F3;
    if (peer[1] != 0 && peer[3] != 0) ret = rt_udp_send(p[0], peer[1], a, b);
    else if (peer[2] != 0 && peer[4] != 0) ret = rt_udp_send(p[0], peer[2], a, b);
    return ret;
}

int rt_p2p_isend_list(void *pp, int **peers, unsigned int n, unsigned short port, void *vec)
{
    char *p = pp;
    unsigned int i;

    if (peers != NULL) {
        for (i = 0; i < n; i++) {
            if (peers[i][1] != 0 && peers[i][3] != 0)
                (*(int **)(p + 0x194))[i] = peers[i][1];
            else if (peers[i][2] != 0 && peers[i][4] != 0)
                (*(int **)(p + 0x194))[i] = peers[i][2];
            else
                (*(int **)(p + 0x194))[i] = 0;
        }
    } else {
        int *peer = *(int **)(p + 0x184);
        for (i = 0, n = 0; i < *(unsigned short *)(p + 0x19C); i++, peer += 20) {
            if (peer[0] == 3 || peer[0] == 4) {
                if (peer[1] != 0 && peer[3] != 0)
                    (*(int **)(p + 0x194))[n++] = peer[1];
                else if (peer[2] != 0 && peer[4] != 0)
                    (*(int **)(p + 0x194))[n++] = peer[2];
            }
        }
    }
    if (n == 0) return 0xD2F3;
    return rt_udp_send_list(*(int *)p, *(int **)(p + 0x194), n, port, vec);
}

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

int rt_p2p_determine_new_host(char *p, unsigned short *host)
{
    unsigned short i;
    unsigned short min = 0xFFFE;
    unsigned short best = 0xFFFF;
    RtP2PPeer *peers, *peer;

    if (host == NULL) return 2;
    *host = 0xFFFE;
    peer = peers = *(RtP2PPeer **)(p + 0x184);
    for (i = 0; i < *(unsigned short *)(p + 0x19C); i++, peer++) {
        if (peer->a == 3 || peer->a == 8) {
            if (*(unsigned short *)((char *)peer + 0x34) < min) {
                min = *(unsigned short *)((char *)peer + 0x34);
                best = i;
            }
        }
    }
    peer = &peers[best];
    if (peer->a == 3) {
        peer->a = 4;
        *host = best;
    } else if (peer->a == 8) {
        peer->a = 9;
        *host = best;
    }
    *(unsigned short *)(p + 0x1A2) = *host;
    return 0;
}

int rt_p2p_send_connection_detached_to_host(char *p, unsigned short a, unsigned short b)
{
    int ret = 2;
    RtP2PVec vec;
    struct { unsigned short type; unsigned short a; unsigned short b; } msg;

    if (p != NULL) {
        msg.type = rt_p2p_pack_type(13, 6);
        msg.a = a;
        msg.b = b;
        vec.e[0].buf = &msg;
        vec.e[0].len = 6;
        vec.total = 6;
        vec.n = 1;
        ret = rt_p2p_isend((int *)p, (int *)(*(char **)(p + 0x184) + *(unsigned short *)(p + 0x1A2) * 80), 0xF000, (int)&vec);
    }
    return ret;
}

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

int rt_p2p_notify_peers_disconnect_forwarding(int mode, char *p, int st, unsigned short a, unsigned short idx)
{
    RtP2PPeer *ps;
    if (mode == 3 || mode == 1) {
        rt_p2p_send_broadcast_disconnect(p, idx);
    } else if (mode == 2) {
        ps = (RtP2PPeer *)(*(int *)(p + 0x184) + idx * sizeof(RtP2PPeer));
        if (st == 9 || ps->a == 4)
            rt_p2p_send_broadcast_disconnect(p, idx);
        else
            rt_p2p_send_connection_detached_to_host(p, a, idx);
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_notify_peers_disconnect);

int rt_udp_deny();
int rt_p2p_save_backlog_connection(char *p, int conn)
{
    unsigned int i;
    unsigned int slot = 32;
    int *b;

    for (i = 0, b = (int *)(p + 4); i < 32; i++, b += 3) {
        if (*b == conn) return 0;
        if (*b == 0 && slot == 32) slot = i;
    }
    if (slot == 32) {
        rt_udp_deny(*(int *)p, conn);
        return 0;
    }
    *(int *)(p + slot * 12 + 4) = conn;
    rt_time_start(p + slot * 12 + 8);
    return 0;
}

int rt_udp_get_address();
typedef struct { int ip; int port; } RtP2PLinkAddr;
typedef struct { RtP2PLinkAddr addr; int port; } RtP2PFullAddr;
int rt_p2p_find_backlog_connection(int *p, RtP2PFullAddr *addr, int *conn)
{
    unsigned int i;
    int ret;
    RtP2PLinkAddr la;
    int port;
    RtP2PBacklog *b = (RtP2PBacklog *)p;

    for (i = 0; i < 32; i++, b++) {
        if (b->conn != 0) {
            ret = rt_udp_get_address(*p, b->conn, &la, &port);
            if (ret != 0) return ret;
            if (rt_comm_linkaddress_isequal(la, addr->addr) && port == addr->port) {
                *conn = b->conn;
                b->conn = 0;
                return 0;
            }
        }
    }
    return 0;
}

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

int rt_p2p_generate_grid_fill_empties();
int rt_p2p_generate_grid_add_peer(char *p, signed char idx)
{
    signed char cnt;
    signed char nb[2];
    signed char *rows[2];
    int r, j, k, m, n;

    cnt = 0;
    r = rt_p2p_generate_grid_fill_empties(p, idx, &cnt);
    if (r != 0) return r;
    if (cnt < 2 && idx > 0) {
        if (idx % 2 == 0) {
            nb[0] = idx / 2;
            nb[1] = idx / 4;
        } else {
            nb[1] = idx / 5;
            nb[0] = idx / 3;
        }
        rows[0] = *(signed char **)(p + 0x198) + nb[0] * 3;
        rows[1] = *(signed char **)(p + 0x198) + nb[1] * 3;
        n = cnt;
        for (j = 0; n < 2 && j < 2; j++) {
            for (k = 0; k < 3; k++) {
                if (rows[j][k] != -1) {
                    signed char *o = *(signed char **)(p + 0x198) + rows[j][k];
                    for (m = 0; m < 3; m++) {
                        if (o[m] == nb[j]) {
                            o[m] = -1;
                            break;
                        }
                    }
                    rows[j][k] = -1;
                    n++;
                    break;
                }
            }
        }
        r = rt_p2p_generate_grid_fill_empties(p, idx, &cnt);
        if (r != 0) return r;
    }
    return 0;
}

int rt_p2p_generate_grid_add_peer(char *, signed char);
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

extern const signed char grid1[][3];
extern const signed char grid2[][3];
extern const signed char grid3[][3];
extern const signed char grid4[][3];
extern const signed char grid5[][3];
extern const signed char grid6[][3];
extern const signed char grid7[][3];
extern const signed char grid8[][3];
extern const signed char grid9[][3];
extern const signed char grid10[][3];
extern const signed char grid11[][3];
extern const signed char grid12[][3];
extern const signed char grid13[][3];
extern const signed char grid14[][3];
extern const signed char grid15[][3];
extern const signed char grid16[][3];
extern const signed char grid17[][3];
extern const signed char grid18[][3];
extern const signed char grid19[][3];
extern const signed char grid20[][3];
extern const signed char grid21[][3];
extern const signed char grid22[][3];
extern const signed char grid23[][3];
extern const signed char grid24[][3];
extern const signed char grid25[][3];
extern const signed char grid26[][3];
extern const signed char grid27[][3];
extern const signed char grid28[][3];
extern const signed char grid29[][3];
extern const signed char grid30[][3];
extern const signed char grid31[][3];
extern const signed char grid32[][3];
int rt_p2p_generate_grid(char *, unsigned int);
int rt_p2p_get_peer_grid_edges(char *p, unsigned int n, unsigned short idx, signed char **out)
{
    int ret = 0;

    if (n < idx) return 2;
    switch (n) {
    case 0:
        ret = 4;
        break;
    case 1:
        *out = (signed char *)grid1[idx];
        break;
    case 2:
        *out = (signed char *)grid2[idx];
        break;
    case 3:
        *out = (signed char *)grid3[idx];
        break;
    case 4:
        *out = (signed char *)grid4[idx];
        break;
    case 5:
        *out = (signed char *)grid5[idx];
        break;
    case 6:
        *out = (signed char *)grid6[idx];
        break;
    case 7:
        *out = (signed char *)grid7[idx];
        break;
    case 8:
        *out = (signed char *)grid8[idx];
        break;
    case 9:
        *out = (signed char *)grid9[idx];
        break;
    case 10:
        *out = (signed char *)grid10[idx];
        break;
    case 11:
        *out = (signed char *)grid11[idx];
        break;
    case 12:
        *out = (signed char *)grid12[idx];
        break;
    case 13:
        *out = (signed char *)grid13[idx];
        break;
    case 14:
        *out = (signed char *)grid14[idx];
        break;
    case 15:
        *out = (signed char *)grid15[idx];
        break;
    case 16:
        *out = (signed char *)grid16[idx];
        break;
    case 17:
        *out = (signed char *)grid17[idx];
        break;
    case 18:
        *out = (signed char *)grid18[idx];
        break;
    case 19:
        *out = (signed char *)grid19[idx];
        break;
    case 20:
        *out = (signed char *)grid20[idx];
        break;
    case 21:
        *out = (signed char *)grid21[idx];
        break;
    case 22:
        *out = (signed char *)grid22[idx];
        break;
    case 23:
        *out = (signed char *)grid23[idx];
        break;
    case 24:
        *out = (signed char *)grid24[idx];
        break;
    case 25:
        *out = (signed char *)grid25[idx];
        break;
    case 26:
        *out = (signed char *)grid26[idx];
        break;
    case 27:
        *out = (signed char *)grid27[idx];
        break;
    case 28:
        *out = (signed char *)grid28[idx];
        break;
    case 29:
        *out = (signed char *)grid29[idx];
        break;
    case 30:
        *out = (signed char *)grid30[idx];
        break;
    case 31:
        *out = (signed char *)grid31[idx];
        break;
    case 32:
        *out = (signed char *)grid32[idx];
        break;
    default:
        ret = rt_p2p_generate_grid(p, n);
        *out = *(signed char **)(p + 0x198) + idx * 3;
        break;
    }
    return ret;
}

int rt_p2p_get_peer_grid_edges(char *, unsigned int, unsigned short, signed char **);
int rt_p2p_update_grid(char *p, RtP2POvlTab *o, unsigned short me)
{
    signed char *edges;
    unsigned short pos = 0xFFFE;
    unsigned int i, j;
    signed char k;
    int r;

    edges = NULL;
    j = 0;
    for (i = 0; i < *(unsigned short *)(p + 0x19C); i++) {
        if (o->peers[i] != NULL) {
            if (me == i) {
                pos = j;
                break;
            }
            j++;
        }
    }
    r = rt_p2p_get_peer_grid_edges(p, o->count, pos, &edges);
    if (r != 0) return r;
    for (j = 0; j < 3; j++) {
        if (edges[j] == -1) {
            o->x[j] = 0;
            continue;
        }
        k = 0;
        for (i = 0; i < *(unsigned short *)(p + 0x19C); i++) {
            if (o->peers[i] != NULL) {
                if (edges[j] == k) {
                    o->x[j] = (int)o->peers[i];
                    break;
                }
                k++;
            }
        }
    }
    return 0;
}

int rt_msg_set_u2byte();
int rt_p2p_send_token_msg(char *p, int tok, int a, int b, unsigned short idx)
{
    int ret;
    RtP2PVec vec;
    struct { unsigned char b[0x10]; } msg;
    unsigned int len;
    unsigned char *mp = msg.b;

    len = 0;
    if (p == NULL) return 2;
    if (idx >= *(unsigned short *)(p + 0x19C)) return 0xD4E6;
    if (*(unsigned short *)(p + 0x1A4) == idx) return 0xD4E6;
    ret = rt_token_build_token_msg(mp + 2, 5, &len, (unsigned char)b, (unsigned short)tok, a);
    if (ret != 0) return ret;
    rt_msg_set_u2byte(mp, rt_p2p_pack_type(14, (unsigned short)(len + 2)));
    vec.e[0].buf = mp;
    vec.e[0].len = len + 2;
    vec.total = len + 2;
    vec.n = 1;
    return rt_p2p_isend((int *)p, (int *)(*(char **)(p + 0x184) + idx * 80), 0xF000, (int)&vec);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_send_token_list_msg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_process_token_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_token_event_notify);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_udp/src/rt_p2p", rt_p2p_timebase_query);

int rt_timebase_get_localtime();
int rt_msg_set_u4byte();
int rt_msg_get_u4byte();
int rt_timebase_get_globaltime();
void rt_timebase_reset_globaltime();
int rt_timebase_update_globaltime();
int rt_p2p_process_timebase_data(char *p, unsigned short idx, unsigned char *msg)
{
    unsigned char buf[10];
    RtP2PVec vec;
    unsigned int t;
    unsigned int local;
    unsigned char *mp;

    if (p == NULL) return 2;
    rt_msg_get_u4byte(msg + 2, &t);
    if (*(unsigned short *)(p + 0x1A2) != idx) {
        mp = buf + 2;
        rt_msg_set_u4byte(mp, t);
        mp += 4;
        rt_timebase_get_globaltime(&t);
        rt_msg_set_u4byte(mp, t);
        rt_msg_set_u2byte(buf, rt_p2p_pack_type(15, 10));
        vec.e[0].buf = buf;
        vec.e[0].len = 10;
        vec.total = 10;
        vec.n = 1;
        {
            int r = rt_p2p_isend((int *)p, (int *)(*(char **)(p + 0x184) + idx * 80), 0xF000, (int)&vec);
            if (r != 0) return r;
        }
    } else {
        unsigned int sent = t;
        unsigned int now, delay;
        rt_timebase_get_localtime(&local);
        now = local;
        rt_msg_get_u4byte(msg + 6, &t);
        delay = now - sent;
        {unsigned int g = t;
        if (*(int *)(p + 0x1E8) == 0) {
            *(int *)(p + 0x1E8) = 1;
            rt_timebase_reset_globaltime(g);
        } else {
            rt_timebase_update_globaltime(delay, g);
        }}
    }
    return 0;
}

typedef struct { unsigned short type; unsigned char key[0x40]; } RtP2PKeyMsg;
int rt_p2p_process_game_session_key(char *p, unsigned short idx, void *msg)
{
    RtP2PKeyMsg k;

    if (gCryptInterfacePtr == NULL) return 0;
    memcpy(&k, msg, sizeof(k));
    (*(int (**)(int, int, unsigned char *))((char *)gCryptInterfacePtr + 0x24))(-1, 0, k.key);
    return 0;
}

int rt_p2p_get_latency_info(char *p, unsigned short idx, void *info)
{
    int r;
    RtP2PPeer *peer;

    if (p == NULL) return 2;
    peer = (RtP2PPeer *)(idx * sizeof(RtP2PPeer) + *(int *)(p + 0x184));
    if (peer->conn1 != 0) {
        r = rt_udp_get_latency_info(peer->conn1, info);
        if (r != 0) return r;
    } else if (peer->conn2 != 0) {
        r = rt_udp_get_latency_info(peer->conn2, info);
        if (r != 0) return r;
    }
    return 0;
}

int rt_p2p_set_host_invactivity_timeout_session(char *p)
{
    int i = 0;
    unsigned int t;
    RtP2PPeer *peer;

    if (*(int *)(p + 0x1E4) != 0) {
        rt_udp_get_inactivity_timeout(&t);
        peer = *(RtP2PPeer **)(p + 0x184);
        t >>= 2;
        for (; i < *(unsigned short *)(p + 0x19C); i++, peer++) {
            if (peer->conn1 != 0)
                rt_udp_set_connection_inactivity_timeout(peer->conn1, t);
            else if (peer->conn2 != 0)
                rt_udp_set_connection_inactivity_timeout(peer->conn2, t);
        }
    }
    return 0;
}

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
