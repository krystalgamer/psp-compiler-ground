/* cflags: -O2 */
#include "common.h"

/* declarations recovered from DWARF (UTST99332 mpeg_ezmpegstr main) */
typedef int SceInt32;
typedef void SceVoid;
typedef struct t_soundBuffer t_soundBuffer;
struct t_soundBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
struct t_soundBuffer { /* size 0x28 */
    SceUID lock_sema;
    SceUID status_flag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 buf_size;
    SceUInt32 soundLatestTimestamp;
};
typedef struct SceKernelLMOption SceKernelLMOption;
struct SceKernelLMOption;
typedef unsigned int SceSize;
struct SceKernelLMOption { /* size 0x14 */
    SceSize size;
    SceUID mpidtext;
    SceUID mpiddata;
    unsigned int flags;
    char position;
    char access;
    char creserved[2];
};
struct _anon1;
struct _anon1 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon1 StrFile;
typedef struct SceMpeg SceMpeg;
struct SceMpeg;
struct SceMpeg { /* size 0x4 */
    SceVoid *sys;
};
typedef struct SceMpegRingbuffer SceMpegRingbuffer;
struct SceMpegRingbuffer;
typedef SceInt32 (*SceMpegRBCallback)(SceVoid *, SceInt32, SceVoid *);
struct SceMpegRingbuffer { /* size 0x2c */
    SceInt32 m_iBufsize;
    SceInt32 m_iRpos;
    SceInt32 m_iWpos;
    SceInt32 m_iInlen;
    SceInt32 m_iTypeSize;
    SceVoid *m_pBuf;
    SceMpegRBCallback callback;
    SceVoid *m_CallbackData;
    SceVoid *pPack;
    SceInt32 iSemaRB;
    SceVoid *mp;
};
typedef struct SceMpegStream SceMpegStream;
struct SceMpegStream;
typedef SceUInt32 SceMpegStreamId;
typedef unsigned char SceUChar8;
typedef short int SceShort16;
struct SceMpegStream { /* size 0x40 */
    SceMpegStreamId qStreamId;
    SceMpegStreamId qStreamIdMask;
    SceVoid *m_pRAPICtrlStream;
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
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
struct t_displayBuffer { /* size 0x28 */
    SceUID start_sema;
    SceUID lock_sema;
    SceUID display_wait_sema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 displayMode;
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
typedef struct SceCtrlData SceCtrlData;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
struct _scemoduleinfo;
struct _scemoduleinfo { /* size 0x34 */
    short unsigned int modattribute;
    unsigned char modversion[2];
    char modname[27];
    char terminal;
    void *gp_value;
    const void *ent_top;
    const void *ent_end;
    const void *stub_top;
    const void *stub_end;
};
typedef struct t_playInfo t_playInfo;
struct t_playInfo;
struct t_playInfo { /* size 0x8 */
    SceInt32 playMode;
    SceUInt32 timestamp;
};

extern int _gp[];
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern SceInt32 sce_newlib_heap_kb_size;
extern t_playInfo playInfo;
extern SceInt32 audioFlag;
extern SceInt32 frameCount;
extern SceInt32 frameLoss;
extern SceUID soundThread;

static SceInt32 exit_func(SceInt32 count, SceInt32 arg1, SceVoid *arg2);
static SceInt32 loadModule(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option);
static SceInt32 unloadModule(SceUID *mid);
static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData);
SceInt32 main(SceInt32 argc, SceChar8 **argv);
static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset);
static SceInt32 pad_read(void);
static SceInt32 readPspStream(SceMpegRingbuffer *pRB);
static SceInt32 startCheck(t_avSyncControl *pAvSync, SceMpegRingbuffer *pRB, SceInt32 filesize, SceInt32 demuxsize);
static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync, SceInt32 filesize);

