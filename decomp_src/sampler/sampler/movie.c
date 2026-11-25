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

extern MOVIE_LIST movie_list;
extern MENU_LIST menu_list;
extern SceChar8 *dispbuf[1];
extern t_playInfo playInfo;
#define strFile strFile_2C55EC
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

static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_ringBuffer *pRingCtrl, t_avSyncControl *pAvSync);

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
		if (pres & 0x4000) {
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
			} else if (menu_list.current >= 12) {
				menu_list.current -= 3;
			} else {
				playInfo.playMode = 10;
				ret = 1;
			}
		} else if (pres & 0x20) {
			menu_list.current++;
			if (menu_list.current >= 12) {
				menu_list.current = 11;
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
		if (pres & 0x2000) {
			playInfo.playMode = 10;
			menu_list.selected = 0;
			ret = 1;
			BgmStart();
		}
	}
	opadd = padd;
	return ret;
}


INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", thumb_load);


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

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/movie", D_00016284);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/movie", D_000162A0);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/movie", D_000162C0);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/movie", D_000162EC);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/movie", D_00016314);

INCLUDE_RODATA("tmp/asm/sampler/sampler/nonmatchings/movie", D_00016334);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", playMovie);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", readHeader);


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

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", init_pinfo);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", MovieInit);


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

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", MovieTerm);

int MovieStat(void)
{
	return 1;
}

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", MovieStart);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", MovieEnd);
