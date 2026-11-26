/* cflags: -O2 -fmerge-constants */
#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
typedef unsigned int u_int32;
enum PeerState {
    MATCHING_DISCONNECTED = 0,
    MATCHING_HELLO = 1,
    MATCHING_SEND_REQ = 2,
    MATCHING_RECV_REQ = 3,
    MATCHING_DENY = 4,
    MATCHING_ESTABLISHED = 5,
};
struct SceNetEtherAddr;
typedef unsigned char SceUChar8;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
struct SceNetAdhocctlNickname;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceUChar8 data[128];
};
struct _anon1 { /* size 0xb0 */
    int x;
    int y;
    u_int32 c;
    int comp;
    float high;
    float vtx_x;
    float vtx_y;
    int detect;
    u_int32 last_v;
    enum PeerState peer_state;
    struct SceNetEtherAddr addr;
    struct SceNetAdhocctlNickname nickname;
};
typedef struct _anon1 OBJECT;
struct SceNetAdhocPdpStat;
typedef short unsigned int SceUShort16;
struct SceNetAdhocPdpStat { /* size 0x14 */
    struct SceNetAdhocPdpStat *next;
    int id;
    struct SceNetEtherAddr laddr;
    SceUShort16 lport;
    unsigned int rcv_sb_cc;
};
typedef short unsigned int u_int16;
enum connect_state {
    CONNECTING_PRIMARY_IBSS = 0,
    PRIMARY_IBSS = 1,
    DISCONNECT_PRIMARY_IBSS = 2,
    DISCONNECTING_PRIMARY_IBSS = 3,
    CONNECTING_SECONDARY_IBSS = 4,
    SECONDARY_IBSS = 5,
    DISCONNECT_SECONDARY_IBSS = 6,
    DISCONNECTING_SECONDARY_IBSS = 7,
    ERROR_DIALOG = 8,
    ERROR_DISCONNECT = 9,
    ERROR_DISCONNECTING = 10,
    DISCONNECTED = 11,
};
struct SceNetAdhocctlAdhocId;
struct SceNetAdhocctlAdhocId { /* size 0x10 */
    int type;
    SceUChar8 data[9];
    SceUChar8 padding[3];
};
struct SceNetAdhocctlGroupName;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceUChar8 data[8];
};

extern enum connect_state connect_state;
extern int socket_id;
extern struct SceNetEtherAddr local_addr;
extern int matching_ctx_id;
extern struct SceNetAdhocctlAdhocId adhoc_id;
extern struct SceNetAdhocctlGroupName group_name;
extern int handlerId;

int matching_start(OBJECT *obj);
int net_init(OBJECT *obj, struct SceNetAdhocctlNickname *nickname);
int net_create_pdp(char *etherstr);
int send_position(OBJECT *obj);
int recv_allpacket(OBJECT *obj);
int disconnect_ibss(void);
int check_disconnect_completed(void);


/* SDK prototypes (tools/sdk_protos.h) */
int memcmp(const void *a, const void *b, unsigned int n);
void *memset(void *s, int c, unsigned int n);
int printf(const char *fmt, ...);
int puts(const char *s);

extern int matching_ctx_id_322C4;
void handler_p2p(int id, int event, struct SceNetEtherAddr *peer, int optlen, void *opt);
int matching_start(OBJECT *obj)
{
	int ret;

	ret = sceNetAdhocMatchingInit(0x20000);
	if (ret < 0) {
		printf("sceNetAdhocMatchingInit() failed. ret = 0x%x\n", ret);
		return ret;
	}
	ret = sceNetAdhocMatchingCreate(3, 2, 0x22b, 0x800, 5000000, 10000000, 3, 500000, handler_p2p);
	if (ret < 0) {
		printf("sceNetAdhocMatchingCreate() failed. ret = 0x%x\n", ret);
		return ret;
	}
	matching_ctx_id_322C4 = ret;
	ret = sceNetAdhocMatchingStart(ret, 0x10, 0x2000, 0x10, 0x2000, 0x80, obj->nickname.data);
	if (ret < 0) {
		printf("sceNetAdhocMatchingStart() failed. ret = 0x%x\n", ret);
		return ret;
	}
	return matching_ctx_id_322C4;
}

