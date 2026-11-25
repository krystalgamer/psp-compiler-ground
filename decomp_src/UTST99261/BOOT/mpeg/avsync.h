#ifndef AVSYNC_H
#define AVSYNC_H
/* types recovered from DWARF */
typedef struct t_avSync_Video {
	SceUInt32 *pts;
	SceInt32 write;
	SceInt32 read;
	SceInt32 count;
	SceInt32 size;
} t_avSync_Video;
typedef struct t_avSyncControl {
	t_displayBuffer *pDisp;
	t_soundBuffer *pSound;
	t_avSync_Video video;
} t_avSyncControl;

SceInt32 avsync_create(t_avSyncControl *pAvSync, t_displayBuffer *pDisp, t_soundBuffer *pSound, SceInt32 videoNum);
SceInt32 avsync_init(t_avSyncControl *pAvSync);
SceInt32 avsync_end(t_avSyncControl *pAvSync);
SceInt32 avsync_playStart(t_avSyncControl *pAvSync);
SceInt32 avsync_video_setPts(t_avSyncControl *pAvSync, SceUInt32 pts);
SceInt32 avsync_video_getPts(t_avSyncControl *pAvSync, SceUInt32 *pPts);
SceInt32 avsync_Compare(t_avSyncControl *pAvSync);
#endif
