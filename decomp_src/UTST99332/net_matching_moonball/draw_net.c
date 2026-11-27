#include "common.h"

/* declarations recovered from DWARF */
struct SceNetAdhocctlScanInfo;
struct SceNetAdhocctlGroupName;
typedef unsigned char SceUChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceUChar8 data[8];
};
struct SceNetAdhocctlBSSId;
struct SceNetAdhocctlBSSId { /* size 0x8 */
    SceUChar8 data[6];
    SceUChar8 padding[2];
};
struct SceNetAdhocctlScanInfo { /* size 0x1c */
    struct SceNetAdhocctlScanInfo *next;
    int channel;
    struct SceNetAdhocctlGroupName group_name;
    struct SceNetAdhocctlBSSId bssid;
    int mode;
};
struct SceNetEtherAddr;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
struct SceNetAdhocctlNickname;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceUChar8 data[128];
};
struct SceNetAdhocctlPeerInfo;
struct SceNetAdhocctlPeerInfo { /* size 0x8c */
    struct SceNetAdhocctlPeerInfo *next;
    struct SceNetAdhocctlNickname nickname;
    struct SceNetEtherAddr mac_addr;
    SceUChar8 padding[2];
};
struct SceNetAdhocMatchingMember;
struct SceNetAdhocMatchingMember { /* size 0xc */
    struct SceNetAdhocMatchingMember *next;
    struct SceNetEtherAddr addr;
    SceUChar8 padding[2];
};
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

extern struct matching_room_info _mrinfo;
extern int minfo_sid;
extern struct minfo minfo[16];
extern struct SceNetAdhocctlPeerInfo peerinfo[16];
extern struct SceNetAdhocctlScanInfo scaninfo[32];
extern struct SceNetAdhocMatchingMember mmember[17];

void draw_net_scan_result_list(int *x_ptr, int *y_ptr);
void draw_net_hello_list(int *x_ptr, int *y_ptr);
void draw_net_established_list(int *x_ptr, int *y_ptr);
static int get_nickname(int buflen, struct SceNetEtherAddr *addr, struct SceNetAdhocctlNickname **n);
void draw_net_member_list(int *x_ptr, int *y_ptr);
void draw_net_neighbors(int *x_ptr, int *y_ptr);
void sceNetEtherNtostr(const struct SceNetEtherAddr *addr, char *str);
void draw_p2p_game_parameter(int index, int color, int x, int *y_ptr);
extern char D_000197C8[];
extern char D_000197D4[];
extern char D_0001981C[];
int sceNetAdhocMatchingGetMembers(int id, int *buflen, struct SceNetAdhocMatchingMember *buf);
int sceNetAdhocctlGetPeerList(int *buflen, struct SceNetAdhocctlPeerInfo *buf);
int sceNetAdhocctlGetScanInfo(int *buflen, struct SceNetAdhocctlScanInfo *buf);
int snprintf(char *buf, unsigned int size, const char *fmt, ...);
void *memcpy(void *d, const void *s, unsigned int n);


/* SDK prototypes (tools/sdk_protos.h) */
int memcmp(const void *a, const void *b, unsigned int n);
int printf(const char *fmt, ...);
void sceGuDebugPrint(int x, int y, unsigned int color, const char *str);
int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
int sprintf(char *buf, const char *fmt, ...);

void draw_net_scan_result_list(int *x_ptr, int *y_ptr)
{
	char group_name_str[9];
	struct SceNetAdhocctlScanInfo *sinfo;
	char mess_buff[128];
	int ret, x, y, buflen, i, n;

	x = *x_ptr;
	y = *y_ptr;
	buflen = sizeof(scaninfo);
	ret = sceNetAdhocctlGetScanInfo(&buflen, scaninfo);
	if (ret < 0) {
		printf("sceNetAdhocctlGetScanInfo() failed. ret = 0x%x\n", ret);
		goto error;
	}
	if (buflen != 0) {
		for (sinfo = scaninfo; sinfo != NULL; sinfo = sinfo->next) {
			ret = snprintf(mess_buff, sizeof(mess_buff), "ch: %d  BSSID: ", sinfo->channel);
			sceNetEtherNtostr((struct SceNetEtherAddr *)&sinfo->bssid, mess_buff + ret);
			n = ret + 17;
			memcpy(group_name_str, sinfo->group_name.data, 8);
			group_name_str[8] = '\0';
			snprintf(mess_buff + n, sizeof(mess_buff) - n, "  Group Name: %s", group_name_str);
			sceGuDebugPrint(x, y, 0xffffff, mess_buff);
			y += 10;
		}
	}
error:
	*x_ptr = x;
	*y_ptr = y;
}

void draw_net_hello_list(int *x_ptr, int *y_ptr)
{
	char etherstr[32];
	char mess_buff[128];
	int x, y, i, color;

	x = *x_ptr;
	y = *y_ptr;
	sceKernelWaitSema(minfo_sid, 1, NULL);
	for (i = 0; i < 16; i++) {
		if (minfo[i].status == 0)
			continue;
		color = (i == _mrinfo.v_cursor_pos) ? 0xff : 0xffffff;
		sceNetEtherNtostr(&minfo[i].addr, etherstr);
		if (minfo[i].hello_opt.nickname.data[0] != 0)
			sprintf(mess_buff, D_000197C8, minfo[i].hello_opt.nickname.data, etherstr);
		else
			sprintf(mess_buff, D_000197D4, etherstr);
		sceGuDebugPrint(x, y, color, mess_buff);
		y += 10;
		draw_p2p_game_parameter(i, color, x + 16, &y);
		y += 5;
	}
	sceKernelSignalSema(minfo_sid, 1);
	*x_ptr = x;
	*y_ptr = y;
}

