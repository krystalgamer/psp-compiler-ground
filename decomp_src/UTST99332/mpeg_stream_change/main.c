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
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x4 */
    SceUID control_flag;
};
typedef struct t_conditionCtrl t_conditionCtrl;
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
typedef struct SceKernelLMOption SceKernelLMOption;
struct SceMpeg;
struct SceMpeg { /* size 0x4 */
    SceVoid *sys;
};
typedef struct SceMpeg SceMpeg;
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
typedef struct SceMpegRingbuffer SceMpegRingbuffer;
struct ScePsmf;
struct ScePsmf { /* size 0x28 */
    SceInt32 type;
    SceInt32 groupingPeriodId;
    SceInt32 groupId;
    SceInt32 streamNumber;
    SceVoid *header;
    SceVoid *sequenceInfo;
    SceVoid *currentGroupingPeriod;
    SceVoid *currentGroup;
    SceVoid *currentStream;
    SceVoid *currentEPmap;
};
typedef struct ScePsmf ScePsmf;
struct t_displayBuffer;
typedef unsigned int SceUInt32;
struct t_displayBuffer { /* size 0x28 */
    SceUID lockSema;
    SceUID delayFlag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 displayMode;
    t_conditionCtrl *pCtrl;
};
typedef struct t_displayBuffer t_displayBuffer;
struct t_ringBuffer;
struct t_ringBuffer { /* size 0x14 */
    SceInt32 dataLen;
    SceUID ringbufSema;
    SceInt32 statusFlag;
    SceMpegRingbuffer *pRingbuf;
    t_conditionCtrl *pCtrl;
};
typedef struct t_ringBuffer t_ringBuffer;
struct t_soundBuffer;
struct t_soundBuffer { /* size 0x28 */
    SceUID lockSema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 bufSize;
    t_conditionCtrl *pCtrl;
    SceUInt32 soundLatestPts;
};
typedef struct t_soundBuffer t_soundBuffer;
struct t_avSyncControl;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x18 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceUInt32 videoLatestPts;
};
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSyncControl { /* size 0x20 */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};
typedef struct t_avSyncControl t_avSyncControl;
struct t_playInfo;
struct t_streamInfo;
struct t_streamInfo { /* size 0x18 */
    ScePsmf *pVideoPsmf;
    ScePsmf *pAudioPsmf;
    SceInt32 currentAvcStreamTypeId;
    SceInt32 currentAudioStreamTypeId;
    SceInt32 numberOfAvcStreams;
    SceInt32 numberOfAudioStreams;
};
typedef struct t_streamInfo t_streamInfo;
struct t_mpegStreamData;
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
typedef struct SceMpegStream SceMpegStream;
struct SceMpegAu;
struct SceMpegTimeStamp;
struct SceMpegTimeStamp { /* size 0x8 */
    SceUInt32 MSB_ts;
    SceUInt32 ts;
};
typedef struct SceMpegTimeStamp SceMpegTimeStamp;
struct SceMpegAu { /* size 0x18 */
    SceMpegTimeStamp pts;
    SceMpegTimeStamp dts;
    SceUChar8 *pEsBuf;
    SceInt32 iEsSize;
};
typedef struct SceMpegAu SceMpegAu;
typedef SceUChar8 *SceMpegHandle;
struct t_mpegStreamData { /* size 0x3a4 */
    SceMpeg *pMpeg;
    SceMpegStream *pVideoStream[16];
    SceMpegStream *pAudioStream[16];
    SceInt32 currentVideoStream;
    SceInt32 currentAudioStream;
    SceInt32 videoStreamNum;
    SceInt32 audioStreamNum;
    SceMpegAu avcAu[16];
    SceMpegAu audioAu[16];
    SceMpegHandle avcEsBuf;
    SceChar8 *pAudioEsBuf;
    SceInt32 audioOutSize;
    SceUInt32 startTimestamp;
};
typedef struct t_mpegStreamData t_mpegStreamData;
struct t_playInfo { /* size 0x3cc */
    SceInt32 playMode;
    SceInt32 fileSize;
    SceInt32 offset;
    SceUInt32 timestamp;
    t_streamInfo sInfo;
    t_mpegStreamData streamData;
};
typedef struct t_playInfo t_playInfo;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
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

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern SceInt32 sce_newlib_heap_kb_size;
extern SceInt32 audioFlag;
extern SceUID dispThread;
extern SceUID readThread;
extern SceUID soundThread;

