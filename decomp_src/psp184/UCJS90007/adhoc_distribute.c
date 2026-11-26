#include "common.h"

/* declarations recovered from DWARF */
struct server_ctx;
enum SceNetAdhocDistributeServerState {
    SCE_NET_ADHOC_DISTRIBUTE_SERVER_STATE_INIT = 0,
    SCE_NET_ADHOC_DISTRIBUTE_SERVER_STATE_WAIT_FOR_REQUEST = 1,
};
struct request_message;
typedef struct SceKernelMsgPacket SceKernelMsgPacket;
struct SceKernelMsgPacket;
typedef unsigned char SceUChar;
struct SceKernelMsgPacket { /* size 0x8 */
    struct SceKernelMsgPacket *next;
    SceUChar msgPriority;
    SceUChar dummy[3];
};
struct SceNetEtherAddr;
typedef unsigned char SceUChar8;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
struct request_message { /* size 0x14 */
    SceKernelMsgPacket msgpkt;
    struct SceNetEtherAddr peer;
    int flag;
};
struct server_ctx { /* size 0x10c */
    enum SceNetAdhocDistributeServerState state;
    int thread_num;
    int nickname_len;
    int hello_optlen;
    void *hello_opt;
    int datasize;
    void *databuf;
    int matching_id;
    int mbxid;
    int workertid[8];
    int workersid[8];
    struct request_message reqmsg[8];
    unsigned int success;
    unsigned int fail;
};
struct worker_ctx;
enum SceNetAdhocDistributeWorkerState {
    SCE_NET_ADHOC_DISTRIBUTE_WORKER_STATE_DEAD = 0,
    SCE_NET_ADHOC_DISTRIBUTE_WORKER_STATE_READY = 1,
    SCE_NET_ADHOC_DISTRIBUTE_WORKER_STATE_BUSY = 2,
};
struct log_info;
struct ScePspDateTime;
struct ScePspDateTime { /* size 0x10 */
    short unsigned int year;
    short unsigned int month;
    short unsigned int day;
    short unsigned int hour;
    short unsigned int minute;
    short unsigned int second;
    unsigned int microsecond;
};
struct log_info { /* size 0x24 */
    struct ScePspDateTime start;
    struct ScePspDateTime finish;
    int error_code;
};
struct worker_ctx { /* size 0x34 */
    enum SceNetAdhocDistributeWorkerState state;
    struct SceNetEtherAddr peer;
    unsigned int transferred;
    struct log_info log_info;
};
struct SceNetAdhocctlGroupName;
typedef char SceChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceChar8 data[8];
};
struct SceNetAdhocctlNickname;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceChar8 data[128];
};
typedef unsigned int size_t;
struct SceKernelVplInfo;
typedef unsigned int SceSize;
typedef unsigned int SceUInt;
struct SceKernelVplInfo { /* size 0x34 */
    SceSize size;
    char name[32];
    SceUInt attr;
    int poolSize;
    int freeSize;
    int numWaitThreads;
};
struct SceNetMallocStat;
struct SceNetMallocStat { /* size 0xc */
    int poolsize;
    int maxsize;
    int freesize;
};
typedef struct SceKernelVplInfo SceKernelVplInfo;
typedef unsigned char u_int8_t;
typedef short unsigned int u_int16_t;
typedef short unsigned int SceUShort16;
typedef unsigned int SceUInt32;
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
typedef int SceUID;

extern struct _info _info;
extern int inited;
extern SceUID vplid;
extern int maxalloc;
extern struct server_ctx _sctx;
extern struct server_ctx *sctx;
extern struct worker_ctx wctx[8];

int sceNetAdhocDistributeInitServer(unsigned int poolsize);
int sceNetAdhocDistributeCreateServer(unsigned int thread_num, int worker_tpl, int worker_stacksize, unsigned int paramsfo_len, void *paramsfo, unsigned int datasize, void *databuf, struct SceNetAdhocctlGroupName *group_name);
int sceNetAdhocDistributeStartServer(int matching_event_tpl, int matching_event_stack, int matching_input_tpl, int matching_input_stack);
int sceNetAdhocDistributeStopServer(void);
int sceNetAdhocDistributeDeleteServer(void);
int sceNetAdhocDistributeTermServer(void);
static void adhoc_distribute_server_matching_cb_func(int id, int ev, struct SceNetEtherAddr *peer, int optlen, void *opt);
static void *adhoc_distribute_malloc(size_t size);
int sceNetAdhocDistributeGetPoolStat(struct SceNetMallocStat *poolstat);
static void *adhoc_download_maketag(u_int8_t type, void *data, int datalen, void *buf);
static SceUShort16 sceNetHtons(SceUShort16 host16);
void *adhoc_download_gettag(u_int8_t type, void *buf, int buflen, int *datalen);
static SceUShort16 sceNetNtohs(SceUShort16 net16);
int sceNetAdhocDistributeUpdateServerHelloOpt(void);
static struct request_message *adhoc_distribute_get_reqmsg(void);
static int adhoc_distribute_worker_thread(SceSize argsize, void *arg);
static void adhoc_distribute_send(int id);
static SceUInt32 sceNetHtonl(SceUInt32 host32);


