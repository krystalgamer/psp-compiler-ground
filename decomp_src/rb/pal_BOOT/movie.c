#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <thread.h>
#include <ctrlsvc.h>
#include <libmpeg.h>
#include <libpsmf.h>
#include "strfile.h"
#include "display.h"
#include "sound.h"
#include "avsync.h"
#include "fileread.h"
#include "menu.h"

typedef struct {
	SceMpegStream *pAvcStream;
	SceMpegAu *pAvcAu;
	SceMpegStream *pAtracStream;
	SceMpegAu *pAtracAu;
} t_mpegStreamData;

typedef struct {
	SceInt32 playMode;
	SceUInt32 timestamp;
} t_playInfo;

typedef struct {
	int start;
	int size;
	int pts;
	int tstart;
	int tsize;
} PTS_INFO;

int BgmStart(void);
int BgmEnd(void);

extern MOVIE_LIST movie_list[12];
extern MENU_LIST menu_list;
extern SceChar8 *dispbuf[1];
extern t_playInfo playInfo;
#define strFile strFile_279F2C
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
extern PTS_INFO pinfo[12];
extern SceUID dispThread;
extern SceUID readThread;
extern SceUID soundThread;
extern SceChar8 *pPSPStream;
extern SceChar8 *pWorkBuf;
extern SceChar8 *pAudioBuf;
extern SceMpegHandle avcEsBuf;
extern SceInt32 audioFlag;
extern SceInt32 readFlag;

#define opadd D_002C55DC

static int init_pinfo(void);
static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_ringBuffer *pRingCtrl, t_avSyncControl *pAvSync);

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/movie", pad_read);


static int thumb_load(void)
{
	SceInt32 iReadSize;
	SceInt32 ret;
	SceChar8 stream_buf[2048];
	int strOffset;

retry1:
	if (strFileOpen(&strFile, "disc0:/PSP_GAME/USRDIR/MOVIE/menu.pmf", 1) < 0) {
		printf("fatal error : strFileOpen()\n");
		goto retry1;
	}
retry2:
	if (strFileLseek(&strFile, 0, 0) < 0)
		goto retry2;
retry3:
	if ((iReadSize = strFileRead(&strFile, stream_buf, 2048)) < 2048) {
		printf("fatal error : strFileRead() %x\n", iReadSize);
		goto retry3;
	}
	ret = sceMpegQueryStreamOffset(&mpeg, stream_buf, &strOffset);
	if (ret != 0) {
		printf("fatal error : sceMpegQueryStreamOffset()\n");
		return -1;
	}
	ret = sceMpegQueryStreamSize(stream_buf, &thumbFilesize);
	if (ret != 0) {
		printf("fatal error : sceMpegQueryStreamSize()\n");
		return -1;
	}
retry4:
	if (strFileLseek(&strFile, 0, 0) < 0) {
		printf("fatal error : strFileLseek()\n");
		goto retry4;
	}
	pHeaderT = malloc(strOffset);
	if (pHeaderT == NULL)
		return -1;
retry5:
	if ((iReadSize = strFileRead(&strFile, pHeaderT, strOffset)) < strOffset) {
		printf("fatal error : strFileRead() %x\n", iReadSize);
		goto retry5;
	}
	thumbBuf = memalign(64, thumbFilesize);
	if (thumbBuf == NULL) {
		printf("Can't malloc thumbnail buffer\n");
		return -1;
	}
retry6:
	if ((iReadSize = strFileRead(&strFile, thumbBuf, thumbFilesize)) < thumbFilesize) {
		printf("fatal error : strFileRead() %x\n", iReadSize);
		goto retry6;
	}
	strFileClose(&strFile);
	return 0;
}


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

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/movie", playMovie);

