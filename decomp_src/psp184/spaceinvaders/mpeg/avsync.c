/* cflags: -O2 */
#include "common.h"

/* declarations recovered from DWARF (UTST99332 mpeg_ezmpegstr avsync) */
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
typedef int SceInt32;
struct t_displayBuffer { /* size 0x28 */
    SceUID start_sema;
    SceUID lock_sema;
    SceUID display_wait_sema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 displayMode;
};
typedef struct t_soundBuffer t_soundBuffer;
struct t_soundBuffer;
struct t_soundBuffer { /* size 0x28 */
    SceUID lock_sema;
    SceUID status_flag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 buf_size;
    SceUInt32 soundLatestTimestamp;
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
SceInt32 avsync_reset(t_avSyncControl *pAvSync);
SceInt32 avsync_delete(t_avSyncControl *pAvSync);
static SceInt32 avsync_init_video(t_avSyncControl *pAvSync);
SceInt32 avsync_video_setPts(t_avSyncControl *pAvSync, SceUInt32 pts);
SceInt32 avsync_video_getPts(t_avSyncControl *pAvSync, SceUInt32 *pPts);
SceInt32 avsync_Compare(t_avSyncControl *pAvSync);

void *malloc(unsigned int size);
extern __typeof__(malloc) psp_malloc;
#define malloc psp_malloc
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
#undef malloc

int avsync_reset(t_avSyncControl *pAvSync) {
    pAvSync->video.videoLatestPts = 0;
    avsync_init_video(pAvSync);
    return 0;
}

void free(void *p);
extern __typeof__(free) psp_free;
#define free psp_free
void free(void *p);
SceInt32 avsync_delete(t_avSyncControl *pAvSync)
{
	if (pAvSync->video.pts) {
		free(pAvSync->video.pts);
		pAvSync->video.pts = NULL;
	}
	return 0;
}
#undef free

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

int dispbuf_getCurrentCount(t_displayBuffer *pDisp);
int dispbuf_getPts(t_displayBuffer *pDisp, unsigned int *pPts);
int soundbuf_getCurrentCount(t_soundBuffer *pSound);
int soundbuf_getPts(t_soundBuffer *pSound, unsigned int *pPts);
SceInt32 avsync_Compare(t_avSyncControl *pAvSync)
{
	SceInt32 ret;
	SceInt32 ptsDiff;
	SceUInt32 soundPts, videoPts;

	if (pAvSync->pSound == NULL) {
		ret = 1;
		goto term;
	}

	if (soundbuf_getCurrentCount(pAvSync->pSound) == 0 || dispbuf_getCurrentCount(pAvSync->pDisp) == 0) {
		ret = 1;
		goto term;
	}

	soundbuf_getPts(pAvSync->pSound, &soundPts);
	dispbuf_getPts(pAvSync->pDisp, &videoPts);

	ptsDiff = soundPts - videoPts;

	if (ptsDiff >= -(videoIntervalSize * 2) && ptsDiff <= videoIntervalSize * 2) {
		ret = 1;
	} else {
		if (ptsDiff > videoIntervalSize * 2)
			ret = 2;
		else
			ret = 3;
	}
term:
	return ret;
}