extern SceUID videoMid;
extern SceUID baseMid;
extern SceUID mpegMid;
int module_file_start(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option);
int strFileReadNoRetry(StrFile *file, void *buff, unsigned int size);
int sceKernelStopModule(SceUID modid, SceSize argsize, void *argp, int *status, void *option);
int sceKernelUnloadModule(SceUID modid);
static SceInt32 loadModule(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option)
{
	module_file_start(mid, filename, option);
	return 0;
}

static SceInt32 unloadModule(SceUID *mid)
{
	int status;

	if (sceKernelStopModule(*mid, 0, NULL, &status, NULL) < 0)
		return -1;
	if (sceKernelUnloadModule(*mid) < 0)
		return -1;
	return 0;
}

static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData)
{
	SceInt32 iTypeSize;
	SceInt32 iReadSize;
	SceInt32 ret;

	iTypeSize = 2048;
	iReadSize = strFileReadNoRetry((StrFile *)CallbackData, pBuf, iTypeSize * iNum);
	if (iReadSize == 0x80210003 || iReadSize == 0x80210001)
		ret = 0;
	else
		ret = (iReadSize % iTypeSize) ? -1 : iReadSize / iTypeSize;
	return ret;
}

void mpeg_init(void)
{
	SceKernelLMOption option;
	SceKernelLMOption option2;

	option.size = sizeof(option);
	option.mpidtext = 1;
	option.mpiddata = 1;
	option.position = 0;
	option.access = 1;
	option2.size = sizeof(option2);
	option2.mpidtext = 2;
	option2.mpiddata = 2;
	option2.position = 0;
	option2.access = 1;
	if (loadModule(&videoMid, "disc0:/PSP_GAME/USRDIR/kmodule/videocodec.prx", &option) != 0)
		goto err;
	if (loadModule(&baseMid, "disc0:/PSP_GAME/USRDIR/kmodule/mpegbase.prx", &option) != 0)
		goto err;
	if (loadModule(&mpegMid, "disc0:/PSP_GAME/USRDIR/module/mpeg.prx", &option2) != 0)
		goto err;
	return;
err:
	unloadModule(&mpegMid);
	unloadModule(&baseMid);
	unloadModule(&videoMid);
}

void mpeg_end(void)
{
	unloadModule(&mpegMid);
	unloadModule(&baseMid);
	unloadModule(&videoMid);
}

