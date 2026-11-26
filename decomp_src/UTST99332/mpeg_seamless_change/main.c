#include "common.h"

/* declarations recovered from DWARF */
typedef void SceVoid;
typedef int SceInt32;
struct _anon1;
typedef int SceUID;
typedef char SceChar8;
struct _anon1 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon1 StrFile;
struct t_conditionCtrl;
struct t_conditionCtrl { /* size 0x4 */
    SceUID control_flag;
};
typedef struct t_conditionCtrl t_conditionCtrl;
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
struct ScePsmf;
struct ScePsmf { /* size 0x28 */
    SceInt32 type;
    SceInt32 groupingPeriodId;
    SceInt32 groupId;
    SceInt32 streamNumber;
    SceVoid *header;
    SceVoid *sequenceInfo;
    SceVoid *currentGroupingPeriod;
    SceVoid *currentGroup;
    SceVoid *currentStream;
    SceVoid *currentEPmap;
};
typedef struct ScePsmf ScePsmf;
struct t_displayBuffer;
typedef unsigned int SceUInt32;
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
struct t_ringBuffer;
struct t_ringBuffer { /* size 0x14 */
    SceInt32 dataLen;
    SceUID ringbufSema;
    SceInt32 statusFlag;
    SceMpegRingbuffer *pRingbuf;
    t_conditionCtrl *pCtrl;
};
typedef struct t_ringBuffer t_ringBuffer;
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
struct t_playInfo;
struct t_streamInfo;
struct t_streamInfo { /* size 0x18 */
    ScePsmf *pVideoPsmf;
    ScePsmf *pAudioPsmf;
    SceInt32 currentVideoStreamTypeId;
    SceInt32 currentAudioStreamTypeId;
    SceInt32 numberOfAvcStreams;
    SceInt32 numberOfAudioStreams;
};
typedef struct t_streamInfo t_streamInfo;
struct t_mpegStreamData;
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
typedef SceUChar8 *SceMpegHandle;
struct t_mpegStreamData { /* size 0x428 */
    SceMpeg *pMpeg;
    SceMpegStream *pVideoStream[16];
    SceMpegStream *pAudioStream[16];
    SceInt32 currentVideoStream;
    SceInt32 reservedVideoStream;
    SceInt32 currentAudioStream;
    SceInt32 videoStreamNum;
    SceInt32 audioStreamNum;
    SceMpegAu pAvcAu[16];
    SceMpegAu pAudioAu[16];
    SceMpegHandle avcEsBuf1;
    SceMpegHandle avcEsBuf2;
    SceChar8 *pAudioEsBuf;
    SceInt32 videoDemuxFlag[16];
    SceInt32 audioDemuxFlag[16];
    SceInt32 audioOutSize;
};
typedef struct t_mpegStreamData t_mpegStreamData;
struct t_playInfo { /* size 0x454 */
    SceInt32 playMode;
    SceInt32 fileSize;
    SceUInt32 timestamp;
    t_streamInfo sInfo;
    t_mpegStreamData streamData;
    SceUInt32 nextIdrTimestamp;
    SceInt32 videoChangeMode;
};
typedef struct t_playInfo t_playInfo;
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

extern int _gp;
extern const int __begin_of_section_lib_ent[1];
extern const int __end_of_section_lib_ent[1];
extern const int __begin_of_section_lib_stub[1];
extern const int __end_of_section_lib_stub[1];
extern const struct _scemoduleinfo __psp_moduleinfo;
extern unsigned int __PSPEXP__module_info[2];
extern unsigned int __PSPREN__module_info___psp_moduleinfo[2];
extern SceInt32 sce_newlib_heap_kb_size;
extern SceInt32 audioFlag;
extern SceUID dispThread;
extern SceUID readThread;
extern SceUID soundThread;

static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData);
static SceInt32 loadModule(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option);
static SceInt32 unloadModule(SceUID *mid);
SceInt32 main(SceInt32 argc, SceChar8 **argv);
static SceInt32 startCheck(t_avSyncControl *pAvSync, t_ringBuffer *pRingCtrl, t_conditionCtrl *pCtrl);
static SceInt32 checkDecodeEnd(t_conditionCtrl *pCtrl);
static SceInt32 checkPlayerErrCondition(t_conditionCtrl *pCtrl);
static SceInt32 setPlayerEndCondition(t_conditionCtrl *pCtrl);
static SceInt32 playMovie(SceMpegRingbuffer *pRB, t_playInfo *pPlayInfo, t_ringBuffer *pRingCtrl, t_avSyncControl *pAvSync, t_conditionCtrl *pCtrl);
static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceChar8 **pHeader, SceInt32 *pFilesize, SceInt32 *strOffset);
static SceInt32 pad_read(t_displayBuffer *pDisp, t_playInfo *pPlayInfo);

/* SDK functions (tools/sdk_protos.h) */
void sceKernelExitGame(void);


INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", ringbufferCallBack);

int exit_func(int count, int arg1, void *arg2) {
    setPlayerEndCondition((t_conditionCtrl *) arg2);
    if (audioFlag == 0) {

    } else {
        sceKernelWaitThreadEnd(soundThread, 0);
    }
    sceKernelWaitThreadEnd(dispThread, 0);
    sceKernelWaitThreadEnd(readThread, 0);
    sceKernelExitGame();
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", loadModule);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", unloadModule);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", main);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", startCheck);

static SceInt32 checkDecodeEnd(t_conditionCtrl *pCtrl)
{
	SceUInt32 cond;

	control_getCondition(pCtrl, &cond);
	if (cond & 8)
		return 1;
	return -1;
}

SceInt32 checkPlayerErrCondition(t_conditionCtrl *pCtrl)
{
	SceUInt32 pattern;

	control_getCondition(pCtrl, &pattern);

	if (pattern & 0x800) {
		return -1;
	}

	return 0;
}

static SceInt32 setPlayerEndCondition(t_conditionCtrl *pCtrl)
{
	control_setCondition(pCtrl, 0xFF);
	return 0;
}

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", D_0001140C);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", D_0001142C);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", D_00011448);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", D_00011454);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", D_0001147C);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", D_000114AC);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", D_000114B8);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", D_000114D8);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", D_00011500);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", D_00011520);

INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", D_00011540);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", playMovie);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", readHeader);

INCLUDE_ASM("tmp/asm/UTST99332/mpeg_seamless_change/nonmatchings/main", pad_read);