struct server_ctx *_sce_pspnet_adhoc_distribute_get_server_ctx(void) {
    return sctx;
}

struct worker_ctx *_sce_pspnet_adhoc_distribute_get_worker_ctx(int id) {
    struct worker_ctx *var_v1;

    var_v1 = NULL;
    if (id < 8) {
        var_v1 = &wctx[id];
    }
    return var_v1;
}

int sceNetAdhocDistributeInitServer(unsigned int poolsize)
{
	int ret;

	if (inited != 0)
		return 0x80410C11;
	ret = adhoc_distribute_malloc_init(poolsize);
	if (ret < 0)
		return ret;
	inited = 1;
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", sceNetAdhocDistributeCreateServer);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", sceNetAdhocDistributeStartServer);

int sceNetAdhocDistributeStopServer(void)
{
	int numWaitThreads;
	int i;

	if (!inited)
		return 0x80410C12;
	if (sctx == NULL)
		return 0x80410C16;
	sctx->state = 0;
	sceNetAdhocMatchingStop(sctx->matching_id);
	sceKernelCancelReceiveMbx(sctx->mbxid, &numWaitThreads);
	for (i = 0; i < 8; i++) {
		if (sctx->workersid[i] > 0)
			sceNetAdhocSetSocketAlert(sctx->workersid[i], 0x3F0);
		if (sctx->workertid[i] > 0)
			sceKernelWaitThreadEnd(sctx->workertid[i], NULL);
	}
	return 0;
}

int sceKernelDeleteThread(int thid);
int sceKernelDeleteMbx(int mbxid);
int sceNetAdhocMatchingDelete(int id);
int sceNetAdhocMatchingStop(int id);
int sceKernelCancelReceiveMbx(int mbxid, int *pnum);
int sceNetAdhocSetSocketAlert(int id, int flag);
int sceKernelWaitThreadEnd(int thid, unsigned int *timeout);
int sceKernelDeleteThread(int thid);
int sceNetAdhocDistributeDeleteServer(void)
{
	int i;

	if (!inited)
		return 0x80410C12;
	if (sctx == NULL)
		return 0x80410C16;
	if (sctx->state != 0)
		return 0x80410C17;
	for (i = 0; i < 8; i++) {
		if (sctx->workertid[i] > 0)
			sceKernelDeleteThread(sctx->workertid[i]);
	}
	sceKernelDeleteMbx(sctx->mbxid);
	sceNetAdhocMatchingDelete(sctx->matching_id);
	adhoc_distribute_free(sctx->hello_opt);
	sctx = NULL;
	return 0;
}

int sceNetAdhocDistributeTermServer(void)
{
	if (inited == 0)
		return 0;
	if (sctx != NULL)
		return 0x80410C14;
	adhoc_distribute_malloc_term();
	inited = 0;
	return 0;
}

int sceNetAdhocMatchingSelectTarget(int id, unsigned char *mac, int optlen, void *opt);
int sceKernelSendMbx(int mbxid, void *msg);
static void adhoc_distribute_server_matching_cb_func(int id, int ev, struct SceNetEtherAddr *peer, int optlen, void *opt)
{
	struct request_message *msg;

	if (sctx->matching_id != id)
		return;
	switch (ev) {
	case 1:
		break;
	case 2:
		sceNetAdhocMatchingSelectTarget(sctx->matching_id, (unsigned char *)peer, 0, NULL);
		break;
	case 7:
		msg = adhoc_distribute_get_reqmsg();
		if (msg == NULL)
			break;
		msg->peer = *peer;
		sceKernelSendMbx(sctx->mbxid, msg);
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 8:
	case 9:
	case 10:
		break;
	}
}

int adhoc_distribute_malloc_init(unsigned int poolsize) {
    int temp_v0;
    int temp_v0_2;

    temp_v0_2 = sceKernelCreateVpl("SceNetAdhocDistributeMemoryPool", 2, 0, poolsize, 0);
    temp_v0 = __builtin_allegrex_min(temp_v0_2, 0);
    vplid = temp_v0_2;
    return temp_v0;
}

void adhoc_distribute_malloc_term(void) {
    if (vplid > 0) {
        sceKernelDeleteVpl(vplid);
        vplid = 0;
    }
}

int sceKernelTryAllocateVpl(SceUID vplid, unsigned int size, void **data);
int sceKernelReferVplStatus(SceUID vplid, SceKernelVplInfo *info);
void *adhoc_distribute_malloc(unsigned int size)
{
	SceKernelVplInfo info;
	void *ptr;
	int used;

	if (sceKernelTryAllocateVpl(vplid, size, &ptr) < 0)
		return NULL;
	info.size = sizeof(info);
	if (sceKernelReferVplStatus(vplid, &info) == 0) {
		used = info.poolSize - info.freeSize;
		maxalloc = (used > maxalloc) ? used : maxalloc;
	}
	return ptr;
}