long long strFileLseek(StrFile *file, long long offset, SceInt32 whence);
void *psp_malloc(unsigned int size);
void psp_free(void *p);
char *strcpy(char *d, const char *s);
char *strcat(char *d, const char *s);
void *memset(void *s, int c, unsigned int n);
SceInt32 strFileOpenCB(StrFile *file, const SceChar8 *filename, SceInt32 flags);
int soundbuf_func(SceSize size, void *argp);
SceInt32 mpeg_main(SceChar8 *name, SceInt32 mode)
{
	SceMpegRingbuffer ringbuf;
	SceMpegStream *pStream[2];
	SceMpegAu avcAu;
	SceMpegAu atracAu;
	StrFile strFile;
	SceMpeg mpeg;
	SceInt32 fileSize, streamOffset;
	SceInt32 audioEsSize, audioOutSize;
	t_avSyncControl *pAvSync = NULL;
	SceChar8 *pAudioBuf;
	SceChar8 *filename = "host0:demo01.pmf";
	SceInt32 bufferSize, workSize, ret;
	t_displayBuffer *pDisp = NULL;
	t_soundBuffer *pSound = NULL;
	t_mpegStreamData *pStreamData;
	SceMpegHandle avcEsBuf = NULL;
	SceChar8 *pPSPStream = NULL;
	SceChar8 *pWorkBuf = NULL;

	audioFlag = 1;
	pStream[0] = NULL;
	pStream[1] = NULL;
	pAudioBuf = NULL;
	if (mode == 0)
		strcpy(filename, "host0:data/");
	else
		strcpy(filename, "disc0:/PSP_GAME/USRDIR/");
	strcat(filename, name);

	bufferSize = sceMpegRingbufferQueryMemSize(0x12C0);
	if (bufferSize < 0)
		goto term3;
	workSize = sceMpegQueryMemSize(0);
	if (workSize < 0)
		goto term3;
	pPSPStream = (SceChar8 *)psp_malloc(bufferSize);
	if (pPSPStream == NULL)
		goto term3;
	pWorkBuf = (SceChar8 *)psp_malloc(workSize);
	if (pWorkBuf == NULL)
		goto term3;
	ret = sceMpegRingbufferConstruct(&ringbuf, 0x12C0, pPSPStream, bufferSize, ringbufferCallBack, (SceVoid *)&strFile);
	if (ret != 0)
		goto term3;
	ret = sceMpegCreate(&mpeg, pWorkBuf, workSize, &ringbuf, 512, 0, NULL);
	if (ret != 0)
		goto term3;
	if (strFileAssign(&strFile, filename) < 0)
		goto term3;
	if (strFileOpenCB(&strFile, filename, 1) < 0)
		goto term3;
	if (readHeader(&mpeg, &strFile, &fileSize, &streamOffset) != 0)
		goto term3;
	pStream[0] = sceMpegRegistStream(&mpeg, 0, 0);
	if (pStream[0] == NULL)
		goto term3;
	if (audioFlag == 1) {
		pStream[1] = sceMpegRegistStream(&mpeg, 1, 0);
		if (pStream[1] == NULL)
			goto term3;
	}
	avcEsBuf = sceMpegMallocAvcEsBuf(&mpeg);
	if (avcEsBuf == NULL)
		goto term3;
	if ((ret = sceMpegInitAu(&mpeg, avcEsBuf, &avcAu) != 0))
		goto term3;
	if (audioFlag == 1) {
		ret = sceMpegQueryAtracEsSize(&mpeg, &audioEsSize, &audioOutSize);
		if (ret != 0)
			goto term3;
		pAudioBuf = (SceChar8 *)psp_malloc(audioEsSize);
		if (pAudioBuf == NULL)
			goto term3;
		ret = sceMpegInitAu(&mpeg, pAudioBuf, &atracAu);
		if (ret != 0)
			goto term3;
	}

	pStreamData = (t_mpegStreamData *)psp_malloc(sizeof(t_mpegStreamData));
	if (pStreamData == NULL)
		goto term2;
	memset(pStreamData, 0, sizeof(t_mpegStreamData));
	decode_setStreamData(pStreamData, pStream[0], &avcAu, pStream[1], &atracAu);

	pDisp = (t_displayBuffer *)psp_malloc(sizeof(t_displayBuffer));
	if (pDisp == NULL)
		goto term2;
	memset(pDisp, 0, sizeof(t_displayBuffer));
	if (dispbuf_create(pDisp, 0x88000, 4) < 0)
		goto term2;

	if (audioFlag == 1) {
		pSound = (t_soundBuffer *)psp_malloc(sizeof(t_soundBuffer));
		if (pSound == NULL)
			goto term2;
		memset(pSound, 0, sizeof(t_soundBuffer));
		if (soundbuf_create(pSound, audioOutSize, 5) < 0)
			goto term2;
	}

	pAvSync = (t_avSyncControl *)psp_malloc(sizeof(t_avSyncControl));
	if (pAvSync == NULL)
		goto term2;
	if (avsync_create(pAvSync, pDisp, pSound, 6) < 0)
		goto term2;

	sceKernelChangeThreadPriority(sceKernelGetThreadId(), 0x3F);

	if (audioFlag == 1)
		soundThread = sceKernelCreateThread("soundThread", soundbuf_func, 0x3D, 0x800, 0, NULL);

	playInfo.playMode = 0;

	while (1) {
		if (strFileLseek(&strFile, streamOffset, 0) < 0)
			goto term1;

		dispbuf_reset(pDisp);
		if (audioFlag == 1)
			soundbuf_reset(pSound);
		avsync_reset(pAvSync);

		if (audioFlag == 1)
			sceKernelStartThread(soundThread, 4, &pAvSync);

		ret = playMovie(&mpeg, &ringbuf, pStreamData, pAvSync, fileSize);
		if (ret == 0) {
			if (audioFlag == 1) {
				sceKernelWaitThreadEnd(soundThread, NULL);
				break;
			}
			continue;
		}

		if (ret < 0)
			goto term1;

		if (playInfo.playMode == 1) {
			if (audioFlag == 1)
				sceKernelWaitThreadEnd(soundThread, NULL);
			if (sceMpegFlushAllStream(&mpeg) != 0)
				goto term1;
			playInfo.playMode = 0;
		} else if (playInfo.playMode == 10) {
			break;
		}
	}

term1:
	if (audioFlag == 1) {
		sceKernelWaitThreadEnd(soundThread, NULL);
		sceKernelTerminateDeleteThread(soundThread);
	}

term2:
	if (pAvSync != NULL) {
		avsync_delete(pAvSync);
		psp_free(pAvSync);
		pAvSync = NULL;
	}
	if (pSound != NULL) {
		soundbuf_delete(pSound);
		psp_free(pSound);
		pSound = NULL;
	}
	if (pDisp != NULL) {
		dispbuf_delete(pDisp);
		psp_free(pDisp);
		pDisp = NULL;
	}
	if (pStreamData != NULL)
		psp_free(pStreamData);

term3:
	if (audioFlag == 1) {
		if (pAudioBuf != NULL)
			psp_free(pAudioBuf);
	}
	if (avcEsBuf != NULL)
		sceMpegFreeAvcEsBuf(&mpeg, avcEsBuf);
	if (pStream[0] != NULL)
		sceMpegUnRegistStream(&mpeg, pStream[0]);
	if (audioFlag == 1) {
		if (pStream[1] != NULL)
			sceMpegUnRegistStream(&mpeg, pStream[1]);
	}
	strFileClose(&strFile);
	strFileUnassign(&strFile);
	sceMpegDelete(&mpeg);
	sceMpegRingbufferDestruct(&ringbuf);
	sceMpegFinish();
	if (pWorkBuf != NULL)
		psp_free(pWorkBuf);
	if (pPSPStream != NULL)
		psp_free(pPSPStream);
	return 1;
}

