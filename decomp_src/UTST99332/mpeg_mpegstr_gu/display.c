#include "common.h"

/* declarations recovered from DWARF */
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
struct _anon1;
struct _anon1 { /* size 0x10 */
    SceUInt32 uiStartWidth;
    SceUInt32 uiStartHeight;
    SceUInt32 uiLenWidth;
    SceUInt32 uiLenHeight;
};
typedef struct _anon1 SceMpegAvcYCbCrRange;
typedef float SceFloat32;
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
typedef struct SceKernelEventFlagInfo SceKernelEventFlagInfo;
struct t_avSyncControl;
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
typedef short int SceShort16;

extern SceInt32 frameCount;
extern SceInt32 frameLoss;
extern SceChar8 disp_list[65536];
extern SceFloat32 displayScale[3];
extern SceShort16 board[2][3];

static SceInt32 init_all(t_displayBuffer *pDisp);
static SceInt32 draw_frame(t_displayBuffer *pDisp, SceChar8 *pYCbCrBuf);
SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceMpeg *pMpeg, SceInt32 disp_num, SceInt32 pixelFormat, t_conditionCtrl *pCtrl);
SceInt32 dispbuf_reset(t_displayBuffer *pDisp);
SceInt32 dispbuf_delete(t_displayBuffer *pDisp);
SceInt32 dispbuf_dataSet(t_displayBuffer *pDisp);
static SceInt32 dispbuf_checkDecodeEnd(t_displayBuffer *pDisp);
SceInt32 dispbuf_checkDelayMode(t_displayBuffer *pDisp);
SceInt32 dispbuf_func(SceSize size, SceVoid *argp);
SceInt32 dispbuf_show(t_displayBuffer *pDisp);


INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", dispbuf_create);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", dispbuf_reset);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", dispbuf_delete);

int dispbuf_getDrawbuf(t_displayBuffer *pDisp, signed char **buffer) {
    int temp_v0;

    temp_v0 = dispbuf_getCapacity(pDisp);
    if (temp_v0 > 0) {
        *buffer = pDisp->buf[pDisp->write];
    } else {
        *buffer = NULL;
    }
    return temp_v0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", dispbuf_dataSet);

int dispbuf_getCapacity(t_displayBuffer *pDisp) {
    return pDisp->size - pDisp->count;
}

int dispbuf_getCurrentCount(t_displayBuffer *pDisp) {
    return pDisp->count;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", dispbuf_checkDecodeEnd);

int dispbuf_setPts(t_displayBuffer *pDisp, unsigned int pts) {
    pDisp->pts[pDisp->write] = pts;
    return 0;
}

int dispbuf_getPts(t_displayBuffer *pDisp, unsigned int *pPts) {
    *pPts = pDisp->pts[pDisp->read];
    return 0;
}

int dispbuf_setMode(t_displayBuffer *pDisp, int mode) {
    pDisp->displayMode = mode;
    return 0;
}

int dispbuf_getMode(t_displayBuffer *pDisp) {
    return pDisp->displayMode;
}

int dispbuf_setDelayMode(t_displayBuffer *pDisp) {
    return sceKernelSetEventFlag(pDisp->delayFlag, 1);
}

int dispbuf_setPlayMode(t_displayBuffer *pDisp) {
    return sceKernelClearEventFlag(pDisp->delayFlag, 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", dispbuf_checkDelayMode);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", dispbuf_func);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", dispbuf_show);

int dispbuf_zoomin(t_displayBuffer *pDisp) {
    int temp_v1;

    temp_v1 = pDisp->scale;
    if (temp_v1 >= 2) {
        return 0;
    }
    pDisp->scale = temp_v1 + 1;
    return 0;
}

int dispbuf_zoomout(t_displayBuffer *pDisp) {
    int temp_v1;

    temp_v1 = pDisp->scale;
    if (temp_v1 > 0) {
        pDisp->scale = temp_v1 - 1;
    }
    return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", D_00014788);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", D_0001478C);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", D_00014790);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", D_00014794);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_mpegstr_gu/nonmatchings/display", D_00014798);
