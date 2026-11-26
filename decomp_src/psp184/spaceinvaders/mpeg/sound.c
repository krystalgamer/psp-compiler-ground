#include "common.h"

/* declarations recovered from DWARF (UTST99332 mpeg_ezmpegstr sound) */
typedef struct t_soundBuffer t_soundBuffer;
struct t_soundBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
typedef int SceInt32;
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
typedef struct SceKernelEventFlagInfo SceKernelEventFlagInfo;
struct SceKernelEventFlagInfo;
typedef unsigned int SceSize;
typedef unsigned int SceUInt;
struct SceKernelEventFlagInfo { /* size 0x34 */
    SceSize size;
    char name[32];
    SceUInt attr;
    SceUInt initPattern;
    SceUInt currentPattern;
    int numWaitThreads;
};
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
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

extern SceInt32 soundframeCount;
extern SceInt32 soundframeDelay;
extern SceInt32 soundIntervalSize;
extern SceChar8 *output_buf[2];

SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 buf_size, SceInt32 buf_num);
SceInt32 soundbuf_reset(t_soundBuffer *pSound);
SceInt32 soundbuf_delete(t_soundBuffer *pSound);
SceInt32 soundbuf_getDrawbuf(t_soundBuffer *pSound, SceChar8 **buffer);
SceInt32 soundbuf_setPts(t_soundBuffer *pSound, SceUInt32 pts);
SceInt32 soundbuf_getPts(t_soundBuffer *pSound, SceUInt32 *pPts);
SceInt32 soundbuf_setBuf(t_soundBuffer *pSound);
SceInt32 soundbuf_getCapacity(t_soundBuffer *pSound);
SceInt32 soundbuf_getCurrentCount(t_soundBuffer *pSound);
SceInt32 soundbuf_setDemuxEnd(t_soundBuffer *pSound);
static SceInt32 soundbuf_getStatus(t_soundBuffer *pSound, SceUInt32 *pPattern);
static SceInt32 soundbuf_checkDemuxEnd(t_soundBuffer *pSound);
SceInt32 soundbuf_setStartFlag(t_soundBuffer *pSound);
SceInt32 soundbuf_func(SceSize size, void *argp);
static SceInt32 soundbuf_swapbuf(t_soundBuffer *pSound, SceChar8 *buf);
SceInt32 soundbuf_output(t_soundBuffer *pSound);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_create);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_reset);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_delete);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_getDrawbuf);

int soundbuf_setPts(t_soundBuffer *pSound, unsigned int pts) {
    unsigned int var_a1;

    var_a1 = pts;
    if (var_a1 == -1U) {
        var_a1 = pSound->soundLatestTimestamp + soundIntervalSize;
    }
    pSound->soundLatestTimestamp = var_a1;
    pSound->pts[pSound->write] = var_a1;
    return 0;
}

int soundbuf_getPts(t_soundBuffer *pSound, unsigned int *pPts) {
    *pPts = pSound->pts[pSound->read];
    return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_setBuf);

int soundbuf_getCapacity(t_soundBuffer *pSound) {
    return pSound->size - pSound->count;
}

int soundbuf_getCurrentCount(t_soundBuffer *pSound) {
    return pSound->count;
}

int soundbuf_setDemuxEnd(t_soundBuffer *pSound) {
    sceKernelSetEventFlag(pSound->status_flag, 3);
    return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_getStatus);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_checkDemuxEnd);

int soundbuf_setStartFlag(t_soundBuffer *pSound) {
    return sceKernelSetEventFlag(pSound->status_flag, 1);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_func);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/sound", soundbuf_swapbuf);

SceInt32 soundbuf_output(t_soundBuffer *pSound)
{
	SceChar8 *buf = pSound->buf[pSound->read];

	soundbuf_swapbuf(pSound, buf);
	return 0;
}
