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

void free(void *p);
int sceKernelWaitThreadEnd(SceUID thid, unsigned int *timeout);
int sceKernelDeleteThread(SceUID thid);
int sceKernelTerminateDeleteThread(SceUID thid);
int sceKernelDeleteEventFlag(int evid);
SceInt32 read_delete(t_ringBuffer *pRing);
SceInt32 avsync_delete(t_avSyncControl *pAvSync);
SceInt32 soundbuf_delete(t_soundBuffer *pSound);
SceInt32 dispbuf_delete(t_displayBuffer *pDisp);
SceInt32 control_delete(t_conditionCtrl *pCtrl);
SceInt32 strFileClose(StrFile *file);
SceInt32 strFileUnassign(StrFile *file);
SceInt32 sceMpegFreeAvcEsBuf(SceMpeg *mpeg, SceMpegHandle buf);
SceInt32 sceMpegUnRegistStream(SceMpeg *mpeg, SceMpegStream *stream);
SceInt32 sceMpegDelete(SceMpeg *mpeg);
SceVoid sceMpegRingbufferDestruct(SceMpegRingbuffer *rb);
SceVoid sceMpegFinish(SceVoid);
void free(void *p);
int mpeg_term(void)
{
	int ret = 0;

	if (audioFlag == 1)
		sceKernelWaitThreadEnd(soundThread, NULL);
	sceKernelWaitThreadEnd(dispThread, NULL);
	sceKernelWaitThreadEnd(readThread, NULL);
	if (audioFlag == 1)
		sceKernelDeleteThread(soundThread);
	sceKernelDeleteThread(dispThread);
	sceKernelDeleteThread(readThread);
	if (_mpeg_info.pRing != NULL) {
		read_delete(_mpeg_info.pRing);
		free(_mpeg_info.pRing);
		_mpeg_info.pRing = NULL;
	}
	if (_mpeg_info.pAvSync != NULL) {
		avsync_delete(_mpeg_info.pAvSync);
		free(_mpeg_info.pAvSync);
		_mpeg_info.pAvSync = NULL;
	}
	if (_mpeg_info.pSound != NULL) {
		soundbuf_delete(_mpeg_info.pSound);
		free(_mpeg_info.pSound);
		_mpeg_info.pSound = NULL;
	}
	if (_mpeg_info.pDisp != NULL) {
		dispbuf_delete(_mpeg_info.pDisp);
		free(_mpeg_info.pDisp);
		_mpeg_info.pDisp = NULL;
	}
	if (_mpeg_info.pCtrl != NULL) {
		control_delete(_mpeg_info.pCtrl);
		free(_mpeg_info.pCtrl);
		_mpeg_info.pCtrl = NULL;
	}
	if (_mpeg_info.pStreamData != NULL) {
		free(_mpeg_info.pStreamData);
		_mpeg_info.pStreamData = NULL;
	}
	if (audioFlag == 1 && _mpeg_info.pAudioBuf != NULL) {
		free(_mpeg_info.pAudioBuf);
		_mpeg_info.pAudioBuf = NULL;
	}
	if (_mpeg_info.avcEsBuf != NULL) {
		sceMpegFreeAvcEsBuf(&_mpeg_info.mpeg, _mpeg_info.avcEsBuf);
		_mpeg_info.avcEsBuf = NULL;
	}
	if (_mpeg_info.pStream[0] != NULL) {
		sceMpegUnRegistStream(&_mpeg_info.mpeg, _mpeg_info.pStream[0]);
		_mpeg_info.pStream[0] = NULL;
	}
	if (audioFlag == 1 && _mpeg_info.pStream[1] != NULL) {
		sceMpegUnRegistStream(&_mpeg_info.mpeg, _mpeg_info.pStream[1]);
		_mpeg_info.pStream[1] = NULL;
	}
	strFileClose(&_mpeg_info.strFile);
	sceMpegDelete(&_mpeg_info.mpeg);
	sceMpegRingbufferDestruct(&_mpeg_info.ringbuf);
	sceMpegFinish();
	if (_mpeg_info.pWorkBuf != NULL)
		free(_mpeg_info.pWorkBuf);
	if (_mpeg_info.pPSPStream != NULL)
		free(_mpeg_info.pPSPStream);
	strFileUnassign(&_mpeg_info.strFile);
	if (mpeg_tid > 0) {
		sceKernelTerminateDeleteThread(mpeg_tid);
		mpeg_tid = -1;
	}
	if (_mpeg_info.evf_id > 0) {
		sceKernelDeleteEventFlag(_mpeg_info.evf_id);
		_mpeg_info.evf_id = -1;
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_main", mpeg_play_thread);

void *memset(void *s, int c, unsigned int n);
char *strcpy(char *d, const char *s);
void *malloc(unsigned int size);
void *memalign(unsigned int align, unsigned int size);
SceInt32 strFileAssign(StrFile *file, const char *filename);
SceInt32 strFileOpenCB(StrFile *file, const char *filename, SceInt32 mode);
SceInt32 sceMpegInit(SceVoid);
SceInt32 sceMpegRingbufferQueryMemSize(SceInt32 iPackNum);
SceInt32 sceMpegQueryMemSize(SceInt32 iReserved);
SceInt32 sceMpegRingbufferConstruct(SceMpegRingbuffer *rb, SceInt32 iPackNum, SceVoid *pData, SceInt32 iSize, void *callback, SceVoid *cbdata);
SceInt32 sceMpegCreate(SceMpeg *mpeg, SceVoid *pData, SceInt32 iSize, SceMpegRingbuffer *rb, SceInt32 iFrameWidth, SceInt32 iReserved1, SceInt32 iReserved2);
SceMpegStream *sceMpegRegistStream(SceMpeg *mpeg, SceInt32 iStreamID, SceInt32 iStreamNum);
SceMpegHandle sceMpegMallocAvcEsBuf(SceMpeg *mpeg);
SceInt32 sceMpegInitAu(SceMpeg *mpeg, SceVoid *pEsBuffer, SceMpegAu *pAu);
SceInt32 sceMpegQueryAtracEsSize(SceMpeg *mpeg, SceInt32 *iEsSize, SceInt32 *iOutSize);
void *memalign(unsigned int align, unsigned int size);
void *malloc(unsigned int size);
void *memset(void *s, int c, unsigned int n);
char *strcpy(char *d, const char *s);
char *strncat(char *d, const char *s, unsigned int n);
SceInt32 decode_setStreamData(t_mpegStreamData *pStreamData, SceMpegStream *pStreamV, SceMpegAu *pAvcAu, SceMpegStream *pStreamA, SceMpegAu *pAtracAu);
SceInt32 control_create(t_conditionCtrl *pCtrl);
SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 dispSize, SceInt32 dispNum, t_conditionCtrl *pCtrl);
SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 size, SceInt32 num, t_conditionCtrl *pCtrl);
SceInt32 read_create(t_ringBuffer *pRing, SceMpegRingbuffer *pRB, t_conditionCtrl *pCtrl);
SceInt32 avsync_create(t_avSyncControl *pAvSync, t_displayBuffer *pDisp, t_soundBuffer *pSound, SceInt32 videoNum);
int dispbuf_func(SceSize size, void *argp);
int read_func(SceSize size, void *argp);
int soundbuf_func(SceSize size, void *argp);
int sceKernelCreateEventFlag(const char *name, int attr, int bits, void *opt);
extern char D_0008D46C[];
extern int error_code_8341C;
static int mpeg_init_thread(SceSize argsize, void *arg)
{
	int ret;

	memset(&_mpeg_info, 0, sizeof(_mpeg_info));
	strcpy((char *)_mpeg_info.filename, "ms0:/");
	strncat((char *)_mpeg_info.filename, D_0008D46C, 256);
	_mpeg_info.pDisp = NULL;
	_mpeg_info.pRing = NULL;
	_mpeg_info.pSound = NULL;
	_mpeg_info.pAvSync = NULL;
	_mpeg_info.pCtrl = NULL;
	_mpeg_info.pStreamData = NULL;
	_mpeg_info.avcEsBuf = NULL;
	_mpeg_info.pPSPStream = NULL;
	_mpeg_info.pWorkBuf = NULL;
	_mpeg_info.pAudioBuf = NULL;
	_mpeg_info.pStream[0] = NULL;
	_mpeg_info.pStream[1] = NULL;
	audioFlag = 1;
	ret = strFileAssign(&_mpeg_info.strFile, (char *)_mpeg_info.filename);
	if (ret < 0)
		goto term4;
	ret = sceMpegInit();
	if (ret != 0)
		goto term3;
	ret = sceMpegRingbufferQueryMemSize(960);
	if (ret < 0)
		goto term3;
	_mpeg_info.bufferSize = ret;
	ret = sceMpegQueryMemSize(0);
	if (ret < 0)
		goto term3;
	_mpeg_info.workSize = ret;
	_mpeg_info.pPSPStream = malloc(_mpeg_info.bufferSize);
	if (_mpeg_info.pPSPStream == NULL) {
		ret = 0x80000022;
		goto term3;
	}
	_mpeg_info.pWorkBuf = malloc(_mpeg_info.workSize);
	if (_mpeg_info.pWorkBuf == NULL) {
		ret = 0x80000022;
		goto term3;
	}
	ret = sceMpegRingbufferConstruct(&_mpeg_info.ringbuf, 960, _mpeg_info.pPSPStream, _mpeg_info.bufferSize, ringbufferCallBack, &_mpeg_info.strFile);
	if (ret != 0)
		goto term3;
	ret = sceMpegCreate(&_mpeg_info.mpeg, _mpeg_info.pWorkBuf, _mpeg_info.workSize, &_mpeg_info.ringbuf, 512, 0, 0);
	if (ret != 0)
		goto term3;
	ret = strFileOpenCB(&_mpeg_info.strFile, (char *)_mpeg_info.filename, 1);
	if (ret < 0)
		goto term3;
	ret = readHeader(&_mpeg_info.mpeg, &_mpeg_info.strFile, &_mpeg_info.fileSize, &_mpeg_info.streamOffset);
	if (ret < 0)
		goto term3;
	_mpeg_info.pStream[0] = sceMpegRegistStream(&_mpeg_info.mpeg, 0, 0);
	if (_mpeg_info.pStream[0] == NULL) {
		ret = 0x80410C83;
		goto term3;
	}
	if (audioFlag == 1) {
		_mpeg_info.pStream[1] = sceMpegRegistStream(&_mpeg_info.mpeg, 1, 0);
		if (_mpeg_info.pStream[1] == NULL) {
			ret = 0x80410C83;
			goto term3;
		}
	}
	_mpeg_info.avcEsBuf = sceMpegMallocAvcEsBuf(&_mpeg_info.mpeg);
	if (_mpeg_info.avcEsBuf == NULL) {
		ret = 0x80410C83;
		goto term3;
	}
	ret = sceMpegInitAu(&_mpeg_info.mpeg, _mpeg_info.avcEsBuf, &_mpeg_info.avcAu);
	if (ret != 0)
		goto term3;
	if (audioFlag == 1) {
		ret = sceMpegQueryAtracEsSize(&_mpeg_info.mpeg, &_mpeg_info.audioEsSize, &_mpeg_info.audioOutSize);
		if (ret != 0)
			goto term3;
		_mpeg_info.pAudioBuf = memalign(64, _mpeg_info.audioEsSize);
		if (_mpeg_info.pAudioBuf == NULL) {
			ret = 0x80000022;
			goto term3;
		}
		ret = sceMpegInitAu(&_mpeg_info.mpeg, _mpeg_info.pAudioBuf, &_mpeg_info.atracAu);
		if (ret != 0)
			goto term3;
	}
	_mpeg_info.pStreamData = malloc(sizeof(t_mpegStreamData));
	if (_mpeg_info.pStreamData == NULL) {
		ret = 0x80000022;
		goto term2;
	}
	decode_setStreamData(_mpeg_info.pStreamData, _mpeg_info.pStream[0], &_mpeg_info.avcAu, _mpeg_info.pStream[1], &_mpeg_info.atracAu);
	_mpeg_info.pCtrl = malloc(sizeof(t_conditionCtrl));
	if (_mpeg_info.pCtrl == NULL) {
		ret = 0x80000022;
		goto term2;
	}
	ret = control_create(_mpeg_info.pCtrl);
	if (ret < 0)
		goto term2;
	_mpeg_info.pDisp = malloc(sizeof(t_displayBuffer));
	if (_mpeg_info.pDisp == NULL) {
		ret = 0x80000022;
		goto term2;
	}
	ret = dispbuf_create(_mpeg_info.pDisp, 0x88000, 4, _mpeg_info.pCtrl);
	if (ret < 0)
		goto term2;
	if (audioFlag == 1) {
		_mpeg_info.pSound = malloc(sizeof(t_soundBuffer));
		if (_mpeg_info.pSound == NULL) {
			ret = 0x80000022;
			goto term2;
		}
		ret = soundbuf_create(_mpeg_info.pSound, _mpeg_info.audioOutSize, 4, _mpeg_info.pCtrl);
		if (ret < 0)
			goto term2;
	}
	_mpeg_info.pRing = malloc(sizeof(t_ringBuffer));
	if (_mpeg_info.pRing == NULL) {
		ret = 0x80000022;
		goto term2;
	}
	ret = read_create(_mpeg_info.pRing, &_mpeg_info.ringbuf, _mpeg_info.pCtrl);
	if (ret < 0)
		goto term2;
	_mpeg_info.pAvSync = malloc(sizeof(t_avSyncControl));
	if (_mpeg_info.pAvSync == NULL) {
		ret = 0x80000022;
		goto term2;
	}
	ret = avsync_create(_mpeg_info.pAvSync, _mpeg_info.pDisp, _mpeg_info.pSound, 6);
	if (ret < 0)
		goto term2;
	ret = sceKernelCreateThread("displayThread", dispbuf_func, 0x20, 0x800, 0, NULL);
	if (ret < 0)
		goto term2;
	dispThread = ret;
	ret = sceKernelCreateThread("readThread", read_func, 0x22, 0x800, 0, NULL);
	if (ret < 0)
		goto term2;
	readThread = ret;
	if (audioFlag == 1) {
		ret = sceKernelCreateThread("soundThread", soundbuf_func, 0x14, 0x800, 0, NULL);
		if (ret < 0)
			goto term2;
		soundThread = ret;
	}
	ret = sceKernelCreateEventFlag("MpegPlayerEventFlag", 0, 1, NULL);
	if (ret < 0)
		goto term2;
	_mpeg_info.evf_id = ret;
	playInfo.playMode = 0;
	return 6;
term2:
	if (_mpeg_info.evf_id > 0) {
		sceKernelDeleteEventFlag(_mpeg_info.evf_id);
		_mpeg_info.evf_id = -1;
	}
	if (_mpeg_info.pRing != NULL) {
		read_delete(_mpeg_info.pRing);
		free(_mpeg_info.pRing);
		_mpeg_info.pRing = NULL;
	}
	if (_mpeg_info.pAvSync != NULL) {
		avsync_delete(_mpeg_info.pAvSync);
		free(_mpeg_info.pAvSync);
		_mpeg_info.pAvSync = NULL;
	}
	if (_mpeg_info.pSound != NULL) {
		soundbuf_delete(_mpeg_info.pSound);
		free(_mpeg_info.pSound);
		_mpeg_info.pSound = NULL;
	}
	if (_mpeg_info.pDisp != NULL) {
		dispbuf_delete(_mpeg_info.pDisp);
		free(_mpeg_info.pDisp);
		_mpeg_info.pDisp = NULL;
	}
	if (_mpeg_info.pCtrl != NULL) {
		control_delete(_mpeg_info.pCtrl);
		free(_mpeg_info.pCtrl);
		_mpeg_info.pCtrl = NULL;
	}
	if (_mpeg_info.pStreamData != NULL) {
		free(_mpeg_info.pStreamData);
		_mpeg_info.pStreamData = NULL;
	}
term3:
	if (audioFlag == 1 && _mpeg_info.pAudioBuf != NULL) {
		free(_mpeg_info.pAudioBuf);
		_mpeg_info.pAudioBuf = NULL;
	}
	if (_mpeg_info.avcEsBuf != NULL) {
		sceMpegFreeAvcEsBuf(&_mpeg_info.mpeg, _mpeg_info.avcEsBuf);
		_mpeg_info.avcEsBuf = NULL;
	}
	if (_mpeg_info.pStream[0] != NULL) {
		sceMpegUnRegistStream(&_mpeg_info.mpeg, _mpeg_info.pStream[0]);
		_mpeg_info.pStream[0] = NULL;
	}
	if (audioFlag == 1 && _mpeg_info.pStream[1] != NULL) {
		sceMpegUnRegistStream(&_mpeg_info.mpeg, _mpeg_info.pStream[1]);
		_mpeg_info.pStream[1] = NULL;
	}
	strFileClose(&_mpeg_info.strFile);
	sceMpegDelete(&_mpeg_info.mpeg);
	sceMpegRingbufferDestruct(&_mpeg_info.ringbuf);
	sceMpegFinish();
	if (_mpeg_info.pWorkBuf != NULL)
		free(_mpeg_info.pWorkBuf);
	if (_mpeg_info.pPSPStream != NULL)
		free(_mpeg_info.pPSPStream);
term4:
	strFileUnassign(&_mpeg_info.strFile);
	error_code_8341C = ret;
	return -1;
}

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

