#include "common.h"

/* declarations recovered from DWARF */
typedef struct t_soundBuffer t_soundBuffer;
struct t_soundBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
typedef int SceInt32;
typedef struct t_conditionCtrl t_conditionCtrl;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x8 */
    SceUID controlFlag;
    SceUID waitFlag;
};
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
typedef unsigned int SceSize;
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
extern SceInt32 soundframeCount;
extern SceInt32 soundframeDelay;
extern SceInt32 soundIntervalSize;
extern SceChar8 *outputBuf[2];

SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 bufSize, SceInt32 bufNum, t_conditionCtrl *pCtrl);
SceInt32 soundbuf_reset(t_soundBuffer *pSound);
SceInt32 soundbuf_delete(t_soundBuffer *pSound);
SceInt32 soundbuf_setBuf(t_soundBuffer *pSound);
static SceInt32 soundbuf_checkDecodeEnd(t_soundBuffer *pSound);
SceInt32 sound_checkConditionEnd(t_soundBuffer *pSound);
int soundbuf_func(SceSize size, void *argp);
static SceInt32 soundbuf_swapbuf(t_soundBuffer *pSound, SceChar8 *buf);
SceInt32 soundbuf_output(t_soundBuffer *pSound);


int puts(const char *s);
int sceWaveInit(void);
int sceWaveAudioSetSample(int channel, int samples);
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);
void *malloc(unsigned int size);
void *memalign(unsigned int align, unsigned int size);

const char D_0002F068[] = "sound_lockSema";

SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 bufSize, SceInt32 buf_num, t_conditionCtrl *pCtrl)
{
	SceInt32 i, ret;

	pSound->bufSize = bufSize;
	pSound->size = buf_num;
	pSound->pCtrl = pCtrl;

	pSound->buf = NULL;
	pSound->pts = NULL;

	outputBuf[0] = NULL;
	outputBuf[1] = NULL;

	ret = sceWaveInit();
	if (ret != 0) {
		goto error;
	}

	ret = sceWaveAudioSetSample(0, 2048);
	if (ret != 0) {
		goto error;
	}

	ret = sceKernelCreateSema(D_0002F068, 0, 1, 1, NULL);
	if (ret < 0) {
		goto error;
	}
	pSound->lockSema = ret;

	pSound->buf = malloc(pSound->size * sizeof(SceChar8 *));
	if (pSound->buf == NULL) {
		ret = 0x80000022;
		goto error;
	}

	for (i = 0; i < pSound->size; i++) {
		pSound->buf[i] = NULL;
	}

	for (i = 0; i < pSound->size; i++) {
		pSound->buf[i] = memalign(64, pSound->bufSize);
		if (pSound->buf[i] == NULL) {
			ret = 0x80000022;
			goto error;
		}
	}

	pSound->pts = malloc(pSound->size * sizeof(SceUInt32));
	if (pSound->pts == NULL) {
		ret = 0x80000022;
		goto error;
	}

	for (i = 0; i < 2; i++) {
		outputBuf[i] = malloc(pSound->bufSize);
		if (outputBuf[i] == NULL) {
			ret = 0x80000022;
			goto error;
		}
	}

	soundIntervalSize = 4179;

	goto term;

error:
	if (pSound->buf != NULL) {
		for (i = 0; i < pSound->size; i++) {
			if (pSound->buf[i] != NULL) {
				free(pSound->buf[i]);
				pSound->buf[i] = NULL;
			}
		}

		free(pSound->buf);
		pSound->buf = NULL;
	}

	if (pSound->pts != NULL) {
		free(pSound->pts);
		pSound->pts = NULL;
	}

	for (i = 0; i < 2; i++) {
		if (outputBuf[i] != NULL) {
			free(outputBuf[i]);
			outputBuf[i] = NULL;
		}
	}

term:
	return ret;
}

SceInt32 soundbuf_reset(t_soundBuffer *pSound)
{
	soundframeCount = 0;
	soundframeDelay = 0;
	pSound->statusFlag = 1;
	pSound->read = 0;
	pSound->count = 0;
	pSound->write = 0;
	return 0;
}

int sceKernelDeleteSema(int semid);
void free(void *p);
int sceKernelDeleteSema(int semid);
void free(void *p);
SceInt32 soundbuf_delete(t_soundBuffer *pSound)
{
	SceInt32 i;

	sceWaveExit();
	sceKernelDeleteSema(pSound->lockSema);
	if (pSound->buf) {
		for (i = 0; i < pSound->size; i++) {
			if (pSound->buf[i]) {
				free(pSound->buf[i]);
				pSound->buf[i] = NULL;
			}
		}
		free(pSound->buf);
		pSound->buf = NULL;
	}
	if (pSound->pts) {
		free(pSound->pts);
		pSound->pts = NULL;
	}
	for (i = 0; i < 2; i++) {
		if (outputBuf[i]) {
			free(outputBuf[i]);
			outputBuf[i] = NULL;
		}
	}
	return 0;
}

int soundbuf_getDrawbuf(t_soundBuffer *pSound, signed char **buffer) {
    int temp_v0;

    temp_v0 = soundbuf_getCapacity(pSound);
    if (temp_v0 > 0) {
        *buffer = pSound->buf[pSound->write];
    } else {
        *buffer = NULL;
    }
    return temp_v0;
}

