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
extern char D_00006CC4[]; /* "fatal error : sceIoLseek()\n", shared with MovieTest */

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

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/main", MovieTest);

static SceInt32 startCheck(t_displayBuffer *pDisp, t_soundBuffer *pSound, void *pRing)
{
	if (dispbuf_getCapacity(pDisp) == 0 && read_isFull(pRing)) {
		dispbuf_setStartFlag(pDisp);
		return 0;
	}
	return -1;
}

INCLUDE_RODATA("tmp/asm/umdt/movietest/nonmatchings/main", D_00006CC4);

INCLUDE_RODATA("tmp/asm/umdt/movietest/nonmatchings/main", D_00006CE0);

INCLUDE_RODATA("tmp/asm/umdt/movietest/nonmatchings/main", D_00006CFC);

INCLUDE_RODATA("tmp/asm/umdt/movietest/nonmatchings/main", D_00006D24);

INCLUDE_RODATA("tmp/asm/umdt/movietest/nonmatchings/main", D_00006D38);

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
		sprintf(msg4, D_00006CC4);
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
