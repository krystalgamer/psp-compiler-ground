/* cflags: -O0 */
#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <ctrlsvc.h>
#include <iofilemgr.h>
#include <libmpeg.h>
#include "display.h"
#include "sound.h"

extern int _productMode;
extern int playInfo;

extern SceChar8 *dispbuf;
extern int audioFlag;

typedef struct {
	SceUInt32 low;
	SceUInt32 hi;
} SceKernelSysClock;

typedef struct {
	SceMpegStream *avcStream;
	SceMpegAu *avcAu;
	SceMpegStream *atracStream;
	SceMpegAu *atracAu;
} t_streams;

SceUID sceKernelCreateVTimer(const char *name, void *opt);
int sceKernelStartVTimer(SceUID uid);
int sceKernelGetVTimerTime(SceUID uid, SceKernelSysClock *clock);
int sceKernelDeleteVTimer(SceUID uid);
extern SceInt32 edata; /* MovieTest's static PlayMovie counter */
static SceInt32 playMovie(SceMpeg *mpeg, SceMpegRingbuffer *ringbuf, t_streams *streams, t_displayBuffer *pDisp, void *pRing, t_soundBuffer *pSound);
static SceInt32 readHeader(SceMpeg *mpeg, SceUID fd, SceInt32 *size, SceInt32 *offset);
SceInt32 sceMpegRingbufferDestruct(SceMpegRingbuffer *pRingbuffer);
SceInt32 sceMpegDelete(SceMpeg *pMpeg);
SceInt32 sceMpegQueryMemSize(SceInt32 iReserved);
SceInt32 sceMpegFlushAllStream(SceMpeg *pMpeg);
int sceKernelCreateFpl(const char *name, int part, int attr, unsigned int size, unsigned int blocks, void *opt);
int sceKernelTryAllocateFpl(int fpl, void **data);
int sceKernelDeleteFpl(int fpl);
int UtilityFileAssign(const char *path, int mode);
int UtilityFileUnassign(const char *path);
int sceCtrlSetSamplingMode(int mode);
int sceKernelGetThreadId(void);
int sceKernelChangeThreadPriority(int thid, int prio);
int sceKernelTerminateDeleteThread(int thid);
void LcdDrawReset(void);
typedef struct t_ringBuffer { SceInt32 data_len; SceUID ringbuf_sema; SceMpegRingbuffer *pRingbuf; SceInt32 *end_flag; } t_ringBuffer;
SceInt32 read_create(t_ringBuffer *pRing, SceMpegRingbuffer *pRB);
SceInt32 read_init(t_ringBuffer *pRing, int fileSize);
SceInt32 read_end(t_ringBuffer *pRing);
SceInt32 read_func(SceSize size, void *argp);
SceInt32 dispbuf_getCapacity(t_displayBuffer *pDisp);
SceInt32 dispbuf_setStartFlag(t_displayBuffer *pDisp);

static SceInt32 ringbufferCallBack(ScePVoid pBuf, SceInt32 iNum, ScePVoid CallbackData)
{
	SceInt32 iPackSize;
	SceInt32 iRet;
	SceUID fd;

	iPackSize = 2048;
	fd = *(SceUID *)CallbackData;
	iRet = sceIoRead(fd, pBuf, iPackSize * iNum);
	if (iRet % iPackSize != 0)
		return -1;
	iRet = iRet / iPackSize;
	return iRet;
}

int MovieTestEntry(SceSize args, void *argp)
{
	return 0;
}

#define printf(...) { char _buf[112]; sprintf(_buf, __VA_ARGS__); sceIoWrite(0, _buf, strlen(_buf)); }