int soundbuf_setStartPts(t_soundBuffer *pSound, unsigned int pts) {
    pSound->soundLatestPts = pts;
    return 0;
}

int soundbuf_setPts(t_soundBuffer *pSound, unsigned int pts) {
    unsigned int var_a1;

    var_a1 = pts;
    if (var_a1 == -1U) {
        var_a1 = pSound->soundLatestPts + soundIntervalSize;
    }
    pSound->soundLatestPts = var_a1;
    pSound->pts[pSound->write] = var_a1;
    return 0;
}

int soundbuf_getPts(t_soundBuffer *pSound, unsigned int *pPts) {
    *pPts = pSound->pts[pSound->read];
    return 0;
}

int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
SceInt32 soundbuf_setBuf(t_soundBuffer *pSound)
{
	sceKernelWaitSema(pSound->lockSema, 1, NULL);
	pSound->count++;
	sceKernelSignalSema(pSound->lockSema, 1);
	pSound->write = (pSound->write + 1) % pSound->size;
	return 0;
}

int soundbuf_getCapacity(t_soundBuffer *pSound) {
    return pSound->size - pSound->count;
}

int soundbuf_getCurrentCount(t_soundBuffer *pSound) {
    return pSound->count;
}

static SceInt32 soundbuf_checkDecodeEnd(t_soundBuffer *pSound)
{
	SceUInt32 pattern;

	control_getCondition(pSound->pCtrl, &pattern);
	if (pattern & 0x8)
		return 1;
	return 0;
}

int sound_sendErrCondition(t_soundBuffer *pSound) {
    control_setCondition(pSound->pCtrl, 0x900);
    return 0;
}

int sound_getStatus(t_soundBuffer *pSound) {
    return pSound->statusFlag;
}

int sound_setStatus(t_soundBuffer *pSound, int status) {
    pSound->statusFlag = status;
    return 0;
}

SceInt32 sound_checkConditionEnd(t_soundBuffer *pSound)
{
	SceUInt32 pattern;

	control_getCondition(pSound->pCtrl, &pattern);
	if ((pattern & 0xFF) == 0xFF)
		sound_setStatus(pSound, 3);
	return 0;
}

int sceKernelDelayThread(unsigned int delay);
void *memcpy(void *d, const void *s, unsigned int n);
SceInt32 control_setCondition(t_conditionCtrl *pCtrl, SceInt32 cond);
SceInt32 control_waitConditionSoundStart(t_conditionCtrl *pCtrl);
int sceWaveAudioGetRestSample(int channel);
int sceWaveAudioWriteBlocking(int channel, int vol1, int vol2, void *buf);
int sceKernelExitThread(int status);
int sceKernelDelayThread(unsigned int delay);
int sceKernelWaitSema(SceUID semid, int signal, unsigned int *timeout);
int sceKernelSignalSema(SceUID semid, int signal);
void *memcpy(void *dst, const void *src, unsigned int n);
extern SceInt32 D_0008343C;
extern SceInt32 D_0008D34C;
int soundbuf_func(SceSize size, void *argp)
{
	SceInt32 ret;
	t_avSyncControl **ppAvSync;
	t_avSyncControl *pAvSync;
	t_soundBuffer *pSound;

	ppAvSync = argp;
	pAvSync = *ppAvSync;
	pSound = pAvSync->pSound;
	control_waitConditionSoundStart(pSound->pCtrl);
	for (;;) {
		sound_checkConditionEnd(pSound);
		if (sound_getStatus(pSound) == 3)
			break;
		if (soundbuf_checkDecodeEnd(pSound) == 1 && soundbuf_getCurrentCount(pSound) == 0)
			break;
		if (soundbuf_getCurrentCount(pSound) > 0) {
			ret = soundbuf_output(pSound);
			if (ret < 0) {
				D_0008D34C = ret;
				sound_sendErrCondition(pSound);
				return 1;
			}
			sceKernelWaitSema(pSound->lockSema, 1, NULL);
			pSound->count--;
			sceKernelSignalSema(pSound->lockSema, 1);
			soundframeCount++;
		} else {
			soundframeDelay++;
			sceKernelDelayThread(1000);
		}
	}
	while (sceWaveAudioGetRestSample(0) != 0)
		sceKernelDelayThread(1000);
	control_setCondition(pSound->pCtrl, 0x20);
	sceKernelExitThread(0);
	return 0;
}

static SceInt32 soundbuf_swapbuf(t_soundBuffer *pSound, SceChar8 *buf)
{
	SceInt32 ret;

	memcpy(outputBuf[D_0008343C], buf, pSound->bufSize);
	pSound->read = (pSound->read + 1) % pSound->size;
	ret = sceWaveAudioWriteBlocking(0, 0x8000, 0x8000, outputBuf[D_0008343C]);
	if (ret >= 0)
		D_0008343C ^= 1;
	return ret;
}

SceInt32 soundbuf_output(t_soundBuffer *pSound)
{
	SceChar8 *buf = pSound->buf[pSound->read];

	return soundbuf_swapbuf(pSound, buf);
}
