#include "common.h"

/* declarations recovered from DWARF */
struct t_soundBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
typedef int SceInt32;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x4 */
    SceUID control_flag;
};
typedef struct t_conditionCtrl t_conditionCtrl;
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
typedef unsigned int SceSize;
typedef void SceVoid;
struct t_avSyncControl;
struct t_displayBuffer;
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

extern SceInt32 soundframeCount;
extern SceInt32 soundframeDelay;
extern SceInt32 soundIntervalSize;
extern SceChar8 *outputBuf[2];

SceInt32 soundbuf_create(t_soundBuffer *pSound, SceInt32 bufSize, SceInt32 buf_num, t_conditionCtrl *pCtrl);
SceInt32 soundbuf_reset(t_soundBuffer *pSound);
SceInt32 soundbuf_delete(t_soundBuffer *pSound);
SceInt32 soundbuf_setBuf(t_soundBuffer *pSound);
static SceInt32 soundbuf_checkDecodeEnd(t_soundBuffer *pSound);
SceInt32 soundbuf_func(SceSize size, SceVoid *argp);
static SceInt32 soundbuf_swapbuf(t_soundBuffer *pSound, SceChar8 *buf);
SceInt32 soundbuf_output(t_soundBuffer *pSound);


INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/sound", soundbuf_create);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/sound", soundbuf_reset);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/sound", soundbuf_delete);

int soundbuf_getDrawbuf(t_soundBuffer *pSound, signed char **buffer) {
    int temp_v0;

    temp_v0 = soundbuf_getCapacity(pSound);
    if (temp_v0 > 0) {
        *buffer = pSound->buf[pSound->write];
    } else {
        *buffer = NULL;
    }
    return temp_v0;
}

int soundbuf_setStartPts(t_soundBuffer *pSound, unsigned int pts) {
    pSound->soundLatestPts = pts;
    return 0;
}

int soundbuf_setPts(t_soundBuffer *pSound, unsigned int pts) {
    unsigned int var_a1;

    var_a1 = pts;
    if (var_a1 == -1U) {
        var_a1 = pSound->soundLatestPts + soundIntervalSize;
    }
    pSound->soundLatestPts = var_a1;
    pSound->pts[pSound->write] = var_a1;
    return 0;
}

int soundbuf_getPts(t_soundBuffer *pSound, unsigned int *pPts) {
    *pPts = pSound->pts[pSound->read];
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/sound", soundbuf_setBuf);

int soundbuf_getCapacity(t_soundBuffer *pSound) {
    return pSound->size - pSound->count;
}

int soundbuf_getCurrentCount(t_soundBuffer *pSound) {
    return pSound->count;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/sound", soundbuf_checkDecodeEnd);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/sound", soundbuf_func);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/sound", soundbuf_swapbuf);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_stream_change/nonmatchings/sound", soundbuf_output);

int soundbuf_createNextPts(t_soundBuffer *pSound, unsigned int pts, unsigned int *pNextPts) {
    unsigned int var_a1;

    var_a1 = pts;
    if (var_a1 == -1U) {
        var_a1 = pSound->soundLatestPts + soundIntervalSize;
    }
    *pNextPts = var_a1;
    return 0;
}

int soundbuf_getAuTimestamp(t_soundBuffer *pSound) {
    return soundIntervalSize;
}