int MovieTest(int mode)
{
	SceMpeg mpeg;
	SceMpegRingbuffer ringbuf;
	SceMpegStream *pStream[2];
	SceMpegAu avcAu;
	SceMpegAu atracAu;
	SceChar8 *filename = "disc0:/PSP_GAME/USRDIR/demo01.pmf";
	SceUID fd;
	SceInt32 bufferSize, workSize, fileSize;
	SceInt32 audioEsSize, audioOutSize;
	SceInt32 offset;
	SceInt32 result = -1;
	t_displayBuffer displayCtrl;
	t_ringBuffer readCtrl;
	t_soundBuffer soundCtrl;
	t_streams mpegStreamData;
	SceMpegHandle avcEsBuf = NULL;
	SceChar8 *pPSPStream = NULL;
	SceChar8 *pWorkBuf = NULL;
	SceChar8 *pAudioBuf = NULL;
	SceUID dispThread = 0;
	SceUID readThread = 0;
	SceUID soundThread = 0;
	SceUID lcdThread = 0;
	SceUID syncSema = 0;
	SceInt32 ret;
	SceUID fplid[3] = { 0, 0, 0 };

	if (mode)
		_productMode = 1;
	else
		_productMode = 0;
	audioFlag = 1;
	ret = sceMpegInit();
	if (ret != 0) {
		printf("fatal error : sceMpegInit() %x\n", ret);
		goto term7;
	}
	bufferSize = sceMpegRingbufferQueryMemSize(320);
	printf("ring buf size:%d\n", bufferSize);
	if (bufferSize < 0) {
		printf("fatal error : sceMpegRingbufferQueryMemSize %x\n", bufferSize);
		goto term6;
	}
	workSize = sceMpegQueryMemSize(0);
	if (workSize < 0) {
		printf("fatal error : sceMpegQueryMemSize %x\n", workSize);
		goto term6;
	}
	fplid[0] = sceKernelCreateFpl("MovieTest1Fpl", 2, 0x100, bufferSize, 1, NULL);
	if (fplid[0] < 0) {
		printf("sceKernelCreateFpl 1 = %08X", fplid[0]);
		fplid[0] = 0;
		goto term6;
	}
	ret = sceKernelTryAllocateFpl(fplid[0], (void **)&pPSPStream);
	if (ret < 0) {
		printf("sceKernelTryAllocateFpl 1 = %08X", ret);
		goto term6;
	}
	fplid[1] = sceKernelCreateFpl("MovieTest2Fpl", 2, 0x100, workSize, 1, NULL);
	if (fplid[1] < 0) {
		printf("sceKernelCreateFpl 2 = %08X", fplid[1]);
		fplid[1] = 0;
		goto term6;
	}
	ret = sceKernelTryAllocateFpl(fplid[1], (void **)&pWorkBuf);
	if (ret < 0) {
		printf("sceKernelTryAllocateFpl 2 = %08X", ret);
		goto term6;
	}
	ret = sceMpegRingbufferConstruct(&ringbuf, 320, pPSPStream, bufferSize, ringbufferCallBack, &fd);
	if (ret != 0) {
		printf("fatal error : sceMpegRingbufferConstruct() %x\n", ret);
		goto term6;
	}
	ret = sceMpegCreate(&mpeg, pWorkBuf, workSize, &ringbuf, 512, 0, 0);
	if (ret != 0) {
		printf("fatal error : sceMpegCreate() %x\n", ret);
		goto term5;
	}
	if (UtilityFileAssign(filename, 1) < 0) {
		printf("fatal error : UtilityFileAssign()\n");
		goto term4;
	}
	fd = sceIoOpen(filename, 1, 644);
	if (fd < 0) {
		printf("fatal error : sceIoOpen()\n");
		goto term3b;
	}
	if (readHeader(&mpeg, fd, &fileSize, &offset) != 0) {
		printf("fatal error : readHeader\n");
		goto term3;
	}
	pStream[0] = sceMpegRegistStream(&mpeg, 0, 0);
	if (pStream[0] == NULL) {
		printf("fatal error : sceMpegRegistStream() AVC\n");
		goto term3;
	}
	if (audioFlag) {
		pStream[1] = sceMpegRegistStream(&mpeg, 1, 0);
		if (pStream[1] == NULL) {
			printf("fatal error : sceMpegRegistStream() ATRAC\n");
			goto term2c;
		}
	}
	avcEsBuf = sceMpegMallocAvcEsBuf(&mpeg);
	if (avcEsBuf == NULL) {
		printf("fatal error : sceMpegMallocAvcEsBuf()\n");
		goto term2b;
	}
	ret = sceMpegInitAu(&mpeg, avcEsBuf, &avcAu);
	if (ret != 0) {
		printf("fatal error : sceMpegInitAu() AVC %x\n", ret);
		goto term2;
	}
	if (audioFlag) {
		ret = sceMpegQueryAtracEsSize(&mpeg, &audioEsSize, &audioOutSize);
		if (ret != 0) {
			printf("fatal error : sceQueryAtracEsSize() %x\n", ret);
			goto term2;
		}
		fplid[2] = sceKernelCreateFpl("MovieTest3Fpl", 2, 0x100, audioEsSize + 64, 1, NULL);
		if (fplid[2] < 0) {
			printf("sceKernelCreateFpl 3 = %08X", fplid[2]);
			fplid[2] = 0;
			goto term2;
		}
		ret = sceKernelTryAllocateFpl(fplid[2], (void **)&pAudioBuf);
		if (ret < 0) {
			printf("sceKernelTryAllocateFpl 1 = %08X", ret);
			goto term2;
		}
		pAudioBuf = (SceChar8 *)(((unsigned int)pAudioBuf + 63) & ~63);
		ret = sceMpegInitAu(&mpeg, pAudioBuf, &atracAu);
		if (ret != 0) {
			printf("fatal error : sceMpegInitAu() %x\n", ret);
			goto term2;
		}
	}
	mpegStreamData.avcStream = pStream[0];
	mpegStreamData.atracStream = pStream[1];
	mpegStreamData.avcAu = &avcAu;
	mpegStreamData.atracAu = &atracAu;
	syncSema = sceKernelCreateSema("sync_sema", 0, 0, 1, NULL);
	sceCtrlSetSamplingMode(0);
	if (dispbuf_create(&displayCtrl, 0x88000, 4, syncSema) < 0) {
		printf("fatal error : dispbuf_create()\n");
		goto term1d;
	}
	if (audioFlag) {
		if (soundbuf_create(&soundCtrl, audioOutSize, 10, syncSema) < 0) {
			printf("fatal error soundbuf_create()\n");
			goto term1c;
		}
	}
	if (read_create(&readCtrl, &ringbuf) < 0) {
		printf("fatal error read_create()\n");
		goto term1b;
	}
	sceKernelChangeThreadPriority(sceKernelGetThreadId(), 63);
	dispThread = sceKernelCreateThread("displayThread", display_func, 62, 2048, 0, NULL);
	readThread = sceKernelCreateThread("readThread", read_func, 64, 2048, 0, NULL);
	if (audioFlag)
		soundThread = sceKernelCreateThread("soundThread", soundbuf_func, 61, 2048, 0, NULL);
	playInfo = 0;
	for (;;) {
		printf("********** PlayMovie (%d) **********\n", edata++);
		if (sceIoLseek(fd, offset, 0) < 0) {
			printf("fatal error : sceIoLseek()\n");
			goto term1;
		}
		if (audioFlag)
			soundbuf_init(&soundCtrl);
		dispbuf_init(&displayCtrl);
		read_init(&readCtrl, fileSize);
		if (audioFlag)
			sceKernelStartThread(soundThread, sizeof(soundCtrl), &soundCtrl);
		sceKernelStartThread(dispThread, sizeof(displayCtrl), &displayCtrl);
		sceKernelStartThread(readThread, sizeof(readCtrl), &readCtrl);
		if ((ret = playMovie(&mpeg, &ringbuf, &mpegStreamData, &displayCtrl, &readCtrl, &soundCtrl)) != 0) {
			if (ret < 0) {
				printf("fatal error: playMovie()\n");
				goto term1;
			} else if (playInfo == 1) {
				if (sceMpegFlushAllStream(&mpeg) != 0) {
					printf("fatal error : sceMpegFlushAllStream()\n");
					goto term1;
				}
				playInfo = 0;
			} else if (playInfo == 10) {
				result = 0;
				printf("abort playMovie()\n");
				goto term1;
			}
		}
		if (audioFlag)
			sceKernelWaitThreadEnd(soundThread, NULL);
		sceKernelWaitThreadEnd(dispThread, NULL);
		sceKernelWaitThreadEnd(readThread, NULL);
	}
term1:
	sceKernelTerminateDeleteThread(lcdThread);
	if (audioFlag)
		sceKernelTerminateDeleteThread(soundThread);
	sceKernelTerminateDeleteThread(dispThread);
	sceKernelTerminateDeleteThread(readThread);
	read_end(&readCtrl);
term1b:
	if (audioFlag)
		soundbuf_end(&soundCtrl);
term1c:
	dispbuf_end(&displayCtrl);
term1d:
	sceKernelDeleteSema(syncSema);
term2:
	sceMpegFreeAvcEsBuf(&mpeg, avcEsBuf);
term2b:
	if (audioFlag)
		sceMpegUnRegistStream(&mpeg, pStream[1]);
term2c:
	sceMpegUnRegistStream(&mpeg, pStream[0]);
term3:
	sceIoClose(fd);
term3b:
	UtilityFileUnassign(filename);
term4:
	sceMpegDelete(&mpeg);
term5:
	sceMpegRingbufferDestruct(&ringbuf);
term6:
	sceMpegFinish();
term7:
	if (fplid[0])
		sceKernelDeleteFpl(fplid[0]);
	if (fplid[1])
		sceKernelDeleteFpl(fplid[1]);
	if (fplid[2])
		sceKernelDeleteFpl(fplid[2]);
	printf("program end\n");
	LcdDrawReset();
	return result;
}

