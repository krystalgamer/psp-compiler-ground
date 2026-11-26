#include "common.h"

/* declarations recovered from DWARF */
typedef void SceVoid;
typedef int SceInt32;
struct _anon1;
typedef int SceUID;
typedef char SceChar8;
struct _anon1 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon1 StrFile;
typedef struct t_conditionCtrl t_conditionCtrl;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x8 */
    SceUID controlFlag;
    SceUID waitFlag;
};
typedef unsigned int SceSize;
typedef unsigned int SceUInt32;
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
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
typedef struct t_ringBuffer t_ringBuffer;
struct t_ringBuffer;
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
struct t_ringBuffer { /* size 0x10 */
    SceInt32 dataLen;
    SceInt32 statusFlag;
    SceMpegRingbuffer *pRingbuf;
    t_conditionCtrl *pCtrl;
};
typedef struct SceMpeg SceMpeg;
struct SceMpeg;
struct SceMpeg { /* size 0x4 */
    void *sys;
};
typedef struct t_mpegStreamData t_mpegStreamData;
struct t_mpegStreamData;
typedef struct SceMpegStream SceMpegStream;
struct SceMpegStream;
typedef SceUInt32 SceMpegStreamId;
typedef unsigned char SceUChar8;
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
struct t_mpegStreamData { /* size 0x10 */
    SceMpegStream *pAvcStream;
    SceMpegAu *pAvcAu;
    SceMpegStream *pAtracStream;
    SceMpegAu *pAtracAu;
};
struct _info;
struct SceNetEtherAddr;
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
typedef struct t_playInfo t_playInfo;
struct t_playInfo;
struct t_playInfo { /* size 0x8 */
    SceInt32 playMode;
    SceUInt32 timestamp;
};
struct _mpeg_info;
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
extern SceInt32 audioFlag;
extern SceUID dispThread;
extern SceUID readThread;
extern SceUID soundThread;
extern int mpeg_tid;
extern int error_code;
extern t_playInfo playInfo;
extern struct _mpeg_info _mpeg_info;

static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData);
int mpeg_exit_func(int count, int arg1, void *arg2);
int mpeg_term(void);
int mpeg_play_thread(SceSize argsize, void *arg);
static int mpeg_init_thread(SceSize argsize, void *arg);
static SceInt32 checkDecodeEnd(t_conditionCtrl *pCtrl);
static SceInt32 checkPlayerErrCondition(t_conditionCtrl *pCtrl);
static SceInt32 setPlayerEndCondition(t_conditionCtrl *pCtrl);
static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_ringBuffer *pRingCtrl, t_avSyncControl *pAvSync, t_conditionCtrl *pCtrl);
static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset);
static int start_mpeg_play_thread(int (*thread_func)(SceSize, void *));
static int start_mpeg_init_thread(int (*thread_func)(SceSize, void *));
static int check_mpeg_init_completed(void);
static int check_mpeg_dialog_completed(void);
static void monitor_mpeg_play_thread(void);
void change_state(enum connect_state state, int error_code);


SceInt32 control_getCondition(t_conditionCtrl *pCtrl, SceUInt32 *pattern);
SceInt32 strFileRead(StrFile *file, void *buff, SceSize size);
static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData)
{
	SceInt32 iTypeSize = 0x800;
	SceInt32 iReadSize;
	StrFile *pStrFile = (StrFile *)CallbackData;

	iReadSize = strFileRead(pStrFile, pBuf, iNum * iTypeSize);
	if (iReadSize < 0)
		return iReadSize;
	if (iReadSize % iTypeSize != 0)
		return -1;
	return iReadSize / iTypeSize;
}

void sceKernelExitGame(void);
void sceKernelExitGame(void);
int mpeg_exit_func(int count, int arg1, void *arg2)
{
	t_conditionCtrl *pCtrl = *(t_conditionCtrl **)arg2;

	if (pCtrl != NULL)
		setPlayerEndCondition(pCtrl);
	strFileUmdReadBreak();
	if (audioFlag == 1) {
		if (soundThread > 0)
			sceKernelWaitThreadEnd(soundThread, 0);
	}
	if (dispThread > 0)
		sceKernelWaitThreadEnd(dispThread, 0);
	if (readThread > 0)
		sceKernelWaitThreadEnd(readThread, 0);
	sceKernelExitGame();
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_main", mpeg_term);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_main", mpeg_play_thread);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_main", mpeg_init_thread);

int startCheck(t_avSyncControl *pAvSync, t_ringBuffer *pRingCtrl, t_conditionCtrl *pCtrl) {
    int var_a0;

    if (audioFlag != 1) {
        if (((dispbuf_getCapacity(pAvSync->pDisp) == 0) && (read_isFull(pRingCtrl) != 0)) || (var_a0 = -1, (checkDecodeEnd(pCtrl) == 1))) {
            goto block_5;
        }
    } else {
        if ((dispbuf_getCapacity(pAvSync->pDisp) != 0) || (soundbuf_getCapacity(pAvSync->pSound) != 0)) {
            goto block_9;
        }
        if (read_isFull(pRingCtrl) == 0) {
block_9:
            var_a0 = -1;
            if (checkDecodeEnd(pCtrl) == 1) {
                goto block_6;
            }
        } else {
block_5:
block_6:
            control_setCondition(pCtrl, 1);
            var_a0 = 0;
        }
    }
    return var_a0;
}