long long strFileLseek(StrFile *file, long long offset, SceInt32 whence);
static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset)
{
	SceInt32 iReadSize, ret;
	SceChar8 stream_buf[2048];

	if (strFileLseek(pStrFile, 0, 0) < 0) {
		ret = -1;
		goto term;
	}

	iReadSize = strFileReadCB(pStrFile, stream_buf, 2048);
	if (iReadSize < 2048) {
		ret = -1;
		goto term;
	}

	if (sceMpegQueryStreamOffset(pMpeg, stream_buf, strOffset) != 0) {
		ret = -1;
		goto term;
	}

	if (sceMpegQueryStreamSize(stream_buf, pFilesize) != 0) {
		ret = -1;
		goto term;
	}

	if (strFileLseek(pStrFile, 0, 0) < 0) {
		ret = -1;
		goto term;
	}

	ret = 0;

term:
	return ret;
}

int readPspStream(SceMpegRingbuffer *pRB) {
    int temp_v0;
    int var_v1;

    temp_v0 = sceMpegRingbufferAvailableSize();
    var_v1 = 0;
    if (temp_v0 > 0) {
        var_v1 = sceMpegRingbufferPut(pRB, 0x20, temp_v0);
    }
    return var_v1;
}

int dispbuf_getCapacity(t_displayBuffer *pDisp);
int soundbuf_getCapacity(t_soundBuffer *pSound);
static SceInt32 startCheck(t_avSyncControl *pAvSync, SceMpegRingbuffer *pRB, SceInt32 filesize, SceInt32 demuxsize)
{
	SceInt32 ret;

	ret = -1;

	if (audioFlag == 1) {
		if (dispbuf_getCapacity(pAvSync->pDisp) == 0 && soundbuf_getCapacity(pAvSync->pSound) == 0 && (sceMpegRingbufferAvailableSize(pRB) == 0 || demuxsize == filesize)) {
			ret = 0;
		}
	} else {
		if (dispbuf_getCapacity(pAvSync->pDisp) == 0 && (sceMpegRingbufferAvailableSize(pRB) == 0 || demuxsize == filesize)) {
			ret = 0;
		}
	}

	return ret;
}