static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData);
static SceInt32 loadModule(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option);
static SceInt32 unloadModule(SceUID *mid);
SceInt32 main(SceInt32 argc, SceChar8 **argv);
static SceInt32 startCheck(t_avSyncControl *pAvSync, t_ringBuffer *pRingCtrl, t_conditionCtrl *pCtrl);
static SceInt32 checkDecodeEnd(t_conditionCtrl *pCtrl);
static SceInt32 checkPlayerErrCondition(t_conditionCtrl *pCtrl);
static SceInt32 setPlayerEndCondition(t_conditionCtrl *pCtrl);
static SceInt32 playMovie(SceMpegRingbuffer *pRB, t_playInfo *pPlayInfo, t_ringBuffer *pRingCtrl, t_avSyncControl *pAvSync, t_conditionCtrl *pCtrl);
static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceChar8 **pHeader, SceInt32 *pFilesize, SceInt32 *strOffset);
static SceInt32 pad_read(t_displayBuffer *pDisp, t_playInfo *pPlayInfo);

/* SDK functions (tools/sdk_protos.h) */
void sceKernelExitGame(void);


/* SDK prototypes (tools/sdk_protos.h) */
void free(void *p);
int sceCtrlSetSamplingMode(int mode);
int sceKernelChangeThreadPriority(int thid, int prio);
int sceKernelCreateCallback(const char *name, void *func, void *arg);
int sceKernelCreateThread(const char *name, void *entry, int prio, int stacksize, unsigned int attr, void *option);
int sceKernelGetThreadId(void);
int sceKernelRegisterExitCallback(int cbid);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);
int strcmp(const char *a, const char *b);

static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData)
{
	SceInt32 iTypeSize = 0x800;
	SceInt32 iReadSize;
	StrFile *pStrFile = (StrFile *)CallbackData;

	iReadSize = strFileRead(pStrFile, pBuf, iNum * iTypeSize);

	if (iReadSize == (SceInt32)0x80210003) {
		return 0;
	}

	if (iReadSize < 0) {
		printf("iReadSize = 0x%x\n", iReadSize);
	}

	if (iReadSize % iTypeSize != 0) {
		return -1;
	}

	return iReadSize / iTypeSize;
}

int exit_func(int count, int arg1, void *arg2) {
    setPlayerEndCondition((t_conditionCtrl *) arg2);
    if (audioFlag == 0) {

    } else {
        sceKernelWaitThreadEnd(soundThread, 0);
    }
    sceKernelWaitThreadEnd(dispThread, 0);
    sceKernelWaitThreadEnd(readThread, 0);
    sceKernelExitGame();
    return 0;
}

SceInt32 loadModule(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option)
{
	SceInt32 res;
	SceInt32 mresult;

	do {
		*mid = sceKernelLoadModule(filename, 0, option);
	} while (*mid < 0);

	do {
		res = sceKernelStartModule(*mid, 0, NULL, &mresult, NULL);
	} while (res < 0);

	return 0;
}

SceInt32 unloadModule(SceUID *mid)
{
	SceInt32 mresult;

	if (sceKernelStopModule(*mid, 0, NULL, &mresult, NULL) < 0) {
		printf("fatal error : sceKernelStopModule\n");
		return -1;
	}

	if (sceKernelUnloadModule(*mid) < 0) {
		printf("fatal error : sceKernelUnloadModule\n");
		return -1;
	}

	return 0;
}

