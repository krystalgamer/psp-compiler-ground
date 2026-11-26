#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int u_int32;
typedef long long unsigned int SceUInt64;
typedef struct SceCtrlData SceCtrlData;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
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
struct _mpeg_info;
typedef struct SceMpeg SceMpeg;
struct SceMpeg;
struct SceMpeg { /* size 0x4 */
    void *sys;
};
typedef struct SceMpegRingbuffer SceMpegRingbuffer;
struct SceMpegRingbuffer;
typedef int SceInt32;
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
typedef struct SceMpegStream SceMpegStream;
struct SceMpegStream;
typedef unsigned int SceUInt32;
typedef SceUInt32 SceMpegStreamId;
typedef short int SceShort16;
struct SceMpegStream { /* size 0x40 */
    SceMpegStreamId qStreamId;
    SceMpegStreamId qStreamIdMask;
    void *m_pRAPICtrlStream;
    SceUChar8 *m_pRAPI;
    SceInt32 m_iAuNum;
    SceInt32 m_iPesPacketForwardSize;
    SceInt32 m_iPesPacketForwardFlag;
    SceShort16 m_iPesPacketAULocator;
    SceShort16 reserved;
    SceInt32 m_iPesPacketNum;
    SceInt32 m_iAuSize;
    SceInt32 m_iBoundarySize;
    SceInt32 m_iAuSizeOfProceed;
    SceUInt32 m_iGetAuMode;
    SceInt32 m_iPayloadHeaderRemainderFlag;
    SceInt32 m_iPayloadHeaderRemainderSize;
    SceChar8 m_cPayloadHeaderBuf[4];
};
typedef struct SceMpegAu SceMpegAu;
struct SceMpegAu;
typedef struct SceMpegTimeStamp SceMpegTimeStamp;
struct SceMpegTimeStamp;
struct SceMpegTimeStamp { /* size 0x8 */
    SceUInt32 MSB_ts;
    SceUInt32 ts;
};
struct SceMpegAu { /* size 0x18 */
    SceMpegTimeStamp pts;
    SceMpegTimeStamp dts;
    SceUChar8 *pEsBuf;
    SceInt32 iEsSize;
};
struct _anon1;
typedef int SceUID;
struct _anon1 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon1 StrFile;
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
typedef struct t_conditionCtrl t_conditionCtrl;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x8 */
    SceUID controlFlag;
    SceUID waitFlag;
};
struct t_displayBuffer { /* size 0x2c */
    SceUID lockSema;
    SceUID delayFlag;
    SceInt32 statusFlag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 displayMode;
    t_conditionCtrl *pCtrl;
};
typedef struct t_ringBuffer t_ringBuffer;
struct t_ringBuffer;
struct t_ringBuffer { /* size 0x10 */
    SceInt32 dataLen;
    SceInt32 statusFlag;
    SceMpegRingbuffer *pRingbuf;
    t_conditionCtrl *pCtrl;
};
typedef struct t_soundBuffer t_soundBuffer;
struct t_soundBuffer;
struct t_soundBuffer { /* size 0x2c */
    SceUID lockSema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 bufSize;
    SceInt32 statusFlag;
    t_conditionCtrl *pCtrl;
    SceUInt32 soundLatestPts;
};
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x18 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceUInt32 videoLatestPts;
};
struct t_avSyncControl { /* size 0x20 */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};
typedef struct t_mpegStreamData t_mpegStreamData;
struct t_mpegStreamData;
struct t_mpegStreamData { /* size 0x10 */
    SceMpegStream *pAvcStream;
    SceMpegAu *pAvcAu;
    SceMpegStream *pAtracStream;
    SceMpegAu *pAtracAu;
};
typedef SceUChar8 *SceMpegHandle;
struct _mpeg_info { /* size 0x1bc */
    SceMpeg mpeg;
    SceMpegRingbuffer ringbuf;
    SceMpegStream *pStream[2];
    SceMpegAu avcAu;
    SceMpegAu atracAu;
    SceChar8 filename[256];
    StrFile strFile;
    SceInt32 bufferSize;
    SceInt32 workSize;
    SceInt32 fileSize;
    SceInt32 audioEsSize;
    SceInt32 audioOutSize;
    SceInt32 streamOffset;
    t_displayBuffer *pDisp;
    t_ringBuffer *pRing;
    t_soundBuffer *pSound;
    t_avSyncControl *pAvSync;
    t_conditionCtrl *pCtrl;
    t_mpegStreamData *pStreamData;
    SceMpegHandle avcEsBuf;
    SceChar8 *pPSPStream;
    SceChar8 *pWorkBuf;
    SceChar8 *pAudioBuf;
    SceInt32 evf_id;
};

extern struct _info _info;
extern struct _mpeg_info _mpeg_info;
extern u_int32 cont;

static void pad_circle(void);
static void pad_triangle(void);
static void pad_square(void);
static void pad_cross(void);
static void pad_up(void);
static void pad_r1(void);
static void pad_start(void);
static void pad_select(void);
void pad_read(void);


int utility_msgdialog_fileio(int error_code);
int utility_msgdialog_mpeg_fileio(int error_code);
static void pad_circle(void)
{
	int ret;

	switch (_info.state) {
	case 2:
		if (_info.v_cursor_pos == 1) {
			ret = get_binlist();
			if (ret < 0) {
				ret = utility_msgdialog_fileio(ret);
				if (ret < 0)
					change_state(2, 0);
				else
					change_state(0x17, 0);
			} else {
				change_state(0x1A, 0);
			}
		} else if (_info.v_cursor_pos == 2) {
			ret = get_mpeglist();
			if (ret < 0) {
				ret = utility_msgdialog_mpeg_fileio(ret);
				if (ret < 0)
					change_state(1, 0);
				else
					change_state(0x18, 0);
			} else {
				change_state(0x1B, 0);
			}
		}
		break;
	case 0x1A:
		set_filename();
		free_binlist();
		change_state(2, 0);
		break;
	case 0x1B:
		set_mpeg_filename();
		free_mpeglist();
		change_state(2, 0);
		break;
	}
}

