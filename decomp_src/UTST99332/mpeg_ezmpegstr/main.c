#include "common.h"

/* declarations recovered from DWARF */
typedef int SceInt32;
typedef void SceVoid;
struct t_soundBuffer;
typedef int SceUID;
typedef char SceChar8;
typedef unsigned int SceUInt32;
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
typedef struct t_soundBuffer t_soundBuffer;
struct SceKernelLMOption;
typedef unsigned int SceSize;
struct SceKernelLMOption { /* size 0x14 */
    SceSize size;
    SceUID mpidtext;
    SceUID mpiddata;
    unsigned int flags;
    char position;
    char access;
    char creserved[2];
};
typedef struct SceKernelLMOption SceKernelLMOption;
struct _anon1;
struct _anon1 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon1 StrFile;
struct SceMpeg;
struct SceMpeg { /* size 0x4 */
    SceVoid *sys;
};
typedef struct SceMpeg SceMpeg;
struct SceMpegRingbuffer;
typedef SceInt32 (*SceMpegRBCallback)(SceVoid *, SceInt32, SceVoid *);
struct SceMpegRingbuffer { /* size 0x2c */
    SceInt32 m_iBufsize;
    SceInt32 m_iRpos;
    SceInt32 m_iWpos;
    SceInt32 m_iInlen;
    SceInt32 m_iTypeSize;
    SceVoid *m_pBuf;
    SceMpegRBCallback callback;
    SceVoid *m_CallbackData;
    SceVoid *pPack;
    SceInt32 iSemaRB;
    SceVoid *mp;
};
typedef struct SceMpegRingbuffer SceMpegRingbuffer;
struct SceMpegStream;
typedef SceUInt32 SceMpegStreamId;
typedef unsigned char SceUChar8;
typedef short int SceShort16;
struct SceMpegStream { /* size 0x40 */
    SceMpegStreamId qStreamId;
    SceMpegStreamId qStreamIdMask;
    SceVoid *m_pRAPICtrlStream;
    SceUChar8 *m_pRAPI;
    SceInt32 m_iAuNum;
    SceInt32 m_iPesPacketForwardSize;
    SceInt32 m_iPesPacketForwardFlag;
    SceShort16 m_iPesPacketAULocator;
    SceShort16 reserved;
    SceInt32 m_iPesPacketNum;
    SceInt32 m_iAuSize;
    SceInt32 m_iBoundarySize;
    SceInt32 m_iAuSizeOfProceed;
    SceUInt32 m_iGetAuMode;
    SceInt32 m_iPayloadHeaderRemainderFlag;
    SceInt32 m_iPayloadHeaderRemainderSize;
    SceChar8 m_cPayloadHeaderBuf[4];
};
typedef struct SceMpegStream SceMpegStream;
struct SceMpegAu;
struct SceMpegTimeStamp;
struct SceMpegTimeStamp { /* size 0x8 */
    SceUInt32 MSB_ts;
    SceUInt32 ts;
};
typedef struct SceMpegTimeStamp SceMpegTimeStamp;
struct SceMpegAu { /* size 0x18 */
    SceMpegTimeStamp pts;
    SceMpegTimeStamp dts;
    SceUChar8 *pEsBuf;
    SceInt32 iEsSize;
};
typedef struct SceMpegAu SceMpegAu;
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
typedef struct t_displayBuffer t_displayBuffer;
struct t_avSyncControl;
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
struct t_mpegStreamData;
struct t_mpegStreamData { /* size 0x10 */
    SceMpegStream *pAvcStream;
    SceMpegAu *pAvcAu;
    SceMpegStream *pAtracStream;
    SceMpegAu *pAtracAu;
};
typedef struct t_mpegStreamData t_mpegStreamData;
typedef SceUChar8 *SceMpegHandle;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
typedef struct SceCtrlData SceCtrlData;
struct _scemoduleinfo;
struct _scemoduleinfo { /* size 0x34 */
    short unsigned int modattribute;
    unsigned char modversion[2];
    char modname[27];
    char terminal;
    void *gp_value;
    const void *ent_top;
    const void *ent_end;
    const void *stub_top;
    const void *stub_end;
};
struct t_playInfo;
struct t_playInfo { /* size 0x8 */
    SceInt32 playMode;
    SceUInt32 timestamp;
};
typedef struct t_playInfo t_playInfo;

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern SceInt32 sce_newlib_heap_kb_size;
extern t_playInfo playInfo;
extern SceInt32 audioFlag;
extern SceInt32 frameCount;
extern SceInt32 frameLoss;
extern SceUID soundThread;

static SceInt32 loadModule(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option);
static SceInt32 unloadModule(SceUID *mid);
static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData);
SceInt32 main(SceInt32 argc, SceChar8 **argv);
static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset);
static SceInt32 startCheck(t_avSyncControl *pAvSync, SceMpegRingbuffer *pRB, SceInt32 filesize, SceInt32 demuxsize);
static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync, SceInt32 filesize);

/* SDK functions (tools/sdk_protos.h) */
int sceCtrlReadBufferPositive(SceCtrlData *data, int count);
void sceKernelExitGame(void);


int exit_func(int count, int arg1, void *arg2) {
    if (audioFlag == 1) {
        soundbuf_setDemuxEnd(arg2);
        sceKernelWaitThreadEnd(soundThread, 0);
    }
    sceKernelExitGame();
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", loadModule);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", unloadModule);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", ringbufferCallBack);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", main);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F12C);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F14C);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F168);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F17C);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F188);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F190);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F1B8);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F1E8);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F208);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F230);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F254);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F278);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F2A4);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", D_0000F2C4);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", readHeader);

extern SceCtrlData D_00010320;

int pad_read(void) {
    int var_a0;

    sceCtrlReadBufferPositive(&D_00010320, 1);
    var_a0 = 1;
    if (D_00010320.Buttons & 1) {
        playInfo.playMode = 0xA;
    } else {
        var_a0 = 0;
        if (D_00010320.Buttons & 8) {
            playInfo.playMode = 1;
            var_a0 = 1;
        }
    }
    return var_a0;
}

int readPspStream(SceMpegRingbuffer *pRB) {
    int temp_v0;
    int var_v1;

    temp_v0 = sceMpegRingbufferAvailableSize();
    var_v1 = 0;
    if (temp_v0 > 0) {
        var_v1 = sceMpegRingbufferPut(pRB, 0x20, temp_v0);
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", startCheck);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_ezmpegstr/nonmatchings/main", playMovie);
