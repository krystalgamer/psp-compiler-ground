#include "common.h"

/* declarations recovered from DWARF */
struct SceNetEtherAddr;
typedef unsigned char SceUChar8;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
typedef short unsigned int SceUShort16;
struct matching_room_info;
enum matching_room_state {
    MATCHING_ROOM_TOP = 0,
    MATCHING_ROOM_SCAN = 1,
    MATCHING_ROOM_SCANNING = 2,
    MATCHING_ROOM_SCAN_RESULT = 3,
    MATCHING_ROOM_CONNECT_ROOM = 4,
    MATCHING_ROOM_CONNECTING_ROOM = 5,
    MATCHING_ROOM_DISCONNECT_ROOM = 6,
    MATCHING_ROOM_DISCONNECTING_ROOM = 7,
    MATCHING_ROOM_CONNECTING_GAME = 8,
    MATCHING_ROOM_DISCONNECTING = 9,
    MATCHING_ROOM_ERROR_DIALOG = 10,
    MATCHING_ROOM_ROOM_LIST = 11,
    MATCHING_ROOM_NEIGHBORS = 12,
    MATCHING_ROOM_REQUESTING = 13,
    MATCHING_ROOM_CANCELED = 14,
    MATCHING_ROOM_DENIED = 15,
    MATCHING_ROOM_START_GAME = 16,
    MATCHING_ROOM_DISCONNECT = 17,
    MATCHING_ROOM_CHILD_ENTER_ROOM = 18,
    MATCHING_ROOM_CHILD_WAIT = 19,
    MATCHING_ROOM_CREATE_ROOM = 20,
    MATCHING_ROOM_PARENT_WAIT = 21,
    MATCHING_ROOM_PARENT_START_INFORM = 22,
    MATCHING_ROOM_PARENT_INFORM_CONNECT = 23,
    MATCHING_ROOM_PARENT_INFORM_SEND = 24,
    MATCHING_ROOM_PARENT_INFORM_FLUSH = 25,
    MATCHING_ROOM_GAME = 26,
};
struct p2p_hello_opt;
struct SceNetAdhocctlNickname;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceUChar8 data[128];
};
struct p2p_hello_opt_game_param;
struct p2p_hello_opt_game_param { /* size 0x0 */

};
enum game_type {
    GAME_TYPE_CHILD = 0,
    GAME_TYPE_PARENT = 1,
};
struct p2p_hello_opt { /* size 0x8c */
    struct SceNetAdhocctlNickname nickname;
    struct p2p_hello_opt_game_param game_param;
    enum game_type game_type;
    int cur_player_num;
    int req_player_num;
};
typedef long long unsigned int SceULong64;
struct matching_room_info { /* size 0x120 */
    enum matching_room_state state;
    struct p2p_hello_opt hello_opt;
    struct p2p_hello_opt *agreed_hello_opt;
    int requesting_minfo_id;
    int v_cursor_pos;
    int ignore_pad_input;
    struct SceNetEtherAddr local_addr;
    int ctx_id;
    struct SceNetEtherAddr members[16];
    struct SceNetEtherAddr parent_addr;
    int informing_minfo_id;
    SceULong64 ptp_start_time;
};
struct minfo;
struct minfo { /* size 0x98 */
    int status;
    struct SceNetEtherAddr addr;
    struct p2p_hello_opt hello_opt;
};
struct _info;
struct _info { /* size 0x10 */
    int server_flag;
    int client_ready;
    struct SceNetEtherAddr server;
};

extern struct matching_room_info _mrinfo;
extern struct minfo minfo[16];
extern struct _info _info;
extern struct SceNetEtherAddr local_addr;
extern int socket_id;

int game_net_init(void);
int send_recv_game_data(void);


/* SDK prototypes (tools/sdk_protos.h) */
int memcmp(const void *a, const void *b, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int printf(const char *fmt, ...);

void *memcpy(void *d, const void *s, unsigned int n);
int game_net_init(void)
{
	int ret;

	sceNetGetLocalEtherAddr(&local_addr);
	if (_mrinfo.hello_opt.game_type == GAME_TYPE_PARENT) {
		_info.server_flag = 1;
	} else {
		_info.server_flag = 0;
		memcpy(&_info.server, &minfo[_mrinfo.requesting_minfo_id].addr, sizeof(struct SceNetEtherAddr));
	}
	ret = sceNetAdhocPdpCreate(&local_addr, 0x309, 0x400, 0);
	if (ret < 0) {
		printf("sceNetAdhocPdpCreate() failed. ret = 0x%x\n", ret);
		goto error;
	}
	socket_id = ret;
error:
	return ret;
}

int game_net_term(void) {
    int temp_v0;
    int var_v1;

    var_v1 = 0;
    if (socket_id > 0) {
        temp_v0 = sceNetAdhocPdpDelete(socket_id, 0);
        socket_id = 0;
        var_v1 = temp_v0;
    }
    return var_v1;
}

int get_game_data(void *data);
int update_game_data(struct SceNetEtherAddr *addr, void *data);
int check_peer_existence(void);
int send_recv_game_data(void)
{
	struct SceNetEtherAddr addr;
	char buf[0x400];
	SceUShort16 port;
	int len;
	int ret;

	memset(&addr, 0xff, sizeof(addr));
	len = get_game_data(buf);
	ret = sceNetAdhocPdpSend(socket_id, &addr, 0x309, buf, len, 0, 1);
	while (1) {
		len = sizeof(buf);
		ret = sceNetAdhocPdpRecv(socket_id, &addr, &port, buf, &len, 0, 1);
		if (ret == (int)0x80410709)
			break;
		if (memcmp(&local_addr, &addr, 6) == 0)
			continue;
		if (port != 0x309)
			continue;
		update_game_data(&addr, buf);
	}
error:
	check_peer_existence();
	return 0;
}
