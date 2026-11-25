#include "common.h"

/* declarations recovered from DWARF */
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
typedef int SceUID;
typedef int SceInt32;
typedef char SceChar8;
typedef unsigned int SceUInt32;
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
typedef struct SceKernelEventFlagInfo SceKernelEventFlagInfo;
struct SceKernelEventFlagInfo;
typedef unsigned int SceSize;
typedef unsigned int SceUInt;
struct SceKernelEventFlagInfo { /* size 0x34 */
    SceSize size;
    char name[32];
    SceUInt attr;
    SceUInt initPattern;
    SceUInt currentPattern;
    int numWaitThreads;
};
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
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
extern SceInt32 frameCount;
extern SceInt32 frameLoss;
extern SceChar8 *displayBuf[2];

SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 dispSize, SceInt32 dispNum, t_conditionCtrl *pCtrl);
static SceInt32 swap_buffer(SceChar8 *buffer);
SceInt32 dispbuf_reset(t_displayBuffer *pDisp);
SceInt32 dispbuf_delete(t_displayBuffer *pDisp);
SceInt32 dispbuf_dataSet(t_displayBuffer *pDisp);
static SceInt32 dispbuf_checkDecodeEnd(t_displayBuffer *pDisp);
SceInt32 dispbuf_checkDelayMode(t_displayBuffer *pDisp);
SceInt32 disp_checkConditionEnd(t_displayBuffer *pDisp);
int dispbuf_func(SceSize size, void *argp);
SceInt32 dispbuf_show(t_displayBuffer *pDisp);


INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_display", dispbuf_create);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_display", swap_buffer);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_display", dispbuf_reset);

int sceKernelDeleteSema(int semid);
void free(void *p);
int sceKernelDeleteSema(int semid);
void free(void *p);
SceInt32 dispbuf_delete(t_displayBuffer *pDisp)
{
	SceInt32 i;

	if (pDisp->buf) {
		for (i = 0; i < pDisp->size; i++) {
			if (pDisp->buf[i]) {
				free(pDisp->buf[i]);
				pDisp->buf[i] = NULL;
			}
		}
		free(pDisp->buf);
		pDisp->buf = NULL;
	}
	if (pDisp->pts) {
		free(pDisp->pts);
		pDisp->pts = NULL;
	}
	sceKernelDeleteSema(pDisp->lockSema);
	sceKernelDeleteEventFlag(pDisp->delayFlag);
	return 0;
}

int dispbuf_getDrawbuf(t_displayBuffer *pDisp, signed char **buffer) {
    int temp_v0;

    temp_v0 = dispbuf_getCapacity(pDisp);
    if (temp_v0 > 0) {
        *buffer = pDisp->buf[pDisp->write];
    } else {
        *buffer = NULL;
    }
    return temp_v0;
}

int dispbuf_setPts(t_displayBuffer *pDisp, unsigned int pts) {
    pDisp->pts[pDisp->write] = pts;
    return 0;
}

int dispbuf_getPts(t_displayBuffer *pDisp, unsigned int *pPts) {
    *pPts = pDisp->pts[pDisp->read];
    return 0;
}

int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
SceInt32 dispbuf_dataSet(t_displayBuffer *pDisp)
{
	sceKernelWaitSema(pDisp->lockSema, 1, NULL);
	pDisp->count++;
	pDisp->write = (pDisp->write + 1) % pDisp->size;
	sceKernelSignalSema(pDisp->lockSema, 1);
	return 0;
}

int dispbuf_getCapacity(t_displayBuffer *pDisp) {
    return pDisp->size - pDisp->count;
}

int dispbuf_getCurrentCount(t_displayBuffer *pDisp) {
    return pDisp->count;
}

static SceInt32 dispbuf_checkDecodeEnd(t_displayBuffer *pDisp)
{
	SceUInt32 pattern;

	control_getCondition(pDisp->pCtrl, &pattern);
	if (pattern & 0x8) {
		dispbuf_setMode(pDisp, 0xff);
		return 1;
	}
	return 0;
}

int dispbuf_setMode(t_displayBuffer *pDisp, int mode) {
    pDisp->displayMode = mode;
    return 0;
}

int dispbuf_getMode(t_displayBuffer *pDisp) {
    return pDisp->displayMode;
}

int dispbuf_setDelayMode(t_displayBuffer *pDisp) {
    return sceKernelSetEventFlag(pDisp->delayFlag, 1);
}

int dispbuf_setPlayMode(t_displayBuffer *pDisp) {
    return sceKernelClearEventFlag(pDisp->delayFlag, 0);
}

SceInt32 dispbuf_checkDelayMode(t_displayBuffer *pDisp)
{
	SceKernelEventFlagInfo info;
	SceInt32 ret;

	info.size = sizeof(info);
	sceKernelReferEventFlagStatus(pDisp->delayFlag, &info);
	if (info.currentPattern == 1)
		ret = 1;
	else
		ret = 0;
	return ret;
}

int display_sendErrCondition(t_displayBuffer *pDisp) {
    control_setCondition(pDisp->pCtrl, 0xA00);
    return 0;
}

int disp_getStatus(t_displayBuffer *pDisp) {
    return pDisp->statusFlag;
}

int disp_setStatus(t_displayBuffer *pDisp, int status) {
    pDisp->statusFlag = status;
    return 0;
}

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_display", disp_checkConditionEnd);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_display", dispbuf_func);

INCLUDE_ASM("tmp/asm/psp184/UCJS90007/nonmatchings/mpeg_display", dispbuf_show);