int sceKernelReferVplStatus(SceUID vplid, SceKernelVplInfo *info);
int sceNetAdhocDistributeGetPoolStat(struct SceNetMallocStat *poolstat)
{
	SceKernelVplInfo info;
	int ret;

	info.size = sizeof(info);
	ret = sceKernelReferVplStatus(vplid, &info);
	if (ret < 0)
		return ret;
	poolstat->poolsize = info.poolSize;
	poolstat->maxsize = maxalloc;
	poolstat->freesize = info.freeSize;
	return 0;
}

void adhoc_distribute_free(void *ptr) {
    sceKernelFreeVpl(vplid, ptr);
}

void *memcpy(void *d, const void *s, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
static void *adhoc_download_maketag(u_int8_t type, void *data, int datalen, void *buf)
{
	u_int8_t *p = buf;
	u_int16_t len;

	len = __builtin_allegrex_wsbh((u_int16_t)datalen);
	*p++ = type;
	__builtin_memcpy(p, &len, 2);
	p += 2;
	memcpy(p, data, datalen);
	p += datalen;
	return p;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", adhoc_download_gettag);

int sceKernelCpuSuspendIntr(void);
void sceKernelCpuResumeIntr(int intr);
int sceNetAdhocMatchingSetHelloOpt(int id, int optlen, void *opt);
int sceNetAdhocDistributeUpdateServerHelloOpt(void)
{
	char *p;
	int ret;
	int i;
	int datalen;
	int oldstat;
	int busy = 0;
	char status[7];

	if (!inited)
		return 0x80410C12;
	if (sctx == NULL)
		return 0x80410C16;
	if (sctx->state != SCE_NET_ADHOC_DISTRIBUTE_SERVER_STATE_WAIT_FOR_REQUEST)
		return 0x80410C17;
	p = adhoc_download_gettag(1, sctx->hello_opt, sctx->hello_optlen, &datalen);
	if (p == NULL)
		return 0;
	oldstat = sceKernelCpuSuspendIntr();
	for (i = 0; i < sctx->thread_num; i++) {
		if (wctx[i].state != SCE_NET_ADHOC_DISTRIBUTE_WORKER_STATE_READY)
			busy++;
	}
	sceKernelCpuResumeIntr(oldstat);
	status[0] = ' ';
	status[1] = '(';
	status[2] = '0' + busy;
	status[3] = '/';
	status[4] = '0' + sctx->thread_num;
	status[5] = ')';
	status[6] = '\0';
	if (0x80 - sctx->nickname_len < 7)
		return 0;
	memcpy(p + sctx->nickname_len, status, sizeof(status));
	ret = sceNetAdhocMatchingSetHelloOpt(sctx->matching_id, sctx->hello_optlen, sctx->hello_opt);
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", adhoc_distribute_get_reqmsg);

int sceKernelReceiveMbx(int mbxid, void **pmessage, unsigned int *timeout);
int sceNetAdhocMatchingCancelTarget(int id, struct SceNetEtherAddr *mac);
int sceNetFreeThreadinfo(int thid);
int adhoc_distribute_log_ms(struct SceNetEtherAddr *peer, struct log_info *log_info);
static int adhoc_distribute_worker_thread(SceSize argsize, void *arg)
{
	int id;
	int ret;
	int oldstat;
	SceKernelMsgPacket *msgpkt;
	struct request_message *reqmsg;

	id = *(int *)arg;
	do {
		wctx[id].transferred = 0;
		wctx[id].state = SCE_NET_ADHOC_DISTRIBUTE_WORKER_STATE_READY;
		ret = sceKernelReceiveMbx(sctx->mbxid, (void **)&msgpkt, NULL);
		if (ret < 0)
			break;
		reqmsg = (struct request_message *)msgpkt;
		memcpy(&wctx[id].peer, &reqmsg->peer, sizeof(struct SceNetEtherAddr));
		oldstat = sceKernelCpuSuspendIntr();
		reqmsg->flag &= ~1;
		sceKernelCpuResumeIntr(oldstat);
		wctx[id].state = SCE_NET_ADHOC_DISTRIBUTE_WORKER_STATE_BUSY;
		adhoc_distribute_send(id);
		adhoc_distribute_log_ms(&wctx[id].peer, &wctx[id].log_info);
		sceNetAdhocMatchingCancelTarget(sctx->matching_id, &wctx[id].peer);
	} while (sctx->state == SCE_NET_ADHOC_DISTRIBUTE_SERVER_STATE_WAIT_FOR_REQUEST);
	sceNetFreeThreadinfo(sctx->workertid[id]);
	wctx[id].state = SCE_NET_ADHOC_DISTRIBUTE_WORKER_STATE_DEAD;
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/adhoc_distribute", adhoc_distribute_send);