static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset)
{
	SceInt32 iReadSize;
	SceInt32 ret;
	SceChar8 stream_buf[2048];

	if (strFileLseek(pStrFile, 0, 0) < 0) {
		ret = -1;
		goto end;
	}
	iReadSize = strFileRead(pStrFile, stream_buf, 2048);
	if (iReadSize < 2048) {
		printf("fatal error : strFileRead() %x\n", iReadSize);
		ret = -1;
		goto end;
	}
	if (sceMpegQueryStreamOffset(pMpeg, stream_buf, strOffset) != 0) {
		printf("fatal error : sceMpegQueryStreamOffset()\n");
		ret = -1;
		goto end;
	}
	if (sceMpegQueryStreamSize(stream_buf, pFilesize) != 0) {
		printf("fatal error : sceMpegQueryStreamSize()\n");
		ret = -1;
		goto end;
	}
	if (strFileLseek(pStrFile, 0, 0) < 0) {
		printf("fatal error : strFileLseek()\n");
		ret = -1;
		goto end;
	}
	ret = -1;
	pHeader = malloc(*strOffset);
	if (pHeader != NULL) {
		iReadSize = strFileRead(pStrFile, pHeader, *strOffset);
		ret = 0;
		if (iReadSize < *strOffset) {
			printf("fatal error : strFileRead() %x\n", iReadSize);
			free(pHeader);
			ret = -1;
		}
	}
end:
	return ret;
}


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

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/movie", init_pinfo);

int MovieInit(void)
{
	SceInt32 bufferSize;
	SceInt32 workSize;
	SceInt32 ret;

	decodeMode.iDecodeMode = -1;
	audioFlag = 1;
	decodeMode.iPixelFormat = 3;
	ret = sceMpegInit();
	if (ret != 0) {
		printf("fatal error : sceMpegInit() %x\n", ret);
		return -1;
	}
	bufferSize = sceMpegRingbufferQueryMemSize(960);
	if (bufferSize < 0) {
		printf("fatal error : sceMpegRingbufferQueryMemSize %x\n", bufferSize);
		return -1;
	}
	workSize = sceMpegQueryMemSize(0);
	if (workSize < 0) {
		printf("fatal error : sceMpegQueryMemSize %x\n", workSize);
		return -1;
	}
	pPSPStream = malloc(bufferSize);
	if (pPSPStream == NULL) {
		printf("fatal error : malloc pPSPStream\n");
		return -1;
	}
	pWorkBuf = malloc(workSize);
	if (pWorkBuf == NULL) {
		printf("fatal error : malloc pWorkBuf\n;");
		return -1;
	}
	ret = sceMpegRingbufferConstruct(&ringbuf, 960, pPSPStream, bufferSize, ringbufferCallBack, &strFile);
	if (ret != 0) {
		printf("fatal error : sceMpegRingbufferConstruct() %x\n", ret);
		return -1;
	}
	ret = sceMpegCreate(&mpeg, pWorkBuf, workSize, &ringbuf, 512, 0, 0);
	if (ret != 0) {
		printf("fatal error : sceMpegCreate() %x\n", ret);
		return -1;
	}
	sceMpegAvcDecodeMode(&mpeg, &decodeMode);
	sceKernelChangeThreadPriority(sceKernelGetThreadId(), 0x40);
	dispThread = sceKernelCreateThread("displayThread", dispbuf_func, 0x3F, 0x800, 0, NULL);
	readThread = sceKernelCreateThread("readThread", read_func, 0x41, 0x800, 0, NULL);
	if (audioFlag)
		soundThread = sceKernelCreateThread("soundThread", soundbuf_func, 0x3D, 0x800, 0, NULL);
	playInfo.playMode = 0;
	thumb_load();
retry1:
	if (strFileOpen(&strFile, "disc0:/PSP_GAME/USRDIR/MOVIE/movie.pmf", 1) < 0) {
		printf("fatal error : strFileOpen()\n");
		goto retry1;
	}
retry2:
	if (readHeader(&mpeg, &strFile, &fileSize, &streamOffset) != 0) {
		printf("fatal error : readHeader\n");
		goto retry2;
	}
	init_pinfo();
	BgmStart();
	return 0;
}


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

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/movie", MovieTerm);

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
