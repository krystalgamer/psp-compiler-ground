#include "common.h"
#define strFile strFile_279F2C

/* declarations recovered from DWARF */
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
typedef int SceInt32;
struct t_displayBuffer { /* size 0x38 */
    SceUID start_sema;
    SceUID lock_sema;
    SceUID display_wait_sema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 *write;
    SceInt32 *read;
    SceInt32 *count;
    SceInt32 *size;
    SceInt32 pixelFormat;
    SceInt32 *displayMode;
    SceInt32 *scale;
    SceInt32 *posx;
    SceInt32 *posy;
};
typedef struct SceCtrlData SceCtrlData;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef void SceVoid;
struct _anon1;
struct _anon1 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon1 StrFile;
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_soundBuffer t_soundBuffer;
struct t_soundBuffer;
struct t_soundBuffer { /* size 0x24 */
    SceUID lock_sema;
    SceInt32 *terminate_flag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 *write;
    SceInt32 *read;
    SceInt32 *count;
    SceInt32 *size;
    SceUID start_sema;
};
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x14 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
};
struct t_avSyncControl { /* size 0x1c */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};
typedef struct t_ringBuffer t_ringBuffer;
struct t_ringBuffer;
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
struct t_ringBuffer { /* size 0x10 */
    SceInt32 data_len;
    SceUID ringbuf_sema;
    SceMpegRingbuffer *pRingbuf;
    SceInt32 *end_flag;
};
typedef struct SceMpeg SceMpeg;
struct SceMpeg;
struct SceMpeg { /* size 0x4 */
    SceVoid *sys;
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
struct t_mpegStreamData { /* size 0x10 */
    SceMpegStream *pAvcStream;
    SceMpegAu *pAvcAu;
    SceMpegStream *pAtracStream;
    SceMpegAu *pAtracAu;
};
typedef struct ScePsmf ScePsmf;
struct ScePsmf;
struct ScePsmf { /* size 0x28 */
    SceInt32 type;
    SceInt32 groupingPeriod_id;
    SceInt32 group_id;
    SceInt32 psmfStream_id;
    SceVoid *header;
    SceVoid *sequenceInfo;
    SceVoid *currentGroupingPeriod;
    SceVoid *currentGroup;
    SceVoid *currentStream;
    SceVoid *currentEP_map;
};
typedef struct ScePsmf_EntryPoint ScePsmf_EntryPoint;
struct ScePsmf_EntryPoint;
struct ScePsmf_EntryPoint { /* size 0x8 */
    SceUInt32 PTS_EP_start;
    SceUInt32 EP_start_offset;
};
struct _anon2;
struct _anon2 { /* size 0x1c */
    int thumbpts;
    int fullptss;
    int fullpts;
    int fullptse;
    void *texture;
    int posx;
    int posy;
};
typedef struct _anon2 MOVIE_LIST;
struct _anon3;
struct _anon3 { /* size 0x14 */
    int current;
    int page;
    int pos;
    int selected;
    int saved;
};
typedef struct _anon3 MENU_LIST;
typedef struct t_playInfo t_playInfo;
struct t_playInfo;
struct t_playInfo { /* size 0x8 */
    SceInt32 playMode;
    SceUInt32 timestamp;
};
struct _anon4;
struct _anon4 { /* size 0x8 */
    SceInt32 iDecodeMode;
    SceInt32 iPixelFormat;
};
typedef struct _anon4 SceMpegAvcMode;
struct _anon5;
struct _anon5 { /* size 0x10 */
    int start;
    int size;
    int tstart;
    int tsize;
};
typedef struct _anon5 PTS_INFO;
typedef SceUChar8 *SceMpegHandle;

extern MOVIE_LIST movie_list[];
extern MENU_LIST menu_list;
extern SceChar8 *dispbuf[1];
extern t_playInfo playInfo;
extern StrFile strFile;
extern SceInt32 streamOffset;
extern t_displayBuffer displayCtrl;
extern t_ringBuffer readCtrl;
extern t_soundBuffer soundCtrl;
extern SceInt32 fileSize;
extern t_avSyncControl avSync;
extern t_mpegStreamData mpegStreamData;
extern SceMpeg mpeg;
extern SceMpegRingbuffer ringbuf;
extern SceMpegStream *pStream[2];
extern SceMpegAu avcAu;
extern SceMpegAu atracAu;
extern SceMpegAvcMode decodeMode;
extern SceChar8 *thumbBuf;
extern SceChar8 *pthumbBuf;
extern int thumbFilesize;
extern int thumbRest;
extern SceChar8 *pHeaderT;
extern SceChar8 *pHeader;
extern ScePsmf psmf;
extern ScePsmf psmfT;
extern PTS_INFO pinfo[14];
extern SceUID dispThread;
extern SceUID readThread;
extern SceUID soundThread;
extern SceChar8 *pPSPStream;
extern SceChar8 *pWorkBuf;
extern SceChar8 *pAudioBuf;
extern SceMpegHandle avcEsBuf;
extern SceInt32 audioFlag;
extern SceInt32 readFlag;

static SceInt32 pad_read(t_displayBuffer *pDisp);
static int thumb_load(void);
static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData);
static SceInt32 startCheck(t_avSyncControl *pAvSync, t_ringBuffer *pRingCtrl);
static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_ringBuffer *pRingCtrl, t_avSyncControl *pAvSync);
static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset);
static int skip_data(ScePsmf *psm, SceUInt32 pts);
static int init_pinfo(void);
int MovieInit(void);
int MovieMain(void);
int MovieTerm(void);
int MovieStat(void);
int MovieStart(void);
int MovieEnd(void);


