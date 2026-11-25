#include "common.h"

/* declarations recovered from DWARF */
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
typedef int SceInt32;
typedef struct t_conditionCtrl t_conditionCtrl;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x8 */
    SceUID controlFlag;
    SceUID waitFlag;
};
struct t_displayBuffer { /* size 0x28 */
    SceUID lockSema;
    SceUID delayFlag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 displayMode;
    t_conditionCtrl *pCtrl;
};
typedef struct t_soundBuffer t_soundBuffer;
struct t_soundBuffer;
struct t_soundBuffer { /* size 0x28 */
    SceUID lockSema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 bufSize;
    t_conditionCtrl *pCtrl;
    SceUInt32 soundLatestPts;
};
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x18 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceUInt32 videoLatestPts;
};
struct t_avSyncControl { /* size 0x20 */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};

extern SceInt32 videoIntervalSize;

SceInt32 avsync_create(t_avSyncControl *pAvSync, t_displayBuffer *pDisp, t_soundBuffer *pSound, SceInt32 videoNum);
SceInt32 avsync_delete(t_avSyncControl *pAvSync);
static SceInt32 avsync_init_video(t_avSyncControl *pAvSync);
SceInt32 avsync_video_setPts(t_avSyncControl *pAvSync, SceUInt32 pts);
SceInt32 avsync_video_getPts(t_avSyncControl *pAvSync, SceUInt32 *pPts);
SceInt32 avsync_Compare(t_avSyncControl *pAvSync);


void *malloc(unsigned int size);
void *malloc(unsigned int size);
void *malloc(unsigned int size);
#include <stdlib.h>
float sceDisplayGetFramePerSec(void);
SceInt32 avsync_create(t_avSyncControl *pAvSync, t_displayBuffer *pDisp, t_soundBuffer *pSound, SceInt32 videoNum)
{
	pAvSync->pDisp = pDisp;
	pAvSync->pSound = pSound;
	pAvSync->video.pts = NULL;
	pAvSync->video.pts = malloc(videoNum * sizeof(SceUInt32));
	if (pAvSync->video.pts == NULL)
		return -1;
	pAvSync->video.size = videoNum;
	videoIntervalSize = (SceInt32)(2.0f * (90000.0f / sceDisplayGetFramePerSec()));
	return 0;
}

int avsync_reset(t_avSyncControl *pAvSync) {
    pAvSync->video.videoLatestPts = 0;
    avsync_init_video(pAvSync);
    return 0;
}

void free(void *p);
void free(void *p);
void free(void *p);
SceInt32 avsync_delete(t_avSyncControl *pAvSync)
{
	if (pAvSync->video.pts) {
		free(pAvSync->video.pts);
		pAvSync->video.pts = NULL;
	}
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
		pts = pAvSync->video.videoLatestPts + videoIntervalSize;
	pAvSync->video.videoLatestPts = pts;
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

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/avsync", avsync_Compare);
