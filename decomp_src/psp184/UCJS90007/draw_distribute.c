#include "common.h"

/* declarations recovered from DWARF */
struct SceNetMallocStat;
struct SceNetMallocStat { /* size 0xc */
    int poolsize;
    int maxsize;
    int freesize;
};
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
struct SceNetAdhocctlGroupName;
typedef char SceChar8;
struct SceNetAdhocctlGroupName { /* size 0x8 */
    SceChar8 data[8];
};
struct SceNetAdhocctlNickname;
struct SceNetAdhocctlNickname { /* size 0x80 */
    SceChar8 data[128];
};
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

extern struct _info _info;
extern char *state_str[3];

static int set_poolstat_color(struct SceNetMallocStat *poolstat);
void draw_distribute(void);


static int set_poolstat_color(struct SceNetMallocStat *poolstat)
{
	float ratio = (float)poolstat->freesize / (float)poolstat->poolsize;

	if (ratio > 0.1f)
		return 0xFFFFFF;
	if (ratio > 0.05f)
		return 0xFFFF;
	return 0xFF;
}

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/draw_distribute", D_0002DC94);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/draw_distribute", D_0002DC9C);

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/draw_distribute", D_0002DCA4);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/draw_distribute", draw_distribute);
