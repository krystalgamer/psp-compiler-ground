#include "common.h"

/* declarations recovered from DWARF */
typedef int SceInt32;
typedef void SceVoid;
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
typedef struct t_soundBuffer t_soundBuffer;
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
struct _anon1;
struct _anon1 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon1 StrFile;
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
typedef struct t_displayBuffer t_displayBuffer;
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
    SceMpegStream *pAtracStream;
    SceMpegAu *pAtracAu;
};
typedef struct t_mpegStreamData t_mpegStreamData;
typedef SceUChar8 *SceMpegHandle;
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
extern t_playInfo playInfo;
extern SceInt32 audioFlag;
extern SceInt32 frameCount;
extern SceInt32 frameLoss;
extern SceUID soundThread;

static SceInt32 loadModule(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option);
static SceInt32 unloadModule(SceUID *mid);
static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData);
SceInt32 main(SceInt32 argc, SceChar8 **argv);
static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset);
static SceInt32 startCheck(t_avSyncControl *pAvSync, SceMpegRingbuffer *pRB, SceInt32 filesize, SceInt32 demuxsize);
static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync, SceInt32 filesize);

/* SDK functions (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
void sceKernelExitGame(void);


/* SDK prototypes (tools/sdk_protos.h) */
void free(void *p);
void *malloc(unsigned int size);
void *memalign(unsigned int align, unsigned int size);
int sceCtrlSetSamplingMode(int mode);
int sceDisplayGetVcount(void);
int sceDisplayWaitVblankStart(void);
int sceKernelChangeThreadPriority(int thid, int prio);
int sceKernelCreateCallback(const char *name, void *func, void *arg);
int sceKernelCreateThread(const char *name, void *entry, int prio, int stacksize, unsigned int attr, void *option);
int sceKernelGetThreadId(void);
int sceKernelRegisterExitCallback(int cbid);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);
int strcmp(const char *a, const char *b);

int exit_func(int count, int arg1, void *arg2) {
    if (audioFlag == 1) {
        soundbuf_setDemuxEnd(arg2);
        sceKernelWaitThreadEnd(soundThread, 0);
    }
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

static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData)
{
	SceInt32 iTypeSize = 0x800;
	SceInt32 iReadSize;
	StrFile *pStrFile = (StrFile *)CallbackData;

	iReadSize = strFileRead(pStrFile, pBuf, iNum * iTypeSize);

	if (iReadSize == (SceInt32)0x80210003) {
		return 0;
	}

	if (iReadSize % iTypeSize != 0) {
		return -1;
	}

	return iReadSize / iTypeSize;
}

