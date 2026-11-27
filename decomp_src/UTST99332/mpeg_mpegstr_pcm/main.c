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
struct SceMpegStream;
typedef unsigned int SceUInt32;
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
struct t_displayBuffer;
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
struct t_soundBuffer { /* size 0x2c */
    SceUID lock_sema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 write2;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 buf_size;
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
struct t_mpegStreamData;
struct t_mpegStreamData { /* size 0x10 */
    SceMpegStream *pAvcStream;
    SceMpegAu *pAvcAu;
    SceMpegStream *pPcmStream;
    SceMpegAu *pPcmAu;
};
typedef struct t_mpegStreamData t_mpegStreamData;
typedef SceUChar8 *SceMpegHandle;
typedef unsigned int u_int32;
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
struct t_playInfo;
struct t_playInfo { /* size 0x8 */
    SceInt32 playMode;
    SceUInt32 timestamp;
};
typedef struct t_playInfo t_playInfo;

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
extern t_playInfo playInfo;

static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData);
static SceInt32 loadModule(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option);
static SceInt32 unloadModule(SceUID *mid);
SceInt32 main(SceInt32 argc, SceChar8 **argv);
static SceInt32 checkDecodeEnd(t_conditionCtrl *pCtrl);
static SceInt32 checkPlayerErrCondition(t_conditionCtrl *pCtrl);
static SceInt32 setPlayerEndCondition(t_conditionCtrl *pCtrl);
static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_ringBuffer *pRingCtrl, t_avSyncControl *pAvSync, t_conditionCtrl *pCtrl);
static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset);
static SceInt32 pad_read(t_displayBuffer *pDisp);

/* SDK functions (tools/sdk_protos.h) */
void sceKernelExitGame(void);


/* SDK prototypes (tools/sdk_protos.h) */
void free(void *p);
void *malloc(unsigned int size);
void *memalign(unsigned int align, unsigned int size);
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

	if (iReadSize == (SceInt32)0x80210003 || iReadSize == (SceInt32)0x80210001) {
		return 0;
	}

	if (iReadSize % iTypeSize != 0) {
		return -1;
	}

	return iReadSize / iTypeSize;
}