void adhocctl_handler(int event, int error, void *arg);
int net_init(OBJECT *obj, struct SceNetAdhocctlNickname *nickname)
{
	int ret;

	ret = sceNetInit(0x20000, 0x20, 0x1000, 0x20, 0x1000);
	if (ret < 0) {
		printf("sceNetInit() failed. ret = 0x%x\n", ret);
		goto error;
	}
	ret = sceNetAdhocInit();
	if (ret < 0) {
		printf("sceNetAdhocInit() failed. ret = 0x%x\n", ret);
		goto error;
	}
	ret = sceNetAdhocctlInit(0x2000, 0x30, &adhoc_id);
	if (ret < 0) {
		printf("sceNetAdhocctlInit() failed. ret = 0x%x\n", ret);
		goto error;
	}
	clear_evf();
	ret = sceNetAdhocctlAddHandler(adhocctl_handler, NULL);
	if (ret < 0) {
		printf("sceNetAdhocctlAddHandler() failed. ret = 0x%x\n", ret);
		goto error;
	}
	handlerId = ret;
	strncpy((char *)obj->nickname.data, (const char *)nickname, 128);
	ret = sceNetAdhocDialogInit();
	if (ret < 0) {
		printf("sceNetAdhocDialogInit() failed. ret = 0x%x\n", ret);
		goto error;
	}
	return 0;

error:
	sceNetAdhocDialogTerm();
	if (handlerId > 0)
		sceNetAdhocctlDelHandler(handlerId);
	sceNetAdhocctlTerm();
	sceNetAdhocTerm();
	sceNetTerm();
	return -1;
}

void sceNetEtherNtostr(const struct SceNetEtherAddr *addr, char *str);
int net_create_pdp(char *etherstr)
{
	int ret;

	sceNetGetLocalEtherAddr(&local_addr);
	memset(etherstr, 0, 4);
	sceNetEtherNtostr(&local_addr, etherstr);
	ret = sceNetAdhocPdpCreate(&local_addr, 0x309, 0x400, 0);
	if (ret < 0) {
		printf("sceNetAdhocPdpCreate() failed. ret = 0x%x\n", ret);
		goto error;
	}
	socket_id = ret;
	return 0;
error:
	return -1;
}

extern int matching_ctx_id_322C4;

int net_stop(void) {
    sceNetAdhocPdpDelete(socket_id, 0);
    if (matching_ctx_id_322C4 > 0) {
        sceNetAdhocMatchingStop(matching_ctx_id_322C4);
        sceNetAdhocMatchingDelete(matching_ctx_id_322C4);
    }
    sceNetAdhocMatchingTerm();
    return 0;
}

extern int matching_ctx_id_322C4;

void net_term(void) {
    if (handlerId > 0) {
        sceNetAdhocctlDelHandler(handlerId);
    }
    if (matching_ctx_id_322C4 > 0) {
        sceNetAdhocMatchingStop(matching_ctx_id_322C4);
        sceNetAdhocMatchingDelete(matching_ctx_id_322C4);
    }
    sceNetAdhocMatchingTerm();
    sceNetAdhocDialogTerm();
    sceNetAdhocctlTerm();
    sceNetAdhocTerm();
    sceNetTerm();
}

#define SCE_NET_ETHER_ADDR_LEN 6
#define PAYLOAD_MOVE_TYPE	0x01
#define PORT		777							
#define PAYLOAD_MOVE_LEN	(1+4+4+4+4+4+4)		
#define SCE_NET_ADHOC_F_NONBLOCK		0x0001
#define SCE_ERROR_NET_ADHOC_WOULD_BLOCK				0x80410709
#define SCE_OK							0

int
send_position(OBJECT *obj)
{
	int ret;
	struct SceNetEtherAddr broadcast;
	char buf[PAYLOAD_MOVE_LEN];

	
	memset(broadcast.data, 0xff, SCE_NET_ETHER_ADDR_LEN);

	
	*buf = PAYLOAD_MOVE_TYPE;
	memcpy(&buf[1], &obj->x, sizeof(int));
	memcpy(&buf[5], &obj->y, sizeof(int));
	memcpy(&buf[9], &obj->c, sizeof(int));
	memcpy(&buf[13], &obj->comp, sizeof(int));
	memcpy(&buf[17], &obj->vtx_x, sizeof(float));
	memcpy(&buf[21], &obj->vtx_y, sizeof(float));

	ret = sceNetAdhocPdpSend(
			socket_id,
			&broadcast,
			PORT,
			buf,
			PAYLOAD_MOVE_LEN,
			0,
			SCE_NET_ADHOC_F_NONBLOCK);

	if (ret == SCE_ERROR_NET_ADHOC_WOULD_BLOCK)
		ret = SCE_OK;

	return ret;
}

#define RXBUFLEN	1024						
#define MAX_OBJ		8

