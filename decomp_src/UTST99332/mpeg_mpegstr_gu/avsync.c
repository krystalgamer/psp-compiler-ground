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
struct SceMpeg;
typedef void SceVoid;
struct SceMpeg { /* size 0x4 */
    SceVoid *sys;
};
typedef struct SceMpeg SceMpeg;
struct t_displayBuffer { /* size 0x38 */
    SceUID lock_sema;
    SceUID delayFlag;
    SceChar8 **buf;
    SceChar8 *workBuf;
    SceUInt32 *pts;
    SceInt32 write;
    SceInt32 read;
    SceInt32 count;
    SceInt32 size;
    SceInt32 pixelFormat;
    SceInt32 displayMode;
    SceInt32 scale;
    t_conditionCtrl *pCtrl;
    SceMpeg *pMpeg;
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


INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/avsync", avsync_create);

int avsync_reset(t_avSyncControl *pAvSync) {
    pAvSync->video.videoLatestPts = 0;
    avsync_init_video(pAvSync);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/avsync", avsync_delete);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/avsync", avsync_init_video);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/avsync", avsync_video_setPts);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/avsync", avsync_video_getPts);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/avsync", avsync_Compare);
