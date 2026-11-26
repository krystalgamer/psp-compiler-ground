#include "common.h"

/* declarations recovered from DWARF */
struct SceNetAdhocctlGroupName;
typedef char SceChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceChar8 data[8];
};
struct SceNetAdhocctlNickname;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceChar8 data[128];
};
struct _sce_pspnet_adhoc_prp_param;
typedef unsigned int u_int;
struct _sce_pspnet_adhoc_prp_param { /* size 0x14 */
    u_int echo_req_int;
    u_int rexmt_int;
    u_int rexmt_cnt;
    u_int keepalive_int;
    u_int expire_timer;
};
struct SceNetAdhocctlPeerInfo;
struct SceNetEtherAddr;
typedef unsigned char SceUChar8;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
typedef long long unsigned int SceUInt64;
struct SceNetAdhocctlPeerInfo { /* size 0x98 */
    struct SceNetAdhocctlPeerInfo *next;
    struct SceNetAdhocctlNickname nickname;
    struct SceNetEtherAddr mac_addr;
    SceUChar8 padding[6];
    SceUInt64 last_recv;
};
struct _info;
enum connect_state {
    STATE_FIRST_INIT = 0,
    STATE_TOP = 1,
    STATE_CONFIG = 2,
    STATE_LOAD_LOGFILE = 3,
    STATE_LOAD_BOOT_BINARY = 4,
    STATE_LOADING = 5,
    STATE_NETINIT = 6,
    STATE_NETTERM = 7,
    STATE_CONNECT = 8,
    STATE_CONNECTING = 9,
    STATE_CONNECTED = 10,
    STATE_MPEG_START = 11,
    STATE_MPEG_INITIALIZING = 12,
    STATE_MPEG_PLAY_START = 13,
    STATE_MOVIE_SCENE = 14,
    STATE_STATUS_SCENE = 15,
    STATE_DISCONNECT = 16,
    STATE_DISCONNECTING = 17,
    STATE_DISPLAY_LOG_MS = 18,
    STATE_DISPLAY_LOG_NEXT = 19,
    STATE_DISPLAY_LOG_PREV = 20,
    STATE_DISPLAY_LOG = 21,
    STATE_ERROR_DIALOG_NET = 22,
    STATE_ERROR_DIALOG_FILEIO = 23,
    STATE_ERROR_DIALOG_MPEG_FILEIO = 24,
    STATE_OSK = 25,
    STATE_BINLIST = 26,
    STATE_MPEGLIST = 27,
    STATE_DISPLAY_PARAMSFO_TOP = 28,
    STATE_DISPLAY_PARAMSFO_BINLIST = 29,
    STATE_DISPLAY_PARAMSFO_CONNECTED = 30,
};
struct SceNetAdhocctlParameter;
struct SceNetAdhocctlBSSId;
struct SceNetAdhocctlBSSId { /* size 0x8 */
    SceUChar8 data[6];
    SceUChar8 padding[2];
};
struct SceNetAdhocctlParameter { /* size 0x94 */
    int channel;
    struct SceNetAdhocctlGroupName group_name;
    struct SceNetAdhocctlNickname nickname;
    struct SceNetAdhocctlBSSId bssid;
};
struct _info { /* size 0x58c */
    struct SceNetEtherAddr local_addr;
    enum connect_state prev_state;
    enum connect_state state;
    int blink_counter;
    int error_code;
    int actual_err_code;
    int actual_err_code_thr;
    int v_cursor_pos;
    int binlist_v_cursor_pos;
    int binlist_top_entry;
    int binlist_entry_num;
    int mpeglist_v_cursor_pos;
    int mpeglist_top_entry;
    int mpeglist_entry_num;
    char bin_filename[256];
    char movie_filename[1][256];
    char log_filename[256];
    int thread_num;
    unsigned int paramsfo_len;
    void *paramsfo;
    unsigned int datasize;
    void *databuf;
    struct SceNetAdhocctlParameter ibss_param;
    int peer_num;
    char paramsfo_filename[256];
    char paramsfo_title[128];
    unsigned int paramsfo_title_len;
    char paramsfo_discid[16];
    unsigned int paramsfo_discid_len;
    int paramsfo_parental;
    int lang;
    int ctrl_assign;
};
struct SceNetAdhocctlAdhocId;
struct SceNetAdhocctlAdhocId { /* size 0x10 */
    int type;
    SceChar8 data[9];
    SceUChar8 padding[3];
};