long long strFileLseek(StrFile *file, long long offset, SceInt32 whence);
SceInt32 control_create(t_conditionCtrl *pCtrl);
SceInt32 control_delete(t_conditionCtrl *pCtrl);
SceInt32 control_reset(t_conditionCtrl *pCtrl);
SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 a, SceInt32 b, t_conditionCtrl *pCtrl);
SceInt32 dispbuf_delete(t_displayBuffer *pDisp);
SceInt32 dispbuf_reset(t_displayBuffer *pDisp);
SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 a, SceInt32 b, t_conditionCtrl *pCtrl);
SceInt32 soundbuf_delete(t_soundBuffer *pSound);
SceInt32 soundbuf_reset(t_soundBuffer *pSound);
SceInt32 read_create(t_ringBuffer *pRing, SceMpegRingbuffer *pRB, t_conditionCtrl *pCtrl);
SceInt32 read_delete(t_ringBuffer *pRing);
SceInt32 read_reset(t_ringBuffer *pRing, SceInt32 fileSize);
SceInt32 avsync_create(t_avSyncControl *pAvSync, t_displayBuffer *pDisp, t_soundBuffer *pSound, SceInt32 n);
SceInt32 avsync_delete(t_avSyncControl *pAvSync);
SceInt32 avsync_reset(t_avSyncControl *pAvSync);
SceInt32 dispbuf_func(SceSize size, SceVoid *argp);
SceInt32 soundbuf_func(SceSize size, SceVoid *argp);
SceInt32 read_func(SceSize size, SceVoid *argp);
SceInt32 strFileAssign(StrFile *file, SceChar8 *name);
SceInt32 strFileUnassign(StrFile *file);
SceInt32 strFileOpen(StrFile *file, SceChar8 *name, SceInt32 mode);
SceInt32 strFileClose(StrFile *file);
SceInt32 sceMpegInit(void);
SceInt32 sceMpegFinish(void);
SceInt32 sceMpegRingbufferQueryMemSize(SceInt32 iPackNum);
SceInt32 sceMpegQueryMemSize(SceInt32 iReserved);
SceInt32 sceMpegRingbufferConstruct(SceMpegRingbuffer *pRingbuffer, SceInt32 iPackNum, SceVoid *pBuf, SceInt32 iSize, SceMpegRBCallback Callback, SceVoid *CallbackData);
SceInt32 sceMpegRingbufferDestruct(SceMpegRingbuffer *pRingbuffer);
SceInt32 sceMpegCreate(SceMpeg *pMpeg, SceVoid *pData, SceInt32 iSize, SceMpegRingbuffer *pRingbuffer, SceInt32 iFrameWidth, SceInt32 iReserved1, SceVoid *pReserved2);
SceInt32 sceMpegDelete(SceMpeg *pMpeg);
SceInt32 sceMpegFlushAllStream(SceMpeg *pMpeg);
int sceKernelDeleteCallback(int cbid);
int sceKernelTerminateDeleteThread(int thid);
void menuInit(void);
void menuTerm(int a, int b);
int puts(const char *s);
SceInt32 scePsmfSetPsmf(ScePsmf *pPsmf, SceVoid *pBuf);
char *strstr(const char *s, const char *t);
SceInt32 playInfo_delete(t_playInfo *pPlayInfo, SceInt32 audioFlag);
SceInt32 playInfo_getAudioStreamNum(t_playInfo *pPlayInfo);
SceInt32 playInfo_getOffset(t_playInfo *pPlayInfo);
SceInt32 playInfo_getPlayerMode(t_playInfo *pPlayInfo);
SceInt32 playInfo_getAudioOutSize(t_playInfo *pPlayInfo);
SceInt32 playInfo_getStartTimestamp(t_playInfo *pPlayInfo, SceUInt32 *pTimestamp);
SceInt32 avsync_video_getLatestPts(t_avSyncControl *pAvSync, SceUInt32 *pPts);
extern const char D_00011154[], D_00011174[], D_000111A8[], D_000111B4[], D_000111D0[], D_000111D8[], D_000111EC[];
extern const char D_00011200[], D_00011228[], D_00011250[], D_0001125C[], D_0001127C[], D_000112A4[], D_000112C4[], D_000112E4[];
SceInt32 main(SceInt32 argc, SceChar8 **argv)
{
	SceMpeg mpeg;
	SceMpegRingbuffer ringbuf;

	ScePsmf videoPsmf;
	ScePsmf audioPsmf;

	SceChar8 *filename = "disc0:/PSP_GAME/USRDIR/DATA/movie/psmf/demo02.pmf";
	SceChar8 *pHeader = NULL;

	StrFile strFile;

	SceInt32 bufferSize, workSize, fileSize;
	SceInt32 audioOutSize = 0;
	SceInt32 streamOffset;
	SceInt32 ret;

	t_displayBuffer *pDisp = NULL;
	t_ringBuffer *pRing = NULL;
	t_soundBuffer *pSound = NULL;
	t_avSyncControl *pAvSync = NULL;
	t_conditionCtrl *pCtrl = NULL;
	t_playInfo *pPlayInfo = NULL;

	SceChar8 *pPSPStream = NULL;
	SceChar8 *pWorkBuf = NULL;

	SceUID exit_cb;

	SceUID videoMid = 0;
	SceUID audioMid = 0;
	SceUID baseMid = 0;
	SceUID mpegMid = 0;
	SceUID psmfMid = 0;

	SceKernelLMOption kMode;
	SceKernelLMOption uMode;

	menuInit();

	kMode.size = sizeof(kMode);
	kMode.mpidtext = 1;
	kMode.mpiddata = 1;
	kMode.position = 0;
	kMode.access = 1;

	uMode.size = sizeof(uMode);
	uMode.mpidtext = 2;
	uMode.mpiddata = 2;
	uMode.position = 0;
	uMode.access = 1;

	if (loadModule(&videoMid, "disc0:/PSP_GAME/USRDIR/MODULE/videocodec.prx", &kMode) != 0) {
		printf("fatal error : load Module videocodec.prx\n");
		goto term4;
	}

	if (loadModule(&audioMid, "disc0:/PSP_GAME/USRDIR/MODULE/audiocodec.prx", &kMode) != 0) {
		printf("fatal error : load Module audiocodec.prx\n");
		goto term4;
	}

	if (loadModule(&baseMid, "disc0:/PSP_GAME/USRDIR/MODULE/mpegbase.prx", &kMode) != 0) {
		printf("fatal error : load Module mpegbase.prx\n");
		goto term4;
	}

	if (loadModule(&mpegMid, "disc0:/PSP_GAME/USRDIR/MODULE/mpeg.prx", &uMode) != 0) {
		printf("fatal error : load Module mpeg.prx\n");
		goto term4;
	}

	if (loadModule(&psmfMid, "disc0:/PSP_GAME/USRDIR/MODULE/psmf.prx", &uMode) != 0) {
		puts(D_000112E4);
		goto term4;
	}

	audioFlag = 1;

	while (argc >= 2) {
		argv++;
		argc--;

		if (strcmp("-noaudio", argv[0]) == 0) {
			audioFlag = 0;
		}
		else if (strstr(argv[0], ".pmf") != NULL || strstr(argv[0], ".PMF") != NULL) {
			filename = argv[0];
		}
	}

	ret = sceMpegInit();
	if (ret != 0) {
		printf("fatal error : sceMpegInit() 0x%x\n", ret);
		goto term3;
	}

	bufferSize = sceMpegRingbufferQueryMemSize(32 * 150);
	if (bufferSize < 0) {
		printf("fatal error : sceMpegRingbufferQueryMemSize 0x%x\n", bufferSize);
		goto term3;
	}

	workSize = sceMpegQueryMemSize(0);
	if (workSize < 0) {
		printf("fatal error : sceMpegQueryMemSize 0x%x\n", workSize);
		goto term3;
	}

	pPSPStream = (SceChar8 *)malloc(sizeof(SceChar8) * bufferSize);
	if (pPSPStream == NULL) {
		printf("fatal error : malloc pPSPStream\n");
		goto term3;
	}

	pWorkBuf = (SceChar8 *)malloc(sizeof(SceChar8) * workSize);
	if (pWorkBuf == NULL) {
		printf(D_000112C4);
		goto term3;
	}

	ret = sceMpegRingbufferConstruct(&ringbuf, 32 * 150, pPSPStream, bufferSize, ringbufferCallBack, (SceVoid *)&strFile);
	if (ret != 0) {
		printf("fatal error : sceMpegRingbufferConstruct() 0x%x\n", ret);
		goto term3;
	}

	ret = sceMpegCreate(&mpeg, pWorkBuf, workSize, &ringbuf, 512, 0, NULL);
	if (ret != 0) {
		printf("fatal error : sceMpegCreate() 0x%x\n", ret);
		goto term3;
	}

	if (strFileAssign(&strFile, filename) < 0) {
		printf("fatal error : strFileAssign()\n");
		goto term3;
	}

	if (strFileOpen(&strFile, filename, 1) < 0) {
		printf("fatal error : strFileOpen()\n");
		goto term3;
	}

	if (readHeader(&mpeg, &strFile, &pHeader, &fileSize, &streamOffset) != 0) {
		printf("fatal error : readHeader\n");
		goto term3;
	}

	if ((ret = scePsmfSetPsmf(&videoPsmf, pHeader)) != 0) {
		puts(D_000112A4);
		goto term3;
	}

	audioPsmf = videoPsmf;

	pPlayInfo = (t_playInfo *)malloc(sizeof(t_playInfo));
	if (pPlayInfo == NULL) {
		goto term2;
	}

	if ((ret = playInfo_create(pPlayInfo, &mpeg, &videoPsmf, &audioPsmf, fileSize, audioFlag)) != 0) {
		printf(D_0001127C, ret);
		goto term2;
	}

	if (playInfo_getAudioStreamNum(pPlayInfo) == 0) {
		audioFlag = 0;
	}

	pCtrl = (t_conditionCtrl *)malloc(sizeof(t_conditionCtrl));
	if (pCtrl == NULL) goto term2;
	control_create(pCtrl);

	pDisp = (t_displayBuffer *)malloc(sizeof(t_displayBuffer));
	if (pDisp == NULL) goto term2;

	if (dispbuf_create(pDisp, 512 * 272 * 4, 4, pCtrl) < 0) {
		printf("fatal error : displayCreate()\n");
		goto term2;
	}

	if (audioFlag == 1) {
		audioOutSize = playInfo_getAudioOutSize(pPlayInfo);

		pSound = (t_soundBuffer *)malloc(sizeof(t_soundBuffer));
		if (pSound == NULL) goto term2;

		if (soundbuf_create(pSound, audioOutSize, 4, pCtrl) < 0) {
			puts(D_0001125C);
			goto term2;
		}
	}

	pRing = (t_ringBuffer *)malloc(sizeof(t_ringBuffer));
	if (pRing == NULL) goto term2;

	if (read_create(pRing, &ringbuf, pCtrl) < 0) {
		printf("fatal error read_create()\n");
		goto term2;
	}

	pAvSync = (t_avSyncControl *)malloc(sizeof(t_avSyncControl));
	if (pAvSync == NULL) goto term2;

	if (avsync_create(pAvSync, pDisp, pSound, 4 + 2) < 0) {
		printf("fatal error avsync_create()\n");
		goto term2;
	}

	sceCtrlSetSamplingMode(0);

	sceKernelChangeThreadPriority(sceKernelGetThreadId(), 23);

	dispThread = sceKernelCreateThread("displayThread", dispbuf_func, 22, 2048, 0, NULL);

	readThread = sceKernelCreateThread("readThread", read_func, 24, 2048, 0, NULL);

	if (audioFlag) {
		soundThread = sceKernelCreateThread(D_00011250, soundbuf_func, 21, 2048, 0, NULL);
	}

	exit_cb = sceKernelCreateCallback("ExitGame", exit_func, pCtrl);
	if (exit_cb <= 0) {
		printf("fatal error: sceKernelCreateCallback() 0x%x\n", exit_cb);
		goto term1;
	}

	sceKernelRegisterExitCallback(exit_cb);

	for (;;) {
		extern SceInt32 D_00012A28; /* static SceInt32 count */
		SceInt32 offset;
		SceUInt32 currentTimestamp;

		if (D_00012A28 == 0) {
			if ((ret = playInfo_getStartTimestamp(pPlayInfo, &currentTimestamp)) != 0) {
				printf("fatal error : playInfo_getStartTimestamp() 0x%x\n", ret);
				goto term1;
			}
		}

		printf("********** PlayMovie (%d) **********\n", D_00012A28++);

		if ((ret = playInfo_reset(pPlayInfo, currentTimestamp)) != 0) {
			printf("fatal error : playInfo_init() 0x%x\n", ret);
			goto term1;
		}

		offset = playInfo_getOffset(pPlayInfo);

		if (strFileLseek(&strFile, streamOffset + offset, 0) < 0) {
			puts(D_00011154);
			goto term1;
		}

		if (audioFlag) soundbuf_reset(pSound);
		dispbuf_reset(pDisp);
		read_reset(pRing, fileSize - offset);
		avsync_reset(pAvSync);
		control_reset(pCtrl);

		if (audioFlag) {
			sceKernelStartThread(soundThread, sizeof(pAvSync), &pAvSync);
		}
		sceKernelStartThread(dispThread, sizeof(pAvSync), &pAvSync);
		sceKernelStartThread(readThread, sizeof(pRing), &pRing);

		if ((ret = playMovie(&ringbuf, pPlayInfo, pRing, pAvSync, pCtrl)) == 0) {
			if (audioFlag) {
				sceKernelWaitThreadEnd(soundThread, NULL);
			}
			sceKernelWaitThreadEnd(dispThread, NULL);
			sceKernelWaitThreadEnd(readThread, NULL);

			if ((ret = playInfo_changeVideoStream(pPlayInfo)) != 0) {
				printf(D_00011174, ret);
				goto term1;
			}

			playInfo_getStartTimestamp(pPlayInfo, &currentTimestamp);

		} else if (ret < 0) {
			puts(D_000111B4);
			goto term1;

		} else if (playInfo_getPlayerMode(pPlayInfo) == 1) {
			puts(D_000111D0);

			if (audioFlag) {
				sceKernelWaitThreadEnd(soundThread, NULL);
			}
			sceKernelWaitThreadEnd(dispThread, NULL);
			sceKernelWaitThreadEnd(readThread, NULL);

			if (sceMpegFlushAllStream(&mpeg) != 0) {
				puts(D_00011200);
				goto term1;
			}

			playInfo_getStartTimestamp(pPlayInfo, &currentTimestamp);

		} else if (playInfo_getPlayerMode(pPlayInfo) == 0xff) {
			puts(D_000111D8);

			goto term1;

		} else if (playInfo_getPlayerMode(pPlayInfo) == 2) {
			puts(D_000111EC);

			if (audioFlag) {
				sceKernelWaitThreadEnd(soundThread, NULL);
			}
			sceKernelWaitThreadEnd(dispThread, NULL);
			sceKernelWaitThreadEnd(readThread, NULL);

			if ((ret = playInfo_changeVideoStream(pPlayInfo)) != 0) {
				printf(D_00011174, ret);
				goto term1;
			}

			if ((ret = sceMpegFlushAllStream(&mpeg)) != 0) {
				puts(D_00011200);

				goto term1;
			}

			if ((ret = avsync_video_getLatestPts(pAvSync, &currentTimestamp)) != 0) {
				puts(D_00011228);

				goto term1;
			}
		}
	}

term1:
	if (audioFlag) {
		sceKernelWaitThreadEnd(soundThread, NULL);
	}
	sceKernelWaitThreadEnd(dispThread, NULL);
	sceKernelWaitThreadEnd(readThread, NULL);

	if (audioFlag) {
		sceKernelTerminateDeleteThread(soundThread);
	}
	sceKernelTerminateDeleteThread(dispThread);
	sceKernelTerminateDeleteThread(readThread);

	sceKernelDeleteCallback(exit_cb);

term2:
	if (pRing != NULL) {
		read_delete(pRing);
		free(pRing);
		pRing = NULL;
	}

	if (pAvSync != NULL) {
		avsync_delete(pAvSync);
		free(pAvSync);
		pAvSync = NULL;
	}

	if (pSound != NULL) {
		soundbuf_delete(pSound);
		free(pSound);
		pSound = NULL;
	}

	if (pDisp != NULL) {
		dispbuf_delete(pDisp);
		free(pDisp);
		pSound = NULL;
	}

	if (pCtrl != NULL) {
		control_delete(pCtrl);
		free(pCtrl);
		pCtrl = NULL;
	}

	if (pPlayInfo != NULL) {
		playInfo_delete(pPlayInfo, audioFlag);
		free(pPlayInfo);
		pPlayInfo = NULL;
	}

term3:
	strFileClose(&strFile);
	strFileUnassign(&strFile);

	sceMpegDelete(&mpeg);
	sceMpegRingbufferDestruct(&ringbuf);
	sceMpegFinish();

	if (pWorkBuf != NULL) free(pWorkBuf);
	if (pPSPStream != NULL) free(pPSPStream);

	if (pHeader != NULL) free(pHeader);

term4:
	unloadModule(&psmfMid);
	unloadModule(&mpegMid);
	unloadModule(&baseMid);
	unloadModule(&audioMid);
	unloadModule(&videoMid);

	puts(D_000111A8);

	menuTerm(2, 5);

	return 1;
}

