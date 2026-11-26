#include "common.h"

/* declarations recovered from DWARF (UTST99332 mpeg_ezmpegstr display) */
typedef char SceChar8;
typedef int SceInt32;
typedef struct t_displayBuffer t_displayBuffer;
struct t_displayBuffer;
typedef int SceUID;
typedef unsigned int SceUInt32;
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
typedef void SceVoid;
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
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

extern SceInt32 frameCount;
extern SceInt32 frameLoss;
extern SceChar8 *displayBuf[2];

static SceInt32 swap_buffer(SceChar8 *buffer);
SceInt32 dispbuf_create(t_displayBuffer *pDisp, SceInt32 disp_size, SceInt32 disp_num);
SceInt32 dispbuf_reset(t_displayBuffer *pDisp);
SceInt32 dispbuf_delete(t_displayBuffer *pDisp);
SceInt32 dispbuf_getDrawbuf(t_displayBuffer *pDisp, SceChar8 **buffer);
SceInt32 dispbuf_setPts(t_displayBuffer *pDisp, SceUInt32 pts);
SceInt32 dispbuf_getPts(t_displayBuffer *pDisp, SceUInt32 *pPts);
SceInt32 dispbuf_dataSet(t_displayBuffer *pDisp);
SceInt32 dispbuf_getCapacity(t_displayBuffer *pDisp);
SceInt32 dispbuf_getCurrentCount(t_displayBuffer *pDisp);
SceInt32 dispbuf_setMode(t_displayBuffer *pDisp, SceInt32 mode);
SceInt32 dispbuf_getMode(t_displayBuffer *pDisp);
SceInt32 dispbuf_display(SceVoid *pAv);
static SceInt32 dispbuf_show(t_displayBuffer *pDisp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", swap_buffer);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_create);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_reset);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_delete);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_getDrawbuf);

int dispbuf_setPts(t_displayBuffer *pDisp, unsigned int pts) {
    pDisp->pts[pDisp->write] = pts;
    return 0;
}

int dispbuf_getPts(t_displayBuffer *pDisp, unsigned int *pPts) {
    *pPts = pDisp->pts[pDisp->read];
    return 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_dataSet);

int dispbuf_getCapacity(t_displayBuffer *pDisp) {
    return pDisp->size - pDisp->count;
}

int dispbuf_getCurrentCount(t_displayBuffer *pDisp) {
    return pDisp->count;
}

int dispbuf_setMode(t_displayBuffer *pDisp, int mode) {
    pDisp->displayMode = mode;
    return 0;
}

int dispbuf_getMode(t_displayBuffer *pDisp) {
    return pDisp->displayMode;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_display);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", dispbuf_show);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/display", D_0007AF20);