void draw_net_established_list(int *x_ptr, int *y_ptr)
{
	char etherstr[32];
	char mess_buff[128];
	int x, y, i;

	x = *x_ptr;
	y = *y_ptr;
	sceNetEtherNtostr(&_mrinfo.local_addr, etherstr);
	if (_mrinfo.hello_opt.nickname.data[0] != 0)
		sprintf(mess_buff, D_000197C8, _mrinfo.hello_opt.nickname.data, etherstr);
	else
		sprintf(mess_buff, D_000197D4, etherstr);
	sceGuDebugPrint(x, y, 0xffffff, mess_buff);
	y += 10;
	sceKernelWaitSema(minfo_sid, 1, NULL);
	for (i = 0; i < 16; i++) {
		if (minfo[i].status != 5)
			continue;
		sceNetEtherNtostr(&minfo[i].addr, etherstr);
		if (minfo[i].hello_opt.nickname.data[0] != 0)
			sprintf(mess_buff, D_000197C8, minfo[i].hello_opt.nickname.data, etherstr);
		else
			sprintf(mess_buff, D_000197D4, etherstr);
		sceGuDebugPrint(x, y, 0xffffff, mess_buff);
		y += 10;
	}
	sceKernelSignalSema(minfo_sid, 1);
	*x_ptr = x;
	*y_ptr = y;
}

static int get_nickname(int buflen, struct SceNetEtherAddr *addr, struct SceNetAdhocctlNickname **n)
{
	struct SceNetAdhocctlPeerInfo *peer;
	int ret = 0;

	if(buflen == 0)
		goto finish;

	if(memcmp(&_mrinfo.local_addr, addr,
	    sizeof(struct SceNetEtherAddr)) == 0){
		if(_mrinfo.hello_opt.nickname.data[0] != '\0'){
			*n = &_mrinfo.hello_opt.nickname;
			ret = 1;
		}
		goto finish;
	}

	for (peer = &peerinfo[0]; peer != NULL; peer = peer->next) {
		if(memcmp(&peer->mac_addr, addr, sizeof(struct SceNetEtherAddr))
		    != 0)
			continue;

		if(peer->nickname.data[0] == '\0')
			goto finish;

		*n = &peer->nickname;
		ret = 1;
		break;
	}

finish:
	return ret;
}

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/draw_net", D_000197C8);

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/draw_net", D_000197D4);

void draw_net_member_list(int *x_ptr, int *y_ptr)
{
	char etherstr[32];
	struct SceNetAdhocctlNickname *nickname;
	struct SceNetAdhocMatchingMember *m;
	char mess_buff[128];
	int ret, x, y, buflen;

	x = *x_ptr;
	y = *y_ptr;
	buflen = sizeof(mmember);
	ret = sceNetAdhocMatchingGetMembers(_mrinfo.ctx_id, &buflen, mmember);
	if (ret < 0) {
		printf("sceNetAdhocMatchingGetMembers() failed. ret = 0x%x\n", ret);
		goto error;
	}
	if (buflen == 0)
		goto error;
	buflen = sizeof(peerinfo);
	ret = sceNetAdhocctlGetPeerList(&buflen, peerinfo);
	if (ret < 0) {
		printf(D_0001981C, ret);
		goto error;
	}
	for (m = mmember; m != NULL; m = m->next) {
		sceNetEtherNtostr(&m->addr, etherstr);
		if (get_nickname(buflen, &m->addr, &nickname) > 0)
			sprintf(mess_buff, D_000197C8, nickname->data, etherstr);
		else
			sprintf(mess_buff, D_000197D4, etherstr);
		sceGuDebugPrint(x, y, 0xffffff, mess_buff);
		y += 10;
	}
error:
	*x_ptr = x;
	*y_ptr = y;
}

void draw_net_neighbors(int *x_ptr, int *y_ptr)
{
	char etherstr[32];
	struct SceNetAdhocctlPeerInfo *peer;
	char mess_buff[128];
	int ret, x, y, n, buflen;

	x = *x_ptr;
	y = *y_ptr;
	buflen = sizeof(peerinfo);
	ret = sceNetAdhocctlGetPeerList(&buflen, peerinfo);
	if (ret < 0) {
		printf(D_0001981C, ret);
		goto error;
	}
	if (buflen == 0)
		goto error;
	for (peer = peerinfo; peer != NULL; peer = peer->next) {
		sceNetEtherNtostr(&peer->mac_addr, etherstr);
		if (peer->nickname.data[0] != 0)
			sprintf(mess_buff, D_000197C8, peer->nickname.data, etherstr);
		else
			sprintf(mess_buff, D_000197D4, etherstr);
		sceGuDebugPrint(x, y, 0xffffff, mess_buff);
		y += 10;
	}
error:
	*x_ptr = x;
	*y_ptr = y;
}

INCLUDE_RODATA("tmp/asm/UTST99332/net_matching_moonball/nonmatchings/draw_net", D_0001981C);