static SceInt32 pad_read(t_displayBuffer *pDisp)
{
	SceCtrlData buf;
	SceUInt32 padd;
	SceUInt32 pres;
	extern SceUInt32 opadd;
	int ret;

	ret = 0;
	sceCtrlReadBufferPositive(&buf, 1);
	padd = buf.Buttons;
	pres = padd & (padd ^ opadd);
	if (menu_list.selected == 0) {
		if (pres & 0x2000) {
			playInfo.playMode = 10;
			menu_list.selected = 1;
			ret = 1;
			BgmEnd();
		}
		if (pres & 0x10) {
			menu_list.current -= 3;
			if (menu_list.current < menu_list.page * 6) {
				menu_list.current += 3;
			} else {
				playInfo.playMode = 10;
				ret = 1;
			}
		} else if (pres & 0x40) {
			menu_list.current += 3;
			if (menu_list.current >= menu_list.page * 6 + 6) {
				menu_list.current -= 3;
			} else if (menu_list.current >= 14) {
				menu_list.current -= 3;
			} else {
				playInfo.playMode = 10;
				ret = 1;
			}
		} else if (pres & 0x20) {
			menu_list.current++;
			if (menu_list.current >= 14) {
				menu_list.current = 13;
			} else {
				if (menu_list.current % 6 == 0)
					menu_list.page++;
				playInfo.playMode = 10;
				ret = 1;
			}
		} else if (pres & 0x80) {
			menu_list.current--;
			if (menu_list.current < 0) {
				menu_list.current = 0;
			} else {
				if (menu_list.current % 6 == 5)
					menu_list.page--;
				playInfo.playMode = 10;
				ret = 1;
			}
		}
	} else {
		if (pres & 0x4000) {
			playInfo.playMode = 10;
			menu_list.selected = 0;
			ret = 1;
			BgmStart();
		}
	}
	opadd = padd;
	return ret;
}

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/movie", thumb_load);