static SceInt32 startCheck(t_avSyncControl *pAvSync, t_ringBuffer *pRingCtrl, t_conditionCtrl *pCtrl)
{
	SceInt32 ret;

	if (audioFlag) {
		if ((dispbuf_getCapacity(pAvSync->pDisp) == 0 && soundbuf_getCapacity(pAvSync->pSound) == 0 && read_isFull(pRingCtrl)) || checkDecodeEnd(pCtrl) == 1) {
			control_setCondition(pCtrl, 1);
			ret = 0;
		} else {
			ret = -1;
		}
	} else {
		if ((dispbuf_getCapacity(pAvSync->pDisp) == 0 && read_isFull(pRingCtrl)) || checkDecodeEnd(pCtrl) == 1) {
			control_setCondition(pCtrl, 1);
			ret = 0;
		} else {
			ret = -1;
		}
	}

	return ret;
}

static SceInt32 checkDecodeEnd(t_conditionCtrl *pCtrl)
{
	SceUInt32 cond;

	control_getCondition(pCtrl, &cond);
	if (cond & 8)
		return 1;
	return -1;
}

SceInt32 checkPlayerErrCondition(t_conditionCtrl *pCtrl)
{
	SceUInt32 pattern;

	control_getCondition(pCtrl, &pattern);

	if (pattern & 0x800) {
		return -1;
	}

	return 0;
}