int pad_sw(void);
int pad_ret_button(void);
int pad_cansel_button(void);
int sceDisplayWaitVblankStartCB(void);

SceInt32 decode_audioDecode(SceMpeg *pMpeg, t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync, SceInt32 audio_init_flag);
SceInt32 decode_videoDecode(SceMpeg *pMpeg, t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync);
SceInt32 decode_videoDecodeEnd(SceMpeg *pMpeg, t_avSyncControl *pAvSync);
SceInt32 dispbuf_display(SceVoid *pAv);
int dispbuf_getCurrentCount(t_displayBuffer *pDisp);
int soundbuf_setStartFlag(t_soundBuffer *pSound);
static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync, SceInt32 filesize)
{
	SceInt32 vBlankCount;
	SceInt32 demuxsize;
	SceInt32 readsize;
	SceInt32 audio_init_flag;
	SceInt32 ret;
	SceInt32 startFlag;
	SceInt32 currentMode;

	audio_init_flag = 1;
	startFlag = 1;
	currentMode = 0;
	ret = 0;
	demuxsize = 0;

	while (1) {
		vBlankCount = sceDisplayGetVcount();
		if (startFlag != 0) {
			startFlag = startCheck(pAvSync, pRB, filesize, demuxsize);
		} else {
			if (audioFlag == 1)
				soundbuf_setStartFlag(pAvSync->pSound);
			pad_read();
			if (pad_sw() & (pad_ret_button() | pad_cansel_button())) {
				playInfo.playMode = 10;
				if (audioFlag == 1)
					soundbuf_setDemuxEnd(pAvSync->pSound);
				ret = 10;
				goto term;
			}
		}

		switch (currentMode) {
		case 0:
			if (demuxsize == filesize && sceMpegRingbufferAvailableSize(pRB) == 0x12C0) {
				if (audioFlag == 1)
					soundbuf_setDemuxEnd(pAvSync->pSound);
				currentMode = 1;
				break;
			}
			if (demuxsize < filesize) {
				readsize = readPspStream(pRB);
				if (readsize >= 0)
					demuxsize += readsize * 2048;
			}
			if (audioFlag == 1) {
				ret = decode_audioDecode(pMpeg, pStreamData, pAvSync, audio_init_flag);
				if (ret >= 0) {
					audio_init_flag = 0;
				} else if (ret != (SceInt32)0x80618001) {
					goto error;
				}
			}
			ret = decode_videoDecode(pMpeg, pStreamData, pAvSync);
			if (ret < 0)
				goto error;
			break;
		case 1:
			ret = decode_videoDecodeEnd(pMpeg, pAvSync);
			if (ret < 0) {
				goto error;
			}
			if (ret == 0)
				currentMode = 2;
			break;
		case 2:
			if (dispbuf_getCurrentCount(pAvSync->pDisp) == 0)
				goto term;
			break;
		}

		if (startFlag == 0) {
			while (sceDisplayGetVcount() < vBlankCount + 1) {
				if (demuxsize < filesize) {
					readsize = readPspStream(pRB);
					if (readsize > 0)
						demuxsize += readsize * 2048;
				} else {
					sceDisplayWaitVblankStartCB();
				}
			}
			dispbuf_display(pAvSync);
		}
		sceKernelCheckCallback();
	}

error:
	if (audioFlag == 1)
		soundbuf_setDemuxEnd(pAvSync->pSound);
term:
	return ret;
}