int
recv_allpacket(OBJECT *obj)
{
	int i, repeat_i, ret;
	struct SceNetEtherAddr saddr;
	struct SceNetAdhocPdpStat stat;
	u_int16 sport;
	int buflen;
	char buf[RXBUFLEN];
	int repeat = 0;
	int stat_buflen;

	
	
	obj[0].last_v++;

	stat_buflen = sizeof(struct SceNetAdhocPdpStat);
	ret = sceNetAdhocGetPdpStat(&stat_buflen, (void *)&stat);
	if (ret < 0) {
		printf("sceNetAdhocGetPdpStat() failed. ret = 0x%x\n", ret);
		return ret;
	}
	if (stat_buflen == 0 || stat.id != socket_id) {
		printf("sceNetAdhocGetPdpStat() invalid data.\n");
		return -1;
	}

	
	
	repeat = stat.rcv_sb_cc / PAYLOAD_MOVE_LEN;
	for (repeat_i=0; repeat_i<repeat; repeat_i++) {
		buflen = RXBUFLEN;
		ret = sceNetAdhocPdpRecv(
				socket_id,
				&saddr,
				&sport,
				buf,
				&buflen,
				0,
				SCE_NET_ADHOC_F_NONBLOCK);

		if (ret == SCE_ERROR_NET_ADHOC_WOULD_BLOCK) {
			ret = SCE_OK;
			break;
		}
		
		if (memcmp(&local_addr, &saddr, SCE_NET_ETHER_ADDR_LEN) == 0)
			continue;
		
		if (sport != PORT)
			continue;
		if (buflen == PAYLOAD_MOVE_LEN && buf[0] == PAYLOAD_MOVE_TYPE) {
			for (i=1; i<MAX_OBJ; i++) {
				if (obj[i].detect == 0 ||
					(obj[i].detect==1 &&
					memcmp(&obj[i].addr.data, &saddr, SCE_NET_ETHER_ADDR_LEN) == 0)) {
					memcpy(&obj[i].x, &buf[1], sizeof(int));
					memcpy(&obj[i].y, &buf[5], sizeof(int));
					memcpy(&obj[i].c, &buf[9], sizeof(int));
					memcpy(&obj[i].comp, &buf[13], sizeof(int));
					memcpy(&obj[i].vtx_x, &buf[17], sizeof(float));
					memcpy(&obj[i].vtx_y, &buf[21], sizeof(float));
					if (obj[i].detect == 0) {
						memcpy(&obj[i].addr, &saddr, SCE_NET_ETHER_ADDR_LEN);
						
						sceNetAdhocctlGetNameByAddr(&saddr, &obj[i].nickname);
					}
					obj[i].last_v = obj[0].last_v;
					obj[i].detect = 1;
					break;
				}
			}
		}
	}

	
	
	for (i=1; i<MAX_OBJ; i++) {
		if ((obj[0].last_v - obj[i].last_v) > 60) {
			obj[i].high = 2.0f;
			obj[i].vtx_x = 0.0f;
			obj[i].vtx_y = 0.0f;
			obj[i].last_v = 0;
			obj[i].detect = 0;
		}
	}
	
	return ret;
}

int net_stop(void);
int sceNetAdhocDialogConnect(struct SceNetAdhocctlGroupName *group_name);
int disconnect_ibss(void)
{
	int ret;

	net_stop();
	ret = sceNetAdhocctlDisconnect();
	if (ret < 0) {
		printf("sceNetAdhocctlDisconnect() failed. ret = 0x%x\n", ret);
		return 0;
	}
	switch (connect_state) {
	case DISCONNECT_PRIMARY_IBSS:
		connect_state = DISCONNECTING_PRIMARY_IBSS;
		break;
	case DISCONNECT_SECONDARY_IBSS:
		connect_state = DISCONNECTING_SECONDARY_IBSS;
		break;
	case ERROR_DIALOG:
	case ERROR_DISCONNECT:
		connect_state = ERROR_DISCONNECTING;
		break;
	}
	return 0;
}

int check_disconnect_completed(void)
{
	int adhocctl_state;
	int ret;

	ret = sceNetAdhocctlGetState(&adhocctl_state);
	if (ret < 0)
		goto error;
	if (adhocctl_state != 0)
		return ret;
	switch (connect_state) {
	case DISCONNECTING_PRIMARY_IBSS:
		ret = sceNetAdhocDialogConnect(&group_name);
		if (ret < 0) {
			printf("sceNetAdhocDialogConnect() failed. ret = 0x%x\n", ret);
			return ret;
		}
		connect_state = CONNECTING_SECONDARY_IBSS;
		break;
	case DISCONNECTING_SECONDARY_IBSS:
		ret = sceNetAdhocDialogConnect(NULL);
		if (ret < 0) {
			printf("sceNetAdhocDialogConnect() failed. ret = 0x%x\n", ret);
			return ret;
		}
		connect_state = CONNECTING_PRIMARY_IBSS;
		break;
	case ERROR_DISCONNECTING:
		connect_state = DISCONNECTED;
		break;
	}
error:
	return ret;
}

int disconnect_check(void) {
    switch (connect_state) {
    case DISCONNECT_PRIMARY_IBSS:
    case DISCONNECT_SECONDARY_IBSS:
    case ERROR_DISCONNECT:
        disconnect_ibss();
        /* fallthrough */
    default:
        break;
    case DISCONNECTING_PRIMARY_IBSS:
    case DISCONNECTING_SECONDARY_IBSS:
    case ERROR_DISCONNECTING:
        check_disconnect_completed();
        break;
    }
    return 0;
}