static SceInt32 setPlayerEndCondition(t_conditionCtrl *pCtrl)
{
	control_setCondition(pCtrl, 0xFF);
	return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_00011154);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_00011174);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_000111A8);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_000111B4);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_000111D0);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_000111D8);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_000111EC);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_00011200);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_00011228);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_00011250);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_0001125C);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_0001127C);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_000112A4);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_000112C4);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/main", D_000112E4);

SceInt32 playInfo_audioDecode(t_playInfo *pPlayInfo, t_avSyncControl *pAvSync, SceInt32 audio_init_flag);
SceInt32 playInfo_videoDecode(t_playInfo *pPlayInfo, t_avSyncControl *pAvSync);
SceInt32 playInfo_videoDecodeEnd(t_playInfo *pPlayInfo, t_avSyncControl *pAvSync);
SceInt32 playInfo_flushDecoder(t_playInfo *pPlayInfo);
SceInt32 playInfo_changeAudioStream(t_playInfo *pPlayInfo);
SceInt32 read_isEnd(t_ringBuffer *pRing);
SceInt32 read_isFull(t_ringBuffer *pRing);
SceInt32 read_decode_sleep(t_ringBuffer *pRing);
SceInt32 control_setCondition(t_conditionCtrl *pCtrl, SceUInt32 pattern);
SceInt32 startCheck(t_avSyncControl *pAvSync, t_ringBuffer *pRingCtrl, t_conditionCtrl *pCtrl);
SceInt32 sceMpegRingbufferAvailableSize(SceMpegRingbuffer *pRingbuffer);
int sceKernelCheckCallback(void);
int printf(const char *fmt, ...);

