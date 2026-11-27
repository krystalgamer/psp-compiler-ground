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
struct t_displayBuffer { /* size 0x38 */
    SceUID start_sema;
    SceUID lock_sema;
    SceUID display_wait_sema;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 *write;
    SceInt32 *read;
    SceInt32 *count;
    SceInt32 *size;
    SceInt32 pixelFormat;
    SceInt32 *displayMode;
    SceInt32 *scale;
    SceInt32 *posx;
    SceInt32 *posy;
};
typedef struct t_soundBuffer t_soundBuffer;
struct t_soundBuffer;
struct t_soundBuffer { /* size 0x24 */
    SceUID lock_sema;
    SceInt32 *terminate_flag;
    SceChar8 **buf;
    SceUInt32 *pts;
    SceInt32 *write;
    SceInt32 *read;
    SceInt32 *count;
    SceInt32 *size;
    SceUID start_sema;
};
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x14 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
};
struct t_avSyncControl { /* size 0x1c */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};

extern SceUInt32 videoLatestPts;
extern SceInt32 audioFlag;

SceInt32 avsync_create(t_avSyncControl *pAvSync, t_displayBuffer *pDisp, t_soundBuffer *pSound, SceInt32 videoNum);
SceInt32 avsync_init(t_avSyncControl *pAvSync);
SceInt32 avsync_end(t_avSyncControl *pAvSync);
SceInt32 avsync_playStart(t_avSyncControl *pAvSync);
static SceInt32 avsync_init_video(t_avSyncControl *pAvSync);
SceInt32 avsync_video_setPts(t_avSyncControl *pAvSync, SceUInt32 pts);
SceInt32 avsync_video_getPts(t_avSyncControl *pAvSync, SceUInt32 *pPts);
SceInt32 avsync_Compare(t_avSyncControl *pAvSync);


INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/avsync", avsync_create);

SceInt32 avsync_init(t_avSyncControl *pAvSync)
{
	videoLatestPts = 0;
	avsync_init_video(pAvSync);
	return 0;
}

void free(void *p);
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

INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/avsync", avsync_Compare);