void *memcpy(void *d, const void *s, unsigned int n);
static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData)
{
	SceInt32 iTypeSize;
	SceInt32 iReadSize;
	StrFile *pStrFile;

	iTypeSize = 2048;
	pStrFile = (StrFile *)CallbackData;
	if (readFlag) {
		iReadSize = strFileRead(pStrFile, pBuf, iTypeSize * iNum);
	} else {
		int size = iTypeSize * iNum;

		if (thumbRest < size) {
			memcpy(pBuf, pthumbBuf, thumbRest);
			iReadSize = thumbRest;
			thumbRest = 0;
			pthumbBuf = thumbBuf;
		} else {
			memcpy(pBuf, pthumbBuf, size);
			iReadSize = size;
			thumbRest -= size;
			pthumbBuf += size;
		}
	}
	return (iReadSize % iTypeSize) ? -1 : iReadSize / iTypeSize;
}

static SceInt32 startCheck(t_avSyncControl *pAvSync, t_ringBuffer *pRingCtrl)
{
	SceInt32 ret;

	if (audioFlag) {
		if (dispbuf_getCapacity(pAvSync->pDisp) == 0 && soundbuf_getCapacity(pAvSync->pSound) == 0 && read_isFull(pRingCtrl)) {
			avsync_playStart(pAvSync);
			ret = 0;
		} else {
			ret = -1;
		}
	} else {
		avsync_playStart(pAvSync);
		ret = 0;
	}
	return ret;
}

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/movie", D_0001634C);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/movie", D_00016368);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/movie", D_00016388);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/movie", D_000163B4);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/movie", D_000163DC);

INCLUDE_RODATA("tmp/asm/rb/jp_BOOT/nonmatchings/movie", D_000163FC);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/movie", playMovie);

#ifdef NON_MATCHING
/* compiles to the original, but its strings are shared with functions still in asm
   (merged constants), so it can only go in once the unit is all C */
typedef long long SceOff_;
SceOff_ strFileLseek(StrFile *file, SceOff_ offset, SceInt32 whence);
static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset)
{
	SceInt32 iReadSize;
	SceChar8 stream_buf[2048];

	if (strFileLseek(pStrFile, 0, 0) < 0)
		return -1;
	iReadSize = strFileRead(pStrFile, stream_buf, 2048);
	if (iReadSize < 2048) {
		printf("fatal error : strFileRead() %x\n", iReadSize);
		return -1;
	}
	if (sceMpegQueryStreamOffset(pMpeg, stream_buf, strOffset) != 0) {
		printf("fatal error : sceMpegQueryStreamOffset()\n");
		return -1;
	}
	if (sceMpegQueryStreamSize(stream_buf, pFilesize) != 0) {
		printf("fatal error : sceMpegQueryStreamSize()\n");
		return -1;
	}
	if (strFileLseek(pStrFile, 0, 0) < 0) {
		printf("fatal error : strFileLseek()\n");
		return -1;
	}
	pHeader = malloc(*strOffset);
	if (pHeader == NULL)
		return -1;
	iReadSize = strFileRead(pStrFile, pHeader, *strOffset);
	if (iReadSize < *strOffset) {
		printf("fatal error : strFileRead() %x\n", iReadSize);
		return -1;
	}
	return 0;
}
#else
INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/movie", readHeader);
#endif

int printf(const char *fmt, ...);
static int skip_data(ScePsmf *psm, SceUInt32 pts)
{
	SceInt32 ret;
	SceInt32 ep_id;
	ScePsmf_EntryPoint ep;

	ret = scePsmfGetEP_idWithTimestamp(psm, pts);
	if (ret < 0) {
		printf("fatal error : scePsmfGetEP_idWithTimestamp() 0x%x\n", ret);
	} else {
		ep_id = ret;
		ret = scePsmfGetEPWithId(psm, ep_id, &ep);
		if (ret != 0)
			printf("fatal error : scePsmfGetEPWithId() 0x%x\n", ret);
		else
			ret = ep.EP_start_offset;
	}
	return ret;
}