static SceInt32 playMovie(SceMpegRingbuffer *pRB, t_playInfo *pPlayInfo, t_ringBuffer *pRingCtrl, t_avSyncControl *pAvSync, t_conditionCtrl *pCtrl)
{
	SceInt32 audio_init_flag;
	SceInt32 ret;
	SceInt32 startFlag;

	audio_init_flag = 1;
	startFlag = -1;

	while (1) {
		if (startFlag != 0) {
			startFlag = startCheck(pAvSync, pRingCtrl, pCtrl);
		} else {
			ret = pad_read(pAvSync->pDisp, pPlayInfo);
			if (ret == 3) {
				audio_init_flag = 1;
				playInfo_changeAudioStream(pPlayInfo);
			} else if (ret != 0) {
				playInfo_flushDecoder(pPlayInfo);
				goto error;
			}
		}

		if (read_isEnd(pRingCtrl) == 1 && sceMpegRingbufferAvailableSize(pRB) == 0x12C0)
			break;

		ret = checkPlayerErrCondition(pCtrl);
		if (ret != 0) {
			printf("fatal error : checkPlayerErrCondition()\n");
			goto error;
		}

		if (audioFlag == 1) {
			ret = playInfo_audioDecode(pPlayInfo, pAvSync, audio_init_flag);
			if (ret == 0) {
				audio_init_flag = 0;
			} else if (ret <= 0) {
				if (ret == (SceInt32)0x80618001) {
					if (read_isFull(pRingCtrl) == 0)
						read_decode_sleep(pRingCtrl);
				} else {
					printf("fatal error : decode_audioDecode() 0x%x\n", ret);
					goto error;
				}
			}
		}

		ret = playInfo_videoDecode(pPlayInfo, pAvSync);
		if (ret != 0) {
			if (ret == (SceInt32)0x80618001) {
				if (read_isFull(pRingCtrl) == 0)
					read_decode_sleep(pRingCtrl);
			} else if (ret < 0) {
				goto video_error;
			}
		}

		if (read_isFull(pRingCtrl) == 0)
			read_decode_sleep(pRingCtrl);

		sceKernelCheckCallback();
	}

	control_setCondition(pCtrl, 8);

	do {
		ret = playInfo_videoDecodeEnd(pPlayInfo, pAvSync);
		if (ret < 0) {
			printf("fatal error : decode_videoDecodeEnd() 0x%x\n", ret);
			goto error;
		}
	} while (ret != 0);

	goto error;
video_error:
	printf("fatal error : sceMpegGetAvcAu () 0x%x\n", ret);
error:
	setPlayerEndCondition(pCtrl);
term:
	return ret;
}