static SceInt32 startCheck(t_displayBuffer *pDisp, t_soundBuffer *pSound, void *pRing)
{
	if (dispbuf_getCapacity(pDisp) == 0 && read_isFull(pRing)) {
		dispbuf_setStartFlag(pDisp);
		return 0;
	}
	return -1;
}

static SceInt32 playMovie(SceMpeg *mpeg, SceMpegRingbuffer *ringbuf, t_streams *streams, t_displayBuffer *pDisp, void *pRing, t_soundBuffer *pSound)
{
	SceInt32 unused0;
	SceInt32 retAvc;
	SceInt32 retAtrac;
	SceInt32 unused1;
	SceInt32 avcAttr;
	SceInt32 ret2;
	SceVoid *atracBody;
	SceInt32 iNum;
	SceChar8 *soundBuf;
	SceChar8 *dispBuf;
	SceInt32 initFlag;
	SceInt32 ret;
	SceInt32 end;
	SceUID vtimer;
	SceKernelSysClock clock;
	char msg[112];

	end = 0;
	clock.low = 0;
	clock.hi = 0;
	unused0 = 0;
	unused1 = 0;
	retAvc = -1;
	retAtrac = -1;
	initFlag = 1;
	vtimer = sceKernelCreateVTimer("movie timer", NULL);
	sceKernelStartVTimer(vtimer);
	while (!end) {
		end = pad_read();
		if (end && playInfo == 10 && _productMode == 1) {
			sceKernelGetVTimerTime(vtimer, &clock);
			sprintf(msg, "%08X %08X\n", clock.hi, clock.low);
			sceIoWrite(0, msg, strlen(msg));
			if (clock.low < 3000000) {
				end = 0;
				playInfo = 0;
			}
		}
		startCheck(pDisp, pSound, pRing);
		if (read_isEnd(pRing) == 1 && sceMpegRingbufferAvailableSize(ringbuf) == 320) {
			end = 0;
			break;
		}
		if (audioFlag == 1 && soundbuf_getCapacity(pSound) > 0) {
			retAtrac = sceMpegGetAtracAu(mpeg, streams->atracStream, streams->atracAu, &atracBody);
			if (retAtrac == 0) {
				soundbuf_getDrawbuf(pSound, &soundBuf);
				ret = sceMpegAtracDecode(mpeg, streams->atracAu, soundBuf, initFlag);
				if (ret != 0) {
					sprintf(msg, "fatal error : sceMpegAtracDecode() %x\n", ret);
					sceIoWrite(0, msg, strlen(msg));
					end = -1;
					goto out;
				}
				if (initFlag == 0)
					soundbuf_setBuf(pSound);
				initFlag = 0;
				retAtrac = -1;
			} else {
				if (!read_isFull(pRing))
					read_decode_sleep(pRing);
			}
		} else {
			if (!read_isFull(pRing))
				read_decode_sleep(pRing);
		}
		if (dispbuf_getCapacity(pDisp) > 0) {
			retAvc = sceMpegGetAvcAu(mpeg, streams->avcStream, streams->avcAu, &avcAttr);
			if (retAvc == 0) {
				dispbuf_getDrawbuf(pDisp, &dispBuf);
				dispbuf = dispBuf;
				ret = sceMpegAvcDecode(mpeg, streams->avcAu, 512, &dispbuf, &iNum);
				if (ret != 0) {
					sprintf(msg, "fatal error : sceMpegAvcDecode() %d\n", ret);
					sceIoWrite(0, msg, strlen(msg));
					end = -1;
					goto out;
				}
				if (iNum == 1) {
					dispbuf_dataSet(pDisp);
					retAvc = -1;
				}
			} else if (retAvc != 0x80618001) {
				sprintf(msg, "fatal error : sceMpegGetAvcAu () %x\n", retAvc);
				sceIoWrite(0, msg, strlen(msg));
				end = -1;
				goto out;
			} else {
				if (!read_isFull(pRing))
					read_decode_sleep(pRing);
			}
		} else {
			if (!read_isFull(pRing))
				read_decode_sleep(pRing);
		}
		if (!read_isFull(pRing))
			read_decode_sleep(pRing);
	}
	dispbuf_setStartFlag(pDisp);
	read_setDemuxEnd(pRing);
	if (audioFlag)
		soundbuf_setDemuxEnd(pSound);
	while (1) {
		ret2 = dispbuf_getDrawbuf(pDisp, &dispBuf);
		if (ret2 > 0) {
			dispbuf = dispBuf;
			ret = sceMpegAvcDecodeStop(mpeg, 512, &dispbuf, &iNum);
			if (ret != 0) {
				sprintf(msg, "fatal error : sceMpegGetAvcDecodeStop() %x\n", ret);
				sceIoWrite(0, msg, strlen(msg));
				end = -1;
				goto out;
			}
			if (iNum > 0)
				dispbuf_dataSet(pDisp);
			break;
		}
		dispbuf_decode_sleep(pDisp);
	}
	dispbuf_setDemuxEnd(pDisp);
out:
	sceKernelDeleteVTimer(vtimer);
	return end;
}