int exit_func(int count, int arg1, void *arg2) {
    setPlayerEndCondition((t_conditionCtrl *) arg2);
    if (audioFlag != 1) {

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
SceInt32 decode_setStreamData(t_mpegStreamData *pStreamData, SceMpegStream *pStreamV, SceMpegAu *pAvcAu, SceMpegStream *pStreamA, SceMpegAu *pAtracAu);
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
SceMpegStream *sceMpegRegistStream(SceMpeg *pMpeg, SceInt32 iStreamID, SceInt32 iStreamNum);
SceVoid sceMpegUnRegistStream(SceMpeg *pMpeg, SceMpegStream *pStream);
SceMpegHandle sceMpegMallocAvcEsBuf(SceMpeg *pMpeg);
SceVoid sceMpegFreeAvcEsBuf(SceMpeg *pMpeg, SceMpegHandle pBuf);
SceInt32 sceMpegInitAu(SceMpeg *pMpeg, SceVoid *pEsBuffer, SceMpegAu *pAu);
SceInt32 sceMpegQueryPcmEsSize(SceMpeg *pMpeg, SceInt32 *iEsSize, SceInt32 *iOutSize);
SceInt32 sceMpegFlushAllStream(SceMpeg *pMpeg);
int sceKernelDeleteCallback(int cbid);
int sceKernelTerminateDeleteThread(int thid);
int sceKernelWaitThreadEnd(int thid, void *timeout);
int printf(const char *fmt, ...);
void menuInit(void);
void menuTerm(int a, int b);

extern const char D_0000F9A8[];
extern const char D_0000F9C8[];
extern const char D_0000F9F8[];
extern const char D_0000FA18[];
extern const char D_0000FA44[];
extern const char D_0000FA68[];
extern const char D_0000FA8C[];
extern const char D_0000FAB8[];
extern const char D_0000FAD8[];
int puts(const char *s);
SceInt32 main(SceInt32 argc, SceChar8 **argv)
{
	SceMpeg mpeg;
	SceMpegRingbuffer ringbuf;
	SceMpegStream *pStream[2];
	SceMpegAu avcAu;
	SceMpegAu atracAu;
	SceChar8 *filename = "disc0:/PSP_GAME/USRDIR/DATA/movie/psmf/demo02.pmf";

	StrFile strFile;

	SceInt32 bufferSize, workSize, fileSize;
	SceInt32 audioEsSize, audioOutSize;
	SceInt32 streamOffset;
	SceInt32 ret;

	t_displayBuffer *pDisp = NULL;
	t_ringBuffer *pRing = NULL;
	t_soundBuffer *pSound = NULL;
	t_avSyncControl *pAvSync = NULL;
	t_conditionCtrl *pCtrl = NULL;
	t_mpegStreamData *pStreamData;

	SceMpegHandle avcEsBuf = NULL;
	SceChar8 *pPSPStream = NULL;
	SceChar8 *pWorkBuf = NULL;
	SceChar8 *pAudioBuf = NULL;

	SceUID exit_cb;

	menuInit();
	pStream[0] = NULL;
	pStream[1] = NULL;

	SceUID videoMid = 0;
	SceUID audioMid = 0;
	SceUID baseMid = 0;
	SceUID mpegMid = 0;

	SceKernelLMOption kMode;
	SceKernelLMOption uMode;

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
		puts(D_0000FAD8);
		goto term4;
	}

	audioFlag = 1;

	while (argc >= 2) {
		argv++;
		argc--;
		if (strcmp("-noaudio", argv[0]) == 0)
			audioFlag = 0;
		else
			filename = argv[0];
	}

	ret = sceMpegInit();
	if (ret != 0) {
		printf("fatal error : sceMpegInit() 0x%x\n", ret);
		goto term3;
	}

	bufferSize = sceMpegRingbufferQueryMemSize(0x12C0);
	if (bufferSize < 0) {
		printf("fatal error : sceMpegRingbufferQueryMemSize 0x%x\n", bufferSize);
		goto term3;
	}

	workSize = sceMpegQueryMemSize(0);
	if (workSize < 0) {
		printf("fatal error : sceMpegQueryMemSize 0x%x\n", workSize);
		goto term3;
	}

	pPSPStream = (SceChar8 *)malloc(bufferSize);
	if (pPSPStream == NULL) {
		printf("fatal error : malloc pPSPStream\n");
		goto term3;
	}

	pWorkBuf = (SceChar8 *)malloc(workSize);
	if (pWorkBuf == NULL) {
		printf(D_0000FAB8);
		goto term3;
	}

	ret = sceMpegRingbufferConstruct(&ringbuf, 0x12C0, pPSPStream, bufferSize, ringbufferCallBack, (SceVoid *)&strFile);
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

	if (readHeader(&mpeg, &strFile, &fileSize, &streamOffset) != 0) {
		printf("fatal error : readHeader\n");
		goto term3;
	}

	pStream[0] = sceMpegRegistStream(&mpeg, 0, 0);
	if (pStream[0] == NULL) {
		printf("fatal error : sceMpegRegistStream() AVC\n");
		goto term3;
	}

	if (audioFlag == 1) {
		pStream[1] = sceMpegRegistStream(&mpeg, 2, 0);
		if (pStream[1] == NULL) {
			puts(D_0000FA8C);
			goto term3;
		}
	}

	avcEsBuf = sceMpegMallocAvcEsBuf(&mpeg);
	if (avcEsBuf == NULL) {
		printf("fatal error : sceMpegMallocAvcEsBuf()\n");
		goto term3;
	}

	ret = sceMpegInitAu(&mpeg, avcEsBuf, &avcAu);
	if (ret != 0) {
		printf("fatal error : sceMpegInitAu() AVC 0x%x\n", ret);
		goto term3;
	}

	if (audioFlag == 1) {
		ret = sceMpegQueryPcmEsSize(&mpeg, &audioEsSize, &audioOutSize);
		if (ret != 0) {
			printf(D_0000FA18, ret);
			goto term3;
		}

		pAudioBuf = (SceChar8 *)memalign(64, audioEsSize);
		if (pAudioBuf == NULL) {
			puts(D_0000FA68);
			goto term3;
		}

		ret = sceMpegInitAu(&mpeg, pAudioBuf, &atracAu);
		if (ret != 0) {
			printf(D_0000FA44, ret);
			goto term3;
		}
	}

	sceCtrlSetSamplingMode(0);

	pStreamData = (t_mpegStreamData *)malloc(sizeof(t_mpegStreamData));
	if (pStreamData == NULL)
		goto term2;

	decode_setStreamData(pStreamData, pStream[0], &avcAu, pStream[1], &atracAu);

	pCtrl = (t_conditionCtrl *)malloc(sizeof(t_conditionCtrl));
	if (pCtrl == NULL)
		goto term2;
	control_create(pCtrl);

	pDisp = (t_displayBuffer *)malloc(sizeof(t_displayBuffer));
	if (pDisp == NULL)
		goto term2;

	if (dispbuf_create(pDisp, 0x88000, 4, pCtrl) < 0) {
		printf("fatal error : displayCreate()\n");
		goto term2;
	}

	if (audioFlag == 1) {
		pSound = (t_soundBuffer *)malloc(sizeof(t_soundBuffer));
		if (pSound == NULL)
			goto term2;

		if (soundbuf_create(pSound, audioOutSize * 4, 25, pCtrl) < 0) {
			puts(D_0000F9F8);
			goto term2;
		}
	}

	pRing = (t_ringBuffer *)malloc(sizeof(t_ringBuffer));
	if (pRing == NULL)
		goto term2;

	if (read_create(pRing, &ringbuf, pCtrl) < 0) {
		printf("fatal error read_create()\n");
		goto term2;
	}

	pAvSync = (t_avSyncControl *)malloc(sizeof(t_avSyncControl));
	if (pAvSync == NULL)
		goto term2;

	if (avsync_create(pAvSync, pDisp, pSound, 6) < 0) {
		printf("fatal error avsync_create()\n");
		goto term2;
	}

	sceKernelChangeThreadPriority(sceKernelGetThreadId(), 0x17);

	dispThread = sceKernelCreateThread("displayThread", dispbuf_func, 0x16, 0x800, 0, NULL);

	readThread = sceKernelCreateThread("readThread", read_func, 0x18, 0x800, 0, NULL);

	if (audioFlag == 1) {
		soundThread = sceKernelCreateThread("soundThread", soundbuf_func, 0x15, 0x800, 0, NULL);
	}

	exit_cb = sceKernelCreateCallback("ExitGame", exit_func, pCtrl);
	if (exit_cb <= 0) {
		printf(D_0000F9C8, exit_cb);
		goto term1;
	}

	sceKernelRegisterExitCallback(exit_cb);

	playInfo.playMode = 0;

	while (1) {
		{
			extern SceInt32 D_00010BA8; /* static SceInt32 count */

			printf("********** PlayMovie (%d) **********\n", D_00010BA8++);
		}

		if (strFileLseek(&strFile, streamOffset, 0) < 0) {
			puts(D_0000F9A8);
			goto term1;
		}

		if (audioFlag == 1)
			soundbuf_reset(pSound);
		dispbuf_reset(pDisp);
		read_reset(pRing, fileSize);
		avsync_reset(pAvSync);
		control_reset(pCtrl);

		if (audioFlag == 1)
			sceKernelStartThread(soundThread, 4, &pAvSync);
		sceKernelStartThread(dispThread, 4, &pAvSync);
		sceKernelStartThread(readThread, 4, &pRing);

		ret = playMovie(&mpeg, &ringbuf, pStreamData, pRing, pAvSync, pCtrl);
		if (ret == 0) {
			if (audioFlag == 1)
				sceKernelWaitThreadEnd(soundThread, NULL);
			sceKernelWaitThreadEnd(dispThread, NULL);
			sceKernelWaitThreadEnd(readThread, NULL);
			continue;
		}

		if (ret < 0) {
			printf("fatal error: playMovie()\n");
			goto term1;
		}

		if (playInfo.playMode == 1) {
			if (audioFlag == 1)
				sceKernelWaitThreadEnd(soundThread, NULL);
			sceKernelWaitThreadEnd(dispThread, NULL);
			sceKernelWaitThreadEnd(readThread, NULL);

			if (sceMpegFlushAllStream(&mpeg) != 0) {
				printf("fatal error : sceMpegFlushAllStream()\n");
				goto term1;
			}
			playInfo.playMode = 0;
		} else if (playInfo.playMode == 10) {
			break;
		}
	}

term1:
	if (audioFlag == 1)
		sceKernelWaitThreadEnd(soundThread, NULL);
	sceKernelWaitThreadEnd(dispThread, NULL);
	sceKernelWaitThreadEnd(readThread, NULL);

	if (audioFlag == 1)
		sceKernelTerminateDeleteThread(soundThread);
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
		pDisp = NULL;
	}

	if (pCtrl != NULL) {
		control_delete(pCtrl);
		free(pCtrl);
		pCtrl = NULL;
	}

	if (pStreamData != NULL)
		free(pStreamData);

term3:
	if (audioFlag == 1) {
		if (pAudioBuf != NULL)
			free(pAudioBuf);
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
		free(pWorkBuf);
	if (pPSPStream != NULL)
		free(pPSPStream);

term4:
	unloadModule(&mpegMid);
	unloadModule(&baseMid);
	unloadModule(&audioMid);
	unloadModule(&videoMid);

	printf("program end\n");

	menuTerm(2, 3);

	return 1;
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

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_pcm/nonmatchings/main", D_0000F9A8);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_pcm/nonmatchings/main", D_0000F9C8);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_pcm/nonmatchings/main", D_0000F9F8);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_pcm/nonmatchings/main", D_0000FA18);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_pcm/nonmatchings/main", D_0000FA44);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_pcm/nonmatchings/main", D_0000FA68);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_pcm/nonmatchings/main", D_0000FA8C);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_pcm/nonmatchings/main", D_0000FAB8);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_pcm/nonmatchings/main", D_0000FAD8);