extern struct _info _info;
extern int handler_id;
extern int evf;
extern int error_code;
extern struct SceNetAdhocctlAdhocId adhoc_id;

void change_state(enum connect_state state, int error_code);
static void adhocctl_handler(int event, int error, void *arg);
static int net_init(void);
static int net_connect(void);
static int check_connect_completed(void);
static int check_disconnect_completed(void);
static int net_connected(void);
static int check_dialog_completed(void);

/* SDK functions (tools/sdk_protos.h) */
int sceKernelGetThreadId(void);
void free(void *p);


extern int error_code_8239C;
static void adhocctl_handler(int event, int error, void *arg)
{
	if (event == 0) {
		error_code_8239C = error;
		evf |= 1;
	} else if (event == 1) {
		error_code_8239C = 0;
		evf |= 2;
	} else if (event == 2) {
		error_code_8239C = 0;
		evf |= 4;
	} else if (event == 3) {
		error_code_8239C = 0;
		evf |= 8;
	} else if (event == 4) {
		error_code_8239C = 0;
		evf |= 0x10;
	}
}

int net_term(void) {
    sceNetAdhocDistributeDeleteServer();
    sceNetAdhocDistributeTermServer();
    if (_info.paramsfo != NULL) {
        free(_info.paramsfo);
        _info.paramsfo = NULL;
    }
    if (_info.databuf != NULL) {
        free(_info.databuf);
        _info.databuf = NULL;
    }
    sceNetAdhocMatchingTerm();
    if (handler_id >= 0) {
        sceNetAdhocctlDelHandler(handler_id);
        handler_id = -1;
    }
    sceNetAdhocctlTerm();
    sceNetAdhocTerm();
    sceNetFreeThreadinfo(sceKernelGetThreadId());
    sceNetTerm();
    change_state(1, 0);
    return 0;
}

int sceNetInit(int poolsize, int calloutprio, int calloutstack, int netintrprio, int netintrstack);
int sceNetAdhocInit(void);
int sceNetAdhocctlInit(int stacksize, int priority, struct SceNetAdhocctlAdhocId *adhoc_id);
int sceNetAdhocctlAddHandler(void *handler, void *arg);
int sceNetAdhocMatchingInit(int memsize);
int sceNetAdhocDistributeInitServer(int memsize);
int sceNetAdhocDistributeCreateServer(int thread_num, int prio, int stacksize, unsigned int optlen, void *opt, unsigned int datasize, void *databuf, struct SceNetAdhocctlGroupName *groupname);
extern int error_code_8239C;
static int net_init(void)
{
	int ret;
	struct SceNetAdhocctlGroupName dummy_groupname = {{0}};

	ret = sceNetInit(0x80000, 0x20, 0x1000, 0x20, 0x1000);
	if (ret < 0)
		goto error;
	ret = sceNetAdhocInit();
	if (ret < 0)
		goto error;
	ret = sceNetAdhocctlInit(0x2000, 0x30, &adhoc_id);
	if (ret < 0)
		goto error;
	evf = 0;
	error_code_8239C = 0;
	ret = sceNetAdhocctlAddHandler(adhocctl_handler, NULL);
	if (ret < 0)
		goto error;
	handler_id = ret;
	ret = sceNetAdhocMatchingInit(0x20000);
	if (ret < 0)
		goto error;
	ret = sceNetAdhocDistributeInitServer(0x20000);
	if (ret < 0)
		goto error;
	ret = sceNetAdhocDistributeCreateServer(_info.thread_num, 0x30, 0x2000, _info.paramsfo_len, _info.paramsfo, _info.datasize, _info.databuf, &dummy_groupname);
	if (ret < 0)
		goto error;
	change_state(8, 0);
	return 0;

error:
	net_term();
	change_state(1, 0);
	return ret;
}