static SceInt32 checkDecodeEnd(t_conditionCtrl *pCtrl)
{
	SceUInt32 cond;

	control_getCondition(pCtrl, &cond);
	if (cond & 8)
		return 1;
	return -1;
}

static SceInt32 checkPlayerErrCondition(t_conditionCtrl *pCtrl)
{
	SceUInt32 pattern;
	SceInt32 ret = 0;

	control_getCondition(pCtrl, &pattern);
	if (pattern & 0x800) {
		if (pattern & 0x400)
			ret = 0x80410C86;
		else if (pattern & 0x200)
			ret = 0x80410C87;
		else if (pattern & 0x100)
			ret = 0x80410C88;
		else
			ret = 0x80410C89;
	}
	return ret;
}

static SceInt32 setPlayerEndCondition(t_conditionCtrl *pCtrl)
{
	control_setCondition(pCtrl, 0xFF);
	return 0;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_main", playMovie);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_main", readHeader);

int sceKernelCreateThread(const char *name, void *entry, int prio, int stacksize, unsigned int attr, void *option);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);
extern int error_code_8341C;
extern char D_0002EFE8[];
static int start_mpeg_play_thread(int (*thread_func)(SceSize, void *))
{
	int ret;

	ret = sceKernelCreateThread(D_0002EFE8, thread_func, 0x21, 0x2000, 0, NULL);
	if (ret < 0)
		goto error;
	mpeg_tid = ret;
	ret = sceKernelStartThread(ret, 0, NULL);
	if (ret < 0)
		goto error;
	change_state(10, 0);
	return 0;

error:
	if (mpeg_tid >= 0) {
		sceKernelDeleteThread(mpeg_tid);
		mpeg_tid = -1;
	}
	error_code_8341C = ret;
	ret = utility_msgdialog_fileio(ret);
	if (ret < 0)
		change_state(1, 0);
	else
		change_state(0x18, 0);
	return ret;
}

extern int error_code_8341C;
extern char D_0002EFE8[];
static int start_mpeg_init_thread(int (*thread_func)(SceSize, void *))
{
	int ret;

	ret = sceKernelCreateThread(D_0002EFE8, thread_func, 0x21, 0x2000, 0, NULL);
	if (ret < 0)
		goto error;
	mpeg_tid = ret;
	ret = sceKernelStartThread(ret, 0, NULL);
	if (ret < 0)
		goto error;
	change_state(12, 0);
	return 0;

error:
	if (mpeg_tid >= 0) {
		sceKernelDeleteThread(mpeg_tid);
		mpeg_tid = -1;
	}
	error_code_8341C = ret;
	ret = utility_msgdialog_mpeg_fileio(ret);
	if (ret < 0)
		change_state(1, 0);
	else
		change_state(0x18, 0);
	return ret;
}

int sceKernelDeleteThread(int thid);
extern int error_code_8341C;
static int check_mpeg_init_completed(void)
{
	int ret;

	ret = sceKernelGetThreadExitStatus(mpeg_tid);
	if (ret == (int)0x800201A4)
		return 0;
	if (ret < 0) {
		if (utility_msgdialog_mpeg_fileio(error_code_8341C) < 0) {
			change_state(1, 0);
		} else {
			net_stop_server();
			change_state(0x18, 0);
		}
	} else {
		change_state(ret, 0);
	}
	sceKernelDeleteThread(mpeg_tid);
	mpeg_tid = -1;
	return 0;
}

extern int D_0008D338;
static int check_mpeg_dialog_completed(void)
{
	int ret;
	int done = 0;

	ret = utility_check_msgdialog_completed(&done);
	if (ret < 0 || done) {
		if (D_0008D338 == 14)
			change_state(0x10, 0);
		else
			change_state(1, 0);
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_main", monitor_mpeg_play_thread);

int mpeg_stop(void) {
    playInfo.playMode = 0xA;
    return 0;
}

INCLUDE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_main", D_0002EFE8);

extern int D_0008D33C;

int mpeg_update(void) {
    switch (D_0008D33C) {
    case 11:
        start_mpeg_init_thread(mpeg_init_thread);
        /* fallthrough */
    default:
        break;
    case 12:
        check_mpeg_init_completed();
        break;
    case 13:
        start_mpeg_play_thread(mpeg_play_thread);
        break;
    case 14:
        monitor_mpeg_play_thread();
        break;
    case 24:
        check_mpeg_dialog_completed();
        break;
    }
    return 0;
}
