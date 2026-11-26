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

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", matching_start);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", net_init);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", net_create_pdp);

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

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", recv_allpacket);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", disconnect_ibss);

INCLUDE_ASM("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", check_disconnect_completed);

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

INCLUDE_RODATA("tmp/asm/UTST99332/net_network_flow/nonmatchings/net", D_000152E4);
