#include "common.h"

/* declarations recovered from DWARF */
struct t_avSyncControl;
struct t_displayBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
typedef int SceInt32;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x4 */
    SceUID control_flag;
};
typedef struct t_conditionCtrl t_conditionCtrl;
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
typedef struct t_displayBuffer t_displayBuffer;
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
typedef struct t_soundBuffer t_soundBuffer;
struct t_avSync_Video;
struct t_avSync_Video { /* size 0x18 */
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceUInt32 videoLatestPts;
};
typedef struct t_avSync_Video t_avSync_Video;
struct t_avSyncControl { /* size 0x20 */
    t_displayBuffer *pDisp;
    t_soundBuffer *pSound;
    t_avSync_Video video;
};
typedef struct t_avSyncControl t_avSyncControl;

extern SceInt32 videoIntervalSize;

SceInt32 avsync_create(t_avSyncControl *pAvSync, t_displayBuffer *pDisp, t_soundBuffer *pSound, SceInt32 videoNum);
SceInt32 avsync_delete(t_avSyncControl *pAvSync);
static SceInt32 avsync_init_video(t_avSyncControl *pAvSync);
SceInt32 avsync_video_setPts(t_avSyncControl *pAvSync, SceUInt32 pts);
SceInt32 avsync_video_getPts(t_avSyncControl *pAvSync, SceUInt32 *pPts);
SceInt32 avsync_Compare(t_avSyncControl *pAvSync);


INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/avsync", avsync_create);

int avsync_reset(t_avSyncControl *pAvSync) {
    pAvSync->video.videoLatestPts = 0;
    avsync_init_video(pAvSync);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/avsync", avsync_delete);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/avsync", avsync_init_video);

int avsync_setStartPts(t_avSyncControl *pAvSync, unsigned int pts) {
    pAvSync->video.videoLatestPts = pts;
    pAvSync->pSound->soundLatestPts = pts;
    return 0;
}

int avsync_setVideoStartPts(t_avSyncControl *pAvSync, unsigned int pts) {
    unsigned int var_a1;

    var_a1 = pts;
    if (var_a1 == -1U) {
        var_a1 = pAvSync->video.videoLatestPts + videoIntervalSize;
    }
    pAvSync->video.videoLatestPts = var_a1;
    return 0;
}

int avsync_video_getLatestPts(t_avSyncControl *pAvSync, unsigned int *pPts) {
    *pPts = pAvSync->video.videoLatestPts;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/avsync", avsync_video_setPts);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/avsync", avsync_video_getPts);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/avsync", avsync_Compare);

int avsync_video_createNextPts(t_avSyncControl *pAvSync, unsigned int pts, unsigned int *pNextPts) {
    unsigned int var_a1;

    var_a1 = pts;
    if (var_a1 == -1U) {
        var_a1 = pAvSync->video.videoLatestPts + videoIntervalSize;
    }
    *pNextPts = var_a1;
    return 0;
}

int avsync_sound_createNextPts(t_avSyncControl *pAvSync, unsigned int pts, unsigned int *pNextPts) {
    return soundbuf_createNextPts(pAvSync->pSound);
}

int avsync_video_getAuTimestamp(t_avSyncControl *pAvSync) {
    return videoIntervalSize;
}

int avsync_sound_getAuTimestamp(t_avSyncControl *pAvSync) {
    return soundbuf_getAuTimestamp(pAvSync->pSound);
}