static int net_connect(void)
{
	int ret;

	ret = utility_net_connect();
	if (ret < 0)
		change_state(7, 0);
	else
		change_state(9, 0);
	return ret;
}

int utility_check_net_completed(int *done_flag, int *error_code);
int utility_msgdialog_net(int error_code);
int sceNetGetLocalEtherAddr(struct SceNetEtherAddr *addr);
int _sce_pspnet_adhoc_prp_stop(void);
int _sce_pspnet_adhoc_prp_start(const char *ifname, int prio, int stacksize, struct _sce_pspnet_adhoc_prp_param *param, unsigned int nicklen, char *nickname);
int sceUtilityGetSystemParamString(int id, char *str, int len);
int sceNetAdhocDistributeStartServer(int a, int b, int c, int d);
int sceNetAdhocctlGetParameter(struct SceNetAdhocctlParameter *param);
int mpeg_term(void);
extern int error_code_8239C;
static int check_connect_completed(void)
{
	int ret;
	int done = 0;
	int err = 0;
	char nickname[128];
	struct _sce_pspnet_adhoc_prp_param prp_param;

	ret = utility_check_net_completed(&done, &err);
	if (done > 0) {
		evf &= ~2;
		ret = sceNetGetLocalEtherAddr(&_info.local_addr);
		if (ret < 0)
			goto error;
		_sce_pspnet_adhoc_prp_stop();
		ret = sceUtilityGetSystemParamString(1, nickname, sizeof(nickname));
		if (ret < 0)
			goto error;
		prp_param.echo_req_int = 1000000;
		prp_param.rexmt_int = 500000;
		prp_param.rexmt_cnt = 5;
		prp_param.keepalive_int = 30000000;
		prp_param.expire_timer = 300000000;
		if (_sce_pspnet_adhoc_prp_start("wlan", 0x30, 0x2000, &prp_param, sizeof(nickname), nickname) < 0) {
			error_code_8239C = 0x80410002;
			goto error2;
		}
		ret = sceNetAdhocDistributeStartServer(0x30, 0x2000, 0x30, 0x2000);
		if (ret < 0)
			goto error;
		sceNetAdhocctlGetParameter(&_info.ibss_param);
		_info.peer_num = 0;
		change_state(0xD, 0);
	} else if (done < 0) {
		evf &= ~1;
		mpeg_term();
		change_state(7, 0);
		error_code_8239C = 0;
	}
	return ret;
error:
	error_code_8239C = ret;
error2:
	mpeg_term();
	ret = utility_msgdialog_net(error_code_8239C);
	if (ret < 0)
		change_state(0x10, 0);
	else
		change_state(0x16, error_code_8239C);
	return ret;
}

int net_stop_server(void) {
    sceNetAdhocDistributeStopServer();
    return 0;
}

int net_disconnect(void) {
    sceNetAdhocDistributeStopServer();
    sceNetAdhocctlDisconnect();
    change_state(0x11, 0);
    return 0;
}

static int check_disconnect_completed(void)
{
	if (evf & 4) {
		evf &= ~4;
		change_state(7, 0);
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/net", net_connected);

static int check_dialog_completed(void)
{
	int ret;
	int done = 0;

	ret = utility_check_msgdialog_completed(&done);
	if (ret < 0 || done)
		change_state(0x10, 0);
	return ret;
}

extern int D_0008D33C;

int net_update(void) {
    switch (D_0008D33C) {
    case 6:
        net_init();
        /* fallthrough */
    default:
        break;
    case 7:
        net_term();
        break;
    case 8:
        net_connect();
        break;
    case 9:
        check_connect_completed();
        break;
    case 10:
        change_state(0xE, 0);
        break;
    case 16:
        net_disconnect();
        break;
    case 17:
        check_disconnect_completed();
        break;
    case 14:
    case 15:
    case 21:
        net_connected();
        break;
    case 22:
        check_dialog_completed();
        break;
    }
    return 0;
}

int net_stop(void) {
    evf |= 0x20;
    return 0;
}
