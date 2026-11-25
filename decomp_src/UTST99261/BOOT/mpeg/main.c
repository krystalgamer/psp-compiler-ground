#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread.h>
#include <ctrlsvc.h>
#include <libmpeg.h>
#include "strfile.h"
#include "display.h"
#include "sound.h"
#include "avsync.h"
#include "fileread.h"

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

void ModMgrInit(void);
void ModMgrTerm(void);

#define count D_00247CB4
#define padd D_00247CBC
#define opadd D_00247CB8
#define readHeader readHeader_6370

extern SceChar8 *dispbuf[1];
extern SceInt32 audioFlag;
extern t_playInfo playInfo;

static SceInt32 startCheck(t_avSyncControl *pAvSync, t_ringBuffer *pRingCtrl);
static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_ringBuffer *pRingCtrl, t_avSyncControl *pAvSync);
static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset);
static SceInt32 pad_read(t_displayBuffer *pDisp);

static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData)
{
	SceInt32 iTypeSize;
	SceInt32 iReadSize;

	iTypeSize = 2048;
	iReadSize = strFileRead((StrFile *)CallbackData, pBuf, iTypeSize * iNum);
	return (iReadSize % iTypeSize) ? -1 : iReadSize / iTypeSize;
}

SceInt32 mpeg_main(char *filename)
{
	SceMpegRingbuffer ringbuf;
	SceMpegStream *pStream[2];
	SceMpegAu avcAu;
	SceMpegAu atracAu;
	StrFile strFile;
	t_displayBuffer displayCtrl;
	t_ringBuffer readCtrl;
	t_soundBuffer soundCtrl;
	t_avSyncControl avSync;
	t_mpegStreamData mpegStreamData;
	SceMpeg mpeg;
	SceInt32 fileSize;
	SceInt32 streamOffset;
	SceInt32 audioEsSize;
	SceInt32 audioOutSize;
	SceMpegHandle avcEsBuf = NULL;
	SceChar8 *pAudioBuf = NULL;
	SceUID soundThread = 0;
	SceUID dispThread;
	SceUID readThread;
	SceChar8 *pPSPStream = NULL;
	SceChar8 *pWorkBuf = NULL;
	SceInt32 bufferSize;
	SceInt32 workSize;
	SceInt32 ret;
	extern int count;

	ModMgrInit();
	audioFlag = 1;
	ret = sceMpegInit();
	if (ret != 0) {
		printf("fatal error : sceMpegInit() 0x%x\n", ret);
		goto term_mpeg;
	}
	bufferSize = sceMpegRingbufferQueryMemSize(320);
	if (bufferSize < 0) {
		printf("fatal error : sceMpegRingbufferQueryMemSize 0x%x\n", bufferSize);
		goto term_mpeg;
	}
	workSize = sceMpegQueryMemSize(0);
	if (workSize < 0) {
		printf("fatal error : sceMpegQueryMemSize 0x%x\n", workSize);
		goto term_mpeg;
	}
	pPSPStream = malloc(bufferSize);
	if (pPSPStream == NULL) {
		printf("fatal error : malloc pPSPStream\n");
		goto term_mpeg;
	}
	pWorkBuf = malloc(workSize);
	if (pWorkBuf == NULL) {
		printf("fatal error : malloc pWorkBuf\n;");
		goto term_mpeg;
	}
	ret = sceMpegRingbufferConstruct(&ringbuf, 320, pPSPStream, bufferSize, ringbufferCallBack, &strFile);
	if (ret != 0) {
		printf("fatal error : sceMpegRingbufferConstruct() 0x%x\n", ret);
		goto term_mpeg;
	}
	ret = sceMpegCreate(&mpeg, pWorkBuf, workSize, &ringbuf, 512, 0, 0);
	if (ret != 0) {
		printf("fatal error : sceMpegCreate() 0x%x\n", ret);
		goto term_mpeg;
	}
	if (strFileAssign(&strFile, filename, 1) < 0) {
		printf("fatal error : strFileAssign()\n");
		goto term_mpeg;
	}
	if (strFileOpen(&strFile, filename, 1) < 0) {
		printf("fatal error : strFileOpen()\n");
		goto term_mpeg;
	}
	if (readHeader(&mpeg, &strFile, &fileSize, &streamOffset) != 0) {
		printf("fatal error : readHeader\n");
		goto term_mpeg;
	}
	pStream[0] = sceMpegRegistStream(&mpeg, 0, 0);
	if (pStream[0] == NULL) {
		printf("fatal error : sceMpegRegistStream() AVC\n");
		goto term_au;
	}
	if (audioFlag) {
		pStream[1] = sceMpegRegistStream(&mpeg, 1, 0);
		if (pStream[1] == NULL) {
			printf("fatal error : sceMpegRegistStream() ATRAC\n");
			goto term_au;
		}
	}
	avcEsBuf = sceMpegMallocAvcEsBuf(&mpeg);
	if (avcEsBuf == NULL) {
		printf("fatal error : sceMpegMallocAvcEsBuf()\n");
		goto term_au;
	}
	ret = sceMpegInitAu(&mpeg, avcEsBuf, &avcAu);
	if (ret != 0) {
		printf("fatal error : sceMpegInitAu() AVC 0x%x\n", ret);
		goto term_au;
	}
	if (audioFlag) {
		ret = sceMpegQueryAtracEsSize(&mpeg, &audioEsSize, &audioOutSize);
		if (ret != 0) {
			printf("fatal error : sceQueryAtracEsSize() 0x%x\n", ret);
			goto term_au;
		}
		pAudioBuf = memalign(64, audioEsSize);
		if (pAudioBuf == NULL) {
			printf("fatal error : memalign audioEsSize\n");
			goto term_au;
		}
		ret = sceMpegInitAu(&mpeg, pAudioBuf, &atracAu);
		if (ret != 0) {
			printf("fatal error : sceMpegInitAu() 0x%x\n", ret);
			goto term_au;
		}
	}
	mpegStreamData.pAvcStream = pStream[0];
	mpegStreamData.pAvcAu = &avcAu;
	mpegStreamData.pAtracStream = pStream[1];
	mpegStreamData.pAtracAu = &atracAu;
	sceCtrlSetSamplingMode(0);
	if (dispbuf_create(&displayCtrl, 0x88000, 4) < 0) {
		printf("fatal error : dispbuf_create()\n");
		goto term_disp;
	}
	if (audioFlag) {
		if (soundbuf_create(&soundCtrl, audioOutSize, 4) < 0) {
			printf("fatal error soundbuf_create()\n");
			goto term_sound;
		}
	}
	if (read_create(&readCtrl, &ringbuf) < 0) {
		printf("fatal error read_create()\n");
		goto term_read;
	}
	if (audioFlag)
		ret = avsync_create(&avSync, &displayCtrl, &soundCtrl, 6);
	else
		ret = avsync_create(&avSync, &displayCtrl, NULL, 6);
	if (ret < 0) {
		printf("fatal error avsync_create()\n");
		goto term_avsync;
	}
	sceKernelChangeThreadPriority(sceKernelGetThreadId(), 0x17);
	dispThread = sceKernelCreateThread("displayThread", display_func, 0x16, 0x800, 0, NULL);
	readThread = sceKernelCreateThread("readThread", read_func, 0x18, 0x800, 0, NULL);
	if (audioFlag)
		soundThread = sceKernelCreateThread("soundThread", soundbuf_func, 0x15, 0x800, 0, NULL);
	playInfo.playMode = 0;
	for (;;) {
		printf("********** PlayMovie (%d) **********\n", count++);
		if (strFileLseek(&strFile, streamOffset, 0) < 0) {
			printf("fatal error : strFileLseek()\n");
			goto term_thread;
		}
		if (audioFlag)
			soundbuf_init(&soundCtrl);
		dispbuf_init(&displayCtrl);
		read_init(&readCtrl, fileSize);
		avsync_init(&avSync);
		if (audioFlag)
			sceKernelStartThread(soundThread, sizeof(avSync), &avSync);
		sceKernelStartThread(dispThread, sizeof(avSync), &avSync);
		sceKernelStartThread(readThread, sizeof(readCtrl), &readCtrl);
		ret = playMovie(&mpeg, &ringbuf, &mpegStreamData, &readCtrl, &avSync);
		if (ret != 0) {
			if (ret < 0) {
				printf("fatal error: playMovie()\n");
				goto term_thread;
			}
			if (playInfo.playMode == 1) {
				if (sceMpegFlushAllStream(&mpeg) != 0) {
					printf("fatal error : sceMpegFlushAllStream()\n");
					goto term_thread;
				}
				playInfo.playMode = 0;
			} else if (playInfo.playMode == 10) {
				printf("abort playMovie()\n");
				goto term_thread;
			}
		}
		if (audioFlag)
			sceKernelWaitThreadEnd(soundThread, NULL);
		sceKernelWaitThreadEnd(dispThread, NULL);
		sceKernelWaitThreadEnd(readThread, NULL);
	}
term_thread:
	if (audioFlag)
		sceKernelWaitThreadEnd(soundThread, NULL);
	sceKernelWaitThreadEnd(dispThread, NULL);
	sceKernelWaitThreadEnd(readThread, NULL);
	if (audioFlag)
		sceKernelTerminateDeleteThread(soundThread);
	sceKernelTerminateDeleteThread(dispThread);
	sceKernelTerminateDeleteThread(readThread);
term_avsync:
	avsync_end(&avSync);
term_read:
	read_end(&readCtrl);
term_sound:
	if (audioFlag)
		soundbuf_end(&soundCtrl);
term_disp:
	dispbuf_end(&displayCtrl);
term_au:
	if (audioFlag) {
		if (pAudioBuf)
			free(pAudioBuf);
	}
	sceMpegFreeAvcEsBuf(&mpeg, avcEsBuf);
	sceMpegUnRegistStream(&mpeg, pStream[0]);
	if (audioFlag)
		sceMpegUnRegistStream(&mpeg, pStream[1]);
term_mpeg:
	strFileClose(&strFile);
	strFileUnassign(&strFile);
	sceMpegDelete(&mpeg);
	sceMpegRingbufferDestruct(&ringbuf);
	sceMpegFinish();
	if (pWorkBuf)
		free(pWorkBuf);
	if (pPSPStream)
		free(pPSPStream);
	ModMgrTerm();
	printf("program end\n");
	return 1;
}