static SceInt32 readHeader(SceMpeg *mpeg, SceUID fd, SceInt32 *size, SceInt32 *offset)
{
	SceInt32 ret;
	SceInt32 result;
	SceUChar8 header[2048];
	char msg1[112];
	char msg2[112];
	char msg3[112];
	char msg4[112];

	if (sceIoLseek(fd, 0, SCE_SEEK_SET) < 0) {
		result = -1;
		goto end;
	}
	ret = sceIoRead(fd, header, 2048);
	if (ret < 2048) {
		sprintf(msg1, "fatal error : sceIoRead() %x\n", ret);
		sceIoWrite(0, msg1, strlen(msg1));
		result = -1;
		goto end;
	}
	if (sceMpegQueryStreamOffset(mpeg, header, offset) != 0) {
		sprintf(msg2, "fatal error : sceMpegQueryStreamOffset()\n");
		sceIoWrite(0, msg2, strlen(msg2));
		result = -1;
		goto end;
	}
	if (sceMpegQueryStreamSize(header, size) != 0) {
		sprintf(msg3, "fatal error : sceMpegQueryStreamSize()\n");
		sceIoWrite(0, msg3, strlen(msg3));
		result = -1;
		goto end;
	}
	if (sceIoLseek(fd, 0, SCE_SEEK_SET) < 0) {
		sprintf(msg4, "fatal error : sceIoLseek()\n");
		sceIoWrite(0, msg4, strlen(msg4));
		result = -1;
		goto end;
	}
	result = 0;
end:
	return result;
}

static int pad_read(void)
{
	SceCtrlLatch latch;

	if (sceCtrlReadLatch(&latch)) {
		if (latch.uiBreak & 0x2000) {
			if (_productMode == 1) {
				playInfo = 10;
				return 1;
			}
		} else if (latch.uiBreak & 0x4000) {
			if (_productMode == 0) {
				playInfo = 10;
				return 1;
			}
		} else if (latch.uiBreak & 0x8000) {
			playInfo = 1;
			return 1;
		}
	}
	return 0;
}

void MovieTestVersion(char *buf)
{
	sprintf(buf, "Ver. 041027_1");
}