static int init_pinfo(void)
{
	int frame[2];
	int tframe[2];
	int ret;
	int i;

	ret = scePsmfCreate(&psmf, pHeader);
	if (ret != 0) {
		printf("fatal error : psmf create\n");
		return -1;
	}
	ret = scePsmfCreate(&psmfT, pHeaderT);
	if (ret != 0) {
		printf("fatal error : psmf create(thumb)\n");
		return -1;
	}
	for (i = 1; i < 13; i++) {
		frame[0] = skip_data(&psmf, movie_list[i].fullpts);
		if (frame[0] < 0)
			printf("fatal error: skip_data\n");
		frame[1] = skip_data(&psmf, movie_list[i + 1].fullpts);
		if (frame[1] < 0)
			printf("fatal error: skip_data\n");
		pinfo[i].start = frame[0];
		pinfo[i].size = frame[1] - frame[0] - 2048;
		tframe[0] = skip_data(&psmfT, movie_list[i].thumbpts);
		if (tframe[0] < 0)
			printf("fatal error: skip_dataT\n");
		tframe[1] = skip_data(&psmfT, movie_list[i + 1].thumbpts);
		if (tframe[1] < 0)
			printf("fatal error: skip_dataT\n");
		pinfo[i].tstart = tframe[0];
		pinfo[i].tsize = tframe[1] - tframe[0];
	}
	pinfo[i].start = skip_data(&psmf, movie_list[i].fullpts);
	pinfo[i].size = fileSize - frame[1];
	pinfo[i].tstart = skip_data(&psmfT, movie_list[i].thumbpts);
	pinfo[i].tsize = thumbFilesize - tframe[1];
	pinfo[0].start = skip_data(&psmf, movie_list[0].fullptss);
	pinfo[0].size = fileSize - pinfo[0].start;
	pinfo[0].tstart = pinfo[1].tstart;
	pinfo[0].tsize = thumbFilesize - pinfo[1].tstart;
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/movie", MovieInit);

int MovieMain(void)
{
	int ret;

	ret = playMovie(&mpeg, &ringbuf, &mpegStreamData, &readCtrl, &avSync);
	if (ret != 0) {
		if (ret < 0) {
			playInfo.playMode = 10;
			menu_list.selected = 0;
			BgmStart();
			return 1;
		}
			if (playInfo.playMode == 1) {
				if (sceMpegFlushAllStream(&mpeg) != 0)
					return -1;
				playInfo.playMode = 0;
			} else if (playInfo.playMode == 10) {
				return 1;
			}
	}
	return 0;
}

void free(void *p);
int MovieTerm(void)
{
	BgmEnd();
	if (audioFlag)
		sceKernelWaitThreadEnd(soundThread, NULL);
	sceKernelWaitThreadEnd(dispThread, NULL);
	sceKernelWaitThreadEnd(readThread, NULL);
	if (audioFlag)
		sceKernelTerminateDeleteThread(soundThread);
	sceKernelTerminateDeleteThread(dispThread);
	sceKernelTerminateDeleteThread(readThread);
	sceMpegDelete(&mpeg);
	sceMpegRingbufferDestruct(&ringbuf);
	sceMpegFinish();
	if (pWorkBuf)
		free(pWorkBuf);
	if (pPSPStream)
		free(pPSPStream);
	if (thumbBuf)
		free(thumbBuf);
	strFileClose(&strFile);
	return 0;
}

int MovieStat(void)
{
	return 1;
}

long long strFileLseek(StrFile *file, long long offset, SceInt32 whence);
int MovieStart(void)
{
	SceInt32 audioEsSize;
	SceInt32 audioOutSize;
	int fs;
	int ret;

	if (menu_list.selected == 1) {
		audioFlag = 1;
		readFlag = 1;
	} else {
		audioFlag = 0;
		readFlag = 0;
	}
	if (readFlag == 0) {
		pthumbBuf = thumbBuf + pinfo[menu_list.current].tstart;
		thumbRest = fs = pinfo[menu_list.current].tsize;
	} else {
		if (strFileLseek(&strFile, streamOffset + pinfo[menu_list.current].start, 0) < 0)
			return -1;
		fs = pinfo[menu_list.current].size + 0x1000;
	}
	pStream[0] = sceMpegRegistStream(&mpeg, 0, 0);
	if (pStream[0] == NULL) {
		printf("fatal error : sceMpegRegistStream() AVC\n");
		return -1;
	}
	if (audioFlag) {
		pStream[1] = sceMpegRegistStream(&mpeg, 1, 0);
		if (pStream[1] == NULL) {
			printf("fatal error : sceMpegRegistStream() ATRAC\n");
			return -1;
		}
	}
	avcEsBuf = sceMpegMallocAvcEsBuf(&mpeg);
	if (avcEsBuf == NULL) {
		printf("fatal error : sceMpegMallocAvcEsBuf()\n");
		return -1;
	}
	ret = sceMpegInitAu(&mpeg, avcEsBuf, &avcAu);
	if (ret != 0) {
		printf("fatal error : sceMpegInitAu() AVC %x\n", ret);
		return -1;
	}
	if (audioFlag) {
		ret = sceMpegQueryAtracEsSize(&mpeg, &audioEsSize, &audioOutSize);
		if (ret != 0) {
			printf("fatal error : sceQueryAtracEsSize() %x\n", ret);
			return -1;
		}
		pAudioBuf = memalign(64, audioEsSize);
		if (pAudioBuf == NULL) {
			printf("fatal error : memalign audioEsSize\n");
			return -1;
		}
		ret = sceMpegInitAu(&mpeg, pAudioBuf, &atracAu);
		if (ret != 0) {
			printf("fatal error : sceMpegInitAu() %x\n", ret);
			return -1;
		}
	}
	mpegStreamData.pAvcStream = pStream[0];
	mpegStreamData.pAtracStream = pStream[1];
	mpegStreamData.pAvcAu = &avcAu;
	mpegStreamData.pAtracAu = &atracAu;
	if (dispbuf_create(&displayCtrl, 0x88000, 1, decodeMode.iPixelFormat) < 0) {
		printf("fatal error : dispbuf_create()\n");
		return -1;
	}
	if (audioFlag) {
		if (soundbuf_create(&soundCtrl, audioOutSize, 4) < 0) {
			printf("fatal error : soundbuf_create()\n");
			return -1;
		}
	}
	if (read_create(&readCtrl, &ringbuf) < 0) {
		printf("fatal error : read_create()\n");
		return -1;
	}
	if (avsync_create(&avSync, &displayCtrl, &soundCtrl, 3) < 0) {
		printf("fatal error : avsync_create()\n");
		return -1;
	}
	if (audioFlag)
		soundbuf_init(&soundCtrl);
	dispbuf_init(&displayCtrl);
	avsync_init(&avSync);
	read_init(&readCtrl, fs);
	{
		MOVIE_LIST *pMv;

		pMv = &movie_list[menu_list.current];
		dispbuf_scale(&displayCtrl, menu_list.selected);
		dispbuf_pos(&displayCtrl, pMv->posx, pMv->posy);
	}
	if (audioFlag)
		sceKernelStartThread(soundThread, sizeof(t_avSyncControl), &avSync);
	sceKernelStartThread(dispThread, sizeof(t_avSyncControl), &avSync);
	sceKernelStartThread(readThread, sizeof(t_ringBuffer), &readCtrl);
	return 0;
}

int MovieEnd(void)
{
	if (audioFlag)
		sceKernelWaitThreadEnd(soundThread, NULL);
	sceKernelWaitThreadEnd(dispThread, NULL);
	sceKernelWaitThreadEnd(readThread, NULL);
	avsync_end(&avSync);
	read_end(&readCtrl);
	if (audioFlag)
		soundbuf_end(&soundCtrl);
	dispbuf_end(&displayCtrl);
	if (audioFlag && pAudioBuf)
		free(pAudioBuf);
	sceMpegFreeAvcEsBuf(&mpeg, avcEsBuf);
	sceMpegUnRegistStream(&mpeg, pStream[0]);
	if (audioFlag)
		sceMpegUnRegistStream(&mpeg, pStream[1]);
	return 0;
}