long long strFileLseek(StrFile *file, long long offset, SceInt32 whence);
SceInt32 decode_setStreamData(t_mpegStreamData *pStreamData, SceMpegStream *pStreamV, SceMpegAu *pAvcAu, SceMpegStream *pStreamA, SceMpegAu *pAtracAu);
SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 a, SceInt32 b);
SceInt32 dispbuf_delete(t_displayBuffer *pDisp);
SceInt32 dispbuf_reset(t_displayBuffer *pDisp);
SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 a, SceInt32 b);
SceInt32 soundbuf_delete(t_soundBuffer *pSound);
SceInt32 soundbuf_reset(t_soundBuffer *pSound);
SceInt32 avsync_create(t_avSyncControl *pAvSync, t_displayBuffer *pDisp, t_soundBuffer *pSound, SceInt32 n);
SceInt32 avsync_delete(t_avSyncControl *pAvSync);
SceInt32 avsync_reset(t_avSyncControl *pAvSync);
SceInt32 soundbuf_func(SceSize size, SceVoid *argp);
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
SceInt32 sceMpegQueryAtracEsSize(SceMpeg *pMpeg, SceInt32 *iEsSize, SceInt32 *iOutSize);
SceInt32 sceMpegFlushAllStream(SceMpeg *pMpeg);
int sceKernelDeleteCallback(int cbid);
int sceKernelTerminateDeleteThread(int thid);
void menuInit(void);
void menuTerm(int a, int b);
int puts(const char *s);
extern const char D_0000F12C[], D_0000F14C[], D_0000F168[], D_0000F17C[], D_0000F188[], D_0000F190[], D_0000F1B8[];
extern const char D_0000F1E8[], D_0000F208[], D_0000F230[], D_0000F254[], D_0000F278[], D_0000F2A4[], D_0000F2C4[];
SceInt32 main(SceInt32 argc, SceChar8 **argv)
{
	SceMpeg mpeg;
	SceMpegRingbuffer ringbuf;
	SceMpegStream *pStream[2];
	SceMpegAu avcAu;
	SceMpegAu atracAu;
	SceChar8 *filename = "disc0:/PSP_GAME/USRDIR/DATA/movie/psmf/demo01.pmf";

	StrFile strFile;

	SceInt32 bufferSize, workSize, fileSize;
	SceInt32 audioEsSize, audioOutSize;
	SceInt32 streamOffset;
	SceInt32 ret;

	t_displayBuffer *pDisp = NULL;
	t_soundBuffer *pSound = NULL;
	t_avSyncControl *pAvSync = NULL;
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
		puts(D_0000F2C4);
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
		printf("fatal error : sceMpegInit() %x\n", ret);
		goto term3;
	}

	bufferSize = sceMpegRingbufferQueryMemSize(0x12C0);
	if (bufferSize < 0) {
		printf("fatal error : sceMpegRingbufferQueryMemSize %x\n", bufferSize);
		goto term3;
	}

	workSize = sceMpegQueryMemSize(0);
	if (workSize < 0) {
		printf("fatal error : sceMpegQueryMemSize %x\n", workSize);
		goto term3;
	}

	pPSPStream = (SceChar8 *)malloc(bufferSize);
	if (pPSPStream == NULL) {
		printf("fatal error : malloc pPSPStream\n");
		goto term3;
	}

	pWorkBuf = (SceChar8 *)malloc(workSize);
	if (pWorkBuf == NULL) {
		printf(D_0000F2A4);
		goto term3;
	}

	ret = sceMpegRingbufferConstruct(&ringbuf, 0x12C0, pPSPStream, bufferSize, ringbufferCallBack, (SceVoid *)&strFile);
	if (ret != 0) {
		printf("fatal error : sceMpegRingbufferConstruct() %x\n", ret);
		goto term3;
	}

	ret = sceMpegCreate(&mpeg, pWorkBuf, workSize, &ringbuf, 512, 0, NULL);
	if (ret != 0) {
		printf("fatal error : sceMpegCreate() %x\n", ret);
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
		pStream[1] = sceMpegRegistStream(&mpeg, 1, 0);
		if (pStream[1] == NULL) {
			puts(D_0000F278);
			goto term3;
		}
	}

	avcEsBuf = sceMpegMallocAvcEsBuf(&mpeg);
	if (avcEsBuf == NULL) {
		printf("fatal error : sceMpegMallocAvcEsBuf()\n");
		goto term3;
	}

	if ((ret = sceMpegInitAu(&mpeg, avcEsBuf, &avcAu) != 0)) {
		printf("fatal error : sceMpegInitAu() AVC %x\n", ret);
		goto term3;
	}

	if (audioFlag == 1) {
		ret = sceMpegQueryAtracEsSize(&mpeg, &audioEsSize, &audioOutSize);
		if (ret != 0) {
			printf(D_0000F208, ret);
			goto term3;
		}

		pAudioBuf = (SceChar8 *)memalign(64, audioEsSize);
		if (pAudioBuf == NULL) {
			puts(D_0000F254);
			goto term3;
		}

		ret = sceMpegInitAu(&mpeg, pAudioBuf, &atracAu);
		if (ret != 0) {
			printf(D_0000F230, ret);
			goto term3;
		}
	}

	sceCtrlSetSamplingMode(0);

	pStreamData = (t_mpegStreamData *)malloc(sizeof(t_mpegStreamData));
	if (pStreamData == NULL)
		goto term2;

	decode_setStreamData(pStreamData, pStream[0], &avcAu, pStream[1], &atracAu);

	pDisp = (t_displayBuffer *)malloc(sizeof(t_displayBuffer));
	if (pDisp == NULL)
		goto term2;

	if (dispbuf_create(pDisp, 0x88000, 4) < 0) {
		printf("fatal error : dispbuf_create()\n");
		goto term2;
	}

	if (audioFlag == 1) {
		pSound = (t_soundBuffer *)malloc(sizeof(t_soundBuffer));
		if (pSound == NULL)
			goto term2;
		if (soundbuf_create(pSound, audioOutSize, 5) < 0) {
			puts(D_0000F1E8);
			goto term2;
		}
	}

	pAvSync = (t_avSyncControl *)malloc(sizeof(t_avSyncControl));
	if (pAvSync == NULL)
		goto term2;

	if (avsync_create(pAvSync, pDisp, pSound, 6) < 0) {
		printf("fatal error avsync_create()\n");
		goto term2;
	}

	sceKernelChangeThreadPriority(sceKernelGetThreadId(), 0x3F);

	if (audioFlag == 1) {
		soundThread = sceKernelCreateThread("soundThread", soundbuf_func, 0x3D, 0x800, 0, NULL);
	}

	exit_cb = sceKernelCreateCallback("ExitGame", exit_func, pSound);
	if (exit_cb <= 0) {
		printf(D_0000F1B8, exit_cb);
		goto term1;
	}

	sceKernelRegisterExitCallback(exit_cb);

	playInfo.playMode = 0;

	while (1) {
		{
			extern SceInt32 D_0001031C; /* static SceInt32 count */

			printf("********** PlayMovie (%d) **********\n", D_0001031C++);
		}

		if (strFileLseek(&strFile, streamOffset, 0) < 0) {
			puts(D_0000F12C);
			goto term1;
		}

		dispbuf_reset(pDisp);
		if (audioFlag == 1)
			soundbuf_reset(pSound);
		avsync_reset(pAvSync);

		if (audioFlag == 1)
			sceKernelStartThread(soundThread, 4, &pAvSync);

		ret = playMovie(&mpeg, &ringbuf, pStreamData, pAvSync, fileSize);
		if (ret == 0) {
			if (audioFlag == 1)
				sceKernelWaitThreadEnd(soundThread, NULL);
			continue;
		}

		if (ret < 0) {
			puts(D_0000F14C);
			goto term1;
		}

		if (playInfo.playMode == 1) {
			puts(D_0000F188);
			if (audioFlag == 1)
				sceKernelWaitThreadEnd(soundThread, NULL);

			if (sceMpegFlushAllStream(&mpeg) != 0) {
				puts(D_0000F190);
				goto term1;
			}
			playInfo.playMode = 0;
		} else if (playInfo.playMode == 10) {
			puts(D_0000F168);
			break;
		}
	}

