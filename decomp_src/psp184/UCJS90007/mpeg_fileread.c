#include "common.h"

/* declarations recovered from DWARF */
typedef struct t_ringBuffer t_ringBuffer;
struct t_ringBuffer;
typedef int SceInt32;
typedef struct SceMpegRingbuffer SceMpegRingbuffer;
struct SceMpegRingbuffer;
typedef SceInt32 (*SceMpegRBCallback)(void *, SceInt32, void *);
struct SceMpegRingbuffer { /* size 0x2c */
    SceInt32 m_iBufsize;
    SceInt32 m_iRpos;
    SceInt32 m_iWpos;
    SceInt32 m_iInlen;
    SceInt32 m_iTypeSize;
    void *m_pBuf;
    SceMpegRBCallback callback;
    void *m_CallbackData;
    void *pPack;
    SceInt32 iSemaRB;
    void *mp;
};
typedef struct t_conditionCtrl t_conditionCtrl;
struct t_conditionCtrl;
typedef int SceUID;
struct t_conditionCtrl { /* size 0x8 */
    SceUID controlFlag;
    SceUID waitFlag;
};
struct t_ringBuffer { /* size 0x10 */
    SceInt32 dataLen;
    SceInt32 statusFlag;
    SceMpegRingbuffer *pRingbuf;
    t_conditionCtrl *pCtrl;
};
typedef unsigned int SceUInt32;
typedef unsigned int SceSize;
struct _info;
struct SceNetEtherAddr;
typedef unsigned char SceUChar8;
struct SceNetEtherAddr { /* size 0x6 */
    SceUChar8 data[6];
};
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

SceInt32 read_create(t_ringBuffer *pRing, SceMpegRingbuffer *pRB, t_conditionCtrl *pCtrl);
SceInt32 read_reset(t_ringBuffer *pRing, SceInt32 fileSize);
SceInt32 read_isEnd(t_ringBuffer *pRing);
SceInt32 read_isFull(t_ringBuffer *pRing);
SceInt32 read_checkConditionEnd(t_ringBuffer *pRing);
int read_func(SceSize size, void *argp);


SceInt32 read_create(t_ringBuffer *pRing, SceMpegRingbuffer *pRB, t_conditionCtrl *pCtrl)
{
	pRing->pRingbuf = pRB;
	pRing->pCtrl = pCtrl;
	return 0;
}

SceInt32 read_reset(t_ringBuffer *pRing, SceInt32 fileSize)
{
	pRing->statusFlag = 1;
	pRing->dataLen = fileSize;
	return 0;
}

int read_delete(t_ringBuffer *pRing) {
    return 0;
}

int read_getStatus(t_ringBuffer *pRing) {
    return pRing->statusFlag;
}

int read_setStatus(t_ringBuffer *pRing, int status) {
    pRing->statusFlag = status;
    return 0;
}

SceInt32 read_isEnd(t_ringBuffer *pRing)
{
	SceUInt32 pattern;

	control_getCondition(pRing->pCtrl, &pattern);
	return (pattern & 0x4) ? 1 : 0;
}

SceInt32 read_isFull(t_ringBuffer *pRing)
{
	SceUInt32 pattern;
	SceInt32 ret;

	control_getCondition(pRing->pCtrl, &pattern);
	if (read_isEnd(pRing) == 1)
		ret = 1;
	else if (read_getCapacity(pRing) == 0)
		ret = 1;
	else
		ret = 0;
	return ret;
}

int read_getCapacity(t_ringBuffer *pRing) {
    return sceMpegRingbufferAvailableSize(pRing->pRingbuf);
}

int read_sendErrCondition(t_ringBuffer *pRing) {
    control_setCondition(pRing->pCtrl, 0xC00);
    return 0;
}

int read_sendEndCondition(t_ringBuffer *pRing) {
    control_setCondition(pRing->pCtrl, 4);
    return 0;
}

SceInt32 read_checkConditionEnd(t_ringBuffer *pRing)
{
	SceUInt32 pattern;

	control_getCondition(pRing->pCtrl, &pattern);
	if ((pattern & 0xFF) == 0xFF)
		read_setStatus(pRing, 3);
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_fileread", read_func);