#ifdef NON_MATCHING
/* the original shares one capacity test between the audio and video-only paths */
static SceInt32 startCheck(t_avSyncControl *pAvSync, t_ringBuffer *pRingCtrl)
{
	if (audioFlag) {
		if (dispbuf_getCapacity(pAvSync->pDisp) == 0 && soundbuf_getCapacity(pAvSync->pSound) == 0 && read_isFull(pRingCtrl)) {
			avsync_playStart(pAvSync);
			return 0;
		}
	} else {
		if (dispbuf_getCapacity(pAvSync->pDisp) == 0 && read_isFull(pRingCtrl)) {
			avsync_playStart(pAvSync);
			return 0;
		}
	}
	return -1;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mpeg/main", startCheck);
#endif

#ifdef NON_MATCHING
/* the original keeps &dispbuf in s3 across the final decode loop */
static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_ringBuffer *pRingCtrl, t_avSyncControl *pAvSync)
{
	SceVoid *atracBody;
	SceChar8 *pSoundCtrlBuf;
	SceInt32 avcAttr;
	SceChar8 *pVideoBuf;
	SceInt32 rgbNum;
	SceUInt32 pts;
	SceInt32 audio_init_flag;
	SceInt32 start;
	SceInt32 res;
	SceInt32 ret;

	audio_init_flag = 1;
	start = -1;
	for (;;) {
		if (start != 0) {
			start = startCheck(pAvSync, pRingCtrl);
		} else {
			ret = pad_read(pAvSync->pDisp);
			if (ret != 0)
				break;
		}
		if (read_isEnd(pRingCtrl) == 1 && sceMpegRingbufferAvailableSize(pRB) == 320) {
			ret = -1;
			break;
		}
		if (read_getStatus(pRingCtrl) == 1) {
			printf("error");
			ret = -1;
			goto term;
		}
		if (audioFlag == 1 && soundbuf_getCapacity(pAvSync->pSound) > 0
		    && sceMpegGetAtracAu(pMpeg, pStreamData->pAtracStream, pStreamData->pAtracAu, &atracBody) == 0) {
			soundbuf_getDrawbuf(pAvSync->pSound, &pSoundCtrlBuf);
			ret = sceMpegAtracDecode(pMpeg, pStreamData->pAtracAu, pSoundCtrlBuf, audio_init_flag);
			if (ret != 0) {
				printf("fatal error : sceMpegAtracDecode() 0x%x\n", ret);
				goto term;
			}
			soundbuf_setPts(pAvSync->pSound, pStreamData->pAtracAu->pts.ts);
			if (audio_init_flag == 0)
				soundbuf_setBuf(pAvSync->pSound);
			audio_init_flag = 0;
		} else {
			if (read_isFull(pRingCtrl) == 0)
				read_decode_sleep(pRingCtrl);
		}
		if (dispbuf_getCapacity(pAvSync->pDisp) > 0) {
			res = sceMpegGetAvcAu(pMpeg, pStreamData->pAvcStream, pStreamData->pAvcAu, &avcAttr);
			if (res == 0) {
				dispbuf_getDrawbuf(pAvSync->pDisp, &pVideoBuf);
				dispbuf[0] = pVideoBuf;
				ret = sceMpegAvcDecode(pMpeg, pStreamData->pAvcAu, 512, dispbuf, &rgbNum);
				if (ret != 0) {
					printf("fatal error : sceMpegAvcDecode() 0x%x\n", ret);
					goto term;
				}
				avsync_video_setPts(pAvSync, pStreamData->pAvcAu->pts.ts);
				if (rgbNum == 1) {
					avsync_video_getPts(pAvSync, &pts);
					dispbuf_setPts(pAvSync->pDisp, pts);
					dispbuf_dataSet(pAvSync->pDisp);
				}
			} else if (res == (SceInt32)0x80618001) {
				if (read_isFull(pRingCtrl) == 0)
					read_decode_sleep(pRingCtrl);
			} else {
				printf("fatal error : sceMpegGetAvcAu () 0x%x\n", res);
				ret = -1;
				goto term;
			}
		} else {
			if (read_isFull(pRingCtrl) == 0)
				read_decode_sleep(pRingCtrl);
		}
		if (read_isFull(pRingCtrl) == 0)
			read_decode_sleep(pRingCtrl);
	}
	avsync_playStart(pAvSync);
	read_setDemuxEnd(pRingCtrl);
	if (audioFlag)
		soundbuf_setDemuxEnd(pAvSync->pSound);
	while (dispbuf_getDrawbuf(pAvSync->pDisp, &pVideoBuf) <= 0)
		dispbuf_decode_sleep(pAvSync->pDisp);
	dispbuf[0] = pVideoBuf;
	{
		SceInt32 stop;

		stop = sceMpegAvcDecodeStop(pMpeg, 512, dispbuf, &rgbNum);
		if (stop != 0) {
			printf("fatal error : sceMpegGetAvcDecodeStop() 0x%x\n", stop);
			ret = stop;
			goto term;
		}
	}
	if (rgbNum > 0) {
		avsync_video_getPts(pAvSync, &pts);
		dispbuf_setPts(pAvSync->pDisp, pts);
		dispbuf_dataSet(pAvSync->pDisp);
	}
	dispbuf_setMode(pAvSync->pDisp, 0xFF);
	return ret;
term:
	read_setDemuxEnd(pRingCtrl);
	if (audioFlag)
		soundbuf_setDemuxEnd(pAvSync->pSound);
	dispbuf_setMode(pAvSync->pDisp, 0xFF);
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mpeg/main", playMovie);
#endif

static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset)
{
	SceInt32 iReadSize;
	SceChar8 stream_buf[2048];

	if (strFileLseek(pStrFile, 0, 0) < 0)
		return -1;
	iReadSize = strFileRead(pStrFile, stream_buf, 2048);
	if (iReadSize < 2048) {
		printf("fatal error : strFileRead() 0x%x\n", iReadSize);
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
	return 0;
}

static SceInt32 pad_read(t_displayBuffer *pDisp)
{
	SceCtrlData buf;
	extern SceUInt32 padd;
	extern SceUInt32 opadd;

	opadd = padd;
	sceCtrlReadBufferPositive(&buf, 1);
	padd = buf.Buttons;
	if (padd & 0x4000) {
		playInfo.playMode = 10;
		return 1;
	}
	return 0;
}
