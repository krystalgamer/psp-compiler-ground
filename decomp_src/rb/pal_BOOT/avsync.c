#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdlib.h>
#include "display.h"
#include "sound.h"
#include "avsync.h"

extern SceUInt32 videoLatestPts;
extern SceInt32 audioFlag;

static SceInt32 avsync_init_video(t_avSyncControl *pAvSync);

SceInt32 avsync_create(t_avSyncControl *pAvSync, t_displayBuffer *pDisp, t_soundBuffer *pSound, SceInt32 videoNum)
{
	pAvSync->pDisp = pDisp;
	pAvSync->pSound = pSound;
	pAvSync->video.pts = NULL;
	pAvSync->video.pts = malloc(videoNum * sizeof(SceUInt32));
	if (pAvSync->video.pts == NULL)
		return -1;
	pAvSync->video.size = videoNum;
	return 0;
}

SceInt32 avsync_init(t_avSyncControl *pAvSync)
{
	videoLatestPts = 0;
	avsync_init_video(pAvSync);
	return 0;
}

SceInt32 avsync_end(t_avSyncControl *pAvSync)
{
	if (pAvSync->video.pts) {
		free(pAvSync->video.pts);
		pAvSync->video.pts = NULL;
	}
	return 0;
}

SceInt32 avsync_playStart(t_avSyncControl *pAvSync)
{
	dispbuf_setStartFlag(pAvSync->pDisp);
	if (audioFlag)
		soundbuf_setStartFlag(pAvSync->pSound);
	return 0;
}

static SceInt32 avsync_init_video(t_avSyncControl *pAvSync)
{
	pAvSync->video.write = 0;
	pAvSync->video.read = 0;
	pAvSync->video.count = 0;
	return 0;
}

SceInt32 avsync_video_setPts(t_avSyncControl *pAvSync, SceUInt32 pts)
{
	SceInt32 ret = 0;

	if (pts == (SceUInt32)-1)
		pts = videoLatestPts + 3004;
	videoLatestPts = pts;
	pAvSync->video.pts[pAvSync->video.write] = pts;
	pAvSync->video.count++;
	pAvSync->video.write = (pAvSync->video.write + 1) % pAvSync->video.size;
	return ret;
}

SceInt32 avsync_video_getPts(t_avSyncControl *pAvSync, SceUInt32 *pPts)
{
	SceInt32 ret = 0;

	*pPts = pAvSync->video.pts[pAvSync->video.read];
	pAvSync->video.count--;
	pAvSync->video.read = (pAvSync->video.read + 1) % pAvSync->video.size;
	return ret;
}

SceInt32 dispbuf_getCurrentCount(t_displayBuffer *pDisp);
SceInt32 dispbuf_getPts(t_displayBuffer *pDisp, SceUInt32 *pPts);
SceInt32 soundbuf_getCurrentCount(t_soundBuffer *pSound);
SceInt32 soundbuf_getPts(t_soundBuffer *pSound, SceUInt32 *pPts);
SceInt32 avsync_Compare(t_avSyncControl *pAvSync)
{
	SceInt32 ret;
	SceInt32 ptsDiff;
	SceUInt32 soundPts, videoPts;

	if (audioFlag == 0)
		return 1;

	if (soundbuf_getCurrentCount(pAvSync->pSound) == 0 || dispbuf_getCurrentCount(pAvSync->pDisp) == 0) {
		ret = 1;
		goto term;
	}

	soundbuf_getPts(pAvSync->pSound, &soundPts);
	dispbuf_getPts(pAvSync->pDisp, &videoPts);

	ptsDiff = soundPts - videoPts;

	if (ptsDiff >= -(3004 * 2) && ptsDiff <= 3004 * 2) {
		ret = 1;
	} else {
		if (ptsDiff > 3004 * 2)
			ret = 2;
		else
			ret = 3;
	}
term:
	return ret;
}