long long strFileLseek(StrFile *file, long long offset, SceInt32 whence);
extern const char D_00011154[];

static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceChar8 **pHeader, SceInt32 *pFilesize, SceInt32 *strOffset)
{
	SceInt32 iReadSize, ret;
	SceChar8 stream_buf[2048];

	if (strFileLseek(pStrFile, 0, 0) < 0) {
		ret = -1;
		goto term;
	}

	iReadSize = strFileRead(pStrFile, stream_buf, 2048);
	if (iReadSize < 2048) {
		printf("fatal error : strFileRead() 0x%x\n", iReadSize);
		ret = -1;
		goto term;
	}

	if (sceMpegQueryStreamOffset(pMpeg, stream_buf, strOffset) != 0) {
		printf("fatal error : sceMpegQueryStreamOffset()\n");
		ret = -1;
		goto term;
	}

	if (sceMpegQueryStreamSize(stream_buf, pFilesize) != 0) {
		printf("fatal error : sceMpegQueryStreamSize()\n");
		ret = -1;
		goto term;
	}

	*pHeader = malloc(*strOffset);

	if (strFileLseek(pStrFile, 0, 0) < 0) {
		ret = -1;
		goto term;
	}

	iReadSize = strFileRead(pStrFile, *pHeader, *strOffset);
	if (iReadSize < *strOffset) {
		printf("fatal error : strFileRead() %x\n", iReadSize);
		ret = -1;
		goto term;
	}

	if (strFileLseek(pStrFile, 0, 0) < 0) {
		puts(D_00011154); /* "fatal error : strFileLseek()", shared with an asm function */
		ret = -1;
		goto term;
	}

	ret = 0;

term:
	return ret;
}

extern SceUInt32 D_00012A2C; /* static SceUInt32 oldpadd in pad_read (bss is asm) */
extern SceUInt32 D_00012A30; /* static SceUInt32 padd in pad_read */

static SceInt32 pad_read(t_displayBuffer *pDisp, t_playInfo *pPlayInfo)
{
	SceCtrlData buf;
	SceInt32 ret;

	ret = 0;

	D_00012A2C = D_00012A30;
	sceCtrlReadBufferPositive(&buf, 1);
	D_00012A30 = buf.Buttons;

	if (D_00012A30 & 0x1) {
		playInfo_setPlayerMode(pPlayInfo, 0xFF);
		ret = 2;
	} else if (D_00012A30 & 0x8) {
		playInfo_setPlayerMode(pPlayInfo, 1);
		ret = 1;
	} else if (D_00012A30 & ~D_00012A2C & 0x2000) {
		dispbuf_setDelayMode(pDisp);
	} else if (D_00012A30 & ~D_00012A2C & 0x200) {
		playInfo_setPlayerMode(pPlayInfo, 2);
		ret = 4;
	} else if (D_00012A30 & ~D_00012A2C & 0x100) {
		ret = 3;
	}

	return ret;
}