static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_ringBuffer *pRingCtrl, t_avSyncControl *pAvSync, t_conditionCtrl *pCtrl)
{
	SceInt32 audio_init_flag;
	SceInt32 ret;
	SceInt32 startFlag;

	audio_init_flag = 1;
	startFlag = -1;

	while (read_isFull(pRingCtrl) != 1) {
		ret = checkPlayerErrCondition(pCtrl);
		if (ret != 0)
			goto error;
		control_waitDecode(pCtrl);
		sceKernelDelayThreadCB(1000);
	}

	while (1) {
		if (startFlag != 0) {
			startFlag = startCheck(pAvSync, pRingCtrl, pCtrl);
		} else {
			if (playInfo.playMode == 0xA) {
				ret = sceMpegAvcDecodeFlush(pMpeg);
				if (ret < 0)
					goto error;
				setPlayerEndCondition(pCtrl);
				return 1;
			}
		}

		if (read_isEnd(pRingCtrl) == 1 && sceMpegRingbufferAvailableSize(pRB) == 0x3C0)
			break;

		ret = checkPlayerErrCondition(pCtrl);
		if (ret != 0)
			goto error;

		if (audioFlag == 1) {
			ret = decode_audioDecode(pMpeg, pStreamData, pAvSync, audio_init_flag);
			if (ret >= 0) {
				audio_init_flag = 0;
			} else if (ret == (SceInt32)0x80618001) {
			} else {
				goto error;
			}
		}

		ret = decode_videoDecode(pMpeg, pStreamData, pAvSync);
		if (ret == (SceInt32)0x80618001) {
		} else if (ret < 0) {
			goto error;
		}

		control_waitDecode(pCtrl);
		sceKernelCheckCallback();
	}

	control_setCondition(pCtrl, 8);

	do {
		ret = decode_videoDecodeEnd(pMpeg, pAvSync);
		if (ret < 0)
			goto error;
		control_waitDecode(pCtrl);
	} while (ret != 0);

error:
	setPlayerEndCondition(pCtrl);
	return ret;
}

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