term1:
	if (audioFlag == 1) {
		sceKernelWaitThreadEnd(soundThread, NULL);
		sceKernelTerminateDeleteThread(soundThread);
	}

	sceKernelDeleteCallback(exit_cb);

term2:
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

	puts(D_0000F17C);

	menuTerm(2, 0);

	return 1;
}

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F12C);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F14C);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F168);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F17C);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F188);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F190);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F1B8);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F1E8);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F208);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F230);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F254);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F278);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F2A4);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F2C4);

long long strFileLseek(StrFile *file, long long offset, SceInt32 whence);
extern const char D_0000F12C[];

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
		printf("fatal error : strFileRead() %x\n", iReadSize);
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
		puts(D_0000F12C); /* "fatal error : strFileLseek()", shared with an asm function */
		ret = -1;
		goto term;
	}

	ret = 0;

term:
	return ret;
}

extern SceCtrlData D_00010320;

int pad_read(void) {
    int var_a0;

    sceCtrlReadBufferPositive(&D_00010320, 1);
    var_a0 = 1;
    if (D_00010320.Buttons & 1) {
        playInfo.playMode = 0xA;
    } else {
        var_a0 = 0;
        if (D_00010320.Buttons & 8) {
            playInfo.playMode = 1;
            var_a0 = 1;
        }
    }
    return var_a0;
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
			ret = pad_read();
			if (ret != 0) {
				sceMpegAvcDecodeFlush(pMpeg);
				if (audioFlag == 1)
					soundbuf_setDemuxEnd(pAvSync->pSound);
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
			while (1) {
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
						printf("fatal error : decode_audioDecode() 0x%x\n", ret);
						goto error;
					}
				}
				ret = decode_videoDecode(pMpeg, pStreamData, pAvSync);
				if (ret >= 0)
					break;
				if (ret != (SceInt32)0x80618001) {
					printf("fatal error : sceMpegGetAvcAu () 0x%x\n", ret);
					goto error;
				}
			}
			break;
		case 1:
			ret = decode_videoDecodeEnd(pMpeg, pAvSync);
			if (ret < 0) {
				printf("fatal error : decode_videoDecodeEnd() 0x%x\n", ret);
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
					sceDisplayWaitVblankStart();
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
	printf("frame count = %d\n", frameCount);
	printf("frame loss = %d\n", frameLoss);
	return ret;
}
