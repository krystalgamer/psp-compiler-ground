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

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/avsync", avsync_Compare);