SceInt32 decode_pcmDemux(SceMpeg *pMpeg, t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync);
SceInt32 decode_videoDecode(SceMpeg *pMpeg, t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync);
SceInt32 decode_videoDecodeEnd(SceMpeg *pMpeg, t_avSyncControl *pAvSync);
SceInt32 read_isEnd(t_ringBuffer *pRing);
SceInt32 read_isFull(t_ringBuffer *pRing);
SceInt32 read_decode_sleep(t_ringBuffer *pRing);
SceInt32 control_setCondition(t_conditionCtrl *pCtrl, SceUInt32 pattern);
SceInt32 startCheck(t_avSyncControl *pAvSync, t_ringBuffer *pRingCtrl, t_conditionCtrl *pCtrl);
SceInt32 sceMpegAvcDecodeFlush(SceMpeg *pMpeg);
SceInt32 sceMpegRingbufferAvailableSize(SceMpegRingbuffer *pRingbuffer);
int sceKernelCheckCallback(void);
int printf(const char *fmt, ...);

static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_ringBuffer *pRingCtrl, t_avSyncControl *pAvSync, t_conditionCtrl *pCtrl)
{
	SceInt32 demuxsize;
	SceInt32 readsize;
	SceInt32 ret;
	SceInt32 startFlag;

	startFlag = -1;

	while (1) {
		if (startFlag != 0) {
			startFlag = startCheck(pAvSync, pRingCtrl, pCtrl);
		} else {
			ret = pad_read(pAvSync->pDisp);
			if (ret != 0) {
				sceMpegAvcDecodeFlush(pMpeg);
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
			ret = decode_pcmDemux(pMpeg, pStreamData, pAvSync);
			if (ret < 0) {
				if (ret == (SceInt32)0x80618001) {
					if (read_isFull(pRingCtrl) == 0)
						read_decode_sleep(pRingCtrl);
				} else {
					printf("fatal error : decode_audioDecode() 0x%x\n", ret);
					goto error;
				}
			}
		}

		ret = decode_videoDecode(pMpeg, pStreamData, pAvSync);
		if (ret == (SceInt32)0x80618001) {
			if (read_isFull(pRingCtrl) == 0)
				read_decode_sleep(pRingCtrl);
		} else if (ret < 0) {
			goto video_error;
		}

		if (read_isFull(pRingCtrl) == 0)
			read_decode_sleep(pRingCtrl);

		sceKernelCheckCallback();
	}

	control_setCondition(pCtrl, 8);

	do {
		ret = decode_videoDecodeEnd(pMpeg, pAvSync);
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
extern const char D_0000F9A8[];

static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset)
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

	if (strFileLseek(pStrFile, 0, 0) < 0) {
		puts(D_0000F9A8); /* "fatal error : strFileLseek()", shared with an asm function */
		ret = -1;
		goto term;
	}

	ret = 0;

term:
	return ret;
}

extern u_int32 D_00010BAC; /* static SceUInt32 oldpadd in pad_read (bss is asm) */
extern u_int32 D_00010BB0; /* static SceUInt32 padd in pad_read */

static SceInt32 pad_read(t_displayBuffer *pDisp)
{
	SceCtrlData buf;

	D_00010BAC = D_00010BB0;
	sceCtrlReadBufferPositive(&buf, 1);
	D_00010BB0 = buf.Buttons;

	if (D_00010BB0 & 0x1) {
		playInfo.playMode = 10;
		return 1;
	} else if (D_00010BB0 & 0x8) {
		playInfo.playMode = 1;
		return 1;
	} else if (D_00010BB0 & ~D_00010BAC & 0x2000) {
		dispbuf_setDelayMode(pDisp);
	}

	return 0;
}
