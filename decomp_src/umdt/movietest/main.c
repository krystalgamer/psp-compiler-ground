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

INCLUDE_ASM("tmp/asm/umdt/movietest/nonmatchings/main", playMovie);

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
