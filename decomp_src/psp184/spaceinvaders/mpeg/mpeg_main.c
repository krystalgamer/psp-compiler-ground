#include "common.h"

/* declarations recovered from DWARF (UTST99332 mpeg_ezmpegstr main) */
typedef int SceInt32;
typedef void SceVoid;
typedef struct t_soundBuffer t_soundBuffer;
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
typedef struct SceKernelLMOption SceKernelLMOption;
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
struct _anon1;
struct _anon1 { /* size 0x10 */
    SceUID fd;
    SceChar8 assignName[10];
};
typedef struct _anon1 StrFile;
typedef struct SceMpeg SceMpeg;
struct SceMpeg;
struct SceMpeg { /* size 0x4 */
    SceVoid *sys;
};
typedef struct SceMpegRingbuffer SceMpegRingbuffer;
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
typedef struct SceMpegStream SceMpegStream;
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
typedef struct SceMpegAu SceMpegAu;
struct SceMpegAu;
typedef struct SceMpegTimeStamp SceMpegTimeStamp;
struct SceMpegTimeStamp;
struct SceMpegTimeStamp { /* size 0x8 */
    SceUInt32 MSB_ts;
    SceUInt32 ts;
};
struct SceMpegAu { /* size 0x18 */
    SceMpegTimeStamp pts;
    SceMpegTimeStamp dts;
    SceUChar8 *pEsBuf;
    SceInt32 iEsSize;
};
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
typedef struct t_avSyncControl t_avSyncControl;
struct t_avSyncControl;
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
typedef struct t_mpegStreamData t_mpegStreamData;
struct t_mpegStreamData;
struct t_mpegStreamData { /* size 0x10 */
    SceMpegStream *pAvcStream;
    SceMpegAu *pAvcAu;
    SceMpegStream *pAtracStream;
    SceMpegAu *pAtracAu;
};
typedef SceUChar8 *SceMpegHandle;
typedef struct SceCtrlData SceCtrlData;
struct SceCtrlData;
struct SceCtrlData { /* size 0x10 */
    unsigned int TimeStamp;
    unsigned int Buttons;
    unsigned char Lx;
    unsigned char Ly;
    unsigned char Rsrv[6];
};
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
typedef struct t_playInfo t_playInfo;
struct t_playInfo;
struct t_playInfo { /* size 0x8 */
    SceInt32 playMode;
    SceUInt32 timestamp;
};

extern int _gp[];
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

static SceInt32 exit_func(SceInt32 count, SceInt32 arg1, SceVoid *arg2);
static SceInt32 loadModule(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option);
static SceInt32 unloadModule(SceUID *mid);
static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData);
SceInt32 main(SceInt32 argc, SceChar8 **argv);
static SceInt32 readHeader(SceMpeg *pMpeg, StrFile *pStrFile, SceInt32 *pFilesize, SceInt32 *strOffset);
static SceInt32 pad_read(void);
static SceInt32 readPspStream(SceMpegRingbuffer *pRB);
static SceInt32 startCheck(t_avSyncControl *pAvSync, SceMpegRingbuffer *pRB, SceInt32 filesize, SceInt32 demuxsize);
static SceInt32 playMovie(SceMpeg *pMpeg, SceMpegRingbuffer *pRB, t_mpegStreamData *pStreamData, t_avSyncControl *pAvSync, SceInt32 filesize);

extern SceUID videoMid;
extern SceUID baseMid;
extern SceUID mpegMid;
int module_file_start(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option);
int strFileReadNoRetry(StrFile *file, void *buff, unsigned int size);
int sceKernelStopModule(SceUID modid, SceSize argsize, void *argp, int *status, void *option);
int sceKernelUnloadModule(SceUID modid);
static SceInt32 loadModule(SceUID *mid, SceChar8 *filename, SceKernelLMOption *option)
{
	module_file_start(mid, filename, option);
	return 0;
}

static SceInt32 unloadModule(SceUID *mid)
{
	int status;

	if (sceKernelStopModule(*mid, 0, NULL, &status, NULL) < 0)
		return -1;
	if (sceKernelUnloadModule(*mid) < 0)
		return -1;
	return 0;
}

static SceInt32 ringbufferCallBack(SceVoid *pBuf, SceInt32 iNum, SceVoid *CallbackData)
{
	SceInt32 iTypeSize;
	SceInt32 iReadSize;
	SceInt32 ret;

	iTypeSize = 2048;
	iReadSize = strFileReadNoRetry((StrFile *)CallbackData, pBuf, iTypeSize * iNum);
	if (iReadSize == 0x80210003 || iReadSize == 0x80210001)
		ret = 0;
	else
		ret = (iReadSize % iTypeSize) ? -1 : iReadSize / iTypeSize;
	return ret;
}

void mpeg_init(void)
{
	SceKernelLMOption option;
	SceKernelLMOption option2;

	option.size = sizeof(option);
	option.mpidtext = 1;
	option.mpiddata = 1;
	option.position = 0;
	option.access = 1;
	option2.size = sizeof(option2);
	option2.mpidtext = 2;
	option2.mpiddata = 2;
	option2.position = 0;
	option2.access = 1;
	if (loadModule(&videoMid, "disc0:/PSP_GAME/USRDIR/kmodule/videocodec.prx", &option) != 0)
		goto err;
	if (loadModule(&baseMid, "disc0:/PSP_GAME/USRDIR/kmodule/mpegbase.prx", &option) != 0)
		goto err;
	if (loadModule(&mpegMid, "disc0:/PSP_GAME/USRDIR/module/mpeg.prx", &option2) != 0)
		goto err;
	return;
err:
	unloadModule(&mpegMid);
	unloadModule(&baseMid);
	unloadModule(&videoMid);
}

void mpeg_end(void)
{
	unloadModule(&mpegMid);
	unloadModule(&baseMid);
	unloadModule(&videoMid);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/mpeg_main", mpeg_main);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/mpeg_main", readHeader);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/mpeg_main", startCheck);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/mpeg/mpeg_main", playMovie);