int get_filename(char *bin_filename);
int get_paramsfo(char *bin_filename);
int utility_msgdialog_fileio(int error_code);
int utility_msgdialog_paramsfo(int error_code);
static void pad_triangle(void)
{
	int ret;
	char bin_filename[256];

	switch (_info.state) {
	case 2:
		if (_info.binlist_entry_num > 0) {
			ret = get_paramsfo(_info.bin_filename);
			ret = utility_msgdialog_paramsfo(ret);
			if (ret < 0)
				change_state(2, 0);
			else
				change_state(0x1C, 0);
		} else {
			ret = utility_msgdialog_fileio(0x80410C81);
			if (ret < 0)
				change_state(2, 0);
			else
				change_state(0x17, 0);
		}
		break;
	case 0xF:
		ret = utility_msgdialog_paramsfo(0);
		if (ret < 0)
			change_state(0x10, 0);
		else
			change_state(0x1E, 0);
		break;
	case 0x1A:
		ret = get_filename(bin_filename);
		if (ret == 0)
			ret = get_paramsfo(bin_filename);
		ret = utility_msgdialog_paramsfo(ret);
		if (ret < 0)
			change_state(2, 0);
		else
			change_state(0x1D, 0);
		break;
	}
}

extern int D_0008D33C;
static void pad_square(void)
{
	switch (D_0008D33C) {
	case 2:
		change_state(3, 0);
		break;
	case 15:
		change_state(0x15, 0);
		break;
	}
}

static void pad_cross(void)
{
	switch (_info.state) {
	case STATE_FIRST_INIT:
		break;
	case STATE_DISPLAY_LOG_MS:
		change_state(STATE_CONFIG, 0);
		break;
	case STATE_BINLIST:
		free_binlist();
		change_state(STATE_CONFIG, 0);
		break;
	case STATE_DISPLAY_LOG:
		change_state(STATE_STATUS_SCENE, 0);
		break;
	case STATE_MPEGLIST:
		free_mpeglist();
		change_state(STATE_CONFIG, 0);
		break;
	}
}

static void pad_up(void)
{
	switch (_info.state) {
	case 2:
		if (_info.v_cursor_pos > 0)
			_info.v_cursor_pos -= 1;
		break;
	case 0x1A:
		if (_info.binlist_v_cursor_pos > 0)
			_info.binlist_v_cursor_pos -= 1;
		if (_info.binlist_v_cursor_pos < _info.binlist_top_entry)
			_info.binlist_top_entry -= 1;
	case 0x1B:
		if (_info.mpeglist_v_cursor_pos > 0)
			_info.mpeglist_v_cursor_pos -= 1;
		if (_info.mpeglist_v_cursor_pos < _info.mpeglist_top_entry)
			_info.mpeglist_top_entry -= 1;
	case 0x12:
		log_pageup();
		break;
	}
}

void pad_down(void) {
    int temp_v0;
    int temp_v0_2;
    int var_v1;
    int var_v1_2;

    switch (_info.state) {                          /* irregular */
    case STATE_CONFIG:
        if (_info.v_cursor_pos < 2) {
            _info.v_cursor_pos += 1;
        }
        break;
    case STATE_MPEGLIST:
        var_v1 = _info.mpeglist_v_cursor_pos;
        if (var_v1 < (_info.mpeglist_entry_num - 1)) {
            temp_v0 = var_v1 + 1;
            _info.mpeglist_v_cursor_pos = temp_v0;
            var_v1 = temp_v0;
        }
        if (var_v1 == (_info.mpeglist_top_entry + 0x10)) {
            _info.mpeglist_top_entry += 1;
        }
        break;
    case STATE_BINLIST:
        var_v1_2 = _info.binlist_v_cursor_pos;
        if (var_v1_2 < (_info.binlist_entry_num - 1)) {
            temp_v0_2 = var_v1_2 + 1;
            _info.binlist_v_cursor_pos = temp_v0_2;
            var_v1_2 = temp_v0_2;
        }
        if (var_v1_2 == (_info.binlist_top_entry + 0x10)) {
            _info.binlist_top_entry += 1;
        }
        break;
    case STATE_DISPLAY_LOG_MS:
        log_pagedown(&_info);
        break;
    }
}

void pad_right(void) {
    if (_info.state == STATE_CONFIG) {
        if (_info.v_cursor_pos == 0) {
            if (_info.thread_num < 8) {
                _info.thread_num += 1;
            }
        }
    }
}

void pad_left(void) {
    if (_info.state == STATE_CONFIG) {
        if (_info.v_cursor_pos == 0) {
            if (_info.thread_num >= 2) {
                _info.thread_num -= 1;
            }
        }
    }
}

void pad_r1(void) {
}

extern int D_0008D33C;

void pad_pss_cmd(void) {
    switch (D_0008D33C) {                           /* irregular */
    case 14:
        mpeg_stop(2, 0);
        break;
    case 1:
        change_state(2, 0);
        break;
    }
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/pad", pad_start);

void pad_select(void) {
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/pad", pad_read);
